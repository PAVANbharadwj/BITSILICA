#include <stdio.h>
#include <stddef.h>  
struct NormalStruct {
    char a;     
    int b;      
    short c;    
};
struct OptimizedStruct {
    int b;      
    short c;    
    char a;     
};
#pragma pack(1)
struct PackedStruct {
    char a;     
    int b;      
    short c;    
};
#pragma pack()
#pragma pack(1)
struct Packet {
    char startByte; 
    short id;       
    char data[4];   
    char checksum;  
};
#pragma pack()

int main() {
    printf("----- Normal Struct -----\n");
    struct NormalStruct n;
    printf("Size: %zu\n", sizeof(n));
    printf("Offset of a: %zu\n", offsetof(struct NormalStruct, a));
    printf("Offset of b: %zu\n", offsetof(struct NormalStruct, b));
    printf("Offset of c: %zu\n", offsetof(struct NormalStruct, c));
    printf("\n----- Optimized Struct -----\n");
    struct OptimizedStruct o;
    printf("Size: %zu\n", sizeof(o));
    printf("Offset of b: %zu\n", offsetof(struct OptimizedStruct, b));
    printf("Offset of c: %zu\n", offsetof(struct OptimizedStruct, c));
    printf("Offset of a: %zu\n", offsetof(struct OptimizedStruct, a));
    printf("\n----- Packed Struct (#pragma pack(1)) -----\n");
    struct PackedStruct p;
    printf("Size: %zu\n", sizeof(p));
    printf("Offset of a: %zu\n", offsetof(struct PackedStruct, a));
    printf("Offset of b: %zu\n", offsetof(struct PackedStruct, b));
    printf("Offset of c: %zu\n", offsetof(struct PackedStruct, c));
    printf("\n----- Communication Packet Struct -----\n");
    struct Packet pkt;
    printf("Size: %zu\n", sizeof(pkt));
    printf("Offset of startByte: %zu\n", offsetof(struct Packet, startByte));
    printf("Offset of id: %zu\n", offsetof(struct Packet, id));
    printf("Offset of data: %zu\n", offsetof(struct Packet, data));
    printf("Offset of checksum: %zu\n", offsetof(struct Packet, checksum));

    return 0;
}