#include <iostream>
#include <cstring>

using namespace std;

int N;
char arr[51][51];

int main(void) {
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);    

    for (int i = 0; i < N; i++) 
        scanf("%s", arr[i]);
    
    int len = strlen(arr[0]);
    for (int i = 0; i < len; i++) { 
        bool same = true;
        for (int j = 1; j < N; j++) {
            if (arr[0][i] != arr[j][i]) {
                same = false;
                break;
            }
        }

        printf("%c", same ? arr[0][i] : '?');
    }

    return 0;
}
