#include <cstdio>

char get_result(int a, int b, int c, int d) {
    int sum = a + b + c + d;
    if (sum == 4)
        return 'E';
    else if (sum == 3)
        return 'A';
    else if (sum == 2)
        return 'B';
    else if (sum == 1)
        return 'C';
    else if (sum == 0)
        return 'D';
}

int main() {
    int a, b, c, d;
    
    for (int i = 0; i < 3; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%c\n", get_result(a, b, c, d));        
    }
}