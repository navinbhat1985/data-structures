int preorder[100] = {0};
int len = 0
void serialize(node* root)
{
    if (root == NULL) {
        preorder[len++]= -1;
        return;
    }
    preorder[len++] = root->data;
    serialize(root->left);
    serialize(root->right);
}

int index = -1;

node* deserialize()
{
    index++;
    if (preorder[index] == -1)
        return NULL;
    Node* node = calloc(1, sizeof(Node));
    node->left = deserialize();
    node->right = deserialize();
    return node;
    
}