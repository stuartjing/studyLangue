#include <iostream>
using namespace std;

class Student{
private:
	char const  *m_name;
	int m_age;
	float m_score;
	static int m_total;
public:
	Student(char *name,int age);
	Student(char const *name,int age, float score);
	void show();
};

Student::Student(char *name,int age){
	m_name = name;
	m_age = age;
	m_score = 0.00f;
}

int Student::m_total = 0;
//采用初始化列表
Student::Student(char const *name,int age,float score):m_name(name),m_age(age),m_score(score){
	//todo
	m_total++;
}

void Student::show(){
	cout<<m_name<<"的年龄是"<<m_age<<"岁，这个月数学成绩是"<<m_score<<"，总数是"<<this->m_total<<" !"<<endl;
}

int main(){
	Student *stu0 = new Student("ooo",18);
        stu0->show();
	stu0->show();
	
	//1
	class Student stu("小明",18,89.9f);
	stu.show();

	//2
	Student *stu1 = new Student("小张",19,100.0f);
	stu1->show();
	
	delete(stu1);
	return 0;
}
