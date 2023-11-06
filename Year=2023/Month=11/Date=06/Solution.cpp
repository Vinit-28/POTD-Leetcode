// Problem Link : https://leetcode.com/problems/seat-reservation-manager/description/


// Solution //
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> hp;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            hp.push(i);
        }
    }
    
    int reserve() {
        int seatNumber = hp.top();
        hp.pop();
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        hp.push(seatNumber);
    }
};