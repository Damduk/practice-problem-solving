#include <iostream>

using namespace std;

int solve(const int& n) {
    if (n < 3) 
        return -1;
    
    return n - 2;
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        int N;
        
        scanf("%d", &N);
        
        printf("%d\n", solve(N));
    }
}