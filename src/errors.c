#include "html.h"

#define METHOD_NOT_ALLOWED \
    RESPONSE_METHOD_NOT_ALLOWED()


const char method_not_allowed[] = METHOD_NOT_ALLOWED;
const char* get_method_not_allowed() {
    return method_not_allowed;
}
