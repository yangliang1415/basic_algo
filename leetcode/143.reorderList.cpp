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


ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || !head -> next) return head;
    int len = 0;
    while (head) {
        head = head -> next;
        len++;
    }
    if (len < k) return head;

    ListNode* oldHead = head;
    cout << "oldHead=" << oldHead -> val << endl;
    ListNode* newHeadFirstKNodes = NULL;
    int count = 0;
    while (head && count < k) {
        ListNode* next = head -> next;
        head -> next = newHeadFirstKNodes;
        newHeadFirstKNodes = head;
        head = next;
        count++;
    }
    // oldHead -> next = head;
    return newHeadFirstKNodes;
}

int main() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    connect_two_node(l1, l2);

    print_linked_list(l1);

    ListNode* res = reverseKGroup(l1, 1);

    print_linked_list(res);

    return 0;
}
