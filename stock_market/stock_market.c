#include "stock_market.h"
static Person *find_person(Person **people,
                           int people_count,
                           const char *name);
static StockMarketEntry *find_entry(StockMarket *market,
                                    const char *abv);
                                    
Person* create_person(char *name, int id) {
    /* WRITE YOUR CODE HERE AND REMOVE RETURN NULL */
    Person *p;
    p = (Person*) malloc(sizeof(Person)); /* allocate size as much as person struct*/
    if (!p) {
        fprintf(stderr, "Failed to allocate memory for Person\n");
        exit(1); /* Provide Error Message*/
    }
    strncpy(p->name, name, MAX_NAME_LEN - 1); /* strncpy makes copy till max_name_len - 1, till null terminate. or null parts. */
    p->name[MAX_NAME_LEN - 1] = '\0'; /* assign null terminate at end.*/
    p->id = id; /* assign id of the person*/
    return p;
}

Company* create_company(char *name, char *abv, int order) {
    /* WRITE YOUR CODE HERE AND REMOVE RETURN NULL */
    Company *c;
    c = (Company*) malloc(sizeof(Company));
    if (!c) {
        fprintf(stderr, "Failed to allocate memory for Company\n");
        exit(1);
    }
    strncpy(c->name, name, MAX_NAME_LEN - 1); /* same as person.*/
    c->name[MAX_NAME_LEN - 1] = '\0'; /* same as person.*/
    strncpy(c->stock_abbreviation, abv, 9); /* stock size is 10 so till 10th assign values.*/
    c->stock_abbreviation[9] = '\0'; /* Null terminate at the end*/
    c->market_order = order; /* assign order of company*/
    return c;
}

void add_company_to_market(StockMarket *market, Company *company) {
    /* WRITE YOUR CODE HERE */
    StockMarketEntry *sme;
    sme = &market->entries[market->company_count];
    sme->company = company;
    sme->buy_requests = NULL;
    sme->sell_requests = NULL;
    market->company_count++;
}

/* Allocate and initialize the RequestNode */
RequestNode* create_request_node(Person *p,
                                 int amount,
                                 float price){
    RequestNode *node;
    node = (RequestNode*) malloc(sizeof(RequestNode));
    if (!node) {
        fprintf(stderr, "Failed to allocate memory for RequestNode\n");
        exit(1);
    }
    /* Linkedlist structure for request node.*/
    node->data.person = p;
    node->data.amount = amount;
    node->data.price_per_share  = price;
    node->next = NULL;
    return node;
}

void insert_sorted(RequestNode **head, RequestNode *node, int ascending) {
    /* WRITE YOUR CODE HERE */
    RequestNode *cur, *prev; /* Bi-directional linkedlist */

    if (*head == NULL || (ascending ? node->data.price_per_share <  (*head)->data.price_per_share : node->data.price_per_share >  (*head)->data.price_per_share)){
        
        node->next = *head; /* Make next our head.*/
        *head = node;
        return;
    }

    prev = *head;
    cur  = prev->next;
    while (cur != NULL && (ascending ? cur->data.price_per_share <= node->data.price_per_share : cur->data.price_per_share >= node->data.price_per_share)){
        
        prev = cur;
        cur  = cur->next;
    }

    node->next = cur;
    prev->next = node;
}

