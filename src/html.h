#ifndef HTML_H
#define HTML_H

#define STR(x) #x
#define XSTR(x) STR(x)

#define RESPONSE_OK(...) \
    "HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n" \
    __VA_ARGS__


#define HTML(...) \
    "<!DOCTYPE html>" \
    "<html>" \
    __VA_ARGS__ \
    "</html>"

#define HEAD(...) \
    "<head>" \
    __VA_ARGS__ \
    "</head>"

#define BODY(...) \
    "<body>" \
    __VA_ARGS__ \
    "</body>"

#define TITLE(content) "<title>" content "</title>"

#define H1(content) "<h1>" content "</h1>"

#define P(content) "<p>" content "</p>"

#define A(href, content) "<a href=\"" href "\">" content "</a>"

#define DIV(...) \
    "<div>" \
    __VA_ARGS__ \
    "</div>"

#define SPAN(content) "<span>" content "</span>"

#define IMG(src, alt) "<img src=\"" src "\" alt=\"" alt "\">"

#define BR "<br>"

#define HR "<hr>"

#endif
