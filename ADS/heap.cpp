#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100

// Function to swap two elements
// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// Function to heapify up (maintain max heap property)
void heapifyUp(int *heap, int index) {
    int parentIndex = (index - 1) / 2;

    // If the current element is greater than its parent, swap them
    if (index > 0 && heap[index] > heap[parentIndex]) {
        //swap(&heap[index], &heap[parentIndex]);
        swap(heap[index], heap[parentIndex]);
        heapifyUp(heap, parentIndex); // Recursively heapify the parent
    }
}

// Function to heapify down (maintain max heap property)
void heapifyDown(int *heap, int size, int index) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    // Check if the left child exists and is greater than the current element
    if (leftChild < size && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    // Check if the right child exists and is greater than the current element
    if (rightChild < size && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    // If the largest is not the current element, swap and heapify down
    if (largest != index) {
        // swap(&heap[index], &heap[largest]);
        swap(heap[index], heap[largest]);
        heapifyDown(heap, size, largest);
    }
}

// Function to insert an element into the max heap
void insert(int *heap, int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }

    heap[(*size)++] = value; // Step 1: Add the element at the end
    heapifyUp(heap, *size - 1); // Step 2: Heapify up to maintain max heap property
}

// Function to delete the root element (maximum element) from the max heap
int deleteRoot(int *heap, int *size) {
    if (*size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[*size - 1]; // Replace root with the last element
    (*size)--;
    heapifyDown(heap, *size, 0); // Heapify down from the root
    return root;
}

// Function to print the heap
void printHeap(int *heap, int size) {
    for (int i = 0; i < size; i++) {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int heap[MAX_SIZE];
    int size = 0;

    insert(heap, &size, 10);
    insert(heap, &size, 20);
    insert(heap, &size, 5);
    insert(heap, &size, 30);
    insert(heap, &size, 15);

    cout<<"Heap after insertions: ";
    printHeap(heap, size); // Output will be a max heap

    int deleted = deleteRoot(heap, &size);
    cout<<"Deleted root element:" <<deleted<<endl;

    cout<<"Heap after deletion: ";
    printHeap(heap, size);

    return 0;
}