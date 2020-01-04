#include <cstdio>

using namespace std;

int main(void) {
    int sum = 0;
    
    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int ele; scanf("%d", &ele);
        sum += ele;
    }
    
    int res = sum - (N - 1);
    
    printf("%d\n", res);
    
    return 0;
}