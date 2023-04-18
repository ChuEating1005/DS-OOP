#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	string Name;
	string StudentID;
	int Score;
public:
	Student(){}
	Student(string name, string studentID, int score){
		Name = name;
        StudentID = studentID;
        Score = score;
	}
	string getName(){
		return Name;
	}
	string getStudentID(){
		return StudentID;
	}
	int getScore(){
		return Score;	
	}
};

int main() {
	string name;
	string studentID;
	int score;
	Student mStudent;
	
	cin >> name >> studentID >> score;
	mStudent = Student(name, studentID, score);
	cout << mStudent.getName() << "'s studentID is " << mStudent.getStudentID()
	<< " and score is " << mStudent.getScore() << "." << endl;
	
	return 0;
}