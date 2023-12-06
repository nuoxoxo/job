#include "iostream"
#include "deque"
#define none NULL
#define nl "\n"
#define nl2 "\n\n"

using	namespace std;

class	bstree
{

int	val;
bstree	*l;
bstree	*r;

public:
	bstree();
	~bstree();
	bstree(int);

	bstree	*Insert(bstree*, int);
	void	printer_inorder(bstree*);
	void	printer_bfs(bstree *root);
};

bstree::bstree() : val(0), l(none), r(none) {} // default constr
bstree::bstree(int n) : val(n), l(none), r(none) {} // param constr
bstree::~bstree() {}

bstree	*bstree::Insert(bstree *node, int n)
{
	if (!node)
		return (new bstree(n));
	if (node->val < n)
		node->r = Insert(node->r, n);
	else if (node->val > n)
		node->l = Insert(node->l, n);
	return (node);
}

// inorder printer
void	bstree::printer_inorder(bstree *node)
{
	if (!node)
	{
		cout << nl;
		return ;
	}
	cout << " (go left) ";
	printer_inorder(node->l);
	cout << node->val << ' ';
	cout << " (go right) ";
	printer_inorder(node->r);
}

// BFS printer
void	bstree::printer_bfs(bstree *root)
{
	cout << nl << __FUNCTION__ << nl2;
	
	deque<bstree *>	D;
	D.push_front(root);
	while (D.empty() == false)
	{
		bstree	*node = D.front();
		
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
	bstree	*root = NULL;
	bstree	tree;
	
	root = tree.Insert(root, 42);
	
	tree.Insert(root, 32);
	tree.Insert(root, 16);
	tree.Insert(root, 12);
	tree.Insert(root, 64);
	tree.Insert(root, 128);
	tree.Insert(root, 123);
	tree.Insert(root, 256);
	
	cout << nl "Inorder " nl2; 
	tree.printer_inorder(root);
	tree.printer_bfs(root);

}
