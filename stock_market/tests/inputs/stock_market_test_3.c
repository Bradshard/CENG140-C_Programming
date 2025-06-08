#include "../../stock_market.h"

/* Test the stock market with 3 companies and 7 people */

int main(void) {
    int i;
    StockMarket market;
    int people_count = 0;
    Company *company1, *company2, *company3;
    Person *population[MAX_PEOPLE];

    market.company_count = 0;

    population[people_count++] = create_person("Alice", 1);
    population[people_count++] = create_person("Bob", 2);
    population[people_count++] = create_person("Charlie", 3);
    population[people_count++] = create_person("Diana", 4);
    population[people_count++] = create_person("Eve", 5);
    population[people_count++] = create_person("Frank", 6);
    population[people_count++] = create_person("George", 7);

    company1 = create_company("Alpha Corp", "ALP", 1);
    company2 = create_company("Beta Inc", "BET", 2);
    company3 = create_company("Gamma Co", "GAM", 3);
    
    add_company_to_market(&market, company1);
    add_company_to_market(&market, company2);
    add_company_to_market(&market, company3);

    printf("Market created with %d companies\n", market.company_count);

    for (i = 0; i < market.company_count; i++) {
        printf("Company %d: %s with abbreviation %s and market order %d\n", i + 1, market.entries[i].company->name, market.entries[i].company->stock_abbreviation, market.entries[i].company->market_order);
    }

    insert_buy_request(&market, population, people_count, "Alice", "ALP", 1, 49.0);
    insert_sell_request(&market, population, people_count, "Bob", "ALP", 2, 50.0);
    insert_buy_request(&market, population, people_count, "Alice", "BET", 3, 49.0);
    insert_sell_request(&market, population, people_count, "Bob", "BET", 4, 50.0);
    insert_buy_request(&market, population, people_count, "Charlie", "ALP", 5, 51.0);
    insert_sell_request(&market, population, people_count, "Diana", "GAM", 6, 52.0);
    insert_buy_request(&market, population, people_count, "Eve", "ALP", 7, 53.0);
    insert_buy_request(&market, population, people_count, "Charlie", "BET", 8, 51.0);
    insert_sell_request(&market, population, people_count, "Diana", "ALP", 9, 52.0);
    insert_buy_request(&market, population, people_count, "Eve", "GAM", 10, 53.0);
    insert_sell_request(&market, population, people_count, "Frank", "GAM", 11, 54.0);
    insert_buy_request(&market, population, people_count, "George", "ALP", 12, 55.0);
    insert_buy_request(&market, population, people_count, "Alice", "GAM", 16, 59.0);
    insert_sell_request(&market, population, people_count, "Bob", "GAM", 17, 60.0);
    insert_buy_request(&market, population, people_count, "Charlie", "BET", 18, 61.0);
    insert_sell_request(&market, population, people_count, "Diana", "ALP", 19, 62.0);
    insert_buy_request(&market, population, people_count, "Eve", "GAM", 20, 63.0);
    insert_sell_request(&market, population, people_count, "Frank", "ALP", 21, 64.0);
    insert_buy_request(&market, population, people_count, "George", "BET", 22, 65.0);
    insert_buy_request(&market, population, people_count, "Alice", "BET", 26, 69.0);
    insert_sell_request(&market, population, people_count, "Bob", "BET", 27, 70.0);
    insert_buy_request(&market, population, people_count, "Charlie", "GAM", 28, 71.0);
    insert_sell_request(&market, population, people_count, "Diana", "BET", 29, 72.0);
    insert_buy_request(&market, population, people_count, "Eve", "ALP", 30, 73.0);
    insert_sell_request(&market, population, people_count, "Frank", "GAM", 31, 74.0);

    print_market(&market);

    return 0;
}
