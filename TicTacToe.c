#include <stdio.h>
#include <stdlib.h>

void makeBoard(int gameBoard[3][3]);
//writes into gameBoard.txt the game board and each spot with an X, O, or _.

void showBoard();
//displays gameBoard.txt into the console.

void playMove(int pos, int gameBoard[3][3], int play);
/*uses pass by reference to alter integer board with a 1 or 2 in user inputted position.
A 1 means an X is played in the position, and a 2 means an O is. 
If a user tries to overwrite a position already played by either player, their turn will be skipped entirely*/

int checkWin(int gameBoard[3][3]);
/*checks for 3 consecutive 1s or 2s horizontally, vertically, or diagonally. 
returns 1 or 2 for win boolean value and 0 for game not done.
A 1 means player X wins and a 2 means player O wins */

int checkDraw(int gameBoard[3][3]);
//checks for a filled out board. returns 3 for draw boolean value and 0 for game not done.

void printBoard(int gameBoard[3][3]);
//debugging function to check how gameboard looks

int main(){
    
    int gameBoard[3][3] = { {0, 0, 0},{0, 0, 0},{0, 0, 0} }, pos;
    char playerX[20], playerO[20], placeholder;
    //All variables needed in main
    
    printf("|   |   |   |   |   |   |   |   |   |   |\n");
    printf("| Welcome to TicTacToe Text Game on C!  |\n");
    printf("|   |   |   |   |   |   |   |   |   |   |\n");
    printf("\n");
    printf("To begin type any character and press enter: ");
    scanf(" %c", &placeholder);
    printf("\nPlayer X name: ");
    scanf(" %s", playerX);
    printf("\nPlayer O name: ");
    scanf(" %s", playerO);
    //Openning screen/message and player assign
    
    makeBoard(gameBoard);
    showBoard();
    //Setting up the 2d integer array board and the file gameBoard.txt, then displaying the empty board to the user
    
    printf("Here is your board! The spots are numbered 1 through 9 from top left to bottom right.\n");
    printf("\n%s will go first, and then %s, and you two will alternate placing your positions until one strikes 3 in a row!\n", playerX, playerO);
    printf("Any attempt at position overwrite will cause penalty of forfeited turn\n");
    printf("Good luck!\n\n");
    //Beginning game
    
    do{
        printf("%s Position: ", playerX);
        scanf("%d", &pos);
        while(pos<1 || pos>9){
            printf("Invalid input, try again: ");
            scanf("%d", &pos);
        }
        playMove(pos, gameBoard, 1);
        makeBoard(gameBoard);
        showBoard();
        if(checkWin(gameBoard))
            break;
        if(checkDraw(gameBoard))
            break;
        //playerX move. Break needed if playerX wins or makes a draw on the board
        //printBoard(gameBoard);
        
        printf("%s Position: ", playerO);
        scanf("%d", &pos);
        while(pos<1 || pos>9){
            printf("Invalid input, try again: ");
            scanf("%d", &pos);
        }
        playMove(pos, gameBoard, 2);
        makeBoard(gameBoard);
        showBoard();
        //playerO move.
        //printBoard(gameBoard);
        
    } while(!checkWin(gameBoard));
    //PlayerX and Y alternate in moves until a true boolean value for checkWin | checkDraw is reached
    
    if (checkWin(gameBoard) == 1){
        printf("\n***** %s wins! *****\n", playerX);
    } else if (checkWin(gameBoard) == 2){
        printf("\n***** %s wins! *****\n", playerO);
    } else if (checkDraw(gameBoard) == 3){
        printf("\nDRAW\n");
    }
    //winner or draw statement, end of game
    
    return(0);
}

void makeBoard(int gameBoard[3][3]){
    FILE *makegameBoard = fopen("gameBoard.txt", "w");
    
    fprintf(makegameBoard, ",---------,\n");
    int count = 1;
    for(int i = 0; i < 3; i++){
        fprintf(makegameBoard, "| |");
        for(int j = 0; j < 3; j++){
            switch (gameBoard[i][j]) {
                
                case 0:
                    fprintf(makegameBoard, "_|");
                    //fprintf(makegameBoard, "%d|", count);
                    break;
                
                case 1:
                    fprintf(makegameBoard, "X|");
                    break;
                
                case 2:
                    fprintf(makegameBoard, "O|");
                    break;
                
            }
            count++;
        }
        fprintf(makegameBoard, " |\n");
    }
    fprintf(makegameBoard, "'---------'");
    
    fclose(makegameBoard);
}

