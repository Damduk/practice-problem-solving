#include <cstdio>

using namespace std;

int m(int n) {
	int result = 0;
	
	while (n) {
		int a = n % 10;
		n /= 10;
		
		result += a;
	}	
	
	return result;
}

int N;

int main(void) {
	int result = -1;
	
	scanf("%d", &N);
	
	for (int i = 1; i < 1000001; i++) {
		if (i + m(i) == N) {
			result = i;
			break;
		}
	}
	
	printf("%d\n", result == -1 ? 0 : result);
	
	return 0;
}
