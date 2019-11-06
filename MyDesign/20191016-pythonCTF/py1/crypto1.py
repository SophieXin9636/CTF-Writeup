#!/usr/bin/python3
# -*- coding: utf-8 -*-
from pwn import *
context(arch = 'i386', os = 'linux')

p = process('crypto1')

for i in range(10):
	s = p.recvuntil("=", drop = True).decode() # return string
	p.recvline()
	p.sendline(str(eval(s)))

print(p.recv().decode())
p.close()