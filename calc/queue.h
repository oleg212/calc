#pragma once
#define MAXSIZE 200


template <class T>
class myqueue {
	int size;
	T* p;
	int start;
	int end;
private:
	int next(int i) { return (i + 1) % size; }
public:
	myqueue() {
		size = MAXSIZE;
		p = new T[MAXSIZE];
		int end = 0;
		int start = next(end);
	}

	bool empty() { return (end == start); }
	bool full() { return (next(next(end)) == start); }
	T front() {
		if (empty()) {
			throw - 1;
		}
		return p[next(start)];
	}
	int getsize() {
		int sz = 0;
		int ind = start;
		while (ind != end){
			sz++;
			ind = next(ind);
		}
		return sz;
	}
	void push(T a) {
		if (full()) { throw - 1; }
		end = next(end);
		p[end] = a;
	}
	void pop() {
		if (empty()) { throw - 1; }
		start =next(start);
	}
};

//
//template <class T>
//class myqueue
//{
//	int size;
//	const int maxsize = MAXSIZE;
//	T* array;
//public:
//	myqueue() {
//		size = -1;
//		array = new T[maxsize];
//	};
//	~myqueue() {
//		delete[] array;
//
//	}
//	void push(T elem) {
//		size += 1;
//		array[size] = elem;
//	}
//	void pop() {
//		if (size >= 0) {
//			size -= 1;
//		}
//		else {
//			throw("cant pop empty stack");
//		}
//	}
//	bool empty() {
//		if (size == -1) {
//			return true;
//		}
//		return false;
//	}
//	T front() {
//		if (size >= 0) {
//			return(array[0]);
//		}
//		else {
//			throw("stack is empty");
//		}
//	}
//};