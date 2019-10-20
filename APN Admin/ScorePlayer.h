#ifndef SCOREPLAYER_H_INCLUDED
#define SCOREPLAYER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

typedef struct _ScorePLayer
{
    int idPlayer;
    double matchTime;
    int scoreTime;
}ScorePLayer;

typedef struct _nodoScorePLayer{
    ScorePLayer dato;
    struct _nodoScorePLayer * izquierda;
    struct _nodoScorePLayer * derecha;
}NodoScorePLayerTree;

NodoScorePLayerTree * inicArbol();
NodoScorePLayerTree * createNodoTree (ScorePLayer dato);
NodoScorePLayerTree * insertTree(NodoScorePLayerTree * tree, ScorePLayer dato);
NodoScorePLayerTree * searchTree(NodoScorePLayerTree * tree, ScorePLayer dato->idPlayer);

#endif // SCOREPLAYER_H_INCLUDED

