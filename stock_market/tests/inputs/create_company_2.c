#include "stock_market.h"

/* Create 2 companies */

int main(void) {
    Company *company1 = create_company("Alpha Corp", "ALP", 1);
    Company *company2 = create_company("Beta Inc", "BET", 2);

    printf("Company created: %s with abbreviation %s and market order %d\n", company1->name, company1->stock_abbreviation, company1->market_order);
    printf("Company created: %s with abbreviation %s and market order %d\n", company2->name, company2->stock_abbreviation, company2->market_order);

    return 0;
}
