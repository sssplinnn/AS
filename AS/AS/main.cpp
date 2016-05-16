#include <iostream>

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

const int search_1(const int array[]. const int size, const int key)
{
	for(int i = 0; i < size; ++i)
	{
		if(array[i] == key)
		{
			return array[i];
		}
	}
	
	return -1;
}

bool test_search(const int array[], const int size, const int key, const int index)
{
	int result = search_1(array, size, key);
	
	cout (result == index)? std::cout << "OK" : std::cout << "FAIL";		
}

void main()
{
	test_search({1}, 1, 2);
	test_search({2}, 1, 2);
	test_search({1, 2}, 2, 1);
	test_search({1, 2}, 2, 2);
	test_search({1, 5, 10}, 3, 5);
	test_search({1, 5, 10}, 3, 1);
	test_search({1, 5, 10}, 3, 10);
}