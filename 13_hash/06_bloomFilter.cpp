#include <iostream>
using namespace std;

bool bloomFilter[10000];
int hash1(string);
int hash2(string);
int numHash = 2;
int (*hashes[2])(string) = {hash1, hash2};

int hash1(string x){
    return (int)x.length();
}
int hash2(string x){
    int ascii = (int)x[0];
    int ans = 0;
    if(65 <= ascii && ascii <= 90){
        ans = ascii - 65;
    }
    if(97 <= ascii && ascii <=122){
        ans = ascii - 97;
    }
    return ans;
}

void insertInBloomFilter(string x){
    for(int i=0; i<numHash; i++){
        bloomFilter[hashes[i](x)] = true;
    }
}

bool isInBloomFilter(string x){
    for(int i=0; i<numHash; i++){
        int hash = hashes[i](x);
        if(!bloomFilter[hash]){
            return false;
        }
    }
    return true;
}
void showBloomFilter(int size){
    for(int i=0; i<size; i++){
        cout << bloomFilter[i] << " ";
    }
    cout << endl;
}

int main(){
    insertInBloomFilter("element");
    showBloomFilter(10);
    cout << isInBloomFilter("elected") << " " << isInBloomFilter("what is it") << endl;
    return 0;
}