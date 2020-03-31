class Solution {
public:
    bool isValid(string s) {
        string open = "([{";
        string close = ")]}";
        
        stack<char> st;
        for (char c : s) {
            if (open.find(c) != -1) {
                st.push(c);
            } else {
                if (st.empty()) 
                    return false;
                
                int openIdx = open.find(st.top());
                int closeIdx = close.find(c);
                if (openIdx != closeIdx)
                    return false;
                
                st.pop();
            }
        }
        
        return st.empty();
    }
};