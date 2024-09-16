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
        P("this site is part blog part evergreen notes")\
      )\
    )\
  )


const char index_html[] = INDEX_PAGE;
const char* get_index_html() {
    return index_html;
}
