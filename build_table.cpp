#include "core.h"
unsigned int core::toInt(const string &s){
    unsigned int n =0; 
    for (char c : s){
        if(c=='\0')
            break;
        n = (n << 1) |  // Shift the current set of bits to the left one bit
        (c - '0');
    }
    return n;
}
// flag is to control build table mode
void core::build_table(int now,const vector<int> same,const map<int, bipartition> current_partition, map<unsigned int ,int> &table,int flag, const map<unsigned int ,int> &previous_table ){
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
        temp.push_back('\0');
        cout<<temp<<endl;
        int movement_count = 0;
        if(i != 0)
            movement_count += 1;
        unsigned key = toInt(temp);
        if(flag != 0) {
            //previous_table
            if ( previous_table.find(key) == previous_table.end() ) {
                // not found
                table.insert(pair<unsigned int , int>(key,-1));
            } 
            else {
                // found
                table.at(key) += movement_count;
            }
        }
        else{
            table.insert(pair<unsigned int , int>(key,movement_count));
        }
        i++;
    }
    
}