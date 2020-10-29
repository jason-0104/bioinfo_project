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
    map<int,char> read_0_1;
    int movement_count;
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
};


