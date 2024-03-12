//Задание 1
#include <iostream>
#include <omp.h>

int main() {
    omp_set_num_threads(4);
#pragma omp parallel for
    for (int i = 0; i < 4; i++) {
        std::cout << "Hello world!" << std::endl;
    }
    return 0;
}
