#include <iostream>
#include <string>
#include "io.h"
#include "main.h"
#include "chess.h"
#include <fstream>

using namespace std;


bool parsePosition(string value, int position[2]){
    char letters[8] = {'a','b','c','d','e','f','g','h'};
    
    for(int i = 0; i < 8; i++)
    {
        if (value.length() > 2)
        {
            return false;
        }
        if (letters[i] == value[0] && value[1] - 49 > -1 && value[1] - 49 < 8) {
            position[1] = i;
            position[0] = value[1] - 49;
            return true;
        }
        
    }
    return false;
    
}
bool getMove(int actual_position_player[2], int next_position_player[2]){
    string position_player_str = "";          
    getline(cin, position_player_str);
    string pos0 = "";
    string pos1 = "";
    short int pos = 0;
    int len_pos = position_player_str.length();
    for(int i = 0; i < len_pos; i++)
    {
        if (position_player_str[i] == ' ') {
            pos += 1;
            continue;
        }   
        if (pos == 0) {
            pos0 += position_player_str[i];
        }
        else if (pos == 1)
        {
            pos1 += position_player_str[i];
        }
    }
    bool value_position0 = parsePosition(pos0, actual_position_player);
    bool value_position1 = parsePosition(pos1, next_position_player);
    if (value_position1 == false || value_position0 == false) {
        cout << "Ingreso una posición no valida, intentelo denuevo \n";
        return false;
    }
    return true;
}
bool getFileMove(string position_player_str, int line_number, int actual_position_player[2], int next_position_player[2]){
    string pos0 = "";
    string pos1 = "";
    short int pos = 0;
    int len_pos = position_player_str.length();
    for(int i = 0; i < len_pos; i++)
    {
        if (position_player_str[i] == ' ') {
            pos += 1;
            continue;
        }   
        if (pos == 0) {
            pos0 += position_player_str[i];
        }
        else if (pos == 1)
        {
            pos1 += position_player_str[i];
        }
    }
    bool value_position0 = parsePosition(pos0, actual_position_player);
    bool value_position1 = parsePosition(pos1, next_position_player);
    if (value_position1 == false || value_position0 == false) {
        cout << "En la linea " << line_number << " fallo una jugada\n";
        return false;
    }
    return true;
}
void Console2Players(){
    Chest chest;
    chest.CreateChest();
    chest.printChest();
    /*    Game     */
    string player1 = "";
    string player2 = "";
    cout << "Ingrese el nombre del jugador 1: ";
    getline(cin, player1);
    cout << "Ingrese el nombre del jugador 2: ";
    getline(cin, player2);    
    bool continue_game = true;
    while(continue_game)
    {
        /* First Player Move */
        int next_position_player_1[2];
        int actual_position_player_1[2];
        while (true){
            cout << "Ingrese la jugada del jugador 1: ";  
            bool value_position = getMove(actual_position_player_1, next_position_player_1);
            if (value_position == false) {
                continue;
            }
            else
            {
                if (chest.chest[actual_position_player_1[0]][actual_position_player_1[1]].team == 'D')
                {
                    cout << "No puedes mover la pieza de tu rival!\n";
                    continue;
                }
                bool can_insert = chest.insertValue(chest.chest[actual_position_player_1[0]][actual_position_player_1[1]], next_position_player_1, continue_game);
                if (continue_game == false)
                {
                    cout << "El jugador " << player1 << " a ganado!\n";
                    break;
                }
                if (can_insert == false) {
                    continue;
                }
                break;
            }
        }
        chest.printChest();
        /* Second Player Move */
        int next_position_player_2[2];
        int actual_position_player_2[2];
        while (true){
            cout << "Ingrese la jugada del jugador 2: ";  
            bool value_position = getMove(actual_position_player_2, next_position_player_2);
            if (value_position == false) {
                continue;
            }
            else
            {
                if (chest.chest[actual_position_player_2[0]][actual_position_player_2[1]].team == 'W')
                {
                    cout << "No puedes mover la pieza de tu rival!\n";
                    continue;
                }
                bool can_insert = chest.insertValue(chest.chest[actual_position_player_2[0]][actual_position_player_2[1]], next_position_player_2, continue_game);
                if (continue_game == false)
                {
                    cout << "El jugador " << player2 << " a ganado!\n";
                    break;
                }
                if (can_insert == false) {
                    continue;
                }
                break;
            }
        }
        chest.printChest();
    }
}

