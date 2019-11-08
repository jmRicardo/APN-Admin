#ifndef SCOREPLAYER_H_INCLUDED
#define SCOREPLAYER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "MatchList.h"
#include "ScorePlayer.h"


typedef struct _NodoScorePLayerTree{
    scorePLayer dato;
    struct _NodoScorePLayerTree * izquierda;
    struct _NodoScorePLayerTree * derecha;
}NodoScorePLayerTree;

typedef struct _nodoListaScorePlayer{
    scorePLayer dato;
    struct _nodoListaScorePlayer * siguiente;
}nodoListaScorePlayer;




NodoScorePLayerTree * inicArbol();
NodoScorePLayerTree * createNodoTree (scorePLayer dato);
NodoScorePLayerTree * insertTree(NodoScorePLayerTree * tree, NodoScorePLayerTree * nuevo);
NodoScorePLayerTree * searchTree(NodoScorePLayerTree * tree, scorePLayer dato);
void postorder(NodoScorePLayerTree * tree);
void printScoreOfCertainPlayer(char nickPlayer[]);


nodoListaScorePlayer * moveFromTreeToLista(NodoScorePLayerTree * tree, nodoListaScorePlayer * lista);

nodoListaScorePlayer * inicListaScore();
nodoListaScorePlayer * createNodoLista(scorePLayer dato);
nodoListaScorePlayer * addToBeginningListeScore(nodoListaScorePlayer * lista, nodoListaScorePlayer * nuevoNodo);
NodoScorePLayerTree * fromFileToTree();

#endif // SCOREPLAYER_H_INCLUDED

