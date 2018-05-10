#include <iostream>

using namespace std;

int get_exe_cnt(int old_hour, int old_min, int new_hour, int new_min) {
    int exe = 0;
    
    while (old_hour != new_hour) {
        old_hour += 1;
        old_min += 1;
        
        if (old_hour > 23)
            old_hour = 0;
        if (old_min > 59)
            old_min = 0;
        
        exe++;
    }
    
    while (old_min != new_min) {
        old_min += 1;
        
        if (old_min > 59)
            old_min = 0;
        
        exe++;
    }
    
    return exe;
}

int main() {
    int old_hour, old_min, new_hour, new_min;
    
    scanf("%d:%d %d:%d", &old_hour, &old_min, &new_hour, &new_min);
    printf("%d\n", get_exe_cnt(old_hour, old_min, new_hour, new_min));
}