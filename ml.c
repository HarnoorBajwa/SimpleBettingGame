/* Simple Betting Game
    Jack Queen King- computer shuffles these cards
    Player needs to guess the position of the queen 
    if he wins , he takes 3*the bet
    if he looses, he looses the bet amount
    player initially has 100 $

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cash = 100;

void Play(int bet){
    char C[3] = {'J','Q','K'};
    printf("Shuffling..........\n");
    srand(time(NULL)); //seeding random number
    int i;
    for(i = 0; i < 5;i++)
    {
        int x = rand() % 3; // generating a random number and then taking a modulus with 3 ,so the return value is either 0, 1 or 2
        int y = rand() % 3;
        int temp = C[x];
        C[x] = C[y];
        C[y] = temp;
        
    }
    
    int playerGuess;
    printf("What is the position of queen 1 , 2 or 3 ?\n");
    scanf("%d\n",&playerGuess);
    if(C[playerGuess - 1] == 'Q'){
        cash = cash + 3*bet;
        printf("Hooray!, you won Result = %c%c%c Total Balance = %d",C[0],C[1],C[2],cash);
    }
    else{
        cash = cash - bet;
        printf("Opps!, you lost = %c%c%c Total Balance = %d",C[0],C[1],C[2],cash);
    }

}

int main(){
    int bet;
    printf("**Welcome to Virtual Casino**\n");
    printf("Total Balance = $%d\n",cash);
    while(cash > 0){
        printf("What is your bet ?\n");
        scanf("%d",&bet);
        if(bet==0 || bet >cash) break;
        Play(bet);
        printf("\n************************************\n");
    }
}