#include <bits/stdc++.h>



using namespace std;



const int MAX = 22;

const int INF = 2E9;



int N, T;

int S[MAX][MAX];

bool visited[MAX];



int stat(bool t) {

    int ret = 0;



    for (int i = 0; i < N; i++) {

        for (int j = i + 1; j < N; j++) {

            if (visited[i] != t || visited[j] != t) continue;



            ret = ret + S[i][j] + S[j][i];

        }

    }



    return ret;

}



int dfs(int idx, int cnt) {

    visited[idx] = true;



    if (cnt == T) {

        int a = stat(true);

        int b = stat(false);

        int diff = a - b;



        visited[idx] = false;

        return diff < 0 ? -diff : diff;

    }



    if (idx >= N) {

        visited[idx] = false;

        return INF;

    }





    int ret = INF;

    for (int i = idx + 1; i < N; i++) {

        ret = min(ret, dfs(i, cnt + 1));

    }



    visited[idx] = false;



    return ret;

}



int solve() {

    int ret = INF;



    for (int i = 0; i < N; i++) {

        ret = min(ret, dfs(i, 1));

    }



    return ret;

}



int main(void) {

#ifdef LOCAL

    freopen("input.txt", "r", stdin);

#endif

    scanf("%d", &N);

    for (int i = 0; i < N; i++)

        for (int j = 0; j < N; j++)

            scanf("%d", &S[i][j]);



    T = N / 2;

    int sol = solve();



    printf("%d\n", sol);



    return 0;

}
