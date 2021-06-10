#pragma once
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include "InitiumMath.hpp"

using namespace std;

struct oper { int p; string o; };
stack<int> num; stack<oper> op;

void calc() {
	int a, b, result;
	b = num.top(); num.pop();
	a = num.top(); num.pop();
	string oper = op.top().o; op.pop();

	if      (oper == "^") result = pow(a, b);
	else if (oper == "*") result = a * b;
	else if (oper == "/") result = a / b;
	else if (oper == "+") result = a + b;
	else if (oper == "-") result = a - b;
	num.push(result);
}

long double calculate(string expression) {
	stringstream ss(expression); string token;

	while (ss >> token) {
		if (token == "(") op.push({ 0, token });
		else if (token == ")") { while (op.top().o != "(") calc(); op.pop(); } 
		else if (token == "^" || token == "*" || token == "/" || token == "+" || token == "-") {
			short priority = 0;
			if      (token == "^") priority = 3;
			else if (token == "*") priority = 2;
			else if (token == "/") priority = 2;
			else if (token == "+") priority = 1;
			else if (token == "-") priority = 1;

			while (!op.empty() && priority <= op.top().p) calc();
			op.push({ priority, token });
		} else num.push(stoi(token));
	}
	while (!op.empty()) calc();
	return num.top();
}
