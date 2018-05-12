#include <iostream>
#include <cmath>

using namespace std;

double roundx(double x, int digit = 1) {
    if (x == 0.0f)
        return x;
    
    double a = x * pow(10, digit);

    a = ceil(a - 0.4);
    
    return a / pow(10, digit);
}

void solve(int H, int M) {
    int total = M + (H * 60);
    
    double h = 0, m = 0;
    
    while (total--) {
        h += 0.5;
        m += 6;
        
        if (h >= 360.0) 
            h = h - 360.0;
        if (m >= 360.0)
            m = m - 360.0;    
    }
    
    printf("%.1lf %.1lf\n", roundx(h), roundx(m));
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        int H, M;
        
        scanf("%d:%d", &H, &M);
        
        solve(H, M);
    }
}