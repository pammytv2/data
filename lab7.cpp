#include <stdio.h>
#include <conio.h>

int Number, ans;

int Factorial(int N)
{
    int x, y;
    if (N == 0)
    {
        printf("\n......Roll back point\n");
        return 1;
    }
    else
    {
        x = N - 1;
        printf("%2dx! = %2d * %2d\n", N, N, x); // displaying the process
        y = Factorial(x);
        printf("%2d! = %2d * %3d = %5d\n", N, N, y, y * N); // displaying the process
        return y * N;
    }
}

int main()
{
    printf("RECURSION\n");
    printf("\n=====================\n ");
    while (Number != -999)
    {
        printf("\nEnter the number  (-999 is END): ");
        scanf("%d", &Number);
        if (Number >= -0)
        {
            printf("N! = N * (N-1)!\n");
            printf("=====================\n");

            ans = Factorial(Number);
            printf("\n Answer N!= %d\n", ans);
            printf("=====================Finished\n");
            getch();
        }
    }
    return 0;
}  //end of main
 