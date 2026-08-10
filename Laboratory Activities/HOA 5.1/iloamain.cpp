#include <iostream>
#include <queue>

void display(std::queue<char> r);

int main()
{

    std::queue<char> q;

    q.push('c');
    q.push('p');
    q.push('e');
    q.push('0');
    q.push('1');
    q.push('0');

    std::cout << "==============================\n";
    std::cout << "Queue Implementation\n";
    std::cout << "==============================\n\n";
    // Display the queue
    std::cout << "Display: ";
    display(q);
    std::cout << "==============================\n\n";

    // empty()
    if (q.empty())
        std::cout << "Queue is empty" << std::endl;
    else
        std::cout << "Queue is not empty" << std::endl;
    std::cout << "==============================\n\n";

    // size()
    std::cout << "Queue size is: " << q.size() << std::endl;
    std::cout << "==============================\n\n";
    // front
    std::cout << "Front Element: " << q.front() << std::endl;
    std::cout << "==============================\n\n";
    // back
    std::cout << "Back Element: " << q.back() << std::endl;
    std::cout << "==============================\n\n";
    // Display
    std::cout << "Queue contents:";
    display(q);
    std::cout << "==============================\n\n";
    // Push another element
    q.push('X');
    // Display the updated queue
    std::cout << "After pushing 'X':";
    display(q);
    std::cout << "==============================\n\n";

    std::cout << "Deleting all elements....\n";
    // deletion
    while (!q.empty())
    {
        display(q);
        q.pop();
    }

    std::cout << "Final Queue:" << std::endl;
    display(q);

    return 0;
}

void display(std::queue<char> r)
{
    // Create a copy of the queue
    std::queue<char> c = r;

    while (!c.empty())
    {
        std::cout << " " << c.front();
        c.pop();
    }

    std::cout << std::endl;
}