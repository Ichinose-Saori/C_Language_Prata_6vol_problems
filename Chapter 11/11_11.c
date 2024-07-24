#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50
#define GOD 10

#include <stdio.h>
#include <string.h>

void sensei(char* arr[], int); //main function of 11_11
void nullify_god(char* orig[]); //just wanted to be sure that all are NULL
char* s_gets(char*, int); //function clipping after SIZE is found (and it replace \n for \0)
void entry_sensei(void); //entry message describing sensei abilities
int correct_int(void); //Thing allowing user to enter only correct values
void stsrt(char* strings[], int num); //sort by ASCII
void show_strarray(char* strings[], int num); //print our array
void cmplen(char* strings[], int num); //sort by length
void cmpflen(char* strings[], int num); //sort by lengths of first words


int main(void)
{
	int i = 0; //will count up to 10
	char arr[GOD][SIZE];
	char* pointers[GOD];
	nullify_god(pointers);
	puts("Please, enter up to 10 strings (enter empty one to quit):");
	while (s_gets(arr[i], SIZE, stdin) != NULL && i < 10 && arr[i][0] != '\0')
	{
		pointers[i] = arr[i];
		i++;
	}
	sensei(pointers, i);
	return 0;
}

void sensei(char *str[], int amo)
{
	char* copy[GOD];
	for (int i = 0; i < amo; i++)
		copy[i] = str[i];
	int choice;
	entry_sensei();
	choice = correct_int();
	while (choice != 5)
	{
		if (choice == 1)
		{
			show_strarray(str, amo);
		}
		else if (choice == 2)
		{
			stsrt(str, amo);
			show_strarray(str, amo);
		}
		else if (choice == 3)
		{
			cmplen(str, amo);
			show_strarray(str, amo);
		}
		else if (choice == 4)
		{
			cmpflen(str, amo);
			show_strarray(str, amo);
		}
		entry_sensei();
		choice = correct_int();
	}
	puts("Thank you for using our product!");
	
}

void nullify_god(char *orig[])
{
	for (int i = 0; i < GOD; i++)
		orig[i] = NULL;
}
char* s_gets(char* arr, int n)
{
	int i = 0;
	char* ret_val = fgets(arr, n, stdin);
	if (ret_val)
	{
		while (arr[i] != '\n' && arr[i] != '\0')
			i++;
		if (arr[i] == '\n')
			arr[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

void entry_sensei(void)
{
	printf("Please, choose what you want to do with this program:\n");
	printf("1) To see original order\n");
	printf("2) To sort by ASCII\n");
	printf("3) To sort by length of strings\n");
	printf("4) To sort by length of the first word\n");
	printf("5) Exit\n");
}

int correct_int(void)
{
	int res;
	while (scanf("%d", &res) != 1 && (res < 1 || res>5))
		continue;
	return res;
}

void stsrt(char* strings[], int num)
{
	char* temp;
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (strcmp(strings[i], strings[j]) > 0)
			{
				temp = strings[i];
				strings[i] = strings[j];
				strings[j] = temp;
			}
		}
	}
}

void show_strarray(char* arr[], int num)
{
	for (int i = 0; i < num; i++)
		puts(arr[i]);
}

void cmplen(char* strings[], int num)
{
	char* temp;
	int lens[GOD];
	for (int i = 0; i < num; i++)
		lens[i] = strlen(strings[i]);

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (lens[i]>lens[j])
			{
				temp = strings[i];
				strings[i] = strings[j];
				strings[j] = temp;
			}
		}
	}
}

void cmpflen(char* strings[], int num)
{
	int j;
	char* temp;
	int flens[GOD] = {0};
	for (int i = 0; i < num; i++)
	{
		j = 0;
		while (strings[i][j] == ' ' || strings[i][j] == '\t')
			j++;
		while (strings[i][j] != ' ' && strings[i][j] != '\t') {
			flens[i]++;
			j++;
		}
	}

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (flens[i] > flens[j])
			{
				temp = strings[i];
				strings[i] = strings[j];
				strings[j] = temp;
			}
		}
	}
}
