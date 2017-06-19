#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void connect(Node* current, Node* left, Node* right) {
    current -> left = left;
    current -> right = right;
}

struct Node* new_node(int data) {
    struct Node* node = new Node();
    node -> data = data;
    node -> left = 0;
    node -> right = 0;
    return node;
}

void pre_travel_recurive(Node* node) {
    if (node == 0) return;
    cout << node -> data;
    pre_travel_recurive(node -> left);
    pre_travel_recurive(node -> right);
}

void pre_travel(Node* node) {
    stack<Node*> s;
    while(node || !s.empty()) {
        if (node) {
            cout << node -> data;
            s.push(node);
            node = node -> left;
        } else {
            node = s.top();
            s.pop();
            node = node -> right;
        }
    }
}

void mid_travel_recurive(Node* node) {
    if (node == 0) return;
    mid_travel_recurive(node -> left);
    cout << node -> data;
    mid_travel_recurive(node -> right);
}

void mid_travel(Node* node) {
    stack<Node*> s;
    while(node || !s.empty()) {
        if (node) {
            s.push(node);
            node = node -> left;
        } else {
            node = s.top();
            s.pop();
            cout << node -> data;
            node = node -> right;
        }
    }
}

void after_travel_recurive(Node* node) {
    if (node == 0) return;
    after_travel_recurive(node -> left);
    after_travel_recurive(node -> right);
    cout << node -> data;
}

/**
 * use visit flag
 *
 * ref
 * http://www.cnblogs.com/fightformylife/p/4089557.html
 * https://stackoverflow.com/questions/1294701/post-order-traversal-of-binary-tree-without-recursion
 */
void after_travel(Node* node) {
    stack<pair<Node*, int> > s;
    s.push(make_pair(node, 0));
    while(!s.empty()) {
        // 取出stack顶元素
        node = s.top().first;
        int is_visited = s.top().second;
        s.pop();
        //
        if (!is_visited) {
            // 左右节点访问标签变化
            s.push(make_pair(node, 1));
            // 左右节点入stack，表示已访问
            if (node -> right) s.push(make_pair(node -> right, 0));
            if (node -> left) s.push(make_pair(node -> left, 0));
        } else {
            // 左右节点都已访问， 输出当前节点data
            cout << node -> data;
        }
    }
}


Node* init_tree() {
    Node* node1 = new_node(1);
    Node* node2 = new_node(2);
    Node* node3 = new_node(3);
    Node* node4 = new_node(4);
    Node* node5 = new_node(5);
    Node* node6 = new_node(6);
    Node* node7 = new_node(7);

    connect(node1, node2, node3);
    connect(node2, node4, node5);
    connect(node4, 0, node6);
    connect(node5, node7, 0);

    return node1;
}



int main() {
    Node* head = init_tree();

    pre_travel_recurive(head);
    cout << endl;
    pre_travel(head);
    cout << endl;

    cout << "===========" << endl;

    mid_travel_recurive(head);
    cout << endl;
    mid_travel(head);
    cout << endl;


    cout << "===========" << endl;
    after_travel_recurive(head);
    cout << endl;
    after_travel(head);
    cout << endl;
    return 0;
}
