# T-OS
**An Open Source Operating System:** <br />
*To build you will need Linux or WSL with the next packages:* <br />
***-NASM*** <br />
***-QEMU*** <br />
***-GCC*** <br />
***-LD*** <br />
*Once the packages are installed run `Build.sh`* <br />
**Now run qemu: `qemu-system-i386 -kernel bin/Kernel.bin`**

## Project Structure:
```path
+ T-OS
|- bin (Last Generated Kernel)
|- src (Directory containing all the src)
|- Build.sh (Build Script)
|- README.md (This document)
|- LICENSE (IGNORE)
```
```
+ src
|- boot (Contains Bootloader src)
|- Kernel (All Kernel source)
|- Link.ld (Linker)
```
```
The 'old-ref' directory contains old versions sources
```

## Origins of T-OS
**T-OS is a side project to get a Bootloader in Assembly and a Kernel written in C** <br />
**T-OS originally was called c-OS (Custom - OS)**
