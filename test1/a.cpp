#include <stdio.h>

//定义结构
struct Student{
	char const *name;
	int age;
};

void display(struct Student s ){
	printf("%s的年龄是%d.\n",s.name,s.age);
}

int main(){
	struct Student s;
	s.name = "stuart";
	s.age = 18;
	display(s);
	return 0;
}
