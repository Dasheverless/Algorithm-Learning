class Solution {
    /**************
    二分核心思想：用m二分数组，然后用算法判断该去查找哪一边。哪边有序查哪边，查不到肯定在另一边。
    区间形式：[a, b)。
    n = nums.size()
    循环不变量：待查找变量在 [l, r)中。
    进入前： l = 0, r = n。 i 属于 [l,r)。l < r。
    一次循环结束时： m = (l + r) / 2。二分数组。如果nums[m] == target，直接返回。
    判断哪边数组有序，左边有序，则看target是否在 [nums[l], nums[m])的范围。
    若是，则 r = m。 则 若l < r，则未查完。此时剩余数组仍在 i 属于 [l, r)中。
    若右边有序，看target是否在(nums[m], nums[r-1]]中(target == num[m]就直接返回了)，
    若是则 l = m + 1。待查找变量依然在[l, r)中。
    循环结束时， l == r [l, r)中无元素，返回 -1。
    ***************/
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r)
        {
            int m = (l + r) >> 1;
            if(nums[m] == target)
                return m;
            if(nums[l] <= nums[m])
            {
                if(nums[m] > target && nums[l] <= target)
                    r = m;
                else
                    l = m + 1;
            }
            else
            {
                if(nums[m] < target && nums[r-1] >= target)
                    l = m + 1;
                else
                    r = m;
            } 
        }
        return -1;
    }
};

作者：nice-6reider
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/li-qing-er-fen-fa-de-si-lu-by-nice-6reid-9eww/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
