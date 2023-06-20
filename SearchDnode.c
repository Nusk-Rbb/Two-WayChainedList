#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} NODE;

NODE *search(int SearchData, NODE *ptr) {
    while(ptr != NULL) {
        if(ptr->data == SearchData) {
            break;
        }
        ptr = ptr->right;
    }
    return ptr;
}

int InsertData(int SearchData, int NewData, NODE *ptr) {
    NODE *nptr;
    ptr = search(SearchData, ptr);
    if(ptr == NULL){ return -1; }
    nptr = (NODE *)malloc(sizeof(NODE));
    nptr->data = NewData;
    nptr->right = ptr;
    (ptr->left)->right = nptr;
    nptr->left = ptr->left;
    ptr->left = nptr;
    return 0;
}

void push_back_list(NODE *list, int value)
{
  NODE *node;
  NODE *p = list;
 
  if ((node = (NODE *) malloc(sizeof(NODE))) == NULL) {
    fprintf(stderr, "Error cannot allocate memory %zu\n", sizeof(NODE));
    exit(1);
  }
 
  while (p->right) {
    p = p->right;
  }
 
  p->right = node;
 
  node->left = p;
  node->data = value;
  node->right = NULL;
}

void init_list(NODE *list)
{
  list->right = list->left = NULL;
  list->data = 0;
}

void print_list(NODE *list)
{
  NODE *p = list->right;
  printf("print_list(): ");
 
  while (p) {
    printf("value(%d)->", p->data);
    p = p->right;
  }
 
  printf("NULL\n");
}

void main(void) {
    int data[3] = {45, 15, 64};
    NODE Data;
    NODE Insert;
    Insert.data = 23;

    init_list(&Data);
    for(int i = 0; i < 3; i++) {
        push_back_list(&Data, data[i]);
    }
    print_list(&Data);

    InsertData(15, 23, &Data);
    print_list(&Data);
    return;
}