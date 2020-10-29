#include "core.h"
void core::read(){
    ifstream f;
    f.open("test.txt", ios::in);
    int count = 0;
    int n = 76;
    string s;
    count = 0;
    while (getline(f, s))
    {
        while (s.find_first_of(',') != string::npos)
        {
            size_t index = s.find_first_of('[');
            size_t ind2 = s.find_first_of(',');
            string child;
            child.clear();
            child.assign(s, index + 1, ind2 - index - 1);
            all_snp.push_back(child);
            link temp;
            temp.read_name = count;
            s.erase(index, ind2 - index + 1);
            index = s.find_first_of('(');
            temp.value = s.at(index + 1);
            s.erase(index, 1);
            //s.erase(s.find_first_of(','), 1);
            index = s.find_first_of(',');
            ind2 = s.find_first_of(')');
            string cost ;
            cost.assign(s, index + 1, ind2 - index - 1);
            temp.cost = stoi(cost);
            //cout<<temp.cost<<endl;
            s.erase(s.find_first_of(','), 1);
            s.erase(s.find_first_of(')'), 1);
            if (reads_on_SNP.find(child) == reads_on_SNP.end())
            {
                //cout<<child<<endl;
                vector<link> reads;
                reads.push_back(temp);
                reads_on_SNP.insert(pair<string, vector<link>>(child, reads));
            }
            else
                reads_on_SNP.at(child).push_back(temp);
        }
        count++;
        f.get();
        if (count == n)
            break;
    }
}