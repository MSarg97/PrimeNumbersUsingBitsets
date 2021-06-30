#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>

using namespace std;

int main()
{
	const int size = 1024;
	bitset<size> primeBitset;
	primeBitset.flip();
	primeBitset.reset(0);
	primeBitset.reset(1);
	
	int value;
	int finalBit = sqrt(static_cast<double>(primeBitset.size())) + 1;


	//Determine all prime numbers from 2 to 1024 by performing Sieve of Eratosthenes

	for (int i = 2; i < finalBit; i++)
	{
		if (primeBitset.test(i))
		{
			for (int j = 2 * i; j < size; j += i)
			{
				primeBitset.reset(j);
			}
		}
	}


	//Display prime numbers in range 2 to 1023

	cout << "The prime numbers in range 2 to 1023 are\n\n";

	for (int i = 2, count = 1; i < size; i++)
	{
		if (primeBitset.test(i))
		{
			cout << setw(6) << i;

			if (count++ % 12 == 0)
				cout << '\n';
		}
	}

	cout << '\n';


	//Get value from user to determine whether the value is prime
	
	cout << "\nEnter value from 2 to 1023 (-1 to end): ";
	cin >> value;

	while (value != -1)
	{
		if (primeBitset[value])
			cout << value << " is prime!\n";
		else
			cout << value << " is not prime!\n";

		cout << "\nEnter value from 2 to 1023 (-1 to end): ";
		cin >> value;
	}

	return 0;
}