void insert_buy_request(StockMarket *market, Person **people, int people_count, char *buyer_name, char *company_abv, int amount, float price) {
    /* WRITE YOUR CODE HERE */
    Person* buyer;
    StockMarketEntry* entry;
    int remaining;
    RequestNode *cur, *prev, *node;
    int trade_amount;
    /* Pointers to person, sme, to node.*/

    buyer = find_person(people, people_count, buyer_name);
    entry = find_entry(market, company_abv);
    if (!buyer || !entry){
        return;
    }
    remaining = amount;
    cur = entry->sell_requests;
    prev = NULL;

    /* Matching amount to buy and sell, for their desired amount. */
    while (cur != NULL && remaining > 0) {
        if (cur->data.price_per_share <= price) {
            trade_amount = (remaining < cur->data.amount ? remaining : cur->data.amount);
            printf("Trade executed: %d shares of %s at %.2f between %s, %s\n",
                   trade_amount,
                   company_abv,
                   cur->data.price_per_share,
                   cur->data.person->name,
                   buyer->name);
            remaining -= trade_amount;
            cur->data.amount -= trade_amount;

            if (cur->data.amount == 0) {
                /* removing the node */
                if (prev == NULL) {
                    entry->sell_requests = cur->next;
                    free(cur);
                    cur = entry->sell_requests;
                } else {
                    prev->next = cur->next;
                    free(cur);
                    cur = prev->next;
                }
            } else {
                prev = cur;
                cur  = cur->next;
            }
        } else {
            break;
        }
    }

    /* Check Enqueue*/
    if (remaining > 0) {
        node = create_request_node(buyer, remaining, price);
        insert_sorted(&entry->buy_requests, node, 0);
    }
}

void insert_sell_request(StockMarket *market, Person **people, int people_count, char *seller_name, char *company_abv, int amount, float price) {
    /* WRITE YOUR CODE HERE */
    Person* seller;
    StockMarketEntry* entry;
    int remaining;
    RequestNode *cur, *prev, *node;
    int trade_amount;

    seller = find_person(people, people_count, seller_name);
    entry = find_entry(market, company_abv);
    if (!seller || !entry){ return;
    }

    remaining = amount;
    cur = entry->buy_requests;
    prev = NULL;

    /* Match */
    while (cur != NULL && remaining > 0) {
        if (cur->data.price_per_share >= price) {
            trade_amount = (remaining < cur->data.amount ? remaining : cur->data.amount);
            printf("Trade executed: %d shares of %s at %.2f between %s, %s\n",
                   trade_amount,
                   company_abv,
                   price,
                   seller->name,
                   cur->data.person->name);
            remaining -= trade_amount;
            cur->data.amount -= trade_amount;

            if (cur->data.amount == 0) {
                if (prev == NULL) {
                    entry->buy_requests = cur->next;
                    free(cur);
                    cur = entry->buy_requests;
                } else {
                    prev->next = cur->next;
                    free(cur);
                    cur = prev->next;
                }
            } else {
                prev = cur;
                cur  = cur->next;
            }
        } else {
            break;
        }
    }

    /* Check Enqueue*/
    if (remaining > 0) {
        node = create_request_node(seller, remaining, price);
        insert_sorted(&entry->sell_requests, node, 1);
    }
}

void print_market(StockMarket *market) {
    /* WRITE YOUR CODE HERE */
    int i;
    RequestNode *p;

    for (i = 0; i < market->company_count; i++) {
        StockMarketEntry *e = &market->entries[i];

        printf("Company: %s (%s)\n",
               e->company->name,
               e->company->stock_abbreviation);

        /* tab correction is made for to fit the the2 requirement*/
        printf("\tBuy Requests:\n");
        p = e->buy_requests;
        while (p != NULL) {
            /* two tabs for wants. */
            printf("\t\t%s wants %d @ %.2f\n",
                   p->data.person->name,
                   p->data.amount,
                   p->data.price_per_share);
            p = p->next;
        }
        /* one tabs for wants. */
        printf("\tSell Requests:\n");
        p = e->sell_requests;
        while (p != NULL) {
            printf("\t\t%s sells %d @ %.2f\n",
                   p->data.person->name,
                   p->data.amount,
                   p->data.price_per_share);
            p = p->next;
        }
    }
}

static Person *find_person(Person **people,
                           int people_count,
                           const char *name)
{
    int i;
    for (i = 0; i < people_count; i++) {
        if (strcmp(people[i]->name, name) == 0) {
            return people[i];
        }
    }
    return NULL;
}


static StockMarketEntry *find_entry(StockMarket *market,
                                    const char *abv)
{
    int i;
    for (i = 0; i < market->company_count; i++) {
        if (strcmp(market->entries[i].company->stock_abbreviation,
                   abv) == 0)
        {
            return &market->entries[i];
        }
    }
    return NULL;
}


