#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct Stack 
{
    int Data;
    struct Stack *Next;
    struct Stack *Prev;
};

struct Stack * push(struct Stack *Top, char data)
{
    struct Stack *Temp;
    if (Top == NULL)
    {
        Temp = (struct Stack *)malloc(sizeof(struct Stack));
        Temp->Data = data - '0';
        Temp->Next = NULL;
        Temp->Prev = NULL;
        Top = Temp;
    }
    else
    {
        Temp = (struct Stack *)malloc(sizeof(struct Stack));
        Temp->Data = data - '0';  
        Temp->Next = Top;   
        Top->Prev = Temp;  
        Temp->Prev = NULL;  
        Top = Temp;
    }
    return Top;
}

struct Stack * pop(struct Stack *Top)
{
    Top = Top->Next;
    free(Top->Prev);
    Top->Prev = NULL;
    return(Top);
}

void main()
{
    char Exp[50];
    struct Stack *Top = NULL;
    int opp1, opp2, opp3;
    printf("Input Postfix Expression: ");
    scanf("%s", Exp);

    for (int i = 0; Exp[i] != '\0'; i++ )
    {
        if (isdigit(Exp[i]))
        {
            Top = push(Top, Exp[i]);
        }
        else if (Exp[i] == '+')
        {
            opp1 =  Top->Data;
            Top = pop(Top);
            opp2 =  Top->Data;
            Top = pop(Top);
            opp3 = (opp1 + opp2);
            Top = push(Top, opp3 +'0');
        }
        else if (Exp[i] == '-')
        {
            opp1 =  Top->Data;
            Top = pop(Top);
            opp2 =  Top->Data;
            Top = pop(Top);
            opp3 =  (opp1 - opp2);
            Top = push(Top, opp3 + '0');
        }
        else if (Exp[i] == '*')
        {
            opp1 =  Top->Data;
            Top = pop(Top);
            opp2 =  Top->Data;
            Top = pop(Top);
            opp3 = (opp1 * opp2);
            Top = push(Top, opp3+'0');
        }
        else if (Exp[i] == '/')
        {
            opp1 =  Top->Data;
            Top = pop(Top);
            opp2 =  Top->Data;
            Top = pop(Top);
            opp3 = (opp1 / opp2);
            Top = push(Top, opp3+'0');
        }
    }
    printf("Evaluated Postfix Expression simplifies to: %d", Top->Data);
    Top = pop(Top);
}