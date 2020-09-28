class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n = satisfaction.size(), ans = 0;

	sort(satisfaction.begin(), satisfaction.end());
	for (int i = 0; i < n; ++i) {
		int curr = 1, currAns = 0;

		for (int j = i; j < n; ++j) {
			currAns += curr * satisfaction[j];
			curr++;
		}
		ans = max(ans, currAns);
	}
	return ans;
        
    }
};
