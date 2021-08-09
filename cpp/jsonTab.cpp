#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ifstream src("C:\\Users\\galax\\Desktop\\luna16.json");
    ofstream dst("C:\\Users\\galax\\Desktop\\luna16new.json");

    string getall;
    getline(src, getall);

    string space = "    ";
    size_t count_of_space = 0;
    size_t n = getall.size();
    bool inmark = false;
    for (size_t i = 0; i < n; ++i){
        char c = getall[i];
        if (c < 1)break;
        //printf("%c[%d/%d]\n", c, i, n);
        if (c == '\"'){
            inmark = !inmark;
        }
        if (inmark){
            dst << c;
            continue;
        }
        switch (c){
        case '[':
        case '{':
            count_of_space += 1;
            dst << c << '\n';
            for (size_t j = 0; j < count_of_space; ++j)dst << space;
            break;
        case ']':
            count_of_space -= 1;
            if (count_of_space < 0)count_of_space = 0;
            dst << '\n';
            for (size_t j = 0; j < count_of_space; ++j)dst << space;
            dst << ']';
            if (i + 3 < n){
                if (getall[i + 1] != ','&&getall[i + 2] != ',')dst << '\n';
            }
            break;
        case '}':
            count_of_space -= 1;
            if (count_of_space < 0)count_of_space = 0;
            dst << '\n';
            for (size_t j = 0; j < count_of_space; ++j)dst << space;
            dst << '}';
            if (i + 3 < n){
                if(getall[i + 1] != ','&&getall[i + 2] != ',')dst << '\n';
            }
            break;
        case ',':
            dst << ',';
        case '\n':
            dst << '\n';
            if (count_of_space < 0)count_of_space = 0;
            for (size_t j = 0; j < count_of_space; ++j)dst << space;
            break;
        default:
            dst << c;
            break;
        }
    }

    return 0;
}