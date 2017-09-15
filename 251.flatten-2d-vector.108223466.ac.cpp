class Vector2D {
    int index;
    vector<vector<int>>::iterator it, iend;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        it = vec2d.begin();
        iend = vec2d.end();
        index = 0;
    }

    int next() {
        return (*it)[index++];
    }

    bool hasNext() {
        while(it != iend && index == (*it).size()) {
            it++;
            index = 0;
        }
        return it != iend;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */