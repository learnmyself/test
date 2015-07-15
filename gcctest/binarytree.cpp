#include <iostream>
using namespace std;

template<typename T>
struct TreeNode {
	T data;
	TreeNode<T>* pLChild;
	TreeNode<T>* pRChild;
	TreeNode()
	{
		pLChild = NULL;
		pRChild = NULL;
	}
};

TreeNode<int> *pHead, *pIndex;

template<typename T>
void Treeinsert(TreeNode<T>* pTree, T element)
{
	if(pTree == NULL) {
		TreeNode<T>* tmp = new TreeNode<T>;
		tmp->data = element;
		pTree = tmp;
		return;
	}
	if (pTree->data == element) {
		cout<<"the element"<<element<< " is already in the tree!"<<endl;
	return;
	}
	if(pTree->data > element) {
		Treeinsert(pTree->pLChild, element);
		
	}
	else {
		Treeinsert(pTree->pRChild, element);
	}
}

template<typename T>
void CreateTree(TreeNode<T>* pRoot, T iArray[], int len)
{
	for(int i = 0; i < len; i++) {
		Treeinsert(pRoot,iArray[i]);
	}
}

template<typename T>
void convertToDoubleList(TreeNode<T>* pCurrent)
{
	pCurrent = pIndex;
	if (NULL == pIndex)
	{
		pHead=pCurrent;
	}
	else
	{
		pIndex->pRChild=pCurrent;
	}

	pIndex=pCurrent;
	cout<<pCurrent->data<<"";
}

template<typename T>
void inOrderBSTree(TreeNode<T>* pBSTree)
{
	if (NULL == pBSTree)
	{
		return;
	}
	if (NULL != pBSTree->pLChild)
	{
		inOrderBSTree(pBSTree->pLChild);
	}
	convertToDoubleList(pBSTree);
	
	if (NULL != pBSTree->pRChild)
	{
		inOrderBSTree(pBSTree->pRChild);
	}
}

int main()
{
	TreeNode<int>* pRoot = NULL;
	int a[7] = {10,6,14,4,8,12,16};
	CreateTree(pRoot, a, 7);
	inOrderBSTree(pRoot); 
	return 0;

}
