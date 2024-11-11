// Problem Link : https://leetcode.com/problems/prime-subtraction-operation/description/


// Solution //
class PrimeNumbers{
public:
    vector<int> primes;
    PrimeNumbers(){
        int n = 1001;
        primes = {0, 2};
        for(int num=3; num<=n; num+=2){
            if( isPrime(num) ) primes.push_back(num);
        }
    } 
    
    bool isPrime(int num){
        if( num&1 == 0 ) return false;
        for(int i=3; i<=sqrt(num); i+=2){
            if( num%i == 0 ) return false;
        }
        return true;
    }
    
    int getClosestPrimeNumber(int num){
        if( num <= 0 ) return 0;
        int idx = lower_bound(begin(primes), end(primes), num) - begin(primes);
        if( idx == 0 ) return primes[idx];
        if( idx < primes.size() && primes[idx] == num ) return primes[idx];
        return primes[idx-1];
    }
};

PrimeNumbers pn;

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int prev = 0;
        for(auto &ele : nums){
            int diff = ele - prev - 1;
            int red = pn.getClosestPrimeNumber(diff);
            if( red == -1 ) return false;
            int newEle = ele - red;
            if( newEle <= prev ) return false;
            prev = newEle;
        }
        return true;
    }
};