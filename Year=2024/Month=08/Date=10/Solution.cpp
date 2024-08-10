// Problem Link : https://leetcode.com/problems/regions-cut-by-slashes/description/


// Solution //
// Solution Idea From :: https://leetcode.com/problems/regions-cut-by-slashes/solutions/205680/java-c-python-split-4-parts-and-union-find/?envType=daily-question&envId=2024-08-10

// Disjoint Set Union //
class DSU{
public:
	vector<int> parents;
	int components;
	DSU(int n){
		this->parents.resize(n, -1);
		this->components = n;
	}

	int findParent(int node){
		if( parents[node] == -1 ){
			return node;
		}
		return parents[node] = findParent(parents[node]);
	}

	bool _union(int u, int v){
		if( isParentSame(u, v) ) return false;
		int pu = findParent(u);
		int pv = findParent(v);
		parents[pv] = pu;
		components -= 1;
		return true;
	}

	bool isParentSame(int u, int v){
		int pu = findParent(u);
		int pv = findParent(v);
		return pu == pv;
	}

    int getComponents(){
        return this->components;
    }
};

class Solution {
public:
    int getNode(int n, int i, int j, int k){
        return ((i*n+j)*4)+k;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU dsu(n*n*4);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if( i>0 ) dsu._union(getNode(n, i-1, j, 2), getNode(n, i, j, 0));
                if( j>0 ) dsu._union(getNode(n, i, j-1, 1), getNode(n, i, j, 3));
                if( grid[i][j] == '/' ){
                    dsu._union(getNode(n, i, j, 0), getNode(n, i, j, 3));
                    dsu._union(getNode(n, i, j, 1), getNode(n, i, j, 2));
                } else if( grid[i][j] == '\\' ){
                    dsu._union(getNode(n, i, j, 0), getNode(n, i, j, 1));
                    dsu._union(getNode(n, i, j, 2), getNode(n, i, j, 3));
                } else{
                    dsu._union(getNode(n, i, j, 0), getNode(n, i, j, 1));
                    dsu._union(getNode(n, i, j, 1), getNode(n, i, j, 2));
                    dsu._union(getNode(n, i, j, 2), getNode(n, i, j, 3));
                }
            }
        }
        return dsu.getComponents();
    }
};