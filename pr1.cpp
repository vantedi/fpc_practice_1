//������� 5
#include <iostream>
#include <omp.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int k; //���������� �����
    int N; //���������� �����

    cout << "������� ���������� ����� (k): ";
    cin >> k;

    cout << "������� ���������� ����� (N): ";
    cin >> N;

    int sum = 0; //����� �����

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