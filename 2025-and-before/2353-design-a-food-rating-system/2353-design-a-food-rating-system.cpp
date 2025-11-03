class FoodRatings {
public:
    unordered_map<string,int>ratingMap;
    unordered_map<string,string>cuisineMap;
    unordered_map<string,map<int,set<string>>>db;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int n = foods.size();
        
        for(int i=0;i<n;i++){
            ratingMap[foods[i]] = ratings[i];
            cuisineMap[foods[i]] = cuisines[i];
            db[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        
        string currCuisine = cuisineMap[food];
        int prevRating = ratingMap[food];

        db[currCuisine][prevRating].erase(food);

        if (db[currCuisine][prevRating].empty()) {
            db[currCuisine].erase(prevRating);
        }

        db[currCuisine][newRating].insert(food);
        ratingMap[food] = newRating;
    }
    
    string highestRated(string cuisine) {

        auto it = db[cuisine].rbegin();
        return *(it->second.begin()); 
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */