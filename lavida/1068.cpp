#include <iostream>

using namespace std;

int M1[15][15];
int M2[15][15];
int H1, H2, W1, W2;

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        scanf("%d %d", &H1, &W1);
        
        for (int i = 0; i < H1; i++)
            for (int j = 0; j < W1; j++)
                scanf("%d", &M1[i][j]);
            
        scanf("%d %d", &H2, &W2);
        
        for (int i = 0; i < H2; i++)
            for (int j = 0; j < W2; j++)
                scanf("%d", &M2[i][j]);
            
        if (H1 != H2 || W1 != W2) {
            printf("Impossible\n");
            continue;
        }
        
        for (int i = 0; i < H1; i++) {
            printf("%d", M1[i][0] + M2[i][0]);
            
            for (int j = 1; j < W1; j++) {
                printf(" %d", M1[i][j] + M2[i][j]);
            }
            
            printf("\n");
        }              
    }
}