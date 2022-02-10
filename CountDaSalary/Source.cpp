#include <iostream>
#include <vector>
#include <string>

#include <fstream>

using namespace std;

class Student
{

public:

	Student(string& _name, float _salary, float _bonus)
		: name(_name), salary(_salary), bonus(_bonus) {}

	string& getName() { return name; }
	float getSalary() { return salary; }
	float getBonus() { return bonus; }

	void PrintData()
	{
		cout << "\nStudent: " + name + "\nSalary: " + to_string(salary) + "\nBonus: " + to_string(bonus);
	}

protected:
	string name;
	float salary;
	float bonus;
};


vector<Student> ReadStudentFile(string&& _filePath)
{
	ifstream file(_filePath);
	vector<Student> vec;

	string separator = ";";


	if (file.is_open())
	{
		string line;

		while (getline(file, line))
		{
			string name = line.substr(0, line.find(separator));
			float salary = stof(line.substr(1, line.find(separator)));
			float bonus = stof(line.substr(2, line.find(separator)));
			Student s(name, salary, bonus);
			vec.push_back(s);
		}
		file.close();
	}
	return vec;
}



int main()
{
	cout << "Hello";
	ReadStudentFile("C:/Users/Naglfar/Desktop/vagh.txt")[0].PrintData();
}
