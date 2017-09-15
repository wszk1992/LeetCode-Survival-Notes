class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        if(flights.empty() || days[0].empty()) {
            return 0;
        }
        int maxDays = 0;
        //cities
        int N = flights.size();
        //weeks
        int K = days[0].size();
        vector<vector<int>> dp(K + 1, vector<int>(N, 0));
        vector<vector<bool>> arrived(K + 1, vector<bool>(N, 0));
        arrived[0][0] = 1;
        for(int i = 1; i <= K; i++) {
            for(int j = 0; j < N; j++) {
                for(int from = 0; from < N; from++) {
                    if(arrived[i - 1][from] && (flights[from][j] || from == j)) {
                        arrived[i][j] = 1;
                        break;
                    }
                }
            }
            for(int j = 0; j < N; j++) {
                //max vacation days in i week in j city
                if(i == 1) {
                    if(j == 0 || flights[0][j]) {
                        dp[i][j] = days[j][i - 1];
                    }
                } else if(arrived[i][j]) {
                    for(int from = 0; from < N; from++) {
                        if((from == j) || flights[from][j]) {
                            dp[i][j] = max(dp[i][j], dp[i - 1][from] + days[j][i - 1]);
                        }
                    }
                }
            }
            // for(int j = 0; j < N; j++) {
            //     cout << dp[i][j] << " ";
            // }
            // cout << endl;
        }
        for(int j = 0; j < N; j++) {
            maxDays = max(maxDays, dp[K][j]);
        }
        return maxDays;
    }
};