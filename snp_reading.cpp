#include "core.h"

int main()
{
    core snp;
    snp.read(); //read data file
    int iterator = 0; 
    map<int, bipartition> now_snp,previous_snp;  //store partition consequence
    // run all snp
    while (iterator < snp.all_snp.size()) {
        snp.partition(0 , now_snp);
        int j =0;
        //print partiton
        while( j < snp.reads_on_SNP.at(snp.all_snp.at(0)).size()){
            cout<<j<<endl;
            for(int a=0;a<now_snp.at(j).at(0).size();a++)
                cout<<"0: "<<now_snp.at(j).at(0).at(a)<<endl;
            for(int a=0;a<now_snp.at(j).at(1).size();a++)
                cout<<"1: "<<now_snp.at(j).at(1).at(a)<<endl;
            j++;
        }
        // find same reads between now and next snp
        if(iterator <  snp.all_snp.size()-1){
            vector<int> same;
            snp.find_same_reads(iterator,same);
            for(int a=0;a<same.size();a++)
                    cout<<"same: "<<same.at(a)<<endl;
        }
        
        //break;
        // compare with previous partition 
        if(iterator != 0){

        }
        previous_snp = now_snp;
        iterator++;
    }

    return 0;
}
