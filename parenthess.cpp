#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool matching(const string &str)
{
	stack<char> charStk;
	for (const auto &s : str) {
		if (s == '(') {
			charStk.push(s);
		}
		else if (s == ')') {
			bool hit = false;
			while (!charStk.empty()) {
				char &c = charStk.top();
				if (c == '(') {
					charStk.pop();
					hit = true;
					break;
				}
				charStk.pop();
			}
			if (!hit) {
				return false;
			}
		}
		else {
			// alphabetic character
			charStk.push(s);
		}
	}
	if (charStk.empty()) {
		return true;
	}
	return false;
}

// assume the first symbol must be '('
bool matching1(const string &str)
{
	stack<char> charStk;
	for (const auto &s : str) {
		if (s == '(') {
			charStk.push(s);
		}
		else if (s == ')') {
			if (!charStk.empty()) {
				char &c = charStk.top();
				if (c == '(') {
					charStk.pop();
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
	}
	if (charStk.empty()) {
		return true;
	}
	return false;
}

int main(int argc, char *argv[])
{
	cout << matching("(a)") << endl;
	cout << matching("(ab") << endl;
	cout << matching(")(") << endl;
	cout << matching("(a(b(c)))") << endl;

	cout << matching1("(a)") << endl;
	cout << matching1("(ab") << endl;
	cout << matching1(")(") << endl;
	cout << matching1("(a(b(c)))") << endl;

	return 0;
}
