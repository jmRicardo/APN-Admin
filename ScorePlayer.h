#ifndef SCOREPLAYER_H_INCLUDED
#define SCOREPLAYER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "MatchList.h"
#include "ScorePlayer.h"


typedef struct _nodoScorePLayer{
    scorePLayer dato;
    struct _nodoScorePLayer * izquierda;
    struct _nodoScorePLayer * derecha;
}NodoScorePLayerTree;

typedef struct _nodoListaScorePlayer{
    scorePLayer dato;
    struct _nodoListaScorePlayer * siguiente;
}nodoListaScorePlayer;




NodoScorePLayerTree * inicArbol();
NodoScorePLayerTree * createNodoTree (scorePLayer dato);
NodoScorePLayerTree * insertTree(NodoScorePLayerTree * tree, scorePLayer dato);
NodoScorePLayerTree * searchTree(NodoScorePLayerTree * tree, scorePLayer dato);
void postorder(NodoScorePLayerTree * tree);
nodoListaScorePlayer * moveFromTreeToLista(NodoScorePLayerTree * tree, nodoListaScorePlayer * lista);

nodoListaScorePlayer * inicListaScore();
nodoListaScorePlayer * createNodoLista(scorePLayer dato);
nodoListaScorePlayer * addToBeginningListeScore(nodoListaScorePlayer * lista, nodoListaScorePlayer * nuevoNodo);
#endif // SCOREPLAYER_H_INCLUDED

