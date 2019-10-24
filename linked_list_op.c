#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * link;
}typedef NODE;

NODE* new_list(){
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->data = 0;
    node->link = NULL;
    return node;
}

NODE* new_node(){
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->data = 0;
    node->link = NULL;
    return node;
}

void insert_beg(NODE* header,int data){
    NODE* ptr=header;
    NODE* temp = new_node();
    if(temp != NULL && ptr != NULL){
        temp->data = data;
        temp->link = ptr->link;
        ptr->link = temp;
    }
}

void insert_end(NODE* header,int data){
    NODE* ptr = header;
    NODE* temp = new_node();
    if(temp != NULL && ptr != NULL){
        while (ptr->link != NULL){
            ptr = ptr->link;
        }
        temp->data = data;
        ptr->link = temp;
        
    }
}

void insert_any(NODE* header, int data,int key){
    NODE* ptr = header->link;
    NODE* temp = new_node();
    if (temp != NULL && ptr != NULL){
        while(ptr != NULL && ptr->data != key){
            ptr = ptr->link;
        }
        if(ptr != NULL && ptr->data == key){
        //if(ptr->data == key){
            temp->link = ptr->link;
            ptr->link = temp;
            temp->data = data;
        }
        
    }
     
}

void delete_beg(NODE* header){
    NODE* ptr = header->link;
    if (ptr != NULL){
        header->link = ptr->link;
        free(ptr);
    }
}

void delete_end(NODE* header){
    NODE* ptr = header->link;
    NODE* ptr1;
    if (ptr != NULL){
        while (ptr->link != NULL){
            ptr1 = ptr;
            ptr = ptr->link;
        }
        ptr1->link = NULL;
        free(ptr);
    }
}

void delete_any(NODE* header,int key){
    NODE* ptr = header->link;
    NODE* ptr1 = header;
    while (ptr != NULL && ptr->data != key){
        ptr1 = ptr;
        ptr = ptr->link;
    }
    if (ptr != NULL && ptr->data == key){
        ptr1->link = ptr->link;
        free(ptr);
    }
}

void display(NODE* header){
    NODE* ptr = header->link;
    while (ptr != NULL){
        printf("%d-> ",ptr->data);
        ptr = ptr->link;
    }
}

void main(){
    NODE* header = new_list();
    int data,n,key,k;
    //insert_beg(header,1);
    //display(header);
    //insert_end(header,3);
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
}