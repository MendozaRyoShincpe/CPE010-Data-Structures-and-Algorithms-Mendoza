#include <iostream>
#include "printer.h"

int main()
{
    Printer printer(10); // storing 10 jobs

    Job job1(101, "Ryo", 8);
    Job job2(102, "Khaira", 10);
    Job job3(103, "Jabez", 6);
    Job job4(104, "Ivan", 7);
    Job job5(105, "Xyle", 9);

    std::cout << "===== SHARED PRINTER SIMULATION =====" << std::endl;

    std::cout << std::endl;
    std::cout << "Adding jobs..." << std::endl;

    printer.AddJob(job1);
    printer.AddJob(job2);
    printer.AddJob(job3);
    printer.AddJob(job4);
    printer.AddJob(job5);

    std::cout << std::endl;
    std::cout << "===== PROCESSING JOBS =====" << std::endl;

    printer.ProcessAll();

    std::cout << std::endl;
    std::cout << "===== ALL JOBS COMPLETED =====" << std::endl;

    return 0;
}