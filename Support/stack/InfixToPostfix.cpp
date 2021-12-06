#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MaxStack 100

char infix1[80] = {"A+B*(C^D*E/F)-G"};
char Ostp[MaxStack];
int SP = 0;

void push(char oper)
{
    if (SP == MaxStack)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        SP++;
        Ostp[SP] = oper;
    }
}
int pop()
{
    char oper;
    if (SP != 0)
    {
        oper = Ostp[SP];
        SP--;
        return oper;
    }
    else
    {
        printf("Stack Underflow\n");
        return 0;
    }
}
int precedenceInput(char oper)
{
    switch (oper)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
void infixToPostfix(char infix2[80])
{
    int i, j, len;
    char ch, temp;
    printf("Infix: %s\n", infix2);
    len = strlen(infix2);
    printf("INFIX: Length %d\n", len);
    printf("Postfix IS : ");
    for (i = 0; i <= len - 1; i++)
    {
        ch = infix2[i];
        if (strchr("+-*/^", ch) == 0)
            printf("%c", ch);
        else
        {
            if (SP == 0)
                push(ch);
            else if (ch != ')')
            {
                if (precedenceInput(ch) > precedenceInput(Ostp[SP]))
                    push(ch);
                else
                {
                    printf("%c", pop());
                    while (precedenceInput(ch) <= precedenceInput(Ostp[SP]) && SP != 0)
                        printf("%c", pop());
                    push(ch);
                }
            }
            else
            {
                temp = pop();
                while (temp != '(')
                {
                    printf("%c", temp);
                    temp = pop();
                }
            }
        }
    }

    j = SP;
    for (i = 1; i <= j; i++)
        printf("%c", pop());
}

int main()
{
    printf("Infix to Postfix conversion program\n");
    printf("---------------------\n");
    infixToPostfix(infix1);
    getch();
    return 0;
}
