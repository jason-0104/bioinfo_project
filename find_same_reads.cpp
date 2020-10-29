#include "core.h"
void core::find_same_reads(int now, vector<int> &same_read){
    string now_snp_name = all_snp.at(now);
    string next_snp_name = all_snp.at(now+1);
    same_read.clear();
    if(compare(reads_on_SNP.at(now_snp_name).size(),reads_on_SNP.at(next_snp_name).size()) < 0){
        string temp;
        temp = now_snp_name;
        now_snp_name = next_snp_name;
        next_snp_name = temp;
    }
    int i =0,j=0;
    while(i <reads_on_SNP.at(now_snp_name).size() && j <reads_on_SNP.at(next_snp_name).size()) {
        if(reads_on_SNP.at(now_snp_name).at(i).read_name == reads_on_SNP.at(next_snp_name).at(j).read_name){
            same_read.push_back(reads_on_SNP.at(next_snp_name).at(j).read_name);
            i++;j++;
        }
        else if(compare(reads_on_SNP.at(now_snp_name).at(i).read_name,reads_on_SNP.at(next_snp_name).at(j).read_name) < 0){
            i++;
        }
        else{
            j++;
        }
    }
}