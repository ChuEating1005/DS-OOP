#include <iostream>
using namespace std;

int factorial(int n) {
   if (n == 0) {
      // TODO
       return 1;
   } else {
      // TODO
       return n * factorial(n-1);
   }
}

int main() {
   int num;
   cin >> num;
   cout << "Factorial of " << num << " is " << factorial(num) << endl;
   return 0;
}

