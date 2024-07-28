static int prev_mode = 0;
static int path = 0;
static double fuel = 0.0;

void set_mode(int);
void get_info(void);
void show_info(void);

void set_mode(int n)
{
	if (n == 0 || n == 1)
		prev_mode = n;
	else
	{
		printf("ERROR: wrong number. Last mode will be used. (0 if no previous entries are seen).\n");
	}
}

void get_info(void)
{
	if (prev_mode == 0)
	{
		printf("Enter your distance in km:\n");
		scanf("%d", &path);
		printf("Enter amount of fuel spent in liters:\n");
		scanf("%lf", &fuel);
	}
	else if (prev_mode == 1)
	{
		printf("Enter your distance in miles:\n");
		scanf("%d", &path);
		printf("Enter amount of fuel spent in gallons:\n");
		scanf("%lf", &fuel);
	}
}

void show_info(void)
{
	if (fuel == 0 && path == 0)
		printf("We don't know, please enter real data.\n");
	else if (fuel == 0)
		printf("God, you have perpetuum mobile! Or you mistyped...\n");
	else if (path == 0)
		printf("Hmm, your car is broken or didn't really move.\n");
	else if (prev_mode == 0)
	{
		printf("Fuel consumption is %lf liters per 100 km.\n", fuel*100.0/(double)path);
	}
	else if (prev_mode == 1)
	{
		printf("Fuel consumption is %lf miles per gallon.\n", (double)path / fuel);
	}

}
