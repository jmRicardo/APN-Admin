#include "MatchList.h"
#include "Players.h"

int main()
{
    cell adl[30];
    /*loadPlayer("EnriquePinty");
    loadPlayer("AdrianBarba");
    loadPlayer("JoaquinAlvarez");
    //printFilePlayers();
    Player aux1 = traeme();
    Player aux2 = traemeotro();

    initMatch(aux1, aux2);
    printMatchFile();*/
    int validos = fromFileToArray(adl, 30);
    printArrayOfPlayers(adl, validos);

    return 0;
}
