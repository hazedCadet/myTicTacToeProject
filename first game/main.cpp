#include "TicTacToe.cpp"
#include <iostream>
#include <ctime>
using namespace std;

int main(){

    int choice=0;

    TicTacToe game;

    cout << "******************************\n";
    cout << "*        TIC-TAC-TOE         *\n";
    cout << "******************************\n";

    do{
        cout << "Will X or O go first?\n";
        cout << "1: X \n2: O \n3: Random \n4: Quit\n";
        cin >> choice;

        if(choice==3){
            srand(time(0));
            choice = rand()%2+1;
        }

        switch(choice){

            case 1:

                do{
                    game.drawBoard();
                    game.turn();
                    game.xTurn();
                    cout << endl;
                    game.drawBoard();
                    if (game.isWinner2()) break;
                    game.oTurn();
                    cout << endl;
                    game.advanceTurn();
                } while(!game.isWinner2());
                cout << "Play again?" << endl;
                cout << "1: Yes \n2: No" << endl;
                cin >> choice;
                if(choice == 2){
                    choice = 4;
                }

            case 2:

                do{
                    game.drawBoard();
                    game.turn();
                    game.oTurn();
                    cout << endl;
                    game.drawBoard();
                    if (game.isWinner2()) break;
                    game.xTurn();
                    cout << endl;
                    game.advanceTurn();
                } while(!game.isWinner2());
                cout << "Play again?" << endl;
                cout << "1: Yes \n2: No" << endl;
                cin >> choice;
                if(choice == 2){
                    choice = 4;
                }

            case 4: 
                cout << "program quit" << endl;
                break;
        }

    }while(choice!=4);

    return 0;
}