#include "Players.h"
#include <stdbool.h>

/// carga el jugador y devuelve falso si ya existe, usar este dato para mostrar cartel de " YA EXISTE "
bool loadPlayer(char playerNick[]){
    bool flag = checkPlayer(playerNick);
    if (flag)
    {
        Player aux;
        int id = searchLastID() + 1;
        FILE * archi = fopen("players.dat", "ab");
        if (archi)
        {
            aux.idPlayer = id;
            strcpy(aux.nick,playerNick);
            aux.active = true;
            fwrite(&aux,sizeof(Player),1,archi);
        }
        fclose(archi);
    }
    return flag;
}

int searchLastID()       /// se para en el ultimo bloque de archivo y retorna su ID
{
    int id = 0;
    Player aux;
    FILE * archi = fopen("players.dat", "rb");
    if (archi)
    {
        if (fseek(archi,-1*sizeof(Player),SEEK_END))
            fread(&aux,sizeof(Player),1,archi);
            id = aux.idPlayer;
    }
    fclose(archi);
    return id;
}

bool checkPlayer(char playerNick[]){            /// recorre el archivo, lo busca (a un Player), si existe devuelve 0
    FILE * archi = fopen("players.dat", "rb");
    Player aux;
    bool flag = true;
    if (archi){
        while (fread(&aux, sizeof(Player), 1, archi)>0 && flag)
        {
           if (!strcmpi(aux.nick,playerNick))
            flag = false;
        }
    }
    fclose(archi);
    return flag;
}

void printPlayer(Player p)  ///funcion auxiliar que imprime un player por pantalla (con o sin el active)
{
    printf("\n    Id: %d", p.idPlayer);
    printf("\n  Nick: %s", p.nick);
    printf("\nActive: %d", p.active);
    /*std::cout << p.idPlayer << std::endl;
    std::cout << p.nick << std::endl;
    std::cout << p.active << std::endl;*/
}

void printFilePlayers()   ///imprime por pantalla todos los players desde el archivo
{
    FILE * archi = fopen("players.dat","rb");
    Player aux;
    if (archi)
    {
        while (fread(&aux,sizeof(Player),1,archi)>0)
        {
            printPlayer(aux);
        }
        fclose(archi);
    }

}

void deactivatePlayer(char playerNick[]){   ///funcion que desactiva (borra) un Player
    Player aux;
    int iD = searchiDFromName(playerNick);
    printf("\nID: %d\n", iD);
    //bool pepe = true;
    FILE * archi = fopen("players.dat", "rb+");
    if (archi){
        fseek(archi, ((iD-1)*sizeof(Player)), SEEK_SET);
        fread(&aux, sizeof(Player), 1, archi);
        //printf("\n---ID---%d\n", iD);
        //printPlayer(aux);
        aux.active = false;
        fseek(archi, ((iD-1)*sizeof(Player)), SEEK_SET);
        fwrite(&aux, sizeof(Player), 1, archi);

        fclose(archi);
    }
    printPlayer(aux);
    printFilePlayers();
}

void printActivePlayers(){   ///imprime Players activos
    Player aux;
    FILE * archi = fopen("players.dat", "rb");
    if (archi){
        while (fread(&aux, sizeof(Player), 1, archi) > 0){
            if (aux.active == true){
                printPlayer(aux);
            }
        }
        fclose(archi);
    }
}

void printInactivePlayers(){   ///imprime Players inactivos
    Player aux;
    FILE * archi = fopen("players.dat", "rb");
    if (archi){
        while (fread(&aux, sizeof(Player), 1, archi) > 0){
            if (aux.active == false){
                printPlayer(aux);
            }
        }
        fclose(archi);
    }
}

void insertInArray(Player a[], int cant, Player dato){   ///funcion auxiliar para el metodo de insercion
    int i = cant;
    while (i >=0 && (strcmpi(dato.nick, a[i].nick) < 0)){
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = dato;
}

void incertion(Player a[], int cant){   ///insercion
    int i = 0;
    while (i < cant-1){
        insertInArray(a, i, a[i + 1]);
        i++;
    }
}

int fromFileToArrayOfPlayers(Player a[], int dim){   ///pasar del archivo a un arreglo de Players
    Player aux;
    int i = 0;
    FILE * archi = fopen("players.dat", "rb");
    if (archi){
        while (fread(&aux, sizeof(Player), 1, archi) > 0){
            a[i] = aux;
            i++;
        }
        fclose(archi);
    }
    return i;
}

void printArrayOfPlayersPlayers(Player a[], int cant){   ///imprimimos un arreglo de Players
    int i = 0;
    for (i=0; i<cant; i++){
        printPlayer(a[i]);
    }
}

int searchiDFromName(char nickPlayer[]){   ///funcion auxiliar que devuelve el iD de un player recibiendo el nick
    FILE * archi = fopen("players.dat", "rb");
    Player aux;
    int iD = -1;
    if (archi){
        while (fread((&aux), sizeof(Player), 1, archi) > 0){
            if (strcmpi(nickPlayer, aux.nick) == 0){
                iD = aux.idPlayer;
            }
        }
        fclose(archi);
    }
    return iD;
}

















