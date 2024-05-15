#include<stdio.h>

int main(void){
  int num;

  //input the number to check
  printf("Enter a number: ");
  scanf("%d", &num);

  //Check if the number is odd or even
  if( num % 2 == 0){
    printf("%d is an even number.\n", num);
  } else {
    printf("%d is an odd number.\n", num);
  }
  return 0;
}
