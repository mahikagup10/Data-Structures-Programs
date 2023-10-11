// Name: Mahika Gupta
// SRN: PES1UG20CS243
#include "bst.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
*/

// Initializes the root of the bst
void init_bst(bst_t *bst)
{
    bst->root=NULL;
}

static node_t* get_node(int ele)
{
    node_t* temp;
    temp = malloc(sizeof(node_t));
	temp->key = ele;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

static void insert_helper(node_t* root, int key, int *count_ptr)
{
    node_t* temp = get_node(key);
	if(root == NULL && ++*count_ptr)
		root = temp;
	else
	{
		if(root->key > key && ++*count_ptr)
			insert_helper(root->left, key, count_ptr);
		else
			insert_helper(root->right, key, count_ptr);
	}
}

// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
void insert(bst_t *tree, int key, int *count_ptr)
{
    insert_helper(tree->root, key, count_ptr);
}



static node_t* find_min(node_t* root, int *count_ptr)
{
    if(root->left == NULL && ++*count_ptr)
		return root;
	else
	{
		return find_min(root->left,count_ptr);
	}
}



static node_t* delete_element_helper(node_t* root, int key, int* count_ptr)
{
    node_t *p,*befp;
    //p = root;
    if (root == NULL && ++*count_ptr)
        return root;
    if (key < root->key && ++*count_ptr)
        root->left = delete_element_helper(root->left, key,count_ptr);
    else if (key > root->key && ++*count_ptr)
        root->right = delete_element_helper(root->right, key,count_ptr);
    else 
    {
        if (root->left == NULL && ++*count_ptr) 
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL && ++*count_ptr) 
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = find_min(root->right,count_ptr);
        root->key = temp->key;
        root->right = delete_element_helper(root->right, temp->key,count_ptr);
    }
    return root;
}

// Delete key from the BST
// Replaces node with in-order successor
void delete_element(bst_t *tree, int key, int *count_ptr)
{
    //int ele = search(tree,key,*count_ptr);
    tree->root = delete_element_helper(tree->root,key,count_ptr);
}

static int search_helper(node_t* root, int key, int *count_ptr)
{
    node_t* p = root;
	if (p==NULL && ++*count_ptr)
		return -1;
	if(p->key == key && ++*count_ptr)
		return key;
	if(p->key > key && ++*count_ptr)
		return (search_helper(p->left, key, count_ptr));
	else 
		return (search_helper(p->right, key, count_ptr));
}

// Searches for the element key in the bst
// Returns the element if found, else -1
int search(const bst_t *tree, int key, int *count_ptr)
{
    return search_helper(tree->root, key, count_ptr);
}



static int find_max_helper(node_t* root, int* count_ptr)
{
    if(root==NULL)
        return -1;
    if(root->right == NULL && ++*count_ptr)
		return root->key;
	else
	{
		return find_max_helper(root->right,count_ptr);
	}
}


// Returns the maximum element in the BST
int find_max(const bst_t *tree, int *count_ptr)
{
    return find_max_helper(tree->root,count_ptr);
}





static void free_bst_helper(node_t* root)
{
    node_t* p = root;
    if(p==NULL)
        free(root);
	if(p!= NULL)
	{
		free_bst_helper(p->left);
		free_bst_helper(p->right);
	}
}
// Deletes all the elements of the bst
void free_bst(bst_t *bst) 
{
    free_bst_helper(bst->root);
}

// Deletes all the elements if the bst and ensures it can be used again
void clear_bst(bst_t *bst)
{
    bst->root= NULL;
}