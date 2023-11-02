#include "Sort.h"

int main()
{
	srand(time(NULL));

	vector<int> vec;
	int size;

	cout << "size: ";
	cin >> size;

	Sort::ArrayCreation(vec, size);


	Sort::Output(vec);

	steady_clock::time_point start = steady_clock::now();

	Sort::QuickSort(vec);

	steady_clock::time_point end = steady_clock::now();

	Sort::Output(vec);


	cout << "quick sort time: " << Sort::Time(start, end);
}
