#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class base // parent
{
    protected:
        int i;

    public:
        base(int x)
        {
            i = x;
            cout << "Constructing base.\n";
        }
        ~base(void) { cout << "Destructing base.\n"; } // free up memory

        void setI(int j){ i = j;}
        int getI() const {return i;}
};

class derived : public base // child
{
    int j;

    public:
        derived(int x, int y) : base(y)
        { // use of initializer list
            j = x;

            cout << "Constructing derived.\n";
        }
        ~derived(void) { cout << "Destructing derived.\n"; } // free up memory
        void show(void) { cout << i << ", " << j << endl; }

        void setJ(int k){j = k;}
        int getJ() const {return j;}
};

class Shape{
    protected:
        string name;
        double perimeter;
        double surfaceArea;

    public:
        Shape()
        {
            cout << "\nParent Shape Default Constructor Called " << endl;
            string name = "Initial Name";
            perimeter = 0.0;
            surfaceArea = 0.0;
        }

        void setName(string s) { name = s; }
        void setPerimeter(double d) { perimeter = d; }
        void setSurfaceArea(double d) { surfaceArea = d; }

};

class RectangleShape: public Shape{
    private:
        double length;
        double width;
    public:
        RectangleShape()
        {
            cout << "\nBase Rect Default Constructor Called." << endl;
            length = 0.0;
            width = 0.0;
        }
        void setLength(double d) {length = d;}
        void setWidth(double d) {width = d;}
        double getPerimeter()
        {
            return 2.0*(length+width);
        }
        double getArea()
        {
            return (length * width);
        }

        string getName() const{return name;}
        double getLength() const {return length;}
        double getWidth() const {return width;}
        void drawShape(){
            cout << "\nDrawing for: " << name << endl;

            for(int i=0; i < width; i++){
                for(int j=0; j < length; j++){
                    cout << "*";
                }
                cout << endl;
            }
        }

        //alternatively, overload the extraction operator to draw the shape
        //now it can be used with more than just cout.
        friend ostream& operator<<(ostream&, const RectangleShape&);

};
ostream& operator<<(ostream& strm, const RectangleShape& rs)
{
    strm << "\nDrawing for: " << rs.name << endl;
    for (int i = 0; i < rs.width; i++){
        for (int j = 0; j < rs.length; j++){
            strm << "*";
        }
        strm << endl;
    }

    return strm;
}


int main(void)
{
    derived object(3, 4);

    object.show();

    RectangleShape rect;

    double userInput = 0.0;
    cout << "\n\n*********Rectangle Program*********" << endl;

    rect.setName("Rectangle_1");

    cout << "Can I have a width for the rectangle pls ";
    cin >> userInput;
    rect.setWidth(userInput);

    cout << "Can I have a length for the rectangle please? ";
    cin >> userInput;
    rect.setLength(userInput);

    ofstream outfile;
    outfile.open("Rectangle.txt");
    if(outfile){
        outfile << rect;
    }
 
    outfile.close();

    cout << rect;
    //system("cat Rectangle.txt"); //conCATonate the file to the terminal

    return 0;
}
