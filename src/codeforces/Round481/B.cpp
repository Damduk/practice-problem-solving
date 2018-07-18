#include <iostream>

using namespace std;

int N;
string str;

int main() {  
    cin >> N >> str;
    
    int conti = 0;
    int cnt = 0;
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'x')
            conti++;
        else 
            conti = 0;
        
        if (conti >= 3)
            cnt++;
    }
    
    printf("%d\n", cnt);
}