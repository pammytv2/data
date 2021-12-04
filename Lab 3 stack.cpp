#include <stdio.h>
#include <conio.h>
#define MaxStack 6 // set Max Stack

int stack[MaxStack]; // Declare Max Stack 0.5
int x;               // Temp Variable
int SP = 0;          // Initial SP=0
char status = 'N';   // Temp Variable
char ch;             // Temp Variable

void push(int x)
{ // Push Function
    if (SP == MaxStack-1)
    { // Check Stack Full?
        printf("\n....overflow....\n");
        status = 'O'; // Set Status  = Overflow
    }
    else
    {
       SP++;          // Increase SP
        stack[SP] = x; // PUT data into Stack
    }

} // End Push Function
int pop()
{                // Pop Function
    int x;       // Temp Variable
    if (SP != 0) // Check Stack empty?
    {
        x = stack[SP]; // GET data from Stack
        SP--;          // Decrease SP
        return (x);      // Return data
    }
    else
    {
        printf("\n....underflow....\n");
        status = 'U'; // Set Status  = Underflow
    }

} // End of Pop Function
void ShowAllStack() // show all stack
{
    int i;
    printf("N : %d\n", MaxStack - 1); // Display N
    printf("Status %c\n", status);    // Display Stack[0]
    printf("SP : %d\n", SP);          // Display SP
    for (i = 1; i < MaxStack; i++)   // Display Stack[1] to Stack[SP]
    {
        printf("%d %d", i, stack[i]); // Display  ALL OF DATA IN STACK
    }
    printf("\n-----------------------------------------------------\n");

} // End of ShowAllStack

int main()
{
    printf("STACK PROGRAM\n");
    printf("===========================\n");
    while (status == 'N')
    {
        printf("[1] Push :         [2] Pop:         " ); // show menu
        ch = getch();                                                // Wait for user input
        switch (ch )
        {
        case '1':
            printf("\nEnter data : ");
            scanf("%d", &x);
            push(x);
            ShowAllStack();

            break;
        case '2':
            x = pop();
            printf("Pop data : %d\n", x);
            ShowAllStack();

            break;
        }
    }
    printf("\n\n");
    return 0;
}
