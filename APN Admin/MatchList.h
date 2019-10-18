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

void initMatch(Player one, Player two);
int searchLastMatch();
void saveMatch(bool whoWon);
void highScores();
void printScore(scorePLayer score);
void printMatch(GameList match);
void printMatchFile();
Player traeme();
Player traemeotro();





#endif // MATCHLIST_H_INCLUDED
