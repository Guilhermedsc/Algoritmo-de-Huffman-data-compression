#include "ftab.h"
#include <fstream>

ftab::ftab(const char* filename, char *comando) {   
    for(int i=0; i<256; i++){
        tab[i].first = 0;
        tab[i].second = 0;
    }
    cmd = comando;

    if(cmd == "COMPACTAR"){     //----------------compactar-----------------//
        FILE* file = fopen(filename, "rb");

        mychar c{0};
        while(!feof(file)){
            fread(&c, sizeof(mychar), 1, file);
            tab[c].first = c;
            tab[c].second++;
        }
        fclose(file);
        this->BubbleSort();

    }else{                     //----------------descompactar-----------------//
        ifstream file3(filename, ios::binary);
        string TT;
        string t;

        while(getline(file3, TT) && TT != "fim"){
            t+=TT+'\n';
        }

        unsigned char carac=0;
        int n=0, cont=0;
        for(int i = 0; i < (int)t.size(); i++){
            if(t[i]== ' ' && t[i+1]== ' '){
                tab[cont].first = ' ';
                tab[cont].second = atoi(t.substr(i+2, t.size()).c_str());
                i+=n+2;
                cont++;

            }else if(t[i] == ' '){
                tab[cont].first = t[i-1];
                tab[cont].second = atoi(t.substr(i+1, t.size()).c_str());
                cont++;
            }
        } 
        file3.close();
    }
}

void ftab::BubbleSort(){
    if(cmd == "COMPACTAR"){     //----------------compactar-----------------//
        for (int i = 255; i > 0; i--){
            for (int j = 0; j < 255; j++){
                if (this->tab[j].second > this->tab[j + 1].second){
                    std::swap(this->tab[j], this->tab[j + 1]);
                }
            }
        }
    }
}

myint ftab::operator[](unsigned char k) {
    for(int i = 0; i < 256; i++){
        if(this->tab[i].first == k){
            return this->tab[i].second;
        }
    }
    return 0;       
}

void ftab::print(){
    for(int i = 0; i < 256; i++){
        if(this->tab[i].second > 0){
            std::cout << i << " " << this->tab[i].first << " " << this->tab[i].second << std::endl;
        }
    }
}