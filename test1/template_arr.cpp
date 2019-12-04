#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class CArray{

	int size;//数组长度
	T *ptr;//数组指针
public:
	CArray(int s = 0);
	CArray(CArray & arr);
	~Carray();
	void push_back(const T & v);//增加元素
	CArray & operator=(const CArray & c) const;
	T length(){ return size;}
	T & operator[](int i){
		return ptr[i];
	}	
};

template<typename T>
CArray<T>::CArray(int s):size(s){
	if(s == 0)
		ptr = NULL;
	else
		ptr = new T[s];
}

template<class T>
CArray<T>::CArray(CArray & arr){
	if(!arr.ptr){
		ptr = NULL;
		size = 0;
		return;	
	}
	ptr = new T[arr.size];
	//内存拷贝函数
	memcpy(ptr,arr.ptr,sizeof(T ) * arr.size);
	size = arr.size;
	return;	
	
}