void showBoard(){
    printf("\n");
    
    char line[20];
    FILE *showgameBoard = fopen("gameBoard.txt", "r");
    
    do{
        fgets(line, sizeof(line), showgameBoard);
        printf("%s", line);
    } while(!feof(showgameBoard));
    
    printf("\n");
    
    fclose(showgameBoard);
}

void playMove(int pos, int gameBoard[3][3], int play){
    switch(pos){
        case 1:
            if(gameBoard[0][0] != 1 && gameBoard[0][0] != 2){
                gameBoard[0][0] = play;
                break;
            }else{
                printf("Position overwrite is not allowed, your turn is skipped.");
                break;
            }
        case 2:
            if(gameBoard[0][1] != 1 && gameBoard[0][1] != 2){
                gameBoard[0][1] = play;
                break;
            }else{
                printf("Position overwrite is not allowed, your turn is skipped.");
                break;
            }
        case 3:
            if(gameBoard[0][2] != 1 && gameBoard[0][2] != 2){
                gameBoard[0][2] = play;
                break;
            }else{
                printf("Position overwrite is not allowed, your turn is skipped.");
                break;
            }
        case 4:
            if(gameBoard[1][0] != 1 && gameBoard[1][0] != 2){
                gameBoard[1][0] = play;
                break;
            }else{
                printf("Position overwrite is not allowed, your turn is skipped.");
                break;
            }
        case 5:
            if(gameBoard[1][1] != 1 && gameBoard[1][1] != 2){
                gameBoard[1][1] = play;
                break;
            }else{
                printf("Position overwrite is not allowed, your turn is skipped.");
                break;
            }
        case 6:
            if(gameBoard[1][2] != 1 && gameBoard[1][2] != 2){
                gameBoard[1][2] = play;
                break;
            }else{
                printf("Position overwrite is not allowed, your turn is skipped.");
                break;
            }
        case 7:
            if(gameBoard[2][0] != 1 && gameBoard[2][0] != 2){
                gameBoard[2][0] = play;
                break;
            }else{
                printf("Position overwrite is not allowed, your turn is skipped.");
                break;
            }
        case 8:
            if(gameBoard[2][1] != 1 && gameBoard[2][1] != 2){
                gameBoard[2][1] = play;
                break;
            }else{
                printf("Position overwrite is not allowed, your turn is skipped.");
                break;
            }
        case 9:
            if(gameBoard[2][2] != 1 && gameBoard[2][2] != 2){
                gameBoard[2][2] = play;
                break;
            }else{
                printf("Position overwrite is not allowed, your turn is skipped.");
                break;
            }
    }
}

int checkWin(int gameBoard[3][3]){
    
    int p1, p2, p3;
    
    for(int i = 0; i < 3; i++){
        p1 = gameBoard[i][0];
        p2 = gameBoard[i][1];
        p3 = gameBoard[i][2];
        if(p1 == 1 && p2 == 1 && p3 == 1){
            return 1;
        }
        if(p1 == 2 && p2 == 2 && p3 == 2){
            return 2;
        }
    }
    //horizontal check
    
    for(int i = 0; i < 3; i++){
        p1 = gameBoard[0][i];
        p2 = gameBoard[1][i];
        p3 = gameBoard[2][i];
        if(p1 == 1 && p2 == 1 && p3 == 1){
            return 1;
        }
        if(p1 == 2 && p2 == 2 && p3 == 2){
            return 2;
        }
    }
    //vertical check
    
    p1 = gameBoard[0][0];
    p2 = gameBoard[1][1];
    p3 = gameBoard[2][2];
    if(p1 == 1 && p2 == 1 && p3 == 1){
        return 1;
    }
    if(p1 == 2 && p2 == 2 && p3 == 2){
        return 2;
    }
    //diagonal top left to bottom right check
    
    p1 = gameBoard[0][2];
    p2 = gameBoard[1][1];
    p3 = gameBoard[2][0];
    if(p1 == 1 && p2 == 1 && p3 == 1){
        return 1;
    }
    if(p1 == 2 && p2 == 2 && p3 == 2){
        return 2;
    }
    //diagonal top right to bottom left check
    
    return 0;
}

int checkDraw(int gameBoard[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (gameBoard[i][j] != 1 && gameBoard[i][j] != 2)
                return 0;
        }
    }
    return 3;
}

void printBoard(int gameBoard[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", gameBoard[i][j]);
        }
        printf("\n");
    }
}