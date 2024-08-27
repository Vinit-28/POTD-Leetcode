// Problem Link : https://leetcode.com/problems/fraction-addition-and-subtraction/description/



// Solution //
class Solution {
public:
    string fractionAddition(string exp) {
        vector<int> num, den;
        vector<char> signs;
        int start = exp[0]=='-'? 1 : 0;
        int ele = 0;
        char prevSym = '~';
        for(int idx=start; idx<exp.length(); idx++){
            if( exp[idx] >= '0' && exp[idx] <= '9' ){
                ele = (ele*10)+(exp[idx]-'0');
            } else{
                if( prevSym == '/' ) den.push_back(ele);
                else num.push_back(ele);
                if( prevSym == '+' || prevSym == '-' ) signs.push_back(prevSym);
                prevSym = exp[idx];
                ele = 0;
            }
        }
        den.push_back(ele);
        if( prevSym == '+' || prevSym == '-' ) signs.push_back(prevSym);
        num[0] = exp[0] == '-'? -num[0] : num[0];
        int lcmVal = getLCM(den);
        int sum = (num[0] * (lcmVal / den[0]));
        for(int idx=1; idx<num.size(); idx++){
            int val = (num[idx] * (lcmVal / den[idx]));
            if( signs[idx-1] == '+' ) sum += val;
            else sum -= val;
        }
        bool isNegative = sum<0;
        sum = abs(sum);
        doDivision(sum, lcmVal);
        sum = isNegative? -sum : sum;
        if( sum%lcmVal == 0 ) return to_string(sum/lcmVal) + "/1";
        return to_string(sum) + "/" + to_string(lcmVal);
    }

    int getLCM(vector<int> &arr){
        int val = 1;
        for(auto &ele : arr){
            val = lcm(val, ele);
        }
        return val;
    }

    void doDivision(int &a, int &b){
        if( a==0 ){
            b=1;
            return;
        }
        if( a==1 || b==1 ) return;
        int maxi = max(a,b);
        for(int d=2; d<=sqrt(maxi); d++){
            if( a%d==0 && b%d==0 ){
                int m = min(a/d, b/d);
                a /= d;
                b /= d;
                doDivision(a, b);
                break;
            }
        }
    }
};