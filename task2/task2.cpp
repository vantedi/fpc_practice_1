//Задание 2
#include <iostream>
#include <omp.h>

int main() {
    int k;
    std::cout << "Enter the number of threads: ";
    std::cin >> k;
#pragma omp parallel for
    for (int i = 0; i < k; i++) {
        std::cout << "I am " << i << " thread from " << k << " threads!"
            << std::endl;
    }
    return 0;
}
