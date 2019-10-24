#include "MatchList.h"
#include "Players.h"
#include "ScorePlayer.h"

int main()
{
    cell adl[30];
    int opcion;
    char control;
    /*loadPlayer("EnriquePinty");
    loadPlayer("AdrianBarba");
    loadPlayer("JoaquinAlvarez");
    //printFilePlayers();
    Player aux1 = traeme();
    Player aux2 = traemeotro();

    initMatch(aux1, aux2);
    printMatchFile();*/
    int validos = fromFileToArray(adl, 30);
    //printf("\nVALIDOS: %d", validos);
    //printArrayOfPlayers(adl, validos);
    listaToArrayOfPlayers(adl, validos);
    printArrayOfPlayersWithListas(adl, validos);

    do{
        printf("\n01- Cargar un jugador");  /// o modificar
        printf("\n02- Listado de Players");
        printf("\n03- Desactivar Player papu");
        printf("\n04- Mostrar score de un Player");
        printf("\n05- Mostrar Match determinado");
        printf("\n06- Mostrar score de todos los Player");
        printf("\n07- Mostrar todos los Match");
        printf("\n08- Un salir");
        printf("\n09- Mostrar los Players ordenados por alguna propiedad");


        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            system("cls");
            break;
        case 8:
            exit(0);
        }

        printf("\nVolver al menu? (s/n)");
        fflush(stdin);
        scanf("%c", &control);
    }while (control = 's');





    return 0;
}
