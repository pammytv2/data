#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Math.h>
#define MaxStack 100

//Convert Infix to postfix
char infix1[80] = {"A+B*(C^D*E/F)-G"};
char Ostp[MaxStack];
int SP = 0;

//Convert Postfix to number
float ValPostfix[80];
float ValOperandST[MaxStack];
int AV = 0;

//Temporart collection
char temp[80];
int count = 0 ;

void pushAV(float ValOperand)
{
    if (AV == MaxStack)
    {
        printf("Stack Overflow");
    }
    else
    {
        AV++;
        ValOperandST[AV]=ValOperand;
        
    }
}
float popAV()
{
    float ValOperand;
    if (AV!=0)
    {
    	ValOperand=ValOperandST[AV];
        AV--;
        return (ValOperand);
    }
    else
    {
        printf("Stack Underflow");
    }
}




void collect(char x){
	temp[count] = x;
	count++;
}


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
        if (strchr("+-*/^", ch) == 0){
        	collect(ch);
			printf("%c", ch);
    	}
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
                	temp = pop();
                    printf("%c", temp);
                    collect(temp);
                    while (precedenceInput(ch) <= precedenceInput(Ostp[SP]) && SP != 0){
                    	temp =  pop();
                    	collect(temp);
						printf("%c",temp);
					}
                        
                    push(ch);
                }
            }
            else
            {
                temp = pop();
                collect(temp);
                while (temp != '(')
                {
                    printf("%c", temp);
                    temp = pop();
                    collect(temp);
                }
            }
        }
    }

    j = SP;
    for (i = 1; i <= j; i++)
    	temp = pop();
    	collect(temp);
        printf("%c", temp );
}

void display(){
	printf("\n");
    int i ;
    for(i = 0 ; i <= count ; i++){
    	printf("%c" , temp[i]);
	}
	printf("\n");
}

void CalPostfix()
{
    float pop1, pop2, value;
    int i;
    char ch;
    printf("\nPostfix Expression: %s", temp);
    for (i = 0; i <= count; i++)
    {
        ch = temp[i];
        if (strchr("+-)*/(^",ch)==0)
        {
            printf("\nAssing Number to %c :", ch);
            scanf("%f", &ValPostfix[i]);
        }
    }
    for (i = 0; i <= count; i++)
    {
        ch = temp[i];
        
        if( strchr("()",ch) != 0){
        	continue;
		}
        
        if (strchr("+-*/^", ch) == 0)
        {
            pushAV(ValPostfix[i]);
        }
        else
        {
            pop1 = popAV();
            pop2 = popAV();
            switch (ch)
            {
            case '+':
                value = pop2 + pop1;
                pushAV(value);
                break;

            case '-':
                value = pop2 - pop1;
                pushAV(value);
                break;
            case '*':
                value = pop2 * pop1;
                pushAV(value);
                break;
            case '/':
                value = pop2 / pop1;
                pushAV(value);
                break;
            case '^':
                value = pow(pop2, pop1);
                pushAV(value);
                break;
            
                
            	
               
            }
        }
    }
    printf("\nANS: %.2f", popAV());
}

int main()
{
    printf("Infix to Postfix conversion program\n");
    printf("---------------------\n");
    infixToPostfix(infix1);

	display();
    CalPostfix();
    
    getch();
    return 0;
}
