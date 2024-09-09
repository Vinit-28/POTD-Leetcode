// Problem Link : https://leetcode.com/problems/spiral-matrix-iv/description/


// Solution //
class Solution {
private:
    void move(int startRow, int startCol, int endRow, int endCol, vector<vector<int>> &mat, ListNode *&node){
        int row = startRow, col = startCol;
        // Moving Right //
        while( node && col < endCol ){
            mat[row][col] = node->val;
            node = node->next;
            col += 1;
        }
        row = startRow + 1;
        col = endCol-1;
        // Moving Down //
        while( node && row < endRow ){
            mat[row][col] = node->val;
            node = node->next;
            row += 1;
        }
        row = endRow-1;
        col = endCol-2;
        // Moving Left //
        while( node && col >= startCol ){
            mat[row][col] = node->val;
            node = node->next;
            col -= 1;
        }
        col = startCol;
        row = endRow-2;
        // Moving Up //
        while( node && row > startRow ){
            mat[row][col] = node->val;
            node = node->next;
            row -= 1;
        }
    }
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int start = 0;
        int endRow = m, endCol = n;
        vector<vector<int>> mat(m, vector<int>(n, -1));
        ListNode *node = head;
        while( node && (start <= endRow || start <= endCol) ){
            move(start, start, endRow, endCol, mat, node);
            if( node ) cout<<"Alive "<<node->val<<endl;
            else cout<<"Dead"<<endl;
            start += 1;
            endRow -= 1;
            endCol -= 1;
        }
        return mat;
    }
};