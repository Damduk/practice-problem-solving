#include <iostream>
#include <functional>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int> max_heap;

int get_median(const int& x) {
    if (max_heap.size() > min_heap.size())
        min_heap.push(x);
    else
        max_heap.push(x);
    
    if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
        min_heap.push(max_heap.top());
        max_heap.pop();
    } else if (!min_heap.empty() && min_heap.top() < max_heap.top()) {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }

    if (max_heap.size() < min_heap.size()) {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
    
    return max_heap.top();
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        printf("%d\n", get_median(x));
    }
}