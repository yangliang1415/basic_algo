/*
 * date: 20151025
 * author: yangliang
 *
 * 链表基本功: 链表 回文判断
 */


#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void print_linked_list(ListNode *l) {
    ListNode *list_node = l;
    while (list_node) {
        cout << list_node->val << " ";
        list_node = list_node->next;
    }
    cout << endl;
}


void connect_two_node(ListNode *l1, ListNode *l2) {
    l1->next = l2;
}


ListNode* reverseListRecursive(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode * new_head;
    new_head = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return new_head;
}



ListNode* findMidNode(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


bool isPalindrome(ListNode* head) {
    if (head == NULL) return true;

    ListNode *mid_node = findMidNode(head);
    ListNode *new_head = mid_node->next;
    ListNode *new_head_reverse = reverseListRecursive(new_head);

    while (new_head_reverse) {
        if (head->val != new_head_reverse->val) {
            return false;
        }
        head = head->next;
        new_head_reverse = new_head_reverse->next;
    }

    return true;
}


int main() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(1);
    connect_two_node(l1, l2);
    connect_two_node(l2, l3);
    connect_two_node(l3, l4);
    connect_two_node(l4, l5);

    cout << isPalindrome(l1) << endl;

    return 0;
}
