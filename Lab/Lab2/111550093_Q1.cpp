#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
	Student(string F, string L, string dormNum, string id) 
    : first_name(F), last_name(L), dormitory(dormNum), ID(id)
    { 
        
    }
    //TODO: design constructor
    
	string generate_address(){
    	//TODO: generate the output address  
        string str = "1001 University Road, Hsinchu, Taiwan 300, ROC, dorm ";
        str =  str + dormitory + ", (" + ID + ") " + first_name + " " + last_name;
        return str;
    }

private:
	string first_name;
    string last_name;
	string dormitory;
	string ID;
};


int main() {
    string f, l, d, id;
    cin >> f >> l >> d >> id;
    Student mStudent(f, l, d, id);
  	cout << mStudent.generate_address() << endl;
    return 0;
}