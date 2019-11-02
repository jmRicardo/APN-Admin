#include "MatchList.h"
#include "Players.h"

int searchLastMatch(){   ///funcion que devuelve el id de la ultima partida jugada
    int id = 0;
    GameList aux;
    FILE * archi = fopen("MatchFile.dat", "rb");
    if (archi){
        if (!(fseek(archi,-1*sizeof(GameList),SEEK_END))){
            fread(&aux, sizeof(GameList), 1, archi);
            id = aux.idMatch;
        }
        fclose(archi);
    }
    return id;
}

void initMatch(Player one, Player two){   ///funcion que inicia una partida
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

void printScore(scorePLayer score){   ///funcion que muestra un solo Score
    printf("\n Id Player: %d", score.idPlayer);
    printf("\nMatch Time: %lf", score.matchTime);
    printf("\nScore Time: %d", score.scoreTime);
    printf("\n--------------------------------------------\n");
}

void printMatch(GameList match){   ///funcion auxiliar que muestra una sola partida
    printf("\n  Id Match: |%d|", match.idMatch);
    printScore(match.player1);
    printScore(match.player2);
    if (match.whoWon){
        printf("\nPlayer 1 Won");
    }else{
        printf("\nPlayer 2 Won");
    }
    printf("\n--------------------------------------------\n");
}

void printMatchFile(){   ///funcion que muestra por pantalla todas las partidas jugadas
    GameList aux;
    FILE * archi = fopen("MatchFile.dat", "rb");
    if (archi){
        while (fread(&aux, sizeof(GameList), 1, archi) > 0){
            printMatch(aux);
        }
        fclose(archi);
    }
}

Player traeme(){  ///funcion auxiliar para cargar un player
    Player aux;
    FILE * archi = fopen("players.dat", "rb");
    if (archi){
        fseek(archi, 4*sizeof(Player), SEEK_SET);
        fread(&aux, sizeof(Player), 1, archi);
        fclose(archi);
    }
    return aux;
}

Player traemeotro(){   ///funcion auxiliar para cargar un player
    Player aux;
    FILE * archi = fopen("players.dat", "rb");
    if (archi){
        fseek(archi, 3*sizeof(Player), SEEK_SET);
        fread(&aux, sizeof(Player), 1, archi);
        fclose(archi);
    }
    return aux;
}

nodoGameList * inicLista(){
    return NULL;
}

nodoGameList * createNodo(GameList dato){
    nodoGameList * aux = (nodoGameList*)malloc(sizeof(nodoGameList));
    aux->dato = dato;
    aux->siguiente = NULL;
    return aux;
}

nodoGameList * addToBeginning(nodoGameList * lista, nodoGameList * nuevoNodo){
    nuevoNodo->siguiente = lista;
    return nuevoNodo;
}

nodoGameList * searchLastNodo(nodoGameList * lista){
    nodoGameList * aux = lista;
    if (aux){
        while (aux->siguiente){
            aux = aux->siguiente;
        }
    }
    return aux;
}

nodoGameList * addToFinal(nodoGameList * lista, nodoGameList * nuevoNodo){   ///añade al final de la lista
    if (lista == NULL){
        lista = nuevoNodo;
    }else{
        nodoGameList * aux = searchLastNodo(lista);
        aux->siguiente = nuevoNodo;
    }
    return lista;
}

nodoGameList * searchNodoForIdPlayer(nodoGameList * lista, int idPlayer){   ///busca un nodo que tenga un id igual al enviado
    nodoGameList * aux = lista;
    while (aux && aux->dato.player1.idPlayer != idPlayer){
        aux = aux->siguiente;
    }
    return aux;
}

int fromFileToArray(cell adl[], int dim){   ///pasa del archivo al arreglo los players
    Player aux;
    int i = 0;
    FILE * archi = fopen("players.dat", "rb");
    if (archi){
        while (fread(&aux, sizeof(Player), 1, archi) > 0){
            adl[i].dato = aux;
            i++;
        }
        fclose(archi);
    }
    return i;
}

void printArrayOfPlayers(cell adl[], int cant){   ///imprime por pantalla el arreglo de players
    int i = 0;
    for (i=0; i<cant; i++){
        printPlayer(adl[i].dato);
    }
}

int searchPosInArray(cell adl[], int cant, int idPlayer){   ///busca la posicion de un player en el arreglo
    int pos = -1;
    int i = 0;
    while (i < cant && pos == -1){
        if (adl[i].dato.idPlayer == idPlayer){
            pos = i;
        }
        i++;
    }
    return pos;
}

void listaToArrayOfPlayers(cell adl[], int cant){   ///pasa del archivo de Matches al arreglo de listas
    GameList aux;
    int i = 0;
    int j = 0;
    FILE * archi = fopen("MatchFile.dat", "rb");
    if (archi){
        while (fread(&aux, sizeof(GameList), 1, archi) > 0){
            nodoGameList * helper = createNodo(aux);
            i = searchPosInArray(adl, cant, helper->dato.player1.idPlayer);
            adl[i].lista = addToBeginning(adl[i].lista, helper);
            j = searchPosInArray(adl, cant, helper->dato.player2.idPlayer);
            adl[j].lista = addToBeginning(adl[j].lista, helper);
        }
        fclose(archi);
    }
}

void printArrayOfPlayersWithListas(cell adl[], int cant){
    int i = 0;
    for (i=0; i<cant; i++){
        printPlayer(adl[i].dato);
        if (adl[i].lista){
            printMatch(adl[i].lista->dato);
        }
    }
}

/*
void printScoreOfWantedPlayer(char nickPlayer[]){
    int iD = searchiDFromName(nickPlayer);
    double totalMatch;
    int totalScore;
    FILE * archi = fopen("score.dat", "rb");
    scorePLayer aux;
    if (archi){
        while ((fread(&aux), sizeof(scorePLayer), 1, archi) > 0){
            if (iD == aux.idPlayer){
                totalMatch =+ aux.matchTime;
                totalScore =+ aux.scoreTime;
            }
        }
        fclose(archi);
    }
    printf("\nTotal Match Time: %lf", totalMatch);
    printf("\nTotal Score Time: %d", totalScore);
}
*/
/*
void printAllScores(){
    int iD = 1;
    FILE * archi = fopen("score.dat", "rb");
    scorePLayer aux;
    if (archi){
        while ((fread(&aux), sizeof(scorePLayer), 1, archi) > 0){

        }
    }
}
*/

void printMatchFromAnId(int iD){   ///muestra un Match buscado por su Id
    GameList aux;
    FILE * archi = fopen("MatchFile.dat", "rb");
    if (archi){
        fseek(archi, ((iD - 1)*(sizeof(GameList))), SEEK_SET);
        fread(&aux, sizeof(GameList), 1, archi);
        printMatch(aux);
        fclose(archi);
    }
}

void printMatchFromAplayer(char nickPlayer[]){   ///muestra todos los Matches de un jugador especifico
    GameList aux;
    int id = searchiDFromName(nickPlayer);
    FILE * archi = fopen("MatchFile.dat", "rb");
    if (archi){
        while (fread(&aux, sizeof(GameList), 1, archi) > 0){
            if (aux.player1.idPlayer == id || aux.player2.idPlayer == id){
                printMatch(aux);
            }
        }
        fclose(archi);
    }
}

