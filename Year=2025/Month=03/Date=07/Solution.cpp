// Problem Link : https://leetcode.com/problems/closest-prime-numbers-in-range/description/


// Solution //
class Utility{
public:
    vector<int> primes;
    int limit = 1e6;

    Utility(){
        vector<bool> isPrime(limit+1, true);
        isPrime[0] = isPrime[1] = false;
        for(long i=2; i<=limit; i++){
            if( !isPrime[i] ) continue;
            primes.push_back(i);
            for(long j=i*i; j<=limit; j+=i){
                isPrime[j] = false;
            }
        }
    }
};

Utility obj;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        auto &primes = obj.primes;
        int n = primes.size();
        int startIdx = (lower_bound(begin(primes), end(primes), left) - begin(primes));
        int endIdx = (upper_bound(begin(primes), end(primes), right) - begin(primes));
        int minDiff = 1e9;
        vector<int> ans = {-1, -1};
        for(int i=startIdx+1; i<endIdx; i++){
            int diff = primes[i] - primes[i-1];
            if( minDiff > diff ){
                minDiff = diff;
                ans = {primes[i-1], primes[i]};
            }
        }
        return ans;
    }
};