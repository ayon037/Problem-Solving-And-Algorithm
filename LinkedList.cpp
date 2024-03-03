#include<bits/stdc++.h>
using namespace std;
class LinkedList
{
    public:
        int data;
        LinkedList* next;
        LinkedList(int val)
        {
            data=val;
            next=NULL;
        }
};

void InsertAtHead(LinkedList* &head,int val)
{
    LinkedList *temp=new LinkedList(val);
    temp->next=head;
    head=temp;
}

void InsertAtTail(LinkedList* &head,int val)
{
    LinkedList *temp=new LinkedList(val);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    LinkedList *n=head;
    while(n->next!=NULL)
    {
        n=n->next;
    }
    n->next=temp;
}

void display(LinkedList *head)
{
    LinkedList *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
bool Search(LinkedList *head,int key)
{
    LinkedList *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
    cout<<"NULL"<<endl;
}
void DeleteAtHead(LinkedList* &head)
{
    LinkedList* toDelete=head;
    head=head->next;
    delete toDelete;
}
void Delete(LinkedList* &head,int key)
{
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        DeleteAtHead(head);
        return;
    }
    LinkedList *temp=head;
    while(temp->next->data!=key)
    {
        temp=temp->next;
    }
    LinkedList* toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}
LinkedList* ReverseIterative(LinkedList* &head)
{
    LinkedList* prevptr=NULL;
    LinkedList* currptr=head;
    LinkedList* nextptr;
    while(currptr!=NULL)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;

}
LinkedList* ReverseRecursive(LinkedList* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    LinkedList* newhead=ReverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

LinkedList* ReverseK(LinkedList* &head,int k)
{
    LinkedList* prevptr=NULL;
    LinkedList* currptr=head;
    LinkedList* nextptr;
    int cnt=0;
    while(currptr!=NULL && cnt!=k)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        cnt++;
    }
    if(nextptr!=NULL)
    {
        head->next=ReverseK(nextptr,k);
    }
    return prevptr;
}
int main()
{
    LinkedList *head=NULL;
    InsertAtTail(head,2);
    InsertAtTail(head,5);
    InsertAtTail(head,7);
    InsertAtHead(head,21);
    InsertAtTail(head,25);
    display(head);
    cout<<Search(head,5);
    DeleteAtHead(head);
    display(head);
    Delete(head,7);
    display(head);
    InsertAtTail(head,7);
    InsertAtHead(head,21);
    LinkedList *newhead=ReverseIterative(head);
    display(newhead);
    LinkedList *newhead2=ReverseRecursive(newhead);
    display(newhead2);
    int k=2;
    LinkedList *newhead3=ReverseK(newhead2,k);
    display(newhead3);
}