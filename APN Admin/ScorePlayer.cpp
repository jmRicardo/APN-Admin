#include "MatchList.h"
#include "Players.h"
#include "ScorePlayer.h"


NodoScorePLayerTree * inicArbol(){
return NULL;
}

NodoScorePLayerTree * createNodoTree (ScorePLayer dato){

NodoScorePLayerTree * aux = (NodoScorePLayerTree*) malloc(sizeof(NodoScorePLayerTree));
aux->dato = dato;
aux->izquierda = NULL;
aux->derecha = NULL;
return aux;
}

NodoScorePLayerTree * insertTree(NodoScorePLayerTree * tree, ScorePLayer dato){

    if(tree == NULL)
        tree = createNodoTree(dato);
    else{
        if (dato->idPlayer > tree->dato.idPlayer)
            tree->derecha = insertTree(tree->derecha,dato);
    else
            tree->izquierda = insertTree(tree->izquierda, dato);
}
    return tree;
}

NodoScorePLayerTree * searchTree(NodoScorePLayerTree * tree, ScorePLayer dato->idPlayer){

NodoScorePLayerTree * reply = NULL;
    if(tree){
        if(dato->idPlayer == tree->dato.idPlayer)
            reply = tree;
        else
            if(dato->idPlayer > tree->dato.idPlayer)
                reply = searchTree(tree->derecha, dato);
            else
                reply = searchTree(tree->izquierda, dato);
}
return reply;
}




