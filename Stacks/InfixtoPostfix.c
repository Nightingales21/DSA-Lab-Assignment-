#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
        Temp->Data = data;
        Temp->Next = NULL;
        Temp->Prev = NULL;
        Top = Temp;
    }
    else
    {
        Temp = (struct Stack *)malloc(sizeof(struct Stack)); 
        Temp->Data = data;  
        Temp->Next = Top;   
        Top->Prev = Temp;  
        Temp->Prev = NULL;  
        Top = Temp;
    }
    return Top;
}

void Peek(struct Stack *Top)
{
    printf("the data at Top is: %d", Top->Data);
}

void main()
{
    char infix[50], postfix[50] = "", a[2];
    printf("Enter the Infix Expression: ");
    scanf("%s", infix);

    for (int i=0; infix[i]!='\0'; i++)
    {
        a[0] = infix[i];
        a[1] = '\0';

        if (isdigit(infix[i]))
        {
            strcat(postfix,a);
        }
        else if (infix[i] == '(')
        {
            push(Top,infix[i]);
        }
    }
    printf("%s", postfix);
    Peek(Top);
}
