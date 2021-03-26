#include<iostream>
#include<time.h>
#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::microseconds;
using namespace std;

template <typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<microseconds>(end - begin).count();
}

class Node {
public:
	Node* next;
	int data;
};


void LLBinarySearch(Node* head, int target) {
	Node* start = head;   
	Node* end = NULL;
	do {
		if (start == NULL) {     //If start is null, end the function
			return; }
		Node* current = start;			//Node current to travel the head node
		Node* trailCurrent = start->next;
		while (trailCurrent != end) {
			trailCurrent = trailCurrent->next;	// Everytime current go up, trailCurrent goes up twice
			if (trailCurrent != end) {			//This is to find the middle node
				current = current->next;
				trailCurrent = trailCurrent->next;
			}
		}
		Node* mid = current;				//Current ends up being the mid node
		if (mid == NULL) { cout << 
			"List is empty";				//If mid is NULL, List is empty
			return; }
		else if (mid->data == target) {		//It mid data is target, then the target was found
			cout << "Target number found in Linked List. It is:" << mid->data << endl;;
			return; }
		else if (mid->data < target) {
			start = mid->next;				//If mid data is less than target
		}									//Then start is now new mid
		else {
			end = mid;						//Else end is new mid
		}
	} while (end == NULL || end != start);	//If target not found, then end function
	cout << "Target not found in the Linked List" << endl;
	return;
}

void insertLast(Node** node, int data) {
	Node* newNode;
	Node* tail = *node;
	newNode = new Node();
	newNode->data = data;
	newNode->next = nullptr;
	if (node == nullptr) {
		*node = newNode;
		return;
	}
	while (tail->next != nullptr) {
		tail = tail->next;
	}
	tail->next = newNode;
	return;
}
void printList(Node* node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

int partition(int* arr, int start, int end) {
	int pivot = arr[start];
	int middle = start;

	for (int i = start + 1; i <= end; ++i)
	{
		if (arr[i] < pivot) {
			++middle;
			int temp = arr[i];
			arr[i] = arr[middle];
			arr[middle] = temp;

		}
	}
	int temp = arr[start];
	arr[start] = arr[middle];
	arr[middle] = temp;
	return middle;
}
void quickSort(int* arr, int start, int end) {
	if (start < end) {
		int pivot = partition(arr, start, end);
		quickSort(arr, start, pivot - 1);
		quickSort(arr, pivot + 1, end);
	}
}
void iterativeBinarySearch(int* arr, int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;    //Finds the middle of the array
		if (arr[mid] == target) {
			cout << "Target number found Iteratively. It is: " << arr[mid] << endl;	//If target is found, print target
			return;
		}

			if (target > arr[mid]) {
				start = mid + 1;				//If target is more than middle element of array, then make start new mid+1
			}
			else {
				end = mid - 1;					//Else, make end new mid-1
			}
	}
	cout << "Number not found in array." << endl;  
	return;
}
void recursiveBinarySearch(int* arr, int start, int end, int target) {
	int mid = (start + end) / 2;	//Finds the middle of the array
	if (arr[mid] == target) {
		cout << "Target number found Recursively. It is: " << arr[mid] << endl; //If target is found, print target
	}
	if (mid == start || mid == end) {
		cout << "Number not found in array." << endl;
		return;
	}
	if (target < arr[mid]) {		//If target is less than middle element of array, then call the function again with mid as end
		return recursiveBinarySearch(arr, start, mid, target);
	}
	else {
		if (target > arr[mid]) {	//Else, call the function again with mid as start
			return recursiveBinarySearch(arr, mid, end, target);
		}
	}
}

int main() {
	srand(time(nullptr));
	int size = 1000000;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % size + 1;
	}
	quickSort(arr,0,size-1);
	int target = rand() % size + 1;
	cout << "Array of size: " << size << endl;
	cout << "Target Number: " << target << endl;
	Node* ll = new Node();
	for (int i = 0; i < size; i++)
	{
		insertLast(&ll, arr[i]);
	}

	
	
	auto itBSearchTime = TimeFunc([&]() {iterativeBinarySearch(arr, 0, size, target);; });
	auto recBSearchTime = TimeFunc([&]() {recursiveBinarySearch(arr, 0, size, target); });
	auto LLSearchTime = TimeFunc([&]() {LLBinarySearch(ll, target); });
	cout << "Time to complete Iterative Binary Search:" << itBSearchTime << " milliseconds" << endl;
	cout << "Time to complete Recursive Binary Search:" << recBSearchTime << " milliseconds" << endl;
	cout << "Time to complete Linked List Binary Search:" << LLSearchTime << " milliseconds" << endl;
	cout << endl << endl;

	int size2 = 10000000;
	int* arr2 = new int[size2];
	for (int i = 0; i < size2; i++)
	{
		arr2[i] = rand() % size2 + 1;
	}
	quickSort(arr2, 0, size2 - 1);
	int target2 = rand() % size2 + 1;
	cout << "Array of size: " << size2 << endl;
	cout << "Target Number: " << target2 << endl;
	Node* ll2 = new Node();
	for (int i = 0; i < size2; i++)
	{
		insertLast(&ll2, arr2[i]);
	}

	
	auto itBSearchTime2 = TimeFunc([&]() {iterativeBinarySearch(arr2, 0, size2, target2);; });
	auto recBSearchTime2 = TimeFunc([&]() {recursiveBinarySearch(arr2, 0, size2, target2); });
	auto LLSearchTime2 = TimeFunc([&]() {LLBinarySearch(ll2, target2); });
	cout << "Time to complete Iterative Binary Search:" << itBSearchTime2 << " milliseconds" << endl;
	cout << "Time to complete Recursive Binary Search:" << recBSearchTime2 << " milliseconds" << endl;
	cout << "Time to complete Linked List Binary Search:" << LLSearchTime2 << " milliseconds" << endl;

	delete[] arr;
	delete[] arr2;
}