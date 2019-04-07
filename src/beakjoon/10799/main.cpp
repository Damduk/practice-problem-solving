#include <bits/stdc++.h>

using namespace std;

string input;
stack<char> st;
int result;

int main(void) {
    cin >> input;
   
    queue<char> q;

    for (auto& item : input)
        q.push(item);
    
    while (q.size()) {
        char cur = q.front(); q.pop();
        if (cur == '(') {
            char next = q.front();
            if (next == ')') {
                q.pop();

                result += st.size();

                continue;
            }

            st.push(cur);
        } else {
            st.pop();

            result += 1;
        }
    }

    printf("%d\n", result);

    return 0;
}
