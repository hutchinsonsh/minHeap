
EXEC = run
CC = g++
CFLAGS = -c

# $(EXEC) has the value of shell variable EXEC, which is run.
# # run depends on the files main.o util.o heap.o
$(EXEC) :mainMin.o heapMin.o
# run is created by the command g++ -o run main.o
# note that the TAB before $(CC) is REQUIRED...
	$(CC) -o $(EXEC) mainMin.o heapMin.o

# main.o depends on the files main.h main.cpp
mainMin.o: mainMin.cpp
# main.o is created by the command g++ -c -Wall main.cpp
# note that the TAB before $(CC) is REQUIRED...
	$(CC) $(CFLAGS) mainMin.cpp

heapMin.o  :heapMin.h heapMin.cpp
	$(CC) $(CFLAGS) heapMin.cpp

clean:
	rm *.o
	rm run

