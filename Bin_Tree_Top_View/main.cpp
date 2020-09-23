#include <iostream>
#include <map>

struct Node{

    int value;
    Node *left;
    Node *right;

    Node(int val){
        value=val;
        left= nullptr;
        right= nullptr;
    }

};


void topViewTraverse(Node *root, int dist, int level, std::map<int, std::pair<int, int>>&treeMap){
    if(root== nullptr){
        return;
    }

    if(treeMap.find(dist)==treeMap.end() || level<treeMap[dist].second){
        treeMap[dist]={root->value, level};
    }

    topViewTraverse(root->left, dist-1, level+1, treeMap);
    topViewTraverse(root->right, dist+1, level+1, treeMap);
}


void printTopView(Node *root){
    std::map<int, std::pair<int, int>>treeMap;
    int dist=0;
    int level=0;
    topViewTraverse(root, dist, level, treeMap);

    for(auto it=treeMap.rbegin(); it!=treeMap.rend(); it++){
        std::cout<<it->second.first<<" ";
    }

}

Node *insertNode(Node *root, int value){
    if(root==nullptr){
        return new Node(value);
    }
    if(root->value<value){
        Node *curr;
        curr=insertNode(root->left, value);
        root->left=curr;
    }
    else{
        Node *curr;
        curr=insertNode(root->right, value);
        root->right=curr;
    }
    return root;
}


int main(){
    Node *root=new Node(7);

    insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 9);


    printTopView(root);

}