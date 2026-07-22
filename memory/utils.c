#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/* ─── Input collection ───────────────────────────────────────── */

InputData getinput(void) {
    InputData result;
    result.count = 0;
    char buffer[BUFFER_SIZE];

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (scanf("%19s", buffer) != 1) {
            /* EOF or read error — stop gracefully */
            break;
        }

        if (strcmp(buffer, "q") == 0 || strcmp(buffer, "Q") == 0) {
            break;
        }

        /* Check that every character is a digit (allow leading '-') */
        int start = (buffer[0] == '-') ? 1 : 0;
        bool valid = (buffer[start] != '\0'); /* at least one digit */
        for (int j = start; buffer[j] != '\0'; j++) {
            if (buffer[j] < '0' || buffer[j] > '9') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            printf("  [skip] \"%s\" is not a valid integer.\n", buffer);
            i--;   /* don't consume a slot */
            continue;
        }

        result.arr[i] = atoi(buffer);
        result.count++;
    }
    return result;
}

/* ─── Display helper ─────────────────────────────────────────── */

void print_element(const InputData *res, int i) {
    printf("  Index   : %d\n",   i);
    printf("  Value   : %d\n",   res->arr[i]);
    printf("  Address : %p\n",   (void *)&res->arr[i]);
    printf("------------------------------------------------------\n\n");
}

/* ─── Menu helpers ───────────────────────────────────────────── */

int choice(void) {
    int opt;
    printf("\n========== Memory Inspector Menu ==========\n");
    printf("  1. Current Position Info\n");
    printf("  2. Jump to an Index\n");
    printf("  3. Modify Value at Index\n");
    printf("  4. Swap Two Elements\n");
    printf("  5. Exit\n");
    printf("-------------------------------------------\n");
    printf("Enter choice: ");

    while (scanf("%d", &opt) != 1) {
        /* Clear the bad token so we don't spin forever */
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("  Invalid input. Enter a number (1-5): ");
    }
    printf("\n");
    return opt;
}

int choose1(void) {
    int opt;
    printf("  Navigate:\n");
    printf("    1. Next Index\n");
    printf("    2. Previous Index\n");
    printf("    3. Back to Main Menu\n");
    printf("  Enter choice: ");

    while (scanf("%d", &opt) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("  Invalid input. Enter 1, 2, or 3: ");
    }
    printf("\n");
    return opt;
}
