#include <iostream> 
#include <fstream> 
using namespace std;
int main () {

ifstream sonl ("bai1.cpp", ifstream::binary);
ofstream son2 ("bai11.cpp", ofstream::binary);
if(sonl) {
sonl.seekg(0, sonl.end);
int length = sonl. tellg() ;
sonl.seekg (0, sonl. beg) ;

char * buffer = new char [length];
sonl. read (buffer, length) ; 
for (int i=0;i<length;i++)
buffer[i] = (buffer[i]-4);
son2. write (buffer, length) ; 
delete [] buffer;


}
sonl.close();
son2.close();
remove("bai1.cpp");
return 0;
}
