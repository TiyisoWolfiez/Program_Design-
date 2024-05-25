#include "chessboard.h"
#include "chesspiece.h"

Chessboard::Chessboard(Chessboard &obj){
    this->rows = obj.rows;
    this->columns = obj.columns;
    this->board = new Chesspiece**[this->rows];
    for(int k_iterator = 0;k_iterator<this->rows;k_iterator++){
        this->board[k_iterator] = new Chesspiece*[this->columns];
        for(int t_iterator = 0;t_iterator<this->columns;t_iterator++){
            if(obj.board[k_iterator][t_iterator]==NULL){
                this->board[k_iterator][t_iterator] = NULL;
            }
            else{
                this->board[k_iterator][t_iterator] = new Chesspiece(*obj.board[k_iterator][t_iterator]);
            }
        }
    }
}

Chessboard::Chessboard(int in_rows, int in_columns){
    this->rows = in_rows;
    this->columns = in_columns;
    this->board = new Chesspiece**[this->rows];
    for(int k_iterator = 0;k_iterator<this->rows;k_iterator++){
        this->board[k_iterator] = new Chesspiece*[this->columns];
        for(int t_iterator = 0;t_iterator<this->columns;t_iterator++){
            this->board[k_iterator][t_iterator] = NULL;
        }
    }
}

Chessboard::~Chessboard(){
    for(int k_iterator = 0;k_iterator<this->rows;k_iterator++){
        for(int t_iterator = 0;t_iterator<this->columns;t_iterator++){
            delete this->board[k_iterator][t_iterator];
            this->board[k_iterator][t_iterator] = NULL;
        }
        delete[] this->board[k_iterator];
        this->board[k_iterator] = NULL;
    }
    delete [] this->board;
    this->board = NULL;
}

void Chessboard::addChesspiece(Chesspiece *piece, int row, int column){
    this->board[row][column] = piece;
}
