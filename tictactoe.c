#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R 3
#define C 3

int promptUser();
void drawBoard(char board[R][C]);
int markCheck(char board[R][C], int row, int col);
char winCheck(char board[R][C]);

int main(void) {
    int choice, mark, row, col;
    int turn = 9;
    char game = ' ';
    char board[R][C] = {{' ',' ',' '},
                        {' ',' ',' '},
                        {' ',' ',' '}};
    //srand(time(NULL));

    choice = promptUser();
    drawBoard(board);

    //if 1 (pvp)
    if(choice == 1)
    {
        while(game == ' ')
        {
            mark = 1;
            while(mark)
            {
                printf("Player 1: Make your move\n");
                scanf("%d %d", &row, &col);
                if(((row >= 1 && row <= 3) && (col >= 1 && col <= 3)))
                {   
                    if(markCheck(board, row, col) == 1)
                    {
                        mark = 0;
                        printf("Good!\n");
                        board[row-1][col-1] = 'X';
                        drawBoard(board);
                    }
                    else
                    {
                        printf("There is already a mark there. Enter new value\n");
                    }               
                }
            }

            turn--;
            game = winCheck(board);
            if(game != ' ')
            {
                if(game == 'X') 
                    printf("Winner is player 1!\n");
                else
                    printf("Winner is player 2!\n");
                break;
            }
            if(turn == 0)
            {
                printf("Tie!\n");
                break;
            }
            
            mark = 1;
            while(mark)
            {
                printf("Player 2: Make your move\n");
                scanf("%d %d", &row, &col);
                if(((row >= 1 && row <= 3) && (col >= 1 && col <= 3)))
                {
                    if(markCheck(board, row, col) == 1)
                    {
                        mark = 0;
                        printf("Good!\n");
                        board[row-1][col-1] = 'O';
                        drawBoard(board);
                    }
                    else
                    {
                        printf("There is already a mark there. Enter new value\n");
                    }   
                }
            }

            turn--;
            game = winCheck(board);
            if(game != ' ')
            {
                if(game == 'X')
                    printf("Winner is player 1!\n");
                else
                    printf("Winner is player 2!\n");
                break;
            }
            if(turn == 0)
            {
                 printf("Tie!\n");
                 break;
            }
        }
    }

    //if 2 (pvc)
    else if(choice == 2)
    {
        while(game == ' ')
        {
            mark = 1;
            while(mark)
            {
                printf("Player 1: Make your move\n");
                scanf("%d %d", &row, &col);
                if(((row >= 1 && row <= 3) && (col >= 1 && col <= 3)))
                {   
                    if(markCheck(board, row, col) == 1)
                    {
                        mark = 0;
                        printf("Good!\n");
                        board[row-1][col-1] = 'X';
                        drawBoard(board);
                    }
                    else
                    {
                        printf("There is already a mark there. Enter new value\n");
                    }               
                }
            }

            turn--;
            game = winCheck(board);
            if(game != ' ')
            {
                if(game == 'X') 
                    printf("Congrats! You win!\n");
                else
                    printf("Computer wins!\n");
                break;
            }
            if(turn == 0)
            {
                printf("Tie!\n");
                break;
            }
            
            mark = 1;
            printf("Computer's move\n");
            while(mark)
            {
                row = randMove();
                col = randMove();
                if(markCheck(board, row, col) == 1)
                {
                    mark = 0;
                    printf("Good!\n");
                    board[row-1][col-1] = 'O';
                    drawBoard(board);
                }
            }

            turn--;
            game = winCheck(board);
            if(game != ' ')
            {
                if(game == 'X')
                    printf("Congrats! You win!\n");
                else
                    printf("Computer wins!\n");
                break;
            }
            if(turn == 0)
            {
                 printf("Tie!\n");
                 break;
            }
        }
    }

    return 0;
}

int promptUser() {
    printf("WELCOME TO TIC TAC TOE!\n");
    printf("1 --- person vs person\n2 --- person vs script\n");
    printf("Enter your choice (1 or 2): ");
    int choice;
    int check = scanf("%d", &choice);
    if(check == 0)
    {
        printf("Error reading choice...\n");
        exit(0);
    }
    else if((choice == 1) || (choice == 2))
    {
        printf("==========================\n");
        printf("You have entered choice %d\n", choice);
        return choice;
    }
    else
    {
        printf("Please enter either 1 or 2\n");
        exit(0);
    }
}

void drawBoard(char board[R][C]) {
    printf("The current status is:\n");
    printf("+-----------+\n");
    printf("| %c | %c | %c | \n", board[0][0], board[0][1], board[0][2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c | \n", board[1][0], board[1][1], board[1][2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c | \n", board[2][0], board[2][1], board[2][2]);
    printf("+-----------+\n");
}

int markCheck(char board[R][C], int row, int col) {
    if(board[row-1][col-1] == ' ')
        return 1;
    else
        return 0;
}

char winCheck(char board[R][C]) {
    if(board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return board[0][0];
    else if(board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return board[1][0];
    else if(board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return board[2][0];
    else if(board[0][0] != ' ' && board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return board[0][0];
    else if(board[0][1] != ' ' && board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return board[0][1];
    else if(board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return board[0][2];
    else if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    else if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    else
        return ' ';
}