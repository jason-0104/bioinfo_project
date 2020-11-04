#include "core.h"
void core::assemble(map<string, int> &encode_on_cur_partition_inverse,map<string, int> &encode_on_pre_partition_inverse,map<int, bipartition> &current_partition,map<int, bipartition> &previous_partition
                    ,map<int, int> &current_snp_movement,map<int, int> &previous_snp_movement)
{
    vector<string> map_key;
    int pre =0,cur=0;
    for(auto const& imap: encode_on_cur_partition_inverse){
        //if there has a same encode in previous partition
        int find =1;
        if(encode_on_pre_partition_inverse.find(imap.first) == encode_on_pre_partition_inverse.end())
            find = 0;
        else
            pre = encode_on_pre_partition_inverse.at(imap.first);
        if(find){
            //put reads together
            for(int i=0;i<current_partition.at(imap.second).at(0).size();i++){
                int j =0;
                while (previous_partition.at(pre).at(0).at(j) < current_partition.at(imap.second).at(0).at(i) && j < previous_partition.at(pre).at(0).size()-1) {
                    j++;
                }
                cout<<j<<" "<<previous_partition.at(pre).at(0).at(j)<<"   "<<current_partition.at(imap.second).at(0).at(i)<<endl;
                if(previous_partition.at(pre).at(0).at(j) > current_partition.at(imap.second).at(0).at(i)){
                    previous_partition.at(pre).at(0).push_back(current_partition.at(imap.second).at(0).at(i));
                    cout<<imap.first<<" add "<<current_partition.at(imap.second).at(0).at(i)<<" at 0\n";
                }
            }
            for(int i=0;i<current_partition.at(imap.second).at(1).size();i++){
                int j =0;
                while (previous_partition.at(pre).at(1).at(j) < current_partition.at(imap.second).at(1).at(i) && j < previous_partition.at(pre).at(0).size()) {
                    j++;
                }
                if(previous_partition.at(pre).at(1).at(j) > current_partition.at(imap.second).at(1).at(i)){
                    previous_partition.at(pre).at(1).push_back(current_partition.at(imap.second).at(1).at(i));
                    cout<<imap.first<<" add "<<current_partition.at(imap.second).at(1).at(i)<<" at 0\n";
                }
            }
            sort(previous_partition.at(pre).at(1).begin(),previous_partition.at(pre).at(1).end());
            sort(previous_partition.at(pre).at(0).begin(),previous_partition.at(pre).at(0).end());
        }
        //else
        else{

        }
    }

}