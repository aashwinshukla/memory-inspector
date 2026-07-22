#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[100]; 
int count = 0;

int main() {
    char input[20];

    printf("--------Welcome to Memory Inspector--------\n");
    printf("\nEnter number elements into the storage: (type q to stop entering numbers)\n");
    
    for (int i = 0; i < 100; i++) {
        if (scanf("%19s", input) != 1) break;

        
        if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
            break;
        }

        
        arr[i] = atoi(input);
        count++;
    }

    printf("\n------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("\nElement %d is: %d", i + 1, arr[i]);
        printf("\nAddress of the element is: %p", (void*)&arr[i]);
    }

    return 0;
}

