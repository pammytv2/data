#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define l 1  // lower Bound
#define u 5  // upper Bound
#define l1 1 // lower Bound 1
#define u1 3 // upper Bound 1
#define l2 1 // lower Bound 2
#define u2 4 // upper Bound 2
#define l3 1 // lower Bound 3
#define u3 5 // upper Bound 3

int *BA1, *BA2, *BA3, *p; // Base address of each dimension and move pointer
int i, j, k, x, ch1;      // subscript of array
char ch;

void Create1DArray()
{                                   // Create Array  1 dimension
    int element, c, totle_mem;      // Variable uses
    element = (u - l + 1);          // Calculate element
    c = sizeof(*BA1);               // Calculate size each block of array
    totle_mem = element * c;        // Calculate total size of array
    BA1 = (int *)malloc(totle_mem); // Allocate memory
}
void A1(int i, int x)
{
    // Put data  into Array 1 dimension
    p = BA1 + (i - 1); // Calculata position of array
    *p = x;            // Put array
}
int ReadA1(int i)
{
    // Read data from Array 1 dimension
    p = BA1 + (i - 1); // Calculata position of array
    return (*p);       // Read array
}
//--------------------------------------------------------------------------------------------------------------------
void Create2DArray()
{
    int element, c, totle_mem;               // Variable uses
    element = (u1 - l1 + 1) * (u2 - l2 + 1); // Calculate element
    c = sizeof(*BA2);                        // Calculate size each block of array
    totle_mem = element * c;                 // Calculate total size of array
    BA2 = (int *)malloc(totle_mem);          // Allocate memory
}

void A2CM(int i, int j, int x)
{
    // Put data  into Array 2 dimension
    p = BA2 + (i - l1) * (u2 - l2 + 1) + (j - l2); // Calculata position of array
    *p = x;                                        // Put array
}
int ReadA2CM(int i, int j)
{
    // Read data from Array 2 dimension
    p = BA2 + (i - l1) * (u2 - l2 + 1) + (j - l2); // Calculata position of array
    return (*p);                                   // Read array
}

void A2Row_Major(int i, int j, int x)
{
    // Put data  into Array 2 dimension
    p = BA2 + (j - l2) * (u1 - l1 + 1) + (i - l1); // Calculata position of array
    *p = x;                                        // Put array
}
int ReadA2Row_Major(int i, int j)
{
    // Read data from Array 2 dimension
    p = BA2 + (j - l2) * (u1 - l1 + 1) + (i - l1); // Calculata position of array
    return (*p);                                   // Read array
}

// #3D Array---------------------------------------------------------------------------------------------------------------------
void Create3DArray()
{
    int element, c, totle_mem;                               // Variable uses
    element = (u1 - l1 + 1) * (u2 - l2 + 1) * (u3 - l3 + 1); // Calculate element
    c = sizeof(*BA3);                                        // Calculate size each block of array
    totle_mem = element * c;                                 // Calculate total size of array
    BA3 = (int *)malloc(totle_mem);                          // Allocate memory
}
void A3(int i, int j, int k, int x)
{
    // Put data  into Array 3 dimension
    p = BA3 + (i - l1) * (u2 - l2 + 1) * (u3 - l3 + 1) + (j - l2) * (u3 - l3 + 1) + (k - l3); // Calculata position of array
    *p = x;                                                                                   // Put array
}
int ReadA3(int i, int j, int k)
{
    // Read data from Array 3 dimension
    p = BA3 + (i - l1) * (u2 - l2 + 1) * (u3 - l3 + 1) + (j - l2) * (u3 - l3 + 1) + (k - l3); // Calculata position of array
    return (*p);                                                                              // Read array
}

//---------------------------------------------------------------------------------------------------------------------

