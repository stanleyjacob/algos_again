class Solution {
public:
    
    int find_pivot(vector<int>& nums) {
        
        if (nums.size() == 1) {
            return 0;
        }
        
        int b = 0;
        int e = nums.size() - 1;
        int pivot;
        
        while (b <= e) {
            pivot = (b + e) / 2;
            
            if (nums[pivot] > nums[pivot + 1]) {
                return pivot; 
            }
            
            if ((nums[pivot] >= nums[b]) &&  (nums[pivot] > nums[e])) {
                b = pivot;
            }
            else if ((nums[pivot] <= nums[e]) &&  (nums[pivot] < nums[b])) {
                e = pivot;
            }
            else if ((nums[b] <= nums[pivot]) && (nums[pivot] <= nums[e])) {
                return e;
            }
        }
        
        return pivot;
    }
    
    int binary_search(vector<int>& nums, int b, int e, int t) {
        
        if (b > e) {
            return -1;
        }
        if (b == e) {
            if (nums[b] == t) {
                return b;
            }
            return -1;
        }
        
        if (nums[e] < t) {
            return -1;
        }
        if (nums[b] > t) {
            return -1;
        }
        
        int pivot;
        while (b <= e) {
            pivot = (b + e) / 2;
            if (t == nums[pivot]) {
                return pivot;
            }
            else if (nums[pivot] < t) {
                b = pivot + 1;
            }
            else if (nums[pivot] > t) {
                e = pivot - 1;
            }
        }
        
        if (nums[pivot] == t) {
            return pivot;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        if (nums.size() == 0) {
            return -1;
        }
        
        if (nums.size() == 1) {
            if (nums[0] == target) {
                return 0;
            }
            else {
                return -1;
            }
        }
        
        int pivot = find_pivot(nums);
        int res = binary_search(nums, 0, pivot, target);
        int res2 = binary_search(nums, pivot + 1, nums.size() - 1, target);
        
        if (res == -1 && res2 == -1) {
            return -1;
        }
        if (res != -1) {
            return res;
        }
        
        return res2;
        
    }
    
};
