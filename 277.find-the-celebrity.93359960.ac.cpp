// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for(int i = 0; i < n; i++) {
            if(!knows(i, candidate)) {
                candidate = i;
            }
        }
        //validate candidate
        for(int i = 0; i < n; i++) {
            if(i != candidate && (!knows(i, candidate) || knows(candidate, i))) {
                return -1;
            }
        }
        return candidate;
    }
};