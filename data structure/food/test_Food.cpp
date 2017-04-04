#include "Vegetable.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    Food* my_snack = new Vegetable("carrot sticks");

    cout<<"My Snack is "<<my_snack->percent_fat()<< "percent fat\n";
    cout<<"My Snack is "<<my_snack->percent_carbohydrates()<<" percent carbohydrates\n";
    cout<<"My Snack is "<<my_snack->percent_protein()<<" percent protein\n";

    return 0;
}