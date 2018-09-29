#define LOCAL_TEST

#include <iostream>

using namespace std;

int N;
int length = 64;

int main(void) {
#ifdef LOCAL_TEST
    freopen("1094.in.txt", "r", stdin);
#endif
    scanf("%d", &N);

    int result = 0;

    while (N) {
        if (N < length) 
            length /= 2;
        else {
            result += 1;
            N -= length;
        }
    }
    
    printf("%d\n", result);
    return 0;
}

