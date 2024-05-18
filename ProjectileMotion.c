#include <stdio.h>
#include <math.h>  // Include math.h for M_PI constant
#include <stdlib.h>  // Include stdlib.h for system function

#define GRAVITY 9.81  // Acceleration due to gravity (m/s^2)

int main() {
    FILE *fp;
    float v0, angleDeg, angleRad, range, maxHeight, timeOfFlight;
    float timeStep = 0.1;  // Time step for trajectory calculation (s)

    // Open a file for writing data
    fp = fopen("projectile_data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Input initial velocity and launch angle
    printf("Enter initial velocity (m/s): ");
    scanf("%f", &v0);
    printf("Enter launch angle (degrees): ");
    scanf("%f", &angleDeg);

    // Convert launch angle from degrees to radians
    angleRad = angleDeg * M_PI / 180.0;

    // Calculate maximum range, height, and time of flight
    range = (v0 * v0 * sin(2 * angleRad)) / GRAVITY;
    maxHeight = (v0 * v0 * sin(angleRad) * sin(angleRad)) / (2 * GRAVITY);
    timeOfFlight = (2 * v0 * sin(angleRad)) / GRAVITY;

    // Write data to the file
    fprintf(fp, "Initial Velocity: %.2f m/s\n", v0);
    fprintf(fp, "Launch Angle: %.2f degrees\n", angleDeg);
    fprintf(fp, "Maximum Range: %.2f meters\n", range);
    fprintf(fp, "Maximum Height: %.2f meters\n", maxHeight);
    fprintf(fp, "Time of Flight: %.2f seconds\n\n", timeOfFlight);

    // Calculate and write trajectory points to the file
    fprintf(fp, "Time (s)\tHorizontal Distance (m)\tVertical Distance (m)\n");
    for (float t = 0; t <= timeOfFlight; t += timeStep) {
        float x = v0 * cos(angleRad) * t;
        float y = v0 * sin(angleRad) * t - 0.5 * GRAVITY * t * t;
        fprintf(fp, "%.2f\t%.2f\t\t\t%.2f\n", t, x, y);
    }

    // Close the file
    fclose(fp);

    // Plot trajectory using gnuplot
    fp = fopen("gnuplot_commands.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "set terminal png\n");  // Set output terminal to PNG format
    fprintf(fp, "set output 'trajectory_plot.png'\n");  // Set output filename
    fprintf(fp, "set title 'Projectile Motion Trajectory'\n");
    fprintf(fp, "set xlabel 'Horizontal Distance (m)'\n");
    fprintf(fp, "set ylabel 'Vertical Distance (m)'\n");
    fprintf(fp, "set xrange [0:%.2f]\n", range);  // Set x-axis range based on maximum range
    fprintf(fp, "set yrange [0:%.2f]\n", maxHeight + 1);  // Set y-axis range slightly above maximum height
    fprintf(fp, "plot 'projectile_data.txt' using 2:3 with lines title 'Trajectory'\n");

    fclose(fp);

    // Execute gnuplot commands
    system("gnuplot gnuplot_commands.txt");

    printf("Projectile data written to 'projectile_data.txt'.\n");
    printf("Trajectory plot generated as 'trajectory_plot.png'.\n");

    return 0;
}
