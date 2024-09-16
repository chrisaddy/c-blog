#ifndef HTML_H
#define HTML_H

#define STR(x) #x
#define XSTR(x) STR(x)

#define RESPONSE_OK(...) \
    "HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n" \
    __VA_ARGS__

#define RESPONSE_METHOD_NOT_ALLOWED(...) \
    "HTTP/1.1 405 Method Not Allowed\r\nContent-length: 0\r\nAllow: GET" \
    __VA_ARGS__

#define HTML(...) \
    "<!DOCTYPE html>" \
    "<html>" \
    __VA_ARGS__ \
    "</html>"

#define HEAD(...) \
    "<head>" \
    "<script src=\"https://polyfill.io/v3/polyfill.min.js?features=es6\"></script>" \
    "<script id=\"MathJax-script\" async src=\"https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-mml-chtml.js\"></script>"\
    __VA_ARGS__ \
    "</head>"

#define BODY(...) \
    "<body style=\"width: 80%; margin: 0 auto;\">" \
    __VA_ARGS__ \
    "</body>"

#define NAVBAR(content) "<div class=\"naviation\"" \
                        "<ul style=\"list-style-type: none; padding: 0; margin: 0; display: flex;\">" \
                        "<li style=\"margin-right: 10px;\"><a style=\"font-size: 1.5em; text-decoration: none;\"; href=\"/\">home</a></li>" \
                        "<li style=\"margin-right: 10px;\"><a style=\"font-size: 1.5em; text-decoration: none;\"; href=\"/about\">about</a></li>" \
                        "<li style=\"margin-right: 10px;\"><a style=\"font-size: 1.5em; text-decoration: none;\"; href=\"/notes\">notes</a></li>" \
                        "</ul></div>"

#define TITLE(content) "<title>" content "</title>"

#define H1(content) "<h1>" content "</h1>"
#define H2(content) "<h2>" content "</h2>"
#define H3(content) "<h3>" content "</h3>"

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
