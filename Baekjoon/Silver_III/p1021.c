#include <stdio.h>
#include <stdlib.h>

struct listNode {
  int data;
  struct listNode *prev;
  struct listNode *next;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *rPtr, int value);
int deleteAndShift(ListNodePtr *rPtr, int value);
int getSize(ListNodePtr rPtr);
int findMinPath(ListNodePtr *rPtr, int value);
void printList(ListNodePtr rPtr);

void insert(ListNodePtr *rPtr, int value) {
  ListNodePtr newPtr = malloc(sizeof(ListNode));

  if (!newPtr) {
    printf("malloc failed, inserting %d\n", value);
    return;
  }

  newPtr->data = value;
  newPtr->prev = NULL;
  newPtr->next = NULL;

  if (!*rPtr) {
    // replace the root node
    newPtr->next = newPtr;
    *rPtr = newPtr;
  } else {
    // insert the node in existing sequence
    ListNodePtr prevPtr = NULL;
    ListNodePtr currPtr = *rPtr;

    while (currPtr->next != *rPtr) {
      prevPtr = currPtr;
      currPtr = currPtr->next;
    }

    newPtr->prev = currPtr; // the end of linkage
    newPtr->next = *rPtr;   // circular linkage
    (*rPtr)->prev = newPtr;
    currPtr->next = newPtr;
  }
}

int deleteAndShift(ListNodePtr *rPtr, int value) {
  ListNodePtr prevPtr = NULL;
  ListNodePtr currPtr = *rPtr;

  if ((*rPtr)->data == value) {
    // delete the root node

    // the root is the only remaining element
    if ((*rPtr)->next == *rPtr) {
      return 0;
    }

    ListNodePtr tempPtr = *rPtr;
    ListNodePtr prevPtr = (*rPtr)->prev;
    *rPtr = (*rPtr)->next;
    prevPtr->next = *rPtr;
    (*rPtr)->prev = prevPtr;
    free(tempPtr);
    return 0;
  } else {
    int cnt = 0;
    while (currPtr && currPtr->data != value) {
      prevPtr = currPtr;
      currPtr = currPtr->next;
      cnt++;
    }

    if (currPtr) {
      ListNodePtr tempPtr = currPtr;
      currPtr->next->prev = prevPtr;
      prevPtr->next = currPtr->next;
      *rPtr = currPtr->next;
      free(tempPtr);
    }
    return cnt;
  }
}

int getSize(ListNodePtr rPtr) {
  if (!rPtr) {
    return 0;
  } else {
    ListNodePtr currPtr = rPtr;
    int cnt = 0;
    do {
      cnt++;
      currPtr = currPtr->next;
    } while (currPtr != rPtr);
    return cnt;
  }
}

int findMinPath(ListNodePtr *rPtr, int value) {
  ListNodePtr currPtr = *rPtr;
  int straight = deleteAndShift(rPtr, value);
  int reverse = getSize(*rPtr) - straight + 1;
  return straight > reverse ? reverse : straight;
}

void printList(ListNodePtr rPtr) {
  if (!rPtr) {
    puts("List is empty");
  } else {
    ListNodePtr currPtr = rPtr;
    do {
      printf("%d ", currPtr->data);
      currPtr = currPtr->next;
    } while (currPtr != rPtr);
    puts("");
  }
}

int main(void) {
  int sizeOfQueue, sizeOfTarget;
  scanf("%d %d", &sizeOfQueue, &sizeOfTarget);

  int targetList[sizeOfTarget];
  for (int i = 0; i < sizeOfTarget; i++) {
    scanf("%d", &targetList[i]);
  }

  ListNodePtr rootPtr = NULL;

  for (int i = 1; i <= sizeOfQueue; i++) {
    insert(&rootPtr, i);
  }

  int sum = 0;
  for (int i = 0; i < sizeOfTarget; i++) {
    sum += findMinPath(&rootPtr, targetList[i]);
  }

  printf("%d\n", sum);

  return 0;
}