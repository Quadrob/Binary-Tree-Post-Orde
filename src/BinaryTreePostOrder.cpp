//============================================================================
// Name        : BinaryTreePostOrder.cpp
// Author      : Robert Zeelie
// Version     : 1.00.00
// Copyright   : Your copyright notice
// Description : A program in C++ to find post-order predecessor of a node in
//				 a Binary Tree. I update and store the Postorder predecessor of
//				 a node in an array during a postorder traversal of the given
//				 tree. When i find the desired node i print the array to
//				 display its predecessor.
//============================================================================

#include <iostream>
#include <array>
using namespace std;


//defines a node of the binary tree
struct BinaryTreeNode {
   int nodeData;//data stored within the node
   struct BinaryTreeNode *leftChildNode, *rightChildNode;//children nodes
};


//my binary tree abstract class
class myBinaryTree{
	//declarations
	public:
		myBinaryTree();
		void insert(int data);
		void postorder_predecessor(int data);

	private:
		void insert(int data, BinaryTreeNode *node);
		void postorder_predecessor(BinaryTreeNode *root, int data, int postorderNode[]);
		BinaryTreeNode *root;
};


//constructor
myBinaryTree::myBinaryTree(){
	root = NULL;
}


//second insert function details to fill binary tree
void myBinaryTree::insert(int data, BinaryTreeNode *node){
	//if data is less than the current node data place it left
	if(data < node->nodeData){
		//if left is full call function again with left node
		if(node->leftChildNode != NULL){
			insert(data, node->leftChildNode);
		}else{//else create new node in left child pointer
			node->leftChildNode = new BinaryTreeNode;
			node->leftChildNode->nodeData = data;
			node->leftChildNode->leftChildNode = NULL;
			node->leftChildNode->rightChildNode = NULL;
		}

	}else if(data >= node->nodeData){//else if data is grater than the current node data place it right
		//if right child is full call function again with right node
		if(node->rightChildNode != NULL){
			insert(data, node->rightChildNode);
		}else{//else create new node in right child pointer
			node->rightChildNode = new BinaryTreeNode;
			node->rightChildNode->nodeData = data;
			node->rightChildNode->rightChildNode = NULL;
			node->rightChildNode->leftChildNode = NULL;
		}
	}
}


//first insert function details to check for root
void myBinaryTree::insert(int data){
	//if tree has a root
	if(root != NULL){
		insert(data, root);
	}else{//else fill root
		root = new BinaryTreeNode;
		root->nodeData = data;
		root->leftChildNode = NULL;
		root->rightChildNode = NULL;
	}
}


//Check if root is the requested node
void myBinaryTree::postorder_predecessor(int data){
	int postorderNode[1] = {NULL};

	if(data != root->nodeData){
		postorder_predecessor(root, data, postorderNode);
	}else if(root->rightChildNode != NULL){
		cout << root->rightChildNode->nodeData;
	}else{
		cout << " This root does not have a predecessor!" << endl;
	}
}


//check all the nodes of the tree for a match while updating the predecessor for each node
void myBinaryTree::postorder_predecessor(BinaryTreeNode *node, int data,int postorderNode[]){

	if(node != NULL){
		postorder_predecessor(node->leftChildNode, data, postorderNode);
		postorder_predecessor(node->rightChildNode, data, postorderNode);

		if(data != node->nodeData){
			postorderNode[0] = node->nodeData;
		}else if(postorderNode[0] != NULL){
			cout << postorderNode[0] << endl;
		}else{
			cout << "This node does not have a predecessor!" << endl;
		}
	}
}


int main() {

	int userInput;

	myBinaryTree *tree = new myBinaryTree();

		tree->insert(9);
		tree->insert(5);
		tree->insert(2);
		tree->insert(7);
		tree->insert(13);
		tree->insert(8);
		tree->insert(6);
		tree->insert(1);
		tree->insert(3);
		tree->insert(12);
		tree->insert(11);
		tree->insert(15);
		tree->insert(14);

		cout << "\tFind a node's predecessor\n\nPlease enter the data of a node to find its predecessor:" << endl;
		cin >> userInput;
		cout << "\nThe postorder Predecessor for: " << userInput << " is = " << endl;
		tree->postorder_predecessor(userInput);


		cout << "\n\n\n\tThank you for using my application!" << endl;

	return 0;
}



