void A3PCR(int i, int j, int k, int x)
{
    // Print Array 3 dimension
    p = BA3 + (i - l1) * (u2 - l2 + 1) * (u3 - l3 + 1) + (k - l3) * (u2 - l2 + 1) + (j - l2); // Calculata position of array
    *p = x;                                                                                   // Put array
}
int ReadA3PCR(int i, int j, int k)
{
    // Read data from Array 3 dimension
    p = BA3 + (i - l1) * (u2 - l2 + 1) * (u3 - l3 + 1) + (k - l3) * (u2 - l2 + 1) + (j - l2); // Calculata position of array
    return (*p);                                                                              // Read array
}
//---------------------------------------------------------------------------------------------------------------------
void A3RPC(int i, int j, int k, int x)
{

    // Print Array 3 dimension
    p = BA3 + (j - l2) * (u1 - l1 + 1) * (u3 - u3 + 1) + (i - l1) * (u3 - l1 + 1) + (k - l3); // Calculata position of array
    *p = x;                                                                                   // Put array
}
int ReadA3RPC(int i, int j, int k)
{
    // Read data from Array 3 dimension
    p = BA3 + (j - l2) * (u1 - l1 + 1) * (u3 - u3 + 1) + (i - l1) * (u3 - l1 + 1) + (k - l3);
    return (*p); // Read array
}

//---------------------------------------------------------------------------------------------------------------------
void A3RCP(int i, int j, int k, int x)
{
    // Print Array 3 dimension
    p = BA3 + (j - l2) * (u1 - l1 + 1) * (u3 - l3 + 1) + (k - l3) * (u1 - l1 + 1) + (i - l1); // Calculata position of array
    *p = x;                                                                                   // Put array
}
int ReadA3RCP(int i, int j, int k)
{
    // Read data from Array 3 dimension
    p = BA3 + (j - l2) * (u1 - l1 + 1) * (u3 - l3 + 1) + (k - l3) * (u1 - l2 + 1) + (i - l1);
    return (*p); // Read array
}

//---------------------------------------------------------------------------------------------------------------------
void A3CPR(int i, int j, int k, int x)
{
    // Print Array 3 dimension
    p = BA3 + (k - l3) * (u1 - l1 + 1) * (u2 - l2 + 1) + (i - l1) * (u2 - l2 + 1) + (j - l2); // Calculata position of array
    *p = x;
}
int ReadA3CPR(int i, int j, int k)
{
    // Read data from Array 3 dimension
    p = BA3 + (k - l3) * (u1 - l1 + 1) * (u2 - l2 + 1) + (i - l1) * (u2 - l2 + 1) + (j - l2);
    return (*p); // Read array
}
//---------------------------------------------------------------------------------------------------------------------

void A3CRP(int i, int j, int k, int x)
{
    // Print Array 3 dimension
    p = BA3 + (k - l3) * (u1 - l1 + 1) * (u2 - l2 + 1) + (j - l2) * (u1 - l1 + 1) + (i - l1); // Calculata position of array
    *p = x;                                                                                   // Put array
}
int ReadA3CRP(int i, int j, int k)
{
    // Read data from Array 3 dimension
    p = BA3 + (k - l3) * (u1 - l1 + 1) * (u2 - l2 + 1) + (j - l2) * (u1 - l1 + 1) + (i - l1);
    return (*p); // Read array
}

//----------------------------------------------------------------------------------------------------------------------------

