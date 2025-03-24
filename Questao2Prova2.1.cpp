#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

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

void inOrder(Node *root, vector<pair<int,int> > &result) {
    if (!root) return;
    inOrder(root->left,result);
    result.push_back(make_pair(root->,root->key));
    inOrder(root->right,result);
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
    
    int Tmin, Tmax;
    cin >> Tmin >> Tmax;

    vector<pair<int,int> > result;
    
    inOrder(root, result);

    for(vector<pair<int,int> >::iterator it = result.begin(); it != result.end(); ++it){
        if(it->first >= Tmin && it->first <= Tmax){
            cout << it->second << ":" << it->first << " "<< endl;
        }
    }
    cout << endl;

    freeTree(root);

    return 0;
}