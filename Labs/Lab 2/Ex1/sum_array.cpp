#include <iostream>
using namespace std;

int sumArray(int arr[], int arrSize);

int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];  
      
    for(int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    delete[] arr;
    return sumArray(arr, size);
}

int sumArray(int arr[], int arrSize)
{
    int sum = 0;
    for(int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }
    return sum;
}