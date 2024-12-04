# Hey! I'm Filing Here

In this lab, I successfully implemented the following:
1. A file system with two directories with a file
2. A symlink to the file
3. Inodes
4. Data Blocks

## Building

TODO
Build using the make command

## Running

The steps to run are shown below, (From the Spec):
1. ./ext2-create
2. mkdir mnt
3. sudo mount -o loop cs111-base.img mnt
4. ls -ain /mnt

This is my output shown below

total 8
1048578 drwxr-xr-x  2 0 0 4096 Jan 18  2021 .
      2 drwxr-xr-x 18 0 0 4096 Sep 27  2021 ..


## Cleaning up

Run these steps to clean up, (Also from the spec):
1. sudo umount mnt
2. rmdir mnt
3. make clean

