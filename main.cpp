#include <iostream>
#include <string>

using namespace std;

struct node
{
	char symbol;
	node* p;
};

void push(node *&top, char symbol);  //	���������� �������� � ����
void del(node *&top);				//	�������� �������� �� ������� �����
void print(node *top);				//	����� ��������� ����� �� �����

int main()
{
	setlocale(LC_ALL, "RUS");
	node *first = NULL, *second = NULL, *result = NULL;
	cout << "������� ������ ����:\n";
	string stec;
	cin >> stec;
	for (int i = 0; i < stec.size(); i++)
	{
		push(first, stec.at(i));
	}
	cout << "������� ������ ����:\n";
	cin >> stec;
	for (int i = 0; i < stec.size(); i++)
	{
		push(second, stec.at(i));
	}
	system("pause");
	return 0;
}

void push(node *&top, char symbol)
{
	node *pv;
	pv = new node;
	pv->symbol = symbol;
	pv->p = top;
	top = pv;
}

void del(node *&top)
{
	node *pv;
	pv = top;
	top = top->p;
	delete pv;
}

void print(node *top)
{
	while (top)
	{
		cout << top->symbol << " ";
		top = top->p;
	}
	cout << endl;
}