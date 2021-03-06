# Goldeneye 007 (U) disassembly and split file
# generated by n64split v0.4a - N64 ROM splitter

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
.section .text 
glabel alSeqGetLoc
/* 021120 70020520 8C8E0008 */  lw    $t6, 8($a0)
/* 021124 70020524 ACAE0000 */  sw    $t6, ($a1)
/* 021128 70020528 848F001A */  lh    $t7, 0x1a($a0)
/* 02112C 7002052C A4AF000C */  sh    $t7, 0xc($a1)
/* 021130 70020530 8C98000C */  lw    $t8, 0xc($a0)
/* 021134 70020534 03E00008 */  jr    $ra
/* 021138 70020538 ACB80004 */   sw    $t8, 4($a1)

glabel alSeqSetLoc
/* 02113C 7002053C 8CAE0000 */  lw    $t6, ($a1)
/* 021140 70020540 AC8E0008 */  sw    $t6, 8($a0)
/* 021144 70020544 84AF000C */  lh    $t7, 0xc($a1)
/* 021148 70020548 A48F001A */  sh    $t7, 0x1a($a0)
/* 02114C 7002054C 8CB80004 */  lw    $t8, 4($a1)
/* 021150 70020550 03E00008 */  jr    $ra
/* 021154 70020554 AC98000C */   sw    $t8, 0xc($a0)

glabel alSeqGetTicks
/* 021158 70020558 03E00008 */  jr    $ra
/* 02115C 7002055C 8C82000C */   lw    $v0, 0xc($a0)

/* 021160 70020560 03E00008 */  jr    $ra
/* 021164 70020564 00000000 */   nop   

glabel readVarLen
/* 021168 70020568 8C830008 */  lw    $v1, 8($a0)
/* 02116C 7002056C 90620000 */  lbu   $v0, ($v1)
/* 021170 70020570 246E0001 */  addiu $t6, $v1, 1
/* 021174 70020574 AC8E0008 */  sw    $t6, 8($a0)
/* 021178 70020578 304F0080 */  andi  $t7, $v0, 0x80
/* 02117C 7002057C 11E0000B */  beqz  $t7, .L700205AC
/* 021180 70020580 00402825 */   move  $a1, $v0
/* 021184 70020584 3045007F */  andi  $a1, $v0, 0x7f
.L70020588:
/* 021188 70020588 8C830008 */  lw    $v1, 8($a0)
/* 02118C 7002058C 0005C9C0 */  sll   $t9, $a1, 7
/* 021190 70020590 90620000 */  lbu   $v0, ($v1)
/* 021194 70020594 24780001 */  addiu $t8, $v1, 1
/* 021198 70020598 AC980008 */  sw    $t8, 8($a0)
/* 02119C 7002059C 304E007F */  andi  $t6, $v0, 0x7f
/* 0211A0 700205A0 304F0080 */  andi  $t7, $v0, 0x80
/* 0211A4 700205A4 15E0FFF8 */  bnez  $t7, .L70020588
/* 0211A8 700205A8 032E2821 */   addu  $a1, $t9, $t6
.L700205AC:
/* 0211AC 700205AC 03E00008 */  jr    $ra
/* 0211B0 700205B0 00A01025 */   move  $v0, $a1

