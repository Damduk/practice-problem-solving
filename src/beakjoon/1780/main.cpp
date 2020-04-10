#include <cstdio>

using namespace std;

int N;
int A[2200][2200];
int res[3];

bool same(int x, int y, int sz) {
    int v = A[y][x];
    
    int ysz = y + sz;
    int xsz = x + sz;
    for (int i = y; i < ysz; i++)
        for (int j = x; j < xsz; j++) 
            if (A[i][j] != v)
                return false;
        
    return true;
}

void divide(int x, int y, int sz) {
    if (sz == 1 || same(x, y, sz)) {
        int v = A[y][x];
        res[v + 1]++;
    } else {
        int nsz = sz / 3;
        
        int ysz = y + sz;
        int xsz = x + sz;
        for (int i = y; i < ysz; i += nsz)
            for (int j = x; j < xsz; j += nsz)
                divide(j, i, nsz);
    }
}

int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
            scanf("%d", &A[i][j]);
    
    divide(0, 0, N);
    
    printf("%d\n%d\n%d\n", res[0], res[1], res[2]);
    
    return 0;
}