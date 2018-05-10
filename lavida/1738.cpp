#include <iostream>

using namespace std;

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        int N;
        
        scanf("%d", &N);
        
        int money = 0;
        int salary = 5000;
        int day = 0;
        int cnt = 0;
        
        while (money < N) {            
            money += salary;
            day++;
            cnt++;
            
            if (cnt == 10) {
                cnt = 0;
                salary += 200;
            }
        }
        
        printf("%d\n", day);
    }
}