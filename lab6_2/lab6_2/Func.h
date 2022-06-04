#pragma once
struct tnode {
	char letter;
	struct tnode* left;
	struct tnode* right;
};
struct tnode* addnode(int x, tnode* tree);
void print_tree(tnode* q, int n);
int height(tnode* tree);


