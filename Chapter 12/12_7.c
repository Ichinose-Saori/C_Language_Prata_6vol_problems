#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#define CYCLES 1000

#include <stdio.h>
#include <stdlib.h>

struct desire
{
	int tries;
	int sides;
	int dices;
};

int correct(int);
void mediator_for_desire(struct desire*);
void tezuna(struct desire*);

int main(void)
{
	srand(time(0));
	struct desire player;
	while (1)
	{
		mediator_for_desire(&player);
		tezuna(&player);
	}
	return 0;
}

int correct(int mode)
{
	int temp;
	if (mode == 0)
	{
		while (scanf("%d", &temp) != 1 && temp < 0)
		{
			while (getchar() != '\n')
				continue;
			printf("We only need positive integers. Now, shall we proceed?\n");
		}
	}
	else
	{
		if (scanf("%d", &temp) != 1)
		{
			printf("Thank you for your patronage! (Program stopped after NON-INTEGER value)\n");
			exit(0);
		}
	}
	
	return temp;
}

void mediator_for_desire(struct desire* main_obj) 
{
	printf("Enter amount of tries (or \'q\' to exit):\n");
	main_obj->tries = correct(1);
	printf("How many dices and sides?\n");
	main_obj->sides = correct(0);
	main_obj->dices = correct(0);
}

void tezuna(struct desire* main_obj)
{
	int temp_sum;
	printf("We had %d throws with %d dices having %d sides.\n", main_obj->tries, main_obj->dices, main_obj->sides);
	for (int i = 0; i < main_obj->tries; i++)
	{
		temp_sum = 0;
		for (int j = 0; j < main_obj->dices; j++)
			temp_sum += rand() % main_obj->sides + 1;
		printf("%d ", temp_sum);
		if (i % 10 == 9) putchar('\n');
	}
	putchar('\n');
}