glabel alSeqNextEvent
/* 0211B4 700205B4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0211B8 700205B8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0211BC 700205BC 00803025 */  move  $a2, $a0
/* 0211C0 700205C0 0C00815A */  jal   readVarLen
/* 0211C4 700205C4 00A03825 */   move  $a3, $a1
/* 0211C8 700205C8 8CCE000C */  lw    $t6, 0xc($a2)
/* 0211CC 700205CC 8CC30008 */  lw    $v1, 8($a2)
/* 0211D0 700205D0 00404825 */  move  $t1, $v0
/* 0211D4 700205D4 01C27821 */  addu  $t7, $t6, $v0
/* 0211D8 700205D8 ACCF000C */  sw    $t7, 0xc($a2)
/* 0211DC 700205DC 90640000 */  lbu   $a0, ($v1)
/* 0211E0 700205E0 240100FF */  li    $at, 255
/* 0211E4 700205E4 24780001 */  addiu $t8, $v1, 1
/* 0211E8 700205E8 ACD80008 */  sw    $t8, 8($a2)
/* 0211EC 700205EC 00801025 */  move  $v0, $a0
/* 0211F0 700205F0 1481002F */  bne   $a0, $at, .L700206B0
/* 0211F4 700205F4 308500FF */   andi  $a1, $a0, 0xff
/* 0211F8 700205F8 93020000 */  lbu   $v0, ($t8)
/* 0211FC 700205FC 27190001 */  addiu $t9, $t8, 1
/* 021200 70020600 24010051 */  li    $at, 81
/* 021204 70020604 ACD90008 */  sw    $t9, 8($a2)
/* 021208 70020608 1441001B */  bne   $v0, $at, .L70020678
/* 02120C 7002060C 00404025 */   move  $t0, $v0
/* 021210 70020610 240E0003 */  li    $t6, 3
/* 021214 70020614 A4EE0000 */  sh    $t6, ($a3)
/* 021218 70020618 ACE90004 */  sw    $t1, 4($a3)
/* 02121C 7002061C A0E50008 */  sb    $a1, 8($a3)
/* 021220 70020620 A0E80009 */  sb    $t0, 9($a3)
/* 021224 70020624 8CC30008 */  lw    $v1, 8($a2)
/* 021228 70020628 90620000 */  lbu   $v0, ($v1)
/* 02122C 7002062C 246F0001 */  addiu $t7, $v1, 1
/* 021230 70020630 ACCF0008 */  sw    $t7, 8($a2)
/* 021234 70020634 A0E2000A */  sb    $v0, 0xa($a3)
/* 021238 70020638 8CC30008 */  lw    $v1, 8($a2)
/* 02123C 7002063C 90640000 */  lbu   $a0, ($v1)
/* 021240 70020640 24780001 */  addiu $t8, $v1, 1
/* 021244 70020644 ACD80008 */  sw    $t8, 8($a2)
/* 021248 70020648 A0E4000B */  sb    $a0, 0xb($a3)
/* 02124C 7002064C 8CC30008 */  lw    $v1, 8($a2)
/* 021250 70020650 90650000 */  lbu   $a1, ($v1)
/* 021254 70020654 24790001 */  addiu $t9, $v1, 1
/* 021258 70020658 ACD90008 */  sw    $t9, 8($a2)
/* 02125C 7002065C A0E5000C */  sb    $a1, 0xc($a3)
/* 021260 70020660 8CC30008 */  lw    $v1, 8($a2)
/* 021264 70020664 90640000 */  lbu   $a0, ($v1)
/* 021268 70020668 246E0001 */  addiu $t6, $v1, 1
/* 02126C 7002066C ACCE0008 */  sw    $t6, 8($a2)
/* 021270 70020670 1000000D */  b     .L700206A8
/* 021274 70020674 A0E4000D */   sb    $a0, 0xd($a3)
.L70020678:
/* 021278 70020678 2401002F */  li    $at, 47
/* 02127C 7002067C 1441000A */  bne   $v0, $at, .L700206A8
/* 021280 70020680 240F0004 */   li    $t7, 4
/* 021284 70020684 A4EF0000 */  sh    $t7, ($a3)
/* 021288 70020688 ACE90004 */  sw    $t1, 4($a3)
/* 02128C 7002068C A0E50008 */  sb    $a1, 8($a3)
/* 021290 70020690 A0E80009 */  sb    $t0, 9($a3)
/* 021294 70020694 8CC30008 */  lw    $v1, 8($a2)
/* 021298 70020698 90640000 */  lbu   $a0, ($v1)
/* 02129C 7002069C 24780001 */  addiu $t8, $v1, 1
/* 0212A0 700206A0 ACD80008 */  sw    $t8, 8($a2)
/* 0212A4 700206A4 A0E4000A */  sb    $a0, 0xa($a3)
.L700206A8:
/* 0212A8 700206A8 1000001F */  b     .L70020728
/* 0212AC 700206AC A4C0001A */   sh    $zero, 0x1a($a2)
.L700206B0:
/* 0212B0 700206B0 24190001 */  li    $t9, 1
/* 0212B4 700206B4 304E0080 */  andi  $t6, $v0, 0x80
/* 0212B8 700206B8 A4F90000 */  sh    $t9, ($a3)
/* 0212BC 700206BC 11C00009 */  beqz  $t6, .L700206E4
/* 0212C0 700206C0 ACE90004 */   sw    $t1, 4($a3)
/* 0212C4 700206C4 A0E50008 */  sb    $a1, 8($a3)
/* 0212C8 700206C8 8CC30008 */  lw    $v1, 8($a2)
/* 0212CC 700206CC 90640000 */  lbu   $a0, ($v1)
/* 0212D0 700206D0 246F0001 */  addiu $t7, $v1, 1
/* 0212D4 700206D4 ACCF0008 */  sw    $t7, 8($a2)
/* 0212D8 700206D8 A0E40009 */  sb    $a0, 9($a3)
/* 0212DC 700206DC 10000004 */  b     .L700206F0
/* 0212E0 700206E0 A4C5001A */   sh    $a1, 0x1a($a2)
.L700206E4:
/* 0212E4 700206E4 84D8001A */  lh    $t8, 0x1a($a2)
/* 0212E8 700206E8 A0E40009 */  sb    $a0, 9($a3)
/* 0212EC 700206EC A0F80008 */  sb    $t8, 8($a3)
.L700206F0:
/* 0212F0 700206F0 90E20008 */  lbu   $v0, 8($a3)
/* 0212F4 700206F4 240100C0 */  li    $at, 192
/* 0212F8 700206F8 305900F0 */  andi  $t9, $v0, 0xf0
/* 0212FC 700206FC 13210009 */  beq   $t9, $at, .L70020724
/* 021300 70020700 240100D0 */   li    $at, 208
/* 021304 70020704 53210008 */  beql  $t9, $at, .L70020728
/* 021308 70020708 A0E0000A */   sb    $zero, 0xa($a3)
/* 02130C 7002070C 8CC30008 */  lw    $v1, 8($a2)
/* 021310 70020710 90640000 */  lbu   $a0, ($v1)
/* 021314 70020714 246E0001 */  addiu $t6, $v1, 1
/* 021318 70020718 ACCE0008 */  sw    $t6, 8($a2)
/* 02131C 7002071C 10000002 */  b     .L70020728
/* 021320 70020720 A0E4000A */   sb    $a0, 0xa($a3)
.L70020724:
/* 021324 70020724 A0E0000A */  sb    $zero, 0xa($a3)
.L70020728:
/* 021328 70020728 8FBF0014 */  lw    $ra, 0x14($sp)
/* 02132C 7002072C 27BD0018 */  addiu $sp, $sp, 0x18
/* 021330 70020730 03E00008 */  jr    $ra
/* 021334 70020734 00000000 */   nop   

