all:
	cd shell && make
	cd linux && make -j 20
	@if [ ! -d setup ]; then \
		mkdir -p setup; \
	fi
	cp linux/arch/x86/boot/bzImage setup/bzImage
	cp shell/shell init
	echo init | cpio -o -H newc > setup/init.cpio
	chmod +r setup/bzImage setup/init.cpio
	chmod +r setup/init.cpio
	qemu-system-x86_64 -kernel setup/bzImage -initrd setup/init.cpio -serial stdio



kernel-menu-config:
	cd linux && make menuconfig


clean:
	rm -rf setup
	rm init
	cd shell && make clean

clean-all:
	rm -rf setup
	rm init
	cd linux && make clean
	cd shell && make clean