#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(void) {
    printf("╔══════════════════════════════════════════╗\n");
    printf("║       Welcome to Memory Inspector        ║\n");
    printf("╚══════════════════════════════════════════╝\n\n");

    printf("Enter integers into storage (type 'q' to stop):\n");
    InputData res = getinput();

    if (res.count == 0) {
        printf("No elements entered. Exiting.\n");
        return 0;
    }

    printf("\n%d element(s) stored successfully.\n", res.count);
    printf("----------------------------------------------\n");

    int i = 0;          /* current cursor position */
    bool running = true;

    while (running) {
        int opt = choice();

        switch (opt) {

            /* ── 1. Navigate from current position ── */
            case 1: {
                print_element(&res, i);
                bool navigating = true;

                while (navigating) {
                    int nav = choose1();

                    switch (nav) {
                        case 1:   /* Next */
                            if (i + 1 >= res.count) {
                                printf("  Already at the last element (index %d).\n\n", i);
                            } else {
                                i++;
                                print_element(&res, i);
                            }
                            break;

                        case 2:   /* Previous */
                            if (i - 1 < 0) {
                                printf("  Already at the first element (index 0).\n\n");
                            } else {
                                i--;
                                print_element(&res, i);
                            }
                            break;

                        case 3:   /* Back */
                            navigating = false;
                            break;

                        default:
                            printf("  Invalid choice. Enter 1, 2, or 3.\n");
                            break;
                    }
                }
                break;
            }

            /* ── 2. Jump to a specific index ── */
            case 2: {
                int idx;
                printf("Enter the index to jump to (0 - %d): ", res.count - 1);
                if (scanf("%d", &idx) != 1) {
                    /* flush bad token */
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    printf("  Invalid input.\n");
                    break;
                }

                if (idx < 0 || idx >= res.count) {
                    printf("  Index out of range. Valid range: 0 to %d.\n", res.count - 1);
                } else {
                    i = idx;   /* update cursor so navigation stays in sync */
                    print_element(&res, i);
                }
                break;
            }

            /* ── 3. Modify value at an index ── */
            case 3: {
                int idx;
                printf("Enter the index to modify (0 - %d): ", res.count - 1);
                if (scanf("%d", &idx) != 1) {
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    printf("  Invalid input.\n");
                    break;
                }

                if (idx < 0 || idx >= res.count) {
                    printf("  Index out of range. Valid range: 0 to %d.\n", res.count - 1);
                    break;
                }

                printf("  Current value at index %d: %d\n", idx, res.arr[idx]);
                printf("  Enter new value: ");
                int val;
                if (scanf("%d", &val) != 1) {
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    printf("  Invalid input. Value not changed.\n");
                    break;
                }

                res.arr[idx] = val;
                printf("  Updated — index %d is now: %d\n\n", idx, res.arr[idx]);
                break;
            }

            /* ── 4. Swap two elements ── */
            case 4: {
                int idx_a, idx_b;
                printf("Enter index of first element  (0 - %d): ", res.count - 1);
                if (scanf("%d", &idx_a) != 1) {
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    printf("  Invalid input.\n");
                    break;
                }

                printf("Enter index of second element (0 - %d): ", res.count - 1);
                if (scanf("%d", &idx_b) != 1) {
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    printf("  Invalid input.\n");
                    break;
                }

                if (idx_a < 0 || idx_a >= res.count ||
                    idx_b < 0 || idx_b >= res.count) {
                    printf("  One or both indices out of range. Valid range: 0 to %d.\n",
                           res.count - 1);
                    break;
                }

                if (idx_a == idx_b) {
                    printf("  Both indices are the same — nothing to swap.\n");
                    break;
                }

                int tmp        = res.arr[idx_a];
                res.arr[idx_a] = res.arr[idx_b];
                res.arr[idx_b] = tmp;

                printf("  Swap done:\n");
                printf("    Index %d → value: %d\n", idx_a, res.arr[idx_a]);
                printf("    Index %d → value: %d\n\n", idx_b, res.arr[idx_b]);
                break;
            }

            /* ── 5. Exit ── */
            case 5:
                printf("\n╔══════════════════════════════════════════╗\n");
                printf("║     Thank you for using Memory Inspector  ║\n");
                printf("╚══════════════════════════════════════════╝\n");
                running = false;
                break;

            default:
                printf("  Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    }

    return 0;
}