glabel alSeqNewMarker
/* 021338 70020738 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 02133C 7002073C AFB70030 */  sw    $s7, 0x30($sp)
/* 021340 70020740 AFB10018 */  sw    $s1, 0x18($sp)
/* 021344 70020744 AFB00014 */  sw    $s0, 0x14($sp)
/* 021348 70020748 00808025 */  move  $s0, $a0
/* 02134C 7002074C 00C08825 */  move  $s1, $a2
/* 021350 70020750 00A0B825 */  move  $s7, $a1
/* 021354 70020754 AFBF0034 */  sw    $ra, 0x34($sp)
/* 021358 70020758 AFB6002C */  sw    $s6, 0x2c($sp)
/* 02135C 7002075C AFB50028 */  sw    $s5, 0x28($sp)
/* 021360 70020760 AFB40024 */  sw    $s4, 0x24($sp)
/* 021364 70020764 AFB30020 */  sw    $s3, 0x20($sp)
/* 021368 70020768 14C00007 */  bnez  $a2, .L70020788
/* 02136C 7002076C AFB2001C */   sw    $s2, 0x1c($sp)
/* 021370 70020770 8C8E0004 */  lw    $t6, 4($a0)
/* 021374 70020774 A4A0000C */  sh    $zero, 0xc($a1)
/* 021378 70020778 ACA00004 */  sw    $zero, 4($a1)
/* 02137C 7002077C ACA00008 */  sw    $zero, 8($a1)
/* 021380 70020780 1000002A */  b     .L7002082C
/* 021384 70020784 ACAE0000 */   sw    $t6, ($a1)
.L70020788:
/* 021388 70020788 8E0F0008 */  lw    $t7, 8($s0)
/* 02138C 7002078C 00001025 */  move  $v0, $zero
/* 021390 70020790 24130004 */  li    $s3, 4
/* 021394 70020794 AFAF004C */  sw    $t7, 0x4c($sp)
/* 021398 70020798 8618001A */  lh    $t8, 0x1a($s0)
/* 02139C 7002079C 27B20050 */  addiu $s2, $sp, 0x50
/* 0213A0 700207A0 A7B8003E */  sh    $t8, 0x3e($sp)
/* 0213A4 700207A4 8E19000C */  lw    $t9, 0xc($s0)
/* 0213A8 700207A8 AFB90044 */  sw    $t9, 0x44($sp)
/* 0213AC 700207AC 8E080004 */  lw    $t0, 4($s0)
/* 0213B0 700207B0 A600001A */  sh    $zero, 0x1a($s0)
/* 0213B4 700207B4 AE00000C */  sw    $zero, 0xc($s0)
/* 0213B8 700207B8 AE080008 */  sw    $t0, 8($s0)
/* 0213BC 700207BC 8E140008 */  lw    $s4, 8($s0)
.L700207C0:
/* 0213C0 700207C0 8615001A */  lh    $s5, 0x1a($s0)
/* 0213C4 700207C4 0040B025 */  move  $s6, $v0
/* 0213C8 700207C8 02002025 */  move  $a0, $s0
/* 0213CC 700207CC 0C00816D */  jal   alSeqNextEvent
/* 0213D0 700207D0 02402825 */   move  $a1, $s2
/* 0213D4 700207D4 87A90050 */  lh    $t1, 0x50($sp)
/* 0213D8 700207D8 55330006 */  bnel  $t1, $s3, .L700207F4
/* 0213DC 700207DC 8E02000C */   lw    $v0, 0xc($s0)
/* 0213E0 700207E0 8E140008 */  lw    $s4, 8($s0)
/* 0213E4 700207E4 8615001A */  lh    $s5, 0x1a($s0)
/* 0213E8 700207E8 10000005 */  b     .L70020800
/* 0213EC 700207EC 8E16000C */   lw    $s6, 0xc($s0)
/* 0213F0 700207F0 8E02000C */  lw    $v0, 0xc($s0)
.L700207F4:
/* 0213F4 700207F4 0051082B */  sltu  $at, $v0, $s1
/* 0213F8 700207F8 5420FFF1 */  bnezl $at, .L700207C0
/* 0213FC 700207FC 8E140008 */   lw    $s4, 8($s0)
.L70020800:
/* 021400 70020800 AEF40000 */  sw    $s4, ($s7)
/* 021404 70020804 A6F5000C */  sh    $s5, 0xc($s7)
/* 021408 70020808 AEF60004 */  sw    $s6, 4($s7)
/* 02140C 7002080C 8E0A000C */  lw    $t2, 0xc($s0)
/* 021410 70020810 AEEA0008 */  sw    $t2, 8($s7)
/* 021414 70020814 8FAB004C */  lw    $t3, 0x4c($sp)
/* 021418 70020818 AE0B0008 */  sw    $t3, 8($s0)
/* 02141C 7002081C 87AC003E */  lh    $t4, 0x3e($sp)
/* 021420 70020820 A60C001A */  sh    $t4, 0x1a($s0)
/* 021424 70020824 8FAD0044 */  lw    $t5, 0x44($sp)
/* 021428 70020828 AE0D000C */  sw    $t5, 0xc($s0)
.L7002082C:
/* 02142C 7002082C 8FBF0034 */  lw    $ra, 0x34($sp)
/* 021430 70020830 8FB00014 */  lw    $s0, 0x14($sp)
/* 021434 70020834 8FB10018 */  lw    $s1, 0x18($sp)
/* 021438 70020838 8FB2001C */  lw    $s2, 0x1c($sp)
/* 02143C 7002083C 8FB30020 */  lw    $s3, 0x20($sp)
/* 021440 70020840 8FB40024 */  lw    $s4, 0x24($sp)
/* 021444 70020844 8FB50028 */  lw    $s5, 0x28($sp)
/* 021448 70020848 8FB6002C */  lw    $s6, 0x2c($sp)
/* 02144C 7002084C 8FB70030 */  lw    $s7, 0x30($sp)
/* 021450 70020850 03E00008 */  jr    $ra
/* 021454 70020854 27BD0060 */   addiu $sp, $sp, 0x60

