/*
 * date: 20151022
 * author: yangliang
 * ref: http://blog.csdn.net/autumn20080101/article/details/7607148
 *
 * 链表基本功: 原地反转链表
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


/*
 * 递归
 */
ListNode* reverseListRecursive(ListNode *head) {
    // 终止条件
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode *new_head;
    // 递归
    new_head = reverseListRecursive(head->next);
    // 回溯
    head->next->next = head;
    // 尾节点的next，防止循环链表: 1->2->3 --> 3->2->1->2->1
    head->next = NULL;

    return new_head;
}


/* 
 * 非递归
 */
ListNode* reverseList(ListNode *head) {
    ListNode *after = NULL;
    ListNode *mid = head;
    ListNode *before;
    while (mid) {
        before = mid->next;

        // 状态转移
        mid->next = after;
        after = mid;
        mid = before;
    }
    return after;
}


int main() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    connect_two_node(l1, l2);
    connect_two_node(l2, l3);

    print_linked_list(l1);

    ListNode *r_l1 = reverseListRecursive(l1);

    print_linked_list(r_l1);

    return 0;
}
