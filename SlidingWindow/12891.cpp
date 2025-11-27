#include <iostream>
#include <string>
using namespace std;

int dnaIndex(char c){
    switch(c) {
        case 'A' : return 0;
        case 'C' : return 1;
        case 'G' : return 2;
        case 'T' : return 3;
    }
    return -1;
}

void updateCnt(int cnts[], char dna, int delta){
    int idx = dnaIndex(dna);
    if(idx != -1) cnts[idx] += delta;
}

int check(int cnts[], int needs[]){
    if(cnts[0] >= needs[0] && cnts[1] >= needs[1] && cnts[2] >= needs[2] && cnts[3] >= needs[3]){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int S, P;
    cin >> S >> P;

    string dna;
    cin >> dna;

    int needs[4] = {0}, cnts[4] = {0};
    for(int i=0; i<4; ++i) { cin >> needs[i]; };
    
    int ans = 0;

    for(int i=0; i<P; ++i) { updateCnt(cnts, dna[i], +1); };
    
    ans += check(cnts, needs);

    for(int i=P; i<S; ++i){
        updateCnt(cnts, dna[i-P], -1);
        updateCnt(cnts, dna[i], +1);
        ans += check(cnts, needs);
    }

    cout << ans << "\n";

    return 0;
}