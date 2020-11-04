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
#define Compare(a, b) (a-b)
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
    void partition(int snp_positon,map<int, bipartition> &snp_partition,map<int, int> &now_snp_movement);
    void read();
    void find_same_reads(int now , vector<int> &same_read);
    void build_table(int now,const vector<int> same,const map<int, bipartition> current_partition, map<string ,int> &table,map<int, int> &current_snp_movement,map<int,string> &encode_on_partition, map<string, int> &encode_on_partition_inverse);
    unsigned int toInt(const string &s);
    void assemble(map<string, int> &encode_on_cur_partition_inverse,map<string, int> &encode_on_pre_partition_inverse,map<int, bipartition> &current_partition,map<int, bipartition> &previous_partition,
                    map<int, int> &current_snp_movement,map<int, int> &previous_snp_movement);
    void change_bits(string &encode,const map<string ,int> &current_table,const map<string ,int> &previous_table,int &move);
    void make_encode(map<int,string> &encode_on_partition, map<string, int> &encode_on_cur_partition_inverse,map<int, int> &current_snp_movement,const int &pos,const string &enco);
};


