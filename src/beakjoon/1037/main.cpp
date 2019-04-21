#include <bits/stdc++.h>

using namespace std;

int N;

int main(void) {
    int mini, maxi;
    int input;

    mini = 1000005;
    maxi = 0;

    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &input);    

        mini = min(mini, input);
        maxi = max(maxi, input);
    }
    
    printf("%d\n", mini * maxi);

    return 0;
}
