#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct node
{
	int value;
	struct node* lChild;
	struct node* rChild;
	node(int a) :value(a), lChild(NULL), rChild(NULL){}
} node;

void initT(node* root)	//get the full binary tree
{
	int i, len;
	int counter = 1, level = 2;
	node* newOne,* tmp = NULL;
	queue<node*> container;
	container.push(root);
	while (level > 0)
	{
		len = container.size();
		for (i = 0; i < len; i++)
		{
			tmp = container.front();
			container.pop();

			newOne = new node(++counter);
			tmp->lChild = newOne;
			container.push(newOne);
			newOne = new node(++counter);
			tmp->rChild = newOne;
			container.push(newOne);
		}
		level--;
	}
	return;
}

void preO(node* T)
{
	if (T != NULL)
	{
		cout << T->value << " ";
		preO(T->lChild);
		preO(T->rChild);
	}
}

void inO(node* T)
{
	if (T != NULL)
	{
		inO(T->lChild);
		cout << T->value << " ";
		inO(T->rChild);
	}
}

void postO(node* T)
{
	if (T != NULL)
	{
		postO(T->lChild);
		postO(T->rChild);
		cout << T->value << " ";
	}
}

void inO2(node* root)
{
	node* T = root;
	stack<node*> s;
	while (T || !s.empty())
	{
		if (T)
		{
			s.push(T);
			T = T->lChild;
		}
		else
		{
			T = s.top();	//Remove the node visited
			s.pop();
			cout << T->value << " ";
			T = T->rChild;
		}
	}
	return;
}

void levelO(node* root)
{
	int i, len;
	node* tmp;
	queue<node*> container;
	container.push(root);
	while (!container.empty())
	{
		len = container.size();
		for (i = 0; i < len; i++)
		{
			tmp = container.front();
			container.pop();

			cout << tmp->value << " ";

			if (tmp->lChild)
				container.push(tmp->lChild);
			if (tmp->rChild)
				container.push(tmp->rChild);
		}
	}
	return;
}

int main()
{
	node* root = new node(1);
	initT(root);

	inO(root);
	cout << endl;

	inO2(root);
	cout << endl;

	levelO(root);
	cout << endl;
	return 0;
}