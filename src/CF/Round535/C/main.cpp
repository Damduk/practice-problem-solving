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

char dict[6][3] = {
    { 'R', 'G', 'B' },
    { 'G', 'B', 'R' },
    { 'B', 'R', 'G' },
    { 'R', 'B', 'G' },
    { 'B', 'G', 'R' },
    { 'G', 'R', 'B' }
};

char cache[3000000];
int main(void) {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) 
        cin >> cache[i]; 

    int mini = 1e9;
    int minIdx = 0;
    for (int i = 0; i < 6; i++) {
        int sum = 0;

        for (int j = 0; j < N; j++) {
            int remain = j % 3;
            if (dict[i][remain] != cache[j]) {
                sum++;
            }
        }

        mini = min(mini, sum);
        if (mini == sum) {
            minIdx = i;
        }
    }
    
    printf("%d\n", mini);
    
    for (int i = 0; i < N; i++) {
        printf("%c", dict[minIdx][i % 3]);
    }

    printf("\n");

    return 0;
}
