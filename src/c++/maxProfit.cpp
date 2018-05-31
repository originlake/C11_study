#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = (int)prices.size();
		if (n == 0) return 0;
		int sell1 = 0, sell2 = 0, buy1 = -prices[0], buy2 = sell1 - prices[0];
		for (int i = 0; i < n; i++) {
			buy1 = max(buy1, -prices[i]);
			sell1 = max(sell1, buy1 + prices[i]);
			buy2 = max(buy2, sell1 - prices[i]);
			sell2 = max(sell2, buy2 + prices[i]);
		}
		return sell2;
	}
	int maxProfit2(vector<int>& prices) {
		int n = (int)prices.size();
		int profit = 0;
		int curmax = 0;
		int buy = prices[0];
		for (int i = 0; i < n-1; i++) {
			if (prices[i] > prices[i + 1]) {
				buy = prices[i + 1];
				profit += (prices[i] - buy);
			}
		}
		return profit;
	}
	int maxProfit1(vector<int>& prices) {
		int n = (int)prices.size();
		int profit = 0;
		int buy = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (prices[i] < buy) {
				buy = prices[i];
			}
			profit = max(profit, buy - prices[i]);
		}
		return profit;
	}
};
int main() {
	vector<int> price{ 2,1,2,0,1 };
	int n=Solution().maxProfit(price);
	return 0;
}
