//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>
#include <queue>

using namespace std;

//Definition of the Node
template <class elemType>
struct nodeType
{
    elemType		info;
    nodeType<elemType>  *llink;
    nodeType<elemType>  *rlink;
};

//Definition of the class
template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator=
    (const binaryTreeType<elemType>&); 
    //Overload the assignment operator.
    bool isEmpty() const;
    //Function to determine whether the binary tree
    //is empty.
    //Postcondition: Returns true if the binary tree is empty;
    //               otherwise, returns false.
    void inorderTraversal() const;
    //Function to do an inorder traversal of the binary tree.
    //Postcondition: Nodes are printed in inorder sequence.
    void preorderTraversal() const;
    //Function to do a preorder traversal of the binary tree.
    //Postcondition: Nodes are printed in preorder sequence.
    void postorderTraversal() const;
    //Function to do a postorder traversal of the binary tree.
    //Postcondition: Nodes are printed in postorder sequence.
    
    void inorderTraversal(void (*visit) (elemType&)) const;
    //Function to do an inorder traversal of the binary tree.
    //The parameter visit, which is a function, specifies
    //the action to be taken at each node.
    //Postcondition: The action specified by the function visit
    //               is applied to each node of the binary tree.
    
    int treeHeight() const;
    //Funtion to determine the height of a binary tree.
    //Postcondition: Returns the height of the binary tree.
    int treeNodeCount() const;
    //Funtion to determine the number of nodes in a 
    //binary tree.
    //Postcondition: Returns the number of nodes in the 
    //               binary tree.
    int treeLeavesCount() const;
    //Funtion to determine the number of leaves in a 
    //binary tree.
    //Postcondition: Returns the number of leaves in the 
    //               binary tree.
    
    int nonLeavesCount() const;
    //Function to return number of nodes that are not leaves
    //Input: none
    //Output: the number of nodes that are not leaves
    //Precondition:  none
    //Postcondition: Returns the number of nodes that are not leaves
    
    int oneChildCount() const;
    //Function to return number of nodes with one child
    //Input: none
    //Output: the number of nodes with one child
    //Precondition:  none
    //Postcondition: Returns the number of nodes with one child
    
    int twoChildrenCount() const;
    //Function to return number of nodes with two children
    //Input: none
    //Output: the number of nodes with two children
    //Precondition:  none
    //Postcondition: Returns the number of nodes with two children
    
    bool balanced() const;
    //Function to return whether the tree is balanced (by definition) or not
    //Input: none
    //Output: whether tree is balanced or not (bool)
    //Precondition:  none
    //Postcondition: Returns true if tree is balanced, false otherwise
    //NOTE: YOU MAY USE ANY OTHER METHOD
    
    void breadthFirstTraversal(void (*visit) (elemType&)) const;
    //Function to do a breadth first traversal of the tree
    //Input: a pointer to a function to execute on each item
    //Output: none
    //Precondition:  none
    //Postcondition: the traversal visits each node
    //NOTE: YOU PROBABLY WILL WANT TO WRITE AN ITERATIVE SOLUTION FOR THIS
    
    bool search(const elemType& searchItem) const;
    //Function to determine if searchItem is in the binary 
    //search tree.
    //Postcondition: Returns true if searchItem is found in the 
    //               binary search tree; otherwise, returns false.
    
    bool full() const;
    //Input: none
    //Output: whether tree is full or not (bool)
    //Function to return whether the tree is full (by definition) or not
    //Precondition:  none
    //Postcondition: Returns true if tree is full, false otherwise
    //NOTE: You may NOT use treeNodecount == 2^height-1 
    
    bool complete() const;
    //Input: none
    //Output: whether tree is complete or not (bool)
    //Function to return whether the tree is complete (by definition) or not
    //Precondition:  none
    //Postcondition: Returns true if tree is complete, false otherwise
    
    void destroyTree();
    //Function to destroy the binary tree.
    //Postcondition: Memory space occupied by each node 
    //               is deallocatd.
    //               root = NULL;
    
    binaryTreeType(const binaryTreeType<elemType>& otherTree); 
    //copy constructor
    
    binaryTreeType();   
    //default constructor
    
    ~binaryTreeType();   
    //destructor
    
protected:
    nodeType<elemType>  *root;
    
