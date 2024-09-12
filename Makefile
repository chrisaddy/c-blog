build:
	cd src && \
		gcc -Wall server.c -o ../server

run:
	./server

docker-build:
	docker build -t blog .

docker-run:
	docker run -p 8080:8080 blog
