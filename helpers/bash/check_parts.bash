#!/bin/bash
main() {
	case "$1" in 
		"blk" | "block")
		lsblk 
		;;
		"mnt" | "mount")
		echo "mnt hit"
		findmnt
		;;
	*)
		echo "Default arg"
		;;
	esac
}


main $1
