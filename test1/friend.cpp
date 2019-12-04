#include <iotream>

using namespace std;

class Student{
public:
    Student(char *name,int age);
public:
    friend void show(Student *std);
private:
    char *m_name;
    int m_age;
    
}

Student::Student(char *name,int age):m_name(name),m_age(age){
    
}

void show(Student *std){
    cout<<std->m_name<<"的年龄是："<<std->m_age<<"."<<endl;
}

void main(){
    class Student std1("昭武",19);
    show(&std1);
    
    Student *std = new Student("张三",18);
    show(std);
}
