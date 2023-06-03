#include <iostream>

using namespace std;


int main() {
   // TODO: (There are no restrictions on the methods you may use.)
    int n, all;
    cin >> n;
    for(int i =0 ; i<n ; i++)
    {
        cin >> all;
        int * arr = new int[all];
        for(int j = 0; j < all; j++)
        {
            cin >> arr[j];
        }
        int cnt = 0;
        for(int j = 0; j < all-1; j++)
        {
            for(int k = 0 ; k < all-1-j ; k++)
            {
                if(arr[k] > arr[k+1])
                {
                    int temp = arr[k];
                    arr[k] = arr[k+1];
                    arr[k+1] = temp;
                    cnt++;
                }
            }
        }
        cout << "The minimum number of exchanges needed is " << cnt <<".\n";
    }
    return 0;
}