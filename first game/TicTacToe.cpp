#include "TicTacToe.h"
#include <iostream>
using namespace std;


void TicTacToe::drawBoard(){
    for (int i=0; i<ROW; i++){

        if(i==0) cout << '\t';

        if(i>0){
            cout << '\t';
            for(int l=0; l<10; l++) cout << '-';
            cout << endl << '\t';
        }

        for (int j=0; j<COL-1; j++){
            cout << board[i][j] << " ";
            if(j<2)cout << "| ";
        }
        cout << endl;
    }
}


char& TicTacToe::boardSpot(){

    switch(spot){

        case 1: 
            return board[0][0];
        case 2:
            return board[0][1];
        case 3:
            return board[0][2];
        case 4:
            return board[1][0];
        case 5:
            return board[1][1];
        case 6:
            return board[1][2];
        case 7:
            return board[2][0];
        case 8:
            return board[2][1];
        case 9:
            return board[2][2];
    }

    return board[0][3];
}


char& TicTacToe::boardSpotMark(int pos){

    switch(pos){

        case 1: 
            return board[0][0];
        case 2:
            return board[0][1];
        case 3:
            return board[0][2];
        case 4:
            return board[1][0];
        case 5:
            return board[1][1];
        case 6:
            return board[1][2];
        case 7:
            return board[2][0];
        case 8:
            return board[2][1];
        case 9:
            return board[2][2];
    }

    return board[0][3];
}


bool TicTacToe::isValidMove(){

    if(0 >= spot || spot > 9){
        cout << "invalid move, choose a spot to take: ";
        return false;
    }

    if(boardSpot() == 'X' || boardSpot() == 'O'){
        cout << "cannot take this spot! choose another: ";
        return false;
    }
    return true;
}

//never got this working
void TicTacToe::sortMoves(int moves[], int size){

    int output[MARKS];
    int *count;
    int max = moves[0];

    for (int i=1; i<MARKS; i++){
        if (moves[i] > max)
            max = moves[i];
    }

    count = new int[max+1];

    for (int i = 0; i<=max; i++)
        count[i]=0;

    for (int i=0; i<MARKS; i++)
        count[moves[i]]++;

    for (int i=1; i<=max; i++)
        count[i]+=count[i-1];

    for (int i=0; i<MARKS; i++){
        output[count[moves[i]]-1] = moves[i];
        count[moves[i]]--;
    }

    for (int i=0; i<MARKS; i++)
        moves[i]=output[i];

    delete [] count;


    return;
}


void TicTacToe::viewMoves(char xo){

    if(xo == 'X'){
        for (int i : playerXMoves) cout << i << ' ';
        return;
    }

    for (int i : playerOMoves) cout << i << ' ';
    return;
}

//never got sorted moves array working, will revise to refelct
bool TicTacToe::isWinner(){

// sort player moves before checking for win
    sortMoves(playerXMoves,MARKS);
    sortMoves(playerOMoves,MARKS);

// check X wins
    if(playerXMoves[0]==1){

        // 1 - 2 - 3 victory
        if(playerXMoves[1]==2){
            if(playerXMoves[2]==3){
                cout << "Player X wins! \n";
                return true;
            }
        }
        
        // 1 - 5 - 9 victory
        if(playerXMoves[1]==5){
            if(playerXMoves[2]==9){
                cout << "Player X wins! \n";
                return true;
            }
        }

        // 1 - 4 - 7 victory
        if(playerXMoves[1]==4){
            if(playerXMoves[2]==7){
                cout << "Player X wins! \n";
                return true;
            }
        }
    }


    if(playerXMoves[0]==2){

        // 2 - 5 - 8 victory
        if(playerXMoves[1]==5){
            if(playerXMoves[2]==8){
                cout << "Player X wins! \n";
                return true;
            }
        }
    }

    if(playerXMoves[0]==3){

        // 3 - 5 - 7 victory
        if(playerXMoves[1]==5){
            if(playerXMoves[2]==7){
                cout << "Player X wins! \n";
                return true;
            }
        }
        
        // 3 - 6 - 9 victory
        if(playerXMoves[1]==6){
            if(playerXMoves[2]==9){
                cout << "Player X wins! \n";
                return true;
            }
        }
    }

    // 4 - 5 - 6 victory
    if(playerXMoves[0] == 4){
        if(playerXMoves[1] == 5){
            if(playerXMoves[2] == 6){
                cout << "Player X wins! \n";
                return true;
            }
        }
    }

    // 7 - 8 - 9 victory
    if(playerXMoves[0] == 7){
        if(playerXMoves[1] == 8){
            if(playerXMoves[2] == 9){
                cout << "Player X wins! \n";
                return true;
            }
        }
    }

// check O wins
    if(playerOMoves[0]==1){

        // 1 - 2 - 3 victory
        if(playerOMoves[1]==2){
            if(playerOMoves[2]==3){
                cout << "Player O wins! \n";
                return true;
            }
        }
        
        // 1 - 5 - 9 victory
        if(playerOMoves[1]==5){
            if(playerOMoves[2]==9){
                cout << "Player O wins! \n";
                return true;
            }
        }

        // 1 - 4 - 7 victory
        if(playerOMoves[1]==4){
            if(playerOMoves[2]==7){
                cout << "Player O wins! \n";
                return true;
            }
        }
    }


    if(playerOMoves[0]==2){

        // 2 - 5 - 8 victory
        if(playerOMoves[1]==5){
            if(playerOMoves[2]==8){
                cout << "Player O wins! \n";
                return true;
            }
        }
    }

    if(playerOMoves[0]==3){

        // 3 - 5 - 7 victory
        if(playerOMoves[1]==5){
            if(playerOMoves[2]==7){
                cout << "Player O wins! \n";
                return true;
            }
        }
        
        // 3 - 6 - 9 victory
        if(playerOMoves[1]==6){
            if(playerOMoves[2]==9){
                cout << "Player O wins! \n";
                return true;
            }
        }
    }

    // 4 - 5 - 6 victory
    if(playerOMoves[0] == 4){
        if(playerOMoves[1] == 5){
            if(playerOMoves[2] == 6){
                cout << "Player O wins! \n";
                return true;
            }
        }
    }

    // 7 - 8 - 9 victory
    if(playerOMoves[0] == 7){
        if(playerOMoves[1] == 8){
            if(playerOMoves[2] == 9){
                cout << "Player O wins! \n";
                return true;
            }
        }
    }

    // if (curTurn == 5){
    //     cout << "It's a draw!\n";
    //     return true;
    // }

    //if()
    return false;
}



