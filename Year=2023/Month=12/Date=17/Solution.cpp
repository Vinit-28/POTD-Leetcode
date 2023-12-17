// Problem Link : https://leetcode.com/problems/design-a-food-rating-system/description/


// Solution //
class CustomComparator{
    public:
        bool operator()(pair<int, string> a, pair<int, string> b){
            if( a.first == b.first ){
                return a.second > b.second;
            }
            return a.first < b.first;
        }
};

class FoodRatings {
public:
    map<string, pair<string, int>> foodMap;
    map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, CustomComparator>> foodRatings;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        foodMap.clear();
        foodRatings.clear();
        int n = foods.size();
        for(int i=0;i<n;i++){
            string food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            foodMap[food] = {cuisine, rating};
            foodRatings[cuisine].push({rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        foodMap[food].second = newRating;
        string cuisine = foodMap[food].first;
        foodRatings[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        while( true ){ 
            auto p = foodRatings[cuisine].top();
            if (p.first != foodMap[p.second].second){
                foodRatings[cuisine].pop();
            } else{
                break;
            }
        }
        return foodRatings[cuisine].top().second;
    }
};