all: a.out
a.out: main.o partition.o read.o find_same_reads.o build_table.o change_bits.o assemble.o make_encode.o core.h
	g++ -g main.o partition.o read.o find_same_reads.o build_table.o change_bits.o assemble.o make_encode.o -o a.out
main.o:main.cpp core.h
	g++ -g -c main.cpp 
partition.o:partition.cpp core.h
	g++ -g -c partition.cpp 
assemble.o:assemble.cpp core.h
	g++ -g -c assemble.cpp
change_bits.o:change_bits.cpp core.h
	g++ -g -c change_bits.cpp
read.o:read.cpp core.h
	g++ -g -c read.cpp core.h
find_same_reads.o:find_same_reads.cpp core.h
	g++ -g -c find_same_reads.cpp 
build_table.o:build_table.cpp core.h
	g++ -g -c build_table.cpp 
make_encode.o:make_encode.cpp core.h
	g++ -g -c make_encode.cpp 
clean:
	rm -f *.out *.o *.gch