#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

const int search_2(int array[], const int size, const int key)
{
	int i = 0;
	array[size] = key;

	while (array[i] != key)
	{
		++i;
	}

	if (i == size)
	{
		return -1;
	}
	else
	{
		return i;
	}
}

const int search_1(const int array[], const int size, const int key)
{
	int elementIndex = -1;

	for (int i = 0; i < size; ++i)
	{
		if (array[i] == key)
		{
			elementIndex = i;
		}
	}

	return elementIndex;
}

void test_search(int array[], const int size, const int key, const int index)
{
	int result = search_1(array, size, key);

	std::cout << ((result == index) ? "OK" : "FAIL") << std::endl;
}

template <class T, class TFunc, class P1, class P2>
void test(T expected, TFunc f, P1 p1, P2 p2)
{
	cout << "Expected: " << expected << " Key: " << p2 << endl;
	auto result = f(p1, p2);
	if (expected != result)
	{
		std::cout << "Fail, expected: " << expected << endl;
		assert(false);
	}
}

typedef _Vector_const_iterator<_Vector_val<_Simple_types<int>>> vIterator;

int binary_search_impl(vIterator begin, vIterator end, int b)
{
	return 1;
}

//template <class TIter, class T>
//TIter binary_search_1(TIter begin, TIter end, T key)
vIterator binary_search_1(vIterator begin, vIterator end, int key)
{
	assert(std::is_sorted(begin, end));


	auto size = end - begin;
	if (size == 0)
	{
		return end;
	}
	if (size == 1)
	{
		return (*begin) == key ? begin : end;
	}
	assert(size > 0);

	auto m = begin + (end - begin) / 2;
	if (key < *m)
	{
		auto r = binary_search_1(begin, m, key);
		return m == r ? end : r;
	}
	else if (*m < key)
	{
		return binary_search_1(m + 1, end, key);
	}
	else
	{
		return m;
	}
}


//template <class TIter, class T>
//TIter binary_search_1(TIter begin, TIter end, T key)
vIterator binary_search_1_it(vIterator begin, vIterator end, int key)
{
	assert(std::is_sorted(begin, end));
	while (begin < end)
	{
		auto m = begin + (end - begin) / 2;

		if (key < *m)
		{
			end = m;
		}
		else if (*m < key)
		{
			begin = m + 1;
		}
		else
		{
			return m;
		}
	}

	return begin;
}

template <class TFunc>
void test_binary_search(TFunc binary_search_impl)
{
	typedef vector<int> Vec;
	int key = 42;

	auto adaptor = [binary_search_impl](Vec& v, int key) {
		auto result = binary_search_impl(v.begin(), v.end(), key);
		return result == v.end() ? -1 : result - v.begin();
	};


	// degenarated
	test(-1, adaptor, Vec(), key);

	// trivial
	test(-1, adaptor, Vec({ 1 }), key);
	test(0, adaptor, Vec({ 42 }), key);

	// and 2nd trivial
	test(-1, adaptor, Vec({ 1, 2 }), key);
	test(1, adaptor, Vec({ 1, 42 }), key);
	test(0, adaptor, Vec({ 42, 100 }), key);

	// key not in array
	test(-1, adaptor, Vec({ 1, 2, 3, 5, 41 }), key);
	test(-1, adaptor, Vec({ 43, 45, 47, 100 }), key);
	test(-1, adaptor, Vec({ 3, 5, 41, 43, 45, 67 }), key);

	// key in array
	test(3, adaptor, Vec({ 1, 2, 5, 42 }), key);
	test(0, adaptor, Vec({ 42, 45, 67, 100 }), key);
	test(3, adaptor, Vec({ 3, 5, 41, 42, 45, 67 }), key);

	// binary search specific
	test(3, adaptor, Vec({ 3, 5, 41, 42, 45, 67 }), key);
	test(2, adaptor, Vec({ 3, 5, 42, 45, 67 }), key);

}

void test_all_binary_searches()
{
	test_binary_search(binary_search_1_it);
}

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

template <class TIter>
void outer_merge(TIter b1, TIter e1, TIter b2, TIter e2, TIter out)
{
	TIter i1 = b1;
	TIter i2 = b2;

	TIter b_out = out;
	while (i1 < e1 && i2 < e2)
	{
		assert(is_sorted(b_out, out));
		assert((i1 - b1) + (i2 - b2) == (out - b_out));
		if (*i1 < *i2)
			*out = *i1++;
		else
			*out = *i2++;

		assert(std::is_sorted(b_out, out));
		out++;
	}

	out = copy(i1, e1, out);
	out = copy(i2, e2, out);
}

template <class TIter>
void merge_sort(TIter b, TIter e, TIter buff)
{
	if (e - b > 1)
	{
		TIter m = b + (e - b) / 2;
		merge_sort(b, m, buff);
		merge_sort(m, e, buff);
		outer_merge(b, m, m, e, buff);
		copy(buff, buff + (e - b), b);
	}

	assert(std::is_sorted(b, e));
}

template <class TFunc>
void test_sort(TFunc sort_impl)
{

}

template <class T>
void test_all_sort()
{
	test_sort(merge_sort);
}

void main()
{
	/*
	test_all_binary_searches();
	int testArray1_1[1] = { 1 };
	int testArray1_2[1] = { 2 };
	int testArray2[2] = { 1, 2 };
	int testArray3[3] = { 1, 5, 10 };

	test_search(testArray1_1, 1, 2, -1);
	test_search(testArray1_2, 1, 2, 0);
	test_search(testArray2, 2, 1, 0);
	test_search(testArray2, 2, 2, 1);
	test_search(testArray3, 3, 5, 1);
	test_search(testArray3, 3, 1, 0);
	test_search(testArray3, 3, 10, 2);

	*/
	/////////////////////////////////////////////
	//std::vector<int> testArray4 = { 5, 3, 8, 1 };
	//std::vector<int> testArray5 = { 0, 0, 0, 0 };
	//sort_buble(testArray4.begin(), testArray4.end());
	//print(testArray4.begin(), testArray4.end());

	/////////////////////////////////////////////
	//merge_sort(testArray4.begin(), testArray4.end(), testArray5.begin());
	//test_all_sort();

	system("pause");
}