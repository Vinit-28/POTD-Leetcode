// Problem Link : https://leetcode.com/problems/product-of-the-last-k-numbers/description/


// Solution //
class ProductOfNumbers {
public:
    vector<int> prefix;
    vector<int> zeros;
    ProductOfNumbers() {
        prefix = {1};
    }
    
    void add(int num) {
        if( num == 0 ) zeros.push_back(prefix.size());
        if( prefix.back() == 0 ){
            prefix.push_back(num);
        } else{
            prefix.push_back(num * prefix.back());
        }
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        int start = n - k;
        auto zeroPos = lower_bound(begin(zeros), end(zeros), start);
        // atleast one occurence of 0 in last K numbers //
        if( zeroPos != end(zeros) ){
            return 0;
        }
        int ans = prefix[start-1]==0? prefix[n-1] : (prefix[n-1]/prefix[start-1]);
        return ans;
    }
};