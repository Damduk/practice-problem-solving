#include <iostream>
#include <cassert>

using namespace std;

const int HEAP_MAX = 100001;
const int HEAP_TOP_IDX = 1;

struct Heap {
    int data[HEAP_MAX];
    int sz;
    
    bool compare(const int& a, const int& b) {
        return a < b;
    }
    
    void push(int x) {
        data[++sz] = x;
        
        for (int cur = sz; cur > HEAP_TOP_IDX; cur /= 2) {
            if (compare(data[cur], data[cur / 2]))
                swap(data[cur], data[cur / 2]);
            else 
                break;
        }
    }
    
    void pop() {
        if (sz < 1)
            assert("Empty heap");
        
        data[HEAP_TOP_IDX] = data[sz--];
        
        int child;
        for (int cur = 1; cur * 2 <= sz; cur = child) {
            if (cur * 2 + 1 > sz || compare(data[cur * 2], data[cur * 2 + 1]))
                child = cur * 2;
            else 
                child = cur * 2 + 1;

            if (!compare(data[cur], data[child]))
                swap(data[cur], data[child]);
            else 
                break;
        }
    }
    
    int top() {
        if (sz < 1)
            assert("Empty heap");
        
        return data[HEAP_TOP_IDX];
    }
    
    int size() {
        return sz;
    }
    
    bool empty() {
        return sz == 0;
    }
};

Heap heap;

void process(const int& n) {
    if (n < 1) {
        int out;
        
        if (heap.empty())
            out = 0;
        else 
            out = heap.top(), heap.pop();
        
        printf("%d\n", out);
    } else {
        heap.push(n);
    }
}

int main() {
    int TC;
    
    scanf("%d", &TC);
    
    while (TC--) {
        int n;
        
        scanf("%d", &n);
        
        process(n);
    }
}