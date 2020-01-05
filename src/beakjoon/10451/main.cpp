#include <cstdio>
#include <cstring>

int N;
int visited[1005];
int adj[1005];

void dfs(int node) {
	visited[node] = true;
	
	int next = adj[node];
	if (!visited[next]) {
		dfs(next);
	}
}

int main(void) {
	int TC; scanf("%d", &TC);
	while (TC--) {
		memset(visited, 0, sizeof(visited));
		
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) 
			scanf("%d", &adj[i]);
			
		int res = 0;
		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;
			
			dfs(i);
			
			res = res + 1;
		}
		
		printf("%d\n", res);
	}
}