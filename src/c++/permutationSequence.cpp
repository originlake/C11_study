#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		const string a = "123456789";
		k--;
		string res(a.begin(), a.begin() + n);
		for (int i = 0; i < n-1; i++) {
			int pos = k / fact(n - i - 1);
			k = k-pos * fact(n - i - 1);
			char tmp = res[i+pos];
			res.erase(res.begin() + pos + i);
			res.insert(res.begin()+i, tmp);
		}
		cout << res << endl;
		return res;
	}

	int fact(int n) {
		return n <= 1 ? 1 : n * fact(n - 1);
	}
};

int main() {
	Solution().getPermutation(9, Solution().fact(9));
}
