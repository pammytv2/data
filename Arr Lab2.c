#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define l 1   //lower Bound
#define u  5//upper Bound
#define l1 1 //lower Bound 1
#define u1 3 //upper Bound 1
#define l2 1 //lower Bound 2
#define u2 4 //upper Bound 2
#define l3 1 //lower Bound 3
#define u3 5 //upper Bound 3


int*BA1 ,*BA2,*BA3,*p; //Base address of each dimension and move pointer
int i,j,k; //subscript of array
char ch,ch1;




void Create1DArray()
{ //Create Array  1 dimension
int element,c,totle_mem;//Variable uses
element=(u-l+1); //Calculate element 
c = sizeof(*BA1); //Calculate size each block of array
totle_mem = element * c; //Calculate total size of array
BA1 = (int*)malloc(totle_mem); //Allocate memory
   
}
void A1(int i,int x){
    //Put data  into Array 1 dimension
    p=BA1+(i-1); //Calculata position of array
    *p=x; //Put array

}
int ReadA1(int i){
    //Read data from Array 1 dimension
    p=BA1+(i-1); //Calculata position of array
    return (*p); //Read array
}
//--------------------------------------------------------------------------------------------------------------------
void Create2DArray(){
int element,c,totle_mem;//Variable uses
element=(u1-l1+1)*(u2-l2+1); //Calculate element
c = sizeof(*BA2); //Calculate size each block of array
totle_mem = element * c; //Calculate total size of array
BA2 = (int*)malloc(totle_mem); //Allocate memory
}

void A2(int i,int j,int x){
    //Put data  into Array 2 dimension
    p=BA2+(i-l1)*(u2-l2+1)+(j-l2); //Calculata position of array
    *p=x; //Put array

}
int ReadA2(int i,int j){
    //Read data from Array 2 dimension
    p=BA2+(i-l1)*(u2-l2+1)+(j-l2); //Calculata position of array
    return (*p); //Read array
}
//---------------------------------------------------------------------------------------------------------------------
void Create3DArray(){
int element,c,totle_mem;//Variable uses
element=(u1-l1+1)*(u2-l2+1)*(u3-l3+1); //Calculate element
c = sizeof(*BA3); //Calculate size each block of array
totle_mem = element * c; //Calculate total size of array
BA3 = (int*)malloc(totle_mem); //Allocate memory 

}
void A3(int i,int j,int k,int x){
    //Put data  into Array 3 dimension
    p=BA3+(i-l1)*(u2-l2+1)*(u3-l3+1)+(j-l2)*(u3-l3+1)+(k-l3); //Calculata position of array
    *p=x; //Put array
}
int ReadA3(int i,int j,int k){
    //Read data from Array 3 dimension
    p=BA3+(i-l1)*(u2-l2+1)*(u3-l3+1)+(j-l2)*(u3-l3+1)+(k-l3); //Calculata position of array
    return (*p); //Read array
}

//---------------------------------------------------------------------------------------------------------------------

void PCR(int i,int j,int k,int x){
    //Print Array 3 dimension
    p=BA3+(i-l1)*(u2-l2+1)*(u3-l3+1)+(k-l3)*(u2-l2+1)+(j-l2); //Calculata position of array
    *p=x; //Put array

}
int ReadPCR(int i,int j,int k){
    //Read data from Array 3 dimension
    p=BA3+(i-l1)*(u2-l2+1)*(u3-l3+1)+(k-l3)*(u2-l2+1)+(j-l2); //Calculata position of array
    return (*p); //Read array
}
//---------------------------------------------------------------------------------------------------------------------
void RPC(int i,int j,int k,int x){

    //Print Array 3 dimension
    p=BA3+(j-l2)*(u1-l1+1)*(u3-u3+1)+(i-l1)*(u3-l1+1)+(k-l3); //Calculata position of array
    *p=x; //Put array

}
int ReadRPC(int i,int j,int k){
    //Read data from Array 3 dimension
    p=BA3+(j-l2)*(u1-l1+1)*(u3-u3+1)+(i-l1)*(u3-l1+1)+(k-l3);
    return (*p); //Read array
}

//---------------------------------------------------------------------------------------------------------------------
void RCP(int i,int j,int k,int x){
    //Print Array 3 dimension
    p=BA3+(j-l2)*(u1-l1+1)(u3-l3+1)+(k-l3)(u1-l1+1)+(i-l1); //Calculata position of array
    *p=x; //Put array

}
int ReadRCP(int i,int j,int k){
    //Read data from Array 3 dimension
    p=BA3+(j-l2)*(u1-l1+1)(u3-l3+1)+(k-l3)(u1-l2+1)+(i-l1);
    return (*p); //Read array


//---------------------------------------------------------------------------------------------------------------------
void CPR(int i,int j,int k,int x){
    //Print Array 3 dimension
   P=BA3+(k-l3)(u1-l1+1)(u2-l2+1)+(i-l1)(u2-l2+1)+(j-l) //Calculata position of array
    *p=x; //Put array

}
int ReadCPR(int i,int j,int k){
    //Read data from Array 3 dimension
    p=BA3+(k-l3)(u1-l1+1)(u2-l2+1)+(i-l1)(u2-l2+1)+(j-l)
    return (*p); //Read array
}
//---------------------------------------------------------------------------------------------------------------------

void CRP(int i,int j,int k,int x){
    //Print Array 3 dimension
    p=BA3+(k-l3)(u1-l1+1)(u2-l2+1)+(j-l2)(u1-l1+1)+(i-l1); //Calculata position of array
    *p=x; //Put array

}
int ReadCRP(int i,int j,int k){
    //Read data from Array 3 dimension
    p=BA3+(k-l3)(u1-l1+1)(u2-l2+1)+(j-l2)(u1-l1+1)+(i-l1);
    return (*p); //Read array
}

//----------------------------------------------------------------------------------------------------------------------------






int main(){
    printf("1-3 DIMENSION ARRAY FUNCTION....\n");
    printf("_\n");
    // Creata Array......
    while(ch!='0'){
        printf("\n(1)  \n(2)  \n(3)  \n"); //Show MENU 
        printf("\n"); 
        ch = getch(); //Wait and read KBD with out ENTER Pressed
    system("cls");
        switch(ch) //Check ch
            {
        case '1'  : Create1DArray();
                         i=2;
                        A1(i,9);
                        printf("\nA1(%d)=%d",i,ReadA1(i));
                    break;
        case '2'  : Create2DArray();
                    i=2; j=3;
                    A2(i,j,99);
                    printf("\nA2(%d,%d)=%d",i,j,ReadA2(i,j));
                    break;
        case '3'  : Create3DArray();
                    i=2; j=3; k=5;
                    A3(i,j,k,999);
                       printf("\nA3(%d,%d,%d)=%d",i,j,k,ReadA3(i,j,k));
                    break;
        case '0'  : exit(0);
            }
    getch(); //Wait for key
    free(BA1); //Free memory
    free(BA2); //Free memory
    free(BA3); //Free memory

   
}//END Main
    return 0;
}//END Program