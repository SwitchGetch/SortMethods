#include "Sort.h"

int main()
{
	srand(time(NULL));

	int size;

	cout << "size: ";
	cin >> size;

	Sort::CheckQuickSortTime(size);

	Sort::CheckSelectionSortTime(size);

	Sort::CheckBubbleSortTime(size);
}
