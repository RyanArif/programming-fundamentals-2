#include <iostream>
#include <string>

using namespace std;

class Month{
    private:
        int num;
        string monthName[12] = {
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December"
        };
    public:
        Month()
        {
            num = 0;
        }
        Month(int i)
        {
            num = i;
        }

        void setNum(int i){ num = i; }
        void setName(string s)
        {
            bool numFound = false;
            for(int i = 0; i < 12; i++){
                if (s == monthName[i]){
                    num = i+1;
                    numFound = true;
                }
            }
            if (!numFound){
                num = 0;
            }
        }

        int getNum(){ return num; }
        string getName(){
            if (num > 12 || num < 1){
                return "Unknown";
            }else{
                return monthName[num-1];
            }
        }
        //overload

        friend ostream &operator << (ostream &, const Month &);
        friend istream &operator >> (istream &, Month &);
};

ostream & operator << (ostream &strm, const Month &obj)
{
    return strm << obj.monthName[obj.num-1];
}

istream& operator>> (istream &in, Month &m)
{
    return in >> m.num;
}

int main()
{
    string monthArr[12] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    
    Month monObj;
    cout << "Enter: month number (1-12):";

    cin >> monObj;

    cout << "The next 8 months are: ";
    for (int i = 0; i < 8; i++){
        int j = monObj.getNum() - 1;
        if( (j + i) >= 12 ){
            j = j - 12;
        }
        cout << monthArr[i+j];
        if (i != 7){
            cout << ", ";
        }else{
            cout << ". ";
        }
    }

    cout << "Enter: another month number (1-12):";
    cin >> monObj;

    cout << "The previous 8 months were: ";
    for(int i = 0; i < 8; i++){
        int j = monObj.getNum() -1;
        if ((j - i) < 0){
            j = 12 + j;
        }
        cout << monthArr[j - i];
        if(i != 7){
            cout << ", ";
        }else{
            cout << ". ";
        }
    }

    return 0;
}
