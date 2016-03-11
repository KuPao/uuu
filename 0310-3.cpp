#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Input(vector<string>&);
void SetAndPrint(vector<string>&);

int main()
{
	vector<string> code(0);
	
	Input(code);
	SetAndPrint(code);

	system("pause");
}

void Input(vector<string>& code)
{
	string str;
	while (1)
	{
		getline(cin, str);
		if (str == "END_OF_CODE") {
			break;
		}
		else
		{
			code.push_back(str);
		}
	}
}

void SetAndPrint(vector<string>& code)
{
	int i, j;
	char a;
	int numOfTab = 0;
	bool needEnter = true;
	for (i = 0; i < code.size(); i++)
	{
		for (j = 0; j < code[i].size(); j++)
		{
			a = code[i][j];
			switch (a)
			{
			case'{':
				cout << '\n';
				for (int k = 0; k < numOfTab; k++)
				{
					cout << '\t';
				}
				numOfTab++;
				cout << "{" << endl;
				for (int k = 0; k < numOfTab; k++)
				{
					cout << '\t';
				}
				for (; j + 1 < code[i].size(); j++) {
					if (code[i][j + 1] != ' ') {
						break;
					}
				}
				break;
			case'}':
				numOfTab--;
				cout << "}" << endl;
				for (int k = 0; k < numOfTab; k++)
				{
					cout << '\t';
				}
				if (numOfTab == 0) cout << endl;
				for (; j + 1 < code[i].size(); j++) {
					if (code[i][j + 1] != ' ') {
						break;
					}
				}
				break;
			case';':
				if (needEnter)
				{
					cout << ";" << endl;
					for (; j + 1 < code[i].size(); j++) {
						if (code[i][j + 1] != ' ') {
							if (code[i][j + 1] != '}') {
								for (int k = 0; k < numOfTab; k++)
								{
									cout << '\t';
								}
							}
							else {
								for (int k = 0; k < numOfTab - 1; k++)
								{
									cout << '\t';
								}
							}
							break;
						}
					}
				}
				else
				{
					cout << ";";
				}
				break;
			case'(':
				needEnter = false;
				cout << "(";
				break;
			case')':
				needEnter = true;
				cout << ")";
				break;
			default:
				cout << code[i][j];
				break;
			}
			if ((i + 2 == code.size()) && (j + 2 == code[i].size())) break;
		}
	}
	if (code[i - 2][code[i - 2].size() - 1] == '}') {
		for (int k = 2; code[i - 2].size() - k > 0; k++) {
			if (code[i - 2][code[i - 2].size() - k] != ' ') {
				if (code[i - 2][code[i - 2].size() - k] == '{') {
					cout << endl;
				}
				break;
			}
		}
	}
	cout << code[i - 2][code[i - 2].size() - 1];
}