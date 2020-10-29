a.out: snp_reading.o partition.o read.o find_same_reads.o core.h
	g++ -g snp_reading.o partition.o read.o find_same_reads.o -o a.out
snp_reading.o:snp_reading.cpp core.h
	g++ -g -c snp_reading.cpp 
partition.o:partition.cpp core.h
	g++ -g -c partition.cpp 
read.o:read.cpp core.h
	g++ -g -c read.cpp core.h
find_same_reads.o:find_same_reads.cpp core.h
	g++ -g -c find_same_reads.cpp 

clean:
	rm -f *.out *.o