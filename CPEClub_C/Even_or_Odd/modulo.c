#include <stdio.h>

void isInteger(int result, int *num);

int main()
{

  int num;
  printf("Enter a number: ");
  int result = scanf("%d",  &num);
  isInteger(result, &num);
  
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

void isInteger(int result, int *num)
{
  if (result != 1)
  {
    while (result != 1)
    {
      while (getchar() != '\n');
      printf("Enter only digits please!\n");
      printf("Enter a number: ");
      result = scanf(" %d", num);
    }
  }
}
