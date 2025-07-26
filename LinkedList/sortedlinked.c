//This C program merges two sorted linked lists into a single sorted linked list, removing duplicates.
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
} *start1 = NULL, *start2 = NULL, *start3 = NULL, *p1, *p2, *p;

struct node* Sort(struct node* start, int item);

struct node* merge(struct node* start1, struct node* start2) {
    p1 = start1;
    p2 = start2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            start3 = Sort(start3, p1->data);
            p1 = p1->link;
        } else if (p1->data > p2->data) {
            start3 = Sort(start3, p2->data);
            p2 = p2->link;
        } else if (p1->data == p2->data) {
            start3 = Sort(start3, p2->data);
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    while (p1 != NULL) {
        start3 = Sort(start3, p1->data);
        p1 = p1->link;
    }

    while (p2 != NULL) {
        start3 = Sort(start3, p2->data);
        p2 = p2->link;
    }

    return start3;
}

struct node* Sort(struct node* start, int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Unable to allocate memory.");
        return NULL;
    } else {
        temp->data = item;
        temp->link = NULL;

        if (start == NULL || start->data > item) {
            temp->link = start;
            start = temp;
        } else {
            struct node* p = start;
            while (p->link != NULL && p->link->data < item)
                p = p->link;
            temp->link = p->link;
            p->link = temp;
        }
        return start;
    }
}

void display(struct node* start) {
    if (start == NULL) {
        printf("Linked list is empty");
        return;
    } else {
        p = start;
        while (p != NULL) {
            printf("%d\n", p->data);
            p = p->link;
        }
    }
}

int main() {
    int item, d;

    printf("Enter the first list\n");
    printf("Enter the item of 1st list: ");
    scanf("%d", &item);
    start1 = Sort(start1, item);

    printf("Enter the second list\n");
    printf("Enter the item of 2nd list: ");
    scanf("%d", &d);
    start2 = Sort(start2, d);

    printf("The merged list is:\n");
    start3 = merge(start1, start2);
    display(start3);

    // Free allocated memory for nodes
    // Add code to free nodes in start1, start2, start3 lists

    return 0;
}
