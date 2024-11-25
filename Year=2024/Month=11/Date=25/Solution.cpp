// Problem Link : https://leetcode.com/problems/sliding-puzzle/description/


// Solution //
class Solution {
private:
    int dirRow[4] = {1,-1,0,0};
    int dirCol[4] = {0,0,1,-1};
    int m = 2, n = 3;
    string target = "123450";
    
    bool isValid(int i, int j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
public:
    pair<int,int> getIndices(int id){
        return {id/n, id%n};
    }
    
    int getId(int i, int j){
        return i*n+j;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        string source = "";
        unordered_set<string> visited;
        queue<string> q;
        int moves = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                source += to_string(board[i][j]);
            }
        }
        q.push(source);
        visited.insert(source);
        while( q.empty()==false ){
            int size = q.size();
            while( size-- > 0 ){
                auto state = q.front(); q.pop();
                if( state == target ){
                    return moves;
                } else{
                    int id;
                    for(int i=0; i<6; i++){
                        if( state[i] == '0' ){
                            id = i;
                            break;
                        }
                    }
                    auto [i, j] = getIndices(id);
                    for(int k=0; k<4; k++){
                        int nexti = i + dirRow[k];
                        int nextj = j + dirCol[k];
                        if( isValid(nexti, nextj) ){
                            string newState = state;
                            int nextId = getId(nexti, nextj);
                            swap(newState[id], newState[nextId]);
                            if( !visited.count(newState) ){
                                visited.insert(newState);
                                q.push(newState);
                            }
                        }
                    }
                }
            }
            moves += 1;
        }
        return -1;
    }
};