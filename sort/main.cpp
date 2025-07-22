#define _CRT_SECURE_NO_WARNINGS
#include "header.h"
#include <cstdio>
#include <chrono>

#define START auto start = std::chrono::high_resolution_clock::now();
#define END																			   \
auto end = std::chrono::high_resolution_clock::now();								   \
std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()\
<<" microseconds" <<std::endl;
#define SORT_TYPE(TYPE) std::cout<< TYPE <<std::endl;

int main() {
	{
		SORT_TYPE("//---Bubble sort, time complexity O(N)")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		sort_buble(array, SIZE);
		END
		delete[] array;
	}
	{
		SORT_TYPE("//---Choice sort, time complexity O(N)")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		sort_choice(array, SIZE);
		END
		delete[] array;
	}
	{
		SORT_TYPE("//---Hoare sort, time complexity O(logN)")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		qsortHoare(array, 0, SIZE-1);
		END
		delete[] array;
	}
	{
		SORT_TYPE("//---Hoare sort mit teil optimization, time complexity O(logN)")
			const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		qsortHoareTailRecursive(array, 0, SIZE - 1);
		END
		delete[] array;
	}
	{
		SORT_TYPE("//---Quick sort, time complexity O(logN)")
		const int SIZE = 10'000;
		int* array = new int[SIZE];
		generate_random_array(array, SIZE);
		START
		quickSort(array, 0, SIZE - 1);.07
		END
		delete[] array;
	}
	
	
	
	
	
	
	

	
 	int arr[] = { 10,11,25,1,3,66,22,15,10,1,28,35,13 };
	int size_array = sizeof(arr) / sizeof(arr[0]);

	sort_choice(arr, size_array);
	print(arr, size_array);
	std::cout << std::endl;

	sort_buble(arr, size_array);
	print(arr, size_array);
	std::cout << std::endl;

	
	qsortHoare(arr, 0, (sizeof(arr) / sizeof(arr[0]) - 1));
	print(arr, size_array);
	std::cout << std::endl;

	quickSort(arr, 0, (sizeof(arr) / sizeof(arr[0]) - 1));
	print(arr, size_array);

	int total = recursiveSumm(arr, size_array);
	std::cout << std::endl;

	bool flag = bin_search(arr, size_array, 13);
	std::cout << flag;

	std::cout << std::endl;

	int arrr[] = { 1,5,6,9,8,0 };

	int* ptr = Min(arrr, sizeof(arrr) / sizeof(arrr[0]));

	int ar_simp[] = {2,15,9,13,17,18};
	int ar_simp2[] = {2,15,9,13,17,18 };

	Simplex_Input(ar_simp, sizeof(ar_simp) / sizeof((ar_simp[0])));
	Shake(ar_simp2, sizeof(ar_simp2) / sizeof(ar_simp2[0]));
	

	int ar2[][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12} };
	
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