glabel alSeqSecToTicks
/* 021458 70020858 44856000 */  mtc1  $a1, $f12
/* 02145C 7002085C 3C018003 */  lui   $at, %hi(F64_80029D50)
/* 021460 70020860 D4269D50 */  ldc1  $f6, %lo(F64_80029D50)($at)
/* 021464 70020864 848E0018 */  lh    $t6, 0x18($a0)
/* 021468 70020868 46006121 */  cvt.d.s $f4, $f12
/* 02146C 7002086C 3C0141F0 */  li    $at, 0x41F00000 # 30.000000
/* 021470 70020870 46262202 */  mul.d $f8, $f4, $f6
/* 021474 70020874 448E5000 */  mtc1  $t6, $f10
/* 021478 70020878 44862000 */  mtc1  $a2, $f4
/* 02147C 7002087C 46805421 */  cvt.d.w $f16, $f10
/* 021480 70020880 468021A1 */  cvt.d.w $f6, $f4
/* 021484 70020884 46304482 */  mul.d $f18, $f8, $f16
/* 021488 70020888 04C30006 */  bgezl $a2, .L700208A4
/* 02148C 7002088C 46269203 */   div.d $f8, $f18, $f6
/* 021490 70020890 44815800 */  mtc1  $at, $f11
/* 021494 70020894 44805000 */  mtc1  $zero, $f10
/* 021498 70020898 00000000 */  nop   
/* 02149C 7002089C 462A3180 */  add.d $f6, $f6, $f10
/* 0214A0 700208A0 46269203 */  div.d $f8, $f18, $f6
.L700208A4:
/* 0214A4 700208A4 24020001 */  li    $v0, 1
/* 0214A8 700208A8 3C0141E0 */  li    $at, 0x41E00000 # 28.000000
/* 0214AC 700208AC 444FF800 */  cfc1  $t7, $31
/* 0214B0 700208B0 44C2F800 */  ctc1  $v0, $31
/* 0214B4 700208B4 00000000 */  nop   
/* 0214B8 700208B8 46204424 */  cvt.w.d $f16, $f8
/* 0214BC 700208BC 4442F800 */  cfc1  $v0, $31
/* 0214C0 700208C0 00000000 */  nop   
/* 0214C4 700208C4 30420078 */  andi  $v0, $v0, 0x78
/* 0214C8 700208C8 50400016 */  beql  $v0, $zero, .L70020924
/* 0214CC 700208CC 44028000 */   mfc1  $v0, $f16
/* 0214D0 700208D0 44818800 */  mtc1  $at, $f17
/* 0214D4 700208D4 44808000 */  mtc1  $zero, $f16
/* 0214D8 700208D8 24020001 */  li    $v0, 1
/* 0214DC 700208DC 3C018000 */  lui   $at, 0x8000
/* 0214E0 700208E0 46304401 */  sub.d $f16, $f8, $f16
/* 0214E4 700208E4 44C2F800 */  ctc1  $v0, $31
/* 0214E8 700208E8 00000000 */  nop   
/* 0214EC 700208EC 46208424 */  cvt.w.d $f16, $f16
/* 0214F0 700208F0 4442F800 */  cfc1  $v0, $31
/* 0214F4 700208F4 00000000 */  nop   
/* 0214F8 700208F8 30420078 */  andi  $v0, $v0, 0x78
/* 0214FC 700208FC 54400006 */  bnezl $v0, .L70020918
/* 021500 70020900 44CFF800 */   ctc1  $t7, $31
/* 021504 70020904 44028000 */  mfc1  $v0, $f16
/* 021508 70020908 44CFF800 */  ctc1  $t7, $31
/* 02150C 7002090C 03E00008 */  jr    $ra
/* 021510 70020910 00411025 */   or    $v0, $v0, $at

