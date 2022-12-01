#pragma once
#include <string>
#include <iostream>
#include "stack.h"
#include "queue.h"
#include "Lexema.h"
#include <cmath>  
using namespace std;

string calc(myqueue <Lexema> q)
{
	string output = "";
	mystack <Lexema> pol;
	Lexema cur("+", Operation);
	myqueue <Lexema> res;

	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.getType() == Value) {
			output += cur.getStr()+" ";
			res.push(cur);
		}
		if ((cur.getStr() == "-") && (output == "") || (cur.getStr() == "-") && (q.front().getType() == Operation) || (cur.getStr() == "(")) {
			if (cur.getStr() == "-") {
				pol.push(Lexema(cur.getStr() + "u", cur.getType()));
			}
			else {
				pol.push(Lexema(cur));
			}
		}
		else {
			if (cur.getStr() == ")") {
				while (pol.top().getStr() != "(") { output += pol.top().getStr() + " ";res.push(pol.top()); pol.pop(); }
				pol.pop();
			}
			else {
				if (cur.getStr() == "^") {
					while ((!pol.empty()) && (pol.top().getStr() == "^")) {
						output += pol.top().getStr() + " ";
							res.push(pol.top());
							pol.pop();
				}
					pol.push(cur);
					
				}
				if ((cur.getStr() == "*") || (cur.getStr() == "/")) {
					while ((!pol.empty()) && ((pol.top().getStr() == "-u") || (pol.top().getStr() == "*") || (pol.top().getStr() == "/")||(pol.top().getStr()=="^"))) {
						output += pol.top().getStr() + " ";
						res.push(pol.top());
						pol.pop();
					}
					pol.push(cur);
				}
				if ((cur.getStr() == "+") || (cur.getStr() == "-")) {
					while ((!pol.empty()) && ((pol.top().getStr() == "-u") || (pol.top().getStr() == "*") || (pol.top().getStr() == "/") || (pol.top().getStr() == "+") || (pol.top().getStr() == "-") || (pol.top().getStr() == "^"))) {
						output += pol.top().getStr() + " ";
						res.push(pol.top());
						pol.pop();
					}
					pol.push(cur);
				}
			}
		}
	}
	while (!pol.empty()) {
		output += pol.top().getStr() + " ";
		res.push(pol.top());
		pol.pop();
	}
	double ans;
	int i = 0;
	mystack <double> counter;
	while (res.size() >= 1) {
		if (res.front().getType() == Value) {
			counter.push(stod(res.front().getStr()));
		}
		else {
			if (res.front().getStr() == "-u") {
				double a = (counter.top());
				counter.pop();
				counter.push(-a);
			}
			else {
				if (res.front().getStr() == "+") {
					double a = (counter.top());
					counter.pop();
					double b = (counter.top());
					counter.pop();
					counter.push(a+b);
				}
				if (res.front().getStr() == "/") {
					double a = (counter.top());
					counter.pop();
					double b = (counter.top());
					counter.pop();
					if (a == 0) {
						throw("cant divide on zero");
						break;
					}
					else {
						counter.push(b / a);
					}
					//counter.push(b / a);
					
				}
				if (res.front().getStr() == "*") {
					double a = (counter.top());
					counter.pop();
					double b = (counter.top());
					counter.pop();
					counter.push(a * b);
				}
				if (res.front().getStr() == "-") {
					double a = (counter.top());
					counter.pop();
					double b = (counter.top());
					counter.pop();
					counter.push(b-a);
				}
				if (res.front().getStr() == "^") {
					double a = (counter.top());
					counter.pop();
					double b = (counter.top());
					counter.pop();
					counter.push(pow(b,a));
				}
			}
		}
		res.pop();
	}
	double d = counter.top();
	//cout << counter.top()<<endl;
	return output+" = " + to_string(d);

}
