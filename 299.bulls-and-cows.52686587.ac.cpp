class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> secret_map;
        int bulls=0;
        int cows=0;
        unordered_map<char, int>::const_iterator got;
        for(int i=0;i<secret.length();i++)
        {
            if(secret[i]==guess[i])
                bulls++;
            else if ((got=secret_map.find(secret[i]))!=secret_map.end())
                secret_map[secret[i]]++;    
            else
                secret_map.insert({secret[i],1});
        }
        for(int i=0;i<secret.length();i++)
        {
            if((got=secret_map.find(guess[i]))!=secret_map.end()&&secret[i]!=guess[i])
            {
                cows++;
                if(secret_map[guess[i]]>1)
                    secret_map[guess[i]]--;
                else
                    secret_map.erase(guess[i]);
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};