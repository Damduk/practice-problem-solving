#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int A[51], B[51];
int N;

int main() {
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    
    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);
    
    int result = 0;
    
    sort(A, A + N, less<int>());
    sort(B, B + N, greater<int>());
    
    for (int i = 0; i < N; i++)
        result += A[i] * B[i];
    
    printf("%d\n", result);
}