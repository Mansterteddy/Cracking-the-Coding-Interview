#ifndef FIND__H__
#define FIND__H__

#include <list>

namespace KW
{
    template<typename Container>
    typename Container::iterator find(Container cont, typename Container::const_reference target)
    {
        typename Container::iterator iter = cont.begin();
        while(iter != cont.end())
        {
            if(*iter == target)
                return iter;
            ++iter;
        }
        return iter;
    }

    template <typename iterator, typename Target>
    iterator find(iterator first, iterator last, const Target& target)
    {
        while(first != last)
        {
            if(*first == target)
                return first;
            ++first;
        }
        return first;
    }

    template <typename iterator, typename Pred>
    iterator find_if(iterator first, iterator last, Pred pred)
    {
        while(first != last)
        {
            if(pred(*first))
                return first;
            else 
                ++first;
        }
        return first;
    }
}

#endif