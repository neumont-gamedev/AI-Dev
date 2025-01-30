#include "Node.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using char_node_t = Node<char>;

vector<char_node_t*> DFS(char_node_t* root, char target)
{
	stack<char_node_t*> node_stack;
	root->visited = true;
	node_stack.push(root);

	// find target
	while (!node_stack.empty())
	{
		char_node_t* current_node = node_stack.top();
		if (current_node->data == target)
		{
			cout << "found: " << current_node->data << endl;
			break;
		}
		else
		{
			cout << "visited: " << current_node->data << endl;
		}

		bool popNode = true;
		for (auto child : current_node->children)
		{
			if (!child->visited)
			{
				popNode = false;
				child->visited = true;
				node_stack.push(child);
				break;
			}
		}

		if (popNode)
		{
			node_stack.pop();
		}
	}

	// create path
	vector<char_node_t*> path;
	while (!node_stack.empty())
	{
		path.insert(path.begin(), node_stack.top());
		node_stack.pop();
	}

	return path;
}

int main()
{
	cout << "hello world!" << endl;

	//     A
	//   B   C
	// D   E   F
	char_node_t* nodeA = new char_node_t('A');
	char_node_t* nodeB = new char_node_t('B');
	char_node_t* nodeC = new char_node_t('C');
	char_node_t* nodeD = new char_node_t('D');
	char_node_t* nodeE = new char_node_t('E');
	char_node_t* nodeF = new char_node_t('F');

	nodeA->children.push_back(nodeB);
	nodeA->children.push_back(nodeC);
	nodeB->children.push_back(nodeD);
	nodeB->children.push_back(nodeE);
	nodeC->children.push_back(nodeE);
	nodeC->children.push_back(nodeF);

	auto path = DFS(nodeA, 'F');

	cout << "path: ";
	for (auto node : path)
	{
		cout << node->data << "->";
	}
	cout << endl;

	return 0;
}