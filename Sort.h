#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;

class Sort
{
public:

	template<typename T>
	static bool CheckIfArrayIsSorted(vector<T> vec)
	{
		if (vec.size() < 2) return true;

		for (int i = 0; i < vec.size() - 1; i++)
		{
			if (vec[i] > vec[i + 1]) return false;
		}

		return true;
	}

	template<typename T>
	static void Swap(T& first, T& second)
	{
		int temp = second;
		second = first;
		first = temp;
	}

	template<typename T>
	static void Output(vector<T> vec)
	{
		cout << endl;

		for (T i : vec) cout << i << ' ';

		cout << endl << endl;
	}

	template<typename T>
	static void ArrayCreation(vector<T>& vec, int size)
	{
		vector<T> temp;

		for (int i = 0; i < size; i++) temp.push_back((T)rand());

		vec = temp;
	}

	template<typename T>
	static void BubbleSort(vector<T>& vec)
	{
		if (CheckIfArrayIsSorted(vec)) return;

		for (int i = 1; i < vec.size(); i++)
		{
			for (int j = 0; j < vec.size() - i; j++)
			{
				if (vec[j] > vec[j + 1])
				{
					Sort::Swap(vec[j], vec[j + 1]);
				}
			}
		}
	}

	template<typename T>
	static void SelectionSort(vector<T>& vec)
	{
		if (CheckIfArrayIsSorted(vec)) return;

		for (int i = 0; i < vec.size() / 2; i++)
		{
			int imin = i, imax = i;

			for (int j = i; j <= vec.size() - i - 1; j++)
			{
				if (vec[j] > vec[imax]) imax = i;

				if (vec[j] < vec[imin]) imin = i;
			}

			Swap(vec[i], vec[imin]);
			Swap(vec[vec.size() - i - 1], vec[imax]);
		}
	}

	template<typename T>
	static void QuickSort(vector<T>& vec)
	{
		if (CheckIfArrayIsSorted(vec)) return;

		vector<int> lower, equal{ vec[0] }, larger;

		for (int i = 1; i < vec.size(); i++)
		{
			if (vec[i] > vec[0]) larger.push_back(vec[i]);
			else if (vec[i] < vec[0]) lower.push_back(vec[i]);
			else equal.push_back(vec[i]);
		}

		QuickSort(larger);

		QuickSort(lower);

		vector<int> result;

		for (int i : lower) result.push_back(i);
		for (int i : equal) result.push_back(i);
		for (int i : larger) result.push_back(i);

		vec = result;
	}

	static void CheckBubbleSortTime(int size)
	{
		vector<int> vec;
		Sort::ArrayCreation(vec, size);


		auto start = steady_clock::now();

		Sort::BubbleSort(vec);

		auto end = steady_clock::now();


		cout << "\nbubble sort time: " << duration_cast<milliseconds>(end - start).count() << " ms\n" << endl;
	}

	static void CheckSelectionSortTime(int size)
	{
		vector<int> vec;
		Sort::ArrayCreation(vec, size);


		auto start = steady_clock::now();

		Sort::SelectionSort(vec);

		auto end = steady_clock::now();


		cout << "\nselection sort time: " << duration_cast<milliseconds>(end - start).count() << " ms\n" << endl;
	}

	static void CheckQuickSortTime(int size)
	{
		vector<int> vec;
		Sort::ArrayCreation(vec, size);


		auto start = steady_clock::now();

		Sort::QuickSort(vec);

		auto end = steady_clock::now();


		cout << "\nquick sort time: " << duration_cast<milliseconds>(end - start).count() << " ms\n" << endl;
	}

};