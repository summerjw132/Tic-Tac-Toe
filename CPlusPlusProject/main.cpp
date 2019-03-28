#include <cstdlib>
#include <iostream>
#include "utilities/Constants.hpp"
#include "utilities/GameActionUtility.hpp"
#include "utilities/GameRulesUtility.hpp"

using namespace std;

int board[3][3];
int currentPlayer;

// Game Actions



void putMark(int x, int y){             //mark row i column j
    board[x][y] = currentPlayer;        //mark cell with current player
    currentPlayer = -currentPlayer;
    return;
}
void printBoard(){ //print the board on screen
    int count = 0;
    cout << "\n\n\n\n";
    cout << ((currentPlayer == 1) ? 'X': 'O') << "'s turn:";
    cout << "\n\n";
    for(int i = 0; i<3; i++){
        
        for(int j = 0; j<3; j++){
            count++;
            switch(board[i][j]) {
                case X:     cout << "X"; break;
                case O:     cout << "O"; break;
                case EMPTY: cout << " "; break;
            }
            if(j < 2) cout << "|";          // column boundary
        }
        if (i < 2) {cout << "\n-+-+-\n";}   //row boundary
    }
    
}
void switchPlayers(){
    currentPlayer = -currentPlayer;
}
void game(){
    bool playerIsStillPlaying = true;
    
    while(playerIsStillPlaying){
        
        clearBoard(board, currentPlayer);
        printBoard();
        
        while(getWinner(board) == EMPTY
              && isBoardFull(board) == false){
            //ask for x
            //ask for y
            int x;
            int y;
            cout << "\n\nGimme an X: ";
            cin >> x;
            cout << "\nGimme a Y: ";
            cin >> y;
            
            //put mark down & switch players if it's a valid move
            if(checkValidMove(x, y, board)){
                putMark(x, y);
            }
            //print the board
            printBoard();
            
            //check winner (at the beginning of the loop)
        }
        
        printBoard();
        
        //get and display the winner
        int winner = getWinner(board);
        if(winner != EMPTY){
            cout << " \n\n" << ((winner == 1) ? 'X': 'O') << " wins!" << endl;
        }else{
            cout << " \n\nIt's a Tie!" << endl;
        }
        
        cout << "\n\nPlay again? (y/n)";
        string playAgain;
        cin >> playAgain;
        if(playAgain == "n"){
            playerIsStillPlaying = false;
            
        }
    }
    
}

int main(){
  
    game();
    
    cout<<"\n_________________\n\n"<<endl;
    cout<<"\n\nThanks for playing!";
    cout<<"\n_________________\n\n"<<endl;
    return EXIT_SUCCESS; // just for padding (formatting)
    
    
    //TODO: Play again? --> Separate this into its own method if possible
    //TODO: Exit at any time
    //TODO: Introduce AI into the mix!
    //TODO: Garbage Collection
    //TODO: Move Game Actions into the GameActionUtility class
    //TODO: If I made a mistake, select
    //TODO: Invalid move checking
}

//PvP - Pseudocode:
    /*
     1. Clear board on game start
     -. While Player wants to play
      1   -. While Winner is not decided && board is not full
            2. Check for player input
            3. if key not valid, then WHile key is not valid
                ...check for input
            4. else,
                ...if no one won yet and last move hasn't been made,
                    ...switch players
            5. After Winner/Draw decided
                ...get winner
                ...display message
     */


