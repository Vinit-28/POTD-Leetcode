// Problem Link : https://leetcode.com/problems/design-a-number-container-system/description/


// Solution //
class NumberContainers {
private:
    unordered_map<int,int> idxToEle;
    unordered_map<int,set<int>> elsToIdxs;
public:
    NumberContainers() {
        idxToEle = unordered_map<int,int>();
        elsToIdxs = unordered_map<int,set<int>>();
    }
    
    void change(int index, int number) {
        if( !idxToEle.count(index) ){
            idxToEle[index] = number;
            elsToIdxs[number].insert(index);
        } else{
            int prevEle = idxToEle[index];
            elsToIdxs[prevEle].erase(index);
            idxToEle[index] = number;
            elsToIdxs[number].insert(index);
        }
    }
    
    int find(int number) {
        return elsToIdxs[number].empty()? -1 : *elsToIdxs[number].begin();
    }
};