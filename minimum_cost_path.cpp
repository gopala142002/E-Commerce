#include <bits/stdc++.h>
using namespace std;

void update(int start, int end, int parent, long long index, vector<int> &tree)
{
  if (start > end)
  {
    return;
  }
  if (start == end)
  {
    tree[parent]++;
    return;
  }
  int mid = (start + end) / 2;
  if (index > mid)
  {
    update(mid + 1, end, 2 * parent + 2, index, tree);
  }
  else
  {
    update(start, mid, 2 * parent + 1, index, tree);
  }
  tree[parent] = tree[2 * parent + 1] + tree[2 * parent + 2];
}

int query(int start, int end, int parent, int qstart, int qend, vector<int> &tree)
{
  if (qstart > end || qend < start)
  {
    return 0;
  }
  if (qstart <= start && qend >= end)
  {
    return tree[parent];
  }
  int mid = (start + end) / 2;
  int L = query(start, mid, 2 * parent + 1, qstart, qend, tree);
  int R = query(mid + 1, end, 2 * parent + 2, qstart, qend, tree);
  return L + R;
}

int getSubsCount(string &S,vector<int>&tree)
{
  int n = S.size();
  tree.resize(4 * 2 * n + 1, 0);

  int shift = n;
  long long currSum = 0;
  long long cnt = 0;

  update(0, 2 * n, 0, 0 + shift, tree);

  for (int i = 0; i < n; i++)
  {
    currSum += (S[i] == '1' ? 1 : -1);
    int lessThan = (currSum + shift) - 1;
    cnt += query(0, 2 * n, 0, 0, lessThan, tree);
    update(0, 2 * n, 0, currSum + shift, tree);
  }
  return cnt;
}
void aar(){
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        vector<vector<int>> arr(m,vector<int> (n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int num;
                cin>>num;
                arr[i][j]=num;
            }
        }
        cout<<solve(arr)<<endl;
    }
    return 0;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    vector<int> tree;
    int ans = getSubsCount(s, tree);
    cout << ans << endl;
  }
  for(int i=0; i<t; i++){
    
  }
  
  return 0;
}
