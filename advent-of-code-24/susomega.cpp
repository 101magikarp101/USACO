#include <iostream>
#include <cstring>
class MyClass {
private:
    int MyClassValue;

public:
    MyClass(int value) : MyClassValue(value) {}
};int o_53645e447a554c6f165b7bacbbe4f7f4(MyClass* o_70fc42a183b507cc837f11ae1379c5d8){return *((int* )((char* )o_70fc42a183b507cc837f11ae1379c5d8 + sizeof(MyClass) - sizeof(int)));};int main(){MyClass* o_995aecdc220c563118cf533c43f6b31a=new MyClass(42);int o_0fda7130f53098e184ddf0bba7fcf4b5=o_53645e447a554c6f165b7bacbbe4f7f4(o_995aecdc220c563118cf533c43f6b31a);std::cout<<"\x56""a\154u\x65"":\040"<<o_0fda7130f53098e184ddf0bba7fcf4b5<<std::endl;char o_19ae6637f6f17502bb0905e88817a6ba[(0x0000000000000064 + 0x0000000000000232 + 0x0000000000000832 - 0x0000000000000A96)];strcpy(o_19ae6637f6f17502bb0905e88817a6ba,"\x48""e\154l\x6F"",\040W\x6F""r\154d\x21""");std::cout<<o_19ae6637f6f17502bb0905e88817a6ba<<std::endl;int* o_025b0e8b857612e5661b67caaec4892d;std::cout<<*o_025b0e8b857612e5661b67caaec4892d<<std::endl;return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);};