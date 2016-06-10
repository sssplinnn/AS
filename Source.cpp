#include <iostream>
#include <algorithm>
#include <vector>

template <class TIter>
TIter min_element(TIter b, TIter e)
{
	TIter result = b;
	while (b < end)
	{
		if (*b < *result)
			result = b;

		++b;
	}
	return result;
}

template <class TIter>
void sort_selection(TIter b, TIter e)
{
	for (TIter pivot = b; pivot < e; ++pivot)
	{
		assert(std::is_sorted(b, pivot));
		auto m = min_element(pivot, e);
		if (pivot != m)
			swap(*pivot, *m);
	}
}

template <class TIter>
void sort_selection_fun(TIter b, TIter e)
{

}

template <class TIter>
void buble_search(TIter b, TIter e)
{
	for (TIter i = b; i < e; ++i)
	{
		for (TIter j = e; j > b; --j)
		{
			//if (*j < *(j + 1))
				//std::cout << "1";
				//std::swap(j, (j + 1));
		}
	}
}

template <class TIter>
void sort_buble(TIter b, TIter e)
{
	for (TIter pivot = e; pivot != b; --pivot)
	{
		for (TIter i = b; i < pivot; ++i)
		{
			auto next_i = i + 1;
			if (*next_i < *i)
				std::cout << "1";
		}
	}
}

template <class TIter>
void print(TIter b, TIter e)
{
	/*
	while (b < e)
		std::cout << *b++ << " ";

	std::cout << std::endl;
	*/
}

void main()
{
	std::vector<int> a = { 5, 3, 8, 1 };
	sort_buble(a.begin(), a.end());
	print(a.begin(), a.end());
	system("pause");
}