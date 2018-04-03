#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j=n-1,tmp;
        int i=n-1;
        while(j>0 && nums[j]<=nums[j-1]){
            j--;
        }
        if(j>0){
            while(nums[i]<=nums[j-1]){
                i--;
            }
            tmp=nums[j-1];
            nums[j-1]=nums[i];
            nums[i]=tmp;
        }
        i=n-1;
        while(j<i){
            tmp=nums[j];
            nums[j]=nums[i];
            nums[i]=tmp;
            j++;
            i--;
        }
    }
};

int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(5);


    Solution().nextPermutation(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
