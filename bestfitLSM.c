#include<stdio.h>

int main(void){
  int n;
  float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0;
  float x, y, mean_x, mean_y;
  float slope, intercept;

  //Ask the user for the number of data points
  printf("Enter the number of data points: ");
  scanf("%d", &n);

  //input loop to get the x and y values and calculate sums
  for(int i = 1; i<=n; i++){
    printf("Enter x%d: ", i);
    scanf("%f", &x);
    printf("Enter y%d: ", i);
    scanf("%f", &y);

    sum_x += x;
    sum_y += y;
    sum_xy += x*y;
    sum_x_squared += x*x;
  }

  //calculate the means of x and y
  mean_x = sum_x/n;
  mean_y = sum_y/n;

  // Calculate slope (m) and intercept (c) using least squares method
slope = (sum_xy - n*mean_x*mean_y)/(sum_x_squared - n*mean_x*mean_x);   
intercept = mean_y - slope * mean_x;

  //Print the linear equation
  printf("The linear equation that best fits the given data: \n");
  printf("y = %.2fx + %.2f\n", slope, intercept);

  return 0;
}
