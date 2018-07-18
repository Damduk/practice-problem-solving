#include <iostream>
#include <map>

using namespace std;

int M[101][101];
int N, MAX, SUM;

int Y[101];
int C[2];

map<int, bool> exists;

bool solve() {
    for (int i = 0; i < N; i++) {
        int x = 0;
        
        for (int j = 0; j < N; j++) {
            scanf("%d", &M[i][j]);
            
            if (!(M[i][j] > 0 && M[i][j] <= MAX)) 
                return false;
            
            if (exists.find(M[i][j]) != exists.end()) 
                return false;
            else
                exists.insert(make_pair(M[i][j], true));
            
            x += M[i][j];
            Y[j] += M[i][j];
            
            if (i == j)
                C[0] += M[i][j];
            if (i + j == N - 1)
                C[1] += M[i][j];
        }
        
        if (x != SUM)
            return false;
    }

    if (C[0] != SUM || C[1] != SUM)
        return false;
    
    for (int i = 0; i < N; i++)
        if (Y[i] != SUM)
            return false;
}

int main() {
    scanf("%d", &N);
    
    MAX = N * N;
    SUM = N * (N * N + 1) / 2;  
    
    printf("%s", solve() ? "TRUE" : "FALSE");
}