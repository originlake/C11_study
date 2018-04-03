#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int n=nums.size();
        int step,i;
        if(target>=nums[0]){
            i=0;
            while(i==0 || (i<n && nums[i-1]<=nums[i])){
                if(nums[i]==target){
                    return i;
                }
                i+=1;
            }
        }else if(target<=nums[n-1]){
            i=n-1;
            step=-1;
            while(i==n-1 || (i>0&& nums[i]<=nums[i+1])){
                if(nums[i]==target){
                    return i;
                }
                i+=step;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> a;
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);


    cout<<Solution().search(a)<<endl;
    return 0;
}
