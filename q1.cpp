#include<iostream>

#include<vector>

using namespace std;

vector<int> sliding_window(vector<int>& nums){
    int n=nums.size();
    vector<int> new_nums(n, 0);

    for(int i=0; i<n; i++){
        int left=0, right=0;
        if(left > 0) left=nums[i-1];
        if(right < n-1) right=nums[i+1];
        new_nums[i] = left+nums[i]+right;
    }
    return new_nums;
}

int new_position(int index, int size, int k){
    int new_index = (index+k) % size;
    return new_index;
}

int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    int k=3;
    int n=nums.size();
    vector<int> new_nums=nums;

    /*
        STEPS:
        Each value is shifting k places over
        - we can go out of bounds, so we need to do a modulo (%) to get it back in bounds
            10%10 = 0 
    */
    for(int i=0; i<n; i++){
        int new_ind = new_position(i, n, k);
        nums[new_ind] = new_nums[i];
    }

    // print rotated array
    for(int i:nums) cout << i << " ";
    cout << endl;


    return 0;
}