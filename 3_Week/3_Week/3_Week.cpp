#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	srand(time(0));
    float* array = new float[30];
	int neg = 0, pos = 0;
	for (int i = 0; i < 30; i++)
	{
		array[i] = (rand() % 5 ) - 2 ; 
		
		cout << array[i] << " ";

		if (array[i] >= 0)
		{
			pos++;
		}
		else {
			neg++;
		}
	}

    cout << "\n";
	cout << pos << "\n";
	cout << neg << "\n";
	delete[] array;
}