private:
    void copyTree(nodeType<elemType>* &copiedTreeRoot,
		  nodeType<elemType>* otherTreeRoot);
    //Makes a copy of the binary tree to which 
    //otherTreeRoot points. 
    //Postcondition: The pointer copiedTreeRoot points to
    //               the root of the copied binary tree.
    void destroy(nodeType<elemType>* &p);
    //Function to destroy the binary tree to which p points. 
    //Postcondition: Memory space occupied by each node, in the
    //               binary tree to which p points, is deallocatd.
    //               p = NULL;
    
    void inorder(nodeType<elemType> *p) const;
    //Function to do an inorder traversal of the binary
    //tree to which p points.  
    //Postcondition: Nodes of the binary tree, to which p
    //               points, are printed in inorder sequence.
    void preorder(nodeType<elemType> *p) const;
    //Function to do a preorder traversal of the binary
    //tree to which p points.  
    //Postcondition: Nodes of the binary tree, to which p
    //               points, are printed in preorder sequence.
    void postorder(nodeType<elemType> *p) const;
    //Function to do a postorder traversal of the binary
    //tree to which p points.  
    //Postcondition: Nodes of the binary tree, to which p
    //               points, are printed in postorder sequence.
    
    void inorder(nodeType<elemType> *p, void (*visit) (elemType&)) const;
    //Function to do an inorder traversal of the binary
    //tree starting at the node specified by the parameter p. 
    //The parameter visit, which is a function, specifies the
    //action to be taken at each node.
    //Postcondition: The action specified by the function visit
    //               is applied to each node of the binary tree
    //               to which p points.
    
    int height(nodeType<elemType> *p) const;
    //Function to determine the height of the binary tree
    //to which p points. 
    //Postcondition: Height of the binary tree to which 
    //               p points is returned.
    int max(int x, int y) const;
    //Function to determine the larger of x and y.
    //Postcondition: Returns the larger of x and y.
    int nodeCount(nodeType<elemType> *p) const;
    //Function to determine the number of nodes in 
    //the binary tree to which p points. 
    //Postcondition: The number of nodes in the binary 
    //               tree to which p points is returned.
    int leavesCount(nodeType<elemType> *p) const;
    //Function to determine the number of leaves in  
    //the binary tree to which p points 
    //Postcondition: The number of leaves in the binary 
    //               tree to which p points is returned.
    int nonLeaves(nodeType<elemType> *p) const;
    
    int oneChild(nodeType<elemType> *p) const;
    
    int twoChildren(nodeType<elemType> *p) const;
    
    bool balancedNode(nodeType<elemType> *p) const;
    
    bool searchNode(const elemType& searchItem, nodeType<elemType> *p) const;
    
    bool fullNode(nodeType<elemType> * p) const;
    
    bool completeNode(nodeType<elemType> *p) const;
};

//Definition of member functions

template<class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = NULL;
}

template<class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == NULL);
}

template<class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

template<class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}

template<class elemType>
int binaryTreeType<elemType>::nonLeavesCount() const
{
    return nonLeaves(root);
}

template<class elemType>
int binaryTreeType<elemType>::oneChildCount() const {
    return oneChild(root);
}

template<class elemType>
int binaryTreeType<elemType>::twoChildrenCount() const {
    return twoChildren(root);
}

template<class elemType>
bool binaryTreeType<elemType>::balanced() const {
    return balancedNode(root);
}

template<class elemType>
bool binaryTreeType<elemType>::search(const elemType& searchItem) const {
    return searchNode(searchItem, root);
}

template<class elemType>
bool binaryTreeType<elemType>::full() const {
    return fullNode(root);
}

template<class elemType>
bool binaryTreeType<elemType>::complete() const {
    return completeNode(root);
}

template<class elemType>
void binaryTreeType<elemType>::breadthFirstTraversal(void (*visit) (elemType&)) const {
    queue< nodeType<elemType>* > q;
    nodeType<elemType> *p = root;
    while (p != NULL) {
	visit(p->info);
	if (p->llink != NULL)
	    q.push(p->llink);
	if (p->rlink != NULL)
	    q.push(p->rlink);
	if (q.empty())
	    p = NULL;
	else {
	    p = q.front();
	    q.pop();
	}
    }
}

template <class elemType>
void  binaryTreeType<elemType>::copyTree
(nodeType<elemType>* &copiedTreeRoot,
 nodeType<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == NULL)
	copiedTreeRoot = NULL;
    else
    {
	copiedTreeRoot = new nodeType<elemType>;
	copiedTreeRoot->info = otherTreeRoot->info;
	copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
	copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
} //end copyTree

template<class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p) const
{
    if (p != NULL)
    {
	inorder(p->llink);
	cout << p->info << " ";
	inorder(p->rlink);
    }
}

