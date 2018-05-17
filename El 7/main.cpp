#include <iostream>
#include <string.h>
#include "main.h"
#include "chess.h"
#include "io.h"
using namespace std;

int main(int argc, char const *argv[]){
    if (argc == 1)
    {
        Console2Players();
    }
    else if (argc > 1 && strcmp(argv[1], "-t") == 0)
    {
        GameReadingFile(argv[2]);
    }
    else{
        cout << "Revisa los flags porfavor!\n";
    }
    
}