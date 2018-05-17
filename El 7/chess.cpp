#include <iostream>
#include <string>
#include "chess.h"
#include "main.h"
using namespace std;


void Chest::CreateChest()
{
    /*    Create Chest   */
    int black_team_pos = 0;
    int white_team_pos = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int x = 0; x < 8;x++)
        {
            
            if (i == 7) {
                /* code */
                
                if (x == 0 || x == 7) {
                    Piece tower;
                    tower.Move = MoveTower;
                    tower.team = 'W';
                    tower.type_name = 'T';
                    tower.position[0] = i;
                    tower.position[1] = x;
                    tower.pos_team_array = white_team_pos;
                    this->white_team[white_team_pos] = tower;
                    white_team_pos++;
                    this->chest[i][x] = tower;
                }
                
                else if (x == 1 || x == 6)
                {
                    Piece horse;
                    horse.team = 'W';
                    horse.Move = MoveHorse;
                    horse.type_name = 'N';
                    horse.position[0] = i;
                    horse.position[1] = x;
                    horse.pos_team_array = white_team_pos;
                    this->white_team[white_team_pos] = horse;
                    white_team_pos++;
                    this->chest[i][x] = horse;
                }
                
                else if (x == 2 || x == 5)
                {
                    Piece pawn;
                    pawn.Move = MovePawn;
                    pawn.team = 'W';
                    pawn.type_name = 'B';
                    pawn.position[0] = i;
                    pawn.position[1] = x;
                    pawn.pos_team_array = white_team_pos;
                    this->white_team[white_team_pos] = pawn;
                    white_team_pos++;
                    this->chest[i][x] = pawn;
                }
                
                else if (x == 4)
                {
                    Piece king;
                    king.Move = MoveKing;
                    king.team = 'W';
                    king.type_name = 'K';
                    king.position[0] = i;
                    king.position[1] = x;
                    king.pos_team_array = white_team_pos;
                    this->white_team[white_team_pos] = king;
                    white_team_pos++;
                    this->chest[i][x] = king;
                }
            
                else
                {
                    Piece queen;
                    queen.Move = MoveQueen;
                    queen.team = 'W';
                    queen.type_name = 'Q';
                    queen.position[0] = i;
                    queen.position[1] = x;
                    queen.pos_team_array = white_team_pos;
                    this->white_team[white_team_pos] = queen;
                    white_team_pos++;
                    this->chest[i][x] = queen;
                }   
            }
            
            else if (i == 0)
            {
                if (x == 7) {
                    Piece tower;
                    tower.Move = MoveTower;
                    tower.team = 'D';
                    tower.type_name = 'T';
                    tower.position[0] = i;
                    tower.position[1] = x;
                    tower.pos_team_array = black_team_pos;
                    this->black_team[black_team_pos] = tower;
                    black_team_pos++;
                    this->chest[i][x] = tower;
                }
                
                else if (x == 1 || x == 6)
                {
                    Piece horse;
                    horse.Move = MoveHorse;
                    horse.team = 'D';
                    horse.type_name = 'N';
                    horse.position[0] = i;
                    horse.position[1] = x;
                    horse.pos_team_array = black_team_pos;
                    this->black_team[black_team_pos] = horse;
                    black_team_pos++;
                    this->chest[i][x] = horse;
                }
                
                else if (x == 2 || x == 5)
                {
                    Piece pawn;
                    pawn.Move = MovePawn;
                    pawn.team = 'D';
                    pawn.type_name = 'B';
                    pawn.position[0] = i;
                    pawn.position[1] = x;
                    pawn.pos_team_array = black_team_pos;
                    this->black_team[black_team_pos] = pawn;
                    black_team_pos++;
                    this->chest[i][x] = pawn;
                }
                
                else if (x == 4)
                {
                    Piece queen;
                    queen.Move = MoveQueen;
                    queen.team = 'D';
                    queen.type_name = 'Q';
                    queen.position[0] = i;
                    queen.position[1] = x;
                    queen.pos_team_array = black_team_pos;
                    this->black_team[black_team_pos] = queen;
                    black_team_pos++;
                    this->chest[i][x] = queen;                        
                }
                
                else
                {
                    Piece king;
                    king.team = 'D';
                    king.Move = MoveKing;
                    king.type_name = 'K';
                    king.position[0] = i;
                    king.position[1] = x;
                    king.pos_team_array = black_team_pos;
                    this->black_team[black_team_pos] = king;
                    black_team_pos++;
                    this->chest[i][x] = king;
                }  
            }
            
            else if (i == 6)
            {
                Piece knight;
                knight.Move = MoveKnight;
                knight.team = 'W';
                knight.type_name = 'P';
                knight.position[0] = i;
                knight.position[1] = x;
                knight.pos_team_array = white_team_pos;
                this->white_team[white_team_pos] = knight;
                white_team_pos++;
                this->chest[i][x] = knight;
            }
            
            else if (i == 1)
            {
                Piece knight;
                knight.Move = MoveKnight;
                knight.team = 'D';
                knight.type_name = 'P';
                knight.position[0] = i;
                knight.position[1] = x;
                knight.pos_team_array = black_team_pos;
                this->black_team[black_team_pos] = knight;
                black_team_pos++;
                this->chest[i][x] = knight;
            }
            
            else
            {
                Piece piece;
                piece.team = 'X';
                piece.type_name = 'X';
                piece.position[0] = -1;
                this->chest[i][x] = piece;
            }
        }
    }
    Piece tower;
    tower.Move = MoveTower;
    tower.team = 'D';
    tower.type_name = 'T';
    tower.position[0] = 0;
    tower.position[1] = 0;
    tower.pos_team_array = black_team_pos;
    this->black_team[black_team_pos] = tower;
    black_team_pos++;
    this->chest[0][0] = tower;
}
bool Chest::insertValue(Piece piece, int position[2], bool continue_game)
{
    Chest *the_chest = this;
    Chest chest = *the_chest;
    bool piece_can_move_to_place = piece.Move(chest ,piece, position);
    if (piece_can_move_to_place == false) {
        return false;
    }
    if (this->chest[position[0]][position[1]].team != piece.team)
    {
        if (this->chest[piece.position[0]][piece.position[1]].type_name == 'K' && continue_game)
        {
            continue_game = false;
        }
        this->chest[piece.position[0]][piece.position[1]].team = 'X';
        this->chest[piece.position[0]][piece.position[1]].type_name = 'X';
        this->chest[piece.position[0]][piece.position[1]].position[0] = -1;
        piece.position[0] = position[0];
        piece.position[1] = position[1];
        this->chest[position[0]][position[1]] = piece;
        return true;
    }
    
    else if (this->chest[position[0]][position[1]].team == piece.team)
    {
        cout <<  "No puedes atacar a tu mismo equipo!\n";
        return false;
    }
    
    else if (position[0] > 8 || position[0] < 0 || position[1] > 8 || position[1] < 0)
    {
        return false;
    }
    
    else
    {
        this->chest[piece.position[0]][piece.position[1]].team = 'X';
        this->chest[piece.position[0]][piece.position[1]].type_name = 'X';
        this->chest[piece.position[0]][piece.position[1]].position[0] = -1;
        piece.position[0] = position[0];
        piece.position[1] = position[1];
        this->chest[position[0]][position[1]] = piece;
        return true;
    }
}
void Chest::printChest()
{
    cout << "      a    b    c    d    e    f    g    h    \n   ";
    for(int c = 0; c < 8; c++)
    {
        /* code */
        cout << "-----";
    }
    cout << "-";
    cout << "\n";
    for(int i = 7; i > -1; i--)
    {
        cout << i + 1;
        cout << "  |";
        for(int x = 0; x < 8;x++)
        {
            
            if (this->chest[i][x].position[0] == -1)
            {
                cout << "    |";
            }
            else
            {
                cout << " " << this->chest[i][x].type_name << this->chest[i][x].team << " |";
            }
            
            if (x == 7) {
                cout << "  ";
                cout << i + 1;
                cout << "\n   ";
                
                for(int c = 0; c < 8; c++)
                {
                    /* code */
                    cout << "-----";
                }
                cout << "-\n";
                
            }
            
        }
        
    }
    cout << "      a    b    c    d    e    f    g    h    \n";
} 

