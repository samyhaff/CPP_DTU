#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
};

Node *get_tree(int n) {
    Node *tree = new Node;

    if (n == 0 || n == 1) {
        tree->val = 1;
        tree->left = nullptr;
        tree->right = nullptr;
        return tree;
    }

    tree->left = get_tree(n - 1);
    tree->right = get_tree(n - 2);
    tree->val = tree->right->val + tree->left->val;

    return tree;
}

int get_size(Node *tree) {
    if (tree == nullptr) return 0;
    return 1 + get_size(tree->right) + get_size(tree->left);
}

int get_depth(Node *tree) {
    if (tree == nullptr) return 0;
    return 1 + max(get_depth(tree->right), get_depth(tree->left));
}

void print_calls(Node *tree) {
    if (tree == nullptr) return;
    cout << tree->val << " ";
    print_calls(tree->left);
    print_calls(tree->right);
}

int get_leaves(Node *tree) {
    if (tree == nullptr) return 0;
    if (tree->right == nullptr && tree->left == nullptr) return 1;
    return get_leaves(tree->left) + get_leaves(tree->right);
}

int main() {
    int n;

    cin >> n;

    Node *tree = get_tree(n);
    cout << "Call tree in pre-order: ";
    print_calls(tree); cout << endl;
    cout << "Call tree size: " << get_size(tree) << endl;
    cout << "Call tree depth: " << get_depth(tree) << endl;;
    cout << "Call tree leafs: " << get_leaves(tree) << endl;

    return 0;
}
