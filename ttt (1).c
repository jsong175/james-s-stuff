#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

int user_spot(void);
int bot_spot(void);
void draw_board(char *userInput);



int main(void)
{
    char userInput[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    printf("0|1|2\n------\n3|4|5\n------\n6|7|8\n");
    int spot = user_spot();
    if(userInput[spot] == 'x' || userInput[spot] == 'o')
    {
        printf("Please pick a spot not already chosen");
        spot = user_spot();
    }
    userInput[spot] = 'x';

    draw_board(userInput);

    int opponent_turn = bot_spot();
    if(userInput[opponent_turn] == 'x' || userInput[opponent_turn] == 'o')
    {
        opponent_turn = bot_spot();
    }
    printf("\n\n opponent picks %i\n", opponent_turn);
    userInput[opponent_turn] = 'o';
    draw_board(userInput);


}

int user_spot(void) //to do: error check if number is higher than 8
{
    printf("Pick a spot (input number from 0-8): ");
    int number;
    scanf("%i", &number);
    if(number < 0 || number > 8)
    {
        printf("Pick a number from 0 to 8 dummy: ");
        scanf("%i", &number);
    }
    return number;
}

int bot_spot(void) //make better algorithm later if possible
{
    srand(time(0));
    int random = rand() % 9;
    return random;
}


void draw_board(char *userInput)
{
    for(int i = 0; i < 9; i++)
    {
        if(i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7)
        {
            printf("%c|", userInput[i]);
        }
        else if(i == 2 || i == 5)
        {
            printf("%c\n------\n", userInput[i]);
        }
        else
        {
            printf("%c\n", userInput[i]);
        }
    }
}






    //code outline
    //show board once
    //loop until there's a winner or whole board is filled {
    //get input I from user for what spot
    //put x into spot I on board
    //pick random spot R that has not been filled
    //put o into spot R on board
    //}