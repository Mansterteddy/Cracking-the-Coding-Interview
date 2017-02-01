#ifndef VECTOR__H__
#define VECTOR__H__

#include <stdexcept>
#include <algorithm>

namespace KW
{
    template <typename Item_Type>
    class Vector
    {
        private:
            static const size_t INITIAL_CAPACITY = 10;
            size_t current_capacity;
            size_t num_items;
            Item_Type* the_data;
        public:
            vector<Item_Type>() : current_capacity(INITIAL_CAPACITY), num_items(0), the_data(new Item_Type[INITIAL_CAPACITY]){}

            vector<Item_Type>(const vector<Item_Type>& other):
                current_capacity(other.capacity), num_items(other.num_items), the_data(new Item_Type[other.current_capacity])
                {
                    for(size_t i = 0; i < num_items; ++i)
                    {
                        the_data[i] = other.the_data[i];
                    }
                }

            virtual ~vector<Item_Type>()
            {
                delete[] the_data;
            }

            vector<Item_Type>& operator=(const vector<Item_Type>& other)
            {
                vector<Item_Type> the_copy(other);
                swap(the_copy);
                return *this;
            }

            void swap(vector<Item_Type>& other)
            {
                std::swap(num_items, other.num_items);
                std::swap(current_capacity, other.current_capacity);
                std::swap(the_data, other.the_data);
            }
    }
}


#endif