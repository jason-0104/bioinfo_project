a.out: snp_reading.o partition.o read.o find_same_reads.o build_table.o core.h
	g++ -g snp_reading.o partition.o read.o find_same_reads.o build_table.o -o a.out
snp_reading.o:snp_reading.cpp core.h
	g++ -g -c snp_reading.cpp 
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