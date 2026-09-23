// INSTRUCTOR NOTE: Remove ALL comments regarding bugs before starting tutorial and giving students access to repository!

/*
 * This program creates a list of five numbers containing the values
 * 10, 20, 30, 40, and 50.
 *
 * The program prints each number in the list and then prints the first
 * number in the list separately.
 *
 * The program also creates a list of ten scores and stores a score of
 * 100 as the first value.
 *
 * Expected output:
 * 10 20 30 40 50
 * First number: 10
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const int size = 5;

    int *numbers = malloc(size * sizeof(*numbers));

    if (numbers == NULL) {
        fprintf(stderr, "malloc failed\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < size - 1; i++) {
        numbers[i] = (i + 1) * 10;
    }

    for (int i = 0; i <= size; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    free(numbers);

    printf("First number: %d\n", numbers[0]);

    int *scores = malloc(10 * sizeof(*scores));

    if (scores == NULL) {
        fprintf(stderr, "malloc failed\n");
        return EXIT_FAILURE;
    }

    scores[0] = 100;

    return EXIT_SUCCESS;
}