#include "core.h"
// flag is to control build table mode
void core::build_table(int now,const vector<int> same,const map<int, bipartition> current_partition, map<string ,int> &table,map<int, int> &current_snp_movement,map<int,string> &encode_on_partition , map<string, int> &encode_on_partition_inverse){
    string snp_pos = all_snp.at(now);
    int i =0;
    cout<<"size "<<(current_partition.at(0).at(0).size())<<"  "<<(current_partition.at(0).at(1).size())<<endl;
    while (i < current_partition.size()){
        cout<<i<<endl;
        unsigned int record = 0;
        int init;
        string temp;temp.clear();
        int a=0,b=0;
        while(a <current_partition.at(i).at(0).size() && b <current_partition.at(i).at(1).size()){
            //cout<<"a "<<a<<" b "<<b<<endl;
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
                //cout<<temp<<endl;
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
                //cout<<temp<<endl;
                b++;
            }
        }
        while (a < current_partition.at(i).at(0).size()){
            //cout<<"a "<<a<<" b "<<b<<endl;
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
            //cout<<temp<<endl;
            a++;
        }
        while (b < current_partition.at(i).at(1).size()){
            //cout<<"a "<<a<<" b "<<b<<endl;
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
            //cout<<temp<<endl;
            b++;
        }
        cout<<temp<<endl;
        make_encode(encode_on_partition,encode_on_partition_inverse,current_snp_movement,i,temp);
        int movement_count = 0;
        if(i != 0)
            movement_count += 1;

        table.insert(pair<string, int>(temp,movement_count));

        i++;
    }
    
}