#include <iostream>

using namespace std;

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    for (int tc = 1; tc <= TC; tc++) {
        int N;
        
        scanf("%d", &N);
        
        printf("Case #%d:", tc);
        
        for (int i = 0; i <= N; i++) {
            if (N >= 4)
                for (int j = 0; j < i - 1; j++)
                    printf(" ");
            
            for (int j = 0; j < i; j++)
                printf("*");
            
            printf("\n");
        }
        
        for (int i = N - 1; i > 0; i--) {
            if (N >= 4)
                for (int j = i - 1; j > 0; j--)
                    printf(" ");
            
            for (int j = 0; j < i; j++)
                printf("*");
            
            printf("\n");
        }
        
        printf("\n");
    }
}