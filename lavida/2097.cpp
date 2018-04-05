#include <cstdio>
#include <cmath>
#define MAX 10001

int arr[MAX];
int n;

float get_avg() {
    int sum = 0;
    
    for (int i = 0; i < n; i++)
        sum += arr[i];
    
    return (float)sum / n; 
}

float get_diff(const float& avg, const int& cur) {
    return fabs(avg - cur);
}

int get_answer(const float& avg) {
    int mini = arr[0];
    
    for (int i = 1; i < n; i++)
        if (fabs(avg - arr[i]) < get_diff(avg, mini))
            mini = arr[i];
        
    return mini;
}

int main() {
    int T;
    
    scanf("%d", &T);
    
    while (T--) {  
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        
        float avg = get_avg();
        
        printf("%d\n", get_answer(avg));
    }
}