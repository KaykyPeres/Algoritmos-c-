#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
    int key;
    int value;
    Node *left, *right;
    Node(int k, int v) : key(k), value(v), left(NULL), right(NULL) {}
};

void insert(Node *&root, int key, int value) {
    if (!root) {
        root = new Node(key, value);
        return;
    }
    if (key < root->key)
        insert(root->left, key, value);
    else
        insert(root->right, key, value);
}

void levelOrder(Node *root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout << temp->key << ":" << temp->value << " " << endl;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

void freeTree(Node *&root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    int P;
    cin >> P;
    Node *root = NULL;
    for (int i = 0; i < P; i++) {
        double V, E, O;
        cin >> V >> E >> O;
        int T = floor(V * E * 7 * E * 7 * O);
        insert(root, i, T);
    }
    show_ordered(root);
    //levelOrder(root);
    freeTree(root);
}