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

Node* vectorInsert(Node* vector, int key){
    Node* node = createNode(key);

    // If vector is empty just return new node
    if(vector == NULL){
        return node;
    }
    
    // If vector is not empty
    Node* temp = vector;
    // Go to last node
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;  // Attach node to the end of the vector
    
    return vector;
}

void vectorPrint(Node* vector){
    Node* temp = vector;
    while(temp != NULL){
        printf("%d\n", temp->key);
        temp = temp->next;
    }
}

Node* vectorGenRandom(int size, int max){
    Node* vector;
    
    srand(time(NULL));
    
    for(int i = 0; i < size; i++){
        int key = rand() % max + 1;
        vector = vectorInsert(vector, key);
    }
    
    return vector;
}

Node* vectorSelectionSort(Node* vector){
    Node* temp = vector;
    Node* temp2 = temp->next;
    Node* min = temp;
    int current = temp->key;
    
    // If vector length is 1, it is already ordered.
    if(temp2 == NULL){
        return vector;
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
    
    return vector;
}

void vectorTest(Node* vector){
    Node* temp = vector;
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
    Node* vector;
    if(INPUT){
        int size, max;
        printf("Vector size: ");
        scanf("%d", &size);
        printf("Max value: ");
        scanf("%d", &max);
        printf("--------------------------\n");
        vector = vectorGenRandom(size, max);
    } else{
        vector = vectorGenRandom(10, 1000);
    }
    
    printf("Initial vector:\n");
    vectorPrint(vector);
    printf("---------------\n");
    vector = vectorSelectionSort(vector);

    printf("---------------\nFinal vector:\n");
    vectorPrint(vector);
    vectorTest(vector);
    return 0;
}
