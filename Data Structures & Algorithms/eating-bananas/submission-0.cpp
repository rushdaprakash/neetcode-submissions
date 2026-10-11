class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed=1;
        int maxSpeed=0;
        for(int pile: piles){
            maxSpeed= max(maxSpeed, pile);}
        while(minSpeed< maxSpeed){
            int mid= minSpeed+(maxSpeed-minSpeed)/2;
            
        if(canEatInTime(piles,h, mid)) maxSpeed=mid;
        else minSpeed= mid+1;}
        
        return minSpeed;
    }
    int canEatInTime(vector<int>& piles, int h, int speed ){
        int hours=0;
        for(int pile:piles){
            hours += ceil((double)pile/speed);
        }return hours <=h;
    }
};
