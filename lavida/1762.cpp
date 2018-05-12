#include <iostream>
#include <cmath>

using namespace std;

double my_log(int a, int b) {
    return log(a) / log(b);
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        int a, b;
        
        scanf("%d %d", &a, &b);
        
        int result = ceil(my_log(b, a)) - 1;
        
        printf("%d\n", result);
    }
}