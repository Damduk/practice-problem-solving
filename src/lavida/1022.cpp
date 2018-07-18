#include <iostream>

using namespace std;

void print_line(const int& N, const int& i) {
    int space = N - i;
    for (int j = 0; j < space; j++)
        printf(" ");
            
    for (int j = 1; j <= i; j++) 
        printf("%d", j);
    for (int j = i - 1; j > 0; j--)
        printf("%d", j);
    
    printf("\n");
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        int N;
        
        scanf("%d", &N);
        
        for (int i = 1; i <= N; i++)
            print_line(N, i);
        
        for (int i = N - 1; i > 0; i--) 
            print_line(N, i);
    }
}