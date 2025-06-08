#include "stock_market.h"

/* Create a population of 10 people */

int main(void) {
    int i;
    Person *population[MAX_PEOPLE];
    int people_count = 0;

    population[people_count++] = create_person("Alice", 1);
    population[people_count++] = create_person("Bob", 2);
    population[people_count++] = create_person("Charlie", 3);
    population[people_count++] = create_person("Diana", 4);
    population[people_count++] = create_person("Eve", 5);
    population[people_count++] = create_person("Frank", 6);
    population[people_count++] = create_person("George", 7);
    population[people_count++] = create_person("Hannah", 8);
    population[people_count++] = create_person("Ivy", 9);
    population[people_count++] = create_person("Jack", 10);

    printf("Population created with %d people\n", people_count);

    for (i = 0; i < people_count; i++) {
        printf("Person %d: %s\n", i + 1, population[i]->name);
    }

    return 0;
}
