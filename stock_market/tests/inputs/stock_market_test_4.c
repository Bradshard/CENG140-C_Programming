#include "stock_market.h"

/* Test the stock market with 5 companies and 15 people */

int main(void) {
    int i;
    StockMarket market;
    int people_count = 0;
    Company *company1, *company2, *company3, *company4, *company5;
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
    population[people_count++] = create_person("Kathy", 11);
    population[people_count++] = create_person("Liam", 12);
    population[people_count++] = create_person("Mia", 13);
    population[people_count++] = create_person("Noah", 14);
    population[people_count++] = create_person("Olivia", 15);

    company1 = create_company("Alpha Corp", "ALP", 1);
    company2 = create_company("Beta Inc", "BET", 2);
    company3 = create_company("Gamma Co", "GAM", 3);
    company4 = create_company("Delta Ltd", "DEL", 4);
    company5 = create_company("Epsilon LLC", "EPS", 5);
    
    add_company_to_market(&market, company1);
    add_company_to_market(&market, company2);
    add_company_to_market(&market, company3);
    add_company_to_market(&market, company4);
    add_company_to_market(&market, company5);

    printf("Market created with %d companies\n", market.company_count);

    for (i = 0; i < market.company_count; i++) {
        printf("Company %d: %s with abbreviation %s and market order %d\n", i + 1, market.entries[i].company->name, market.entries[i].company->stock_abbreviation, market.entries[i].company->market_order);
    }

    insert_buy_request(&market, population, people_count, "Alice", "ALP", 50, 49.0);
    insert_sell_request(&market, population, people_count, "Bob", "ALP", 49, 50.0);
    insert_buy_request(&market, population, people_count, "Charlie", "BET", 48, 49.0);
    insert_sell_request(&market, population, people_count, "Diana", "BET", 47, 50.0);
    insert_buy_request(&market, population, people_count, "Eve", "GAM", 46, 49.0);
    insert_sell_request(&market, population, people_count, "Frank", "GAM", 45, 50.0);
    insert_buy_request(&market, population, people_count, "George", "DEL", 44, 49.0);
    insert_sell_request(&market, population, people_count, "Hannah", "DEL", 43, 50.0);
    insert_buy_request(&market, population, people_count, "Ivy", "EPS", 42, 49.0);
    insert_sell_request(&market, population, people_count, "Jack", "EPS", 41, 50.0);
    insert_buy_request(&market, population, people_count, "Kathy", "ALP", 40, 49.0);
    insert_sell_request(&market, population, people_count, "Liam", "ALP", 39, 50.0);
    insert_buy_request(&market, population, people_count, "Mia", "BET", 38, 49.0);
    insert_sell_request(&market, population, people_count, "Noah", "BET", 37, 50.0);
    insert_buy_request(&market, population, people_count, "Olivia", "GAM", 36, 49.0);
    insert_sell_request(&market, population, people_count, "Alice", "GAM", 35, 50.0);
    insert_buy_request(&market, population, people_count, "Bob", "DEL", 34, 49.0);
    insert_sell_request(&market, population, people_count, "Charlie", "DEL", 33, 50.0);
    insert_buy_request(&market, population, people_count, "Diana", "EPS", 32, 49.0);
    insert_sell_request(&market, population, people_count, "Eve", "EPS", 31, 50.0);
    insert_buy_request(&market, population, people_count, "Frank", "ALP", 30, 49.0);
    insert_sell_request(&market, population, people_count, "George", "ALP", 29, 50.0);
    insert_buy_request(&market, population, people_count, "Hannah", "BET", 28, 49.0);
    insert_sell_request(&market, population, people_count, "Ivy", "BET", 27, 50.0);
    insert_buy_request(&market, population, people_count, "Jack", "GAM", 26, 49.0);
    insert_sell_request(&market, population, people_count, "Kathy", "GAM", 25, 50.0);
    insert_buy_request(&market, population, people_count, "Liam", "DEL", 24, 49.0);
    insert_sell_request(&market, population, people_count, "Mia", "DEL", 23, 50.0);
    insert_buy_request(&market, population, people_count, "Noah", "EPS", 22, 49.0);
    insert_sell_request(&market, population, people_count, "Olivia", "EPS", 21, 50.0);
    insert_buy_request(&market, population, people_count, "Alice", "ALP", 20, 49.0);
    insert_sell_request(&market, population, people_count, "Bob", "ALP", 19, 50.0);
    insert_buy_request(&market, population, people_count, "Charlie", "BET", 18, 49.0);
    insert_sell_request(&market, population, people_count, "Diana", "BET", 17, 50.0);
    insert_buy_request(&market, population, people_count, "Eve", "GAM", 16, 49.0);
    insert_sell_request(&market, population, people_count, "Frank", "GAM", 15, 50.0);
    insert_buy_request(&market, population, people_count, "George", "DEL", 14, 49.0);
    insert_sell_request(&market, population, people_count, "Hannah", "DEL", 13, 50.0);
    insert_buy_request(&market, population, people_count, "Ivy", "EPS", 12, 49.0);
    insert_sell_request(&market, population, people_count, "Jack", "EPS", 11, 50.0);
    insert_buy_request(&market, population, people_count, "Kathy", "ALP", 10, 49.0);
    insert_sell_request(&market, population, people_count, "Liam", "ALP", 9, 50.0);
    insert_buy_request(&market, population, people_count, "Mia", "BET", 8, 49.0);
    insert_sell_request(&market, population, people_count, "Noah", "BET", 7, 50.0);
    insert_buy_request(&market, population, people_count, "Olivia", "GAM", 6, 49.0);
    insert_sell_request(&market, population, people_count, "Alice", "GAM", 5, 50.0);
    insert_buy_request(&market, population, people_count, "Bob", "DEL", 4, 49.0);
    insert_sell_request(&market, population, people_count, "Charlie", "DEL", 3, 50.0);
    insert_buy_request(&market, population, people_count, "Diana", "EPS", 2, 49.0);
    insert_sell_request(&market, population, people_count, "Eve", "EPS", 1, 50.0);
    
    print_market(&market);

    return 0;
}
