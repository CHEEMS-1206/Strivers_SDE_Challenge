/// Ques 1 ---Reverse the linked list
/// ->> Codestudio
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int>* forward = NULL;
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

/// ->> Leetcode 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = NULL;

        // reverse the ll
        while(temp != NULL){
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

// ============================================================================================== ///

/// Ques 2 --- Middle of the linked list
/// ->> Codestudio
Node *findMiddle(Node *head) {
    if(head->next == NULL){
        return head;
    }
    if(head == NULL){
        return NULL;
    }
    // getting length of node
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    count = count/2;
    temp = head;
    int reach = 0;
    while(reach < count){
        temp = temp->next;
        reach++;
    }
    return temp;
}

/// ->> Leetcode 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* end = head;
        ListNode* middle = head;
        while(end != NULL && end->next != NULL){
            middle = middle->next;
            end = end->next->next;
        }
        return middle;
    }
};

// ============================================================================================== ///

/// Ques 3 --- Merge two sorted ll
/// ->> Codestudio
Node<int>* sortTwoLists(Node<int>* l1, Node<int>* l2)
{
    // Write your code here.
    if(l1==NULL)
        return l2;
       else if(l2==NULL)
        return l1;
    Node<int>*t=NULL;
    if(l1->data<=l2->data){
        t=l1;
        l1=l1->next;
    }
    else{
        t=l2;
        l2=l2->next;
    }
    Node<int>*h=t;
    while(l1!=NULL && l2!=NULL){
        Node<int>*temp=NULL;
        if(l1->data<=l2->data){
            temp=l1;
            l1=l1->next;
        }
        else{
            temp=l2;
            l2=l2->next;
        }
        t->next=temp;
        t=temp;
    }
    if(l1!=NULL)
        t->next=l1;
    else
        t->next=l2;
    return h;
}

/// ->> Leetcode 

// ============================================================================================== ///

/// Ques 4 --- Remove element from the back of the ll
/// ->> Codestudio
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(head == NULL || K==0)
        return head;
    LinkedListNode<int> *forLength = head;
    int len = 0;
    while(forLength != NULL){
        len++;
        forLength = forLength->next;
    }
    if(K == len) return head -> next;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = head;
    int j = (len-K);
    while( j != 0){
        prev = curr;
        curr = curr->next;
        j--;
    }
    prev->next = curr->next;
    curr->next = NULL;
    
    return head;
}

/// ->> Leetcode 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // first we reverse the ll
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = NULL;

        if(head->next == NULL)
            return NULL;

        if(n == 1){
            while(temp->next != NULL){
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            return head;
        }

        // reverse the ll
        while(temp != NULL){
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
        temp = head;
        prev = head;
        // then we delete nth node from forward
        while(n > 1){
            prev = temp;
            temp = temp->next;
            n--;
        }
        prev->next = temp->next;

        // than we reverse the ll again
        temp = head;
        curr = head;
        prev = NULL;
        // reverse the ll
        while(temp != NULL){
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

// ============================================================================================== ///

/// Ques 5 --- Add two numbers as LinkedList
/// ->> Codestudio

/// ->> Leetcode
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};

// ============================================================================================== ///

/// Ques 6 --- Delete the given node from the ll
/// ->> Codestudio
void deleteNode(LinkedListNode<int> * node) {
    node->data=node->next->data;
    node->next=node->next->next;
}

/// ->> Leetcode 

// ============================================================================================== ///