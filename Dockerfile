FROM gcc:13.2.0-bookworm AS build

WORKDIR /src

COPY ./server.c /src/server.c

RUN set -xe; \
    gcc \
	-Wall -Wextra \
	-fPIC -pie \
	-o /server /src/server.c

FROM scratch

COPY --from=build /server /server
COPY --from=build /lib/x86_64-linux-gnu/libc.so.6 /lib/x86_64-linux-gnu/
COPY --from=build /lib64/ld-linux-x86-64.so.2 /lib64/

EXPOSE 8080

ENTRYPOINT ["/server"]
