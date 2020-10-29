#include "core.h"

int main()
{
    core snp;
    snp.read(); //read data file
    int iterator = 0; 
    map<int, bipartition> current_partition,previous_partition;  //store partition consequence
    vector<table_record> table;  //store table by partiton encodding
    // run all snp
    while (iterator < snp.all_snp.size()) {
        table.clear();
        snp.partition(0 , current_partition);
        int j =0;
        //print partiton
        while( j < snp.reads_on_SNP.at(snp.all_snp.at(0)).size()+1){
            cout<<j<<endl;
            for(int a=0;a<current_partition.at(j).at(0).size();a++)
                cout<<"0: "<<current_partition.at(j).at(0).at(a)<<endl;
            for(int a=0;a<current_partition.at(j).at(1).size();a++)
                cout<<"1: "<<current_partition.at(j).at(1).at(a)<<endl;
            j++;
        }
        // find same reads between current and previous snp
        vector<int> same;
        if(iterator <  snp.all_snp.size()-1){
            snp.find_same_reads(iterator,same);
            for(int a=0;a<same.size();a++)
                    cout<<"same: "<<same.at(a)<<endl;
        }
        // build table to record partition
        snp.build_table(iterator,same,current_partition,table);
        break;
        //break;
        // compare with previous partition 
        if(iterator != 0){
            
        }
        previous_partition = current_partition;
        iterator++;
    }

    return 0;
}
