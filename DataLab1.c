#include <stdio.h> //use printf
#include <conio.h> //use getch

char ch; //KBD Read variable

void DecToBin(int data2,int byt) //Convert Decimal To Binary as byt Bytes
	{
		int count, chk, bits;
		bits = ( byt * 8 ) - 1; //Calculate total bits started at bit no 0
		for ( count = bits; count >= 0; count-- ){
			chk = data2 >> count; //shift right count bits of data2 and keep in to chk
			if (chk & 1) // conpare with '0000 0001'
				printf( "1" ); //if true
			else
				printf( "0" ); //if false
			if (count %4 == 0 && count > 3)//seperate any 4 bits
				printf( " " );
		}//end for
		printf("B\n");
	}//end void
void UnsignedShortInt() //Test Data in Unsigned Short Integer Mode
    {
    unsigned short int data ; //Declare data variable for keep short unsigned integer types
    printf("\nUNSIGNED SHORT INTEGER MODE (0 to 65,535)\n") ; 
    printf("______________________________\n") ;
    printf(" Enter Raw Data ") ; 
    scanf("%hu",&data);
    printf(" Data in Decimal  = %huD\n ", data) ;  //Show in Decimal format
    printf("Data in Hexamal  = %xH\n", data)    ;  //Show in Haxamal format
    printf(" Data in Binary   = " ) ; 
	DecToBin(data, sizeof(data)); //Show in Binary format 
    printf(" Size             = %d Bytes\n",sizeof(data)); //show size of unsigned short integer
    getch(); //Wait for press any key
    }
void UnsignedInt() //Test Data in Unsigned Integer Mode
    {
    unsigned int data ; //Declare data variable for keep unsigned integer types
    printf("\nUNSIGNED INTEGER MODE (0 to 4,294,967,295 )\n") ;
    printf("______________________________\n") ;
    printf(" Enter Raw Data ");
	scanf (" %u",&data ) ;
    printf(" Data in Decimal = %uD\n", data); //Show in Decimal format
    printf(" Data in Hexamal = %xH\n", data) ; //Show in Haxamal format
    printf(" Data in Binary  = ") ;
    DecToBin(data, sizeof(data)); //Show in Binary format printf Size
    printf(" Size            = %d Bytes\n", sizeof(data)) ; //Show size of unsigned integer
    getch(); //Wait for press any key
    }
void Boolean()//Test Data in Boolean Mode
	{
		Boolean data; //Declare data variable for keep boolean type
		printf( "\nBOOLEAN MODE ( 0 to 255 ) \n" );
		printf( "______________________________\n" );
		printf( "Enter Raw Dara " );
		scanf ( "%hu",&data );
		printf( "Data Meaning    = " ); //Show meaning
		if( data )
			printf( "TRUE\n" ); //Show if True
		else
			printf( "FALSE\n" ); //Show if False
		printf( "Data in Decimal = %uD\n",data ); //Show in	Decimal format
		printf( "Data in Hexamal = %xH\n",data ); //Show in Hexamal format
		printf( "charracter      = %c\n",data )	; //Show in Character format
		printf("Data in Binary  = ");
		DecToBin(data,sizeof(data)); //Show in Binary format
		printf("Size            = %d Bytes\n ",sizeof(data)); //Show size of unsigned short integer
		getch(); //Wait for press any key
		
	}//end void Boolean

void Character() //Test Data in Character Mode
	{
	char data; //Declare data variable for keep Character type
	printf( "\nCHARACTER MODE (Aa to Zz)\n" );
	printf( "______________________________\n" );
	printf( " Enter Raw Data " );
	scanf ( "%c", &data );
	printf( "Data in Decimal = %uD\n",data ); //Show in Decimal format
	printf( "Data in Hexamal = %xH\n",data ); //Show in Hexamal format
	printf( "Charracter      = %c\n",data )	; //Show in Character format
	printf( "Data in Binary  = ");
	DecToBin(data,sizeof(data)); //Show in Binary format
	printf("Size            = %d Bytes\n ",sizeof(data)); //Show size of unsigned short integer
	getch(); //Wait for press any key	
	}//end void Character
void SFloat () // Test Data in Single Percision Float Mode
{
    float data; //Declare data variable for keep Single Precision float types

    printf("\nSingle Precision Float MODE (1.2E-38 to 3.4E+38)"); 
    printf("\n______________________________\n");
    printf("Enter Raw Data ");
    scanf("%f", &data);
    printf("Data in Decimal = %.2fD\n", data); //Show in Decimal format
    printf("Data in Hexamal = %xH\n", data); //Show in Haxamal format
    printf("Data in Binary  = "); 
    DecToBin (data, sizeof(data)); //Show in Binary format 
    printf("Size            = %d Bytes\n", sizeof(data)); //Show size of unsigned integer
    getch(); //Wait for press any key
}//Void SFloat
void Adouble(){

float data; //Declare data variable for keep Single Precision float types

    printf("\nDouble Precision daouble MODE (1.7E-308 to 1.7E+308)"); 
    printf("\n______________________________\n");
    printf("\nEnter Raw Data ");
    scanf("%lf", &data);
    printf("Data in Decimal = %.2fD\n", data); //Show in Decimal format
    printf("Data in Hexamal = %xH\n", data); //Show in Haxamal format
    printf("Data in Binary  = "); 
    DecToBin (data, sizeof(data)); //Show in Binary format 
    printf("Size            = %d Bytes\n", sizeof(data)); //Show size of unsigned integer
    getch(); //Wait for press any key
}
void  Blongdouble(){
long double data; //Declare data variable for keep Single Precision float types
printf("\nSingle Precision longdouble MODE (3.4E-4932 to 1.1E+4932)"); 
    printf("\n______________________________\n");
    printf("Enter Raw Data ");
    scanf("%Lf ", &data);
    printf("Data in Decimal = %.2Lf\n", data); //Show in Decimal format
    printf("Data in Hexamal = %xH\n", data); //Show in Haxamal format
    printf("Data in Binary  = "); 
    DecToBin (data, sizeof(data)); //Show in Binary format 
    printf("Size            = %d Bytes\n", sizeof(data)); //Show size of unsigned integer
    getch(); //Wait for press any keyt

}
int main(){
    printf("\nDATA REPRESENTATION PROGRAM..\n"); 
    printf("______________________________\n");
    while (ch !='0') {
        
        
        printf("(1) Unsign ShortInt\n(2) Boolean\n(3) Unsigned Int\n(4) Character\n");
        printf("(5) Single Prec Float\n(6) double\n(7) long double\n(0) Exit\n"); //Show MENU 
        printf("\n"); //Line Feed

       
       
       
        ch = getch(); //Wait and read KBD with out ENTER Pressed

        switch(ch) //Check ch
			{
        case '1'  : UnsignedShortInt();
                    break;
        case '2'  : Boolean();
                    break;
        case '3'  : UnsignedInt();
                    break;
        case '4'  : Character();
                    break;
        case '5'  : SFloat();
                    break;
        case '6'   :   Adouble();
                    break;
        case '7'   :   Blongdouble();
                    break;
        case '0':
                    break;
        default : printf("\nInvalid Input\n");
        }//End switch case
    }//End While Loop

printf("\n"); //line feed
return 0;
}//End main


