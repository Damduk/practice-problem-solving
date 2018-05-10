#include <iostream>

using namespace std;

int sum(int x) {
    int result = 0;
    
    while (x) {
        int n = x % 10;
        
        x /= 10;
        
        result += n;
    }
    
    return result;
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        int a, b;
        
        scanf("%d %d", &a, &b);
        
        int result = sum(a) + sum(b);
        
        printf("%d\n", sum(result));
    }
}