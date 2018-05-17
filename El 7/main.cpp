#include <iostream>
#include <string>
#include "main.h"
#include "chess.h"
#include "io.h"
using namespace std;

int main(int argc, char const *argv[]){
    if (argc == 1)
    {
        Console2Players();
    }
    else if (argc > 1)
    {
        GameReadingFile(argv[2]);
    }
    
}