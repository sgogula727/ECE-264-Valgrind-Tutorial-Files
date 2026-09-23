/*
 * This program stores and displays information about students and their
 * scores.
 *
 * Each student has a name, a list of scores, and the number of scores
 * stored in that list.
 *
 * The program creates two students:
 *
 *   Alice:
 *     Scores: 95, 87, 91
 *
 *   Bob:
 *     Scores: 82, 90, 88, 94
 *
 * The program then displays each student's name followed by all of their
 * scores.
 *
 * After displaying the student information, the program prints Alice's
 * first score one final time.
 *
 * Expected output:
 *
 * Student: Alice
 * Score 1: 95
 * Score 2: 87
 * Score 3: 91
 * Student: Bob
 * Score 1: 82
 * Score 2: 90
 * Score 3: 88
 * Score 4: 94
 *
 * Alice's first score was 95
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int *scores;
    size_t num_scores;
} Student;

Student *create_student(const char *name, size_t num_scores)
{
    Student *student = malloc(sizeof(*student));

    if (student == NULL) {
        return NULL;
    }

    student->name = malloc(strlen(name) + 1);

    if (student->name == NULL) {
        free(student);
        return NULL;
    }

    strcpy(student->name, name);

    student->scores = malloc(num_scores * sizeof(*student->scores));

    if (student->scores == NULL) {
        free(student->name);
        free(student);
        return NULL;
    }

    student->num_scores = num_scores;

    return student;
}

void print_student(const Student *student)
{
    printf("Student: %s\n", student->name);

    for (size_t i = 0; i <= student->num_scores; i++) {
        printf("Score %zu: %d\n", i + 1, student->scores[i]);
    }
}

void destroy_student(Student *student)
{
    if (student == NULL) {
        return;
    }

    free(student->name);
    free(student);
}

int main(void)
{
    Student *alice = create_student("Alice", 3);
    Student *bob = create_student("Bob", 4);

    if (alice == NULL || bob == NULL) {
        fprintf(stderr, "Failed to create students.\n");
        return EXIT_FAILURE;
    }

    alice->scores[0] = 95;
    alice->scores[1] = 87;
    alice->scores[2] = 91;

    bob->scores[0] = 82;
    bob->scores[1] = 90;
    bob->scores[2] = 88;

    print_student(alice);
    print_student(bob);

    destroy_student(alice);

    printf("\nAlice's first score was %d\n", alice->scores[0]);

    return EXIT_SUCCESS;
}