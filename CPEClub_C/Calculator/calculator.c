#include <stdio.h>
#include <string.h>

void isFloat(int i, float *num, const char s[]);
int solve(float *num1, float *num2, char operand);

int main()
{
  float num1; 
  float num2;
  char operand;

  printf("When prompted, input the two numbers you're working with and the operand\n");
  printf("Input first number: ");
  int result1 = scanf(" %f", &num1);
  isFloat(result1, &num1,  "first");
 
  printf("Input second number: ");
  int result2 = scanf(" %f", &num2);
  isFloat(result2, &num2, "second");

  printf("Input operand: ");
  scanf(" %c", &operand);

  if (operand == '+' || operand == '-' || operand == '/' || operand == '*')
  {
    solve(&num1, &num2, operand);
  }

  else 
  {
    while (operand != '+' && operand != '-' && operand != '*' && operand != '/' )
    {
     printf("Please enter strictly only these characters as operands: +, -, *, and / \n");
     printf("Enter operand: ");
     scanf(" %c", &operand);
     solve(&num1, &num2, operand);
    }
  }

  return 0;
}

void isFloat(int result, float *num, const char s[])
{
  if (result != 1)
  {
    while (result != 1)
    {
      while (getchar() != '\n');
      printf("Enter only digits please!\n");
      printf("Input %s number: ", s);
      result = scanf(" %f", num);
    }
  }
}

int solve(float *num1, float *num2, char operand)
{
  if (operand == '+')
  {
    printf("Your answer is: %f\n", *num1 + *num2);
  }  
  else if (operand == '-')
  {
    printf("Your answer is: %f\n", *num1 - *num2);
  }

  else if (operand == '/')
  {
    if (*num2 == 0)
    {
      while (*num2 == 0)
      {
        printf("Division by 0 is not possible. Enter a non zero denominator please!\n");
        printf("Enter a non zero denominator: ");
        int result3 = scanf("%f", num2);
        isFloat(result3, num2, "second");
      }
    }
        
    printf("Your answer is: %f\n", *num1 / *num2);
  }

  else
  {
    printf("Your answer is: %f\n", *num1 * *num2);
  }
}
