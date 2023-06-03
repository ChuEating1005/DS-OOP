#include <iostream>
using namespace std;

int countOccurrences(int arr[], int n, int x, int count = 0) {
    // base case
    if (n == 0) {
        // TODO
        return 0;
    }

    // check if current element matches x
    // TODO
    if(*arr == x)
    {
        return 1+countOccurrences(arr+1, n-1, x);
    }
    else
    {
        return countOccurrences(arr+1, n-1, x);
    }
    // recursive case (return  countOccurrences(...);
    // TODO 	
    }

int main() {
    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    int count = countOccurrences(arr, n, x);
    if (count > 0) {
        cout << "The number " << x << " occurs " << count << " times in the array." << endl;
    } else {
        cout << "The number " << x << " does not occur in the array." << endl;
    }

    return 0;
}