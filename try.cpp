#include <bits/stdc++.h>
using namespace std;
int getMid(int s, int e)
{  
    return s + (e -s)/2;  
}
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
    if (qs <= ss && qe >= se)
        return st[si];
    if (se < qs || ss > qe)
        return 0;
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}
int getSum(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}
int main()
{
    int Q, N, a, b;
    string str;
    cin >> str >> Q;
    N = str.length();
    int open[N], close[N];
    memset(open, 0, sizeof(open));
    memset(close, 0, sizeof(close));
    for(int i = 0; i < N; i++)
    {
        if(str[i] == '(')
        {
            open[i] = 1;
        }
        else
        {
            close[i] = 1;
        }
    }
    int height = (int)ceil(log2(N));
    int size = 2 * (int)pow(2, height) - 1;
    int *open_st = constructST(open, N);
    int *close_st = constructST(close, N);
    for(int i = 0; i < size; i++)
    {
        printf("%d  ", open_st[i]);
    }
    printf("\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d  ", close_st[i]);
    }
    printf("\n");
    while(Q--)
    {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        int ans = getSum(open_st, N, a, b);
        int ans1 = getSum(close_st, N, a, b);
        printf("%d   %d\n", ans, ans1);
    }
    return 0;
}