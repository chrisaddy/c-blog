FROM alpine:3.14

RUN apk add --no-cache gcc musl-dev

WORKDIR /app

COPY server.c .

RUN gcc -static -o server server.c

EXPOSE 8080

CMD ["./server"]
