#include <memory>
#include <vector>
#include <iostream>

using namespace std;

int main(){

    vector<unique_ptr<string>> songs;

    songs.push_back(make_unique<string>("a"));
    songs.push_back(make_unique<string>("b"));

    for(const auto& song: songs){
        cout << *song << endl;
    }

    return 0;
}