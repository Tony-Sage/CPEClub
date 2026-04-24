#include <stdio.h>

int main()
{

  int num;
  printf("Enter a number\n");
  scanf("%d",  &num);
  
  if ((num % 2) == 0)
  {
    printf("The number is an even number. \n");
  }
  else 
  {
    printf("The number is an odd number.\n");
  }

  return 0;

}
