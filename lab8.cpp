#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define textcolor(txt, back) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back * 16 + txt)
#define resetcolor() SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} // end void gotoxy
int Number, ans, c;

float M;

float Fpow(int N, float M)
{
    float temp = 1;
    float i;
    int j;

    if (N == 0)
    {
        printf("\n......Roll back point\n");
        return 1;
    }
    for (j = 0; j < N; j++)
    {
        temp *= M;
    }
    printf("\n%.2f^%d = %.2f\n", M, N, temp);

    i = Fpow(N - 1, M);

    printf("\n %.2f * %.2f = %.2f\n ", i, M, M * i);
    return M * i;
}

int main()
{   textcolor(11, 0);
    printf("RECURSION\n");
    textcolor(11, 0);
    printf("\n=====================\n ");
    while (Number != -999)
    {
        textcolor(11, 0);
        printf("\nEnter the number  (POw): ");
        scanf("%d", &Number);
        printf("\nEnter the number  (M): ");
        scanf("%f", &M);
        if (Number >= -0)
        {
            printf("\n M^N = M^(N-1)\n");
            printf("=====================\n");

            ans = Fpow(Number, M);
            printf("\n Answer  M = %d \n", ans);
            printf("=====================Finished\n");
            getch();
        }
    }
    return 0;
} // end of main
