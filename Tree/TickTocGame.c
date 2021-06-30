//
//  TickTocGame.c
//  Tree
//
//  Created by Rahul Mane on 16/08/18.
//  Copyright © 2018 developer. All rights reserved.
//

#include "TickTocGame.h"


void showBoard(int board[3][3]){
    for (int i = 0; i< 3; i++) {
        for (int j=0; j<3; j++) {
            printf("|   %.3d   |",board[i][j]);
        }
        printf("\n");
    }
}

void addMove(int board[3][3],int position, int value){
    int counter = 0;
    for (int i = 0; i< 3; i++) {
        for (int j=0; j<3; j++) {
            counter++;
            
            if(counter == position){
                board[i][j] = value;
            }
        }
    }
}

int isAvailable(int board[3][3], int position){
    int counter = 0;
    for (int i = 0; i< 3; i++) {
        for (int j=0; j<3; j++) {
            counter++;
            
            if(counter == position && board[i][j] == position){
                return 1;
            }
        }
    }
    return 0;
}

int rowCrossed(int board[3][3]){
    for (int i=0; i<3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;
    }
    return 0;
}

// A function that returns true if any of the column
// is crossed with the same player's move
int columnCrossed(int board[3][3])
{
    for (int i=0; i<3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }
    return 0;
}

// A function that returns true if any of the diagonal
// is crossed with the same player's move
int diagonalCrossed(int board[3][3])
{
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;
    
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;
    
    return 0;
}


int isWin(int board[3][3]){
    return rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board);
}

int * availablePositions(int board[3][3]){
    static int availablePosistion[9];
    int expectedValue = 0;
    
    int arrayindex = 0;
    for (int i = 0; i< 3; i++) {
        for (int j=0; j<3; j++) {
            expectedValue++;
            
            if(board[i][j] == expectedValue){
                availablePosistion[arrayindex] = expectedValue;
                arrayindex++;
            }
        }
    }
    
    return availablePosistion;
}

void giveMePosition(int board[3][3]){
    int position;
    int *availables;
    
    availables = availablePositions(board);
    
    for (int i = 0; i< 9; i++) {
        printf( "*(availables + %d) : %d\n", i, *(availables + i));
    }
    
    printf( "\n\nEnding available algo\n\n");
}



//decide player and it's character..

int mainTickTockGame(){
    printf("\n\n==== TICK TACK TOE ====\n\n");
    
    int MAXMoves = 9;
    int board[3][3] = {1,2,3,4,5,6,7,8,9};
    int moves[9];
    int moveIndex = 0;
    
    int player = 0;
    showBoard(board);
    

    while (moveIndex < 9) {
        int position;
        if(player % 2 == 0){
            //player one == Should be now computer...
            giveMePosition(board);
            printf("\nPlayer 1 : Enter your position : ");
            scanf("%d",&position);
            if(isAvailable(board, position)){
                addMove(board, position, 111);
                showBoard(board);
                moveIndex++;
            }
            else{
                continue;
            }
        }
        else{
            //player two
            printf("\nPlayer 2 : Enter your position : ");
            scanf("%d",&position);
            if(isAvailable(board, position)){
                addMove(board, position, 222);
                showBoard(board);
                moveIndex++;
            }
            else{
                continue;
            }
        }
        
        if(isWin(board)){
            printf("\n\n\nSomeone has won !!!!\n\n\n");
            break;
        }
        player++;
    }
    
    return 0;
}



