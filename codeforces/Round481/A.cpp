#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> result;

int pos[1005];
int N, len;

int main() {
    memset(pos, -1, sizeof(pos));
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int x;
        
        scanf("%d", &x);
        
        int& last_pos = pos[x];
        if (last_pos != -1) {
            result[last_pos] = 0;
            len -= 1;
        }
        
        last_pos = i;
        len += 1;
                  
        result.push_back(x);
    }
    
    printf("%d\n", len);
    
    for (int& item : result)
        if (item != 0)
            printf("%d ", item);
}