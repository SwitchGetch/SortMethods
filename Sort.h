#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;

class Sort
{
public:

	static string Time(steady_clock::time_point start, steady_clock::time_point end)
	{
		string result = "";


		int h = duration_cast<hours>(end - start).count();
		int m = duration_cast<minutes>(end - start).count();
		int s = duration_cast<seconds>(end - start).count();
		int ms = duration_cast<milliseconds>(end - start).count();


		int min = m - h * 60;
		int sec = s - m * 60;
		int milsec = ms - s * 1000;

		result += to_string(h) + ":";

		if (to_string(min).size() == 2) result += to_string(min) + ":";
		else result += "0" + to_string(min) + ":";

		if (to_string(sec).size() == 2) result += to_string(sec) + ":";
		else result += "0" + to_string(sec) + ":";

		if (to_string(milsec).size() == 3) result += to_string(milsec);
		else if (to_string(milsec).size() == 2) result += "0" + to_string(milsec);
		else result += "00" + to_string(milsec);


		return result;
	}

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
		if (Sort::CheckIfArrayIsSorted(vec)) return;

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
		if (Sort::CheckIfArrayIsSorted(vec)) return;

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
		if (Sort::CheckIfArrayIsSorted(vec)) return;

		vector<int> lower, equal{ vec[0] }, larger;

		for (int i = 1; i < vec.size(); i++)
		{
			if (vec[i] > vec[0]) larger.push_back(vec[i]);
			else if (vec[i] < vec[0]) lower.push_back(vec[i]);
			else equal.push_back(vec[i]);
		}

		vec.clear();

		QuickSort(larger);

		QuickSort(lower);

		for (int i : lower) vec.push_back(i);
		lower.clear();

		for (int i : equal) vec.push_back(i);
		equal.clear();

		for (int i : larger) vec.push_back(i);
		larger.clear();
	}

	template<typename T>
	static void MergeSort(vector<T>& vec)
	{
		if (Sort::CheckIfArrayIsSorted(vec)) return;
		else if (vec.size() == 2) Sort::Swap(vec[0], vec[1]);
		else
		{
			vector<T> temp1, temp2;

			for (int i = 0; i < vec.size() / 2; i++) temp1.push_back(vec[i]);

			for (int i = vec.size() / 2; i < vec.size(); i++) temp2.push_back(vec[i]);

			vec.clear();

			MergeSort(temp1);
			MergeSort(temp2);

			while (temp1.size() > 0 && temp2.size() > 0)
			{
				if (temp1[0] > temp2[0])
				{
					vec.push_back(temp2[0]);

					temp2.erase(temp2.begin());
				}
				else if (temp1[0] < temp2[0])
				{
					vec.push_back(temp1[0]);

					temp1.erase(temp1.begin());
				}
				else
				{
					vec.push_back(temp1[0]);

					temp1.erase(temp1.begin());

					vec.push_back(temp2[0]);

					temp2.erase(temp2.begin());
				}
			}

			for (int i = 0; i < temp1.size(); i++) vec.push_back(temp1[i]);
			for (int i = 0; i < temp2.size(); i++) vec.push_back(temp2[i]);
		}
	}

};
