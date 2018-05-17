#include <iostream>
#include <map>

using namespace std;

map<string, char> cached = {
    {"%20", ' '},
    {"%21", '!'},
    {"%24", '$'},
    {"%25", '%'},
    {"%28", '('},
    {"%29", ')'},
    {"%2a", '*'},
};

int main() {
    string str;
    
    cin >> str;
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '%')
            printf("%c", str[i]);
        else {
            string key = str.substr(i, 3);
            
            printf("%c", cached[key]);
            
            i = i + 2;
        }
    }
}