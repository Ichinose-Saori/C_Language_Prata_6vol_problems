#include <stdio.h>

#define MAXLENN 50
#define GRADOS 3
#define CSIZE 4

struct name {
    char name[MAXLENN];
    char surname[MAXLENN];
};

struct student {
    struct name person;
    double grades[GRADOS];
    double average;
};

void input_grades(struct student *);
double corr_doub(void);
void average_it(struct student *);
void show_me(struct student *);
void show_average_test(struct student arr[], int, int);

int main(void)
{
    struct student arr[CSIZE] = {
        {
            .person.name = "John", .person.surname = "Connor"
        },
        {
            .person.name = "Kirill", .person.surname = "Rusanov"
        },
        {
            .person.name = "Zerui", .person.surname = "Lu"
        },
        {
            .person.name = "Wenhao", .person.surname = "Chen"
        }
    };
    for (int i = 0; i<CSIZE; i++)
    {
        input_grades(&arr[i]);
        average_it(&arr[i]);
    }
    
    for (int i = 0; i<CSIZE; i++)
    {
        show_me(&arr[i]);
    }

    for (int i = 0; i<CSIZE; i++)
    {
        show_average_test(arr, CSIZE, i);
    }
    return 0;
}

void input_grades(struct student * persona)
{
    double temp_grade;
    printf("Enter %d grades of %s %s:\n", GRADOS, persona->person.surname, persona->person.name);
    for (int i = 0; i<GRADOS; i++)
    {
        temp_grade = corr_doub();
        persona->grades[i] = temp_grade;
    }
}

double corr_doub(void)
{
    double temp;
    while ((scanf("%lf", &temp) != 1) || temp<0.0 || temp>4.0)
        puts("Try again, grades are from 0.0 to 4.0");
    return temp;
}

void average_it(struct student * persona)
{
    persona->average = 0.0;
    for (int i = 0; i<3; i++)
    {
        persona->average += persona->grades[i];
    }
    persona->average/=(double)GRADOS;
}

void show_me(struct student * persona)
{
    printf("%s %s, average grade is %lf\n", persona->person.surname, persona->person.name, persona->average);
}

void show_average_test(struct student arr[], int size, int num)
{
    double sum = 0.0;
    for (int i = 0; i<size; i++)
    {
        sum += arr[i].grades[num];
    }
    sum/=(double)size;
    printf("Test #%d on average is %lf\n", num, sum);
}
