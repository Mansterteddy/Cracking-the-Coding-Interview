#include "String_Tokenizer.h"
#include <iostream>

using namespace std;
using std::string;

void String_Tokenizer::find_next()
{
    //Find the first character that is not a delimeter
    start = the_source.find_first_not_of(the_delim, end);
    //Find the next delimeter
    end = the_source.find_first_of(the_delim, start);
}

bool String_Tokenizer::has_more_tokens()
{
    return start != string::npos;
}

/**
Retrieve the next token
@return the next token. If there are no more tokens, an empty string is returned.
*/
string String_Tokenizer::next_token()
{
    if(!has_more_tokens())
        return "";
    string token = the_source.substr(start, end - start);

    find_next();

    return token;
}

/*int main()
{
    string person = "Joe, Joghh";
    String_Tokenizer st(person);
    //cout<<st.next_token()<<"h"<<endl;
    //cout<<st.next_token()<<endl;
    //cout入栈顺序是从右往左的，因此输出顺序可能和正常期望的不太一致。
    cout<<st.next_token()<<" "st.next_token()<<endl;
    return 0;
}*/