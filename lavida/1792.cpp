#include <iostream>

using namespace std;

int score[3];
int times[3][2];
int N;

int get_second(const int min) {
    return min * 60;
}

int push_second(int t, int cur_m, int pm, int cur_s, int ps) {
    times[t][1] += get_second(cur_m - pm) + (cur_s - ps);
}

void update_time() {
    int first_total = times[1][1];
    times[1][0] = first_total / 60;
    times[1][1] = first_total % 60;
    
    int second_total = times[2][1];
    times[2][0] = second_total / 60;
    times[2][1] = second_total % 60;
}

int main() {
    scanf("%d", &N);
    
    int PT = -1, PM = -1, PS = -1;
    
    for (int i = 0; i < N; i++) {
        int T, M, S;
        
        scanf("%d %d:%d", &T, &M, &S);
        
        score[T]++;
        
        if (score[1] == score[2]) {
            push_second(PT, M, PM, S, PS);
            
            PT = PM = PS = -1;
        } else if (PT == -1) {
            PT = T;
            PM = M;
            PS = S;
        }
    }
    
    if (PT != -1)
        push_second(PT, 48, PM, 0, PS);
    
    update_time();
    
    printf("%02d:%02d\n", times[1][0], times[1][1]);
    printf("%02d:%02d\n", times[2][0], times[2][1]);
}