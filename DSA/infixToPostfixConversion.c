// WAP to convert Infix to Postfix Conversion
#include <stdio.h>
#define MAXSIZE 40
char infix[MAXSIZE];
char postfix[MAXSIZE];
char stack[MAXSIZE];
int top;
void push(char);
char pop();
void display_array(char arr[MAXSIZE], int);

int main()
{
    int i, j = 0;
    char str[MAXSIZE];
    top = -1;

    printf("Enter the expression : ");
    gets(str); // string input

    for (i = 0; str[i] != '\0'; i++)
    {
        infix[i] = str[i]; // store all the element into infix array
    }
    

    // Operation
    for (i = 0; i<sizeof(infix)/sizeof(infix[0]); i++)
    {

        // Step - 1(a)
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix[j] = infix[i];
            j++;
        }

        // Step - 1(b)
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^' || infix[i] == '(' || infix[i] == ')')
        {
            if(top == -1 || infix[i]=='(')
                push(infix[i]); // push element on the stack
            
            else{
                if(infix[i] == '+' || infix[i] == '-'){
                    if(stack[top]!='('){
                        postfix[j] = pop();
                        j++;
                        push(infix[i]);
                    }
                    else{
                        push(infix[i]);
                    }
                }
                else if(infix[i] == '*' || infix[i] == '/'){
                    if(stack[top]=='^' || stack[top]=='/' || stack[top]=='*'){
                        postfix[j] = pop();
                        j++;
                        push(infix[i]);
                    }
                    else{
                        push(infix[i]);
                    }
                }
                else if(infix[i]=='^'){
                    if(stack[top] == '^'){
                        postfix[j] = pop();
                        j++;
                        push(infix[i]);
                    }
                    else{
                        push(infix[i]);
                    }
                }
            }
            if (infix[i] == ')'){  // Step - 1(c)
                postfix[j] = pop();
                j++;
                pop();
            }
        }
    }
    for (i = top; i >= 0; i--)
    {
        postfix[j] = stack[i];
        j++;
        top--;
    }

    display_array(postfix, j);

    return 0;
}

// to add element
void push(char ch)
{
    if (top == MAXSIZE - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

// to remove element
char pop()
{
    char p;
    if (top == -1)
    {
        return 0;
    }
    else
    {
        p = stack[top];
        top--;
    }
    return p;
}

// to display to array
void display_array(char *arr, int n)
{
    int i;
    printf("\nPostfix : \n");
    for (i = 0; i < n; i++)
    {
        printf("%c ", arr[i]);
    }
}