#Ran Mizrahi 314809625
#makefile

CC=gcc
AR=ar 
OBJECTS_GRAPH=my_graph.o
OBJECTS_KNAPSACK=my_knapsack.o
OBJECTS=my_mat.o my_knapsack.o

FLAGS= -Wall -g

all: my_mat.a my_graph my_knapsack
run: my_mat.a my_knapsack
my_mat.a: $(OBJECTS)
	$(AR) -rcs my_mat.a $(OBJECTS)
my_knapsack.a: $(OBJECTS)
	$(AR) -rcs my_knapsack.a $(OBJECTS)
my_graph: $(OBJECTS_GRAPH) my_mat.a
	$(CC) $(FLAGS) -o my_graph $(OBJECTS_GRAPH) my_mat.a
my_knapsack: $(OBJECTS_KNAPSACK) my_knapsack.a
	$(CC) $(FLAGS) -o my_knapsack $(OBJECTS_KNAPSACK) my_knapsack.a
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c -fPIC -o my_mat.o my_mat.c 
my_knapsack.o: my_knapsack.c my_mat.h
	$(CC) $(FLAGS) -c -fPIC -o my_knapsack.o my_knapsack.c 

.PHONY: clean all

make clean:
	rm -f *.o *.a *.so my_graph my_knapsack