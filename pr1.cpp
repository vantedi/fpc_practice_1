//Задание 5
#include <iostream>
#include <omp.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int k; //количество нитей
    int N; //количество чисел

    cout << "Введите количество нитей (k): ";
    cin >> k;

    cout << "Введите количество чисел (N): ";
    cin >> N;

    int sum = 0; //общая сумма

#pragma omp parallel num_threads(k) reduction(+:sum)
    {
        int id = omp_get_thread_num();
        int partial_sum = 0;

        for (int i = id + 1; i <= N; i += k) {
            partial_sum += i;
        }

        cout << "[" << id << "] : Sum = " << partial_sum << endl;
        sum += partial_sum;
    }

    cout << "Sum = " << sum << endl;

    return 0;
}