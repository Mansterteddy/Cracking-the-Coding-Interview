#include <string>
#include <iostream>
#include <cassert>
#include "String_Tokenizer.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    //Create a string tokenizer
    string person_data = "Doe, John 5/15/65";
    String_Tokenizer st(person_data, " ,/");

    string family_name = st.next_token();
    string given_name = st.next_token();
    string month = st.next_token();
    string day = st.next_token();
    string year = st.next_token();

    assert(family_name == "Doe");
    assert(given_name == "John");
    assert(month == "5");
    assert(day == "15");
    assert(year == "65");

    string sentence = "This is a set of seven tokens";
    String_Tokenizer get_words(sentence);

    while(get_words.has_more_tokens())
        cout<<get_words.next_token()<<endl;

    return 0;
}