#ifndef CHESS_H_
#define CHESS_H_
class Chest;
class Piece
{
    public:
        char team;
        int position[2];
        char type_name;
        int pos_team_array;
        bool (*Move) (Chest, Piece, int[2]);
};
class Chest
{
    public:
        Piece black_team[15];
        Piece white_team[15];
        Piece chest [8][8]; 
    void CreateChest();    
    bool insertValue(Piece piece, int position[2], bool continue_game);
    void printChest();
};
bool MoveKnight(Chest chest, Piece knight, int position[2]);
bool MoveQueen(Chest chest, Piece knight, int position[2]);
bool MoveKing(Chest chest, Piece knight, int position[2]);
bool MoveHorse(Chest chest, Piece knight, int position[2]);
bool MovePawn(Chest chest, Piece knight, int position[2]);
bool MoveTower(Chest chest, Piece knight, int position[2]);
bool getMove(int actual_position_player[2], int next_position_player[2]);

#endif