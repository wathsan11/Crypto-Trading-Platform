#include <string>
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> strings;
    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("Three");

    for(const ::string& s: strings)
    {
        std::cout<<s<<std::endl;
        
    }
}