root = insert(root,1);
    root = insert(root,3);
    root = insert(root,2);
    root = insert(root,4);
    root = insert(root,6);
    root = insert(root,5);
    root = insert(root,5);
    root = insert(root,7);
    root = insert(root,8);
    root = insert(root,8);
    root = insert(root,10);


    root = delete(root,7);
    root = delete(root,1);

    PreOrderTraversal(root);