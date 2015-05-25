all: fork_test pthread_test

fork_test: fork_test.c
	${CC} -o $@ $^

pthread_test: pthread_test.c
	${CC} -o $@ $^ -lpthread

clean:
	rm fork_test pthread_test
