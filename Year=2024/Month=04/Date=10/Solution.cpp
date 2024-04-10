// Problem Link : https://leetcode.com/problems/time-needed-to-buy-tickets/description/


// Solution //
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> dq;
        dq.push_front(deck.back());
        for(int idx=deck.size()-2; idx>=0; idx--){
            int currEle = deck[idx];
            // Poping the last element of the queue //
            int lastEle = dq.back(); dq.pop_back();
            // Inserting the popped element in the front //
            dq.push_front(lastEle);
            // Inserting the current new element in the front //
            dq.push_front(currEle);
        }
        vector<int> revealedOrder(dq.begin(), dq.end());
        return revealedOrder;
    }
};