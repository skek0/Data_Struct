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
		Node* newNode = new Node();
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
				else if (currentNode->data < data)
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
		if (node != nullptr)
		{
			Inorder(node->left);
			cout << node->data << " ";
			Inorder(node->right);
		}
	}
	void Destroy(Node* node)
	{
		if (node != nullptr)
		{
			Destroy(node->left);
			Destroy(node->right);
			delete node;
		}
	}
	bool Find(T data)
	{
		Node* currentNode = root;
		while (currentNode != nullptr)
		{
			if (currentNode->data < data)
			{
				currentNode = currentNode->right;
			}
			else if (currentNode->data > data)
			{
				currentNode = currentNode->left;
			}
			else	//currentNode == data
			{
				return true;
			}
		}
		return false;
	}
	void Remove(T data)
	{
		if (root == nullptr) cout << "BinaryTree is Empty!" << endl;

		Node* currentNode = root;
		Node* parentNode = nullptr;

		while (currentNode != nullptr && currentNode->data != data)
		{
			if (currentNode->data > data)
			{
				parentNode = currentNode;
				currentNode = currentNode->left;
			}
			else
			{
				parentNode = currentNode;
				currentNode = currentNode->right;
			}
		}

		if (currentNode == nullptr)
		{
			cout << "No Data Found" << endl; return;
		}

		if (currentNode == root) delete root;
		else if (currentNode->left == nullptr && currentNode->right == nullptr)
		{
			if (parentNode->left == currentNode)
			{
				parentNode->left = nullptr;
			}
			else //parentNode->right == currentNode)
			{
				parentNode->right = nullptr;
			}
		}
		else if (currentNode->left == nullptr || currentNode->right == nullptr)
		{
			//Node* childNode = nullptr;

			//if (parentNode->left == currentNode)
			//{
			//	if (currentNode->left != nullptr)
			//	{
			//		Node* childNode = currentNode->left;
			//		parentNode->left = childNode;
			//	}
			//	else //currentNode->right != nullptr
			//	{
			//		Node* childNode = currentNode->right;
			//		parentNode->right = childNode;
			//	}
			//}
			//else //parentNode->right == currentNode
			//{
			//	parentNode->right = nullptr;
			//}
			Node* childNode = nullptr;

			if (currentNode->left != nullptr)
			{
				childNode = currentNode->left;
			}
			else
			{
				childNode = currentNode->right;
			}

			if (parentNode != nullptr)
			{
				if (parentNode->left == currentNode)
				{
					parentNode->left = childNode;
				}
				else
				{
					parentNode->right = childNode;
				}
			}
		}
		else //currentNode->left != nullptr && currentNode->right != nullptr
		{
			Node* childNode = currentNode->right;
			Node* traceNode = childNode;

			while (childNode->left != nullptr)
			{
				traceNode = childNode;
				childNode = childNode->left;
			}
			currentNode->data = childNode->data;
			traceNode->left = childNode->right;

			delete childNode;

			return;
		}
		delete currentNode;
	}

	~BinarySearchTree()
	{
		Destroy(root);
	}
};

int main()
{
	BinarySearchTree<int> bnsTree;

	bnsTree.Insert(10);
	bnsTree.Insert(7);
	bnsTree.Insert(15);
	bnsTree.Insert(6);
	bnsTree.Insert(9);
	bnsTree.Insert(8);

	bnsTree.Remove(7);

	bnsTree.Inorder(bnsTree.RootNode());

	return 0;
}