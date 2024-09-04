#include <stdio.h>
#include <string.h>

#define MAXLEN 40
#define NNUM 5 //amount of people mentioned in the problem


struct full_name{
    char name[MAXLEN];
    char patronymic[MAXLEN];
    char surname[MAXLEN];
};

struct american {
    long long int social;
    struct full_name human;
};

void show_people(const struct american *);

int main(void)
{
    struct american community[NNUM] = {
        {
            100000000, 
            {
                "John", "Barry", "Allen"
            }
        },
        {
            100000001,
            {
                "Karl", "Junior", "Johnson"
            }
        },
        {
            100000002,
            {
                "Gustavo", "Huares", "Fring"
            }
        },
        {
            100000003,
            {
                .name = "Mike", .surname = "Ermintraup"
            }
        },
        {
            100000004,
            {
                "Walter", "Wachovski", "White"
            }
        }
    };

    show_people(community);
    return 0;
}

void show_people(const struct american * squad)
{
    for (int i = 0; i<NNUM; i++)
    {
        if (strlen(squad[i].human.patronymic) != 0)
        {
            printf("%s, %s %c. -- %lld\n", squad[i].human.surname, squad[i].human.name, squad[i].human.patronymic[0], squad[i].social);
        }
        else
        {
            printf("%s, %s -- %lld\n", squad[i].human.surname, squad[i].human.name, squad[i].social);
        }
    }
}
