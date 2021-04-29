#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int d;
    struct Stack *next;
} stack;

void stackPush(stack **st, int d) {
    stack *tmp = (stack *) malloc(sizeof(stack));
    tmp->d = d;
    tmp->next = *st;
    *st = tmp;
}

void stackPop(stack **st) {
    if (!(*st)) {
        return;
    }
    stack *tmp = *st;
    *st = (*st)->next;
    free(tmp);
}

void stackShow(stack *st) {
    if (!st) {
        printf("empty\n");
        return;
    }
    stack *tmp = st;
    while (tmp) {
        printf("%d ", tmp->d);
        tmp = tmp->next;
    }
    printf("\n");
}

void stackDelete(stack *st) {
    while (st) {
        stack *tmp = st;
        st = st->next;
        free(tmp);
    }
}

typedef struct Queue {
    int i;
    char ch;
    int data;
    struct Queue *next;
    struct Queue *tail;
} queue;

void queuePush(queue **q, int data, int i) {
    queue *tmp = (queue *) malloc(sizeof(queue));
    if (!tmp) {
        printf("lack of memory");
        exit(-1);
    }
    if (data == 0) {
        tmp->ch = 'D';
    } else {
        tmp->ch = 'A';
    }
    tmp->data = data;
    tmp->i = i;
    if (*q == NULL) {
        *q = tmp;
        (*q)->tail = tmp;
    } else {
        (*q)->tail->next = tmp;
        (*q)->tail = tmp;
    }
}

void queueDelete(queue *q) {
    while (q) {
        queue *tmp = q;
        q = q->next;
        free(tmp);
    }
}

void queueShow(queue *q) {
    printf("QUEUE:\n");
    queue *tmp = q;
    while (tmp) {
        printf("%c %d ", tmp->ch, tmp->i);
        if (tmp->ch == 'A') {
            printf("%d", tmp->data);
        }
        tmp = tmp->next;
        printf("\n");
    }
}

void queueClear(queue **q, stack **array) {
    while ((*q) != NULL) {
        queue *tmp = *q;
        *q = (*q)->next;
        if (tmp->ch == 'A') {
            stackPush(&array[tmp->i - 1], tmp->data);
        } else {
            stackPop(&array[tmp->i - 1]);
        }
        free(tmp);
    }
}

int main() {
    printf("Input number of stacks\n");
    int n;
    scanf("%d", &n);
    stack *array[n];
    int j = 0;
    for (; j < n; j++) {
        array[j] = NULL;
    }
    queue *q = NULL;
    while (1) {
        printf("Enter 'A' to add or 'D' to delete or 'C' to clear the queue or 'E' to exit:\n");
        char option;
        scanf("%c", &option);
        scanf("%c", &option);
        switch (option) {
            case 'E':
                for (j = 0; j < n; j++) {
                    stackDelete(array[j]);
                }
                queueDelete(q);
                return 0;
            case 'D': {
                int i;
                scanf("%d", &i);
                if (i > n || i < 1) {
                    printf("Invalid input\n");
                    break;
                }
                queuePush(&q, 0, i);
                break;
            }
            case 'A': {
                int i, data;
                scanf("%d%d", &i, &data);
                if (i > n || i < 1) {
                    printf("Invalid input\n");
                    break;
                }
                queuePush(&q, data, i);
                break;
            }
            case 'C':
                queueClear(&q, array);
                break;
            default:
                printf("Invalid input\n");
        }
        printf("STACKS:\n");
        for (j = 0; j < n; j++) {
            printf("%d: ", j + 1);
            stackShow(array[j]);
        }
        queueShow(q);
    }
}
