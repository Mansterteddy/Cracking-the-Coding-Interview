#ifndef ORDERED_LIST_H_
#define ORDERED_LIST_H_

#include <list>

template<typename Item_Type>
class Ordered_List 
{
    private:
        std::list<Item_Type> a_list;

    public:
        typedef typename std::list<Item_Type>::const_iterator const_iterator;

        void insert(const Item_Type& an_item)
        {
            typename std::list<Item_Type>::iterator itr = a_list.begin();
            while(itr != a_list.end() && *itr < an_item)
                ++itr;
            a_list.insert(itr, an_item);
        }

        void remove(const Item_Type& item)
        {
            a_list.remove(item);
        }

        const_iterator begin() const
        {
            return a_list.begin();
        }      

        const_iterator end() const
        {
            return a_list.end();
        }

};

#endif