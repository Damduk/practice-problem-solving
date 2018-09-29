#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> marr;
vector<int> parr;

int N;
int in;

int solve() {
    int result = -1;
    
    if (parr.size() > 2) {
        result = max(result, parr[0] * parr[1] * parr[2]);
    }

    if (parr.size() > 1) {
        result = max(result, parr[0] * parr[1]);

        if (marr.size() > 0) {
            result = max(result, parr[parr.size() - 1] * parr[parr.size() -2] * marr[marr.size() - 1]);
        }
    }

    if (marr.size() > 1) {
        result = max(result, marr[0] * marr[1]);

        if (parr.size() > 0) {
            result = max(result, marr[0] * marr[1] * parr[0]);
        }
    }

    if (marr.size() > 2) {
        result = max(result, marr[marr.size() - 1] * marr[marr.size() - 2] * marr[marr.size() - 3]);
    }
    
    return result;
}

int main(void) {
#ifdef local
    freopen("14753.txt", "r", stdin);
#endif
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &in);

        if (in < 0)
            marr.push_back(in);
        else
            parr.push_back(in);
    }
    
    sort(marr.begin(), marr.end());
    sort(parr.begin(), parr.end(), greater<int>());

    int result = solve();

    printf("%d\n", result);

    return 0;
}
