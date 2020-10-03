class SnapshotArray {
    vector<vector<pair<int, int>>> sarr;
    vector<pair<int, int>> snapV;
public:
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        for (int i = 0; i < snapV.size(); i++) {
            if (snapV[i].first == index) {
                snapV[i] = {index, val};
                return;
            }
        }
        snapV.push_back(make_pair(index, val));
    }
    
    int snap() {
        sarr.push_back(snapV);
        snapV.clear();
        return sarr.size()-1;
    }
    
    int get(int index, int snap_id) {
        for (int i = snap_id; i >= 0; i--) {
            for (int j = 0; j < sarr[i].size();j++) {
                if (sarr[i][j].first == index) return sarr[i][j].second;
            }
        }
        return 0;
    }
};
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
