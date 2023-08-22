#include <stdio.h>
// #include <string.h>
// #include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
// #include <stdbool.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);


int main(){

    printf("Hello World\n\n");

    char winner = ' ';

    resetBoard();

    while(winner == ' ' && checkFreeSpaces() != 0)
    {
       printBoard();

       playerMove();
       winner = checkWinner();
       if(winner != ' ' || checkFreeSpaces() == 0)
       {
        break;
       }

       computerMove();
       winner = checkWinner();
       if(winner != ' ' || checkFreeSpaces() == 0)
       {
        break;
       }

    }
    printBoard();
    printWinner(winner);
    

    return 0;
}

void resetBoard()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkFreeSpaces()
{
    int freeSpace = 9;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpace--;
            }
        }
    }
    return freeSpace;
}
void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter row number (1-3): ");
        scanf("%d", &x);
        x--;

        printf("ENter column number (1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }while (board[x][y] != ' ');
    
    
}
void computerMove()
{
    // create a seed based on current time
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}
char checkWinner()
{
    // check rows
    for(int i=0; i<3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // check columns
    for(int i=0; i<3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    //check diagonals 
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';


}
void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("YOU WON!");
    }
    else if(winner == COMPUTER)
    {
        printf("YOU LOSE!");
    }
    else
    {
        printf("DRAW!");
    }
}



// void SayHello(char name1[], char name2[])
// {
//     printf("\nHello %s", name1);
//     printf("\nHello %s", name2);
// }


// // sorting function for array with numbers
// void sort(int array[], int size)
// {
//     for (int i = 0; i < size-1; i++)
//     {
//         for (int j = 0; j < size -1; j++) //size -i-1?
//         {
//             if(array[j] > array[j+1])
//             {
//                 int temp = array[j];
//                 array[j] = array[j+1];
//                 array[j+1] = temp;
//             }
//         }
//     }
// }

// void displayArray(int array[], int size)
// {
//     for(int i=0; i<size;i++)
//     {
//         printf("%d ", array[i]);
//     }
// }

// //sorting function for array with characters
// void sortChar(char array[], int size)
// {
//     for (int i = 0; i < size-1; i++)
//     {
//         for (int j = 0; j < size -i-1; j++) //size -i-1?
//         {
//             if(array[j] > array[j+1]) // >: descending order <: ascending order
//             {
//                 int temp = array[j];
//                 array[j] = array[j+1];
//                 array[j+1] = temp;
//             }
//         }
//     }
// }

// void displayArrayChar(char array[], int size)
// {
//     for(int i=0; i<size;i++)
//     {
//         printf("%c ", array[i]);
//     }
// }

// struct Player
// {
//     /* data */
//     char name[12];
//     int score;
// };


// // typedef char user[25];

// typedef struct
// {
//     char name[25];
//     float gpa;
//     int id;
// }User;

// void loop(char Buffer, FILE file)
// {
//     while(fgets(Buffer, 255, file) != NULL)
//     {
//         printf("%s", Buffer);
//     }
// }

