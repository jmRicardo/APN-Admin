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

NodoScorePLayerTree * insertTree(NodoScorePLayerTree * tree, scorePLayer dato){

    if(tree == NULL)
        tree = createNodoTree(dato);
    else{
        if (dato.idPlayer > tree->dato.idPlayer)
            tree->derecha = insertTree(tree->derecha,dato);
    else
            tree->izquierda = insertTree(tree->izquierda, dato);
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
 postorder(tree->derecha);
 postorder(tree->izquierda);
 printf("\n Id           :%i ", tree->dato.idPlayer);
 printf("\n Tiempo       :%lf ", tree->dato.matchTime);
 printf("\n Score Time   :%i ", tree->dato.scoreTime);
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
