@echo off

rem ..\x64\Release\win32\kd.exe 

cd ..

echo select vdisk file="%cd%\carbon_os.vhd">dp
echo attach vdisk>>dp
diskpart /s %cd%\dp

cd x64\Release

copy *.sys D:\system\*.sys
copy *.dll D:\system\*.dll
copy .\symbols\*.pdb D:\system\symbols\*.pdb
copy ..\..\assets\system\*.* D:\system\*.*

cd ..
cd ..

echo select vdisk file="%cd%\carbon_os.vhd">dp
echo detach vdisk>>dp
diskpart /s %cd%\dp

del dp

start .\x64\Release\win32\kd.exe

rem -accel hax 
rem qemu-system-x86_64 -s -m 1024 -cpu core2duo -smp 2 -no-reboot -no-shutdown -monitor stdio -drive id=disk,if=none,format=raw,media=disk,file="%cd%\..\carbon_os.vhd" -device ahci,id=ahci -device ide-drive,drive=disk,bus=ahci.0


rem qemu-system-x86_64 -s -m 1024 -cpu core2duo -smp 2 -no-reboot -no-shutdown -monitor stdio -vga vmware -accel hax -drive format=raw,media=disk,file="%cd%\carbon_os.vhd"

rem del /s /q "..\carbon_os.vhd.lock"
rem "I:\win_old\Chris\Downloads\bochs-master\bochs-master\bochs\obj-release\bochs.exe" -f bochsrc.bxrc 

