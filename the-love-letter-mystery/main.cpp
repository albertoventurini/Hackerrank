#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;


int moves_to_palindrome(string s)
{
	if(s.size() <= 1)
		return 0;

	char first = s[0];
	char last = s[s.size() - 1];

	return abs(first - last) + moves_to_palindrome(s.substr(1, s.size() - 2));

}

int main() {

	int T;
	cin >> T;

	string line;

	for(int i = 0; i < T; i++)
	{
		cin >> line;
		cout << moves_to_palindrome(line) << endl;
	}
    
    return 0;
}