/* 021514 70020914 44CFF800 */  ctc1  $t7, $31
.L70020918:
/* 021518 70020918 03E00008 */  jr    $ra
/* 02151C 7002091C 2402FFFF */   li    $v0, -1

/* 021520 70020920 44028000 */  mfc1  $v0, $f16
.L70020924:
/* 021524 70020924 00000000 */  nop   
/* 021528 70020928 0442FFFB */  bltzl $v0, .L70020918
/* 02152C 7002092C 44CFF800 */   ctc1  $t7, $31
/* 021530 70020930 44CFF800 */  ctc1  $t7, $31
/* 021534 70020934 03E00008 */  jr    $ra
/* 021538 70020938 00000000 */   nop   

glabel alSeqTicksToSec
/* 02153C 7002093C 44852000 */  mtc1  $a1, $f4
/* 021540 70020940 44864000 */  mtc1  $a2, $f8
/* 021544 70020944 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 021548 70020948 468021A0 */  cvt.s.w $f6, $f4
/* 02154C 7002094C 04C10004 */  bgez  $a2, .L70020960
/* 021550 70020950 468042A0 */   cvt.s.w $f10, $f8
/* 021554 70020954 44818000 */  mtc1  $at, $f16
/* 021558 70020958 00000000 */  nop   
/* 02155C 7002095C 46105280 */  add.s $f10, $f10, $f16
.L70020960:
/* 021560 70020960 848E0018 */  lh    $t6, 0x18($a0)
/* 021564 70020964 460A3482 */  mul.s $f18, $f6, $f10
/* 021568 70020968 3C018003 */  lui   $at, %hi(F64_80029D58)
/* 02156C 7002096C 448E4000 */  mtc1  $t6, $f8
/* 021570 70020970 D42A9D58 */  ldc1  $f10, %lo(F64_80029D58)($at)
/* 021574 70020974 46804420 */  cvt.s.w $f16, $f8
/* 021578 70020978 46009121 */  cvt.d.s $f4, $f18
/* 02157C 7002097C 460081A1 */  cvt.d.s $f6, $f16
/* 021580 70020980 462A3482 */  mul.d $f18, $f6, $f10
/* 021584 70020984 46322203 */  div.d $f8, $f4, $f18
/* 021588 70020988 03E00008 */  jr    $ra
/* 02158C 7002098C 46204020 */   cvt.s.d $f0, $f8
.section .rodata
glabel F64_80029D50
 .double 1000000.0
