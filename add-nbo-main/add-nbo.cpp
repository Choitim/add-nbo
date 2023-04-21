
#include <stdio.h>
#include <stdint.h>


int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *f1 = fopen(argv[1], "rb");
    if (!f1) {
        printf("Failed to open %s\n", argv[1]);
        return 1;
    }

    FILE *f2 = fopen(argv[2], "rb");
    if (!f2) {
        printf("Failed to open %s\n", argv[2]);
        fclose(f1);
        return 1;
    }

    uint32_t n1, n2;
    fread(&n1, sizeof(uint32_t), 1, f1);
    fread(&n2, sizeof(uint32_t), 1, f2);

    uint32_t add1 = ntohl(n1);
    uint32_t add2 = ntohl(n2);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", add1, add1, add2, add2, add1 + add2, add1 + add2);

    fclose(f1);
    fclose(f2);

    return 0;
}
