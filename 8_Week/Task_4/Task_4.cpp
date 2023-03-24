#include <iostream> 
using namespace std;

int Sum(int i, int A[], int n);

int main(void) {

    int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10 };
    cout << Sum(0, A, 10);

    return 0;
}
int Sum(int i, int A[], int n)
{
    if (i == n - 1)
        return A[i];
    else
        return A[i] + Sum(i + 1, A, n);
}