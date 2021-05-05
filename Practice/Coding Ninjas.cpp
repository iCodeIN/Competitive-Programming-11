/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

class BST
{
    // Define the data members
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        // Implement the Constructor
        root = NULL;
    }

    /*----------------- Public Functions of BST -----------------*/
private:
    BinaryTreeNode<int> *minValueNode(BinaryTreeNode<int> *node)
    {
        BinaryTreeNode<int> *current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

private:
    BinaryTreeNode<int> *deleteNode(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
            return NULL;

        if (data < node->data)
        {
            node->left = deleteNode(node->left, data);
        }

        else if (data > node->data)
        {
            node->right = deleteNode(node->right, data);
        }
        else
        {
            if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                delete (node);
                return temp;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                free(node);
                return temp;
            }
            BinaryTreeNode<int> *temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

public:
    void remove(int data)
    {
        // Implement the remove() function
        root = deleteNode(root, data);
    }

private:
    void print(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right != NULL)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        print(root->left);
        print(root->right);
    }

public:
    void print()
    {
        // Implement the print() function
        print(root);
    }

private:
    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data <= root->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }

        return node;
    }

public:
    void insert(int data)
    {
        root = insert(root, data);
    }
    bool help(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        if (root->data > data)
        {
            return help(data, root->left);
        }
        else
        {
            return help(data, root->right);
        }
    }
    bool search(int data)
    {
        // Implement the search() function
        return help(data, root);
    }
};