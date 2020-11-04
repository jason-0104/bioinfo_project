#include "core.h"

int main()
{
    core snp;
    snp.read(); //read data file
    int iterator = 0; 
    map<int, bipartition> current_partition,previous_partition;  //store partition consequence
    map<string,int> table;  //store table by partiton encodding
    vector<int> next_same,previous_smae;    //store reads which apear in two consecutive snp
    std::vector<string> map_key;
    map<int, int> current_snp_movement,previous_snp_movement;
    map<int, string> encode_on_cur_partition,encode_on_pre_partition;
    map<string, int> encode_on_cur_partition_inverse,encode_on_pre_partition_inverse;
    // run all snp
    while (iterator < snp.all_snp.size()) {
        //first snp
        if(iterator == 0){
            //do partition in current snp
            current_partition.clear();
            snp.partition(iterator , current_partition , current_snp_movement);
            //find same
            next_same.clear();
            if(iterator <  snp.all_snp.size()-1){
                snp.find_same_reads(iterator,next_same);
                for(int a=0;a<next_same.size();a++)
                        cout<<"same: "<<next_same.at(a)<<endl;
            }

            //build encode
            map<string ,int> table_current;
            snp.build_table(iterator,next_same,current_partition,table_current,current_snp_movement,encode_on_cur_partition,encode_on_cur_partition_inverse);
            // key value change
            

            //print partiton
            int j =0;
            cout<<"c"<<endl;
            while( j < snp.reads_on_SNP.at(snp.all_snp.at(iterator)).size()+1){
                cout<<j<<endl;
                cout<<"0: ";
                for(int a=0;a<current_partition.at(j).at(0).size();a++)
                    cout<<current_partition.at(j).at(0).at(a)<<" ";
                cout<<'\n';
                cout<<"1: ";
                for(int a=0;a<current_partition.at(j).at(1).size();a++)
                    cout<<current_partition.at(j).at(1).at(a)<<" ";
                cout<<'\n';
                cout<<"move: "<<current_snp_movement.at(j)<<endl;
                cout<<"econde: "<<encode_on_cur_partition.at(j)<<endl;
                j++;
            }

            previous_partition = current_partition; current_partition.clear();
            encode_on_pre_partition = encode_on_cur_partition; encode_on_cur_partition.clear();
            previous_snp_movement = current_snp_movement; current_snp_movement.clear();
            previous_smae = next_same; next_same.clear();
            encode_on_pre_partition_inverse = encode_on_cur_partition_inverse; encode_on_cur_partition_inverse.clear();
            iterator++;
            continue;
        }
        //after first snp
        //do partition in current snp
        snp.partition(iterator , current_partition , current_snp_movement);
        //find same
        next_same.clear();
        if(iterator <  snp.all_snp.size()-1){
            snp.find_same_reads(iterator,next_same);
            for(int a=0;a<next_same.size();a++)
                    cout<<"same: "<<next_same.at(a)<<endl;
        }

        //build encode
        map<string ,int> table_current;
        snp.build_table(iterator,previous_smae,current_partition,table_current,current_snp_movement,encode_on_cur_partition,encode_on_cur_partition_inverse);

        //print partiton
        int j =0;
        cout<<"c"<<endl;
        while( j < snp.reads_on_SNP.at(snp.all_snp.at(iterator)).size()+1){
            cout<<j<<endl;
            cout<<"0: ";
            for(int a=0;a<current_partition.at(j).at(0).size();a++)
                cout<<current_partition.at(j).at(0).at(a)<<" ";
            cout<<'\n';
            cout<<"1: ";
            for(int a=0;a<current_partition.at(j).at(1).size();a++)
                cout<<current_partition.at(j).at(1).at(a)<<" ";
            cout<<'\n';
            cout<<"move: "<<current_snp_movement.at(j)<<endl;
            cout<<"econde: "<<encode_on_cur_partition.at(j)<<endl;
            j++;
        }
        
        // put two partition together
        map_key.clear();
        snp.assemble(encode_on_cur_partition_inverse,encode_on_pre_partition_inverse,current_partition,previous_partition,current_snp_movement,previous_snp_movement);
        cout<<"P"<<endl;
        j=0;
        while( j < snp.reads_on_SNP.at(snp.all_snp.at(iterator-1)).size()+1){
            cout<<j<<endl;
            cout<<"0: ";
            for(int a=0;a<previous_partition.at(j).at(0).size();a++)
                cout<<previous_partition.at(j).at(0).at(a)<<" ";
            cout<<'\n';
            cout<<"1: ";
            for(int a=0;a<previous_partition.at(j).at(1).size();a++)
                cout<<previous_partition.at(j).at(1).at(a)<<" ";
            cout<<'\n';
            cout<<"move: "<<previous_snp_movement.at(j)<<endl;
            cout<<"econde: "<<encode_on_pre_partition.at(j)<<endl;
            j++;
        }
        
        

        if(iterator == 1)
            break;
        
        previous_partition = current_partition;
        encode_on_pre_partition = encode_on_cur_partition;
        previous_snp_movement = current_snp_movement;
        previous_smae = next_same;
        iterator++;
    }

    return 0;
}
