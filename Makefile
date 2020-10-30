all: a.out
a.out: main.o partition.o read.o find_same_reads.o build_table.o core.h
	g++ -g main.o partition.o read.o find_same_reads.o build_table.o -o a.out
main.o:main.cpp core.h
	g++ -g -c main.cpp 
partition.o:partition.cpp core.h
	g++ -g -c partition.cpp 
read.o:read.cpp core.h
	g++ -g -c read.cpp core.h
find_same_reads.o:find_same_reads.cpp core.h
	g++ -g -c find_same_reads.cpp 
build_table.o:build_table.cpp core.h
	g++ -g -c build_table.cpp 
clean:
	rm -f *.out *.o *.gch