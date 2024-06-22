#include <stdio.h>
#include <string.h>


int main()
{
    char ch, prev;
    int counter=0;
    ch = getchar();
    if(ch == '#') printf("You haven't entered anything!\n");
    else {
        prev = ch;
        ch = getchar();
        if (ch == '#') printf("There were 0 \"ei\" sequences, because you've entered # on the second symbol.\n");
        else {
            //printf("%c%c\n", prev, ch);
            if (prev=='e' && ch=='i') counter++;
            prev = ch;
            while((ch=getchar())!='#')
            {
                if (prev == 'e' && ch == 'i') counter++;
                prev = ch;
            }
            printf("There were %d \"ei\" enters.\n", counter);
        }
    }

    return 0;
}