bool MoveKnight(Chest chest, Piece knight, int position[2]){ 
    if (knight.team == 'D') {
        if (position[0] == knight.position[0] + 2 && position[1] == knight.position[1] && knight.position[0] == 1)
        {
            return true;
        }
        else if (position[0] == knight.position[0] + 1 && position[1] == knight.position[1])
        {
            return true;
        }
        else if ((position[0] == knight.position[0] + 1 && position[1] == knight.position[1] + 1 && chest.chest[knight.position[0] + 1][knight.position[1] + 1].team == 'D') || (position[0] == knight.position[0] + 1 && position[1] == knight.position[1] - 1 && chest.chest[knight.position[0] + 1][knight.position[1] - 1].team == 'D'))
        {
            return true;
        }
        return false;
    }
    else if (knight.team == 'W') {
        if (position[0] == knight.position[0] - 2 && position[1] == knight.position[1] && knight.position[0] == 6)
        {
            return true;
        }
        else if (position[0] == knight.position[0] - 1 && position[1] == knight.position[1])
        {
            return true;
        }
        else if ((position[0] == knight.position[0] - 1 && position[1] == knight.position[1] + 1 && chest.chest[knight.position[0] - 1][knight.position[1] + 1].team == 'W') || (position[0] == knight.position[0] - 1 && position[1] == knight.position[1] - 1 && chest.chest[knight.position[0] - 1][knight.position[1] - 1].team == 'W'))
        {
            return true;
        }
        return false;
    }
    return false;
    
}
bool MoveQueen(Chest chest, Piece queen, int position[2]){
    int queen_x = queen.position[1];
    int queen_y = queen.position[0];
    /*  To_Right */
    for(int i = queen_x + 1; i < 8; i++)
    {
        if (position[0] == queen_y && position[1] == i) {
            return true;
        }
        else if (chest.chest[queen_y][i].type_name != 'X')
        {
            break;
        }
    }
    /*  To_Left  */
    for(int i = queen_x - 1; i > -1; i--)
    {
        if (position[0] == queen_y && position[1] == i) {
            return true;
        }
        else if (chest.chest[queen_y][i].type_name != 'X')
        {
            break;
        }
    }
    /*  To_Top   */
    for(int i = queen_y - 1; i > -1; i--)
    {
        if (position[0] == i && position[1] == queen_x) {
            return true;
        }
        else if (chest.chest[i][queen_x].type_name != 'X')
        {
            break;
        }
    }
    /* To_Bottom */
    for(int i = queen_y + 1; i < 8; i++)
    {
        if (position[0] == i && position[1] == queen_x) {
            return true;
        }
        else if (chest.chest[i][queen_x].type_name != 'X')
        {
            break;
        }
    }
    /*  To_Top Left   */
    int x = queen_x - 1;
    int y = queen_y - 1;
    while(x > -1 && y > -1)
    {
        if (position[0] == y && position[1] == x) {
            return true;
        
        }
        else if (chest.chest[y][x].type_name != 'X')
        {
            break;
        }
        x--;
        y--;
    }
    /*  To_Top Right */
    x = queen_x + 1;
    y = queen_y - 1;
    while(x < 8 && y > -1)
    {
        if (position[0] == y && position[1] == x) {
            return true;
        }
        else if (chest.chest[y][x].type_name != 'X')
        {
            break;
        }
        x++;
        y--;
    }
    /*  To_Bottom Left  */
    x = queen_x - 1;
    y = queen_y + 1;
    while(x > -1 && y < 8)
    {
        if (position[0] == y && position[1] == x) {
            return true;
        }
        else if (chest.chest[y][x].type_name != 'X')
        {
            break;
        }
        x--;
        y++;
    }
    /*  To_Bottom Right  */
    x = queen_x + 1;
    y = queen_y + 1;
    while(x < 8 && y < 8)
    {
        if (position[0] == y && position[1] == x) {
            return true;
        }
        else if (chest.chest[y][x].type_name != 'X')
        {
            break;
        }
        x++;
        y++;
    }
    return false;
}
bool MoveKing(Chest chest, Piece king, int position[2]){
    int king_x = king.position[1];
    int king_y = king.position[0];
    if (chest.chest[0][0].position[0] == 0)
    {

    }
    if (king_x + 1 == position[1] && king_y == position[0]) {
        return true;
    }
    
    else if (king_x == position[1] && king_y + 1 == position[0])
    {
        return true;
    }
    else if (king_x == position[1] && king_y - 1 == position[0])
    {
        return true;
    }
    else if (king_x - 1 == position[1] && king_y == position[0])
    {
        return true;
    }
    else if (king_x + 1 == position[1] && king_y + 1 == position[0])
    {
        return true;
    }
    else if (king_x - 1 == position[1] && king_y + 1 == position[0])
    {
        return true;
    }
    else if (king_x + 1 == position[1] && king_y - 1 == position[0])
    {
        return true;
    }
    else if (king_x - 1 == position[1] && king_y - 1 == position[0])
    {
        return true;
    }
    else
    {
        return false;
    }
    

}
bool MovePawn(Chest chest, Piece pawn, int position[2]){
    
    /*  To_Top Left   */
    int x = pawn.position[1] - 1;
    int y = pawn.position[0] - 1;
    while(x > -1 && y > -1)
    {
        if (position[0] == y && position[1] == x) {
            return true;
        
        }
        else if (chest.chest[y][x].type_name != 'X')
        {
            break;
        }
        x--;
        y--;
    }
    /*  To_Top Right */
    x = pawn.position[1] + 1;
    y = pawn.position[0] - 1;
    while(x < 8 && y > -1)
    {
        if (position[0] == y && position[1] == x) {
            return true;
        }
        else if (chest.chest[y][x].type_name != 'X')
        {
            break;
        }
        x++;
        y--;
    }
    /*  To_Bottom Left  */
    x = pawn.position[1] - 1;
    y = pawn.position[0] + 1;
    while(x > -1 && y < 8)
    {
        if (position[0] == y && position[1] == x) {
            return true;
        }
        else if (chest.chest[y][x].type_name != 'X')
        {
            break;
        }
        x--;
        y++;
    }
    /*  To_Bottom Right  */
    x = pawn.position[1] + 1;
    y = pawn.position[0] + 1;
    while(x < 8 && y < 8)
    {
        if (position[0] == y && position[1] == x) {
            return true;
        }
        else if (chest.chest[y][x].type_name != 'X')
        {
            break;
        }
        x++;
        y++;
    }
    return false;
}
bool MoveTower(Chest chest, Piece tower, int position[2]){
    int queen_x = tower.position[1];
    int queen_y = tower.position[0];
    /*  To_Right */
    for(int i = queen_x + 1; i < 8; i++)
    {
        if (position[0] == queen_y && position[1] == i) {
            return true;
        }
        else if (chest.chest[queen_y][i].type_name != 'X')
        {
            break;
        }
    }
    /*  To_Left  */
    for(int i = queen_x - 1; i > -1; i--)
    {
        if (position[0] == queen_y && position[1] == i) {
            return true;
        }
        else if (chest.chest[queen_y][i].type_name != 'X')
        {
            break;
        }
    }
    /*  To_Top   */
    for(int i = queen_y - 1; i > -1; i--)
    {
        if (position[0] == i && position[1] == queen_x) {
            return true;
        }
        else if (chest.chest[i][queen_x].type_name != 'X')
        {
            break;
        }
    }
    /* To_Bottom */
    for(int i = queen_y + 1; i < 8; i++)
    {
        if (position[0] == i && position[1] == queen_x) {
            return true;
        }
        else if (chest.chest[i][queen_x].type_name != 'X')
        {
            break;
        }
    }
    return false;
}
bool MoveHorse(Chest chest, Piece horse, int position[2]){
    int horse_x = horse.position[1];
    int horse_y = horse.position[0];
    if (chest.chest[0][0].position[0] == 0)
    {
        
    }
    if (horse_x + 2 == position[1] && horse_y + 1 == position[0]) {
        return true;
    }
    
    else if (horse_x + 2 == position[1] && horse_y - 1 == position[0])
    {
        return true;
    }
    else if (horse_x + 1 == position[1] && horse_y + 2 == position[0])
    {
        return true;
    }
    else if (horse_x + 1 == position[1] && horse_y - 2 == position[0])
    {
        return true;
    }
    else if (horse_x - 2 == position[1] && horse_y + 1 == position[0])
    {
        return true;
    }
    else if (horse_x - 2 == position[1] && horse_y - 1 == position[0])
    {
        return true;
    }
    else if (horse_x - 1 == position[1] && horse_y - 2 == position[0])
    {
        return true;
    }
    else if (horse_x - 1 == position[1] && horse_y + 2 == position[0])
    {
        return true;
    }
    return false;
} 
