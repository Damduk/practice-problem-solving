#include <iostream>

using namespace std;

int arr[21];
int N;

double absx(double x) {
    return x < 0 ? -x : x;
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {   
        scanf("%d", &N);
        
        double sum = 0;
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
            
            sum += arr[i];
        }
        
        double avg = sum / N;
        int result = 1e9;
        
        for (auto& item : arr) {
            int item_diff = absx(avg - item);
            int min_diff = absx(avg - result);
            
            if (item_diff < min_diff) 
                result = item;           
        }
        
        printf("%d\n", result);
    }
}