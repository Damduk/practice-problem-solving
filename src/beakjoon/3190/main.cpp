#include <cstdio>
#include <queue>
#include <deque>

#define NONE 0
#define APPLE 1
#define BODY 2

using namespace std;

typedef pair<int, int> ii;

int N, K, L;
int A[105][105];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, char>> Q;
deque<pair<int, int>> body;

int rotate(int sec, int dir) {
	if (Q.size() && Q.front().first == sec) {
		char cmdDir = Q.front().second; Q.pop();
		if (cmdDir == 'D') {
			return (dir + 1) % 4;
		} else if (cmdDir == 'L') {
			return (dir - 1) < 0 ? 3 : dir - 1;
		}
	}
	
	return dir;
}

bool isEnd(int dir) {
	const ii f = body.front();
	int x = f.first + dx[dir];
	int y = f.second + dy[dir];
	
	int isOut = x < 0 || y < 0 || x >= N || y >= N;
	
	return isOut || A[x][y] == BODY;
}

void proceed(int dir) {
	const ii f = body.front();
	int x = f.first + dx[dir];
	int y = f.second + dy[dir];
	bool hasApple = A[x][y] == APPLE;
	
	A[x][y] = BODY;
	body.push_front({x, y});
	
	if (!hasApple) {
		auto tail = body.back();
		A[tail.first][tail.second] = NONE;
		body.pop_back();
	} 
}

int main(void) {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		int x, y; scanf("%d %d", &x, &y);
		A[y-1][x-1] = APPLE;
	}
	
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		int sec;
		char dir;
		
		scanf("%d %c", &sec, &dir);
		
		Q.push({sec, dir});
	}
	
	body.push_back({0, 0});
	
	int curSec = 0;
	int curDir = 0;
	while (true) {
		curDir = rotate(curSec, curDir);
		curSec = curSec + 1;
		
		if (isEnd(curDir)) {
			break;
		}

		proceed(curDir);
	}
	
	printf("%d\n", curSec);
}