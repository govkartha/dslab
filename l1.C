#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * rlink;
    struct Node * llink;
}typedef NODE;

NODE* new_list(){
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->data = 0;
    node->llink = NULL;
    node->rlink=NULL;
    return node;
}

NODE* new_node(){
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->data = 0;
    node->llink = NULL;
    node->rlink=NULL;
    return node;
}

void insert_beg(NODE* header,int data){
    NODE* ptr=header->rlink;
    NODE* temp = new_node();
    if(temp != NULL && ptr != NULL){
        temp->data = data;
        temp->rlink = ptr;
        temp->llink=header;
        header->rlink = temp;
        ptr->llink=temp;
    }
}

void insert_end(NODE* header,int data){
    NODE* ptr = header;
    NODE* temp = new_node();
    if(temp != NULL && ptr != NULL){
        while (ptr->rlink != NULL){
            ptr = ptr->rlink;
        }
        temp->data = data;
        ptr->rlink = temp;
        temp->llink=ptr;
        
    }
}

// void insert_any(NODE* header, int data,int key){
//     NODE* ptr = header->link;
//     NODE* temp = new_node();
//     if (temp != NULL && ptr != NULL){
//         while(ptr != NULL && ptr->data != key){
//             ptr = ptr->link;
//         }
//         if(ptr != NULL && ptr->data == key){
//         //if(ptr->data == key){
//             temp->link = ptr->link;
//             ptr->link = temp;
//             temp->data = data;
//         }
        
//     }
     
// }

// void delete_beg(NODE* header){
//     NODE* ptr = header->link;
//     if (ptr != NULL){
//         header->link = ptr->link;
//         free(ptr);
//     }
// }

// void delete_end(NODE* header){
//     NODE* ptr = header->link;
//     NODE* ptr1;
//     if (ptr != NULL){
//         while (ptr->link != NULL){
//             ptr1 = ptr;
//             ptr = ptr->link;
//         }
//         ptr1->link = NULL;
//         free(ptr);
//     }
// }

// void delete_any(NODE* header,int key){
//     NODE* ptr = header->link;
//     NODE* ptr1 = header;
//     while (ptr != NULL && ptr->data != key){
//         ptr1 = ptr;
//         ptr = ptr->link;
//     }
//     if (ptr != NULL && ptr->data == key){
//         ptr1->link = ptr->link;
//         free(ptr);
//     }
// }

void display(NODE* header){
    NODE* ptr = header->rlink;
    while (ptr != NULL){
        printf("%d-> ",ptr->data);
        ptr = ptr->rlink;
    }
}



int main(){
    NODE* header = new_list();
    int data,n,key,k;
    insert_end(header,5);
    display(header);
    //insert_end(header,6);
    //display(header);
    //insert_any(header,2,1);
    //display(header);
    //insert_any(header,4,3);
    //delete_beg(header);
    //display(header);
    //delete_end(header);
    //display(header);
    //delete_any(header,2);
    display(header);
    return 0;
}