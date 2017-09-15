class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x[4] = {A, C, E, G};
        int y[4] = {B, D, F, H};
        sortArray(x, 4);
        sortArray(y, 4);
        int S;
        if(C < E || A > G || B > H || D < F) {
            S = 0;
        }
        else {
            S = (x[2]-x[1])*(y[2]-y[1]);
        }
        return (C-A)*(D-B)+(G-E)*(H-F)-S;
    }
    
    void sortArray(int *a, int len){
        while(len-- > 1) {
            for(int j = 0; j < len; j++) {
                if(a[j] > a[j+1]) {
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
    }
    
};

//x:ACEG
//y:BDFH
