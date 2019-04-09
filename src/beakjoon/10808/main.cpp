#include <bits/stdc++.h>

using namespace std;

string input;

int cnt[26];
int main(void) {
    cin >> input;
    
    for (char item : input) {
        int idx = (int)item - (int)'a';
        cnt[idx]++;
    }

    for (int item : cnt)
        printf("%d ", item);

    return 0;
}
