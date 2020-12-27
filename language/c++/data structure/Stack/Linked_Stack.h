#ifndef LINKED_STACK_TC_
#define LINKED_STACK_TC_

/** Constructs an empty stack. */
template<typename Item_Type>
  stack<Item_Type>::stack() : top_of_stack(NULL) {}

/** Pushes an item onto the top of the stack.
    @param item The item to be inserted
*/
template<typename Item_Type>
  void stack<Item_Type>::push(const Item_Type& item) 
  {
    top_of_stack = new Node(item, top_of_stack);
  }

/** Returns a reference to the object at the top of the stack 
    without removing it.
    @return A reference to the object at the top of the stack
*/
template<typename Item_Type>
  Item_Type& stack<Item_Type>::top() 
  {
    return top_of_stack->data;
  }

/** Returns a const reference to the object at the
    top of the stack without removing it.
    @return A const reference to the object at the top of the stack
*/
template<typename Item_Type>
  const Item_Type& stack<Item_Type>::top() const 
  {
    return top_of_stack->data;
  }

/** Removes the top item from the stack. */
template<typename Item_Type>
  void stack<Item_Type>::pop()
  {
    Node* old_top = top_of_stack;
    top_of_stack = top_of_stack->next;
    delete old_top;
  }

/** Determines whether the stack is empty. */
template<typename Item_Type>
  bool stack<Item_Type>::empty() const 
  {
    return top_of_stack == NULL;
  }

/** Determines the size of the stack. */
template<typename Item_Type>
  size_t stack<Item_Type>::size() const 
  {
      size_t size = 1;
      Node* point = top_of_stack;
      while(point->next != NULL)
      {
          size += 1;
          point = point->next;
      }
      return size;
  }

#endif
