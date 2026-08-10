#include <iostream>
#include <stack> // call =ing stack from STL


int main() {
    // creare an object for the stack
    std::stack<int> newStack;


    std::cout<<"Stack empty? " << newStack.empty()<<std::endl;
    //push to the stack
    /*15
      6
      3*/
    newStack.push(3);
    newStack.push(6);
    newStack.push(15);


    std::cout<<"Stack empty? " << newStack.empty()<<std::endl;
    std::cout << "The size of the stack: " << newStack.size() << std::endl;
    std::cout << "The top of the element is: " << newStack.top() << std::endl;
    std::cout << "Removing elements from the stack: \n";
    newStack.pop();


    std::cout << "The top of the element is: " << newStack.top() << std::endl;
    newStack.pop();


    std::cout << "The top of the element is: " << newStack.top() << std::endl;
    newStack.pop();
   
    std::cout<<"Stack empty? " << newStack.empty()<<std::endl;
    std::cout << "The size of the stack: " << newStack.size() << std::endl;

    return 0;
}

