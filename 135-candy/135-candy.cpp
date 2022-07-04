class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
    if(n == 1) return 1;
    vector<int> candies(n,1);
    
    for(int i=1; i<n; i++)
    {
        if(ratings[i] >ratings[i-1])
        {
            candies[i]+=candies[i-1];
        }
    }

    for(int i=n-2; i>-1; i--)
    {
        if(ratings[i] > ratings[i+1])
        {
            if(candies[i] > candies[i+1]) continue;
            candies[i] = max(candies[i], candies[i+1])+1;
        }
    }

    int sum = 0;
    for(auto x: candies)
    {
        sum+=x;
    }
    return sum;
    }
};