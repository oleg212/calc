#pragma once
#define MAXSIZE 200

template <class T>
class mystack
{
	int size;
	const int maxsize = MAXSIZE;
	T  *array;
public:
	mystack() {
		size = -1;
		array = new T[maxsize];
	};
	~mystack() {
		delete[] array;
	}
	void push(T elem) {
		size += 1;
		array[size] = elem;
	}
	void pop() {
		if (size >= 0) {
			size -= 1;
		}
		else {
			throw("cant pop empty stack");
		}
	}
	bool empty() {
		if (size == -1) {
			return true;
		}
		return false;
	}
	int getsize() {
		return (size + 1);
	}
	T top() {
		if (size >= 0) {
			return(array[size]);
		}
		else {
			throw("stack is empty");
		}
	}
};
