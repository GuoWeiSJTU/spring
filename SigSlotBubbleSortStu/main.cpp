#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <boost/signals2.hpp>
using namespace boost::signals2;
using namespace std;

class Student
{
public :
	int stuID;
	int stuScore;

	Student(){};

	Student(int id,int score)
	{
		this->stuID = id;
		this->stuScore = score;
	};

	bool comp(Student stu)
	{
		return this->stuID > stu.stuID;
	}
	bool operator()(Student stu)
	{
		return this->stuID > stu.stuID;
	}


};

void BubbleSort(Student stuArray[], int size) {
	signal<bool(Student)> sig;
	int j, i;
	Student temp;
	for (i = 0; i < size - 1; i++) {
		int count = 0;
		for (j = 0; j < size - 1; j++) {
			sig.connect(0, stuArray[j]);
		//	cout << sig(stuArray[j+1]).get()<< endl;
			if (sig(stuArray[j + 1]).get())
			{
				temp = stuArray[j];
				stuArray[j] = stuArray[j + 1];
				stuArray[j + 1] = temp;
				count = 1;
			}

			//if (stuArray[j].comp(stuArray[j + 1]) ) 
			//{
			//	temp = stuArray[j];
			//	stuArray[j] = stuArray[j + 1];
			//	stuArray[j + 1] = temp;
			//	count = 1;
			//}

		}
		if (count == 0)
			break;
	}
}

void ShowStudent(Student stuArray[], int size)
{
	for (int i = 0; i < size;i++)
	cout <<stuArray[i].stuID << endl;
}
int main()
{
	Student stu1(3, 10);
	Student stu2(5, 20);
	Student stu3(2, 30);
	Student stuArray[3] = { stu1,stu2,stu3 };
	BubbleSort(stuArray, 3);
	ShowStudent(stuArray, 3);
	return 0;
}