class Solution {
    struct Node {
        int i, j;
        int num1, num2;
        Node(int _i, int _j, int n1, int n2) : i(_i), j(_j), num1(n1), num2(n2) {}
    };
public:
    struct Cmp {
        bool operator() (Node& p1, Node& p2) {
            return p1.num1 + p1.num2 > p2.num1 + p2.num2;
        }
    };
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pairs;
        if(nums1.empty() || nums2.empty()) {
            return pairs;
        }
        priority_queue<Node, vector<Node>, Cmp> pq;
        pq.push(Node(0, 0, nums1[0], nums2[0]));
        while(k-- && !pq.empty()) {
            Node cur = pq.top();
            pq.pop();
            pairs.push_back(make_pair(cur.num1, cur.num2));
            if(cur.j == 0 && cur.i+1 < nums1.size()) pq.push(Node(cur.i+1, cur.j, nums1[cur.i+1], nums2[cur.j]));
            if(cur.j+1 < nums2.size()) pq.push(Node(cur.i, cur.j+1, nums1[cur.i], nums2[cur.j+1]));
        }
        return pairs;
    }
};