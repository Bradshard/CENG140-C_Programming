#include "stock_market.h"

/* Create 1 company */

int main(void) {
    Company *company = create_company("Alpha Corp", "ALP", 1);

    printf("Company created: %s with abbreviation %s and market order %d\n", company->name, company->stock_abbreviation, company->market_order);

    return 0;
}
