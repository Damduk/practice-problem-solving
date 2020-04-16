class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> star;
        
        for (int i = 0; i < s.size(); i++) {
            const char& c = s[i];
            if (c == '*')
                star.push(i);
            else if (c == '(')
                st.push(i);
            else {
                int sz = st.size();
                if (sz > 0) {
                    st.pop();
                    continue;
                }
                
                if (star.size() > 0) {
                    star.pop();
                    continue;
                }
                
                return false;
            } 
        }
        
        while (st.size()) {
            int idx = st.top(); st.pop();
            int starIdx = -1;
            
            while (starIdx < idx) {
                if (star.empty()) {
                    return false;
                }
                
                starIdx = star.top(); star.pop();
            }        
        }
        
        return true;
    }
};