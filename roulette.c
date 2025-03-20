/* Assignment 4: Write a program to simulate the casino game called Roulette. We will use a simplified version of Roulette. We will only use numbers from 0 to 36 (00 is excluded). Further, the user is only 
 * allowed to bet on odd or even numbers. First, your program will prompt the users to enter the amount of money they had (balance) and the betting type such as 1-Odd number, 2-Even number, 0-To quit the game. 
 * Then your program will prompt for the betting amount. */
/* Author: Edison Lin */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int draw_card()
{
    return rand() % 36 + 1;
}

int main(void)
{
	int total_money, odd_even, bet;
	srand(time(0));
	printf("Entering the casino, how much money do you have? ");
	scanf("%d", &total_money);
	printf("We are playing Roulette, odd or even bets only.\n");

	while (1 || 2 || 0)
	{
		printf("Place your bet!\n");
        	printf("Enter 1 for odd, 2 for even, 0 to quit: ");
        	scanf("%d", &odd_even);
		if (odd_even == 0)
                {
                        printf("You exit the casino with $%d \n", total_money);
                        break;
                }
		printf("How much money you want to bet? \n");
		scanf("%d", &bet);
		while (bet >= total_money)
		{
			printf("You don't have enough money\n");
			printf("How much money you want to bet? \n");
                	scanf("%d", &bet);
		}
		if (odd_even == 1)
		{
			int new_number = draw_card();
			printf("You bet $%d on odd numbers \n", bet);
			printf("The winning number is %d! \n", new_number);
			if (new_number % 2 == 1)
			{
				total_money = total_money + bet;
				printf("You Win!\n");
				printf("Your balance is $%d!!\n", total_money);
				continue;

			}
			else if (new_number % 2 == 0)
			{
				total_money = total_money - bet;
				if (total_money <= 0)
				{
					printf("You ran out of money. Sorry!\n");
					break;
				}
				printf("You Lose!\n");
                                printf("Your balance is $%d!!\n", total_money);
				continue;
			}

		}
		if (odd_even == 2)
        	{
                	int new_number = draw_card();
                	printf("You bet $%d on even numbers\n", bet);
                	printf("The winning number is %d! \n", new_number);
                	if (new_number % 2 == 0)
                	{
                        	total_money = total_money + bet;
				printf("You Win!\n");
                                printf("Your balance is $%d!!\n", total_money);
				continue;
                	}
                	else if (new_number % 2 == 1)
                	{
                        	total_money = total_money - bet;
				if (total_money <= 0)
                        	{
                                	printf("You ran out of money. Sorry!\n");
                                	break;
                        	}
				printf("You Lose!\n");
                                printf("Your balance is $%d!!\n", total_money);
                                continue;
                	}

        	}
	}
	return 0;
}
	

