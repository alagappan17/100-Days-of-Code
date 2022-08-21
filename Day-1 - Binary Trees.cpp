//Day 1 
//Started learning and implementing Non-Linear Data Structures
//Binary Tree - Height, Diameter, Depth First Traversal - Inorder, Preorder, Postorder, Breadth First Search - Level Order Traversal

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Depth First Traversal - 
void preorder(Node* root_ref);
void postorder(Node* root_ref);
void inorder(Node* root_ref);

// Breadth First Traversal - 
int height(Node* node);
void printCurrentLevel(Node* node, int level);
void printLevelOrder(Node* node);

// Diameter
int findDiameter(Node* root);
int heightDiam(Node* node, int &ans);

int main() {
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    cout<<"Preorder: ";
    preorder(root);
    cout<<"\nInorder: ";
    inorder(root);
    cout<<"\nPostorder: ";
    postorder(root);
    cout<<"\nHeight: ";
    cout<<height(root);
    cout<<"\nLevel Order: ";
    printLevelOrder(root);
    cout<<"\nDiameter: ";
    cout<<findDiameter(root);
}

void preorder(Node* root_ref) {
    if(root_ref == NULL)
        return;
    cout<< root_ref -> data<<" ";
    preorder(root_ref -> left);
    preorder(root_ref -> right);
}

void inorder(Node* root_ref) {
    if(root_ref == NULL)
        return;
    inorder(root_ref -> left);
    cout<<root_ref -> data<<" ";
    inorder(root_ref -> right);
}

void postorder(Node* root_ref) {
    if(root_ref == NULL)
        return;
    postorder(root_ref -> left);
    postorder(root_ref -> right);
    cout<<root_ref -> data<<" ";
}

int height(Node* node) {
    if(node == NULL)
        return 0;
    else {
        int lheight = height(node -> left);
        int rheight = height(node -> right);
        if(rheight > lheight)
            return rheight + 1;
        else
            return lheight + 1;
    }
}

void printCurrentLevel(Node* node, int level) {
    if(node == NULL)
        return;
    if(level == 1){
        cout<<node -> data<<" ";
    } 
    else if(level > 1) {
        printCurrentLevel(node -> left, level - 1);
        printCurrentLevel(node -> right, level - 1);
    }
}

void printLevelOrder(Node* root) {
    int h = height(root);
    for(int i = 1 ; i <= h ; i++) {
        printCurrentLevel(root, i);
    }
}

int findDiameter(Node* root) {
    if (root == NULL)
		return 0;
	int ans = INT_MIN;
	heightDiam(root, ans);
	return ans;
}

int heightDiam(Node* root, int& ans) {
	if (root == NULL)
		return 0;
	int left_height = heightDiam(root->left, ans);
	int right_height = heightDiam(root->right, ans);
	ans = max(ans, 1 + left_height + right_height);
	return 1 + max(left_height, right_height);
}
