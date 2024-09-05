struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node* i=head1, *j=head2;
        Node* temp3=NULL;
        Node* head3=NULL;
        
        while(i!=NULL && j!=NULL){
            if(i->data == j->data){
                Node* newNode = new Node(i->data);
                newNode->next=NULL;
                
                if(head3==NULL){
                    head3=newNode;
                    temp3=newNode;
                }
                else{
                    temp3->next=newNode;
                    temp3=temp3->next;
                }
               
                i=i->next;
                j=j->next;
            }
            else if(i->data<j->data){
                i=i->next;
            }
            else{
                j=j->next;
            }
        }
        return head3;
    }
};
