#ifndef MATCHLIST_H_INCLUDED
#define MATCHLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Players.h"
#include <iostream>

typedef struct
{
    int idPlayer;
    double matchTime;
    int scoreTime;
}scorePLayer;

typedef struct _GameList
{
    int idMatch;
    scorePLayer player1;
    scorePLayer player2;
    bool whoWon;
    //struct _Gamelist * nextGame;
}GameList;

typedef struct _nodoGameList
{
    GameList dato;
    struct _nodoGameList * siguiente;
}nodoGameList;

typedef struct{
    Player dato;
    nodoGameList * lista;
}cell;

void initMatch(Player one, Player two);
int searchLastMatch();
void saveMatch(bool whoWon);
void highScores();
void printScore(scorePLayer score);
void printMatch(GameList match);
void printMatchFile();
Player traeme();
Player traemeotro();
nodoGameList * inicLista();
nodoGameList * createNodo(GameList dato);
nodoGameList * addToBeginning(nodoGameList * lista, nodoGameList * nuevoNodo);
nodoGameList * searchLastNodo(nodoGameList * lista);
nodoGameList * addToFinal(nodoGameList * lista, nodoGameList * nuevoNodo);
nodoGameList * searchNodoForIdPlayer(nodoGameList * lista);
int fromFileToArray(cell adl[], int dim);
void printArrayOfPlayers(cell adl[], int cant);
int searchPosInArray(cell adl[], int cant, int idPlayer);
void listaToArrayOfPlayers(cell adl[], int cant);
void printArrayOfPlayersWithListas(cell adl[], int cant);
int searchiDFromName(char nickPlayer[]);
void printMatchFromAnId(int iD);
void printMatchFromAplayer(char nickPlayer[]);




#endif // MATCHLIST_H_INCLUDED
