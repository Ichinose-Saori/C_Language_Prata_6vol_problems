#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int* make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
	int* pa;
	int size;
	int value;

	printf("Enter the amount of elements:\n");
	while (scanf("%d", &size) == 1 && size > 0)
	{
		printf("Enter initialisation value:\n");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the amount of elements (0 or less to quit):\n");
	}
	printf("The end.\n");
	return 0;
}

int* make_array(int elem, int val)
{
	int* pa = malloc(elem * sizeof(int));
	for (int i = 0; i < elem; i++)
	{
		pa[i] = val;
	}
	return pa;
}

void show_array(const int ar[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", ar[i]);
	putchar('\n');
}
