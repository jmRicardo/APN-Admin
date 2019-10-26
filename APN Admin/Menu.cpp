#include "Menu.h"

cell adl[30];
int opcion;
int validos;
int IdAbuscarMatch;
bool flagPlayer;
char control;
char playerToDeactivate[30];
char playerToShowScores[30];

void printMainMenu(){
    printf("\nMENU ADMIN\n\n");
    printf("\n00- Un salir");
    printf("\n01- Cargar un jugador");  /// o modificar
    printf("\n02- Listado de Players");
    printf("\n03- Desactivar Player papu");
    printf("\n04- Mostrar score de un Player");
    printf("\n05- Mostrar Match determinado");
    printf("\n06- Mostrar score de todos los Player");
    printf("\n07- Mostrar todos los Match");
    printf("\n08- Mostrar los Players ordenados por alguna propiedad");
}

int switchMainMenu(){
    int opcion;
    do{
        opcion = choseYourDestiny();
        switch(opcion){
        case 1:
            system("cls");
            break;
        case 2:
            system("cls");
            validos = fromFileToArray(adl, 30);
            printArrayOfPlayersWithListas(adl, validos);
            break;
        case 3:
            system("cls");
            printf("\nQue jugador desea desactivar: ");
            fflush(stdin);
            scanf("%s", &playerToDeactivate);
            flagPlayer = checkPlayer(playerToDeactivate);
            ///printf("\n------%d", flagPlayer);
            if (flagPlayer){
                printf("\nEl jugador no existe\n");
            }else{
                deactivatePlayer(playerToDeactivate);
                printFilePlayers();
                //printArrayOfPlayersWithListas(adl, validos);
            }
            break;
        case 4:
            system("cls");
            validos = fromFileToArray(adl, 30);
            printf("\nDe que jugador desea mostrar los Scores: ");
            fflush(stdin);
            scanf("%s", &playerToShowScores);
            flagPlayer = checkPlayer(playerToShowScores);
            if (flagPlayer){
                printf("\nEl jugador no existe\n");
            }else{
                int idbuscado = searchiDFromName(playerToShowScores);
                printf("\n--ID: %d\n", idbuscado);
            }
            break;
        case 5:
            system("cls");
            ///mostrar Match de alguna/s forma/s
            ///Por iDMatch:
            printf("\nIngrese iD del Match deseado: ");
            scanf("%d", &IdAbuscarMatch);
            printMatchFromAnId(IdAbuscarMatch);
            break;

        case 0:
            exit(0);
            break;
        default:
            printf("\nOpcion invalida\n");
            break;
        }
    system("pause");
    system("cls");
    printMainMenu();
    }while (opcion != 0);
    return opcion;
}

int choseYourDestiny(){
    int aux;
    printf("\n\nElija accion a realizar: ");
    fflush(stdin);
    scanf("%i", &aux);
    return aux;
}

void menu(){
    int aux;
    do{
        system("cls");
        printMainMenu();
        aux = switchMainMenu();
    }while(aux != 0);
}
