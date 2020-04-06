bool cmp(const int& a, const int& b) {
    if (a == 0) {
        return false;
    } else if (b == 0) {
        return true;
    }

    return false;
}
class Solution {
public:    
    void moveZeroes(vector<int>& nums) {
        stable_sort(nums.begin(), nums.end(), cmp);
    }
};