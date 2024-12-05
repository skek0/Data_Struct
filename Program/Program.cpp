#include <iostream>

using namespace std;

template<typename T>
class BinarySearchTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};
	Node* root;
public:
	BinarySearchTree()
	{
		root = nullptr;
	}

	Node* RootNode()
	{
		return root;
	}
	Node* CreateNode(T data)
	{
		Node * newNode = new Node();
		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;

		return newNode;
	}
	void Insert(T data)
	{
		if (root != nullptr)
		{
			Node* currentNode = root;
			while (currentNode != nullptr)
			{
				if (currentNode->data > data)
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = CreateNode(data);
						break;
					}
					else
					{
						currentNode = currentNode->left;
					}
				}
				else if(currentNode->data < data)
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = CreateNode(data);
						break;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
				else /* currentNode->data == data */return;
			}
		}
		else // root == nullptr
		{
			root = CreateNode(data);
		}
	}
	void Inorder(Node* node)
	{
		if (node->left != nullptr) Inorder(node->left);
		cout << node->data << " ";
		if (node->right != nullptr) Inorder(node->right);
	}
	void Print()
	{
		Node* currentNode = root;
		if (currentNode != nullptr)
		{
			Inorder(currentNode);
		}
		else cout << "BinarySearchTree is Empty!" << endl;
	}
	void Destroy(Node* node)
	{
		if (node->left != nullptr) Destroy(node->left);
		if (node->right != nullptr) Destroy(node->right);
		delete node;
	}

	~BinarySearchTree()
	{
		Destroy(root);
	}
};

int main()
{
	BinarySearchTree<int> bnsTree;

	bnsTree.Insert(15);
	bnsTree.Insert(7);
	bnsTree.Insert(9);
	bnsTree.Insert(20);

	bnsTree.Print();

	return 0;
}