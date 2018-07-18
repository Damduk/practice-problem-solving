#include <iostream>

using namespace std;

const int MAX = 100002;

int nprime[MAX];

void reserve() {
    nprime[0] = 1;
    nprime[1] = 1;
    
    for (int i = 2; i <= MAX; i++) {
        for (int j = i * 2; j <= MAX; j += i) {
            if (nprime[j])
                continue;
                
            nprime[j] = 1;
        }
    }
}

int part(int a, int b) {
    int result = 0;
    
    for (int i = a; i <= b; i++)
        if (!nprime[i])
            result++;
        
    return result;
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    reserve();
    
    while (TC--) {
        int A, B;
        
        scanf("%d %d", &A, &B);
        printf("%d\n", part(A, B));
    }
}