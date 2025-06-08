#include "stock_market.h"

/* Test the stock market with 4 companies and 10 people */

int main(void) {
    int i;
    StockMarket market;
    int people_count = 0;
    Company *company1, *company2, *company3, *company4;
    Person *population[MAX_PEOPLE];
    
    market.company_count = 0;

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

    company1 = create_company("Alpha Corp", "ALP", 1);
    company2 = create_company("Beta Inc", "BET", 2);
    company3 = create_company("Gamma Co", "GAM", 3);
    company4 = create_company("Delta Inc", "DEL", 4);
    
    add_company_to_market(&market, company1);
    add_company_to_market(&market, company2);
    add_company_to_market(&market, company3);
    add_company_to_market(&market, company4);

    printf("Market created with %d companies\n", market.company_count);

    for (i = 0; i < market.company_count; i++) {
        printf("Company %d: %s with abbreviation %s and market order %d\n", i + 1, market.entries[i].company->name, market.entries[i].company->stock_abbreviation, market.entries[i].company->market_order);
    }

    insert_sell_request(&market, population, people_count, "Bob", "ALP", 40, 49.0);
    insert_sell_request(&market, population, people_count, "Charlie", "ALP", 30, 49.5);
    insert_buy_request(&market, population, people_count, "Alice", "ALP", 60, 50.0);
    insert_sell_request(&market, population, people_count, "Eve", "BET", 20, 48.0);
    insert_buy_request(&market, population, people_count, "Diana", "BET", 25, 49.0);
    insert_sell_request(&market, population, people_count, "Frank", "GAM", 10, 47.0);
    insert_buy_request(&market, population, people_count, "George", "GAM", 15, 47.5);
    insert_sell_request(&market, population, people_count, "Hannah", "DEL", 5, 46.0);
    insert_buy_request(&market, population, people_count, "Ivy", "DEL", 8, 46.5);
    insert_sell_request(&market, population, people_count, "Jack", "DEL", 12, 46.0);
    insert_buy_request(&market, population, people_count, "Alice", "DEL", 18, 45.5);
    insert_sell_request(&market, population, people_count, "Bob", "GAM", 20, 44.0);
    insert_buy_request(&market, population, people_count, "Charlie", "GAM", 25, 44.5);
    insert_sell_request(&market, population, people_count, "Eve", "DEL", 15, 43.0);
    insert_buy_request(&market, population, people_count, "Diana", "DEL", 20, 43.5);
    insert_sell_request(&market, population, people_count, "Frank", "ALP", 10, 42.0);
    insert_buy_request(&market, population, people_count, "George", "ALP", 15, 42.5);
    insert_sell_request(&market, population, people_count, "Hannah", "BET", 5, 41.0);
    insert_buy_request(&market, population, people_count, "Ivy", "BET", 8, 41.5);
    insert_sell_request(&market, population, people_count, "Jack", "BET", 12, 41.0);
    insert_buy_request(&market, population, people_count, "Alice", "BET", 18, 40.5);
    

    print_market(&market);

    return 0;
}
