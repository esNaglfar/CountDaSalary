#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>


using namespace std;


/// <summary>
/// Обычный класс для студентиков с парой полей, функцией печати и гетерами
/// </summary>
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
		cout << "\nStudent: " + name + "\nSalary: " + to_string(salary) + "\nBonus: " + to_string(bonus)+"\n==========\n";
	}

protected:
	string name;
	float salary;
	float bonus;
};

/// <summary>
/// Функция чтения данных из файла. Возвращает распаршенные данные в виде массива студентиков
/// </summary>
/// <param name="_fileName"></param>
/// <returns></returns>
vector<Student> ReadStudentFile(string&& _fileName)
{

	//filesystem::path path = filesystem::current_path().u8string() + "\\" + _fileName;
	//cout << path;
	

	ifstream file(_fileName);

	vector<Student> vec;

	string separator = ";";
	


	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			string name = line.substr(0, line.find(separator));  // Самоя простая часть. Взяли строку до первого вхождения разделителя.
			string other = line.substr(name.length()+1, line.length()-name.length());  // пошли макароны. По сути, мы из исходной строки убрали всё что было до первого разделителя + сам разделитель
			string salary_text = other.substr(0, other.find(separator)); // из полученного остатка забираем занечния до первого вхождения разделителя
			other = other.substr(salary_text.length() + 1, other.length() - name.length()); // повторяем процедуру разбиения строки. Вырезаем уже два куска.
			string bonus_text = other.substr(0, other.find(separator)); // Забираем последние данные


			float salary = stof(salary_text); // привели к флоату
			float bonus = stof(bonus_text);

			Student s(name, salary, bonus); // создали объект и запихнули в массив
			vec.push_back(s);
		}
		file.close();
	}
	return vec;
}



int main()
{
	setlocale(LC_ALL, "");

	cout << "Hello!!!\n";

	vector<Student> s = ReadStudentFile("C:/Users/Naglfar/source/repos/CountDaSalary/Debug/StudentsList.txt");

	for(auto _s : s)
	{
		_s.PrintData();
	}
}
