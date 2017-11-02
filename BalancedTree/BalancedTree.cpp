// BalancedTree.cpp : Defines the entry point for the console application.
/*
Given a binary tree, determine if it is height-balanced.
Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node
never differ by more than 1.
*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>


using namespace std;

struct TNode {
	TNode* left;
	TNode* right;
	int data;
};

TNode* newNode(int val)
{
	TNode* temp = new TNode();
	temp->left = nullptr;
	temp->right = nullptr;
	temp->data = val;
	return temp;
}

pair<int, bool> isBalancedWithDepth(TNode* root)
{
	if (!root) return make_pair(0, true);
	
	pair<int, bool> left = isBalancedWithDepth(root->left);
	pair<int, bool> right = isBalancedWithDepth(root->right);

	int depth = max(left.first, right.first) + 1;
	bool isBalanced = (abs(left.first - right.first) < 2) && left.second && right.second;

	return make_pair(depth, isBalanced);
}

bool isBalanced(TNode* root)
{
	return isBalancedWithDepth(root).second;
}

int main()
{
	TNode* root = newNode(5);
	root->right = newNode(10);
	root->right->right = newNode(20);
	root->right->left = newNode(8);

	cout << isBalanced(root) << endl;

	root->left = newNode(3);
	cout << isBalanced(root) << endl;
	root->right->right->right = newNode(30);
	cout << isBalanced(root) << endl;
    return 0;
}

