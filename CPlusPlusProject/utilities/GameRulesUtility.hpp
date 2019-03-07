//
//  GameRulesUtility.hpp
//  CPlusPlusProject
//
//  Created by Jesus' Blood on 12/27/18.
//  Copyright © 2018 Jesus' Blood. All rights reserved.
//

#ifndef GameRulesUtility_hpp
#define GameRulesUtility_hpp

#include <stdio.h>

bool isWin(int mark, int board[3][3]);
int getWinner(int board[3][3]);
bool checkValidMove(int x, int y, int board[3][3]);
bool isBoardFull(int board[3][3]);

#endif /* GameRulesUtility_hpp */

