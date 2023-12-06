#include "iostream"
#include "deque"
#define none NULL
#define nl "\n"
#define nl2 "\n\n"

using	namespace std;

int	Max(int l, int r) { return (l > r) ? l : r; }; // simple util

class	avltree
{

int	val;
avltree	*l;
avltree	*r;
int	hite; // avl special

public:
	avltree();
	~avltree();
	avltree(int);

	avltree	*Rotate_Left(avltree *);
	avltree	*Rotate_Right(avltree *);
	avltree	*Insert(avltree *, avltree *);
	void	printer_inorder(avltree *);
	void	printer_bfs(avltree *root);

	int	GetHeight(avltree*);
	int	GetFactor(avltree *node);
};

avltree::avltree() : val(0), l(none), r(none), hite(1) {}
avltree::avltree(int n) : val(n), l(none), r(none), hite(1) {}
avltree::~avltree() {}

// avl special :: get height
int	avltree::GetHeight(avltree *tree)
{
	if (tree)
		return hite;
	return 0;
}

// avl special :: rotation
// rotate >>
avltree	*avltree::Rotate_Right(avltree *root) // subtree beiginning w/ root
{
	avltree	*P;

	P = root->l;
	root->l = P->r;
	P->r = root;

	root->hite = Max(GetHeight(root->l), GetHeight(root->r)) + 1;
	P->hite = Max(GetHeight(P->l), GetHeight(P->r)) + 1;

	return P;
}

// rotate <<
avltree	*avltree::Rotate_Left(avltree *root)
{
	avltree	*P;

	P = root->r;
	root->r = P->l;
	P->l = root;

	root->hite = 1 + Max(GetHeight(root->l), GetHeight(root->r));
	P->hite	= 1 + Max(GetHeight(P->l), GetHeight(P->r));

	return P;
}

// recursively insert
avltree	*avltree::Insert(avltree *root, avltree *node)
{
	// perform standard VST insertion
	if (!root)
		return node;
	if (node->val < root->val)
		root->l = Insert(root->l, node);
	else if (node->val > root->val)
		root->r = Insert(root->r, node);
	else
		return node;
	
	// update root's height
	root->hite = 1 + Max(GetHeight(root->l), GetHeight(root->r));

	// get balance factor
	int	balance = GetFactor(root);

	// in case of imbalance, deal with 4 cases
	if (balance > 1 && node->val < root->l->val) // L-L
		return Rotate_Left(root);
	if (balance < -1 && node->val > root->r->val) // R-R
		return Rotate_Right(root);
	if (balance > 1 && node->val > root->l->val) // L-R
		return Rotate_Right(root);
	if (balance < -1 && node->val < root->r->val) // R-L
		return Rotate_Left(root);
	return root; // root is unchanged
}

// get balance factor
int	avltree::GetFactor(avltree *node)
{
	if (!node)
		return 0;
	return GetHeight(node->l) - GetHeight(node->r);
}

// inorder printer
void	avltree::printer_inorder(avltree *node)
{
	if (!node)
	{
		cout << nl;
		return ;
	}
	cout << "(go l) ";
	printer_inorder(node->l);
	cout << node->val << ' ';
	cout << "(go r) ";
	printer_inorder(node->r);
}

/*
avltree	*avltree::Insert(avltree *node, avltree *n)
{
	if (!node)
		return (n);
	if (node->val < n->val)
		node->r = Insert(node->r, n);
	else if (node->val > n->val)
		node->l = Insert(node->l, n);
	return (node);
}
*/

void	avltree::printer_bfs(avltree *root)
{
	cout << nl "BFS " nl2;
	
	deque<avltree *>	D;
	D.push_front(root);
	while (D.empty() == false)
	{
		avltree	*node = D.front();
		
		cout << node->val << nl;

		D.pop_front();
		if (node->l)
			D.push_back(node->l);
		if (node->r)
			D.push_back(node->r);
	}
}

int	main()
{
	avltree	*root = NULL;
	//avltree	tree;
	
	root = root->Insert(root, new avltree(42));
	
	root->Insert(root, new avltree(32));
	root->Insert(root, new avltree(16));
	root->Insert(root, new avltree(12));
	root->Insert(root, new avltree(64));
	root->Insert(root, new avltree(128));
	root->Insert(root, new avltree(123));
	root->Insert(root, new avltree(256));

	root->printer_inorder(root);
	root->printer_bfs(root);

}

// util

