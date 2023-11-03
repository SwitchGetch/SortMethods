#include "Sort.h"

int main()
{
	srand(time(NULL));

	steady_clock::time_point start, end;

	vector<int> vec;
	int size;

	cout << "array size: ";
	cin >> size;


	start = steady_clock::now();

	Sort::ArrayCreation(vec, size);

	end = steady_clock::now();

	cout << "\ncreation time: " << Sort::Time(start, end) << endl;


	Sort::Output(vec);

	start = steady_clock::now();

	Sort::QuickSort(vec);

	end = steady_clock::now();

	Sort::Output(vec);


	cout << "\nquick sort time: " << Sort::Time(start, end) << endl;

	while (true);
}
