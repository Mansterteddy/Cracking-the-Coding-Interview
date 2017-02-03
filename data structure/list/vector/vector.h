#ifndef VECTOR__H__
#define VECTOR__H__

#include <stdexcept>
#include <algorithm>

namespace KW
{
    template <typename Item_Type>
    class vector
    {
        private:
            static const size_t INITIAL_CAPACITY = 10;
            size_t current_capacity;
            size_t num_items;
            Item_Type* the_data;

        public:
            vector<Item_Type>() : current_capacity(INITIAL_CAPACITY), num_items(0), the_data(new Item_Type[INITIAL_CAPACITY]){ }

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

            Item_Type& operator[](size_t index)
            {
                if(index >= num_items)
                {
                    throw std::out_of_range("index to operator[] is out of range");
                }
                return the_data[index];
            }

            const Item_Type& operator[](size_t index) const
            {
                if(index >= num_items)
                {
                    throw std::out_of_range("index to operator[] is out of range");
                }
                return the_data[index];
            }

            void push_back(const Item_Type& the_value)
            {
                if(num_items == current_capacity)
                {
                    reserve(2 * current_capacity);
                }

                the_data[num_items] = the_value;
                num_items++;
            }

            void insert(size_t index, const Item_Type& the_value)
            {
                if(index > num_items)
                {
                    throw std::out_of_range("index to insert is out of range");
                }

                if(num_items == current_capacity)
                {
                    reserve(2 * current_capacity);
                }

                for(size_t i = num_items; i > index; i--)
                {
                    the_data[i] = the_data[i - 1];
                }

                the_data[index] = the_value;
                num_items++;
            }   

            void pop_back()
            {
                num_items--;
            }         

            void erase(size_t index)
            {
                if(index >= num_items)
                {
                    throw std::out_of_range("index to erase is out of range");
                }

                for(size_t i = index + 1; i < num_items; i++)
                {
                    the_data[i-1] = the_data[i];
                }
                num_items--;
            }

            size_t size() const
            {
                return num_items;
            }

            bool empty() const
            {
                return num_items == 0;
            }

            size_t capacity() const
            {
                return current_capacity;
            }

            Item_Type& front()
            {
                if(num_items == 0)
                {
                    throw std::out_of_range("Attempt to access ")
                }
                return the_data[0];
            }

            const Item_Type& front() const
            {
                if(num_items == 0)
                    throw std::out_of_range("Attempt to access front of empty vector");
                return the_data[0];
            }

            Item_Type& back()
            {
                if(num_items == 0)
                    throw std::out_of_range("Attempt to access back of empty vector");
                return the_data[num_items - 1];
            }

            const Item_Type& back() const
            {
                if(num_items == 0)
                    throw std::out_of_range("Attempt to access back of empty vector");
                return the_data[num_items - 1];
            }

            void reserve(size_t new_capacity)
            {
                if(new_capacity > current_capacity)
                {
                    if(new_capacity > 2 * current_capacity)
                    {
                        current_capacity = new_capacity;
                    }
                    else
                    {
                        current_capacity *= 2;
                    }
                    Item_Type* new_data = new Item_Type[current_capacity];
                    for(size_t i = 0; i < num_items; ++i)
                    {
                        new_data[i] = the_data[i];
                    }

                    delete[] the_data;

                    the_data = new_data;
                }
            }
    };

    template<typename Item_Type>
        inline void swap(vector<Item_Type>& x, vector<Item_Type>& y)
        {
            x.swap(y);
        }
}


#endif