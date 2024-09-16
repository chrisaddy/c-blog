#include "html.h"

#define METHOD_NOT_ALLOWED \
    RESPONSE_METHOD_NOT_ALLOWED()


const char method_not_allowed[] = METHOD_NOT_ALLOWED;
const char* get_method_not_allowed() {
    return method_not_allowed;
}


#define MISSING_PAGE \
  RESPONSE_OK(\
    HTML(\
      HEAD(\
        TITLE("hyperprior")\
      )\
      BODY(\
        NAVBAR()\
        H1("hyperprior")\
        P("this page does not exist")\
        A("/", "home") \
      )\
    )\
  )

const char missing_html[] = MISSING_PAGE;
const char* get_missing_page() {
    return missing_html;
}
