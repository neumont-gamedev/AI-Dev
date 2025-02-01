#include "Node.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
using char_node_t = Node<char>;

vector<char_node_t*> DFS(char_node_t* root, char target)
{
	// check for valid root node
	if (root == nullptr) return vector<char_node_t*>();

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

vector<char_node_t*> BFS(char_node_t* root, char target)
{
	// check for valid root node
	if (root == nullptr) return vector<char_node_t*>();

	// create nodes queue and queue root onto stack
	queue<char_node_t*> node_queue;
	root->visited = true;
	node_queue.push(root);

	while (!node_queue.empty())
	{
		// get current node from the front of the queue
		char_node_t* current = node_queue.front();

		// check if the current node data is target value
		if (current->data == target)
		{
			cout << "found: " << current->data << endl;
			break;
		}
		else
		{
			cout << "visit: " << current->data << endl;
		}

		// if target not found then push all the children of the current node into the queue
		for (auto child : current->children)
		{
			if (!child->visited)
			{
				child->visited = true;
				child->parent = current;
				node_queue.push(child);
			}
		}

		// pop the front of the queue
		node_queue.pop();
	}

	// convert nodes to vector of nodes (path)
	// nodes are in reverse order with the parent used to move through the nodes
	// add nodes to front of path vector
	vector<char_node_t*> path;
	char_node_t* node = (!node_queue.empty()) ? node_queue.front() : nullptr;
	while (node)
	{
		// add node and then set node to node parent
		path.insert(path.begin(), node);
		node = node->parent;
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

	auto path = BFS(nodeA, 'F');

	cout << "path: ";
	for (auto node : path)
	{
		cout << node->data << "->";
	}
	cout << endl;

	return 0;
}