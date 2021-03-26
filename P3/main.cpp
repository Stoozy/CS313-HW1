#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int* TwoDmatrix(int** arr, int len) { //converts the array one array
    int* myarray = new int[len];
    for (int i = 0; i < len; i++) {
        myarray[i] = *(*arr + i);
    }
    return myarray;
}

void swap(int& x, int& y) //interchange two variables
{
    int temp = x;
    x = y;
    y = temp;
}

void bubble_sort(int **arr, int arrSize) { //swapping the adjacent elements if they are in wrong order.
    int len = arrSize * arrSize;
    int* myarray = TwoDmatrix(arr, len);
    int temp;
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1 - i; j++)
            if (myarray[j] > myarray[j + 1]) {
                swap(myarray[j], myarray[j + 1]);
            }
    for (int i = 0; i < len; i++) {
        *(*arr + i) = myarray[i];
    }
}


void SelectionSort(int **arr, int arrSize) // finds smallest element in the unsorted array and puts it at the begining 
{
    int len = arrSize * arrSize;
    int* myarray = TwoDmatrix(arr, len);
    int minIndex;
    
    for (int i = 0; i < len - 1; ++i)
    {
        minIndex = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (myarray[j] < myarray[minIndex])
                minIndex = j;
        }
        swap(myarray[i], myarray[minIndex]);
    }
    for (int i = 0; i < len; i++) {
        *(*arr + i) = myarray[i];
    }
}



void InsertionSort(int **arr, int arrSize) //compares each element in the array and shifts the unsorted array to a spot suitable for it
{
    int len = arrSize * arrSize;
    int* myarray = TwoDmatrix(arr, len);
    for (int i = 0; i < len; ++i)
    {
        int refValue = myarray[i];
        int j;
        for (j = i - 1; j >= 0; --j)
        {
            if (myarray[j] > refValue)
                myarray[j + 1] = myarray[j];
            else
                break;
        }
        myarray[j + 1] = refValue;
    }
    for (int i = 0; i < len; i++) {
        *(*arr + i) = myarray[i];
    }
}


void insertion_sort(int arr[], int len) {
    int i, j, key;
    for (i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    // creates an array
    int*( myArray[5]);
    int a[5][5]= {
        { 99, 49, 72, 87, 24 },
        { 52, 27, 22, 67, 11 },
        { 15, 87, 53, 100, 55  },
        { 47, 29, 99, 91, 72},
        { 36, 55, 69, 88, 44 },
    };
    for (int i = 0; i < 5; i++) {
        myArray[i] = a[i];
    }
    // unsorted array.
    cout << "Unsorted 2D structure is: " << endl << endl;;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }
    //each type of sort is done to myarray
    bubble_sort(myArray , 5);
    SelectionSort(myArray, 5);
    InsertionSort(myArray, 5);
    cout << endl;
    //sorted array.
    cout << "Sorted 2D structure is: " << endl << endl;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

