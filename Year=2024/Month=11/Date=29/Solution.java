// Problem Link : https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/


// Solution //
class Pair{
    int first, second;
    Pair(int first, int second){
        this.first = first;
        this.second = second;
    }
}

class PairComparator implements Comparator<Pair>{
    public int compare(Pair a, Pair b){
        return a.first - b.first;
    }
}

class Solution {
    int dirRow[] = {1,-1,0,0};
    int dirCol[] = {0,0,1,-1};
    
    boolean isValid(int m, int n, int i, int j){
        return !(i<0 || j<0 || i>=m || j>=n);
    }
    
    public int minimumTime(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int ans[][] = new int [m][n];
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>(new PairComparator());
        for(int []row: ans) Arrays.fill(row, (int)1e9);
        
        ans[0][0] = grid[0][0];
        pq.offer(new Pair(grid[0][0], 0));
        while( pq.isEmpty() == false ){
            Pair currPair = pq.poll();
            int time = currPair.first;
            int row = currPair.second/n;
            int col = currPair.second%n;
            
            if( row==m-1 && col==n-1 ){
                return time;
            } else if( ans[row][col] == time ){
                boolean flag = false;
                for(int k=0; k<4; k++){
                    int nextRow = row + dirRow[k];
                    int nextCol = col + dirCol[k];
                    if( isValid(m, n, nextRow, nextCol) ){
                        int newTime = time + 1;
                        if( newTime >= grid[nextRow][nextCol] ){
                            flag = true;
                        }
                    }
                }
                
                for(int k=0; k<4; k++){
                    int nextRow = row + dirRow[k];
                    int nextCol = col + dirCol[k];
                    if( isValid(m, n, nextRow, nextCol) ){
                        int newTime = time + 1;
                        if( newTime < ans[nextRow][nextCol] ){
                            if( newTime >= grid[nextRow][nextCol] ){
                                ans[nextRow][nextCol] = newTime;
                                pq.offer(new Pair(newTime, nextRow*n+nextCol));
                            } else if( flag ){
                                int diff = grid[nextRow][nextCol] - newTime;
                                newTime = (diff&1)==1? grid[nextRow][nextCol]+1 : grid[nextRow][nextCol];
                                ans[nextRow][nextCol] = newTime;
                                pq.offer(new Pair(newTime, nextRow*n+nextCol));
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
}