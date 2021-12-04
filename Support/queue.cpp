#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define N 5 //JarnTong

int queue[N];
int count = 0;

void insertIntoQueue(int x){
	if(count > N-1){
		printf("Stack Overflow\n");
		return ;
	}
    queue[count] = x;
    count++;
}

void deleteQueue(){
	if(count < 1) {
		printf("Stack Underflow\n");
		return ;
	}

	count--;
	int i ;
	for( i = 0 ; i < count ;i++){
		queue[i] = queue[i+1];
	}
		
}

void displayQueue(){
	
    int i ;
    for(i = 0 ; i < count ; i++){
        printf("%d " ,queue[i]);
    }
	printf("\n");	
}


int main(){
	char c;
	printf("(1)InsertNumber (2)DeleteNumber  (3) Display : ");
	scanf("%c",&c);
	
    while(c != 'x' && c != 'X'){
    	
    	switch(c){
    		
			case '1' : 
						int num;
						printf("Insert number: ");
						scanf("%d",&num);
						insertIntoQueue(num);
						break;
					
			case '2' :
						deleteQueue();
						break;
						
			case '3' :
						displayQueue();
						break;	
			
		}
	
		printf("\n(1) InsertNumber (2) DeleteNumber (3) Display (X) Exit : ");
		scanf("%c",&c);
	}
	
    return 0;
}