glabel F64_80029D58
 .double 1000000.0

.section .text
glabel __alSeqNextDelta
/* 021590 70020990 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 021594 70020994 AFBF0014 */  sw    $ra, 0x14($sp)
/* 021598 70020998 8C8F0010 */  lw    $t7, 0x10($a0)
/* 02159C 7002099C 8C8E0000 */  lw    $t6, ($a0)
/* 0215A0 700209A0 8C820008 */  lw    $v0, 8($a0)
/* 0215A4 700209A4 00803025 */  move  $a2, $a0
/* 0215A8 700209A8 01CFC021 */  addu  $t8, $t6, $t7
/* 0215AC 700209AC 0058082B */  sltu  $at, $v0, $t8
/* 0215B0 700209B0 14200003 */  bnez  $at, .L700209C0
/* 0215B4 700209B4 00A04025 */   move  $t0, $a1
/* 0215B8 700209B8 10000007 */  b     .L700209D8
/* 0215BC 700209BC 00001025 */   move  $v0, $zero
.L700209C0:
/* 0215C0 700209C0 00403825 */  move  $a3, $v0
/* 0215C4 700209C4 0C00815A */  jal   readVarLen
/* 0215C8 700209C8 00C02025 */   move  $a0, $a2
/* 0215CC 700209CC AD020000 */  sw    $v0, ($t0)
/* 0215D0 700209D0 ACC70008 */  sw    $a3, 8($a2)
/* 0215D4 700209D4 24020001 */  li    $v0, 1
.L700209D8:
/* 0215D8 700209D8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0215DC 700209DC 27BD0018 */  addiu $sp, $sp, 0x18
/* 0215E0 700209E0 03E00008 */  jr    $ra
/* 0215E4 700209E4 00000000 */   nop   

