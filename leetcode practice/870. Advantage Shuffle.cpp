class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
         multiset<int> q;
        for (int i : A) q.insert(i);
        
        for (int i = 0; i < B.size(); i++) {
            auto iter = q.lower_bound(B[i] + 1);
            
            if (iter == q.end()) {
                iter = q.begin();
            }
            
            A[i] = *iter;
            q.erase(iter);
        }
        
        return A;
        
    }
};
