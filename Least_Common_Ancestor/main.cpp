#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if(root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if(data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};



 */

bool nodePath(Node *root, std::vector<Node*>&path, int nodeData){
    if(root== nullptr){
        return false;
    }

    path.push_back(root);

    if(root->data==nodeData){
        return true;
    }

    if((root->left && nodePath(root->left, path, nodeData)) || (root->right && nodePath(root->right, path, nodeData))){
        return true;
    }

    path.pop_back();
    return false;
}

Node *lca(Node *root, int v1, int v2){
    std::vector<Node*>pathNode1;
    std::vector<Node*>pathNode2;

    if(!nodePath(root, pathNode1, v1) || !nodePath(root, pathNode2, v2)){
        return nullptr;
    }

    int i=0;
    for(i; i<(pathNode1.size() && i<pathNode2.size()); i++){
        if(pathNode1[i]!=pathNode2[i]){
            break;
        }
    }

    return pathNode1[i-1];

}

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    std::stack<std::pair<int, Node*>>s1;
    std::stack<std::pair<int, Node*>>s2;
    int v1;
    int v2;

    std::cout<<"input v1 and v2: ";
    std::cin>>v1>>v2;

    int level=0;

    Node *lcaNode=myTree.lca(root, v1, v2);
    std::cout<<lcaNode->data;
}
