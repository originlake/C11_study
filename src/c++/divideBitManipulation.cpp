#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        long long sign=(dividend<0 != divisor<0)?-1:1;
        dividend=dividend>0?dividend:-dividend;
        divisor=divisor>0?divisor:-divisor;
        long long tmp=1,ans=0;
        long long div=divisor;
        while(dividend>=divisor){
            while(dividend>=(div<<1)){
                div<<=1;
                tmp<<=1;
            }
            ans=ans+tmp;
            dividend=dividend-divisor*tmp;
            div=divisor;
            tmp=1;
        }
        return sign*ans;
    }
};
