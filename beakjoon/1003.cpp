#include <cstdio>
#define MAX 41

int call_cnt[MAX][2];

void init() {
    call_cnt[0][0] = call_cnt[1][1] = 1;
    
    for (int i = 2; i < MAX; i++) {
        call_cnt[i][0] = call_cnt[i - 1][0] + call_cnt[i - 2][0];
        call_cnt[i][1] = call_cnt[i - 1][1] + call_cnt[i - 2][1];
    }
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    init();
    
    while (TC--) {
        int n;
        
        scanf("%d", &n);
        printf("%d %d\n", call_cnt[n][0], call_cnt[n][1]);
    }
}