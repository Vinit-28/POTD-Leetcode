// Problem Link : https://leetcode.com/problems/flatten-nested-list-iterator/description/


// Solution //
class NestedIterator {
public:
    int idx, size;
    vector<int> arr;

    NestedIterator(vector<NestedInteger> &nestedList) {
        idx = 0;
        arr = vector<int>();
        flatten(nestedList);
        size = arr.size();
    }

    void flatten(vector<NestedInteger> &nestedList){
        for(auto &nl : nestedList){
            if( nl.isInteger() ){
                arr.push_back(nl.getInteger());
            } else{
                flatten(nl.getList());
            }
        }
    }

    int next() {
        return arr[idx++];
    }
    
    bool hasNext() {
        return idx < size;
    }
};