#pragma once
#include <vector>

template<typename T>
struct Node
{
	Node(const T& data) : data{ data } {}

	T data{ T() };
	bool visited{ false };
	Node* parent{ nullptr };
	
	std::vector<Node*> children;
};
