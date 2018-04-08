#include <iostream>

using namespace std;

void space_for(int len) {
    for (int i = 0; i < len; i++)
        printf(" ");
}

void enter() {
    printf("\n");
}

void draw(const int& sz) {
    for (int i = 1; i <= sz; i++) {
        int start = sz;
        int space = sz - i;
        int len = i * 2 - 1;
        
        space_for(space);
        
        for (int i = 0; i < (len / 2) + 1; i++)
            printf("%d", start--); 
        
        start += 2;      
        
        for (int i = 0; i < len / 2; i++)
            printf("%d", start++);     
        
        enter();
    }   
    
    for (int i = sz - 1; i > 0; i--) {
        int start = sz;
        int space = sz - i;
        int len = i * 2 - 1;
                
        space_for(space);
    
        for (int i = 0; i < (len / 2) + 1; i++)
            printf("%d", start--);
        
        start += 2;
        
        for (int i = 0; i < len / 2; i++)
            printf("%d", start++);
        
        enter();
    }
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        int sz;
        
        scanf("%d", &sz);
        
        draw(sz);
    }
}