N=2
AB
CC
--------------------------
Cost[2] = 1
__________________________



N=4
AABB [From 2]
ACCB 
BBCB
BAAB
CCCC
------------------Cost(2)+Cost(2)+4 = 1+1+4
Cost[4] = 6
___________________________________________



N=5
AAAAB [From 4+2]
AAACC
AABBC
ACCBC
BBCBC		
BAABC
CCCCC
----------------------------------------
5:: 1+6+5
Cost[5] = 12
___________________________________________

CCAAA
CBBAA
CBCCA
CBCBB
CBAAB
CCCCC


N=8
AAAABBBB [From 4+From 4]
AAACCBBB
AABBAABB
CCCCCCCC [4 + 4 What to apply on First Half, apply on Second Half]

--------------------------------------------
8:: Cost(4)+Cost(4)+2+Cost(4)+Cost(4) = 6+6+2+6+6
Cost[8] = 26
____________________________________________


N=10
AAAAAAAABB [From 8+4]
AAAAAAACCB
AAAAAAACAA
AAAAAABBAA
AAAAACCBAA
AAAABBCBAA
AAAABBAAAA 
CCCCCCCCCC [5+5 What you apply on first Half, apply the reverse on Second Half]

--------------------------------------------------------------
10 :: Cost(4) + Cost(8) + 6 + Cost(5) + Cost(5) = 6+26+6+12+12
Cost[10] = 62
___________________________________________________



N=11

AAAAAAAAAAB [From 10]
AAAAAACCCCC	[From 5]
AAAAABBCCCC
AAAACCBCCCC
AAAACAACCCC
AAAABBACCCC
AAAABCCCCCC
CCCCCCCCCCC [From 5 AAAAB]

------------------------------------------------------
11 :: Cost(10)+Cost(5) +5+ Cost(5) = 62+12+5+12
Cost[11] = 91
______________________________________________________

N=13

AAAAAAAAAAABB [4+10]
AAAAAAAAAACCB
AAAAAAAAAACAA
AAAAAAAAAABBA
AAAAAAAAAABCC 
CCCCCCCCCCCCC [Apply 11 from 1 to 11 bits +CC]

--------------------------------------------------------
Cost(4) + Cost(10)+4+Cost(11) = 6+62+91
Cost[13] = 160
________________________________________________________


N=16

AAAAAAAAAAAAABBB [From 10+4]
AAAAAAAAAAAACCBB 
AAAAAAAAAAAACAAB
AAAAAAAAAAAACACC
AAAAAAAAAAAABBAB
AAAAAAAAAAACCCCB [From 5]
AAAAAAAAAAAAAAAA

---------------------------------------------------------
Cost(4) + Cost(10) + 4 + Cost(5) + 1 = 6+62+12+1
Cost[16] = 81
____________________________________________________________


N=20
AAAAAAAAAAABBBBBBBBB [11+11 First From Left]
AAAAAAAAAACCBBBBBBBB 
AAAAAAAAAACAABBBBBBB
AAAAAAAAAACACCBBBBBB
AAAAAAAAAACBBCBBBBBB
AAAAAAAAAAAAAABBBBBB [16 frm 2 to 17 bits]
AAAAAAAAAAAAAAAAABBB [16 from 5 to 20 bits]
AAAAAAAAAAAAAAAAAAAA

Cost(11)+Cost(11)+4+Cost(16)+Cost(16)+1 = 91+91+4+81+81+1
Cost[20] = 350

