#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 10
#define INF 2E9

using namespace std;

int N;
int A[MAX + 3];
int visited[MAX + 3];
int stamp[MAX + 3];

vector<int> adj[MAX + 3];

int minIdx(int visit) {
	int res = -1;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == visit) {
			res = i;
			break;
		}
	}
	
	return res;
}

int connected() {
	memset(stamp, 0, sizeof(stamp));
	
	int a = minIdx(0);
	int b = minIdx(1);
	if (a == -1 || b == -1) {
		return 0;
	}
	
	queue<int> q;
	q.push(a);
	q.push(b);
	
	int visit = 0;
	while (q.size()) {
		int front = q.front(); q.pop();
		if (stamp[front]) {
			continue;
		}
		
		stamp[front] = 1;
		visit++;
		
		for (int next : adj[front]) {
			if (!stamp[next] && visited[front] == visited[next]) {
				q.push(next);
			}
		}
	}
	
	return visit == N;
}

int abs(int x) {
	return x < 0 ? -x : x;
} 

int diff() {
	int v[2] = { 0, 0 };
	for (int i = 1; i <= N; i++) {
		int idx = visited[i];
		v[idx] += A[i];	
	}
	
	return abs(v[0] - v[1]);
}

int backtracking(int idx) {
	visited[idx] = 1;
	
	int res = connected() ? diff() : INF;
	for (int next = idx + 1; next <= N; next++) {
		if (!visited[next]) {
			res = min(res, backtracking(next));
		}
	}
	
	visited[idx] = 0;
	
	return res;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);
		
	for (int from = 1; from <= N; from++) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int to; scanf("%d", &to);
			adj[from].push_back(to);
		}
	}
	
	int res = INF;
	for (int i = 1; i <= N; i++) {
		res = min(res, backtracking(i));
	}
	
	printf("%d\n", res == INF ? -1 : res);
	
	return 0;
}