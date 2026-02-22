# AOS - LeArning Operating System

AOS is a project with minimal configuration and optimization aimed at learning how an operating system works. This project is based on the RISC-V architecture and uses C and Assembly languages.

This project is expected to serve as a framework for the repository owner in developing skills in IoT and Embedded Systems as well as other future projects.

## Purpose
This project will study how ... works
1. Bootloader
2. Hardware Abstraction
3. Layers of Operating System
4. Task Scheduler
5. Memory Management
6. I/O Management

## Environment
I use Windows Subsystem For Linux with NixOS Distribition as main system.
Here are the packages related to this development:
```
environment.systemPackages = with pkgs; [
  gnumake # Makefile 
  spike   # RISC-V Emulator
  dtc     # Device Tree Compiler
  ]
```
In addition, it is necessary to use flake to enable riscv64-none-elf-gnu with command
```bash
nix develop
```
