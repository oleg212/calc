#pragma once


#include <string>
#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

enum TypeElement {
	Operation,
	Value
};

class Lexema {
	string str;
	TypeElement type;
public:
	Lexema() { str = "0";type = Value; };
	Lexema(string _str, TypeElement _type) : str(_str), type(_type) {};
	Lexema(const Lexema& a) {
		str = a.str;
		type = a.type;

	}
	string getStr() { return str; }
	TypeElement getType() { return type; }
	friend ostream& operator << (ostream& out, Lexema& p) {
		out << "{" << p.str << ", ";
		if (p.type == Operation) {
			out << "operation";
		}
		else if (p.type == Value) {
			out << "value";
		};
		out << "}";
		return out;
	}
};

myqueue <Lexema> lex(string input) {
	myqueue<Lexema>res;
	input += ' ';
	int i = 0;
	string tmp = "";
	string op = "+-*/()^";
	string sep = " \n\t";
	int state = 0;
	for (i = 0; i < input.size(); i++) {
		char c = input[i];
		int fres;
		switch (state)
		{
		case 0: // оператор
			if (c >= '0' && c <= '9') {
				tmp = c;
				state = 1;
				break;
			}
			fres = op.find(c);
			if (fres >= 0) {
				tmp = c;
				Lexema l(tmp, Operation);
				res.push(l);
				state = 0;
				break;
			}
			break;
		case 1: // число
			if (c >= '0' && c <= '9') {
				tmp += c;
				state = 1;
				break;
			}
			fres = op.find(c);
			if (fres >= 0) {
				Lexema l1(tmp, Value);
				res.push(l1);
				tmp = c;
				Lexema l2(tmp, Operation);
				res.push(l2);
				state = 0;
				break;
			}
			fres = sep.find(c);
			if (fres >= 0) {
				Lexema l(tmp, Value);
				res.push(l);
				state = 0;
				break;
			}
			break;
		}
	}
	return res;
}

void print(myqueue <Lexema> t) {
	while (!t.empty()) {
		cout << t.front() << endl;
		t.pop();
	}
}

