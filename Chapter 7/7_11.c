#include <stdio.h>
#include <string.h>

struct order
{
    int artichoke_weight;
    int beetroot_weight;
    int carrot_weight;
};

#define ARTICHOKE 2.05
#define BEETROOT 1.15
#define CARROT 1.09
#define DISCOUNT 100.0
#define DISCOUNT_AMO 0.95
#define FIRTRE 5
#define SECTRE 20
#define PRICE_FIR 6.50
#define PRICE_SEC 14.00
#define FEE 0.50



void shop_info(void);
int correct_input4(void);
int correct_input_for_int(void);
struct order client_orders(void);
void process_order(struct order token);

int main()
{
    struct order token;
    shop_info();
    token = client_orders();
    process_order(token);
    return 0;
}

void shop_info(void)
{
    printf("Hello, dear customer!!!\n");
    int option;
    printf("Choose what information is worth your attention:\n");
    printf("1) Prices\n2) Discount\n3) Delivery prices\n4) Exit\n");
    option = correct_input4();
    while(option!=4)
    {
    switch(option)
    {
    case 1:
        printf("Our prices are like this today:\n");
        printf("1) Artichoke is $%.2lf per pound.\n", ARTICHOKE);
        printf("2) Beetroot is $%.2lf per pound.\n", BEETROOT);
        printf("3) Carrot is $%.2lf per pound.\n", CARROT);
        break;
    case 2:
        printf("Be sure to know, that you get 5%% discount for sums >= $%d, that applies to sum before delivery.\n", DISCOUNT);
        break;
    case 3:
        printf("%lf for weights under %lf\n", PRICE_FIR, FIRTRE);
        printf("%lf for weights between %lf and %lf pounds\n", PRICE_SEC, FIRTRE, SECTRE);
        printf("For every pound above %lf you pay %lf and plus %lf\n", SECTRE, FEE, PRICE_SEC);
        break;
    }
    printf("Anything else?\n");
    option = correct_input4();
    }
    printf("The information part is over, thanks!\n\n");
}

int correct_input4(void)
{
    int choice;
    while((scanf("%d", &choice))!=1 || choice<1 || choice>4)
    {
        printf("Please, enter integer from 1 to 4.\n");
    }
    return choice;
}

int correct_input_for_int()
{
    int a;
    while((scanf("%d", &a))!=1)
    {
        printf("Please, enter INT type :(\n");
    }
    return a;
}

struct order client_orders(void)
{
    struct order token;
    token.artichoke_weight = 0;
    token.beetroot_weight = 0;
    token.carrot_weight = 0;
    int option, temp;
    printf("Please, start your order and choose from options below:\n");
    printf("1) Artichokes\n2) Beetroots\n3) Carrots\n4) End order\n\n");
    option = correct_input4();
    while(option!=4)
    {
        switch(option)
        {
        case 1:
            printf("Please, enter weight in lbs.\n");
            token.artichoke_weight += correct_input_for_int();
            break;
        case 2:
            printf("Please, enter weight in lbs.\n");
            token.beetroot_weight += correct_input_for_int();
            break;
        case 3:
            printf("Please, enter weight in lbs.\n");
            token.carrot_weight += correct_input_for_int();
            break;
        }
        option = correct_input4();
    }
    return token;
}

void process_order(struct order token)
{
    double summ = 0;
    double sum_orig;
    double delivery = 0;
    int weight = 0;
    summ+= (double)token.artichoke_weight*ARTICHOKE + (double)token.beetroot_weight*BEETROOT + (double)token.carrot_weight*CARROT;
    weight+= token.artichoke_weight + token.beetroot_weight + token.carrot_weight;
    if (weight==0)
    {
        printf("You haven't bought anything, so no money today.\n");
        return;
    }
    sum_orig = summ;
    if (summ>DISCOUNT) summ*=DISCOUNT_AMO;
    printf("Our prices are like this today:\n");
    printf("1) Artichoke is $%.2lf per pound.\n", ARTICHOKE);
    printf("2) Beetroot is $%.2lf per pound.\n", BEETROOT);
    printf("3) Carrot is $%.2lf per pound.\n", CARROT);

    printf("So, you have ordered %d lbs of artichoke, %d lbs of beetroot and %d lbs of carrot.\n", token.artichoke_weight, token.beetroot_weight, token.carrot_weight);
    printf("You have bought artichokes for %.2lf pounds.\n", (double)token.artichoke_weight*ARTICHOKE);
    printf("You have bought beetroots for %.2lf pounds.\n", (double)token.beetroot_weight*BEETROOT);
    printf("You have bought carrots for %.2lf pounds.\n", (double)token.beetroot_weight*CARROT);

    printf("That sums to %.2lf\n", sum_orig);

    if(sum_orig>DISCOUNT) printf("Your discount is $%.2lf\n", sum_orig-summ);

    if(weight<FIRTRE) delivery+=PRICE_FIR;
    else if (weight<SECTRE) delivery+= PRICE_SEC;
    else delivery += PRICE_SEC + (weight-SECTRE)*FEE;

    printf("You will pay $%.2lf for delivery\n", delivery);
    summ+=delivery;
    printf("Finally, your check is $%.2lf.\n", summ);

}
