Stack s;
    s.top = NULL;
    s.size = 0;
    Queue q;
    q.size = 0;
    q.head = NULL;
    q.tail = NULL;
    BTNode *temp = root;
    
    
    while(temp!=NULL || s.size != 0){
        while(temp != NULL)
        {
            push(&s,temp);
            temp = temp->left;
        }
        temp = peek(s);
        pop(&s);
        enqueue(&q,temp);
        temp = temp->right;
    }
    for (int i = 0; i < q.size; i++)
    {
        QueueNode *temp1 = q.head;
        for (int j = i+1; j < q.size; j++)
        {
            temp1 = temp1 -> next;
            if (getFront(q) ->item > temp1->data->item)
            {
                int temp3 = getFront(q)->item;
                getFront(q)->item = temp1->data->item;
                temp1->data->item = temp3;
            }
        }
        
    }