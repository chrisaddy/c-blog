#include "html.h"

#define ABOUT_PAGE \
  RESPONSE_OK(\
    HTML(\
      HEAD(\
        TITLE("hyperprior")\
      )\
      BODY(\
        NAVBAR()\
        H1("about")\
        P("this is the about page, if that wasn't obvious")\
      )\
    )\
  )


const char about_html[] = ABOUT_PAGE;
const char* get_about_html() {
    return about_html;
}
