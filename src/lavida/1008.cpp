#include <iostream>

using namespace std;

string solve(const string& str) {
    string result;
    
    for (int i = 0; i < str.size(); i += 2) 
        result += str[i];
    
    for (int i = 1; i < str.size(); i += 2) 
        result += str[i];
    
    return result;
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        string str;
        
        cin >> str;
        cout << solve(str) << "\n";
    }
}