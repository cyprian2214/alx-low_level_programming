#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

/**
 * ELF Header Information Retrieval Program
 *
 * This program reads and displays information from the ELF header of an ELF file.
 * It displays information such as the ELF magic number, class, data format, version,
 * OS/ABI, ABI version, file type, and entry point address.
 */

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void print_elf_header_info(Elf64_Ehdr *header) {
    unsigned int i;

    printf("Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
    printf("Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little-endian" : "Unknown data format");
    printf("Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
    printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type:                              %d\n", header->e_type);
    printf("Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[]) {
    const char *elf_filename;
    Elf64_Ehdr header;
    int fd;

    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    elf_filename = argv[1];
    fd = open(elf_filename, O_RDONLY);
    if (fd == -1) {
        print_error(strerror(errno));
    }

    if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
        print_error("Failed to read ELF header");
    }

    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    print_elf_header_info(&header);

    close(fd);
    return 0;
}
