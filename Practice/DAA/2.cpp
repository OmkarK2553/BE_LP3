#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode{
    char data;
    int freq;
    MinHeapNode *left,*right;

    MinHeapNode(char data,int freq){
        this->data=data;
        this->freq=freq;
        left=right=nullptr;
    }
};

void printNodes(MinHeapNode* root,string s){
    if(root==nullptr){
        return;
    }

    if(root->data!='$'){
        cout<<root->data<<": "<<s<<"\n";
    }
    printNodes(root->left,s+"0");
    printNodes(root->right,s+"1");
}

struct compare{
    bool operator()(MinHeapNode *a, MinHeapNode *b){
        return (a->freq>b->freq);
    }
};

void HuffmanEncoding(vector<char> data,vector<int> freq){
    MinHeapNode *leftChild,*rightChild,*temp;

    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> minHeap;

    for(int i=0;i<data.size();i++){
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    while (minHeap.size() != 1){
        leftChild = minHeap.top();
        minHeap.pop();
        rightChild = minHeap.top();
        minHeap.pop();

        temp = new MinHeapNode('$',leftChild->freq+rightChild->freq);
        temp->left = leftChild;
        temp->right = rightChild;
        minHeap.push(temp);
    }
    printNodes(minHeap.top(),"");
    
}

int main()
{
    int n;
    vector<char> data;
    vector<int> freq;

    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        int d;
        cin>>c>>d;
        data.push_back(c);
        freq.push_back(d);
    }

    HuffmanEncoding(data,freq);
}