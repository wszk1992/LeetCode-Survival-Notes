class RandomizedSet {
public:
    vector<int> data;
    unordered_map<int, int> dict;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dict.count(val)) {
            return false;
        } else{
            dict[val] = (int)data.size();
            data.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(dict.count(val)) {
            dict[data.back()] = dict[val];
            swap(data[dict[val]], data[data.size() - 1]);
            data.pop_back();
            dict.erase(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data[rand() % data.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */