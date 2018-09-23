#include <bits/stdc++.h>
using namespace std;
string s;
struct Node
{
    int numL;
    int numR;
    int sum;
}
struct TreeNode
{
    int l;
    int r;
    Node val;
}tree[3 * MAXN];
void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    if(l == r)
    {
        tree[x].val.numL = s[l - 1] == '(';
        tree[x].val.numR = s[l - 1] == ')';
        tree[x].val.sum = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * x, l, mid);
    build(2 * x + 1, mid + 1, r);
    tree[x].val = tree[2 * x].val + tree[2 * x + 1].val;
}
Node query(int x, int l, int r)
{
    if(tree[x].l == l && tree[x].r == r)
    {
        return tree[x].val;
    }
    int mid = (l + r) / 2;
    return (query(2 * x, l, mid) + query(2 * x + 1, mid + 1, r));
}
int main()
{
    int q, l, r;
    cin >> s;
    build(1, 1, s.size());
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(1, l, r).sum << 1);
    }
    return 0;
}