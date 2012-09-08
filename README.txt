Print Reverse System Call
CS3210: Operating Systems
Phil Oliver
Reid Harrison

Begin by extracting the archive, placing the printcall folder and the Makefile in the base directory of the linux kernel. The syscall_table_32.S file belongs in
	
	linux-2.6.24.6/arch/x86/kernel/syscall_table_32.S
	
while unistd_64.h goes in the directory
	
	/linux2.6.24.6/include/asm-x86

The module for the print call should be in /linux2.6.24.6/printcall. The system call can be modified through printcall.c

Next the kernel needs to be built:

	In /linux2.6.24.6
	run sudo make

Then the modules need to be compiled:

	sudo make modules
	
Then the modules must be installed:

    sudo make modules_install

Finally, the kernel must be installed:

    sudo make install

Add an entry to the grub config so we can choose to boot into our new kernel:

	title CS3210 DIS HACK (2.6.24.6)
        root (hd0,0)
        kernel /vmlinuz-2.6.24.6-myProj ro
        initrd /initrd-2.6.24.6-myProj.img

Now, reboot the kernel:

    sudo reboot

When the kernel is back up, use vncviewer to select the kernel. The one we're using is titled "DIS HACK"
Next, proceed to the printtest directory from the archive. Make...
And run the executable by typing:

	./printtest"SOME PHRASE"
	
Where SOME PHRASE can be any string that does not contain special characters.

The input's reverse will be printed.
