#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define N 5 //JarnTong
#define E 5 //Inverse

/*Left To Right*/
int Q[ N ] ;
int x, Qnumber = 0, F = 0, R = 0 ;
char status = 'N' ;

char ch ;

/*Right To Left*/
int Qz[ E ] ;
int a, Qnumberz = 0, Fa = E, Ra = E ;
char statusz = 'N' ;

/*Left To Right*/
void insertCQ( int y ) {
	if( ( R == F - 1 ) || ( R == N - 1 ) && ( F == 1 ) ) {
		printf( "!!!OVER FLOW!!!\n" ) ;
		status = '0' ;
	}//end if
	else {
		if( R == N - 1 ) {
			R = 1 ;
		}//end if
		else{
			R++ ;
			if( F == 0 ) {
				F = 1 ;
			}//end if
		Qnumber++ ;
		printf( "Your Are queue number : %d\n", Qnumber ) ;
		Q[ R ] = y ;
		status = 'N' ;
		}//end else
	}//end else
}//end insertCQ

int deleteCQ() {
	int y ;
	if( F == 0 ) {
		printf( "\n!!!UNDER FLOW!!!\n" ) ;
		status = 'U' ;
	}//end if
	else {
		y = Q[ F ] ;
		if( F == R ) {
			F = 0 ; R = 0 ;
		}//end if
		else {
			if( F == N - 1 ) {
				F = 1 ;
			}//end if
			else {
				F++ ;
			}//end else
		}//end else
	status = 'N' ;
	return y ;
	}//end else
}//end deleteCQ

int DataInQueue() {
	int y = 0 ;
	if( F != 0 && R != 0 ) {
		if( F <= R )
			y = R - F + 1 ;
		else
			y = ( N - 1 ) - F + 1  + R ;
	}//end if
return y ; 
}//end DataInQueue

void ShowAllQueue() {
	int i ;
	printf( "N                     : %d\n", N - 1 ) ;
	printf( "Status                : %c\n", status ) ;
	printf( "Data waiting in queue : %d\n", DataInQueue() ) ;
	printf( "     F : %d  /  R : %d\n", F, R ) ;
	for( i = 1 ; i < N ; i++ ) {
		printf( "%d:%d  ", i, Q[ i ] ) ;
	}//end for
	printf( "\n____________________________\n" ) ;
}//end void ShowAllQueue

/*Right To Left*/
void insertCQz( int v ) {
	if( ( Ra == Fa + 1 ) || ( Ra == 1 ) && ( Fa == E - 1 ) ) {     //
		printf( "!!!OVER FLOW!!!\n" ) ;
		statusz = 'O' ;
	}//end if
	else {
		if( Ra == 1 ) {
			Ra = E - 1 ;
		}//end if
		else{
			Ra-- ;
			if( Fa == E ) {
				Fa = E - 1 ;
			}//end if
		Qnumberz++ ;
		printf( "Your Are queue number : %d\n", Qnumberz ) ;
		Qz[ Ra ] = v ;
		statusz = 'N' ;
		}//end else
	}//end else
}//end insertCQ

int deleteCQz() {
	int v ;
	if( Fa == E ) {
		printf( "\n!!!UNDER FLOW!!!\n" ) ;
		statusz = 'U' ;
	}//end if
	else {
		v = Qz[ Fa ] ;
		if( Fa == Ra ) {
			Fa = E ; Ra = E ;
		}//end if
		else {
			if( Fa == 1 ) {
				Fa = E - 1 ;
			}//end if
			else {
				Fa-- ;
			}//end else
		}//end else
	statusz = 'N' ;
	return v ;
	}//end else
}//end deleteCQ

int DataInQueuez() {
	int v = 0 ;
	if( Fa != E && Ra != E ) {
		if( Fa >= Ra )
			v = Fa - Ra + 1 ;
		else
			v = ( E - 1 ) - Ra + 1  + Fa ;
	}//end if
return v ; 
}//end DataInQueue

void ShowAllQueuez() {
	int j ;
	printf( "N                     : %d\n", E - 1 ) ;
	printf( "Status                : %c\n", statusz ) ;
	printf( "Data waiting in queue : %d\n", DataInQueuez() ) ;
	printf( "     F : %d  /  R : %d\n", Fa, Ra ) ;
	for( j = 1 ; j < E ; j++ ) {
		printf( "%d:%d  ", j, Qz[ j ] ) ;
	}//end for
	
	printf( "\n____________________________\n" ) ;
}//end void ShowAllQueue

/*Main*/
int main() {
	printf( "CIRCULAR QUEUE PROGRAME...\n" ) ;
	printf( "__________________________\n" ) ;
	ch = ' ' ;
	
	while( ch != 'E' ) {
		printf( "\n[1]  INSERT               [2]  DELETE" ) ;
		printf( "\n[3]  INSERT(Inverse)      [4]  DELETE(Inverse)" ) ;
		printf( "\n[5]  CLEARSCREEN  " ) ;
		ch = getch() ;
		switch( ch ) {
			case '1'	:	printf( "\nInsert Number : " ) ;
							scanf( "%d", &x ) ;
							insertCQ( x ) ;
							ShowAllQueue() ;
							break ;
							
			case '2'	:	x = deleteCQ() ;
							printf( "\nData from Queue : %d\n", x ) ;
							ShowAllQueue() ;
							break ;		
							
			case '3'	:	printf( "\nInsert Number : " ) ;
							scanf( "%d", &a ) ;
							insertCQz( a ) ;
							ShowAllQueuez() ;
							break ;
							
			case '4'	:	x = deleteCQz() ;
							printf( "\nData from Queue : %d\n", a ) ;
							ShowAllQueuez() ;
							break ;										
							
			case '5' 	: 	system( "cls" ) ;
							printf( "CIRCULAR QUEUE PROGRAME...\n" ) ;
							printf( "__________________________\n" ) ;
							break ;		
		}//end case
	}//end while 
	printf( "\n" ) ;
	return 0 ;
}//end main
