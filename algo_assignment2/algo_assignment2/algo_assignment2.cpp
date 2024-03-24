#include <iostream>
#include <vector>
#include <windows.h>
#include <chrono>
#include <thread>  
#include <cstdlib>  
using namespace std;


void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
    {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; ++j) 
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;

        // Play sound effect for swap
        Beep(500, 100);
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    std::cout << "Merged Array: ";
    for (int x = left; x <= right; x++) 
    {
        std::cout << arr[x] << " ";
    }
    std::cout << std::endl;
}


void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr = { 11, 1, 30, 2, 51, 6, 29, 7, 67, 15, 118, 4, 89, 23 };
    int n = arr.size();

    cout << "Original Array:";
    for (int num : arr)
        cout << " " << num;
    cout << endl;

    auto start = std::chrono::high_resolution_clock::now(); 


    mergeSort(arr, 0, n - 1);

    auto stop = std::chrono::high_resolution_clock::now();  // Stop timing
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start) / 1000; // Calculate duration

    cout << "Sorted Array:";
    for (int num : arr)
        cout << " " << num;
    cout << endl;

    std::cout << "Time taken for sorting: " << duration.count() << " miliseconds" << std::endl;

    return 0;
}


