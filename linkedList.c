#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для книги
typedef struct {
    char title[80];
    double price;
    int pages;
    char language[10];
    double weight;
    int year;
} Book;

// Вузол списку
typedef struct Node {
    Book book;
    struct Node* next;
} Node;

// Створення нового вузла зі структурою Book
Node* create_node(Book book) {
    Node* node = malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    node->book = book;     // копіюємо всю структуру одразу
    node->next = NULL;
    return node;
}

// Додає вузол у кінець списку
void append_node(Node** head, Book book) {
    Node* new_node = create_node(book);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Друк усього списку
void print_list(Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        Book b = temp->book;
        printf("Title: %s\n", b.title);
        printf("Price: %.2f UAH\n", b.price);
        printf("Pages: %d\n", b.pages);
        printf("Language: %s\n", b.language);
        printf("Weight: %.2f g\n", b.weight);
        printf("Year: %d\n", b.year);
        printf("----------------------\n");
        temp = temp->next;
    }
}

// Звільнення пам'яті
void free_list(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void) {
    Node* head = NULL;

    // Створюємо книги як окремі структури
    Book b1 = {"Philosopher's Stone", 500.0, 223, "English", 553, 1997};
    Book b2 = {"Chamber of Secrets", 520.0, 251, "English", 622, 1998};
    Book b3 = {"Prisoner of Azkaban", 1200.0, 317, "English", 786, 1999};
    Book b4 = {"Goblet of Fire", 420.0, 636, "English", 1576, 2000};
    Book b5 = {"Order of the Phoenix", 450.0, 766, "English", 1898, 2003};
    Book b6 = {"Half-Blood Prince", 420.0, 607, "English", 1506, 2005};
    Book b7 = {"Deathly Hallows", 420.0, 607, "English", 1506, 2007};

    append_node(&head, b1);
    append_node(&head, b2);
    append_node(&head, b3);
    append_node(&head, b4);
    append_node(&head, b5);
    append_node(&head, b6);
    append_node(&head, b7);

    print_list(head);

    free_list(head);
    return 0;
}
