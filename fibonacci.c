#inlcude<stdio.h>

int main(void)
{
  int n, f1 = 0, f2 = 1, nextTerm;
  printf("Enter the number of terms: \n");
  scanf("%d", &n);

  printf("The fibonacci series is: %d, %d,", f1, f2);

  for(int i=1; i<=n-2; i++){
    nextTerm = f1+f2;
    printf("%d,", nextTerm);
    f1 = f2;
    f2 = nextTerm;
  }

  printf("\n");
  return 0;
  
}
