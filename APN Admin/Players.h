#ifndef PLAYERS_H_INCLUDED
#define PLAYERS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "MatchList.h"

typedef struct{
    int idPlayer;
    char nick[30];
    bool active;
    //double totalTime;
    //double totalScoreTime;
    //int wins;
}Player;

typedef struct{
    GameList dato;
    struct nodoGameList * siguiente;
}nodoGameList;

typedef struct{
    Player dato;
    nodoGameList * lista;
}cell;

bool loadPlayer(char playerNick[]);
int searchLastID();
bool checkPlayer(char playerNick[]);
void printPlayer(Player p);
void printFilePlayers();
nodoGameList * inicLista();
nodoGameList * createNodo(GameList dato);
nodoGameList * addToBeginning(nodoGameList * lista, nodoGameList * nuevoNodo);
nodoGameList * searchLastNodo(nodoGameList * lista);
nodoGameList * addToFinal(nodoGameList * lista, nodoGameList * nuevoNodo);
int addCell(cell adl[], int dim);


#endif // PLAYERS_H_INCLUDED
