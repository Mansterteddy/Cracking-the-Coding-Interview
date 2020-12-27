/** Implementation of Infix_To_Postfix. */

#include "Infix_To_Postfix.h"
#include <sstream>
#include <cctype>
using std::string;
using std::istringstream;

const string Infix_To_Postfix::OPERATORS = "+-*/";
const int Infix_To_Postfix::PRECEDENCE[] = { 1, 1, 2, 2 };

/** Extracts and processes each token in infix and returns the
    equivalent postfix string.
    @param expression The infix expression
    @return The equivalent postfix expression
    @throws Syntax_Error
*/
string Infix_To_Postfix::convert(const string& expression) {
  postfix = "";
  while (!operator_stack.empty())
    operator_stack.pop();
  istringstream infix_tokens(expression);
  string next_token;
  while(infix_tokens >> next_token) {
    if (isalnum(next_token[0])) {
      postfix += next_token;
      postfix += " ";
    } else if (is_operator(next_token[0])) {
      process_operator(next_token[0]);
    } else {
      throw Syntax_Error("Unexpected Character Encountered");
    }
  } // End while
  // Pop any remaining operators and append them to postfix
  while (!operator_stack.empty()) {
    char op = operator_stack.top();
    operator_stack.pop();
    postfix += op;
    postfix += " ";
  }
  return postfix;
}

/** Function to process operators.
    @param op The operator
    @throws Syntax_Error
*/
void Infix_To_Postfix::process_operator(char op) {
  if (operator_stack.empty()) {
    operator_stack.push(op);
  } else {
    if (precedence(op) > precedence(operator_stack.top())) {
      operator_stack.push(op);
    } else {
      // Pop all stacked operators with equal
      // or higher precedence than op.
      while (!operator_stack.empty() 
             && (precedence(op) <= precedence(operator_stack.top()))) {
        postfix += operator_stack.top();
        postfix += " ";
        operator_stack.pop();
      }
      // assert: Operator stack is empty or current
      //         operator precedence > top of stack operator
      //         precedence;
      operator_stack.push(op);
    }
  }
}
