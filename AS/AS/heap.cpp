#include <assert.h>
#include <vector>

namespace heap_sort_details
{
	size_t left(size_t i)
	{
		return 
	}

	size_t right(size_t i)
	{
		return 2 * i + 2;
	}

	size_t parent(size_t i)
	{
		assert(i > 0);
		return (i - 1) / 2;
	}

	template <class T>
	void heapify(T A[], size_t i)
	{
		assert(is_heap(A, i));

		if (i == 0)
			return;

		auto p = parent(i);
		if (A[p] < A[i])
		{
			swap(A[p], A[i]);
			heapify(A, p);
		}

		assert(is_heap(A, i + 1));
	}

	template <class T>
	build_max_heap(vector<T>& A)
	{
		// [0, heap_size) [heap_size, size)
		size_t heap_size = 1;
		while (heap_size < A.size())
		{
			heapify(A, heap_size);
			++heap_size;
		}
	}
}