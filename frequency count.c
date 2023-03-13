#include <stdio.h>
#include <stdlib.h>
struct node
{
    int n;
    struct node *next;
};
 
struct node2
{
    int n;
    int t;
    struct node2 *next;
};
 
void create(struct node **);
void demo(struct node *, struct node2 **);
void calculate(struct node **);
void compute(struct node2 **);
void display(struct node *);
void disp(struct node2 *);
 
void demo(struct node *head, struct node2 **res)
{
    struct node *p;
    struct node2 *temp, *prev;
 
    p = head;
    while (p != NULL)
    {
        temp = *res;
        while (temp != NULL && temp->n != p->n)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            temp = (struct node2 *)malloc(sizeof(struct node2));
            temp->n = p->n;
            temp->t = 1;
            temp->next = NULL;
            if (*res != NULL)
            {
                prev->next = temp;
            }
            else
            {
                *res = temp;
            }
        }
        else
        {
            temp->t += 1;
        }
        p = p->next;
    }
}
 
void create(struct node **head)
{
    int c, ch;
    struct node *temp, *rear;
 
    do
    {
        printf("Enter number: ");
        scanf("%d", &c);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->n = c;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        printf("Do you wish to continue, choose 1 or 0: ");
        scanf("%d", &ch);
    } while (ch != 0);
    printf("\n");
}
 
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d\t", p->n);
        p = p->next;
    }
    printf("\n");
}
 
void disp(struct node2 *p)
{
    printf("Number\tFrequency\n");
    while (p != NULL)
    {
        printf("    %d\t\t%d\n", p->n, p->t);
        p = p->next;
    }
}
 
void calculate(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->next;
    while ((*head) != NULL)
    {
        free(temp);
        temp = *head;
        (*head) = (*head)->next;
    }
}
 
void compute(struct node2 **head)
{
    struct node2 *temp = *head;
    *head = (*head)->next;
    while ((*head) != NULL)
    {
        free(temp);
        temp = *head;
        (*head) = (*head)->next;
    }
}
int main()
{
    struct node *p = NULL;
    struct node2 *head = NULL;
    int n;
 
    printf("Enter data into the list\n");
    create(&p);
    printf("Displaying the frequency of each node in the list:\n");
    display(p);
    demo(p, &head);
    disp(head);
    calculate(&p);
    compute(&head);
 
    return 0;
}
