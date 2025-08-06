#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <cstdio>
#include <chrono>

#define START auto start = std::chrono::high_resolution_clock::now();
#define END																			   \
auto end = std::chrono::high_resolution_clock::now();								   \
std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()\
<<" microseconds" <<std::endl;
#define CONTEXT(TYPE) std::cout<< TYPE <<std::endl;

int main() {
	{
		CONTEXT("//---Shake sort, time complexity best O(n), mid O(n^2), worst O(n^2)")
			const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
			sort_shake(array, SIZE);
		END
			delete[] array;
	}
	{
		CONTEXT("//---Bubble sort, time complexity best O(n), mid O(n^2), worst O(n^2)")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		sort_buble(array, SIZE);
		END
		delete[] array;
	}
	{
		CONTEXT("//---Choice sort, time complexity best O(n^2), mid O(n^2), worst O(n^2)")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		sort_choice(array, SIZE);
		END
		delete[] array;
	}
	{
		CONTEXT("//---Insert sort, time complexity best O(n), mid O(n^2), worst O(n^2)")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		sort_insert(array, SIZE);
		END
		delete[] array;
	}
	{
		CONTEXT("//---Hoare sort, time complexity best O(log n), mid O(log n), worst O(n^2)")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		qsortHoare(array, 0, SIZE-1);
		END
		delete[] array;
	}
	{
		CONTEXT("//---Hoare sort mit teil optimization, time complexity O(log n), mid O(log n), worst O(n^2)")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		qsortHoareTailRecursive(array, 0, SIZE - 1);
		END
		delete[] array;
	}
	{
		CONTEXT("//---Quick sort, time complexityO(log n), mid O(log n), worst O(n^2)")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		quickSort(array, 0, SIZE - 1);
		END
		delete[] array;
	}
	{
		CONTEXT("//---Merge sort, time complexityO(log n), mid O(log n), worst O(log n)")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		mergeSort(array, 0, SIZE - 1);
		END
		delete[] array;
	}
	{
		CONTEXT("//---Sum of array by recursive function")
		const int SIZE = 1'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		int total = recursiveSumm(array, SIZE);
		END
		delete[] array;
	}
	{
		CONTEXT("//---Sum of array by iterative function")
		const int SIZE = 1'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		int total = iterativeSumm(array, SIZE);
		END
		delete[] array;
	}
	{
		CONTEXT("//---Binary search in sorted array in ascending order of array by iterative function")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		qsortHoare(array, 0, SIZE - 1);
		START
		bool isFound = bin_search(array, SIZE, 13);
		END
		delete[] array;
	
	
	}
	{
		CONTEXT("//---Returns a pointer to the minimum element in the array ar[]")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		int* isMin = Min(array, SIZE);
		END
		delete[] array;
	}

	int ar2[][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12} 
	};
	
	int(*int_ptr)[4] = ar2;

	int tmp1 = *(int_ptr[1] + 1);
	int tmp2 = *(*(int_ptr+1)+1);
	int tmp3 = (*(int_ptr + 1))[1];
	int tmp4 = ar2[1][1];
	int tmp5 = *ar2[1];
	int tmp6 = (*ar2)[1];
	int tmp7 = (*(ar2 + 1))[1];
	int tmp8 = *(*(ar2 + 1) + 1);

	int ar3[][3][4] = {
			{{0,1,2,3},
			{4,5,6,7},
			{8,9,10,11}},
						  
			{{12,13,14,15},
	        {16,17,18,19},
	        {20,21,22,23}},

	};
	
	const int N = 2;
	const int M = 3;
	int* p = new int[N*M];
	int** pp = new int* [N];

	for (size_t i = 0; i < N; i++)
	{
		pp[i] = p + i * M;
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			pp[i][j] = rand() % 10;
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << pp[i][j]<<" ";
		}
		std::cout << std::endl;
	}

	int* tmp = new int[(N + 1)*M];
	for (size_t i = 0; i < N*M; i++)
	{
		tmp[i] = p[i];
	}
	delete[]p;
	p = tmp;
	delete[]pp;
	pp = new int* [N + 1];

	for (size_t i = 0; i < N+1; i++)
	{
		pp[i] = p + i * M;
	}
	
	for (size_t i = 0; i < N+1; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << pp[i][j] << " ";
		}
		std::cout << std::endl;
	}
	delete[]p;
	p = nullptr;
	delete[]pp;
	pp = nullptr;

	int** pp1 = new int* [N];
	for (size_t i = 0; i < N; i++)
	{
		pp1[i] = new int[M];
	}

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			pp1[i][j] = rand() % 10;
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << pp1[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int** tmp_pp = new int* [N + 1];

	for (size_t i = 0; i < N; i++)
	{
		tmp_pp[i] = pp1[i];
	}
	delete[]pp1;
	pp1 = tmp_pp;

	pp1[N] = new int[M];

	for (size_t i = 0; i < N+1; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			std::cout << pp1[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (size_t i = 0; i < N+1; i++)
	{
		delete[]pp1[i];
	}
	delete[]pp1;
	pp1 = nullptr;

	FILE* pf = fopen("MyFile.txt", "w");
	if (pf)
	{
		char name[] = "Derik";
		int age = 4;
		fprintf(pf, "My dog %s is %d years old", name, age);
		fclose(pf);
	}
	return 0;
}