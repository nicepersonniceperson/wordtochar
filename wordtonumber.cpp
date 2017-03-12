#include "iostream"
#include "string"
#include "fstream"

using namespace std;

int main(){
string word;
ifstream ifile;
ifstream rofile;
ofstream wofile("number.txt", ios_base::app);
ofstream efile("wordn.txt");
rofile.open ("number.txt");
ifile.open ("word.txt");
int x=0;
while (rofile >> word) x++;
cout << x << '\n';
if (x>127)
{
        cout << "لم تنجح فأقصى عدد للكلمات 128" << '\n';
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
rofile.clear();
rofile.seekg(0, rofile.beg);
x=0;
int found;
while (ifile >> word)
{
        found=0;
        for( int a = 0; a < sizeof(oarray)/sizeof(oarray[0]); a = a + 1 )
        {
                if ( word == oarray[a] )
                {
                        found=1;
                        break;
                }
        }
        if (found == 0)
        {
                x++;
        }
}
cout << x << ": عدد الكلمات الجديدة" << '\n';
cout << "عدد الكلمات القديمة:" << sizeof(oarray)/ sizeof(oarray[0]) << "\n";
if (x>127-sizeof(oarray)/sizeof(oarray[0]))
{
        cout << "لم تنجح حيث أن أقصى عدد للكلمات 128" << '\n';
        exit(1);
}

string noarray[x];

ifile.clear();
ifile.seekg(0, ifile.beg);
x=0;
found=0;
while (ifile >> word)
{
        found=0;
        for( int a = 0; a < sizeof(oarray)/sizeof(oarray[0]); a = a + 1 )
        {
                if ( word == oarray[a] || word == "" )
                {
                        found=1;
                        break;
                }
        }
        if (found == 0)
        {
                noarray[x]=word;
                x++;
        }
}

ifile.clear();
ifile.seekg(0, ifile.beg);

for( int a = 0; a < sizeof(noarray)/sizeof(noarray[0]); a = a + 1 )
{
        wofile << noarray[a] << "\n";
}

char c;

ifile.clear();
ifile.seekg(0, ifile.beg);
while (ifile >> word)
{
        for( int a = 0; a < sizeof(oarray)/sizeof(oarray[0]); a = a + 1 )
        {
                if ( word == oarray[a] )
                {
                        c = 'A' - 65 + a;
                        efile << c;
                        break;
                }
        }
        for( int a = 0; a < sizeof(noarray)/sizeof(noarray[0]); a = a + 1 )
        {
                if ( word == noarray[a] )
                {
                        c = 'A' - 65 + a +sizeof(oarray)/sizeof(oarray[0]);
                        efile << c;
                        break;
                }
        }
}
}
