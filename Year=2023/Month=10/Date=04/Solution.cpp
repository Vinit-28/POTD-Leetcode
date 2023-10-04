// Problem Link : https://leetcode.com/problems/design-hashmap/description/


// Solution //
class MyHashMap {
public:
    vector<vector<pair<int, int>>> hashTable;
    int sizeLimit = 1e4;
    MyHashMap() {
        hashTable = vector<vector<pair<int, int>>>(sizeLimit);
    }
    
    void put(int key, int value) {
        int baseIdx = getBaseIdx(key);
        int exactIdx = getExactIdx(baseIdx, key);
        if( exactIdx != -1 ){
            hashTable[baseIdx][exactIdx].second = value;
        } else{
            hashTable[baseIdx].push_back({key, value});
        }
    }
    
    int get(int key) {
        int baseIdx = getBaseIdx(key);
        int exactIdx = getExactIdx(baseIdx, key);
        if( exactIdx != -1 ){
            return hashTable[baseIdx][exactIdx].second;
        }
        return -1;
    }
    
    void remove(int key) {
        int baseIdx = getBaseIdx(key);
        int exactIdx = getExactIdx(baseIdx, key);
        if( exactIdx != -1 ){
            auto &v = hashTable[baseIdx];
            v.erase(v.begin() + exactIdx);
        }
    }

    int getBaseIdx(int key){
        return key % sizeLimit;
    }

    int getExactIdx(int baseIdx, int key){
        int n = hashTable[baseIdx].size();
        for(int i=0;i<n;i++){
            if( hashTable[baseIdx][i].first == key ){
                return i;
            }
        }
        return -1;
    }
};