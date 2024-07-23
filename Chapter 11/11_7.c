#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 50

char* my_strncpy(char*, char*, int);

int main(void)
{
	char arr[SIZE] = "Yappeeeeeee";
	my_strncpy(arr+10, " kitttyyyy", 4);
	puts(arr);
	return 0;
}

char* my_strncpy(char* s1, char* s2, int n)
{
	int len2 = strlen(s2);
	int i = 0;
	if (len2 < n)
	{
		for (i = 0; i<len2; i++)
			*(s1 + i) = s2[i];
		while (*(s1 + i) != '\0')
		{
			*(s1 + i) = '\0';
			i++;
		}
	}
	else
	{
		for (i = 0; i < n; i++)
			*(s1 + i) = s2[i];
		while (*(s1 + i) != '\0')
		{
			*(s1 + i) = '\0';
			i++;
		}
	}

}
