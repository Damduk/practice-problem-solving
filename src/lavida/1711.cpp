#include <cstdio>
#include <cmath>

double my_round(double x, const int& digit) {
    double p = x * pow(10, digit);
    double r = floor(p + 0.5);

    return r * pow(10, -digit);
}

int main() {
    double principal, interest_rate;

    scanf("%lf %lf", &principal, &interest_rate);

    double interest = principal * (interest_rate / 100.0);
    
    printf("%.1lf\n", my_round(principal + interest, 1));
}