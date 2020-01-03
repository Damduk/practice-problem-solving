#include <cstdio>
#include <vector>

using namespace std;

int N;
int visited[10];

vector<vector<int>> arr;

void dfs(vector<int> v) {
	if (v.size() == N) {
		arr.push_back(v);
		return;
	}
	
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		
		visited[i] = true;
		v.push_back(i);
		dfs(v);	
		v.pop_back();
		visited[i] = false;
	}
}

int main(void) {
	scanf("%d", &N);
	
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		visited[i] = true;
		v.push_back(i);
		dfs(v);
		v.pop_back();
		visited[i] = false;
	}
	
	for (auto item : arr) {
		for (int node : item) {
			printf("%d ", node);
		}
		
		printf("\n");
	}
}