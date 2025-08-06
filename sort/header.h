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
//---Шейкерная сортировка
void sort_shake(int arr[], size_t size) {
	int left = 0;
	int right = size - 1;
	bool swapped = true;

	while (left < right&& swapped)
	{
		swapped = false;
		//---Проход слева направо
		for (size_t i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		//---Сдвигаем правую границу
		right--;
		//---Проход справа налево
		for (size_t i = right; i > left; i--)
		{
			if (arr[i - 1] > arr[i])
			{
				swap(arr[i], arr[i - 1]);
				swapped = true;
			}
		}
		//---Сдвигаем левую границу
		left++;
	}
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
				swap(ar[j], ar[i]);
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
//---—Сортировка слиянием
void merge(int* array, int left, int mid, int right) {
	const int sizeLeft = mid - left + 1;
	const int sizeRight = right - mid;
	int* leftArray = new int[sizeLeft];
	int* rightArray = new int[sizeRight];

	for (size_t i = 0; i < sizeLeft; i++)
	{
		leftArray[i] = array[left + i];
	}
	for (size_t i = 0; i < sizeRight; i++)
	{
		rightArray[i] = array[mid + 1 + i];
	}
	int indexLeft = 0;
	int indexRight = 0;
	int indexMerged = left;
	while (indexLeft < sizeLeft && indexRight < sizeRight)
	{
		array[indexMerged++] = (leftArray[indexLeft] < rightArray[indexRight]) 
			? leftArray[indexLeft++] 
			: rightArray[indexRight++];
	}
	while (indexLeft < sizeLeft) {
		array[indexMerged++] = leftArray[indexLeft++];
	}
	while (indexRight < sizeRight)
	{
		array[indexMerged++] = rightArray[indexRight++];
	}
	delete[] leftArray;
	delete[] rightArray;
}
void mergeSort(int* array, int left, int right) {
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(array, left, mid);
		mergeSort(array, mid + 1, right);
		merge(array, left, mid, right);
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
 [[nodiscard]]int recursiveSumm(int arr[], size_t size) {
	if (!size)
	{
		return 0;
	}
	return	arr[size-1]+recursiveSumm(arr, size-1);
	
 }
 //---Итеративная функция сложения элементов массива
 [[nodiscard]] int iterativeSumm(int arr[], size_t size) {
	 int result = 0;
	 for (size_t i = 0; i < size; i++)
	 {
		 result += arr[i];
	 }
	 return result;
 }
 //---Реализация бинарного поиска в отсортированном по возрастанию массиве
 bool bin_search(int arr[], size_t size_ar, int sample) {
	 
	 int left = 0, right = size_ar - 1;
	 
	 while (left <= right)
	 {
		 int middle = left + (right - left) / 2;

		 if (arr[middle] == sample) 
		 {
			 return true;
		 }
		 else if (sample < arr[middle])
		 {
			 right = middle - 1;
		 }
		 else
		 {
			 left = middle + 1;
		 }
	 }
	 return false;
 }
 //---Функция возвращает указатель на минимальный элемент массива
 int* Min(int *ar, size_t size_ar) {
	 int min=0;
	 for (size_t i = 0; i <size_ar; i++)
	 {
		 if (ar[min] > ar[i]) min = i;
	 }
	 return &ar[min];

 }

 
