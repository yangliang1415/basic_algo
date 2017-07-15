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


int kthSmallest(Node* root, int k) {
    stack<Node*> s;
    int cnt = 0;
    Node* node = root;
    while (node || !s.empty()) {
        if (node) {
            s.push(node);
            node = node -> left;
        } else {
            node = s.top(); s.pop();
            cnt++;
            if (cnt == k) return node -> data;
            node = node -> right;
        }
    }
    return 0;
}

Node* init_tree() {
    Node* node1 = new_node(1);
    Node* node2 = new_node(2);
    connect(node1, 0, node2);
    return node1;
}


int main() {
    Node* head = init_tree();
    int k = kthSmallest(head, 2);
    cout << "k=" << k << endl;
}
