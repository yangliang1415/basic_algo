/*
 * date: 20151115
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


void connect_two_node(ListNode *l1, ListNode *l2) {
    l1->next = l2;
}


void print_linked_list(ListNode *l) {
    ListNode *list_node = l;
    while (list_node) {
        cout << list_node->val << " ";
        list_node = list_node->next;
    }
    cout << endl;
}


ListNode* partition(ListNode* head, int x) {
    if (head == NULL || head->next == NULL) return head;

    // 拆分
    ListNode* head1 = NULL;
    ListNode* temp1 = NULL;
    ListNode* head2 = NULL;
    ListNode* temp2 = NULL;

    while (head) {
        ListNode* new_node  = new ListNode(head->val);
        if (head->val >= x) {
            if (head1) {
                temp1->next = new_node;
                temp1 = temp1->next;
            } else {
                head1 = temp1 = new_node;
            }
        } else {
            if (head2) {
                temp2->next = new_node;
                temp2 = temp2->next;
            } else {
                head2 = temp2 = new_node;
            }
        }

        head = head->next;
    }

    print_linked_list(head1);
    print_linked_list(head2);

    // 合并
    if (temp2) {
        temp2->next = head1;
    } else {
        return head1;
    }

    return head2;
}


int main() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(1);
    connect_two_node(l1, l2);
    
    print_linked_list(partition(l1, 0));

    return 0;
}
