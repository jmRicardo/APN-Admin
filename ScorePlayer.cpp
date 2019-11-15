#include "MatchList.h"
#include "Players.h"
#include "ScorePlayer.h"

/*nodoGameList * inicLista(){
    return NULL;
}*/

NodoScorePLayerTree * inicArbol(){
return NULL;
}

NodoScorePLayerTree * createNodoTree (scorePLayer dato){

NodoScorePLayerTree * aux = (NodoScorePLayerTree*) malloc(sizeof(NodoScorePLayerTree));
aux->dato = dato;
aux->izquierda = NULL;
aux->derecha = NULL;
return aux;
}

NodoScorePLayerTree * insertTree(NodoScorePLayerTree * tree, NodoScorePLayerTree * nuevo){

    if(tree == NULL)
        tree = nuevo;
    else{
        if (nuevo->dato.idPlayer > tree->dato.idPlayer)
            tree->derecha = insertTree(tree->derecha, nuevo);
    else
            tree->izquierda = insertTree(tree->izquierda, nuevo);
}
    return tree;
}

NodoScorePLayerTree * searchTree(NodoScorePLayerTree * tree, scorePLayer dato){

NodoScorePLayerTree * reply = NULL;
    if(tree){
        if(dato.idPlayer == tree->dato.idPlayer)
            reply = tree;
        else
            if(dato.idPlayer > tree->dato.idPlayer)
                reply = searchTree(tree->derecha, dato);
            else
                reply = searchTree(tree->izquierda, dato);
}
return reply;
}

void postorder(NodoScorePLayerTree * tree){
    if(tree){
        postorder(tree->izquierda);
        postorder(tree->derecha);
        printScore(tree->dato);
    }
}

void inorder(NodoScorePLayerTree * tree){
    if (tree){
        inorder(tree->izquierda);
        printScore(tree->dato);
        inorder(tree->derecha);
    }
}
void preorder(NodoScorePLayerTree * tree){
    if (tree){
        printScore(tree->dato);
        preorder(tree->izquierda);
        preorder(tree->derecha);
    }
}

nodoListaScorePlayer * moveFromTreeToLista(NodoScorePLayerTree * tree, nodoListaScorePlayer * lista){
    nodoListaScorePlayer * aux = NULL;
    if (tree){
        aux = createNodoLista(tree->dato);
        lista = addToBeginningListeScore(lista, aux);
        lista = moveFromTreeToLista(tree->derecha, lista);
        lista = moveFromTreeToLista(tree->izquierda, lista);
    }
    return lista;
}

nodoListaScorePlayer * inicListaScore(){
    return NULL;
}

nodoListaScorePlayer * createNodoLista(scorePLayer dato){
    nodoListaScorePlayer * aux = (nodoListaScorePlayer*)malloc(sizeof(nodoListaScorePlayer));
    aux->dato = dato;
    aux->siguiente = NULL;
    return aux;
}

nodoListaScorePlayer * addToBeginningListeScore(nodoListaScorePlayer * lista, nodoListaScorePlayer * nuevoNodo){
    nuevoNodo->siguiente = lista;
    //nuevoNodo->dato = lista;
    return nuevoNodo;
}

NodoScorePLayerTree * fromFileToTree(){
    GameList aux;
    NodoScorePLayerTree * barbol = inicArbol();
    FILE * archi = fopen("MatchFile.dat", "rb");
    if (archi){
        while (fread(&aux, sizeof(GameList), 1, archi) > 0){
            NodoScorePLayerTree * helper = createNodoTree(aux.player1);
            barbol = insertTree(barbol, helper);
            NodoScorePLayerTree * helper2 = createNodoTree(aux.player2);
            barbol = insertTree(barbol, helper2);
        }
        fclose(archi);
    }
    return barbol;
}

void printScoreOfCertainPlayer(char nickPlayer[]){
    GameList aux;
    int id = searchiDFromName(nickPlayer);
    NodoScorePLayerTree * barbol = inicArbol();
    FILE * archi = fopen("MatchFile.dat", "rb");
    if (archi){
        while (fread(&aux, sizeof(GameList), 1, archi) > 0){
            if (id == aux.player1.idPlayer){
                printScore(aux.player1);
            }else{
                if (id == aux.player2.idPlayer){
                    printScore(aux.player2);
                }
            }
        }
        fclose(archi);
    }
}















