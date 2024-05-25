#include "chesspiece.h"

// Instantiating the static Member Variable
int Chesspiece::numberOfPieces = 0;

Chesspiece::Chesspiece(){
    this->numberOfPieces++;
    this->name  = "";
    this->type = true;
}

Chesspiece::Chesspiece(Chesspiece &obj){
    this->type = obj.getType();
    this->name = obj.getName();
    this->numberOfPieces= obj.getNumberOfPieces();
    this->numberOfPieces++;
}
