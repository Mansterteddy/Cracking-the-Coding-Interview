/*<snippet id="" omit="false">*/
#ifndef STACK_TC_
#define STACK_TC_

/** Construct an initially empty stack. */
template<typename Item_Type>
  stack<Item_Type>::stack() { }

/** Pushes an item onto the top of the stack.
    @param item The item to be inserted
*/
template<typename Item_Type>
  void stack<Item_Type>::push(const Item_Type& item) 
  {
    container.push_back(item);
  }

/** Returns a reference to the object at the top of the stack 
    without removing it.
    @return A reference to the object at the top of the stack
*/
template<typename Item_Type>
  Item_Type& stack<Item_Type>::top() 
  {
    return container.back();
  }

/** Returns a const reference to the object at the 
    top of the stack without removing it.
    @return A const reference to the object at the top of the stack
*/
template<typename Item_Type>
  const Item_Type& stack<Item_Type>::top() const 
  {
    return container.back();
  }

/** Removes the top item from the stack.
 */
template<typename Item_Type>
  void stack<Item_Type>::pop() 
  {
    container.pop_back();
  }

/** Determines whether the stack is empty. */
template<typename Item_Type>
  bool stack<Item_Type>::empty() const 
  {
    return container.empty();
  }

/** Returns the number of items in the stack. */
template<typename Item_Type>
  size_t stack<Item_Type>::size() const 
  {
    return container.size();
  }

#endif
