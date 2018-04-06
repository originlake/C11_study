#include <string>
#include <conio.h>
#include <vector>
#include <map>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	string multiply(string num1, string num2) {
		string tmp;
		string sum = "0",mult;
		if (num1.size() < num2.size()) {
			tmp = num1;
			num1 = num2;
			num2 = tmp;
		}
		if (num2 == "0") return "0";
		int n = num2.size();
		for (int i = 0; i < n; i++) {
			mult = smult(num1 + string(i, '0'), num2[n - 1 - i]);
			sum = add(sum, mult);
		}
		return sum;
	}
	string smult(string num, char a) {
		int n = num.size() - 1;
		int sum = 0, res = 0;
		int i = a - '0';
		while (n >= 0) {
			sum = (num[n] - '0')*i+res;	
			res = 0;
			if (sum > 9) {
				res = sum / 10;
				sum = sum - res * 10;
			}
			string a = to_string(sum);
			num[n] = a[0];
			n--;
		}
		if (res > 0) {
			num = to_string(res) + num;
		}
		return num;
	}
	string add(string num1, string num2) {
		string tmp;
		int sum=0, res=0;
		if (num1.size() < num2.size()) num1 = string(num2.size() - num1.size(), '0') + num1;
		else num2 = string(num1.size() - num2.size(), '0') + num2;
		int n = num1.size()-1;
		while (n >= 0) {
			sum = (num1[n]-'0')+(num2[n]-'0')+res;
			res = 0;
			if (sum > 9) {
				res = 1;
				sum -= 10;
			}
			string a = to_string(sum);
			num1[n] = a[0];
			n--;
		}
		if (res > 0) {
			num1 = '1' + num1;
		}
		return num1;
	}
};
int main() {
	cout << Solution().multiply("1111111","10") << endl;
}
