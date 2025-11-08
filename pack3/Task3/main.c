#include "include/linked_list.h"
#include "include/solve.h"
#include "include/liver.h"
#include "include/string_manager.h"
#include "include/status_manager.h"
#include <stdio.h>
#include "include/interface.h"

int main() {
    Status status = talk_to_user();
    if (status != OK) {
        print_status(status);
        return status;
    }
}