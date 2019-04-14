#include <iostream>
#include <queue>
#include <cstring>

#define EMPTY -1
#define READY 0
#define DONE 1
#define TEMP 2

using namespace std;

int N, M, H;
int board[105][105][105];
int remain;
int day;

int d[6][3] = {
    { 1, 0, 0 }, // UP
    { -1, 0, 0 }, // DOWN
    { 0, 1, 0 }, // RIGHT
    { 0, -1, 0 }, // LEFT
    { 0, 0, 1 }, // FRONT
    { 0, 0, -1 } // BACK
};

typedef struct tomato {
    int x, y, z;
    int day;
} Tomato;

queue<Tomato> q;

int main(void) {
    freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &N, &M, &H);
    
    memset(board, -1, sizeof(board));

    for (int z = 1; z <= H; z++) {
        for (int y = 1; y <= M; y++) {
            for (int x = 1; x <= N; x++) {
                scanf("%d", &board[x][y][z]);

                if (board[x][y][z] == READY)
                    remain++;
                else if (board[x][y][z] == DONE)
                    q.push({x, y, z, 1});
            }
        }
    }
    
    while (remain > 0 && q.size()) {
        Tomato cur = q.front(); q.pop();
        
        board[cur.x][cur.y][cur.z] = DONE;

        for (int i = 0; i < 6; i++) {
            Tomato next = {cur.x + d[i][1], cur.y + d[i][2], cur.z + d[i][0], cur.day + 1};

            if (board[next.x][next.y][next.z] == READY) {
                board[next.x][next.y][next.z] = TEMP;
                q.push(next);

                remain--;
            }
        }

        day = max(day, cur.day);
    }

    printf("%d\n", remain <= 0 ? day : -1);

    return 0;
}
