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
void print(node *&top);											//	����� ��������� ����� �� �����
node *check(node *&top, char symbol, bool *answer);				//	�������� �� ������� �������� � �����
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

void print(node *&top)
{
	while (top)
	{
		cout << top->symbol;
		node *pv = top;
		top = top->p;
		delete pv;
	}
	cout << endl;
}

node *check(node *&top, char symbol, bool *answer)
{
	(*answer) = false;
	node *new_top = NULL;
	while (top)
	{
		if (top->symbol == symbol)
		{
			(*answer) = true;
		}
		push(new_top, top->symbol);
		node *pv = top;
		top = top->p;
		delete pv;
	}
	return new_top;
}

void create(node *&top, node *first, node *second)
{
	while (first)
	{
		bool answer1 = false;
		bool answer2 = false;
		top=check(top, first->symbol, &answer1);
		second=check(second, first->symbol, &answer2);
		if (!answer1 && !answer2)
		{
			node *pv;
			pv = new node;
			pv->symbol = first->symbol;
			pv->p = top;
			top = pv;
		}
		node *pv = first;
		first = first->p;
		delete pv;
	}
}