#include <string>

using std::string;

int count_occurrences(char c, const string& s)
{
    int count = 0;
    for(size_t i = 0; i < s.size(); i++)
    {
        if(c == s[i])
            count++;
    }
    return count;
}