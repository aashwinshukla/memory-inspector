#include <stdio.h>

int arr[100]; 
int n;
int count = 0;

int main(){
    printf("--------Welcome to Memory Inspector--------\n");
    printf("\nEnter number elements into the storage: (type q to stop entering number)\n");
    
    for(int i=0;i<=100;i++){
        scanf("%d", &n);
            if(n == 'q' || n == 'Q'){
                count = i;
                break;
            }else{
                arr[i] = n;
            }
    }

    for(int i=0; i<=count; i++){
        printf("\nelemnet %d is: %d", i+1, arr[i] );
    }
    return 0;
}