#include <cstdio>
#include <cmath>
#include <cstring>

const int MAX = 10001;
const char* PRIME = "Prime";
const char* NOT_PRIME = "Not Prime";

int is_prime[MAX];

void init(const int& n) {
    memset(is_prime, true, sizeof(is_prime));
    
    int sqrtn = sqrt(n);
    for (int i = 2; i <= sqrtn; i++) {
        if (!is_prime[i]) 
            continue;
        
        for (int j = i + i; j <= n; j += i)        
            is_prime[j] = false;
    }
}

int main() {
    init(MAX);
    
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        int input;
        
        scanf("%d", &input);
        printf("%s\n", is_prime[input] ? PRIME : NOT_PRIME);
    }
}