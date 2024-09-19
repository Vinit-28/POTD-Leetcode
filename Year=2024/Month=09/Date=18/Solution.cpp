// Problem Link : https://leetcode.com/problems/different-ways-to-add-parentheses/description/


// Solution //
class Solution {
private:
    bool isOperand(char &ch){
        return (ch=='+' || ch=='-' || ch=='*');
    }

    int doOperation(int val1, int val2, char operand){
        return (operand=='+'? val1 + val2 : operand=='-'? val1 - val2 : val1 * val2);
    }
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;
        int n = exp.size();
        for(int idx=0; idx<n; idx++){
            if( isOperand(exp[idx]) ){
                char operand = exp[idx];
                vector<int> left = diffWaysToCompute(exp.substr(0, idx));
                vector<int> right = diffWaysToCompute(exp.substr(idx+1, n-idx-1));
                for(auto &l : left){
                    for(auto &r : right){
                        ans.push_back(doOperation(l, r, operand));
                    }
                }
            }
        }
        if( ans.empty() ){
            ans.push_back(stoi(exp));
        }
        return ans;
    }
};