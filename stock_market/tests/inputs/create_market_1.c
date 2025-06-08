#include "stock_market.h"

/* Create a market with 2 companies */

int main(void) {
    int i;
    StockMarket market;
    Company *company1, *company2;

    market.company_count = 0;

    company1 = create_company("Alpha Corp", "ALP", 1);
    company2 = create_company("Beta Inc", "BET", 2);

    add_company_to_market(&market, company1);
    add_company_to_market(&market, company2);

    printf("Market created with %d companies\n", market.company_count);

    for (i = 0; i < market.company_count; i++) {
        printf("Company %d: %s with abbreviation %s and market order %d\n", i + 1, market.entries[i].company->name, market.entries[i].company->stock_abbreviation, market.entries[i].company->market_order);
    }

    return 0;
}
