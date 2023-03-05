#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int **array = new int*[3];
	int odd = 0, even = 0;
	for (int i = 0; i < 3; i++)
	{
		array[i] = new int [3];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			array[i][j] = rand() % 5 - 2;
			cout << setprecision(5) << array[i];

			if (array[i][j] % 2 == 0)
			{
				even++;
			}
			else {
				odd++;
			}
		}
		
		
	}

	cout << "\n";
	cout << "even = "<< even << "\n";
	cout << "odd =" << odd << "\n";

	for (int i = 0; i < 3; i++)
	{
		delete[] array[i];
	}
	
}