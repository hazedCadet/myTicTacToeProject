#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe{

    private:

        int spot=0;
        float curTurn=0;
        
        const static int ROW=3,
                         COL=4,
                         MARKS=5;

        char board[ROW][COL] = { {'1', '2', '3', 'a'},
                                 {'4', '5', '6', 'b'},
                                 {'7', '8', '9', 'c'}
                                };

        int playerXMoves[MARKS]={0,0,0,0,0},
            playerOMoves[MARKS]={0,0,0,0,0};
        

    public:

        TicTacToe(){};

        void drawBoard();
        char &boardSpot();
        char& boardSpotMark(int pos);
        bool isValidMove();
        bool isWinner();
        bool isWinner2();
        void sortMoves(int array[], int size);
        void viewMoves(char xo);
        void turn();
        void advanceTurn();

        void xTurn();
        void oTurn();
        void markSpot(char mark);
        int &moves(char xo, int i);
        void recordPlayerMove(char xo, int i);

};

#endif