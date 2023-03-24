#include <iostream>
using namespace std;

bool isPrime(int);

int main() {
    int num;
    cout << "Enter a number ";
    cin >> num;
    if (isPrime(num))
    {
        cout << "Number is prime.";
    }
    else
    {
        cout << "Number isn't prime.";
    }
    return 0;
}
bool isPrime(int x)
{
    bool prime = true;
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0) prime = false;
    }
    return prime;
}