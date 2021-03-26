#include<iostream>
#include<time.h>
#include<algorithm>
#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using namespace std;

//Time function to time how long the function takes.
template <typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();
}


void insertionSort(int arr[], int start, int size) {
	for (int i = start+1; i < size+1; ++i)
	{
		int key = arr[i];
		int j;
		for(j = i-1;  j>= 0; --j)
		{
			if (arr[j] > key) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = key;
	}
}

void swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int partition(int arr[], int start, int end) {
	int pivot = arr[start];            //Pivot is the first element in the array
	int middle = start;                
	for (int i = start + 1; i <= end; ++i)
	{
		if (arr[i] < pivot) {          //If the number in the array is smaller than the pivot, then swap them
			++middle;				 	
			swap(arr[i],arr[middle]);
			
		}
	}
	swap(arr[start], arr[middle]);	   //Then swap arr[start] and arr[end]
	return middle;					   //Return the middle value
}

void quickSort(int arr[], int start, int end) {
	if (start < end) {
		int pivot = partition(arr, start, end);   
		quickSort(arr, start, pivot-1);         //Do quicksort on the left side of the array
		quickSort(arr, pivot + 1, end);			//Do quicksort on the right side of the array 
	}
}

void customSort(int* arr, int start, int end) {
	int pivot;
	while (start < end) {
		if (end - start + 1 > 10) {					  //When the array is geater than 10, we use the customSort again	            
			pivot = partition(arr, start, end - 1);   //Gets pivot point from partition function
			if (pivot - start < pivot - end) {		  
				customSort(arr, start, pivot - 1);   //Using the custom sort on the left side
				start = pivot - 1;
			}
			else {
				customSort(arr, pivot + 1, end);     //Using the custom sort on the right side
				end = pivot - 1;
			}
		}
		else {									     //If the array is less than 10, then use insertionSort
			insertionSort(arr, start, end);
			return;
		}
	}
}
	


int main() {
	srand(time(NULL));
	int size = 1000000;						      						
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % size + 1;
	}
	int* arr2 = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr2[i] = rand() % size + 1;
	}
	int* arr3 = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr3[i] = rand() % size + 1;
	}
	auto customSortTime = TimeFunc([&]() {customSort(arr, 0, size); });
	auto algo_sort_time = TimeFunc([&]() {sort(arr2,arr2+size); });
	auto algo_stableSort_time = TimeFunc([&]() {stable_sort(arr3, arr3 + size); });
	cout << "Custom sort time:\t " <<customSortTime << " milliseconds" << endl;
	cout << "STL sort function time: " << algo_sort_time << " milliseconds" << endl;;
	cout << "STL stable sort function time: " << algo_stableSort_time << " milliseconds" << endl;

	return 0;
}