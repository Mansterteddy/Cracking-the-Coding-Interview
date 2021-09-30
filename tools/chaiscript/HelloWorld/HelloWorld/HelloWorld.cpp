// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chaiscript/chaiscript.hpp>

using namespace std;

double helloworld(int i, double j) {
    return i * j;
}

int main()
{
    std::cout << "Hello World!\n";
    chaiscript::ChaiScript chai;
    chai.add(chaiscript::fun(&helloworld), "helloworld");

    double d = chai.eval<double>("helloworld(3, 4.75);");
    cout << "res: " << d << endl;
    return 0;
}