glabel read32
/* 0215E8 700209E8 8C850008 */  lw    $a1, 8($a0)
/* 0215EC 700209EC 90A30000 */  lbu   $v1, ($a1)
/* 0215F0 700209F0 24AF0001 */  addiu $t7, $a1, 1
/* 0215F4 700209F4 AC8F0008 */  sw    $t7, 8($a0)
/* 0215F8 700209F8 91F80000 */  lbu   $t8, ($t7)
/* 0215FC 700209FC 00037600 */  sll   $t6, $v1, 0x18
/* 021600 70020A00 0018CC00 */  sll   $t9, $t8, 0x10
/* 021604 70020A04 01D91825 */  or    $v1, $t6, $t9
/* 021608 70020A08 25EE0001 */  addiu $t6, $t7, 1
/* 02160C 70020A0C AC8E0008 */  sw    $t6, 8($a0)
/* 021610 70020A10 91CF0000 */  lbu   $t7, ($t6)
/* 021614 70020A14 25D90001 */  addiu $t9, $t6, 1
/* 021618 70020A18 AC990008 */  sw    $t9, 8($a0)
/* 02161C 70020A1C 000FC200 */  sll   $t8, $t7, 8
/* 021620 70020A20 932E0000 */  lbu   $t6, ($t9)
/* 021624 70020A24 00781825 */  or    $v1, $v1, $t8
/* 021628 70020A28 272F0001 */  addiu $t7, $t9, 1
/* 02162C 70020A2C AC8F0008 */  sw    $t7, 8($a0)
/* 021630 70020A30 03E00008 */  jr    $ra
/* 021634 70020A34 006E1025 */   or    $v0, $v1, $t6

glabel read16
/* 021638 70020A38 8C850008 */  lw    $a1, 8($a0)
/* 02163C 70020A3C 90A30000 */  lbu   $v1, ($a1)
/* 021640 70020A40 24B90001 */  addiu $t9, $a1, 1
/* 021644 70020A44 AC990008 */  sw    $t9, 8($a0)
/* 021648 70020A48 932E0000 */  lbu   $t6, ($t9)
/* 02164C 70020A4C 0003C200 */  sll   $t8, $v1, 8
/* 021650 70020A50 27390001 */  addiu $t9, $t9, 1
/* 021654 70020A54 030E1825 */  or    $v1, $t8, $t6
/* 021658 70020A58 00037C00 */  sll   $t7, $v1, 0x10
/* 02165C 70020A5C 000F1403 */  sra   $v0, $t7, 0x10
/* 021660 70020A60 03E00008 */  jr    $ra
/* 021664 70020A64 AC990008 */   sw    $t9, 8($a0)

