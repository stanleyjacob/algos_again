class SparseVector {

    
public:
    unordered_map<int, int> indices;    
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                indices.insert({i, nums[i]});
            }
        }
    }
    
    void helper_set_intersection(unordered_set<int>& s1,
                                unordered_set<int>& s2,
                                vector<int>& ret_vec) {
        
        unordered_set<int>* loop_set;
        if (s1.size() > s2.size()) {
            loop_set = &s2;
        }
        else {
            loop_set = &s1;
        }
        for (int ind : *loop_set) {
            if (s2.find(ind) != s2.end()) {
                ret_vec.push_back(ind);
            }
        }
        
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        
        vector<int> index_vec;
        unordered_set<int> this_set;
        unordered_set<int> index_set;
        
        for (auto& [key, value] : this->indices) {
            this_set.insert(key);
            // cout << key << ' ';
        }
        // cout << endl;
        
        for (auto& [key, value] : vec.indices) {
            index_set.insert(key);
            // cout << key << ' ';
        }
        
        helper_set_intersection(this_set, index_set, index_vec);
        
        int sum = 0;
        for (int& ind : index_vec) {
            sum += (this->indices)[ind] * vec.indices[ind];
            // cout << sum << endl;
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
