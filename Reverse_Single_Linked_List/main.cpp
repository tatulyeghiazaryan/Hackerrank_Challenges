#include <iostream>

struct SinglyLinkedListNode{
    int m_data;
    SinglyLinkedListNode *m_next;

    SinglyLinkedListNode(int data){
        m_data=data;
        m_next=nullptr;
    }
};

SinglyLinkedListNode* createNewNode(int data){
    SinglyLinkedListNode *newNode=new SinglyLinkedListNode(NULL);
    newNode->m_data=data;
    newNode->m_next= nullptr;
    return newNode;
}

void pushFront(SinglyLinkedListNode **head, int data){
    SinglyLinkedListNode *newNode=createNewNode(data);
    newNode->m_next=(*head);
    (*head)=newNode;
}

void printList(SinglyLinkedListNode *head){
    SinglyLinkedListNode *currentNode=head;
    while(currentNode!= nullptr){
        std::cout<<currentNode->m_data<<" ";
        currentNode=currentNode->m_next;
    }
    std::cout<<"\n";
}

void reverseList(SinglyLinkedListNode **head){
    SinglyLinkedListNode *prevNode= nullptr;
    SinglyLinkedListNode *currentNode=(*head);
    SinglyLinkedListNode *nextNode= nullptr;
    while(currentNode!= nullptr){
        nextNode=currentNode->m_next;
        currentNode->m_next=prevNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }
    (*head)=prevNode;
}

int main(){
   SinglyLinkedListNode *head=new SinglyLinkedListNode(1);
   pushFront(&head, 2);
   pushFront(&head, 3);
   pushFront(&head, 4);
   pushFront(&head, 5);

   printList(head);
   reverseList(&head);
       printList(head);


}