#ifndef STACK_H_
#define STACK_H_

#ifndef USELIST
#define USELIST
#endif 

/** Definition file for class KW::stack */
// Include directives needed by the implementation
#include <stdexcept>
#ifdef USELIST
#include <cstddef>
#else
#include <vector>
#endif
#include <algorithm>
#include <string>
#include <sstream>

namespace KW 
{
  /** A stack is a data structure that provides last-in first-out
      access to the items that are stored in it. Only the most recently
      inserted item is accessible.
  */
  template<typename Item_Type>
  class stack 
  {
    
    public:
      // Constructor and member functions

      /** Constructs an initially empty stack. */
      stack();

      /** Pushes an item onto the top of the stack.
          @param item The item to be inserted
      */
      void push(const Item_Type& item);

      /** Returns a reference to the object at the top of the stack 
          without removing it.
          @return A reference to the object at the top of the stack
      */
      Item_Type& top();

      /** Returns a const reference to the object at the at the 
          top of the stack without removing it.
          @return A const reference to the object at the top of the stack
      */
      const Item_Type& top() const;

      /** Removes the top item from the stack. */
      void pop();

      /** Determines whether the stack is empty. */
      bool empty() const;

      /** Returns the number of items in the stack. */
      size_t size() const;

    private:
      // Data fields
        #ifdef USELIST
      // Insert definition of node here
            #include "Node.h"
      /** A pointer to the top of the stack */
            Node* top_of_stack;
      
        #else
      /** A sequential container to contain the stack items */
            std::vector<Item_Type> container;
        #endif
      
  }; // End class stack

  // Insert implementation of member functions here
#ifdef USELIST
#include "Linked_Stack.h"
#else
#include "stack_1.h"
#endif

} // End namespace KW
#endif
