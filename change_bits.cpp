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

void core::change_bits(string &encode,const map<string ,int> &current_table,const map<string ,int> &previous_table,int &move ){
    int min = 16;
    int cost = 16;
    string mew_encode;
   for(auto const& imap: previous_table){
       string temp = imap.first;
       
       int diff =0;
       for (unsigned i = 0; i < encode.size(); i++ ) {
            if (encode[i] != temp[i]) {
                diff++;
            }   
        } 
        if(diff <= min){
            if(diff == min){
                if(cost>previous_table.at(temp)){
                    min = diff;
                    cost = previous_table.at(temp);
                    mew_encode = temp;
                }
            }
            else {
                min = diff;
                cost = previous_table.at(temp);
                mew_encode = temp;
            }
        }  
   }
   cout<<toInt(encode)<<" "<<toInt(mew_encode)<<"---"<<cost+min<<endl;
   move = cost+min;
  
}