#include <stdio.h>
#include <string.h>

void isFloat(int i, float *num, const char s[]);

int main()
{
    float num1; 
    float num2;
    char operand;

    printf("When prompted, input the two numbers you're working with and the operand\n");
    printf("Input first number: \n");
    int result1 = scanf(" %f", &num1);
    isFloat(result1, &num1,  "first");
 
    printf("Input second number: \n");
    int result2 = scanf(" %f", &num2);
    isFloat(result2, &num2, "second");

    printf("Input operand: \n");
    scanf(" %c", &operand);

    if (operand == '+')
    {
        printf("Your answer is: %f\n", num1 + num2);
    }  
    else if (operand == '-')
    {
        printf("Your answer is: %f\n", num1 - num2);
    }

    else if (operand == '/' || operand == '÷')
    {
        if (num2 == 0)
        {
            while (num2 == 0)
            {
                printf("Division by 0 is not possible. Enter a non zero denominator please!\n");
                printf("Enter a non zero denominator:  \n");
                int result3 = scanf("%f", &num2);
                isFloat(result3, &num2, "second");
        }
    }
        printf("Your answer is: %f\n", num1 / num2);
    }

    else if (operand == '×' || operand == '*')
    {
        printf("Your answer is: %f\n", num1 * num2);
    }

    else 
    {
        printf("Please enter strictly only these characters as operands: +, -, *, /, ÷ and ×");
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
            printf("Input %s number: \n", s);
            result = scanf(" %f", num);
        }
    }
}
