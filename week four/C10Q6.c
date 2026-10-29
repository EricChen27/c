#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int value)
{
    if (is_full()) {
        printf("Expression is too complex\n");
        exit(EXIT_FAILURE);
    }

    contents[top++] = value;
}

int pop(void)
{
    if (is_empty()) {
        printf("Not enough operands in expression\n");
        exit(EXIT_FAILURE);
    }

    return contents[--top];
}

int main(void)
{
    char ch;
    int operand1, operand2;

    printf("Enter an RPN expression: ");

    while (scanf(" %c", &ch) == 1) {

        if (ch >= '0' && ch <= '9') {
            push(ch - '0');
        }

        else {
            switch (ch) {

                case '+':
                    operand2 = pop();
                    operand1 = pop();
                    push(operand1 + operand2);
                    break;

                case '-':
                    operand2 = pop();
                    operand1 = pop();
                    push(operand1 - operand2);
                    break;

                case '*':
                    operand2 = pop();
                    operand1 = pop();
                    push(operand1 * operand2);
                    break;

                case '/':
                    operand2 = pop();
                    operand1 = pop();

                    if (operand2 == 0) {
                        printf("Division by zero\n");
                        return 1;
                    }

                    push(operand1 / operand2);
                    break;

                case '=':
                    printf("Value of expression: %d\n", pop());
                    make_empty();
                    printf("Enter an RPN expression: ");
                    break;

                default:
                    return 0;
            }
        }
    }

    return 0;
}
