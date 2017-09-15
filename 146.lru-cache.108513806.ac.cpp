class LRUCache {
    struct Node {
        int val;
        int key;
        Node* front;
        Node* back;
        Node(int v = -1, int k = -1) : val(v), key(k), front(NULL), back(NULL) {}
    };
    int cap;
    unordered_map<int, Node*> map;
    Node* start, *end;
public:
    LRUCache(int capacity) {
        cap = capacity;
        start = new Node();
        end = start;
    }
    
    int get(int key) {
        //move the node with the key back to the end
        if(map.count(key)) {
            Node* curNode = map[key];
            if(curNode != end) {
                curNode->front->back = curNode->back;
                curNode->back->front = curNode->front;
                end->back = curNode;
                curNode->front = end;
                end = end->back;
            }
            return end->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(map.count(key)) {
            //move the node of the key back in the end with new value
            Node* curNode = map[key];
            curNode->val = value;
            if(curNode != end) {
                curNode->front->back = curNode->back;
                curNode->back->front = curNode->front;
                end->back = curNode;
                curNode->front = end;
                end = end->back;
            }
        } else {
            //push a new node in the end and update the map
            end->back = new Node(value, key);
            end->back->front = end;
            end = end->back;
            map[key] = end;
            //if out of capacity, remove the first node from the map and list 
            if(map.size() > cap) {
                Node* curNode = start->back;
                curNode->front->back = curNode->back;
                curNode->back->front = curNode->front;
                map.erase(curNode->key);
                delete curNode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */