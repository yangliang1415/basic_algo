/*
 * date: 20151025
 * author: yangliang
 *
 * 链表基本功: 链表重新排序
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


void mergeList(ListNode *head1, ListNode *head2) {
    ListNode *node1 = head1;
    ListNode *node2 = head2;
    while (node1 && node2) {
        ListNode *node1_old_next = node1->next;
        node1->next = node2;
        node1 = node1_old_next;

        ListNode *node2_old_next = node2->next;
        node2->next = node1;
        node2 = node2_old_next;
    }
}


/* 输入：l0->l1->l2->l3->l4->l5 
 * 输出：l0->l5->l1->l4->l2->l3
 * 逻辑：拆分、逆序、合并
 */
void reorderList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    // 拆分
    ListNode *mid_node = findMidNode(head);
    ListNode *another_head = mid_node->next;
    mid_node->next = NULL;
    
    // 逆序
    ListNode *new_head = reverseListRecursive(another_head);
    // 合并
    ListNode *node1 = head;
    ListNode *node2 = new_head;
    mergeList(head, new_head);
}


int main() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    connect_two_node(l1, l2);
    connect_two_node(l2, l3);
    connect_two_node(l3, l4);
    connect_two_node(l4, l5);

    print_linked_list(l1);

    reorderList(l1);

    print_linked_list(l1);

    return 0;
}
