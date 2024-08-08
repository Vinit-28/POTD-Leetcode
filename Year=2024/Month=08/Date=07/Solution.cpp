// Problem Link : https://leetcode.com/problems/integer-to-english-words/description/


// Solution //
class Solution {
public:
    vector<pair<int,string>> preCal = {
        {1000000000, "Billion"},
        {1000000, "Million"},
        {1000, "Thousand"},
        {100, "Hundred"},
        {90, "Ninety"},
        {80, "Eighty"},
        {70, "Seventy"},
        {60, "Sixty"},
        {50, "Fifty"},
        {40, "Forty"},
        {30, "Thirty"},
        {20, "Twenty"},
        {19, "Nineteen"},
        {18, "Eighteen"},
        {17, "Seventeen"},
        {16, "Sixteen"},
        {15, "Fifteen"},
        {14, "Fourteen"},
        {13, "Thirteen"},
        {12, "Twelve"},
        {11, "Eleven"},
        {10, "Ten"},
        {9, "Nine"},
        {8, "Eight"},
        {7, "Seven"},
        {6, "Six"},
        {5, "Five"},
        {4, "Four"},
        {3, "Three"},
        {2, "Two"},
        {1, "One"}
    };

    string numberToWords(int num) {
        if( num == 0 ) return "Zero";
        for(auto &p : preCal){
            if( num >= p.first ){
                string left = "";
                string middle = p.second;
                string right = "";
                // Adding Number of Billion/Million/Thousand/Hundred //
                if( num >= 100 ){
                    left = numberToWords(num/p.first) + " ";
                }
                // Adding the Final Value //
                if( num%p.first != 0 ){
                    right = " " + numberToWords(num%p.first);
                }
                return left + middle + right;
            }
        }    
        return "";
    }
};
