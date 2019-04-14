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

int main(void) {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int Q;
    long long int L1, R1, L2, R2;

    scanf("%d", &Q);

    while (Q--) {
        long long int A, B;

        scanf("%lld %lld %lld %lld", &L1, &R1, &L2, &R2);

        for (long long int i = L1; i <= R1; i++) {
            A = i;

            for (long long int j = L2; j <= R2; j++) {
                if (A != j) {
                    B = j;
                    break;
                }
            }

            if (A != B) {
                printf("%lld %lld\n", A, B);
                break; 
            }
        }
    }

    return 0;
}
