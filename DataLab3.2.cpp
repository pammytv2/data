#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define MaxStack 6
#define MaxStackx 6

/*Left To Right*/
int stack[MaxStack];
int x;
int SP = 0;
char status = 'N';

/*Right To Left*/
int stack1[MaxStackx];
int y;
int SP1 = MaxStackx;
char statusx = 'N';

char ch;

/*Left To Right*/
void push(int y)
{
	if (SP == MaxStack - 1)
	{
		printf("!!!OVER FLOW!!!\n");
		status = '0';
	} // end if
	else
	{
		SP++;
		stack[SP] = y;
	} // end else
} // end void push

int pop()
{
	int y;
	if (SP != 0 /*Left*/)
	{
		y = stack[SP];
		SP--;
	} // end if
	else
	{
		printf("\n!!!UNDER FLOW!!!");
		status = 'U';
	} // end else
	return y;
} // end int pop

void ShowAllStack()
{
	int i;
	printf("N      : %d\n", MaxStack - 1);
	printf("Status : %c\n", status);
	printf("SP     : %d\n\n", SP);

	for (i = 1; i < MaxStack; i++)
	{
		printf("%d : %d\t", i, stack[i]);
	} // end for
	printf("\n_________________________________________\n");
} // end void ShowAllStack

/*Right To Left*/
void pushx(int x)
{
	if (SP1 == 1)
	{
		printf("!!!OVER FLOW!!!\n");
		statusx = '0';
	} // end if
	else
	{
		SP1--;
		stack1[SP1] = x;
	} // end else
} // end void push

int popx()
{
	int x = -1;
	if (SP1 != MaxStackx /*Right*/)
	{
		x = stack1[SP1];
		SP1++;
	} // end if
	else
	{
		printf("\n!!!UNDER FLOW!!!");
		statusx = 'U';
	} // end else
	return x;
} // end int pop

void ShowAllStackx()
{
	int i;
	printf("N      : %d\n", MaxStackx - 1);
	printf("Status : %c\n", statusx);
	printf("SP     : %d\n\n", SP1);

	for (i = 1; i < MaxStackx; i++)
	{
		printf("%d:%d\t", i, stack1[i]);
	} // end for
	printf("\n_________________________________________\n");
} // end void ShowAllStack

// Main
int main()
{
	printf("  STACK PROGRAM...\n");
	printf("  ________________\n");

	while (status == 'N')
	{
		printf("\n  [1] = PUSH           ::  [2] = POP     ");
		printf("\n  [3] = PUSH(Inverse)  ::  [4] = POP(Inverse)  ");
		printf("\n  [5] = CLEARSCREEN    ::  [0] = EXIT \n  Select ");
		ch = getch();
		switch (ch)
		{
		case '1':
			printf("\n\nEnter Number : ");
			scanf("%d", &y);
			push(y);
			ShowAllStack();
			break;

		case '2':
			x = pop();
			printf("\n\nPop Data : %d\n", y);
			ShowAllStack();
			break;

		case '3':
			printf("\n\nEnter Number : ");
			scanf("%d", &x);
			pushx(x);
			ShowAllStackx();
			break;

		case '4':
			x = popx();
			printf("\n\nPop Data : %d\n", x);
			ShowAllStackx();
			break;

		case '5':
			system("cls");
			printf("  STACK PROGRAM...\n");
			printf("  ________________\n");
			ShowAllStackx();
			break;

		case '0':
			exit(0);
		} // end case
	}	  // end while
	return 0;
} // end int main
