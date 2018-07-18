#include <iostream>
#include <cmath>

using namespace std;

int powx(int x) {
    return x * x;
}

int get_id(const char& x) {
    return x - 'A' + 1; 
}

int solve(const string& n1, const string& n2) {
    int maxi = max(n1.size(), n2.size());
    int sum = 0;
    
    string big, small;
    if (n1.size() > n2.size()) {
        big = n1;
        small = n2;
    } else {
        big = n2;
        small = n1;
    }
    
    for (int i = 0; i < maxi; i++) {
        int front = get_id(big[i]);
        int back = 0;
        if (i < small.size())
            back = get_id(small[i]);
        
        int diff = front - back;
        
        sum += powx(diff);
    }
    
    return floor(sum / maxi);
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        string N1, N2;
        
        cin >> N1 >> N2;
        
        printf("%d\n", solve(N1, N2));
    }
}