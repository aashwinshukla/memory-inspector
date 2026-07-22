#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

int main() {
    printf("--------Welcome to Memory Inspector--------\n");
    printf("\nEnter number elements into the storage: (type q to stop entering numbers)\n");
    
    
    InputData res = getinput();

    printf("\n------------------------------------------\n");



    
    // for (int i = 0; i < res.count; i++) {
    //     printf("\nElement %d is: %d", i + 1, res.arr[i]);
    //     printf("\nAddress of the element is: %p", (void*)&res.arr[i]);
    // }

    return 0;
}

