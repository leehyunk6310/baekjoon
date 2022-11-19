#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int test_case;
	int T;
	int arr[200];
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{		
		cin >> arr[test_case];
	}

	sort(arr, arr + T-1);

	cout << arr[T / 2 ] << '\n';

	return 0;
}