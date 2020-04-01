// C++ program to print the 
// left view of Binary Tree 

#include <bits/stdc++.h> 

using namespace std; 

// A Binary Tree Node 
struct node { 
	int data; 
	struct node *left, *right; 
}; 

// A utility function to create a new 
// Binary Tree node 
struct node* newNode(int item) 
{ 
	struct node* temp = new node; 
	temp->data = item; 
	temp->left = NULL; 
	temp->right = NULL; 
	return temp; 
} 

// Utility function to print the left view of 
// the binary tree 
void leftViewUtil(struct node* root) 
{ 
	if (root == NULL) 
		return; 

	// Queue to store all 
	// the nodes of the tree 
	queue<node*> q; 
	// Push root 
	q.push(root); 

	// Delimiter 
	q.push(NULL); 

	while (!q.empty()) { 
		node* current = q.front(); 

		if (current) { 

			// Prints first node 
			// of each level 
			cout << current->data << " "; 

			// Push children of all nodes at 
			// current level 
			while (q.front() != NULL) { 

				// If left child is present 
				// push into queue 
				if (current->left) 
					q.push(current->left); 

				// If right child is present 
				// push into queue 
				if (current->right) 
					q.push(current->right); 

				// Pop the current node 
				q.pop(); 

				current = q.front(); 
			} 

			// Push delimiter 
			// for the next level 
			q.push(NULL); 
		} 

		// Pop the delimiter of 
		// the previous level 
		q.pop(); 
	} 
} 

// Iterative function to print left view of given binary tree
void leftView(node* root)
{
    // return if tree is empty
    if (root == nullptr)
        return;

    // create an empty queue and enqueue root node
    queue<node*> queue;
    queue.push(root);

    // pointer to store current node
    node* curr = nullptr;

    // run till queue is not empty
    while (!queue.empty())
    {
        // calculate number of nodes in current level
        int size = queue.size();
        int i = 0;

        // process every node of current level and enqueue their
        // non-empty left and right child to queue
        while (i++ < size)
        {
           curr = queue.front();
           queue.pop();

           // if this is first node of current level, print it
           if (i == 1)
                cout << curr->data << " ";

           if (curr->left)
                queue.push(curr->left);

           if (curr->right)
                queue.push(curr->right);
        }
    }
}

void rightView(node* root)
{
    // return if tree is empty
    if (root == nullptr)
        return;

    // create an empty queue and enqueue root node
    queue<node*> queue;
    queue.push(root);

    // pointer to store current node
    node* curr = nullptr;

    // run till queue is not empty
    while (!queue.empty())
    {
        // calculate number of nodes in current level
        int size = queue.size();
        int i = 0;

        // process every node of current level and enqueue their
        // non-empty left and right child to queue
        while (i++ < size)
        {
           curr = queue.front();
           queue.pop();

           // if this is first node of current level, print it
           if (i == size)
                cout << curr->data << " ";

           if (curr->left)
                queue.push(curr->left);

           if (curr->right)
                queue.push(curr->right);
        }
    }
}

void levelOrderTraversal(node* root){
	queue<node*> q;
	q.push(root);
	node* current;
	
	while(!q.empty()){
		current=q.front();
		q.pop();
		cout<<current->data<<" ";
		
		if(current->left)
			q.push(current->left);
		if(current->right)
			q.push(current->right);
	}
	
}

// Driver Code 
int main() 
{ 
	struct node* root = newNode(5); 
	root->left = newNode(10); 
	root->right = newNode(7); 
	root->left->left = newNode(3); 
	root->right->right = newNode(14); 
	root->right->right->left = newNode(2); 
	
	leftViewUtil(root); 
	
	printf("\n");
	leftView(root); 
	
	printf("\nRight View of tree:\n");
	rightView(root);
	
	printf("\nLevel Order Traversal of tree:\n");
	levelOrderTraversal(root);

	return 0; 
} 

