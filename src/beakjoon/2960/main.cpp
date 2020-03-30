#include <cstdio>

using namespace std;

int deleted[2000];

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);
    
    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (deleted[i]) continue;
        
        cnt++;
        if (cnt == K) {
            printf("%d\n", i);
            return 0;
        }
        
        for (int j = i + i; j <= N; j += i) {
            if (deleted[j]) continue;
            
            cnt++;
            if (cnt == K) {
                printf("%d\n", j);
                return 0;
            }
                
            deleted[j] = 1;
        }
    }
    
    return 0;
}