#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define MaxStack 100

char postfix1[80] = {"(A^B)+C-d/"};
float ValPostfix[80];
float ValOperandST[MaxStack];
int SP = 0;

void push(float ValOperand)
{
    if (SP == MaxStack)
    {
        printf("Stack Overflow");
    }
    else
    {
        SP++;
        ValOperandST[SP]=ValOperand;
        
    }
}
float pop()
{
    float ValOperand;
    if (SP!=0)
    {
    	ValOperand=ValOperandST[SP];
        SP--;
        return (ValOperand);
    }
    else
    {
        printf("Stack Underflow");
    }
}
void CalPostfix(char postfix[80])
{
    float pop1, pop2, value;
    int i, len;
    char ch;
    len = strlen(postfix);
    printf("\nPostfix Expression: %s", postfix);
    for (i = 0; i <= len - 1; i++)
    {
        ch = postfix[i];
        if (strchr("+-*/",ch)==0)
        {
            printf("\nAssing Number to %c :", ch);
            scanf("%f", &ValPostfix[i]);
        }
    }
    for (i = 0; i <= len - 1; i++)
    {
        ch = postfix[i];
        if (strchr("+-*/", ch) == 0)
        {
            push(ValPostfix[i]);
        }
        else
        {
            pop1 = pop();
            pop2 = pop();
            switch (ch)
            {
            case '+':
                value = pop2 + pop1;
                push(value);
                break;

            case '-':
                value = pop2 - pop1;
                push(value);
                break;
            case '*':
                value = pop2 * pop1;
                push(value);
                break;
            case '/':
                value = pop2 / pop1;
                push(value);
                break;
            case '^':
                value = pow(pop2, pop1);
                push(value);
                break;
            
                
            	
               
            }
        }
    }
    printf("\nANS: %.2f", pop());
}

int main()
{   printf("\nPOstfix Calculation program\n");
    printf("\n---------------------------------------------\n");
    CalPostfix(postfix1);
    getch();
    return 0;
}

