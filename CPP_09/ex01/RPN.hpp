#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

/*
 * Stack allows to store operands and perform operations on them.
 * The stack is implemented as a linked list of nodes.
 * Each node contains a value and a pointer to the next node.
 * The stack is empty when the pointer to the top node is null.
 */

class RPN {
	public:
		RPN(const std::string& input);
		virtual ~RPN();

		double getResult() const;

		void do_operation(const std::string& op);
		void evaluate();
		bool isError() const;

	private:
		RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& rhs);

		std::string         _input;
		std::stack<double>  _operands;
		bool                _isError;
		double              _result;
};

#endif
