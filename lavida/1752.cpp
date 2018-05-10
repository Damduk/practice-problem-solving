#include <iostream>

using namespace std;

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        int N;
        
        scanf("%d", &N);
        
        int result = 1;
        
        for (int i = 1; i <= N; i++) {
            if (result % i == 0)
                result /= i;
            else
                result *= i;
        }
        
        printf("%d\n", result);
    }
}