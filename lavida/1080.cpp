#include <iostream>

using namespace std;

int M[105][105];
int H, W;

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        scanf("%d %d", &H, &W);
        
        for (int i = 0; i < H; i++) 
            for (int j = 0; j < W; j++)
                scanf("%d", &M[i][j]);
            
        for (int i = 0; i < W; i++) {
            printf("%d", M[0][i]);
            
            for (int j = 1; j < H; j++)
                printf(" %d", M[j][i]);
            
            printf("\n");
        }
    }
}