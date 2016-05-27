#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

const int search_2(int array[], const int size, const int key)
{
	int i = 0;
	array[size] = key;
	
	while(array[i] != key)
	{
		++i;
	}
	
	if(i == size)
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

	for(int i = 0; i < size; ++i)
	{
		if(array[i] == key)
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

	auto m = begin + (end - begin) / 2;
	if (key < *m)
	{
		auto r = binary_search_1(begin, m, key);
		return m == r ? end : r;
	}
	else
		return binary_search_1(m, end, key);
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
	test_binary_search(binary_search_1);
}

void main()
{
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
	
	
	system("pause");
}