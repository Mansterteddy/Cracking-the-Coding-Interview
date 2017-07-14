#include "Infix_To_Postfix"
#include <sstream>
#include <cctype>

using std::string;
using std::istringstream;

const string Infix_To_Postfix::OPERATORS = "+-*/()";
const int Infix_To_Postfix::PRECEDENCE[] = {1, 1, 2, 2, -1, -1};

string Infix_To_Postfix::convert(const string& expression)
{
    postfix = "";
    while(!operator_stack.empty())
        operator_stack.pop();

    istringstream infix_tokens(expression);
    string next_token;

    while(infix_tokens>>next_token)
    {
        if(isalnum(next_token[0]))
        {
            postfix += next_token;
            postfix += " ";
        }
        else if(is_operator(next_token[0]))
        {
            process_operator(next_token[0]);
        }
        else
        {
            throw Syntax_Error("Unexpected Charater Encourtered");
        }
    }

    while(!operator_stack.empty())
    {
        char op = operator_stack.top();
        operator_stack.pop();

        if(op == '(')
        {
            throw Syntax_Error("Unmatched open parenthesis");
        }

        postfix += op;
        postfix += " ";
    }

    return postfix;

}

void Infix_To_Postfix::process_operator(char op)
{
    if(opertor_stack.empty() || (op == '('))
    {
        if(op == ')')
        {
            throw Syntax_Error("Unmatched close parenthesis");
        }
        operator_stack.push(op);
    }
    else
    {
        if(precedence(op) > precedence(operator_stack.top()))
        {
            operator_stack.push(op);
        }
        else
        {
            while(!operator_stack.empty() && (operator_stack.top() != '(') 
            && (precedence(op) <= precedence(operator_stack.top())))
            {
                postfix += operator_stack.top();
                postfix += " ";
                operator_stack.pop()
            }

            if(op == ')')
            {
                if(!operator_stack.empty() && (operator_stack.top() == '('))
                {
                    operator_stack.pop();
                }
                else
                {
                    throw Syntax_Error("Unmatched close parentheses");
                }
            }
            else
            {
                operator_stack.push(op);
            }
        }
    }
}