int main()
{
    printf("1-3 DIMENSION ARRAY FUNCTION....\n");
    printf("\n");
    // Creata Array......
    while (ch != '0')
    {
        printf("Select Array dimension\n");
        printf("\n(1)1DArray \n(2)2DArray  \n(3)3DArray  \n"); // Show MENU
        printf("\n");
        ch = getch(); // Wait and read KBD with out ENTER Pressed
        system("cls");
        switch (ch)
        // Check ch
        {
            // -----------------------------------1D Array-----------------------------------------------------------
        case '1':
            Create1DArray();
            i = 2;
            A1(i, 9);
            printf("\nA1(%d)=%d\n", i, ReadA1(i));
            printf("\nAddress of BA1=%d\n", BA1);
            printf("\nAddress Aarray  = %d\n", p);
            break;
            // -----------------------------2D Array---------------------------------------------------------------
        case '2':
            printf("\n(1) Put Column Major\n(2) Put Row Major\n");
            printf("\n2DArray EnterNum(1-2) :");
            scanf("%d", &ch1);
            switch (ch1)
            {
                //---------------------------------------------------------------------------------------------------
            case 1:
                Create2DArray();
                i = 2;
                j = 3;
                A2CM(i, j, 99);
                printf("\nA2CM(%d,%d)=%d\n", i, j, ReadA2CM(i, j));
                printf("\nAddress of BA2=%d\n", BA2);
                printf("\nAddress Aarray  = %d\n", p);
                break;
            //---------------------------------------------------------------------------------------------------------
            case 2:
                Create2DArray();
                i = 2;
                j = 3;
                A2Row_Major(i, j, 99);
                printf("\nA2Row_Major(%d,%d)=%d\n", i, j, ReadA2Row_Major(i, j));
                printf("\nAddress of BA2=%d\n", BA2);
                printf("\nAddress Aarray  = %d\n", p);
                break;
            }
            break;
            // -------------------------------3D Array----------------------------------------------------
        case '3':
            
            
            printf("\n(1)Plane_Row_Colume\n(2)Plane_Colume_Row\n(3)Row_Plane_Colume\n(4)Row_Colume_Plane\n(5)Colume_Plane_Row\n(6)Colume_Row_Plane\n");
            printf("\n3DArray EnterNum(1-6) :");
            scanf("%d", &ch1);
            switch (ch1)
            {
            //----------------------------(1) Plane_Row_Colume------------------------------------------
            case 1:
                Create3DArray();
                i = 2;
                j = 3;
                k = 4;
                A3(i, j, k, 999);
                printf("\nA3(%d,%d,%d)=%d\n", i, j, k, ReadA3(i, j, k));
                printf("\nAddress of BA3=%d\n", BA3);
                printf("\nAddress Aarray  = %d\n", p);
                break;
                // ---------------------(2)Plane_Colume_Row---------------------------------------

            case 2:
                Create3DArray();
                i = 2;
                j = 3;
                k = 4;
                A3PCR(i, j, k, 999);
                printf("\nA3PCR(%d,%d,%d)=%d\n", i, j, k, ReadA3PCR(i, j, k));
                printf("\nAddress of BA3=%d\n", BA3);
                printf("\nAddress Aarray  = %d\n", p);
                break;
            // ------------------------(3)Row_Plane_Colume---------------------------------
            case 3:
                Create3DArray();
                i = 2;
                j = 3;
                k = 4;
                A3RPC(i, j, k, 999);
                printf("\nA3RPC(%d,%d,%d)=%d\n", i, j, k, ReadA3RPC(i, j, k));
                printf("\nAddress of BA3=%d\n", BA3);
                printf("\nAddress Aarray  = %d\n", p);
                break;
            // --------------------------(4)Row_Colume_Plane--------------------------------
            case 4:
                Create3DArray();
                i = 2;
                j = 3;
                k = 4;
                A3RCP(i, j, k, 999);
                printf("\nA3RCP(%d,%d,%d)=%d\n", i, j, k, ReadA3RCP(i, j, k));
                printf("\nAddress of BA3=%d\n", BA3);
                printf("\nAddress Aarray  = %d\n", p);
                break;
            // -------------------------(5)Colume_Plane_Row---------------------------------
            case 5:
                Create3DArray();
                i = 2;
                j = 3;
                k = 4;
                A3CPR(i, j, k, 999);
                printf("\nA3CPR(%d,%d,%d)=%d\n", i, j, k, ReadA3CPR(i, j, k));
                printf("\nAddress of BA3=%d\n", BA3);
                printf("\nAddress Aarray  = %d\n", p);
                break;
            // ------------------------(6)Colume_Row_Plane------------------------------------
            case 6:
                Create3DArray();
                i = 2;
                j = 3;
                k = 4;
                A3CRP(i, j, k, 999);
                printf("\nA3CRP(%d,%d,%d)=%d\n", i, j, k, ReadA3CRP(i, j, k));
                printf("\nAddress of BA3=%d\n", BA3);
                printf("\nAddress Aarray  = %d\n", p);

                break;
                // -------------------------------------------------------------------------
            }
            break;

            getch();   // Wait for key
            free(BA1); // Free memory
            free(BA2); // Free memory
            free(BA3); // Free memory

        } // END Main

    } // END Program

    return 0;
}
