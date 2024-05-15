#include<stdio.h>

int main(void){
  int largest, smallest, n, num;
  //Ask the user the number of elements
  printf("Enter the number of elements: \n");
  scanf("%d", &n);

  //Ask for the first number as input
  printf("Enter number 1: ");
  scanf("%d", &num);

  //Assume the first number is both largest and smallest for now
  largest = smallest = num;

  //Loop through the remaining number
  for(int i = 2; i<=n; i++){
    printf("Enter number %d: ", i);
    scanf("%d", &num);

    //update largest if the current number is greater
    if(num > largest){
      largest = num;
    }

    //update smallest if the current number is smaller
    if(num < smallest){
      smallest = num;
    }
  }

  //print the largest and smallest numbers
  printf("The largest number is: %d\n", largest);
  printf("The smallest number is: %d\n", smallest);

  return 0;  
}
