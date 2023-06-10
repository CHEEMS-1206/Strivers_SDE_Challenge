/// Ques 1 --- Find intersection point of Y LinkedList
/// ->> Codestudio
/// ->> Leetcode 
class Solution {
public:
    int length(ListNode *head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        int lenA = length(headA), lenB = length(headB);
        if(lenA>lenB){
            while(lenA>lenB){
                headA = headA->next;
                lenA--;
            }
        }
        else if(lenA<lenB){
            while(lenA<lenB){
                headB = headB->next;
                lenB--;
            }
        }
        while(headA && headB){
            if(headA==headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

// ============================================================================================== ///

/// Ques 2 --- Cycle in a linked list
/// ->> Codestudio

/// ->> Leetcode 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        
        return false;
    }
};

// ============================================================================================== ///

/// Ques 3 --- Reverse a LinkedList in groups of size k.
/// ->> Codestudio

/// ->> Leetcode 

class Solution {
public:

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* beforeGroup = dummy;
    ListNode* afterGroup = head;
    ListNode* current = nullptr;
    ListNode* previous = nullptr;
    ListNode* nextNode = nullptr;
    while (true) {
        ListNode* cursor = afterGroup;
        for (int i = 0; i < k; i++) {
            if (cursor == nullptr) {
                return dummy->next;
            }
            cursor = cursor->next;
        }
        current = afterGroup;
        previous = beforeGroup;
        for (int i = 0; i < k; i++) {
            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        afterGroup->next = current;
        beforeGroup->next = previous;
        beforeGroup = afterGroup;
        afterGroup = current;
    }
}
};

// ============================================================================================== ///

/// Ques 4 --- Palindrome linked list
/// ->> Codestudio

/// ->> Leetcode 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> forward;
        while( temp != NULL){
            forward.push_back(temp->val);
            cout << temp->val;
            temp = temp->next;
        }

        int i=0, j=forward.size()-1;
        while(i<=j){
            if(forward[i++] != forward[j--])
                return false;
        }
        return true;
    }
};

// ============================================================================================== ///

/// Ques 5 --- Find the starting point of the Loop of Linked list
/// ->> Codestudio

/// ->> Leetcode
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
            
        }
        return 0;
    }
};

// ============================================================================================== ///

/// Ques 6 --- Flattening a Linked List
/// ->> Codestudio

/// ->> Leetcode 

// ============================================================================================== ///