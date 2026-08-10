#include <iostream>
#include "Printer.h"
using namespace std;

int main() {
    Printer printer;

    // Task 4: Create different jobs
    Job job1(1, "Ryo", 8);
    Job job2(2, "Khaira", 6);
    Job job3(3, "Jabez", 7);
    Job job4(4, "Ivan", 9);

    // Add jobs to the printer
    printer.addJob(&job1);
    printer.addJob(&job2);
    printer.addJob(&job3);
    printer.addJob(&job4);

    // Process all jobs
    printer.processJobs();

    return 0;
}