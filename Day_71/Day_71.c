#include <stdio.h>
#include <string.h>

#define SIZE 1000

int table[SIZE];
int occupied[SIZE]; 

int m; 


void insert(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (!occupied[index]) {
            table[index] = key;
            occupied[index] = 1;
            return;
        }
    }
}

// Search function
void search(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (!occupied[index]) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);  
    scanf("%d", &q);   

    for (int i = 0; i < m; i++) {
        occupied[i] = 0;
    }

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}