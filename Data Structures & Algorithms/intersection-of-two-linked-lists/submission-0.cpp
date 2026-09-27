/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* temp)
    {
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp -> next;
        }
        return count;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int n1 = getLength(headA);
        int n2 = getLength(headB);
        ListNode* list1 = headA;
        ListNode* list2 = headB;
        if(n1 > n2){
            int count = 0;
            int diff = n1 - n2;
            while(count < diff){
                list1 = list1 -> next;
                count++;
            }
        }else{
            int count = 0;
            int diff = n2 - n1;
            while(count < diff){
                list2 = list2 -> next;
                count++;
            }
        }

        while(list1 != list2){
            list1 = list1 -> next;
            list2 = list2 -> next;
        }
        return list1;
    }
};