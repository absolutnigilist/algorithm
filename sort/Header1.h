#pragma once

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubble(int arr[], int N) {

	for (size_t i = 0; i < N-1; i++)
	{
		for (size_t j = i+1; j < N; j++)
		{
			if (arr[i]>arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

void choice(int arr[], int N) {
	for (size_t i = 0; i < N-1; i++)
	{
		int minIndex = i; 
		for (size_t j = i+1; j < N; j++)
		{
			if (arr[minIndex]>arr[j])
			{
				minIndex = j;
			}
		}
		swap(arr[minIndex], arr[i]);
	}
}

void hoare(int arr[], int l, int r) {
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
			hoare(arr, l, right);
			l = left;
		}
		else
		{
			hoare(arr, left, r);
			r = right;
		}
	}
	//hoare(arr, l, right);
	//hoare(arr, left, r);
}
int part(int arr[], int l, int r) {
	int pivot = arr[r];
	int index = (l-1);

	for (int i = l; i < r; i++)
	{
		if (arr[i]<pivot)
		{
			++index;
			swap(arr[i], arr[index]);
		}
	}
	swap(arr[index + 1], arr[r]);
	return (index + 1);
}

void quick(int arr[], int l, int r) {
	if (l >= r) return;
	int pivot = part(arr, l, r);
	quick(arr, l, pivot - 1);
	quick(arr, pivot + 1, r);
}