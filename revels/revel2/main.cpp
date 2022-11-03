#include <iostream> //cin, cout
#include <fstream> //file stream
#include <string>
#include <vector> //vectos
using namespace std;

int main()
{
    ifstream charFile, posFile;
    charFile.open("chars.txt");
    posFile.open("pos.txt");

    vector<int> posArr;
    vector<char> charArr;

    while(posFile){
       int pos = 0;
       posFile >> pos;
       if(!posFile) break;
       posArr.push_back(pos);
   };
    posFile.close();

    while(charFile){
        char ch = '\0';
        charFile.get(ch);
        charArr.push_back(ch);
    };
    charFile.close();

    for(int pos : posArr){
        if(!((pos < 0) || (pos > charArr.size()))){
            cout << charArr[pos] << endl;
        }
    }

    return 0;
}
