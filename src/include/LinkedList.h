#pragma once
#ifndef KiberCollections_LinkedList_H
#define KiberCollections_LinkedList_H

struct LinkedListNode {
    void *data;
    struct LinkedListNode *next;
};

typedef struct LinkedList {
    struct LinkedListNode *head;
} LinkedList;

LinkedList LinkedList_create();

void LinkedList_push_back(LinkedList *list, void *data);

void LinkedList_push_front(LinkedList *list, void *data);

void *LinkedList_pop_back(LinkedList *list);

void *LinkedList_pop_front(LinkedList *list);

unsigned int LinkedList_length(const LinkedList *list);

void *LinkedList_get(const LinkedList *list, unsigned int index);

void *LinkedList_set(const LinkedList *list, unsigned int index, void *data);

void LinkedList_free(LinkedList *list, void (*dealloc)(void *));

#endif
