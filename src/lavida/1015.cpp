#include <iostream>

using namespace std;

int N;

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        scanf("%d", &N);
        
        int day = 0;
        
        while (N != 1) {
            if (N & 1)
                N = N * 3 + 1;
            else 
                N /= 2;
            
            day++;
        }
        
        printf("%d\n", day);
    }
}