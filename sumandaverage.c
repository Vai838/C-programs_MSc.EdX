#include <stdio.h>

int main() {
    FILE *file1, *file2;
    int n, i;
    float data, sum = 0, avg;

    // Open file1 for reading
    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        printf("Error opening file1.txt!\n");
        return 1; // Exit program with error status
    }

    // Open file2 for writing
    file2 = fopen("file2.txt", "w");
    if (file2 == NULL) {
        printf("Error opening file2.txt!\n");
        fclose(file1); // Close file1 if file2 opening fails
        return 1; // Exit program with error status
    }

    // Read total number of data points from user
    printf("Enter the total number of data points: ");
    scanf("%d", &n);

    // Read data from file1, calculate sum
    for (i = 1; i <= n; i++) {
        fscanf(file1, "%f", &data);
        sum += data;
    }

    // Calculate average
    avg = sum / n;

    // Write sum and average to file2
    fprintf(file2, "Sum = %.2f\nAverage = %.2f\n", sum, avg);

    // Close both files
    fclose(file1);
    fclose(file2);

    printf("Sum and average calculated and written to file2.txt.\n");

    return 0; // Exit program with success status
}
