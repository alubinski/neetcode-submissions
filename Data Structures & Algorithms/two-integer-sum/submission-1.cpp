class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> numMap;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int dif = target - nums[i];
            if (numMap.count(dif)) {
                return {numMap[dif], i};
            }
            numMap[nums[i]] = i;
        }
    }
};
