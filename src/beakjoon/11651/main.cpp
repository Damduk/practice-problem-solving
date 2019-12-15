#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

pii arr[100005];

int main(void) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].second, &arr[i].first);
	}
	
	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].second, arr[i].first);
	}
	
	return 0;
}