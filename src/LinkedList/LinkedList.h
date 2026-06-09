#pragma once
#ifndef KiberCollections_LinkedList_H
#define KiberCollections_LinkedList_H

struct LinkedListNode {
    void *data;
    struct LinkedListNode *next;
};

struct LinkedList {
    struct LinkedListNode *head;
};

struct LinkedList *LinkedList_create();

void LinkedList_push_back(struct LinkedList *list, void *data);

void LinkedList_push_front(struct LinkedList *list, void *data);

void *LinkedList_pop_back(struct LinkedList *list);

void *LinkedList_pop_front(struct LinkedList *list);

unsigned int LinkedList_length(const struct LinkedList *list);

void *LinkedList_get(const struct LinkedList *list, unsigned int index);

void *LinkedList_set(const struct LinkedList *list, unsigned int index, void *data);

void LinkedList_free(struct LinkedList *list, void (*dealloc)(void *));

#endif
