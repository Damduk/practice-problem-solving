#include <iostream>

using namespace std;

int X, Y, W, H;

int main(void) {
    scanf("%d %d %d %d", &X, &Y, &W, &H);

    int minX = min(X, W - X);
    int minY = min(Y, H - Y);

    printf("%d\n", min(minX, minY));
}
