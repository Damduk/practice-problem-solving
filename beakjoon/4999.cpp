#include <iostream>

using namespace std;

int main() {
    string str1, str2;

    cin >> str1 >> str2;

    if (str1.size() >= str2.size()) 
        printf("go\n");
    else 
        printf("no\n");
}

