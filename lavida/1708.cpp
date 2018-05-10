#include <iostream>
#include <cmath>

using namespace std;

float roundx(float x) {
    int digit = 2;
    
    float a = x * pow(10, digit);
    float result = floor(a + 0.5);
    
    return result / pow(10, digit);
}

int main() {
    int a, b, c, d;
    
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    float result = 0;
    
    result += a;
    result -= b;
    result *= c;
    result /= d;
    
    printf("%.2f", roundx(result));
}