#include <iostream>

using namespace std;

int psum[100001];

int main() {
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i <= N; i++) {
        int input;
        
        scanf("%d", &input);
        
        psum[i] = psum[i - 1] + input;
    }
    
    while (M--) {
        int L, R; 
        
        scanf("%d %d", &L, &R);
        
        printf("%d\n", psum[R] - psum[L - 1]);
    }
}