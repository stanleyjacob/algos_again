
class Solution {
public:
    
    
    int binary_search_matrix(vector<vector<int>>& matrix, int target) {
        
        int low_index = 0;
        int high_index = matrix.size() - 1;
        
        while (low_index <= high_index) {
            
            int mid_index = (high_index + low_index) / 2; 
            if (matrix[mid_index][0] < target) {
                low_index = mid_index + 1;
            }
            else if (matrix[mid_index][0] > target) {
                high_index = mid_index - 1;
            }
            else {
                return mid_index;
            }
        }
        
        int mid_index = (high_index + low_index) / 2; 
        if (matrix[mid_index][0] > target) {
            return mid_index - 1;
        }
        return mid_index;
    }
    
    int binary_search_vector(vector<int>& curr_vector, int target) {
        
        int low_index = 0;
        int high_index = curr_vector.size() - 1;
        
        while (low_index <= high_index) {
            
            int mid_index = (high_index + low_index) / 2 ; 
            if (curr_vector[mid_index] < target) {
                low_index = mid_index + 1;
            }
            else if (curr_vector[mid_index] > target) {
                high_index = mid_index - 1;
            }
            else {
                return mid_index;
            }
        }
        
        int mid_index = (high_index + low_index) / 2; 
        if (curr_vector[mid_index] > target) {
            return mid_index - 1;
        }
        return mid_index;
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        
        if (m == 0) {
            return false;
        } 

        // binary search based on elements in first column
        // search row that target is bounded by in binary search way
        int matrix_index = binary_search_matrix(matrix, target);
        if (matrix_index < 0) {
            matrix_index = 0;
        }
        if (matrix_index >= matrix.size()) {
            matrix_index = matrix.size() - 1;
        }
        
        vector<int> curr_vector = matrix[matrix_index];
        int vector_index = binary_search_vector(curr_vector, target);
        
        if (vector_index < 0) {
            vector_index = 0;
        }
        if (vector_index >= matrix[0].size()) {
            vector_index = matrix[0].size() - 1;
        }
        
        // cout << matrix_index << endl;
        // cout << vector_index << endl;
        
        if (matrix[matrix_index][vector_index] == target) {
            return true;
        }
        
        return false;
    }
};