bool TicTacToe::isWinner2(){

    // check board positions
    // for winning combos

// check for X victory
    if(boardSpotMark(1)=='X'){

        if(boardSpotMark(2)=='X'){
            if(boardSpotMark(3)=='X'){
                cout << "X wins!" << endl;
                return true;
            }
        }
        if(boardSpotMark(4)=='X'){
            if(boardSpotMark(7)=='X'){
                cout << "X wins!" << endl;
                return true;
            }
        }
        if(boardSpotMark(5)=='X'){
            if(boardSpotMark(9)=='X'){
                cout << "X wins!" << endl;
                return true;
            }
        }
    }

    if (boardSpotMark(2)=='X'){

        if(boardSpotMark(5)=='X'){
            if(boardSpotMark(8)=='X'){
                cout << "X wins!" << endl;
                return true;
            }
        }
    }

    if (boardSpotMark(3)=='X'){

        if(boardSpotMark(6)=='X'){
            if(boardSpotMark(9)=='X'){
                cout << "X wins!" << endl;
                return true;
            }
        }

        if(boardSpotMark(5)=='X'){
            if(boardSpotMark(7)=='X'){
                cout << "X wins!" << endl;
                return true;
            }
        }
    }

    if(boardSpotMark(4)=='X'){
        if(boardSpotMark(5)=='X'){
            if(boardSpotMark(6)=='X'){
                cout << "X wins!" << endl;
                return true;
            }
        }
    }
    if(boardSpotMark(7)=='X'){
        if(boardSpotMark(8)=='X'){
            if(boardSpotMark(9)=='X'){
                cout << "X wins!" << endl;
                return true;
            }
        }
    }
// check for O victory
    if(boardSpotMark(1)=='O'){

        if(boardSpotMark(2)=='O'){
            if(boardSpotMark(3)=='O'){
                cout << "O wins!" << endl;
                return true;
            }
        }
        if(boardSpotMark(4)=='O'){
            if(boardSpotMark(7)=='O'){
                cout << "O wins!" << endl;
                return true;
            }
        }
        if(boardSpotMark(5)=='O'){
            if(boardSpotMark(9)=='O'){
                cout << "X wins!" << endl;
                return true;
            }
        }
    }

    if (boardSpotMark(2)=='O'){

        if(boardSpotMark(5)=='O'){
            if(boardSpotMark(8)=='O'){
                cout << "O wins!" << endl;
                return true;
            }
        }
    }

    if (boardSpotMark(3)=='O'){

        if(boardSpotMark(6)=='O'){
            if(boardSpotMark(9)=='O'){
                cout << "O wins!" << endl;
                return true;
            }
        }

        if(boardSpotMark(5)=='O'){
            if(boardSpotMark(7)=='O'){
                cout << "O wins!" << endl;
                return true;
            }
        }
    }

    if(boardSpotMark(4)=='O'){
        if(boardSpotMark(5)=='O'){
            if(boardSpotMark(6)=='O'){
                cout << "O wins!" << endl;
                return true;
            }
        }
    }
    if(boardSpotMark(7)=='O'){
        if(boardSpotMark(8)=='O'){
            if(boardSpotMark(9)=='O'){
                cout << "O wins!" << endl;
                return true;
            }
        }
    }

    if (curTurn==5){

        cout << "Its a tie!" << endl;
        return true;
    }
    return false;
}


void TicTacToe::turn(){
    cout << "turn " << curTurn+1 << ":" << endl;
}


void TicTacToe::xTurn(){
    cout << endl;
    cout << "x's turn, select a spot to take: ";
    cin >> spot;
    while(!isValidMove()){
        cin >> spot;
    }
    cout << endl;
    markSpot('X');
//    recordPlayerMove('X', curTurn-1);
}


void TicTacToe::oTurn(){
    cout << endl;
    cout << "o's turn, select a spot to take: ";
    cin >> spot;
    while(!isValidMove()){
        cin >> spot;
    }
    cout << endl;
    markSpot('O');
//    recordPlayerMove('O', curTurn-1);
}


void TicTacToe::advanceTurn(){
    curTurn++;
}


void TicTacToe::markSpot(char mark){
    boardSpot() = mark;
}

//could not sort moves array no longer in use
int& TicTacToe::moves(char xo, int i){
    if(xo=='X') return playerXMoves[i];
    return playerOMoves[i];
}

//could not sort moves array no longer in use
void TicTacToe::recordPlayerMove(char xo, int i){
    moves(xo, i) = spot;
    return;
}