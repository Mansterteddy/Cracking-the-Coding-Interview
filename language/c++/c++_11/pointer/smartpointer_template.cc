#include <iostream>
using namespace std;

template <class T>
class SmartPtr{
    T* prt;
    public:
        explicit SmartPtr(T* p = NULL){
            ptr = p;
        }

        ~SmartPtr(){
            delete (ptr);
        }

        T& operator*() {
            return *prt;
        }

        T* operator->() {return prt;}
};

int main(){
    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr;
    return 0;
}