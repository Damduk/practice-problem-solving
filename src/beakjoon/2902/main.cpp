#include <bits/stdc++.h>

using namespace std;

string input;
queue<char> q;

int main(void) {
    cin >> input;
    
    for (int i = 0; i < input.size(); i++) {
        if (i == 0) {
            q.push(input[i]);   
        } else if (input[i] == '-') {
            q.push(input[i + 1]);   
        }
    }
    
    while (q.size()) {
        char top = q.front(); q.pop();
        
        printf("%c", top);
    }
    
    return 0;
}
