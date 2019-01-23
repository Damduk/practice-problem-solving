#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;

#define mp make_pair

int cache[130];
int num[200000];

bool valid(int a, int b) {
    if (b == 1) {
        return true;
    }

    return a % b != 0;
}

int main(void) {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int N;
    int maxi = -1;
    int B = -1;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &cache[i]);

        maxi = max(maxi, cache[i]);

        if (num[cache[i]]++ == 1) {
            B = max(B, cache[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (valid(maxi, cache[i])) {
            B = max(B, cache[i]);
        }
    }

    printf("%d %d\n", maxi, B);

    return 0;
}
