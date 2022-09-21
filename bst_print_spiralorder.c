if (root == NULL)
    return

s1.push(root)
while( !s1.empty || !s2.empty)
{
    while(!s1.empty) { 
        Node* n = s1.pop() 
        print(n.data); 
        s2.push(n.right);
        s2.push(n.left);
    }
    while(!s2.empty) 
    { 
        Node* n = s2.pop() 
        print(n.data); 
        s2.push(n.left);
        s2.push(n.right);
    }
}
