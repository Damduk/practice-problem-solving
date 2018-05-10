#include <iostream>
#include <stack>

using namespace std;

int get_convert(int n) {    
    stack<int> st;
    
    while (n) {
        int a = n % 10;
        n /= 10;
        
        st.push(a);
    }
    
    int mux = 1;
    int result = 0;
    
    while (st.size()) {
        int num = st.top() * mux;
        
        st.pop();
        
        result += num;
        
        mux *= 10;
    }
    
    return result;
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while(TC--) {
        int N;
        
        scanf("%d", &N);
        
        int convert = get_convert(N);
        
        printf("%d\n", N > convert ? N : convert);
    }
}