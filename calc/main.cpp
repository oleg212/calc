

#include <string>
#include <iostream>
#include "stack.h"
#include "queue.h"
#include "lexema.h"
#include "polish.h"
using namespace std;




int main() {
	string str = "10*(2-3*(14-20))^2-5";
	cout << str<<endl<<endl;
	myqueue <Lexema> lex_res;
	lex_res = lex(str);
	print(lex(str));
	try {
		cout << calc(lex_res) << endl;
	}
	catch(exception) {};
	return 0;
}