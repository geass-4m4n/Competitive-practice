class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
              map<int, int> m;
        for(int x: A) m[abs(x)]++;
        for(auto &p: m) { // start with smallest number
            int x = p.first; 
            if(m[x]) {
                if(m[2*x] < m[x]) return false;
                m[2*x] -= m[x];
            }
        }
        return true;
        
    }
};
