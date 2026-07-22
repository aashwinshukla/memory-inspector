#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

/* ─── Constants ─────────────────────────────────────────────── */
#define MAX_ELEMENTS 100
#define BUFFER_SIZE  20

/* ─── Data types ─────────────────────────────────────────────── */
typedef struct {
    int arr[MAX_ELEMENTS];
    int count;
} InputData;

/* ─── Function prototypes ────────────────────────────────────── */

/**
 * Reads up to MAX_ELEMENTS integers from stdin.
 * The user types 'q' or 'Q' to stop early.
 * Non-numeric tokens are skipped with a warning.
 */
InputData getinput(void);

/**
 * Displays the main menu and returns the chosen option.
 * Keeps prompting until a valid integer is entered.
 */
int choice(void);

/**
 * Displays the navigation sub-menu and returns the chosen option.
 * Keeps prompting until a valid integer is entered.
 */
int choose1(void);

/**
 * Prints index, value, and memory address for res->arr[i].
 */
void print_element(const InputData *res, int i);

#endif /* UTILS_H */
