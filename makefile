all:
	cd linux && make -j 20
	cd qminit && cmake . && make
	cd shell && cmake . && make
	cd qve && cmake . && make

	@if [ ! -d setup ]; then \
		mkdir -p setup; \
	fi
	rm -rf setup/bin
	mkdir setup/bin
	cp linux/arch/x86/boot/bzImage bzImage
	cp shell/shell setup/bin/shell
	cp qve/qve setup/bin/qve
	cp qminit/init setup/init
	cd setup && find . | cpio -o -H newc > ../init.cpio
	chmod +r bzImage init.cpio
	qemu-system-x86_64 -kernel bzImage -initrd init.cpio -serial stdio



kernel-menu-config:
	cd linux && make menuconfig


clean:
	rm -rf setup
	cd shell && make clean
	cd qminit && make clean
	cd qve && make clean
	rm bzImage
	rm init.cpio
	


clean-all:
	rm -rf setup
	cd linux && make clean
	cd shell && make clean
	cd qminit && make clean
	cd qve && make clean
	rm bzImage
	rm init.cpio

