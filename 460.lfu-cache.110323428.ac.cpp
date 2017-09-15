class LFUCache {
    struct Node {
        int key;
        Node* last;
        Node* next;
        Node(int k): key(k), last(NULL), next(NULL) {}
    };
    unordered_map<int, int> keyToVal;
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, int> keyToFreq;
    int cap;
    Node* dummy;
    Node* back;
public:
    LFUCache(int capacity) {
        dummy = new Node(0);
        cap = capacity;
        back = dummy;
    }
    
    int get(int key) {
        if(keyToFreq.count(key)){
            int freq = ++keyToFreq[key];
            Node* cur = keyToNode[key];
            Node* last = cur->last;
            while(last != dummy && keyToFreq[last->key] <= freq) {
                last = last->last;
            }
            if(last != cur->last) {
                if(cur == back) {
                    //change the back;
                    back = cur->last;
                }
                //move cur to last->next
                Node* temp = cur->last;
                temp->next = cur->next;
                if(temp->next) temp->next->last = temp;
                cur->next = last->next;
                cur->next->last = cur;
                last->next = cur;
                cur->last = last;
            }
            return keyToVal[key];
        } else {
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        if(keyToVal.count(key)) {
            //change value
            keyToVal[key] = value;
            //update frequency
            get(key);
        } else {
            if(keyToVal.size() < cap) {
                keyToVal[key] = value;
                keyToNode[key] = new Node(key);
                keyToFreq[key] = 0;
                back->next = keyToNode[key];
                back->next->last = back;
                back = back->next;
                get(key);
            } else {
                if(cap == 0) {
                    return;
                }
                keyToVal.erase(back->key);
                keyToNode.erase(back->key);
                keyToFreq.erase(back->key);
                back = back->last;
                delete back->next;
                back->next = NULL;
                put(key, value);
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */