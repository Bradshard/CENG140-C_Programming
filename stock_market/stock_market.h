#ifndef STOCK_MARKET_H
#define STOCK_MARKET_H

#define MAX_NAME_LEN 50
#define MAX_COMPANIES 100
#define MAX_PEOPLE 200

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[MAX_NAME_LEN];
    int id;
} Person;

typedef struct {
    Person *person;
    int amount;
    float price_per_share;
} Request;

typedef struct RequestNode {
    Request data;
    struct RequestNode *next;
} RequestNode;

typedef struct {
    char name[MAX_NAME_LEN];
    char stock_abbreviation[10];
    int market_order;
} Company;

typedef struct {
    Company *company;
    RequestNode *buy_requests;
    RequestNode *sell_requests;
} StockMarketEntry;

typedef struct {
    StockMarketEntry entries[MAX_COMPANIES];
    int company_count;
} StockMarket;

/* Main logic functions */
void insert_buy_request(StockMarket *market, Person **people, int people_count, char *buyer_name, char *company_abbr, int amount, float price);
void insert_sell_request(StockMarket *market, Person **people, int people_count, char *seller_name, char *company_abbr, int amount, float price);
void print_market(StockMarket *market);

/* Creation utilities */
Person* create_person(char *name, int id);
Company* create_company(char *name, char *abbr, int order);
void add_company_to_market(StockMarket *market, Company *company);
RequestNode* create_request_node(Person *p, int amount, float price);

#endif
