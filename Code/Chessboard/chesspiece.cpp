#include "chesspiece.h"

// Instantiating the static Member Variable
int Chesspiece::numberOfPieces = 0;

Chesspiece::Chesspiece(){
    this->numberOfPieces++;
    this->name  = "";
    this->type = true;
}
