#include <bits/stdc++.h>

using namespace std;

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

/* you only have to complete the function given below.
Node is defined as

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
    //root, left, right
    void preOrder(Node *root) {
        if(root!=nullptr){
            std::cout<<root->data<<std::endl;
            preOrder(root->left);
            preOrder(root->right);
        }

    }

}; //End of Solution


int main(){
    Solution s1;
    Node *root=new Node(11);
    s1.insert(root, 5);
    s1.insert(root, 4);
    s1.insert(root, 6);
    s1.insert(root, 3);
    s1.insert(root, 13);
    s1.insert(root, 15);

    s1.preOrder(root);


}