glabel alSeqNew
/* 021668 70020A68 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 02166C 70020A6C AFBF0014 */  sw    $ra, 0x14($sp)
/* 021670 70020A70 00803825 */  move  $a3, $a0
/* 021674 70020A74 AC850000 */  sw    $a1, ($a0)
/* 021678 70020A78 AC860010 */  sw    $a2, 0x10($a0)
/* 02167C 70020A7C A480001A */  sh    $zero, 0x1a($a0)
/* 021680 70020A80 AC80000C */  sw    $zero, 0xc($a0)
/* 021684 70020A84 0C00827A */  jal   read32
/* 021688 70020A88 AC850008 */   sw    $a1, 8($a0)
/* 02168C 70020A8C 3C014D54 */  lui   $at, (0x4D546864 >> 16) # lui $at, 0x4d54
/* 021690 70020A90 34216864 */  ori   $at, (0x4D546864 & 0xFFFF) # ori $at, $at, 0x6864
/* 021694 70020A94 54410027 */  bnel  $v0, $at, .L70020B34
/* 021698 70020A98 8FBF0014 */   lw    $ra, 0x14($sp)
/* 02169C 70020A9C 0C00827A */  jal   read32
/* 0216A0 70020AA0 00E02025 */   move  $a0, $a3
/* 0216A4 70020AA4 0C00828E */  jal   read16
/* 0216A8 70020AA8 00E02025 */   move  $a0, $a3
/* 0216AC 70020AAC 54400021 */  bnezl $v0, .L70020B34
/* 0216B0 70020AB0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0216B4 70020AB4 0C00828E */  jal   read16
/* 0216B8 70020AB8 00E02025 */   move  $a0, $a3
/* 0216BC 70020ABC 24010001 */  li    $at, 1
/* 0216C0 70020AC0 5441001C */  bnel  $v0, $at, .L70020B34
/* 0216C4 70020AC4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0216C8 70020AC8 0C00828E */  jal   read16
/* 0216CC 70020ACC 00E02025 */   move  $a0, $a3
/* 0216D0 70020AD0 A4E20018 */  sh    $v0, 0x18($a3)
/* 0216D4 70020AD4 84E30018 */  lh    $v1, 0x18($a3)
/* 0216D8 70020AD8 306E8000 */  andi  $t6, $v1, 0x8000
/* 0216DC 70020ADC 55C00015 */  bnezl $t6, .L70020B34
/* 0216E0 70020AE0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0216E4 70020AE4 44833000 */  mtc1  $v1, $f6
/* 0216E8 70020AE8 3C013FF0 */  li    $at, 0x3FF00000 # 1.875000
/* 0216EC 70020AEC 44812800 */  mtc1  $at, $f5
/* 0216F0 70020AF0 46803220 */  cvt.s.w $f8, $f6
/* 0216F4 70020AF4 44802000 */  mtc1  $zero, $f4
/* 0216F8 70020AF8 00E02025 */  move  $a0, $a3
/* 0216FC 70020AFC 460042A1 */  cvt.d.s $f10, $f8
/* 021700 70020B00 462A2183 */  div.d $f6, $f4, $f10
/* 021704 70020B04 46203220 */  cvt.s.d $f8, $f6
/* 021708 70020B08 0C00827A */  jal   read32
/* 02170C 70020B0C E4E80014 */   swc1  $f8, 0x14($a3)
/* 021710 70020B10 3C014D54 */  lui   $at, (0x4D54726B >> 16) # lui $at, 0x4d54
/* 021714 70020B14 3421726B */  ori   $at, (0x4D54726B & 0xFFFF) # ori $at, $at, 0x726b
/* 021718 70020B18 54410006 */  bnel  $v0, $at, .L70020B34
/* 02171C 70020B1C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 021720 70020B20 0C00827A */  jal   read32
/* 021724 70020B24 00E02025 */   move  $a0, $a3
/* 021728 70020B28 8CEF0008 */  lw    $t7, 8($a3)
/* 02172C 70020B2C ACEF0004 */  sw    $t7, 4($a3)
/* 021730 70020B30 8FBF0014 */  lw    $ra, 0x14($sp)
.L70020B34:
/* 021734 70020B34 27BD0018 */  addiu $sp, $sp, 0x18
/* 021738 70020B38 03E00008 */  jr    $ra
/* 02173C 70020B3C 00000000 */   nop   
