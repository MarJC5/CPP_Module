#include "RPN.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>

RPN::RPN(const std::string &input) : _input(input), _isError(false), _result(0.0) {}

RPN::~RPN() {}

/*
 * Read each token from the input string
 * If the token is a number, convert it to a double and push it onto the operand stack
 * If the token is an operator (+, -, *, /), pop two operands from the stack, apply the operation and push the result back onto the stack
 * If the token is not a number or an operator, set the error flag
 * If there is only one operand on the stack and no errors were detected, pop it and set it as the result, otherwise set the error flag.
*/

void RPN::do_operation(const std::string& op) {
	double operand2 = _operands.top();
	_operands.pop();
	double operand1 = _operands.top();
	_operands.pop();

	switch(op[0]) {
		case '+':
			_operands.push(operand1 + operand2);
			break;
		case '-':
			_operands.push(operand1 - operand2);
			break;
		case '*':
			_operands.push(operand1 * operand2);
			break;
		case '/':
			if (operand2 == 0.0) {
				_isError = true;
				std::cerr << "Error: division by zero." << std::endl;
				return;
			}
			_operands.push(operand1 / operand2);
			break;
		default:
			_isError = true;
			std::cerr << "Error: unknown operator '" << op << "'." << std::endl;
			break;
	}
}

void RPN::evaluate() {
	std::istringstream iss(_input);
	std::string token;

	while (iss >> token) {
		if (isdigit(token[0])) {
			double operand = std::atof(token.c_str());
			_operands.push(operand);
		} else if (token == "+" || token == "-" || token == "*" || token == "/") {
			if (_operands.size() < 2) {
				_isError = true;
				std::cerr << "Error: not enough operands for " << token << " operation." << std::endl;
				break;
			}
			do_operation(token);
		} else {
			_isError = true;
			std::cerr << "Error: unknown token '" << token << "'." << std::endl;
			break;
		}
	}

	if (_operands.size() == 1 && !_isError) {
		_result = _operands.top();
		_operands.pop();
	} else {
		_isError = true;
		std::cerr << "Error: invalid expression." << std::endl;
	}
}

double RPN::getResult() const {
	return _result;
}

bool RPN::isError() const {
	return _isError;
}
