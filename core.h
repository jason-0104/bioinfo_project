#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <fstream>
#include <bits/stdc++.h> //sorting library
#include <sstream>
using namespace std;
using std::cout;
using std::endl;
#define compare(a, b) (a-b)
typedef  map<int, vector<int>> bipartition;

class link{
public:
    int read_name;
    char value;
    int cost;
};
class table_record{
public:
    table_record(){
        movement_count = 0;
    }
    unsigned int encode;  // store current partition ex: '0': R1 R2  & '1':R3 R4 by encode
    int movement_count;      //movement 
};
class core{
public:
    core(){
        reads_on_SNP.clear();
    }
    map<string, vector<link>> reads_on_SNP;
    vector<string> all_snp;
    void partition(int snp_positon,map<int, bipartition> &snp_partition);
    void read();
    void find_same_reads(int now , vector<int> &same_read);
    void build_table(int now,const vector<int> same,const map<int, bipartition> current_partition, map<unsigned int ,int> &table,int flag=0 ,const map<unsigned int ,int> &previous_table =  map<unsigned int ,int>());
    unsigned int toInt(const string &s);
};


