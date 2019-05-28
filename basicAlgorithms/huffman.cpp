#include<bits/stdc++.h>

using namespace std;

pair <int,char>arr[101];
struct minHeap
{
    char data;
    int freq;
    minHeap *left,*right;

    minHeap(char data, int freq)
    {
        this->data=data;
        this->freq=freq;
        left=right=NULL;
    }
};

struct cmp
{
    bool operator()(minHeap* l, minHeap* r)
    {
        return(l->freq > r->freq);
    }
};

minHeap* huffman(int sz)
{
    minHeap *left,*right,*top;

    priority_queue<minHeap*, vector<minHeap*>, cmp> v;
     for (int i = 0; i < sz; ++i)
        v.push(new minHeap(arr[i].second, arr[i].first));

      while (v.size() != 1)
    {
        // Extract the two minimum freq items from min heap
        left = v.top();
        v.pop();

        right = v.top();
        v.pop();

        top = new minHeap('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        v.push(top);
    }
        return v.top();
}

void printCodes(minHeap* root, string str)
{
    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
int main()
{
   // pair<int,char>arr[5001];
    char c;
    int f,n;

    cin>>n;

    for(int i=0;i<n;++i)
        cin>>arr[i].first>>arr[i].second;

    sort(arr,arr+n);
    minHeap *root;

    root=huffman(n);
    printCodes(root,"");
}
