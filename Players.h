#ifndef PLAYERS_H_INCLUDED
#define PLAYERS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>


typedef struct{
    int idPlayer;
    char nick[30];
    bool active;
    //double totalTime;
    //double totalScoreTime;
    //int wins;
}Player;

bool loadPlayer(char playerNick[]);
int searchLastID();
bool checkPlayer(char playerNick[]);
void printPlayer(Player p);
void printFilePlayers();
void deactivatePlayer(char playerNick[]);
void printActivePlayers();
void printInactivePlayers();
void insertInArray(Player a[], int cant, Player dato);
void incertion(Player a[], int cant);
int fromFileToArrayOfPlayers(Player a[], int dim);
void printArrayOfPlayersPlayers(Player a[], int cant);
int searchiDFromName(char nickPlayer[]);



#endif // PLAYERS_H_INCLUDED