template<class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p) const
{
    if (p != NULL)
    {
	cout << p->info << " ";
	preorder(p->llink);
	preorder(p->rlink);
    }
}

template<class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p) const
{
    if (p != NULL)
    {
	postorder(p->llink);
	postorder(p->rlink);
	cout << p->info << " ";
    }		
}

//Overload the assignment operator
template<class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
operator=(const binaryTreeType<elemType>& otherTree)
{ 
    if (this != &otherTree) //avoid self-copy
	{
	    if (root != NULL)  //if the binary tree is not empty, 
			              //destroy the binary tree
		destroy(root);
	    
	    if (otherTree.root == NULL) //otherTree is empty
			root = NULL;
	    else
		copyTree(root, otherTree.root);
	}//end else
	
	return *this; 
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(nodeType<elemType>* &p)
{
    if (p != NULL)
    {
	destroy(p->llink);
	destroy(p->rlink);
	delete p;
	p = NULL;
    }
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
(const binaryTreeType<elemType>& otherTree)
{
    if (otherTree.root == NULL) //otherTree is empty
		root = NULL;
    else
	copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

template<class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType> *p) const
{
    if (p == NULL)
	return 0;
    else
	return 1 + max(height(p->llink), height(p->rlink));
}

template<class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
	return x;
    else
	return y;
}

template<class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType> *p) const
{
    if (p == NULL)
	return 0;
    else
	return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
}

template<class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p) const
{
    if (p == NULL) 
	return 0;
    if (p->llink == NULL && p->rlink == NULL)
	return 1;
    else
	return leavesCount(p->llink) + leavesCount(p->rlink);
}

template<class elemType>
int binaryTreeType<elemType>::nonLeaves(nodeType<elemType> *p) const {
    if (p == NULL)
	return 0;
    else if (p->llink != NULL || p->rlink != NULL)
	return 1 + nonLeaves(p->llink) + nonLeaves(p->rlink);
}

template<class elemType>
int binaryTreeType<elemType>::oneChild(nodeType<elemType> *p) const {
    if (p == NULL)
	return 0;
    else if (p->llink == NULL && p->rlink == NULL)
	return oneChild(p->llink) + oneChild(p->rlink);
    else if (p->llink != NULL && p->rlink != NULL)
	return oneChild(p->llink) + oneChild(p->rlink);
    else
	return 1 + oneChild(p->llink) + oneChild(p->rlink);
}

template<class elemType>
int binaryTreeType<elemType>::twoChildren(nodeType<elemType> *p) const {
    if (p == NULL)
	return 0;
    else if (p->llink != NULL && p->rlink != NULL)
	return 1 + twoChildren(p->llink) + twoChildren(p->rlink);
    else
	return twoChildren(p->llink) + twoChildren(p->rlink);
}

template<class elemType>
bool binaryTreeType<elemType>::balancedNode(nodeType<elemType> *p) const {
    if (p == NULL)
	return true;
    else {
	int difference = height(p->llink) - height(p->rlink);
	if (-1 <= difference && difference <= 1)
	    return balancedNode(p->llink) && balancedNode(p->rlink);
	else
	    return false;
    }
}

template<class elemType>
bool binaryTreeType<elemType>::searchNode(const elemType& searchItem, nodeType<elemType> *p) const {
    if (p == NULL)
	return false;
    else if (searchItem == p->info)
	return true;
    else
	return searchNode(searchItem, p->llink) || searchNode(searchItem, p->rlink);
}

template<class elemType>
bool binaryTreeType<elemType>::fullNode(nodeType<elemType> *p) const {
    if (p == NULL)
	return true;
    else if (p->llink != NULL && p->rlink != NULL)
	return fullNode(p->llink) && fullNode(p->rlink);
    else if (p->llink == NULL && p->rlink == NULL)
	return true;
    else
	return false;
}

template<class elemType>
bool binaryTreeType<elemType>::completeNode(nodeType<elemType> *p) const {
    if (p == NULL)
	return true;
    else if (height(p->llink) == height(p->rlink))
	return completeNode(p->llink) && completeNode(p->rlink);
    else
	return false;
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal
(void (*visit) (elemType& item)) const
{ 
    inorder(root, *visit);
}

template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType>* p,
				       void (*visit) (elemType& item)) const
				       {
					   if (p != NULL)
					   {
					       inorder(p->llink, *visit);
					       (*visit)(p->info);
					       inorder(p->rlink, *visit);
					   }
				       }
				       
				       #endif
				       
				       