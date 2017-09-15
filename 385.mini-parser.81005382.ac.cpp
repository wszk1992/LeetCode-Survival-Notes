/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger res;
        if(isList(s)) {
            removeBracket(s);
            listToNest(res, s);
        }else {
            res.setInteger(stoi(s));
        }
        return res;
    }
    
    bool isList(string& s) {
        return s.front() == '[' && s.back() == ']';
    }
    
    void removeBracket(string& s) {
        s.erase(s.begin());
        s.pop_back();
    }
    
    void listToNest(NestedInteger& res, string& s) {
        if(s.empty()) {
            return;
        }
        int flag = 0;
        string ss;
        for(auto c : s) {
            if(c == '[') {
                flag++;
            }else if(c == ']') {
                flag--;
            }
            
            if(flag == 0 && c == ',') {
                res.add(deserialize(ss));
                ss = "";
            }else {
                ss += c;
            }
        }
        res.add(deserialize(ss));
    }
};