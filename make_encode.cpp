#include "core.h"
void core::make_encode(map<int,string> &encode_on_partition, map<string, int> &encode_on_cur_partition_inverse,map<int, int> &current_snp_movement,const int &pos,const string &enco){
    encode_on_partition.insert(pair<int,string>(pos,enco));
    if(encode_on_cur_partition_inverse.find(enco) == encode_on_cur_partition_inverse.end())
        encode_on_cur_partition_inverse.insert(pair<string,int>(enco,pos));
    else {
        if(current_snp_movement.at(encode_on_cur_partition_inverse.at(enco)) >= current_snp_movement.at(pos)){
            encode_on_cur_partition_inverse.at(enco) = pos;
        }
    }
    
}