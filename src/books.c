#include "html.h"

#define BOOKS_PAGE \
  RESPONSE_OK(\
    HTML(\
      HEAD(\
        TITLE("hyperprior")\
      )\
      BODY(\
        NAVBAR()\
        H1("hyperprior") \
        H2("finished") \
        P("war and peace") \
        H2("in progress") \
      )\
    )\
  )


const char books_html[] = BOOKS_PAGE;
const char* get_books() {
    return books_html;
}
