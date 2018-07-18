#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<string, int> si;

vector<si> arr[101];
int N;

bool solve() {
    for (int i = 1; i < 101; i++) {
        for (auto& cur : arr[i]) {
            for (int j = i; j < 101; j++) {
                for (auto& next : arr[j]) {
                    if (i == j && cur.first != next.first)
                        return false;

                    if (next.first.find(cur.first) == string::npos)
                        return false;

                    cur.second--;
                }
            }
        }
    }

    return true;
}

bool cmp(si& p1, si& p2) {
    return p1.second < p2.second;
}

void print() {
    for (int i = 1; i < 101; i++) {
        sort(arr[i].begin(), arr[i].end(), cmp);

        for (auto& item : arr[i]) 
            cout << item.first << "\n";
    }
}

int main() {
    freopen("B.in", "r", stdin);
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        string S;

        cin >> S;

        arr[S.size()].push_back({S, 0});
    }

    if (solve()) {
        printf("YES\n");

        print();
    } else {
        printf("NO\n");
    }
}
