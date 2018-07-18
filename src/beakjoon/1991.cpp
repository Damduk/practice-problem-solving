#include <iostream>

using namespace std;

char tree[50];
int pos[50];
int N;

int get_id(const char& x) {
    return x - 'A' + 1;
}

void insert(char p, char l, char r) {
    int& ppos = pos[get_id(p)];
    if (ppos == 0)
        ppos = 1;
    
    tree[ppos] = p;
    
    if (l == '.')
        tree[ppos * 2] = NULL;
    else {
        tree[ppos * 2] = l;
        pos[get_id(l)] = ppos * 2;
    }
    
    if (r == '.')
        tree[ppos * 2 + 1] = NULL;
    else {
        tree[ppos * 2 + 1] = r;
        pos[get_id(r)] = ppos * 2 + 1;
    }
}

void preorder(int parent) {
    printf("%c", tree[parent]);
    
    if (tree[parent * 2] != NULL)
        preorder(parent * 2);
    
    if (tree[parent * 2 + 1] != NULL)
        preorder(parent * 2 + 1);
}

void inorder(int parent) {    
    if (tree[parent * 2] != NULL)
        inorder(parent * 2);
    
    printf("%c", tree[parent]);
    
    if (tree[parent * 2 + 1] != NULL)
        inorder(parent * 2 + 1);
}

void postorder(int parent) {
    if (tree[parent * 2] != NULL)
        postorder(parent * 2);
    
    if (tree[parent * 2 + 1] != NULL)
        postorder(parent * 2 + 1);
    
    printf("%c", tree[parent]);
}

int main() {
    scanf("%d", &N);
    
    while (N--) {
        char parent, left, right;
        
        scanf(" %c %c %c", &parent, &left, &right);
        
        insert(parent, left, right);
    }
    
    preorder(1);
    
    printf("\n");
    
    inorder(1);
    
    printf("\n");
    
    postorder(1);
}