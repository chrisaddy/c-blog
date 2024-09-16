#include "html.h"

#define ABOUT_PAGE \
  RESPONSE_OK(\
    HTML(\
      HEAD(\
        TITLE("hyperprior")\
      )\
      BODY(\
        NAVBAR()\
        H1("hyperprior")\
        P("this site is written entirely in C")\
      )\
    )\
  )


const char about_html[] = ABOUT_PAGE;
const char* get_about_html() {
    return about_html;
}
