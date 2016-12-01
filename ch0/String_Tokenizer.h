#ifndef STRING_TOKENIZER_H
#define STRING_TOKENIZER_H
#include <string>

//The string_tolenizer class splits a string into a sequence of substrings,
//called tokens, separated by delimeters
class String_Tokenizer
{
    public:
        /**
        Construct a string_tokenizer
        @param source The string to be split into tokens
        @param delim The string containing the delimeters. If 
        this parameter is omitted, a space character is assumed
        */
        String_Tokenizer(std::string source, std::string delim = " "):
        the_source(source), the_delim(delim), start(0), end(0)
        {
            find_next();
        }

        /**
        Determine if there are more tokens
        @return true if there are more tokens
        */
        bool has_more_tokens();

        /**
        Retrieve the next token
        @return The next token. If there are no more tokens, an empty string is returned.
        */
        std::string next_token();

    private:
        void find_next();
        std::string the_source;
        std::string the_delim;
        size_t start;
        size_t end;
};

#endif