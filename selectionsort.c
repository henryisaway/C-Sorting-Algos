#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INPUT 1

typedef struct Node{
    int key;
    struct Node* next;
} Node;

Node* createNode(int key){
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    
    return node;
}

Node* listInsert(Node* list, int key){
    Node* node = createNode(key);

    // If list is empty just return new node
    if(list == NULL){
        return node;
    }
    
    // If list is not empty
    Node* temp = list;
    // Go to last node
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;  // Attach node to the end of the list
    
    return list;
}

void listPrint(Node* list){
    Node* temp = list;
    while(temp != NULL){
        printf("%d\n", temp->key);
        temp = temp->next;
    }
}

Node* listGenRandom(int size, int max){
    Node* list = NULL;
    
    srand(time(NULL));
    
    for(int i = 0; i < size; i++){
        int key = rand() % max + 1;
        list = listInsert(list, key);
    }
    
    return list;
}

Node* listSelectionSort(Node* list){
    Node* temp = list;
    Node* temp2 = temp->next;
    Node* min = temp;
    int current = temp->key;
    
    // If list length is 1, it is already ordered.
    if(temp2 == NULL){
        return list;
    }
    
    
    while(temp != NULL){
        min = temp;
        temp2 = temp->next;
        
        while(temp2 != NULL){
            if(temp2->key < min->key){
                min = temp2;
            }
            temp2 = temp2->next;
        }
        
        if(min != temp){
            current = temp->key;
            temp->key = min->key;
            min->key = current;
        }
        
        temp = temp->next;
    }
    
    return list;
}

void listTest(Node* list){
    Node* temp = list;
    while(temp->next != NULL){
        if(temp->next->key < temp->key){
            printf("Test failed!\n");
            return;
        }
        temp = temp->next;
    }
    
    printf("Test passed!\n");
}

int main() {
    Node* list = NULL;
    if(INPUT){
        int size, max;
        printf("list size: ");
        scanf("%d", &size);
        printf("Max value: ");
        scanf("%d", &max);
        printf("--------------------------\n");
        list = listGenRandom(size, max);
    } else{
        list = listGenRandom(10, 1000);
    }
    
    printf("Initial list:\n");
    listPrint(list);
    printf("---------------\n");
    list = listSelectionSort(list);

    printf("---------------\nFinal list:\n");
    listPrint(list);
    listTest(list);
    return 0;
}
