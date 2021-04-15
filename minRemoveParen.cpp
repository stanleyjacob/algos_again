class Solution {
    
public:
    
    string minRemoveToMakeValid(string s) {
        
        stack<int> open_paren;
        unordered_set<int> remove_set;

        for (int i = 0; i < s.size(); ++i) {
            
            if (s[i] == '(') {
                open_paren.push(i);
            }
            else if (s[i] == ')') {
                if (open_paren.empty()) {
                    remove_set.insert(i);
                }
                else {
                    open_paren.pop(); 
                }
            }
        }
        
        while (open_paren.size() > 0) {
            remove_set.insert(open_paren.top());
            open_paren.pop();
        }
        
        string final_str;
        for (int i = 0; i < s.size(); ++i) {
            if (remove_set.find(i) == remove_set.end()) {
                final_str += s[i]; 
            }
        }
        return final_str;
    }
};
