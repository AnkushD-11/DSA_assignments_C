void printlinkedlist(struct NODE *p)
{
    while(p != NULL)
    {
        printf("%d--->", p->data);
        p = p->next;
    }
}