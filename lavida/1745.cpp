#include <iostream>

using namespace std;

int main() {
    int N, M;
    
    while (true) {
        scanf("%d %d", &N, &M);
        
        if (N == 0 && M == 0)
            break;
        
        if (N % M == 0)
            printf("multiple\n");
        else 
            printf("%d\n", N % M);
    }
}