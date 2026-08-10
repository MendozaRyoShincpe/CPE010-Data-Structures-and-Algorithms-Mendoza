#include <iostream>

using namespace std;

// Maximum capacity of the stack
const size_t maxCap = 100;

// Stack array
int stack[maxCap];
int top = -1;

// Variables
int i; // User-defined stack size
int choice;
int newData;

// Function prototypes
void push();
void Top();
void pop();
bool isEmpty();
bool isFull();
void display();


int main()
{
    cout << "Enter the number of max elements for the new Stack: ";
    cin >> i;

    // Prevent invalid size
    if (i > maxCap || i <= 0)
    {
        cout << "Invalid stack size!" << endl;
        return 0;
    }

    while (true)
    {
        cout << "\n===== Stack Operation =====" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. TOP" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            Top();
            break;

        case 4:
            if (isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;

        case 5:
            display();
            break;

        case 6:
            main();

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

// Check if stack is empty
bool isEmpty()
{
    return (top == -1);
}

// Check if stack is full
bool isFull()
{
    return (top == i - 1);
}

// Push operation
void push()
{
    if (isFull())
    {
        cout << "Stack Overflow!" << endl;
        return;
    }
    
    cout << "New value to add into the stack: ";
    cin >> newData;

    stack[++top] = newData;
}

// Display top element
void Top()
{
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
        return;
    }

    cout << "The element on the top of the stack is: " << stack[top] << endl;
}

// Pop operation
void pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
        return;
    }

    cout << "Popping: " << stack[top] << endl;
    top--;
}

void display()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty." << endl;
        return;
    }

    std::cout << "Stack contents: " << std::endl;

    for (int j = top; j >= 0; j--)
    {
        std::cout << "|" << stack[j] << "|" << "\n";
    }
}