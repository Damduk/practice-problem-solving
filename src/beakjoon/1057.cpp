#include <iostream>
#include <queue>

#define ELE 100001

using namespace std;

int N;
int A, B;

queue<int> round;
queue<int> winner;
int roundNum;

int main(void) {
    scanf("%d %d %d", &N, &A, &B);

    for (int i = 1; i <= N; i++) {
        round.push(i != A && i != B ? ELE : i);
    }

    roundNum = 1;

    while (round.size() > 1) {
        winner = queue<int>();

        while (round.size()) {
            int a = round.front();
            round.pop();

            if (round.empty()) {
                winner.push(a);
                break;
            }

            int b = round.front();
            round.pop();
            if ((a == A && b == B) || (a == B && b == A)) {
                printf("%d\n", roundNum);
                return 0;
            } else if (a == A || a == B) {
                winner.push(a);
            } else if (b == A || b == B) {
                winner.push(b);
            } else {
                winner.push(ELE);
            }
        }

        round = winner;
        roundNum++;
    }

    printf("-1\n");

    return 0;
}