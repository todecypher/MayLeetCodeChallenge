/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        
         ListNode *odd = head;
         ListNode *even = head->next;
            
         ListNode *copy = head->next;
        if(!even) return head;
        
        while(odd and even){
            if(odd->next->next){
                    odd->next = odd->next->next;
                    odd=odd->next;
            }
            if(even->next){
                    even->next = even->next->next;
                    if(even->next)
                        even = even->next;
                    else
                        break;
            }
            else
                break;
        }

        odd->next = copy;
        even->next = NULL;
        return head;
    }
};