source init.gdb

set confirm off

echo #### BOOTLOADER ####\n
load build/bootloader/bootloader.elf
echo #### EPICARDIUM ####\n
load build/epicardium/epicardium.elf
echo #### PYCARDIUM ####\n
load build/pycardium/pycardium.elf
reset
quit
