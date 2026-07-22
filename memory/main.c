#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

bool flag = true;
bool flag1 = true;
int option;
int option1;
int idx;
int value;
int idx1;

typedef struct {
    int arr[100];
    int count;
} InputData;

InputData getinput() {
    InputData result;
    result.count = 0;
    char buffer[20];

    for (int i = 0; i < 100; i++) {
        if (scanf("%19s", buffer) != 1)
            break;

        if (strcmp(buffer, "q") == 0 || strcmp(buffer, "Q") == 0) {
            break;
        }

        result.arr[i] = atoi(buffer);
        result.count++;
    }
    return result;
}

int choice();

int main() {
    printf("--------Welcome to Memory Inspector--------\n");
    printf("\nEnter number elements into the storage: (type q to stop entering numbers)\n");
    
    
    InputData res = getinput();

    printf("\n------------------------------------------\n");

    int i = 0;
    while(flag){
        flag = true;
        int c;
            choice();
                switch(option){

                    
                    
                    case 1:
                    printf("Current position: %d\n", i);
                    printf("Value of Current Position: %d\n", res.arr[i]);
                    printf("Address of Current Position: %p\n", (void*)&res.arr[i]);
                    printf("------------------------------------------------------\n\n");
                    
                    while(flag1){
                        flag1 = true;
                            choose1();
                                switch(option1){
                                    
                                    case 1:
                                    i++;
                                    printf("Current position: %d\n", i);
                                    printf("Value of Current Position: %d\n", res.arr[i]);
                                    printf("Address of Current Position: %p\n", (void*)&res.arr[i]);
                                    printf("------------------------------------------------------\n\n");

                                    case 2:
                                    i--;
                                    if(i<0){
                                        printf("You were on the very first index");
                                    }else if(i>res.count){
                                        printf("You were on the final element in the Storage");
                                    }else{
                                        printf("Current position: %d\n", i);
                                        printf("Value of Current Position: %d\n", res.arr[i]);
                                        printf("Address of Current Position: %p\n", (void*)&res.arr[i]);
                                        printf("------------------------------------------------------\n\n");
                                    }

                                    case 3:
                                    flag1 = false;
                                    return;

                                    default:
                                    printf("WRONG INPUT ! TRY AGAIN");
                                }
                         
                    }
                    
                    case 2:
                    printf("Enter the index you want to check\n");
                    scanf("%d", &idx);
                    if(idx<0 || idx > res.count){
                        printf("index can only be from 0 to %d", res.count);
                    }else{
                        printf("Current position: %d\n", idx);
                        printf("Value of Current Position: %d\n", res.arr[idx]);
                        printf("Address of Current Position: %p\n", (void*)&res.arr[idx]);
                        printf("------------------------------------------------------\n\n");
                    }
                    

                    case 3:
                    printf("Enter the index whos value you want to modify\n");
                    scanf("%d", &idx);
                    if(idx<0 || idx> res.count){
                        printf("index can only be from 0 to %d", res.count);
                    }else{
                        printf("Current position: %d\n", idx);
                        printf("Value of Current Position: %d\n", res.arr[idx]);
                        printf("Enter the new value :\n");
                        scanf("%d", &value);
                        res.arr[idx] = value;
                        printf("New modified value is : %d ", res.arr[idx]);
                    }
                    
                    case 4:
                    
                    printf("Enter the Index number of the first element:\n");
                    scanf("%d", &idx);
                    printf("Enter the Index number of the second element:\n");
                    scanf("%d", &idx1);

                    c = res.arr[idx];
                    res.arr[idx] = res.arr[idx1];
                    res.arr[idx1] = c;

                    printf("Value at %d index is : %d", idx, res.arr[idx]);
                    printf("Value at %d index is : %d", idx1, res.arr[idx1]);

                    case 5:
                    printf("\n----------------------------------------------\n");
                    printf("         thank you for using our tool         ");
                    printf("\n----------------------------------------------\n");
                    flag = false;

                    default:
                    printf("WRONG INPUT!! TRY AGAIN");
                }
            

    }
    
 

    return 0;
}

int choice(){
    printf("Below are the tool you can use :");
    printf("\n1. Current Position Info");
    printf("\n2. Jump to an Index");
    printf("\n3. Modify Value");
    printf("\n4. Swap with Another Index");
    printf("\n5. Exit");
    printf("\nPlease Enter the choice number :");
    scanf("%d", &option);
    printf("\n-----------------------------------\n");

    return option; 
}

int choose1(){
        printf("Enter what you want to do next:\n");
        printf("1. Next Index");
        printf("2. Previous Index");
        printf("3. Back");
        scanf("%d", &option1);

        return option1;
}