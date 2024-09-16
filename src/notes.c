#include "html.h"

#define NOTES_INDEX_PAGE \
  RESPONSE_OK(\
    HTML(\
      HEAD(\
        TITLE("hyperprior")\
      )\
      BODY(\
        NAVBAR()\
        H1("hyperprior")\
        P("notes, if you couldn't tell")\
        P(A("/notes/books", "books")) \
        P(A("/notes/ml", "ml")) \
      )\
    )\
  )


const char notes_index_html[] = NOTES_INDEX_PAGE;
const char* get_notes_index() {
    return notes_index_html;
}
