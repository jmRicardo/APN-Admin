#include "MatchList.h"
#include "Players.h"

int main()
{
    loadPlayer("EnriquePinty");
    loadPlayer("AdrianBarba");
    loadPlayer("JoaquinAlvarez");
    //printFilePlayers();
    Player aux1 = traeme();
    Player aux2 = traemeotro();

    initMatch(aux1, aux2);
    printMatchFile();

    return 0;
}
