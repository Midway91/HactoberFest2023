
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rockpaperscissor(char you, char com);

int rockpaperscissor(char you,char com)
{
    if(you==com)
    {
        return 0;
    }
    if(you=='r' && com=='p')
    {
        return -1;
    }
    else if(you=='p' && com=='r')
    {
        return 1;
    }
    if(you=='r' && com=='s')
    {
        return 1;
    }
    else if(you=='s' && com=='r')
    {
        return -1;
    }
    if(you=='s' && com=='p')
    {
        return 1;
    }
    else if(you=='p' && com=='s')
    {
        return -1;
    }
}

void main()
{
    char you,com;
    srand(time(0));
    int n = rand()%100 + 1;
    if(n>0 && n<33)
    {
        com = 'r';
    }
    else if(n>=33 && n<66)
    {
        com = 'p';
    }
    else if(n>=66 && n<=100)
    {
        com = 's';
    }
    printf("Enter r for rock, p for paper, s for scissor:\n");
    scanf("%c",&you);
    int result = rockpaperscissor(you,com);
    if(result==0)
    {
        printf("You have tied with computer\n");
    }
    else if(result==1)
    {
        printf("You have won the game\n");
    }
    else if(result==-1)
    {
        printf("You have lost the game\n");
    }
    printf("You choose %c and computer choose %c\n",you,com);
}