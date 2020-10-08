class Solution {
public:
    int maximumSwap(int num) {
        string str_num = to_string(num);
        string res = helper(str_num);
        return stoi(res);
        
    }
    string helper (string str_num) { 
        if (str_num.size() < 2) return str_num;
        auto max_dig = max_element(str_num.rbegin(),str_num.rend()-1); // search from left to right
        if (*max_dig > str_num[0]) {//swap
            swap(*max_dig, str_num[0]);
            return str_num;
        }
        string res = helper (str_num.substr(1));
        return str_num.substr(0,1) + res;
    }
};
