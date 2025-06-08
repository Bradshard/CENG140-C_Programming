#include <stdio.h>
#include "stock_market.h"

int main(void) {
    int i;
    StockMarket market;
    Person *population[MAX_PEOPLE];
    Company *c1;
    int people_count;

    market.company_count = 0;
    people_count = 0;

    population[people_count++] = create_person("Alice", 1);
    population[people_count++] = create_person("Bob", 2);
    population[people_count++] = create_person("Charlie", 3);
    population[people_count++] = create_person("Diana", 4);
    population[people_count++] = create_person("Eve", 5);
    population[people_count++] = create_person("Frank", 6);
    population[people_count++] = create_person("Grace", 7);
    
    for (i = 0; i < people_count; i++) {
        printf("Person %d: %s\n", i + 1, population[i]->name);
    }

    c1 = create_company("Alpha Corp", "ALP", 1);
    
    if (c1 != NULL) {
        printf("Company created: %s with abbreviation %s and market order %d\n", c1->name, c1->stock_abbreviation, c1->market_order);
    }
    
    add_company_to_market(&market, c1);
    
    printf("Market created with %d companies\n", market.company_count);

    insert_sell_request(&market, population, people_count, "Bob", "ALP", 40, 49.0);
    insert_sell_request(&market, population, people_count, "Charlie", "ALP", 30, 49.5);
    insert_sell_request(&market, population, people_count, "Diana", "ALP", 20, 50.0);

    insert_buy_request(&market, population, people_count, "Alice", "ALP", 60, 50.0);
    insert_buy_request(&market, population, people_count, "Eve", "ALP", 25, 49.0);
    insert_buy_request(&market, population, people_count, "Frank", "ALP", 15, 48.0);

    insert_sell_request(&market, population, people_count, "Grace", "ALP", 10, 48.5);

    print_market(&market);
    return 0;
}
