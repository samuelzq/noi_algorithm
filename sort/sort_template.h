#ifndef __H_SORT_TEMPLATE
#define __H_SORT_TEMPLATE

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstring>

template <class T>
class sort {
public:
	sort() {
		data = NULL;
		len = 0;
	};
	~sort() {
		if (data)
			delete[] data;
		len = 0;
	};
	void insertionsort();
	void selectionsort();
	void bubblesort();
	void shellsort();
	void mergesort() {merge(0, len - 1);};
	void heapsort();
	void quicksort();
protected:
	T *data;
	int len;
	void swap(T &d1, T &d2);
	void merge(int first, int last);
	void mergesort(int first, int last);
	void movedown(int first, int last);
	void quicksort(int first, int last);
};

template <class T>
void sort<T>::insertionsort(void)
{
	for (int i = 1, j; i < len; i++) {
		T tmp = data[i];
		for (j = i; j > 0 && tmp < data[j - 1]; j--)
			data[j] = data[j - 1];
		data[j] = tmp;
	}
}

template <class T>
void sort<T>::selectionsort(void)
{
	for (int i = 0, j, least; i < len - 1; i++) {
		for (j = 1 + 1, least = i; j < len; j++)
			if (data[j] < data[least])
				least = j;
		swap(data[least], data[i]);
	}
}

template <class T>
void sort<T>::bubblesort(void)
{
	for (int i = 0; i < len - 1; i++)
		for (int j = len - 1; j > i; --j)
			if (data[j] < data[j - 1])
				swap(data[j], data[j - 1]);
}

template <class T>
void sort<T>::merge(int first, int last)
{
	int mid = (first + last) / 2;
	int i1 = 0, i2 = first, i3 = mid + 1;
	T *tmp = new T[last - first + 1];
	while (i2 <= mid || i3 <= last) {
		if (data[i2] < data[i3])
			tmp[i1++] = data[i2++];
		else
			tmp[i1++] = data[i3++];
	}
	for (i1 = 0, i2 = first; i2 <= last; i1++, i2++)
		data[i2] = tmp[i1];
	delete[] tmp;
}

template <class T>
void sort<T>::mergesort(int first, int last)
{
	if (first < last) {
		int mid = (first + last) / 2;
		mergesort(first, mid);
		mergesort(mid + 1, last);
		merge(first, last);
	}

}

template <class T>
void sort<T>::shellsort(void)
{
	int i, j, hcnt, h;
#define HCOUNT      20
	int increments[HCOUNT + 1], k;

	// create an appropriate number of increments h
	for (h = 1, i = 0; h < len && i < HCOUNT; i++) {
		increments[i] = h;
		h = 3 * h + 1;
	}

	// loop on different increments h
	for (i--; i >= 0; i--) {
		h = increments[i];
		// loop on the number of subarrays h-sorted in ith pass
		for (hcnt = h; hcnt < 2 * h; hcnt++) {
			// insertion sort is here for sub-array
			for (j = hcnt; j < len; j += h) {
				T tmp = data[j];
				k = j;
				while (k - h >= 0 && tmp < data[k - h]) {
					data[k] = data[k - h];
					k -= h;
				}
				data[k] = tmp;
				j += h;
			}
		}
	}
}

template <class T>
void sort<T>::movedown(int first, int last)
{
	int largest = 2 * first + 1;
	while (largest <= last) {
		if (largest < last && data[largest] < data[largest + 1])
			largest++;
		if (data[first] < data[largest]) {
			swap(data[first], data[largest]);
			first = largest;
			largest = 2 * first + 1;
		} else
			largest = last + 1;
	}

}

template <class T>
void sort<T>::heapsort(void)
{
	for (int i = len / 2 -  1; i >= 0; i--) // make a heap here
		movedown(i, len - 1);
	for (int i = len - 1; i >= 1; i--) {
		swap(data[0], data[i]); // move the largest item to the end
		movedown(0, i - 1); // restore the heap
	}
}

template <class T>
void sort<T>::quicksort(int first, int last)
{
	int lower = first + 1, upper = last;
	swap(data[first], data[(first + last) / 2]);
	T bound = data[first];
	while (lower <= upper) {
		while (bound > data[lower])
			lower++;
		while (bound < data[upper])
			upper--;
		if (lower < upper)
			swap(data[lower++], data[upper--]);
		else
			lower++;
	}
	swap(data[upper], data[first]);
	if (first < upper - 1)
		quicksort(first, upper - 1);
	if (upper + 1 < last)
		quicksort(upper + 1, last);
}

template <class T>
void sort<T>::quicksort(void)
{
	int i, max;
	if (len < 2)
		return;
	for (i = 1, max = 0; i < len; i++)
		if (data[max] < data[i])
			max = i;
	swap(data[len - 1], data[max]);
	quicksort(0, len - 2);
}
#endif
