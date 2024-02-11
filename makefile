#Ran Mizrahi 314809625
#makefile

CC=gcc
AR=ar 
OBJECTS_GRAPH=my_graph.o
OBJECTS_KNAPSACK=my_Knapsack.o
OBJECTS_MAT=my_mat.o
#OBJECTS=my_mat.o my_knapsack.o

FLAGS= -Wall -g

all: my_mat.a my_graph my_Knapsack.a my_Knapsack
run: my_Knapsack.a my_mat.a

my_mat.a: $(OBJECTS_MAT)
	$(AR) -rcs my_mat.a $(OBJECTS_MAT)
my_Knapsack.a: $(OBJECTS_KNAPSACK)
	$(AR) -rcs my_Knapsack.a $(OBJECTS_KNAPSACK)
my_graph: $(OBJECTS_GRAPH) my_mat.a
	$(CC) $(FLAGS) -o my_graph $(OBJECTS_GRAPH) my_mat.a
my_Knapsack: $(OBJECTS_KNAPSACK) my_Knapsack.a
	$(CC) $(FLAGS) -o my_Knapsack $(OBJECTS_KNAPSACK) my_Knapsack.a
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c -fPIC -o my_mat.o my_mat.c 
my_Knapsack.o: my_Knapsack.c 
	$(CC) $(FLAGS) -c -fPIC -o my_Knapsack.o my_Knapsack.c 
my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c -fPIC -o my_graph.o my_graph.c 

.PHONY: clean all

clean:
	rm -f *.o *.a my_graph my_Knapsack