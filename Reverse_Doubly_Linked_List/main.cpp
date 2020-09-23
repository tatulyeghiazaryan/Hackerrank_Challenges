#include <iostream>


struct DoublyLinkedListNode{
    int m_data;
    DoublyLinkedListNode *m_nextNode;
    DoublyLinkedListNode *m_prevNode;
    DoublyLinkedListNode(int data):m_data(data), m_nextNode(nullptr), m_prevNode(nullptr){}
};

DoublyLinkedListNode* reverse(DoublyLinkedListNode **head){
    DoublyLinkedListNode *prev= nullptr;
    DoublyLinkedListNode *current=(*head);
    DoublyLinkedListNode *next;

    while(current!= nullptr){
        next=current->m_nextNode;
        current->m_nextNode=prev;
        current->m_prevNode=next;

        prev=current;
        current=next;
    }

    (*head)=prev;
}

//inserts node from the head
void insertNode(DoublyLinkedListNode **head, int data){
    DoublyLinkedListNode *newNode=new DoublyLinkedListNode(data);
    newNode->m_nextNode=*head;
    (*head)->m_prevNode=newNode;
    (*head)=newNode;
}

void printList(DoublyLinkedListNode *head){
    while(head!=nullptr){
        std::cout<<head->m_data<<" ";
        head=head->m_nextNode;
    }
}

int main(){
    DoublyLinkedListNode *head=new DoublyLinkedListNode(1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 6);

    printList(head);
    std::cout<<"\n";
//    reverse(&head);
    reverse(&head);
    printList(head);

}
