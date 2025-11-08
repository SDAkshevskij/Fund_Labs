#ifndef INTERFACE_H
#define INTERFACE_H
#include "status_manager.h"
#include "vector.h"



typedef enum {
    TRANSACTION_EDIT,
    TRANSACTION_ADD,
    TRANSACTION_DELETE
} TransactionType;

typedef struct {
    TransactionType type;
    Liver liver;
    int index;
} Transaction;

DECLARE_VECTOR(Transaction);
DEFINE_VECTOR(Transaction);

Status talk_to_user();

#endif