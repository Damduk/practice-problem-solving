#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int TC;

    scanf("%d", &TC);

    while (TC--) {
        int n, m;

        scanf("%d %d", &n, &m);

        vector<int> users;

        for (int i = 0; i < n; i++) {
            int id;

            scanf("%d", &id);

            users.push_back(id);
        }

        sort(users.begin(), users.end());

        printf("%d\n", users[m - 1]);
    }
}