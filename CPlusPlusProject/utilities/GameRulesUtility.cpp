//
//  GameRulesUtility.cpp
//  CPlusPlusProject
//
//  Created by Jesus' Blood on 12/27/18.
//  Copyright © 2018 Jesus' Blood. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "Constants.hpp"
#include "GameRulesUtility.hpp"

using namespace std;


bool isWin(int mark, int board[3][3]){                   // is mark the winner?
    int win = 3*mark;                   // mark = +3 (X) or -3 (O)
    return (
            (board[0][0] + board[0][1] + board[0][2] == win)        // row 0
            || (board[1][0] + board[1][1] + board[1][2] == win)     // row 1
            || (board[2][0] + board[2][1] + board[2][2] == win)     // row 2
            || (board[0][0] + board[1][0] + board[2][0] == win)     // col 0
            || (board[0][1] + board[1][1] + board[2][1] == win)     // col 1
            || (board[0][2] + board[1][2] + board[2][2] == win)     // col 2
            || (board[0][0] + board[1][1] + board[2][2] == win)     // diag
            || (board[2][0] + board[1][1] + board[0][2] == win)     // diag
            
            );
}



int getWinner(int board[3][3]){ //who wins? (EMPTY = TIE)
    if (isWin(X, board)) return X;
    else if(isWin(O, board)) return O;
    else return EMPTY;
}
bool checkValidMove(int x, int y, int board[3][3]){ //Checks if the given input is a valid move
    //Conditions:
    /// If Move is out of scope (x or y is > 2 or < 0), not valid
    /// If Move is already taken on board, not valid
    /// else, we have a valid move!
    bool isValidMove = true;
    
    if(x > 2 || y > 2 || x < 0 || y < 0){
        isValidMove = false;
        cout << "\n\n invalid move! Please try again!";
    }
    
    if(board[x][y] != EMPTY){
        isValidMove = false;
        cout << "\n\n Move aleady taken! Please try again!";
    }
    
    return isValidMove;
    
}

bool isBoardFull(int board[3][3]){
    //Assume the board is full
    
    //If ANY of the board cells is EMPTY, board is NOT full
    for(int x = 0; x <=2; x++){
        for(int y = 0; y <=2; y++){
            if(board[x][y] == EMPTY){
                return false;
            }
        }
    }
    return true;
}
