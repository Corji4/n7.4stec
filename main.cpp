#include <iostream>
#include <string>

using namespace std;

struct node
{
	char symbol;
	node* p;
};

void push(node *&top, char symbol);								//	���������� �������� � ����
void del(node *&top);											//	�������� �������� �� ������� �����
void print(node *top);											//	����� ��������� ����� �� �����
bool check(node *top, char symbol);								//	�������� �� ������� �������� � �����
void create(node *&top, node *first, node *second);				//	�������� ����� �� ������ ���� ������

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
	create(result, first, second);
	while (first)
	{
		del(first);
	}
	while (second)
	{
		del(second);
	}
	print(result);
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

bool check(node *top, char symbol)
{
	bool answer = false;
	while (top)
	{
		if (top->symbol == symbol)
		{
			answer = true;
		}
		top = top->p;
	}
	return answer;
}

void create(node *&top, node *first, node *second)
{
	while (first)
	{
		if (!check(top, first->symbol) && !check(second, first->symbol))
		{
			node *pv;
			pv = new node;
			pv->symbol = first->symbol;
			pv->p = top;
			top = pv;
		}
		first = first->p;
	}
}