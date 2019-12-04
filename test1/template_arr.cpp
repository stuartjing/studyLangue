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
	~CArray();
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
	//设置数组的容量
	ptr = new T[arr.size];
	//内存拷贝函数 将之前的数据copy到新的数组中
	memcpy(ptr,arr.ptr,sizeof(T ) * arr.size);
	size = arr.size;
	return;		
}

template<typename T>
CArray<T>::~CArray(){
	if (ptr)
		delete[] ptr;
}
//CArray & operator=(const CArray & c) const;
template<typename T>
CArray<T> & CArray<T>::operator=(const CArray & c) const{
	if ( this == & c)
		return * this;
	if (c.ptr == NULL){
		if (ptr)
			delete[] ptr;
		ptr = NULL;
		size = 0;
		return * this;
	}

	if (size < c.size) {
		if(ptr)
			delete [] ptr;
		ptr = new T[c.size];
	}
	memcpy(ptr,c.ptr,sizeof(T ) * c.size);
        size = c.size;
        return * this;
	
}

template<class T>
void CArray<T>::push_back(const T & v){
	if(ptr){
		T *tmpptr = new T[size+1];
		memcpy(tmpptr,ptr,sizeof(T )*size);
		delete[] ptr;
		ptr = tmpptr;
	}else{
		ptr = new T[1];
	}
	ptr[size++] = v;
}

int main(){
	
	CArray<int> a;
	for(int i =0;i<5;i++){
		a.push_back(i);
	}
	for(int i=0;i<a.length();i++){
		cout << a[i]<<endl;
	}
	return 0;


}
