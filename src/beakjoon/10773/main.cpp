#include <cstdio>
#include <vector>

using namespace std;

vector<int> v;

int tmp;

int main(void) {
	int K; scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);	
		
		if (tmp == 0 && v.size() > 0) v.pop_back();
		else v.push_back(tmp);
	}
	
	int res = 0;
	for (int i : v) res += i;
	
	printf("%d\n", res);
	return 0;
}