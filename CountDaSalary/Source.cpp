#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>


using namespace std;

class Student
{
public:
	Student(string& _name, double _salary, double _bonus)
		: name(_name), salary(_salary), bonus(_bonus) {}

	string& getName() { return name; }
	double getSalary() { return salary; }
	double getBonus() { return bonus; }

	double getFullSalary() { return salary + salary * bonus / 100; }

	string GetStudentData()
	{
		
		return "\nStudent: " + name + "\nSalary:" + to_string(salary) + "\nBonus: " + to_string(bonus)+"%\n==========\nTotal salary: " + to_string(getFullSalary()) + "\n";
	}

private:
	string name;
	double salary;
	double bonus;
};

vector<Student> ReadStudentFile(string&& _fileName)
{
	ifstream file(_fileName);
	vector<Student> vec;
	string separator = ";";
	
	if (file.is_open())
	{
		string line;

		while (getline(file, line))
		{
			string name = line.substr(0, line.find(separator));  
			string other = line.substr(name.length()+1, line.length()-name.length());  
			string salary_text = other.substr(0, other.find(separator)); 
			other = other.substr(salary_text.length() + 1, other.length() - name.length());
			string bonus_text = other.substr(0, other.find(separator));

			double salary = stod(salary_text);
			double bonus = stod(bonus_text);

			Student s(name, salary, bonus); 
			vec.push_back(s);
		}

		file.close();

	}
	return vec;
}

void SaveVectorToFile(string&& _fileName, vector<Student> _vector)
{
	ofstream file;
	
	file.open(_fileName);

	for (auto _s : _vector)
	{
		file << _s.GetStudentData();
	}

	file.close();
}


int main()
{
	setlocale(LC_ALL, "");

	cout << "Hello!!!\n";

	vector<Student> s = ReadStudentFile("C:/Users/Naglfar/source/repos/CountDaSalary/Debug/StudentsList.txt");

	for(auto _s : s)
	{
		cout << _s.GetStudentData();
	}

	SaveVectorToFile("C:/Users/Naglfar/source/repos/CountDaSalary/Debug/StudentsList_OUT.txt", s);


}
