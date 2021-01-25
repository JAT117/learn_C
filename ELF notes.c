ELF Notes

Executable and Linkable Format elf(5)

Commands to see section and headers
file a.out
readelf -h a.out
dumpelf
elfls -p /bin/ps
eu-readelf –section-headers /bin/ps
readelf -S /bin/ps
objdump -h /bin/ps
hd /usr/bin/touch | head -5

UNIX file utility

ulimit -S // see the max size of stack memory in linux 
ulimit -a // list all flags 
readelf -elf_file

ELF Header	
	32 bits long
	
	(45=E,4c=L,46=F), prefixed with 7f value

	Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00
	Class:                             ELF64
	Data:                              2's complement, little endian
	Version:                           1 (current)
	OS/ABI:                            UNIX - System V
	ABI Version:                       0
	Type:                              DYN (Shared object file)
	Machine:                           Advanced Micro Devices X86-64
	Version:                           0x1
	Entry point address:               0x1050
	Start of program headers:          64 (bytes into file)
	Start of section headers:          14688 (bytes into file)
	Flags:                             0x0
	Size of this header:               64 (bytes)
	Size of program headers:           56 (bytes)
	Number of program headers:         11
	Size of section headers:           64 (bytes)
	Number of section headers:         30
	Section header string table index: 29

ELF Sections- can bee seen with readelf -S	
		
	.text
		Contains executable code

	.data
		Initalized data with read/write access rights

	.rodata
		Initialized data, with read access rights only (=A)

	.bss
		Uninitalized data segment 
		"block started by the symbol"

https://linux-audit.com/elf-binaries-on-linux-understanding-and-analysis/
