/** Implementation of the Phone_Directory using an map
    @author Koffman and Wolfgang
*/

#include "Map_Based_PD.h"
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
}

#ifndef ALT
/** Add an entry or change an existing entry.
    @param name The name of the person being added or changed
    @param number The new number to be assigned
    @return The old number or, if a new entry, an empty string
*/
string Phone_Directory::add_or_change_entry(
    const string& name, const string& number) {
  string old_number = the_directory[name];
  the_directory[name] = number;
  modified = true;
  return old_number;
}
#else
/** Add an entry or change an existing entry.
    @param name The name of the person being added or changed
    @param number The new number to be assigned
    @return The old number or, if a new entry, an empty string
*/
string Phone_Directory::add_or_change_entry(
    const string& name, const string& number) {
  string old_number = "";
  pair<iterator, bool> ret = 
    the_directory.insert(pair<string, string>(name, number));
  if (!ret.second) { // Name already in the directory
    old_number = ret.first->second;
    ret.first->second = number;
  }
  modified = true;
  return old_number;
}
#endif
/** Look up an entry.
    @param name The name of the person
    @return The number. If not in the directory, an empty string
*/
string Phone_Directory::lookup_entry(const string& name) const
{
  const_iterator itr = the_directory.find(name);
  if (itr != the_directory.end())
    return itr->second;
  else
    return "";
}

/** Method to save the directory
    pre:  The directory has been loaded with data
    post: Contents of directory written back to the file in the
          form of name-number pairs on adjacent lines.
          modified is reset to false.
*/
void Phone_Directory::save()
{
}

/** Remove an entry
    post: The name is no longer in the directory
    @param name The name to be removed
    @return That person's number or an empty string
            if not in the directory
*/
string Phone_Directory::remove_entry(const string& name)
{
  string old_number = the_directory[name];
  the_directory.erase(name);
  modified = old_number != string();
  return old_number;
}

