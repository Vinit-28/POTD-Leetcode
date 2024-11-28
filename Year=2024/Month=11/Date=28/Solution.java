// Problem Link : https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/


// Solution //
class Pair{
    public int first;
    public int second;
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
    private int dirRow[] = {1,-1,0,0};
    private int dirCol[] = {0,0,1,-1};
    
    private boolean isCellValid(int m, int n, int i, int j){
        return !(i<0 || j<0 || i>=m || j>=n);    
    }
    
    public int minimumObstacles(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>(new PairComparator());
        int ans[][] = new int[m][n];
        for(int []row : ans) Arrays.fill(row, Integer.MAX_VALUE);
        
        ans[m-1][n-1] = grid[m-1][n-1];
        pq.add(new Pair(ans[m-1][n-1], (m-1)*n+(n-1)));
        while( pq.isEmpty()==false ){
            int size = pq.size();
            while( size-- > 0 ){
                Pair currPair = pq.poll();
                int cost = currPair.first;
                int id = currPair.second;
                int row = id/n, col = id%n;
                if( row == 0 && col == 0 ){
                    return cost;
                } else if( cost == ans[row][col] ){
                    for(int k=0; k<4; k++){
                        int nextRow = row + dirRow[k];
                        int nextCol = col + dirCol[k];
                        if( isCellValid(m, n, nextRow, nextCol) ){
                            int newCost = cost + grid[nextRow][nextCol];
                            if( newCost < ans[nextRow][nextCol] ){
                                ans[nextRow][nextCol] = newCost;
                                pq.add(new Pair(newCost, nextRow*n+nextCol));
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
}