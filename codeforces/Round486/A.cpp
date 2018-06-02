#include <iostream>
#include <vector>

using namespace std;

int u[101];
int N, K;

int main() {
    freopen("A.in", "r", stdin);
    
    scanf("%d %d", &N, &K);

    vector<int> vec;
    int result = 0;

    for (int i = 0; i < N; i++) { 
        if (result == K)
            break;
        
        int X;
        
        scanf("%d", &X);

        if (u[X] == 0) {
            u[X] = 1;

            result++;

            vec.push_back(i + 1);
        }
    }

    if (result != K)
        printf("NO\n");
    else {
        printf("YES\n");

        for (auto& item : vec) 
            printf("%d ", item);
    }
}
