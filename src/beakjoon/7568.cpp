#include <iostream>

using namespace std;

typedef struct info {
    int height;
    int weight;
    int rank;
} Info;

int N;
Info info[51];

int cmp(Info a, Info b) {
    return a.height > b.height && a.weight > b.weight;
}

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &info[i].weight, &info[i].height);
    }

    for (int i = 0; i < N; i++) {
        info[i].rank = 1;

        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (cmp(info[j], info[i]))
                info[i].rank++;
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", info[i].rank);
    }

    return 0;
}