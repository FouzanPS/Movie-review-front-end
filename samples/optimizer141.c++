#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;
    char a[50][50]; // Array to hold up to 50 lines of intermediate code, each up to 50 characters long

    // Prompt the user for the number of intermediate code lines
    printf("Enter the number of intermediate codes: ");
    scanf("%d", &n);

    // Read each line of intermediate code from the user
    for (i = 0; i < n; i++)
    {
        printf("Enter the 3 address code %d: ", i + 1);
        scanf(" %[^\n]", a[i]); // Read a line of input including spaces
    }

    // Display the generated code
    printf("The generated code is: \n");

    // Process each line of intermediate code
    for (i = 0; i < n; i++)
    {
        char op, operand1, operand2, result;

        // Parse the intermediate code line into result, operand1, operator, and operand2
        sscanf(a[i], "%c=%c%c%c", &result, &operand1, &op, &operand2);

        // Generate assembly-like code based on the operator
        if (op == '+')
        {
            printf("Mov %c, R%d\n", operand1, i); // Move operand1 to register R<i>
            printf("Add %c, R%d\n", operand2, i); // Add operand2 to the value in register R<i>
        }
        else if (op == '-')
        {
            printf("Mov %c, R%d\n", operand1, i); // Move operand1 to register R<i>
            printf("Sub %c, R%d\n", operand2, i); // Subtract operand2 from the value in register R<i>
        }
        else if (op == '*')
        {
            printf("Mov %c, R%d\n", operand1, i); // Move operand1 to register R<i>
            printf("Mul %c, R%d\n", operand2, i); // Multiply the value in register R<i> by operand2
        }
        else if (op == '/')
        {
            printf("Mov %c, R%d\n", operand1, i); // Move operand1 to register R<i>
            printf("Div %c, R%d\n", operand2, i); // Divide the value in register R<i> by operand2
        }

        // Move the result from the register to the result variable
        printf("Mov R%d, %c\n", i, result);
    }
    // Wait for a key press before closing (specific to some compilers/environments)
    return 0;
}
