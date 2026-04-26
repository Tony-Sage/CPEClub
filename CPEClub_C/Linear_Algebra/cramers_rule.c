#include <stdio.h>

float findDeterminant (int a, int b, int c, int d);
float findXDeterminant (int b, int d, int e, int f);
float findYDeterminant (int a, int b, int e, int f);
void isInteger(int result, int *coefficient, char variable);

int main()
{
    int a, b, c, d, e, f;
    int coefficients[6];
    char variables[] = {'a', 'b', 'c', 'd', 'e', 'f'};

    printf("a, b, c, d, e, f are variables in your equation in the format below:\n ax + by = e \n cx + dy = f \n");

    for (int i = 0; i < 6; i++) {
        printf("Input %c: ", variables[i]);
        int result = scanf("%d", &coefficients[i]);
        isInteger(result, &coefficients[i], variables[i]); 
    }

    a = coefficients[0]; b = coefficients[1]; c = coefficients[2];
    d = coefficients[3]; e = coefficients[4]; f = coefficients[5];

    float determinant = findDeterminant(a, b, c, d);
    float xDeterminant = findXDeterminant(b, d, e, f);
       float yDeterminant = findYDeterminant(a, b, e, f);

    if (determinant == 0)
    {
        printf("equations have no unique solutions.\n");
    } // This was where the mistake was made
    else 
    {
        printf("x is: %f\n", xDeterminant / determinant);
        printf("y is: %f\n", yDeterminant / determinant);
    }

    return 0;
}

float findDeterminant (int a, int b, int c, int d)
{
  float determinant = (a * d) - (b * c);
  return determinant;
}

float findXDeterminant (int b, int d, int e, int f)
{
    float xDeterminant = (b * f) - (e * d);
    return xDeterminant;
}

float findYDeterminant (int a, int b, int e, int f)
{
    float yDeterminant = (a * f) - (e * b);
    return yDeterminant;
}

void isInteger(int result, int *coefficient, char variable)
{
  if (result != 1)
  {
    while (result != 1)
    {
      while (getchar() != '\n');
      printf("Enter only digits please!\n");
      printf("Input %c: ", variable);
      result = scanf(" %f", coefficient);
    }
  }
}
