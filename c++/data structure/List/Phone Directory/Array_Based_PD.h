#ifndef __ARRAY_BASED_PD__H__
#define __ARRAY_BASED_PD__H__
#include <string>

class Phone_Directory
{
    public:
        Phone_Directory();
        ~Phone_Directory();
        void load_data(const std::string& source_name);
        std::string lookup_entry(const std::string& name) const;
        std::string add_or_change_entry(const std::string& name, const std::string& number);
        std::string remove_entry(const std::string& name);
        void save();

    private:
        class Directory_Entry
        {
            public:
                Directory_Entry(std::string _name, std::string _number): name(_name), number(_number) {};
                Directory_Entry(): name(""), number("") {};
                std::string get_name() {return name;}
                std::string get_number(){return number;}
                void set_name(std::string _name){name = _name;}
                void set_number(std::string _number){number = _number;}
            private:
                std::string name;
                std::string number;
        };

        int find(const std::string& name) const;

        void add(const std::string& name, const std::string& number);

        void remove_entry(int index);

        void reallocate();

        int size;

        int capacity;

        Directory_Entry* the_directory;

        std::string source_name;

        bool modified;

};

#endif
