#include "Array_Based_PD.h"
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <iostream>

using namespace std;

Phone_Directory::Phone_Directory():
    size(0), capacity(100), the_directory(new Directory_Entry[100]), source_name("") {}

Phone_Directory::~Phone_Directory()
{
    delete[] the_directory;
}

void Phone_Directory::load_data(const string& source_name)
{
    this->source_name = source_name;

    ifstream in(source_name.c_str());

    if(in)
    {
        string name;
        string number;
        while(getline(in, name))
        {
            if(getline(in, number))
            {
                add(name, number);
            }
        }

        in.close();
    }
}

string Phone_Directory::add_or_change_entry(const string& name, const string& number)
{
    string old_number = "";
    int index = find(name);
    if(index != -1)
    {
        old_number = the_directory[index].get_number();
        the_directory[index].set_number(number);
    }
    else
    {
        add(name, number);
    }

    modified = true;

    return old_number;
}

//声明为const的函数 内部不能使用非const的函数
string Phone_Directory::lookup_entry(const string& name) const
{
    int index = find(name);
    if(index != -1)
    {
        return the_directory[index].get_number();
    }
    else
    {
        return "";
    }
}

void Phone_Directory::save()
{
    if(modified)
    {
        ofstream out(source_name.c_str());

        for(int i = 0; i < size; ++i)
        {
            out<<the_directory[i].get_name()<<"\n";
            out<<the_directory[i].get_number()<<"\n";
        }

        out.close();
        modified = false;
    }
}

string Phone_Directory::remove_entry(const string& name)
{
    int index = find(name);
    if(index != -1)
    {
        string num = the_directory[index].get_number();
        remove_entry(index);
        return num;
    }
    else
    {
        return "";
    }
}

void Phone_Directory::remove_entry(int index)
{
    for(int i = index; i < size - 1; ++i)
    {
        string name = the_directory[i + 1].get_name();
        string number = the_directory[i + 1].get_number();
        the_directory[i] = Directory_Entry(name, number);
    }
    --size;
    modified = true;

}

int Phone_Directory::find(const string& name) const
{
    for(int i = 0; i < size; ++i)
    {
        if(the_directory[i].get_name() == name)
            return i;
    }
    return -1;
}

void Phone_Directory::add(const string& name, const string& number)
{
    if(size == capacity)
        reallocate();
    the_directory[size] = Directory_Entry(name, number);
    size++;
}

void Phone_Directory::reallocate()
{
    capacity *= 2;
    Directory_Entry* new_directory = new Directory_Entry[capacity];

    for(int i = 0; i < size; ++i)
    {
        new_directory[i] = the_directory[i];
    }

    delete[] the_directory;
    
    the_directory = new_directory;
}