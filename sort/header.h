#pragma once
#include<iostream>
#include <random>
#include <algorithm>
#include <cstddef>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void generate_random_array(int arr[], size_t size) {
	std::random_device rd;  // Получаем случайное число от устройства
	std::mt19937 gen(rd()); // Инициализируем генератор случайных чисел
	std::uniform_int_distribution<> distrib(0, 99);
	std::generate(arr, arr + size, [&]() {return distrib(gen); });
}
//---Сортировка выбором
void sort_choice(int arr[], size_t size) {
	for (size_t i = 0; i < size-1; i++)
	{
		int min_index = i;
		for (size_t j = i+1; j < size; j++)
		{
			if (arr[j]<arr[min_index])
			{
				min_index = j;
			}
		}
		if (min_index!=i)
		{
			int tmp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = tmp;
		}
	}
}
//---Сортировка вставками
void sort_insert(int arr[], size_t size) {
	for (size_t i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j>=0 && arr[j]> key) {
			arr[j + 1] = arr[j];
			--j;
		};
		arr[j + 1] = key;
	}
}
//---Пузырьковая сортировка
void sort_buble(int ar[], size_t size_ar) {
	bool swapped = false;
	for (size_t i = 0; i < size_ar-1; i++)
	{
		for (size_t j = i+1; j < size_ar; j++)
		{
			if (ar[j]<ar[i])
			{
				int tmp = ar[j];
				ar[j] = ar[i];
				ar[i] = tmp;
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}
//---Быстрая сортировка Хоара с простой рекурсией
void qsortHoare(int arr[], int l, int r) {
	if (l >= r)
	{
		return;
	}
	int mid = arr[l + (r - l) / 2];
	int left = l;
	int right = r;

	do
	{
		while (arr[left] < mid) ++left;
		while (arr[right] > mid) --right;

		if (left <= right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			++left;
			--right;
		}
	} while (left <= right);

	qsortHoare(arr, l, right);
	qsortHoare(arr, left, r);
}
 //---Быстрая сортировка Хоара с оптимизированной хвостовой рекурсией
void qsortHoareTailRecursive(int arr[], int l, int r) {
	while (l < r) {
		int pivot = arr[l + (r - l) / 2];
		int left = l;
		int right = r;

		while (left <= right)
		{
			while (arr[left] < pivot)++left;
			while (arr[right] > pivot) --right;
			if (left <= right)
			{
				swap(arr[left], arr[right]);
				++left;
				--right;
			}
		}
		if (right - l < r - left)
		{
			qsortHoareTailRecursive(arr, l, right);
			l = left;
		}
		else
		{
			qsortHoareTailRecursive(arr, left, r);
			r = right;
		}
	}
}
//---Функция получения pivot для quickSort (Lomuto partition)
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
//---Функция для преобразования поддерева в двоичную кучу
void heapify(int arr[], int n, int i) {
	int largest = i; //---Инициализируем наибольший элемент как корень
	const int left = 2 * i + 1;
	const int right = 2 * i + 2;
	//---Если левый дочерний элемент больше корня
	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}
	//---Если правый дочерний элемент больге корня
	if (right < n && arr[right]> arr[largest])
	{
		largest = right;
	}
	//---Если наибольший элемент не корень
	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);
		//---Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
}
//---Heap сортировка
void heapSort(int arr[], size_t size) {
	//---Построение кучи (перегруппируем массив)
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(arr, size, i);
	}
	//---Один за другим извлекаем элементы из кучи
	for (int i = size - 1; i > 0; i--)
	{
		//---Перемещаем текущий корень в конец
		std::swap(arr[0], arr[i]);
		//---Вызываем heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}
//---—Сортировка сли¤нием
void merge(int* array, int l, int m, int r) {
	const int n1 = m - l + 1;
	const int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];

	for (size_t i = 0; i < n1; i++)
	{
		L[i] = array[l + i];
	}
	for (size_t i = 0; i < n2; i++)
	{
		R[i] = array[m + 1 + i];
	}
	int i = 0;
	int j = 0;
	int k = l;
	while (i < n1 && j < n2)
	{
		array[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
	}
	while (i < n1) {
		array[k++] = L[i++];
	}
	while (j < n2)
	{
		array[k++] = R[j++];
	}
	delete[] L;
	delete[] R;
}
void mergeSort(int* array, int l, int r) {
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(array, l, m);
		mergeSort(array, m + 1, r);
		merge(array, l, m, r);
	}

}


//---Печать массива
void print(int ar[], size_t size_ar) {

	for (size_t i = 0; i < size_ar; i++)
	{
		if (i != size_ar - 1)
		{
			std::cout << ar[i] << ", ";
		}
		else
		{
			std::cout << ar[i];
		}

	}
	std::cout << std::endl;
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
