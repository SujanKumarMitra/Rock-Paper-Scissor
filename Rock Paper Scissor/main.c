#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void printing_input_of_player_1_single_player(int);
void printing_input_of_player_1_multi_player(int);
void printing_input_of_cpu(int);
void printing_input_of_player_2_multi_player(int);
int calculation(int,int);
void instruction();
int input_player_1_single_player();
int input_player_1_multi_player();
int input_player_2_multi_player();
int input_cpu();
void co_ordinate(short,short);
void print_score_card_single_player(int,int);
void print_final_score_card_single_player(int,int);
void print_final_score_card_multi_player(int,int);
void print_score_card_multi_player(int,int);

typedef enum {Rock = 1,Paper = 2,Scissor = 3} move;

int main()
{

	move player_1,player_2;
	int i,score_of_player_1,score_of_player_2,calculate;
	char s;
	char mode='A';

	srand(time(0));

	instruction();
	do
    {

        score_of_player_1=0;
        score_of_player_2=0;
        system("cls");
        printf("Single-Player or Multi-Player? Press 'S' for Single-Player; 'M' for Multi-Player.");
        fflush(stdin);
        mode=getch();
        while(mode != 'S' && mode != 'M')
        {
            printf("\nInvalid Input! Press 'S' for Single-Player; 'M' for Multi-Player.");
            fflush(stdin);
            mode=getch();
        }
        for(i=1; i<=5; i++)
        {

            system("cls");
            co_ordinate(56,0);
            printf("ROUND %d",i);

            switch(mode)
            {
            case 'S':
                {
                    print_score_card_single_player(score_of_player_1,score_of_player_2);
                    player_1=input_player_1_single_player();
                    printing_input_of_player_1_single_player(player_1);
                    player_2=input_cpu();
                    printing_input_of_cpu(player_2);
                    break;
                }
            case 'M':
                {
                    print_score_card_multi_player(score_of_player_1,score_of_player_2);
                    player_1=input_player_1_multi_player();
                    printing_input_of_player_1_multi_player(player_1);
                    player_2=input_player_2_multi_player();
                    printing_input_of_player_2_multi_player(player_2);
                    break;
                }
            }
            calculate=calculation(player_1,player_2);

            Sleep(2000);

            switch(mode)
            {
            case 'S':
                {
                    switch(calculate)
                    {
                        case (1):
                            {
                                printf("\n\nIt' a draw.");
                                break;
                            }
                        case (2):
                            {
                                printf("\n\nYou won the round!");
                                ++score_of_player_1;
                                break;
                            }
                        case (3):
                            {
                                printf("\n\nYou lost the round!");
                                ++score_of_player_2;
                                break;
                            }
                        case (4):
                            {
                                printf("\n\nYou lost the round!");
                                ++score_of_player_2;
                                break;
                            }
                        case (5):
                            {
                                printf("\n\nIt's a draw!");
                                break;
                            }
                        case (6):
                            {
                                printf("\n\nYou win the round!");
                                ++score_of_player_1;
                                break;
                            }
                        case (7):
                            {
                                printf("\n\nYou win the round!");
                                ++score_of_player_1;
                                break;
                            }
                        case (8):
                            {
                                printf("\n\nYou lost the round.");
                                ++score_of_player_2;
                                break;
                            }
                        case (9):
                            {
                                printf("\n\nIt's a draw.");
                                break;
                            }
                        }
                        break;
                    }
            case 'M':
                {
                    switch(calculate)
                    {
                        case (1):
                            {
                                printf("\n\nIt' a draw.");
                                break;
                            }
                        case (2):
                            {
                                printf("\n\nPlayer 1 won the round!");
                                ++score_of_player_1;
                                break;
                            }
                        case (3):
                            {
                                printf("\n\nPlayer 2 won the round!");
                                ++score_of_player_2;
                                break;
                            }
                        case (4):
                            {
                                printf("\n\nPlayer 2 won the round!");
                                ++score_of_player_2;
                                break;
                            }
                        case (5):
                            {
                                printf("\n\nIt's a draw!");
                                break;
                            }
                        case (6):
                            {
                                printf("\n\nPlayer 1 won the round!");
                                ++score_of_player_1;
                                break;
                            }
                        case (7):
                            {
                                printf("\n\nPlayer 1 win the round!");
                                ++score_of_player_1;
                                break;
                            }
                        case (8):
                            {
                                printf("\n\nPlayer 2 win the round.");
                                ++score_of_player_2;
                                break;
                            }
                        case (9):
                            {
                                printf("\n\nIt's a draw.");
                                break;
                            }
                        }
                        break;
                }
            }


            Sleep(3000);

            system("cls");
        }
        switch(mode)
        {
        case 'S':
            {
                print_final_score_card_single_player(score_of_player_1,score_of_player_2);
                if(score_of_player_1 == score_of_player_2)
                {
                    co_ordinate(42,6);
                    printf("Scores Equal!!! This match is a tie.");
                }
                else if (score_of_player_1 > score_of_player_2)
                {
                    co_ordinate(41,7);
                    printf("CONGRATULATIONS!!! You win the match!");
                }
                else if (score_of_player_1 < score_of_player_2)
                {
                    co_ordinate(35,7);
                    printf("SORRY! You lost the match! Better luck next time!");
                }
                break;
            }
        case 'M':
            {
                print_final_score_card_multi_player(score_of_player_1,score_of_player_2);
                if(score_of_player_1 == score_of_player_2)
                {
                    co_ordinate(42,6);
                    printf("Scores Equal!!! This match is a tie.");
                }
                else if (score_of_player_1 > score_of_player_2)
                {
                    co_ordinate(23,7);
                    printf("CONGRATULATIONS!!! Player 1 win the match! Better luck next time Player 2");
                }
                else if (score_of_player_1 < score_of_player_2)
                {
                    co_ordinate(23,7);
                    printf("CONGRATULATIONS!!! Player 2 win the match! Better luck next time Player 1");
                }
            }
            break;
        }
    co_ordinate(18,8);
	printf("Do you want to play again?Press 'Y' for another match or press any key to terminate.");
	fflush(stdin);
	s=getch();
    } while(s=='Y');
	return 0;
}
void printing_input_of_player_1_single_player(int player_1)
{
    switch(player_1)
		{
            case Rock:
                {
                    printf("You chose Rock!");
                    Sleep(2000);
                    break;
                }
            case Paper:
                {
                    printf("You chose Paper!");
                    Sleep(2000);
                    break;
                }
            case Scissor:
                {
                    printf("You chose Scissor!");
                    Sleep(2000);
                    break;
                }
		}
}
void printing_input_of_player_1_multi_player(int player_1)
{
    switch(player_1)
		{
            case Rock:
                {
                    printf("Player 1 chose Rock!");
                    Sleep(2000);
                    break;
                }
            case Paper:
                {
                    printf("Player 1 chose Paper!");
                    Sleep(2000);
                    break;
                }
            case Scissor:
                {
                    printf("Player 1 chose Scissor!");
                    Sleep(2000);
                    break;
                }
		}
}
void printing_input_of_player_2_multi_player(int player_2)
{
    switch(player_2)
    {
        case Rock:
            {
                printf("Player 2 chose Rock!");
                Sleep(2000);
                break;
            }
        case Paper:
            {
                printf("Player 2 chose Paper!");
                Sleep(2000);
                break;
            }
        case Scissor:
            {
                printf("Player 2 chose Scissor!");
                Sleep(2000);
                break;
            }
    }
}
void printing_input_of_cpu(int player_2)
{
    switch(player_2)
		{
            case Rock:
                {
                    printf("\nCPU chose Rock!");
                    Sleep(2000);
                    break;
                }
            case Paper:
                {
                    printf("\nCPU chose Paper!");
                    Sleep(2000);
                    break;
                }
            case Scissor:
                {
                    printf("\nCPU chose Scissor!");
                    Sleep(2000);
                    break;
                }
		}
}
int calculation(int player_1,int player_2)
{
    if(player_1 == 1 && player_2 == 1)
		{
            return (1);
		}
		else if(player_1 == 2 && player_2 == 1)
		{
			return (2);
		}
		else if(player_1 == 3 && player_2 == 1)
		{
			return (3);
		}
		else if(player_1 == 1 && player_2 == 2)
		{
			return (4);
		}
		else if(player_1 == 2 && player_2 == 2)
		{
           return (5);
		}
		else if(player_1 == 3 && player_2 == 2)
		{
			return (6);
		}
		else if(player_1 == 1 && player_2 == 3)
		{
			return (7);
		}
		else if(player_1 == 2 && player_2 == 3)
		{
			return (8);
		}
		else if(player_1 == 3 && player_2 == 3)
		{
            return (9);
		}
}
void instruction()
{
    Sleep(2000);
    co_ordinate(57,0);

    printf("HELLO");

    Sleep(2000);
    co_ordinate(39,1);
    printf("Welcome to the game Rock, Paper, Scissors!");

    Sleep(1000);
    co_ordinate(40,2);
    printf("Please read the instructions carefully.");

	Sleep(2000);
    co_ordinate(30,3);
    printf("You can play either single-player mode or multi-player mode.");


    Sleep(3000);
    co_ordinate(34,4);
    printf("Players will have to choose from the three options.");

    Sleep(1000);
    co_ordinate(55,5);
    printf("1 for Rock");

    Sleep(500);
    co_ordinate(55,6);
    printf("2 for Paper");

    Sleep(500);
    co_ordinate(55,7);
    printf("3 for Scissor");

    Sleep(3000);
    co_ordinate(14,8);
    printf("In Single-player Mode; CPU will choose a random move and then the result will be determined.");

    Sleep(2000);
    co_ordinate(44,9);
    printf("This will continue for 5 rounds.");

    Sleep(3000);
    co_ordinate(36,10);
    printf("The player with more round wins; wins the match.");

    Sleep(5000);

    system("cls");

	co_ordinate(57,0);
	printf("OKAY!!!");

	Sleep(1000);
	co_ordinate(58,1);
	printf("ARE");

	Sleep(1000);
	co_ordinate(58,2);
	printf("YOU");

	Sleep(1000);
	co_ordinate(57,3);
	printf("READY???");

    Sleep(3000);
}
int input_player_1_single_player()
{
    move player_1;
    co_ordinate(0,1);
    printf("Enter choice(1 for Rock; 2 for Paper; 3 for Scissor):");
    fflush(stdin);
    scanf("%d",&player_1);
    while(player_1>3 || player_1==0)
    {
        printf("Invalid Input!Please Enter Again!\n(1 for Rock; 2 for Paper; 3 for Scissor):");
        scanf("%d",&player_1);
    }
    return (player_1);
}
int input_player_1_multi_player()
{
    move player_1;
    co_ordinate(0,1);
    printf("Player 1's turn");
    printf("\nEnter choice(1 for Rock; 2 for Paper; 3 for Scissor):");
    fflush(stdin);
    scanf("%d",&player_1);
    while(player_1>3 || player_1==0)
    {
        printf("Invalid Input!Please Enter Again!\n(1 for Rock; 2 for Paper; 3 for Scissor):");
        scanf("%d",&player_1);
    }
    return (player_1);
}
int input_player_2_multi_player()
{
    move player_2;
    printf("\n\nPlayer 2's turn");
    printf("\nEnter choice(1 for Rock; 2 for Paper; 3 for Scissor):");
    fflush(stdin);
    scanf("%d",&player_2);
    while(player_2>3 || player_2==0)
    {
        printf("Invalid Input!Please Enter Again!\n(1 for Rock; 2 for Paper; 3 for Scissor):");
        scanf("%d",&player_2);
    }
    return (player_2);
}
int input_cpu()
{
    move player_2;

    printf("\n\nCPU is thinking!!");
		Sleep(5000);
		fflush(stdin);
		player_2=rand() % 4;
		while(player_2==0)
        {
            player_2=rand() % 4;
        }
		return (player_2);
}
void co_ordinate(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void print_score_card_single_player(int score_of_player_1,int score_of_player_2)
{
	co_ordinate(103,0);
	printf("SCORE  CARD");
	co_ordinate(97,1);
	printf("-----------------------");
	co_ordinate(97,2);
	printf("|  Player  |    CPU   |");
	co_ordinate(97,3);
	printf("-----------------------");
	co_ordinate(97,4);
	printf("|");
	co_ordinate(108,4);
	printf("|");
	co_ordinate(119,4);
	printf("|");
	co_ordinate(97,5);
	printf("-----------------------");
	co_ordinate(102,4);
	printf("0%d",score_of_player_1);
	co_ordinate(113,4);
	printf("0%d",score_of_player_2);
}
void print_score_card_multi_player(int score_of_player_1,int score_of_player_2)
{
    co_ordinate(103,0);
	printf("SCORE  CARD");
	co_ordinate(97,1);
	printf("-----------------------");
	co_ordinate(97,2);
	printf("| Player 1 | Player 2 |");
	co_ordinate(97,3);
	printf("-----------------------");
	co_ordinate(97,4);
	printf("|");
	co_ordinate(108,4);
	printf("|");
	co_ordinate(119,4);
	printf("|");
	co_ordinate(97,5);
	printf("-----------------------");
	co_ordinate(102,4);
	printf("0%d",score_of_player_1);
	co_ordinate(113,4);
	printf("0%d",score_of_player_2);
}
void print_final_score_card_single_player(int score_of_player_1,int score_of_player_2)
{
    co_ordinate(54,0);
	printf("FINAL SCORE");

	co_ordinate(48,1);
	printf("-----------------------");

	co_ordinate(48,2);
	printf("|  Player  |    CPU   |");

	co_ordinate(48,3);
	printf("-----------------------");

	co_ordinate(48,4);
	printf("|");

	co_ordinate(59,4);
	printf("|");

	co_ordinate(70,4);
	printf("|");

	co_ordinate(53,4);
	printf("0%d",score_of_player_1);

	co_ordinate(64,4);
	printf("0%d",score_of_player_2);

    co_ordinate(48,5);
	printf("-----------------------");
}
void print_final_score_card_multi_player(int score_of_player_1,int score_of_player_2)
{
    co_ordinate(54,0);
	printf("FINAL SCORE");

	co_ordinate(48,1);
	printf("-----------------------");

	co_ordinate(48,2);
	printf("| Player 1 | Player 2 |");

	co_ordinate(48,3);
	printf("-----------------------");

	co_ordinate(48,4);
	printf("|");

	co_ordinate(59,4);
	printf("|");

	co_ordinate(70,4);
	printf("|");

	co_ordinate(53,4);
	printf("0%d",score_of_player_1);

	co_ordinate(64,4);
	printf("0%d",score_of_player_2);

    co_ordinate(48,5);
	printf("-----------------------");
}
