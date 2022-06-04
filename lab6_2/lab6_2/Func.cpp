#include "Func.h"
#include<iostream>
using namespace std;
tnode* addnode(int x, tnode* tree)
{
	{
		if (tree == NULL) {
			tree = new tnode;
			tree->letter = x;
			tree->left = NULL;
			tree->right = NULL;
		}
		else  if (x < tree->letter)
			tree->left = addnode(x, tree->left);
		else
			tree->right = addnode(x, tree->right);
		return(tree);
	}
}
void print_tree(tnode* tree, int n)
{
	int i;
	if (tree != NULL) {
        print_tree(tree->right, n + 5);
        for (i = 0; i < n; i++)
            cout<<" ";
        cout<<tree->letter<<"\n";
        print_tree(tree->left, n + 5);
	}

}
int height(tnode* tree)
{
    if (tree == NULL)
        return 0;
    else {
        int lheight = height(tree->left);
        int rheight = height(tree->right);

        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
}
}
