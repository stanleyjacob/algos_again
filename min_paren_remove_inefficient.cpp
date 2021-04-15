class Solution {
    
    size_t ind = 0;
    
public:
    
    void updateStringList(list<string>& str_list, string& curr_str) {
        if (curr_str != "") {
            str_list.push_back(curr_str);
            curr_str.clear();
            ind += 1; 
        }
    }
    
    void insertHelper(list<string>& str_list, size_t open_index) {
        list<string>::iterator it = str_list.begin();
        std::advance(it, open_index);
        str_list.insert(it, "(");
    }
    
    string minRemoveToMakeValid(string s) {
        list<string> str_list;
        stack<size_t> open_parens;
        string curr_str;
        int paren_num = 0;
        
        for (char c : s) {
            if (c == '(') {
                updateStringList(str_list, curr_str);
                open_parens.push(ind);
                paren_num += 1;
            }
            else if (c == ')') {
                updateStringList(str_list, curr_str);
                if (paren_num > 0) {
                    size_t open_index = open_parens.top();
                    open_parens.pop();
                    
                    insertHelper(str_list, open_index); 
                    str_list.push_back(")");
                    paren_num -= 1;
                }
            }
            else {
                curr_str += c;
            }
            
        }
        updateStringList(str_list, curr_str);
        
        string ret_str;
        for (string s : str_list) {
            ret_str += s;
        }
        
        return ret_str;
    }
};
