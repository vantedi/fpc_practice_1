//Задание 4
#include <iostream>
#include <omp.h>

int main() {
    int k;
    int rank;
    std::cout << "Enter the number of threads: ";
    std::cin >> k;

#pragma omp parallel num_threads(k) private(rank)
    {
#pragma omp critical
        {
            rank = omp_get_thread_num();
            std::cout << "I am " << rank << " thread" << std::endl;
        }
    }

    return 0;
}
