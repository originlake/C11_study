#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
//be sure to check overflow when trans negative to positive
using namespace std;
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) {
			return 1;
		}
		if (n < 0) {
			x = 1 / x;
			return x * myPow(x, -(n + 1));
		}
		return n % 2 == 0 ? myPow(x*x, n / 2) : x * myPow(x*x, n / 2);
	}
};
int main() {
	cout<<Solution().myPow(2, INT_MIN)<<endl;

	return 0;
}
