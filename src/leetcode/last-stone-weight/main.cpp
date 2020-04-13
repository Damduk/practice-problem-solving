class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (const int& item : stones)
            pq.push(item);
        
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            
            int c = abs(a - b);
            if (c > 0) 
                pq.push(c);
        }
        
        int res = pq.size() > 0 ? pq.top() : 0;
        return res;
    }
};