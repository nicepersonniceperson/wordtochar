#include "iostream"
#include "string"
#include "fstream"

using namespace std;

int main(){
string word;
ifstream ifile;
ifstream rofile;
ofstream wofile("number.txt", ios_base::app);
ofstream efile("wordx.txt");
rofile.open ("number.txt");
ifile.open ("wordn.txt");
int x=0;
while (rofile >> word) x++;
if (x>127)
{
        cout << "big file" << '\n';
        exit(1);
}
string oarray[x];
x=0;
rofile.clear();
rofile.seekg(0, rofile.beg);
while (rofile >> word)
{
        oarray[x]=word;
        x++;
}
char c;
char character;
while (ifile >> noskipws >> character)
{
        for( int a = 0; a < sizeof(oarray)/sizeof(oarray[0]); a = a + 1 )
        {
                if ( character == a )
                {
                        cout << oarray[a] << " ";
                        break;
                }
        }
}
cout << "\n";
}
