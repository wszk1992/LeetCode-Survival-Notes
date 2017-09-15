class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || !canDecodePerUnit(s.substr(0,1))){
            return 0;
        }
        
        vector<int> dp(s.length()+1, 1);
        dp[1] = 1;
        
        for(int i = 2; i <= s.length(); i++){
            dp[i] = dp[i-1] * canDecodePerUnit(s.substr(i-1,1)) + dp[i-2] * canDecodePerUnit(s.substr(i-2,2));
            if(dp[i] == 0){
                return 0;
            }
            //cout << "dp " << i << ": " << dp[i] << endl;
        }
        
        return dp[s.length()];
    }
    
    bool canDecodePerUnit(string s){
        //cout << "decode : " << s <<endl;
        if(s.length() == 1){
            if(s[0] >= '1' && s[0] <= '9'){
                return true;
            }
            else{
                return false;
            }
        }
        // else if(s.length() == 2){
        //     if(s[0] <= '0' || s[0] > '9' || s[1] < '0' || s[1] > '9'){
        //         return 0;
        //     }
        //     if(s[0] >= '3' || (s[0] == '2' && s[1] > '6')){
        //         if(s[1] == '0'){
        //             return 0;
        //         }
        //         else{
        //             return 1;
        //         }
        //     }
        //     else if(s[1] == '0'){
        //         return 1;
        //     }
        //     else{
        //         return 2;
        //     }
        // }
        else if(s.length() == 2){
            if((s[0] == '1' && s[1] >= '0' && s[1] <= '9') || (s[0] == '2' && s[1] >= '0' && s[1] <= '6'))
                return true;
            else
                return false;
        }
        else{
            cout << "length of decode unit WRONG!!!"<<endl;
            exit(0);
        }
    }
    
    // char decode(string s){
    //     if(s.length() == 1){
    //         return 'A' + s[0] - '1';
    //     }
    //     else if(s.length() == 2){
    //         return 'A' + (s[0] - '0') * 10 + s[1] - '1';
    //     }
    //     else{
    //         cout << "error in decode" << endl;
    //         exit(0);
    //     }
    // }
};

// //1234
// dp[0] = 1
// dp[1] = 2
// dp[2] = dp[1] * 1 + dp[0] * 2 

// //4051
// dp[0] = 1
// dp[1] = 1    (1 if have 0, 0 if x0 > 26 or 0x)
// dp[2] = dp[1] * 1 + dp[0] * 2

// if dp[x] == 0  break