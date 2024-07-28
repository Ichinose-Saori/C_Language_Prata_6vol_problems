void set_mode(int*, int*);
void get_info(int, int*, double*);
void show_info(int, int, double);

void set_mode(int *prev, int *n)
{
	if (*n == 0 || *n == 1)
		*prev = *n;
	else
	{
		printf("ERROR: wrong number. Last mode will be used. (0 if no previous entries are seen).\n");
		*n = *prev;
	}
}

void get_info(int mode, int* path, double *fuel)
{
	if (mode == 0)
	{
		printf("Enter your distance in km:\n");
		scanf("%d", path);
		printf("Enter amount of fuel spent in liters:\n");
		scanf("%lf", fuel);
	}
	else if (mode == 1)
	{
		printf("Enter your distance in miles:\n");
		scanf("%d", path);
		printf("Enter amount of fuel spent in gallons:\n");
		scanf("%lf", fuel);
	}
}

void show_info(int prev_mode, int path, double fuel)
{
	if (fuel == 0 && path == 0)
		printf("We don't know, please enter real data.\n");
	else if (fuel == 0)
		printf("God, you have perpetuum mobile! Or you mistyped...\n");
	else if (path == 0)
		printf("Hmm, your car is broken or didn't really move while sipping your fuel.\n");
	else if (prev_mode == 0)
	{
		printf("Fuel consumption is %lf liters per 100 km.\n", fuel * 100.0 / (double)path);
	}
	else if (prev_mode == 1)
	{
		printf("Fuel consumption is %lf miles per gallon.\n", (double)path / fuel);
	}

}
