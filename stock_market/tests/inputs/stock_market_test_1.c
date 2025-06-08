#include "stock_market.h"

/* Test the stock market with 2 companies and 5 people */

int main(void) {
    int i;
    StockMarket market;
    int people_count = 0;
    Company *company1, *company2;
    Person *population[MAX_PEOPLE];
    
    market.company_count = 0;

    population[people_count++] = create_person("Alice", 1);
    population[people_count++] = create_person("Bob", 2);
    population[people_count++] = create_person("Charlie", 3);
    population[people_count++] = create_person("Diana", 4);
    population[people_count++] = create_person("Eve", 5);

    company1 = create_company("Alpha Corp", "ALP", 1);
    company2 = create_company("Beta Inc", "BET", 2);

    add_company_to_market(&market, company1);
    add_company_to_market(&market, company2);

    printf("Market created with %d companies\n", market.company_count);

    for (i = 0; i < market.company_count; i++) {
        printf("Company %d: %s with abbreviation %s and market order %d\n", i + 1, market.entries[i].company->name, market.entries[i].company->stock_abbreviation, market.entries[i].company->market_order);
    }

    insert_sell_request(&market, population, people_count, "Bob", "ALP", 40, 49.0);
    insert_sell_request(&market, population, people_count, "Charlie", "ALP", 30, 49.5);
    insert_buy_request(&market, population, people_count, "Alice", "ALP", 60, 50.0);
    insert_sell_request(&market, population, people_count, "Eve", "BET", 20, 48.0);
    insert_buy_request(&market, population, people_count, "Diana", "BET", 25, 49.0);

    print_market(&market);

    return 0;
}
