#include <cstdio>
using namespace std;

int m[5][10];
int buf[8];
int arr[4] = { 1, 2, 4, 8 };
int N;

int twelveOclock(int pos) {
    return m[pos][0];
}

int threeOclock(int pos) {
    return m[pos][2];
}

int nineOclock(int pos) {
    return m[pos][6];
}

void query(int pos, int d, int prev) {
    int left = pos - 1;
    if (left >= 0 && prev != left && threeOclock(left) != nineOclock(pos))
        query(left, -d, pos);

    int right = pos + 1;
    if (right < 4 && prev != right && threeOclock(pos) != nineOclock(right))
        query(right, -d, pos);

    for (int i = 0; i < 8; i++)
        buf[i] = m[pos][i];
    
    if (d == 1) {
        for (int i = 0; i < 7; i++)
            m[pos][i + 1] = buf[i];
            
        m[pos][0] = buf[7];
    } else {
        for (int i = 1; i <= 7; i++)
            m[pos][i - 1] = buf[i];

        m[pos][7] = buf[0];
    }
}

int main(void) {
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 8; j++)
            scanf("%1d", &m[i][j]);
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int a, b; 
        scanf("%d %d", &a, &b);
        query(a - 1, b, 2E9);
    }
   
    int res = 0;
    for (int i = 0; i < 4; i++) 
        if (twelveOclock(i))
            res += arr[i];
    
    printf("%d\n", res);
    return 0;
}