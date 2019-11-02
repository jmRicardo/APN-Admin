#include "Menu.h"

cell adl[30];
int opcion;
Player forOrderedArray[30];
int validos;
int validosPlayers;
char playerToAdd[30];
int IdAbuscarMatch;
char playerToSearch[30];
bool flagPlayer;
char control;
char playerToDeactivate[30];
char playerToActivate[30];
char playerToShowScores[30];

void printMainMenu(){   ///opciones del menu principal
    printf("\nMENU ADMIN\n\n");
    printf("\n00- Salir");
    printf("\n01- Players");
    printf("\n02- Matches");
    printf("\n03- Scores");
    printf("\n06- Mostrar score de todos los Player");
}

void printSubMenuMatch(){   ///opciones del menu de Matches
    printf("\nSUBMENU MATCHES\n\n");
    printf("\n00- Atras");
    printf("\n01- Mostrar Match desde su Id");
    printf("\n02- Mostrar Matches de cierto jugador");
    printf("\n03- Mostrar todos los Matches");
}

void printSubMenuPlayer(){   ///opciones del menu de Players
    printf("\nSUBMENU PLAYERS\n\n");
    printf("\n00- Atras");
    printf("\n01- Cargar un jugador");
    printf("\n02- Mostrar listado de Players");
    printf("\n03- Mostrar listado de Players Activos");
    printf("\n04- Mostrar listado de Players Inactivos");
    printf("\n05- Mostrar listado de Players ordenados por Nick");
    printf("\n06- Desactivar Player");
    printf("\n07- Reactivar Player");
}

void printSubMenuScores(){   ///opciones del menu de Scores
    printf("\nSUBMENU SCORES\n\n");
    printf("\n00- Atras");
    printf("\n01- Mostrar Scores de un jugador");
}
int switchSubMenuScores(){   ///submenu de Scores
    int opcion;
    do{
        opcion = choseYourDestiny();
        switch(opcion){
        case 1:
            system("cls");

            break;
        case 0:
            break;
        default:
            printf("\nOpcion invalida\n");
            fflush(stdin);
            getchar();
            break;
        }
        system("cls");
        if (opcion != 0){
            printSubMenuScores();
        }
    }while (opcion != 0);
    return opcion;
}

int switchSubMenuMatch(){   ///submenu de Matches
    int opcion;
    do{
        opcion = choseYourDestiny();
        switch(opcion){
            case 1:
                system("cls");
                printf("\nIngrese iD del Match deseado: ");
                scanf("%d", &IdAbuscarMatch);
                printMatchFromAnId(IdAbuscarMatch);
                fflush(stdin);
                getchar();
                break;
            case 2:
                system("cls");
                printf("\nIngrese nombre del jugador del cual desea ver los Matches: ");
                fflush(stdin);
                scanf("%s", &playerToSearch);
                printMatchFromAplayer(playerToSearch);
                fflush(stdin);
                getchar();
                break;
            case 3:
                system("cls");
                printMatchFile();
                fflush(stdin);
                getchar();
                break;
            case 0:
                break;
            default:
                printf("\nOpcion invalida\n");
                fflush(stdin);
                getchar();
                break;
        }
        system("cls");
        if (opcion != 0){
            printSubMenuMatch();
        }
    }while (opcion != 0);
    return opcion;
}

int switchMainMenu(){   ///menu principal del modo Admin
    int opcion;
    do{
        opcion = choseYourDestiny();
        switch(opcion){
        case 1:
            system("cls");
            subMenuPlayer();
            break;
        case 2:
            system("cls");
            subMenuMatch();
            break;
        case 3:
            system("cls");
            subMenuScores();
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
            fflush(stdin);
            getchar();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("\nOpcion invalida\n");
            fflush(stdin);
            getchar();
            break;
        }
    system("cls");
    printMainMenu();
    }while (opcion != 0);
    return opcion;
}

int choseYourDestiny(){   ///funcion auxiliar para los menues
    int aux;
    printf("\n\nElija accion a realizar: ");
    fflush(stdin);
    scanf("%i", &aux);
    return aux;
}

void menu(){   ///funcion que invoca el menu principal
    int aux;
    do{
        system("cls");
        printMainMenu();
        aux = switchMainMenu();
    }while(aux != 0);
}

void subMenuMatch(){   ///funcion que invoca el menu de Matches
    int aux;
    do{
        system("cls");
        printSubMenuMatch();
        aux = switchSubMenuMatch();
    }while(aux != 0);
}

void subMenuPlayer(){   ///funcion que invoca el menu de Players
    int aux;
    do{
        system("cls");
        printSubMenuPlayer();
        aux = switchSubMenuPlayer();
    }while(aux != 0);
}

void subMenuScores(){   ///funcion que invoca el menu de Scores
    int aux;
    do{
        system("cls");
        printSubMenuScores();
        aux = switchSubMenuScores();
    }while(aux != 0);
}

int switchSubMenuPlayer(){   ///submenu de Players
    int opcion;
    do{
        opcion = choseYourDestiny();
        switch(opcion){
        case 1:
            system("cls");
            printf("\nIngrese su Nick: ");
            fflush(stdin);
            scanf("%s", &playerToAdd);
            loadPlayer(playerToAdd);
            fflush(stdin);
            getchar();
            break;
        case 2:
            system("cls");
            validos = fromFileToArray(adl, 30);
            printf("\n--------------------------------");
            printArrayOfPlayersWithListas(adl, validos);
            printf("\n--------------------------------\n");
            fflush(stdin);
            getchar();
            break;
        case 3:
            system("cls");
            printf("\n--------------------------------");
            printActiveOrInactivePlayers(true);
            printf("\n--------------------------------\n");
            fflush(stdin);
            getchar();
            break;
        case 4:
            system("cls");
            printf("\n--------------------------------");
            printActiveOrInactivePlayers(false);
            printf("\n--------------------------------\n");
            fflush(stdin);
            getchar();
            break;
        case 5:
            system("cls");
            validosPlayers = fromFileToArrayOfPlayers(forOrderedArray, 30);
            incertion(forOrderedArray, validosPlayers);
            printf("\n--------------------------------");
            printArrayOfPlayersPlayers(forOrderedArray, validosPlayers);
            printf("\n--------------------------------\n");
            fflush(stdin);
            getchar();
            break;
        case 6:
            system("cls");
            printf("\nQue jugador desea desactivar: ");
            fflush(stdin);
            scanf("%s", &playerToDeactivate);
            flagPlayer = checkPlayer(playerToDeactivate);
            if (flagPlayer){
                printf("\nEl jugador no existe\n");
            }else{
                activeOrDeactivatePlayer(playerToDeactivate, false);
                printf("\n--------------------------------");
                printFilePlayers();
                printf("\n--------------------------------\n");
            }
            fflush(stdin);
            getchar();
            break;
        case 7:
            system("cls");
            printf("\nQue jugador desea reactivar: ");
            fflush(stdin);
            scanf("%s", &playerToActivate);
            flagPlayer = checkPlayer(playerToActivate);
            if (flagPlayer){
                printf("\nEl jugador no existe\n");
            }else{
                activeOrDeactivatePlayer(playerToActivate, true);
                printf("\n--------------------------------");
                printFilePlayers();
                printf("\n--------------------------------\n");
            }
            fflush(stdin);
            getchar();

        case 0:
            break;
        default:
            printf("\nOpcion Invalida\n");
            system("pause");
            break;
        }
        system("cls");
        if (opcion != 0){
            printSubMenuPlayer();
        }
    }while (opcion != 0);
    return opcion;
}
























