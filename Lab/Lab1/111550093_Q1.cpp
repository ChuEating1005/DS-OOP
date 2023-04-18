#include <iostream>
using namespace std;

class Calculator
{
private:
    int Num1;
    int Num2;
public:
    Calculator(){}
    Calculator(int num1, int num2){
        Num1 = num1;
        Num2 = num2;
    }
    void get_add_result(int *value){
      	*value = Num1 + Num2;
    }

    void get_sub_result(int &value){
      	value = Num1 - Num2;
    }

    int get_mul_result(){
        return Num1 * Num2;
    }
};

int main() {
    int num1 = 0;
    int num2 = 0;
    int value = 0;
  
    while(cin >> num1 >> num2)
    {
        Calculator calc(num1, num2);
        calc.get_add_result(&value);
        cout << value << " ";
        calc.get_sub_result(value);
        cout << value << " ";
        value = calc.get_mul_result();
        cout << value << " ";
    }
    return 0;
}