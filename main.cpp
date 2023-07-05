#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main() {    
    FILE *fp;
    uint8_t network_buffer[4];
    uint32_t *ptr;
    uint32_t num1,num2;

    fp = fopen("thousand.bin", "rb");
    fread(network_buffer, sizeof(uint8_t), 4, fp);
    ptr = reinterpret_cast<uint32_t*>(network_buffer);
    num1 = htonl(*ptr);
    fclose(fp);

    fp = fopen("five-hundred.bin","rb");
    fread(network_buffer, sizeof(uint8_t), 4, fp);
    ptr = reinterpret_cast<uint32_t*>(network_buffer);
    num2 = htonl(*ptr);
    fclose(fp);

    printf("%d + %d = %d",num1,num2,num1+num2);
}

