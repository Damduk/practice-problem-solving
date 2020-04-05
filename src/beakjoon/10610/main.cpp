#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

string str;

int main(void) {
    cin >> str;
    
    long long sum = 0;
    bool hasZero = false;
    for (char c : str) {
        int n = c - '0';
        sum += n;
        
        if (n == 0)
            hasZero = true;
    }
    
    sort(str.begin(), str.end(), greater<char>());
    
    printf("%s\n", (sum % 3 == 0 && hasZero) ? str.c_str() : "-1");
}