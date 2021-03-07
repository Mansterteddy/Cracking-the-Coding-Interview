#include <memory>
#include <iostream>

using namespace std;

void foo(std::shared_ptr<int> i){
    (*i)++;
}

int main(){

    auto pointer = make_shared<int>(10);
    foo(pointer);
    cout << *pointer << endl;

    auto pointer_1 = make_shared<int>(10);
    auto pointer_2 = pointer_1;
    auto pointer_3 = pointer_1;

    int* p = pointer_1.get();

    cout << "pointer_1 use count: " << pointer_1.use_count() << endl;
    cout << "pointer_2 use count: " << pointer_2.use_count() << endl;
    cout << "pointer_3 use count: " << pointer_3.use_count() << endl;

    pointer_2.reset();
    cout << "reset pointer_2: " << endl;
    cout << "pointer_1 use count: " << pointer_1.use_count() << endl;
    cout << "pointer 2 use count: " << pointer_2.use_count() << endl;
    cout << "pointer_3 use count: " << pointer_3.use_count() << endl;

    pointer_3.reset();
    cout << "reset pointer_3: " << endl;
    cout << "pointer_1 use count: " << pointer_1.use_count() << endl;
    cout << "pointer 2 use count: " << pointer_2.use_count() << endl;
    cout << "pointer_3 use count: " << pointer_3.use_count() << endl;
    
    return 0;
}