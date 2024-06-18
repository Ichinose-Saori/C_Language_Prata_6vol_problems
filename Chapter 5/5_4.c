#include <stdio.h>

#define HOUOUIN "EL PSY CONGROO!"
#define CM_IN_FT 30.48
#define CM_IN_INCH 2.54

int main()
{
    printf("Takasa wo senchimeetoru de nyun shite kudasai!\n"
           "Koko kara detehoshii nara, rei yori chhisai suu wo kureteagete kudasai!\n");
    float height;
    scanf("%f", &height);
    while(height>0)
    {
        printf("%.1f centimeters = %d ft and %.1f in.\n", height, (int)(height/CM_IN_FT), (height-CM_IN_FT*(int)(height/CM_IN_FT))/CM_IN_INCH);
        scanf("%f", height);
    }

    return 0;
}
