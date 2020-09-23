class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        vector<pair<int, char>> count = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        sort(count.begin(), count.end());   
        string s = "";
        char last = 'd';                        
        while(true)
        {
            if(last != count[2].second)       
            {
                for(int i=0;i<2&&count[2].first>0;i++)
                {
                    count[2].first--;
                    s.push_back(count[2].second);
                    last = count[2].second;
                }
            }
            else if(count[1].first > 0)         
            {
                count[1].first--;
                s.push_back(count[1].second);
                last = count[1].second;
            }
            if(last == count[2].second && count[0].first+count[1].first == 0)  
                break;
            sort(count.begin(), count.end());      
        }
        return s;
        
    }
};
