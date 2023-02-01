#include <iostream>
using namespace std;

    int main(void) {
        int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
        int n = sizeof(vector) / sizeof(vector[0]);
        int* min = &vector[0];
        int* max = &vector[0];

        for (int* ptr = vector; ptr <= &vector[n - 1]; ptr++)
        {
            std::cout << "address=" << ptr << "\tvalue=" << *ptr << std::endl;
            *min > *ptr ? min = ptr : min = min;
            *max < *ptr ? max = ptr : max = max;
        }
        cout << *min << endl;
        cout << *max;
        return 0;
    }