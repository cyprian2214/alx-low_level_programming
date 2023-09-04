#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUFSIZE 64

void display_elf_header_info(int fd) {
    Elf64_Ehdr header;
    int i; /* Declare i outside of the for loop in C90 mode */

    /* Read the ELF header into the 'header' structure */
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        dprintf(STDERR_FILENO, "Error: Unable to read ELF header\n");
        exit(98);
    }

    /* Check if the file is an ELF file */
    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3) {
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        exit(98);
    }

    /* Display the ELF header information */
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n",
           header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
           header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Unknown");
    printf("  Data:                              %s\n",
           header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
           header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "Unknown");
    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %d\n", header.e_ident[EI_OSABI]);
    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              %d\n", header.e_type);
    printf("  Entry point address:               %lx\n", header.e_entry);
}

int main(int argc, char *argv[]) {
    int fd; /* Declare fd at the beginning of the function */

    if (argc != 2) {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    fd = open(argv[1], O_RDONLY); /* Declare and initialize fd separately */
    if (fd == -1) {
        perror("Error");
        return 98;
    }

    display_elf_header_info(fd);
    close(fd);
    return 0;
}
