class ZigzagIterator {
    int index;
    int k;
    vector<vector<int>> v;
    int maxLen = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.push_back(v1);
        v.push_back(v2);
        maxLen = max(v1.size(), v2.size());
        index = 0;
        k = 0;
    }

    int next() {
        return v[k++][index];
    }

    bool hasNext() {
        if(k == v.size()) {
            index++;
            k = 0;
        }
        while(index >= v[k].size()) {
            k++;
            if(k == v.size()) {
                index++;
                k = 0;
            }
            if(index == maxLen) {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */