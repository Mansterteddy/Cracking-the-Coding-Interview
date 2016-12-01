#include <iostream>
#include <sstream>
#include <string>
#include "String_Tokenizer.h"

using std::string;
using std::istringstream;
using std::ostringstream;
using std::cout;
using std::endl;

int main()
{
    string person_data = "Doe, Hogh 5/15/65";
    string person_data2 = "Roe, Jane 9/25/66";

    istringstream in(person_data);

    string family_name, given_name;
    in>>family_name>>given_name; 

    int month, day, year;
    char c;

    in>>month;
    in>>c;
    in>>day;
    in>>c;
    in>>year;

    cout<<"family_name: "<<family_name<<endl;
    cout<<"given_name: "<<given_name<<endl;
    cout<<"month: "<<month<<endl;
    cout<<"day: "<<day<<endl;
    cout<<"year: "<<year<<endl;

    String_Tokenizer st(person_data2, " ,/");
    family_name = st.next_token();
    given_name = st.next_token();
    string s_month = st.next_token();
    string s_day = st.next_token();
    string s_year = st.next_token();

    istringstream(s_month)>>month;
    istringstream(s_day)>>day;
    istringstream(s_year)>>year;

    cout<<"family_name: "<<family_name<<endl;
    cout<<"given_name: "<<given_name<<endl;
    cout<<"month: "<<month<<endl;
    cout<<"day: "<<day<<endl;
    cout<<"year: "<<year<<endl;

    ostringstream out;
    out<<family_name<<", "<<given_name<<' '<<month<<'/'<<day<<'/'<<year;
    string person_data3 = out.str();
    cout<<person_data3;
    return 0;

}