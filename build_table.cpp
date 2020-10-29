#include "core.h"
void core::build_table(int now,const vector<int> same,const map<int, bipartition> current_partition,vector<table_record> &table){
    string snp_pos = all_snp.at(now);
    int i =0;
    while (i < current_partition.size()){
        unsigned int record = 0;
        int init;
        string temp;temp.clear();
        int a=0,b=0;
        while(a <current_partition.at(i).at(0).size() && b <current_partition.at(i).at(1).size()){
            if(current_partition.at(i).at(0).at(a) < current_partition.at(i).at(1).at(b)){
                if(std::find(same.begin(), same.end(), current_partition.at(i).at(0).at(a)) != same.end()){
                    if(temp.empty()){
                        init = 0;
                        temp.push_back('0');
                    }
                    else {
                        if(0 == init)
                            temp.push_back('0');
                        else
                            temp.push_back('1');
                    }
                }
                a++;
            }
            else{
                if(std::find(same.begin(), same.end(), current_partition.at(i).at(1).at(b)) != same.end()){
                    if(temp.empty()){
                        init = 1;
                        temp.push_back('0');
                    }
                    else {
                        if(1 == init)
                            temp.push_back('0');
                        else
                            temp.push_back('1');
                    }
                }
                b++;
            }
        }
        while (a < current_partition.at(i).at(0).size()){
            if(std::find(same.begin(), same.end(), current_partition.at(i).at(0).at(a)) != same.end()){
                if(temp.empty()){
                    init = 0;
                    temp.push_back('0');
                }
                else {
                    if(0 == init)
                        temp.push_back('0');
                    else
                        temp.push_back('1');
                }
            }
            a++;
        }
        while (b < current_partition.at(i).at(1).size()){
            if(std::find(same.begin(), same.end(), current_partition.at(i).at(1).at(b)) != same.end()){
                if(temp.empty()){
                    init = 1;
                    temp.push_back('0');
                }
                else {
                    if(1 == init)
                        temp.push_back('0');
                    else
                        temp.push_back('1');
                }
            }
            b++;
        }
        unsigned int encode = stoi(temp);
        table.at(i).encode = encode;
        //cout<<temp<<endl;
        i++;
    }
    
}