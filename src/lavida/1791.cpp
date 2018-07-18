#include <iostream>

using namespace std;

int X;

int absx(int x) {
    return x < 0 ? -x : x;   
}

int main() {
    int result = 0;
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &X);
        
        int cur_diff = absx(100 - result);
        int after_diff = absx(100 - (result + X));
        
        if (after_diff <= cur_diff) 
            result += X;
        else
            break;
    }
        
    printf("%d\n", result);
}