//
//  GameActionUtility.cpp
//  CPlusPlusProject
//
//  Created by Jesus' Blood on 1/3/19.
//  Copyright © 2019 Jesus' Blood. All rights reserved.
//


#include <iostream>
#include <cstdlib>
#include "Constants.hpp"
#include "GameActionUtility.hpp"

using namespace std;

void clearBoard(int (&board)[3][3], int& currentPlayer){                      //CLeards the board!
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = EMPTY;        //Set every cell in the board to EMPTY
        }
    }
    currentPlayer = X;                  // Player X starts first
    //return;                           //not needed
}
