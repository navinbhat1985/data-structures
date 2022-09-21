Node* cur = root
while(cur != NULL || !stack.empty()) {
    while(cur != NULL) {
        Stack.push(cur); cur = cur->left;
    }
    Node* n = Stack.pop(); printf(" %d" , n);
    cur = cur->right;
}
