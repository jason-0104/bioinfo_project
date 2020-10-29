#include "core.h"
void core::partition(int snp_positon,map<int, bipartition> &snp_partition){
    map<int, bipartition> now_snp; //store all partition
    int j=0;
    int i=0;
    int k=snp_positon;
    while(j<reads_on_SNP.at(all_snp.at(k)).size()+1){   
        vector<int>read;
        bipartition table;
        table.insert(pair<int, vector<int>>(0,read));
        table.insert(pair<int, vector<int>>(1,read));
        now_snp.insert(pair<int,bipartition>(j,table));
        i=0;
     
        while(i<reads_on_SNP.at(all_snp.at(k)).size()){
            if(reads_on_SNP.at(all_snp.at(k)).at(i).value=='0')
                now_snp.at(j).at(0).push_back(reads_on_SNP.at(all_snp.at(k)).at(i).read_name);
            else
                now_snp.at(j).at(1).push_back(reads_on_SNP.at(all_snp.at(k)).at(i).read_name); 
            i++;
        }
        if(j==0){
            j++;
            continue;
        }  
        else{
            if((reads_on_SNP.at(all_snp.at(k)).at(j-1).value)=='0'){
                now_snp.at(j).at(1).push_back(reads_on_SNP.at(all_snp.at(k)).at(j-1).read_name); 
                int iter=0;
                while(iter<now_snp.at(j).at(0).size()){
                    if(now_snp.at(j).at(0).at(iter)==reads_on_SNP.at(all_snp.at(k)).at(j-1).read_name){
                        now_snp.at(j).at(0).erase(now_snp.at(j).at(0).begin()+iter);
                        break;
                    }
                iter++; 
                }
            sort(now_snp.at(j).at(1).begin(),now_snp.at(j).at(1).end());
            }
            else{
                now_snp.at(j).at(0).push_back(reads_on_SNP.at(all_snp.at(k)).at(j-1).read_name); 
                int iter=0;
                while(iter<now_snp.at(j).at(1).size()){
                    if(now_snp.at(j).at(1).at(iter)==reads_on_SNP.at(all_snp.at(k)).at(j-1).read_name){
                       now_snp.at(j).at(1).erase(now_snp.at(j).at(1).begin()+iter);
                        break;
                    }
                iter++;
                }
            sort(now_snp.at(j).at(0).begin(),now_snp.at(j).at(0).end()); 
            }
        }
        j++;
    } 
    snp_partition = now_snp;
}