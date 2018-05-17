#ifndef IO_H_
#define IO_H_
#include <string>


bool parsePosition(std::string value, int position[2]);
bool getMove(int actual_position_player[2], int next_position_player[2]);
void Console2Players();
void GameReadingFile(const char *name_file);
#endif