#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct InfoList {
    char name[20];
    char address[20];
    char activity[20];
    struct InfoList *next;
} infoList;

void addInfo(infoList **list) {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        printf("no file\n");
        exit(-1);
    }
    while (!feof(fp)) {
        infoList *tmp = (infoList *) malloc(sizeof(infoList));
        fscanf(fp, "%s %s %s", tmp->name, tmp->address, tmp->activity);
        if (*list) {
            tmp->next = *list;
        } else {
            tmp->next = NULL;
        }
        *list = tmp;
    }
    fclose(fp);
}

void viewInfo(infoList *list) {
    infoList *tmp = list;
    while (tmp) {
        printf("%s %s %s\n", tmp->name, tmp->address, tmp->activity);
        tmp = tmp->next;
    }
}

void deleteInfo(infoList *list) {
    while (list) {
        infoList *tmp = list;
        list = list->next;
        free(tmp);
    }
}

void addToMyList(infoList *info, infoList **list, char city[20], char add[20]) {
    infoList *tmp = info;
    while (tmp && strcmp(city, tmp->name) != 0 && strcmp(add, tmp->address) != 0) {
        tmp = tmp->next;
    }
    if (tmp) {
        infoList *t = (infoList *) malloc(sizeof(infoList));
        strcpy(t->name, tmp->name);
        strcpy(t->address, tmp->address);
        strcpy(t->activity, tmp->activity);
        if (*list) {
            t->next = *list;
        } else {
            t->next = NULL;
        }
        *list = t;
    } else {
        printf("there is no such city or address\n");
    }
}

int main() {
    infoList *info = NULL;
    infoList *myList = NULL;
    addInfo(&info);
    while (1) {
        printf("1 - view\n2 - choose a city and an address\n3 - view list of visited places\nother - exit\n");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                viewInfo(info);
                break;
            case 2:
                printf("input a city and an address\n");
                char city[20], add[20];
                scanf("%s %s", city, add);
                addToMyList(info, &myList, city, add);
                break;
            case 3:
                viewInfo(myList);
                break;
            default: {
                deleteInfo(info);
                deleteInfo(myList);
                return 0;
            }
        }
    }
}
