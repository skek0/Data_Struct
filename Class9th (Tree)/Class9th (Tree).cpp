﻿#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data, Node* left, Node* right)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = left;
	newNode->right = right;

	return newNode;
}
void PreOrder(Node* root)
{
	cout << root->data << " ";
	if (root->left != nullptr)PreOrder(root->left);
	if (root->right != nullptr)PreOrder(root->right);
}
void InOrder(Node* root)
{
	if (root->left != nullptr)InOrder(root->left);
	cout << root->data << " ";
	if (root->right != nullptr)InOrder(root->right);
}
void PostOrder(Node* root)
{
	if (root->left != nullptr)PostOrder(root->left);
	if (root->right != nullptr)PostOrder(root->right);
	cout << root->data << " ";
}

int main()
{
	Node* node5 = CreateNode(5, nullptr, nullptr);
	Node* node4 = CreateNode(4, nullptr, nullptr);
	Node* node3 = CreateNode(3, nullptr, nullptr);
	Node* node2 = CreateNode(2, node4, node5);
	Node* node1 = CreateNode(1, node2, node3);

	//PreOrder(node1);
	//cout << endl;
	//InOrder(node1);
	//cout << endl;
	//PostOrder(node1);



	return 0;
}