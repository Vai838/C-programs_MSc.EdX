#include<stdio.h>

int main(void)
{
int a[10][10], b[10][10],c[10][10], m, n, i, j;
printf("Enter the order of the matrix\n");
scanf("%d%d", &m, &n);
printf("Enter the elements of the first matrix\n");
for(i=1; i<=m; i++)
for(j=1; j<=n; j++)
scanf("%d", &a[i][j]);
printf("Enter the elements of the second matrix\n");
for(i=1; i<=m; i++)
for(j=1; j<=n; j++)
scanf("%d", &b[i][j]);
printf("******************************\n");
printf("The first matrix is\n");
for (i=1;i<=m; i++)
{
for (j=1;j<=n; j++)
printf("%d\t", a[i][j]);
printf("\n");
printf("\n");
printf("The second matrix is\n");
for (i=1;i<=m; i++)
{
for (j=1;j<=n;j++)
printf("%d\t", b[i][j]);
printf("\n");
}
printf("   \n");
for(i=1; i<=m; i++)
for (j=1; j<=n; j++)
c[i][j] = a[i][j] + b[i][j];
printf("The resultant matrix is\n");
for (i=1; i<=m; i++)
{
for(j=1;j<=n; j++)
printf("%d \t",c[i][j]);
printf("\n");
}
printf("***********************\n");

}
return 0;
}
