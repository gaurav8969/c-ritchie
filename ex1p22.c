/*This program sends back the input text, edited such that no line of input exceeds "x" characters, which we
decide*/
#include <stdio.h>
#include<string.h>
#define NUMBER 1000
int split(char word[]);
int margin,countdown; 
int main()
{   int i,slot;
    slot = 0;
    margin = countdown = 20;
    char word[NUMBER];
    while((i = getchar()) != EOF)
    {if(i == ' ' || i == '\t' || i == '\n')
        {if(countdown >= slot)
            {printf("%s",word);
            countdown = countdown - (slot);
            if (countdown > 0)
            {
                putchar(' ');
                --countdown;
            }
            }
        else
            {if(countdown != margin)
                {printf("\n");
                countdown = margin;}
            split(word);}
        memset(word, 0, NUMBER);
        slot = 0;
        if (i == '\n')
            {printf("\n");
            countdown = margin;}
        i = getchar();
        }
    word[slot] = i;
    ++slot;
    }
}
int split(char word[])
{
    int j = 0;
    while(word[j] != 0)
    {if( countdown > 0 )
        {printf("%c",word[j]);
        --countdown;
        ++j;
        }
    else
    {printf("\n");
    countdown = margin;}
    }
    if (countdown > 1)
        {putchar(' ');
        --countdown;}
}