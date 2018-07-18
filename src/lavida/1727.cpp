#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, float>& o1, const pair<int, float>& o2) {
    return o1.second > o2.second;
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        pair<int, float> arr[3];
        
        for (int i = 0; i < 3; i++) {
            float x, y;
            
            scanf("%d %d", &x, &y);
            
            arr[i] = {i + 1, y / x};
        }
            
        sort(arr, arr + 3, cmp);
        
        printf("%d\n", arr[0].first);
    }
}