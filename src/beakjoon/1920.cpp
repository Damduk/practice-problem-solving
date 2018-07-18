#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;

int data[MAX];
int check[MAX];
int n, m;

int search(int target) {
    int l = -1, r = n + 1;
    int mid;
    
    while (l + 1 < r) {
        mid = (l + r) / 2;
        
        if (data[mid] >= target)
            r = mid;
        else 
            l = mid;
    }
    
    return r;
}

int exists(int a) {
    int pos = search(a);
    
    return a == data[pos];
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    
    sort(data, data + n);
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int input;
        
        scanf("%d", &input);
        printf("%d\n", exists(input));
    }
}