CC = gcc
CFLAGS = -Wall -Wextra -pthread

TARGET = ex3.out
SOURCES = article.c boundedQueue.c coEditors.c dispatcher.c main.c producer.c screenManager.c unboundedQueue.c
HEADERS = article.h boundedQueue.h coEditors.h dispatcher.h producer.h screenManager.h unboundedQueue.h
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
