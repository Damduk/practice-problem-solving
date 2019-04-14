#include <iostream>
#include <cstring>

using namespace std;

string str, bomb;
char ans[1000005];

int idx;

int main(void) {
    freopen("input.txt", "r", stdin);

    cin >> str >> bomb;

    int lenBomb = bomb.size();

    for (auto& c : str) {
        ans[idx++] = c;
        if (ans[idx - 1] == bomb[lenBomb - 1]) {
            if (idx - lenBomb < 0) continue;

            bool exploit = true;
            for (int i = 0; i < lenBomb; i++) {
                if (ans[idx - i - 1] != bomb[lenBomb - i - 1]) {
                    exploit = false;
                    break;
                }
            }
            
            if (exploit) 
                idx -= lenBomb;
        }
    }

    ans[idx] = '\0';

    idx == 0 ? printf("FRULA\n") : printf("%s\n", ans);
    
    return 0;
}
