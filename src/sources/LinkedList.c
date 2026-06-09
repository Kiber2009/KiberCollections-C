#include <stdlib.h>
#include "../include/LinkedList.h"

struct LinkedList *LinkedList_create() {
    struct LinkedList *a = malloc(sizeof(struct LinkedList));
    a->head = NULL;
    return a;
}

void LinkedList_push_back(struct LinkedList *list, void *data) {
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        return;
    }
    struct LinkedListNode *last = list->head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = node;
}

void LinkedList_push_front(struct LinkedList *list, void *data) {
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    node->data = data;
    node->next = list->head;
    list->head = node;
}

void *LinkedList_pop_back(struct LinkedList *list) {
    if (list->head == NULL) {
        return NULL;
    }
    if (list->head->next == NULL) {
        void *tmp = list->head->data;
        free(list->head);
        list->head = NULL;
        return tmp;
    }
    struct LinkedListNode *last = list->head;
    while (last->next->next != NULL) {
        last = last->next;
    }
    void *tmp = last->next->data;
    free(last->next);
    last->next = NULL;
    return tmp;
}

void *LinkedList_pop_front(struct LinkedList *list) {
    if (list->head == NULL) {
        return NULL;
    }
    void *tmp = list->head->data;
    struct LinkedListNode *node = list->head->next;
    free(list->head);
    list->head = node;
    return tmp;
}

unsigned int LinkedList_length(const struct LinkedList *list) {
    unsigned int length = 0;
    const struct LinkedListNode *node = list->head;
    while (node != NULL) {
        length++;
        node = node->next;
    }
    return length;
}

void *LinkedList_get(const struct LinkedList *list, unsigned int index) {
    for (const struct LinkedListNode *node = list->head; node != NULL; node = node->next) {
        if (index == 0) {
            return node->data;
        }
        index--;
    }
    return NULL;
}

void *LinkedList_set(const struct LinkedList *list, unsigned int index, void *data) {
    for (struct LinkedListNode *node = list->head; node != NULL; node = node->next) {
        if (index == 0) {
            void *tmp = node->data;
            node->data = data;
            return tmp;
        }
        index--;
    }
    return NULL;
}

void LinkedList_free(struct LinkedList *list, void (*dealloc)(void *)) {
    while (list->head != NULL) {
        dealloc(LinkedList_pop_front(list));
    }
    free(list);
}
