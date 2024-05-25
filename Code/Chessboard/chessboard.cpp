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
