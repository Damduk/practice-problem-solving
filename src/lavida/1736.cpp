#include <iostream>

using namespace std;

string menu[11];
int price[11];

int M, P;

int get_idx(const string& str) {
    for (int i = 0; i < M; i++)
        if (menu[i] == str)
            return i;
        
    return 0;
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        scanf("%d %d", &M, &P);
        
        for (int i = 0; i < M; i++)
            cin >> menu[i] >> price[i];
        
        int result = 0;
        
        for (int i = 0; i < P; i++) {
            string str;
            
            cin >> str;
            
            result += price[get_idx(str)];
        }
            
        printf("%d\n", result);
    }
}