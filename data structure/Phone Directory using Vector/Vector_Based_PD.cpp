/** Implementation of the Phone_Directory using an array
    of entries
    @author Koffman and Wolfgang
*/

#include "Vector_Based_PD.h"
#include <string>
#include <fstream>
#include <istream>
#include <ostream>

using namespace std;

/** Construct an empty Phone_Directory
 */
Phone_Directory::Phone_Directory(): source_name("") {}

/** Destroy the Phone_Directory
 */
Phone_Directory::~Phone_Directory()
{
}

/** Function to load the data file.
    pre:  The directory storage has been created and it is empty
          If the file exists, it consists of the name-number pairs
          on adjacent lines.
    post: The data from the file is loaded into the directory.
    @param source_name The name of the data file
*/
void Phone_Directory::load_data(const string& source_name)
{
  // Remember the source name for use by save
  this->source_name = source_name;
  // Create an input stream for this file
  ifstream in(source_name.c_str());
  if (in) 
  { // Stream exists
    string name;
    string number;
    while (getline(in, name)) 
    {
      if (getline(in, number)) 
      {
        add(name, number);
      }
    }
    // close the file
    in.close();
  }
}

/** Add an entry or change an existing entry.
    @param name The name of the person being added or changed
    @param number The new number to be assigned
    @return The old number or, if a new entry, an empty string
*/
string Phone_Directory::add_or_change_entry(const string& name,
					    const string& number)
{
  string old_number = "";
  int index = find(name);
  if (index != -1) 
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

/** Look up an entry
    @param name The name of the person
    @return The number. If not in the directory, an empty string
*/
string Phone_Directory::lookup_entry(const string& name) const
{
  int index = find(name);
  if(index == -1) return "";
  return the_directory[index].get_number();
}

/** Method to save the directory
    pre:  The directory has been loaded with data
    post: Contents of directory written back to the file in the
          form of name-number pairs on adjacent lines.
          modified is reset to false.
*/
void Phone_Directory::save()
{
  if(modified == true)
  {
    ofstream out(source_name.c_str());
    for(int i = 0; i < the_directory.size(); ++i)
    {
      out<<the_directory[i].get_name()<<"\n";
      out<<the_directory[i].get_number()<<"\n";
    }
    out.close();
    modified = false;
  }
}

/** Remove an entry
    post: The name is no longer in the directory
    @param name The name to be removed
    @return That person's number or an empty string
            if not in the directory
*/
string Phone_Directory::remove_entry(const string& name)
{
  string old_number = "";
  int index = find(name);
  if(index == -1)
  {
    return old_number;
  }
  else
  {
    old_number = the_directory[index].get_number();
    modified = true;
    the_directory.erase(the_directory.begin() + index);
    return old_number;
  }
}

// Private method implementation

/** Search the array for a given name
    @param name The name to be found
    @return The index of the entry containing this name
            or -1 if the name is not present
*/
int Phone_Directory::find(const string& name)const
{
  for (size_t i = 0; i < the_directory.size(); i++) 
  {
    if (the_directory[i].get_name() == name)
      return i;
  }
  return -1;
}
/** Add a new name-number pair to the directory
    @param name The name to be added
    @param number The numer to be added
*/
void Phone_Directory::add(const string& name, 
			  const string& number)
{
  the_directory.push_back(Directory_Entry(name, number));
}
