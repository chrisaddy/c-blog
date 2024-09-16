#include "../html.h"

#define ML_INDEX_PAGE \
  RESPONSE_OK(\
    HTML(\
      HEAD(\
        TITLE("hyperprior")\
      )\
      BODY(\
        NAVBAR()\
        H1("hyperprior") \
        A("/notes/ml/neural-networks", "neural networks") \
      )\
    )\
  )


const char ml_index_html[] = ML_INDEX_PAGE;
const char* get_ml_index() {
    return ml_index_html;
}