void GameReadingFile(const char *name_file){
    Chest chest;
    chest.CreateChest();
    chest.printChest();
    ifstream file;
    file.open(name_file);
    string jugada;
    long int file_line = 1;
    bool continue_game = true;
    int actual_position_player_1[2];
    int next_position_player_1[2];
    int actual_position_player_2[2];
    int next_position_player_2[2];
    while(!file.eof() && continue_game)
    {
        getline(file, jugada);
        file_line += 1;
        cout << "Jugada " << jugada << "\n";
        bool value_position = getFileMove(jugada, file_line, actual_position_player_1, next_position_player_1);
        if (value_position == false) {
            continue;
        }
        else {
            if (chest.chest[actual_position_player_1[0]][actual_position_player_1[1]].team == 'D')
            {
                cout << "No puedes mover la pieza de tu rival!\n";
                continue;
            }
            chest.insertValue(chest.chest[actual_position_player_1[0]][actual_position_player_1[1]], next_position_player_1, continue_game);
            if (continue_game == false)
            {
                cout << "El jugador blanco a ganado!\n";
                break;
            }
        }
        chest.printChest();
        if (!file.eof() && continue_game) {
            getline(file, jugada);
            cout << "Jugada " << jugada << "\n";
            file_line += 1; 
            bool value_position = getFileMove(jugada, file_line, actual_position_player_2, next_position_player_2);
            if (value_position == false) {
                continue;
            }
            else {
                if (chest.chest[actual_position_player_2[0]][actual_position_player_2[1]].team == 'W')
                {
                    cout << "No puedes mover la pieza de tu rival!\n";
                    continue;
                }
                chest.insertValue(chest.chest[actual_position_player_2[0]][actual_position_player_2[1]], next_position_player_2, continue_game);
                if (continue_game == false)
                {
                    cout << "El jugador negro a ganado!\n";
                    break;
                }
            }
            chest.printChest();
        } 
    }
    if (continue_game) {
        cout << "El juego no a acabado, porfavor continue jugando\n";
        while (true){
            cout << "Ingrese la jugada del blanco: ";  
            bool value_position = getMove(actual_position_player_1, next_position_player_1);
            if (value_position == false) {
                continue;
            }
            else
            {
                if (chest.chest[actual_position_player_1[0]][actual_position_player_1[1]].team == 'D')
                {
                    cout << "No puedes mover la pieza de tu rival!\n";
                    continue;
                }
                bool can_insert = chest.insertValue(chest.chest[actual_position_player_1[0]][actual_position_player_1[1]], next_position_player_1, continue_game);
                if (continue_game == false)
                {
                    cout << "El jugador blanco a ganado!\n";
                    break;
                }
                if (can_insert == false) {
                    continue;
                }
                break;
            }
        }
        chest.printChest();
        while (true){
            cout << "Ingrese la jugada del negro: ";  
            bool value_position = getMove(actual_position_player_2, next_position_player_2);
            if (value_position == false) {
                continue;
            }
            else
            {
                if (chest.chest[actual_position_player_2[0]][actual_position_player_2[1]].team == 'W')
                {
                    cout << "No puedes mover la pieza de tu rival!\n";
                    continue;
                }
                bool can_insert = chest.insertValue(chest.chest[actual_position_player_2[0]][actual_position_player_2[1]], next_position_player_2, continue_game);
                if (continue_game == false)
                {
                    cout << "El jugador negro a ganado!\n";
                    break;
                }
                if (can_insert == false) {
                    continue;
                }
                break;
            }
        }
        chest.printChest();   
    }
}