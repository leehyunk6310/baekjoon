#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int test_case;
	int T;
	cin >> T;
	// u_map을 사용해서 strng-> num으로 바꾸고 벡터를 정렬한다.
	// 다른 u_map을 사용해 num -> string으로 바꾼다.
	unordered_map<string, int> m1;
	m1["ZRO"] = 0;
	m1["ONE"] = 1;
	m1["TWO"] = 2;
	m1["THR"] = 3;
	m1["FOR"] = 4;
	m1["FIV"] = 5;
	m1["SIX"] = 6;
	m1["SVN"] = 7;
	m1["EGT"] = 8;
	m1["NIN"] = 9;
	unordered_map<int, string> m2;
	m2[0] = "ZRO";
	m2[1] = "ONE";
	m2[2] = "TWO";
	m2[3] = "THR";
	m2[4] = "FOR";
	m2[5] = "FIV";
	m2[6] = "SIX";
	m2[7] = "SVN";
	m2[8] = "EGT";
	m2[9] = "NIN";

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		int n;
		vector<int> v1;
		vector<string> v2;

		cin >> s >> n;

		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			v1.push_back(m1[str]);
		}

		sort(v1.begin(), v1.end());

		for (auto vv : v1)
		{
			v2.push_back(m2[vv]);
		}

		cout << s << "\n";
		for (auto vv : v2)
			cout << vv << " ";
		cout << '\n';
	}

	return 0;
}