#include<algorithm>
#include<climits>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> answer;
        auto maxElement = max_element(candies.begin(), candies.end());

        for(int i=0; i<candies.size(); i++){
          if(candies[i]+extraCandies >= *maxElement) answer.push_back(1);
          else answer.push_back(0);
        }
        return answer;
    }

  double findMaxAverage(vector<int>& nums, int k) {
    int max_sum = INT_MIN;
    int cur_sum=0;
    int beg=0;

    // now we have the first k elements (k=3.. 0-2 inclusive)
    while(beg < k){
      cur_sum += nums[beg];
      beg++;
    }
    max_sum = cur_sum;
    for(int i=k; i<nums.size(); i++){
      cur_sum -= nums[i-k];
      cur_sum += nums[i];
      max_sum = max(cur_sum, max_sum);
    }

    return double(max_sum)/k;
  }
};

int main(){

    return 0;
}