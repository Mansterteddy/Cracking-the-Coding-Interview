/** Program to test the postfix evaluator */

#include "Postfix_Evaluator.h"
#include <iostream>
#include <string>
using namespace std;

int main() 
{
  Postfix_Evaluator postfix_evaluator;
  cout << "Enter expressions to be evaluated\n";
  string expression;
  while (getline(cin, expression)) {
    try {
      int result = postfix_evaluator.eval(expression);
      cout << "== " << result << endl;
    } catch (Syntax_Error ex) {
      cout << "Syntax Error: " << ex.what() << endl;
    }
  }
}
