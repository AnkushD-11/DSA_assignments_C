/* Write a program to collect height & weight of 'N' students. Find the highest weight/ height
ratio.*/

#include <stdio.h>

#define max 100

struct record {
    double height;
    double weight;
};

double calculateRatio(const struct record *student) {
    // Avoid division by zero
    if (student->height == 0) {
        return 0;
    }
    return student->weight / student->height;
}

int main() {
    int numStudents;
    struct record students[max];

    printf("Enter the number of students (N): ");
    scanf("%d", &numStudents);

    if (numStudents <= 0 || numStudents > max) {
        printf("Invalid number of students. Please enter a number between 1 and %d.\n", max);
        return 1;
    }

    // Input data for each student
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter height (in cm): ");
        scanf("%lf", &students[i].height);
        printf("Enter weight (in kg): ");
        scanf("%lf", &students[i].weight);
    }

    // Find the student with the highest weight/height ratio
    int indexMaxRatio = 0;
    double maxRatio = calculateRatio(&students[0]);

    for (int i = 1; i < numStudents; i++) {
        double currentRatio = calculateRatio(&students[i]);
        if (currentRatio > maxRatio) {
            maxRatio = currentRatio;
            indexMaxRatio = i;
        }
    }

    // Output the student with the highest weight/height ratio
    printf("\nStudent with the highest weight/height ratio:\n");
    printf("Height: %.2lf cm\n", students[indexMaxRatio].height);
    printf("Weight: %.2lf kg\n", students[indexMaxRatio].weight);
    printf("Ratio: %.2lf kg/cm\n", maxRatio);

    return 0;
}
