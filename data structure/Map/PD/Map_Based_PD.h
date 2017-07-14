#ifndef MAP_BASED_PD_H
#define MAP_BASED_PD_H
#include <string>
#include <map>

/** Specification file for the array based phone directory
*/

class Phone_Directory
{
 public:

  /** Construct an empty phone directory
   */
  Phone_Directory();

  /** Destroy the phone directory when it is no longer needed
   */
  ~Phone_Directory();

  /** Load the data file containing the directory, or
      establish a connection with the data source.
      @param source_name The name of the file (data source)
                        with the phone directory entries.
  */
  void load_data(const std::string& source_name);

  /** Look up an entry.
      @param name The name of the person to look up
      @return The number associated with that person
              or an empty string if name is not in
              the directory
  */
  std::string lookup_entry(const std::string& name) const;

  /** Changes the number associated with the given name to
      the new value, or adds a new entry with this name and
      number.
      @param name The name of the person
      @param number The new number 
      @return The old value of number or an empty string
              if this is a new entry
  */
  std::string add_or_change_entry(const std::string& name, 
                                  const std::string& number);

  /** Removes the entry with the specified name from the directory
      @param name The name of the person
      @return The person's name or an empty string if not in
              the directory.
  */
  std::string remove_entry(const std::string& name);

  /** Write the contents of the directory to the data file
   */
  void save();

private:


  /** Map to contain the directory data*/
  std::map<std::string, std::string> the_directory;
  /** An iterator to the directory */
  typedef std::map<std::string, std::string>::iterator iterator;
  /** A const_iterator to the directory */
  typedef std::map<std::string, std::string>::const_iterator 
    const_iterator;
  /** The name of the data file that contains the directory data */
  std::string source_name;
  /** Boolean flag to indicate whether the directory was
      modified since it was either loaded or saved */
  bool modified;
};

#endif
