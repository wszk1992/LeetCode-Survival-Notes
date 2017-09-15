class Solution {
public:
    //Method1: check each number if it's prime  : TIME LIMIT EXCEEDED
    // int countPrimes(int n) {
    //     int count=0;
    //     for(int i=2;i<n;i++)
    //         if(isPrime(i))
    //             count++;
    //     return count;
    // }
    // bool isPrime(int n)
    // {
    //     for(int i=2;i*i<=n;i++)
    //     {
    //         if(n%i==0)
    //             return false;
    //     }
    //     return true;
    // }
    
    
    //Method2: Sieve of Eratosthenes: unordered_set   Time limit exceeded
    // int countPrimes(int n) {
    //     unordered_set<int> set;
    //     int count=0;
    //     for(int i=2;i*i<n;i++)
    //     {
    //         if(set.find(i)==set.end())
    //         {
    //             for(int j=i;i*j<n;j++)
    //                 set.insert(i*j);
    //         }
                
    //     }
    //     return n-2-set.size();
    // }
    
    //Method2: Sieve of Eratosthenes: Array
    int countPrimes(int n) {
        int* num = new int[n];
        for(int i=2;i<n;i++)
            num[i]=true;
        int count=0;
        for(int i=2;i*i<n;i++)
        {
            if(num[i])
            {
                for(int j=i;i*j<n;j++)
                    num[i*j]=false;
            }
                
        }
        for(int i=2;i<n;i++)
        {
            if(num[i])
                count++;
        }
        return count;
    }
};