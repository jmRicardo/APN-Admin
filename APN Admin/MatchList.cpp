#include "MatchList.h"
#include "Players.h"

int searchLastMatch(){   ///funcion que devuelve el id de la ultima partida jugada
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
    std::cout << "idPlayer: " << score.idPlayer << std::endl;
    std::cout << "Match Time : " << score.matchTime << std::endl;
    std::cout << "Score Time: " << score.scoreTime << std::endl;
}

void printMatch(GameList match){   ///funcion auxiliar que muestra una sola partida
    std::cout << "idMatch: " << match.idMatch << std::endl;
    printScore(match.player1);
    printScore(match.player2);
    if (match.whoWon){
        std::cout << "Player 1 won" << match.whoWon << std::endl;
    }else{
        std::cout << "Player 2 won" << match.whoWon << std::endl;
    }
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
        fread(&aux, sizeof(Player), 1, archi);
    }
    return aux;
}

Player traemeotro(){   ///funcion auxiliar para cargar un player
    Player aux;
    FILE * archi = fopen("players.dat", "rb");
    if (archi){
        fread(&aux, sizeof(Player), 2, archi);
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

void listaToArrayOfPlayers(cell adl[], int cant){
    GameList aux;
    int i = 0;
    FILE * archi = fopen("MatchFile.dat", "rb");
    if (archi){
        while (fread(&aux, sizeof(GameList), 1, archi) > 0){
            nodoGameList * helper = createNodo(aux);
            i = searchPosInArray(adl, cant, helper->dato.player1.idPlayer);
            adl[i].lista = addToBeginning(adl[i].lista, helper);
        }
        fclose(archi);
    }
}













