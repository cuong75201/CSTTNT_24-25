#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>
 int main(){
    FILE *f = fopen("Johnsona.txt","rt");
    int n;
    fscanf(f,"%d ",&n);
    std::vector<int> timeM1(n,0);
    std::vector<int> timeM2(n,0);

    for (int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            if(i==0)  fscanf(f,"%d ",&timeM1[j]);
            if(i==1)  fscanf(f,"%d ",&timeM2[j]);
        }
    }
    std::vector<int> group1;
    std::vector<int> group2;
    for(int i=0;i<n;i++){
        if(timeM1[i]<=timeM2[i]) group1.push_back(i);
        else group2.push_back(i);

    }
    sort(group1.begin(),group1.end());
    sort(group2.begin(), group2.end(), std::greater<int>());
    std::vector<int> sequence;
for (auto i : group1) sequence.push_back(i);
for (auto i : group2) sequence.push_back(i);
for(int i=0;i<n;i++){
    std::cout<<sequence[i]<<" ";
}
}