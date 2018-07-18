#include <iostream>

using namespace std;

double solve(double T, double N) {
    return N / (1 + (1 / T));
}

int main() {
    double T, N;
    
    scanf("%lf %lf", &T, &N); 
    printf("%.2lf\n", solve(T, N));
}