#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_Array(int *arr, int len)
{
    // TODO:
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}

void fill_Array(int *arr, int len)
{
    // TODO:
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
}

void reverse_Array(int *arr, int len)
{
    // TODO:
    if (len % 2 == 0)
    {
        for (int i = 0; i <= len / 2 - 1; i++)
        {
            int temp = arr[i];
            arr[i] = arr[len - 1 - i];
            arr[len - 1 - i] = temp;
        }
    }
    else
    {
        for (int i = 0; i <= (len - 1) / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[len - 1 - i];
            arr[len - 1 - i] = temp;
        }
    }
}

int main()
{
    int *arr;
    int arrSize;
    // TODO:    (Hint: input)
    cin >> arrSize;

    // TODO:    (Hint: create a dynamic array...)
    arr = new int[arrSize];

    fill_Array(arr, arrSize);
    reverse_Array(arr, arrSize);
    print_Array(arr, arrSize);

    return 0;
}