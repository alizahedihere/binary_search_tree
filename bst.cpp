#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;                  
    struct node *left, *right;
};
struct node *create(int item)
{
    struct node *t;
    t = new node;              
    t->data = item;            
    t->left = t->right = NULL;
    return t;
}
struct node *insert(struct node *n, int item)
{
    if (n == NULL)
        return create(item);
    if (item < n->data)
        n->left = insert(n->left, item);
    else if (item > n->data)
        n->right = insert(n->right, item);
    return n;
}
void inorder(struct node *r)
{
    if (r != NULL)
    {
        inorder(r->left);       
        cout << r->data << " "; 
        inorder(r->right);
    }
}
int main()
{
    vector<int> a;
    int n, input;
    cout << "Number Of Nods : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Node " << i + 1 << " : ";
        cin >> input;
        a.push_back(input);
    }
    vector<int>::iterator itr;
    itr = a.begin();
    struct node *r = NULL;
    r = insert(r, *itr);
    itr++;
    for (; itr != a.end(); itr++)
    {
        insert(r, *itr);
    }
    inorder(r);
    return 0;
}
