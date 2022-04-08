#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, std::string> studentMap ={
        {1, "Tom"},
        {2, "Jack"},
        {3, "John"}
    };
    studentMap.insert(pair<int, string>(6, "Tom"));
    studentMap[9] = "Brian";

    // range-based for loop
    
    return 0;
}