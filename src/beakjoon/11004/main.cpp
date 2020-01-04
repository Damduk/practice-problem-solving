#include <cstdio>
#include <algorithm>
#define MAX 5000005
using namespace std;

int N, K;
int A[MAX];

int main(void) {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) 
		scanf("%d", &A[i]);
		
	sort(A, A + N);
	
	printf("%d\n", A[K - 1]);
	
	return 0;
}