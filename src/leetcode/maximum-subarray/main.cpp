#define INF -2147483648

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INF;
        for (int i = 0; i < nums.size(); i++) {
            int sub = nums[i];
            int s = nums[i];
            
            for (int j = i + 1; j < nums.size(); j++) {
                s += nums[j];
                sub = max(sub, s);
            }
            
            res = max(res, sub);
        }
        
        return res;
    }
};