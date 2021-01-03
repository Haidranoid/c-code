#include <stdio.h>
#include <stdlib.h>

struct item {
    char *name;
    int quantity;
    float price;
    float amount;
};

void read_item(struct item *const item) {
    printf("Introduce the name, price and quantity of the item: ");
    scanf("%s%f%i", item->name, &item->price, &item->quantity);
    item->amount = (float) (item->quantity * item->price);
}

void print_item(const struct item *const item) {
    printf("Name: %s, Price: %.2f, Quantity: %i, Amount: %.2f", item->name, item->price, item->quantity, item->amount);
}

int challenge_structs(int argc, char *argv[]) {
    struct item *new_item = (struct item *) malloc(sizeof(struct item));
    if (!new_item)
        exit(-1);

    new_item->name = (char *) malloc(50 * sizeof(char));
    if (!new_item->name)
        exit(-1);

    read_item(new_item);
    print_item(new_item);

    free(new_item->name);
    new_item->name = NULL;
    free(new_item);
    new_item = NULL;

    return 0;
}

struct employee {
    char name[50];
    int hireDate;
    float salary;
};

void challenge_structs_1() {
    struct employee eduardo = {"Eduardo", 2010, 11000.00f};
    printf("Name: %s, hireDate:%i, salary:%.2f\n", eduardo.name, eduardo.hireDate, eduardo.salary);

    printf("Introduce the name, hire date and the salary of the new employee: ");
    struct employee new_employee;
    scanf("%s%i%f", new_employee.name, &new_employee.hireDate, &new_employee.salary);

    printf("Name: %s, hireDate:%i, salary:%.2f\n", new_employee.name, new_employee.hireDate, new_employee.salary);
}
