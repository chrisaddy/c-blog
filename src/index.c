#include "html.h"

#define INDEX_PAGE \
  RESPONSE_OK(\
    HTML(\
      HEAD(\
        TITLE("hyperprior")\
      )\
      BODY(\
        NAVBAR()\
        H1("hyperprior")\
        P("we'll be right back")\
      )\
    )\
  )


const char index_html[] = INDEX_PAGE;
const char* get_index_html() {
    return index_html;
}
