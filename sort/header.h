#pragma once
#include<iostream>

//---Сортировка выбором
void sort_choice(int ar[], size_t size_ar) {
	for (size_t i = 0; i < size_ar-1; i++)
	{
		int min_index = i;
		for (size_t j = i+1; j < size_ar; j++)
		{
			if (ar[j]<ar[min_index])
			{
				min_index = j;
			}
		}
		if (min_index!=i)
		{
			int tmp = ar[i];
			ar[i] = ar[min_index];
			ar[min_index] = tmp;
		}
	}
}
//---Пузырьковая сортировка
void sort_buble(int ar[], size_t size_ar) {
	for (size_t i = 0; i < size_ar-1; i++)
	{
		for (size_t j = i+1; j < size_ar; j++)
		{
			if (ar[j]>ar[i])
			{
				int tmp = ar[j];
				ar[j] = ar[i];
				ar[i] = tmp;
			}
		}
	}

}
//---Быстрая сортировка Хоара
 void qsortHoare(int arr[], int left, int right) {
	if (left >= right)
	{
		return;
	}
	int mid = arr[left + (right - left)/2];
	int i = left;
	int j = right;

	do
	{
		while (arr[i] < mid) ++i;
		while (arr[j] > mid) --j;
		
		if (i <= j)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			++i;
			--j;
		}
	} while (i <= j);

	qsortHoare(arr, left, j);
	qsortHoare(arr, i, right);
}
//---Функция получения pivot для quickSort
 int partition (int arr[], int low, int high){
	 int pivot = arr[high];
	 int i = (low - 1);
	 for (size_t j = low; j < high; j++)
	 {
		 if (arr[j] <= pivot)
		 {
			 i++;
			 int temp = arr[i];
			 arr[i] = arr[j];
			 arr[j] = temp;
		 }
	 }
	 int temp = arr[i + 1];
	 arr[i + 1] = arr[high];
	 arr[high] = temp;
	 return (i + 1);
	 };
 //---Быстрая сортировка опорным послежним элементом
 void quickSort(int arr[], int low, int high) {
	 if (low < high)
	 {
		 int pivot = partition(arr, low, high);
		 quickSort(arr, low, pivot - 1);
		 quickSort(arr, pivot + 1, high);
	 }
 }
//---Печать массива
void print(int ar[], size_t size_ar) {
	
	for (size_t i = 0; i < size_ar; i++)
	{
		if (i!=size_ar-1)
		{
			std::cout << ar[i] << ", ";
		}
		else
		{
			std::cout << ar[i];
		}
		
	}
}

//---Рекурсивная функция сложения элементов массива
 int recursiveSumm(int arr[], size_t size) {
	if (!size)
	{
		return 0;
	}
	return	arr[size-1]+recursiveSumm(arr, size-1);
	
}
 
 bool bin_search(int arr[], size_t size_ar, int sample) {
	 int left = 0, right = size_ar - 1;
	 int middle = (right - left) / 2;
	 while (left < right)
	 {
		 if (arr[middle] == sample) break;
		 else if (sample < arr[middle])
		 {
			 left = middle + 1;
		 }
		 else
		 {
			 right = middle - 1;
		 }
	 }
	 if (sample == arr[middle]) return 1;
 }
 
 int* Min(int *ar, size_t size_ar) {
	 int min=0;
	 for (size_t i = 0; i <size_ar; i++)
	 {
		 if (ar[min] > ar[i]) min = i;
	 }
	 return &ar[min];

 }

 void Simplex_Input(int arr[], size_t size) {
 
	 for (size_t i = 1; i < size-1; i++)
	 {
		 int tmp = arr[i];
		 for (size_t j = 0; j < i; j++)
		 {
			 if (tmp<arr[j])
			 {
				 for (size_t k = i; k > j; k--)
				 {
					 arr[k] = arr[k - 1];
				 }
				 arr[j] = tmp;
				 break;
			 }
		 }
	 }
 }

 void Shake(int arr[], size_t size) {
	 int left = 0;
	 int right = size - 1;
	 while (left<right)
	 {
		 for (size_t i = left; i < right; i++)
		 {
			 if (arr[i]>arr[i+1])
			 {
				 int tmp = arr[i];
				 arr[i] = arr[i + 1];
				 arr[i + 1] = tmp;
			 }
		 }
		 right--;
		 for (size_t i = right; i >left ; i--)
		 {
			 if (arr[i-1]>arr[i])
			 {
				 int tmp = arr[i - 1];
				 arr[i - 1] = arr[i];
				 arr[i] = tmp;
			 }
		 }
		 left++;
	 }
 }
