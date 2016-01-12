#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/amadeos.kernel isodir/boot/amadeos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "amadeos" {
	multiboot /boot/amadeos.kernel
}
EOF
grub2-mkrescue -o amadeos.iso isodir
