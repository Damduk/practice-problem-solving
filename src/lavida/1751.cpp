#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double get_value(double h, double w) {
    return 100 - (fabs(h - 160) + fabs(22 - w * 10000 / (h * h)) * 4);
}

bool cmp(const pair<int, double>& p1, const pair<int, double>& p2) {
    return p1.second > p2.second;
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        vector<pair<int, double>> a;
        vector<pair<int, double>> b;
        
        for (int i = 1; i <= 3; i++) {
            double h, w;
            
            scanf("%lf %lf", &h, &w);
            
            a.push_back({i, get_value(h, w)});
        }
        
        for (int i = 1; i <= 3; i++) {
            double h, w;
            
            scanf("%lf %lf", &h, &w);
            
            b.push_back({i, get_value(h, w)});
        }
            
        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end(), cmp);
        
        printf("%d %d\n", a[0].first, b[0].first);
    }
}