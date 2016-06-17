#include <algorithm>

template <class TIter>
void partition(TIter begin, TIter pivot, TIter end)
{
	//write correct partition sorts
	assert(begin <= pivot && pivot <= end);
	
	for (TIter i = pivot; i > begin; --i)
	{
		if (*i < *(i - 1))
		{
			std::swap(*i, *(i - 1));
			pivot = i - 1;
		}
	}
	
	/*
	// [b, p) U [p] U [p+1, e)
	// [<x) [x] [>=x)
	auto x = *pivot;

	while (true)
	{
		// [partitioned)			[unpartitioned)
		// [b, m) [m, bu)			[bu, e)

		// [b, m) [m] [m + 1, bu)	[bu] [bu + 1, e)

		if (*bu >= *m)
		{
			// [b, m)
		}
		
	}
	*/

	assert(*std::max_element(begin, pivot) <= *pivot);
	assert(*std::min_element(pivot, end) >= *pivot);
}

template <class TIter>
void quick_sort(TIter begin, TIter end)
{

}