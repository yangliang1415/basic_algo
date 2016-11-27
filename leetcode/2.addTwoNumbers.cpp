/*
 * date: 20151018
 * author: yangliang
 *
 * 链表基本功; 加法
 */

#include <iostream>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *result = NULL;
    ListNode *current_node = NULL;
    int plus = 0;
    int num1 = 0;
    int num2 = 0;
    int num = 0;

    while (l1 || l2) {
        if (l1) num1 = l1->val;
        else num1 = 0;

        if (l2) num2 = l2->val;
        else num2 = 0;

        // new node
        num = (num1 + num2 + plus) % 10;
        if (current_node) {
            current_node->next = new ListNode(num);
            current_node = current_node->next;
        } else {
            // first node
            current_node = new ListNode(num);
            result = current_node;
        }

        plus = (num1 + num2 + plus) / 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        // cout << num1 << "\t" << num2 << "\t" << plus << endl;
    }
    // caution
    if (plus) {
        current_node->next = new ListNode(plus);
    }

    return result;
}


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


int main() {
    /*
     * test cases:
     * 1 0
     * 1 999
     * 11 99
     * 3 2222
     */
    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(9);
    connect_two_node(l1, l2);
    cout << "l1:\t";
    print_linked_list(l1);

    ListNode *r1 = new ListNode(5);
    ListNode *r2 = new ListNode(6);
    connect_two_node(r1, r2);
    cout << "r1:\t";
    print_linked_list(r1);
    
    
    ListNode *result =  addTwoNumbers(l1,  new ListNode(1));
    cout << "l1+r1 result:\t";
    print_linked_list(result);

    return 0;
}


