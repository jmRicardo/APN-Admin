#include "MatchList.h"

int searchLastMatch(){
    int id = 0;
    GameList aux;
    FILE * archi = fopen("MatchFile.dat", "rb");
    if (archi){
        if (fseek(archi,-1*sizeof(GameList),SEEK_END)){
            fread(&aux, sizeof(GameList), 1, archi);
            id = aux.idMatch;
        }
        fclose(archi);
    }
    return id;
}

void initMatch(Player one, Player two){
    GameList aux;
    int id = searchLastMatch();
    FILE * archi = fopen("MatchFile.dat", "ab");
    if (archi){
        aux.idMatch = id + 1;
        aux.player1.idPlayer = one.idPlayer;
        aux.player1.matchTime = aux.player2.matchTime = 0;
        aux.player1.scoreTime = aux.player2.scoreTime = 0;
        aux.player2.idPlayer = two.idPlayer;
        fwrite(&aux, sizeof(GameList), 1, archi);
        fclose(archi);
    }
}

void printScore(scorePLayer score){
    std::cout << "idPlayer: " << score.idPlayer << std::endl;
    std::cout << "Match Time : " << score.matchTime << std::endl;
    std::cout << "Score Time: " << score.scoreTime << std::endl;
}

void printMatch(GameList match){
    std::cout << "idMatch: " << match.idMatch << std::endl;
    printScore(match.player1);
    printScore(match.player2);
    if (match.whoWon){
        std::cout << "Player 1 won" << match.whoWon << std::endl;
    }else{
        std::cout << "Player 2 won" << match.whoWon << std::endl;
    }
}

void printMatchFile(){
    GameList aux;
    FILE * archi = fopen("MatchFile.dat", "rb");
    if (archi){
        while ((&aux, sizeof(GameList), 1, archi) > 0){
            printMatch(aux);
        }
        fclose(archi);
    }
}

Player traeme(){
    Player aux;
    FILE * archi = fopen("players.dat", "rb");
    if (archi){
        fread(&aux, sizeof(Player), 1, archi);
    }
    return aux;
}

Player traemeotro(){
    Player aux;
    FILE * archi = fopen("players.dat", "rb");
    if (archi){
        fread(&aux, sizeof(Player), 2, archi);
    }
    return aux;
}

