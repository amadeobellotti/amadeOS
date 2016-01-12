#!/bin/sh
set -e
. ./iso.sh

qemu-system-$(./target-triplet-to-arch.sh $HOST) -cdrom amadeos.iso -d cpu_reset -D ./qemu.log
