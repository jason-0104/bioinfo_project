#include "core.h"

int main()
{
    core snp;
    snp.read(); //read data file
    int iterator = 0; 
    map<int, bipartition> current_partition,previous_partition;  //store partition consequence
    map<unsigned int ,int> table;  //store table by partiton encodding
    vector<int> same;    //store reads which apear in two consecutive snp
    std::vector<int> map_key;
    
    // run all snp
    while (iterator < snp.all_snp.size()) {
        //do partition in current snp
        snp.partition(iterator , current_partition);

        //print partiton
        int j =0;
        while( j < snp.reads_on_SNP.at(snp.all_snp.at(iterator)).size()+1){
            cout<<j<<endl;
            for(int a=0;a<current_partition.at(j).at(0).size();a++)
                cout<<"0: "<<current_partition.at(j).at(0).at(a)<<endl;
            for(int a=0;a<current_partition.at(j).at(1).size();a++)
                cout<<"1: "<<current_partition.at(j).at(1).at(a)<<endl;
            j++;
        }

        // compare with previous partition 
        map_key.clear();
        if(iterator != 0){
            map<unsigned int ,int> table_current;
            snp.build_table(iterator,same,current_partition,table_current,1,table);
            for(auto const& imap: table_current)
                map_key.push_back(imap.first);
            for(int a=0;a<map_key.size();a++)
                cout<<"Encode: "<<map_key.at(a)<<" Cost: "<<table_current.at(map_key.at(a))<<endl;
        }
        
        // find same reads between current and previous snp
        
        if(iterator <  snp.all_snp.size()-1){
            snp.find_same_reads(iterator,same);
            for(int a=0;a<same.size();a++)
                    cout<<"same: "<<same.at(a)<<endl;
        }
        table.clear();
        map_key.clear();
        // build table to record partition
        snp.build_table(iterator,same,current_partition,table);
        for(auto const& imap: table)
            map_key.push_back(imap.first);
        for(int a=0;a<map_key.size();a++)
            cout<<"encode: "<<map_key.at(a)<<" cost: "<<table.at(map_key.at(a))<<endl;
        if(iterator == 1)
            break;
        
        previous_partition = current_partition;
        iterator++;
    }

    return 0;
}
