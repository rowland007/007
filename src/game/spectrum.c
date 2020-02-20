#include "ultra64.h"

// bss
s32 ptr_sectrum_monitor_data_temp_buf;
s32 ptr_sectrum_game_data_temp_buf;
s32 ptr_spectrum_roms;
s32 ptr_300alloc;
s32 ptr_6000alloc;
s32 ptr_pc_keyboard_table_alloc;
s8 spectrum_header16_15;
s8 byte_CODE_bss_8008E339;
s8 byte_CODE_bss_8008E33A;
s8 byte_CODE_bss_8008E33B;
s8 off_CODE_bss_8008E33C;
s8 byte_CODE_bss_8008E33D;
s8 byte_CODE_bss_8008E33E;
s8 byte_CODE_bss_8008E33F;
s8 off_CODE_bss_8008E340;
s8 byte_CODE_bss_8008E341;
s8 byte_CODE_bss_8008E342;
s8 byte_CODE_bss_8008E343;
s8 off_CODE_bss_8008E344;
s8 byte_CODE_bss_8008E345;
s8 byte_CODE_bss_8008E346;
s8 byte_CODE_bss_8008E347;
s8 spec_I;
s8 byte_CODE_bss_8008E349;
s8 spec_IFF2_lower;
s8 spec_IFF2_upper;
s8 spec_IM;
s8 byte_CODE_bss_8008E34D;
s16 spec_IX;
s16 spec_IY;
s16 spec_SP;
s16 spec_PC;


// data
s8 D_8004EC30 = 0x0;
s8 D_8004EC34[] = {0xFF, 0xFF, 0xFF, 0xFF};

s8 D_8004EC38[] = {0xFF, 0xFF, 0xFF, 0xFF};

s8 D_8004EC3C[] = {0xFF, 0x0, 0x0, 0x0};

s16 D_8004EC40[] = {
        0,     0, 0x7FE, 0x3FE, 0x3FD, 0x3FB, 0x3F7, 0x3EF, 0x4F7, 0x3FD,
    0x4FD, 0x4FE, 0x4FB, 0x6FB, 0x7F7, 0x6F7, 0x8FB,  0xEF, 0x4FE, 0x3FE,
    0x3FD, 0x3FB, 0x3F7, 0x3EF, 0x4EF, 0x4F7, 0x4FB, 0x4FD,  0xFD, 0x5FD,
    0x7F7, 0x6FB, 0x8FB,  0xEF, 0x3FD, 0x1FE, 0x7EF,  0xF7, 0x1FB, 0x2FB,
    0x1F7, 0x1EF, 0x6EF, 0x5FB, 0x6F7, 0x6FB, 0x6FD, 0x7FB, 0x7F7, 0x5FD,
    0x5FE, 0x2FE, 0x2F7, 0x1FD, 0x2EF, 0x5F7,  0xEF, 0x2FD,  0xFB, 0x5EF,
     0xFD, 0x8FF, 0x8FF, 0x8FF, 0x4EF, 0x6F7, 0x8FF, 0x1FE, 0x7EF,  0xF7,
    0x1FB, 0x2FB, 0x1F7, 0x1EF, 0x6EF, 0x5FB, 0x6F7, 0x6FB, 0x6FD, 0x7FB,
    0x7F7, 0x5FD, 0x5FE, 0x2FE, 0x2F7, 0x1FD, 0x2EF, 0x5F7,  0xEF, 0x2FD,
     0xFB, 0x5EF,  0xFD, 0x8FF, 0x8FF, 0x8FF, 0x8FF, 0x8FF,     0,     0
};

s32 D_8004ED08 = 0;

s16 D_8004ED0C[] = {
    1,  0x21,0x8001,0x8021, 0x401, 0x421,0x8401,0x8421,
    1,  0x3F,0xF801,0xF83F, 0x7C1, 0x7FF,0xFFC1,0xFFFF
};
//
char* romnames[] = {
    "em/data/sabre.seg.rz",
    "em/data/atic.seg.rz",
    "em/data/jetpac.seg.rz",
    "em/data/jetman.seg.rz",
    "em/data/alien8.seg.rz",
    "em/data/gunfright.seg.rz",
    "em/data/under.seg.rz",
    "em/data/knightlore.seg.rz",
    "em/data/pssst.seg.rz",
    "em/data/cookie.seg.rz"
};

u32 D_8004ED54[] = {0x7000000, 0x0,0xFF000000,0xFF000000};

// rodata
//8005C114
const char aEmDataSpec_rom_seg_rz[] = "em/data/spec_rom.seg.rz";



#ifdef NONMATCHING
void sub_GAME_7F0D28E0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D28E0
/* 107410 7F0D28E0 0006C200 */  sll   $t8, $a2, 8
/* 107414 7F0D28E4 33190700 */  andi  $t9, $t8, 0x700
/* 107418 7F0D28E8 00067140 */  sll   $t6, $a2, 5
/* 10741C 7F0D28EC 31CF1800 */  andi  $t7, $t6, 0x1800
/* 107420 7F0D28F0 00061880 */  sll   $v1, $a2, 2
/* 107424 7F0D28F4 01F95825 */  or    $t3, $t7, $t9
/* 107428 7F0D28F8 000540C3 */  sra   $t0, $a1, 3
/* 10742C 7F0D28FC 307803E0 */  andi  $t8, $v1, 0x3e0
/* 107430 7F0D2900 27BDFFF8 */  addiu $sp, $sp, -8
/* 107434 7F0D2904 03087821 */  addu  $t7, $t8, $t0
/* 107438 7F0D2908 AFB00004 */  sw    $s0, 4($sp)
/* 10743C 7F0D290C 01E4C821 */  addu  $t9, $t7, $a0
/* 107440 7F0D2910 93291800 */  lbu   $t1, 0x1800($t9)
/* 107444 7F0D2914 306C00E0 */  andi  $t4, $v1, 0xe0
/* 107448 7F0D2918 016C6825 */  or    $t5, $t3, $t4
/* 10744C 7F0D291C 01A87025 */  or    $t6, $t5, $t0
/* 107450 7F0D2920 312B0080 */  andi  $t3, $t1, 0x80
/* 107454 7F0D2924 00E08025 */  move  $s0, $a3
/* 107458 7F0D2928 01C41021 */  addu  $v0, $t6, $a0
/* 10745C 7F0D292C 1160000A */  beqz  $t3, .L7F0D2958
/* 107460 7F0D2930 01205025 */   move  $t2, $t1
/* 107464 7F0D2934 3C0C8005 */  lui   $t4, %hi(D_8004EC40+0xC4) 
/* 107468 7F0D2938 918CED04 */  lbu   $t4, %lo(D_8004EC40+0xC4)($t4)
/* 10746C 7F0D293C 01201825 */  move  $v1, $t1
/* 107470 7F0D2940 306D0007 */  andi  $t5, $v1, 7
/* 107474 7F0D2944 11800004 */  beqz  $t4, .L7F0D2958
/* 107478 7F0D2948 01A01825 */   move  $v1, $t5
/* 10747C 7F0D294C 000970C3 */  sra   $t6, $t1, 3
/* 107480 7F0D2950 10000006 */  b     .L7F0D296C
/* 107484 7F0D2954 31C40007 */   andi  $a0, $t6, 7
.L7F0D2958:
/* 107488 7F0D2958 01402025 */  move  $a0, $t2
/* 10748C 7F0D295C 308F0007 */  andi  $t7, $a0, 7
/* 107490 7F0D2960 000AC8C3 */  sra   $t9, $t2, 3
/* 107494 7F0D2964 01E02025 */  move  $a0, $t7
/* 107498 7F0D2968 33230007 */  andi  $v1, $t9, 7
.L7F0D296C:
/* 10749C 7F0D296C 314C0040 */  andi  $t4, $t2, 0x40
/* 1074A0 7F0D2970 15800007 */  bnez  $t4, .L7F0D2990
/* 1074A4 7F0D2974 00002825 */   move  $a1, $zero
/* 1074A8 7F0D2978 24840008 */  addiu $a0, $a0, 8
/* 1074AC 7F0D297C 24630008 */  addiu $v1, $v1, 8
/* 1074B0 7F0D2980 308D00FF */  andi  $t5, $a0, 0xff
/* 1074B4 7F0D2984 306E00FF */  andi  $t6, $v1, 0xff
/* 1074B8 7F0D2988 01A02025 */  move  $a0, $t5
/* 1074BC 7F0D298C 01C01825 */  move  $v1, $t6
.L7F0D2990:
/* 1074C0 7F0D2990 24090008 */  li    $t1, 8
.L7F0D2994:
/* 1074C4 7F0D2994 90470000 */  lbu   $a3, ($v0)
/* 1074C8 7F0D2998 24A50001 */  addiu $a1, $a1, 1
/* 1074CC 7F0D299C 24420100 */  addiu $v0, $v0, 0x100
/* 1074D0 7F0D29A0 30F80080 */  andi  $t8, $a3, 0x80
/* 1074D4 7F0D29A4 13000003 */  beqz  $t8, .L7F0D29B4
/* 1074D8 7F0D29A8 30EF0040 */   andi  $t7, $a3, 0x40
/* 1074DC 7F0D29AC 10000002 */  b     .L7F0D29B8
/* 1074E0 7F0D29B0 00803025 */   move  $a2, $a0
.L7F0D29B4:
/* 1074E4 7F0D29B4 00603025 */  move  $a2, $v1
.L7F0D29B8:
/* 1074E8 7F0D29B8 11E00003 */  beqz  $t7, .L7F0D29C8
/* 1074EC 7F0D29BC 0006C900 */   sll   $t9, $a2, 4
/* 1074F0 7F0D29C0 10000002 */  b     .L7F0D29CC
/* 1074F4 7F0D29C4 00804025 */   move  $t0, $a0
.L7F0D29C8:
/* 1074F8 7F0D29C8 00604025 */  move  $t0, $v1
.L7F0D29CC:
/* 1074FC 7F0D29CC 01195825 */  or    $t3, $t0, $t9
/* 107500 7F0D29D0 30EC0020 */  andi  $t4, $a3, 0x20
/* 107504 7F0D29D4 11800003 */  beqz  $t4, .L7F0D29E4
/* 107508 7F0D29D8 A20B0000 */   sb    $t3, ($s0)
/* 10750C 7F0D29DC 10000002 */  b     .L7F0D29E8
/* 107510 7F0D29E0 00803025 */   move  $a2, $a0
.L7F0D29E4:
/* 107514 7F0D29E4 00603025 */  move  $a2, $v1
.L7F0D29E8:
/* 107518 7F0D29E8 30ED0010 */  andi  $t5, $a3, 0x10
/* 10751C 7F0D29EC 11A00003 */  beqz  $t5, .L7F0D29FC
/* 107520 7F0D29F0 00067100 */   sll   $t6, $a2, 4
/* 107524 7F0D29F4 10000002 */  b     .L7F0D2A00
/* 107528 7F0D29F8 00804025 */   move  $t0, $a0
.L7F0D29FC:
/* 10752C 7F0D29FC 00604025 */  move  $t0, $v1
.L7F0D2A00:
/* 107530 7F0D2A00 010EC025 */  or    $t8, $t0, $t6
/* 107534 7F0D2A04 30EF0008 */  andi  $t7, $a3, 8
/* 107538 7F0D2A08 11E00003 */  beqz  $t7, .L7F0D2A18
/* 10753C 7F0D2A0C A2180001 */   sb    $t8, 1($s0)
/* 107540 7F0D2A10 10000002 */  b     .L7F0D2A1C
/* 107544 7F0D2A14 00803025 */   move  $a2, $a0
.L7F0D2A18:
/* 107548 7F0D2A18 00603025 */  move  $a2, $v1
.L7F0D2A1C:
/* 10754C 7F0D2A1C 30F90004 */  andi  $t9, $a3, 4
/* 107550 7F0D2A20 13200003 */  beqz  $t9, .L7F0D2A30
/* 107554 7F0D2A24 00065900 */   sll   $t3, $a2, 4
/* 107558 7F0D2A28 10000002 */  b     .L7F0D2A34
/* 10755C 7F0D2A2C 00804025 */   move  $t0, $a0
.L7F0D2A30:
/* 107560 7F0D2A30 00604025 */  move  $t0, $v1
.L7F0D2A34:
/* 107564 7F0D2A34 010B6025 */  or    $t4, $t0, $t3
/* 107568 7F0D2A38 30ED0002 */  andi  $t5, $a3, 2
/* 10756C 7F0D2A3C 11A00003 */  beqz  $t5, .L7F0D2A4C
/* 107570 7F0D2A40 A20C0002 */   sb    $t4, 2($s0)
/* 107574 7F0D2A44 10000002 */  b     .L7F0D2A50
/* 107578 7F0D2A48 00803025 */   move  $a2, $a0
.L7F0D2A4C:
/* 10757C 7F0D2A4C 00603025 */  move  $a2, $v1
.L7F0D2A50:
/* 107580 7F0D2A50 30EE0001 */  andi  $t6, $a3, 1
/* 107584 7F0D2A54 11C00003 */  beqz  $t6, .L7F0D2A64
/* 107588 7F0D2A58 0006C100 */   sll   $t8, $a2, 4
/* 10758C 7F0D2A5C 10000002 */  b     .L7F0D2A68
/* 107590 7F0D2A60 00804025 */   move  $t0, $a0
.L7F0D2A64:
/* 107594 7F0D2A64 00604025 */  move  $t0, $v1
.L7F0D2A68:
/* 107598 7F0D2A68 01187825 */  or    $t7, $t0, $t8
/* 10759C 7F0D2A6C A20F0003 */  sb    $t7, 3($s0)
/* 1075A0 7F0D2A70 14A9FFC8 */  bne   $a1, $t1, .L7F0D2994
/* 1075A4 7F0D2A74 26100020 */   addiu $s0, $s0, 0x20
/* 1075A8 7F0D2A78 8FB00004 */  lw    $s0, 4($sp)
/* 1075AC 7F0D2A7C 03E00008 */  jr    $ra
/* 1075B0 7F0D2A80 27BD0008 */   addiu $sp, $sp, 8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D2A84(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D2A84
/* 1075B4 7F0D2A84 3C028005 */  lui   $v0, %hi(D_8004ED08)
/* 1075B8 7F0D2A88 2442ED08 */  addiu $v0, %lo(D_8004ED08) # addiu $v0, $v0, -0x12f8
/* 1075BC 7F0D2A8C 904E0000 */  lbu   $t6, ($v0)
/* 1075C0 7F0D2A90 24010019 */  li    $at, 25
/* 1075C4 7F0D2A94 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 1075C8 7F0D2A98 25CF0001 */  addiu $t7, $t6, 1
/* 1075CC 7F0D2A9C 31F800FF */  andi  $t8, $t7, 0xff
/* 1075D0 7F0D2AA0 0301001A */  div   $zero, $t8, $at
/* 1075D4 7F0D2AA4 AFB5002C */  sw    $s5, 0x2c($sp)
/* 1075D8 7F0D2AA8 0000C810 */  mfhi  $t9
/* 1075DC 7F0D2AAC 0080A825 */  move  $s5, $a0
/* 1075E0 7F0D2AB0 AFBF003C */  sw    $ra, 0x3c($sp)
/* 1075E4 7F0D2AB4 AFBE0038 */  sw    $fp, 0x38($sp)
/* 1075E8 7F0D2AB8 AFB70034 */  sw    $s7, 0x34($sp)
/* 1075EC 7F0D2ABC AFB60030 */  sw    $s6, 0x30($sp)
/* 1075F0 7F0D2AC0 AFB40028 */  sw    $s4, 0x28($sp)
/* 1075F4 7F0D2AC4 AFB30024 */  sw    $s3, 0x24($sp)
/* 1075F8 7F0D2AC8 AFB20020 */  sw    $s2, 0x20($sp)
/* 1075FC 7F0D2ACC AFB1001C */  sw    $s1, 0x1c($sp)
/* 107600 7F0D2AD0 AFB00018 */  sw    $s0, 0x18($sp)
/* 107604 7F0D2AD4 AFA50064 */  sw    $a1, 0x64($sp)
/* 107608 7F0D2AD8 1720001B */  bnez  $t9, .L7F0D2B48
/* 10760C 7F0D2ADC A04F0000 */   sb    $t7, ($v0)
/* 107610 7F0D2AE0 A0400000 */  sb    $zero, ($v0)
/* 107614 7F0D2AE4 3C168009 */  lui   $s6, %hi(ptr_300alloc)
/* 107618 7F0D2AE8 26D6E32C */  addiu $s6, %lo(ptr_300alloc) # addiu $s6, $s6, -0x1cd4
/* 10761C 7F0D2AEC 24020001 */  li    $v0, 1
/* 107620 7F0D2AF0 00001825 */  move  $v1, $zero
.L7F0D2AF4:
/* 107624 7F0D2AF4 8EC80000 */  lw    $t0, ($s6)
/* 107628 7F0D2AF8 24010300 */  li    $at, 768
/* 10762C 7F0D2AFC 01034821 */  addu  $t1, $t0, $v1
/* 107630 7F0D2B00 A1220000 */  sb    $v0, ($t1)
/* 107634 7F0D2B04 8ECA0000 */  lw    $t2, ($s6)
/* 107638 7F0D2B08 01435821 */  addu  $t3, $t2, $v1
/* 10763C 7F0D2B0C A1620001 */  sb    $v0, 1($t3)
/* 107640 7F0D2B10 8ECC0000 */  lw    $t4, ($s6)
/* 107644 7F0D2B14 01836821 */  addu  $t5, $t4, $v1
/* 107648 7F0D2B18 A1A20002 */  sb    $v0, 2($t5)
/* 10764C 7F0D2B1C 8ECE0000 */  lw    $t6, ($s6)
/* 107650 7F0D2B20 01C37821 */  addu  $t7, $t6, $v1
/* 107654 7F0D2B24 24630004 */  addiu $v1, $v1, 4
/* 107658 7F0D2B28 1461FFF2 */  bne   $v1, $at, .L7F0D2AF4
/* 10765C 7F0D2B2C A1E20003 */   sb    $v0, 3($t7)
/* 107660 7F0D2B30 3C028005 */  lui   $v0, %hi(D_8004EC40+0xC4)
/* 107664 7F0D2B34 2442ED04 */  addiu $v0, %lo(D_8004EC40+0xC4) # addiu $v0, $v0, -0x12fc
/* 107668 7F0D2B38 90580000 */  lbu   $t8, ($v0)
/* 10766C 7F0D2B3C 24190001 */  li    $t9, 1
/* 107670 7F0D2B40 03384023 */  subu  $t0, $t9, $t8
/* 107674 7F0D2B44 A0480000 */  sb    $t0, ($v0)
.L7F0D2B48:
/* 107678 7F0D2B48 3C168009 */  lui   $s6, %hi(ptr_300alloc)
/* 10767C 7F0D2B4C 26D6E32C */  addiu $s6, %lo(ptr_300alloc) # addiu $s6, $s6, -0x1cd4
/* 107680 7F0D2B50 AFA00058 */  sw    $zero, 0x58($sp)
.L7F0D2B54:
/* 107684 7F0D2B54 8FA90058 */  lw    $t1, 0x58($sp)
/* 107688 7F0D2B58 0000B825 */  move  $s7, $zero
/* 10768C 7F0D2B5C 00095183 */  sra   $t2, $t1, 6
/* 107690 7F0D2B60 000A5880 */  sll   $t3, $t2, 2
/* 107694 7F0D2B64 AFAB0040 */  sw    $t3, 0x40($sp)
/* 107698 7F0D2B68 253E0040 */  addiu $fp, $t1, 0x40
/* 10769C 7F0D2B6C 8FAC0040 */  lw    $t4, 0x40($sp)
.L7F0D2B70:
/* 1076A0 7F0D2B70 8FB40058 */  lw    $s4, 0x58($sp)
/* 1076A4 7F0D2B74 00176983 */  sra   $t5, $s7, 6
/* 1076A8 7F0D2B78 8FB90064 */  lw    $t9, 0x64($sp)
/* 1076AC 7F0D2B7C 018D7021 */  addu  $t6, $t4, $t5
/* 1076B0 7F0D2B80 000E7AC0 */  sll   $t7, $t6, 0xb
/* 1076B4 7F0D2B84 029E082A */  slt   $at, $s4, $fp
/* 1076B8 7F0D2B88 1020001B */  beqz  $at, .L7F0D2BF8
/* 1076BC 7F0D2B8C 01F98821 */   addu  $s1, $t7, $t9
/* 1076C0 7F0D2B90 26F30040 */  addiu $s3, $s7, 0x40
.L7F0D2B94:
/* 1076C4 7F0D2B94 02F3082A */  slt   $at, $s7, $s3
/* 1076C8 7F0D2B98 10200013 */  beqz  $at, .L7F0D2BE8
/* 1076CC 7F0D2B9C 02E08025 */   move  $s0, $s7
/* 1076D0 7F0D2BA0 001490C3 */  sra   $s2, $s4, 3
/* 1076D4 7F0D2BA4 00124140 */  sll   $t0, $s2, 5
/* 1076D8 7F0D2BA8 01009025 */  move  $s2, $t0
.L7F0D2BAC:
/* 1076DC 7F0D2BAC 8EC90000 */  lw    $t1, ($s6)
/* 1076E0 7F0D2BB0 001050C3 */  sra   $t2, $s0, 3
/* 1076E4 7F0D2BB4 024A5825 */  or    $t3, $s2, $t2
/* 1076E8 7F0D2BB8 01696021 */  addu  $t4, $t3, $t1
/* 1076EC 7F0D2BBC 918D0000 */  lbu   $t5, ($t4)
/* 1076F0 7F0D2BC0 02A02025 */  move  $a0, $s5
/* 1076F4 7F0D2BC4 02002825 */  move  $a1, $s0
/* 1076F8 7F0D2BC8 11A00003 */  beqz  $t5, .L7F0D2BD8
/* 1076FC 7F0D2BCC 02803025 */   move  $a2, $s4
/* 107700 7F0D2BD0 0FC34A38 */  jal   sub_GAME_7F0D28E0
/* 107704 7F0D2BD4 02203825 */   move  $a3, $s1
.L7F0D2BD8:
/* 107708 7F0D2BD8 26100008 */  addiu $s0, $s0, 8
/* 10770C 7F0D2BDC 0213082A */  slt   $at, $s0, $s3
/* 107710 7F0D2BE0 1420FFF2 */  bnez  $at, .L7F0D2BAC
/* 107714 7F0D2BE4 26310004 */   addiu $s1, $s1, 4
.L7F0D2BE8:
/* 107718 7F0D2BE8 26940008 */  addiu $s4, $s4, 8
/* 10771C 7F0D2BEC 029E082A */  slt   $at, $s4, $fp
/* 107720 7F0D2BF0 1420FFE8 */  bnez  $at, .L7F0D2B94
/* 107724 7F0D2BF4 263100E0 */   addiu $s1, $s1, 0xe0
.L7F0D2BF8:
/* 107728 7F0D2BF8 26F70040 */  addiu $s7, $s7, 0x40
/* 10772C 7F0D2BFC 2AE10100 */  slti  $at, $s7, 0x100
/* 107730 7F0D2C00 5420FFDB */  bnezl $at, .L7F0D2B70
/* 107734 7F0D2C04 8FAC0040 */   lw    $t4, 0x40($sp)
/* 107738 7F0D2C08 2BC100C0 */  slti  $at, $fp, 0xc0
/* 10773C 7F0D2C0C 1420FFD1 */  bnez  $at, .L7F0D2B54
/* 107740 7F0D2C10 AFBE0058 */   sw    $fp, 0x58($sp)
/* 107744 7F0D2C14 00001025 */  move  $v0, $zero
.L7F0D2C18:
/* 107748 7F0D2C18 8ECF0000 */  lw    $t7, ($s6)
/* 10774C 7F0D2C1C 24010300 */  li    $at, 768
/* 107750 7F0D2C20 01E2C821 */  addu  $t9, $t7, $v0
/* 107754 7F0D2C24 A3200000 */  sb    $zero, ($t9)
/* 107758 7F0D2C28 8ED80000 */  lw    $t8, ($s6)
/* 10775C 7F0D2C2C 03024021 */  addu  $t0, $t8, $v0
/* 107760 7F0D2C30 A1000001 */  sb    $zero, 1($t0)
/* 107764 7F0D2C34 8ECA0000 */  lw    $t2, ($s6)
/* 107768 7F0D2C38 01425821 */  addu  $t3, $t2, $v0
/* 10776C 7F0D2C3C A1600002 */  sb    $zero, 2($t3)
/* 107770 7F0D2C40 8EC90000 */  lw    $t1, ($s6)
/* 107774 7F0D2C44 01226021 */  addu  $t4, $t1, $v0
/* 107778 7F0D2C48 24420004 */  addiu $v0, $v0, 4
/* 10777C 7F0D2C4C 1441FFF2 */  bne   $v0, $at, .L7F0D2C18
/* 107780 7F0D2C50 A1800003 */   sb    $zero, 3($t4)
/* 107784 7F0D2C54 8FBF003C */  lw    $ra, 0x3c($sp)
/* 107788 7F0D2C58 8FB00018 */  lw    $s0, 0x18($sp)
/* 10778C 7F0D2C5C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 107790 7F0D2C60 8FB20020 */  lw    $s2, 0x20($sp)
/* 107794 7F0D2C64 8FB30024 */  lw    $s3, 0x24($sp)
/* 107798 7F0D2C68 8FB40028 */  lw    $s4, 0x28($sp)
/* 10779C 7F0D2C6C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 1077A0 7F0D2C70 8FB60030 */  lw    $s6, 0x30($sp)
/* 1077A4 7F0D2C74 8FB70034 */  lw    $s7, 0x34($sp)
/* 1077A8 7F0D2C78 8FBE0038 */  lw    $fp, 0x38($sp)
/* 1077AC 7F0D2C7C 03E00008 */  jr    $ra
/* 1077B0 7F0D2C80 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif





#ifdef NONMATCHING
void spectrum_p1controller_to_kempston(void) {

}
#else
GLOBAL_ASM(
.text
glabel spectrum_p1controller_to_kempston
/* 1077B4 7F0D2C84 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 1077B8 7F0D2C88 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1077BC 7F0D2C8C AFA00034 */  sw    $zero, 0x34($sp)
/* 1077C0 7F0D2C90 AFA00030 */  sw    $zero, 0x30($sp)
/* 1077C4 7F0D2C94 AFA0002C */  sw    $zero, 0x2c($sp)
/* 1077C8 7F0D2C98 AFA00028 */  sw    $zero, 0x28($sp)
/* 1077CC 7F0D2C9C 0C002F43 */  jal   redirect_to_ramrom_replay_and_record_handlers_if_set
/* 1077D0 7F0D2CA0 AFA00024 */   sw    $zero, 0x24($sp)
/* 1077D4 7F0D2CA4 00002025 */  move  $a0, $zero
/* 1077D8 7F0D2CA8 0C0030C3 */  jal   get_controller_buttons_held
/* 1077DC 7F0D2CAC 3405FFFF */   li    $a1, 65535
/* 1077E0 7F0D2CB0 00002025 */  move  $a0, $zero
/* 1077E4 7F0D2CB4 2405FFFD */  li    $a1, -3
/* 1077E8 7F0D2CB8 24060003 */  li    $a2, 3
/* 1077EC 7F0D2CBC 0C00312D */  jal   get_controller_3dstick_L_R
/* 1077F0 7F0D2CC0 AFA20020 */   sw    $v0, 0x20($sp)
/* 1077F4 7F0D2CC4 00002025 */  move  $a0, $zero
/* 1077F8 7F0D2CC8 2405FFFD */  li    $a1, -3
/* 1077FC 7F0D2CCC 24060003 */  li    $a2, 3
/* 107800 7F0D2CD0 0C00314A */  jal   get_controller_3dstick_U_D
/* 107804 7F0D2CD4 AFA2001C */   sw    $v0, 0x1c($sp)
/* 107808 7F0D2CD8 240E00FF */  li    $t6, 255
/* 10780C 7F0D2CDC 3C018005 */  lui   $at, %hi(D_8004EC34)
/* 107810 7F0D2CE0 3C048005 */  lui   $a0, %hi(D_8004EC34+1)
/* 107814 7F0D2CE4 3C058005 */  lui   $a1, %hi(D_8004EC3C+1)
/* 107818 7F0D2CE8 8FA70020 */  lw    $a3, 0x20($sp)
/* 10781C 7F0D2CEC 8FA8001C */  lw    $t0, 0x1c($sp)
/* 107820 7F0D2CF0 24A5EC3D */  addiu $a1, %lo(D_8004EC3C+1) # addiu $a1, $a1, -0x13c3
/* 107824 7F0D2CF4 2484EC35 */  addiu $a0, %lo(D_8004EC34+1) # addiu $a0, $a0, -0x13cb
/* 107828 7F0D2CF8 A02EEC34 */  sb    $t6, %lo(D_8004EC34)($at)
/* 10782C 7F0D2CFC 240300FF */  li    $v1, 255
.L7F0D2D00:
/* 107830 7F0D2D00 24840004 */  addiu $a0, $a0, 4
/* 107834 7F0D2D04 A083FFFD */  sb    $v1, -3($a0)
/* 107838 7F0D2D08 A083FFFE */  sb    $v1, -2($a0)
/* 10783C 7F0D2D0C A083FFFF */  sb    $v1, -1($a0)
/* 107840 7F0D2D10 1485FFFB */  bne   $a0, $a1, .L7F0D2D00
/* 107844 7F0D2D14 A083FFFC */   sb    $v1, -4($a0)
/* 107848 7F0D2D18 30EF2000 */  andi  $t7, $a3, 0x2000
/* 10784C 7F0D2D1C 11E00003 */  beqz  $t7, .L7F0D2D2C
/* 107850 7F0D2D20 30F90202 */   andi  $t9, $a3, 0x202
/* 107854 7F0D2D24 24180001 */  li    $t8, 1
/* 107858 7F0D2D28 AFB80024 */  sw    $t8, 0x24($sp)
.L7F0D2D2C:
/* 10785C 7F0D2D2C 17200003 */  bnez  $t9, .L7F0D2D3C
/* 107860 7F0D2D30 30EA0101 */   andi  $t2, $a3, 0x101
/* 107864 7F0D2D34 2901FFFF */  slti  $at, $t0, -1
/* 107868 7F0D2D38 10200002 */  beqz  $at, .L7F0D2D44
.L7F0D2D3C:
/* 10786C 7F0D2D3C 24090001 */   li    $t1, 1
/* 107870 7F0D2D40 AFA9002C */  sw    $t1, 0x2c($sp)
.L7F0D2D44:
/* 107874 7F0D2D44 15400003 */  bnez  $t2, .L7F0D2D54
/* 107878 7F0D2D48 30EC0808 */   andi  $t4, $a3, 0x808
/* 10787C 7F0D2D4C 29010002 */  slti  $at, $t0, 2
/* 107880 7F0D2D50 14200002 */  bnez  $at, .L7F0D2D5C
.L7F0D2D54:
/* 107884 7F0D2D54 240B0001 */   li    $t3, 1
/* 107888 7F0D2D58 AFAB0028 */  sw    $t3, 0x28($sp)
.L7F0D2D5C:
/* 10788C 7F0D2D5C 15800003 */  bnez  $t4, .L7F0D2D6C
/* 107890 7F0D2D60 30ED0404 */   andi  $t5, $a3, 0x404
/* 107894 7F0D2D64 28410002 */  slti  $at, $v0, 2
/* 107898 7F0D2D68 14200002 */  bnez  $at, .L7F0D2D74
.L7F0D2D6C:
/* 10789C 7F0D2D6C 24050001 */   li    $a1, 1
/* 1078A0 7F0D2D70 AFA50034 */  sw    $a1, 0x34($sp)
.L7F0D2D74:
/* 1078A4 7F0D2D74 15A00003 */  bnez  $t5, .L7F0D2D84
/* 1078A8 7F0D2D78 8FA50034 */   lw    $a1, 0x34($sp)
/* 1078AC 7F0D2D7C 2841FFFF */  slti  $at, $v0, -1
/* 1078B0 7F0D2D80 10200002 */  beqz  $at, .L7F0D2D8C
.L7F0D2D84:
/* 1078B4 7F0D2D84 24060001 */   li    $a2, 1
/* 1078B8 7F0D2D88 AFA60030 */  sw    $a2, 0x30($sp)
.L7F0D2D8C:
/* 1078BC 7F0D2D8C 3C038009 */  lui   $v1, %hi(byte_CODE_bss_8008E34D)
/* 1078C0 7F0D2D90 9063E34D */  lbu   $v1, %lo(byte_CODE_bss_8008E34D)($v1)
/* 1078C4 7F0D2D94 24040002 */  li    $a0, 2
/* 1078C8 7F0D2D98 8FA60030 */  lw    $a2, 0x30($sp)
/* 1078CC 7F0D2D9C 14830005 */  bne   $a0, $v1, .L7F0D2DB4
/* 1078D0 7F0D2DA0 24020004 */   li    $v0, 4
/* 1078D4 7F0D2DA4 30EEC000 */  andi  $t6, $a3, 0xc000
/* 1078D8 7F0D2DA8 11C00002 */  beqz  $t6, .L7F0D2DB4
/* 1078DC 7F0D2DAC 00000000 */   nop   
/* 1078E0 7F0D2DB0 24050001 */  li    $a1, 1
.L7F0D2DB4:
/* 1078E4 7F0D2DB4 10430002 */  beq   $v0, $v1, .L7F0D2DC0
/* 1078E8 7F0D2DB8 24010007 */   li    $at, 7
/* 1078EC 7F0D2DBC 14610004 */  bne   $v1, $at, .L7F0D2DD0
.L7F0D2DC0:
/* 1078F0 7F0D2DC0 30EFC000 */   andi  $t7, $a3, 0xc000
/* 1078F4 7F0D2DC4 11E00002 */  beqz  $t7, .L7F0D2DD0
/* 1078F8 7F0D2DC8 00000000 */   nop   
/* 1078FC 7F0D2DCC 24060001 */  li    $a2, 1
.L7F0D2DD0:
/* 107900 7F0D2DD0 1060000A */  beqz  $v1, .L7F0D2DFC
/* 107904 7F0D2DD4 24010001 */   li    $at, 1
/* 107908 7F0D2DD8 10610008 */  beq   $v1, $at, .L7F0D2DFC
/* 10790C 7F0D2DDC 24010006 */   li    $at, 6
/* 107910 7F0D2DE0 10610006 */  beq   $v1, $at, .L7F0D2DFC
/* 107914 7F0D2DE4 24010009 */   li    $at, 9
/* 107918 7F0D2DE8 50610005 */  beql  $v1, $at, .L7F0D2E00
/* 10791C 7F0D2DEC 30F8C000 */   andi  $t8, $a3, 0xc000
/* 107920 7F0D2DF0 10430002 */  beq   $v0, $v1, .L7F0D2DFC
/* 107924 7F0D2DF4 24010007 */   li    $at, 7
/* 107928 7F0D2DF8 14610007 */  bne   $v1, $at, .L7F0D2E18
.L7F0D2DFC:
/* 10792C 7F0D2DFC 30F8C000 */   andi  $t8, $a3, 0xc000
.L7F0D2E00:
/* 107930 7F0D2E00 13000005 */  beqz  $t8, .L7F0D2E18
/* 107934 7F0D2E04 3C028005 */   lui   $v0, %hi(D_8004EC34)
/* 107938 7F0D2E08 2442EC34 */  addiu $v0, %lo(D_8004EC34) # addiu $v0, $v0, -0x13cc
/* 10793C 7F0D2E0C 90590004 */  lbu   $t9, 4($v0)
/* 107940 7F0D2E10 332900FE */  andi  $t1, $t9, 0xfe
/* 107944 7F0D2E14 A0490004 */  sb    $t1, 4($v0)
.L7F0D2E18:
/* 107948 7F0D2E18 3C028005 */  lui   $v0, %hi(D_8004EC34)
/* 10794C 7F0D2E1C 10830003 */  beq   $a0, $v1, .L7F0D2E2C
/* 107950 7F0D2E20 2442EC34 */   addiu $v0, %lo(D_8004EC34) # addiu $v0, $v0, -0x13cc
/* 107954 7F0D2E24 24010008 */  li    $at, 8
/* 107958 7F0D2E28 14610006 */  bne   $v1, $at, .L7F0D2E44
.L7F0D2E2C:
/* 10795C 7F0D2E2C 30EAC000 */   andi  $t2, $a3, 0xc000
/* 107960 7F0D2E30 51400005 */  beql  $t2, $zero, .L7F0D2E48
/* 107964 7F0D2E34 24010005 */   li    $at, 5
/* 107968 7F0D2E38 904B0003 */  lbu   $t3, 3($v0)
/* 10796C 7F0D2E3C 316C00EF */  andi  $t4, $t3, 0xef
/* 107970 7F0D2E40 A04C0003 */  sb    $t4, 3($v0)
.L7F0D2E44:
/* 107974 7F0D2E44 24010005 */  li    $at, 5
.L7F0D2E48:
/* 107978 7F0D2E48 14610006 */  bne   $v1, $at, .L7F0D2E64
/* 10797C 7F0D2E4C 30EDC000 */   andi  $t5, $a3, 0xc000
/* 107980 7F0D2E50 51A00005 */  beql  $t5, $zero, .L7F0D2E68
/* 107984 7F0D2E54 24010003 */   li    $at, 3
/* 107988 7F0D2E58 904E0003 */  lbu   $t6, 3($v0)
/* 10798C 7F0D2E5C 31CF00FB */  andi  $t7, $t6, 0xfb
/* 107990 7F0D2E60 A04F0003 */  sb    $t7, 3($v0)
.L7F0D2E64:
/* 107994 7F0D2E64 24010003 */  li    $at, 3
.L7F0D2E68:
/* 107998 7F0D2E68 14610010 */  bne   $v1, $at, .L7F0D2EAC
/* 10799C 7F0D2E6C 30F8C000 */   andi  $t8, $a3, 0xc000
/* 1079A0 7F0D2E70 13000004 */  beqz  $t8, .L7F0D2E84
/* 1079A4 7F0D2E74 30EA8000 */   andi  $t2, $a3, 0x8000
/* 1079A8 7F0D2E78 90590004 */  lbu   $t9, 4($v0)
/* 1079AC 7F0D2E7C 332900EF */  andi  $t1, $t9, 0xef
/* 1079B0 7F0D2E80 A0490004 */  sb    $t1, 4($v0)
.L7F0D2E84:
/* 1079B4 7F0D2E84 11400004 */  beqz  $t2, .L7F0D2E98
/* 1079B8 7F0D2E88 30ED4000 */   andi  $t5, $a3, 0x4000
/* 1079BC 7F0D2E8C 904B0000 */  lbu   $t3, ($v0)
/* 1079C0 7F0D2E90 316C00FD */  andi  $t4, $t3, 0xfd
/* 1079C4 7F0D2E94 A04C0000 */  sb    $t4, ($v0)
.L7F0D2E98:
/* 1079C8 7F0D2E98 51A00005 */  beql  $t5, $zero, .L7F0D2EB0
/* 1079CC 7F0D2E9C 24010006 */   li    $at, 6
/* 1079D0 7F0D2EA0 904E0007 */  lbu   $t6, 7($v0)
/* 1079D4 7F0D2EA4 31CF00FE */  andi  $t7, $t6, 0xfe
/* 1079D8 7F0D2EA8 A04F0007 */  sb    $t7, 7($v0)
.L7F0D2EAC:
/* 1079DC 7F0D2EAC 24010006 */  li    $at, 6
.L7F0D2EB0:
/* 1079E0 7F0D2EB0 14610009 */  bne   $v1, $at, .L7F0D2ED8
/* 1079E4 7F0D2EB4 30F88000 */   andi  $t8, $a3, 0x8000
/* 1079E8 7F0D2EB8 13000002 */  beqz  $t8, .L7F0D2EC4
/* 1079EC 7F0D2EBC 30E44000 */   andi  $a0, $a3, 0x4000
/* 1079F0 7F0D2EC0 24050001 */  li    $a1, 1
.L7F0D2EC4:
/* 1079F4 7F0D2EC4 50800005 */  beql  $a0, $zero, .L7F0D2EDC
/* 1079F8 7F0D2EC8 24010001 */   li    $at, 1
/* 1079FC 7F0D2ECC 90590007 */  lbu   $t9, 7($v0)
/* 107A00 7F0D2ED0 332900FE */  andi  $t1, $t9, 0xfe
/* 107A04 7F0D2ED4 A0490007 */  sb    $t1, 7($v0)
.L7F0D2ED8:
/* 107A08 7F0D2ED8 24010001 */  li    $at, 1
.L7F0D2EDC:
/* 107A0C 7F0D2EDC 14610015 */  bne   $v1, $at, .L7F0D2F34
/* 107A10 7F0D2EE0 30EAC000 */   andi  $t2, $a3, 0xc000
/* 107A14 7F0D2EE4 11400004 */  beqz  $t2, .L7F0D2EF8
/* 107A18 7F0D2EE8 30ED0200 */   andi  $t5, $a3, 0x200
/* 107A1C 7F0D2EEC 904B0000 */  lbu   $t3, ($v0)
/* 107A20 7F0D2EF0 316C00FD */  andi  $t4, $t3, 0xfd
/* 107A24 7F0D2EF4 A04C0000 */  sb    $t4, ($v0)
.L7F0D2EF8:
/* 107A28 7F0D2EF8 11A00004 */  beqz  $t5, .L7F0D2F0C
/* 107A2C 7F0D2EFC 30F80400 */   andi  $t8, $a3, 0x400
/* 107A30 7F0D2F00 904E0003 */  lbu   $t6, 3($v0)
/* 107A34 7F0D2F04 31CF00F7 */  andi  $t7, $t6, 0xf7
/* 107A38 7F0D2F08 A04F0003 */  sb    $t7, 3($v0)
.L7F0D2F0C:
/* 107A3C 7F0D2F0C 13000004 */  beqz  $t8, .L7F0D2F20
/* 107A40 7F0D2F10 30EA0100 */   andi  $t2, $a3, 0x100
/* 107A44 7F0D2F14 90590003 */  lbu   $t9, 3($v0)
/* 107A48 7F0D2F18 332900EF */  andi  $t1, $t9, 0xef
/* 107A4C 7F0D2F1C A0490003 */  sb    $t1, 3($v0)
.L7F0D2F20:
/* 107A50 7F0D2F20 51400005 */  beql  $t2, $zero, .L7F0D2F38
/* 107A54 7F0D2F24 30ED0020 */   andi  $t5, $a3, 0x20
/* 107A58 7F0D2F28 904B0004 */  lbu   $t3, 4($v0)
/* 107A5C 7F0D2F2C 316C00EF */  andi  $t4, $t3, 0xef
/* 107A60 7F0D2F30 A04C0004 */  sb    $t4, 4($v0)
.L7F0D2F34:
/* 107A64 7F0D2F34 30ED0020 */  andi  $t5, $a3, 0x20
.L7F0D2F38:
/* 107A68 7F0D2F38 11A00013 */  beqz  $t5, .L7F0D2F88
/* 107A6C 7F0D2F3C 3C018005 */   lui   $at, %hi(D_8004EC40)
/* 107A70 7F0D2F40 3C028009 */  lui   $v0, %hi(ptr_spectrum_roms)
/* 107A74 7F0D2F44 2442E328 */  addiu $v0, %lo(ptr_spectrum_roms) # addiu $v0, $v0, -0x1cd8
/* 107A78 7F0D2F48 00001825 */  move  $v1, $zero
/* 107A7C 7F0D2F4C 24044000 */  li    $a0, 16384
.L7F0D2F50:
/* 107A80 7F0D2F50 8C4E0000 */  lw    $t6, ($v0)
/* 107A84 7F0D2F54 01C37821 */  addu  $t7, $t6, $v1
/* 107A88 7F0D2F58 A1E00000 */  sb    $zero, ($t7)
/* 107A8C 7F0D2F5C 8C580000 */  lw    $t8, ($v0)
/* 107A90 7F0D2F60 0303C821 */  addu  $t9, $t8, $v1
/* 107A94 7F0D2F64 A3200001 */  sb    $zero, 1($t9)
/* 107A98 7F0D2F68 8C490000 */  lw    $t1, ($v0)
/* 107A9C 7F0D2F6C 01235021 */  addu  $t2, $t1, $v1
/* 107AA0 7F0D2F70 A1400002 */  sb    $zero, 2($t2)
/* 107AA4 7F0D2F74 8C4B0000 */  lw    $t3, ($v0)
/* 107AA8 7F0D2F78 01636021 */  addu  $t4, $t3, $v1
/* 107AAC 7F0D2F7C 24630004 */  addiu $v1, 4 # addiu $v1, $v1, 4
/* 107AB0 7F0D2F80 1464FFF3 */  bne   $v1, $a0, .L7F0D2F50
/* 107AB4 7F0D2F84 A1800003 */   sb    $zero, 3($t4)
.L7F0D2F88:
/* 107AB8 7F0D2F88 8FAD0024 */  lw    $t5, 0x24($sp)
/* 107ABC 7F0D2F8C 8FAA002C */  lw    $t2, 0x2c($sp)
/* 107AC0 7F0D2F90 000578C0 */  sll   $t7, $a1, 3
/* 107AC4 7F0D2F94 000D7100 */  sll   $t6, $t5, 4
/* 107AC8 7F0D2F98 8FAD0028 */  lw    $t5, 0x28($sp)
/* 107ACC 7F0D2F9C 01CFC025 */  or    $t8, $t6, $t7
/* 107AD0 7F0D2FA0 0006C880 */  sll   $t9, $a2, 2
/* 107AD4 7F0D2FA4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 107AD8 7F0D2FA8 03194825 */  or    $t1, $t8, $t9
/* 107ADC 7F0D2FAC 000A5840 */  sll   $t3, $t2, 1
/* 107AE0 7F0D2FB0 012B6025 */  or    $t4, $t1, $t3
/* 107AE4 7F0D2FB4 018D7025 */  or    $t6, $t4, $t5
/* 107AE8 7F0D2FB8 A02EEC40 */  sb    $t6, %lo(D_8004EC40)($at)
/* 107AEC 7F0D2FBC 03E00008 */  jr    $ra
/* 107AF0 7F0D2FC0 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
void init_spectrum_game(void) {

}
#else
GLOBAL_ASM(
.text
glabel init_spectrum_game
/* 107AF4 7F0D2FC4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 107AF8 7F0D2FC8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 107AFC 7F0D2FCC AFA40018 */  sw    $a0, 0x18($sp)
/* 107B00 7F0D2FD0 24040100 */  li    $a0, 256
/* 107B04 7F0D2FD4 0C0025C8 */  jal   mempAllocBytesInBank
/* 107B08 7F0D2FD8 24050004 */   li    $a1, 4
/* 107B0C 7F0D2FDC 3C068009 */  lui   $a2, %hi(ptr_pc_keyboard_table_alloc)
/* 107B10 7F0D2FE0 24C6E334 */  addiu $a2, %lo(ptr_pc_keyboard_table_alloc) # addiu $a2, $a2, -0x1ccc
/* 107B14 7F0D2FE4 ACC20000 */  sw    $v0, ($a2)
/* 107B18 7F0D2FE8 00002025 */  move  $a0, $zero
/* 107B1C 7F0D2FEC 24070004 */  li    $a3, 4
/* 107B20 7F0D2FF0 24050008 */  li    $a1, 8
/* 107B24 7F0D2FF4 00001825 */  move  $v1, $zero
.L7F0D2FF8:
/* 107B28 7F0D2FF8 00001025 */  move  $v0, $zero
/* 107B2C 7F0D2FFC 00447007 */  srav  $t6, $a0, $v0
.L7F0D3000:
/* 107B30 7F0D3000 31CF0001 */  andi  $t7, $t6, 1
/* 107B34 7F0D3004 11E00002 */  beqz  $t7, .L7F0D3010
/* 107B38 7F0D3008 24420001 */   addiu $v0, $v0, 1
/* 107B3C 7F0D300C 24630001 */  addiu $v1, $v1, 1
.L7F0D3010:
/* 107B40 7F0D3010 5445FFFB */  bnel  $v0, $a1, .L7F0D3000
/* 107B44 7F0D3014 00447007 */   srav  $t6, $a0, $v0
/* 107B48 7F0D3018 30780001 */  andi  $t8, $v1, 1
/* 107B4C 7F0D301C 53000006 */  beql  $t8, $zero, .L7F0D3038
/* 107B50 7F0D3020 8CCA0000 */   lw    $t2, ($a2)
/* 107B54 7F0D3024 8CD90000 */  lw    $t9, ($a2)
/* 107B58 7F0D3028 03244821 */  addu  $t1, $t9, $a0
/* 107B5C 7F0D302C 10000004 */  b     .L7F0D3040
/* 107B60 7F0D3030 A1200000 */   sb    $zero, ($t1)
/* 107B64 7F0D3034 8CCA0000 */  lw    $t2, ($a2)
.L7F0D3038:
/* 107B68 7F0D3038 01445821 */  addu  $t3, $t2, $a0
/* 107B6C 7F0D303C A1670000 */  sb    $a3, ($t3)
.L7F0D3040:
/* 107B70 7F0D3040 24840001 */  addiu $a0, $a0, 1
/* 107B74 7F0D3044 28810100 */  slti  $at, $a0, 0x100
/* 107B78 7F0D3048 5420FFEB */  bnezl $at, .L7F0D2FF8
/* 107B7C 7F0D304C 00001825 */   move  $v1, $zero
/* 107B80 7F0D3050 24046000 */  li    $a0, 24576
/* 107B84 7F0D3054 0C0025C8 */  jal   mempAllocBytesInBank
/* 107B88 7F0D3058 24050004 */   li    $a1, 4
/* 107B8C 7F0D305C 3C018009 */  lui   $at, %hi(ptr_6000alloc)
/* 107B90 7F0D3060 AC22E330 */  sw    $v0, %lo(ptr_6000alloc)($at)
/* 107B94 7F0D3064 24040300 */  li    $a0, 768
/* 107B98 7F0D3068 0C0025C8 */  jal   mempAllocBytesInBank
/* 107B9C 7F0D306C 24050004 */   li    $a1, 4
/* 107BA0 7F0D3070 3C038009 */  lui   $v1, %hi(ptr_300alloc)
/* 107BA4 7F0D3074 2463E32C */  addiu $v1, %lo(ptr_300alloc) # addiu $v1, $v1, -0x1cd4
/* 107BA8 7F0D3078 AC620000 */  sw    $v0, ($v1)
/* 107BAC 7F0D307C 24020001 */  li    $v0, 1
/* 107BB0 7F0D3080 00002025 */  move  $a0, $zero
.L7F0D3084:
/* 107BB4 7F0D3084 8C6C0000 */  lw    $t4, ($v1)
/* 107BB8 7F0D3088 01846821 */  addu  $t5, $t4, $a0
/* 107BBC 7F0D308C 24840001 */  addiu $a0, $a0, 1
/* 107BC0 7F0D3090 28810300 */  slti  $at, $a0, 0x300
/* 107BC4 7F0D3094 1420FFFB */  bnez  $at, .L7F0D3084
/* 107BC8 7F0D3098 A1A20000 */   sb    $v0, ($t5)
/* 107BCC 7F0D309C 3C040001 */  lui   $a0, 1
/* 107BD0 7F0D30A0 0C0025C8 */  jal   mempAllocBytesInBank
/* 107BD4 7F0D30A4 24050004 */   li    $a1, 4
/* 107BD8 7F0D30A8 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 107BDC 7F0D30AC 2508E328 */  addiu $t0, %lo(ptr_spectrum_roms) # addiu $t0, $t0, -0x1cd8
/* 107BE0 7F0D30B0 3C048006 */  lui   $a0, %hi(aEmDataSpec_rom_seg_rz)
/* 107BE4 7F0D30B4 AD020000 */  sw    $v0, ($t0)
/* 107BE8 7F0D30B8 2484C114 */  addiu $a0, %lo(aEmDataSpec_rom_seg_rz) # addiu $a0, $a0, -0x3eec
/* 107BEC 7F0D30BC 24050001 */  li    $a1, 1
/* 107BF0 7F0D30C0 24060100 */  li    $a2, 256
/* 107BF4 7F0D30C4 0FC2F341 */  jal   _load_resource_named_to_membank
/* 107BF8 7F0D30C8 24070004 */   li    $a3, 4
/* 107BFC 7F0D30CC 3C038009 */  lui   $v1, %hi(ptr_sectrum_monitor_data_temp_buf)
/* 107C00 7F0D30D0 2463E320 */  addiu $v1, %lo(ptr_sectrum_monitor_data_temp_buf) # addiu $v1, $v1, -0x1ce0
/* 107C04 7F0D30D4 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 107C08 7F0D30D8 2508E328 */  addiu $t0, %lo(ptr_spectrum_roms) # addiu $t0, $t0, -0x1cd8
/* 107C0C 7F0D30DC AC620000 */  sw    $v0, ($v1)
/* 107C10 7F0D30E0 00002025 */  move  $a0, $zero
.L7F0D30E4:
/* 107C14 7F0D30E4 8C6E0000 */  lw    $t6, ($v1)
/* 107C18 7F0D30E8 8D190000 */  lw    $t9, ($t0)
/* 107C1C 7F0D30EC 01C47821 */  addu  $t7, $t6, $a0
/* 107C20 7F0D30F0 03244821 */  addu  $t1, $t9, $a0
/* 107C24 7F0D30F4 91F80000 */  lbu   $t8, ($t7)
/* 107C28 7F0D30F8 24840001 */  addiu $a0, $a0, 1
/* 107C2C 7F0D30FC 28814000 */  slti  $at, $a0, 0x4000
/* 107C30 7F0D3100 1420FFF8 */  bnez  $at, .L7F0D30E4
/* 107C34 7F0D3104 A1380000 */   sb    $t8, ($t1)
/* 107C38 7F0D3108 8FAA0018 */  lw    $t2, 0x18($sp)
/* 107C3C 7F0D310C 3C038009 */  lui   $v1, %hi(byte_CODE_bss_8008E34D)
/* 107C40 7F0D3110 2463E34D */  addiu $v1, %lo(byte_CODE_bss_8008E34D) # addiu $v1, $v1, -0x1cb3
/* 107C44 7F0D3114 314200FF */  andi  $v0, $t2, 0xff
/* 107C48 7F0D3118 28410005 */  slti  $at, $v0, 5
/* 107C4C 7F0D311C 14200003 */  bnez  $at, .L7F0D312C
/* 107C50 7F0D3120 A06A0000 */   sb    $t2, ($v1)
/* 107C54 7F0D3124 A0600000 */  sb    $zero, ($v1)
/* 107C58 7F0D3128 300200FF */  andi  $v0, $zero, 0xff
.L7F0D312C:
/* 107C5C 7F0D312C 00025880 */  sll   $t3, $v0, 2
/* 107C60 7F0D3130 3C048005 */  lui   $a0, %hi(romnames)
/* 107C64 7F0D3134 008B2021 */  addu  $a0, $a0, $t3
/* 107C68 7F0D3138 8C84ED2C */  lw    $a0, %lo(romnames)($a0)
/* 107C6C 7F0D313C 24050001 */  li    $a1, 1
/* 107C70 7F0D3140 24060100 */  li    $a2, 256
/* 107C74 7F0D3144 0FC2F341 */  jal   _load_resource_named_to_membank
/* 107C78 7F0D3148 24070004 */   li    $a3, 4
/* 107C7C 7F0D314C 3C038009 */  lui   $v1, %hi(ptr_sectrum_game_data_temp_buf)
/* 107C80 7F0D3150 2463E324 */  addiu $v1, %lo(ptr_sectrum_game_data_temp_buf) # addiu $v1, $v1, -0x1cdc
/* 107C84 7F0D3154 AC620000 */  sw    $v0, ($v1)
/* 107C88 7F0D3158 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 107C8C 7F0D315C 2508E328 */  addiu $t0, %lo(ptr_spectrum_roms) # addiu $t0, $t0, -0x1cd8
/* 107C90 7F0D3160 3402C000 */  li    $v0, 49152
/* 107C94 7F0D3164 00002025 */  move  $a0, $zero
.L7F0D3168:
/* 107C98 7F0D3168 8C6C0000 */  lw    $t4, ($v1)
/* 107C9C 7F0D316C 8D0F0000 */  lw    $t7, ($t0)
/* 107CA0 7F0D3170 008C6821 */  addu  $t5, $a0, $t4
/* 107CA4 7F0D3174 91AE001B */  lbu   $t6, 0x1b($t5)
/* 107CA8 7F0D3178 01E4C821 */  addu  $t9, $t7, $a0
/* 107CAC 7F0D317C A32E4000 */  sb    $t6, 0x4000($t9)
/* 107CB0 7F0D3180 8C780000 */  lw    $t8, ($v1)
/* 107CB4 7F0D3184 8D0B0000 */  lw    $t3, ($t0)
/* 107CB8 7F0D3188 00984821 */  addu  $t1, $a0, $t8
/* 107CBC 7F0D318C 912A001C */  lbu   $t2, 0x1c($t1)
/* 107CC0 7F0D3190 01646021 */  addu  $t4, $t3, $a0
/* 107CC4 7F0D3194 A18A4001 */  sb    $t2, 0x4001($t4)
/* 107CC8 7F0D3198 8C6D0000 */  lw    $t5, ($v1)
/* 107CCC 7F0D319C 8D190000 */  lw    $t9, ($t0)
/* 107CD0 7F0D31A0 008D7821 */  addu  $t7, $a0, $t5
/* 107CD4 7F0D31A4 91EE001D */  lbu   $t6, 0x1d($t7)
/* 107CD8 7F0D31A8 0324C021 */  addu  $t8, $t9, $a0
/* 107CDC 7F0D31AC A30E4002 */  sb    $t6, 0x4002($t8)
/* 107CE0 7F0D31B0 8C690000 */  lw    $t1, ($v1)
/* 107CE4 7F0D31B4 8D0C0000 */  lw    $t4, ($t0)
/* 107CE8 7F0D31B8 00895821 */  addu  $t3, $a0, $t1
/* 107CEC 7F0D31BC 916A001E */  lbu   $t2, 0x1e($t3)
/* 107CF0 7F0D31C0 01846821 */  addu  $t5, $t4, $a0
/* 107CF4 7F0D31C4 24840004 */  addiu $a0, $a0, 4
/* 107CF8 7F0D31C8 1482FFE7 */  bne   $a0, $v0, .L7F0D3168
/* 107CFC 7F0D31CC A1AA4003 */   sb    $t2, 0x4003($t5)
/* 107D00 7F0D31D0 8C620000 */  lw    $v0, ($v1)
/* 107D04 7F0D31D4 3C018009 */  lui   $at, %hi(spec_I)
/* 107D08 7F0D31D8 3C058009 */  lui   $a1, %hi(spec_IFF2_upper)
/* 107D0C 7F0D31DC 904F0000 */  lbu   $t7, ($v0)
/* 107D10 7F0D31E0 24A5E34B */  addiu $a1, %lo(spec_IFF2_upper) # addiu $a1, $a1, -0x1cb5
/* 107D14 7F0D31E4 3C068009 */  lui   $a2, %hi(spec_SP)
/* 107D18 7F0D31E8 A02FE348 */  sb    $t7, %lo(spec_I)($at)
/* 107D1C 7F0D31EC 90590001 */  lbu   $t9, 1($v0)
/* 107D20 7F0D31F0 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E347)
/* 107D24 7F0D31F4 24C6E352 */  addiu $a2, %lo(spec_SP) # addiu $a2, $a2, -0x1cae
/* 107D28 7F0D31F8 A039E347 */  sb    $t9, %lo(byte_CODE_bss_8008E347)($at)
/* 107D2C 7F0D31FC 904E0002 */  lbu   $t6, 2($v0)
/* 107D30 7F0D3200 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E346)
/* 107D34 7F0D3204 3C078009 */  lui   $a3, %hi(spec_IM)
/* 107D38 7F0D3208 A02EE346 */  sb    $t6, %lo(byte_CODE_bss_8008E346)($at)
/* 107D3C 7F0D320C 90580003 */  lbu   $t8, 3($v0)
/* 107D40 7F0D3210 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E345)
/* 107D44 7F0D3214 24E7E34C */  addiu $a3, %lo(spec_IM) # addiu $a3, $a3, -0x1cb4
/* 107D48 7F0D3218 A038E345 */  sb    $t8, %lo(byte_CODE_bss_8008E345)($at)
/* 107D4C 7F0D321C 90490004 */  lbu   $t1, 4($v0)
/* 107D50 7F0D3220 3C018009 */  lui   $at, %hi(off_CODE_bss_8008E344)
/* 107D54 7F0D3224 A029E344 */  sb    $t1, %lo(off_CODE_bss_8008E344)($at)
/* 107D58 7F0D3228 904B0005 */  lbu   $t3, 5($v0)
/* 107D5C 7F0D322C 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E343)
/* 107D60 7F0D3230 A02BE343 */  sb    $t3, %lo(byte_CODE_bss_8008E343)($at)
/* 107D64 7F0D3234 904C0006 */  lbu   $t4, 6($v0)
/* 107D68 7F0D3238 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E342)
/* 107D6C 7F0D323C A02CE342 */  sb    $t4, %lo(byte_CODE_bss_8008E342)($at)
/* 107D70 7F0D3240 904A0007 */  lbu   $t2, 7($v0)
/* 107D74 7F0D3244 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E341)
/* 107D78 7F0D3248 A02AE341 */  sb    $t2, %lo(byte_CODE_bss_8008E341)($at)
/* 107D7C 7F0D324C 904D0008 */  lbu   $t5, 8($v0)
/* 107D80 7F0D3250 3C018009 */  lui   $at, %hi(off_CODE_bss_8008E340)
/* 107D84 7F0D3254 A02DE340 */  sb    $t5, %lo(off_CODE_bss_8008E340)($at)
/* 107D88 7F0D3258 904F0009 */  lbu   $t7, 9($v0)
/* 107D8C 7F0D325C 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E33F)
/* 107D90 7F0D3260 A02FE33F */  sb    $t7, %lo(byte_CODE_bss_8008E33F)($at)
/* 107D94 7F0D3264 9059000A */  lbu   $t9, 0xa($v0)
/* 107D98 7F0D3268 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E33E)
/* 107D9C 7F0D326C A039E33E */  sb    $t9, %lo(byte_CODE_bss_8008E33E)($at)
/* 107DA0 7F0D3270 904E000B */  lbu   $t6, 0xb($v0)
/* 107DA4 7F0D3274 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E33D)
/* 107DA8 7F0D3278 A02EE33D */  sb    $t6, %lo(byte_CODE_bss_8008E33D)($at)
/* 107DAC 7F0D327C 9058000C */  lbu   $t8, 0xc($v0)
/* 107DB0 7F0D3280 3C018009 */  lui   $at, %hi(off_CODE_bss_8008E33C)
/* 107DB4 7F0D3284 A038E33C */  sb    $t8, %lo(off_CODE_bss_8008E33C)($at)
/* 107DB8 7F0D3288 9049000D */  lbu   $t1, 0xd($v0)
/* 107DBC 7F0D328C 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E33B)
/* 107DC0 7F0D3290 A029E33B */  sb    $t1, %lo(byte_CODE_bss_8008E33B)($at)
/* 107DC4 7F0D3294 904B000E */  lbu   $t3, 0xe($v0)
/* 107DC8 7F0D3298 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E33A)
/* 107DCC 7F0D329C A02BE33A */  sb    $t3, %lo(byte_CODE_bss_8008E33A)($at)
/* 107DD0 7F0D32A0 904C0010 */  lbu   $t4, 0x10($v0)
/* 107DD4 7F0D32A4 904D000F */  lbu   $t5, 0xf($v0)
/* 107DD8 7F0D32A8 3C018009 */  lui   $at, %hi(spec_IY)
/* 107DDC 7F0D32AC 000C5200 */  sll   $t2, $t4, 8
/* 107DE0 7F0D32B0 014D7821 */  addu  $t7, $t2, $t5
/* 107DE4 7F0D32B4 A42FE350 */  sh    $t7, %lo(spec_IY)($at)
/* 107DE8 7F0D32B8 90590012 */  lbu   $t9, 0x12($v0)
/* 107DEC 7F0D32BC 90580011 */  lbu   $t8, 0x11($v0)
/* 107DF0 7F0D32C0 3C018009 */  lui   $at, %hi(spec_IX)
/* 107DF4 7F0D32C4 00197200 */  sll   $t6, $t9, 8
/* 107DF8 7F0D32C8 01D84821 */  addu  $t1, $t6, $t8
/* 107DFC 7F0D32CC A429E34E */  sh    $t1, %lo(spec_IX)($at)
/* 107E00 7F0D32D0 904B0013 */  lbu   $t3, 0x13($v0)
/* 107E04 7F0D32D4 3C018009 */  lui   $at, %hi(spec_IFF2_lower)
/* 107E08 7F0D32D8 000B6083 */  sra   $t4, $t3, 2
/* 107E0C 7F0D32DC 318D0001 */  andi  $t5, $t4, 1
/* 107E10 7F0D32E0 A0AD0000 */  sb    $t5, ($a1)
/* 107E14 7F0D32E4 A02DE34A */  sb    $t5, %lo(spec_IFF2_lower)($at)
/* 107E18 7F0D32E8 904F0014 */  lbu   $t7, 0x14($v0)
/* 107E1C 7F0D32EC 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E349)
/* 107E20 7F0D32F0 A02FE349 */  sb    $t7, %lo(byte_CODE_bss_8008E349)($at)
/* 107E24 7F0D32F4 90590015 */  lbu   $t9, 0x15($v0)
/* 107E28 7F0D32F8 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E339)
/* 107E2C 7F0D32FC A039E339 */  sb    $t9, %lo(byte_CODE_bss_8008E339)($at)
/* 107E30 7F0D3300 904E0016 */  lbu   $t6, 0x16($v0)
/* 107E34 7F0D3304 3C018009 */  lui   $at, %hi(spectrum_header16_15)
/* 107E38 7F0D3308 A02EE338 */  sb    $t6, %lo(spectrum_header16_15)($at)
/* 107E3C 7F0D330C 90580018 */  lbu   $t8, 0x18($v0)
/* 107E40 7F0D3310 904B0017 */  lbu   $t3, 0x17($v0)
/* 107E44 7F0D3314 3C018009 */  lui   $at, %hi(spec_PC)
/* 107E48 7F0D3318 00184A00 */  sll   $t1, $t8, 8
/* 107E4C 7F0D331C 012B6021 */  addu  $t4, $t1, $t3
/* 107E50 7F0D3320 A4CC0000 */  sh    $t4, ($a2)
/* 107E54 7F0D3324 904A0019 */  lbu   $t2, 0x19($v0)
/* 107E58 7F0D3328 314400FF */  andi  $a0, $t2, 0xff
/* 107E5C 7F0D332C 18800003 */  blez  $a0, .L7F0D333C
/* 107E60 7F0D3330 A0EA0000 */   sb    $t2, ($a3)
/* 107E64 7F0D3334 248D0001 */  addiu $t5, $a0, 1
/* 107E68 7F0D3338 A0ED0000 */  sb    $t5, ($a3)
.L7F0D333C:
/* 107E6C 7F0D333C 94C30000 */  lhu   $v1, ($a2)
/* 107E70 7F0D3340 8D020000 */  lw    $v0, ($t0)
/* 107E74 7F0D3344 8FBF0014 */  lw    $ra, 0x14($sp)
/* 107E78 7F0D3348 246C0002 */  addiu $t4, $v1, 2
/* 107E7C 7F0D334C 00437021 */  addu  $t6, $v0, $v1
/* 107E80 7F0D3350 91D80001 */  lbu   $t8, 1($t6)
/* 107E84 7F0D3354 00627821 */  addu  $t7, $v1, $v0
/* 107E88 7F0D3358 91F90000 */  lbu   $t9, ($t7)
/* 107E8C 7F0D335C 00184A00 */  sll   $t1, $t8, 8
/* 107E90 7F0D3360 27BD0018 */  addiu $sp, $sp, 0x18
/* 107E94 7F0D3364 03295825 */  or    $t3, $t9, $t1
/* 107E98 7F0D3368 A42BE354 */  sh    $t3, %lo(spec_PC)($at)
/* 107E9C 7F0D336C 03E00008 */  jr    $ra
/* 107EA0 7F0D3370 A4CC0000 */   sh    $t4, ($a2)
)
#endif





#ifdef NONMATCHING
void run_spectrum_game(void) {

}
#else
GLOBAL_ASM(
.text
glabel run_spectrum_game
/* 107EA4 7F0D3374 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 107EA8 7F0D3378 AFBF0014 */  sw    $ra, 0x14($sp)
/* 107EAC 7F0D337C 0FC34B21 */  jal   spectrum_p1controller_to_kempston
/* 107EB0 7F0D3380 00000000 */   nop   
/* 107EB4 7F0D3384 0FC34E0B */  jal   spectrum_hw_emulation
/* 107EB8 7F0D3388 00000000 */   nop   
/* 107EBC 7F0D338C 3C048009 */  lui   $a0, %hi(ptr_spectrum_roms)
/* 107EC0 7F0D3390 8C84E328 */  lw    $a0, %lo(ptr_spectrum_roms)($a0)
/* 107EC4 7F0D3394 3C058009 */  lui   $a1, %hi(ptr_6000alloc)
/* 107EC8 7F0D3398 8CA5E330 */  lw    $a1, %lo(ptr_6000alloc)($a1)
/* 107ECC 7F0D339C 0FC34AA1 */  jal   sub_GAME_7F0D2A84
/* 107ED0 7F0D33A0 24844000 */   addiu $a0, $a0, 0x4000
/* 107ED4 7F0D33A4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 107ED8 7F0D33A8 27BD0018 */  addiu $sp, $sp, 0x18
/* 107EDC 7F0D33AC 03E00008 */  jr    $ra
/* 107EE0 7F0D33B0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void spectrum_draw_screen(void) {

}
#else
GLOBAL_ASM(
.text
glabel spectrum_draw_screen
/* 107EE4 7F0D33B4 27BDFF60 */  addiu $sp, $sp, -0xa0
/* 107EE8 7F0D33B8 00801025 */  move  $v0, $a0
/* 107EEC 7F0D33BC AFBF002C */  sw    $ra, 0x2c($sp)
/* 107EF0 7F0D33C0 AFBE0028 */  sw    $fp, 0x28($sp)
/* 107EF4 7F0D33C4 AFB70024 */  sw    $s7, 0x24($sp)
/* 107EF8 7F0D33C8 AFB60020 */  sw    $s6, 0x20($sp)
/* 107EFC 7F0D33CC AFB5001C */  sw    $s5, 0x1c($sp)
/* 107F00 7F0D33D0 AFB40018 */  sw    $s4, 0x18($sp)
/* 107F04 7F0D33D4 AFB30014 */  sw    $s3, 0x14($sp)
/* 107F08 7F0D33D8 AFB20010 */  sw    $s2, 0x10($sp)
/* 107F0C 7F0D33DC AFB1000C */  sw    $s1, 0xc($sp)
/* 107F10 7F0D33E0 AFB00008 */  sw    $s0, 8($sp)
/* 107F14 7F0D33E4 3C0BE700 */  lui   $t3, 0xe700
/* 107F18 7F0D33E8 24840008 */  addiu $a0, $a0, 8
/* 107F1C 7F0D33EC AC4B0000 */  sw    $t3, ($v0)
/* 107F20 7F0D33F0 AC400004 */  sw    $zero, 4($v0)
/* 107F24 7F0D33F4 00801825 */  move  $v1, $a0
/* 107F28 7F0D33F8 3C0E8005 */  lui   $t6, %hi(D_8004ED0C) 
/* 107F2C 7F0D33FC 25CEED0C */  addiu $t6, %lo(D_8004ED0C) # addiu $t6, $t6, -0x12f4
/* 107F30 7F0D3400 24840008 */  addiu $a0, $a0, 8
/* 107F34 7F0D3404 3C10FD10 */  lui   $s0, 0xfd10
/* 107F38 7F0D3408 AC6E0004 */  sw    $t6, 4($v1)
/* 107F3C 7F0D340C 00802825 */  move  $a1, $a0
/* 107F40 7F0D3410 3C0FF500 */  lui   $t7, (0xF5000300 >> 16) # lui $t7, 0xf500
/* 107F44 7F0D3414 AC700000 */  sw    $s0, ($v1)
/* 107F48 7F0D3418 35EF0300 */  ori   $t7, (0xF5000300 & 0xFFFF) # ori $t7, $t7, 0x300
/* 107F4C 7F0D341C 24840008 */  addiu $a0, $a0, 8
/* 107F50 7F0D3420 3C110700 */  lui   $s1, 0x700
/* 107F54 7F0D3424 ACAF0000 */  sw    $t7, ($a1)
/* 107F58 7F0D3428 00803025 */  move  $a2, $a0
/* 107F5C 7F0D342C ACB10004 */  sw    $s1, 4($a1)
/* 107F60 7F0D3430 24840008 */  addiu $a0, $a0, 8
/* 107F64 7F0D3434 3C12E600 */  lui   $s2, 0xe600
/* 107F68 7F0D3438 00803825 */  move  $a3, $a0
/* 107F6C 7F0D343C ACD20000 */  sw    $s2, ($a2)
/* 107F70 7F0D3440 ACC00004 */  sw    $zero, 4($a2)
/* 107F74 7F0D3444 3C190703 */  lui   $t9, (0x0703C000 >> 16) # lui $t9, 0x703
/* 107F78 7F0D3448 3739C000 */  ori   $t9, (0x0703C000 & 0xFFFF) # ori $t9, $t9, 0xc000
/* 107F7C 7F0D344C 24840008 */  addiu $a0, $a0, 8
/* 107F80 7F0D3450 3C18F000 */  lui   $t8, 0xf000
/* 107F84 7F0D3454 ACF80000 */  sw    $t8, ($a3)
/* 107F88 7F0D3458 ACF90004 */  sw    $t9, 4($a3)
/* 107F8C 7F0D345C 00801025 */  move  $v0, $a0
/* 107F90 7F0D3460 3C0EBA00 */  lui   $t6, (0xBA001301 >> 16) # lui $t6, 0xba00
/* 107F94 7F0D3464 35CE1301 */  ori   $t6, (0xBA001301 & 0xFFFF) # ori $t6, $t6, 0x1301
/* 107F98 7F0D3468 24840008 */  addiu $a0, $a0, 8
/* 107F9C 7F0D346C AC4E0000 */  sw    $t6, ($v0)
/* 107FA0 7F0D3470 00801825 */  move  $v1, $a0
/* 107FA4 7F0D3474 AC400004 */  sw    $zero, 4($v0)
/* 107FA8 7F0D3478 3C180F0A */  lui   $t8, (0x0F0A4000 >> 16) # lui $t8, 0xf0a
/* 107FAC 7F0D347C 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 107FB0 7F0D3480 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 107FB4 7F0D3484 37184000 */  ori   $t8, (0x0F0A4000 & 0xFFFF) # ori $t8, $t8, 0x4000
/* 107FB8 7F0D3488 24840008 */  addiu $a0, $a0, 8
/* 107FBC 7F0D348C AC780004 */  sw    $t8, 4($v1)
/* 107FC0 7F0D3490 AC6F0000 */  sw    $t7, ($v1)
/* 107FC4 7F0D3494 00802825 */  move  $a1, $a0
/* 107FC8 7F0D3498 3C19FCFF */  lui   $t9, (0xFCFFFFFF >> 16) # lui $t9, 0xfcff
/* 107FCC 7F0D349C 3739FFFF */  ori   $t9, (0xFCFFFFFF & 0xFFFF) # ori $t9, $t9, 0xffff
/* 107FD0 7F0D34A0 24840008 */  addiu $a0, $a0, 8
/* 107FD4 7F0D34A4 3C0EFFFC */  lui   $t6, (0xFFFCF87C >> 16) # lui $t6, 0xfffc
/* 107FD8 7F0D34A8 35CEF87C */  ori   $t6, (0xFFFCF87C & 0xFFFF) # ori $t6, $t6, 0xf87c
/* 107FDC 7F0D34AC ACB90000 */  sw    $t9, ($a1)
/* 107FE0 7F0D34B0 00803025 */  move  $a2, $a0
/* 107FE4 7F0D34B4 ACAE0004 */  sw    $t6, 4($a1)
/* 107FE8 7F0D34B8 3C0FBA00 */  lui   $t7, (0xBA000C02 >> 16) # lui $t7, 0xba00
/* 107FEC 7F0D34BC 35EF0C02 */  ori   $t7, (0xBA000C02 & 0xFFFF) # ori $t7, $t7, 0xc02
/* 107FF0 7F0D34C0 24840008 */  addiu $a0, $a0, 8
/* 107FF4 7F0D34C4 ACCF0000 */  sw    $t7, ($a2)
/* 107FF8 7F0D34C8 ACC00004 */  sw    $zero, 4($a2)
/* 107FFC 7F0D34CC 00803825 */  move  $a3, $a0
/* 108000 7F0D34D0 3C18BB00 */  lui   $t8, (0xBB000001 >> 16) # lui $t8, 0xbb00
/* 108004 7F0D34D4 37180001 */  ori   $t8, (0xBB000001 & 0xFFFF) # ori $t8, $t8, 1
/* 108008 7F0D34D8 2419FFFF */  li    $t9, -1
/* 10800C 7F0D34DC ACF90004 */  sw    $t9, 4($a3)
/* 108010 7F0D34E0 ACF80000 */  sw    $t8, ($a3)
/* 108014 7F0D34E4 3C138009 */  lui   $s3, %hi(ptr_6000alloc)
/* 108018 7F0D34E8 3C16073F */  lui   $s6, (0x073FF200 >> 16) # lui $s6, 0x73f
/* 10801C 7F0D34EC 3C17BA00 */  lui   $s7, (0xBA000E02 >> 16) # lui $s7, 0xba00
/* 108020 7F0D34F0 3C1FF540 */  lui   $ra, (0xF5400800 >> 16) # lui $ra, 0xf540
/* 108024 7F0D34F4 24840008 */  addiu $a0, $a0, 8
/* 108028 7F0D34F8 37FF0800 */  ori   $ra, (0xF5400800 & 0xFFFF) # ori $ra, $ra, 0x800
/* 10802C 7F0D34FC 36F70E02 */  ori   $s7, (0xBA000E02 & 0xFFFF) # ori $s7, $s7, 0xe02
/* 108030 7F0D3500 36D6F200 */  ori   $s6, (0x073FF200 & 0xFFFF) # ori $s6, $s6, 0xf200
/* 108034 7F0D3504 2673E330 */  addiu $s3, %lo(ptr_6000alloc) # addiu $s3, $s3, -0x1cd0
/* 108038 7F0D3508 AFA0003C */  sw    $zero, 0x3c($sp)
/* 10803C 7F0D350C 00001025 */  move  $v0, $zero
/* 108040 7F0D3510 3C14F510 */  lui   $s4, 0xf510
/* 108044 7F0D3514 3C15F300 */  lui   $s5, 0xf300
/* 108048 7F0D3518 341E8000 */  li    $fp, 32768
.L7F0D351C:
/* 10804C 7F0D351C 8FA8003C */  lw    $t0, 0x3c($sp)
/* 108050 7F0D3520 24430001 */  addiu $v1, $v0, 1
/* 108054 7F0D3524 00036180 */  sll   $t4, $v1, 6
/* 108058 7F0D3528 00026980 */  sll   $t5, $v0, 6
/* 10805C 7F0D352C 25AD0018 */  addiu $t5, $t5, 0x18
/* 108060 7F0D3530 258C0018 */  addiu $t4, $t4, 0x18
/* 108064 7F0D3534 000C7880 */  sll   $t7, $t4, 2
/* 108068 7F0D3538 000DC880 */  sll   $t9, $t5, 2
/* 10806C 7F0D353C 000872C0 */  sll   $t6, $t0, 0xb
/* 108070 7F0D3540 01C04025 */  move  $t0, $t6
/* 108074 7F0D3544 332D0FFF */  andi  $t5, $t9, 0xfff
/* 108078 7F0D3548 31EC0FFF */  andi  $t4, $t7, 0xfff
/* 10807C 7F0D354C AFA30034 */  sw    $v1, 0x34($sp)
/* 108080 7F0D3550 00003825 */  move  $a3, $zero
.L7F0D3554:
/* 108084 7F0D3554 00801025 */  move  $v0, $a0
/* 108088 7F0D3558 24840008 */  addiu $a0, $a0, 8
/* 10808C 7F0D355C AC4B0000 */  sw    $t3, ($v0)
/* 108090 7F0D3560 AC400004 */  sw    $zero, 4($v0)
/* 108094 7F0D3564 00801825 */  move  $v1, $a0
/* 108098 7F0D3568 AC700000 */  sw    $s0, ($v1)
/* 10809C 7F0D356C 8E6F0000 */  lw    $t7, ($s3)
/* 1080A0 7F0D3570 24840008 */  addiu $a0, $a0, 8
/* 1080A4 7F0D3574 00802825 */  move  $a1, $a0
/* 1080A8 7F0D3578 010FC021 */  addu  $t8, $t0, $t7
/* 1080AC 7F0D357C AC780004 */  sw    $t8, 4($v1)
/* 1080B0 7F0D3580 24840008 */  addiu $a0, $a0, 8
/* 1080B4 7F0D3584 00803025 */  move  $a2, $a0
/* 1080B8 7F0D3588 ACB10004 */  sw    $s1, 4($a1)
/* 1080BC 7F0D358C ACB40000 */  sw    $s4, ($a1)
/* 1080C0 7F0D3590 24840008 */  addiu $a0, $a0, 8
/* 1080C4 7F0D3594 00804825 */  move  $t1, $a0
/* 1080C8 7F0D3598 ACC00004 */  sw    $zero, 4($a2)
/* 1080CC 7F0D359C ACD20000 */  sw    $s2, ($a2)
/* 1080D0 7F0D35A0 24840008 */  addiu $a0, $a0, 8
/* 1080D4 7F0D35A4 00801025 */  move  $v0, $a0
/* 1080D8 7F0D35A8 AD360004 */  sw    $s6, 4($t1)
/* 1080DC 7F0D35AC AD350000 */  sw    $s5, ($t1)
/* 1080E0 7F0D35B0 24840008 */  addiu $a0, $a0, 8
/* 1080E4 7F0D35B4 AC400004 */  sw    $zero, 4($v0)
/* 1080E8 7F0D35B8 AC4B0000 */  sw    $t3, ($v0)
/* 1080EC 7F0D35BC 00801825 */  move  $v1, $a0
/* 1080F0 7F0D35C0 24840008 */  addiu $a0, $a0, 8
/* 1080F4 7F0D35C4 00802825 */  move  $a1, $a0
/* 1080F8 7F0D35C8 3C190001 */  lui   $t9, (0x00018060 >> 16) # lui $t9, 1
/* 1080FC 7F0D35CC AC770000 */  sw    $s7, ($v1)
/* 108100 7F0D35D0 AC7E0004 */  sw    $fp, 4($v1)
/* 108104 7F0D35D4 37398060 */  ori   $t9, (0x00018060 & 0xFFFF) # ori $t9, $t9, 0x8060
/* 108108 7F0D35D8 ACB90004 */  sw    $t9, 4($a1)
/* 10810C 7F0D35DC 24840008 */  addiu $a0, $a0, 8
/* 108110 7F0D35E0 24E20001 */  addiu $v0, $a3, 1
/* 108114 7F0D35E4 ACBF0000 */  sw    $ra, ($a1)
/* 108118 7F0D35E8 00803025 */  move  $a2, $a0
/* 10811C 7F0D35EC 3C0F007E */  lui   $t7, (0x007E07E0 >> 16) # lui $t7, 0x7e
/* 108120 7F0D35F0 3C0EF200 */  lui   $t6, 0xf200
/* 108124 7F0D35F4 0002C180 */  sll   $t8, $v0, 6
/* 108128 7F0D35F8 ACCE0000 */  sw    $t6, ($a2)
/* 10812C 7F0D35FC 35EF07E0 */  ori   $t7, (0x007E07E0 & 0xFFFF) # ori $t7, $t7, 0x7e0
/* 108130 7F0D3600 27190020 */  addiu $t9, $t8, 0x20
/* 108134 7F0D3604 ACCF0004 */  sw    $t7, 4($a2)
/* 108138 7F0D3608 00197080 */  sll   $t6, $t9, 2
/* 10813C 7F0D360C 31CF0FFF */  andi  $t7, $t6, 0xfff
/* 108140 7F0D3610 000FC300 */  sll   $t8, $t7, 0xc
/* 108144 7F0D3614 3C01E400 */  lui   $at, 0xe400
/* 108148 7F0D3618 0301C825 */  or    $t9, $t8, $at
/* 10814C 7F0D361C 24840008 */  addiu $a0, $a0, 8
/* 108150 7F0D3620 032C7025 */  or    $t6, $t9, $t4
/* 108154 7F0D3624 00077980 */  sll   $t7, $a3, 6
/* 108158 7F0D3628 25F80020 */  addiu $t8, $t7, 0x20
/* 10815C 7F0D362C 00805025 */  move  $t2, $a0
/* 108160 7F0D3630 AD4E0000 */  sw    $t6, ($t2)
/* 108164 7F0D3634 0018C880 */  sll   $t9, $t8, 2
/* 108168 7F0D3638 332E0FFF */  andi  $t6, $t9, 0xfff
/* 10816C 7F0D363C 000E7B00 */  sll   $t7, $t6, 0xc
/* 108170 7F0D3640 24840008 */  addiu $a0, $a0, 8
/* 108174 7F0D3644 00801825 */  move  $v1, $a0
/* 108178 7F0D3648 01EDC025 */  or    $t8, $t7, $t5
/* 10817C 7F0D364C AD580004 */  sw    $t8, 4($t2)
/* 108180 7F0D3650 24840008 */  addiu $a0, $a0, 8
/* 108184 7F0D3654 00802825 */  move  $a1, $a0
/* 108188 7F0D3658 3C0F0400 */  lui   $t7, (0x04000400 >> 16) # lui $t7, 0x400
/* 10818C 7F0D365C 3C19B400 */  lui   $t9, 0xb400
/* 108190 7F0D3660 24010004 */  li    $at, 4
/* 108194 7F0D3664 AC790000 */  sw    $t9, ($v1)
/* 108198 7F0D3668 35EF0400 */  ori   $t7, (0x04000400 & 0xFFFF) # ori $t7, $t7, 0x400
/* 10819C 7F0D366C AC600004 */  sw    $zero, 4($v1)
/* 1081A0 7F0D3670 3C0EB300 */  lui   $t6, 0xb300
/* 1081A4 7F0D3674 00403825 */  move  $a3, $v0
/* 1081A8 7F0D3678 25080800 */  addiu $t0, $t0, 0x800
/* 1081AC 7F0D367C ACAE0000 */  sw    $t6, ($a1)
/* 1081B0 7F0D3680 ACAF0004 */  sw    $t7, 4($a1)
/* 1081B4 7F0D3684 1441FFB3 */  bne   $v0, $at, .L7F0D3554
/* 1081B8 7F0D3688 24840008 */   addiu $a0, $a0, 8
/* 1081BC 7F0D368C 8FB8003C */  lw    $t8, 0x3c($sp)
/* 1081C0 7F0D3690 8FA20034 */  lw    $v0, 0x34($sp)
/* 1081C4 7F0D3694 24010003 */  li    $at, 3
/* 1081C8 7F0D3698 27190004 */  addiu $t9, $t8, 4
/* 1081CC 7F0D369C 1441FF9F */  bne   $v0, $at, .L7F0D351C
/* 1081D0 7F0D36A0 AFB9003C */   sw    $t9, 0x3c($sp)
/* 1081D4 7F0D36A4 8FBF002C */  lw    $ra, 0x2c($sp)
/* 1081D8 7F0D36A8 8FB00008 */  lw    $s0, 8($sp)
/* 1081DC 7F0D36AC 8FB1000C */  lw    $s1, 0xc($sp)
/* 1081E0 7F0D36B0 8FB20010 */  lw    $s2, 0x10($sp)
/* 1081E4 7F0D36B4 8FB30014 */  lw    $s3, 0x14($sp)
/* 1081E8 7F0D36B8 8FB40018 */  lw    $s4, 0x18($sp)
/* 1081EC 7F0D36BC 8FB5001C */  lw    $s5, 0x1c($sp)
/* 1081F0 7F0D36C0 8FB60020 */  lw    $s6, 0x20($sp)
/* 1081F4 7F0D36C4 8FB70024 */  lw    $s7, 0x24($sp)
/* 1081F8 7F0D36C8 8FBE0028 */  lw    $fp, 0x28($sp)
/* 1081FC 7F0D36CC 27BD00A0 */  addiu $sp, $sp, 0xa0
/* 108200 7F0D36D0 03E00008 */  jr    $ra
/* 108204 7F0D36D4 00801025 */   move  $v0, $a0
)
#endif





#ifdef NONMATCHING
void spectrum_input_handling(void) {

}
#else
GLOBAL_ASM(
.text
glabel spectrum_input_handling
/* 108208 7F0D36D8 AFA50004 */  sw    $a1, 4($sp)
/* 10820C 7F0D36DC 30AE00FF */  andi  $t6, $a1, 0xff
/* 108210 7F0D36E0 30C200FF */  andi  $v0, $a2, 0xff
/* 108214 7F0D36E4 240100FE */  li    $at, 254
/* 108218 7F0D36E8 01C02825 */  move  $a1, $t6
/* 10821C 7F0D36EC AFA40000 */  sw    $a0, ($sp)
/* 108220 7F0D36F0 14410030 */  bne   $v0, $at, .L7F0D37B4
/* 108224 7F0D36F4 AFA60008 */   sw    $a2, 8($sp)
/* 108228 7F0D36F8 3C068005 */  lui   $a2, %hi(D_8004EC34)
/* 10822C 7F0D36FC 240300FF */  li    $v1, 255
/* 108230 7F0D3700 24C6EC34 */  addiu $a2, %lo(D_8004EC34) # addiu $a2, $a2, -0x13cc
/* 108234 7F0D3704 00001025 */  move  $v0, $zero
/* 108238 7F0D3708 24070008 */  li    $a3, 8
.L7F0D370C:
/* 10823C 7F0D370C 30B80001 */  andi  $t8, $a1, 1
/* 108240 7F0D3710 17000006 */  bnez  $t8, .L7F0D372C
/* 108244 7F0D3714 00A02025 */   move  $a0, $a1
/* 108248 7F0D3718 00C2C821 */  addu  $t9, $a2, $v0
/* 10824C 7F0D371C 93280000 */  lbu   $t0, ($t9)
/* 108250 7F0D3720 00681824 */  and   $v1, $v1, $t0
/* 108254 7F0D3724 306900FF */  andi  $t1, $v1, 0xff
/* 108258 7F0D3728 01201825 */  move  $v1, $t1
.L7F0D372C:
/* 10825C 7F0D372C 00042842 */  srl   $a1, $a0, 1
/* 108260 7F0D3730 30A400FF */  andi  $a0, $a1, 0xff
/* 108264 7F0D3734 308B0001 */  andi  $t3, $a0, 1
/* 108268 7F0D3738 15600006 */  bnez  $t3, .L7F0D3754
/* 10826C 7F0D373C 00042842 */   srl   $a1, $a0, 1
/* 108270 7F0D3740 00C26021 */  addu  $t4, $a2, $v0
/* 108274 7F0D3744 918D0001 */  lbu   $t5, 1($t4)
/* 108278 7F0D3748 006D1824 */  and   $v1, $v1, $t5
/* 10827C 7F0D374C 306E00FF */  andi  $t6, $v1, 0xff
/* 108280 7F0D3750 01C01825 */  move  $v1, $t6
.L7F0D3754:
/* 108284 7F0D3754 30A400FF */  andi  $a0, $a1, 0xff
/* 108288 7F0D3758 30980001 */  andi  $t8, $a0, 1
/* 10828C 7F0D375C 17000006 */  bnez  $t8, .L7F0D3778
/* 108290 7F0D3760 00042842 */   srl   $a1, $a0, 1
/* 108294 7F0D3764 00C2C821 */  addu  $t9, $a2, $v0
/* 108298 7F0D3768 93280002 */  lbu   $t0, 2($t9)
/* 10829C 7F0D376C 00681824 */  and   $v1, $v1, $t0
/* 1082A0 7F0D3770 306900FF */  andi  $t1, $v1, 0xff
/* 1082A4 7F0D3774 01201825 */  move  $v1, $t1
.L7F0D3778:
/* 1082A8 7F0D3778 30A400FF */  andi  $a0, $a1, 0xff
/* 1082AC 7F0D377C 308B0001 */  andi  $t3, $a0, 1
/* 1082B0 7F0D3780 15600006 */  bnez  $t3, .L7F0D379C
/* 1082B4 7F0D3784 00042842 */   srl   $a1, $a0, 1
/* 1082B8 7F0D3788 00C26021 */  addu  $t4, $a2, $v0
/* 1082BC 7F0D378C 918D0003 */  lbu   $t5, 3($t4)
/* 1082C0 7F0D3790 006D1824 */  and   $v1, $v1, $t5
/* 1082C4 7F0D3794 306E00FF */  andi  $t6, $v1, 0xff
/* 1082C8 7F0D3798 01C01825 */  move  $v1, $t6
.L7F0D379C:
/* 1082CC 7F0D379C 30AF00FF */  andi  $t7, $a1, 0xff
/* 1082D0 7F0D37A0 24420004 */  addiu $v0, $v0, 4
/* 1082D4 7F0D37A4 1447FFD9 */  bne   $v0, $a3, .L7F0D370C
/* 1082D8 7F0D37A8 01E02825 */   move  $a1, $t7
/* 1082DC 7F0D37AC 03E00008 */  jr    $ra
/* 1082E0 7F0D37B0 00601025 */   move  $v0, $v1

.L7F0D37B4:
/* 1082E4 7F0D37B4 2401001F */  li    $at, 31
/* 1082E8 7F0D37B8 14410003 */  bne   $v0, $at, .L7F0D37C8
/* 1082EC 7F0D37BC 3C028005 */   lui   $v0, %hi(D_8004EC40)
/* 1082F0 7F0D37C0 03E00008 */  jr    $ra
/* 1082F4 7F0D37C4 9042EC40 */   lbu   $v0, %lo(D_8004EC40)($v0)

.L7F0D37C8:
/* 1082F8 7F0D37C8 240200FF */  li    $v0, 255
/* 1082FC 7F0D37CC 03E00008 */  jr    $ra
/* 108300 7F0D37D0 00000000 */   nop   
)
#endif




void nullsub_50(void) {
    return;
}






#ifdef NONMATCHING
void sub_GAME_7F0D37DC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D37DC
/* 10830C 7F0D37DC 30CE00FF */  andi  $t6, $a2, 0xff
/* 108310 7F0D37E0 240100FE */  li    $at, 254
/* 108314 7F0D37E4 AFA40000 */  sw    $a0, ($sp)
/* 108318 7F0D37E8 AFA50004 */  sw    $a1, 4($sp)
/* 10831C 7F0D37EC AFA60008 */  sw    $a2, 8($sp)
/* 108320 7F0D37F0 AFA7000C */  sw    $a3, 0xc($sp)
/* 108324 7F0D37F4 15C1000A */  bne   $t6, $at, .L7F0D3820
/* 108328 7F0D37F8 30EF00FF */   andi  $t7, $a3, 0xff
/* 10832C 7F0D37FC 3C188005 */  lui   $t8, %hi(D_8004ED54) 
/* 108330 7F0D3800 9318ED54 */  lbu   $t8, %lo(D_8004ED54)($t8)
/* 108334 7F0D3804 31E20007 */  andi  $v0, $t7, 7
/* 108338 7F0D3808 3C018005 */  lui   $at, %hi(D_8004ED54)
/* 10833C 7F0D380C 10580002 */  beq   $v0, $t8, .L7F0D3818
/* 108340 7F0D3810 00000000 */   nop   
/* 108344 7F0D3814 A022ED54 */  sb    $v0, %lo(D_8004ED54)($at)
.L7F0D3818:
/* 108348 7F0D3818 03E00008 */  jr    $ra
/* 10834C 7F0D381C 00001025 */   move  $v0, $zero

.L7F0D3820:
/* 108350 7F0D3820 00001025 */  move  $v0, $zero
/* 108354 7F0D3824 03E00008 */  jr    $ra
/* 108358 7F0D3828 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void spectrum_hw_emulation(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005C12C*/
glabel spectrum_op_table
.word spectrum_op_00
.word spectrum_op_01
.word spectrum_op_02
.word spectrum_op_03
.word spectrum_op_04
.word spectrum_op_05
.word spectrum_op_06
.word spectrum_op_07
.word spectrum_op_08
.word spectrum_op_09
.word spectrum_op_0A
.word spectrum_op_0B
.word spectrum_op_0C
.word spectrum_op_0D
.word spectrum_op_0E
.word spectrum_op_0F
.word spectrum_op_10
.word spectrum_op_11
.word spectrum_op_12
.word spectrum_op_13
.word spectrum_op_14
.word spectrum_op_15
.word spectrum_op_16
.word spectrum_op_17
.word spectrum_op_18
.word spectrum_op_19
.word spectrum_op_1A
.word spectrum_op_1B
.word spectrum_op_1C
.word spectrum_op_1D
.word spectrum_op_1E
.word spectrum_op_1F
.word spectrum_op_20
.word spectrum_op_21
.word spectrum_op_22
.word spectrum_op_23
.word spectrum_op_24
.word spectrum_op_25
.word spectrum_op_26
.word spectrum_op_27
.word spectrum_op_28
.word spectrum_op_29
.word spectrum_op_2A
.word spectrum_op_2B
.word spectrum_op_2C
.word spectrum_op_2D
.word spectrum_op_2E
.word spectrum_op_2F
.word spectrum_op_30
.word spectrum_op_31
.word spectrum_op_32
.word spectrum_op_33
.word spectrum_op_34
.word spectrum_op_35
.word spectrum_op_36
.word spectrum_op_37
.word spectrum_op_38
.word spectrum_op_39
.word spectrum_op_3A
.word spectrum_op_3B
.word spectrum_op_3C
.word spectrum_op_3D
.word spectrum_op_3E
.word spectrum_op_3F
.word spectrum_op_40
.word spectrum_op_41
.word spectrum_op_42
.word spectrum_op_43
.word spectrum_op_44
.word spectrum_op_45
.word spectrum_op_46
.word spectrum_op_47
.word spectrum_op_48
.word spectrum_op_49
.word spectrum_op_4A
.word spectrum_op_4B
.word spectrum_op_4C
.word spectrum_op_4D
.word spectrum_op_4E
.word spectrum_op_4F
.word spectrum_op_50
.word spectrum_op_51
.word spectrum_op_52
.word spectrum_op_53
.word spectrum_op_54
.word spectrum_op_55
.word spectrum_op_56
.word spectrum_op_57
.word spectrum_op_58
.word spectrum_op_59
.word spectrum_op_5A
.word spectrum_op_5B
.word spectrum_op_5C
.word spectrum_op_5D
.word spectrum_op_5E
.word spectrum_op_5F
.word spectrum_op_60
.word spectrum_op_61
.word spectrum_op_62
.word spectrum_op_63
.word spectrum_op_64
.word spectrum_op_65
.word spectrum_op_66
.word spectrum_op_67
.word spectrum_op_68
.word spectrum_op_69
.word spectrum_op_6A
.word spectrum_op_6B
.word spectrum_op_6C
.word spectrum_op_6D
.word spectrum_op_6E
.word spectrum_op_6F
.word spectrum_op_70
.word spectrum_op_71
.word spectrum_op_72
.word spectrum_op_73
.word spectrum_op_74
.word spectrum_op_75
.word spectrum_op_76
.word spectrum_op_77
.word spectrum_op_78
.word spectrum_op_79
.word spectrum_op_7A
.word spectrum_op_7B
.word spectrum_op_7C
.word spectrum_op_7D
.word spectrum_op_7E
.word spectrum_op_7F
.word spectrum_op_80
.word spectrum_op_81
.word spectrum_op_82
.word spectrum_op_83
.word spectrum_op_84
.word spectrum_op_85
.word spectrum_op_86
.word spectrum_op_87
.word spectrum_op_88
.word spectrum_op_89
.word spectrum_op_8A
.word spectrum_op_8B
.word spectrum_op_8C
.word spectrum_op_8D
.word spectrum_op_8E
.word spectrum_op_8F
.word spectrum_op_90
.word spectrum_op_91
.word spectrum_op_92
.word spectrum_op_93
.word spectrum_op_94
.word spectrum_op_95
.word spectrum_op_96
.word spectrum_op_97
.word spectrum_op_98
.word spectrum_op_99
.word spectrum_op_9A
.word spectrum_op_9B
.word spectrum_op_9C
.word spectrum_op_9D
.word spectrum_op_9E
.word spectrum_op_9F
.word spectrum_op_A0
.word spectrum_op_A1
.word spectrum_op_A2
.word spectrum_op_A3
.word spectrum_op_A4
.word spectrum_op_A5
.word spectrum_op_A6
.word spectrum_op_A7
.word spectrum_op_A8
.word spectrum_op_A9
.word spectrum_op_AA
.word spectrum_op_AB
.word spectrum_op_AC
.word spectrum_op_AD
.word spectrum_op_AE
.word spectrum_op_AF
.word spectrum_op_B0
.word spectrum_op_B1
.word spectrum_op_B2
.word spectrum_op_B3
.word spectrum_op_B4
.word spectrum_op_B5
.word spectrum_op_B6
.word spectrum_op_B7
.word spectrum_op_B8
.word spectrum_op_B9
.word spectrum_op_BA
.word spectrum_op_BB
.word spectrum_op_BC
.word spectrum_op_BD
.word spectrum_op_BE
.word spectrum_op_BF
.word spectrum_op_C0
.word spectrum_op_C1
.word spectrum_op_C2
.word spectrum_op_C3
.word spectrum_op_C4
.word spectrum_op_C5
.word spectrum_op_C6
.word spectrum_op_C7
.word spectrum_op_C8
.word spectrum_op_C9
.word spectrum_op_CA
.word spectrum_op_CB
.word spectrum_op_CC
.word spectrum_op_CD
.word spectrum_op_CE
.word spectrum_op_CF
.word spectrum_op_D0
.word spectrum_op_D1
.word spectrum_op_D2
.word spectrum_op_D3
.word spectrum_op_D4
.word spectrum_op_D5
.word spectrum_op_D6
.word spectrum_op_D7
.word spectrum_op_D8
.word spectrum_op_D9
.word spectrum_op_DA
.word spectrum_op_DB
.word spectrum_op_DC
.word spectrum_op_DD
.word spectrum_op_DE
.word spectrum_op_DF
.word spectrum_op_E0
.word spectrum_op_E1
.word spectrum_op_E2
.word spectrum_op_E3
.word spectrum_op_E4
.word spectrum_op_E5
.word spectrum_op_E6
.word spectrum_op_E7
.word spectrum_op_E8
.word spectrum_op_E9
.word spectrum_op_EA
.word spectrum_op_EB
.word spectrum_op_EC
.word spectrum_op_ED
.word spectrum_op_EE
.word spectrum_op_EF
.word spectrum_op_F0
.word spectrum_op_F1
.word spectrum_op_F2
.word spectrum_op_F3
.word spectrum_op_F4
.word spectrum_op_F5
.word spectrum_op_F6
.word spectrum_op_F7
.word spectrum_op_F8
.word spectrum_op_F9
.word spectrum_op_FA
.word spectrum_op_FB
.word spectrum_op_FC
.word spectrum_op_FD
.word spectrum_op_FE
.word spectrum_op_FF

/*D:8005C52C*/
glabel jpt_8005C52C
.word spectrum_op_CB_00
.word spectrum_op_CB_01
.word spectrum_op_CB_02
.word spectrum_op_CB_03
.word spectrum_op_CB_04
.word spectrum_op_CB_05
.word spectrum_op_CB_06
.word spectrum_op_CB_07
.word spectrum_op_CB_08
.word spectrum_op_CB_09
.word spectrum_op_CB_0A
.word spectrum_op_CB_0B
.word spectrum_op_CB_0C
.word spectrum_op_CB_0D
.word spectrum_op_CB_0E
.word spectrum_op_CB_0F
.word spectrum_op_CB_10
.word spectrum_op_CB_11
.word spectrum_op_CB_12
.word spectrum_op_CB_13
.word spectrum_op_CB_14
.word spectrum_op_CB_15
.word spectrum_op_CB_16
.word spectrum_op_CB_17
.word spectrum_op_CB_18
.word spectrum_op_CB_19
.word spectrum_op_CB_1A
.word spectrum_op_CB_1B
.word spectrum_op_CB_1C
.word spectrum_op_CB_1D
.word spectrum_op_CB_1E
.word spectrum_op_CB_1F
.word spectrum_op_CB_20
.word spectrum_op_CB_21
.word spectrum_op_CB_22
.word spectrum_op_CB_23
.word spectrum_op_CB_24
.word spectrum_op_CB_25
.word spectrum_op_CB_26
.word spectrum_op_CB_27
.word spectrum_op_CB_28
.word spectrum_op_CB_29
.word spectrum_op_CB_2A
.word spectrum_op_CB_2B
.word spectrum_op_CB_2C
.word spectrum_op_CB_2D
.word spectrum_op_CB_2E
.word spectrum_op_CB_2F
.word spectrum_op_CB_30
.word spectrum_op_CB_31
.word spectrum_op_CB_32
.word spectrum_op_CB_33
.word spectrum_op_CB_34
.word spectrum_op_CB_35
.word spectrum_op_CB_36
.word spectrum_op_CB_37
.word spectrum_op_CB_38
.word spectrum_op_CB_39
.word spectrum_op_CB_3A
.word spectrum_op_CB_3B
.word spectrum_op_CB_3C
.word spectrum_op_CB_3D
.word spectrum_op_CB_3E
.word spectrum_op_CB_3F

/*D:8005C62C*/
glabel jpt_8005C62C
.word spectrum_op_SET_x_B
.word spectrum_op_SET_x_C
.word spectrum_op_SET_x_D
.word spectrum_op_SET_x_E
.word spectrum_op_SET_x_H
.word spectrum_op_SET_x_L
.word spectrum_op_SET_x_HL
.word spectrum_op_SET_x_A

/*D:8005C64C*/
glabel jpt_8005C64C
.word spectrum_op_RES_x_B
.word spectrum_op_RES_x_C
.word spectrum_op_RES_x_D
.word spectrum_op_RES_x_E
.word spectrum_op_RES_x_H
.word spectrum_op_RES_x_L
.word spectrum_op_RES_x_HL
.word spectrum_op_RES_x_A

/*D:8005C66C*/
glabel jpt_8005C66C
.word spectrum_op_BIT_x_B
.word spectrum_op_BIT_x_C
.word spectrum_op_BIT_x_D
.word spectrum_op_BIT_x_E
.word spectrum_op_BIT_x_H
.word spectrum_op_BIT_x_L
.word spectrum_op_BIT_x_HL
.word spectrum_op_BIT_x_A

/*D:8005C68C*/
glabel jpt_8005C68C
.word .L7F0DC5C4
.word .L7F0DC5CC
.word .L7F0DC5D4
.word .L7F0DC5DC
.word .L7F0DC5E4
.word .L7F0DC5EC
.word .L7F0E27FC
.word .L7F0DC5F4

/*D:8005C6AC*/
glabel jpt_8005C6AC
.word spectrum_op_ED_A0
.word spectrum_op_ED_A1
.word spectrum_op_ED_A2
.word spectrum_op_ED_A3
.word .L7F0E1A6C
.word .L7F0E1A6C
.word .L7F0E1A6C
.word .L7F0E1A6C
.word spectrum_op_ED_A8
.word spectrum_op_ED_A9
.word spectrum_op_ED_AA
.word spectrum_op_ED_AB
.word .L7F0E1A6C
.word .L7F0E1A6C
.word .L7F0E1A6C
.word .L7F0E1A6C
.word spectrum_op_ED_B0
.word spectrum_op_ED_B1
.word spectrum_op_ED_B2
.word spectrum_op_ED_B3
.word .L7F0E1A6C
.word .L7F0E1A6C
.word .L7F0E1A6C
.word .L7F0E1A6C
.word spectrum_op_ED_B8
.word spectrum_op_ED_B9
.word spectrum_op_ED_BA
.word spectrum_op_ED_BB

/*D:8005C71C*/
glabel jpt_8005C71C
.word spectrum_op_ED_40
.word spectrum_op_ED_41
.word spectrum_op_ED_42
.word spectrum_op_ED_43
.word spectrum_op_ED_44
.word spectrum_op_ED_45
.word spectrum_op_ED_46
.word spectrum_op_ED_47
.word spectrum_op_ED_48
.word spectrum_op_ED_49
.word spectrum_op_ED_4A
.word spectrum_op_ED_4B
.word spectrum_op_ED_4C
.word spectrum_op_ED_4D
.word spectrum_op_ED_4E
.word spectrum_op_ED_4F
.word spectrum_op_ED_50
.word spectrum_op_ED_51
.word spectrum_op_ED_52
.word spectrum_op_ED_53
.word spectrum_op_ED_54
.word spectrum_op_ED_55
.word spectrum_op_ED_56
.word spectrum_op_ED_57
.word spectrum_op_ED_58
.word spectrum_op_ED_59
.word spectrum_op_ED_5A
.word spectrum_op_ED_5B
.word spectrum_op_ED_5C
.word spectrum_op_ED_5D
.word spectrum_op_ED_5E
.word spectrum_op_ED_5F
.word spectrum_op_ED_60
.word spectrum_op_ED_61
.word spectrum_op_ED_62
.word spectrum_op_ED_63
.word spectrum_op_ED_64
.word spectrum_op_ED_65
.word spectrum_op_ED_66
.word spectrum_op_ED_67
.word spectrum_op_ED_68
.word spectrum_op_ED_69
.word spectrum_op_ED_6A
.word spectrum_op_ED_6B
.word spectrum_op_ED_6C
.word spectrum_op_ED_6D
.word spectrum_op_ED_6E
.word spectrum_op_ED_6F
.word spectrum_op_ED_70
.word spectrum_op_ED_71
.word spectrum_op_ED_72
.word spectrum_op_ED_73
.word spectrum_op_ED_74
.word spectrum_op_ED_75
.word spectrum_op_ED_76
.word .L7F0E1A6C
.word spectrum_op_ED_78
.word spectrum_op_ED_79
.word spectrum_op_ED_7A
.word spectrum_op_ED_7B
.word spectrum_op_ED_7C
.word spectrum_op_ED_7D
.word spectrum_op_ED_7E

.text
glabel spectrum_hw_emulation
/* 10835C 7F0D382C 27BDFD50 */  addiu $sp, $sp, -0x2b0
/* 108360 7F0D3830 3C0E0001 */  lui   $t6, (0x00011100 >> 16) # lui $t6, 1
/* 108364 7F0D3834 35CE1100 */  ori   $t6, (0x00011100 & 0xFFFF) # ori $t6, $t6, 0x1100
/* 108368 7F0D3838 AFAE0280 */  sw    $t6, 0x280($sp)
/* 10836C 7F0D383C 3C0E8009 */  lui   $t6, %hi(byte_CODE_bss_8008E341) 
/* 108370 7F0D3840 91CEE341 */  lbu   $t6, %lo(byte_CODE_bss_8008E341)($t6)
/* 108374 7F0D3844 3C0D8009 */  lui   $t5, %hi(off_CODE_bss_8008E340) 
/* 108378 7F0D3848 3C0F8009 */  lui   $t7, %hi(byte_CODE_bss_8008E342) 
/* 10837C 7F0D384C 3C188009 */  lui   $t8, %hi(byte_CODE_bss_8008E343) 
/* 108380 7F0D3850 3C198009 */  lui   $t9, %hi(off_CODE_bss_8008E344) 
/* 108384 7F0D3854 3C088009 */  lui   $t0, %hi(byte_CODE_bss_8008E345) 
/* 108388 7F0D3858 3C098009 */  lui   $t1, %hi(byte_CODE_bss_8008E346) 
/* 10838C 7F0D385C 91ADE340 */  lbu   $t5, %lo(off_CODE_bss_8008E340)($t5)
/* 108390 7F0D3860 91EFE342 */  lbu   $t7, %lo(byte_CODE_bss_8008E342)($t7)
/* 108394 7F0D3864 9318E343 */  lbu   $t8, %lo(byte_CODE_bss_8008E343)($t8)
/* 108398 7F0D3868 9339E344 */  lbu   $t9, %lo(off_CODE_bss_8008E344)($t9)
/* 10839C 7F0D386C 9108E345 */  lbu   $t0, %lo(byte_CODE_bss_8008E345)($t0)
/* 1083A0 7F0D3870 9129E346 */  lbu   $t1, %lo(byte_CODE_bss_8008E346)($t1)
/* 1083A4 7F0D3874 A3A002A5 */  sb    $zero, 0x2a5($sp)
/* 1083A8 7F0D3878 A3A002A0 */  sb    $zero, 0x2a0($sp)
/* 1083AC 7F0D387C A3A002A1 */  sb    $zero, 0x2a1($sp)
/* 1083B0 7F0D3880 A3A002A2 */  sb    $zero, 0x2a2($sp)
/* 1083B4 7F0D3884 A3A002A3 */  sb    $zero, 0x2a3($sp)
/* 1083B8 7F0D3888 A3A002A4 */  sb    $zero, 0x2a4($sp)
/* 1083BC 7F0D388C A3A002A6 */  sb    $zero, 0x2a6($sp)
/* 1083C0 7F0D3890 A3AE02A5 */  sb    $t6, 0x2a5($sp)
/* 1083C4 7F0D3894 3C0E8009 */  lui   $t6, %hi(byte_CODE_bss_8008E349) 
/* 1083C8 7F0D3898 A3AD02A6 */  sb    $t5, 0x2a6($sp)
/* 1083CC 7F0D389C A3AF02A4 */  sb    $t7, 0x2a4($sp)
/* 1083D0 7F0D38A0 A3B802A3 */  sb    $t8, 0x2a3($sp)
/* 1083D4 7F0D38A4 A3B902A2 */  sb    $t9, 0x2a2($sp)
/* 1083D8 7F0D38A8 A3A802A1 */  sb    $t0, 0x2a1($sp)
/* 1083DC 7F0D38AC A3A902A0 */  sb    $t1, 0x2a0($sp)
/* 1083E0 7F0D38B0 91CEE349 */  lbu   $t6, %lo(byte_CODE_bss_8008E349)($t6)
/* 1083E4 7F0D38B4 3C0A8009 */  lui   $t2, %hi(byte_CODE_bss_8008E347) 
/* 1083E8 7F0D38B8 3C0B8009 */  lui   $t3, %hi(spec_IFF2_lower) 
/* 1083EC 7F0D38BC 3C0C8009 */  lui   $t4, %hi(spec_IFF2_upper) 
/* 1083F0 7F0D38C0 3C0D8009 */  lui   $t5, %hi(spec_I) 
/* 1083F4 7F0D38C4 3C0F8009 */  lui   $t7, %hi(spec_IM) 
/* 1083F8 7F0D38C8 3C188009 */  lui   $t8, %hi(spec_IX) 
/* 1083FC 7F0D38CC 3C198009 */  lui   $t9, %hi(spec_IY) 
/* 108400 7F0D38D0 3C088009 */  lui   $t0, %hi(spec_SP) 
/* 108404 7F0D38D4 3C098009 */  lui   $t1, %hi(spec_PC) 
/* 108408 7F0D38D8 914AE347 */  lbu   $t2, %lo(byte_CODE_bss_8008E347)($t2)
/* 10840C 7F0D38DC 916BE34A */  lbu   $t3, %lo(spec_IFF2_lower)($t3)
/* 108410 7F0D38E0 918CE34B */  lbu   $t4, %lo(spec_IFF2_upper)($t4)
/* 108414 7F0D38E4 91ADE348 */  lbu   $t5, %lo(spec_I)($t5)
/* 108418 7F0D38E8 91EFE34C */  lbu   $t7, %lo(spec_IM)($t7)
/* 10841C 7F0D38EC 9718E34E */  lhu   $t8, %lo(spec_IX)($t8)
/* 108420 7F0D38F0 9739E350 */  lhu   $t9, %lo(spec_IY)($t9)
/* 108424 7F0D38F4 9508E352 */  lhu   $t0, %lo(spec_SP)($t0)
/* 108428 7F0D38F8 9529E354 */  lhu   $t1, %lo(spec_PC)($t1)
/* 10842C 7F0D38FC AFB70030 */  sw    $s7, 0x30($sp)
/* 108430 7F0D3900 AFB6002C */  sw    $s6, 0x2c($sp)
/* 108434 7F0D3904 AFB50028 */  sw    $s5, 0x28($sp)
/* 108438 7F0D3908 AFB40024 */  sw    $s4, 0x24($sp)
/* 10843C 7F0D390C AFB30020 */  sw    $s3, 0x20($sp)
/* 108440 7F0D3910 AFB2001C */  sw    $s2, 0x1c($sp)
/* 108444 7F0D3914 AFB10018 */  sw    $s1, 0x18($sp)
/* 108448 7F0D3918 AFB00014 */  sw    $s0, 0x14($sp)
/* 10844C 7F0D391C 3C010001 */  lui   $at, (0x00011100 >> 16) # lui $at, 1
/* 108450 7F0D3920 A3A0029B */  sb    $zero, 0x29b($sp)
/* 108454 7F0D3924 A3A0029C */  sb    $zero, 0x29c($sp)
/* 108458 7F0D3928 A3A0029D */  sb    $zero, 0x29d($sp)
/* 10845C 7F0D392C A3A002A7 */  sb    $zero, 0x2a7($sp)
/* 108460 7F0D3930 A3A0029E */  sb    $zero, 0x29e($sp)
/* 108464 7F0D3934 A3A0029F */  sb    $zero, 0x29f($sp)
/* 108468 7F0D3938 A7A00298 */  sh    $zero, 0x298($sp)
/* 10846C 7F0D393C A7A00292 */  sh    $zero, 0x292($sp)
/* 108470 7F0D3940 A7A00294 */  sh    $zero, 0x294($sp)
/* 108474 7F0D3944 A7A00296 */  sh    $zero, 0x296($sp)
/* 108478 7F0D3948 AFA00288 */  sw    $zero, 0x288($sp)
/* 10847C 7F0D394C 3C108009 */  lui   $s0, %hi(spectrum_header16_15)
/* 108480 7F0D3950 3C118009 */  lui   $s1, %hi(byte_CODE_bss_8008E339)
/* 108484 7F0D3954 3C128009 */  lui   $s2, %hi(byte_CODE_bss_8008E33A)
/* 108488 7F0D3958 3C138009 */  lui   $s3, %hi(byte_CODE_bss_8008E33B)
/* 10848C 7F0D395C 3C148009 */  lui   $s4, %hi(off_CODE_bss_8008E33C)
/* 108490 7F0D3960 3C158009 */  lui   $s5, %hi(byte_CODE_bss_8008E33D)
/* 108494 7F0D3964 3C168009 */  lui   $s6, %hi(byte_CODE_bss_8008E33E)
/* 108498 7F0D3968 3C178009 */  lui   $s7, %hi(byte_CODE_bss_8008E33F) 
/* 10849C 7F0D396C 34211100 */  ori   $at, (0x00011100 & 0xFFFF) # ori $at, $at, 0x1100
/* 1084A0 7F0D3970 AFBF0034 */  sw    $ra, 0x34($sp)
/* 1084A4 7F0D3974 A3A00286 */  sb    $zero, 0x286($sp)
/* 1084A8 7F0D3978 A3A00287 */  sb    $zero, 0x287($sp)
/* 1084AC 7F0D397C AFA0028C */  sw    $zero, 0x28c($sp)
/* 1084B0 7F0D3980 9210E338 */  lbu   $s0, %lo(spectrum_header16_15)($s0)
/* 1084B4 7F0D3984 9231E339 */  lbu   $s1, %lo(byte_CODE_bss_8008E339)($s1)
/* 1084B8 7F0D3988 9252E33A */  lbu   $s2, %lo(byte_CODE_bss_8008E33A)($s2)
/* 1084BC 7F0D398C 9273E33B */  lbu   $s3, %lo(byte_CODE_bss_8008E33B)($s3)
/* 1084C0 7F0D3990 9294E33C */  lbu   $s4, %lo(off_CODE_bss_8008E33C)($s4)
/* 1084C4 7F0D3994 92B5E33D */  lbu   $s5, %lo(byte_CODE_bss_8008E33D)($s5)
/* 1084C8 7F0D3998 92D6E33E */  lbu   $s6, %lo(byte_CODE_bss_8008E33E)($s6)
/* 1084CC 7F0D399C 92F7E33F */  lbu   $s7, %lo(byte_CODE_bss_8008E33F)($s7)
/* 1084D0 7F0D39A0 A3AE02A7 */  sb    $t6, 0x2a7($sp)
/* 1084D4 7F0D39A4 AFAE0288 */  sw    $t6, 0x288($sp)
/* 1084D8 7F0D39A8 A3AA029F */  sb    $t2, 0x29f($sp)
/* 1084DC 7F0D39AC A3AB029D */  sb    $t3, 0x29d($sp)
/* 1084E0 7F0D39B0 A3AC029C */  sb    $t4, 0x29c($sp)
/* 1084E4 7F0D39B4 A3AD029E */  sb    $t5, 0x29e($sp)
/* 1084E8 7F0D39B8 A3AF029B */  sb    $t7, 0x29b($sp)
/* 1084EC 7F0D39BC A7B80296 */  sh    $t8, 0x296($sp)
/* 1084F0 7F0D39C0 A7B90294 */  sh    $t9, 0x294($sp)
/* 1084F4 7F0D39C4 A7A80292 */  sh    $t0, 0x292($sp)
/* 1084F8 7F0D39C8 14200003 */  bnez  $at, .L7F0D39D8
/* 1084FC 7F0D39CC A7A90298 */   sh    $t1, 0x298($sp)
/* 108500 7F0D39D0 93AB0285 */  lbu   $t3, 0x285($sp)
/* 108504 7F0D39D4 15603B91 */  bnez  $t3, .L7F0E281C
.L7F0D39D8:
/* 108508 7F0D39D8 3C0F8009 */   lui   $t7, %hi(ptr_spectrum_roms) 
/* 10850C 7F0D39DC 93AC0286 */  lbu   $t4, 0x286($sp)
/* 108510 7F0D39E0 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 108514 7F0D39E4 97AE0298 */  lhu   $t6, 0x298($sp)
/* 108518 7F0D39E8 240D0001 */  li    $t5, 1
/* 10851C 7F0D39EC A3A00286 */  sb    $zero, 0x286($sp)
/* 108520 7F0D39F0 A3AD0285 */  sb    $t5, 0x285($sp)
/* 108524 7F0D39F4 A3AC0287 */  sb    $t4, 0x287($sp)
/* 108528 7F0D39F8 01CFC021 */  addu  $t8, $t6, $t7
/* 10852C 7F0D39FC 93190000 */  lbu   $t9, ($t8)
/* 108530 7F0D3A00 8FA90288 */  lw    $t1, 0x288($sp)
/* 108534 7F0D3A04 25C80001 */  addiu $t0, $t6, 1
/* 108538 7F0D3A08 332B00FF */  andi  $t3, $t9, 0xff
/* 10853C 7F0D3A0C 2D610100 */  sltiu $at, $t3, 0x100
/* 108540 7F0D3A10 252A0001 */  addiu $t2, $t1, 1
/* 108544 7F0D3A14 A7A80298 */  sh    $t0, 0x298($sp)
/* 108548 7F0D3A18 AFAA0288 */  sw    $t2, 0x288($sp)
/* 10854C 7F0D3A1C 10203B77 */  beqz  $at, .L7F0E27FC
/* 108550 7F0D3A20 A3B90284 */   sb    $t9, 0x284($sp)
/* 108554 7F0D3A24 000B5880 */  sll   $t3, $t3, 2
/* 108558 7F0D3A28 3C018006 */  lui   $at, %hi(spectrum_op_table)
/* 10855C 7F0D3A2C 002B0821 */  addu  $at, $at, $t3
/* 108560 7F0D3A30 8C2BC12C */  lw    $t3, %lo(spectrum_op_table)($at)
/* 108564 7F0D3A34 01600008 */  jr    $t3
/* 108568 7F0D3A38 00000000 */   nop   
spectrum_op_00:
/* 10856C 7F0D3A3C 8FAC028C */  lw    $t4, 0x28c($sp)
/* 108570 7F0D3A40 258D0004 */  addiu $t5, $t4, 4
/* 108574 7F0D3A44 10003B6D */  b     .L7F0E27FC
/* 108578 7F0D3A48 AFAD028C */   sw    $t5, 0x28c($sp)
spectrum_op_01:
/* 10857C 7F0D3A4C 8FAF028C */  lw    $t7, 0x28c($sp)
/* 108580 7F0D3A50 97B90298 */  lhu   $t9, 0x298($sp)
/* 108584 7F0D3A54 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 108588 7F0D3A58 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10858C 7F0D3A5C 25F8000A */  addiu $t8, $t7, 0xa
/* 108590 7F0D3A60 AFB8028C */  sw    $t8, 0x28c($sp)
/* 108594 7F0D3A64 272C0001 */  addiu $t4, $t9, 1
/* 108598 7F0D3A68 032E4021 */  addu  $t0, $t9, $t6
/* 10859C 7F0D3A6C 91130000 */  lbu   $s3, ($t0)
/* 1085A0 7F0D3A70 318AFFFF */  andi  $t2, $t4, 0xffff
/* 1085A4 7F0D3A74 A7AC0298 */  sh    $t4, 0x298($sp)
/* 1085A8 7F0D3A78 014E5821 */  addu  $t3, $t2, $t6
/* 1085AC 7F0D3A7C 91720000 */  lbu   $s2, ($t3)
/* 1085B0 7F0D3A80 258D0001 */  addiu $t5, $t4, 1
/* 1085B4 7F0D3A84 10003B5D */  b     .L7F0E27FC
/* 1085B8 7F0D3A88 A7AD0298 */   sh    $t5, 0x298($sp)
spectrum_op_02:
/* 1085BC 7F0D3A8C 8FAF028C */  lw    $t7, 0x28c($sp)
/* 1085C0 7F0D3A90 00124200 */  sll   $t0, $s2, 8
/* 1085C4 7F0D3A94 0113C825 */  or    $t9, $t0, $s3
/* 1085C8 7F0D3A98 2B215B00 */  slti  $at, $t9, 0x5b00
/* 1085CC 7F0D3A9C 25F80007 */  addiu $t8, $t7, 7
/* 1085D0 7F0D3AA0 14200008 */  bnez  $at, .L7F0D3AC4
/* 1085D4 7F0D3AA4 AFB8028C */   sw    $t8, 0x28c($sp)
/* 1085D8 7F0D3AA8 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 1085DC 7F0D3AAC 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 1085E0 7F0D3AB0 00127200 */  sll   $t6, $s2, 8
/* 1085E4 7F0D3AB4 01D35825 */  or    $t3, $t6, $s3
/* 1085E8 7F0D3AB8 014B4821 */  addu  $t1, $t2, $t3
/* 1085EC 7F0D3ABC 10003B4F */  b     .L7F0E27FC
/* 1085F0 7F0D3AC0 A1300000 */   sb    $s0, ($t1)
.L7F0D3AC4:
/* 1085F4 7F0D3AC4 00126200 */  sll   $t4, $s2, 8
/* 1085F8 7F0D3AC8 01936825 */  or    $t5, $t4, $s3
/* 1085FC 7F0D3ACC 29A15800 */  slti  $at, $t5, 0x5800
/* 108600 7F0D3AD0 1420000F */  bnez  $at, .L7F0D3B10
/* 108604 7F0D3AD4 00126A00 */   sll   $t5, $s2, 8
/* 108608 7F0D3AD8 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 10860C 7F0D3ADC 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 108610 7F0D3AE0 0012C200 */  sll   $t8, $s2, 8
/* 108614 7F0D3AE4 03134025 */  or    $t0, $t8, $s3
/* 108618 7F0D3AE8 01E8C821 */  addu  $t9, $t7, $t0
/* 10861C 7F0D3AEC A3300000 */  sb    $s0, ($t9)
/* 108620 7F0D3AF0 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 108624 7F0D3AF4 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 108628 7F0D3AF8 00125A00 */  sll   $t3, $s2, 8
/* 10862C 7F0D3AFC 01734825 */  or    $t1, $t3, $s3
/* 108630 7F0D3B00 240E0001 */  li    $t6, 1
/* 108634 7F0D3B04 01496021 */  addu  $t4, $t2, $t1
/* 108638 7F0D3B08 10003B3C */  b     .L7F0E27FC
/* 10863C 7F0D3B0C A18EA800 */   sb    $t6, -0x5800($t4)
.L7F0D3B10:
/* 108640 7F0D3B10 01B3C025 */  or    $t8, $t5, $s3
/* 108644 7F0D3B14 2B014000 */  slti  $at, $t8, 0x4000
/* 108648 7F0D3B18 14203B38 */  bnez  $at, .L7F0E27FC
/* 10864C 7F0D3B1C 3C0F8009 */   lui   $t7, %hi(ptr_spectrum_roms) 
/* 108650 7F0D3B20 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 108654 7F0D3B24 00124200 */  sll   $t0, $s2, 8
/* 108658 7F0D3B28 0113C825 */  or    $t9, $t0, $s3
/* 10865C 7F0D3B2C 01F95821 */  addu  $t3, $t7, $t9
/* 108660 7F0D3B30 A1700000 */  sb    $s0, ($t3)
/* 108664 7F0D3B34 00124A00 */  sll   $t1, $s2, 8
/* 108668 7F0D3B38 01337025 */  or    $t6, $t1, $s3
/* 10866C 7F0D3B3C 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 108670 7F0D3B40 0012C200 */  sll   $t8, $s2, 8
/* 108674 7F0D3B44 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 108678 7F0D3B48 03134025 */  or    $t0, $t8, $s3
/* 10867C 7F0D3B4C 31CC1800 */  andi  $t4, $t6, 0x1800
/* 108680 7F0D3B50 000C68C3 */  sra   $t5, $t4, 3
/* 108684 7F0D3B54 310F00FF */  andi  $t7, $t0, 0xff
/* 108688 7F0D3B58 01AFC825 */  or    $t9, $t5, $t7
/* 10868C 7F0D3B5C 240A0001 */  li    $t2, 1
/* 108690 7F0D3B60 01794821 */  addu  $t1, $t3, $t9
/* 108694 7F0D3B64 10003B25 */  b     .L7F0E27FC
/* 108698 7F0D3B68 A12A0000 */   sb    $t2, ($t1)
spectrum_op_03:
/* 10869C 7F0D3B6C 8FAE028C */  lw    $t6, 0x28c($sp)
/* 1086A0 7F0D3B70 26730001 */  addiu $s3, $s3, 1
/* 1086A4 7F0D3B74 327800FF */  andi  $t8, $s3, 0xff
/* 1086A8 7F0D3B78 25CC0006 */  addiu $t4, $t6, 6
/* 1086AC 7F0D3B7C AFAC028C */  sw    $t4, 0x28c($sp)
/* 1086B0 7F0D3B80 17003B1E */  bnez  $t8, .L7F0E27FC
/* 1086B4 7F0D3B84 03009825 */   move  $s3, $t8
/* 1086B8 7F0D3B88 26520001 */  addiu $s2, $s2, 1
/* 1086BC 7F0D3B8C 324800FF */  andi  $t0, $s2, 0xff
/* 1086C0 7F0D3B90 10003B1A */  b     .L7F0E27FC
/* 1086C4 7F0D3B94 01009025 */   move  $s2, $t0
spectrum_op_04:
/* 1086C8 7F0D3B98 26520001 */  addiu $s2, $s2, 1
/* 1086CC 7F0D3B9C 324B00FF */  andi  $t3, $s2, 0xff
/* 1086D0 7F0D3BA0 8FAD028C */  lw    $t5, 0x28c($sp)
/* 1086D4 7F0D3BA4 316A000F */  andi  $t2, $t3, 0xf
/* 1086D8 7F0D3BA8 2D490001 */  sltiu $t1, $t2, 1
/* 1086DC 7F0D3BAC 01609025 */  move  $s2, $t3
/* 1086E0 7F0D3BB0 2D790001 */  sltiu $t9, $t3, 1
/* 1086E4 7F0D3BB4 316C00A8 */  andi  $t4, $t3, 0xa8
/* 1086E8 7F0D3BB8 322E0001 */  andi  $t6, $s1, 1
/* 1086EC 7F0D3BBC 01CCC025 */  or    $t8, $t6, $t4
/* 1086F0 7F0D3BC0 3A4A0080 */  xori  $t2, $s2, 0x80
/* 1086F4 7F0D3BC4 00094100 */  sll   $t0, $t1, 4
/* 1086F8 7F0D3BC8 25AF0004 */  addiu $t7, $t5, 4
/* 1086FC 7F0D3BCC 03086825 */  or    $t5, $t8, $t0
/* 108700 7F0D3BD0 2D4A0001 */  sltiu $t2, $t2, 1
/* 108704 7F0D3BD4 00195980 */  sll   $t3, $t9, 6
/* 108708 7F0D3BD8 AFB90044 */  sw    $t9, 0x44($sp)
/* 10870C 7F0D3BDC 01ABC825 */  or    $t9, $t5, $t3
/* 108710 7F0D3BE0 000A7080 */  sll   $t6, $t2, 2
/* 108714 7F0D3BE4 032E8825 */  or    $s1, $t9, $t6
/* 108718 7F0D3BE8 322C00FF */  andi  $t4, $s1, 0xff
/* 10871C 7F0D3BEC AFAF028C */  sw    $t7, 0x28c($sp)
/* 108720 7F0D3BF0 01808825 */  move  $s1, $t4
/* 108724 7F0D3BF4 10003B01 */  b     .L7F0E27FC
/* 108728 7F0D3BF8 AFA90048 */   sw    $t1, 0x48($sp)
spectrum_op_05:
/* 10872C 7F0D3BFC 8FA9028C */  lw    $t1, 0x28c($sp)
/* 108730 7F0D3C00 3248000F */  andi  $t0, $s2, 0xf
/* 108734 7F0D3C04 2652FFFF */  addiu $s2, $s2, -1
/* 108738 7F0D3C08 25380004 */  addiu $t8, $t1, 4
/* 10873C 7F0D3C0C AFB8028C */  sw    $t8, 0x28c($sp)
/* 108740 7F0D3C10 324E00FF */  andi  $t6, $s2, 0xff
/* 108744 7F0D3C14 2D0F0001 */  sltiu $t7, $t0, 1
/* 108748 7F0D3C18 000F5900 */  sll   $t3, $t7, 4
/* 10874C 7F0D3C1C 39D8007F */  xori  $t8, $t6, 0x7f
/* 108750 7F0D3C20 2F180001 */  sltiu $t8, $t8, 1
/* 108754 7F0D3C24 322D0001 */  andi  $t5, $s1, 1
/* 108758 7F0D3C28 01AB8825 */  or    $s1, $t5, $t3
/* 10875C 7F0D3C2C 00184080 */  sll   $t0, $t8, 2
/* 108760 7F0D3C30 AFAF0048 */  sw    $t7, 0x48($sp)
/* 108764 7F0D3C34 2DCC0001 */  sltiu $t4, $t6, 1
/* 108768 7F0D3C38 31C900A8 */  andi  $t1, $t6, 0xa8
/* 10876C 7F0D3C3C 01287825 */  or    $t7, $t1, $t0
/* 108770 7F0D3C40 000C5980 */  sll   $t3, $t4, 6
/* 108774 7F0D3C44 01EB5025 */  or    $t2, $t7, $t3
/* 108778 7F0D3C48 36390002 */  ori   $t9, $s1, 2
/* 10877C 7F0D3C4C 032A8825 */  or    $s1, $t9, $t2
/* 108780 7F0D3C50 323900FF */  andi  $t9, $s1, 0xff
/* 108784 7F0D3C54 03208825 */  move  $s1, $t9
/* 108788 7F0D3C58 AFAC0044 */  sw    $t4, 0x44($sp)
/* 10878C 7F0D3C5C 10003AE7 */  b     .L7F0E27FC
/* 108790 7F0D3C60 01C09025 */   move  $s2, $t6
spectrum_op_06:
/* 108794 7F0D3C64 8FAE028C */  lw    $t6, 0x28c($sp)
/* 108798 7F0D3C68 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10879C 7F0D3C6C 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 1087A0 7F0D3C70 97B80298 */  lhu   $t8, 0x298($sp)
/* 1087A4 7F0D3C74 25CC0007 */  addiu $t4, $t6, 7
/* 1087A8 7F0D3C78 AFAC028C */  sw    $t4, 0x28c($sp)
/* 1087AC 7F0D3C7C 03094021 */  addu  $t0, $t8, $t1
/* 1087B0 7F0D3C80 91120000 */  lbu   $s2, ($t0)
/* 1087B4 7F0D3C84 270D0001 */  addiu $t5, $t8, 1
/* 1087B8 7F0D3C88 10003ADC */  b     .L7F0E27FC
/* 1087BC 7F0D3C8C A7AD0298 */   sh    $t5, 0x298($sp)
spectrum_op_07:
/* 1087C0 7F0D3C90 00105040 */  sll   $t2, $s0, 1
/* 1087C4 7F0D3C94 0010C9C3 */  sra   $t9, $s0, 7
/* 1087C8 7F0D3C98 01598025 */  or    $s0, $t2, $t9
/* 1087CC 7F0D3C9C 8FAF028C */  lw    $t7, 0x28c($sp)
/* 1087D0 7F0D3CA0 320E00FF */  andi  $t6, $s0, 0xff
/* 1087D4 7F0D3CA4 31C90029 */  andi  $t1, $t6, 0x29
/* 1087D8 7F0D3CA8 322C00C4 */  andi  $t4, $s1, 0xc4
/* 1087DC 7F0D3CAC 01898825 */  or    $s1, $t4, $t1
/* 1087E0 7F0D3CB0 322800FF */  andi  $t0, $s1, 0xff
/* 1087E4 7F0D3CB4 25EB0004 */  addiu $t3, $t7, 4
/* 1087E8 7F0D3CB8 AFAB028C */  sw    $t3, 0x28c($sp)
/* 1087EC 7F0D3CBC 01C08025 */  move  $s0, $t6
/* 1087F0 7F0D3CC0 10003ACE */  b     .L7F0E27FC
/* 1087F4 7F0D3CC4 01008825 */   move  $s1, $t0
spectrum_op_08:
/* 1087F8 7F0D3CC8 8FB8028C */  lw    $t8, 0x28c($sp)
/* 1087FC 7F0D3CCC A3B0027F */  sb    $s0, 0x27f($sp)
/* 108800 7F0D3CD0 A3B1027E */  sb    $s1, 0x27e($sp)
/* 108804 7F0D3CD4 93AF027F */  lbu   $t7, 0x27f($sp)
/* 108808 7F0D3CD8 93AB027E */  lbu   $t3, 0x27e($sp)
/* 10880C 7F0D3CDC 93B002A6 */  lbu   $s0, 0x2a6($sp)
/* 108810 7F0D3CE0 93B102A5 */  lbu   $s1, 0x2a5($sp)
/* 108814 7F0D3CE4 270D0004 */  addiu $t5, $t8, 4
/* 108818 7F0D3CE8 AFAD028C */  sw    $t5, 0x28c($sp)
/* 10881C 7F0D3CEC A3AF02A6 */  sb    $t7, 0x2a6($sp)
/* 108820 7F0D3CF0 10003AC2 */  b     .L7F0E27FC
/* 108824 7F0D3CF4 A3AB02A5 */   sb    $t3, 0x2a5($sp)
spectrum_op_09:
/* 108828 7F0D3CF8 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10882C 7F0D3CFC 93AE0287 */  lbu   $t6, 0x287($sp)
/* 108830 7F0D3D00 93A90287 */  lbu   $t1, 0x287($sp)
/* 108834 7F0D3D04 2559000B */  addiu $t9, $t2, 0xb
/* 108838 7F0D3D08 15C0001C */  bnez  $t6, .L7F0D3D7C
/* 10883C 7F0D3D0C AFB9028C */   sw    $t9, 0x28c($sp)
/* 108840 7F0D3D10 02F36021 */  addu  $t4, $s7, $s3
/* 108844 7F0D3D14 3189FFFF */  andi  $t1, $t4, 0xffff
/* 108848 7F0D3D18 00094202 */  srl   $t0, $t1, 8
/* 10884C 7F0D3D1C 310DFFFF */  andi  $t5, $t0, 0xffff
/* 108850 7F0D3D20 32D8000F */  andi  $t8, $s6, 0xf
/* 108854 7F0D3D24 01B87821 */  addu  $t7, $t5, $t8
/* 108858 7F0D3D28 324B000F */  andi  $t3, $s2, 0xf
/* 10885C 7F0D3D2C 01EB5021 */  addu  $t2, $t7, $t3
/* 108860 7F0D3D30 A7AC027C */  sh    $t4, 0x27c($sp)
/* 108864 7F0D3D34 2401000F */  li    $at, 15
/* 108868 7F0D3D38 002AC82A */  slt   $t9, $at, $t2
/* 10886C 7F0D3D3C 93B7027D */  lbu   $s7, 0x27d($sp)
/* 108870 7F0D3D40 02D26821 */  addu  $t5, $s6, $s2
/* 108874 7F0D3D44 010D5021 */  addu  $t2, $t0, $t5
/* 108878 7F0D3D48 A7A8027C */  sh    $t0, 0x27c($sp)
/* 10887C 7F0D3D4C A7AA027C */  sh    $t2, 0x27c($sp)
/* 108880 7F0D3D50 93B6027D */  lbu   $s6, 0x27d($sp)
/* 108884 7F0D3D54 00197100 */  sll   $t6, $t9, 4
/* 108888 7F0D3D58 322C00C4 */  andi  $t4, $s1, 0xc4
/* 10888C 7F0D3D5C 01CC4825 */  or    $t1, $t6, $t4
/* 108890 7F0D3D60 000ACA03 */  sra   $t9, $t2, 8
/* 108894 7F0D3D64 32CB0028 */  andi  $t3, $s6, 0x28
/* 108898 7F0D3D68 01797025 */  or    $t6, $t3, $t9
/* 10889C 7F0D3D6C 012E8825 */  or    $s1, $t1, $t6
/* 1088A0 7F0D3D70 322C00FF */  andi  $t4, $s1, 0xff
/* 1088A4 7F0D3D74 10003AA1 */  b     .L7F0E27FC
/* 1088A8 7F0D3D78 01808825 */   move  $s1, $t4
.L7F0D3D7C:
/* 1088AC 7F0D3D7C 24010001 */  li    $at, 1
/* 1088B0 7F0D3D80 15210004 */  bne   $t1, $at, .L7F0D3D94
/* 1088B4 7F0D3D84 00125200 */   sll   $t2, $s2, 8
/* 1088B8 7F0D3D88 97A80296 */  lhu   $t0, 0x296($sp)
/* 1088BC 7F0D3D8C 10000003 */  b     .L7F0D3D9C
/* 1088C0 7F0D3D90 AFA80278 */   sw    $t0, 0x278($sp)
.L7F0D3D94:
/* 1088C4 7F0D3D94 97B80294 */  lhu   $t8, 0x294($sp)
/* 1088C8 7F0D3D98 AFB80278 */  sw    $t8, 0x278($sp)
.L7F0D3D9C:
/* 1088CC 7F0D3D9C 8FAD0278 */  lw    $t5, 0x278($sp)
/* 1088D0 7F0D3DA0 01535825 */  or    $t3, $t2, $s3
/* 1088D4 7F0D3DA4 24010FFF */  li    $at, 4095
/* 1088D8 7F0D3DA8 31AF0FFF */  andi  $t7, $t5, 0xfff
/* 1088DC 7F0D3DAC 01EBC821 */  addu  $t9, $t7, $t3
/* 1088E0 7F0D3DB0 0039702B */  sltu  $t6, $at, $t9
/* 1088E4 7F0D3DB4 93AB0287 */  lbu   $t3, 0x287($sp)
/* 1088E8 7F0D3DB8 000E6100 */  sll   $t4, $t6, 4
/* 1088EC 7F0D3DBC 322900C4 */  andi  $t1, $s1, 0xc4
/* 1088F0 7F0D3DC0 0012C200 */  sll   $t8, $s2, 8
/* 1088F4 7F0D3DC4 03135025 */  or    $t2, $t8, $s3
/* 1088F8 7F0D3DC8 012C8825 */  or    $s1, $t1, $t4
/* 1088FC 7F0D3DCC 322800FF */  andi  $t0, $s1, 0xff
/* 108900 7F0D3DD0 24010001 */  li    $at, 1
/* 108904 7F0D3DD4 01AA7821 */  addu  $t7, $t5, $t2
/* 108908 7F0D3DD8 AFAF0278 */  sw    $t7, 0x278($sp)
/* 10890C 7F0D3DDC 15610003 */  bne   $t3, $at, .L7F0D3DEC
/* 108910 7F0D3DE0 01008825 */   move  $s1, $t0
/* 108914 7F0D3DE4 10000003 */  b     .L7F0D3DF4
/* 108918 7F0D3DE8 A7AF0296 */   sh    $t7, 0x296($sp)
.L7F0D3DEC:
/* 10891C 7F0D3DEC 8FB90278 */  lw    $t9, 0x278($sp)
/* 108920 7F0D3DF0 A7B90294 */  sh    $t9, 0x294($sp)
.L7F0D3DF4:
/* 108924 7F0D3DF4 8FAE0278 */  lw    $t6, 0x278($sp)
/* 108928 7F0D3DF8 000E4A02 */  srl   $t1, $t6, 8
/* 10892C 7F0D3DFC 312C0028 */  andi  $t4, $t1, 0x28
/* 108930 7F0D3E00 000E4402 */  srl   $t0, $t6, 0x10
/* 108934 7F0D3E04 0188C025 */  or    $t8, $t4, $t0
/* 108938 7F0D3E08 02388825 */  or    $s1, $s1, $t8
/* 10893C 7F0D3E0C 322D00FF */  andi  $t5, $s1, 0xff
/* 108940 7F0D3E10 10003A7A */  b     .L7F0E27FC
/* 108944 7F0D3E14 01A08825 */   move  $s1, $t5
spectrum_op_0A:
/* 108948 7F0D3E18 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10894C 7F0D3E1C 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 108950 7F0D3E20 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 108954 7F0D3E24 00127A00 */  sll   $t7, $s2, 8
/* 108958 7F0D3E28 01F3C825 */  or    $t9, $t7, $s3
/* 10895C 7F0D3E2C 254B0007 */  addiu $t3, $t2, 7
/* 108960 7F0D3E30 AFAB028C */  sw    $t3, 0x28c($sp)
/* 108964 7F0D3E34 03297021 */  addu  $t6, $t9, $t1
/* 108968 7F0D3E38 10003A70 */  b     .L7F0E27FC
/* 10896C 7F0D3E3C 91D00000 */   lbu   $s0, ($t6)
spectrum_op_0B:
/* 108970 7F0D3E40 8FAC028C */  lw    $t4, 0x28c($sp)
/* 108974 7F0D3E44 2E780001 */  sltiu $t8, $s3, 1
/* 108978 7F0D3E48 2673FFFF */  addiu $s3, $s3, -1
/* 10897C 7F0D3E4C 326D00FF */  andi  $t5, $s3, 0xff
/* 108980 7F0D3E50 25880006 */  addiu $t0, $t4, 6
/* 108984 7F0D3E54 AFA8028C */  sw    $t0, 0x28c($sp)
/* 108988 7F0D3E58 01A09825 */  move  $s3, $t5
/* 10898C 7F0D3E5C 13003A67 */  beqz  $t8, .L7F0E27FC
/* 108990 7F0D3E60 AFB80048 */   sw    $t8, 0x48($sp)
/* 108994 7F0D3E64 2652FFFF */  addiu $s2, $s2, -1
/* 108998 7F0D3E68 324B00FF */  andi  $t3, $s2, 0xff
/* 10899C 7F0D3E6C 10003A63 */  b     .L7F0E27FC
/* 1089A0 7F0D3E70 01609025 */   move  $s2, $t3
spectrum_op_0C:
/* 1089A4 7F0D3E74 26730001 */  addiu $s3, $s3, 1
/* 1089A8 7F0D3E78 326900FF */  andi  $t1, $s3, 0xff
/* 1089AC 7F0D3E7C 8FAF028C */  lw    $t7, 0x28c($sp)
/* 1089B0 7F0D3E80 312C000F */  andi  $t4, $t1, 0xf
/* 1089B4 7F0D3E84 2D880001 */  sltiu $t0, $t4, 1
/* 1089B8 7F0D3E88 01209825 */  move  $s3, $t1
/* 1089BC 7F0D3E8C 2D2E0001 */  sltiu $t6, $t1, 1
/* 1089C0 7F0D3E90 312D00A8 */  andi  $t5, $t1, 0xa8
/* 1089C4 7F0D3E94 32380001 */  andi  $t8, $s1, 1
/* 1089C8 7F0D3E98 030D5025 */  or    $t2, $t8, $t5
/* 1089CC 7F0D3E9C 3A6C0080 */  xori  $t4, $s3, 0x80
/* 1089D0 7F0D3EA0 00085900 */  sll   $t3, $t0, 4
/* 1089D4 7F0D3EA4 25F90004 */  addiu $t9, $t7, 4
/* 1089D8 7F0D3EA8 014B7825 */  or    $t7, $t2, $t3
/* 1089DC 7F0D3EAC 2D8C0001 */  sltiu $t4, $t4, 1
/* 1089E0 7F0D3EB0 000E4980 */  sll   $t1, $t6, 6
/* 1089E4 7F0D3EB4 AFAE0044 */  sw    $t6, 0x44($sp)
/* 1089E8 7F0D3EB8 01E97025 */  or    $t6, $t7, $t1
/* 1089EC 7F0D3EBC 000CC080 */  sll   $t8, $t4, 2
/* 1089F0 7F0D3EC0 01D88825 */  or    $s1, $t6, $t8
/* 1089F4 7F0D3EC4 322D00FF */  andi  $t5, $s1, 0xff
/* 1089F8 7F0D3EC8 AFB9028C */  sw    $t9, 0x28c($sp)
/* 1089FC 7F0D3ECC 01A08825 */  move  $s1, $t5
/* 108A00 7F0D3ED0 10003A4A */  b     .L7F0E27FC
/* 108A04 7F0D3ED4 AFA80048 */   sw    $t0, 0x48($sp)
spectrum_op_0D:
/* 108A08 7F0D3ED8 8FA8028C */  lw    $t0, 0x28c($sp)
/* 108A0C 7F0D3EDC 326B000F */  andi  $t3, $s3, 0xf
/* 108A10 7F0D3EE0 2673FFFF */  addiu $s3, $s3, -1
/* 108A14 7F0D3EE4 250A0004 */  addiu $t2, $t0, 4
/* 108A18 7F0D3EE8 AFAA028C */  sw    $t2, 0x28c($sp)
/* 108A1C 7F0D3EEC 327800FF */  andi  $t8, $s3, 0xff
/* 108A20 7F0D3EF0 2D790001 */  sltiu $t9, $t3, 1
/* 108A24 7F0D3EF4 00194900 */  sll   $t1, $t9, 4
/* 108A28 7F0D3EF8 3B0A007F */  xori  $t2, $t8, 0x7f
/* 108A2C 7F0D3EFC 2D4A0001 */  sltiu $t2, $t2, 1
/* 108A30 7F0D3F00 322F0001 */  andi  $t7, $s1, 1
/* 108A34 7F0D3F04 01E98825 */  or    $s1, $t7, $t1
/* 108A38 7F0D3F08 000A5880 */  sll   $t3, $t2, 2
/* 108A3C 7F0D3F0C AFB90048 */  sw    $t9, 0x48($sp)
/* 108A40 7F0D3F10 2F0D0001 */  sltiu $t5, $t8, 1
/* 108A44 7F0D3F14 330800A8 */  andi  $t0, $t8, 0xa8
/* 108A48 7F0D3F18 010BC825 */  or    $t9, $t0, $t3
/* 108A4C 7F0D3F1C 000D4980 */  sll   $t1, $t5, 6
/* 108A50 7F0D3F20 03296025 */  or    $t4, $t9, $t1
/* 108A54 7F0D3F24 362E0002 */  ori   $t6, $s1, 2
/* 108A58 7F0D3F28 01CC8825 */  or    $s1, $t6, $t4
/* 108A5C 7F0D3F2C 322E00FF */  andi  $t6, $s1, 0xff
/* 108A60 7F0D3F30 01C08825 */  move  $s1, $t6
/* 108A64 7F0D3F34 AFAD0044 */  sw    $t5, 0x44($sp)
/* 108A68 7F0D3F38 10003A30 */  b     .L7F0E27FC
/* 108A6C 7F0D3F3C 03009825 */   move  $s3, $t8
spectrum_op_0E:
/* 108A70 7F0D3F40 8FB8028C */  lw    $t8, 0x28c($sp)
/* 108A74 7F0D3F44 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 108A78 7F0D3F48 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 108A7C 7F0D3F4C 97AA0298 */  lhu   $t2, 0x298($sp)
/* 108A80 7F0D3F50 270D0007 */  addiu $t5, $t8, 7
/* 108A84 7F0D3F54 AFAD028C */  sw    $t5, 0x28c($sp)
/* 108A88 7F0D3F58 01485821 */  addu  $t3, $t2, $t0
/* 108A8C 7F0D3F5C 91730000 */  lbu   $s3, ($t3)
/* 108A90 7F0D3F60 254F0001 */  addiu $t7, $t2, 1
/* 108A94 7F0D3F64 10003A25 */  b     .L7F0E27FC
/* 108A98 7F0D3F68 A7AF0298 */   sh    $t7, 0x298($sp)
spectrum_op_0F:
/* 108A9C 7F0D3F6C 320E0001 */  andi  $t6, $s0, 1
/* 108AA0 7F0D3F70 00106843 */  sra   $t5, $s0, 1
/* 108AA4 7F0D3F74 001041C0 */  sll   $t0, $s0, 7
/* 108AA8 7F0D3F78 01A88025 */  or    $s0, $t5, $t0
/* 108AAC 7F0D3F7C 8FB9028C */  lw    $t9, 0x28c($sp)
/* 108AB0 7F0D3F80 322C00C4 */  andi  $t4, $s1, 0xc4
/* 108AB4 7F0D3F84 320B00FF */  andi  $t3, $s0, 0xff
/* 108AB8 7F0D3F88 018EC025 */  or    $t8, $t4, $t6
/* 108ABC 7F0D3F8C 316A0028 */  andi  $t2, $t3, 0x28
/* 108AC0 7F0D3F90 030A8825 */  or    $s1, $t8, $t2
/* 108AC4 7F0D3F94 322F00FF */  andi  $t7, $s1, 0xff
/* 108AC8 7F0D3F98 27290004 */  addiu $t1, $t9, 4
/* 108ACC 7F0D3F9C AFA9028C */  sw    $t1, 0x28c($sp)
/* 108AD0 7F0D3FA0 01608025 */  move  $s0, $t3
/* 108AD4 7F0D3FA4 10003A15 */  b     .L7F0E27FC
/* 108AD8 7F0D3FA8 01E08825 */   move  $s1, $t7
spectrum_op_10:
/* 108ADC 7F0D3FAC 8FB9028C */  lw    $t9, 0x28c($sp)
/* 108AE0 7F0D3FB0 2652FFFF */  addiu $s2, $s2, -1
/* 108AE4 7F0D3FB4 324C00FF */  andi  $t4, $s2, 0xff
/* 108AE8 7F0D3FB8 27290008 */  addiu $t1, $t9, 8
/* 108AEC 7F0D3FBC AFA9028C */  sw    $t1, 0x28c($sp)
/* 108AF0 7F0D3FC0 15800005 */  bnez  $t4, .L7F0D3FD8
/* 108AF4 7F0D3FC4 01809025 */   move  $s2, $t4
/* 108AF8 7F0D3FC8 97AE0298 */  lhu   $t6, 0x298($sp)
/* 108AFC 7F0D3FCC 25D80001 */  addiu $t8, $t6, 1
/* 108B00 7F0D3FD0 10003A0A */  b     .L7F0E27FC
/* 108B04 7F0D3FD4 A7B80298 */   sh    $t8, 0x298($sp)
.L7F0D3FD8:
/* 108B08 7F0D3FD8 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 108B0C 7F0D3FDC 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 108B10 7F0D3FE0 97AD0298 */  lhu   $t5, 0x298($sp)
/* 108B14 7F0D3FE4 8FA9028C */  lw    $t1, 0x28c($sp)
/* 108B18 7F0D3FE8 01A85821 */  addu  $t3, $t5, $t0
/* 108B1C 7F0D3FEC 816A0000 */  lb    $t2, ($t3)
/* 108B20 7F0D3FF0 252C0005 */  addiu $t4, $t1, 5
/* 108B24 7F0D3FF4 AFAC028C */  sw    $t4, 0x28c($sp)
/* 108B28 7F0D3FF8 01AA7821 */  addu  $t7, $t5, $t2
/* 108B2C 7F0D3FFC 25F90001 */  addiu $t9, $t7, 1
/* 108B30 7F0D4000 A7B90298 */  sh    $t9, 0x298($sp)
/* 108B34 7F0D4004 100039FD */  b     .L7F0E27FC
/* 108B38 7F0D4008 AFAA0274 */   sw    $t2, 0x274($sp)
spectrum_op_11:
/* 108B3C 7F0D400C 8FAE028C */  lw    $t6, 0x28c($sp)
/* 108B40 7F0D4010 97A80298 */  lhu   $t0, 0x298($sp)
/* 108B44 7F0D4014 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 108B48 7F0D4018 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 108B4C 7F0D401C 25D8000A */  addiu $t8, $t6, 0xa
/* 108B50 7F0D4020 AFB8028C */  sw    $t8, 0x28c($sp)
/* 108B54 7F0D4024 25090001 */  addiu $t1, $t0, 1
/* 108B58 7F0D4028 010B6821 */  addu  $t5, $t0, $t3
/* 108B5C 7F0D402C 91B50000 */  lbu   $s5, ($t5)
/* 108B60 7F0D4030 312FFFFF */  andi  $t7, $t1, 0xffff
/* 108B64 7F0D4034 A7A90298 */  sh    $t1, 0x298($sp)
/* 108B68 7F0D4038 01EBC821 */  addu  $t9, $t7, $t3
/* 108B6C 7F0D403C 93340000 */  lbu   $s4, ($t9)
/* 108B70 7F0D4040 252C0001 */  addiu $t4, $t1, 1
/* 108B74 7F0D4044 100039ED */  b     .L7F0E27FC
/* 108B78 7F0D4048 A7AC0298 */   sh    $t4, 0x298($sp)
spectrum_op_12:
/* 108B7C 7F0D404C 8FAE028C */  lw    $t6, 0x28c($sp)
/* 108B80 7F0D4050 00146A00 */  sll   $t5, $s4, 8
/* 108B84 7F0D4054 01B54025 */  or    $t0, $t5, $s5
/* 108B88 7F0D4058 29015B00 */  slti  $at, $t0, 0x5b00
/* 108B8C 7F0D405C 25D80007 */  addiu $t8, $t6, 7
/* 108B90 7F0D4060 14200008 */  bnez  $at, .L7F0D4084
/* 108B94 7F0D4064 AFB8028C */   sw    $t8, 0x28c($sp)
/* 108B98 7F0D4068 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 108B9C 7F0D406C 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 108BA0 7F0D4070 00145A00 */  sll   $t3, $s4, 8
/* 108BA4 7F0D4074 0175C825 */  or    $t9, $t3, $s5
/* 108BA8 7F0D4078 01F95021 */  addu  $t2, $t7, $t9
/* 108BAC 7F0D407C 100039DF */  b     .L7F0E27FC
/* 108BB0 7F0D4080 A1500000 */   sb    $s0, ($t2)
.L7F0D4084:
/* 108BB4 7F0D4084 00144A00 */  sll   $t1, $s4, 8
/* 108BB8 7F0D4088 01356025 */  or    $t4, $t1, $s5
/* 108BBC 7F0D408C 29815800 */  slti  $at, $t4, 0x5800
/* 108BC0 7F0D4090 1420000F */  bnez  $at, .L7F0D40D0
/* 108BC4 7F0D4094 00146200 */   sll   $t4, $s4, 8
/* 108BC8 7F0D4098 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 108BCC 7F0D409C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 108BD0 7F0D40A0 0014C200 */  sll   $t8, $s4, 8
/* 108BD4 7F0D40A4 03156825 */  or    $t5, $t8, $s5
/* 108BD8 7F0D40A8 01CD4021 */  addu  $t0, $t6, $t5
/* 108BDC 7F0D40AC A1100000 */  sb    $s0, ($t0)
/* 108BE0 7F0D40B0 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 108BE4 7F0D40B4 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 108BE8 7F0D40B8 0014CA00 */  sll   $t9, $s4, 8
/* 108BEC 7F0D40BC 03355025 */  or    $t2, $t9, $s5
/* 108BF0 7F0D40C0 240B0001 */  li    $t3, 1
/* 108BF4 7F0D40C4 01EA4821 */  addu  $t1, $t7, $t2
/* 108BF8 7F0D40C8 100039CC */  b     .L7F0E27FC
/* 108BFC 7F0D40CC A12BA800 */   sb    $t3, -0x5800($t1)
.L7F0D40D0:
/* 108C00 7F0D40D0 0195C025 */  or    $t8, $t4, $s5
/* 108C04 7F0D40D4 2B014000 */  slti  $at, $t8, 0x4000
/* 108C08 7F0D40D8 142039C8 */  bnez  $at, .L7F0E27FC
/* 108C0C 7F0D40DC 3C0E8009 */   lui   $t6, %hi(ptr_spectrum_roms) 
/* 108C10 7F0D40E0 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 108C14 7F0D40E4 00146A00 */  sll   $t5, $s4, 8
/* 108C18 7F0D40E8 01B54025 */  or    $t0, $t5, $s5
/* 108C1C 7F0D40EC 01C8C821 */  addu  $t9, $t6, $t0
/* 108C20 7F0D40F0 A3300000 */  sb    $s0, ($t9)
/* 108C24 7F0D40F4 00145200 */  sll   $t2, $s4, 8
/* 108C28 7F0D40F8 01555825 */  or    $t3, $t2, $s5
/* 108C2C 7F0D40FC 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 108C30 7F0D4100 0014C200 */  sll   $t8, $s4, 8
/* 108C34 7F0D4104 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 108C38 7F0D4108 03156825 */  or    $t5, $t8, $s5
/* 108C3C 7F0D410C 31691800 */  andi  $t1, $t3, 0x1800
/* 108C40 7F0D4110 000960C3 */  sra   $t4, $t1, 3
/* 108C44 7F0D4114 31AE00FF */  andi  $t6, $t5, 0xff
/* 108C48 7F0D4118 018E4025 */  or    $t0, $t4, $t6
/* 108C4C 7F0D411C 240F0001 */  li    $t7, 1
/* 108C50 7F0D4120 03285021 */  addu  $t2, $t9, $t0
/* 108C54 7F0D4124 100039B5 */  b     .L7F0E27FC
/* 108C58 7F0D4128 A14F0000 */   sb    $t7, ($t2)
spectrum_op_13:
/* 108C5C 7F0D412C 8FAB028C */  lw    $t3, 0x28c($sp)
/* 108C60 7F0D4130 26B50001 */  addiu $s5, $s5, 1
/* 108C64 7F0D4134 32B800FF */  andi  $t8, $s5, 0xff
/* 108C68 7F0D4138 25690006 */  addiu $t1, $t3, 6
/* 108C6C 7F0D413C AFA9028C */  sw    $t1, 0x28c($sp)
/* 108C70 7F0D4140 170039AE */  bnez  $t8, .L7F0E27FC
/* 108C74 7F0D4144 0300A825 */   move  $s5, $t8
/* 108C78 7F0D4148 26940001 */  addiu $s4, $s4, 1
/* 108C7C 7F0D414C 328D00FF */  andi  $t5, $s4, 0xff
/* 108C80 7F0D4150 100039AA */  b     .L7F0E27FC
/* 108C84 7F0D4154 01A0A025 */   move  $s4, $t5
spectrum_op_14:
/* 108C88 7F0D4158 26940001 */  addiu $s4, $s4, 1
/* 108C8C 7F0D415C 329900FF */  andi  $t9, $s4, 0xff
/* 108C90 7F0D4160 8FAC028C */  lw    $t4, 0x28c($sp)
/* 108C94 7F0D4164 332F000F */  andi  $t7, $t9, 0xf
/* 108C98 7F0D4168 2DEA0001 */  sltiu $t2, $t7, 1
/* 108C9C 7F0D416C 0320A025 */  move  $s4, $t9
/* 108CA0 7F0D4170 2F280001 */  sltiu $t0, $t9, 1
/* 108CA4 7F0D4174 332900A8 */  andi  $t1, $t9, 0xa8
/* 108CA8 7F0D4178 322B0001 */  andi  $t3, $s1, 1
/* 108CAC 7F0D417C 0169C025 */  or    $t8, $t3, $t1
/* 108CB0 7F0D4180 3A8F0080 */  xori  $t7, $s4, 0x80
/* 108CB4 7F0D4184 000A6900 */  sll   $t5, $t2, 4
/* 108CB8 7F0D4188 258E0004 */  addiu $t6, $t4, 4
/* 108CBC 7F0D418C 030D6025 */  or    $t4, $t8, $t5
/* 108CC0 7F0D4190 2DEF0001 */  sltiu $t7, $t7, 1
/* 108CC4 7F0D4194 0008C980 */  sll   $t9, $t0, 6
/* 108CC8 7F0D4198 AFA80044 */  sw    $t0, 0x44($sp)
/* 108CCC 7F0D419C 01994025 */  or    $t0, $t4, $t9
/* 108CD0 7F0D41A0 000F5880 */  sll   $t3, $t7, 2
/* 108CD4 7F0D41A4 010B8825 */  or    $s1, $t0, $t3
/* 108CD8 7F0D41A8 322900FF */  andi  $t1, $s1, 0xff
/* 108CDC 7F0D41AC AFAE028C */  sw    $t6, 0x28c($sp)
/* 108CE0 7F0D41B0 01208825 */  move  $s1, $t1
/* 108CE4 7F0D41B4 10003991 */  b     .L7F0E27FC
/* 108CE8 7F0D41B8 AFAA0048 */   sw    $t2, 0x48($sp)
spectrum_op_15:
/* 108CEC 7F0D41BC 8FAA028C */  lw    $t2, 0x28c($sp)
/* 108CF0 7F0D41C0 328D000F */  andi  $t5, $s4, 0xf
/* 108CF4 7F0D41C4 2694FFFF */  addiu $s4, $s4, -1
/* 108CF8 7F0D41C8 25580004 */  addiu $t8, $t2, 4
/* 108CFC 7F0D41CC AFB8028C */  sw    $t8, 0x28c($sp)
/* 108D00 7F0D41D0 328B00FF */  andi  $t3, $s4, 0xff
/* 108D04 7F0D41D4 2DAE0001 */  sltiu $t6, $t5, 1
/* 108D08 7F0D41D8 000EC900 */  sll   $t9, $t6, 4
/* 108D0C 7F0D41DC 3978007F */  xori  $t8, $t3, 0x7f
/* 108D10 7F0D41E0 2F180001 */  sltiu $t8, $t8, 1
/* 108D14 7F0D41E4 322C0001 */  andi  $t4, $s1, 1
/* 108D18 7F0D41E8 01998825 */  or    $s1, $t4, $t9
/* 108D1C 7F0D41EC 00186880 */  sll   $t5, $t8, 2
/* 108D20 7F0D41F0 AFAE0048 */  sw    $t6, 0x48($sp)
/* 108D24 7F0D41F4 2D690001 */  sltiu $t1, $t3, 1
/* 108D28 7F0D41F8 316A00A8 */  andi  $t2, $t3, 0xa8
/* 108D2C 7F0D41FC 014D7025 */  or    $t6, $t2, $t5
/* 108D30 7F0D4200 0009C980 */  sll   $t9, $t1, 6
/* 108D34 7F0D4204 01D97825 */  or    $t7, $t6, $t9
/* 108D38 7F0D4208 36280002 */  ori   $t0, $s1, 2
/* 108D3C 7F0D420C 010F8825 */  or    $s1, $t0, $t7
/* 108D40 7F0D4210 322800FF */  andi  $t0, $s1, 0xff
/* 108D44 7F0D4214 01008825 */  move  $s1, $t0
/* 108D48 7F0D4218 AFA90044 */  sw    $t1, 0x44($sp)
/* 108D4C 7F0D421C 10003977 */  b     .L7F0E27FC
/* 108D50 7F0D4220 0160A025 */   move  $s4, $t3
spectrum_op_16:
/* 108D54 7F0D4224 8FAB028C */  lw    $t3, 0x28c($sp)
/* 108D58 7F0D4228 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 108D5C 7F0D422C 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 108D60 7F0D4230 97B80298 */  lhu   $t8, 0x298($sp)
/* 108D64 7F0D4234 25690007 */  addiu $t1, $t3, 7
/* 108D68 7F0D4238 AFA9028C */  sw    $t1, 0x28c($sp)
/* 108D6C 7F0D423C 030A6821 */  addu  $t5, $t8, $t2
/* 108D70 7F0D4240 91B40000 */  lbu   $s4, ($t5)
/* 108D74 7F0D4244 270C0001 */  addiu $t4, $t8, 1
/* 108D78 7F0D4248 1000396C */  b     .L7F0E27FC
/* 108D7C 7F0D424C A7AC0298 */   sh    $t4, 0x298($sp)
spectrum_op_17:
/* 108D80 7F0D4250 001079C3 */  sra   $t7, $s0, 7
/* 108D84 7F0D4254 00104040 */  sll   $t0, $s0, 1
/* 108D88 7F0D4258 322B0001 */  andi  $t3, $s1, 1
/* 108D8C 7F0D425C 010B8025 */  or    $s0, $t0, $t3
/* 108D90 7F0D4260 8FAE028C */  lw    $t6, 0x28c($sp)
/* 108D94 7F0D4264 320900FF */  andi  $t1, $s0, 0xff
/* 108D98 7F0D4268 312D0028 */  andi  $t5, $t1, 0x28
/* 108D9C 7F0D426C 322A00C4 */  andi  $t2, $s1, 0xc4
/* 108DA0 7F0D4270 014DC025 */  or    $t8, $t2, $t5
/* 108DA4 7F0D4274 030F8825 */  or    $s1, $t8, $t7
/* 108DA8 7F0D4278 25D90004 */  addiu $t9, $t6, 4
/* 108DAC 7F0D427C 322E00FF */  andi  $t6, $s1, 0xff
/* 108DB0 7F0D4280 AFB9028C */  sw    $t9, 0x28c($sp)
/* 108DB4 7F0D4284 AFAF0270 */  sw    $t7, 0x270($sp)
/* 108DB8 7F0D4288 01208025 */  move  $s0, $t1
/* 108DBC 7F0D428C 1000395B */  b     .L7F0E27FC
/* 108DC0 7F0D4290 01C08825 */   move  $s1, $t6
spectrum_op_18:
/* 108DC4 7F0D4294 8FB9028C */  lw    $t9, 0x28c($sp)
/* 108DC8 7F0D4298 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 108DCC 7F0D429C 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 108DD0 7F0D42A0 97A80298 */  lhu   $t0, 0x298($sp)
/* 108DD4 7F0D42A4 272F0007 */  addiu $t7, $t9, 7
/* 108DD8 7F0D42A8 AFAF028C */  sw    $t7, 0x28c($sp)
/* 108DDC 7F0D42AC 010B4821 */  addu  $t1, $t0, $t3
/* 108DE0 7F0D42B0 812A0000 */  lb    $t2, ($t1)
/* 108DE4 7F0D42B4 25EE0005 */  addiu $t6, $t7, 5
/* 108DE8 7F0D42B8 AFAE028C */  sw    $t6, 0x28c($sp)
/* 108DEC 7F0D42BC 010A6821 */  addu  $t5, $t0, $t2
/* 108DF0 7F0D42C0 25B80001 */  addiu $t8, $t5, 1
/* 108DF4 7F0D42C4 A7B80298 */  sh    $t8, 0x298($sp)
/* 108DF8 7F0D42C8 1000394C */  b     .L7F0E27FC
/* 108DFC 7F0D42CC AFAA026C */   sw    $t2, 0x26c($sp)
spectrum_op_19:
/* 108E00 7F0D42D0 8FB9028C */  lw    $t9, 0x28c($sp)
/* 108E04 7F0D42D4 93AB0287 */  lbu   $t3, 0x287($sp)
/* 108E08 7F0D42D8 93A80287 */  lbu   $t0, 0x287($sp)
/* 108E0C 7F0D42DC 272F000B */  addiu $t7, $t9, 0xb
/* 108E10 7F0D42E0 1560001C */  bnez  $t3, .L7F0D4354
/* 108E14 7F0D42E4 AFAF028C */   sw    $t7, 0x28c($sp)
/* 108E18 7F0D42E8 02F54821 */  addu  $t1, $s7, $s5
/* 108E1C 7F0D42EC 3128FFFF */  andi  $t0, $t1, 0xffff
/* 108E20 7F0D42F0 00085202 */  srl   $t2, $t0, 8
/* 108E24 7F0D42F4 3158FFFF */  andi  $t8, $t2, 0xffff
/* 108E28 7F0D42F8 32CD000F */  andi  $t5, $s6, 0xf
/* 108E2C 7F0D42FC 030D6021 */  addu  $t4, $t8, $t5
/* 108E30 7F0D4300 328E000F */  andi  $t6, $s4, 0xf
/* 108E34 7F0D4304 018EC821 */  addu  $t9, $t4, $t6
/* 108E38 7F0D4308 A7A9026A */  sh    $t1, 0x26a($sp)
/* 108E3C 7F0D430C 2401000F */  li    $at, 15
/* 108E40 7F0D4310 0039782A */  slt   $t7, $at, $t9
/* 108E44 7F0D4314 93B7026B */  lbu   $s7, 0x26b($sp)
/* 108E48 7F0D4318 02D4C021 */  addu  $t8, $s6, $s4
/* 108E4C 7F0D431C 0158C821 */  addu  $t9, $t2, $t8
/* 108E50 7F0D4320 A7AA026A */  sh    $t2, 0x26a($sp)
/* 108E54 7F0D4324 A7B9026A */  sh    $t9, 0x26a($sp)
/* 108E58 7F0D4328 93B6026B */  lbu   $s6, 0x26b($sp)
/* 108E5C 7F0D432C 000F5900 */  sll   $t3, $t7, 4
/* 108E60 7F0D4330 322900C4 */  andi  $t1, $s1, 0xc4
/* 108E64 7F0D4334 01694025 */  or    $t0, $t3, $t1
/* 108E68 7F0D4338 00197A03 */  sra   $t7, $t9, 8
/* 108E6C 7F0D433C 32CE0028 */  andi  $t6, $s6, 0x28
/* 108E70 7F0D4340 01CF5825 */  or    $t3, $t6, $t7
/* 108E74 7F0D4344 010B8825 */  or    $s1, $t0, $t3
/* 108E78 7F0D4348 322900FF */  andi  $t1, $s1, 0xff
/* 108E7C 7F0D434C 1000392B */  b     .L7F0E27FC
/* 108E80 7F0D4350 01208825 */   move  $s1, $t1
.L7F0D4354:
/* 108E84 7F0D4354 24010001 */  li    $at, 1
/* 108E88 7F0D4358 15010004 */  bne   $t0, $at, .L7F0D436C
/* 108E8C 7F0D435C 0014CA00 */   sll   $t9, $s4, 8
/* 108E90 7F0D4360 97AA0296 */  lhu   $t2, 0x296($sp)
/* 108E94 7F0D4364 10000003 */  b     .L7F0D4374
/* 108E98 7F0D4368 AFAA0264 */   sw    $t2, 0x264($sp)
.L7F0D436C:
/* 108E9C 7F0D436C 97AD0294 */  lhu   $t5, 0x294($sp)
/* 108EA0 7F0D4370 AFAD0264 */  sw    $t5, 0x264($sp)
.L7F0D4374:
/* 108EA4 7F0D4374 8FB80264 */  lw    $t8, 0x264($sp)
/* 108EA8 7F0D4378 03357025 */  or    $t6, $t9, $s5
/* 108EAC 7F0D437C 24010FFF */  li    $at, 4095
/* 108EB0 7F0D4380 330C0FFF */  andi  $t4, $t8, 0xfff
/* 108EB4 7F0D4384 018E7821 */  addu  $t7, $t4, $t6
/* 108EB8 7F0D4388 002F582B */  sltu  $t3, $at, $t7
/* 108EBC 7F0D438C 93AE0287 */  lbu   $t6, 0x287($sp)
/* 108EC0 7F0D4390 000B4900 */  sll   $t1, $t3, 4
/* 108EC4 7F0D4394 322800C4 */  andi  $t0, $s1, 0xc4
/* 108EC8 7F0D4398 00146A00 */  sll   $t5, $s4, 8
/* 108ECC 7F0D439C 01B5C825 */  or    $t9, $t5, $s5
/* 108ED0 7F0D43A0 01098825 */  or    $s1, $t0, $t1
/* 108ED4 7F0D43A4 322A00FF */  andi  $t2, $s1, 0xff
/* 108ED8 7F0D43A8 24010001 */  li    $at, 1
/* 108EDC 7F0D43AC 03196021 */  addu  $t4, $t8, $t9
/* 108EE0 7F0D43B0 AFAC0264 */  sw    $t4, 0x264($sp)
/* 108EE4 7F0D43B4 15C10003 */  bne   $t6, $at, .L7F0D43C4
/* 108EE8 7F0D43B8 01408825 */   move  $s1, $t2
/* 108EEC 7F0D43BC 10000003 */  b     .L7F0D43CC
/* 108EF0 7F0D43C0 A7AC0296 */   sh    $t4, 0x296($sp)
.L7F0D43C4:
/* 108EF4 7F0D43C4 8FAF0264 */  lw    $t7, 0x264($sp)
/* 108EF8 7F0D43C8 A7AF0294 */  sh    $t7, 0x294($sp)
.L7F0D43CC:
/* 108EFC 7F0D43CC 8FAB0264 */  lw    $t3, 0x264($sp)
/* 108F00 7F0D43D0 000B4202 */  srl   $t0, $t3, 8
/* 108F04 7F0D43D4 31090028 */  andi  $t1, $t0, 0x28
/* 108F08 7F0D43D8 000B5402 */  srl   $t2, $t3, 0x10
/* 108F0C 7F0D43DC 012A6825 */  or    $t5, $t1, $t2
/* 108F10 7F0D43E0 022D8825 */  or    $s1, $s1, $t5
/* 108F14 7F0D43E4 323800FF */  andi  $t8, $s1, 0xff
/* 108F18 7F0D43E8 10003904 */  b     .L7F0E27FC
/* 108F1C 7F0D43EC 03008825 */   move  $s1, $t8
spectrum_op_1A:
/* 108F20 7F0D43F0 8FB9028C */  lw    $t9, 0x28c($sp)
/* 108F24 7F0D43F4 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 108F28 7F0D43F8 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 108F2C 7F0D43FC 00146200 */  sll   $t4, $s4, 8
/* 108F30 7F0D4400 01957825 */  or    $t7, $t4, $s5
/* 108F34 7F0D4404 272E0007 */  addiu $t6, $t9, 7
/* 108F38 7F0D4408 AFAE028C */  sw    $t6, 0x28c($sp)
/* 108F3C 7F0D440C 01E85821 */  addu  $t3, $t7, $t0
/* 108F40 7F0D4410 100038FA */  b     .L7F0E27FC
/* 108F44 7F0D4414 91700000 */   lbu   $s0, ($t3)
spectrum_op_1B:
/* 108F48 7F0D4418 8FA9028C */  lw    $t1, 0x28c($sp)
/* 108F4C 7F0D441C 2EAD0001 */  sltiu $t5, $s5, 1
/* 108F50 7F0D4420 26B5FFFF */  addiu $s5, $s5, -1
/* 108F54 7F0D4424 32B800FF */  andi  $t8, $s5, 0xff
/* 108F58 7F0D4428 252A0006 */  addiu $t2, $t1, 6
/* 108F5C 7F0D442C AFAA028C */  sw    $t2, 0x28c($sp)
/* 108F60 7F0D4430 0300A825 */  move  $s5, $t8
/* 108F64 7F0D4434 11A038F1 */  beqz  $t5, .L7F0E27FC
/* 108F68 7F0D4438 AFAD0048 */   sw    $t5, 0x48($sp)
/* 108F6C 7F0D443C 2694FFFF */  addiu $s4, $s4, -1
/* 108F70 7F0D4440 328E00FF */  andi  $t6, $s4, 0xff
/* 108F74 7F0D4444 100038ED */  b     .L7F0E27FC
/* 108F78 7F0D4448 01C0A025 */   move  $s4, $t6
spectrum_op_1C:
/* 108F7C 7F0D444C 26B50001 */  addiu $s5, $s5, 1
/* 108F80 7F0D4450 32A800FF */  andi  $t0, $s5, 0xff
/* 108F84 7F0D4454 8FAC028C */  lw    $t4, 0x28c($sp)
/* 108F88 7F0D4458 3109000F */  andi  $t1, $t0, 0xf
/* 108F8C 7F0D445C 2D2A0001 */  sltiu $t2, $t1, 1
/* 108F90 7F0D4460 0100A825 */  move  $s5, $t0
/* 108F94 7F0D4464 2D0B0001 */  sltiu $t3, $t0, 1
/* 108F98 7F0D4468 311800A8 */  andi  $t8, $t0, 0xa8
/* 108F9C 7F0D446C 322D0001 */  andi  $t5, $s1, 1
/* 108FA0 7F0D4470 01B8C825 */  or    $t9, $t5, $t8
/* 108FA4 7F0D4474 3AA90080 */  xori  $t1, $s5, 0x80
/* 108FA8 7F0D4478 000A7100 */  sll   $t6, $t2, 4
/* 108FAC 7F0D447C 258F0004 */  addiu $t7, $t4, 4
/* 108FB0 7F0D4480 032E6025 */  or    $t4, $t9, $t6
/* 108FB4 7F0D4484 2D290001 */  sltiu $t1, $t1, 1
/* 108FB8 7F0D4488 000B4180 */  sll   $t0, $t3, 6
/* 108FBC 7F0D448C AFAB0044 */  sw    $t3, 0x44($sp)
/* 108FC0 7F0D4490 01885825 */  or    $t3, $t4, $t0
/* 108FC4 7F0D4494 00096880 */  sll   $t5, $t1, 2
/* 108FC8 7F0D4498 016D8825 */  or    $s1, $t3, $t5
/* 108FCC 7F0D449C 323800FF */  andi  $t8, $s1, 0xff
/* 108FD0 7F0D44A0 AFAF028C */  sw    $t7, 0x28c($sp)
/* 108FD4 7F0D44A4 03008825 */  move  $s1, $t8
/* 108FD8 7F0D44A8 100038D4 */  b     .L7F0E27FC
/* 108FDC 7F0D44AC AFAA0048 */   sw    $t2, 0x48($sp)
spectrum_op_1D:
/* 108FE0 7F0D44B0 8FAA028C */  lw    $t2, 0x28c($sp)
/* 108FE4 7F0D44B4 32AE000F */  andi  $t6, $s5, 0xf
/* 108FE8 7F0D44B8 26B5FFFF */  addiu $s5, $s5, -1
/* 108FEC 7F0D44BC 25590004 */  addiu $t9, $t2, 4
/* 108FF0 7F0D44C0 AFB9028C */  sw    $t9, 0x28c($sp)
/* 108FF4 7F0D44C4 32AD00FF */  andi  $t5, $s5, 0xff
/* 108FF8 7F0D44C8 2DCF0001 */  sltiu $t7, $t6, 1
/* 108FFC 7F0D44CC 000F4100 */  sll   $t0, $t7, 4
/* 109000 7F0D44D0 39B9007F */  xori  $t9, $t5, 0x7f
/* 109004 7F0D44D4 2F390001 */  sltiu $t9, $t9, 1
/* 109008 7F0D44D8 322C0001 */  andi  $t4, $s1, 1
/* 10900C 7F0D44DC 01888825 */  or    $s1, $t4, $t0
/* 109010 7F0D44E0 00197080 */  sll   $t6, $t9, 2
/* 109014 7F0D44E4 AFAF0048 */  sw    $t7, 0x48($sp)
/* 109018 7F0D44E8 2DB80001 */  sltiu $t8, $t5, 1
/* 10901C 7F0D44EC 31AA00A8 */  andi  $t2, $t5, 0xa8
/* 109020 7F0D44F0 014E7825 */  or    $t7, $t2, $t6
/* 109024 7F0D44F4 00184180 */  sll   $t0, $t8, 6
/* 109028 7F0D44F8 01E84825 */  or    $t1, $t7, $t0
/* 10902C 7F0D44FC 362B0002 */  ori   $t3, $s1, 2
/* 109030 7F0D4500 01698825 */  or    $s1, $t3, $t1
/* 109034 7F0D4504 322B00FF */  andi  $t3, $s1, 0xff
/* 109038 7F0D4508 01608825 */  move  $s1, $t3
/* 10903C 7F0D450C AFB80044 */  sw    $t8, 0x44($sp)
/* 109040 7F0D4510 100038BA */  b     .L7F0E27FC
/* 109044 7F0D4514 01A0A825 */   move  $s5, $t5
spectrum_op_1E:
/* 109048 7F0D4518 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10904C 7F0D451C 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 109050 7F0D4520 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 109054 7F0D4524 97B90298 */  lhu   $t9, 0x298($sp)
/* 109058 7F0D4528 25B80007 */  addiu $t8, $t5, 7
/* 10905C 7F0D452C AFB8028C */  sw    $t8, 0x28c($sp)
/* 109060 7F0D4530 032A7021 */  addu  $t6, $t9, $t2
/* 109064 7F0D4534 91D50000 */  lbu   $s5, ($t6)
/* 109068 7F0D4538 272C0001 */  addiu $t4, $t9, 1
/* 10906C 7F0D453C 100038AF */  b     .L7F0E27FC
/* 109070 7F0D4540 A7AC0298 */   sh    $t4, 0x298($sp)
spectrum_op_1F:
/* 109074 7F0D4544 32090001 */  andi  $t1, $s0, 1
/* 109078 7F0D4548 00105843 */  sra   $t3, $s0, 1
/* 10907C 7F0D454C 001169C0 */  sll   $t5, $s1, 7
/* 109080 7F0D4550 016D8025 */  or    $s0, $t3, $t5
/* 109084 7F0D4554 8FAF028C */  lw    $t7, 0x28c($sp)
/* 109088 7F0D4558 321800FF */  andi  $t8, $s0, 0xff
/* 10908C 7F0D455C 330E0028 */  andi  $t6, $t8, 0x28
/* 109090 7F0D4560 322A00C4 */  andi  $t2, $s1, 0xc4
/* 109094 7F0D4564 014EC825 */  or    $t9, $t2, $t6
/* 109098 7F0D4568 03298825 */  or    $s1, $t9, $t1
/* 10909C 7F0D456C 25E80004 */  addiu $t0, $t7, 4
/* 1090A0 7F0D4570 322F00FF */  andi  $t7, $s1, 0xff
/* 1090A4 7F0D4574 AFA8028C */  sw    $t0, 0x28c($sp)
/* 1090A8 7F0D4578 AFA90260 */  sw    $t1, 0x260($sp)
/* 1090AC 7F0D457C 03008025 */  move  $s0, $t8
/* 1090B0 7F0D4580 1000389E */  b     .L7F0E27FC
/* 1090B4 7F0D4584 01E08825 */   move  $s1, $t7
spectrum_op_20:
/* 1090B8 7F0D4588 8FA8028C */  lw    $t0, 0x28c($sp)
/* 1090BC 7F0D458C 322B0040 */  andi  $t3, $s1, 0x40
/* 1090C0 7F0D4590 97AA0298 */  lhu   $t2, 0x298($sp)
/* 1090C4 7F0D4594 25090007 */  addiu $t1, $t0, 7
/* 1090C8 7F0D4598 11600005 */  beqz  $t3, .L7F0D45B0
/* 1090CC 7F0D459C AFA9028C */   sw    $t1, 0x28c($sp)
/* 1090D0 7F0D45A0 97AD0298 */  lhu   $t5, 0x298($sp)
/* 1090D4 7F0D45A4 25B80001 */  addiu $t8, $t5, 1
/* 1090D8 7F0D45A8 10003894 */  b     .L7F0E27FC
/* 1090DC 7F0D45AC A7B80298 */   sh    $t8, 0x298($sp)
.L7F0D45B0:
/* 1090E0 7F0D45B0 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 1090E4 7F0D45B4 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 1090E8 7F0D45B8 8FA9028C */  lw    $t1, 0x28c($sp)
/* 1090EC 7F0D45BC 014EC821 */  addu  $t9, $t2, $t6
/* 1090F0 7F0D45C0 832C0000 */  lb    $t4, ($t9)
/* 1090F4 7F0D45C4 252B0005 */  addiu $t3, $t1, 5
/* 1090F8 7F0D45C8 AFAB028C */  sw    $t3, 0x28c($sp)
/* 1090FC 7F0D45CC 014C7821 */  addu  $t7, $t2, $t4
/* 109100 7F0D45D0 25E80001 */  addiu $t0, $t7, 1
/* 109104 7F0D45D4 A7A80298 */  sh    $t0, 0x298($sp)
/* 109108 7F0D45D8 10003888 */  b     .L7F0E27FC
/* 10910C 7F0D45DC AFAC025C */   sw    $t4, 0x25c($sp)
spectrum_op_21:
/* 109110 7F0D45E0 8FAD028C */  lw    $t5, 0x28c($sp)
/* 109114 7F0D45E4 93AE0287 */  lbu   $t6, 0x287($sp)
/* 109118 7F0D45E8 97B90298 */  lhu   $t9, 0x298($sp)
/* 10911C 7F0D45EC 25B8000A */  addiu $t8, $t5, 0xa
/* 109120 7F0D45F0 15C0000D */  bnez  $t6, .L7F0D4628
/* 109124 7F0D45F4 AFB8028C */   sw    $t8, 0x28c($sp)
/* 109128 7F0D45F8 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 10912C 7F0D45FC 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 109130 7F0D4600 272B0001 */  addiu $t3, $t9, 1
/* 109134 7F0D4604 3168FFFF */  andi  $t0, $t3, 0xffff
/* 109138 7F0D4608 032A6021 */  addu  $t4, $t9, $t2
/* 10913C 7F0D460C 91970000 */  lbu   $s7, ($t4)
/* 109140 7F0D4610 A7AB0298 */  sh    $t3, 0x298($sp)
/* 109144 7F0D4614 010A4821 */  addu  $t1, $t0, $t2
/* 109148 7F0D4618 91360000 */  lbu   $s6, ($t1)
/* 10914C 7F0D461C 256D0001 */  addiu $t5, $t3, 1
/* 109150 7F0D4620 10003876 */  b     .L7F0E27FC
/* 109154 7F0D4624 A7AD0298 */   sh    $t5, 0x298($sp)
.L7F0D4628:
/* 109158 7F0D4628 93B80287 */  lbu   $t8, 0x287($sp)
/* 10915C 7F0D462C 24010001 */  li    $at, 1
/* 109160 7F0D4630 97AE0298 */  lhu   $t6, 0x298($sp)
/* 109164 7F0D4634 1701000B */  bne   $t8, $at, .L7F0D4664
/* 109168 7F0D4638 97AD0298 */   lhu   $t5, 0x298($sp)
/* 10916C 7F0D463C 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 109170 7F0D4640 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 109174 7F0D4644 018E5021 */  addu  $t2, $t4, $t6
/* 109178 7F0D4648 91490001 */  lbu   $t1, 1($t2)
/* 10917C 7F0D464C 01CCC821 */  addu  $t9, $t6, $t4
/* 109180 7F0D4650 93280000 */  lbu   $t0, ($t9)
/* 109184 7F0D4654 00097A00 */  sll   $t7, $t1, 8
/* 109188 7F0D4658 010F5825 */  or    $t3, $t0, $t7
/* 10918C 7F0D465C 1000000A */  b     .L7F0D4688
/* 109190 7F0D4660 A7AB0296 */   sh    $t3, 0x296($sp)
.L7F0D4664:
/* 109194 7F0D4664 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 109198 7F0D4668 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10919C 7F0D466C 030D7021 */  addu  $t6, $t8, $t5
/* 1091A0 7F0D4670 91CA0001 */  lbu   $t2, 1($t6)
/* 1091A4 7F0D4674 01B8C821 */  addu  $t9, $t5, $t8
/* 1091A8 7F0D4678 932C0000 */  lbu   $t4, ($t9)
/* 1091AC 7F0D467C 000A4A00 */  sll   $t1, $t2, 8
/* 1091B0 7F0D4680 01894025 */  or    $t0, $t4, $t1
/* 1091B4 7F0D4684 A7A80294 */  sh    $t0, 0x294($sp)
.L7F0D4688:
/* 1091B8 7F0D4688 97AF0298 */  lhu   $t7, 0x298($sp)
/* 1091BC 7F0D468C 25EB0002 */  addiu $t3, $t7, 2
/* 1091C0 7F0D4690 1000385A */  b     .L7F0E27FC
/* 1091C4 7F0D4694 A7AB0298 */   sh    $t3, 0x298($sp)
spectrum_op_22:
/* 1091C8 7F0D4698 8FB9028C */  lw    $t9, 0x28c($sp)
/* 1091CC 7F0D469C 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 1091D0 7F0D46A0 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 1091D4 7F0D46A4 97AD0298 */  lhu   $t5, 0x298($sp)
/* 1091D8 7F0D46A8 27380010 */  addiu $t8, $t9, 0x10
/* 1091DC 7F0D46AC AFB8028C */  sw    $t8, 0x28c($sp)
/* 1091E0 7F0D46B0 01CD4821 */  addu  $t1, $t6, $t5
/* 1091E4 7F0D46B4 91280001 */  lbu   $t0, 1($t1)
/* 1091E8 7F0D46B8 01AE5021 */  addu  $t2, $t5, $t6
/* 1091EC 7F0D46BC 914C0000 */  lbu   $t4, ($t2)
/* 1091F0 7F0D46C0 93B80287 */  lbu   $t8, 0x287($sp)
/* 1091F4 7F0D46C4 00087A00 */  sll   $t7, $t0, 8
/* 1091F8 7F0D46C8 25B90002 */  addiu $t9, $t5, 2
/* 1091FC 7F0D46CC 018F5825 */  or    $t3, $t4, $t7
/* 109200 7F0D46D0 A7AB025A */  sh    $t3, 0x25a($sp)
/* 109204 7F0D46D4 17000054 */  bnez  $t8, .L7F0D4828
/* 109208 7F0D46D8 A7B90298 */   sh    $t9, 0x298($sp)
/* 10920C 7F0D46DC 316AFFFF */  andi  $t2, $t3, 0xffff
/* 109210 7F0D46E0 29415B00 */  slti  $at, $t2, 0x5b00
/* 109214 7F0D46E4 14200006 */  bnez  $at, .L7F0D4700
/* 109218 7F0D46E8 97A8025A */   lhu   $t0, 0x25a($sp)
/* 10921C 7F0D46EC 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 109220 7F0D46F0 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 109224 7F0D46F4 01CA4821 */  addu  $t1, $t6, $t2
/* 109228 7F0D46F8 1000001F */  b     .L7F0D4778
/* 10922C 7F0D46FC A1370000 */   sb    $s7, ($t1)
.L7F0D4700:
/* 109230 7F0D4700 29015800 */  slti  $at, $t0, 0x5800
/* 109234 7F0D4704 1420000C */  bnez  $at, .L7F0D4738
/* 109238 7F0D4708 97AE025A */   lhu   $t6, 0x25a($sp)
/* 10923C 7F0D470C 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 109240 7F0D4710 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 109244 7F0D4714 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 109248 7F0D4718 240B0001 */  li    $t3, 1
/* 10924C 7F0D471C 01887821 */  addu  $t7, $t4, $t0
/* 109250 7F0D4720 A1F70000 */  sb    $s7, ($t7)
/* 109254 7F0D4724 97B9025A */  lhu   $t9, 0x25a($sp)
/* 109258 7F0D4728 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 10925C 7F0D472C 01B9C021 */  addu  $t8, $t5, $t9
/* 109260 7F0D4730 10000011 */  b     .L7F0D4778
/* 109264 7F0D4734 A30BA800 */   sb    $t3, -0x5800($t8)
.L7F0D4738:
/* 109268 7F0D4738 29C14000 */  slti  $at, $t6, 0x4000
/* 10926C 7F0D473C 1420000E */  bnez  $at, .L7F0D4778
/* 109270 7F0D4740 3C0A8009 */   lui   $t2, %hi(ptr_spectrum_roms) 
/* 109274 7F0D4744 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 109278 7F0D4748 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 10927C 7F0D474C 240C0001 */  li    $t4, 1
/* 109280 7F0D4750 014E4821 */  addu  $t1, $t2, $t6
/* 109284 7F0D4754 A1370000 */  sb    $s7, ($t1)
/* 109288 7F0D4758 97A8025A */  lhu   $t0, 0x25a($sp)
/* 10928C 7F0D475C 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 109290 7F0D4760 310F1800 */  andi  $t7, $t0, 0x1800
/* 109294 7F0D4764 000F68C3 */  sra   $t5, $t7, 3
/* 109298 7F0D4768 311900FF */  andi  $t9, $t0, 0xff
/* 10929C 7F0D476C 01B95825 */  or    $t3, $t5, $t9
/* 1092A0 7F0D4770 030B5021 */  addu  $t2, $t8, $t3
/* 1092A4 7F0D4774 A14C0000 */  sb    $t4, ($t2)
.L7F0D4778:
/* 1092A8 7F0D4778 97AE025A */  lhu   $t6, 0x25a($sp)
/* 1092AC 7F0D477C 97AD025A */  lhu   $t5, 0x25a($sp)
/* 1092B0 7F0D4780 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 1092B4 7F0D4784 25C90001 */  addiu $t1, $t6, 1
/* 1092B8 7F0D4788 29215B00 */  slti  $at, $t1, 0x5b00
/* 1092BC 7F0D478C 14200005 */  bnez  $at, .L7F0D47A4
/* 1092C0 7F0D4790 25B90001 */   addiu $t9, $t5, 1
/* 1092C4 7F0D4794 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 1092C8 7F0D4798 01EE4021 */  addu  $t0, $t7, $t6
/* 1092CC 7F0D479C 10003817 */  b     .L7F0E27FC
/* 1092D0 7F0D47A0 A1160001 */   sb    $s6, 1($t0)
.L7F0D47A4:
/* 1092D4 7F0D47A4 2B215800 */  slti  $at, $t9, 0x5800
/* 1092D8 7F0D47A8 1420000C */  bnez  $at, .L7F0D47DC
/* 1092DC 7F0D47AC 97AE025A */   lhu   $t6, 0x25a($sp)
/* 1092E0 7F0D47B0 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 1092E4 7F0D47B4 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 1092E8 7F0D47B8 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 1092EC 7F0D47BC 240C0001 */  li    $t4, 1
/* 1092F0 7F0D47C0 030D5821 */  addu  $t3, $t8, $t5
/* 1092F4 7F0D47C4 A1760001 */  sb    $s6, 1($t3)
/* 1092F8 7F0D47C8 97A9025A */  lhu   $t1, 0x25a($sp)
/* 1092FC 7F0D47CC 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 109300 7F0D47D0 01497821 */  addu  $t7, $t2, $t1
/* 109304 7F0D47D4 10003809 */  b     .L7F0E27FC
/* 109308 7F0D47D8 A1ECA801 */   sb    $t4, -0x57ff($t7)
.L7F0D47DC:
/* 10930C 7F0D47DC 25C80001 */  addiu $t0, $t6, 1
/* 109310 7F0D47E0 29014000 */  slti  $at, $t0, 0x4000
/* 109314 7F0D47E4 14203805 */  bnez  $at, .L7F0E27FC
/* 109318 7F0D47E8 3C198009 */   lui   $t9, %hi(ptr_spectrum_roms) 
/* 10931C 7F0D47EC 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 109320 7F0D47F0 240D0001 */  li    $t5, 1
/* 109324 7F0D47F4 032EC021 */  addu  $t8, $t9, $t6
/* 109328 7F0D47F8 A3160001 */  sb    $s6, 1($t8)
/* 10932C 7F0D47FC 97AB025A */  lhu   $t3, 0x25a($sp)
/* 109330 7F0D4800 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 109334 7F0D4804 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 109338 7F0D4808 256A0001 */  addiu $t2, $t3, 1
/* 10933C 7F0D480C 31491800 */  andi  $t1, $t2, 0x1800
/* 109340 7F0D4810 000960C3 */  sra   $t4, $t1, 3
/* 109344 7F0D4814 314F00FF */  andi  $t7, $t2, 0xff
/* 109348 7F0D4818 018F4025 */  or    $t0, $t4, $t7
/* 10934C 7F0D481C 03287021 */  addu  $t6, $t9, $t0
/* 109350 7F0D4820 100037F6 */  b     .L7F0E27FC
/* 109354 7F0D4824 A1CD0000 */   sb    $t5, ($t6)
.L7F0D4828:
/* 109358 7F0D4828 93B80287 */  lbu   $t8, 0x287($sp)
/* 10935C 7F0D482C 24010001 */  li    $at, 1
/* 109360 7F0D4830 97AB025A */  lhu   $t3, 0x25a($sp)
/* 109364 7F0D4834 1701005B */  bne   $t8, $at, .L7F0D49A4
/* 109368 7F0D4838 29615B00 */   slti  $at, $t3, 0x5b00
/* 10936C 7F0D483C 14200007 */  bnez  $at, .L7F0D485C
/* 109370 7F0D4840 97AF025A */   lhu   $t7, 0x25a($sp)
/* 109374 7F0D4844 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 109378 7F0D4848 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 10937C 7F0D484C 97A90296 */  lhu   $t1, 0x296($sp)
/* 109380 7F0D4850 014B6021 */  addu  $t4, $t2, $t3
/* 109384 7F0D4854 10000021 */  b     .L7F0D48DC
/* 109388 7F0D4858 A1890000 */   sb    $t1, ($t4)
.L7F0D485C:
/* 10938C 7F0D485C 29E15800 */  slti  $at, $t7, 0x5800
/* 109390 7F0D4860 1420000D */  bnez  $at, .L7F0D4898
/* 109394 7F0D4864 97A9025A */   lhu   $t1, 0x25a($sp)
/* 109398 7F0D4868 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10939C 7F0D486C 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 1093A0 7F0D4870 97B90296 */  lhu   $t9, 0x296($sp)
/* 1093A4 7F0D4874 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 1093A8 7F0D4878 010F6821 */  addu  $t5, $t0, $t7
/* 1093AC 7F0D487C A1B90000 */  sb    $t9, ($t5)
/* 1093B0 7F0D4880 97AA025A */  lhu   $t2, 0x25a($sp)
/* 1093B4 7F0D4884 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 1093B8 7F0D4888 240E0001 */  li    $t6, 1
/* 1093BC 7F0D488C 030A5821 */  addu  $t3, $t8, $t2
/* 1093C0 7F0D4890 10000012 */  b     .L7F0D48DC
/* 1093C4 7F0D4894 A16EA800 */   sb    $t6, -0x5800($t3)
.L7F0D4898:
/* 1093C8 7F0D4898 29214000 */  slti  $at, $t1, 0x4000
/* 1093CC 7F0D489C 1420000F */  bnez  $at, .L7F0D48DC
/* 1093D0 7F0D48A0 3C088009 */   lui   $t0, %hi(ptr_spectrum_roms) 
/* 1093D4 7F0D48A4 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 1093D8 7F0D48A8 97AC0296 */  lhu   $t4, 0x296($sp)
/* 1093DC 7F0D48AC 24190001 */  li    $t9, 1
/* 1093E0 7F0D48B0 01097821 */  addu  $t7, $t0, $t1
/* 1093E4 7F0D48B4 A1EC0000 */  sb    $t4, ($t7)
/* 1093E8 7F0D48B8 97AD025A */  lhu   $t5, 0x25a($sp)
/* 1093EC 7F0D48BC 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 1093F0 7F0D48C0 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 1093F4 7F0D48C4 31B81800 */  andi  $t8, $t5, 0x1800
/* 1093F8 7F0D48C8 001850C3 */  sra   $t2, $t8, 3
/* 1093FC 7F0D48CC 31AE00FF */  andi  $t6, $t5, 0xff
/* 109400 7F0D48D0 014E5825 */  or    $t3, $t2, $t6
/* 109404 7F0D48D4 010B4821 */  addu  $t1, $t0, $t3
/* 109408 7F0D48D8 A1390000 */  sb    $t9, ($t1)
.L7F0D48DC:
/* 10940C 7F0D48DC 97AC025A */  lhu   $t4, 0x25a($sp)
/* 109410 7F0D48E0 97A8025A */  lhu   $t0, 0x25a($sp)
/* 109414 7F0D48E4 97B80296 */  lhu   $t8, 0x296($sp)
/* 109418 7F0D48E8 258F0001 */  addiu $t7, $t4, 1
/* 10941C 7F0D48EC 29E15B00 */  slti  $at, $t7, 0x5b00
/* 109420 7F0D48F0 14200007 */  bnez  $at, .L7F0D4910
/* 109424 7F0D48F4 250B0001 */   addiu $t3, $t0, 1
/* 109428 7F0D48F8 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 10942C 7F0D48FC 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 109430 7F0D4900 00186A03 */  sra   $t5, $t8, 8
/* 109434 7F0D4904 014C7021 */  addu  $t6, $t2, $t4
/* 109438 7F0D4908 100037BC */  b     .L7F0E27FC
/* 10943C 7F0D490C A1CD0001 */   sb    $t5, 1($t6)
.L7F0D4910:
/* 109440 7F0D4910 29615800 */  slti  $at, $t3, 0x5800
/* 109444 7F0D4914 1420000E */  bnez  $at, .L7F0D4950
/* 109448 7F0D4918 97AB025A */   lhu   $t3, 0x25a($sp)
/* 10944C 7F0D491C 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 109450 7F0D4920 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 109454 7F0D4924 97B90296 */  lhu   $t9, 0x296($sp)
/* 109458 7F0D4928 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 10945C 7F0D492C 01E8C021 */  addu  $t8, $t7, $t0
/* 109460 7F0D4930 00194A03 */  sra   $t1, $t9, 8
/* 109464 7F0D4934 A3090001 */  sb    $t1, 1($t8)
/* 109468 7F0D4938 97AD025A */  lhu   $t5, 0x25a($sp)
/* 10946C 7F0D493C 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 109470 7F0D4940 240A0001 */  li    $t2, 1
/* 109474 7F0D4944 018D7021 */  addu  $t6, $t4, $t5
/* 109478 7F0D4948 100037AC */  b     .L7F0E27FC
/* 10947C 7F0D494C A1CAA801 */   sb    $t2, -0x57ff($t6)
.L7F0D4950:
/* 109480 7F0D4950 25790001 */  addiu $t9, $t3, 1
/* 109484 7F0D4954 2B214000 */  slti  $at, $t9, 0x4000
/* 109488 7F0D4958 142037A8 */  bnez  $at, .L7F0E27FC
/* 10948C 7F0D495C 97AF0296 */   lhu   $t7, 0x296($sp)
/* 109490 7F0D4960 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 109494 7F0D4964 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 109498 7F0D4968 000F4203 */  sra   $t0, $t7, 8
/* 10949C 7F0D496C 240C0001 */  li    $t4, 1
/* 1094A0 7F0D4970 012BC021 */  addu  $t8, $t1, $t3
/* 1094A4 7F0D4974 A3080001 */  sb    $t0, 1($t8)
/* 1094A8 7F0D4978 97AD025A */  lhu   $t5, 0x25a($sp)
/* 1094AC 7F0D497C 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 1094B0 7F0D4980 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 1094B4 7F0D4984 25AA0001 */  addiu $t2, $t5, 1
/* 1094B8 7F0D4988 314E1800 */  andi  $t6, $t2, 0x1800
/* 1094BC 7F0D498C 000EC8C3 */  sra   $t9, $t6, 3
/* 1094C0 7F0D4990 314F00FF */  andi  $t7, $t2, 0xff
/* 1094C4 7F0D4994 032F4825 */  or    $t1, $t9, $t7
/* 1094C8 7F0D4998 01694021 */  addu  $t0, $t3, $t1
/* 1094CC 7F0D499C 10003797 */  b     .L7F0E27FC
/* 1094D0 7F0D49A0 A10C0000 */   sb    $t4, ($t0)
.L7F0D49A4:
/* 1094D4 7F0D49A4 97B8025A */  lhu   $t8, 0x25a($sp)
/* 1094D8 7F0D49A8 97B9025A */  lhu   $t9, 0x25a($sp)
/* 1094DC 7F0D49AC 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 1094E0 7F0D49B0 2B015B00 */  slti  $at, $t8, 0x5b00
/* 1094E4 7F0D49B4 54200007 */  bnezl $at, .L7F0D49D4
/* 1094E8 7F0D49B8 2B215800 */   slti  $at, $t9, 0x5800
/* 1094EC 7F0D49BC 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 1094F0 7F0D49C0 97AD0294 */  lhu   $t5, 0x294($sp)
/* 1094F4 7F0D49C4 01D85021 */  addu  $t2, $t6, $t8
/* 1094F8 7F0D49C8 10000021 */  b     .L7F0D4A50
/* 1094FC 7F0D49CC A14D0000 */   sb    $t5, ($t2)
/* 109500 7F0D49D0 2B215800 */  slti  $at, $t9, 0x5800
.L7F0D49D4:
/* 109504 7F0D49D4 1420000D */  bnez  $at, .L7F0D4A0C
/* 109508 7F0D49D8 97AD025A */   lhu   $t5, 0x25a($sp)
/* 10950C 7F0D49DC 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 109510 7F0D49E0 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 109514 7F0D49E4 97AF0294 */  lhu   $t7, 0x294($sp)
/* 109518 7F0D49E8 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 10951C 7F0D49EC 01794821 */  addu  $t1, $t3, $t9
/* 109520 7F0D49F0 A12F0000 */  sb    $t7, ($t1)
/* 109524 7F0D49F4 97AE025A */  lhu   $t6, 0x25a($sp)
/* 109528 7F0D49F8 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 10952C 7F0D49FC 240C0001 */  li    $t4, 1
/* 109530 7F0D4A00 010EC021 */  addu  $t8, $t0, $t6
/* 109534 7F0D4A04 10000012 */  b     .L7F0D4A50
/* 109538 7F0D4A08 A30CA800 */   sb    $t4, -0x5800($t8)
.L7F0D4A0C:
/* 10953C 7F0D4A0C 29A14000 */  slti  $at, $t5, 0x4000
/* 109540 7F0D4A10 1420000F */  bnez  $at, .L7F0D4A50
/* 109544 7F0D4A14 3C0B8009 */   lui   $t3, %hi(ptr_spectrum_roms) 
/* 109548 7F0D4A18 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10954C 7F0D4A1C 97AA0294 */  lhu   $t2, 0x294($sp)
/* 109550 7F0D4A20 240F0001 */  li    $t7, 1
/* 109554 7F0D4A24 016DC821 */  addu  $t9, $t3, $t5
/* 109558 7F0D4A28 A32A0000 */  sb    $t2, ($t9)
/* 10955C 7F0D4A2C 97A9025A */  lhu   $t1, 0x25a($sp)
/* 109560 7F0D4A30 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 109564 7F0D4A34 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 109568 7F0D4A38 31281800 */  andi  $t0, $t1, 0x1800
/* 10956C 7F0D4A3C 000870C3 */  sra   $t6, $t0, 3
/* 109570 7F0D4A40 312C00FF */  andi  $t4, $t1, 0xff
/* 109574 7F0D4A44 01CCC025 */  or    $t8, $t6, $t4
/* 109578 7F0D4A48 01786821 */  addu  $t5, $t3, $t8
/* 10957C 7F0D4A4C A1AF0000 */  sb    $t7, ($t5)
.L7F0D4A50:
/* 109580 7F0D4A50 97AA025A */  lhu   $t2, 0x25a($sp)
/* 109584 7F0D4A54 97AB025A */  lhu   $t3, 0x25a($sp)
/* 109588 7F0D4A58 97A80294 */  lhu   $t0, 0x294($sp)
/* 10958C 7F0D4A5C 25590001 */  addiu $t9, $t2, 1
/* 109590 7F0D4A60 2B215B00 */  slti  $at, $t9, 0x5b00
/* 109594 7F0D4A64 14200007 */  bnez  $at, .L7F0D4A84
/* 109598 7F0D4A68 25780001 */   addiu $t8, $t3, 1
/* 10959C 7F0D4A6C 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 1095A0 7F0D4A70 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 1095A4 7F0D4A74 00084A03 */  sra   $t1, $t0, 8
/* 1095A8 7F0D4A78 01CA6021 */  addu  $t4, $t6, $t2
/* 1095AC 7F0D4A7C 1000375F */  b     .L7F0E27FC
/* 1095B0 7F0D4A80 A1890001 */   sb    $t1, 1($t4)
.L7F0D4A84:
/* 1095B4 7F0D4A84 2B015800 */  slti  $at, $t8, 0x5800
/* 1095B8 7F0D4A88 1420000E */  bnez  $at, .L7F0D4AC4
/* 1095BC 7F0D4A8C 97B8025A */   lhu   $t8, 0x25a($sp)
/* 1095C0 7F0D4A90 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 1095C4 7F0D4A94 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 1095C8 7F0D4A98 97AF0294 */  lhu   $t7, 0x294($sp)
/* 1095CC 7F0D4A9C 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 1095D0 7F0D4AA0 032B4021 */  addu  $t0, $t9, $t3
/* 1095D4 7F0D4AA4 000F6A03 */  sra   $t5, $t7, 8
/* 1095D8 7F0D4AA8 A10D0001 */  sb    $t5, 1($t0)
/* 1095DC 7F0D4AAC 97A9025A */  lhu   $t1, 0x25a($sp)
/* 1095E0 7F0D4AB0 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 1095E4 7F0D4AB4 240E0001 */  li    $t6, 1
/* 1095E8 7F0D4AB8 01496021 */  addu  $t4, $t2, $t1
/* 1095EC 7F0D4ABC 1000374F */  b     .L7F0E27FC
/* 1095F0 7F0D4AC0 A18EA801 */   sb    $t6, -0x57ff($t4)
.L7F0D4AC4:
/* 1095F4 7F0D4AC4 270F0001 */  addiu $t7, $t8, 1
/* 1095F8 7F0D4AC8 29E14000 */  slti  $at, $t7, 0x4000
/* 1095FC 7F0D4ACC 1420374B */  bnez  $at, .L7F0E27FC
/* 109600 7F0D4AD0 97B90294 */   lhu   $t9, 0x294($sp)
/* 109604 7F0D4AD4 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 109608 7F0D4AD8 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10960C 7F0D4ADC 00195A03 */  sra   $t3, $t9, 8
/* 109610 7F0D4AE0 240A0001 */  li    $t2, 1
/* 109614 7F0D4AE4 01B84021 */  addu  $t0, $t5, $t8
/* 109618 7F0D4AE8 A10B0001 */  sb    $t3, 1($t0)
/* 10961C 7F0D4AEC 97A9025A */  lhu   $t1, 0x25a($sp)
/* 109620 7F0D4AF0 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 109624 7F0D4AF4 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 109628 7F0D4AF8 252E0001 */  addiu $t6, $t1, 1
/* 10962C 7F0D4AFC 31CC1800 */  andi  $t4, $t6, 0x1800
/* 109630 7F0D4B00 000C78C3 */  sra   $t7, $t4, 3
/* 109634 7F0D4B04 31D900FF */  andi  $t9, $t6, 0xff
/* 109638 7F0D4B08 01F96825 */  or    $t5, $t7, $t9
/* 10963C 7F0D4B0C 030D5821 */  addu  $t3, $t8, $t5
/* 109640 7F0D4B10 1000373A */  b     .L7F0E27FC
/* 109644 7F0D4B14 A16A0000 */   sb    $t2, ($t3)
spectrum_op_23:
/* 109648 7F0D4B18 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10964C 7F0D4B1C 93AC0287 */  lbu   $t4, 0x287($sp)
/* 109650 7F0D4B20 93B90287 */  lbu   $t9, 0x287($sp)
/* 109654 7F0D4B24 25090006 */  addiu $t1, $t0, 6
/* 109658 7F0D4B28 15800009 */  bnez  $t4, .L7F0D4B50
/* 10965C 7F0D4B2C AFA9028C */   sw    $t1, 0x28c($sp)
/* 109660 7F0D4B30 26F70001 */  addiu $s7, $s7, 1
/* 109664 7F0D4B34 32EE00FF */  andi  $t6, $s7, 0xff
/* 109668 7F0D4B38 15C03730 */  bnez  $t6, .L7F0E27FC
/* 10966C 7F0D4B3C 01C0B825 */   move  $s7, $t6
/* 109670 7F0D4B40 26D60001 */  addiu $s6, $s6, 1
/* 109674 7F0D4B44 32CF00FF */  andi  $t7, $s6, 0xff
/* 109678 7F0D4B48 1000372C */  b     .L7F0E27FC
/* 10967C 7F0D4B4C 01E0B025 */   move  $s6, $t7
.L7F0D4B50:
/* 109680 7F0D4B50 24010001 */  li    $at, 1
/* 109684 7F0D4B54 17210005 */  bne   $t9, $at, .L7F0D4B6C
/* 109688 7F0D4B58 97AA0294 */   lhu   $t2, 0x294($sp)
/* 10968C 7F0D4B5C 97B80296 */  lhu   $t8, 0x296($sp)
/* 109690 7F0D4B60 270D0001 */  addiu $t5, $t8, 1
/* 109694 7F0D4B64 10003725 */  b     .L7F0E27FC
/* 109698 7F0D4B68 A7AD0296 */   sh    $t5, 0x296($sp)
.L7F0D4B6C:
/* 10969C 7F0D4B6C 254B0001 */  addiu $t3, $t2, 1
/* 1096A0 7F0D4B70 10003722 */  b     .L7F0E27FC
/* 1096A4 7F0D4B74 A7AB0294 */   sh    $t3, 0x294($sp)
spectrum_op_24:
/* 1096A8 7F0D4B78 8FA8028C */  lw    $t0, 0x28c($sp)
/* 1096AC 7F0D4B7C 93AC0287 */  lbu   $t4, 0x287($sp)
/* 1096B0 7F0D4B80 93B80287 */  lbu   $t8, 0x287($sp)
/* 1096B4 7F0D4B84 25090004 */  addiu $t1, $t0, 4
/* 1096B8 7F0D4B88 15800017 */  bnez  $t4, .L7F0D4BE8
/* 1096BC 7F0D4B8C AFA9028C */   sw    $t1, 0x28c($sp)
/* 1096C0 7F0D4B90 26D60001 */  addiu $s6, $s6, 1
/* 1096C4 7F0D4B94 32CE00FF */  andi  $t6, $s6, 0xff
/* 1096C8 7F0D4B98 31D9000F */  andi  $t9, $t6, 0xf
/* 1096CC 7F0D4B9C 2F380001 */  sltiu $t8, $t9, 1
/* 1096D0 7F0D4BA0 01C0B025 */  move  $s6, $t6
/* 1096D4 7F0D4BA4 2DCF0001 */  sltiu $t7, $t6, 1
/* 1096D8 7F0D4BA8 31CA00A8 */  andi  $t2, $t6, 0xa8
/* 1096DC 7F0D4BAC 322D0001 */  andi  $t5, $s1, 1
/* 1096E0 7F0D4BB0 01AA5825 */  or    $t3, $t5, $t2
/* 1096E4 7F0D4BB4 3AD90080 */  xori  $t9, $s6, 0x80
/* 1096E8 7F0D4BB8 00184100 */  sll   $t0, $t8, 4
/* 1096EC 7F0D4BBC 01684825 */  or    $t1, $t3, $t0
/* 1096F0 7F0D4BC0 2F390001 */  sltiu $t9, $t9, 1
/* 1096F4 7F0D4BC4 000F7180 */  sll   $t6, $t7, 6
/* 1096F8 7F0D4BC8 AFAF0044 */  sw    $t7, 0x44($sp)
/* 1096FC 7F0D4BCC 012E7825 */  or    $t7, $t1, $t6
/* 109700 7F0D4BD0 00196880 */  sll   $t5, $t9, 2
/* 109704 7F0D4BD4 01ED8825 */  or    $s1, $t7, $t5
/* 109708 7F0D4BD8 322A00FF */  andi  $t2, $s1, 0xff
/* 10970C 7F0D4BDC 01408825 */  move  $s1, $t2
/* 109710 7F0D4BE0 10003706 */  b     .L7F0E27FC
/* 109714 7F0D4BE4 AFB80048 */   sw    $t8, 0x48($sp)
.L7F0D4BE8:
/* 109718 7F0D4BE8 24010001 */  li    $at, 1
/* 10971C 7F0D4BEC 17010004 */  bne   $t8, $at, .L7F0D4C00
/* 109720 7F0D4BF0 97A80294 */   lhu   $t0, 0x294($sp)
/* 109724 7F0D4BF4 97AB0296 */  lhu   $t3, 0x296($sp)
/* 109728 7F0D4BF8 10000002 */  b     .L7F0D4C04
/* 10972C 7F0D4BFC AFAB0048 */   sw    $t3, 0x48($sp)
.L7F0D4C00:
/* 109730 7F0D4C00 AFA80048 */  sw    $t0, 0x48($sp)
.L7F0D4C04:
/* 109734 7F0D4C04 8FAC0048 */  lw    $t4, 0x48($sp)
/* 109738 7F0D4C08 32280001 */  andi  $t0, $s1, 1
/* 10973C 7F0D4C0C 24010001 */  li    $at, 1
/* 109740 7F0D4C10 000C7203 */  sra   $t6, $t4, 8
/* 109744 7F0D4C14 25CA0001 */  addiu $t2, $t6, 1
/* 109748 7F0D4C18 314F00FF */  andi  $t7, $t2, 0xff
/* 10974C 7F0D4C1C 2DED0001 */  sltiu $t5, $t7, 1
/* 109750 7F0D4C20 314C00FF */  andi  $t4, $t2, 0xff
/* 109754 7F0D4C24 A3AE0259 */  sb    $t6, 0x259($sp)
/* 109758 7F0D4C28 318900A8 */  andi  $t1, $t4, 0xa8
/* 10975C 7F0D4C2C AFAD0044 */  sw    $t5, 0x44($sp)
/* 109760 7F0D4C30 3158000F */  andi  $t8, $t2, 0xf
/* 109764 7F0D4C34 8FB90044 */  lw    $t9, 0x44($sp)
/* 109768 7F0D4C38 2F0B0001 */  sltiu $t3, $t8, 1
/* 10976C 7F0D4C3C 01097025 */  or    $t6, $t0, $t1
/* 109770 7F0D4C40 000B7900 */  sll   $t7, $t3, 4
/* 109774 7F0D4C44 01CF6825 */  or    $t5, $t6, $t7
/* 109778 7F0D4C48 39880080 */  xori  $t0, $t4, 0x80
/* 10977C 7F0D4C4C A3AA0259 */  sb    $t2, 0x259($sp)
/* 109780 7F0D4C50 2D080001 */  sltiu $t0, $t0, 1
/* 109784 7F0D4C54 00195180 */  sll   $t2, $t9, 6
/* 109788 7F0D4C58 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10978C 7F0D4C5C 01AAC025 */  or    $t8, $t5, $t2
/* 109790 7F0D4C60 00084880 */  sll   $t1, $t0, 2
/* 109794 7F0D4C64 03098825 */  or    $s1, $t8, $t1
/* 109798 7F0D4C68 AFAB0048 */  sw    $t3, 0x48($sp)
/* 10979C 7F0D4C6C 322B00FF */  andi  $t3, $s1, 0xff
/* 1097A0 7F0D4C70 15C10007 */  bne   $t6, $at, .L7F0D4C90
/* 1097A4 7F0D4C74 01608825 */   move  $s1, $t3
/* 1097A8 7F0D4C78 97AF0296 */  lhu   $t7, 0x296($sp)
/* 1097AC 7F0D4C7C 000C6A00 */  sll   $t5, $t4, 8
/* 1097B0 7F0D4C80 31F900FF */  andi  $t9, $t7, 0xff
/* 1097B4 7F0D4C84 032D5025 */  or    $t2, $t9, $t5
/* 1097B8 7F0D4C88 100036DC */  b     .L7F0E27FC
/* 1097BC 7F0D4C8C A7AA0296 */   sh    $t2, 0x296($sp)
.L7F0D4C90:
/* 1097C0 7F0D4C90 97A80294 */  lhu   $t0, 0x294($sp)
/* 1097C4 7F0D4C94 93A90259 */  lbu   $t1, 0x259($sp)
/* 1097C8 7F0D4C98 311800FF */  andi  $t8, $t0, 0xff
/* 1097CC 7F0D4C9C 00095A00 */  sll   $t3, $t1, 8
/* 1097D0 7F0D4CA0 030B7025 */  or    $t6, $t8, $t3
/* 1097D4 7F0D4CA4 100036D5 */  b     .L7F0E27FC
/* 1097D8 7F0D4CA8 A7AE0294 */   sh    $t6, 0x294($sp)
spectrum_op_25:
/* 1097DC 7F0D4CAC 8FAF028C */  lw    $t7, 0x28c($sp)
/* 1097E0 7F0D4CB0 93B90287 */  lbu   $t9, 0x287($sp)
/* 1097E4 7F0D4CB4 93AE0287 */  lbu   $t6, 0x287($sp)
/* 1097E8 7F0D4CB8 25EC0004 */  addiu $t4, $t7, 4
/* 1097EC 7F0D4CBC 17200018 */  bnez  $t9, .L7F0D4D20
/* 1097F0 7F0D4CC0 AFAC028C */   sw    $t4, 0x28c($sp)
/* 1097F4 7F0D4CC4 32CD000F */  andi  $t5, $s6, 0xf
/* 1097F8 7F0D4CC8 26D6FFFF */  addiu $s6, $s6, -1
/* 1097FC 7F0D4CCC 32CE00FF */  andi  $t6, $s6, 0xff
/* 109800 7F0D4CD0 2DAA0001 */  sltiu $t2, $t5, 1
/* 109804 7F0D4CD4 000A4900 */  sll   $t1, $t2, 4
/* 109808 7F0D4CD8 39D9007F */  xori  $t9, $t6, 0x7f
/* 10980C 7F0D4CDC 2F390001 */  sltiu $t9, $t9, 1
/* 109810 7F0D4CE0 32280001 */  andi  $t0, $s1, 1
/* 109814 7F0D4CE4 01098825 */  or    $s1, $t0, $t1
/* 109818 7F0D4CE8 00196880 */  sll   $t5, $t9, 2
/* 10981C 7F0D4CEC AFAA0048 */  sw    $t2, 0x48($sp)
/* 109820 7F0D4CF0 2DCF0001 */  sltiu $t7, $t6, 1
/* 109824 7F0D4CF4 31CC00A8 */  andi  $t4, $t6, 0xa8
/* 109828 7F0D4CF8 018D5025 */  or    $t2, $t4, $t5
/* 10982C 7F0D4CFC 000F4980 */  sll   $t1, $t7, 6
/* 109830 7F0D4D00 0149C025 */  or    $t8, $t2, $t1
/* 109834 7F0D4D04 362B0002 */  ori   $t3, $s1, 2
/* 109838 7F0D4D08 01788825 */  or    $s1, $t3, $t8
/* 10983C 7F0D4D0C 322B00FF */  andi  $t3, $s1, 0xff
/* 109840 7F0D4D10 01608825 */  move  $s1, $t3
/* 109844 7F0D4D14 AFAF0044 */  sw    $t7, 0x44($sp)
/* 109848 7F0D4D18 100036B8 */  b     .L7F0E27FC
/* 10984C 7F0D4D1C 01C0B025 */   move  $s6, $t6
.L7F0D4D20:
/* 109850 7F0D4D20 24010001 */  li    $at, 1
/* 109854 7F0D4D24 15C10004 */  bne   $t6, $at, .L7F0D4D38
/* 109858 7F0D4D28 97B90294 */   lhu   $t9, 0x294($sp)
/* 10985C 7F0D4D2C 97AF0296 */  lhu   $t7, 0x296($sp)
/* 109860 7F0D4D30 10000002 */  b     .L7F0D4D3C
/* 109864 7F0D4D34 AFAF0048 */   sw    $t7, 0x48($sp)
.L7F0D4D38:
/* 109868 7F0D4D38 AFB90048 */  sw    $t9, 0x48($sp)
.L7F0D4D3C:
/* 10986C 7F0D4D3C 8FAC0048 */  lw    $t4, 0x48($sp)
/* 109870 7F0D4D40 32380001 */  andi  $t8, $s1, 1
/* 109874 7F0D4D44 24010001 */  li    $at, 1
/* 109878 7F0D4D48 000C4203 */  sra   $t0, $t4, 8
/* 10987C 7F0D4D4C 310A000F */  andi  $t2, $t0, 0xf
/* 109880 7F0D4D50 2D490001 */  sltiu $t1, $t2, 1
/* 109884 7F0D4D54 00095900 */  sll   $t3, $t1, 4
/* 109888 7F0D4D58 030B8825 */  or    $s1, $t8, $t3
/* 10988C 7F0D4D5C 311900FF */  andi  $t9, $t0, 0xff
/* 109890 7F0D4D60 272CFFFF */  addiu $t4, $t9, -1
/* 109894 7F0D4D64 319800FF */  andi  $t8, $t4, 0xff
/* 109898 7F0D4D68 3B0B007F */  xori  $t3, $t8, 0x7f
/* 10989C 7F0D4D6C 362E0002 */  ori   $t6, $s1, 2
/* 1098A0 7F0D4D70 A3A80258 */  sb    $t0, 0x258($sp)
/* 1098A4 7F0D4D74 01C08825 */  move  $s1, $t6
/* 1098A8 7F0D4D78 2D6B0001 */  sltiu $t3, $t3, 1
/* 1098AC 7F0D4D7C 318D00FF */  andi  $t5, $t4, 0xff
/* 1098B0 7F0D4D80 AFA90048 */  sw    $t1, 0x48($sp)
/* 1098B4 7F0D4D84 318900A8 */  andi  $t1, $t4, 0xa8
/* 1098B8 7F0D4D88 2DA80001 */  sltiu $t0, $t5, 1
/* 1098BC 7F0D4D8C 000B7080 */  sll   $t6, $t3, 2
/* 1098C0 7F0D4D90 012E7825 */  or    $t7, $t1, $t6
/* 1098C4 7F0D4D94 0008C980 */  sll   $t9, $t0, 6
/* 1098C8 7F0D4D98 93B80287 */  lbu   $t8, 0x287($sp)
/* 1098CC 7F0D4D9C 01F96825 */  or    $t5, $t7, $t9
/* 1098D0 7F0D4DA0 022D8825 */  or    $s1, $s1, $t5
/* 1098D4 7F0D4DA4 322A00FF */  andi  $t2, $s1, 0xff
/* 1098D8 7F0D4DA8 01408825 */  move  $s1, $t2
/* 1098DC 7F0D4DAC AFA80044 */  sw    $t0, 0x44($sp)
/* 1098E0 7F0D4DB0 17010007 */  bne   $t8, $at, .L7F0D4DD0
/* 1098E4 7F0D4DB4 A3AC0258 */   sb    $t4, 0x258($sp)
/* 1098E8 7F0D4DB8 97AB0296 */  lhu   $t3, 0x296($sp)
/* 1098EC 7F0D4DBC 000C4200 */  sll   $t0, $t4, 8
/* 1098F0 7F0D4DC0 316900FF */  andi  $t1, $t3, 0xff
/* 1098F4 7F0D4DC4 01287825 */  or    $t7, $t1, $t0
/* 1098F8 7F0D4DC8 1000368C */  b     .L7F0E27FC
/* 1098FC 7F0D4DCC A7AF0296 */   sh    $t7, 0x296($sp)
.L7F0D4DD0:
/* 109900 7F0D4DD0 97B90294 */  lhu   $t9, 0x294($sp)
/* 109904 7F0D4DD4 93AA0258 */  lbu   $t2, 0x258($sp)
/* 109908 7F0D4DD8 332D00FF */  andi  $t5, $t9, 0xff
/* 10990C 7F0D4DDC 000AC200 */  sll   $t8, $t2, 8
/* 109910 7F0D4DE0 01B85825 */  or    $t3, $t5, $t8
/* 109914 7F0D4DE4 10003685 */  b     .L7F0E27FC
/* 109918 7F0D4DE8 A7AB0294 */   sh    $t3, 0x294($sp)
spectrum_op_26:
/* 10991C 7F0D4DEC 8FAC028C */  lw    $t4, 0x28c($sp)
/* 109920 7F0D4DF0 93A90287 */  lbu   $t1, 0x287($sp)
/* 109924 7F0D4DF4 93AA0287 */  lbu   $t2, 0x287($sp)
/* 109928 7F0D4DF8 258E0007 */  addiu $t6, $t4, 7
/* 10992C 7F0D4DFC 15200007 */  bnez  $t1, .L7F0D4E1C
/* 109930 7F0D4E00 AFAE028C */   sw    $t6, 0x28c($sp)
/* 109934 7F0D4E04 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 109938 7F0D4E08 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10993C 7F0D4E0C 97A80298 */  lhu   $t0, 0x298($sp)
/* 109940 7F0D4E10 010FC821 */  addu  $t9, $t0, $t7
/* 109944 7F0D4E14 10000018 */  b     .L7F0D4E78
/* 109948 7F0D4E18 93360000 */   lbu   $s6, ($t9)
.L7F0D4E1C:
/* 10994C 7F0D4E1C 24010001 */  li    $at, 1
/* 109950 7F0D4E20 1541000C */  bne   $t2, $at, .L7F0D4E54
/* 109954 7F0D4E24 97B90298 */   lhu   $t9, 0x298($sp)
/* 109958 7F0D4E28 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 10995C 7F0D4E2C 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 109960 7F0D4E30 97AD0298 */  lhu   $t5, 0x298($sp)
/* 109964 7F0D4E34 97A90296 */  lhu   $t1, 0x296($sp)
/* 109968 7F0D4E38 01B85821 */  addu  $t3, $t5, $t8
/* 10996C 7F0D4E3C 916C0000 */  lbu   $t4, ($t3)
/* 109970 7F0D4E40 312800FF */  andi  $t0, $t1, 0xff
/* 109974 7F0D4E44 000C7200 */  sll   $t6, $t4, 8
/* 109978 7F0D4E48 01C87825 */  or    $t7, $t6, $t0
/* 10997C 7F0D4E4C 1000000A */  b     .L7F0D4E78
/* 109980 7F0D4E50 A7AF0296 */   sh    $t7, 0x296($sp)
.L7F0D4E54:
/* 109984 7F0D4E54 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 109988 7F0D4E58 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 10998C 7F0D4E5C 97AC0294 */  lhu   $t4, 0x294($sp)
/* 109990 7F0D4E60 032A6821 */  addu  $t5, $t9, $t2
/* 109994 7F0D4E64 91B80000 */  lbu   $t8, ($t5)
/* 109998 7F0D4E68 318900FF */  andi  $t1, $t4, 0xff
/* 10999C 7F0D4E6C 00185A00 */  sll   $t3, $t8, 8
/* 1099A0 7F0D4E70 01697025 */  or    $t6, $t3, $t1
/* 1099A4 7F0D4E74 A7AE0294 */  sh    $t6, 0x294($sp)
.L7F0D4E78:
/* 1099A8 7F0D4E78 97A80298 */  lhu   $t0, 0x298($sp)
/* 1099AC 7F0D4E7C 250F0001 */  addiu $t7, $t0, 1
/* 1099B0 7F0D4E80 1000365E */  b     .L7F0E27FC
/* 1099B4 7F0D4E84 A7AF0298 */   sh    $t7, 0x298($sp)
spectrum_op_27:
/* 1099B8 7F0D4E88 8FB9028C */  lw    $t9, 0x28c($sp)
/* 1099BC 7F0D4E8C 322D0001 */  andi  $t5, $s1, 1
/* 1099C0 7F0D4E90 32380010 */  andi  $t8, $s1, 0x10
/* 1099C4 7F0D4E94 272A0004 */  addiu $t2, $t9, 4
/* 1099C8 7F0D4E98 AFAA028C */  sw    $t2, 0x28c($sp)
/* 1099CC 7F0D4E9C A3AD0256 */  sb    $t5, 0x256($sp)
/* 1099D0 7F0D4EA0 17000004 */  bnez  $t8, .L7F0D4EB4
/* 1099D4 7F0D4EA4 A3A00257 */   sb    $zero, 0x257($sp)
/* 1099D8 7F0D4EA8 320C000F */  andi  $t4, $s0, 0xf
/* 1099DC 7F0D4EAC 2981000A */  slti  $at, $t4, 0xa
/* 1099E0 7F0D4EB0 14200002 */  bnez  $at, .L7F0D4EBC
.L7F0D4EB4:
/* 1099E4 7F0D4EB4 240B0006 */   li    $t3, 6
/* 1099E8 7F0D4EB8 A3AB0257 */  sb    $t3, 0x257($sp)
.L7F0D4EBC:
/* 1099EC 7F0D4EBC 32290001 */  andi  $t1, $s1, 1
/* 1099F0 7F0D4EC0 15200005 */  bnez  $t1, .L7F0D4ED8
/* 1099F4 7F0D4EC4 32390002 */   andi  $t9, $s1, 2
/* 1099F8 7F0D4EC8 00107103 */  sra   $t6, $s0, 4
/* 1099FC 7F0D4ECC 29C1000A */  slti  $at, $t6, 0xa
/* 109A00 7F0D4ED0 14200004 */  bnez  $at, .L7F0D4EE4
/* 109A04 7F0D4ED4 00000000 */   nop   
.L7F0D4ED8:
/* 109A08 7F0D4ED8 93A80257 */  lbu   $t0, 0x257($sp)
/* 109A0C 7F0D4EDC 350F0060 */  ori   $t7, $t0, 0x60
/* 109A10 7F0D4EE0 A3AF0257 */  sb    $t7, 0x257($sp)
.L7F0D4EE4:
/* 109A14 7F0D4EE4 1320001D */  beqz  $t9, .L7F0D4F5C
/* 109A18 7F0D4EE8 2A010091 */   slti  $at, $s0, 0x91
/* 109A1C 7F0D4EEC 93AA0257 */  lbu   $t2, 0x257($sp)
/* 109A20 7F0D4EF0 320F000F */  andi  $t7, $s0, 0xf
/* 109A24 7F0D4EF4 020A6823 */  subu  $t5, $s0, $t2
/* 109A28 7F0D4EF8 31B801FF */  andi  $t8, $t5, 0x1ff
/* 109A2C 7F0D4EFC 330B00A8 */  andi  $t3, $t8, 0xa8
/* 109A30 7F0D4F00 00187203 */  sra   $t6, $t8, 8
/* 109A34 7F0D4F04 3159000F */  andi  $t9, $t2, 0xf
/* 109A38 7F0D4F08 01F9682A */  slt   $t5, $t7, $t9
/* 109A3C 7F0D4F0C 016E4025 */  or    $t0, $t3, $t6
/* 109A40 7F0D4F10 020A5826 */  xor   $t3, $s0, $t2
/* 109A44 7F0D4F14 000D6100 */  sll   $t4, $t5, 4
/* 109A48 7F0D4F18 0310C826 */  xor   $t9, $t8, $s0
/* 109A4C 7F0D4F1C A7B80254 */  sh    $t8, 0x254($sp)
/* 109A50 7F0D4F20 93B00255 */  lbu   $s0, 0x255($sp)
/* 109A54 7F0D4F24 316E0080 */  andi  $t6, $t3, 0x80
/* 109A58 7F0D4F28 01D96824 */  and   $t5, $t6, $t9
/* 109A5C 7F0D4F2C 010C4825 */  or    $t1, $t0, $t4
/* 109A60 7F0D4F30 000D4143 */  sra   $t0, $t5, 5
/* 109A64 7F0D4F34 01288825 */  or    $s1, $t1, $t0
/* 109A68 7F0D4F38 A3AA0253 */  sb    $t2, 0x253($sp)
/* 109A6C 7F0D4F3C 2E0B0001 */  sltiu $t3, $s0, 1
/* 109A70 7F0D4F40 000B7980 */  sll   $t7, $t3, 6
/* 109A74 7F0D4F44 362A0002 */  ori   $t2, $s1, 2
/* 109A78 7F0D4F48 014F8825 */  or    $s1, $t2, $t7
/* 109A7C 7F0D4F4C 322E00FF */  andi  $t6, $s1, 0xff
/* 109A80 7F0D4F50 01C08825 */  move  $s1, $t6
/* 109A84 7F0D4F54 10000024 */  b     .L7F0D4FE8
/* 109A88 7F0D4F58 AFAB0048 */   sw    $t3, 0x48($sp)
.L7F0D4F5C:
/* 109A8C 7F0D4F5C 14200006 */  bnez  $at, .L7F0D4F78
/* 109A90 7F0D4F60 3219000F */   andi  $t9, $s0, 0xf
/* 109A94 7F0D4F64 2B21000A */  slti  $at, $t9, 0xa
/* 109A98 7F0D4F68 14200003 */  bnez  $at, .L7F0D4F78
/* 109A9C 7F0D4F6C 93AD0257 */   lbu   $t5, 0x257($sp)
/* 109AA0 7F0D4F70 35A90060 */  ori   $t1, $t5, 0x60
/* 109AA4 7F0D4F74 A3A90257 */  sb    $t1, 0x257($sp)
.L7F0D4F78:
/* 109AA8 7F0D4F78 93A80257 */  lbu   $t0, 0x257($sp)
/* 109AAC 7F0D4F7C 320E000F */  andi  $t6, $s0, 0xf
/* 109AB0 7F0D4F80 2401000F */  li    $at, 15
/* 109AB4 7F0D4F84 02085021 */  addu  $t2, $s0, $t0
/* 109AB8 7F0D4F88 314B00A8 */  andi  $t3, $t2, 0xa8
/* 109ABC 7F0D4F8C 000AC203 */  sra   $t8, $t2, 8
/* 109AC0 7F0D4F90 3119000F */  andi  $t9, $t0, 0xf
/* 109AC4 7F0D4F94 01D96821 */  addu  $t5, $t6, $t9
/* 109AC8 7F0D4F98 01787825 */  or    $t7, $t3, $t8
/* 109ACC 7F0D4F9C 0200C027 */  not   $t8, $s0
/* 109AD0 7F0D4FA0 002D482A */  slt   $t1, $at, $t5
/* 109AD4 7F0D4FA4 01506826 */  xor   $t5, $t2, $s0
/* 109AD8 7F0D4FA8 A7AA0250 */  sh    $t2, 0x250($sp)
/* 109ADC 7F0D4FAC 93B00251 */  lbu   $s0, 0x251($sp)
/* 109AE0 7F0D4FB0 00096100 */  sll   $t4, $t1, 4
/* 109AE4 7F0D4FB4 03087026 */  xor   $t6, $t8, $t0
/* 109AE8 7F0D4FB8 31D90080 */  andi  $t9, $t6, 0x80
/* 109AEC 7F0D4FBC 032D4824 */  and   $t1, $t9, $t5
/* 109AF0 7F0D4FC0 01EC5825 */  or    $t3, $t7, $t4
/* 109AF4 7F0D4FC4 00097943 */  sra   $t7, $t1, 5
/* 109AF8 7F0D4FC8 2E180001 */  sltiu $t8, $s0, 1
/* 109AFC 7F0D4FCC 00187180 */  sll   $t6, $t8, 6
/* 109B00 7F0D4FD0 016F6025 */  or    $t4, $t3, $t7
/* 109B04 7F0D4FD4 018E8825 */  or    $s1, $t4, $t6
/* 109B08 7F0D4FD8 322A00FF */  andi  $t2, $s1, 0xff
/* 109B0C 7F0D4FDC 01408825 */  move  $s1, $t2
/* 109B10 7F0D4FE0 AFB80048 */  sw    $t8, 0x48($sp)
/* 109B14 7F0D4FE4 A3A8024F */  sb    $t0, 0x24f($sp)
.L7F0D4FE8:
/* 109B18 7F0D4FE8 3C198009 */  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
/* 109B1C 7F0D4FEC 8F39E334 */  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
/* 109B20 7F0D4FF0 93AB0256 */  lbu   $t3, 0x256($sp)
/* 109B24 7F0D4FF4 02196821 */  addu  $t5, $s0, $t9
/* 109B28 7F0D4FF8 91A90000 */  lbu   $t1, ($t5)
/* 109B2C 7F0D4FFC 022B7825 */  or    $t7, $s1, $t3
/* 109B30 7F0D5000 31EC00FB */  andi  $t4, $t7, 0xfb
/* 109B34 7F0D5004 012C8825 */  or    $s1, $t1, $t4
/* 109B38 7F0D5008 323800FF */  andi  $t8, $s1, 0xff
/* 109B3C 7F0D500C 100035FB */  b     .L7F0E27FC
/* 109B40 7F0D5010 03008825 */   move  $s1, $t8
spectrum_op_28:
/* 109B44 7F0D5014 8FA8028C */  lw    $t0, 0x28c($sp)
/* 109B48 7F0D5018 322A0040 */  andi  $t2, $s1, 0x40
/* 109B4C 7F0D501C 97B90298 */  lhu   $t9, 0x298($sp)
/* 109B50 7F0D5020 250E0007 */  addiu $t6, $t0, 7
/* 109B54 7F0D5024 1140000C */  beqz  $t2, .L7F0D5058
/* 109B58 7F0D5028 AFAE028C */   sw    $t6, 0x28c($sp)
/* 109B5C 7F0D502C 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 109B60 7F0D5030 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 109B64 7F0D5034 25C80005 */  addiu $t0, $t6, 5
/* 109B68 7F0D5038 032D5821 */  addu  $t3, $t9, $t5
/* 109B6C 7F0D503C 816F0000 */  lb    $t7, ($t3)
/* 109B70 7F0D5040 AFA8028C */  sw    $t0, 0x28c($sp)
/* 109B74 7F0D5044 032F4821 */  addu  $t1, $t9, $t7
/* 109B78 7F0D5048 252C0001 */  addiu $t4, $t1, 1
/* 109B7C 7F0D504C A7AC0298 */  sh    $t4, 0x298($sp)
/* 109B80 7F0D5050 100035EA */  b     .L7F0E27FC
/* 109B84 7F0D5054 AFAF0248 */   sw    $t7, 0x248($sp)
.L7F0D5058:
/* 109B88 7F0D5058 97AE0298 */  lhu   $t6, 0x298($sp)
/* 109B8C 7F0D505C 25CA0001 */  addiu $t2, $t6, 1
/* 109B90 7F0D5060 100035E6 */  b     .L7F0E27FC
/* 109B94 7F0D5064 A7AA0298 */   sh    $t2, 0x298($sp)
spectrum_op_29:
/* 109B98 7F0D5068 8FAD028C */  lw    $t5, 0x28c($sp)
/* 109B9C 7F0D506C 93B90287 */  lbu   $t9, 0x287($sp)
/* 109BA0 7F0D5070 25AB000B */  addiu $t3, $t5, 0xb
/* 109BA4 7F0D5074 17200045 */  bnez  $t9, .L7F0D518C
/* 109BA8 7F0D5078 AFAB028C */   sw    $t3, 0x28c($sp)
/* 109BAC 7F0D507C 1720001C */  bnez  $t9, .L7F0D50F0
/* 109BB0 7F0D5080 93A90287 */   lbu   $t1, 0x287($sp)
/* 109BB4 7F0D5084 02F77821 */  addu  $t7, $s7, $s7
/* 109BB8 7F0D5088 31E9FFFF */  andi  $t1, $t7, 0xffff
/* 109BBC 7F0D508C 00096202 */  srl   $t4, $t1, 8
/* 109BC0 7F0D5090 3188FFFF */  andi  $t0, $t4, 0xffff
/* 109BC4 7F0D5094 32D8000F */  andi  $t8, $s6, 0xf
/* 109BC8 7F0D5098 01187021 */  addu  $t6, $t0, $t8
/* 109BCC 7F0D509C 32CA000F */  andi  $t2, $s6, 0xf
/* 109BD0 7F0D50A0 01CA6821 */  addu  $t5, $t6, $t2
/* 109BD4 7F0D50A4 A7AF0246 */  sh    $t7, 0x246($sp)
/* 109BD8 7F0D50A8 2401000F */  li    $at, 15
/* 109BDC 7F0D50AC 002D582A */  slt   $t3, $at, $t5
/* 109BE0 7F0D50B0 93B70247 */  lbu   $s7, 0x247($sp)
/* 109BE4 7F0D50B4 02D64021 */  addu  $t0, $s6, $s6
/* 109BE8 7F0D50B8 01886821 */  addu  $t5, $t4, $t0
/* 109BEC 7F0D50BC A7AC0246 */  sh    $t4, 0x246($sp)
/* 109BF0 7F0D50C0 A7AD0246 */  sh    $t5, 0x246($sp)
/* 109BF4 7F0D50C4 93B60247 */  lbu   $s6, 0x247($sp)
/* 109BF8 7F0D50C8 000BC900 */  sll   $t9, $t3, 4
/* 109BFC 7F0D50CC 322F00C4 */  andi  $t7, $s1, 0xc4
/* 109C00 7F0D50D0 032F4825 */  or    $t1, $t9, $t7
/* 109C04 7F0D50D4 000D5A03 */  sra   $t3, $t5, 8
/* 109C08 7F0D50D8 32CA0028 */  andi  $t2, $s6, 0x28
/* 109C0C 7F0D50DC 014BC825 */  or    $t9, $t2, $t3
/* 109C10 7F0D50E0 01398825 */  or    $s1, $t1, $t9
/* 109C14 7F0D50E4 322F00FF */  andi  $t7, $s1, 0xff
/* 109C18 7F0D50E8 100035C4 */  b     .L7F0E27FC
/* 109C1C 7F0D50EC 01E08825 */   move  $s1, $t7
.L7F0D50F0:
/* 109C20 7F0D50F0 24010001 */  li    $at, 1
/* 109C24 7F0D50F4 15210004 */  bne   $t1, $at, .L7F0D5108
/* 109C28 7F0D50F8 00166A00 */   sll   $t5, $s6, 8
/* 109C2C 7F0D50FC 97AC0296 */  lhu   $t4, 0x296($sp)
/* 109C30 7F0D5100 10000003 */  b     .L7F0D5110
/* 109C34 7F0D5104 AFAC0240 */   sw    $t4, 0x240($sp)
.L7F0D5108:
/* 109C38 7F0D5108 97B80294 */  lhu   $t8, 0x294($sp)
/* 109C3C 7F0D510C AFB80240 */  sw    $t8, 0x240($sp)
.L7F0D5110:
/* 109C40 7F0D5110 8FA80240 */  lw    $t0, 0x240($sp)
/* 109C44 7F0D5114 01B75025 */  or    $t2, $t5, $s7
/* 109C48 7F0D5118 24010FFF */  li    $at, 4095
/* 109C4C 7F0D511C 310E0FFF */  andi  $t6, $t0, 0xfff
/* 109C50 7F0D5120 01CA5821 */  addu  $t3, $t6, $t2
/* 109C54 7F0D5124 002BC82B */  sltu  $t9, $at, $t3
/* 109C58 7F0D5128 93AA0287 */  lbu   $t2, 0x287($sp)
/* 109C5C 7F0D512C 00197900 */  sll   $t7, $t9, 4
/* 109C60 7F0D5130 322900C4 */  andi  $t1, $s1, 0xc4
/* 109C64 7F0D5134 0016C200 */  sll   $t8, $s6, 8
/* 109C68 7F0D5138 03176825 */  or    $t5, $t8, $s7
/* 109C6C 7F0D513C 012F8825 */  or    $s1, $t1, $t7
/* 109C70 7F0D5140 322C00FF */  andi  $t4, $s1, 0xff
/* 109C74 7F0D5144 24010001 */  li    $at, 1
/* 109C78 7F0D5148 010D7021 */  addu  $t6, $t0, $t5
/* 109C7C 7F0D514C AFAE0240 */  sw    $t6, 0x240($sp)
/* 109C80 7F0D5150 15410003 */  bne   $t2, $at, .L7F0D5160
/* 109C84 7F0D5154 01808825 */   move  $s1, $t4
/* 109C88 7F0D5158 10000003 */  b     .L7F0D5168
/* 109C8C 7F0D515C A7AE0296 */   sh    $t6, 0x296($sp)
.L7F0D5160:
/* 109C90 7F0D5160 8FAB0240 */  lw    $t3, 0x240($sp)
/* 109C94 7F0D5164 A7AB0294 */  sh    $t3, 0x294($sp)
.L7F0D5168:
/* 109C98 7F0D5168 8FB90240 */  lw    $t9, 0x240($sp)
/* 109C9C 7F0D516C 00194A02 */  srl   $t1, $t9, 8
/* 109CA0 7F0D5170 312F0028 */  andi  $t7, $t1, 0x28
/* 109CA4 7F0D5174 00196402 */  srl   $t4, $t9, 0x10
/* 109CA8 7F0D5178 01ECC025 */  or    $t8, $t7, $t4
/* 109CAC 7F0D517C 02388825 */  or    $s1, $s1, $t8
/* 109CB0 7F0D5180 322800FF */  andi  $t0, $s1, 0xff
/* 109CB4 7F0D5184 1000359D */  b     .L7F0E27FC
/* 109CB8 7F0D5188 01008825 */   move  $s1, $t0
.L7F0D518C:
/* 109CBC 7F0D518C 93AD0287 */  lbu   $t5, 0x287($sp)
/* 109CC0 7F0D5190 24010001 */  li    $at, 1
/* 109CC4 7F0D5194 93A90287 */  lbu   $t1, 0x287($sp)
/* 109CC8 7F0D5198 15A10049 */  bne   $t5, $at, .L7F0D52C0
/* 109CCC 7F0D519C 00000000 */   nop   
/* 109CD0 7F0D51A0 15A0001F */  bnez  $t5, .L7F0D5220
/* 109CD4 7F0D51A4 93A80287 */   lbu   $t0, 0x287($sp)
/* 109CD8 7F0D51A8 97AA0296 */  lhu   $t2, 0x296($sp)
/* 109CDC 7F0D51AC 32CF000F */  andi  $t7, $s6, 0xf
/* 109CE0 7F0D51B0 2401000F */  li    $at, 15
/* 109CE4 7F0D51B4 314E00FF */  andi  $t6, $t2, 0xff
/* 109CE8 7F0D51B8 02EE5821 */  addu  $t3, $s7, $t6
/* 109CEC 7F0D51BC 3169FFFF */  andi  $t1, $t3, 0xffff
/* 109CF0 7F0D51C0 0009CA02 */  srl   $t9, $t1, 8
/* 109CF4 7F0D51C4 332CFFFF */  andi  $t4, $t9, 0xffff
/* 109CF8 7F0D51C8 000A4203 */  sra   $t0, $t2, 8
/* 109CFC 7F0D51CC 310D000F */  andi  $t5, $t0, 0xf
/* 109D00 7F0D51D0 018FC021 */  addu  $t8, $t4, $t7
/* 109D04 7F0D51D4 030D7021 */  addu  $t6, $t8, $t5
/* 109D08 7F0D51D8 A7AB023E */  sh    $t3, 0x23e($sp)
/* 109D0C 7F0D51DC 002E582A */  slt   $t3, $at, $t6
/* 109D10 7F0D51E0 000B4900 */  sll   $t1, $t3, 4
/* 109D14 7F0D51E4 93B7023F */  lbu   $s7, 0x23f($sp)
/* 109D18 7F0D51E8 02C85021 */  addu  $t2, $s6, $t0
/* 109D1C 7F0D51EC 032A5821 */  addu  $t3, $t9, $t2
/* 109D20 7F0D51F0 A7B9023E */  sh    $t9, 0x23e($sp)
/* 109D24 7F0D51F4 A7AB023E */  sh    $t3, 0x23e($sp)
/* 109D28 7F0D51F8 93B6023F */  lbu   $s6, 0x23f($sp)
/* 109D2C 7F0D51FC 322C00C4 */  andi  $t4, $s1, 0xc4
/* 109D30 7F0D5200 012C7825 */  or    $t7, $t1, $t4
/* 109D34 7F0D5204 000B4A03 */  sra   $t1, $t3, 8
/* 109D38 7F0D5208 32CE0028 */  andi  $t6, $s6, 0x28
/* 109D3C 7F0D520C 01C96025 */  or    $t4, $t6, $t1
/* 109D40 7F0D5210 01EC8825 */  or    $s1, $t7, $t4
/* 109D44 7F0D5214 322F00FF */  andi  $t7, $s1, 0xff
/* 109D48 7F0D5218 10003578 */  b     .L7F0E27FC
/* 109D4C 7F0D521C 01E08825 */   move  $s1, $t7
.L7F0D5220:
/* 109D50 7F0D5220 24010001 */  li    $at, 1
/* 109D54 7F0D5224 15010004 */  bne   $t0, $at, .L7F0D5238
/* 109D58 7F0D5228 97B80294 */   lhu   $t8, 0x294($sp)
/* 109D5C 7F0D522C 97B90296 */  lhu   $t9, 0x296($sp)
/* 109D60 7F0D5230 10000002 */  b     .L7F0D523C
/* 109D64 7F0D5234 AFB90238 */   sw    $t9, 0x238($sp)
.L7F0D5238:
/* 109D68 7F0D5238 AFB80238 */  sw    $t8, 0x238($sp)
.L7F0D523C:
/* 109D6C 7F0D523C 97AA0296 */  lhu   $t2, 0x296($sp)
/* 109D70 7F0D5240 8FAC0238 */  lw    $t4, 0x238($sp)
/* 109D74 7F0D5244 24010FFF */  li    $at, 4095
/* 109D78 7F0D5248 000A6A03 */  sra   $t5, $t2, 8
/* 109D7C 7F0D524C 000D5A00 */  sll   $t3, $t5, 8
/* 109D80 7F0D5250 314E00FF */  andi  $t6, $t2, 0xff
/* 109D84 7F0D5254 016E4825 */  or    $t1, $t3, $t6
/* 109D88 7F0D5258 318F0FFF */  andi  $t7, $t4, 0xfff
/* 109D8C 7F0D525C 01E94021 */  addu  $t0, $t7, $t1
/* 109D90 7F0D5260 0028C82B */  sltu  $t9, $at, $t0
/* 109D94 7F0D5264 93AE0287 */  lbu   $t6, 0x287($sp)
/* 109D98 7F0D5268 0019C100 */  sll   $t8, $t9, 4
/* 109D9C 7F0D526C 322D00C4 */  andi  $t5, $s1, 0xc4
/* 109DA0 7F0D5270 01B88825 */  or    $s1, $t5, $t8
/* 109DA4 7F0D5274 322A00FF */  andi  $t2, $s1, 0xff
/* 109DA8 7F0D5278 24010001 */  li    $at, 1
/* 109DAC 7F0D527C 01895821 */  addu  $t3, $t4, $t1
/* 109DB0 7F0D5280 AFAB0238 */  sw    $t3, 0x238($sp)
/* 109DB4 7F0D5284 15C10003 */  bne   $t6, $at, .L7F0D5294
/* 109DB8 7F0D5288 01408825 */   move  $s1, $t2
/* 109DBC 7F0D528C 10000003 */  b     .L7F0D529C
/* 109DC0 7F0D5290 A7AB0296 */   sh    $t3, 0x296($sp)
.L7F0D5294:
/* 109DC4 7F0D5294 8FAF0238 */  lw    $t7, 0x238($sp)
/* 109DC8 7F0D5298 A7AF0294 */  sh    $t7, 0x294($sp)
.L7F0D529C:
/* 109DCC 7F0D529C 8FA80238 */  lw    $t0, 0x238($sp)
/* 109DD0 7F0D52A0 0008CA02 */  srl   $t9, $t0, 8
/* 109DD4 7F0D52A4 332D0028 */  andi  $t5, $t9, 0x28
/* 109DD8 7F0D52A8 0008C402 */  srl   $t8, $t0, 0x10
/* 109DDC 7F0D52AC 01B85025 */  or    $t2, $t5, $t8
/* 109DE0 7F0D52B0 022A8825 */  or    $s1, $s1, $t2
/* 109DE4 7F0D52B4 322C00FF */  andi  $t4, $s1, 0xff
/* 109DE8 7F0D52B8 10003550 */  b     .L7F0E27FC
/* 109DEC 7F0D52BC 01808825 */   move  $s1, $t4
.L7F0D52C0:
/* 109DF0 7F0D52C0 1520001F */  bnez  $t1, .L7F0D5340
/* 109DF4 7F0D52C4 93AC0287 */   lbu   $t4, 0x287($sp)
/* 109DF8 7F0D52C8 97AE0294 */  lhu   $t6, 0x294($sp)
/* 109DFC 7F0D52CC 32CD000F */  andi  $t5, $s6, 0xf
/* 109E00 7F0D52D0 2401000F */  li    $at, 15
/* 109E04 7F0D52D4 31CB00FF */  andi  $t3, $t6, 0xff
/* 109E08 7F0D52D8 02EB7821 */  addu  $t7, $s7, $t3
/* 109E0C 7F0D52DC 31F9FFFF */  andi  $t9, $t7, 0xffff
/* 109E10 7F0D52E0 00194202 */  srl   $t0, $t9, 8
/* 109E14 7F0D52E4 3118FFFF */  andi  $t8, $t0, 0xffff
/* 109E18 7F0D52E8 000E6203 */  sra   $t4, $t6, 8
/* 109E1C 7F0D52EC 3189000F */  andi  $t1, $t4, 0xf
/* 109E20 7F0D52F0 030D5021 */  addu  $t2, $t8, $t5
/* 109E24 7F0D52F4 01495821 */  addu  $t3, $t2, $t1
/* 109E28 7F0D52F8 A7AF0236 */  sh    $t7, 0x236($sp)
/* 109E2C 7F0D52FC 002B782A */  slt   $t7, $at, $t3
/* 109E30 7F0D5300 000FC900 */  sll   $t9, $t7, 4
/* 109E34 7F0D5304 93B70237 */  lbu   $s7, 0x237($sp)
/* 109E38 7F0D5308 02CC7021 */  addu  $t6, $s6, $t4
/* 109E3C 7F0D530C 010E7821 */  addu  $t7, $t0, $t6
/* 109E40 7F0D5310 A7A80236 */  sh    $t0, 0x236($sp)
/* 109E44 7F0D5314 A7AF0236 */  sh    $t7, 0x236($sp)
/* 109E48 7F0D5318 93B60237 */  lbu   $s6, 0x237($sp)
/* 109E4C 7F0D531C 323800C4 */  andi  $t8, $s1, 0xc4
/* 109E50 7F0D5320 03386825 */  or    $t5, $t9, $t8
/* 109E54 7F0D5324 000FCA03 */  sra   $t9, $t7, 8
/* 109E58 7F0D5328 32CB0028 */  andi  $t3, $s6, 0x28
/* 109E5C 7F0D532C 0179C025 */  or    $t8, $t3, $t9
/* 109E60 7F0D5330 01B88825 */  or    $s1, $t5, $t8
/* 109E64 7F0D5334 322D00FF */  andi  $t5, $s1, 0xff
/* 109E68 7F0D5338 10003530 */  b     .L7F0E27FC
/* 109E6C 7F0D533C 01A08825 */   move  $s1, $t5
.L7F0D5340:
/* 109E70 7F0D5340 24010001 */  li    $at, 1
/* 109E74 7F0D5344 15810004 */  bne   $t4, $at, .L7F0D5358
/* 109E78 7F0D5348 97AA0294 */   lhu   $t2, 0x294($sp)
/* 109E7C 7F0D534C 97A80296 */  lhu   $t0, 0x296($sp)
/* 109E80 7F0D5350 10000002 */  b     .L7F0D535C
/* 109E84 7F0D5354 AFA80230 */   sw    $t0, 0x230($sp)
.L7F0D5358:
/* 109E88 7F0D5358 AFAA0230 */  sw    $t2, 0x230($sp)
.L7F0D535C:
/* 109E8C 7F0D535C 97AE0294 */  lhu   $t6, 0x294($sp)
/* 109E90 7F0D5360 8FB80230 */  lw    $t8, 0x230($sp)
/* 109E94 7F0D5364 24010FFF */  li    $at, 4095
/* 109E98 7F0D5368 000E4A03 */  sra   $t1, $t6, 8
/* 109E9C 7F0D536C 00097A00 */  sll   $t7, $t1, 8
/* 109EA0 7F0D5370 31CB00FF */  andi  $t3, $t6, 0xff
/* 109EA4 7F0D5374 01EBC825 */  or    $t9, $t7, $t3
/* 109EA8 7F0D5378 330D0FFF */  andi  $t5, $t8, 0xfff
/* 109EAC 7F0D537C 01B96021 */  addu  $t4, $t5, $t9
/* 109EB0 7F0D5380 002C402B */  sltu  $t0, $at, $t4
/* 109EB4 7F0D5384 93AB0287 */  lbu   $t3, 0x287($sp)
/* 109EB8 7F0D5388 00085100 */  sll   $t2, $t0, 4
/* 109EBC 7F0D538C 322900C4 */  andi  $t1, $s1, 0xc4
/* 109EC0 7F0D5390 012A8825 */  or    $s1, $t1, $t2
/* 109EC4 7F0D5394 322E00FF */  andi  $t6, $s1, 0xff
/* 109EC8 7F0D5398 24010001 */  li    $at, 1
/* 109ECC 7F0D539C 03197821 */  addu  $t7, $t8, $t9
/* 109ED0 7F0D53A0 AFAF0230 */  sw    $t7, 0x230($sp)
/* 109ED4 7F0D53A4 15610003 */  bne   $t3, $at, .L7F0D53B4
/* 109ED8 7F0D53A8 01C08825 */   move  $s1, $t6
/* 109EDC 7F0D53AC 10000003 */  b     .L7F0D53BC
/* 109EE0 7F0D53B0 A7AF0296 */   sh    $t7, 0x296($sp)
.L7F0D53B4:
/* 109EE4 7F0D53B4 8FAD0230 */  lw    $t5, 0x230($sp)
/* 109EE8 7F0D53B8 A7AD0294 */  sh    $t5, 0x294($sp)
.L7F0D53BC:
/* 109EEC 7F0D53BC 8FAC0230 */  lw    $t4, 0x230($sp)
/* 109EF0 7F0D53C0 000C4202 */  srl   $t0, $t4, 8
/* 109EF4 7F0D53C4 31090028 */  andi  $t1, $t0, 0x28
/* 109EF8 7F0D53C8 000C5402 */  srl   $t2, $t4, 0x10
/* 109EFC 7F0D53CC 012A7025 */  or    $t6, $t1, $t2
/* 109F00 7F0D53D0 022E8825 */  or    $s1, $s1, $t6
/* 109F04 7F0D53D4 323800FF */  andi  $t8, $s1, 0xff
/* 109F08 7F0D53D8 10003508 */  b     .L7F0E27FC
/* 109F0C 7F0D53DC 03008825 */   move  $s1, $t8
spectrum_op_2A:
/* 109F10 7F0D53E0 8FB9028C */  lw    $t9, 0x28c($sp)
/* 109F14 7F0D53E4 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 109F18 7F0D53E8 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 109F1C 7F0D53EC 97AF0298 */  lhu   $t7, 0x298($sp)
/* 109F20 7F0D53F0 272B0010 */  addiu $t3, $t9, 0x10
/* 109F24 7F0D53F4 AFAB028C */  sw    $t3, 0x28c($sp)
/* 109F28 7F0D53F8 01AF4821 */  addu  $t1, $t5, $t7
/* 109F2C 7F0D53FC 912A0001 */  lbu   $t2, 1($t1)
/* 109F30 7F0D5400 01ED4021 */  addu  $t0, $t7, $t5
/* 109F34 7F0D5404 910C0000 */  lbu   $t4, ($t0)
/* 109F38 7F0D5408 93AB0287 */  lbu   $t3, 0x287($sp)
/* 109F3C 7F0D540C 000A7200 */  sll   $t6, $t2, 8
/* 109F40 7F0D5410 25F90002 */  addiu $t9, $t7, 2
/* 109F44 7F0D5414 018EC025 */  or    $t8, $t4, $t6
/* 109F48 7F0D5418 A7B8022E */  sh    $t8, 0x22e($sp)
/* 109F4C 7F0D541C 15600006 */  bnez  $t3, .L7F0D5438
/* 109F50 7F0D5420 A7B90298 */   sh    $t9, 0x298($sp)
/* 109F54 7F0D5424 3308FFFF */  andi  $t0, $t8, 0xffff
/* 109F58 7F0D5428 010D4821 */  addu  $t1, $t0, $t5
/* 109F5C 7F0D542C 91370000 */  lbu   $s7, ($t1)
/* 109F60 7F0D5430 100034F2 */  b     .L7F0E27FC
/* 109F64 7F0D5434 91360001 */   lbu   $s6, 1($t1)
.L7F0D5438:
/* 109F68 7F0D5438 93AA0287 */  lbu   $t2, 0x287($sp)
/* 109F6C 7F0D543C 24010001 */  li    $at, 1
/* 109F70 7F0D5440 97AC022E */  lhu   $t4, 0x22e($sp)
/* 109F74 7F0D5444 1541000B */  bne   $t2, $at, .L7F0D5474
/* 109F78 7F0D5448 97A9022E */   lhu   $t1, 0x22e($sp)
/* 109F7C 7F0D544C 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 109F80 7F0D5450 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 109F84 7F0D5454 01CCC821 */  addu  $t9, $t6, $t4
/* 109F88 7F0D5458 932B0001 */  lbu   $t3, 1($t9)
/* 109F8C 7F0D545C 018EC021 */  addu  $t8, $t4, $t6
/* 109F90 7F0D5460 930F0000 */  lbu   $t7, ($t8)
/* 109F94 7F0D5464 000B4200 */  sll   $t0, $t3, 8
/* 109F98 7F0D5468 01E86825 */  or    $t5, $t7, $t0
/* 109F9C 7F0D546C 100034E3 */  b     .L7F0E27FC
/* 109FA0 7F0D5470 A7AD0296 */   sh    $t5, 0x296($sp)
.L7F0D5474:
/* 109FA4 7F0D5474 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 109FA8 7F0D5478 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 109FAC 7F0D547C 01496021 */  addu  $t4, $t2, $t1
/* 109FB0 7F0D5480 91990001 */  lbu   $t9, 1($t4)
/* 109FB4 7F0D5484 012AC021 */  addu  $t8, $t1, $t2
/* 109FB8 7F0D5488 930E0000 */  lbu   $t6, ($t8)
/* 109FBC 7F0D548C 00195A00 */  sll   $t3, $t9, 8
/* 109FC0 7F0D5490 01CB7825 */  or    $t7, $t6, $t3
/* 109FC4 7F0D5494 100034D9 */  b     .L7F0E27FC
/* 109FC8 7F0D5498 A7AF0294 */   sh    $t7, 0x294($sp)
spectrum_op_2B:
/* 109FCC 7F0D549C 8FA8028C */  lw    $t0, 0x28c($sp)
/* 109FD0 7F0D54A0 93B80287 */  lbu   $t8, 0x287($sp)
/* 109FD4 7F0D54A4 93AE0287 */  lbu   $t6, 0x287($sp)
/* 109FD8 7F0D54A8 250D0006 */  addiu $t5, $t0, 6
/* 109FDC 7F0D54AC 1700000B */  bnez  $t8, .L7F0D54DC
/* 109FE0 7F0D54B0 AFAD028C */   sw    $t5, 0x28c($sp)
/* 109FE4 7F0D54B4 2EEA0001 */  sltiu $t2, $s7, 1
/* 109FE8 7F0D54B8 26F7FFFF */  addiu $s7, $s7, -1
/* 109FEC 7F0D54BC 32E900FF */  andi  $t1, $s7, 0xff
/* 109FF0 7F0D54C0 0120B825 */  move  $s7, $t1
/* 109FF4 7F0D54C4 114034CD */  beqz  $t2, .L7F0E27FC
/* 109FF8 7F0D54C8 AFAA0048 */   sw    $t2, 0x48($sp)
/* 109FFC 7F0D54CC 26D6FFFF */  addiu $s6, $s6, -1
/* 10A000 7F0D54D0 32D900FF */  andi  $t9, $s6, 0xff
/* 10A004 7F0D54D4 100034C9 */  b     .L7F0E27FC
/* 10A008 7F0D54D8 0320B025 */   move  $s6, $t9
.L7F0D54DC:
/* 10A00C 7F0D54DC 24010001 */  li    $at, 1
/* 10A010 7F0D54E0 15C10005 */  bne   $t6, $at, .L7F0D54F8
/* 10A014 7F0D54E4 97A80294 */   lhu   $t0, 0x294($sp)
/* 10A018 7F0D54E8 97AB0296 */  lhu   $t3, 0x296($sp)
/* 10A01C 7F0D54EC 256FFFFF */  addiu $t7, $t3, -1
/* 10A020 7F0D54F0 100034C2 */  b     .L7F0E27FC
/* 10A024 7F0D54F4 A7AF0296 */   sh    $t7, 0x296($sp)
.L7F0D54F8:
/* 10A028 7F0D54F8 250DFFFF */  addiu $t5, $t0, -1
/* 10A02C 7F0D54FC 100034BF */  b     .L7F0E27FC
/* 10A030 7F0D5500 A7AD0294 */   sh    $t5, 0x294($sp)
spectrum_op_2C:
/* 10A034 7F0D5504 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10A038 7F0D5508 93A90287 */  lbu   $t1, 0x287($sp)
/* 10A03C 7F0D550C 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10A040 7F0D5510 270A0004 */  addiu $t2, $t8, 4
/* 10A044 7F0D5514 15200017 */  bnez  $t1, .L7F0D5574
/* 10A048 7F0D5518 AFAA028C */   sw    $t2, 0x28c($sp)
/* 10A04C 7F0D551C 26F70001 */  addiu $s7, $s7, 1
/* 10A050 7F0D5520 32EC00FF */  andi  $t4, $s7, 0xff
/* 10A054 7F0D5524 318E000F */  andi  $t6, $t4, 0xf
/* 10A058 7F0D5528 2DCB0001 */  sltiu $t3, $t6, 1
/* 10A05C 7F0D552C 0180B825 */  move  $s7, $t4
/* 10A060 7F0D5530 2D990001 */  sltiu $t9, $t4, 1
/* 10A064 7F0D5534 318800A8 */  andi  $t0, $t4, 0xa8
/* 10A068 7F0D5538 322F0001 */  andi  $t7, $s1, 1
/* 10A06C 7F0D553C 01E86825 */  or    $t5, $t7, $t0
/* 10A070 7F0D5540 3AEE0080 */  xori  $t6, $s7, 0x80
/* 10A074 7F0D5544 000BC100 */  sll   $t8, $t3, 4
/* 10A078 7F0D5548 01B85025 */  or    $t2, $t5, $t8
/* 10A07C 7F0D554C 2DCE0001 */  sltiu $t6, $t6, 1
/* 10A080 7F0D5550 00196180 */  sll   $t4, $t9, 6
/* 10A084 7F0D5554 AFB90044 */  sw    $t9, 0x44($sp)
/* 10A088 7F0D5558 014CC825 */  or    $t9, $t2, $t4
/* 10A08C 7F0D555C 000E7880 */  sll   $t7, $t6, 2
/* 10A090 7F0D5560 032F8825 */  or    $s1, $t9, $t7
/* 10A094 7F0D5564 322800FF */  andi  $t0, $s1, 0xff
/* 10A098 7F0D5568 01008825 */  move  $s1, $t0
/* 10A09C 7F0D556C 100034A3 */  b     .L7F0E27FC
/* 10A0A0 7F0D5570 AFAB0048 */   sw    $t3, 0x48($sp)
.L7F0D5574:
/* 10A0A4 7F0D5574 24010001 */  li    $at, 1
/* 10A0A8 7F0D5578 15610004 */  bne   $t3, $at, .L7F0D558C
/* 10A0AC 7F0D557C 97B80294 */   lhu   $t8, 0x294($sp)
/* 10A0B0 7F0D5580 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10A0B4 7F0D5584 10000002 */  b     .L7F0D5590
/* 10A0B8 7F0D5588 A3AD022D */   sb    $t5, 0x22d($sp)
.L7F0D558C:
/* 10A0BC 7F0D558C A3B8022D */  sb    $t8, 0x22d($sp)
.L7F0D5590:
/* 10A0C0 7F0D5590 93A9022D */  lbu   $t1, 0x22d($sp)
/* 10A0C4 7F0D5594 322B0001 */  andi  $t3, $s1, 1
/* 10A0C8 7F0D5598 24010001 */  li    $at, 1
/* 10A0CC 7F0D559C 252A0001 */  addiu $t2, $t1, 1
/* 10A0D0 7F0D55A0 315800A8 */  andi  $t8, $t2, 0xa8
/* 10A0D4 7F0D55A4 01784825 */  or    $t1, $t3, $t8
/* 10A0D8 7F0D55A8 314C00FF */  andi  $t4, $t2, 0xff
/* 10A0DC 7F0D55AC 314F000F */  andi  $t7, $t2, 0xf
/* 10A0E0 7F0D55B0 2DE80001 */  sltiu $t0, $t7, 1
/* 10A0E4 7F0D55B4 2D8E0001 */  sltiu $t6, $t4, 1
/* 10A0E8 7F0D55B8 00086100 */  sll   $t4, $t0, 4
/* 10A0EC 7F0D55BC 314B00FF */  andi  $t3, $t2, 0xff
/* 10A0F0 7F0D55C0 39780080 */  xori  $t8, $t3, 0x80
/* 10A0F4 7F0D55C4 012CC825 */  or    $t9, $t1, $t4
/* 10A0F8 7F0D55C8 2F180001 */  sltiu $t8, $t8, 1
/* 10A0FC 7F0D55CC 000E7980 */  sll   $t7, $t6, 6
/* 10A100 7F0D55D0 AFA80048 */  sw    $t0, 0x48($sp)
/* 10A104 7F0D55D4 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10A108 7F0D55D8 00184080 */  sll   $t0, $t8, 2
/* 10A10C 7F0D55DC 032F6825 */  or    $t5, $t9, $t7
/* 10A110 7F0D55E0 01A88825 */  or    $s1, $t5, $t0
/* 10A114 7F0D55E4 322900FF */  andi  $t1, $s1, 0xff
/* 10A118 7F0D55E8 01208825 */  move  $s1, $t1
/* 10A11C 7F0D55EC AFAE0044 */  sw    $t6, 0x44($sp)
/* 10A120 7F0D55F0 15810007 */  bne   $t4, $at, .L7F0D5610
/* 10A124 7F0D55F4 A3AA022D */   sb    $t2, 0x22d($sp)
/* 10A128 7F0D55F8 97AE0296 */  lhu   $t6, 0x296($sp)
/* 10A12C 7F0D55FC 314F00FF */  andi  $t7, $t2, 0xff
/* 10A130 7F0D5600 31D9FF00 */  andi  $t9, $t6, 0xff00
/* 10A134 7F0D5604 032F5825 */  or    $t3, $t9, $t7
/* 10A138 7F0D5608 1000347C */  b     .L7F0E27FC
/* 10A13C 7F0D560C A7AB0296 */   sh    $t3, 0x296($sp)
.L7F0D5610:
/* 10A140 7F0D5610 97B80294 */  lhu   $t8, 0x294($sp)
/* 10A144 7F0D5614 93A8022D */  lbu   $t0, 0x22d($sp)
/* 10A148 7F0D5618 330DFF00 */  andi  $t5, $t8, 0xff00
/* 10A14C 7F0D561C 01A84825 */  or    $t1, $t5, $t0
/* 10A150 7F0D5620 10003476 */  b     .L7F0E27FC
/* 10A154 7F0D5624 A7A90294 */   sh    $t1, 0x294($sp)
spectrum_op_2D:
/* 10A158 7F0D5628 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10A15C 7F0D562C 93AA0287 */  lbu   $t2, 0x287($sp)
/* 10A160 7F0D5630 93A90287 */  lbu   $t1, 0x287($sp)
/* 10A164 7F0D5634 258E0004 */  addiu $t6, $t4, 4
/* 10A168 7F0D5638 15400018 */  bnez  $t2, .L7F0D569C
/* 10A16C 7F0D563C AFAE028C */   sw    $t6, 0x28c($sp)
/* 10A170 7F0D5640 32F9000F */  andi  $t9, $s7, 0xf
/* 10A174 7F0D5644 26F7FFFF */  addiu $s7, $s7, -1
/* 10A178 7F0D5648 32E900FF */  andi  $t1, $s7, 0xff
/* 10A17C 7F0D564C 2F2F0001 */  sltiu $t7, $t9, 1
/* 10A180 7F0D5650 000FC100 */  sll   $t8, $t7, 4
/* 10A184 7F0D5654 392A007F */  xori  $t2, $t1, 0x7f
/* 10A188 7F0D5658 2D4A0001 */  sltiu $t2, $t2, 1
/* 10A18C 7F0D565C 322B0001 */  andi  $t3, $s1, 1
/* 10A190 7F0D5660 01788825 */  or    $s1, $t3, $t8
/* 10A194 7F0D5664 000AC880 */  sll   $t9, $t2, 2
/* 10A198 7F0D5668 AFAF0048 */  sw    $t7, 0x48($sp)
/* 10A19C 7F0D566C 2D2C0001 */  sltiu $t4, $t1, 1
/* 10A1A0 7F0D5670 312E00A8 */  andi  $t6, $t1, 0xa8
/* 10A1A4 7F0D5674 01D97825 */  or    $t7, $t6, $t9
/* 10A1A8 7F0D5678 000CC180 */  sll   $t8, $t4, 6
/* 10A1AC 7F0D567C 01F86825 */  or    $t5, $t7, $t8
/* 10A1B0 7F0D5680 36280002 */  ori   $t0, $s1, 2
/* 10A1B4 7F0D5684 010D8825 */  or    $s1, $t0, $t5
/* 10A1B8 7F0D5688 322800FF */  andi  $t0, $s1, 0xff
/* 10A1BC 7F0D568C 01008825 */  move  $s1, $t0
/* 10A1C0 7F0D5690 AFAC0044 */  sw    $t4, 0x44($sp)
/* 10A1C4 7F0D5694 10003459 */  b     .L7F0E27FC
/* 10A1C8 7F0D5698 0120B825 */   move  $s7, $t1
.L7F0D569C:
/* 10A1CC 7F0D569C 24010001 */  li    $at, 1
/* 10A1D0 7F0D56A0 15210004 */  bne   $t1, $at, .L7F0D56B4
/* 10A1D4 7F0D56A4 97AA0294 */   lhu   $t2, 0x294($sp)
/* 10A1D8 7F0D56A8 97AC0296 */  lhu   $t4, 0x296($sp)
/* 10A1DC 7F0D56AC 10000002 */  b     .L7F0D56B8
/* 10A1E0 7F0D56B0 A3AC022C */   sb    $t4, 0x22c($sp)
.L7F0D56B4:
/* 10A1E4 7F0D56B4 A3AA022C */  sb    $t2, 0x22c($sp)
.L7F0D56B8:
/* 10A1E8 7F0D56B8 93AE022C */  lbu   $t6, 0x22c($sp)
/* 10A1EC 7F0D56BC 322F0001 */  andi  $t7, $s1, 1
/* 10A1F0 7F0D56C0 24010001 */  li    $at, 1
/* 10A1F4 7F0D56C4 31D9000F */  andi  $t9, $t6, 0xf
/* 10A1F8 7F0D56C8 2F2B0001 */  sltiu $t3, $t9, 1
/* 10A1FC 7F0D56CC 000BC100 */  sll   $t8, $t3, 4
/* 10A200 7F0D56D0 01F88825 */  or    $s1, $t7, $t8
/* 10A204 7F0D56D4 25C9FFFF */  addiu $t1, $t6, -1
/* 10A208 7F0D56D8 312F00FF */  andi  $t7, $t1, 0xff
/* 10A20C 7F0D56DC 39F8007F */  xori  $t8, $t7, 0x7f
/* 10A210 7F0D56E0 362D0002 */  ori   $t5, $s1, 2
/* 10A214 7F0D56E4 01A08825 */  move  $s1, $t5
/* 10A218 7F0D56E8 2F180001 */  sltiu $t8, $t8, 1
/* 10A21C 7F0D56EC 312C00FF */  andi  $t4, $t1, 0xff
/* 10A220 7F0D56F0 AFAB0048 */  sw    $t3, 0x48($sp)
/* 10A224 7F0D56F4 312B00A8 */  andi  $t3, $t1, 0xa8
/* 10A228 7F0D56F8 2D8A0001 */  sltiu $t2, $t4, 1
/* 10A22C 7F0D56FC 00186880 */  sll   $t5, $t8, 2
/* 10A230 7F0D5700 016D4025 */  or    $t0, $t3, $t5
/* 10A234 7F0D5704 000A7180 */  sll   $t6, $t2, 6
/* 10A238 7F0D5708 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10A23C 7F0D570C 010E6025 */  or    $t4, $t0, $t6
/* 10A240 7F0D5710 022C8825 */  or    $s1, $s1, $t4
/* 10A244 7F0D5714 323900FF */  andi  $t9, $s1, 0xff
/* 10A248 7F0D5718 03208825 */  move  $s1, $t9
/* 10A24C 7F0D571C AFAA0044 */  sw    $t2, 0x44($sp)
/* 10A250 7F0D5720 15E10007 */  bne   $t7, $at, .L7F0D5740
/* 10A254 7F0D5724 A3A9022C */   sb    $t1, 0x22c($sp)
/* 10A258 7F0D5728 97B80296 */  lhu   $t8, 0x296($sp)
/* 10A25C 7F0D572C 312D00FF */  andi  $t5, $t1, 0xff
/* 10A260 7F0D5730 330BFF00 */  andi  $t3, $t8, 0xff00
/* 10A264 7F0D5734 016D5025 */  or    $t2, $t3, $t5
/* 10A268 7F0D5738 10003430 */  b     .L7F0E27FC
/* 10A26C 7F0D573C A7AA0296 */   sh    $t2, 0x296($sp)
.L7F0D5740:
/* 10A270 7F0D5740 97A80294 */  lhu   $t0, 0x294($sp)
/* 10A274 7F0D5744 93AC022C */  lbu   $t4, 0x22c($sp)
/* 10A278 7F0D5748 310EFF00 */  andi  $t6, $t0, 0xff00
/* 10A27C 7F0D574C 01CCC825 */  or    $t9, $t6, $t4
/* 10A280 7F0D5750 1000342A */  b     .L7F0E27FC
/* 10A284 7F0D5754 A7B90294 */   sh    $t9, 0x294($sp)
spectrum_op_2E:
/* 10A288 7F0D5758 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10A28C 7F0D575C 93A90287 */  lbu   $t1, 0x287($sp)
/* 10A290 7F0D5760 93A80287 */  lbu   $t0, 0x287($sp)
/* 10A294 7F0D5764 25F80007 */  addiu $t8, $t7, 7
/* 10A298 7F0D5768 15200007 */  bnez  $t1, .L7F0D5788
/* 10A29C 7F0D576C AFB8028C */   sw    $t8, 0x28c($sp)
/* 10A2A0 7F0D5770 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 10A2A4 7F0D5774 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10A2A8 7F0D5778 97AB0298 */  lhu   $t3, 0x298($sp)
/* 10A2AC 7F0D577C 016D5021 */  addu  $t2, $t3, $t5
/* 10A2B0 7F0D5780 10000016 */  b     .L7F0D57DC
/* 10A2B4 7F0D5784 91570000 */   lbu   $s7, ($t2)
.L7F0D5788:
/* 10A2B8 7F0D5788 24010001 */  li    $at, 1
/* 10A2BC 7F0D578C 1501000B */  bne   $t0, $at, .L7F0D57BC
/* 10A2C0 7F0D5790 97AD0298 */   lhu   $t5, 0x298($sp)
/* 10A2C4 7F0D5794 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 10A2C8 7F0D5798 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 10A2CC 7F0D579C 97AE0298 */  lhu   $t6, 0x298($sp)
/* 10A2D0 7F0D57A0 97B80296 */  lhu   $t8, 0x296($sp)
/* 10A2D4 7F0D57A4 01CCC821 */  addu  $t9, $t6, $t4
/* 10A2D8 7F0D57A8 932F0000 */  lbu   $t7, ($t9)
/* 10A2DC 7F0D57AC 3309FF00 */  andi  $t1, $t8, 0xff00
/* 10A2E0 7F0D57B0 01E95825 */  or    $t3, $t7, $t1
/* 10A2E4 7F0D57B4 10000009 */  b     .L7F0D57DC
/* 10A2E8 7F0D57B8 A7AB0296 */   sh    $t3, 0x296($sp)
.L7F0D57BC:
/* 10A2EC 7F0D57BC 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 10A2F0 7F0D57C0 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 10A2F4 7F0D57C4 97AC0294 */  lhu   $t4, 0x294($sp)
/* 10A2F8 7F0D57C8 01AA4021 */  addu  $t0, $t5, $t2
/* 10A2FC 7F0D57CC 910E0000 */  lbu   $t6, ($t0)
/* 10A300 7F0D57D0 3199FF00 */  andi  $t9, $t4, 0xff00
/* 10A304 7F0D57D4 01D9C025 */  or    $t8, $t6, $t9
/* 10A308 7F0D57D8 A7B80294 */  sh    $t8, 0x294($sp)
.L7F0D57DC:
/* 10A30C 7F0D57DC 97AF0298 */  lhu   $t7, 0x298($sp)
/* 10A310 7F0D57E0 25E90001 */  addiu $t1, $t7, 1
/* 10A314 7F0D57E4 10003405 */  b     .L7F0E27FC
/* 10A318 7F0D57E8 A7A90298 */   sh    $t1, 0x298($sp)
spectrum_op_2F:
/* 10A31C 7F0D57EC 02008027 */  not   $s0, $s0
/* 10A320 7F0D57F0 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10A324 7F0D57F4 320A00FF */  andi  $t2, $s0, 0xff
/* 10A328 7F0D57F8 314C0028 */  andi  $t4, $t2, 0x28
/* 10A32C 7F0D57FC 322800C5 */  andi  $t0, $s1, 0xc5
/* 10A330 7F0D5800 010C8825 */  or    $s1, $t0, $t4
/* 10A334 7F0D5804 362E0012 */  ori   $t6, $s1, 0x12
/* 10A338 7F0D5808 256D0004 */  addiu $t5, $t3, 4
/* 10A33C 7F0D580C AFAD028C */  sw    $t5, 0x28c($sp)
/* 10A340 7F0D5810 01408025 */  move  $s0, $t2
/* 10A344 7F0D5814 100033F9 */  b     .L7F0E27FC
/* 10A348 7F0D5818 31D100FF */   andi  $s1, $t6, 0xff
spectrum_op_30:
/* 10A34C 7F0D581C 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10A350 7F0D5820 32290001 */  andi  $t1, $s1, 1
/* 10A354 7F0D5824 97AA0298 */  lhu   $t2, 0x298($sp)
/* 10A358 7F0D5828 270F0007 */  addiu $t7, $t8, 7
/* 10A35C 7F0D582C 11200005 */  beqz  $t1, .L7F0D5844
/* 10A360 7F0D5830 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10A364 7F0D5834 97AB0298 */  lhu   $t3, 0x298($sp)
/* 10A368 7F0D5838 256D0001 */  addiu $t5, $t3, 1
/* 10A36C 7F0D583C 100033EF */  b     .L7F0E27FC
/* 10A370 7F0D5840 A7AD0298 */   sh    $t5, 0x298($sp)
.L7F0D5844:
/* 10A374 7F0D5844 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10A378 7F0D5848 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10A37C 7F0D584C 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10A380 7F0D5850 01486021 */  addu  $t4, $t2, $t0
/* 10A384 7F0D5854 818E0000 */  lb    $t6, ($t4)
/* 10A388 7F0D5858 25E90005 */  addiu $t1, $t7, 5
/* 10A38C 7F0D585C AFA9028C */  sw    $t1, 0x28c($sp)
/* 10A390 7F0D5860 014EC821 */  addu  $t9, $t2, $t6
/* 10A394 7F0D5864 27380001 */  addiu $t8, $t9, 1
/* 10A398 7F0D5868 A7B80298 */  sh    $t8, 0x298($sp)
/* 10A39C 7F0D586C 100033E3 */  b     .L7F0E27FC
/* 10A3A0 7F0D5870 AFAE0228 */   sw    $t6, 0x228($sp)
spectrum_op_31:
/* 10A3A4 7F0D5874 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10A3A8 7F0D5878 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 10A3AC 7F0D587C 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 10A3B0 7F0D5880 97A80298 */  lhu   $t0, 0x298($sp)
/* 10A3B4 7F0D5884 256D000A */  addiu $t5, $t3, 0xa
/* 10A3B8 7F0D5888 AFAD028C */  sw    $t5, 0x28c($sp)
/* 10A3BC 7F0D588C 0188C821 */  addu  $t9, $t4, $t0
/* 10A3C0 7F0D5890 93380001 */  lbu   $t8, 1($t9)
/* 10A3C4 7F0D5894 010C5021 */  addu  $t2, $t0, $t4
/* 10A3C8 7F0D5898 914E0000 */  lbu   $t6, ($t2)
/* 10A3CC 7F0D589C 00187A00 */  sll   $t7, $t8, 8
/* 10A3D0 7F0D58A0 250B0002 */  addiu $t3, $t0, 2
/* 10A3D4 7F0D58A4 01CF4825 */  or    $t1, $t6, $t7
/* 10A3D8 7F0D58A8 A7A90292 */  sh    $t1, 0x292($sp)
/* 10A3DC 7F0D58AC 100033D3 */  b     .L7F0E27FC
/* 10A3E0 7F0D58B0 A7AB0298 */   sh    $t3, 0x298($sp)
spectrum_op_32:
/* 10A3E4 7F0D58B4 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10A3E8 7F0D58B8 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10A3EC 7F0D58BC 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10A3F0 7F0D58C0 97AC0298 */  lhu   $t4, 0x298($sp)
/* 10A3F4 7F0D58C4 25AA000D */  addiu $t2, $t5, 0xd
/* 10A3F8 7F0D58C8 AFAA028C */  sw    $t2, 0x28c($sp)
/* 10A3FC 7F0D58CC 032C7821 */  addu  $t7, $t9, $t4
/* 10A400 7F0D58D0 91E90001 */  lbu   $t1, 1($t7)
/* 10A404 7F0D58D4 0199C021 */  addu  $t8, $t4, $t9
/* 10A408 7F0D58D8 930E0000 */  lbu   $t6, ($t8)
/* 10A40C 7F0D58DC 00094200 */  sll   $t0, $t1, 8
/* 10A410 7F0D58E0 258D0002 */  addiu $t5, $t4, 2
/* 10A414 7F0D58E4 01C85825 */  or    $t3, $t6, $t0
/* 10A418 7F0D58E8 316AFFFF */  andi  $t2, $t3, 0xffff
/* 10A41C 7F0D58EC 29415B00 */  slti  $at, $t2, 0x5b00
/* 10A420 7F0D58F0 A7AB0226 */  sh    $t3, 0x226($sp)
/* 10A424 7F0D58F4 14200006 */  bnez  $at, .L7F0D5910
/* 10A428 7F0D58F8 A7AD0298 */   sh    $t5, 0x298($sp)
/* 10A42C 7F0D58FC 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 10A430 7F0D5900 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10A434 7F0D5904 030AC821 */  addu  $t9, $t8, $t2
/* 10A438 7F0D5908 100033BC */  b     .L7F0E27FC
/* 10A43C 7F0D590C A3300000 */   sb    $s0, ($t9)
.L7F0D5910:
/* 10A440 7F0D5910 97AF0226 */  lhu   $t7, 0x226($sp)
/* 10A444 7F0D5914 97B80226 */  lhu   $t8, 0x226($sp)
/* 10A448 7F0D5918 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10A44C 7F0D591C 29E15800 */  slti  $at, $t7, 0x5800
/* 10A450 7F0D5920 5420000C */  bnezl $at, .L7F0D5954
/* 10A454 7F0D5924 2B014000 */   slti  $at, $t8, 0x4000
/* 10A458 7F0D5928 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10A45C 7F0D592C 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 10A460 7F0D5930 24080001 */  li    $t0, 1
/* 10A464 7F0D5934 012F7021 */  addu  $t6, $t1, $t7
/* 10A468 7F0D5938 A1D00000 */  sb    $s0, ($t6)
/* 10A46C 7F0D593C 97AC0226 */  lhu   $t4, 0x226($sp)
/* 10A470 7F0D5940 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 10A474 7F0D5944 016C6821 */  addu  $t5, $t3, $t4
/* 10A478 7F0D5948 100033AC */  b     .L7F0E27FC
/* 10A47C 7F0D594C A1A8A800 */   sb    $t0, -0x5800($t5)
/* 10A480 7F0D5950 2B014000 */  slti  $at, $t8, 0x4000
.L7F0D5954:
/* 10A484 7F0D5954 142033A9 */  bnez  $at, .L7F0E27FC
/* 10A488 7F0D5958 3C0A8009 */   lui   $t2, %hi(ptr_spectrum_roms) 
/* 10A48C 7F0D595C 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 10A490 7F0D5960 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 10A494 7F0D5964 24090001 */  li    $t1, 1
/* 10A498 7F0D5968 0158C821 */  addu  $t9, $t2, $t8
/* 10A49C 7F0D596C A3300000 */  sb    $s0, ($t9)
/* 10A4A0 7F0D5970 97AF0226 */  lhu   $t7, 0x226($sp)
/* 10A4A4 7F0D5974 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 10A4A8 7F0D5978 31EE1800 */  andi  $t6, $t7, 0x1800
/* 10A4AC 7F0D597C 000E58C3 */  sra   $t3, $t6, 3
/* 10A4B0 7F0D5980 31EC00FF */  andi  $t4, $t7, 0xff
/* 10A4B4 7F0D5984 016C4025 */  or    $t0, $t3, $t4
/* 10A4B8 7F0D5988 01A85021 */  addu  $t2, $t5, $t0
/* 10A4BC 7F0D598C 1000339B */  b     .L7F0E27FC
/* 10A4C0 7F0D5990 A1490000 */   sb    $t1, ($t2)
spectrum_op_33:
/* 10A4C4 7F0D5994 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10A4C8 7F0D5998 97AE0292 */  lhu   $t6, 0x292($sp)
/* 10A4CC 7F0D599C 27190006 */  addiu $t9, $t8, 6
/* 10A4D0 7F0D59A0 25CF0001 */  addiu $t7, $t6, 1
/* 10A4D4 7F0D59A4 AFB9028C */  sw    $t9, 0x28c($sp)
/* 10A4D8 7F0D59A8 10003394 */  b     .L7F0E27FC
/* 10A4DC 7F0D59AC A7AF0292 */   sh    $t7, 0x292($sp)
spectrum_op_34:
/* 10A4E0 7F0D59B0 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10A4E4 7F0D59B4 93AD0287 */  lbu   $t5, 0x287($sp)
/* 10A4E8 7F0D59B8 00164200 */  sll   $t0, $s6, 8
/* 10A4EC 7F0D59BC 256C000B */  addiu $t4, $t3, 0xb
/* 10A4F0 7F0D59C0 15A00004 */  bnez  $t5, .L7F0D59D4
/* 10A4F4 7F0D59C4 AFAC028C */   sw    $t4, 0x28c($sp)
/* 10A4F8 7F0D59C8 01174825 */  or    $t1, $t0, $s7
/* 10A4FC 7F0D59CC 10000016 */  b     .L7F0D5A28
/* 10A500 7F0D59D0 A7A90224 */   sh    $t1, 0x224($sp)
.L7F0D59D4:
/* 10A504 7F0D59D4 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10A508 7F0D59D8 93B90287 */  lbu   $t9, 0x287($sp)
/* 10A50C 7F0D59DC 24010001 */  li    $at, 1
/* 10A510 7F0D59E0 25580008 */  addiu $t8, $t2, 8
/* 10A514 7F0D59E4 17210004 */  bne   $t9, $at, .L7F0D59F8
/* 10A518 7F0D59E8 AFB8028C */   sw    $t8, 0x28c($sp)
/* 10A51C 7F0D59EC 97AE0296 */  lhu   $t6, 0x296($sp)
/* 10A520 7F0D59F0 10000003 */  b     .L7F0D5A00
/* 10A524 7F0D59F4 AFAE0048 */   sw    $t6, 0x48($sp)
.L7F0D59F8:
/* 10A528 7F0D59F8 97AF0294 */  lhu   $t7, 0x294($sp)
/* 10A52C 7F0D59FC AFAF0048 */  sw    $t7, 0x48($sp)
.L7F0D5A00:
/* 10A530 7F0D5A00 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 10A534 7F0D5A04 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 10A538 7F0D5A08 97AB0298 */  lhu   $t3, 0x298($sp)
/* 10A53C 7F0D5A0C 8FA90048 */  lw    $t1, 0x48($sp)
/* 10A540 7F0D5A10 016C6821 */  addu  $t5, $t3, $t4
/* 10A544 7F0D5A14 81A80000 */  lb    $t0, ($t5)
/* 10A548 7F0D5A18 25780001 */  addiu $t8, $t3, 1
/* 10A54C 7F0D5A1C A7B80298 */  sh    $t8, 0x298($sp)
/* 10A550 7F0D5A20 01095021 */  addu  $t2, $t0, $t1
/* 10A554 7F0D5A24 A7AA0224 */  sh    $t2, 0x224($sp)
.L7F0D5A28:
/* 10A558 7F0D5A28 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10A55C 7F0D5A2C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10A560 7F0D5A30 97B90224 */  lhu   $t9, 0x224($sp)
/* 10A564 7F0D5A34 032E7821 */  addu  $t7, $t9, $t6
/* 10A568 7F0D5A38 91EC0000 */  lbu   $t4, ($t7)
/* 10A56C 7F0D5A3C 32390001 */  andi  $t9, $s1, 1
/* 10A570 7F0D5A40 258D0001 */  addiu $t5, $t4, 1
/* 10A574 7F0D5A44 31AF00A8 */  andi  $t7, $t5, 0xa8
/* 10A578 7F0D5A48 A3AC0223 */  sb    $t4, 0x223($sp)
/* 10A57C 7F0D5A4C 032F6025 */  or    $t4, $t9, $t7
/* 10A580 7F0D5A50 31A800FF */  andi  $t0, $t5, 0xff
/* 10A584 7F0D5A54 31AB000F */  andi  $t3, $t5, 0xf
/* 10A588 7F0D5A58 2D780001 */  sltiu $t8, $t3, 1
/* 10A58C 7F0D5A5C 2D090001 */  sltiu $t1, $t0, 1
/* 10A590 7F0D5A60 00184100 */  sll   $t0, $t8, 4
/* 10A594 7F0D5A64 31B900FF */  andi  $t9, $t5, 0xff
/* 10A598 7F0D5A68 3B2F0080 */  xori  $t7, $t9, 0x80
/* 10A59C 7F0D5A6C 01885025 */  or    $t2, $t4, $t0
/* 10A5A0 7F0D5A70 97A80224 */  lhu   $t0, 0x224($sp)
/* 10A5A4 7F0D5A74 2DEF0001 */  sltiu $t7, $t7, 1
/* 10A5A8 7F0D5A78 00095980 */  sll   $t3, $t1, 6
/* 10A5AC 7F0D5A7C AFB80048 */  sw    $t8, 0x48($sp)
/* 10A5B0 7F0D5A80 000FC080 */  sll   $t8, $t7, 2
/* 10A5B4 7F0D5A84 014B7025 */  or    $t6, $t2, $t3
/* 10A5B8 7F0D5A88 01D88825 */  or    $s1, $t6, $t8
/* 10A5BC 7F0D5A8C 322C00FF */  andi  $t4, $s1, 0xff
/* 10A5C0 7F0D5A90 29015B00 */  slti  $at, $t0, 0x5b00
/* 10A5C4 7F0D5A94 01808825 */  move  $s1, $t4
/* 10A5C8 7F0D5A98 AFA90044 */  sw    $t1, 0x44($sp)
/* 10A5CC 7F0D5A9C 14200006 */  bnez  $at, .L7F0D5AB8
/* 10A5D0 7F0D5AA0 A3AD0223 */   sb    $t5, 0x223($sp)
/* 10A5D4 7F0D5AA4 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 10A5D8 7F0D5AA8 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 10A5DC 7F0D5AAC 01485821 */  addu  $t3, $t2, $t0
/* 10A5E0 7F0D5AB0 10003352 */  b     .L7F0E27FC
/* 10A5E4 7F0D5AB4 A16D0000 */   sb    $t5, ($t3)
.L7F0D5AB8:
/* 10A5E8 7F0D5AB8 97AD0224 */  lhu   $t5, 0x224($sp)
/* 10A5EC 7F0D5ABC 97A90224 */  lhu   $t1, 0x224($sp)
/* 10A5F0 7F0D5AC0 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 10A5F4 7F0D5AC4 29A15800 */  slti  $at, $t5, 0x5800
/* 10A5F8 7F0D5AC8 5420000D */  bnezl $at, .L7F0D5B00
/* 10A5FC 7F0D5ACC 29214000 */   slti  $at, $t1, 0x4000
/* 10A600 7F0D5AD0 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10A604 7F0D5AD4 93B90223 */  lbu   $t9, 0x223($sp)
/* 10A608 7F0D5AD8 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 10A60C 7F0D5ADC 01ED7021 */  addu  $t6, $t7, $t5
/* 10A610 7F0D5AE0 A1D90000 */  sb    $t9, ($t6)
/* 10A614 7F0D5AE4 97AA0224 */  lhu   $t2, 0x224($sp)
/* 10A618 7F0D5AE8 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 10A61C 7F0D5AEC 24180001 */  li    $t8, 1
/* 10A620 7F0D5AF0 018A4021 */  addu  $t0, $t4, $t2
/* 10A624 7F0D5AF4 10003341 */  b     .L7F0E27FC
/* 10A628 7F0D5AF8 A118A800 */   sb    $t8, -0x5800($t0)
/* 10A62C 7F0D5AFC 29214000 */  slti  $at, $t1, 0x4000
.L7F0D5B00:
/* 10A630 7F0D5B00 1420333E */  bnez  $at, .L7F0E27FC
/* 10A634 7F0D5B04 3C0F8009 */   lui   $t7, %hi(ptr_spectrum_roms) 
/* 10A638 7F0D5B08 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10A63C 7F0D5B0C 93AB0223 */  lbu   $t3, 0x223($sp)
/* 10A640 7F0D5B10 24190001 */  li    $t9, 1
/* 10A644 7F0D5B14 01E96821 */  addu  $t5, $t7, $t1
/* 10A648 7F0D5B18 A1AB0000 */  sb    $t3, ($t5)
/* 10A64C 7F0D5B1C 97AE0224 */  lhu   $t6, 0x224($sp)
/* 10A650 7F0D5B20 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 10A654 7F0D5B24 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 10A658 7F0D5B28 31CC1800 */  andi  $t4, $t6, 0x1800
/* 10A65C 7F0D5B2C 000C50C3 */  sra   $t2, $t4, 3
/* 10A660 7F0D5B30 31D800FF */  andi  $t8, $t6, 0xff
/* 10A664 7F0D5B34 01584025 */  or    $t0, $t2, $t8
/* 10A668 7F0D5B38 01E84821 */  addu  $t1, $t7, $t0
/* 10A66C 7F0D5B3C 1000332F */  b     .L7F0E27FC
/* 10A670 7F0D5B40 A1390000 */   sb    $t9, ($t1)
spectrum_op_35:
/* 10A674 7F0D5B44 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10A678 7F0D5B48 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10A67C 7F0D5B4C 00167200 */  sll   $t6, $s6, 8
/* 10A680 7F0D5B50 256D000B */  addiu $t5, $t3, 0xb
/* 10A684 7F0D5B54 15800004 */  bnez  $t4, .L7F0D5B68
/* 10A688 7F0D5B58 AFAD028C */   sw    $t5, 0x28c($sp)
/* 10A68C 7F0D5B5C 01D75025 */  or    $t2, $t6, $s7
/* 10A690 7F0D5B60 10000016 */  b     .L7F0D5BBC
/* 10A694 7F0D5B64 A7AA0220 */   sh    $t2, 0x220($sp)
.L7F0D5B68:
/* 10A698 7F0D5B68 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10A69C 7F0D5B6C 93A80287 */  lbu   $t0, 0x287($sp)
/* 10A6A0 7F0D5B70 24010001 */  li    $at, 1
/* 10A6A4 7F0D5B74 270F0008 */  addiu $t7, $t8, 8
/* 10A6A8 7F0D5B78 15010004 */  bne   $t0, $at, .L7F0D5B8C
/* 10A6AC 7F0D5B7C AFAF028C */   sw    $t7, 0x28c($sp)
/* 10A6B0 7F0D5B80 97B90296 */  lhu   $t9, 0x296($sp)
/* 10A6B4 7F0D5B84 10000003 */  b     .L7F0D5B94
/* 10A6B8 7F0D5B88 AFB90048 */   sw    $t9, 0x48($sp)
.L7F0D5B8C:
/* 10A6BC 7F0D5B8C 97A90294 */  lhu   $t1, 0x294($sp)
/* 10A6C0 7F0D5B90 AFA90048 */  sw    $t1, 0x48($sp)
.L7F0D5B94:
/* 10A6C4 7F0D5B94 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 10A6C8 7F0D5B98 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10A6CC 7F0D5B9C 97AB0298 */  lhu   $t3, 0x298($sp)
/* 10A6D0 7F0D5BA0 8FAA0048 */  lw    $t2, 0x48($sp)
/* 10A6D4 7F0D5BA4 016D6021 */  addu  $t4, $t3, $t5
/* 10A6D8 7F0D5BA8 818E0000 */  lb    $t6, ($t4)
/* 10A6DC 7F0D5BAC 256F0001 */  addiu $t7, $t3, 1
/* 10A6E0 7F0D5BB0 A7AF0298 */  sh    $t7, 0x298($sp)
/* 10A6E4 7F0D5BB4 01CAC021 */  addu  $t8, $t6, $t2
/* 10A6E8 7F0D5BB8 A7B80220 */  sh    $t8, 0x220($sp)
.L7F0D5BBC:
/* 10A6EC 7F0D5BBC 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10A6F0 7F0D5BC0 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10A6F4 7F0D5BC4 97A80220 */  lhu   $t0, 0x220($sp)
/* 10A6F8 7F0D5BC8 32380001 */  andi  $t8, $s1, 1
/* 10A6FC 7F0D5BCC 01194821 */  addu  $t1, $t0, $t9
/* 10A700 7F0D5BD0 912D0000 */  lbu   $t5, ($t1)
/* 10A704 7F0D5BD4 31AC000F */  andi  $t4, $t5, 0xf
/* 10A708 7F0D5BD8 2D8E0001 */  sltiu $t6, $t4, 1
/* 10A70C 7F0D5BDC 000E5100 */  sll   $t2, $t6, 4
/* 10A710 7F0D5BE0 030A8825 */  or    $s1, $t8, $t2
/* 10A714 7F0D5BE4 25A8FFFF */  addiu $t0, $t5, -1
/* 10A718 7F0D5BE8 311800FF */  andi  $t8, $t0, 0xff
/* 10A71C 7F0D5BEC 3B0A007F */  xori  $t2, $t8, 0x7f
/* 10A720 7F0D5BF0 362B0002 */  ori   $t3, $s1, 2
/* 10A724 7F0D5BF4 AFAE0048 */  sw    $t6, 0x48($sp)
/* 10A728 7F0D5BF8 310E00A8 */  andi  $t6, $t0, 0xa8
/* 10A72C 7F0D5BFC 01608825 */  move  $s1, $t3
/* 10A730 7F0D5C00 2D4A0001 */  sltiu $t2, $t2, 1
/* 10A734 7F0D5C04 311900FF */  andi  $t9, $t0, 0xff
/* 10A738 7F0D5C08 A3AD021F */  sb    $t5, 0x21f($sp)
/* 10A73C 7F0D5C0C A3A8021F */  sb    $t0, 0x21f($sp)
/* 10A740 7F0D5C10 2F290001 */  sltiu $t1, $t9, 1
/* 10A744 7F0D5C14 000A5880 */  sll   $t3, $t2, 2
/* 10A748 7F0D5C18 97A80220 */  lhu   $t0, 0x220($sp)
/* 10A74C 7F0D5C1C 01CB7825 */  or    $t7, $t6, $t3
/* 10A750 7F0D5C20 00096980 */  sll   $t5, $t1, 6
/* 10A754 7F0D5C24 01EDC825 */  or    $t9, $t7, $t5
/* 10A758 7F0D5C28 02398825 */  or    $s1, $s1, $t9
/* 10A75C 7F0D5C2C 322C00FF */  andi  $t4, $s1, 0xff
/* 10A760 7F0D5C30 29015B00 */  slti  $at, $t0, 0x5b00
/* 10A764 7F0D5C34 01808825 */  move  $s1, $t4
/* 10A768 7F0D5C38 14200007 */  bnez  $at, .L7F0D5C58
/* 10A76C 7F0D5C3C AFA90044 */   sw    $t1, 0x44($sp)
/* 10A770 7F0D5C40 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 10A774 7F0D5C44 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 10A778 7F0D5C48 93B8021F */  lbu   $t8, 0x21f($sp)
/* 10A77C 7F0D5C4C 01487021 */  addu  $t6, $t2, $t0
/* 10A780 7F0D5C50 100032EA */  b     .L7F0E27FC
/* 10A784 7F0D5C54 A1D80000 */   sb    $t8, ($t6)
.L7F0D5C58:
/* 10A788 7F0D5C58 97AB0220 */  lhu   $t3, 0x220($sp)
/* 10A78C 7F0D5C5C 97B80220 */  lhu   $t8, 0x220($sp)
/* 10A790 7F0D5C60 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 10A794 7F0D5C64 29615800 */  slti  $at, $t3, 0x5800
/* 10A798 7F0D5C68 5420000D */  bnezl $at, .L7F0D5CA0
/* 10A79C 7F0D5C6C 2B014000 */   slti  $at, $t8, 0x4000
/* 10A7A0 7F0D5C70 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10A7A4 7F0D5C74 93A9021F */  lbu   $t1, 0x21f($sp)
/* 10A7A8 7F0D5C78 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 10A7AC 7F0D5C7C 01EB6821 */  addu  $t5, $t7, $t3
/* 10A7B0 7F0D5C80 A1A90000 */  sb    $t1, ($t5)
/* 10A7B4 7F0D5C84 97AA0220 */  lhu   $t2, 0x220($sp)
/* 10A7B8 7F0D5C88 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 10A7BC 7F0D5C8C 24190001 */  li    $t9, 1
/* 10A7C0 7F0D5C90 018A4021 */  addu  $t0, $t4, $t2
/* 10A7C4 7F0D5C94 100032D9 */  b     .L7F0E27FC
/* 10A7C8 7F0D5C98 A119A800 */   sb    $t9, -0x5800($t0)
/* 10A7CC 7F0D5C9C 2B014000 */  slti  $at, $t8, 0x4000
.L7F0D5CA0:
/* 10A7D0 7F0D5CA0 142032D6 */  bnez  $at, .L7F0E27FC
/* 10A7D4 7F0D5CA4 3C0F8009 */   lui   $t7, %hi(ptr_spectrum_roms) 
/* 10A7D8 7F0D5CA8 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10A7DC 7F0D5CAC 93AE021F */  lbu   $t6, 0x21f($sp)
/* 10A7E0 7F0D5CB0 24090001 */  li    $t1, 1
/* 10A7E4 7F0D5CB4 01F85821 */  addu  $t3, $t7, $t8
/* 10A7E8 7F0D5CB8 A16E0000 */  sb    $t6, ($t3)
/* 10A7EC 7F0D5CBC 97AD0220 */  lhu   $t5, 0x220($sp)
/* 10A7F0 7F0D5CC0 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 10A7F4 7F0D5CC4 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 10A7F8 7F0D5CC8 31AC1800 */  andi  $t4, $t5, 0x1800
/* 10A7FC 7F0D5CCC 000C50C3 */  sra   $t2, $t4, 3
/* 10A800 7F0D5CD0 31B900FF */  andi  $t9, $t5, 0xff
/* 10A804 7F0D5CD4 01594025 */  or    $t0, $t2, $t9
/* 10A808 7F0D5CD8 01E8C021 */  addu  $t8, $t7, $t0
/* 10A80C 7F0D5CDC 100032C7 */  b     .L7F0E27FC
/* 10A810 7F0D5CE0 A3090000 */   sb    $t1, ($t8)
spectrum_op_36:
/* 10A814 7F0D5CE4 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10A818 7F0D5CE8 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10A81C 7F0D5CEC 00166A00 */  sll   $t5, $s6, 8
/* 10A820 7F0D5CF0 25CB000A */  addiu $t3, $t6, 0xa
/* 10A824 7F0D5CF4 15800004 */  bnez  $t4, .L7F0D5D08
/* 10A828 7F0D5CF8 AFAB028C */   sw    $t3, 0x28c($sp)
/* 10A82C 7F0D5CFC 01B75025 */  or    $t2, $t5, $s7
/* 10A830 7F0D5D00 10000016 */  b     .L7F0D5D5C
/* 10A834 7F0D5D04 A7AA021C */   sh    $t2, 0x21c($sp)
.L7F0D5D08:
/* 10A838 7F0D5D08 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10A83C 7F0D5D0C 93A80287 */  lbu   $t0, 0x287($sp)
/* 10A840 7F0D5D10 24010001 */  li    $at, 1
/* 10A844 7F0D5D14 272F0005 */  addiu $t7, $t9, 5
/* 10A848 7F0D5D18 15010004 */  bne   $t0, $at, .L7F0D5D2C
/* 10A84C 7F0D5D1C AFAF028C */   sw    $t7, 0x28c($sp)
/* 10A850 7F0D5D20 97A90296 */  lhu   $t1, 0x296($sp)
/* 10A854 7F0D5D24 10000003 */  b     .L7F0D5D34
/* 10A858 7F0D5D28 AFA90048 */   sw    $t1, 0x48($sp)
.L7F0D5D2C:
/* 10A85C 7F0D5D2C 97B80294 */  lhu   $t8, 0x294($sp)
/* 10A860 7F0D5D30 AFB80048 */  sw    $t8, 0x48($sp)
.L7F0D5D34:
/* 10A864 7F0D5D34 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 10A868 7F0D5D38 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10A86C 7F0D5D3C 97AE0298 */  lhu   $t6, 0x298($sp)
/* 10A870 7F0D5D40 8FAA0048 */  lw    $t2, 0x48($sp)
/* 10A874 7F0D5D44 01CB6021 */  addu  $t4, $t6, $t3
/* 10A878 7F0D5D48 818D0000 */  lb    $t5, ($t4)
/* 10A87C 7F0D5D4C 25CF0001 */  addiu $t7, $t6, 1
/* 10A880 7F0D5D50 A7AF0298 */  sh    $t7, 0x298($sp)
/* 10A884 7F0D5D54 01AAC821 */  addu  $t9, $t5, $t2
/* 10A888 7F0D5D58 A7B9021C */  sh    $t9, 0x21c($sp)
.L7F0D5D5C:
/* 10A88C 7F0D5D5C 97A8021C */  lhu   $t0, 0x21c($sp)
/* 10A890 7F0D5D60 97AA021C */  lhu   $t2, 0x21c($sp)
/* 10A894 7F0D5D64 97A90298 */  lhu   $t1, 0x298($sp)
/* 10A898 7F0D5D68 29015B00 */  slti  $at, $t0, 0x5b00
/* 10A89C 7F0D5D6C 14200007 */  bnez  $at, .L7F0D5D8C
/* 10A8A0 7F0D5D70 3C188009 */   lui   $t8, %hi(ptr_spectrum_roms) 
/* 10A8A4 7F0D5D74 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10A8A8 7F0D5D78 01385821 */  addu  $t3, $t1, $t8
/* 10A8AC 7F0D5D7C 916C0000 */  lbu   $t4, ($t3)
/* 10A8B0 7F0D5D80 03086821 */  addu  $t5, $t8, $t0
/* 10A8B4 7F0D5D84 10000025 */  b     .L7F0D5E1C
/* 10A8B8 7F0D5D88 A1AC0000 */   sb    $t4, ($t5)
.L7F0D5D8C:
/* 10A8BC 7F0D5D8C 29415800 */  slti  $at, $t2, 0x5800
/* 10A8C0 7F0D5D90 1420000F */  bnez  $at, .L7F0D5DD0
/* 10A8C4 7F0D5D94 97B9021C */   lhu   $t9, 0x21c($sp)
/* 10A8C8 7F0D5D98 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10A8CC 7F0D5D9C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10A8D0 7F0D5DA0 97B90298 */  lhu   $t9, 0x298($sp)
/* 10A8D4 7F0D5DA4 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 10A8D8 7F0D5DA8 01CA5821 */  addu  $t3, $t6, $t2
/* 10A8DC 7F0D5DAC 032E7821 */  addu  $t7, $t9, $t6
/* 10A8E0 7F0D5DB0 91E90000 */  lbu   $t1, ($t7)
/* 10A8E4 7F0D5DB4 24180001 */  li    $t8, 1
/* 10A8E8 7F0D5DB8 A1690000 */  sb    $t1, ($t3)
/* 10A8EC 7F0D5DBC 97AC021C */  lhu   $t4, 0x21c($sp)
/* 10A8F0 7F0D5DC0 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 10A8F4 7F0D5DC4 010C6821 */  addu  $t5, $t0, $t4
/* 10A8F8 7F0D5DC8 10000014 */  b     .L7F0D5E1C
/* 10A8FC 7F0D5DCC A1B8A800 */   sb    $t8, -0x5800($t5)
.L7F0D5DD0:
/* 10A900 7F0D5DD0 2B214000 */  slti  $at, $t9, 0x4000
/* 10A904 7F0D5DD4 14200011 */  bnez  $at, .L7F0D5E1C
/* 10A908 7F0D5DD8 97AF0298 */   lhu   $t7, 0x298($sp)
/* 10A90C 7F0D5DDC 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10A910 7F0D5DE0 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10A914 7F0D5DE4 24080001 */  li    $t0, 1
/* 10A918 7F0D5DE8 01EE5021 */  addu  $t2, $t7, $t6
/* 10A91C 7F0D5DEC 91490000 */  lbu   $t1, ($t2)
/* 10A920 7F0D5DF0 01D95821 */  addu  $t3, $t6, $t9
/* 10A924 7F0D5DF4 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 10A928 7F0D5DF8 A1690000 */  sb    $t1, ($t3)
/* 10A92C 7F0D5DFC 97AC021C */  lhu   $t4, 0x21c($sp)
/* 10A930 7F0D5E00 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 10A934 7F0D5E04 31981800 */  andi  $t8, $t4, 0x1800
/* 10A938 7F0D5E08 001868C3 */  sra   $t5, $t8, 3
/* 10A93C 7F0D5E0C 318F00FF */  andi  $t7, $t4, 0xff
/* 10A940 7F0D5E10 01AF5025 */  or    $t2, $t5, $t7
/* 10A944 7F0D5E14 01CAC821 */  addu  $t9, $t6, $t2
/* 10A948 7F0D5E18 A3280000 */  sb    $t0, ($t9)
.L7F0D5E1C:
/* 10A94C 7F0D5E1C 97A90298 */  lhu   $t1, 0x298($sp)
/* 10A950 7F0D5E20 252B0001 */  addiu $t3, $t1, 1
/* 10A954 7F0D5E24 10003275 */  b     .L7F0E27FC
/* 10A958 7F0D5E28 A7AB0298 */   sh    $t3, 0x298($sp)
spectrum_op_37:
/* 10A95C 7F0D5E2C 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10A960 7F0D5E30 322D00C4 */  andi  $t5, $s1, 0xc4
/* 10A964 7F0D5E34 35AF0001 */  ori   $t7, $t5, 1
/* 10A968 7F0D5E38 320E0028 */  andi  $t6, $s0, 0x28
/* 10A96C 7F0D5E3C 01EE8825 */  or    $s1, $t7, $t6
/* 10A970 7F0D5E40 322A00FF */  andi  $t2, $s1, 0xff
/* 10A974 7F0D5E44 270C0004 */  addiu $t4, $t8, 4
/* 10A978 7F0D5E48 AFAC028C */  sw    $t4, 0x28c($sp)
/* 10A97C 7F0D5E4C 1000326B */  b     .L7F0E27FC
/* 10A980 7F0D5E50 01408825 */   move  $s1, $t2
spectrum_op_38:
/* 10A984 7F0D5E54 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10A988 7F0D5E58 32290001 */  andi  $t1, $s1, 1
/* 10A98C 7F0D5E5C 97AB0298 */  lhu   $t3, 0x298($sp)
/* 10A990 7F0D5E60 25190007 */  addiu $t9, $t0, 7
/* 10A994 7F0D5E64 1120000C */  beqz  $t1, .L7F0D5E98
/* 10A998 7F0D5E68 AFB9028C */   sw    $t9, 0x28c($sp)
/* 10A99C 7F0D5E6C 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 10A9A0 7F0D5E70 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10A9A4 7F0D5E74 27280005 */  addiu $t0, $t9, 5
/* 10A9A8 7F0D5E78 01786021 */  addu  $t4, $t3, $t8
/* 10A9AC 7F0D5E7C 818D0000 */  lb    $t5, ($t4)
/* 10A9B0 7F0D5E80 AFA8028C */  sw    $t0, 0x28c($sp)
/* 10A9B4 7F0D5E84 016D7821 */  addu  $t7, $t3, $t5
/* 10A9B8 7F0D5E88 25EE0001 */  addiu $t6, $t7, 1
/* 10A9BC 7F0D5E8C A7AE0298 */  sh    $t6, 0x298($sp)
/* 10A9C0 7F0D5E90 1000325A */  b     .L7F0E27FC
/* 10A9C4 7F0D5E94 AFAD0218 */   sw    $t5, 0x218($sp)
.L7F0D5E98:
/* 10A9C8 7F0D5E98 97B90298 */  lhu   $t9, 0x298($sp)
/* 10A9CC 7F0D5E9C 27290001 */  addiu $t1, $t9, 1
/* 10A9D0 7F0D5EA0 10003256 */  b     .L7F0E27FC
/* 10A9D4 7F0D5EA4 A7A90298 */   sh    $t1, 0x298($sp)
spectrum_op_39:
/* 10A9D8 7F0D5EA8 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10A9DC 7F0D5EAC 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10A9E0 7F0D5EB0 97AD0292 */  lhu   $t5, 0x292($sp)
/* 10A9E4 7F0D5EB4 270C000B */  addiu $t4, $t8, 0xb
/* 10A9E8 7F0D5EB8 1560001E */  bnez  $t3, .L7F0D5F34
/* 10A9EC 7F0D5EBC AFAC028C */   sw    $t4, 0x28c($sp)
/* 10A9F0 7F0D5EC0 31AF00FF */  andi  $t7, $t5, 0xff
/* 10A9F4 7F0D5EC4 02EF7021 */  addu  $t6, $s7, $t7
/* 10A9F8 7F0D5EC8 31CAFFFF */  andi  $t2, $t6, 0xffff
/* 10A9FC 7F0D5ECC 000A4202 */  srl   $t0, $t2, 8
/* 10AA00 7F0D5ED0 3109FFFF */  andi  $t1, $t0, 0xffff
/* 10AA04 7F0D5ED4 32D9000F */  andi  $t9, $s6, 0xf
/* 10AA08 7F0D5ED8 000D6203 */  sra   $t4, $t5, 8
/* 10AA0C 7F0D5EDC 318B000F */  andi  $t3, $t4, 0xf
/* 10AA10 7F0D5EE0 0139C021 */  addu  $t8, $t1, $t9
/* 10AA14 7F0D5EE4 030B7821 */  addu  $t7, $t8, $t3
/* 10AA18 7F0D5EE8 A7AE0216 */  sh    $t6, 0x216($sp)
/* 10AA1C 7F0D5EEC 2401000F */  li    $at, 15
/* 10AA20 7F0D5EF0 002F702A */  slt   $t6, $at, $t7
/* 10AA24 7F0D5EF4 000E5100 */  sll   $t2, $t6, 4
/* 10AA28 7F0D5EF8 93B70217 */  lbu   $s7, 0x217($sp)
/* 10AA2C 7F0D5EFC 02CC6821 */  addu  $t5, $s6, $t4
/* 10AA30 7F0D5F00 010D7021 */  addu  $t6, $t0, $t5
/* 10AA34 7F0D5F04 A7A80216 */  sh    $t0, 0x216($sp)
/* 10AA38 7F0D5F08 A7AE0216 */  sh    $t6, 0x216($sp)
/* 10AA3C 7F0D5F0C 93B60217 */  lbu   $s6, 0x217($sp)
/* 10AA40 7F0D5F10 322900C4 */  andi  $t1, $s1, 0xc4
/* 10AA44 7F0D5F14 0149C825 */  or    $t9, $t2, $t1
/* 10AA48 7F0D5F18 000E5203 */  sra   $t2, $t6, 8
/* 10AA4C 7F0D5F1C 32CF0028 */  andi  $t7, $s6, 0x28
/* 10AA50 7F0D5F20 01EA4825 */  or    $t1, $t7, $t2
/* 10AA54 7F0D5F24 03298825 */  or    $s1, $t9, $t1
/* 10AA58 7F0D5F28 323900FF */  andi  $t9, $s1, 0xff
/* 10AA5C 7F0D5F2C 10003233 */  b     .L7F0E27FC
/* 10AA60 7F0D5F30 03208825 */   move  $s1, $t9
.L7F0D5F34:
/* 10AA64 7F0D5F34 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10AA68 7F0D5F38 24010001 */  li    $at, 1
/* 10AA6C 7F0D5F3C 97B80294 */  lhu   $t8, 0x294($sp)
/* 10AA70 7F0D5F40 15810003 */  bne   $t4, $at, .L7F0D5F50
/* 10AA74 7F0D5F44 97A80296 */   lhu   $t0, 0x296($sp)
/* 10AA78 7F0D5F48 10000002 */  b     .L7F0D5F54
/* 10AA7C 7F0D5F4C AFA80210 */   sw    $t0, 0x210($sp)
.L7F0D5F50:
/* 10AA80 7F0D5F50 AFB80210 */  sw    $t8, 0x210($sp)
.L7F0D5F54:
/* 10AA84 7F0D5F54 97AD0292 */  lhu   $t5, 0x292($sp)
/* 10AA88 7F0D5F58 8FA90210 */  lw    $t1, 0x210($sp)
/* 10AA8C 7F0D5F5C 24010FFF */  li    $at, 4095
/* 10AA90 7F0D5F60 000D5A03 */  sra   $t3, $t5, 8
/* 10AA94 7F0D5F64 000B7200 */  sll   $t6, $t3, 8
/* 10AA98 7F0D5F68 31AF00FF */  andi  $t7, $t5, 0xff
/* 10AA9C 7F0D5F6C 01CF5025 */  or    $t2, $t6, $t7
/* 10AAA0 7F0D5F70 31390FFF */  andi  $t9, $t1, 0xfff
/* 10AAA4 7F0D5F74 032A6021 */  addu  $t4, $t9, $t2
/* 10AAA8 7F0D5F78 002C402B */  sltu  $t0, $at, $t4
/* 10AAAC 7F0D5F7C 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10AAB0 7F0D5F80 0008C100 */  sll   $t8, $t0, 4
/* 10AAB4 7F0D5F84 322B00C4 */  andi  $t3, $s1, 0xc4
/* 10AAB8 7F0D5F88 01788825 */  or    $s1, $t3, $t8
/* 10AABC 7F0D5F8C 322D00FF */  andi  $t5, $s1, 0xff
/* 10AAC0 7F0D5F90 24010001 */  li    $at, 1
/* 10AAC4 7F0D5F94 012A7021 */  addu  $t6, $t1, $t2
/* 10AAC8 7F0D5F98 AFAE0210 */  sw    $t6, 0x210($sp)
/* 10AACC 7F0D5F9C 15E10003 */  bne   $t7, $at, .L7F0D5FAC
/* 10AAD0 7F0D5FA0 01A08825 */   move  $s1, $t5
/* 10AAD4 7F0D5FA4 10000003 */  b     .L7F0D5FB4
/* 10AAD8 7F0D5FA8 A7AE0296 */   sh    $t6, 0x296($sp)
.L7F0D5FAC:
/* 10AADC 7F0D5FAC 8FB90210 */  lw    $t9, 0x210($sp)
/* 10AAE0 7F0D5FB0 A7B90294 */  sh    $t9, 0x294($sp)
.L7F0D5FB4:
/* 10AAE4 7F0D5FB4 8FAC0210 */  lw    $t4, 0x210($sp)
/* 10AAE8 7F0D5FB8 000C4202 */  srl   $t0, $t4, 8
/* 10AAEC 7F0D5FBC 310B0028 */  andi  $t3, $t0, 0x28
/* 10AAF0 7F0D5FC0 000CC402 */  srl   $t8, $t4, 0x10
/* 10AAF4 7F0D5FC4 01786825 */  or    $t5, $t3, $t8
/* 10AAF8 7F0D5FC8 022D8825 */  or    $s1, $s1, $t5
/* 10AAFC 7F0D5FCC 322900FF */  andi  $t1, $s1, 0xff
/* 10AB00 7F0D5FD0 1000320A */  b     .L7F0E27FC
/* 10AB04 7F0D5FD4 01208825 */   move  $s1, $t1
spectrum_op_3A:
/* 10AB08 7F0D5FD8 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10AB0C 7F0D5FDC 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10AB10 7F0D5FE0 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10AB14 7F0D5FE4 97AE0298 */  lhu   $t6, 0x298($sp)
/* 10AB18 7F0D5FE8 254F000D */  addiu $t7, $t2, 0xd
/* 10AB1C 7F0D5FEC AFAF028C */  sw    $t7, 0x28c($sp)
/* 10AB20 7F0D5FF0 032E5821 */  addu  $t3, $t9, $t6
/* 10AB24 7F0D5FF4 91780001 */  lbu   $t8, 1($t3)
/* 10AB28 7F0D5FF8 01D94021 */  addu  $t0, $t6, $t9
/* 10AB2C 7F0D5FFC 910C0000 */  lbu   $t4, ($t0)
/* 10AB30 7F0D6000 00186A00 */  sll   $t5, $t8, 8
/* 10AB34 7F0D6004 25CA0002 */  addiu $t2, $t6, 2
/* 10AB38 7F0D6008 018D4825 */  or    $t1, $t4, $t5
/* 10AB3C 7F0D600C 312FFFFF */  andi  $t7, $t1, 0xffff
/* 10AB40 7F0D6010 A7A9020E */  sh    $t1, 0x20e($sp)
/* 10AB44 7F0D6014 A7AA0298 */  sh    $t2, 0x298($sp)
/* 10AB48 7F0D6018 01F94021 */  addu  $t0, $t7, $t9
/* 10AB4C 7F0D601C 100031F7 */  b     .L7F0E27FC
/* 10AB50 7F0D6020 91100000 */   lbu   $s0, ($t0)
spectrum_op_3B:
/* 10AB54 7F0D6024 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10AB58 7F0D6028 97AC0292 */  lhu   $t4, 0x292($sp)
/* 10AB5C 7F0D602C 25780006 */  addiu $t8, $t3, 6
/* 10AB60 7F0D6030 258DFFFF */  addiu $t5, $t4, -1
/* 10AB64 7F0D6034 AFB8028C */  sw    $t8, 0x28c($sp)
/* 10AB68 7F0D6038 100031F0 */  b     .L7F0E27FC
/* 10AB6C 7F0D603C A7AD0292 */   sh    $t5, 0x292($sp)
spectrum_op_3C:
/* 10AB70 7F0D6040 26100001 */  addiu $s0, $s0, 1
/* 10AB74 7F0D6044 320A00FF */  andi  $t2, $s0, 0xff
/* 10AB78 7F0D6048 8FA9028C */  lw    $t1, 0x28c($sp)
/* 10AB7C 7F0D604C 3159000F */  andi  $t9, $t2, 0xf
/* 10AB80 7F0D6050 2F280001 */  sltiu $t0, $t9, 1
/* 10AB84 7F0D6054 01408025 */  move  $s0, $t2
/* 10AB88 7F0D6058 2D4F0001 */  sltiu $t7, $t2, 1
/* 10AB8C 7F0D605C 315800A8 */  andi  $t8, $t2, 0xa8
/* 10AB90 7F0D6060 322B0001 */  andi  $t3, $s1, 1
/* 10AB94 7F0D6064 01786025 */  or    $t4, $t3, $t8
/* 10AB98 7F0D6068 3A190080 */  xori  $t9, $s0, 0x80
/* 10AB9C 7F0D606C 00086900 */  sll   $t5, $t0, 4
/* 10ABA0 7F0D6070 252E0004 */  addiu $t6, $t1, 4
/* 10ABA4 7F0D6074 018D4825 */  or    $t1, $t4, $t5
/* 10ABA8 7F0D6078 2F390001 */  sltiu $t9, $t9, 1
/* 10ABAC 7F0D607C 000F5180 */  sll   $t2, $t7, 6
/* 10ABB0 7F0D6080 AFAF0044 */  sw    $t7, 0x44($sp)
/* 10ABB4 7F0D6084 012A7825 */  or    $t7, $t1, $t2
/* 10ABB8 7F0D6088 00195880 */  sll   $t3, $t9, 2
/* 10ABBC 7F0D608C 01EB8825 */  or    $s1, $t7, $t3
/* 10ABC0 7F0D6090 323800FF */  andi  $t8, $s1, 0xff
/* 10ABC4 7F0D6094 AFAE028C */  sw    $t6, 0x28c($sp)
/* 10ABC8 7F0D6098 03008825 */  move  $s1, $t8
/* 10ABCC 7F0D609C 100031D7 */  b     .L7F0E27FC
/* 10ABD0 7F0D60A0 AFA80048 */   sw    $t0, 0x48($sp)
spectrum_op_3D:
/* 10ABD4 7F0D60A4 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10ABD8 7F0D60A8 320D000F */  andi  $t5, $s0, 0xf
/* 10ABDC 7F0D60AC 2610FFFF */  addiu $s0, $s0, -1
/* 10ABE0 7F0D60B0 250C0004 */  addiu $t4, $t0, 4
/* 10ABE4 7F0D60B4 AFAC028C */  sw    $t4, 0x28c($sp)
/* 10ABE8 7F0D60B8 320B00FF */  andi  $t3, $s0, 0xff
/* 10ABEC 7F0D60BC 2DAE0001 */  sltiu $t6, $t5, 1
/* 10ABF0 7F0D60C0 000E5100 */  sll   $t2, $t6, 4
/* 10ABF4 7F0D60C4 396C007F */  xori  $t4, $t3, 0x7f
/* 10ABF8 7F0D60C8 2D8C0001 */  sltiu $t4, $t4, 1
/* 10ABFC 7F0D60CC 32290001 */  andi  $t1, $s1, 1
/* 10AC00 7F0D60D0 012A8825 */  or    $s1, $t1, $t2
/* 10AC04 7F0D60D4 000C6880 */  sll   $t5, $t4, 2
/* 10AC08 7F0D60D8 AFAE0048 */  sw    $t6, 0x48($sp)
/* 10AC0C 7F0D60DC 2D780001 */  sltiu $t8, $t3, 1
/* 10AC10 7F0D60E0 316800A8 */  andi  $t0, $t3, 0xa8
/* 10AC14 7F0D60E4 010D7025 */  or    $t6, $t0, $t5
/* 10AC18 7F0D60E8 00185180 */  sll   $t2, $t8, 6
/* 10AC1C 7F0D60EC 01CAC825 */  or    $t9, $t6, $t2
/* 10AC20 7F0D60F0 362F0002 */  ori   $t7, $s1, 2
/* 10AC24 7F0D60F4 01F98825 */  or    $s1, $t7, $t9
/* 10AC28 7F0D60F8 322F00FF */  andi  $t7, $s1, 0xff
/* 10AC2C 7F0D60FC 01E08825 */  move  $s1, $t7
/* 10AC30 7F0D6100 AFB80044 */  sw    $t8, 0x44($sp)
/* 10AC34 7F0D6104 100031BD */  b     .L7F0E27FC
/* 10AC38 7F0D6108 01608025 */   move  $s0, $t3
spectrum_op_3E:
/* 10AC3C 7F0D610C 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10AC40 7F0D6110 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10AC44 7F0D6114 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10AC48 7F0D6118 97AC0298 */  lhu   $t4, 0x298($sp)
/* 10AC4C 7F0D611C 25780007 */  addiu $t8, $t3, 7
/* 10AC50 7F0D6120 AFB8028C */  sw    $t8, 0x28c($sp)
/* 10AC54 7F0D6124 01886821 */  addu  $t5, $t4, $t0
/* 10AC58 7F0D6128 91B00000 */  lbu   $s0, ($t5)
/* 10AC5C 7F0D612C 25890001 */  addiu $t1, $t4, 1
/* 10AC60 7F0D6130 100031B2 */  b     .L7F0E27FC
/* 10AC64 7F0D6134 A7A90298 */   sh    $t1, 0x298($sp)
spectrum_op_3F:
/* 10AC68 7F0D6138 322F0001 */  andi  $t7, $s1, 1
/* 10AC6C 7F0D613C 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10AC70 7F0D6140 39EB0001 */  xori  $t3, $t7, 1
/* 10AC74 7F0D6144 323900C4 */  andi  $t9, $s1, 0xc4
/* 10AC78 7F0D6148 32280001 */  andi  $t0, $s1, 1
/* 10AC7C 7F0D614C 00086900 */  sll   $t5, $t0, 4
/* 10AC80 7F0D6150 032BC025 */  or    $t8, $t9, $t3
/* 10AC84 7F0D6154 030D6025 */  or    $t4, $t8, $t5
/* 10AC88 7F0D6158 32090028 */  andi  $t1, $s0, 0x28
/* 10AC8C 7F0D615C 01898825 */  or    $s1, $t4, $t1
/* 10AC90 7F0D6160 25CA0004 */  addiu $t2, $t6, 4
/* 10AC94 7F0D6164 322E00FF */  andi  $t6, $s1, 0xff
/* 10AC98 7F0D6168 AFAA028C */  sw    $t2, 0x28c($sp)
/* 10AC9C 7F0D616C 100031A3 */  b     .L7F0E27FC
/* 10ACA0 7F0D6170 01C08825 */   move  $s1, $t6
spectrum_op_40:
/* 10ACA4 7F0D6174 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10ACA8 7F0D6178 254F0004 */  addiu $t7, $t2, 4
/* 10ACAC 7F0D617C 1000319F */  b     .L7F0E27FC
/* 10ACB0 7F0D6180 AFAF028C */   sw    $t7, 0x28c($sp)
spectrum_op_41:
/* 10ACB4 7F0D6184 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10ACB8 7F0D6188 327200FF */  andi  $s2, $s3, 0xff
/* 10ACBC 7F0D618C 272B0004 */  addiu $t3, $t9, 4
/* 10ACC0 7F0D6190 1000319A */  b     .L7F0E27FC
/* 10ACC4 7F0D6194 AFAB028C */   sw    $t3, 0x28c($sp)
spectrum_op_42:
/* 10ACC8 7F0D6198 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10ACCC 7F0D619C 329200FF */  andi  $s2, $s4, 0xff
/* 10ACD0 7F0D61A0 25180004 */  addiu $t8, $t0, 4
/* 10ACD4 7F0D61A4 10003195 */  b     .L7F0E27FC
/* 10ACD8 7F0D61A8 AFB8028C */   sw    $t8, 0x28c($sp)
spectrum_op_43:
/* 10ACDC 7F0D61AC 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10ACE0 7F0D61B0 32B200FF */  andi  $s2, $s5, 0xff
/* 10ACE4 7F0D61B4 25AC0004 */  addiu $t4, $t5, 4
/* 10ACE8 7F0D61B8 10003190 */  b     .L7F0E27FC
/* 10ACEC 7F0D61BC AFAC028C */   sw    $t4, 0x28c($sp)
spectrum_op_44:
/* 10ACF0 7F0D61C0 8FA9028C */  lw    $t1, 0x28c($sp)
/* 10ACF4 7F0D61C4 93AA0287 */  lbu   $t2, 0x287($sp)
/* 10ACF8 7F0D61C8 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10ACFC 7F0D61CC 252E0004 */  addiu $t6, $t1, 4
/* 10AD00 7F0D61D0 15400003 */  bnez  $t2, .L7F0D61E0
/* 10AD04 7F0D61D4 AFAE028C */   sw    $t6, 0x28c($sp)
/* 10AD08 7F0D61D8 10003188 */  b     .L7F0E27FC
/* 10AD0C 7F0D61DC 32D200FF */   andi  $s2, $s6, 0xff
.L7F0D61E0:
/* 10AD10 7F0D61E0 24010001 */  li    $at, 1
/* 10AD14 7F0D61E4 15E10005 */  bne   $t7, $at, .L7F0D61FC
/* 10AD18 7F0D61E8 97A80294 */   lhu   $t0, 0x294($sp)
/* 10AD1C 7F0D61EC 97B90296 */  lhu   $t9, 0x296($sp)
/* 10AD20 7F0D61F0 00195A03 */  sra   $t3, $t9, 8
/* 10AD24 7F0D61F4 10000003 */  b     .L7F0D6204
/* 10AD28 7F0D61F8 AFAB0048 */   sw    $t3, 0x48($sp)
.L7F0D61FC:
/* 10AD2C 7F0D61FC 0008C203 */  sra   $t8, $t0, 8
/* 10AD30 7F0D6200 AFB80048 */  sw    $t8, 0x48($sp)
.L7F0D6204:
/* 10AD34 7F0D6204 1000317D */  b     .L7F0E27FC
/* 10AD38 7F0D6208 93B2004B */   lbu   $s2, 0x4b($sp)
spectrum_op_45:
/* 10AD3C 7F0D620C 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10AD40 7F0D6210 93A90287 */  lbu   $t1, 0x287($sp)
/* 10AD44 7F0D6214 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10AD48 7F0D6218 25AC0004 */  addiu $t4, $t5, 4
/* 10AD4C 7F0D621C 15200003 */  bnez  $t1, .L7F0D622C
/* 10AD50 7F0D6220 AFAC028C */   sw    $t4, 0x28c($sp)
/* 10AD54 7F0D6224 10003175 */  b     .L7F0E27FC
/* 10AD58 7F0D6228 32F200FF */   andi  $s2, $s7, 0xff
.L7F0D622C:
/* 10AD5C 7F0D622C 24010001 */  li    $at, 1
/* 10AD60 7F0D6230 15C10005 */  bne   $t6, $at, .L7F0D6248
/* 10AD64 7F0D6234 97B90294 */   lhu   $t9, 0x294($sp)
/* 10AD68 7F0D6238 97AA0296 */  lhu   $t2, 0x296($sp)
/* 10AD6C 7F0D623C 314F00FF */  andi  $t7, $t2, 0xff
/* 10AD70 7F0D6240 10000003 */  b     .L7F0D6250
/* 10AD74 7F0D6244 AFAF0048 */   sw    $t7, 0x48($sp)
.L7F0D6248:
/* 10AD78 7F0D6248 332B00FF */  andi  $t3, $t9, 0xff
/* 10AD7C 7F0D624C AFAB0048 */  sw    $t3, 0x48($sp)
.L7F0D6250:
/* 10AD80 7F0D6250 1000316A */  b     .L7F0E27FC
/* 10AD84 7F0D6254 93B2004B */   lbu   $s2, 0x4b($sp)
spectrum_op_46:
/* 10AD88 7F0D6258 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10AD8C 7F0D625C 93AD0287 */  lbu   $t5, 0x287($sp)
/* 10AD90 7F0D6260 00166200 */  sll   $t4, $s6, 8
/* 10AD94 7F0D6264 25180007 */  addiu $t8, $t0, 7
/* 10AD98 7F0D6268 15A00004 */  bnez  $t5, .L7F0D627C
/* 10AD9C 7F0D626C AFB8028C */   sw    $t8, 0x28c($sp)
/* 10ADA0 7F0D6270 01974825 */  or    $t1, $t4, $s7
/* 10ADA4 7F0D6274 10000016 */  b     .L7F0D62D0
/* 10ADA8 7F0D6278 A7A9020C */   sh    $t1, 0x20c($sp)
.L7F0D627C:
/* 10ADAC 7F0D627C 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10ADB0 7F0D6280 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10ADB4 7F0D6284 24010001 */  li    $at, 1
/* 10ADB8 7F0D6288 25CA0008 */  addiu $t2, $t6, 8
/* 10ADBC 7F0D628C 15E10004 */  bne   $t7, $at, .L7F0D62A0
/* 10ADC0 7F0D6290 AFAA028C */   sw    $t2, 0x28c($sp)
/* 10ADC4 7F0D6294 97B90296 */  lhu   $t9, 0x296($sp)
/* 10ADC8 7F0D6298 10000003 */  b     .L7F0D62A8
/* 10ADCC 7F0D629C AFB90048 */   sw    $t9, 0x48($sp)
.L7F0D62A0:
/* 10ADD0 7F0D62A0 97AB0294 */  lhu   $t3, 0x294($sp)
/* 10ADD4 7F0D62A4 AFAB0048 */  sw    $t3, 0x48($sp)
.L7F0D62A8:
/* 10ADD8 7F0D62A8 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 10ADDC 7F0D62AC 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10ADE0 7F0D62B0 97A80298 */  lhu   $t0, 0x298($sp)
/* 10ADE4 7F0D62B4 8FA90048 */  lw    $t1, 0x48($sp)
/* 10ADE8 7F0D62B8 01186821 */  addu  $t5, $t0, $t8
/* 10ADEC 7F0D62BC 81AC0000 */  lb    $t4, ($t5)
/* 10ADF0 7F0D62C0 250A0001 */  addiu $t2, $t0, 1
/* 10ADF4 7F0D62C4 A7AA0298 */  sh    $t2, 0x298($sp)
/* 10ADF8 7F0D62C8 01897021 */  addu  $t6, $t4, $t1
/* 10ADFC 7F0D62CC A7AE020C */  sh    $t6, 0x20c($sp)
.L7F0D62D0:
/* 10AE00 7F0D62D0 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10AE04 7F0D62D4 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10AE08 7F0D62D8 97AF020C */  lhu   $t7, 0x20c($sp)
/* 10AE0C 7F0D62DC 01F95821 */  addu  $t3, $t7, $t9
/* 10AE10 7F0D62E0 10003146 */  b     .L7F0E27FC
/* 10AE14 7F0D62E4 91720000 */   lbu   $s2, ($t3)
spectrum_op_47:
/* 10AE18 7F0D62E8 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10AE1C 7F0D62EC 321200FF */  andi  $s2, $s0, 0xff
/* 10AE20 7F0D62F0 270D0004 */  addiu $t5, $t8, 4
/* 10AE24 7F0D62F4 10003141 */  b     .L7F0E27FC
/* 10AE28 7F0D62F8 AFAD028C */   sw    $t5, 0x28c($sp)
spectrum_op_48:
/* 10AE2C 7F0D62FC 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10AE30 7F0D6300 325300FF */  andi  $s3, $s2, 0xff
/* 10AE34 7F0D6304 25890004 */  addiu $t1, $t4, 4
/* 10AE38 7F0D6308 1000313C */  b     .L7F0E27FC
/* 10AE3C 7F0D630C AFA9028C */   sw    $t1, 0x28c($sp)
spectrum_op_49:
/* 10AE40 7F0D6310 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10AE44 7F0D6314 25C80004 */  addiu $t0, $t6, 4
/* 10AE48 7F0D6318 10003138 */  b     .L7F0E27FC
/* 10AE4C 7F0D631C AFA8028C */   sw    $t0, 0x28c($sp)
spectrum_op_4A:
/* 10AE50 7F0D6320 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10AE54 7F0D6324 329300FF */  andi  $s3, $s4, 0xff
/* 10AE58 7F0D6328 254F0004 */  addiu $t7, $t2, 4
/* 10AE5C 7F0D632C 10003133 */  b     .L7F0E27FC
/* 10AE60 7F0D6330 AFAF028C */   sw    $t7, 0x28c($sp)
spectrum_op_4B:
/* 10AE64 7F0D6334 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10AE68 7F0D6338 32B300FF */  andi  $s3, $s5, 0xff
/* 10AE6C 7F0D633C 272B0004 */  addiu $t3, $t9, 4
/* 10AE70 7F0D6340 1000312E */  b     .L7F0E27FC
/* 10AE74 7F0D6344 AFAB028C */   sw    $t3, 0x28c($sp)
spectrum_op_4C:
/* 10AE78 7F0D6348 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10AE7C 7F0D634C 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10AE80 7F0D6350 93A90287 */  lbu   $t1, 0x287($sp)
/* 10AE84 7F0D6354 270D0004 */  addiu $t5, $t8, 4
/* 10AE88 7F0D6358 15800003 */  bnez  $t4, .L7F0D6368
/* 10AE8C 7F0D635C AFAD028C */   sw    $t5, 0x28c($sp)
/* 10AE90 7F0D6360 10003126 */  b     .L7F0E27FC
/* 10AE94 7F0D6364 32D300FF */   andi  $s3, $s6, 0xff
.L7F0D6368:
/* 10AE98 7F0D6368 24010001 */  li    $at, 1
/* 10AE9C 7F0D636C 15210005 */  bne   $t1, $at, .L7F0D6384
/* 10AEA0 7F0D6370 97AA0294 */   lhu   $t2, 0x294($sp)
/* 10AEA4 7F0D6374 97AE0296 */  lhu   $t6, 0x296($sp)
/* 10AEA8 7F0D6378 000E4203 */  sra   $t0, $t6, 8
/* 10AEAC 7F0D637C 10000003 */  b     .L7F0D638C
/* 10AEB0 7F0D6380 AFA80048 */   sw    $t0, 0x48($sp)
.L7F0D6384:
/* 10AEB4 7F0D6384 000A7A03 */  sra   $t7, $t2, 8
/* 10AEB8 7F0D6388 AFAF0048 */  sw    $t7, 0x48($sp)
.L7F0D638C:
/* 10AEBC 7F0D638C 1000311B */  b     .L7F0E27FC
/* 10AEC0 7F0D6390 93B3004B */   lbu   $s3, 0x4b($sp)
spectrum_op_4D:
/* 10AEC4 7F0D6394 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10AEC8 7F0D6398 93B80287 */  lbu   $t8, 0x287($sp)
/* 10AECC 7F0D639C 93AD0287 */  lbu   $t5, 0x287($sp)
/* 10AED0 7F0D63A0 272B0004 */  addiu $t3, $t9, 4
/* 10AED4 7F0D63A4 17000003 */  bnez  $t8, .L7F0D63B4
/* 10AED8 7F0D63A8 AFAB028C */   sw    $t3, 0x28c($sp)
/* 10AEDC 7F0D63AC 10003113 */  b     .L7F0E27FC
/* 10AEE0 7F0D63B0 32F300FF */   andi  $s3, $s7, 0xff
.L7F0D63B4:
/* 10AEE4 7F0D63B4 24010001 */  li    $at, 1
/* 10AEE8 7F0D63B8 15A10005 */  bne   $t5, $at, .L7F0D63D0
/* 10AEEC 7F0D63BC 97AE0294 */   lhu   $t6, 0x294($sp)
/* 10AEF0 7F0D63C0 97AC0296 */  lhu   $t4, 0x296($sp)
/* 10AEF4 7F0D63C4 318900FF */  andi  $t1, $t4, 0xff
/* 10AEF8 7F0D63C8 10000003 */  b     .L7F0D63D8
/* 10AEFC 7F0D63CC AFA90048 */   sw    $t1, 0x48($sp)
.L7F0D63D0:
/* 10AF00 7F0D63D0 31C800FF */  andi  $t0, $t6, 0xff
/* 10AF04 7F0D63D4 AFA80048 */  sw    $t0, 0x48($sp)
.L7F0D63D8:
/* 10AF08 7F0D63D8 10003108 */  b     .L7F0E27FC
/* 10AF0C 7F0D63DC 93B3004B */   lbu   $s3, 0x4b($sp)
spectrum_op_4E:
/* 10AF10 7F0D63E0 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10AF14 7F0D63E4 93B90287 */  lbu   $t9, 0x287($sp)
/* 10AF18 7F0D63E8 00165A00 */  sll   $t3, $s6, 8
/* 10AF1C 7F0D63EC 254F0007 */  addiu $t7, $t2, 7
/* 10AF20 7F0D63F0 17200004 */  bnez  $t9, .L7F0D6404
/* 10AF24 7F0D63F4 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10AF28 7F0D63F8 0177C025 */  or    $t8, $t3, $s7
/* 10AF2C 7F0D63FC 10000016 */  b     .L7F0D6458
/* 10AF30 7F0D6400 A7B8020A */   sh    $t8, 0x20a($sp)
.L7F0D6404:
/* 10AF34 7F0D6404 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10AF38 7F0D6408 93A90287 */  lbu   $t1, 0x287($sp)
/* 10AF3C 7F0D640C 24010001 */  li    $at, 1
/* 10AF40 7F0D6410 25AC0008 */  addiu $t4, $t5, 8
/* 10AF44 7F0D6414 15210004 */  bne   $t1, $at, .L7F0D6428
/* 10AF48 7F0D6418 AFAC028C */   sw    $t4, 0x28c($sp)
/* 10AF4C 7F0D641C 97AE0296 */  lhu   $t6, 0x296($sp)
/* 10AF50 7F0D6420 10000003 */  b     .L7F0D6430
/* 10AF54 7F0D6424 AFAE0048 */   sw    $t6, 0x48($sp)
.L7F0D6428:
/* 10AF58 7F0D6428 97A80294 */  lhu   $t0, 0x294($sp)
/* 10AF5C 7F0D642C AFA80048 */  sw    $t0, 0x48($sp)
.L7F0D6430:
/* 10AF60 7F0D6430 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 10AF64 7F0D6434 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10AF68 7F0D6438 97AA0298 */  lhu   $t2, 0x298($sp)
/* 10AF6C 7F0D643C 8FB80048 */  lw    $t8, 0x48($sp)
/* 10AF70 7F0D6440 014FC821 */  addu  $t9, $t2, $t7
/* 10AF74 7F0D6444 832B0000 */  lb    $t3, ($t9)
/* 10AF78 7F0D6448 254C0001 */  addiu $t4, $t2, 1
/* 10AF7C 7F0D644C A7AC0298 */  sh    $t4, 0x298($sp)
/* 10AF80 7F0D6450 01786821 */  addu  $t5, $t3, $t8
/* 10AF84 7F0D6454 A7AD020A */  sh    $t5, 0x20a($sp)
.L7F0D6458:
/* 10AF88 7F0D6458 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10AF8C 7F0D645C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10AF90 7F0D6460 97A9020A */  lhu   $t1, 0x20a($sp)
/* 10AF94 7F0D6464 012E4021 */  addu  $t0, $t1, $t6
/* 10AF98 7F0D6468 100030E4 */  b     .L7F0E27FC
/* 10AF9C 7F0D646C 91130000 */   lbu   $s3, ($t0)
spectrum_op_4F:
/* 10AFA0 7F0D6470 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10AFA4 7F0D6474 321300FF */  andi  $s3, $s0, 0xff
/* 10AFA8 7F0D6478 25F90004 */  addiu $t9, $t7, 4
/* 10AFAC 7F0D647C 100030DF */  b     .L7F0E27FC
/* 10AFB0 7F0D6480 AFB9028C */   sw    $t9, 0x28c($sp)
spectrum_op_50:
/* 10AFB4 7F0D6484 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10AFB8 7F0D6488 325400FF */  andi  $s4, $s2, 0xff
/* 10AFBC 7F0D648C 25780004 */  addiu $t8, $t3, 4
/* 10AFC0 7F0D6490 100030DA */  b     .L7F0E27FC
/* 10AFC4 7F0D6494 AFB8028C */   sw    $t8, 0x28c($sp)
spectrum_op_51:
/* 10AFC8 7F0D6498 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10AFCC 7F0D649C 327400FF */  andi  $s4, $s3, 0xff
/* 10AFD0 7F0D64A0 25AA0004 */  addiu $t2, $t5, 4
/* 10AFD4 7F0D64A4 100030D5 */  b     .L7F0E27FC
/* 10AFD8 7F0D64A8 AFAA028C */   sw    $t2, 0x28c($sp)
spectrum_op_52:
/* 10AFDC 7F0D64AC 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10AFE0 7F0D64B0 25890004 */  addiu $t1, $t4, 4
/* 10AFE4 7F0D64B4 100030D1 */  b     .L7F0E27FC
/* 10AFE8 7F0D64B8 AFA9028C */   sw    $t1, 0x28c($sp)
spectrum_op_53:
/* 10AFEC 7F0D64BC 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10AFF0 7F0D64C0 32B400FF */  andi  $s4, $s5, 0xff
/* 10AFF4 7F0D64C4 25C80004 */  addiu $t0, $t6, 4
/* 10AFF8 7F0D64C8 100030CC */  b     .L7F0E27FC
/* 10AFFC 7F0D64CC AFA8028C */   sw    $t0, 0x28c($sp)
spectrum_op_54:
/* 10B000 7F0D64D0 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10B004 7F0D64D4 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10B008 7F0D64D8 93B80287 */  lbu   $t8, 0x287($sp)
/* 10B00C 7F0D64DC 25F90004 */  addiu $t9, $t7, 4
/* 10B010 7F0D64E0 15600003 */  bnez  $t3, .L7F0D64F0
/* 10B014 7F0D64E4 AFB9028C */   sw    $t9, 0x28c($sp)
/* 10B018 7F0D64E8 100030C4 */  b     .L7F0E27FC
/* 10B01C 7F0D64EC 32D400FF */   andi  $s4, $s6, 0xff
.L7F0D64F0:
/* 10B020 7F0D64F0 24010001 */  li    $at, 1
/* 10B024 7F0D64F4 17010005 */  bne   $t8, $at, .L7F0D650C
/* 10B028 7F0D64F8 97AC0294 */   lhu   $t4, 0x294($sp)
/* 10B02C 7F0D64FC 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10B030 7F0D6500 000D5203 */  sra   $t2, $t5, 8
/* 10B034 7F0D6504 10000003 */  b     .L7F0D6514
/* 10B038 7F0D6508 AFAA0048 */   sw    $t2, 0x48($sp)
.L7F0D650C:
/* 10B03C 7F0D650C 000C4A03 */  sra   $t1, $t4, 8
/* 10B040 7F0D6510 AFA90048 */  sw    $t1, 0x48($sp)
.L7F0D6514:
/* 10B044 7F0D6514 100030B9 */  b     .L7F0E27FC
/* 10B048 7F0D6518 93B4004B */   lbu   $s4, 0x4b($sp)
spectrum_op_55:
/* 10B04C 7F0D651C 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10B050 7F0D6520 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10B054 7F0D6524 93B90287 */  lbu   $t9, 0x287($sp)
/* 10B058 7F0D6528 25C80004 */  addiu $t0, $t6, 4
/* 10B05C 7F0D652C 15E00003 */  bnez  $t7, .L7F0D653C
/* 10B060 7F0D6530 AFA8028C */   sw    $t0, 0x28c($sp)
/* 10B064 7F0D6534 100030B1 */  b     .L7F0E27FC
/* 10B068 7F0D6538 32F400FF */   andi  $s4, $s7, 0xff
.L7F0D653C:
/* 10B06C 7F0D653C 24010001 */  li    $at, 1
/* 10B070 7F0D6540 17210005 */  bne   $t9, $at, .L7F0D6558
/* 10B074 7F0D6544 97AD0294 */   lhu   $t5, 0x294($sp)
/* 10B078 7F0D6548 97AB0296 */  lhu   $t3, 0x296($sp)
/* 10B07C 7F0D654C 317800FF */  andi  $t8, $t3, 0xff
/* 10B080 7F0D6550 10000003 */  b     .L7F0D6560
/* 10B084 7F0D6554 AFB80048 */   sw    $t8, 0x48($sp)
.L7F0D6558:
/* 10B088 7F0D6558 31AA00FF */  andi  $t2, $t5, 0xff
/* 10B08C 7F0D655C AFAA0048 */  sw    $t2, 0x48($sp)
.L7F0D6560:
/* 10B090 7F0D6560 100030A6 */  b     .L7F0E27FC
/* 10B094 7F0D6564 93B4004B */   lbu   $s4, 0x4b($sp)
spectrum_op_56:
/* 10B098 7F0D6568 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10B09C 7F0D656C 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10B0A0 7F0D6570 00164200 */  sll   $t0, $s6, 8
/* 10B0A4 7F0D6574 25890007 */  addiu $t1, $t4, 7
/* 10B0A8 7F0D6578 15C00004 */  bnez  $t6, .L7F0D658C
/* 10B0AC 7F0D657C AFA9028C */   sw    $t1, 0x28c($sp)
/* 10B0B0 7F0D6580 01177825 */  or    $t7, $t0, $s7
/* 10B0B4 7F0D6584 10000016 */  b     .L7F0D65E0
/* 10B0B8 7F0D6588 A7AF0208 */   sh    $t7, 0x208($sp)
.L7F0D658C:
/* 10B0BC 7F0D658C 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10B0C0 7F0D6590 93B80287 */  lbu   $t8, 0x287($sp)
/* 10B0C4 7F0D6594 24010001 */  li    $at, 1
/* 10B0C8 7F0D6598 272B0008 */  addiu $t3, $t9, 8
/* 10B0CC 7F0D659C 17010004 */  bne   $t8, $at, .L7F0D65B0
/* 10B0D0 7F0D65A0 AFAB028C */   sw    $t3, 0x28c($sp)
/* 10B0D4 7F0D65A4 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10B0D8 7F0D65A8 10000003 */  b     .L7F0D65B8
/* 10B0DC 7F0D65AC AFAD0048 */   sw    $t5, 0x48($sp)
.L7F0D65B0:
/* 10B0E0 7F0D65B0 97AA0294 */  lhu   $t2, 0x294($sp)
/* 10B0E4 7F0D65B4 AFAA0048 */  sw    $t2, 0x48($sp)
.L7F0D65B8:
/* 10B0E8 7F0D65B8 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10B0EC 7F0D65BC 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10B0F0 7F0D65C0 97AC0298 */  lhu   $t4, 0x298($sp)
/* 10B0F4 7F0D65C4 8FAF0048 */  lw    $t7, 0x48($sp)
/* 10B0F8 7F0D65C8 01897021 */  addu  $t6, $t4, $t1
/* 10B0FC 7F0D65CC 81C80000 */  lb    $t0, ($t6)
/* 10B100 7F0D65D0 258B0001 */  addiu $t3, $t4, 1
/* 10B104 7F0D65D4 A7AB0298 */  sh    $t3, 0x298($sp)
/* 10B108 7F0D65D8 010FC821 */  addu  $t9, $t0, $t7
/* 10B10C 7F0D65DC A7B90208 */  sh    $t9, 0x208($sp)
.L7F0D65E0:
/* 10B110 7F0D65E0 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 10B114 7F0D65E4 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10B118 7F0D65E8 97B80208 */  lhu   $t8, 0x208($sp)
/* 10B11C 7F0D65EC 030D5021 */  addu  $t2, $t8, $t5
/* 10B120 7F0D65F0 10003082 */  b     .L7F0E27FC
/* 10B124 7F0D65F4 91540000 */   lbu   $s4, ($t2)
spectrum_op_57:
/* 10B128 7F0D65F8 8FA9028C */  lw    $t1, 0x28c($sp)
/* 10B12C 7F0D65FC 321400FF */  andi  $s4, $s0, 0xff
/* 10B130 7F0D6600 252E0004 */  addiu $t6, $t1, 4
/* 10B134 7F0D6604 1000307D */  b     .L7F0E27FC
/* 10B138 7F0D6608 AFAE028C */   sw    $t6, 0x28c($sp)
spectrum_op_58:
/* 10B13C 7F0D660C 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10B140 7F0D6610 325500FF */  andi  $s5, $s2, 0xff
/* 10B144 7F0D6614 250F0004 */  addiu $t7, $t0, 4
/* 10B148 7F0D6618 10003078 */  b     .L7F0E27FC
/* 10B14C 7F0D661C AFAF028C */   sw    $t7, 0x28c($sp)
spectrum_op_59:
/* 10B150 7F0D6620 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10B154 7F0D6624 327500FF */  andi  $s5, $s3, 0xff
/* 10B158 7F0D6628 272C0004 */  addiu $t4, $t9, 4
/* 10B15C 7F0D662C 10003073 */  b     .L7F0E27FC
/* 10B160 7F0D6630 AFAC028C */   sw    $t4, 0x28c($sp)
spectrum_op_5A:
/* 10B164 7F0D6634 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10B168 7F0D6638 329500FF */  andi  $s5, $s4, 0xff
/* 10B16C 7F0D663C 25780004 */  addiu $t8, $t3, 4
/* 10B170 7F0D6640 1000306E */  b     .L7F0E27FC
/* 10B174 7F0D6644 AFB8028C */   sw    $t8, 0x28c($sp)
spectrum_op_5B:
/* 10B178 7F0D6648 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10B17C 7F0D664C 25AA0004 */  addiu $t2, $t5, 4
/* 10B180 7F0D6650 1000306A */  b     .L7F0E27FC
/* 10B184 7F0D6654 AFAA028C */   sw    $t2, 0x28c($sp)
spectrum_op_5C:
/* 10B188 7F0D6658 8FA9028C */  lw    $t1, 0x28c($sp)
/* 10B18C 7F0D665C 93A80287 */  lbu   $t0, 0x287($sp)
/* 10B190 7F0D6660 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10B194 7F0D6664 252E0004 */  addiu $t6, $t1, 4
/* 10B198 7F0D6668 15000003 */  bnez  $t0, .L7F0D6678
/* 10B19C 7F0D666C AFAE028C */   sw    $t6, 0x28c($sp)
/* 10B1A0 7F0D6670 10003062 */  b     .L7F0E27FC
/* 10B1A4 7F0D6674 32D500FF */   andi  $s5, $s6, 0xff
.L7F0D6678:
/* 10B1A8 7F0D6678 24010001 */  li    $at, 1
/* 10B1AC 7F0D667C 15E10005 */  bne   $t7, $at, .L7F0D6694
/* 10B1B0 7F0D6680 97AB0294 */   lhu   $t3, 0x294($sp)
/* 10B1B4 7F0D6684 97B90296 */  lhu   $t9, 0x296($sp)
/* 10B1B8 7F0D6688 00196203 */  sra   $t4, $t9, 8
/* 10B1BC 7F0D668C 10000003 */  b     .L7F0D669C
/* 10B1C0 7F0D6690 AFAC0048 */   sw    $t4, 0x48($sp)
.L7F0D6694:
/* 10B1C4 7F0D6694 000BC203 */  sra   $t8, $t3, 8
/* 10B1C8 7F0D6698 AFB80048 */  sw    $t8, 0x48($sp)
.L7F0D669C:
/* 10B1CC 7F0D669C 10003057 */  b     .L7F0E27FC
/* 10B1D0 7F0D66A0 93B5004B */   lbu   $s5, 0x4b($sp)
spectrum_op_5D:
/* 10B1D4 7F0D66A4 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10B1D8 7F0D66A8 93A90287 */  lbu   $t1, 0x287($sp)
/* 10B1DC 7F0D66AC 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10B1E0 7F0D66B0 25AA0004 */  addiu $t2, $t5, 4
/* 10B1E4 7F0D66B4 15200003 */  bnez  $t1, .L7F0D66C4
/* 10B1E8 7F0D66B8 AFAA028C */   sw    $t2, 0x28c($sp)
/* 10B1EC 7F0D66BC 1000304F */  b     .L7F0E27FC
/* 10B1F0 7F0D66C0 32F500FF */   andi  $s5, $s7, 0xff
.L7F0D66C4:
/* 10B1F4 7F0D66C4 24010001 */  li    $at, 1
/* 10B1F8 7F0D66C8 15C10005 */  bne   $t6, $at, .L7F0D66E0
/* 10B1FC 7F0D66CC 97B90294 */   lhu   $t9, 0x294($sp)
/* 10B200 7F0D66D0 97A80296 */  lhu   $t0, 0x296($sp)
/* 10B204 7F0D66D4 310F00FF */  andi  $t7, $t0, 0xff
/* 10B208 7F0D66D8 10000003 */  b     .L7F0D66E8
/* 10B20C 7F0D66DC AFAF0048 */   sw    $t7, 0x48($sp)
.L7F0D66E0:
/* 10B210 7F0D66E0 332C00FF */  andi  $t4, $t9, 0xff
/* 10B214 7F0D66E4 AFAC0048 */  sw    $t4, 0x48($sp)
.L7F0D66E8:
/* 10B218 7F0D66E8 10003044 */  b     .L7F0E27FC
/* 10B21C 7F0D66EC 93B5004B */   lbu   $s5, 0x4b($sp)
spectrum_op_5E:
/* 10B220 7F0D66F0 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10B224 7F0D66F4 93AD0287 */  lbu   $t5, 0x287($sp)
/* 10B228 7F0D66F8 00165200 */  sll   $t2, $s6, 8
/* 10B22C 7F0D66FC 25780007 */  addiu $t8, $t3, 7
/* 10B230 7F0D6700 15A00004 */  bnez  $t5, .L7F0D6714
/* 10B234 7F0D6704 AFB8028C */   sw    $t8, 0x28c($sp)
/* 10B238 7F0D6708 01574825 */  or    $t1, $t2, $s7
/* 10B23C 7F0D670C 10000016 */  b     .L7F0D6768
/* 10B240 7F0D6710 A7A90206 */   sh    $t1, 0x206($sp)
.L7F0D6714:
/* 10B244 7F0D6714 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10B248 7F0D6718 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10B24C 7F0D671C 24010001 */  li    $at, 1
/* 10B250 7F0D6720 25C80008 */  addiu $t0, $t6, 8
/* 10B254 7F0D6724 15E10004 */  bne   $t7, $at, .L7F0D6738
/* 10B258 7F0D6728 AFA8028C */   sw    $t0, 0x28c($sp)
/* 10B25C 7F0D672C 97B90296 */  lhu   $t9, 0x296($sp)
/* 10B260 7F0D6730 10000003 */  b     .L7F0D6740
/* 10B264 7F0D6734 AFB90048 */   sw    $t9, 0x48($sp)
.L7F0D6738:
/* 10B268 7F0D6738 97AC0294 */  lhu   $t4, 0x294($sp)
/* 10B26C 7F0D673C AFAC0048 */  sw    $t4, 0x48($sp)
.L7F0D6740:
/* 10B270 7F0D6740 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 10B274 7F0D6744 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10B278 7F0D6748 97AB0298 */  lhu   $t3, 0x298($sp)
/* 10B27C 7F0D674C 8FA90048 */  lw    $t1, 0x48($sp)
/* 10B280 7F0D6750 01786821 */  addu  $t5, $t3, $t8
/* 10B284 7F0D6754 81AA0000 */  lb    $t2, ($t5)
/* 10B288 7F0D6758 25680001 */  addiu $t0, $t3, 1
/* 10B28C 7F0D675C A7A80298 */  sh    $t0, 0x298($sp)
/* 10B290 7F0D6760 01497021 */  addu  $t6, $t2, $t1
/* 10B294 7F0D6764 A7AE0206 */  sh    $t6, 0x206($sp)
.L7F0D6768:
/* 10B298 7F0D6768 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10B29C 7F0D676C 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10B2A0 7F0D6770 97AF0206 */  lhu   $t7, 0x206($sp)
/* 10B2A4 7F0D6774 01F96021 */  addu  $t4, $t7, $t9
/* 10B2A8 7F0D6778 10003020 */  b     .L7F0E27FC
/* 10B2AC 7F0D677C 91950000 */   lbu   $s5, ($t4)
spectrum_op_5F:
/* 10B2B0 7F0D6780 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10B2B4 7F0D6784 321500FF */  andi  $s5, $s0, 0xff
/* 10B2B8 7F0D6788 270D0004 */  addiu $t5, $t8, 4
/* 10B2BC 7F0D678C 1000301B */  b     .L7F0E27FC
/* 10B2C0 7F0D6790 AFAD028C */   sw    $t5, 0x28c($sp)
spectrum_op_60:
/* 10B2C4 7F0D6794 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10B2C8 7F0D6798 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10B2CC 7F0D679C 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10B2D0 7F0D67A0 25490004 */  addiu $t1, $t2, 4
/* 10B2D4 7F0D67A4 15C00003 */  bnez  $t6, .L7F0D67B4
/* 10B2D8 7F0D67A8 AFA9028C */   sw    $t1, 0x28c($sp)
/* 10B2DC 7F0D67AC 10003013 */  b     .L7F0E27FC
/* 10B2E0 7F0D67B0 325600FF */   andi  $s6, $s2, 0xff
.L7F0D67B4:
/* 10B2E4 7F0D67B4 24010001 */  li    $at, 1
/* 10B2E8 7F0D67B8 15610007 */  bne   $t3, $at, .L7F0D67D8
/* 10B2EC 7F0D67BC 97B80294 */   lhu   $t8, 0x294($sp)
/* 10B2F0 7F0D67C0 97A80296 */  lhu   $t0, 0x296($sp)
/* 10B2F4 7F0D67C4 0012CA00 */  sll   $t9, $s2, 8
/* 10B2F8 7F0D67C8 310F00FF */  andi  $t7, $t0, 0xff
/* 10B2FC 7F0D67CC 01F96025 */  or    $t4, $t7, $t9
/* 10B300 7F0D67D0 1000300A */  b     .L7F0E27FC
/* 10B304 7F0D67D4 A7AC0296 */   sh    $t4, 0x296($sp)
.L7F0D67D8:
/* 10B308 7F0D67D8 330D00FF */  andi  $t5, $t8, 0xff
/* 10B30C 7F0D67DC 00125200 */  sll   $t2, $s2, 8
/* 10B310 7F0D67E0 01AA4825 */  or    $t1, $t5, $t2
/* 10B314 7F0D67E4 10003005 */  b     .L7F0E27FC
/* 10B318 7F0D67E8 A7A90294 */   sh    $t1, 0x294($sp)
spectrum_op_61:
/* 10B31C 7F0D67EC 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10B320 7F0D67F0 93A80287 */  lbu   $t0, 0x287($sp)
/* 10B324 7F0D67F4 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10B328 7F0D67F8 25CB0004 */  addiu $t3, $t6, 4
/* 10B32C 7F0D67FC 15000003 */  bnez  $t0, .L7F0D680C
/* 10B330 7F0D6800 AFAB028C */   sw    $t3, 0x28c($sp)
/* 10B334 7F0D6804 10002FFD */  b     .L7F0E27FC
/* 10B338 7F0D6808 327600FF */   andi  $s6, $s3, 0xff
.L7F0D680C:
/* 10B33C 7F0D680C 24010001 */  li    $at, 1
/* 10B340 7F0D6810 15E10007 */  bne   $t7, $at, .L7F0D6830
/* 10B344 7F0D6814 97AA0294 */   lhu   $t2, 0x294($sp)
/* 10B348 7F0D6818 97B90296 */  lhu   $t9, 0x296($sp)
/* 10B34C 7F0D681C 0013C200 */  sll   $t8, $s3, 8
/* 10B350 7F0D6820 332C00FF */  andi  $t4, $t9, 0xff
/* 10B354 7F0D6824 01986825 */  or    $t5, $t4, $t8
/* 10B358 7F0D6828 10002FF4 */  b     .L7F0E27FC
/* 10B35C 7F0D682C A7AD0296 */   sh    $t5, 0x296($sp)
.L7F0D6830:
/* 10B360 7F0D6830 314900FF */  andi  $t1, $t2, 0xff
/* 10B364 7F0D6834 00137200 */  sll   $t6, $s3, 8
/* 10B368 7F0D6838 012E5825 */  or    $t3, $t1, $t6
/* 10B36C 7F0D683C 10002FEF */  b     .L7F0E27FC
/* 10B370 7F0D6840 A7AB0294 */   sh    $t3, 0x294($sp)
spectrum_op_62:
/* 10B374 7F0D6844 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10B378 7F0D6848 93B90287 */  lbu   $t9, 0x287($sp)
/* 10B37C 7F0D684C 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10B380 7F0D6850 250F0004 */  addiu $t7, $t0, 4
/* 10B384 7F0D6854 17200003 */  bnez  $t9, .L7F0D6864
/* 10B388 7F0D6858 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10B38C 7F0D685C 10002FE7 */  b     .L7F0E27FC
/* 10B390 7F0D6860 329600FF */   andi  $s6, $s4, 0xff
.L7F0D6864:
/* 10B394 7F0D6864 24010001 */  li    $at, 1
/* 10B398 7F0D6868 15810007 */  bne   $t4, $at, .L7F0D6888
/* 10B39C 7F0D686C 97AE0294 */   lhu   $t6, 0x294($sp)
/* 10B3A0 7F0D6870 97B80296 */  lhu   $t8, 0x296($sp)
/* 10B3A4 7F0D6874 00145200 */  sll   $t2, $s4, 8
/* 10B3A8 7F0D6878 330D00FF */  andi  $t5, $t8, 0xff
/* 10B3AC 7F0D687C 01AA4825 */  or    $t1, $t5, $t2
/* 10B3B0 7F0D6880 10002FDE */  b     .L7F0E27FC
/* 10B3B4 7F0D6884 A7A90296 */   sh    $t1, 0x296($sp)
.L7F0D6888:
/* 10B3B8 7F0D6888 31CB00FF */  andi  $t3, $t6, 0xff
/* 10B3BC 7F0D688C 00144200 */  sll   $t0, $s4, 8
/* 10B3C0 7F0D6890 01687825 */  or    $t7, $t3, $t0
/* 10B3C4 7F0D6894 10002FD9 */  b     .L7F0E27FC
/* 10B3C8 7F0D6898 A7AF0294 */   sh    $t7, 0x294($sp)
spectrum_op_63:
/* 10B3CC 7F0D689C 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10B3D0 7F0D68A0 93B80287 */  lbu   $t8, 0x287($sp)
/* 10B3D4 7F0D68A4 93AD0287 */  lbu   $t5, 0x287($sp)
/* 10B3D8 7F0D68A8 272C0004 */  addiu $t4, $t9, 4
/* 10B3DC 7F0D68AC 17000003 */  bnez  $t8, .L7F0D68BC
/* 10B3E0 7F0D68B0 AFAC028C */   sw    $t4, 0x28c($sp)
/* 10B3E4 7F0D68B4 10002FD1 */  b     .L7F0E27FC
/* 10B3E8 7F0D68B8 32B600FF */   andi  $s6, $s5, 0xff
.L7F0D68BC:
/* 10B3EC 7F0D68BC 24010001 */  li    $at, 1
/* 10B3F0 7F0D68C0 15A10007 */  bne   $t5, $at, .L7F0D68E0
/* 10B3F4 7F0D68C4 97A80294 */   lhu   $t0, 0x294($sp)
/* 10B3F8 7F0D68C8 97AA0296 */  lhu   $t2, 0x296($sp)
/* 10B3FC 7F0D68CC 00157200 */  sll   $t6, $s5, 8
/* 10B400 7F0D68D0 314900FF */  andi  $t1, $t2, 0xff
/* 10B404 7F0D68D4 012E5825 */  or    $t3, $t1, $t6
/* 10B408 7F0D68D8 10002FC8 */  b     .L7F0E27FC
/* 10B40C 7F0D68DC A7AB0296 */   sh    $t3, 0x296($sp)
.L7F0D68E0:
/* 10B410 7F0D68E0 310F00FF */  andi  $t7, $t0, 0xff
/* 10B414 7F0D68E4 0015CA00 */  sll   $t9, $s5, 8
/* 10B418 7F0D68E8 01F96025 */  or    $t4, $t7, $t9
/* 10B41C 7F0D68EC 10002FC3 */  b     .L7F0E27FC
/* 10B420 7F0D68F0 A7AC0294 */   sh    $t4, 0x294($sp)
spectrum_op_64:
/* 10B424 7F0D68F4 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10B428 7F0D68F8 270D0004 */  addiu $t5, $t8, 4
/* 10B42C 7F0D68FC 10002FBF */  b     .L7F0E27FC
/* 10B430 7F0D6900 AFAD028C */   sw    $t5, 0x28c($sp)
spectrum_op_65:
/* 10B434 7F0D6904 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10B438 7F0D6908 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10B43C 7F0D690C 93AD0287 */  lbu   $t5, 0x287($sp)
/* 10B440 7F0D6910 25490004 */  addiu $t1, $t2, 4
/* 10B444 7F0D6914 2DCB0001 */  sltiu $t3, $t6, 1
/* 10B448 7F0D6918 11600010 */  beqz  $t3, .L7F0D695C
/* 10B44C 7F0D691C AFA9028C */   sw    $t1, 0x28c($sp)
/* 10B450 7F0D6920 11600003 */  beqz  $t3, .L7F0D6930
/* 10B454 7F0D6924 93A80287 */   lbu   $t0, 0x287($sp)
/* 10B458 7F0D6928 10002FB4 */  b     .L7F0E27FC
/* 10B45C 7F0D692C 32F600FF */   andi  $s6, $s7, 0xff
.L7F0D6930:
/* 10B460 7F0D6930 24010001 */  li    $at, 1
/* 10B464 7F0D6934 15010005 */  bne   $t0, $at, .L7F0D694C
/* 10B468 7F0D6938 97AC0294 */   lhu   $t4, 0x294($sp)
/* 10B46C 7F0D693C 97AF0296 */  lhu   $t7, 0x296($sp)
/* 10B470 7F0D6940 31F900FF */  andi  $t9, $t7, 0xff
/* 10B474 7F0D6944 10000003 */  b     .L7F0D6954
/* 10B478 7F0D6948 AFB90048 */   sw    $t9, 0x48($sp)
.L7F0D694C:
/* 10B47C 7F0D694C 319800FF */  andi  $t8, $t4, 0xff
/* 10B480 7F0D6950 AFB80048 */  sw    $t8, 0x48($sp)
.L7F0D6954:
/* 10B484 7F0D6954 10002FA9 */  b     .L7F0E27FC
/* 10B488 7F0D6958 93B6004B */   lbu   $s6, 0x4b($sp)
.L7F0D695C:
/* 10B48C 7F0D695C 24010001 */  li    $at, 1
/* 10B490 7F0D6960 15A10017 */  bne   $t5, $at, .L7F0D69C0
/* 10B494 7F0D6964 93A90287 */   lbu   $t1, 0x287($sp)
/* 10B498 7F0D6968 15A00003 */  bnez  $t5, .L7F0D6978
/* 10B49C 7F0D696C 93AA0287 */   lbu   $t2, 0x287($sp)
/* 10B4A0 7F0D6970 1000000C */  b     .L7F0D69A4
/* 10B4A4 7F0D6974 AFB70044 */   sw    $s7, 0x44($sp)
.L7F0D6978:
/* 10B4A8 7F0D6978 24010001 */  li    $at, 1
/* 10B4AC 7F0D697C 15410005 */  bne   $t2, $at, .L7F0D6994
/* 10B4B0 7F0D6980 97AB0294 */   lhu   $t3, 0x294($sp)
/* 10B4B4 7F0D6984 97A90296 */  lhu   $t1, 0x296($sp)
/* 10B4B8 7F0D6988 312E00FF */  andi  $t6, $t1, 0xff
/* 10B4BC 7F0D698C 10000003 */  b     .L7F0D699C
/* 10B4C0 7F0D6990 AFAE0040 */   sw    $t6, 0x40($sp)
.L7F0D6994:
/* 10B4C4 7F0D6994 316800FF */  andi  $t0, $t3, 0xff
/* 10B4C8 7F0D6998 AFA80040 */  sw    $t0, 0x40($sp)
.L7F0D699C:
/* 10B4CC 7F0D699C 8FAF0040 */  lw    $t7, 0x40($sp)
/* 10B4D0 7F0D69A0 AFAF0044 */  sw    $t7, 0x44($sp)
.L7F0D69A4:
/* 10B4D4 7F0D69A4 8FB90044 */  lw    $t9, 0x44($sp)
/* 10B4D8 7F0D69A8 97B80296 */  lhu   $t8, 0x296($sp)
/* 10B4DC 7F0D69AC 00196200 */  sll   $t4, $t9, 8
/* 10B4E0 7F0D69B0 330D00FF */  andi  $t5, $t8, 0xff
/* 10B4E4 7F0D69B4 018D5025 */  or    $t2, $t4, $t5
/* 10B4E8 7F0D69B8 10002F90 */  b     .L7F0E27FC
/* 10B4EC 7F0D69BC A7AA0296 */   sh    $t2, 0x296($sp)
.L7F0D69C0:
/* 10B4F0 7F0D69C0 15200003 */  bnez  $t1, .L7F0D69D0
/* 10B4F4 7F0D69C4 93AE0287 */   lbu   $t6, 0x287($sp)
/* 10B4F8 7F0D69C8 1000000C */  b     .L7F0D69FC
/* 10B4FC 7F0D69CC AFB7003C */   sw    $s7, 0x3c($sp)
.L7F0D69D0:
/* 10B500 7F0D69D0 24010001 */  li    $at, 1
/* 10B504 7F0D69D4 15C10005 */  bne   $t6, $at, .L7F0D69EC
/* 10B508 7F0D69D8 97AF0294 */   lhu   $t7, 0x294($sp)
/* 10B50C 7F0D69DC 97AB0296 */  lhu   $t3, 0x296($sp)
/* 10B510 7F0D69E0 316800FF */  andi  $t0, $t3, 0xff
/* 10B514 7F0D69E4 10000003 */  b     .L7F0D69F4
/* 10B518 7F0D69E8 AFA80038 */   sw    $t0, 0x38($sp)
.L7F0D69EC:
/* 10B51C 7F0D69EC 31F900FF */  andi  $t9, $t7, 0xff
/* 10B520 7F0D69F0 AFB90038 */  sw    $t9, 0x38($sp)
.L7F0D69F4:
/* 10B524 7F0D69F4 8FB80038 */  lw    $t8, 0x38($sp)
/* 10B528 7F0D69F8 AFB8003C */  sw    $t8, 0x3c($sp)
.L7F0D69FC:
/* 10B52C 7F0D69FC 8FAC003C */  lw    $t4, 0x3c($sp)
/* 10B530 7F0D6A00 97AA0294 */  lhu   $t2, 0x294($sp)
/* 10B534 7F0D6A04 000C6A00 */  sll   $t5, $t4, 8
/* 10B538 7F0D6A08 314900FF */  andi  $t1, $t2, 0xff
/* 10B53C 7F0D6A0C 01A97025 */  or    $t6, $t5, $t1
/* 10B540 7F0D6A10 10002F7A */  b     .L7F0E27FC
/* 10B544 7F0D6A14 A7AE0294 */   sh    $t6, 0x294($sp)
spectrum_op_66:
/* 10B548 7F0D6A18 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10B54C 7F0D6A1C 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10B550 7F0D6A20 0016CA00 */  sll   $t9, $s6, 8
/* 10B554 7F0D6A24 25680007 */  addiu $t0, $t3, 7
/* 10B558 7F0D6A28 15E00004 */  bnez  $t7, .L7F0D6A3C
/* 10B55C 7F0D6A2C AFA8028C */   sw    $t0, 0x28c($sp)
/* 10B560 7F0D6A30 0337C025 */  or    $t8, $t9, $s7
/* 10B564 7F0D6A34 10000016 */  b     .L7F0D6A90
/* 10B568 7F0D6A38 A7B80204 */   sh    $t8, 0x204($sp)
.L7F0D6A3C:
/* 10B56C 7F0D6A3C 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10B570 7F0D6A40 93AD0287 */  lbu   $t5, 0x287($sp)
/* 10B574 7F0D6A44 24010001 */  li    $at, 1
/* 10B578 7F0D6A48 258A0008 */  addiu $t2, $t4, 8
/* 10B57C 7F0D6A4C 15A10004 */  bne   $t5, $at, .L7F0D6A60
/* 10B580 7F0D6A50 AFAA028C */   sw    $t2, 0x28c($sp)
/* 10B584 7F0D6A54 97A90296 */  lhu   $t1, 0x296($sp)
/* 10B588 7F0D6A58 10000003 */  b     .L7F0D6A68
/* 10B58C 7F0D6A5C AFA90048 */   sw    $t1, 0x48($sp)
.L7F0D6A60:
/* 10B590 7F0D6A60 97AE0294 */  lhu   $t6, 0x294($sp)
/* 10B594 7F0D6A64 AFAE0048 */  sw    $t6, 0x48($sp)
.L7F0D6A68:
/* 10B598 7F0D6A68 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10B59C 7F0D6A6C 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10B5A0 7F0D6A70 97AB0298 */  lhu   $t3, 0x298($sp)
/* 10B5A4 7F0D6A74 8FB80048 */  lw    $t8, 0x48($sp)
/* 10B5A8 7F0D6A78 01687821 */  addu  $t7, $t3, $t0
/* 10B5AC 7F0D6A7C 81F90000 */  lb    $t9, ($t7)
/* 10B5B0 7F0D6A80 256A0001 */  addiu $t2, $t3, 1
/* 10B5B4 7F0D6A84 A7AA0298 */  sh    $t2, 0x298($sp)
/* 10B5B8 7F0D6A88 03386021 */  addu  $t4, $t9, $t8
/* 10B5BC 7F0D6A8C A7AC0204 */  sh    $t4, 0x204($sp)
.L7F0D6A90:
/* 10B5C0 7F0D6A90 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10B5C4 7F0D6A94 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10B5C8 7F0D6A98 97AD0204 */  lhu   $t5, 0x204($sp)
/* 10B5CC 7F0D6A9C 01A97021 */  addu  $t6, $t5, $t1
/* 10B5D0 7F0D6AA0 10002F56 */  b     .L7F0E27FC
/* 10B5D4 7F0D6AA4 91D60000 */   lbu   $s6, ($t6)
spectrum_op_67:
/* 10B5D8 7F0D6AA8 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10B5DC 7F0D6AAC 93B90287 */  lbu   $t9, 0x287($sp)
/* 10B5E0 7F0D6AB0 93B80287 */  lbu   $t8, 0x287($sp)
/* 10B5E4 7F0D6AB4 250F0004 */  addiu $t7, $t0, 4
/* 10B5E8 7F0D6AB8 17200003 */  bnez  $t9, .L7F0D6AC8
/* 10B5EC 7F0D6ABC AFAF028C */   sw    $t7, 0x28c($sp)
/* 10B5F0 7F0D6AC0 10002F4E */  b     .L7F0E27FC
/* 10B5F4 7F0D6AC4 321600FF */   andi  $s6, $s0, 0xff
.L7F0D6AC8:
/* 10B5F8 7F0D6AC8 24010001 */  li    $at, 1
/* 10B5FC 7F0D6ACC 17010007 */  bne   $t8, $at, .L7F0D6AEC
/* 10B600 7F0D6AD0 97A90294 */   lhu   $t1, 0x294($sp)
/* 10B604 7F0D6AD4 97AC0296 */  lhu   $t4, 0x296($sp)
/* 10B608 7F0D6AD8 00105200 */  sll   $t2, $s0, 8
/* 10B60C 7F0D6ADC 318B00FF */  andi  $t3, $t4, 0xff
/* 10B610 7F0D6AE0 016A6825 */  or    $t5, $t3, $t2
/* 10B614 7F0D6AE4 10002F45 */  b     .L7F0E27FC
/* 10B618 7F0D6AE8 A7AD0296 */   sh    $t5, 0x296($sp)
.L7F0D6AEC:
/* 10B61C 7F0D6AEC 312E00FF */  andi  $t6, $t1, 0xff
/* 10B620 7F0D6AF0 00104200 */  sll   $t0, $s0, 8
/* 10B624 7F0D6AF4 01C87825 */  or    $t7, $t6, $t0
/* 10B628 7F0D6AF8 10002F40 */  b     .L7F0E27FC
/* 10B62C 7F0D6AFC A7AF0294 */   sh    $t7, 0x294($sp)
spectrum_op_68:
/* 10B630 7F0D6B00 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10B634 7F0D6B04 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10B638 7F0D6B08 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10B63C 7F0D6B0C 27380004 */  addiu $t8, $t9, 4
/* 10B640 7F0D6B10 15800003 */  bnez  $t4, .L7F0D6B20
/* 10B644 7F0D6B14 AFB8028C */   sw    $t8, 0x28c($sp)
/* 10B648 7F0D6B18 10002F38 */  b     .L7F0E27FC
/* 10B64C 7F0D6B1C 325700FF */   andi  $s7, $s2, 0xff
.L7F0D6B20:
/* 10B650 7F0D6B20 24010001 */  li    $at, 1
/* 10B654 7F0D6B24 15610006 */  bne   $t3, $at, .L7F0D6B40
/* 10B658 7F0D6B28 97AE0294 */   lhu   $t6, 0x294($sp)
/* 10B65C 7F0D6B2C 97AA0296 */  lhu   $t2, 0x296($sp)
/* 10B660 7F0D6B30 314DFF00 */  andi  $t5, $t2, 0xff00
/* 10B664 7F0D6B34 01B24825 */  or    $t1, $t5, $s2
/* 10B668 7F0D6B38 10002F30 */  b     .L7F0E27FC
/* 10B66C 7F0D6B3C A7A90296 */   sh    $t1, 0x296($sp)
.L7F0D6B40:
/* 10B670 7F0D6B40 31C8FF00 */  andi  $t0, $t6, 0xff00
/* 10B674 7F0D6B44 01127825 */  or    $t7, $t0, $s2
/* 10B678 7F0D6B48 10002F2C */  b     .L7F0E27FC
/* 10B67C 7F0D6B4C A7AF0294 */   sh    $t7, 0x294($sp)
spectrum_op_69:
/* 10B680 7F0D6B50 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10B684 7F0D6B54 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10B688 7F0D6B58 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10B68C 7F0D6B5C 27380004 */  addiu $t8, $t9, 4
/* 10B690 7F0D6B60 15800003 */  bnez  $t4, .L7F0D6B70
/* 10B694 7F0D6B64 AFB8028C */   sw    $t8, 0x28c($sp)
/* 10B698 7F0D6B68 10002F24 */  b     .L7F0E27FC
/* 10B69C 7F0D6B6C 327700FF */   andi  $s7, $s3, 0xff
.L7F0D6B70:
/* 10B6A0 7F0D6B70 24010001 */  li    $at, 1
/* 10B6A4 7F0D6B74 15610006 */  bne   $t3, $at, .L7F0D6B90
/* 10B6A8 7F0D6B78 97AE0294 */   lhu   $t6, 0x294($sp)
/* 10B6AC 7F0D6B7C 97AA0296 */  lhu   $t2, 0x296($sp)
/* 10B6B0 7F0D6B80 314DFF00 */  andi  $t5, $t2, 0xff00
/* 10B6B4 7F0D6B84 01B34825 */  or    $t1, $t5, $s3
/* 10B6B8 7F0D6B88 10002F1C */  b     .L7F0E27FC
/* 10B6BC 7F0D6B8C A7A90296 */   sh    $t1, 0x296($sp)
.L7F0D6B90:
/* 10B6C0 7F0D6B90 31C8FF00 */  andi  $t0, $t6, 0xff00
/* 10B6C4 7F0D6B94 01137825 */  or    $t7, $t0, $s3
/* 10B6C8 7F0D6B98 10002F18 */  b     .L7F0E27FC
/* 10B6CC 7F0D6B9C A7AF0294 */   sh    $t7, 0x294($sp)
spectrum_op_6A:
/* 10B6D0 7F0D6BA0 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10B6D4 7F0D6BA4 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10B6D8 7F0D6BA8 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10B6DC 7F0D6BAC 27380004 */  addiu $t8, $t9, 4
/* 10B6E0 7F0D6BB0 15800003 */  bnez  $t4, .L7F0D6BC0
/* 10B6E4 7F0D6BB4 AFB8028C */   sw    $t8, 0x28c($sp)
/* 10B6E8 7F0D6BB8 10002F10 */  b     .L7F0E27FC
/* 10B6EC 7F0D6BBC 329700FF */   andi  $s7, $s4, 0xff
.L7F0D6BC0:
/* 10B6F0 7F0D6BC0 24010001 */  li    $at, 1
/* 10B6F4 7F0D6BC4 15610006 */  bne   $t3, $at, .L7F0D6BE0
/* 10B6F8 7F0D6BC8 97AE0294 */   lhu   $t6, 0x294($sp)
/* 10B6FC 7F0D6BCC 97AA0296 */  lhu   $t2, 0x296($sp)
/* 10B700 7F0D6BD0 314DFF00 */  andi  $t5, $t2, 0xff00
/* 10B704 7F0D6BD4 01B44825 */  or    $t1, $t5, $s4
/* 10B708 7F0D6BD8 10002F08 */  b     .L7F0E27FC
/* 10B70C 7F0D6BDC A7A90296 */   sh    $t1, 0x296($sp)
.L7F0D6BE0:
/* 10B710 7F0D6BE0 31C8FF00 */  andi  $t0, $t6, 0xff00
/* 10B714 7F0D6BE4 01147825 */  or    $t7, $t0, $s4
/* 10B718 7F0D6BE8 10002F04 */  b     .L7F0E27FC
/* 10B71C 7F0D6BEC A7AF0294 */   sh    $t7, 0x294($sp)
spectrum_op_6B:
/* 10B720 7F0D6BF0 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10B724 7F0D6BF4 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10B728 7F0D6BF8 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10B72C 7F0D6BFC 27380004 */  addiu $t8, $t9, 4
/* 10B730 7F0D6C00 15800003 */  bnez  $t4, .L7F0D6C10
/* 10B734 7F0D6C04 AFB8028C */   sw    $t8, 0x28c($sp)
/* 10B738 7F0D6C08 10002EFC */  b     .L7F0E27FC
/* 10B73C 7F0D6C0C 32B700FF */   andi  $s7, $s5, 0xff
.L7F0D6C10:
/* 10B740 7F0D6C10 24010001 */  li    $at, 1
/* 10B744 7F0D6C14 15610006 */  bne   $t3, $at, .L7F0D6C30
/* 10B748 7F0D6C18 97AE0294 */   lhu   $t6, 0x294($sp)
/* 10B74C 7F0D6C1C 97AA0296 */  lhu   $t2, 0x296($sp)
/* 10B750 7F0D6C20 314DFF00 */  andi  $t5, $t2, 0xff00
/* 10B754 7F0D6C24 01B54825 */  or    $t1, $t5, $s5
/* 10B758 7F0D6C28 10002EF4 */  b     .L7F0E27FC
/* 10B75C 7F0D6C2C A7A90296 */   sh    $t1, 0x296($sp)
.L7F0D6C30:
/* 10B760 7F0D6C30 31C8FF00 */  andi  $t0, $t6, 0xff00
/* 10B764 7F0D6C34 01157825 */  or    $t7, $t0, $s5
/* 10B768 7F0D6C38 10002EF0 */  b     .L7F0E27FC
/* 10B76C 7F0D6C3C A7AF0294 */   sh    $t7, 0x294($sp)
spectrum_op_6C:
/* 10B770 7F0D6C40 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10B774 7F0D6C44 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10B778 7F0D6C48 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10B77C 7F0D6C4C 27380004 */  addiu $t8, $t9, 4
/* 10B780 7F0D6C50 2D8B0001 */  sltiu $t3, $t4, 1
/* 10B784 7F0D6C54 11600010 */  beqz  $t3, .L7F0D6C98
/* 10B788 7F0D6C58 AFB8028C */   sw    $t8, 0x28c($sp)
/* 10B78C 7F0D6C5C 11600003 */  beqz  $t3, .L7F0D6C6C
/* 10B790 7F0D6C60 93AA0287 */   lbu   $t2, 0x287($sp)
/* 10B794 7F0D6C64 10002EE5 */  b     .L7F0E27FC
/* 10B798 7F0D6C68 32D700FF */   andi  $s7, $s6, 0xff
.L7F0D6C6C:
/* 10B79C 7F0D6C6C 24010001 */  li    $at, 1
/* 10B7A0 7F0D6C70 15410005 */  bne   $t2, $at, .L7F0D6C88
/* 10B7A4 7F0D6C74 97AE0294 */   lhu   $t6, 0x294($sp)
/* 10B7A8 7F0D6C78 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10B7AC 7F0D6C7C 000D4A03 */  sra   $t1, $t5, 8
/* 10B7B0 7F0D6C80 10000003 */  b     .L7F0D6C90
/* 10B7B4 7F0D6C84 AFA90048 */   sw    $t1, 0x48($sp)
.L7F0D6C88:
/* 10B7B8 7F0D6C88 000E4203 */  sra   $t0, $t6, 8
/* 10B7BC 7F0D6C8C AFA80048 */  sw    $t0, 0x48($sp)
.L7F0D6C90:
/* 10B7C0 7F0D6C90 10002EDA */  b     .L7F0E27FC
/* 10B7C4 7F0D6C94 93B7004B */   lbu   $s7, 0x4b($sp)
.L7F0D6C98:
/* 10B7C8 7F0D6C98 24010001 */  li    $at, 1
/* 10B7CC 7F0D6C9C 15E10016 */  bne   $t7, $at, .L7F0D6CF8
/* 10B7D0 7F0D6CA0 93B90287 */   lbu   $t9, 0x287($sp)
/* 10B7D4 7F0D6CA4 15E00003 */  bnez  $t7, .L7F0D6CB4
/* 10B7D8 7F0D6CA8 93B90287 */   lbu   $t9, 0x287($sp)
/* 10B7DC 7F0D6CAC 1000000C */  b     .L7F0D6CE0
/* 10B7E0 7F0D6CB0 AFB60044 */   sw    $s6, 0x44($sp)
.L7F0D6CB4:
/* 10B7E4 7F0D6CB4 24010001 */  li    $at, 1
/* 10B7E8 7F0D6CB8 17210005 */  bne   $t9, $at, .L7F0D6CD0
/* 10B7EC 7F0D6CBC 97AB0294 */   lhu   $t3, 0x294($sp)
/* 10B7F0 7F0D6CC0 97B80296 */  lhu   $t8, 0x296($sp)
/* 10B7F4 7F0D6CC4 00186203 */  sra   $t4, $t8, 8
/* 10B7F8 7F0D6CC8 10000003 */  b     .L7F0D6CD8
/* 10B7FC 7F0D6CCC AFAC0040 */   sw    $t4, 0x40($sp)
.L7F0D6CD0:
/* 10B800 7F0D6CD0 000B5203 */  sra   $t2, $t3, 8
/* 10B804 7F0D6CD4 AFAA0040 */  sw    $t2, 0x40($sp)
.L7F0D6CD8:
/* 10B808 7F0D6CD8 8FAD0040 */  lw    $t5, 0x40($sp)
/* 10B80C 7F0D6CDC AFAD0044 */  sw    $t5, 0x44($sp)
.L7F0D6CE0:
/* 10B810 7F0D6CE0 97AE0296 */  lhu   $t6, 0x296($sp)
/* 10B814 7F0D6CE4 8FA90044 */  lw    $t1, 0x44($sp)
/* 10B818 7F0D6CE8 31C8FF00 */  andi  $t0, $t6, 0xff00
/* 10B81C 7F0D6CEC 01287825 */  or    $t7, $t1, $t0
/* 10B820 7F0D6CF0 10002EC2 */  b     .L7F0E27FC
/* 10B824 7F0D6CF4 A7AF0296 */   sh    $t7, 0x296($sp)
.L7F0D6CF8:
/* 10B828 7F0D6CF8 17200003 */  bnez  $t9, .L7F0D6D08
/* 10B82C 7F0D6CFC 93B80287 */   lbu   $t8, 0x287($sp)
/* 10B830 7F0D6D00 1000000C */  b     .L7F0D6D34
/* 10B834 7F0D6D04 AFB6003C */   sw    $s6, 0x3c($sp)
.L7F0D6D08:
/* 10B838 7F0D6D08 24010001 */  li    $at, 1
/* 10B83C 7F0D6D0C 17010005 */  bne   $t8, $at, .L7F0D6D24
/* 10B840 7F0D6D10 97AA0294 */   lhu   $t2, 0x294($sp)
/* 10B844 7F0D6D14 97AC0296 */  lhu   $t4, 0x296($sp)
/* 10B848 7F0D6D18 000C5A03 */  sra   $t3, $t4, 8
/* 10B84C 7F0D6D1C 10000003 */  b     .L7F0D6D2C
/* 10B850 7F0D6D20 AFAB0038 */   sw    $t3, 0x38($sp)
.L7F0D6D24:
/* 10B854 7F0D6D24 000A6A03 */  sra   $t5, $t2, 8
/* 10B858 7F0D6D28 AFAD0038 */  sw    $t5, 0x38($sp)
.L7F0D6D2C:
/* 10B85C 7F0D6D2C 8FAE0038 */  lw    $t6, 0x38($sp)
/* 10B860 7F0D6D30 AFAE003C */  sw    $t6, 0x3c($sp)
.L7F0D6D34:
/* 10B864 7F0D6D34 97A80294 */  lhu   $t0, 0x294($sp)
/* 10B868 7F0D6D38 8FA9003C */  lw    $t1, 0x3c($sp)
/* 10B86C 7F0D6D3C 310FFF00 */  andi  $t7, $t0, 0xff00
/* 10B870 7F0D6D40 012FC825 */  or    $t9, $t1, $t7
/* 10B874 7F0D6D44 10002EAD */  b     .L7F0E27FC
/* 10B878 7F0D6D48 A7B90294 */   sh    $t9, 0x294($sp)
spectrum_op_6D:
/* 10B87C 7F0D6D4C 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10B880 7F0D6D50 270C0004 */  addiu $t4, $t8, 4
/* 10B884 7F0D6D54 10002EA9 */  b     .L7F0E27FC
/* 10B888 7F0D6D58 AFAC028C */   sw    $t4, 0x28c($sp)
spectrum_op_6E:
/* 10B88C 7F0D6D5C 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10B890 7F0D6D60 93AD0287 */  lbu   $t5, 0x287($sp)
/* 10B894 7F0D6D64 00167200 */  sll   $t6, $s6, 8
/* 10B898 7F0D6D68 256A0007 */  addiu $t2, $t3, 7
/* 10B89C 7F0D6D6C 15A00004 */  bnez  $t5, .L7F0D6D80
/* 10B8A0 7F0D6D70 AFAA028C */   sw    $t2, 0x28c($sp)
/* 10B8A4 7F0D6D74 01D74025 */  or    $t0, $t6, $s7
/* 10B8A8 7F0D6D78 10000016 */  b     .L7F0D6DD4
/* 10B8AC 7F0D6D7C A7A80202 */   sh    $t0, 0x202($sp)
.L7F0D6D80:
/* 10B8B0 7F0D6D80 8FA9028C */  lw    $t1, 0x28c($sp)
/* 10B8B4 7F0D6D84 93B90287 */  lbu   $t9, 0x287($sp)
/* 10B8B8 7F0D6D88 24010001 */  li    $at, 1
/* 10B8BC 7F0D6D8C 252F0008 */  addiu $t7, $t1, 8
/* 10B8C0 7F0D6D90 17210004 */  bne   $t9, $at, .L7F0D6DA4
/* 10B8C4 7F0D6D94 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10B8C8 7F0D6D98 97B80296 */  lhu   $t8, 0x296($sp)
/* 10B8CC 7F0D6D9C 10000003 */  b     .L7F0D6DAC
/* 10B8D0 7F0D6DA0 AFB80048 */   sw    $t8, 0x48($sp)
.L7F0D6DA4:
/* 10B8D4 7F0D6DA4 97AC0294 */  lhu   $t4, 0x294($sp)
/* 10B8D8 7F0D6DA8 AFAC0048 */  sw    $t4, 0x48($sp)
.L7F0D6DAC:
/* 10B8DC 7F0D6DAC 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 10B8E0 7F0D6DB0 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 10B8E4 7F0D6DB4 97AB0298 */  lhu   $t3, 0x298($sp)
/* 10B8E8 7F0D6DB8 8FA80048 */  lw    $t0, 0x48($sp)
/* 10B8EC 7F0D6DBC 016A6821 */  addu  $t5, $t3, $t2
/* 10B8F0 7F0D6DC0 81AE0000 */  lb    $t6, ($t5)
/* 10B8F4 7F0D6DC4 256F0001 */  addiu $t7, $t3, 1
/* 10B8F8 7F0D6DC8 A7AF0298 */  sh    $t7, 0x298($sp)
/* 10B8FC 7F0D6DCC 01C84821 */  addu  $t1, $t6, $t0
/* 10B900 7F0D6DD0 A7A90202 */  sh    $t1, 0x202($sp)
.L7F0D6DD4:
/* 10B904 7F0D6DD4 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 10B908 7F0D6DD8 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10B90C 7F0D6DDC 97B90202 */  lhu   $t9, 0x202($sp)
/* 10B910 7F0D6DE0 03386021 */  addu  $t4, $t9, $t8
/* 10B914 7F0D6DE4 10002E85 */  b     .L7F0E27FC
/* 10B918 7F0D6DE8 91970000 */   lbu   $s7, ($t4)
spectrum_op_6F:
/* 10B91C 7F0D6DEC 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10B920 7F0D6DF0 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10B924 7F0D6DF4 93A80287 */  lbu   $t0, 0x287($sp)
/* 10B928 7F0D6DF8 254D0004 */  addiu $t5, $t2, 4
/* 10B92C 7F0D6DFC 15C00003 */  bnez  $t6, .L7F0D6E0C
/* 10B930 7F0D6E00 AFAD028C */   sw    $t5, 0x28c($sp)
/* 10B934 7F0D6E04 10002E7D */  b     .L7F0E27FC
/* 10B938 7F0D6E08 321700FF */   andi  $s7, $s0, 0xff
.L7F0D6E0C:
/* 10B93C 7F0D6E0C 24010001 */  li    $at, 1
/* 10B940 7F0D6E10 15010006 */  bne   $t0, $at, .L7F0D6E2C
/* 10B944 7F0D6E14 97B90294 */   lhu   $t9, 0x294($sp)
/* 10B948 7F0D6E18 97A90296 */  lhu   $t1, 0x296($sp)
/* 10B94C 7F0D6E1C 312BFF00 */  andi  $t3, $t1, 0xff00
/* 10B950 7F0D6E20 01707825 */  or    $t7, $t3, $s0
/* 10B954 7F0D6E24 10002E75 */  b     .L7F0E27FC
/* 10B958 7F0D6E28 A7AF0296 */   sh    $t7, 0x296($sp)
.L7F0D6E2C:
/* 10B95C 7F0D6E2C 3338FF00 */  andi  $t8, $t9, 0xff00
/* 10B960 7F0D6E30 03106025 */  or    $t4, $t8, $s0
/* 10B964 7F0D6E34 10002E71 */  b     .L7F0E27FC
/* 10B968 7F0D6E38 A7AC0294 */   sh    $t4, 0x294($sp)
spectrum_op_70:
/* 10B96C 7F0D6E3C 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10B970 7F0D6E40 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10B974 7F0D6E44 00164200 */  sll   $t0, $s6, 8
/* 10B978 7F0D6E48 254D0007 */  addiu $t5, $t2, 7
/* 10B97C 7F0D6E4C 15C00004 */  bnez  $t6, .L7F0D6E60
/* 10B980 7F0D6E50 AFAD028C */   sw    $t5, 0x28c($sp)
/* 10B984 7F0D6E54 01174825 */  or    $t1, $t0, $s7
/* 10B988 7F0D6E58 10000016 */  b     .L7F0D6EB4
/* 10B98C 7F0D6E5C A7A90200 */   sh    $t1, 0x200($sp)
.L7F0D6E60:
/* 10B990 7F0D6E60 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10B994 7F0D6E64 93B90287 */  lbu   $t9, 0x287($sp)
/* 10B998 7F0D6E68 24010001 */  li    $at, 1
/* 10B99C 7F0D6E6C 256F0008 */  addiu $t7, $t3, 8
/* 10B9A0 7F0D6E70 17210004 */  bne   $t9, $at, .L7F0D6E84
/* 10B9A4 7F0D6E74 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10B9A8 7F0D6E78 97B80296 */  lhu   $t8, 0x296($sp)
/* 10B9AC 7F0D6E7C 10000003 */  b     .L7F0D6E8C
/* 10B9B0 7F0D6E80 AFB80048 */   sw    $t8, 0x48($sp)
.L7F0D6E84:
/* 10B9B4 7F0D6E84 97AC0294 */  lhu   $t4, 0x294($sp)
/* 10B9B8 7F0D6E88 AFAC0048 */  sw    $t4, 0x48($sp)
.L7F0D6E8C:
/* 10B9BC 7F0D6E8C 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 10B9C0 7F0D6E90 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10B9C4 7F0D6E94 97AA0298 */  lhu   $t2, 0x298($sp)
/* 10B9C8 7F0D6E98 8FA90048 */  lw    $t1, 0x48($sp)
/* 10B9CC 7F0D6E9C 014D7021 */  addu  $t6, $t2, $t5
/* 10B9D0 7F0D6EA0 81C80000 */  lb    $t0, ($t6)
/* 10B9D4 7F0D6EA4 254F0001 */  addiu $t7, $t2, 1
/* 10B9D8 7F0D6EA8 A7AF0298 */  sh    $t7, 0x298($sp)
/* 10B9DC 7F0D6EAC 01095821 */  addu  $t3, $t0, $t1
/* 10B9E0 7F0D6EB0 A7AB0200 */  sh    $t3, 0x200($sp)
.L7F0D6EB4:
/* 10B9E4 7F0D6EB4 97B90200 */  lhu   $t9, 0x200($sp)
/* 10B9E8 7F0D6EB8 97AD0200 */  lhu   $t5, 0x200($sp)
/* 10B9EC 7F0D6EBC 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 10B9F0 7F0D6EC0 2B215B00 */  slti  $at, $t9, 0x5b00
/* 10B9F4 7F0D6EC4 54200006 */  bnezl $at, .L7F0D6EE0
/* 10B9F8 7F0D6EC8 29A15800 */   slti  $at, $t5, 0x5800
/* 10B9FC 7F0D6ECC 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10BA00 7F0D6ED0 03196021 */  addu  $t4, $t8, $t9
/* 10BA04 7F0D6ED4 10002E49 */  b     .L7F0E27FC
/* 10BA08 7F0D6ED8 A1920000 */   sb    $s2, ($t4)
/* 10BA0C 7F0D6EDC 29A15800 */  slti  $at, $t5, 0x5800
.L7F0D6EE0:
/* 10BA10 7F0D6EE0 1420000C */  bnez  $at, .L7F0D6F14
/* 10BA14 7F0D6EE4 97B80200 */   lhu   $t8, 0x200($sp)
/* 10BA18 7F0D6EE8 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10BA1C 7F0D6EEC 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10BA20 7F0D6EF0 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 10BA24 7F0D6EF4 24090001 */  li    $t1, 1
/* 10BA28 7F0D6EF8 01CD4021 */  addu  $t0, $t6, $t5
/* 10BA2C 7F0D6EFC A1120000 */  sb    $s2, ($t0)
/* 10BA30 7F0D6F00 97AA0200 */  lhu   $t2, 0x200($sp)
/* 10BA34 7F0D6F04 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 10BA38 7F0D6F08 016A7821 */  addu  $t7, $t3, $t2
/* 10BA3C 7F0D6F0C 10002E3B */  b     .L7F0E27FC
/* 10BA40 7F0D6F10 A1E9A800 */   sb    $t1, -0x5800($t7)
.L7F0D6F14:
/* 10BA44 7F0D6F14 2B014000 */  slti  $at, $t8, 0x4000
/* 10BA48 7F0D6F18 14202E38 */  bnez  $at, .L7F0E27FC
/* 10BA4C 7F0D6F1C 3C198009 */   lui   $t9, %hi(ptr_spectrum_roms) 
/* 10BA50 7F0D6F20 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10BA54 7F0D6F24 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 10BA58 7F0D6F28 240E0001 */  li    $t6, 1
/* 10BA5C 7F0D6F2C 03386021 */  addu  $t4, $t9, $t8
/* 10BA60 7F0D6F30 A1920000 */  sb    $s2, ($t4)
/* 10BA64 7F0D6F34 97AD0200 */  lhu   $t5, 0x200($sp)
/* 10BA68 7F0D6F38 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 10BA6C 7F0D6F3C 31A81800 */  andi  $t0, $t5, 0x1800
/* 10BA70 7F0D6F40 000858C3 */  sra   $t3, $t0, 3
/* 10BA74 7F0D6F44 31AA00FF */  andi  $t2, $t5, 0xff
/* 10BA78 7F0D6F48 016A4825 */  or    $t1, $t3, $t2
/* 10BA7C 7F0D6F4C 01E9C821 */  addu  $t9, $t7, $t1
/* 10BA80 7F0D6F50 10002E2A */  b     .L7F0E27FC
/* 10BA84 7F0D6F54 A32E0000 */   sb    $t6, ($t9)
spectrum_op_71:
/* 10BA88 7F0D6F58 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10BA8C 7F0D6F5C 93A80287 */  lbu   $t0, 0x287($sp)
/* 10BA90 7F0D6F60 00166A00 */  sll   $t5, $s6, 8
/* 10BA94 7F0D6F64 270C0007 */  addiu $t4, $t8, 7
/* 10BA98 7F0D6F68 15000004 */  bnez  $t0, .L7F0D6F7C
/* 10BA9C 7F0D6F6C AFAC028C */   sw    $t4, 0x28c($sp)
/* 10BAA0 7F0D6F70 01B75825 */  or    $t3, $t5, $s7
/* 10BAA4 7F0D6F74 10000016 */  b     .L7F0D6FD0
/* 10BAA8 7F0D6F78 A7AB01FE */   sh    $t3, 0x1fe($sp)
.L7F0D6F7C:
/* 10BAAC 7F0D6F7C 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10BAB0 7F0D6F80 93A90287 */  lbu   $t1, 0x287($sp)
/* 10BAB4 7F0D6F84 24010001 */  li    $at, 1
/* 10BAB8 7F0D6F88 254F0008 */  addiu $t7, $t2, 8
/* 10BABC 7F0D6F8C 15210004 */  bne   $t1, $at, .L7F0D6FA0
/* 10BAC0 7F0D6F90 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10BAC4 7F0D6F94 97AE0296 */  lhu   $t6, 0x296($sp)
/* 10BAC8 7F0D6F98 10000003 */  b     .L7F0D6FA8
/* 10BACC 7F0D6F9C AFAE0048 */   sw    $t6, 0x48($sp)
.L7F0D6FA0:
/* 10BAD0 7F0D6FA0 97B90294 */  lhu   $t9, 0x294($sp)
/* 10BAD4 7F0D6FA4 AFB90048 */  sw    $t9, 0x48($sp)
.L7F0D6FA8:
/* 10BAD8 7F0D6FA8 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 10BADC 7F0D6FAC 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 10BAE0 7F0D6FB0 97B80298 */  lhu   $t8, 0x298($sp)
/* 10BAE4 7F0D6FB4 8FAB0048 */  lw    $t3, 0x48($sp)
/* 10BAE8 7F0D6FB8 030C4021 */  addu  $t0, $t8, $t4
/* 10BAEC 7F0D6FBC 810D0000 */  lb    $t5, ($t0)
/* 10BAF0 7F0D6FC0 270F0001 */  addiu $t7, $t8, 1
/* 10BAF4 7F0D6FC4 A7AF0298 */  sh    $t7, 0x298($sp)
/* 10BAF8 7F0D6FC8 01AB5021 */  addu  $t2, $t5, $t3
/* 10BAFC 7F0D6FCC A7AA01FE */  sh    $t2, 0x1fe($sp)
.L7F0D6FD0:
/* 10BB00 7F0D6FD0 97A901FE */  lhu   $t1, 0x1fe($sp)
/* 10BB04 7F0D6FD4 97AC01FE */  lhu   $t4, 0x1fe($sp)
/* 10BB08 7F0D6FD8 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10BB0C 7F0D6FDC 29215B00 */  slti  $at, $t1, 0x5b00
/* 10BB10 7F0D6FE0 54200006 */  bnezl $at, .L7F0D6FFC
/* 10BB14 7F0D6FE4 29815800 */   slti  $at, $t4, 0x5800
/* 10BB18 7F0D6FE8 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10BB1C 7F0D6FEC 01C9C821 */  addu  $t9, $t6, $t1
/* 10BB20 7F0D6FF0 10002E02 */  b     .L7F0E27FC
/* 10BB24 7F0D6FF4 A3330000 */   sb    $s3, ($t9)
/* 10BB28 7F0D6FF8 29815800 */  slti  $at, $t4, 0x5800
.L7F0D6FFC:
/* 10BB2C 7F0D6FFC 1420000C */  bnez  $at, .L7F0D7030
/* 10BB30 7F0D7000 97AE01FE */   lhu   $t6, 0x1fe($sp)
/* 10BB34 7F0D7004 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10BB38 7F0D7008 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10BB3C 7F0D700C 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 10BB40 7F0D7010 240B0001 */  li    $t3, 1
/* 10BB44 7F0D7014 010C6821 */  addu  $t5, $t0, $t4
/* 10BB48 7F0D7018 A1B30000 */  sb    $s3, ($t5)
/* 10BB4C 7F0D701C 97B801FE */  lhu   $t8, 0x1fe($sp)
/* 10BB50 7F0D7020 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 10BB54 7F0D7024 01587821 */  addu  $t7, $t2, $t8
/* 10BB58 7F0D7028 10002DF4 */  b     .L7F0E27FC
/* 10BB5C 7F0D702C A1EBA800 */   sb    $t3, -0x5800($t7)
.L7F0D7030:
/* 10BB60 7F0D7030 29C14000 */  slti  $at, $t6, 0x4000
/* 10BB64 7F0D7034 14202DF1 */  bnez  $at, .L7F0E27FC
/* 10BB68 7F0D7038 3C098009 */   lui   $t1, %hi(ptr_spectrum_roms) 
/* 10BB6C 7F0D703C 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10BB70 7F0D7040 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 10BB74 7F0D7044 24080001 */  li    $t0, 1
/* 10BB78 7F0D7048 012EC821 */  addu  $t9, $t1, $t6
/* 10BB7C 7F0D704C A3330000 */  sb    $s3, ($t9)
/* 10BB80 7F0D7050 97AC01FE */  lhu   $t4, 0x1fe($sp)
/* 10BB84 7F0D7054 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 10BB88 7F0D7058 318D1800 */  andi  $t5, $t4, 0x1800
/* 10BB8C 7F0D705C 000D50C3 */  sra   $t2, $t5, 3
/* 10BB90 7F0D7060 319800FF */  andi  $t8, $t4, 0xff
/* 10BB94 7F0D7064 01585825 */  or    $t3, $t2, $t8
/* 10BB98 7F0D7068 01EB4821 */  addu  $t1, $t7, $t3
/* 10BB9C 7F0D706C 10002DE3 */  b     .L7F0E27FC
/* 10BBA0 7F0D7070 A1280000 */   sb    $t0, ($t1)
spectrum_op_72:
/* 10BBA4 7F0D7074 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10BBA8 7F0D7078 93AD0287 */  lbu   $t5, 0x287($sp)
/* 10BBAC 7F0D707C 00166200 */  sll   $t4, $s6, 8
/* 10BBB0 7F0D7080 25D90007 */  addiu $t9, $t6, 7
/* 10BBB4 7F0D7084 15A00004 */  bnez  $t5, .L7F0D7098
/* 10BBB8 7F0D7088 AFB9028C */   sw    $t9, 0x28c($sp)
/* 10BBBC 7F0D708C 01975025 */  or    $t2, $t4, $s7
/* 10BBC0 7F0D7090 10000016 */  b     .L7F0D70EC
/* 10BBC4 7F0D7094 A7AA01FC */   sh    $t2, 0x1fc($sp)
.L7F0D7098:
/* 10BBC8 7F0D7098 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10BBCC 7F0D709C 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10BBD0 7F0D70A0 24010001 */  li    $at, 1
/* 10BBD4 7F0D70A4 270F0008 */  addiu $t7, $t8, 8
/* 10BBD8 7F0D70A8 15610004 */  bne   $t3, $at, .L7F0D70BC
/* 10BBDC 7F0D70AC AFAF028C */   sw    $t7, 0x28c($sp)
/* 10BBE0 7F0D70B0 97A80296 */  lhu   $t0, 0x296($sp)
/* 10BBE4 7F0D70B4 10000003 */  b     .L7F0D70C4
/* 10BBE8 7F0D70B8 AFA80048 */   sw    $t0, 0x48($sp)
.L7F0D70BC:
/* 10BBEC 7F0D70BC 97A90294 */  lhu   $t1, 0x294($sp)
/* 10BBF0 7F0D70C0 AFA90048 */  sw    $t1, 0x48($sp)
.L7F0D70C4:
/* 10BBF4 7F0D70C4 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10BBF8 7F0D70C8 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10BBFC 7F0D70CC 97AE0298 */  lhu   $t6, 0x298($sp)
/* 10BC00 7F0D70D0 8FAA0048 */  lw    $t2, 0x48($sp)
/* 10BC04 7F0D70D4 01D96821 */  addu  $t5, $t6, $t9
/* 10BC08 7F0D70D8 81AC0000 */  lb    $t4, ($t5)
/* 10BC0C 7F0D70DC 25CF0001 */  addiu $t7, $t6, 1
/* 10BC10 7F0D70E0 A7AF0298 */  sh    $t7, 0x298($sp)
/* 10BC14 7F0D70E4 018AC021 */  addu  $t8, $t4, $t2
/* 10BC18 7F0D70E8 A7B801FC */  sh    $t8, 0x1fc($sp)
.L7F0D70EC:
/* 10BC1C 7F0D70EC 97AB01FC */  lhu   $t3, 0x1fc($sp)
/* 10BC20 7F0D70F0 97B901FC */  lhu   $t9, 0x1fc($sp)
/* 10BC24 7F0D70F4 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10BC28 7F0D70F8 29615B00 */  slti  $at, $t3, 0x5b00
/* 10BC2C 7F0D70FC 54200006 */  bnezl $at, .L7F0D7118
/* 10BC30 7F0D7100 2B215800 */   slti  $at, $t9, 0x5800
/* 10BC34 7F0D7104 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10BC38 7F0D7108 010B4821 */  addu  $t1, $t0, $t3
/* 10BC3C 7F0D710C 10002DBB */  b     .L7F0E27FC
/* 10BC40 7F0D7110 A1340000 */   sb    $s4, ($t1)
/* 10BC44 7F0D7114 2B215800 */  slti  $at, $t9, 0x5800
.L7F0D7118:
/* 10BC48 7F0D7118 1420000C */  bnez  $at, .L7F0D714C
/* 10BC4C 7F0D711C 97A801FC */   lhu   $t0, 0x1fc($sp)
/* 10BC50 7F0D7120 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 10BC54 7F0D7124 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10BC58 7F0D7128 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 10BC5C 7F0D712C 240A0001 */  li    $t2, 1
/* 10BC60 7F0D7130 01B96021 */  addu  $t4, $t5, $t9
/* 10BC64 7F0D7134 A1940000 */  sb    $s4, ($t4)
/* 10BC68 7F0D7138 97AE01FC */  lhu   $t6, 0x1fc($sp)
/* 10BC6C 7F0D713C 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 10BC70 7F0D7140 030E7821 */  addu  $t7, $t8, $t6
/* 10BC74 7F0D7144 10002DAD */  b     .L7F0E27FC
/* 10BC78 7F0D7148 A1EAA800 */   sb    $t2, -0x5800($t7)
.L7F0D714C:
/* 10BC7C 7F0D714C 29014000 */  slti  $at, $t0, 0x4000
/* 10BC80 7F0D7150 14202DAA */  bnez  $at, .L7F0E27FC
/* 10BC84 7F0D7154 3C0B8009 */   lui   $t3, %hi(ptr_spectrum_roms) 
/* 10BC88 7F0D7158 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10BC8C 7F0D715C 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 10BC90 7F0D7160 240D0001 */  li    $t5, 1
/* 10BC94 7F0D7164 01684821 */  addu  $t1, $t3, $t0
/* 10BC98 7F0D7168 A1340000 */  sb    $s4, ($t1)
/* 10BC9C 7F0D716C 97B901FC */  lhu   $t9, 0x1fc($sp)
/* 10BCA0 7F0D7170 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 10BCA4 7F0D7174 332C1800 */  andi  $t4, $t9, 0x1800
/* 10BCA8 7F0D7178 000CC0C3 */  sra   $t8, $t4, 3
/* 10BCAC 7F0D717C 332E00FF */  andi  $t6, $t9, 0xff
/* 10BCB0 7F0D7180 030E5025 */  or    $t2, $t8, $t6
/* 10BCB4 7F0D7184 01EA5821 */  addu  $t3, $t7, $t2
/* 10BCB8 7F0D7188 10002D9C */  b     .L7F0E27FC
/* 10BCBC 7F0D718C A16D0000 */   sb    $t5, ($t3)
spectrum_op_73:
/* 10BCC0 7F0D7190 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10BCC4 7F0D7194 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10BCC8 7F0D7198 0016CA00 */  sll   $t9, $s6, 8
/* 10BCCC 7F0D719C 25090007 */  addiu $t1, $t0, 7
/* 10BCD0 7F0D71A0 15800004 */  bnez  $t4, .L7F0D71B4
/* 10BCD4 7F0D71A4 AFA9028C */   sw    $t1, 0x28c($sp)
/* 10BCD8 7F0D71A8 0337C025 */  or    $t8, $t9, $s7
/* 10BCDC 7F0D71AC 10000016 */  b     .L7F0D7208
/* 10BCE0 7F0D71B0 A7B801FA */   sh    $t8, 0x1fa($sp)
.L7F0D71B4:
/* 10BCE4 7F0D71B4 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10BCE8 7F0D71B8 93AA0287 */  lbu   $t2, 0x287($sp)
/* 10BCEC 7F0D71BC 24010001 */  li    $at, 1
/* 10BCF0 7F0D71C0 25CF0008 */  addiu $t7, $t6, 8
/* 10BCF4 7F0D71C4 15410004 */  bne   $t2, $at, .L7F0D71D8
/* 10BCF8 7F0D71C8 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10BCFC 7F0D71CC 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10BD00 7F0D71D0 10000003 */  b     .L7F0D71E0
/* 10BD04 7F0D71D4 AFAD0048 */   sw    $t5, 0x48($sp)
.L7F0D71D8:
/* 10BD08 7F0D71D8 97AB0294 */  lhu   $t3, 0x294($sp)
/* 10BD0C 7F0D71DC AFAB0048 */  sw    $t3, 0x48($sp)
.L7F0D71E0:
/* 10BD10 7F0D71E0 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10BD14 7F0D71E4 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10BD18 7F0D71E8 97A80298 */  lhu   $t0, 0x298($sp)
/* 10BD1C 7F0D71EC 8FB80048 */  lw    $t8, 0x48($sp)
/* 10BD20 7F0D71F0 01096021 */  addu  $t4, $t0, $t1
/* 10BD24 7F0D71F4 81990000 */  lb    $t9, ($t4)
/* 10BD28 7F0D71F8 250F0001 */  addiu $t7, $t0, 1
/* 10BD2C 7F0D71FC A7AF0298 */  sh    $t7, 0x298($sp)
/* 10BD30 7F0D7200 03387021 */  addu  $t6, $t9, $t8
/* 10BD34 7F0D7204 A7AE01FA */  sh    $t6, 0x1fa($sp)
.L7F0D7208:
/* 10BD38 7F0D7208 97AA01FA */  lhu   $t2, 0x1fa($sp)
/* 10BD3C 7F0D720C 97A901FA */  lhu   $t1, 0x1fa($sp)
/* 10BD40 7F0D7210 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 10BD44 7F0D7214 29415B00 */  slti  $at, $t2, 0x5b00
/* 10BD48 7F0D7218 54200006 */  bnezl $at, .L7F0D7234
/* 10BD4C 7F0D721C 29215800 */   slti  $at, $t1, 0x5800
/* 10BD50 7F0D7220 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10BD54 7F0D7224 01AA5821 */  addu  $t3, $t5, $t2
/* 10BD58 7F0D7228 10002D74 */  b     .L7F0E27FC
/* 10BD5C 7F0D722C A1750000 */   sb    $s5, ($t3)
/* 10BD60 7F0D7230 29215800 */  slti  $at, $t1, 0x5800
.L7F0D7234:
/* 10BD64 7F0D7234 1420000C */  bnez  $at, .L7F0D7268
/* 10BD68 7F0D7238 97AD01FA */   lhu   $t5, 0x1fa($sp)
/* 10BD6C 7F0D723C 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 10BD70 7F0D7240 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 10BD74 7F0D7244 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 10BD78 7F0D7248 24180001 */  li    $t8, 1
/* 10BD7C 7F0D724C 0189C821 */  addu  $t9, $t4, $t1
/* 10BD80 7F0D7250 A3350000 */  sb    $s5, ($t9)
/* 10BD84 7F0D7254 97A801FA */  lhu   $t0, 0x1fa($sp)
/* 10BD88 7F0D7258 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 10BD8C 7F0D725C 01C87821 */  addu  $t7, $t6, $t0
/* 10BD90 7F0D7260 10002D66 */  b     .L7F0E27FC
/* 10BD94 7F0D7264 A1F8A800 */   sb    $t8, -0x5800($t7)
.L7F0D7268:
/* 10BD98 7F0D7268 29A14000 */  slti  $at, $t5, 0x4000
/* 10BD9C 7F0D726C 14202D63 */  bnez  $at, .L7F0E27FC
/* 10BDA0 7F0D7270 3C0A8009 */   lui   $t2, %hi(ptr_spectrum_roms) 
/* 10BDA4 7F0D7274 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 10BDA8 7F0D7278 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 10BDAC 7F0D727C 240C0001 */  li    $t4, 1
/* 10BDB0 7F0D7280 014D5821 */  addu  $t3, $t2, $t5
/* 10BDB4 7F0D7284 A1750000 */  sb    $s5, ($t3)
/* 10BDB8 7F0D7288 97A901FA */  lhu   $t1, 0x1fa($sp)
/* 10BDBC 7F0D728C 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 10BDC0 7F0D7290 31391800 */  andi  $t9, $t1, 0x1800
/* 10BDC4 7F0D7294 001970C3 */  sra   $t6, $t9, 3
/* 10BDC8 7F0D7298 312800FF */  andi  $t0, $t1, 0xff
/* 10BDCC 7F0D729C 01C8C025 */  or    $t8, $t6, $t0
/* 10BDD0 7F0D72A0 01F85021 */  addu  $t2, $t7, $t8
/* 10BDD4 7F0D72A4 10002D55 */  b     .L7F0E27FC
/* 10BDD8 7F0D72A8 A14C0000 */   sb    $t4, ($t2)
spectrum_op_74:
/* 10BDDC 7F0D72AC 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10BDE0 7F0D72B0 93B90287 */  lbu   $t9, 0x287($sp)
/* 10BDE4 7F0D72B4 00164A00 */  sll   $t1, $s6, 8
/* 10BDE8 7F0D72B8 25AB0007 */  addiu $t3, $t5, 7
/* 10BDEC 7F0D72BC 17200004 */  bnez  $t9, .L7F0D72D0
/* 10BDF0 7F0D72C0 AFAB028C */   sw    $t3, 0x28c($sp)
/* 10BDF4 7F0D72C4 01377025 */  or    $t6, $t1, $s7
/* 10BDF8 7F0D72C8 10000016 */  b     .L7F0D7324
/* 10BDFC 7F0D72CC A7AE01F8 */   sh    $t6, 0x1f8($sp)
.L7F0D72D0:
/* 10BE00 7F0D72D0 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10BE04 7F0D72D4 93B80287 */  lbu   $t8, 0x287($sp)
/* 10BE08 7F0D72D8 24010001 */  li    $at, 1
/* 10BE0C 7F0D72DC 250F0008 */  addiu $t7, $t0, 8
/* 10BE10 7F0D72E0 17010004 */  bne   $t8, $at, .L7F0D72F4
/* 10BE14 7F0D72E4 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10BE18 7F0D72E8 97AC0296 */  lhu   $t4, 0x296($sp)
/* 10BE1C 7F0D72EC 10000003 */  b     .L7F0D72FC
/* 10BE20 7F0D72F0 AFAC0048 */   sw    $t4, 0x48($sp)
.L7F0D72F4:
/* 10BE24 7F0D72F4 97AA0294 */  lhu   $t2, 0x294($sp)
/* 10BE28 7F0D72F8 AFAA0048 */  sw    $t2, 0x48($sp)
.L7F0D72FC:
/* 10BE2C 7F0D72FC 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 10BE30 7F0D7300 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10BE34 7F0D7304 97AD0298 */  lhu   $t5, 0x298($sp)
/* 10BE38 7F0D7308 8FAE0048 */  lw    $t6, 0x48($sp)
/* 10BE3C 7F0D730C 01ABC821 */  addu  $t9, $t5, $t3
/* 10BE40 7F0D7310 83290000 */  lb    $t1, ($t9)
/* 10BE44 7F0D7314 25AF0001 */  addiu $t7, $t5, 1
/* 10BE48 7F0D7318 A7AF0298 */  sh    $t7, 0x298($sp)
/* 10BE4C 7F0D731C 012E4021 */  addu  $t0, $t1, $t6
/* 10BE50 7F0D7320 A7A801F8 */  sh    $t0, 0x1f8($sp)
.L7F0D7324:
/* 10BE54 7F0D7324 97B801F8 */  lhu   $t8, 0x1f8($sp)
/* 10BE58 7F0D7328 97AB01F8 */  lhu   $t3, 0x1f8($sp)
/* 10BE5C 7F0D732C 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 10BE60 7F0D7330 2B015B00 */  slti  $at, $t8, 0x5b00
/* 10BE64 7F0D7334 54200006 */  bnezl $at, .L7F0D7350
/* 10BE68 7F0D7338 29615800 */   slti  $at, $t3, 0x5800
/* 10BE6C 7F0D733C 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 10BE70 7F0D7340 01985021 */  addu  $t2, $t4, $t8
/* 10BE74 7F0D7344 10002D2D */  b     .L7F0E27FC
/* 10BE78 7F0D7348 A1560000 */   sb    $s6, ($t2)
/* 10BE7C 7F0D734C 29615800 */  slti  $at, $t3, 0x5800
.L7F0D7350:
/* 10BE80 7F0D7350 1420000C */  bnez  $at, .L7F0D7384
/* 10BE84 7F0D7354 97AC01F8 */   lhu   $t4, 0x1f8($sp)
/* 10BE88 7F0D7358 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10BE8C 7F0D735C 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10BE90 7F0D7360 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 10BE94 7F0D7364 240E0001 */  li    $t6, 1
/* 10BE98 7F0D7368 032B4821 */  addu  $t1, $t9, $t3
/* 10BE9C 7F0D736C A1360000 */  sb    $s6, ($t1)
/* 10BEA0 7F0D7370 97AD01F8 */  lhu   $t5, 0x1f8($sp)
/* 10BEA4 7F0D7374 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 10BEA8 7F0D7378 010D7821 */  addu  $t7, $t0, $t5
/* 10BEAC 7F0D737C 10002D1F */  b     .L7F0E27FC
/* 10BEB0 7F0D7380 A1EEA800 */   sb    $t6, -0x5800($t7)
.L7F0D7384:
/* 10BEB4 7F0D7384 29814000 */  slti  $at, $t4, 0x4000
/* 10BEB8 7F0D7388 14202D1C */  bnez  $at, .L7F0E27FC
/* 10BEBC 7F0D738C 3C188009 */   lui   $t8, %hi(ptr_spectrum_roms) 
/* 10BEC0 7F0D7390 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10BEC4 7F0D7394 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 10BEC8 7F0D7398 24190001 */  li    $t9, 1
/* 10BECC 7F0D739C 030C5021 */  addu  $t2, $t8, $t4
/* 10BED0 7F0D73A0 A1560000 */  sb    $s6, ($t2)
/* 10BED4 7F0D73A4 97AB01F8 */  lhu   $t3, 0x1f8($sp)
/* 10BED8 7F0D73A8 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 10BEDC 7F0D73AC 31691800 */  andi  $t1, $t3, 0x1800
/* 10BEE0 7F0D73B0 000940C3 */  sra   $t0, $t1, 3
/* 10BEE4 7F0D73B4 316D00FF */  andi  $t5, $t3, 0xff
/* 10BEE8 7F0D73B8 010D7025 */  or    $t6, $t0, $t5
/* 10BEEC 7F0D73BC 01EEC021 */  addu  $t8, $t7, $t6
/* 10BEF0 7F0D73C0 10002D0E */  b     .L7F0E27FC
/* 10BEF4 7F0D73C4 A3190000 */   sb    $t9, ($t8)
spectrum_op_75:
/* 10BEF8 7F0D73C8 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10BEFC 7F0D73CC 93A90287 */  lbu   $t1, 0x287($sp)
/* 10BF00 7F0D73D0 00165A00 */  sll   $t3, $s6, 8
/* 10BF04 7F0D73D4 258A0007 */  addiu $t2, $t4, 7
/* 10BF08 7F0D73D8 15200004 */  bnez  $t1, .L7F0D73EC
/* 10BF0C 7F0D73DC AFAA028C */   sw    $t2, 0x28c($sp)
/* 10BF10 7F0D73E0 01774025 */  or    $t0, $t3, $s7
/* 10BF14 7F0D73E4 10000016 */  b     .L7F0D7440
/* 10BF18 7F0D73E8 A7A801F6 */   sh    $t0, 0x1f6($sp)
.L7F0D73EC:
/* 10BF1C 7F0D73EC 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10BF20 7F0D73F0 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10BF24 7F0D73F4 24010001 */  li    $at, 1
/* 10BF28 7F0D73F8 25AF0008 */  addiu $t7, $t5, 8
/* 10BF2C 7F0D73FC 15C10004 */  bne   $t6, $at, .L7F0D7410
/* 10BF30 7F0D7400 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10BF34 7F0D7404 97B90296 */  lhu   $t9, 0x296($sp)
/* 10BF38 7F0D7408 10000003 */  b     .L7F0D7418
/* 10BF3C 7F0D740C AFB90048 */   sw    $t9, 0x48($sp)
.L7F0D7410:
/* 10BF40 7F0D7410 97B80294 */  lhu   $t8, 0x294($sp)
/* 10BF44 7F0D7414 AFB80048 */  sw    $t8, 0x48($sp)
.L7F0D7418:
/* 10BF48 7F0D7418 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 10BF4C 7F0D741C 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 10BF50 7F0D7420 97AC0298 */  lhu   $t4, 0x298($sp)
/* 10BF54 7F0D7424 8FA80048 */  lw    $t0, 0x48($sp)
/* 10BF58 7F0D7428 018A4821 */  addu  $t1, $t4, $t2
/* 10BF5C 7F0D742C 812B0000 */  lb    $t3, ($t1)
/* 10BF60 7F0D7430 258F0001 */  addiu $t7, $t4, 1
/* 10BF64 7F0D7434 A7AF0298 */  sh    $t7, 0x298($sp)
/* 10BF68 7F0D7438 01686821 */  addu  $t5, $t3, $t0
/* 10BF6C 7F0D743C A7AD01F6 */  sh    $t5, 0x1f6($sp)
.L7F0D7440:
/* 10BF70 7F0D7440 97AE01F6 */  lhu   $t6, 0x1f6($sp)
/* 10BF74 7F0D7444 97AA01F6 */  lhu   $t2, 0x1f6($sp)
/* 10BF78 7F0D7448 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10BF7C 7F0D744C 29C15B00 */  slti  $at, $t6, 0x5b00
/* 10BF80 7F0D7450 54200006 */  bnezl $at, .L7F0D746C
/* 10BF84 7F0D7454 29415800 */   slti  $at, $t2, 0x5800
/* 10BF88 7F0D7458 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10BF8C 7F0D745C 032EC021 */  addu  $t8, $t9, $t6
/* 10BF90 7F0D7460 10002CE6 */  b     .L7F0E27FC
/* 10BF94 7F0D7464 A3170000 */   sb    $s7, ($t8)
/* 10BF98 7F0D7468 29415800 */  slti  $at, $t2, 0x5800
.L7F0D746C:
/* 10BF9C 7F0D746C 1420000C */  bnez  $at, .L7F0D74A0
/* 10BFA0 7F0D7470 97B901F6 */   lhu   $t9, 0x1f6($sp)
/* 10BFA4 7F0D7474 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10BFA8 7F0D7478 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10BFAC 7F0D747C 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 10BFB0 7F0D7480 24080001 */  li    $t0, 1
/* 10BFB4 7F0D7484 012A5821 */  addu  $t3, $t1, $t2
/* 10BFB8 7F0D7488 A1770000 */  sb    $s7, ($t3)
/* 10BFBC 7F0D748C 97AC01F6 */  lhu   $t4, 0x1f6($sp)
/* 10BFC0 7F0D7490 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 10BFC4 7F0D7494 01AC7821 */  addu  $t7, $t5, $t4
/* 10BFC8 7F0D7498 10002CD8 */  b     .L7F0E27FC
/* 10BFCC 7F0D749C A1E8A800 */   sb    $t0, -0x5800($t7)
.L7F0D74A0:
/* 10BFD0 7F0D74A0 2B214000 */  slti  $at, $t9, 0x4000
/* 10BFD4 7F0D74A4 14202CD5 */  bnez  $at, .L7F0E27FC
/* 10BFD8 7F0D74A8 3C0E8009 */   lui   $t6, %hi(ptr_spectrum_roms) 
/* 10BFDC 7F0D74AC 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10BFE0 7F0D74B0 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 10BFE4 7F0D74B4 24090001 */  li    $t1, 1
/* 10BFE8 7F0D74B8 01D9C021 */  addu  $t8, $t6, $t9
/* 10BFEC 7F0D74BC A3170000 */  sb    $s7, ($t8)
/* 10BFF0 7F0D74C0 97AA01F6 */  lhu   $t2, 0x1f6($sp)
/* 10BFF4 7F0D74C4 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 10BFF8 7F0D74C8 314B1800 */  andi  $t3, $t2, 0x1800
/* 10BFFC 7F0D74CC 000B68C3 */  sra   $t5, $t3, 3
/* 10C000 7F0D74D0 314C00FF */  andi  $t4, $t2, 0xff
/* 10C004 7F0D74D4 01AC4025 */  or    $t0, $t5, $t4
/* 10C008 7F0D74D8 01E87021 */  addu  $t6, $t7, $t0
/* 10C00C 7F0D74DC 10002CC7 */  b     .L7F0E27FC
/* 10C010 7F0D74E0 A1C90000 */   sb    $t1, ($t6)
spectrum_op_76:
/* 10C014 7F0D74E4 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10C018 7F0D74E8 8FAB0280 */  lw    $t3, 0x280($sp)
/* 10C01C 7F0D74EC 27380004 */  addiu $t8, $t9, 4
/* 10C020 7F0D74F0 030B082B */  sltu  $at, $t8, $t3
/* 10C024 7F0D74F4 10200007 */  beqz  $at, .L7F0D7514
/* 10C028 7F0D74F8 AFB8028C */   sw    $t8, 0x28c($sp)
/* 10C02C 7F0D74FC 01785023 */  subu  $t2, $t3, $t8
/* 10C030 7F0D7500 254D0003 */  addiu $t5, $t2, 3
/* 10C034 7F0D7504 2401FFFC */  li    $at, -4
/* 10C038 7F0D7508 01A16024 */  and   $t4, $t5, $at
/* 10C03C 7F0D750C 030C7821 */  addu  $t7, $t8, $t4
/* 10C040 7F0D7510 AFAF028C */  sw    $t7, 0x28c($sp)
.L7F0D7514:
/* 10C044 7F0D7514 97A80298 */  lhu   $t0, 0x298($sp)
/* 10C048 7F0D7518 2509FFFF */  addiu $t1, $t0, -1
/* 10C04C 7F0D751C 10002CB7 */  b     .L7F0E27FC
/* 10C050 7F0D7520 A7A90298 */   sh    $t1, 0x298($sp)
spectrum_op_77:
/* 10C054 7F0D7524 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10C058 7F0D7528 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10C05C 7F0D752C 00165200 */  sll   $t2, $s6, 8
/* 10C060 7F0D7530 25D90007 */  addiu $t9, $t6, 7
/* 10C064 7F0D7534 15600004 */  bnez  $t3, .L7F0D7548
/* 10C068 7F0D7538 AFB9028C */   sw    $t9, 0x28c($sp)
/* 10C06C 7F0D753C 01576825 */  or    $t5, $t2, $s7
/* 10C070 7F0D7540 10000016 */  b     .L7F0D759C
/* 10C074 7F0D7544 A7AD01F4 */   sh    $t5, 0x1f4($sp)
.L7F0D7548:
/* 10C078 7F0D7548 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10C07C 7F0D754C 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10C080 7F0D7550 24010001 */  li    $at, 1
/* 10C084 7F0D7554 270C0008 */  addiu $t4, $t8, 8
/* 10C088 7F0D7558 15E10004 */  bne   $t7, $at, .L7F0D756C
/* 10C08C 7F0D755C AFAC028C */   sw    $t4, 0x28c($sp)
/* 10C090 7F0D7560 97A80296 */  lhu   $t0, 0x296($sp)
/* 10C094 7F0D7564 10000003 */  b     .L7F0D7574
/* 10C098 7F0D7568 AFA80048 */   sw    $t0, 0x48($sp)
.L7F0D756C:
/* 10C09C 7F0D756C 97A90294 */  lhu   $t1, 0x294($sp)
/* 10C0A0 7F0D7570 AFA90048 */  sw    $t1, 0x48($sp)
.L7F0D7574:
/* 10C0A4 7F0D7574 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10C0A8 7F0D7578 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10C0AC 7F0D757C 97AE0298 */  lhu   $t6, 0x298($sp)
/* 10C0B0 7F0D7580 8FAD0048 */  lw    $t5, 0x48($sp)
/* 10C0B4 7F0D7584 01D95821 */  addu  $t3, $t6, $t9
/* 10C0B8 7F0D7588 816A0000 */  lb    $t2, ($t3)
/* 10C0BC 7F0D758C 25CC0001 */  addiu $t4, $t6, 1
/* 10C0C0 7F0D7590 A7AC0298 */  sh    $t4, 0x298($sp)
/* 10C0C4 7F0D7594 014DC021 */  addu  $t8, $t2, $t5
/* 10C0C8 7F0D7598 A7B801F4 */  sh    $t8, 0x1f4($sp)
.L7F0D759C:
/* 10C0CC 7F0D759C 97AF01F4 */  lhu   $t7, 0x1f4($sp)
/* 10C0D0 7F0D75A0 97B901F4 */  lhu   $t9, 0x1f4($sp)
/* 10C0D4 7F0D75A4 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10C0D8 7F0D75A8 29E15B00 */  slti  $at, $t7, 0x5b00
/* 10C0DC 7F0D75AC 54200006 */  bnezl $at, .L7F0D75C8
/* 10C0E0 7F0D75B0 2B215800 */   slti  $at, $t9, 0x5800
/* 10C0E4 7F0D75B4 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10C0E8 7F0D75B8 010F4821 */  addu  $t1, $t0, $t7
/* 10C0EC 7F0D75BC 10002C8F */  b     .L7F0E27FC
/* 10C0F0 7F0D75C0 A1300000 */   sb    $s0, ($t1)
/* 10C0F4 7F0D75C4 2B215800 */  slti  $at, $t9, 0x5800
.L7F0D75C8:
/* 10C0F8 7F0D75C8 1420000C */  bnez  $at, .L7F0D75FC
/* 10C0FC 7F0D75CC 97A801F4 */   lhu   $t0, 0x1f4($sp)
/* 10C100 7F0D75D0 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 10C104 7F0D75D4 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10C108 7F0D75D8 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 10C10C 7F0D75DC 240D0001 */  li    $t5, 1
/* 10C110 7F0D75E0 01795021 */  addu  $t2, $t3, $t9
/* 10C114 7F0D75E4 A1500000 */  sb    $s0, ($t2)
/* 10C118 7F0D75E8 97AE01F4 */  lhu   $t6, 0x1f4($sp)
/* 10C11C 7F0D75EC 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 10C120 7F0D75F0 030E6021 */  addu  $t4, $t8, $t6
/* 10C124 7F0D75F4 10002C81 */  b     .L7F0E27FC
/* 10C128 7F0D75F8 A18DA800 */   sb    $t5, -0x5800($t4)
.L7F0D75FC:
/* 10C12C 7F0D75FC 29014000 */  slti  $at, $t0, 0x4000
/* 10C130 7F0D7600 14202C7E */  bnez  $at, .L7F0E27FC
/* 10C134 7F0D7604 3C0F8009 */   lui   $t7, %hi(ptr_spectrum_roms) 
/* 10C138 7F0D7608 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10C13C 7F0D760C 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 10C140 7F0D7610 240B0001 */  li    $t3, 1
/* 10C144 7F0D7614 01E84821 */  addu  $t1, $t7, $t0
/* 10C148 7F0D7618 A1300000 */  sb    $s0, ($t1)
/* 10C14C 7F0D761C 97B901F4 */  lhu   $t9, 0x1f4($sp)
/* 10C150 7F0D7620 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 10C154 7F0D7624 332A1800 */  andi  $t2, $t9, 0x1800
/* 10C158 7F0D7628 000AC0C3 */  sra   $t8, $t2, 3
/* 10C15C 7F0D762C 332E00FF */  andi  $t6, $t9, 0xff
/* 10C160 7F0D7630 030E6825 */  or    $t5, $t8, $t6
/* 10C164 7F0D7634 018D7821 */  addu  $t7, $t4, $t5
/* 10C168 7F0D7638 10002C70 */  b     .L7F0E27FC
/* 10C16C 7F0D763C A1EB0000 */   sb    $t3, ($t7)
spectrum_op_78:
/* 10C170 7F0D7640 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10C174 7F0D7644 325000FF */  andi  $s0, $s2, 0xff
/* 10C178 7F0D7648 25090004 */  addiu $t1, $t0, 4
/* 10C17C 7F0D764C 10002C6B */  b     .L7F0E27FC
/* 10C180 7F0D7650 AFA9028C */   sw    $t1, 0x28c($sp)
spectrum_op_79:
/* 10C184 7F0D7654 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10C188 7F0D7658 327000FF */  andi  $s0, $s3, 0xff
/* 10C18C 7F0D765C 25590004 */  addiu $t9, $t2, 4
/* 10C190 7F0D7660 10002C66 */  b     .L7F0E27FC
/* 10C194 7F0D7664 AFB9028C */   sw    $t9, 0x28c($sp)
spectrum_op_7A:
/* 10C198 7F0D7668 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10C19C 7F0D766C 329000FF */  andi  $s0, $s4, 0xff
/* 10C1A0 7F0D7670 270E0004 */  addiu $t6, $t8, 4
/* 10C1A4 7F0D7674 10002C61 */  b     .L7F0E27FC
/* 10C1A8 7F0D7678 AFAE028C */   sw    $t6, 0x28c($sp)
spectrum_op_7B:
/* 10C1AC 7F0D767C 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10C1B0 7F0D7680 32B000FF */  andi  $s0, $s5, 0xff
/* 10C1B4 7F0D7684 258D0004 */  addiu $t5, $t4, 4
/* 10C1B8 7F0D7688 10002C5C */  b     .L7F0E27FC
/* 10C1BC 7F0D768C AFAD028C */   sw    $t5, 0x28c($sp)
spectrum_op_7C:
/* 10C1C0 7F0D7690 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10C1C4 7F0D7694 93A80287 */  lbu   $t0, 0x287($sp)
/* 10C1C8 7F0D7698 93A90287 */  lbu   $t1, 0x287($sp)
/* 10C1CC 7F0D769C 256F0004 */  addiu $t7, $t3, 4
/* 10C1D0 7F0D76A0 15000003 */  bnez  $t0, .L7F0D76B0
/* 10C1D4 7F0D76A4 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10C1D8 7F0D76A8 10002C54 */  b     .L7F0E27FC
/* 10C1DC 7F0D76AC 32D000FF */   andi  $s0, $s6, 0xff
.L7F0D76B0:
/* 10C1E0 7F0D76B0 24010001 */  li    $at, 1
/* 10C1E4 7F0D76B4 15210005 */  bne   $t1, $at, .L7F0D76CC
/* 10C1E8 7F0D76B8 97B80294 */   lhu   $t8, 0x294($sp)
/* 10C1EC 7F0D76BC 97AA0296 */  lhu   $t2, 0x296($sp)
/* 10C1F0 7F0D76C0 000ACA03 */  sra   $t9, $t2, 8
/* 10C1F4 7F0D76C4 10000003 */  b     .L7F0D76D4
/* 10C1F8 7F0D76C8 AFB90048 */   sw    $t9, 0x48($sp)
.L7F0D76CC:
/* 10C1FC 7F0D76CC 00187203 */  sra   $t6, $t8, 8
/* 10C200 7F0D76D0 AFAE0048 */  sw    $t6, 0x48($sp)
.L7F0D76D4:
/* 10C204 7F0D76D4 10002C49 */  b     .L7F0E27FC
/* 10C208 7F0D76D8 93B0004B */   lbu   $s0, 0x4b($sp)
spectrum_op_7D:
/* 10C20C 7F0D76DC 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10C210 7F0D76E0 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10C214 7F0D76E4 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10C218 7F0D76E8 258D0004 */  addiu $t5, $t4, 4
/* 10C21C 7F0D76EC 15600003 */  bnez  $t3, .L7F0D76FC
/* 10C220 7F0D76F0 AFAD028C */   sw    $t5, 0x28c($sp)
/* 10C224 7F0D76F4 10002C41 */  b     .L7F0E27FC
/* 10C228 7F0D76F8 32F000FF */   andi  $s0, $s7, 0xff
.L7F0D76FC:
/* 10C22C 7F0D76FC 24010001 */  li    $at, 1
/* 10C230 7F0D7700 15E10005 */  bne   $t7, $at, .L7F0D7718
/* 10C234 7F0D7704 97AA0294 */   lhu   $t2, 0x294($sp)
/* 10C238 7F0D7708 97A80296 */  lhu   $t0, 0x296($sp)
/* 10C23C 7F0D770C 310900FF */  andi  $t1, $t0, 0xff
/* 10C240 7F0D7710 10000003 */  b     .L7F0D7720
/* 10C244 7F0D7714 AFA90048 */   sw    $t1, 0x48($sp)
.L7F0D7718:
/* 10C248 7F0D7718 315900FF */  andi  $t9, $t2, 0xff
/* 10C24C 7F0D771C AFB90048 */  sw    $t9, 0x48($sp)
.L7F0D7720:
/* 10C250 7F0D7720 10002C36 */  b     .L7F0E27FC
/* 10C254 7F0D7724 93B0004B */   lbu   $s0, 0x4b($sp)
spectrum_op_7E:
/* 10C258 7F0D7728 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10C25C 7F0D772C 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10C260 7F0D7730 00166A00 */  sll   $t5, $s6, 8
/* 10C264 7F0D7734 270E0007 */  addiu $t6, $t8, 7
/* 10C268 7F0D7738 15800004 */  bnez  $t4, .L7F0D774C
/* 10C26C 7F0D773C AFAE028C */   sw    $t6, 0x28c($sp)
/* 10C270 7F0D7740 01B75825 */  or    $t3, $t5, $s7
/* 10C274 7F0D7744 10000016 */  b     .L7F0D77A0
/* 10C278 7F0D7748 A7AB01F2 */   sh    $t3, 0x1f2($sp)
.L7F0D774C:
/* 10C27C 7F0D774C 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10C280 7F0D7750 93A90287 */  lbu   $t1, 0x287($sp)
/* 10C284 7F0D7754 24010001 */  li    $at, 1
/* 10C288 7F0D7758 25E80008 */  addiu $t0, $t7, 8
/* 10C28C 7F0D775C 15210004 */  bne   $t1, $at, .L7F0D7770
/* 10C290 7F0D7760 AFA8028C */   sw    $t0, 0x28c($sp)
/* 10C294 7F0D7764 97AA0296 */  lhu   $t2, 0x296($sp)
/* 10C298 7F0D7768 10000003 */  b     .L7F0D7778
/* 10C29C 7F0D776C AFAA0048 */   sw    $t2, 0x48($sp)
.L7F0D7770:
/* 10C2A0 7F0D7770 97B90294 */  lhu   $t9, 0x294($sp)
/* 10C2A4 7F0D7774 AFB90048 */  sw    $t9, 0x48($sp)
.L7F0D7778:
/* 10C2A8 7F0D7778 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10C2AC 7F0D777C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10C2B0 7F0D7780 97B80298 */  lhu   $t8, 0x298($sp)
/* 10C2B4 7F0D7784 8FAB0048 */  lw    $t3, 0x48($sp)
/* 10C2B8 7F0D7788 030E6021 */  addu  $t4, $t8, $t6
/* 10C2BC 7F0D778C 818D0000 */  lb    $t5, ($t4)
/* 10C2C0 7F0D7790 27080001 */  addiu $t0, $t8, 1
/* 10C2C4 7F0D7794 A7A80298 */  sh    $t0, 0x298($sp)
/* 10C2C8 7F0D7798 01AB7821 */  addu  $t7, $t5, $t3
/* 10C2CC 7F0D779C A7AF01F2 */  sh    $t7, 0x1f2($sp)
.L7F0D77A0:
/* 10C2D0 7F0D77A0 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 10C2D4 7F0D77A4 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 10C2D8 7F0D77A8 97A901F2 */  lhu   $t1, 0x1f2($sp)
/* 10C2DC 7F0D77AC 012AC821 */  addu  $t9, $t1, $t2
/* 10C2E0 7F0D77B0 10002C12 */  b     .L7F0E27FC
/* 10C2E4 7F0D77B4 93300000 */   lbu   $s0, ($t9)
spectrum_op_7F:
/* 10C2E8 7F0D77B8 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10C2EC 7F0D77BC 25CC0004 */  addiu $t4, $t6, 4
/* 10C2F0 7F0D77C0 10002C0E */  b     .L7F0E27FC
/* 10C2F4 7F0D77C4 AFAC028C */   sw    $t4, 0x28c($sp)
spectrum_op_80:
/* 10C2F8 7F0D77C8 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10C2FC 7F0D77CC 324F00FF */  andi  $t7, $s2, 0xff
/* 10C300 7F0D77D0 020F4021 */  addu  $t0, $s0, $t7
/* 10C304 7F0D77D4 25AB0004 */  addiu $t3, $t5, 4
/* 10C308 7F0D77D8 310900A8 */  andi  $t1, $t0, 0xa8
/* 10C30C 7F0D77DC 00085203 */  sra   $t2, $t0, 8
/* 10C310 7F0D77E0 31EC000F */  andi  $t4, $t7, 0xf
/* 10C314 7F0D77E4 320E000F */  andi  $t6, $s0, 0xf
/* 10C318 7F0D77E8 AFAB028C */  sw    $t3, 0x28c($sp)
/* 10C31C 7F0D77EC 01CC6821 */  addu  $t5, $t6, $t4
/* 10C320 7F0D77F0 012AC825 */  or    $t9, $t1, $t2
/* 10C324 7F0D77F4 2401000F */  li    $at, 15
/* 10C328 7F0D77F8 002D582A */  slt   $t3, $at, $t5
/* 10C32C 7F0D77FC 02005027 */  not   $t2, $s0
/* 10C330 7F0D7800 01106826 */  xor   $t5, $t0, $s0
/* 10C334 7F0D7804 A7A801F0 */  sh    $t0, 0x1f0($sp)
/* 10C338 7F0D7808 93B001F1 */  lbu   $s0, 0x1f1($sp)
/* 10C33C 7F0D780C 014F7026 */  xor   $t6, $t2, $t7
/* 10C340 7F0D7810 000BC100 */  sll   $t8, $t3, 4
/* 10C344 7F0D7814 31CC0080 */  andi  $t4, $t6, 0x80
/* 10C348 7F0D7818 018D5824 */  and   $t3, $t4, $t5
/* 10C34C 7F0D781C 03384825 */  or    $t1, $t9, $t8
/* 10C350 7F0D7820 000BC943 */  sra   $t9, $t3, 5
/* 10C354 7F0D7824 2E0A0001 */  sltiu $t2, $s0, 1
/* 10C358 7F0D7828 000A7180 */  sll   $t6, $t2, 6
/* 10C35C 7F0D782C 0139C025 */  or    $t8, $t1, $t9
/* 10C360 7F0D7830 030E8825 */  or    $s1, $t8, $t6
/* 10C364 7F0D7834 322800FF */  andi  $t0, $s1, 0xff
/* 10C368 7F0D7838 01008825 */  move  $s1, $t0
/* 10C36C 7F0D783C AFAA0048 */  sw    $t2, 0x48($sp)
/* 10C370 7F0D7840 10002BEE */  b     .L7F0E27FC
/* 10C374 7F0D7844 A3B201EF */   sb    $s2, 0x1ef($sp)
spectrum_op_81:
/* 10C378 7F0D7848 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10C37C 7F0D784C 326B00FF */  andi  $t3, $s3, 0xff
/* 10C380 7F0D7850 020BC821 */  addu  $t9, $s0, $t3
/* 10C384 7F0D7854 258D0004 */  addiu $t5, $t4, 4
/* 10C388 7F0D7858 333800A8 */  andi  $t8, $t9, 0xa8
/* 10C38C 7F0D785C 00195203 */  sra   $t2, $t9, 8
/* 10C390 7F0D7860 3168000F */  andi  $t0, $t3, 0xf
/* 10C394 7F0D7864 320E000F */  andi  $t6, $s0, 0xf
/* 10C398 7F0D7868 AFAD028C */  sw    $t5, 0x28c($sp)
/* 10C39C 7F0D786C 01C86021 */  addu  $t4, $t6, $t0
/* 10C3A0 7F0D7870 030A7825 */  or    $t7, $t8, $t2
/* 10C3A4 7F0D7874 2401000F */  li    $at, 15
/* 10C3A8 7F0D7878 002C682A */  slt   $t5, $at, $t4
/* 10C3AC 7F0D787C 02005027 */  not   $t2, $s0
/* 10C3B0 7F0D7880 03306026 */  xor   $t4, $t9, $s0
/* 10C3B4 7F0D7884 A7B901EC */  sh    $t9, 0x1ec($sp)
/* 10C3B8 7F0D7888 93B001ED */  lbu   $s0, 0x1ed($sp)
/* 10C3BC 7F0D788C 014B7026 */  xor   $t6, $t2, $t3
/* 10C3C0 7F0D7890 000D4900 */  sll   $t1, $t5, 4
/* 10C3C4 7F0D7894 31C80080 */  andi  $t0, $t6, 0x80
/* 10C3C8 7F0D7898 010C6824 */  and   $t5, $t0, $t4
/* 10C3CC 7F0D789C 01E9C025 */  or    $t8, $t7, $t1
/* 10C3D0 7F0D78A0 000D7943 */  sra   $t7, $t5, 5
/* 10C3D4 7F0D78A4 2E0A0001 */  sltiu $t2, $s0, 1
/* 10C3D8 7F0D78A8 000A7180 */  sll   $t6, $t2, 6
/* 10C3DC 7F0D78AC 030F4825 */  or    $t1, $t8, $t7
/* 10C3E0 7F0D78B0 012E8825 */  or    $s1, $t1, $t6
/* 10C3E4 7F0D78B4 323900FF */  andi  $t9, $s1, 0xff
/* 10C3E8 7F0D78B8 03208825 */  move  $s1, $t9
/* 10C3EC 7F0D78BC AFAA0048 */  sw    $t2, 0x48($sp)
/* 10C3F0 7F0D78C0 10002BCE */  b     .L7F0E27FC
/* 10C3F4 7F0D78C4 A3B301EB */   sb    $s3, 0x1eb($sp)
spectrum_op_82:
/* 10C3F8 7F0D78C8 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10C3FC 7F0D78CC 328D00FF */  andi  $t5, $s4, 0xff
/* 10C400 7F0D78D0 020D7821 */  addu  $t7, $s0, $t5
/* 10C404 7F0D78D4 250C0004 */  addiu $t4, $t0, 4
/* 10C408 7F0D78D8 31E900A8 */  andi  $t1, $t7, 0xa8
/* 10C40C 7F0D78DC 000F5203 */  sra   $t2, $t7, 8
/* 10C410 7F0D78E0 31B9000F */  andi  $t9, $t5, 0xf
/* 10C414 7F0D78E4 320E000F */  andi  $t6, $s0, 0xf
/* 10C418 7F0D78E8 AFAC028C */  sw    $t4, 0x28c($sp)
/* 10C41C 7F0D78EC 01D94021 */  addu  $t0, $t6, $t9
/* 10C420 7F0D78F0 012A5825 */  or    $t3, $t1, $t2
/* 10C424 7F0D78F4 2401000F */  li    $at, 15
/* 10C428 7F0D78F8 0028602A */  slt   $t4, $at, $t0
/* 10C42C 7F0D78FC 02005027 */  not   $t2, $s0
/* 10C430 7F0D7900 01F04026 */  xor   $t0, $t7, $s0
/* 10C434 7F0D7904 A7AF01E8 */  sh    $t7, 0x1e8($sp)
/* 10C438 7F0D7908 93B001E9 */  lbu   $s0, 0x1e9($sp)
/* 10C43C 7F0D790C 014D7026 */  xor   $t6, $t2, $t5
/* 10C440 7F0D7910 000CC100 */  sll   $t8, $t4, 4
/* 10C444 7F0D7914 31D90080 */  andi  $t9, $t6, 0x80
/* 10C448 7F0D7918 03286024 */  and   $t4, $t9, $t0
/* 10C44C 7F0D791C 01784825 */  or    $t1, $t3, $t8
/* 10C450 7F0D7920 000C5943 */  sra   $t3, $t4, 5
/* 10C454 7F0D7924 2E0A0001 */  sltiu $t2, $s0, 1
/* 10C458 7F0D7928 000A7180 */  sll   $t6, $t2, 6
/* 10C45C 7F0D792C 012BC025 */  or    $t8, $t1, $t3
/* 10C460 7F0D7930 030E8825 */  or    $s1, $t8, $t6
/* 10C464 7F0D7934 322F00FF */  andi  $t7, $s1, 0xff
/* 10C468 7F0D7938 01E08825 */  move  $s1, $t7
/* 10C46C 7F0D793C AFAA0048 */  sw    $t2, 0x48($sp)
/* 10C470 7F0D7940 10002BAE */  b     .L7F0E27FC
/* 10C474 7F0D7944 A3B401E7 */   sb    $s4, 0x1e7($sp)
spectrum_op_83:
/* 10C478 7F0D7948 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10C47C 7F0D794C 32AC00FF */  andi  $t4, $s5, 0xff
/* 10C480 7F0D7950 020C5821 */  addu  $t3, $s0, $t4
/* 10C484 7F0D7954 27280004 */  addiu $t0, $t9, 4
/* 10C488 7F0D7958 317800A8 */  andi  $t8, $t3, 0xa8
/* 10C48C 7F0D795C 000B5203 */  sra   $t2, $t3, 8
/* 10C490 7F0D7960 318F000F */  andi  $t7, $t4, 0xf
/* 10C494 7F0D7964 320E000F */  andi  $t6, $s0, 0xf
/* 10C498 7F0D7968 AFA8028C */  sw    $t0, 0x28c($sp)
/* 10C49C 7F0D796C 01CFC821 */  addu  $t9, $t6, $t7
/* 10C4A0 7F0D7970 030A6825 */  or    $t5, $t8, $t2
/* 10C4A4 7F0D7974 2401000F */  li    $at, 15
/* 10C4A8 7F0D7978 0039402A */  slt   $t0, $at, $t9
/* 10C4AC 7F0D797C 02005027 */  not   $t2, $s0
/* 10C4B0 7F0D7980 0170C826 */  xor   $t9, $t3, $s0
/* 10C4B4 7F0D7984 A7AB01E4 */  sh    $t3, 0x1e4($sp)
/* 10C4B8 7F0D7988 93B001E5 */  lbu   $s0, 0x1e5($sp)
/* 10C4BC 7F0D798C 014C7026 */  xor   $t6, $t2, $t4
/* 10C4C0 7F0D7990 00084900 */  sll   $t1, $t0, 4
/* 10C4C4 7F0D7994 31CF0080 */  andi  $t7, $t6, 0x80
/* 10C4C8 7F0D7998 01F94024 */  and   $t0, $t7, $t9
/* 10C4CC 7F0D799C 01A9C025 */  or    $t8, $t5, $t1
/* 10C4D0 7F0D79A0 00086943 */  sra   $t5, $t0, 5
/* 10C4D4 7F0D79A4 2E0A0001 */  sltiu $t2, $s0, 1
/* 10C4D8 7F0D79A8 000A7180 */  sll   $t6, $t2, 6
/* 10C4DC 7F0D79AC 030D4825 */  or    $t1, $t8, $t5
/* 10C4E0 7F0D79B0 012E8825 */  or    $s1, $t1, $t6
/* 10C4E4 7F0D79B4 322B00FF */  andi  $t3, $s1, 0xff
/* 10C4E8 7F0D79B8 01608825 */  move  $s1, $t3
/* 10C4EC 7F0D79BC AFAA0048 */  sw    $t2, 0x48($sp)
/* 10C4F0 7F0D79C0 10002B8E */  b     .L7F0E27FC
/* 10C4F4 7F0D79C4 A3B501E3 */   sb    $s5, 0x1e3($sp)
spectrum_op_84:
/* 10C4F8 7F0D79C8 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10C4FC 7F0D79CC 93A80287 */  lbu   $t0, 0x287($sp)
/* 10C500 7F0D79D0 93B80287 */  lbu   $t8, 0x287($sp)
/* 10C504 7F0D79D4 25F90004 */  addiu $t9, $t7, 4
/* 10C508 7F0D79D8 15000003 */  bnez  $t0, .L7F0D79E8
/* 10C50C 7F0D79DC AFB9028C */   sw    $t9, 0x28c($sp)
/* 10C510 7F0D79E0 1000000C */  b     .L7F0D7A14
/* 10C514 7F0D79E4 A3B601DF */   sb    $s6, 0x1df($sp)
.L7F0D79E8:
/* 10C518 7F0D79E8 24010001 */  li    $at, 1
/* 10C51C 7F0D79EC 17010005 */  bne   $t8, $at, .L7F0D7A04
/* 10C520 7F0D79F0 97AA0294 */   lhu   $t2, 0x294($sp)
/* 10C524 7F0D79F4 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10C528 7F0D79F8 000D4A03 */  sra   $t1, $t5, 8
/* 10C52C 7F0D79FC 10000003 */  b     .L7F0D7A0C
/* 10C530 7F0D7A00 AFA90048 */   sw    $t1, 0x48($sp)
.L7F0D7A04:
/* 10C534 7F0D7A04 000A6203 */  sra   $t4, $t2, 8
/* 10C538 7F0D7A08 AFAC0048 */  sw    $t4, 0x48($sp)
.L7F0D7A0C:
/* 10C53C 7F0D7A0C 8FAE0048 */  lw    $t6, 0x48($sp)
/* 10C540 7F0D7A10 A3AE01DF */  sb    $t6, 0x1df($sp)
.L7F0D7A14:
/* 10C544 7F0D7A14 93AB01DF */  lbu   $t3, 0x1df($sp)
/* 10C548 7F0D7A18 3209000F */  andi  $t1, $s0, 0xf
/* 10C54C 7F0D7A1C 2401000F */  li    $at, 15
/* 10C550 7F0D7A20 020BC821 */  addu  $t9, $s0, $t3
/* 10C554 7F0D7A24 332800A8 */  andi  $t0, $t9, 0xa8
/* 10C558 7F0D7A28 0019C203 */  sra   $t8, $t9, 8
/* 10C55C 7F0D7A2C 316A000F */  andi  $t2, $t3, 0xf
/* 10C560 7F0D7A30 012A6021 */  addu  $t4, $t1, $t2
/* 10C564 7F0D7A34 01186825 */  or    $t5, $t0, $t8
/* 10C568 7F0D7A38 0200C027 */  not   $t8, $s0
/* 10C56C 7F0D7A3C 002C702A */  slt   $t6, $at, $t4
/* 10C570 7F0D7A40 03306026 */  xor   $t4, $t9, $s0
/* 10C574 7F0D7A44 A7B901E0 */  sh    $t9, 0x1e0($sp)
/* 10C578 7F0D7A48 93B001E1 */  lbu   $s0, 0x1e1($sp)
/* 10C57C 7F0D7A4C 000E7900 */  sll   $t7, $t6, 4
/* 10C580 7F0D7A50 030B4826 */  xor   $t1, $t8, $t3
/* 10C584 7F0D7A54 312A0080 */  andi  $t2, $t1, 0x80
/* 10C588 7F0D7A58 014C7024 */  and   $t6, $t2, $t4
/* 10C58C 7F0D7A5C 01AF4025 */  or    $t0, $t5, $t7
/* 10C590 7F0D7A60 000E6943 */  sra   $t5, $t6, 5
/* 10C594 7F0D7A64 2E180001 */  sltiu $t8, $s0, 1
/* 10C598 7F0D7A68 00184980 */  sll   $t1, $t8, 6
/* 10C59C 7F0D7A6C 010D7825 */  or    $t7, $t0, $t5
/* 10C5A0 7F0D7A70 01E98825 */  or    $s1, $t7, $t1
/* 10C5A4 7F0D7A74 323900FF */  andi  $t9, $s1, 0xff
/* 10C5A8 7F0D7A78 03208825 */  move  $s1, $t9
/* 10C5AC 7F0D7A7C 10002B5F */  b     .L7F0E27FC
/* 10C5B0 7F0D7A80 AFB80048 */   sw    $t8, 0x48($sp)
spectrum_op_85:
/* 10C5B4 7F0D7A84 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10C5B8 7F0D7A88 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10C5BC 7F0D7A8C 93A80287 */  lbu   $t0, 0x287($sp)
/* 10C5C0 7F0D7A90 254C0004 */  addiu $t4, $t2, 4
/* 10C5C4 7F0D7A94 15C00003 */  bnez  $t6, .L7F0D7AA4
/* 10C5C8 7F0D7A98 AFAC028C */   sw    $t4, 0x28c($sp)
/* 10C5CC 7F0D7A9C 1000000C */  b     .L7F0D7AD0
/* 10C5D0 7F0D7AA0 A3B701DB */   sb    $s7, 0x1db($sp)
.L7F0D7AA4:
/* 10C5D4 7F0D7AA4 24010001 */  li    $at, 1
/* 10C5D8 7F0D7AA8 15010005 */  bne   $t0, $at, .L7F0D7AC0
/* 10C5DC 7F0D7AAC 97B80294 */   lhu   $t8, 0x294($sp)
/* 10C5E0 7F0D7AB0 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10C5E4 7F0D7AB4 31AF00FF */  andi  $t7, $t5, 0xff
/* 10C5E8 7F0D7AB8 10000003 */  b     .L7F0D7AC8
/* 10C5EC 7F0D7ABC AFAF0048 */   sw    $t7, 0x48($sp)
.L7F0D7AC0:
/* 10C5F0 7F0D7AC0 330B00FF */  andi  $t3, $t8, 0xff
/* 10C5F4 7F0D7AC4 AFAB0048 */  sw    $t3, 0x48($sp)
.L7F0D7AC8:
/* 10C5F8 7F0D7AC8 8FA90048 */  lw    $t1, 0x48($sp)
/* 10C5FC 7F0D7ACC A3A901DB */  sb    $t1, 0x1db($sp)
.L7F0D7AD0:
/* 10C600 7F0D7AD0 93B901DB */  lbu   $t9, 0x1db($sp)
/* 10C604 7F0D7AD4 320F000F */  andi  $t7, $s0, 0xf
/* 10C608 7F0D7AD8 2401000F */  li    $at, 15
/* 10C60C 7F0D7ADC 02196021 */  addu  $t4, $s0, $t9
/* 10C610 7F0D7AE0 318E00A8 */  andi  $t6, $t4, 0xa8
/* 10C614 7F0D7AE4 000C4203 */  sra   $t0, $t4, 8
/* 10C618 7F0D7AE8 3338000F */  andi  $t8, $t9, 0xf
/* 10C61C 7F0D7AEC 01F85821 */  addu  $t3, $t7, $t8
/* 10C620 7F0D7AF0 01C86825 */  or    $t5, $t6, $t0
/* 10C624 7F0D7AF4 02004027 */  not   $t0, $s0
/* 10C628 7F0D7AF8 002B482A */  slt   $t1, $at, $t3
/* 10C62C 7F0D7AFC 01905826 */  xor   $t3, $t4, $s0
/* 10C630 7F0D7B00 A7AC01DC */  sh    $t4, 0x1dc($sp)
/* 10C634 7F0D7B04 93B001DD */  lbu   $s0, 0x1dd($sp)
/* 10C638 7F0D7B08 00095100 */  sll   $t2, $t1, 4
/* 10C63C 7F0D7B0C 01197826 */  xor   $t7, $t0, $t9
/* 10C640 7F0D7B10 31F80080 */  andi  $t8, $t7, 0x80
/* 10C644 7F0D7B14 030B4824 */  and   $t1, $t8, $t3
/* 10C648 7F0D7B18 01AA7025 */  or    $t6, $t5, $t2
/* 10C64C 7F0D7B1C 00096943 */  sra   $t5, $t1, 5
/* 10C650 7F0D7B20 2E080001 */  sltiu $t0, $s0, 1
/* 10C654 7F0D7B24 00087980 */  sll   $t7, $t0, 6
/* 10C658 7F0D7B28 01CD5025 */  or    $t2, $t6, $t5
/* 10C65C 7F0D7B2C 014F8825 */  or    $s1, $t2, $t7
/* 10C660 7F0D7B30 322C00FF */  andi  $t4, $s1, 0xff
/* 10C664 7F0D7B34 01808825 */  move  $s1, $t4
/* 10C668 7F0D7B38 10002B30 */  b     .L7F0E27FC
/* 10C66C 7F0D7B3C AFA80048 */   sw    $t0, 0x48($sp)
spectrum_op_86:
/* 10C670 7F0D7B40 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10C674 7F0D7B44 93A90287 */  lbu   $t1, 0x287($sp)
/* 10C678 7F0D7B48 00167200 */  sll   $t6, $s6, 8
/* 10C67C 7F0D7B4C 270B0007 */  addiu $t3, $t8, 7
/* 10C680 7F0D7B50 15200004 */  bnez  $t1, .L7F0D7B64
/* 10C684 7F0D7B54 AFAB028C */   sw    $t3, 0x28c($sp)
/* 10C688 7F0D7B58 01D76825 */  or    $t5, $t6, $s7
/* 10C68C 7F0D7B5C 10000016 */  b     .L7F0D7BB8
/* 10C690 7F0D7B60 A7AD01D8 */   sh    $t5, 0x1d8($sp)
.L7F0D7B64:
/* 10C694 7F0D7B64 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10C698 7F0D7B68 93B90287 */  lbu   $t9, 0x287($sp)
/* 10C69C 7F0D7B6C 24010001 */  li    $at, 1
/* 10C6A0 7F0D7B70 25480008 */  addiu $t0, $t2, 8
/* 10C6A4 7F0D7B74 17210004 */  bne   $t9, $at, .L7F0D7B88
/* 10C6A8 7F0D7B78 AFA8028C */   sw    $t0, 0x28c($sp)
/* 10C6AC 7F0D7B7C 97AF0296 */  lhu   $t7, 0x296($sp)
/* 10C6B0 7F0D7B80 10000003 */  b     .L7F0D7B90
/* 10C6B4 7F0D7B84 AFAF0048 */   sw    $t7, 0x48($sp)
.L7F0D7B88:
/* 10C6B8 7F0D7B88 97AC0294 */  lhu   $t4, 0x294($sp)
/* 10C6BC 7F0D7B8C AFAC0048 */  sw    $t4, 0x48($sp)
.L7F0D7B90:
/* 10C6C0 7F0D7B90 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 10C6C4 7F0D7B94 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10C6C8 7F0D7B98 97B80298 */  lhu   $t8, 0x298($sp)
/* 10C6CC 7F0D7B9C 8FAD0048 */  lw    $t5, 0x48($sp)
/* 10C6D0 7F0D7BA0 030B4821 */  addu  $t1, $t8, $t3
/* 10C6D4 7F0D7BA4 812E0000 */  lb    $t6, ($t1)
/* 10C6D8 7F0D7BA8 27080001 */  addiu $t0, $t8, 1
/* 10C6DC 7F0D7BAC A7A80298 */  sh    $t0, 0x298($sp)
/* 10C6E0 7F0D7BB0 01CD5021 */  addu  $t2, $t6, $t5
/* 10C6E4 7F0D7BB4 A7AA01D8 */  sh    $t2, 0x1d8($sp)
.L7F0D7BB8:
/* 10C6E8 7F0D7BB8 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 10C6EC 7F0D7BBC 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10C6F0 7F0D7BC0 97B901D8 */  lhu   $t9, 0x1d8($sp)
/* 10C6F4 7F0D7BC4 2401000F */  li    $at, 15
/* 10C6F8 7F0D7BC8 032F6021 */  addu  $t4, $t9, $t7
/* 10C6FC 7F0D7BCC 918B0000 */  lbu   $t3, ($t4)
/* 10C700 7F0D7BD0 3219000F */  andi  $t9, $s0, 0xf
/* 10C704 7F0D7BD4 020B7021 */  addu  $t6, $s0, $t3
/* 10C708 7F0D7BD8 31CD00A8 */  andi  $t5, $t6, 0xa8
/* 10C70C 7F0D7BDC 000E5203 */  sra   $t2, $t6, 8
/* 10C710 7F0D7BE0 3168000F */  andi  $t0, $t3, 0xf
/* 10C714 7F0D7BE4 03287821 */  addu  $t7, $t9, $t0
/* 10C718 7F0D7BE8 01AAC025 */  or    $t8, $t5, $t2
/* 10C71C 7F0D7BEC 02005027 */  not   $t2, $s0
/* 10C720 7F0D7BF0 002F602A */  slt   $t4, $at, $t7
/* 10C724 7F0D7BF4 01D07826 */  xor   $t7, $t6, $s0
/* 10C728 7F0D7BF8 A7AE01D6 */  sh    $t6, 0x1d6($sp)
/* 10C72C 7F0D7BFC 93B001D7 */  lbu   $s0, 0x1d7($sp)
/* 10C730 7F0D7C00 000C4900 */  sll   $t1, $t4, 4
/* 10C734 7F0D7C04 014BC826 */  xor   $t9, $t2, $t3
/* 10C738 7F0D7C08 33280080 */  andi  $t0, $t9, 0x80
/* 10C73C 7F0D7C0C 010F6024 */  and   $t4, $t0, $t7
/* 10C740 7F0D7C10 03096825 */  or    $t5, $t8, $t1
/* 10C744 7F0D7C14 000CC143 */  sra   $t8, $t4, 5
/* 10C748 7F0D7C18 2E0A0001 */  sltiu $t2, $s0, 1
/* 10C74C 7F0D7C1C 000AC980 */  sll   $t9, $t2, 6
/* 10C750 7F0D7C20 01B84825 */  or    $t1, $t5, $t8
/* 10C754 7F0D7C24 01398825 */  or    $s1, $t1, $t9
/* 10C758 7F0D7C28 322E00FF */  andi  $t6, $s1, 0xff
/* 10C75C 7F0D7C2C 01C08825 */  move  $s1, $t6
/* 10C760 7F0D7C30 AFAA0048 */  sw    $t2, 0x48($sp)
/* 10C764 7F0D7C34 10002AF1 */  b     .L7F0E27FC
/* 10C768 7F0D7C38 A3AB01D5 */   sb    $t3, 0x1d5($sp)
spectrum_op_87:
/* 10C76C 7F0D7C3C 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10C770 7F0D7C40 320C00FF */  andi  $t4, $s0, 0xff
/* 10C774 7F0D7C44 020CC021 */  addu  $t8, $s0, $t4
/* 10C778 7F0D7C48 250F0004 */  addiu $t7, $t0, 4
/* 10C77C 7F0D7C4C 330900A8 */  andi  $t1, $t8, 0xa8
/* 10C780 7F0D7C50 00185203 */  sra   $t2, $t8, 8
/* 10C784 7F0D7C54 318E000F */  andi  $t6, $t4, 0xf
/* 10C788 7F0D7C58 3219000F */  andi  $t9, $s0, 0xf
/* 10C78C 7F0D7C5C AFAF028C */  sw    $t7, 0x28c($sp)
/* 10C790 7F0D7C60 032E4021 */  addu  $t0, $t9, $t6
/* 10C794 7F0D7C64 012A5825 */  or    $t3, $t1, $t2
/* 10C798 7F0D7C68 2401000F */  li    $at, 15
/* 10C79C 7F0D7C6C 0028782A */  slt   $t7, $at, $t0
/* 10C7A0 7F0D7C70 02005027 */  not   $t2, $s0
/* 10C7A4 7F0D7C74 03104026 */  xor   $t0, $t8, $s0
/* 10C7A8 7F0D7C78 A7B801D2 */  sh    $t8, 0x1d2($sp)
/* 10C7AC 7F0D7C7C A3B001D1 */  sb    $s0, 0x1d1($sp)
/* 10C7B0 7F0D7C80 93B001D3 */  lbu   $s0, 0x1d3($sp)
/* 10C7B4 7F0D7C84 014CC826 */  xor   $t9, $t2, $t4
/* 10C7B8 7F0D7C88 000F6900 */  sll   $t5, $t7, 4
/* 10C7BC 7F0D7C8C 332E0080 */  andi  $t6, $t9, 0x80
/* 10C7C0 7F0D7C90 01C87824 */  and   $t7, $t6, $t0
/* 10C7C4 7F0D7C94 016D4825 */  or    $t1, $t3, $t5
/* 10C7C8 7F0D7C98 000F5943 */  sra   $t3, $t7, 5
/* 10C7CC 7F0D7C9C 2E0A0001 */  sltiu $t2, $s0, 1
/* 10C7D0 7F0D7CA0 000AC980 */  sll   $t9, $t2, 6
/* 10C7D4 7F0D7CA4 012B6825 */  or    $t5, $t1, $t3
/* 10C7D8 7F0D7CA8 01B98825 */  or    $s1, $t5, $t9
/* 10C7DC 7F0D7CAC 323800FF */  andi  $t8, $s1, 0xff
/* 10C7E0 7F0D7CB0 03008825 */  move  $s1, $t8
/* 10C7E4 7F0D7CB4 10002AD1 */  b     .L7F0E27FC
/* 10C7E8 7F0D7CB8 AFAA0048 */   sw    $t2, 0x48($sp)
spectrum_op_88:
/* 10C7EC 7F0D7CBC 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10C7F0 7F0D7CC0 324F00FF */  andi  $t7, $s2, 0xff
/* 10C7F4 7F0D7CC4 020F4821 */  addu  $t1, $s0, $t7
/* 10C7F8 7F0D7CC8 322B0001 */  andi  $t3, $s1, 1
/* 10C7FC 7F0D7CCC 012B6821 */  addu  $t5, $t1, $t3
/* 10C800 7F0D7CD0 25C80004 */  addiu $t0, $t6, 4
/* 10C804 7F0D7CD4 AFA8028C */  sw    $t0, 0x28c($sp)
/* 10C808 7F0D7CD8 3208000F */  andi  $t0, $s0, 0xf
/* 10C80C 7F0D7CDC 31E9000F */  andi  $t1, $t7, 0xf
/* 10C810 7F0D7CE0 01095821 */  addu  $t3, $t0, $t1
/* 10C814 7F0D7CE4 31AC00A8 */  andi  $t4, $t5, 0xa8
/* 10C818 7F0D7CE8 000DC203 */  sra   $t8, $t5, 8
/* 10C81C 7F0D7CEC 322A0001 */  andi  $t2, $s1, 1
/* 10C820 7F0D7CF0 016AC821 */  addu  $t9, $t3, $t2
/* 10C824 7F0D7CF4 01987025 */  or    $t6, $t4, $t8
/* 10C828 7F0D7CF8 2401000F */  li    $at, 15
/* 10C82C 7F0D7CFC 0039602A */  slt   $t4, $at, $t9
/* 10C830 7F0D7D00 000CC100 */  sll   $t8, $t4, 4
/* 10C834 7F0D7D04 01A0C825 */  move  $t9, $t5
/* 10C838 7F0D7D08 02004827 */  not   $t1, $s0
/* 10C83C 7F0D7D0C 03306026 */  xor   $t4, $t9, $s0
/* 10C840 7F0D7D10 A7AD01CE */  sh    $t5, 0x1ce($sp)
/* 10C844 7F0D7D14 93B001CF */  lbu   $s0, 0x1cf($sp)
/* 10C848 7F0D7D18 012F5826 */  xor   $t3, $t1, $t7
/* 10C84C 7F0D7D1C 316A0080 */  andi  $t2, $t3, 0x80
/* 10C850 7F0D7D20 01D84025 */  or    $t0, $t6, $t8
/* 10C854 7F0D7D24 014C7024 */  and   $t6, $t2, $t4
/* 10C858 7F0D7D28 000EC143 */  sra   $t8, $t6, 5
/* 10C85C 7F0D7D2C 2E0F0001 */  sltiu $t7, $s0, 1
/* 10C860 7F0D7D30 000F6980 */  sll   $t5, $t7, 6
/* 10C864 7F0D7D34 01184825 */  or    $t1, $t0, $t8
/* 10C868 7F0D7D38 012D8825 */  or    $s1, $t1, $t5
/* 10C86C 7F0D7D3C 323900FF */  andi  $t9, $s1, 0xff
/* 10C870 7F0D7D40 03208825 */  move  $s1, $t9
/* 10C874 7F0D7D44 AFAF0048 */  sw    $t7, 0x48($sp)
/* 10C878 7F0D7D48 10002AAC */  b     .L7F0E27FC
/* 10C87C 7F0D7D4C A3B201CD */   sb    $s2, 0x1cd($sp)
spectrum_op_89:
/* 10C880 7F0D7D50 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10C884 7F0D7D54 326E00FF */  andi  $t6, $s3, 0xff
/* 10C888 7F0D7D58 020E4021 */  addu  $t0, $s0, $t6
/* 10C88C 7F0D7D5C 32380001 */  andi  $t8, $s1, 1
/* 10C890 7F0D7D60 01184821 */  addu  $t1, $t0, $t8
/* 10C894 7F0D7D64 254C0004 */  addiu $t4, $t2, 4
/* 10C898 7F0D7D68 AFAC028C */  sw    $t4, 0x28c($sp)
/* 10C89C 7F0D7D6C 320C000F */  andi  $t4, $s0, 0xf
/* 10C8A0 7F0D7D70 31C8000F */  andi  $t0, $t6, 0xf
/* 10C8A4 7F0D7D74 0188C021 */  addu  $t8, $t4, $t0
/* 10C8A8 7F0D7D78 312B00A8 */  andi  $t3, $t1, 0xa8
/* 10C8AC 7F0D7D7C 0009CA03 */  sra   $t9, $t1, 8
/* 10C8B0 7F0D7D80 322F0001 */  andi  $t7, $s1, 1
/* 10C8B4 7F0D7D84 030F6821 */  addu  $t5, $t8, $t7
/* 10C8B8 7F0D7D88 01795025 */  or    $t2, $t3, $t9
/* 10C8BC 7F0D7D8C 2401000F */  li    $at, 15
/* 10C8C0 7F0D7D90 002D582A */  slt   $t3, $at, $t5
/* 10C8C4 7F0D7D94 000BC900 */  sll   $t9, $t3, 4
/* 10C8C8 7F0D7D98 01206825 */  move  $t5, $t1
/* 10C8CC 7F0D7D9C 02004027 */  not   $t0, $s0
/* 10C8D0 7F0D7DA0 01B05826 */  xor   $t3, $t5, $s0
/* 10C8D4 7F0D7DA4 A7A901CA */  sh    $t1, 0x1ca($sp)
/* 10C8D8 7F0D7DA8 93B001CB */  lbu   $s0, 0x1cb($sp)
/* 10C8DC 7F0D7DAC 010EC026 */  xor   $t8, $t0, $t6
/* 10C8E0 7F0D7DB0 330F0080 */  andi  $t7, $t8, 0x80
/* 10C8E4 7F0D7DB4 01596025 */  or    $t4, $t2, $t9
/* 10C8E8 7F0D7DB8 01EB5024 */  and   $t2, $t7, $t3
/* 10C8EC 7F0D7DBC 000AC943 */  sra   $t9, $t2, 5
/* 10C8F0 7F0D7DC0 2E0E0001 */  sltiu $t6, $s0, 1
/* 10C8F4 7F0D7DC4 000E4980 */  sll   $t1, $t6, 6
/* 10C8F8 7F0D7DC8 01994025 */  or    $t0, $t4, $t9
/* 10C8FC 7F0D7DCC 01098825 */  or    $s1, $t0, $t1
/* 10C900 7F0D7DD0 322D00FF */  andi  $t5, $s1, 0xff
/* 10C904 7F0D7DD4 01A08825 */  move  $s1, $t5
/* 10C908 7F0D7DD8 AFAE0048 */  sw    $t6, 0x48($sp)
/* 10C90C 7F0D7DDC 10002A87 */  b     .L7F0E27FC
/* 10C910 7F0D7DE0 A3B301C9 */   sb    $s3, 0x1c9($sp)
spectrum_op_8A:
/* 10C914 7F0D7DE4 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10C918 7F0D7DE8 328A00FF */  andi  $t2, $s4, 0xff
/* 10C91C 7F0D7DEC 020A6021 */  addu  $t4, $s0, $t2
/* 10C920 7F0D7DF0 32390001 */  andi  $t9, $s1, 1
/* 10C924 7F0D7DF4 01994021 */  addu  $t0, $t4, $t9
/* 10C928 7F0D7DF8 25EB0004 */  addiu $t3, $t7, 4
/* 10C92C 7F0D7DFC AFAB028C */  sw    $t3, 0x28c($sp)
/* 10C930 7F0D7E00 320B000F */  andi  $t3, $s0, 0xf
/* 10C934 7F0D7E04 314C000F */  andi  $t4, $t2, 0xf
/* 10C938 7F0D7E08 016CC821 */  addu  $t9, $t3, $t4
/* 10C93C 7F0D7E0C 311800A8 */  andi  $t8, $t0, 0xa8
/* 10C940 7F0D7E10 00086A03 */  sra   $t5, $t0, 8
/* 10C944 7F0D7E14 322E0001 */  andi  $t6, $s1, 1
/* 10C948 7F0D7E18 032E4821 */  addu  $t1, $t9, $t6
/* 10C94C 7F0D7E1C 030D7825 */  or    $t7, $t8, $t5
/* 10C950 7F0D7E20 2401000F */  li    $at, 15
/* 10C954 7F0D7E24 0029C02A */  slt   $t8, $at, $t1
/* 10C958 7F0D7E28 00186900 */  sll   $t5, $t8, 4
/* 10C95C 7F0D7E2C 01004825 */  move  $t1, $t0
/* 10C960 7F0D7E30 02006027 */  not   $t4, $s0
/* 10C964 7F0D7E34 0130C026 */  xor   $t8, $t1, $s0
/* 10C968 7F0D7E38 A7A801C6 */  sh    $t0, 0x1c6($sp)
/* 10C96C 7F0D7E3C 93B001C7 */  lbu   $s0, 0x1c7($sp)
/* 10C970 7F0D7E40 018AC826 */  xor   $t9, $t4, $t2
/* 10C974 7F0D7E44 332E0080 */  andi  $t6, $t9, 0x80
/* 10C978 7F0D7E48 01ED5825 */  or    $t3, $t7, $t5
/* 10C97C 7F0D7E4C 01D87824 */  and   $t7, $t6, $t8
/* 10C980 7F0D7E50 000F6943 */  sra   $t5, $t7, 5
/* 10C984 7F0D7E54 2E0A0001 */  sltiu $t2, $s0, 1
/* 10C988 7F0D7E58 000A4180 */  sll   $t0, $t2, 6
/* 10C98C 7F0D7E5C 016D6025 */  or    $t4, $t3, $t5
/* 10C990 7F0D7E60 01888825 */  or    $s1, $t4, $t0
/* 10C994 7F0D7E64 322900FF */  andi  $t1, $s1, 0xff
/* 10C998 7F0D7E68 01208825 */  move  $s1, $t1
/* 10C99C 7F0D7E6C AFAA0048 */  sw    $t2, 0x48($sp)
/* 10C9A0 7F0D7E70 10002A62 */  b     .L7F0E27FC
/* 10C9A4 7F0D7E74 A3B401C5 */   sb    $s4, 0x1c5($sp)
spectrum_op_8B:
/* 10C9A8 7F0D7E78 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10C9AC 7F0D7E7C 32AF00FF */  andi  $t7, $s5, 0xff
/* 10C9B0 7F0D7E80 020F5821 */  addu  $t3, $s0, $t7
/* 10C9B4 7F0D7E84 322D0001 */  andi  $t5, $s1, 1
/* 10C9B8 7F0D7E88 016D6021 */  addu  $t4, $t3, $t5
/* 10C9BC 7F0D7E8C 25D80004 */  addiu $t8, $t6, 4
/* 10C9C0 7F0D7E90 AFB8028C */  sw    $t8, 0x28c($sp)
/* 10C9C4 7F0D7E94 3218000F */  andi  $t8, $s0, 0xf
/* 10C9C8 7F0D7E98 31EB000F */  andi  $t3, $t7, 0xf
/* 10C9CC 7F0D7E9C 030B6821 */  addu  $t5, $t8, $t3
/* 10C9D0 7F0D7EA0 319900A8 */  andi  $t9, $t4, 0xa8
/* 10C9D4 7F0D7EA4 000C4A03 */  sra   $t1, $t4, 8
/* 10C9D8 7F0D7EA8 322A0001 */  andi  $t2, $s1, 1
/* 10C9DC 7F0D7EAC 01AA4021 */  addu  $t0, $t5, $t2
/* 10C9E0 7F0D7EB0 03297025 */  or    $t6, $t9, $t1
/* 10C9E4 7F0D7EB4 2401000F */  li    $at, 15
/* 10C9E8 7F0D7EB8 0028C82A */  slt   $t9, $at, $t0
/* 10C9EC 7F0D7EBC 00194900 */  sll   $t1, $t9, 4
/* 10C9F0 7F0D7EC0 01804025 */  move  $t0, $t4
/* 10C9F4 7F0D7EC4 02005827 */  not   $t3, $s0
/* 10C9F8 7F0D7EC8 0110C826 */  xor   $t9, $t0, $s0
/* 10C9FC 7F0D7ECC A7AC01C2 */  sh    $t4, 0x1c2($sp)
/* 10CA00 7F0D7ED0 93B001C3 */  lbu   $s0, 0x1c3($sp)
/* 10CA04 7F0D7ED4 016F6826 */  xor   $t5, $t3, $t7
/* 10CA08 7F0D7ED8 31AA0080 */  andi  $t2, $t5, 0x80
/* 10CA0C 7F0D7EDC 01C9C025 */  or    $t8, $t6, $t1
/* 10CA10 7F0D7EE0 01597024 */  and   $t6, $t2, $t9
/* 10CA14 7F0D7EE4 000E4943 */  sra   $t1, $t6, 5
/* 10CA18 7F0D7EE8 2E0F0001 */  sltiu $t7, $s0, 1
/* 10CA1C 7F0D7EEC 000F6180 */  sll   $t4, $t7, 6
/* 10CA20 7F0D7EF0 03095825 */  or    $t3, $t8, $t1
/* 10CA24 7F0D7EF4 016C8825 */  or    $s1, $t3, $t4
/* 10CA28 7F0D7EF8 322800FF */  andi  $t0, $s1, 0xff
/* 10CA2C 7F0D7EFC 01008825 */  move  $s1, $t0
/* 10CA30 7F0D7F00 AFAF0048 */  sw    $t7, 0x48($sp)
/* 10CA34 7F0D7F04 10002A3D */  b     .L7F0E27FC
/* 10CA38 7F0D7F08 A3B501C1 */   sb    $s5, 0x1c1($sp)
spectrum_op_8C:
/* 10CA3C 7F0D7F0C 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10CA40 7F0D7F10 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10CA44 7F0D7F14 93B80287 */  lbu   $t8, 0x287($sp)
/* 10CA48 7F0D7F18 25590004 */  addiu $t9, $t2, 4
/* 10CA4C 7F0D7F1C 15C00003 */  bnez  $t6, .L7F0D7F2C
/* 10CA50 7F0D7F20 AFB9028C */   sw    $t9, 0x28c($sp)
/* 10CA54 7F0D7F24 1000000C */  b     .L7F0D7F58
/* 10CA58 7F0D7F28 A3B601BD */   sb    $s6, 0x1bd($sp)
.L7F0D7F2C:
/* 10CA5C 7F0D7F2C 24010001 */  li    $at, 1
/* 10CA60 7F0D7F30 17010005 */  bne   $t8, $at, .L7F0D7F48
/* 10CA64 7F0D7F34 97AF0294 */   lhu   $t7, 0x294($sp)
/* 10CA68 7F0D7F38 97A90296 */  lhu   $t1, 0x296($sp)
/* 10CA6C 7F0D7F3C 00095A03 */  sra   $t3, $t1, 8
/* 10CA70 7F0D7F40 10000003 */  b     .L7F0D7F50
/* 10CA74 7F0D7F44 AFAB0048 */   sw    $t3, 0x48($sp)
.L7F0D7F48:
/* 10CA78 7F0D7F48 000F6A03 */  sra   $t5, $t7, 8
/* 10CA7C 7F0D7F4C AFAD0048 */  sw    $t5, 0x48($sp)
.L7F0D7F50:
/* 10CA80 7F0D7F50 8FAC0048 */  lw    $t4, 0x48($sp)
/* 10CA84 7F0D7F54 A3AC01BD */  sb    $t4, 0x1bd($sp)
.L7F0D7F58:
/* 10CA88 7F0D7F58 93A801BD */  lbu   $t0, 0x1bd($sp)
/* 10CA8C 7F0D7F5C 32390001 */  andi  $t9, $s1, 1
/* 10CA90 7F0D7F60 320C000F */  andi  $t4, $s0, 0xf
/* 10CA94 7F0D7F64 02085021 */  addu  $t2, $s0, $t0
/* 10CA98 7F0D7F68 01597021 */  addu  $t6, $t2, $t9
/* 10CA9C 7F0D7F6C 310A000F */  andi  $t2, $t0, 0xf
/* 10CAA0 7F0D7F70 018AC821 */  addu  $t9, $t4, $t2
/* 10CAA4 7F0D7F74 31C900A8 */  andi  $t1, $t6, 0xa8
/* 10CAA8 7F0D7F78 000E7A03 */  sra   $t7, $t6, 8
/* 10CAAC 7F0D7F7C 32380001 */  andi  $t8, $s1, 1
/* 10CAB0 7F0D7F80 03385821 */  addu  $t3, $t9, $t8
/* 10CAB4 7F0D7F84 012F6825 */  or    $t5, $t1, $t7
/* 10CAB8 7F0D7F88 2401000F */  li    $at, 15
/* 10CABC 7F0D7F8C 002B482A */  slt   $t1, $at, $t3
/* 10CAC0 7F0D7F90 00097900 */  sll   $t7, $t1, 4
/* 10CAC4 7F0D7F94 01C05825 */  move  $t3, $t6
/* 10CAC8 7F0D7F98 02005027 */  not   $t2, $s0
/* 10CACC 7F0D7F9C 01704826 */  xor   $t1, $t3, $s0
/* 10CAD0 7F0D7FA0 A7AE01BE */  sh    $t6, 0x1be($sp)
/* 10CAD4 7F0D7FA4 93B001BF */  lbu   $s0, 0x1bf($sp)
/* 10CAD8 7F0D7FA8 0148C826 */  xor   $t9, $t2, $t0
/* 10CADC 7F0D7FAC 33380080 */  andi  $t8, $t9, 0x80
/* 10CAE0 7F0D7FB0 01AF6025 */  or    $t4, $t5, $t7
/* 10CAE4 7F0D7FB4 03096824 */  and   $t5, $t8, $t1
/* 10CAE8 7F0D7FB8 000D7943 */  sra   $t7, $t5, 5
/* 10CAEC 7F0D7FBC 2E080001 */  sltiu $t0, $s0, 1
/* 10CAF0 7F0D7FC0 00087180 */  sll   $t6, $t0, 6
/* 10CAF4 7F0D7FC4 018F5025 */  or    $t2, $t4, $t7
/* 10CAF8 7F0D7FC8 014E8825 */  or    $s1, $t2, $t6
/* 10CAFC 7F0D7FCC 322B00FF */  andi  $t3, $s1, 0xff
/* 10CB00 7F0D7FD0 01608825 */  move  $s1, $t3
/* 10CB04 7F0D7FD4 10002A09 */  b     .L7F0E27FC
/* 10CB08 7F0D7FD8 AFA80048 */   sw    $t0, 0x48($sp)
spectrum_op_8D:
/* 10CB0C 7F0D7FDC 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10CB10 7F0D7FE0 93AD0287 */  lbu   $t5, 0x287($sp)
/* 10CB14 7F0D7FE4 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10CB18 7F0D7FE8 27090004 */  addiu $t1, $t8, 4
/* 10CB1C 7F0D7FEC 15A00003 */  bnez  $t5, .L7F0D7FFC
/* 10CB20 7F0D7FF0 AFA9028C */   sw    $t1, 0x28c($sp)
/* 10CB24 7F0D7FF4 1000000C */  b     .L7F0D8028
/* 10CB28 7F0D7FF8 A3B701B9 */   sb    $s7, 0x1b9($sp)
.L7F0D7FFC:
/* 10CB2C 7F0D7FFC 24010001 */  li    $at, 1
/* 10CB30 7F0D8000 15810005 */  bne   $t4, $at, .L7F0D8018
/* 10CB34 7F0D8004 97A80294 */   lhu   $t0, 0x294($sp)
/* 10CB38 7F0D8008 97AF0296 */  lhu   $t7, 0x296($sp)
/* 10CB3C 7F0D800C 31EA00FF */  andi  $t2, $t7, 0xff
/* 10CB40 7F0D8010 10000003 */  b     .L7F0D8020
/* 10CB44 7F0D8014 AFAA0048 */   sw    $t2, 0x48($sp)
.L7F0D8018:
/* 10CB48 7F0D8018 311900FF */  andi  $t9, $t0, 0xff
/* 10CB4C 7F0D801C AFB90048 */  sw    $t9, 0x48($sp)
.L7F0D8020:
/* 10CB50 7F0D8020 8FAE0048 */  lw    $t6, 0x48($sp)
/* 10CB54 7F0D8024 A3AE01B9 */  sb    $t6, 0x1b9($sp)
.L7F0D8028:
/* 10CB58 7F0D8028 93AB01B9 */  lbu   $t3, 0x1b9($sp)
/* 10CB5C 7F0D802C 32290001 */  andi  $t1, $s1, 1
/* 10CB60 7F0D8030 320E000F */  andi  $t6, $s0, 0xf
/* 10CB64 7F0D8034 020BC021 */  addu  $t8, $s0, $t3
/* 10CB68 7F0D8038 03096821 */  addu  $t5, $t8, $t1
/* 10CB6C 7F0D803C 3178000F */  andi  $t8, $t3, 0xf
/* 10CB70 7F0D8040 01D84821 */  addu  $t1, $t6, $t8
/* 10CB74 7F0D8044 31AF00A8 */  andi  $t7, $t5, 0xa8
/* 10CB78 7F0D8048 000D4203 */  sra   $t0, $t5, 8
/* 10CB7C 7F0D804C 322C0001 */  andi  $t4, $s1, 1
/* 10CB80 7F0D8050 012C5021 */  addu  $t2, $t1, $t4
/* 10CB84 7F0D8054 01E8C825 */  or    $t9, $t7, $t0
/* 10CB88 7F0D8058 2401000F */  li    $at, 15
/* 10CB8C 7F0D805C 002A782A */  slt   $t7, $at, $t2
/* 10CB90 7F0D8060 000F4100 */  sll   $t0, $t7, 4
/* 10CB94 7F0D8064 01A05025 */  move  $t2, $t5
/* 10CB98 7F0D8068 0200C027 */  not   $t8, $s0
/* 10CB9C 7F0D806C 01507826 */  xor   $t7, $t2, $s0
/* 10CBA0 7F0D8070 A7AD01BA */  sh    $t5, 0x1ba($sp)
/* 10CBA4 7F0D8074 93B001BB */  lbu   $s0, 0x1bb($sp)
/* 10CBA8 7F0D8078 030B4826 */  xor   $t1, $t8, $t3
/* 10CBAC 7F0D807C 312C0080 */  andi  $t4, $t1, 0x80
/* 10CBB0 7F0D8080 03287025 */  or    $t6, $t9, $t0
/* 10CBB4 7F0D8084 018FC824 */  and   $t9, $t4, $t7
/* 10CBB8 7F0D8088 00194143 */  sra   $t0, $t9, 5
/* 10CBBC 7F0D808C 2E0B0001 */  sltiu $t3, $s0, 1
/* 10CBC0 7F0D8090 000B6980 */  sll   $t5, $t3, 6
/* 10CBC4 7F0D8094 01C8C025 */  or    $t8, $t6, $t0
/* 10CBC8 7F0D8098 030D8825 */  or    $s1, $t8, $t5
/* 10CBCC 7F0D809C 322A00FF */  andi  $t2, $s1, 0xff
/* 10CBD0 7F0D80A0 01408825 */  move  $s1, $t2
/* 10CBD4 7F0D80A4 100029D5 */  b     .L7F0E27FC
/* 10CBD8 7F0D80A8 AFAB0048 */   sw    $t3, 0x48($sp)
spectrum_op_8E:
/* 10CBDC 7F0D80AC 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10CBE0 7F0D80B0 93B90287 */  lbu   $t9, 0x287($sp)
/* 10CBE4 7F0D80B4 00167200 */  sll   $t6, $s6, 8
/* 10CBE8 7F0D80B8 258F0007 */  addiu $t7, $t4, 7
/* 10CBEC 7F0D80BC 17200004 */  bnez  $t9, .L7F0D80D0
/* 10CBF0 7F0D80C0 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10CBF4 7F0D80C4 01D74025 */  or    $t0, $t6, $s7
/* 10CBF8 7F0D80C8 10000016 */  b     .L7F0D8124
/* 10CBFC 7F0D80CC A7A801B6 */   sh    $t0, 0x1b6($sp)
.L7F0D80D0:
/* 10CC00 7F0D80D0 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10CC04 7F0D80D4 93A90287 */  lbu   $t1, 0x287($sp)
/* 10CC08 7F0D80D8 24010001 */  li    $at, 1
/* 10CC0C 7F0D80DC 270B0008 */  addiu $t3, $t8, 8
/* 10CC10 7F0D80E0 15210004 */  bne   $t1, $at, .L7F0D80F4
/* 10CC14 7F0D80E4 AFAB028C */   sw    $t3, 0x28c($sp)
/* 10CC18 7F0D80E8 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10CC1C 7F0D80EC 10000003 */  b     .L7F0D80FC
/* 10CC20 7F0D80F0 AFAD0048 */   sw    $t5, 0x48($sp)
.L7F0D80F4:
/* 10CC24 7F0D80F4 97AA0294 */  lhu   $t2, 0x294($sp)
/* 10CC28 7F0D80F8 AFAA0048 */  sw    $t2, 0x48($sp)
.L7F0D80FC:
/* 10CC2C 7F0D80FC 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 10CC30 7F0D8100 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10CC34 7F0D8104 97AC0298 */  lhu   $t4, 0x298($sp)
/* 10CC38 7F0D8108 8FA80048 */  lw    $t0, 0x48($sp)
/* 10CC3C 7F0D810C 018FC821 */  addu  $t9, $t4, $t7
/* 10CC40 7F0D8110 832E0000 */  lb    $t6, ($t9)
/* 10CC44 7F0D8114 258B0001 */  addiu $t3, $t4, 1
/* 10CC48 7F0D8118 A7AB0298 */  sh    $t3, 0x298($sp)
/* 10CC4C 7F0D811C 01C8C021 */  addu  $t8, $t6, $t0
/* 10CC50 7F0D8120 A7B801B6 */  sh    $t8, 0x1b6($sp)
.L7F0D8124:
/* 10CC54 7F0D8124 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 10CC58 7F0D8128 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10CC5C 7F0D812C 97A901B6 */  lhu   $t1, 0x1b6($sp)
/* 10CC60 7F0D8130 322E0001 */  andi  $t6, $s1, 1
/* 10CC64 7F0D8134 32380001 */  andi  $t8, $s1, 1
/* 10CC68 7F0D8138 012D5021 */  addu  $t2, $t1, $t5
/* 10CC6C 7F0D813C 914F0000 */  lbu   $t7, ($t2)
/* 10CC70 7F0D8140 2401000F */  li    $at, 15
/* 10CC74 7F0D8144 020FC821 */  addu  $t9, $s0, $t7
/* 10CC78 7F0D8148 032E4021 */  addu  $t0, $t9, $t6
/* 10CC7C 7F0D814C 3219000F */  andi  $t9, $s0, 0xf
/* 10CC80 7F0D8150 31EA000F */  andi  $t2, $t7, 0xf
/* 10CC84 7F0D8154 032A7021 */  addu  $t6, $t9, $t2
/* 10CC88 7F0D8158 310C00A8 */  andi  $t4, $t0, 0xa8
/* 10CC8C 7F0D815C 00084A03 */  sra   $t1, $t0, 8
/* 10CC90 7F0D8160 01896825 */  or    $t5, $t4, $t1
/* 10CC94 7F0D8164 01D85821 */  addu  $t3, $t6, $t8
/* 10CC98 7F0D8168 002B602A */  slt   $t4, $at, $t3
/* 10CC9C 7F0D816C 000C4900 */  sll   $t1, $t4, 4
/* 10CCA0 7F0D8170 01005825 */  move  $t3, $t0
/* 10CCA4 7F0D8174 02005027 */  not   $t2, $s0
/* 10CCA8 7F0D8178 01706026 */  xor   $t4, $t3, $s0
/* 10CCAC 7F0D817C A7A801B4 */  sh    $t0, 0x1b4($sp)
/* 10CCB0 7F0D8180 93B001B5 */  lbu   $s0, 0x1b5($sp)
/* 10CCB4 7F0D8184 014F7026 */  xor   $t6, $t2, $t7
/* 10CCB8 7F0D8188 31D80080 */  andi  $t8, $t6, 0x80
/* 10CCBC 7F0D818C 01A9C825 */  or    $t9, $t5, $t1
/* 10CCC0 7F0D8190 030C6824 */  and   $t5, $t8, $t4
/* 10CCC4 7F0D8194 A3AF01B3 */  sb    $t7, 0x1b3($sp)
/* 10CCC8 7F0D8198 000D4943 */  sra   $t1, $t5, 5
/* 10CCCC 7F0D819C 2E0F0001 */  sltiu $t7, $s0, 1
/* 10CCD0 7F0D81A0 000F4180 */  sll   $t0, $t7, 6
/* 10CCD4 7F0D81A4 03295025 */  or    $t2, $t9, $t1
/* 10CCD8 7F0D81A8 01488825 */  or    $s1, $t2, $t0
/* 10CCDC 7F0D81AC 322B00FF */  andi  $t3, $s1, 0xff
/* 10CCE0 7F0D81B0 01608825 */  move  $s1, $t3
/* 10CCE4 7F0D81B4 10002991 */  b     .L7F0E27FC
/* 10CCE8 7F0D81B8 AFAF0048 */   sw    $t7, 0x48($sp)
spectrum_op_8F:
/* 10CCEC 7F0D81BC 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10CCF0 7F0D81C0 320D00FF */  andi  $t5, $s0, 0xff
/* 10CCF4 7F0D81C4 020DC821 */  addu  $t9, $s0, $t5
/* 10CCF8 7F0D81C8 32290001 */  andi  $t1, $s1, 1
/* 10CCFC 7F0D81CC 03295021 */  addu  $t2, $t9, $t1
/* 10CD00 7F0D81D0 270C0004 */  addiu $t4, $t8, 4
/* 10CD04 7F0D81D4 AFAC028C */  sw    $t4, 0x28c($sp)
/* 10CD08 7F0D81D8 320C000F */  andi  $t4, $s0, 0xf
/* 10CD0C 7F0D81DC 31B9000F */  andi  $t9, $t5, 0xf
/* 10CD10 7F0D81E0 01994821 */  addu  $t1, $t4, $t9
/* 10CD14 7F0D81E4 314E00A8 */  andi  $t6, $t2, 0xa8
/* 10CD18 7F0D81E8 000A5A03 */  sra   $t3, $t2, 8
/* 10CD1C 7F0D81EC 322F0001 */  andi  $t7, $s1, 1
/* 10CD20 7F0D81F0 012F4021 */  addu  $t0, $t1, $t7
/* 10CD24 7F0D81F4 01CBC025 */  or    $t8, $t6, $t3
/* 10CD28 7F0D81F8 2401000F */  li    $at, 15
/* 10CD2C 7F0D81FC 0028702A */  slt   $t6, $at, $t0
/* 10CD30 7F0D8200 000E5900 */  sll   $t3, $t6, 4
/* 10CD34 7F0D8204 01404025 */  move  $t0, $t2
/* 10CD38 7F0D8208 0200C827 */  not   $t9, $s0
/* 10CD3C 7F0D820C 01107026 */  xor   $t6, $t0, $s0
/* 10CD40 7F0D8210 A7AA01B0 */  sh    $t2, 0x1b0($sp)
/* 10CD44 7F0D8214 A3B001AF */  sb    $s0, 0x1af($sp)
/* 10CD48 7F0D8218 93B001B1 */  lbu   $s0, 0x1b1($sp)
/* 10CD4C 7F0D821C 032D4826 */  xor   $t1, $t9, $t5
/* 10CD50 7F0D8220 312F0080 */  andi  $t7, $t1, 0x80
/* 10CD54 7F0D8224 030B6025 */  or    $t4, $t8, $t3
/* 10CD58 7F0D8228 01EEC024 */  and   $t8, $t7, $t6
/* 10CD5C 7F0D822C 00185943 */  sra   $t3, $t8, 5
/* 10CD60 7F0D8230 2E0D0001 */  sltiu $t5, $s0, 1
/* 10CD64 7F0D8234 000D5180 */  sll   $t2, $t5, 6
/* 10CD68 7F0D8238 018BC825 */  or    $t9, $t4, $t3
/* 10CD6C 7F0D823C 032A8825 */  or    $s1, $t9, $t2
/* 10CD70 7F0D8240 322800FF */  andi  $t0, $s1, 0xff
/* 10CD74 7F0D8244 01008825 */  move  $s1, $t0
/* 10CD78 7F0D8248 1000296C */  b     .L7F0E27FC
/* 10CD7C 7F0D824C AFAD0048 */   sw    $t5, 0x48($sp)
spectrum_op_90:
/* 10CD80 7F0D8250 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10CD84 7F0D8254 325800FF */  andi  $t8, $s2, 0xff
/* 10CD88 7F0D8258 02186023 */  subu  $t4, $s0, $t8
/* 10CD8C 7F0D825C 25EE0004 */  addiu $t6, $t7, 4
/* 10CD90 7F0D8260 318B01FF */  andi  $t3, $t4, 0x1ff
/* 10CD94 7F0D8264 AFAE028C */  sw    $t6, 0x28c($sp)
/* 10CD98 7F0D8268 330E000F */  andi  $t6, $t8, 0xf
/* 10CD9C 7F0D826C 316D00A8 */  andi  $t5, $t3, 0xa8
/* 10CDA0 7F0D8270 000B5203 */  sra   $t2, $t3, 8
/* 10CDA4 7F0D8274 320F000F */  andi  $t7, $s0, 0xf
/* 10CDA8 7F0D8278 01EE602A */  slt   $t4, $t7, $t6
/* 10CDAC 7F0D827C 01AA4025 */  or    $t0, $t5, $t2
/* 10CDB0 7F0D8280 02186826 */  xor   $t5, $s0, $t8
/* 10CDB4 7F0D8284 000CC900 */  sll   $t9, $t4, 4
/* 10CDB8 7F0D8288 01707026 */  xor   $t6, $t3, $s0
/* 10CDBC 7F0D828C A7AB01AC */  sh    $t3, 0x1ac($sp)
/* 10CDC0 7F0D8290 93B001AD */  lbu   $s0, 0x1ad($sp)
/* 10CDC4 7F0D8294 31AA0080 */  andi  $t2, $t5, 0x80
/* 10CDC8 7F0D8298 014E6024 */  and   $t4, $t2, $t6
/* 10CDCC 7F0D829C 01194825 */  or    $t1, $t0, $t9
/* 10CDD0 7F0D82A0 000C4143 */  sra   $t0, $t4, 5
/* 10CDD4 7F0D82A4 01288825 */  or    $s1, $t1, $t0
/* 10CDD8 7F0D82A8 2E0D0001 */  sltiu $t5, $s0, 1
/* 10CDDC 7F0D82AC 000D7980 */  sll   $t7, $t5, 6
/* 10CDE0 7F0D82B0 36380002 */  ori   $t8, $s1, 2
/* 10CDE4 7F0D82B4 030F8825 */  or    $s1, $t8, $t7
/* 10CDE8 7F0D82B8 322A00FF */  andi  $t2, $s1, 0xff
/* 10CDEC 7F0D82BC 01408825 */  move  $s1, $t2
/* 10CDF0 7F0D82C0 AFAD0048 */  sw    $t5, 0x48($sp)
/* 10CDF4 7F0D82C4 1000294D */  b     .L7F0E27FC
/* 10CDF8 7F0D82C8 A3B201AB */   sb    $s2, 0x1ab($sp)
spectrum_op_91:
/* 10CDFC 7F0D82CC 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10CE00 7F0D82D0 326900FF */  andi  $t1, $s3, 0xff
/* 10CE04 7F0D82D4 02094023 */  subu  $t0, $s0, $t1
/* 10CE08 7F0D82D8 25CC0004 */  addiu $t4, $t6, 4
/* 10CE0C 7F0D82DC 311901FF */  andi  $t9, $t0, 0x1ff
/* 10CE10 7F0D82E0 AFAC028C */  sw    $t4, 0x28c($sp)
/* 10CE14 7F0D82E4 312C000F */  andi  $t4, $t1, 0xf
/* 10CE18 7F0D82E8 332D00A8 */  andi  $t5, $t9, 0xa8
/* 10CE1C 7F0D82EC 00197A03 */  sra   $t7, $t9, 8
/* 10CE20 7F0D82F0 320E000F */  andi  $t6, $s0, 0xf
/* 10CE24 7F0D82F4 01CC402A */  slt   $t0, $t6, $t4
/* 10CE28 7F0D82F8 01AF5025 */  or    $t2, $t5, $t7
/* 10CE2C 7F0D82FC 02096826 */  xor   $t5, $s0, $t1
/* 10CE30 7F0D8300 0008C100 */  sll   $t8, $t0, 4
/* 10CE34 7F0D8304 03306026 */  xor   $t4, $t9, $s0
/* 10CE38 7F0D8308 A7B901A8 */  sh    $t9, 0x1a8($sp)
/* 10CE3C 7F0D830C 93B001A9 */  lbu   $s0, 0x1a9($sp)
/* 10CE40 7F0D8310 31AF0080 */  andi  $t7, $t5, 0x80
/* 10CE44 7F0D8314 01EC4024 */  and   $t0, $t7, $t4
/* 10CE48 7F0D8318 01585825 */  or    $t3, $t2, $t8
/* 10CE4C 7F0D831C 00085143 */  sra   $t2, $t0, 5
/* 10CE50 7F0D8320 016A8825 */  or    $s1, $t3, $t2
/* 10CE54 7F0D8324 2E0D0001 */  sltiu $t5, $s0, 1
/* 10CE58 7F0D8328 000D7180 */  sll   $t6, $t5, 6
/* 10CE5C 7F0D832C 36290002 */  ori   $t1, $s1, 2
/* 10CE60 7F0D8330 012E8825 */  or    $s1, $t1, $t6
/* 10CE64 7F0D8334 322F00FF */  andi  $t7, $s1, 0xff
/* 10CE68 7F0D8338 01E08825 */  move  $s1, $t7
/* 10CE6C 7F0D833C AFAD0048 */  sw    $t5, 0x48($sp)
/* 10CE70 7F0D8340 1000292E */  b     .L7F0E27FC
/* 10CE74 7F0D8344 A3B301A7 */   sb    $s3, 0x1a7($sp)
spectrum_op_92:
/* 10CE78 7F0D8348 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10CE7C 7F0D834C 328B00FF */  andi  $t3, $s4, 0xff
/* 10CE80 7F0D8350 020B5023 */  subu  $t2, $s0, $t3
/* 10CE84 7F0D8354 25880004 */  addiu $t0, $t4, 4
/* 10CE88 7F0D8358 315801FF */  andi  $t8, $t2, 0x1ff
/* 10CE8C 7F0D835C AFA8028C */  sw    $t0, 0x28c($sp)
/* 10CE90 7F0D8360 3168000F */  andi  $t0, $t3, 0xf
/* 10CE94 7F0D8364 330D00A8 */  andi  $t5, $t8, 0xa8
/* 10CE98 7F0D8368 00187203 */  sra   $t6, $t8, 8
/* 10CE9C 7F0D836C 320C000F */  andi  $t4, $s0, 0xf
/* 10CEA0 7F0D8370 0188502A */  slt   $t2, $t4, $t0
/* 10CEA4 7F0D8374 01AE7825 */  or    $t7, $t5, $t6
/* 10CEA8 7F0D8378 020B6826 */  xor   $t5, $s0, $t3
/* 10CEAC 7F0D837C 000A4900 */  sll   $t1, $t2, 4
/* 10CEB0 7F0D8380 03104026 */  xor   $t0, $t8, $s0
/* 10CEB4 7F0D8384 A7B801A4 */  sh    $t8, 0x1a4($sp)
/* 10CEB8 7F0D8388 93B001A5 */  lbu   $s0, 0x1a5($sp)
/* 10CEBC 7F0D838C 31AE0080 */  andi  $t6, $t5, 0x80
/* 10CEC0 7F0D8390 01C85024 */  and   $t2, $t6, $t0
/* 10CEC4 7F0D8394 01E9C825 */  or    $t9, $t7, $t1
/* 10CEC8 7F0D8398 000A7943 */  sra   $t7, $t2, 5
/* 10CECC 7F0D839C 032F8825 */  or    $s1, $t9, $t7
/* 10CED0 7F0D83A0 2E0D0001 */  sltiu $t5, $s0, 1
/* 10CED4 7F0D83A4 000D6180 */  sll   $t4, $t5, 6
/* 10CED8 7F0D83A8 362B0002 */  ori   $t3, $s1, 2
/* 10CEDC 7F0D83AC 016C8825 */  or    $s1, $t3, $t4
/* 10CEE0 7F0D83B0 322E00FF */  andi  $t6, $s1, 0xff
/* 10CEE4 7F0D83B4 01C08825 */  move  $s1, $t6
/* 10CEE8 7F0D83B8 AFAD0048 */  sw    $t5, 0x48($sp)
/* 10CEEC 7F0D83BC 1000290F */  b     .L7F0E27FC
/* 10CEF0 7F0D83C0 A3B401A3 */   sb    $s4, 0x1a3($sp)
spectrum_op_93:
/* 10CEF4 7F0D83C4 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10CEF8 7F0D83C8 32B900FF */  andi  $t9, $s5, 0xff
/* 10CEFC 7F0D83CC 02197823 */  subu  $t7, $s0, $t9
/* 10CF00 7F0D83D0 250A0004 */  addiu $t2, $t0, 4
/* 10CF04 7F0D83D4 31E901FF */  andi  $t1, $t7, 0x1ff
/* 10CF08 7F0D83D8 AFAA028C */  sw    $t2, 0x28c($sp)
/* 10CF0C 7F0D83DC 332A000F */  andi  $t2, $t9, 0xf
/* 10CF10 7F0D83E0 312D00A8 */  andi  $t5, $t1, 0xa8
/* 10CF14 7F0D83E4 00096203 */  sra   $t4, $t1, 8
/* 10CF18 7F0D83E8 3208000F */  andi  $t0, $s0, 0xf
/* 10CF1C 7F0D83EC 010A782A */  slt   $t7, $t0, $t2
/* 10CF20 7F0D83F0 01AC7025 */  or    $t6, $t5, $t4
/* 10CF24 7F0D83F4 02196826 */  xor   $t5, $s0, $t9
/* 10CF28 7F0D83F8 000F5900 */  sll   $t3, $t7, 4
/* 10CF2C 7F0D83FC 01305026 */  xor   $t2, $t1, $s0
/* 10CF30 7F0D8400 A7A901A0 */  sh    $t1, 0x1a0($sp)
/* 10CF34 7F0D8404 93B001A1 */  lbu   $s0, 0x1a1($sp)
/* 10CF38 7F0D8408 31AC0080 */  andi  $t4, $t5, 0x80
/* 10CF3C 7F0D840C 018A7824 */  and   $t7, $t4, $t2
/* 10CF40 7F0D8410 01CBC025 */  or    $t8, $t6, $t3
/* 10CF44 7F0D8414 000F7143 */  sra   $t6, $t7, 5
/* 10CF48 7F0D8418 030E8825 */  or    $s1, $t8, $t6
/* 10CF4C 7F0D841C 2E0D0001 */  sltiu $t5, $s0, 1
/* 10CF50 7F0D8420 000D4180 */  sll   $t0, $t5, 6
/* 10CF54 7F0D8424 36390002 */  ori   $t9, $s1, 2
/* 10CF58 7F0D8428 03288825 */  or    $s1, $t9, $t0
/* 10CF5C 7F0D842C 322C00FF */  andi  $t4, $s1, 0xff
/* 10CF60 7F0D8430 01808825 */  move  $s1, $t4
/* 10CF64 7F0D8434 AFAD0048 */  sw    $t5, 0x48($sp)
/* 10CF68 7F0D8438 100028F0 */  b     .L7F0E27FC
/* 10CF6C 7F0D843C A3B5019F */   sb    $s5, 0x19f($sp)
spectrum_op_94:
/* 10CF70 7F0D8440 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10CF74 7F0D8444 93B80287 */  lbu   $t8, 0x287($sp)
/* 10CF78 7F0D8448 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10CF7C 7F0D844C 254F0004 */  addiu $t7, $t2, 4
/* 10CF80 7F0D8450 17000003 */  bnez  $t8, .L7F0D8460
/* 10CF84 7F0D8454 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10CF88 7F0D8458 1000000C */  b     .L7F0D848C
/* 10CF8C 7F0D845C A3B6019B */   sb    $s6, 0x19b($sp)
.L7F0D8460:
/* 10CF90 7F0D8460 24010001 */  li    $at, 1
/* 10CF94 7F0D8464 15C10005 */  bne   $t6, $at, .L7F0D847C
/* 10CF98 7F0D8468 97AD0294 */   lhu   $t5, 0x294($sp)
/* 10CF9C 7F0D846C 97AB0296 */  lhu   $t3, 0x296($sp)
/* 10CFA0 7F0D8470 000BCA03 */  sra   $t9, $t3, 8
/* 10CFA4 7F0D8474 10000003 */  b     .L7F0D8484
/* 10CFA8 7F0D8478 AFB90048 */   sw    $t9, 0x48($sp)
.L7F0D847C:
/* 10CFAC 7F0D847C 000D4A03 */  sra   $t1, $t5, 8
/* 10CFB0 7F0D8480 AFA90048 */  sw    $t1, 0x48($sp)
.L7F0D8484:
/* 10CFB4 7F0D8484 8FA80048 */  lw    $t0, 0x48($sp)
/* 10CFB8 7F0D8488 A3A8019B */  sb    $t0, 0x19b($sp)
.L7F0D848C:
/* 10CFBC 7F0D848C 93AC019B */  lbu   $t4, 0x19b($sp)
/* 10CFC0 7F0D8490 3209000F */  andi  $t1, $s0, 0xf
/* 10CFC4 7F0D8494 020C5023 */  subu  $t2, $s0, $t4
/* 10CFC8 7F0D8498 314F01FF */  andi  $t7, $t2, 0x1ff
/* 10CFCC 7F0D849C 31EE00A8 */  andi  $t6, $t7, 0xa8
/* 10CFD0 7F0D84A0 000FCA03 */  sra   $t9, $t7, 8
/* 10CFD4 7F0D84A4 3188000F */  andi  $t0, $t4, 0xf
/* 10CFD8 7F0D84A8 0128502A */  slt   $t2, $t1, $t0
/* 10CFDC 7F0D84AC 01D96825 */  or    $t5, $t6, $t9
/* 10CFE0 7F0D84B0 020C7026 */  xor   $t6, $s0, $t4
/* 10CFE4 7F0D84B4 000AC100 */  sll   $t8, $t2, 4
/* 10CFE8 7F0D84B8 01F04026 */  xor   $t0, $t7, $s0
/* 10CFEC 7F0D84BC A7AF019C */  sh    $t7, 0x19c($sp)
/* 10CFF0 7F0D84C0 93B0019D */  lbu   $s0, 0x19d($sp)
/* 10CFF4 7F0D84C4 31D90080 */  andi  $t9, $t6, 0x80
/* 10CFF8 7F0D84C8 03285024 */  and   $t2, $t9, $t0
/* 10CFFC 7F0D84CC 01B85825 */  or    $t3, $t5, $t8
/* 10D000 7F0D84D0 000A6943 */  sra   $t5, $t2, 5
/* 10D004 7F0D84D4 016D8825 */  or    $s1, $t3, $t5
/* 10D008 7F0D84D8 2E0E0001 */  sltiu $t6, $s0, 1
/* 10D00C 7F0D84DC 000E4980 */  sll   $t1, $t6, 6
/* 10D010 7F0D84E0 362C0002 */  ori   $t4, $s1, 2
/* 10D014 7F0D84E4 01898825 */  or    $s1, $t4, $t1
/* 10D018 7F0D84E8 323900FF */  andi  $t9, $s1, 0xff
/* 10D01C 7F0D84EC 03208825 */  move  $s1, $t9
/* 10D020 7F0D84F0 100028C2 */  b     .L7F0E27FC
/* 10D024 7F0D84F4 AFAE0048 */   sw    $t6, 0x48($sp)
spectrum_op_95:
/* 10D028 7F0D84F8 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10D02C 7F0D84FC 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10D030 7F0D8500 93AD0287 */  lbu   $t5, 0x287($sp)
/* 10D034 7F0D8504 250A0004 */  addiu $t2, $t0, 4
/* 10D038 7F0D8508 15600003 */  bnez  $t3, .L7F0D8518
/* 10D03C 7F0D850C AFAA028C */   sw    $t2, 0x28c($sp)
/* 10D040 7F0D8510 1000000C */  b     .L7F0D8544
/* 10D044 7F0D8514 A3B70197 */   sb    $s7, 0x197($sp)
.L7F0D8518:
/* 10D048 7F0D8518 24010001 */  li    $at, 1
/* 10D04C 7F0D851C 15A10005 */  bne   $t5, $at, .L7F0D8534
/* 10D050 7F0D8520 97AE0294 */   lhu   $t6, 0x294($sp)
/* 10D054 7F0D8524 97B80296 */  lhu   $t8, 0x296($sp)
/* 10D058 7F0D8528 330C00FF */  andi  $t4, $t8, 0xff
/* 10D05C 7F0D852C 10000003 */  b     .L7F0D853C
/* 10D060 7F0D8530 AFAC0048 */   sw    $t4, 0x48($sp)
.L7F0D8534:
/* 10D064 7F0D8534 31CF00FF */  andi  $t7, $t6, 0xff
/* 10D068 7F0D8538 AFAF0048 */  sw    $t7, 0x48($sp)
.L7F0D853C:
/* 10D06C 7F0D853C 8FA90048 */  lw    $t1, 0x48($sp)
/* 10D070 7F0D8540 A3A90197 */  sb    $t1, 0x197($sp)
.L7F0D8544:
/* 10D074 7F0D8544 93B90197 */  lbu   $t9, 0x197($sp)
/* 10D078 7F0D8548 320F000F */  andi  $t7, $s0, 0xf
/* 10D07C 7F0D854C 02194023 */  subu  $t0, $s0, $t9
/* 10D080 7F0D8550 310A01FF */  andi  $t2, $t0, 0x1ff
/* 10D084 7F0D8554 314D00A8 */  andi  $t5, $t2, 0xa8
/* 10D088 7F0D8558 000A6203 */  sra   $t4, $t2, 8
/* 10D08C 7F0D855C 3329000F */  andi  $t1, $t9, 0xf
/* 10D090 7F0D8560 01E9402A */  slt   $t0, $t7, $t1
/* 10D094 7F0D8564 01AC7025 */  or    $t6, $t5, $t4
/* 10D098 7F0D8568 02196826 */  xor   $t5, $s0, $t9
/* 10D09C 7F0D856C 00085900 */  sll   $t3, $t0, 4
/* 10D0A0 7F0D8570 01504826 */  xor   $t1, $t2, $s0
/* 10D0A4 7F0D8574 A7AA0198 */  sh    $t2, 0x198($sp)
/* 10D0A8 7F0D8578 93B00199 */  lbu   $s0, 0x199($sp)
/* 10D0AC 7F0D857C 31AC0080 */  andi  $t4, $t5, 0x80
/* 10D0B0 7F0D8580 01894024 */  and   $t0, $t4, $t1
/* 10D0B4 7F0D8584 01CBC025 */  or    $t8, $t6, $t3
/* 10D0B8 7F0D8588 00087143 */  sra   $t6, $t0, 5
/* 10D0BC 7F0D858C 030E8825 */  or    $s1, $t8, $t6
/* 10D0C0 7F0D8590 2E0D0001 */  sltiu $t5, $s0, 1
/* 10D0C4 7F0D8594 000D7980 */  sll   $t7, $t5, 6
/* 10D0C8 7F0D8598 36390002 */  ori   $t9, $s1, 2
/* 10D0CC 7F0D859C 032F8825 */  or    $s1, $t9, $t7
/* 10D0D0 7F0D85A0 322C00FF */  andi  $t4, $s1, 0xff
/* 10D0D4 7F0D85A4 01808825 */  move  $s1, $t4
/* 10D0D8 7F0D85A8 10002894 */  b     .L7F0E27FC
/* 10D0DC 7F0D85AC AFAD0048 */   sw    $t5, 0x48($sp)
spectrum_op_96:
/* 10D0E0 7F0D85B0 8FA9028C */  lw    $t1, 0x28c($sp)
/* 10D0E4 7F0D85B4 93B80287 */  lbu   $t8, 0x287($sp)
/* 10D0E8 7F0D85B8 00167200 */  sll   $t6, $s6, 8
/* 10D0EC 7F0D85BC 25280007 */  addiu $t0, $t1, 7
/* 10D0F0 7F0D85C0 17000004 */  bnez  $t8, .L7F0D85D4
/* 10D0F4 7F0D85C4 AFA8028C */   sw    $t0, 0x28c($sp)
/* 10D0F8 7F0D85C8 01D75825 */  or    $t3, $t6, $s7
/* 10D0FC 7F0D85CC 10000016 */  b     .L7F0D8628
/* 10D100 7F0D85D0 A7AB0194 */   sh    $t3, 0x194($sp)
.L7F0D85D4:
/* 10D104 7F0D85D4 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10D108 7F0D85D8 93AA0287 */  lbu   $t2, 0x287($sp)
/* 10D10C 7F0D85DC 24010001 */  li    $at, 1
/* 10D110 7F0D85E0 272D0008 */  addiu $t5, $t9, 8
/* 10D114 7F0D85E4 15410004 */  bne   $t2, $at, .L7F0D85F8
/* 10D118 7F0D85E8 AFAD028C */   sw    $t5, 0x28c($sp)
/* 10D11C 7F0D85EC 97AF0296 */  lhu   $t7, 0x296($sp)
/* 10D120 7F0D85F0 10000003 */  b     .L7F0D8600
/* 10D124 7F0D85F4 AFAF0048 */   sw    $t7, 0x48($sp)
.L7F0D85F8:
/* 10D128 7F0D85F8 97AC0294 */  lhu   $t4, 0x294($sp)
/* 10D12C 7F0D85FC AFAC0048 */  sw    $t4, 0x48($sp)
.L7F0D8600:
/* 10D130 7F0D8600 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10D134 7F0D8604 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10D138 7F0D8608 97A90298 */  lhu   $t1, 0x298($sp)
/* 10D13C 7F0D860C 8FAB0048 */  lw    $t3, 0x48($sp)
/* 10D140 7F0D8610 0128C021 */  addu  $t8, $t1, $t0
/* 10D144 7F0D8614 830E0000 */  lb    $t6, ($t8)
/* 10D148 7F0D8618 252D0001 */  addiu $t5, $t1, 1
/* 10D14C 7F0D861C A7AD0298 */  sh    $t5, 0x298($sp)
/* 10D150 7F0D8620 01CBC821 */  addu  $t9, $t6, $t3
/* 10D154 7F0D8624 A7B90194 */  sh    $t9, 0x194($sp)
.L7F0D8628:
/* 10D158 7F0D8628 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 10D15C 7F0D862C 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10D160 7F0D8630 97AA0194 */  lhu   $t2, 0x194($sp)
/* 10D164 7F0D8634 014F6021 */  addu  $t4, $t2, $t7
/* 10D168 7F0D8638 91880000 */  lbu   $t0, ($t4)
/* 10D16C 7F0D863C 320C000F */  andi  $t4, $s0, 0xf
/* 10D170 7F0D8640 0208C023 */  subu  $t8, $s0, $t0
/* 10D174 7F0D8644 330E01FF */  andi  $t6, $t8, 0x1ff
/* 10D178 7F0D8648 31D900A8 */  andi  $t9, $t6, 0xa8
/* 10D17C 7F0D864C 000E6A03 */  sra   $t5, $t6, 8
/* 10D180 7F0D8650 310F000F */  andi  $t7, $t0, 0xf
/* 10D184 7F0D8654 018FC02A */  slt   $t8, $t4, $t7
/* 10D188 7F0D8658 032D5025 */  or    $t2, $t9, $t5
/* 10D18C 7F0D865C 0208C826 */  xor   $t9, $s0, $t0
/* 10D190 7F0D8660 00185900 */  sll   $t3, $t8, 4
/* 10D194 7F0D8664 01D07826 */  xor   $t7, $t6, $s0
/* 10D198 7F0D8668 A7AE0192 */  sh    $t6, 0x192($sp)
/* 10D19C 7F0D866C 93B00193 */  lbu   $s0, 0x193($sp)
/* 10D1A0 7F0D8670 332D0080 */  andi  $t5, $t9, 0x80
/* 10D1A4 7F0D8674 01AFC024 */  and   $t8, $t5, $t7
/* 10D1A8 7F0D8678 014B4825 */  or    $t1, $t2, $t3
/* 10D1AC 7F0D867C 00185143 */  sra   $t2, $t8, 5
/* 10D1B0 7F0D8680 012A8825 */  or    $s1, $t1, $t2
/* 10D1B4 7F0D8684 A3A80191 */  sb    $t0, 0x191($sp)
/* 10D1B8 7F0D8688 2E190001 */  sltiu $t9, $s0, 1
/* 10D1BC 7F0D868C 00196180 */  sll   $t4, $t9, 6
/* 10D1C0 7F0D8690 36280002 */  ori   $t0, $s1, 2
/* 10D1C4 7F0D8694 010C8825 */  or    $s1, $t0, $t4
/* 10D1C8 7F0D8698 322D00FF */  andi  $t5, $s1, 0xff
/* 10D1CC 7F0D869C 01A08825 */  move  $s1, $t5
/* 10D1D0 7F0D86A0 10002856 */  b     .L7F0E27FC
/* 10D1D4 7F0D86A4 AFB90048 */   sw    $t9, 0x48($sp)
spectrum_op_97:
/* 10D1D8 7F0D86A8 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10D1DC 7F0D86AC 320900FF */  andi  $t1, $s0, 0xff
/* 10D1E0 7F0D86B0 02095023 */  subu  $t2, $s0, $t1
/* 10D1E4 7F0D86B4 25F80004 */  addiu $t8, $t7, 4
/* 10D1E8 7F0D86B8 314B01FF */  andi  $t3, $t2, 0x1ff
/* 10D1EC 7F0D86BC AFB8028C */  sw    $t8, 0x28c($sp)
/* 10D1F0 7F0D86C0 3138000F */  andi  $t8, $t1, 0xf
/* 10D1F4 7F0D86C4 317900A8 */  andi  $t9, $t3, 0xa8
/* 10D1F8 7F0D86C8 000B6203 */  sra   $t4, $t3, 8
/* 10D1FC 7F0D86CC 320F000F */  andi  $t7, $s0, 0xf
/* 10D200 7F0D86D0 01F8502A */  slt   $t2, $t7, $t8
/* 10D204 7F0D86D4 032C6825 */  or    $t5, $t9, $t4
/* 10D208 7F0D86D8 0209C826 */  xor   $t9, $s0, $t1
/* 10D20C 7F0D86DC 000A4100 */  sll   $t0, $t2, 4
/* 10D210 7F0D86E0 0170C026 */  xor   $t8, $t3, $s0
/* 10D214 7F0D86E4 A7AB018E */  sh    $t3, 0x18e($sp)
/* 10D218 7F0D86E8 A3B0018D */  sb    $s0, 0x18d($sp)
/* 10D21C 7F0D86EC 93B0018F */  lbu   $s0, 0x18f($sp)
/* 10D220 7F0D86F0 332C0080 */  andi  $t4, $t9, 0x80
/* 10D224 7F0D86F4 01985024 */  and   $t2, $t4, $t8
/* 10D228 7F0D86F8 01A87025 */  or    $t6, $t5, $t0
/* 10D22C 7F0D86FC 000A6943 */  sra   $t5, $t2, 5
/* 10D230 7F0D8700 01CD8825 */  or    $s1, $t6, $t5
/* 10D234 7F0D8704 2E190001 */  sltiu $t9, $s0, 1
/* 10D238 7F0D8708 00197980 */  sll   $t7, $t9, 6
/* 10D23C 7F0D870C 36290002 */  ori   $t1, $s1, 2
/* 10D240 7F0D8710 012F8825 */  or    $s1, $t1, $t7
/* 10D244 7F0D8714 322C00FF */  andi  $t4, $s1, 0xff
/* 10D248 7F0D8718 01808825 */  move  $s1, $t4
/* 10D24C 7F0D871C 10002837 */  b     .L7F0E27FC
/* 10D250 7F0D8720 AFB90048 */   sw    $t9, 0x48($sp)
spectrum_op_98:
/* 10D254 7F0D8724 324E00FF */  andi  $t6, $s2, 0xff
/* 10D258 7F0D8728 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10D25C 7F0D872C 020E6823 */  subu  $t5, $s0, $t6
/* 10D260 7F0D8730 32280001 */  andi  $t0, $s1, 1
/* 10D264 7F0D8734 01A84823 */  subu  $t1, $t5, $t0
/* 10D268 7F0D8738 313901FF */  andi  $t9, $t1, 0x1ff
/* 10D26C 7F0D873C 31CD000F */  andi  $t5, $t6, 0xf
/* 10D270 7F0D8740 270A0004 */  addiu $t2, $t8, 4
/* 10D274 7F0D8744 01A84821 */  addu  $t1, $t5, $t0
/* 10D278 7F0D8748 320B000F */  andi  $t3, $s0, 0xf
/* 10D27C 7F0D874C AFAA028C */  sw    $t2, 0x28c($sp)
/* 10D280 7F0D8750 0169602A */  slt   $t4, $t3, $t1
/* 10D284 7F0D8754 0019C203 */  sra   $t8, $t9, 8
/* 10D288 7F0D8758 332F00A8 */  andi  $t7, $t9, 0xa8
/* 10D28C 7F0D875C 01F85025 */  or    $t2, $t7, $t8
/* 10D290 7F0D8760 020E6826 */  xor   $t5, $s0, $t6
/* 10D294 7F0D8764 000C7900 */  sll   $t7, $t4, 4
/* 10D298 7F0D8768 03304826 */  xor   $t1, $t9, $s0
/* 10D29C 7F0D876C A7B9018A */  sh    $t9, 0x18a($sp)
/* 10D2A0 7F0D8770 93B0018B */  lbu   $s0, 0x18b($sp)
/* 10D2A4 7F0D8774 31A80080 */  andi  $t0, $t5, 0x80
/* 10D2A8 7F0D8778 01096024 */  and   $t4, $t0, $t1
/* 10D2AC 7F0D877C 014FC025 */  or    $t8, $t2, $t7
/* 10D2B0 7F0D8780 000C5143 */  sra   $t2, $t4, 5
/* 10D2B4 7F0D8784 030A8825 */  or    $s1, $t8, $t2
/* 10D2B8 7F0D8788 2E0D0001 */  sltiu $t5, $s0, 1
/* 10D2BC 7F0D878C 000D5980 */  sll   $t3, $t5, 6
/* 10D2C0 7F0D8790 362E0002 */  ori   $t6, $s1, 2
/* 10D2C4 7F0D8794 01CB8825 */  or    $s1, $t6, $t3
/* 10D2C8 7F0D8798 322800FF */  andi  $t0, $s1, 0xff
/* 10D2CC 7F0D879C 01008825 */  move  $s1, $t0
/* 10D2D0 7F0D87A0 AFAD0048 */  sw    $t5, 0x48($sp)
/* 10D2D4 7F0D87A4 10002815 */  b     .L7F0E27FC
/* 10D2D8 7F0D87A8 A3B20189 */   sb    $s2, 0x189($sp)
spectrum_op_99:
/* 10D2DC 7F0D87AC 327800FF */  andi  $t8, $s3, 0xff
/* 10D2E0 7F0D87B0 8FA9028C */  lw    $t1, 0x28c($sp)
/* 10D2E4 7F0D87B4 02185023 */  subu  $t2, $s0, $t8
/* 10D2E8 7F0D87B8 322F0001 */  andi  $t7, $s1, 1
/* 10D2EC 7F0D87BC 014F7023 */  subu  $t6, $t2, $t7
/* 10D2F0 7F0D87C0 31CD01FF */  andi  $t5, $t6, 0x1ff
/* 10D2F4 7F0D87C4 330A000F */  andi  $t2, $t8, 0xf
/* 10D2F8 7F0D87C8 252C0004 */  addiu $t4, $t1, 4
/* 10D2FC 7F0D87CC 014F7021 */  addu  $t6, $t2, $t7
/* 10D300 7F0D87D0 3219000F */  andi  $t9, $s0, 0xf
/* 10D304 7F0D87D4 AFAC028C */  sw    $t4, 0x28c($sp)
/* 10D308 7F0D87D8 032E402A */  slt   $t0, $t9, $t6
/* 10D30C 7F0D87DC 000D4A03 */  sra   $t1, $t5, 8
/* 10D310 7F0D87E0 31AB00A8 */  andi  $t3, $t5, 0xa8
/* 10D314 7F0D87E4 01696025 */  or    $t4, $t3, $t1
/* 10D318 7F0D87E8 02185026 */  xor   $t2, $s0, $t8
/* 10D31C 7F0D87EC 00085900 */  sll   $t3, $t0, 4
/* 10D320 7F0D87F0 01B07026 */  xor   $t6, $t5, $s0
/* 10D324 7F0D87F4 A7AD0186 */  sh    $t5, 0x186($sp)
/* 10D328 7F0D87F8 93B00187 */  lbu   $s0, 0x187($sp)
/* 10D32C 7F0D87FC 314F0080 */  andi  $t7, $t2, 0x80
/* 10D330 7F0D8800 01EE4024 */  and   $t0, $t7, $t6
/* 10D334 7F0D8804 018B4825 */  or    $t1, $t4, $t3
/* 10D338 7F0D8808 00086143 */  sra   $t4, $t0, 5
/* 10D33C 7F0D880C 012C8825 */  or    $s1, $t1, $t4
/* 10D340 7F0D8810 2E0A0001 */  sltiu $t2, $s0, 1
/* 10D344 7F0D8814 000AC980 */  sll   $t9, $t2, 6
/* 10D348 7F0D8818 36380002 */  ori   $t8, $s1, 2
/* 10D34C 7F0D881C 03198825 */  or    $s1, $t8, $t9
/* 10D350 7F0D8820 322F00FF */  andi  $t7, $s1, 0xff
/* 10D354 7F0D8824 01E08825 */  move  $s1, $t7
/* 10D358 7F0D8828 AFAA0048 */  sw    $t2, 0x48($sp)
/* 10D35C 7F0D882C 100027F3 */  b     .L7F0E27FC
/* 10D360 7F0D8830 A3B30185 */   sb    $s3, 0x185($sp)
spectrum_op_9A:
/* 10D364 7F0D8834 328900FF */  andi  $t1, $s4, 0xff
/* 10D368 7F0D8838 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10D36C 7F0D883C 02096023 */  subu  $t4, $s0, $t1
/* 10D370 7F0D8840 322B0001 */  andi  $t3, $s1, 1
/* 10D374 7F0D8844 018BC023 */  subu  $t8, $t4, $t3
/* 10D378 7F0D8848 330A01FF */  andi  $t2, $t8, 0x1ff
/* 10D37C 7F0D884C 312C000F */  andi  $t4, $t1, 0xf
/* 10D380 7F0D8850 25C80004 */  addiu $t0, $t6, 4
/* 10D384 7F0D8854 018BC021 */  addu  $t8, $t4, $t3
/* 10D388 7F0D8858 320D000F */  andi  $t5, $s0, 0xf
/* 10D38C 7F0D885C AFA8028C */  sw    $t0, 0x28c($sp)
/* 10D390 7F0D8860 01B8782A */  slt   $t7, $t5, $t8
/* 10D394 7F0D8864 000A7203 */  sra   $t6, $t2, 8
/* 10D398 7F0D8868 315900A8 */  andi  $t9, $t2, 0xa8
/* 10D39C 7F0D886C 032E4025 */  or    $t0, $t9, $t6
/* 10D3A0 7F0D8870 02096026 */  xor   $t4, $s0, $t1
/* 10D3A4 7F0D8874 000FC900 */  sll   $t9, $t7, 4
/* 10D3A8 7F0D8878 0150C026 */  xor   $t8, $t2, $s0
/* 10D3AC 7F0D887C A7AA0182 */  sh    $t2, 0x182($sp)
/* 10D3B0 7F0D8880 93B00183 */  lbu   $s0, 0x183($sp)
/* 10D3B4 7F0D8884 318B0080 */  andi  $t3, $t4, 0x80
/* 10D3B8 7F0D8888 01787824 */  and   $t7, $t3, $t8
/* 10D3BC 7F0D888C 01197025 */  or    $t6, $t0, $t9
/* 10D3C0 7F0D8890 000F4143 */  sra   $t0, $t7, 5
/* 10D3C4 7F0D8894 01C88825 */  or    $s1, $t6, $t0
/* 10D3C8 7F0D8898 2E0C0001 */  sltiu $t4, $s0, 1
/* 10D3CC 7F0D889C 000C6980 */  sll   $t5, $t4, 6
/* 10D3D0 7F0D88A0 36290002 */  ori   $t1, $s1, 2
/* 10D3D4 7F0D88A4 012D8825 */  or    $s1, $t1, $t5
/* 10D3D8 7F0D88A8 322B00FF */  andi  $t3, $s1, 0xff
/* 10D3DC 7F0D88AC 01608825 */  move  $s1, $t3
/* 10D3E0 7F0D88B0 AFAC0048 */  sw    $t4, 0x48($sp)
/* 10D3E4 7F0D88B4 100027D1 */  b     .L7F0E27FC
/* 10D3E8 7F0D88B8 A3B40181 */   sb    $s4, 0x181($sp)
spectrum_op_9B:
/* 10D3EC 7F0D88BC 32AE00FF */  andi  $t6, $s5, 0xff
/* 10D3F0 7F0D88C0 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10D3F4 7F0D88C4 020E4023 */  subu  $t0, $s0, $t6
/* 10D3F8 7F0D88C8 32390001 */  andi  $t9, $s1, 1
/* 10D3FC 7F0D88CC 01194823 */  subu  $t1, $t0, $t9
/* 10D400 7F0D88D0 312C01FF */  andi  $t4, $t1, 0x1ff
/* 10D404 7F0D88D4 31C8000F */  andi  $t0, $t6, 0xf
/* 10D408 7F0D88D8 270F0004 */  addiu $t7, $t8, 4
/* 10D40C 7F0D88DC 01194821 */  addu  $t1, $t0, $t9
/* 10D410 7F0D88E0 320A000F */  andi  $t2, $s0, 0xf
/* 10D414 7F0D88E4 AFAF028C */  sw    $t7, 0x28c($sp)
/* 10D418 7F0D88E8 0149582A */  slt   $t3, $t2, $t1
/* 10D41C 7F0D88EC 000CC203 */  sra   $t8, $t4, 8
/* 10D420 7F0D88F0 318D00A8 */  andi  $t5, $t4, 0xa8
/* 10D424 7F0D88F4 01B87825 */  or    $t7, $t5, $t8
/* 10D428 7F0D88F8 020E4026 */  xor   $t0, $s0, $t6
/* 10D42C 7F0D88FC 000B6900 */  sll   $t5, $t3, 4
/* 10D430 7F0D8900 01904826 */  xor   $t1, $t4, $s0
/* 10D434 7F0D8904 A7AC017E */  sh    $t4, 0x17e($sp)
/* 10D438 7F0D8908 93B0017F */  lbu   $s0, 0x17f($sp)
/* 10D43C 7F0D890C 31190080 */  andi  $t9, $t0, 0x80
/* 10D440 7F0D8910 03295824 */  and   $t3, $t9, $t1
/* 10D444 7F0D8914 01EDC025 */  or    $t8, $t7, $t5
/* 10D448 7F0D8918 000B7943 */  sra   $t7, $t3, 5
/* 10D44C 7F0D891C 030F8825 */  or    $s1, $t8, $t7
/* 10D450 7F0D8920 2E080001 */  sltiu $t0, $s0, 1
/* 10D454 7F0D8924 00085180 */  sll   $t2, $t0, 6
/* 10D458 7F0D8928 362E0002 */  ori   $t6, $s1, 2
/* 10D45C 7F0D892C 01CA8825 */  or    $s1, $t6, $t2
/* 10D460 7F0D8930 323900FF */  andi  $t9, $s1, 0xff
/* 10D464 7F0D8934 03208825 */  move  $s1, $t9
/* 10D468 7F0D8938 AFA80048 */  sw    $t0, 0x48($sp)
/* 10D46C 7F0D893C 100027AF */  b     .L7F0E27FC
/* 10D470 7F0D8940 A3B5017D */   sb    $s5, 0x17d($sp)
spectrum_op_9C:
/* 10D474 7F0D8944 8FA9028C */  lw    $t1, 0x28c($sp)
/* 10D478 7F0D8948 93B80287 */  lbu   $t8, 0x287($sp)
/* 10D47C 7F0D894C 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10D480 7F0D8950 252B0004 */  addiu $t3, $t1, 4
/* 10D484 7F0D8954 17000003 */  bnez  $t8, .L7F0D8964
/* 10D488 7F0D8958 AFAB028C */   sw    $t3, 0x28c($sp)
/* 10D48C 7F0D895C 1000000C */  b     .L7F0D8990
/* 10D490 7F0D8960 A3B60179 */   sb    $s6, 0x179($sp)
.L7F0D8964:
/* 10D494 7F0D8964 24010001 */  li    $at, 1
/* 10D498 7F0D8968 15E10005 */  bne   $t7, $at, .L7F0D8980
/* 10D49C 7F0D896C 97A80294 */   lhu   $t0, 0x294($sp)
/* 10D4A0 7F0D8970 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10D4A4 7F0D8974 000D7203 */  sra   $t6, $t5, 8
/* 10D4A8 7F0D8978 10000003 */  b     .L7F0D8988
/* 10D4AC 7F0D897C AFAE0048 */   sw    $t6, 0x48($sp)
.L7F0D8980:
/* 10D4B0 7F0D8980 00086203 */  sra   $t4, $t0, 8
/* 10D4B4 7F0D8984 AFAC0048 */  sw    $t4, 0x48($sp)
.L7F0D8988:
/* 10D4B8 7F0D8988 8FAA0048 */  lw    $t2, 0x48($sp)
/* 10D4BC 7F0D898C A3AA0179 */  sb    $t2, 0x179($sp)
.L7F0D8990:
/* 10D4C0 7F0D8990 93B90179 */  lbu   $t9, 0x179($sp)
/* 10D4C4 7F0D8994 322B0001 */  andi  $t3, $s1, 1
/* 10D4C8 7F0D8998 320D000F */  andi  $t5, $s0, 0xf
/* 10D4CC 7F0D899C 02194823 */  subu  $t1, $s0, $t9
/* 10D4D0 7F0D89A0 012BC023 */  subu  $t8, $t1, $t3
/* 10D4D4 7F0D89A4 330F01FF */  andi  $t7, $t8, 0x1ff
/* 10D4D8 7F0D89A8 3329000F */  andi  $t1, $t9, 0xf
/* 10D4DC 7F0D89AC 012BC021 */  addu  $t8, $t1, $t3
/* 10D4E0 7F0D89B0 01B8402A */  slt   $t0, $t5, $t8
/* 10D4E4 7F0D89B4 31EE00A8 */  andi  $t6, $t7, 0xa8
/* 10D4E8 7F0D89B8 000F6203 */  sra   $t4, $t7, 8
/* 10D4EC 7F0D89BC 01CC5025 */  or    $t2, $t6, $t4
/* 10D4F0 7F0D89C0 02194826 */  xor   $t1, $s0, $t9
/* 10D4F4 7F0D89C4 00087100 */  sll   $t6, $t0, 4
/* 10D4F8 7F0D89C8 01F0C026 */  xor   $t8, $t7, $s0
/* 10D4FC 7F0D89CC A7AF017A */  sh    $t7, 0x17a($sp)
/* 10D500 7F0D89D0 93B0017B */  lbu   $s0, 0x17b($sp)
/* 10D504 7F0D89D4 312B0080 */  andi  $t3, $t1, 0x80
/* 10D508 7F0D89D8 01784024 */  and   $t0, $t3, $t8
/* 10D50C 7F0D89DC 014E6025 */  or    $t4, $t2, $t6
/* 10D510 7F0D89E0 00085143 */  sra   $t2, $t0, 5
/* 10D514 7F0D89E4 018A8825 */  or    $s1, $t4, $t2
/* 10D518 7F0D89E8 2E090001 */  sltiu $t1, $s0, 1
/* 10D51C 7F0D89EC 00096980 */  sll   $t5, $t1, 6
/* 10D520 7F0D89F0 36390002 */  ori   $t9, $s1, 2
/* 10D524 7F0D89F4 032D8825 */  or    $s1, $t9, $t5
/* 10D528 7F0D89F8 322B00FF */  andi  $t3, $s1, 0xff
/* 10D52C 7F0D89FC 01608825 */  move  $s1, $t3
/* 10D530 7F0D8A00 1000277E */  b     .L7F0E27FC
/* 10D534 7F0D8A04 AFA90048 */   sw    $t1, 0x48($sp)
spectrum_op_9D:
/* 10D538 7F0D8A08 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10D53C 7F0D8A0C 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10D540 7F0D8A10 93AA0287 */  lbu   $t2, 0x287($sp)
/* 10D544 7F0D8A14 27080004 */  addiu $t0, $t8, 4
/* 10D548 7F0D8A18 15800003 */  bnez  $t4, .L7F0D8A28
/* 10D54C 7F0D8A1C AFA8028C */   sw    $t0, 0x28c($sp)
/* 10D550 7F0D8A20 1000000C */  b     .L7F0D8A54
/* 10D554 7F0D8A24 A3B70175 */   sb    $s7, 0x175($sp)
.L7F0D8A28:
/* 10D558 7F0D8A28 24010001 */  li    $at, 1
/* 10D55C 7F0D8A2C 15410005 */  bne   $t2, $at, .L7F0D8A44
/* 10D560 7F0D8A30 97A90294 */   lhu   $t1, 0x294($sp)
/* 10D564 7F0D8A34 97AE0296 */  lhu   $t6, 0x296($sp)
/* 10D568 7F0D8A38 31D900FF */  andi  $t9, $t6, 0xff
/* 10D56C 7F0D8A3C 10000003 */  b     .L7F0D8A4C
/* 10D570 7F0D8A40 AFB90048 */   sw    $t9, 0x48($sp)
.L7F0D8A44:
/* 10D574 7F0D8A44 312F00FF */  andi  $t7, $t1, 0xff
/* 10D578 7F0D8A48 AFAF0048 */  sw    $t7, 0x48($sp)
.L7F0D8A4C:
/* 10D57C 7F0D8A4C 8FAD0048 */  lw    $t5, 0x48($sp)
/* 10D580 7F0D8A50 A3AD0175 */  sb    $t5, 0x175($sp)
.L7F0D8A54:
/* 10D584 7F0D8A54 93AB0175 */  lbu   $t3, 0x175($sp)
/* 10D588 7F0D8A58 32280001 */  andi  $t0, $s1, 1
/* 10D58C 7F0D8A5C 320E000F */  andi  $t6, $s0, 0xf
/* 10D590 7F0D8A60 020BC023 */  subu  $t8, $s0, $t3
/* 10D594 7F0D8A64 03086023 */  subu  $t4, $t8, $t0
/* 10D598 7F0D8A68 318A01FF */  andi  $t2, $t4, 0x1ff
/* 10D59C 7F0D8A6C 3178000F */  andi  $t8, $t3, 0xf
/* 10D5A0 7F0D8A70 03086021 */  addu  $t4, $t8, $t0
/* 10D5A4 7F0D8A74 01CC482A */  slt   $t1, $t6, $t4
/* 10D5A8 7F0D8A78 315900A8 */  andi  $t9, $t2, 0xa8
/* 10D5AC 7F0D8A7C 000A7A03 */  sra   $t7, $t2, 8
/* 10D5B0 7F0D8A80 032F6825 */  or    $t5, $t9, $t7
/* 10D5B4 7F0D8A84 020BC026 */  xor   $t8, $s0, $t3
/* 10D5B8 7F0D8A88 0009C900 */  sll   $t9, $t1, 4
/* 10D5BC 7F0D8A8C 01506026 */  xor   $t4, $t2, $s0
/* 10D5C0 7F0D8A90 A7AA0176 */  sh    $t2, 0x176($sp)
/* 10D5C4 7F0D8A94 93B00177 */  lbu   $s0, 0x177($sp)
/* 10D5C8 7F0D8A98 33080080 */  andi  $t0, $t8, 0x80
/* 10D5CC 7F0D8A9C 010C4824 */  and   $t1, $t0, $t4
/* 10D5D0 7F0D8AA0 01B97825 */  or    $t7, $t5, $t9
/* 10D5D4 7F0D8AA4 00096943 */  sra   $t5, $t1, 5
/* 10D5D8 7F0D8AA8 01ED8825 */  or    $s1, $t7, $t5
/* 10D5DC 7F0D8AAC 2E180001 */  sltiu $t8, $s0, 1
/* 10D5E0 7F0D8AB0 00187180 */  sll   $t6, $t8, 6
/* 10D5E4 7F0D8AB4 362B0002 */  ori   $t3, $s1, 2
/* 10D5E8 7F0D8AB8 016E8825 */  or    $s1, $t3, $t6
/* 10D5EC 7F0D8ABC 322800FF */  andi  $t0, $s1, 0xff
/* 10D5F0 7F0D8AC0 01008825 */  move  $s1, $t0
/* 10D5F4 7F0D8AC4 1000274D */  b     .L7F0E27FC
/* 10D5F8 7F0D8AC8 AFB80048 */   sw    $t8, 0x48($sp)
spectrum_op_9E:
/* 10D5FC 7F0D8ACC 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10D600 7F0D8AD0 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10D604 7F0D8AD4 00166A00 */  sll   $t5, $s6, 8
/* 10D608 7F0D8AD8 25890007 */  addiu $t1, $t4, 7
/* 10D60C 7F0D8ADC 15E00004 */  bnez  $t7, .L7F0D8AF0
/* 10D610 7F0D8AE0 AFA9028C */   sw    $t1, 0x28c($sp)
/* 10D614 7F0D8AE4 01B7C825 */  or    $t9, $t5, $s7
/* 10D618 7F0D8AE8 10000016 */  b     .L7F0D8B44
/* 10D61C 7F0D8AEC A7B90172 */   sh    $t9, 0x172($sp)
.L7F0D8AF0:
/* 10D620 7F0D8AF0 8FAB028C */  lw    $t3, 0x28c($sp)
/* 10D624 7F0D8AF4 93AA0287 */  lbu   $t2, 0x287($sp)
/* 10D628 7F0D8AF8 24010001 */  li    $at, 1
/* 10D62C 7F0D8AFC 25780008 */  addiu $t8, $t3, 8
/* 10D630 7F0D8B00 15410004 */  bne   $t2, $at, .L7F0D8B14
/* 10D634 7F0D8B04 AFB8028C */   sw    $t8, 0x28c($sp)
/* 10D638 7F0D8B08 97AE0296 */  lhu   $t6, 0x296($sp)
/* 10D63C 7F0D8B0C 10000003 */  b     .L7F0D8B1C
/* 10D640 7F0D8B10 AFAE0048 */   sw    $t6, 0x48($sp)
.L7F0D8B14:
/* 10D644 7F0D8B14 97A80294 */  lhu   $t0, 0x294($sp)
/* 10D648 7F0D8B18 AFA80048 */  sw    $t0, 0x48($sp)
.L7F0D8B1C:
/* 10D64C 7F0D8B1C 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10D650 7F0D8B20 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10D654 7F0D8B24 97AC0298 */  lhu   $t4, 0x298($sp)
/* 10D658 7F0D8B28 8FB90048 */  lw    $t9, 0x48($sp)
/* 10D65C 7F0D8B2C 01897821 */  addu  $t7, $t4, $t1
/* 10D660 7F0D8B30 81ED0000 */  lb    $t5, ($t7)
/* 10D664 7F0D8B34 25980001 */  addiu $t8, $t4, 1
/* 10D668 7F0D8B38 A7B80298 */  sh    $t8, 0x298($sp)
/* 10D66C 7F0D8B3C 01B95821 */  addu  $t3, $t5, $t9
/* 10D670 7F0D8B40 A7AB0172 */  sh    $t3, 0x172($sp)
.L7F0D8B44:
/* 10D674 7F0D8B44 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10D678 7F0D8B48 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10D67C 7F0D8B4C 97AA0172 */  lhu   $t2, 0x172($sp)
/* 10D680 7F0D8B50 322D0001 */  andi  $t5, $s1, 1
/* 10D684 7F0D8B54 320C000F */  andi  $t4, $s0, 0xf
/* 10D688 7F0D8B58 014E4021 */  addu  $t0, $t2, $t6
/* 10D68C 7F0D8B5C 91090000 */  lbu   $t1, ($t0)
/* 10D690 7F0D8B60 02097823 */  subu  $t7, $s0, $t1
/* 10D694 7F0D8B64 01EDC823 */  subu  $t9, $t7, $t5
/* 10D698 7F0D8B68 332B01FF */  andi  $t3, $t9, 0x1ff
/* 10D69C 7F0D8B6C 312F000F */  andi  $t7, $t1, 0xf
/* 10D6A0 7F0D8B70 01EDC821 */  addu  $t9, $t7, $t5
/* 10D6A4 7F0D8B74 0199502A */  slt   $t2, $t4, $t9
/* 10D6A8 7F0D8B78 317800A8 */  andi  $t8, $t3, 0xa8
/* 10D6AC 7F0D8B7C 000B7203 */  sra   $t6, $t3, 8
/* 10D6B0 7F0D8B80 030E4025 */  or    $t0, $t8, $t6
/* 10D6B4 7F0D8B84 02097826 */  xor   $t7, $s0, $t1
/* 10D6B8 7F0D8B88 000AC100 */  sll   $t8, $t2, 4
/* 10D6BC 7F0D8B8C 0170C826 */  xor   $t9, $t3, $s0
/* 10D6C0 7F0D8B90 A7AB0170 */  sh    $t3, 0x170($sp)
/* 10D6C4 7F0D8B94 93B00171 */  lbu   $s0, 0x171($sp)
/* 10D6C8 7F0D8B98 31ED0080 */  andi  $t5, $t7, 0x80
/* 10D6CC 7F0D8B9C 01B95024 */  and   $t2, $t5, $t9
/* 10D6D0 7F0D8BA0 01187025 */  or    $t6, $t0, $t8
/* 10D6D4 7F0D8BA4 000A4143 */  sra   $t0, $t2, 5
/* 10D6D8 7F0D8BA8 01C88825 */  or    $s1, $t6, $t0
/* 10D6DC 7F0D8BAC A3A9016F */  sb    $t1, 0x16f($sp)
/* 10D6E0 7F0D8BB0 2E0F0001 */  sltiu $t7, $s0, 1
/* 10D6E4 7F0D8BB4 000F6180 */  sll   $t4, $t7, 6
/* 10D6E8 7F0D8BB8 36290002 */  ori   $t1, $s1, 2
/* 10D6EC 7F0D8BBC 012C8825 */  or    $s1, $t1, $t4
/* 10D6F0 7F0D8BC0 322D00FF */  andi  $t5, $s1, 0xff
/* 10D6F4 7F0D8BC4 01A08825 */  move  $s1, $t5
/* 10D6F8 7F0D8BC8 1000270C */  b     .L7F0E27FC
/* 10D6FC 7F0D8BCC AFAF0048 */   sw    $t7, 0x48($sp)
spectrum_op_9F:
/* 10D700 7F0D8BD0 320E00FF */  andi  $t6, $s0, 0xff
/* 10D704 7F0D8BD4 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10D708 7F0D8BD8 020E4023 */  subu  $t0, $s0, $t6
/* 10D70C 7F0D8BDC 32380001 */  andi  $t8, $s1, 1
/* 10D710 7F0D8BE0 01184823 */  subu  $t1, $t0, $t8
/* 10D714 7F0D8BE4 312F01FF */  andi  $t7, $t1, 0x1ff
/* 10D718 7F0D8BE8 31C8000F */  andi  $t0, $t6, 0xf
/* 10D71C 7F0D8BEC 272A0004 */  addiu $t2, $t9, 4
/* 10D720 7F0D8BF0 01184821 */  addu  $t1, $t0, $t8
/* 10D724 7F0D8BF4 320B000F */  andi  $t3, $s0, 0xf
/* 10D728 7F0D8BF8 AFAA028C */  sw    $t2, 0x28c($sp)
/* 10D72C 7F0D8BFC 0169682A */  slt   $t5, $t3, $t1
/* 10D730 7F0D8C00 000FCA03 */  sra   $t9, $t7, 8
/* 10D734 7F0D8C04 31EC00A8 */  andi  $t4, $t7, 0xa8
/* 10D738 7F0D8C08 01995025 */  or    $t2, $t4, $t9
/* 10D73C 7F0D8C0C 020E4026 */  xor   $t0, $s0, $t6
/* 10D740 7F0D8C10 000D6100 */  sll   $t4, $t5, 4
/* 10D744 7F0D8C14 01F04826 */  xor   $t1, $t7, $s0
/* 10D748 7F0D8C18 A7AF016C */  sh    $t7, 0x16c($sp)
/* 10D74C 7F0D8C1C A3B0016B */  sb    $s0, 0x16b($sp)
/* 10D750 7F0D8C20 93B0016D */  lbu   $s0, 0x16d($sp)
/* 10D754 7F0D8C24 31180080 */  andi  $t8, $t0, 0x80
/* 10D758 7F0D8C28 03096824 */  and   $t5, $t8, $t1
/* 10D75C 7F0D8C2C 014CC825 */  or    $t9, $t2, $t4
/* 10D760 7F0D8C30 000D5143 */  sra   $t2, $t5, 5
/* 10D764 7F0D8C34 032A8825 */  or    $s1, $t9, $t2
/* 10D768 7F0D8C38 2E080001 */  sltiu $t0, $s0, 1
/* 10D76C 7F0D8C3C 00085980 */  sll   $t3, $t0, 6
/* 10D770 7F0D8C40 362E0002 */  ori   $t6, $s1, 2
/* 10D774 7F0D8C44 01CB8825 */  or    $s1, $t6, $t3
/* 10D778 7F0D8C48 323800FF */  andi  $t8, $s1, 0xff
/* 10D77C 7F0D8C4C 03008825 */  move  $s1, $t8
/* 10D780 7F0D8C50 100026EA */  b     .L7F0E27FC
/* 10D784 7F0D8C54 AFA80048 */   sw    $t0, 0x48($sp)
spectrum_op_A0:
/* 10D788 7F0D8C58 8FA9028C */  lw    $t1, 0x28c($sp)
/* 10D78C 7F0D8C5C 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 10D790 7F0D8C60 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 10D794 7F0D8C64 02128024 */  and   $s0, $s0, $s2
/* 10D798 7F0D8C68 321900FF */  andi  $t9, $s0, 0xff
/* 10D79C 7F0D8C6C 252D0004 */  addiu $t5, $t1, 4
/* 10D7A0 7F0D8C70 2F2A0001 */  sltiu $t2, $t9, 1
/* 10D7A4 7F0D8C74 AFAD028C */  sw    $t5, 0x28c($sp)
/* 10D7A8 7F0D8C78 AFAA0048 */  sw    $t2, 0x48($sp)
/* 10D7AC 7F0D8C7C 03384821 */  addu  $t1, $t9, $t8
/* 10D7B0 7F0D8C80 912D0000 */  lbu   $t5, ($t1)
/* 10D7B4 7F0D8C84 000A4180 */  sll   $t0, $t2, 6
/* 10D7B8 7F0D8C88 332C00A8 */  andi  $t4, $t9, 0xa8
/* 10D7BC 7F0D8C8C 01887825 */  or    $t7, $t4, $t0
/* 10D7C0 7F0D8C90 35EB0010 */  ori   $t3, $t7, 0x10
/* 10D7C4 7F0D8C94 03208025 */  move  $s0, $t9
/* 10D7C8 7F0D8C98 01AB8825 */  or    $s1, $t5, $t3
/* 10D7CC 7F0D8C9C 323900FF */  andi  $t9, $s1, 0xff
/* 10D7D0 7F0D8CA0 100026D6 */  b     .L7F0E27FC
/* 10D7D4 7F0D8CA4 03208825 */   move  $s1, $t9
spectrum_op_A1:
/* 10D7D8 7F0D8CA8 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10D7DC 7F0D8CAC 3C198009 */  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
/* 10D7E0 7F0D8CB0 8F39E334 */  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
/* 10D7E4 7F0D8CB4 02138024 */  and   $s0, $s0, $s3
/* 10D7E8 7F0D8CB8 320C00FF */  andi  $t4, $s0, 0xff
/* 10D7EC 7F0D8CBC 254E0004 */  addiu $t6, $t2, 4
/* 10D7F0 7F0D8CC0 2D880001 */  sltiu $t0, $t4, 1
/* 10D7F4 7F0D8CC4 AFAE028C */  sw    $t6, 0x28c($sp)
/* 10D7F8 7F0D8CC8 AFA80048 */  sw    $t0, 0x48($sp)
/* 10D7FC 7F0D8CCC 01995021 */  addu  $t2, $t4, $t9
/* 10D800 7F0D8CD0 914E0000 */  lbu   $t6, ($t2)
/* 10D804 7F0D8CD4 00084980 */  sll   $t1, $t0, 6
/* 10D808 7F0D8CD8 318F00A8 */  andi  $t7, $t4, 0xa8
/* 10D80C 7F0D8CDC 01E96825 */  or    $t5, $t7, $t1
/* 10D810 7F0D8CE0 35AB0010 */  ori   $t3, $t5, 0x10
/* 10D814 7F0D8CE4 01808025 */  move  $s0, $t4
/* 10D818 7F0D8CE8 01CB8825 */  or    $s1, $t6, $t3
/* 10D81C 7F0D8CEC 322C00FF */  andi  $t4, $s1, 0xff
/* 10D820 7F0D8CF0 100026C2 */  b     .L7F0E27FC
/* 10D824 7F0D8CF4 01808825 */   move  $s1, $t4
spectrum_op_A2:
/* 10D828 7F0D8CF8 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10D82C 7F0D8CFC 3C0C8009 */  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
/* 10D830 7F0D8D00 8D8CE334 */  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
/* 10D834 7F0D8D04 02148024 */  and   $s0, $s0, $s4
/* 10D838 7F0D8D08 320F00FF */  andi  $t7, $s0, 0xff
/* 10D83C 7F0D8D0C 25180004 */  addiu $t8, $t0, 4
/* 10D840 7F0D8D10 2DE90001 */  sltiu $t1, $t7, 1
/* 10D844 7F0D8D14 AFB8028C */  sw    $t8, 0x28c($sp)
/* 10D848 7F0D8D18 AFA90048 */  sw    $t1, 0x48($sp)
/* 10D84C 7F0D8D1C 01EC4021 */  addu  $t0, $t7, $t4
/* 10D850 7F0D8D20 91180000 */  lbu   $t8, ($t0)
/* 10D854 7F0D8D24 00095180 */  sll   $t2, $t1, 6
/* 10D858 7F0D8D28 31ED00A8 */  andi  $t5, $t7, 0xa8
/* 10D85C 7F0D8D2C 01AA7025 */  or    $t6, $t5, $t2
/* 10D860 7F0D8D30 35CB0010 */  ori   $t3, $t6, 0x10
/* 10D864 7F0D8D34 01E08025 */  move  $s0, $t7
/* 10D868 7F0D8D38 030B8825 */  or    $s1, $t8, $t3
/* 10D86C 7F0D8D3C 322F00FF */  andi  $t7, $s1, 0xff
/* 10D870 7F0D8D40 100026AE */  b     .L7F0E27FC
/* 10D874 7F0D8D44 01E08825 */   move  $s1, $t7
spectrum_op_A3:
/* 10D878 7F0D8D48 8FA9028C */  lw    $t1, 0x28c($sp)
/* 10D87C 7F0D8D4C 3C0F8009 */  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
/* 10D880 7F0D8D50 8DEFE334 */  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
/* 10D884 7F0D8D54 02158024 */  and   $s0, $s0, $s5
/* 10D888 7F0D8D58 320D00FF */  andi  $t5, $s0, 0xff
/* 10D88C 7F0D8D5C 25390004 */  addiu $t9, $t1, 4
/* 10D890 7F0D8D60 2DAA0001 */  sltiu $t2, $t5, 1
/* 10D894 7F0D8D64 AFB9028C */  sw    $t9, 0x28c($sp)
/* 10D898 7F0D8D68 AFAA0048 */  sw    $t2, 0x48($sp)
/* 10D89C 7F0D8D6C 01AF4821 */  addu  $t1, $t5, $t7
/* 10D8A0 7F0D8D70 91390000 */  lbu   $t9, ($t1)
/* 10D8A4 7F0D8D74 000A4180 */  sll   $t0, $t2, 6
/* 10D8A8 7F0D8D78 31AE00A8 */  andi  $t6, $t5, 0xa8
/* 10D8AC 7F0D8D7C 01C8C025 */  or    $t8, $t6, $t0
/* 10D8B0 7F0D8D80 370B0010 */  ori   $t3, $t8, 0x10
/* 10D8B4 7F0D8D84 01A08025 */  move  $s0, $t5
/* 10D8B8 7F0D8D88 032B8825 */  or    $s1, $t9, $t3
/* 10D8BC 7F0D8D8C 322D00FF */  andi  $t5, $s1, 0xff
/* 10D8C0 7F0D8D90 1000269A */  b     .L7F0E27FC
/* 10D8C4 7F0D8D94 01A08825 */   move  $s1, $t5
spectrum_op_A4:
/* 10D8C8 7F0D8D98 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10D8CC 7F0D8D9C 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10D8D0 7F0D8DA0 93A80287 */  lbu   $t0, 0x287($sp)
/* 10D8D4 7F0D8DA4 254C0004 */  addiu $t4, $t2, 4
/* 10D8D8 7F0D8DA8 15C00003 */  bnez  $t6, .L7F0D8DB8
/* 10D8DC 7F0D8DAC AFAC028C */   sw    $t4, 0x28c($sp)
/* 10D8E0 7F0D8DB0 1000000C */  b     .L7F0D8DE4
/* 10D8E4 7F0D8DB4 AFB60048 */   sw    $s6, 0x48($sp)
.L7F0D8DB8:
/* 10D8E8 7F0D8DB8 24010001 */  li    $at, 1
/* 10D8EC 7F0D8DBC 15010005 */  bne   $t0, $at, .L7F0D8DD4
/* 10D8F0 7F0D8DC0 97A90294 */   lhu   $t1, 0x294($sp)
/* 10D8F4 7F0D8DC4 97B80296 */  lhu   $t8, 0x296($sp)
/* 10D8F8 7F0D8DC8 00187A03 */  sra   $t7, $t8, 8
/* 10D8FC 7F0D8DCC 10000003 */  b     .L7F0D8DDC
/* 10D900 7F0D8DD0 AFAF0044 */   sw    $t7, 0x44($sp)
.L7F0D8DD4:
/* 10D904 7F0D8DD4 0009CA03 */  sra   $t9, $t1, 8
/* 10D908 7F0D8DD8 AFB90044 */  sw    $t9, 0x44($sp)
.L7F0D8DDC:
/* 10D90C 7F0D8DDC 8FAB0044 */  lw    $t3, 0x44($sp)
/* 10D910 7F0D8DE0 AFAB0048 */  sw    $t3, 0x48($sp)
.L7F0D8DE4:
/* 10D914 7F0D8DE4 8FAD0048 */  lw    $t5, 0x48($sp)
/* 10D918 7F0D8DE8 3C198009 */  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
/* 10D91C 7F0D8DEC 8F39E334 */  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
/* 10D920 7F0D8DF0 020D8024 */  and   $s0, $s0, $t5
/* 10D924 7F0D8DF4 320A00FF */  andi  $t2, $s0, 0xff
/* 10D928 7F0D8DF8 2D4C0001 */  sltiu $t4, $t2, 1
/* 10D92C 7F0D8DFC AFAC0048 */  sw    $t4, 0x48($sp)
/* 10D930 7F0D8E00 01595821 */  addu  $t3, $t2, $t9
/* 10D934 7F0D8E04 916D0000 */  lbu   $t5, ($t3)
/* 10D938 7F0D8E08 000CC180 */  sll   $t8, $t4, 6
/* 10D93C 7F0D8E0C 314E00A8 */  andi  $t6, $t2, 0xa8
/* 10D940 7F0D8E10 01D87825 */  or    $t7, $t6, $t8
/* 10D944 7F0D8E14 35E90010 */  ori   $t1, $t7, 0x10
/* 10D948 7F0D8E18 01408025 */  move  $s0, $t2
/* 10D94C 7F0D8E1C 01A98825 */  or    $s1, $t5, $t1
/* 10D950 7F0D8E20 322A00FF */  andi  $t2, $s1, 0xff
/* 10D954 7F0D8E24 10002675 */  b     .L7F0E27FC
/* 10D958 7F0D8E28 01408825 */   move  $s1, $t2
spectrum_op_A5:
/* 10D95C 7F0D8E2C 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10D960 7F0D8E30 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10D964 7F0D8E34 93B80287 */  lbu   $t8, 0x287($sp)
/* 10D968 7F0D8E38 25880004 */  addiu $t0, $t4, 4
/* 10D96C 7F0D8E3C 15C00003 */  bnez  $t6, .L7F0D8E4C
/* 10D970 7F0D8E40 AFA8028C */   sw    $t0, 0x28c($sp)
/* 10D974 7F0D8E44 1000000C */  b     .L7F0D8E78
/* 10D978 7F0D8E48 AFB70048 */   sw    $s7, 0x48($sp)
.L7F0D8E4C:
/* 10D97C 7F0D8E4C 24010001 */  li    $at, 1
/* 10D980 7F0D8E50 17010005 */  bne   $t8, $at, .L7F0D8E68
/* 10D984 7F0D8E54 97AB0294 */   lhu   $t3, 0x294($sp)
/* 10D988 7F0D8E58 97AF0296 */  lhu   $t7, 0x296($sp)
/* 10D98C 7F0D8E5C 31F900FF */  andi  $t9, $t7, 0xff
/* 10D990 7F0D8E60 10000003 */  b     .L7F0D8E70
/* 10D994 7F0D8E64 AFB90044 */   sw    $t9, 0x44($sp)
.L7F0D8E68:
/* 10D998 7F0D8E68 316D00FF */  andi  $t5, $t3, 0xff
/* 10D99C 7F0D8E6C AFAD0044 */  sw    $t5, 0x44($sp)
.L7F0D8E70:
/* 10D9A0 7F0D8E70 8FA90044 */  lw    $t1, 0x44($sp)
/* 10D9A4 7F0D8E74 AFA90048 */  sw    $t1, 0x48($sp)
.L7F0D8E78:
/* 10D9A8 7F0D8E78 8FAA0048 */  lw    $t2, 0x48($sp)
/* 10D9AC 7F0D8E7C 3C0D8009 */  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
/* 10D9B0 7F0D8E80 8DADE334 */  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
/* 10D9B4 7F0D8E84 020A8024 */  and   $s0, $s0, $t2
/* 10D9B8 7F0D8E88 320C00FF */  andi  $t4, $s0, 0xff
/* 10D9BC 7F0D8E8C 2D880001 */  sltiu $t0, $t4, 1
/* 10D9C0 7F0D8E90 AFA80048 */  sw    $t0, 0x48($sp)
/* 10D9C4 7F0D8E94 018D4821 */  addu  $t1, $t4, $t5
/* 10D9C8 7F0D8E98 912A0000 */  lbu   $t2, ($t1)
/* 10D9CC 7F0D8E9C 00087980 */  sll   $t7, $t0, 6
/* 10D9D0 7F0D8EA0 318E00A8 */  andi  $t6, $t4, 0xa8
/* 10D9D4 7F0D8EA4 01CFC825 */  or    $t9, $t6, $t7
/* 10D9D8 7F0D8EA8 372B0010 */  ori   $t3, $t9, 0x10
/* 10D9DC 7F0D8EAC 01808025 */  move  $s0, $t4
/* 10D9E0 7F0D8EB0 014B8825 */  or    $s1, $t2, $t3
/* 10D9E4 7F0D8EB4 322C00FF */  andi  $t4, $s1, 0xff
/* 10D9E8 7F0D8EB8 10002650 */  b     .L7F0E27FC
/* 10D9EC 7F0D8EBC 01808825 */   move  $s1, $t4
spectrum_op_A6:
/* 10D9F0 7F0D8EC0 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10D9F4 7F0D8EC4 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10D9F8 7F0D8EC8 00167A00 */  sll   $t7, $s6, 8
/* 10D9FC 7F0D8ECC 25180007 */  addiu $t8, $t0, 7
/* 10DA00 7F0D8ED0 15C00004 */  bnez  $t6, .L7F0D8EE4
/* 10DA04 7F0D8ED4 AFB8028C */   sw    $t8, 0x28c($sp)
/* 10DA08 7F0D8ED8 01F7C825 */  or    $t9, $t7, $s7
/* 10DA0C 7F0D8EDC 10000016 */  b     .L7F0D8F38
/* 10DA10 7F0D8EE0 A7B90168 */   sh    $t9, 0x168($sp)
.L7F0D8EE4:
/* 10DA14 7F0D8EE4 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10DA18 7F0D8EE8 93AA0287 */  lbu   $t2, 0x287($sp)
/* 10DA1C 7F0D8EEC 24010001 */  li    $at, 1
/* 10DA20 7F0D8EF0 25A90008 */  addiu $t1, $t5, 8
/* 10DA24 7F0D8EF4 15410004 */  bne   $t2, $at, .L7F0D8F08
/* 10DA28 7F0D8EF8 AFA9028C */   sw    $t1, 0x28c($sp)
/* 10DA2C 7F0D8EFC 97AB0296 */  lhu   $t3, 0x296($sp)
/* 10DA30 7F0D8F00 10000003 */  b     .L7F0D8F10
/* 10DA34 7F0D8F04 AFAB0048 */   sw    $t3, 0x48($sp)
.L7F0D8F08:
/* 10DA38 7F0D8F08 97AC0294 */  lhu   $t4, 0x294($sp)
/* 10DA3C 7F0D8F0C AFAC0048 */  sw    $t4, 0x48($sp)
.L7F0D8F10:
/* 10DA40 7F0D8F10 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 10DA44 7F0D8F14 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10DA48 7F0D8F18 97A80298 */  lhu   $t0, 0x298($sp)
/* 10DA4C 7F0D8F1C 8FB90048 */  lw    $t9, 0x48($sp)
/* 10DA50 7F0D8F20 01187021 */  addu  $t6, $t0, $t8
/* 10DA54 7F0D8F24 81CF0000 */  lb    $t7, ($t6)
/* 10DA58 7F0D8F28 25090001 */  addiu $t1, $t0, 1
/* 10DA5C 7F0D8F2C A7A90298 */  sh    $t1, 0x298($sp)
/* 10DA60 7F0D8F30 01F96821 */  addu  $t5, $t7, $t9
/* 10DA64 7F0D8F34 A7AD0168 */  sh    $t5, 0x168($sp)
.L7F0D8F38:
/* 10DA68 7F0D8F38 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 10DA6C 7F0D8F3C 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 10DA70 7F0D8F40 97AB0168 */  lhu   $t3, 0x168($sp)
/* 10DA74 7F0D8F44 014B6021 */  addu  $t4, $t2, $t3
/* 10DA78 7F0D8F48 91980000 */  lbu   $t8, ($t4)
/* 10DA7C 7F0D8F4C 3C0B8009 */  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DA80 7F0D8F50 8D6BE334 */  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
/* 10DA84 7F0D8F54 02188024 */  and   $s0, $s0, $t8
/* 10DA88 7F0D8F58 320E00FF */  andi  $t6, $s0, 0xff
/* 10DA8C 7F0D8F5C 2DCF0001 */  sltiu $t7, $t6, 1
/* 10DA90 7F0D8F60 AFAF0048 */  sw    $t7, 0x48($sp)
/* 10DA94 7F0D8F64 01CB6021 */  addu  $t4, $t6, $t3
/* 10DA98 7F0D8F68 91980000 */  lbu   $t8, ($t4)
/* 10DA9C 7F0D8F6C 000F4180 */  sll   $t0, $t7, 6
/* 10DAA0 7F0D8F70 31D900A8 */  andi  $t9, $t6, 0xa8
/* 10DAA4 7F0D8F74 03284825 */  or    $t1, $t9, $t0
/* 10DAA8 7F0D8F78 352A0010 */  ori   $t2, $t1, 0x10
/* 10DAAC 7F0D8F7C 01C08025 */  move  $s0, $t6
/* 10DAB0 7F0D8F80 030A8825 */  or    $s1, $t8, $t2
/* 10DAB4 7F0D8F84 322E00FF */  andi  $t6, $s1, 0xff
/* 10DAB8 7F0D8F88 1000261C */  b     .L7F0E27FC
/* 10DABC 7F0D8F8C 01C08825 */   move  $s1, $t6
spectrum_op_A7:
/* 10DAC0 7F0D8F90 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10DAC4 7F0D8F94 3C0E8009 */  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DAC8 7F0D8F98 8DCEE334 */  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
/* 10DACC 7F0D8F9C 02108024 */  and   $s0, $s0, $s0
/* 10DAD0 7F0D8FA0 321900FF */  andi  $t9, $s0, 0xff
/* 10DAD4 7F0D8FA4 25ED0004 */  addiu $t5, $t7, 4
/* 10DAD8 7F0D8FA8 2F280001 */  sltiu $t0, $t9, 1
/* 10DADC 7F0D8FAC AFAD028C */  sw    $t5, 0x28c($sp)
/* 10DAE0 7F0D8FB0 AFA80048 */  sw    $t0, 0x48($sp)
/* 10DAE4 7F0D8FB4 032E7821 */  addu  $t7, $t9, $t6
/* 10DAE8 7F0D8FB8 91ED0000 */  lbu   $t5, ($t7)
/* 10DAEC 7F0D8FBC 00086180 */  sll   $t4, $t0, 6
/* 10DAF0 7F0D8FC0 332900A8 */  andi  $t1, $t9, 0xa8
/* 10DAF4 7F0D8FC4 012CC025 */  or    $t8, $t1, $t4
/* 10DAF8 7F0D8FC8 370A0010 */  ori   $t2, $t8, 0x10
/* 10DAFC 7F0D8FCC 03208025 */  move  $s0, $t9
/* 10DB00 7F0D8FD0 01AA8825 */  or    $s1, $t5, $t2
/* 10DB04 7F0D8FD4 323900FF */  andi  $t9, $s1, 0xff
/* 10DB08 7F0D8FD8 10002608 */  b     .L7F0E27FC
/* 10DB0C 7F0D8FDC 03208825 */   move  $s1, $t9
spectrum_op_A8:
/* 10DB10 7F0D8FE0 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10DB14 7F0D8FE4 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DB18 7F0D8FE8 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 10DB1C 7F0D8FEC 02128026 */  xor   $s0, $s0, $s2
/* 10DB20 7F0D8FF0 320900FF */  andi  $t1, $s0, 0xff
/* 10DB24 7F0D8FF4 2D2C0001 */  sltiu $t4, $t1, 1
/* 10DB28 7F0D8FF8 250B0004 */  addiu $t3, $t0, 4
/* 10DB2C 7F0D8FFC AFAB028C */  sw    $t3, 0x28c($sp)
/* 10DB30 7F0D9000 AFAC0048 */  sw    $t4, 0x48($sp)
/* 10DB34 7F0D9004 012AC821 */  addu  $t9, $t1, $t2
/* 10DB38 7F0D9008 93280000 */  lbu   $t0, ($t9)
/* 10DB3C 7F0D900C 000C7980 */  sll   $t7, $t4, 6
/* 10DB40 7F0D9010 313800A8 */  andi  $t8, $t1, 0xa8
/* 10DB44 7F0D9014 030F6825 */  or    $t5, $t8, $t7
/* 10DB48 7F0D9018 010D8825 */  or    $s1, $t0, $t5
/* 10DB4C 7F0D901C 322B00FF */  andi  $t3, $s1, 0xff
/* 10DB50 7F0D9020 01608825 */  move  $s1, $t3
/* 10DB54 7F0D9024 100025F5 */  b     .L7F0E27FC
/* 10DB58 7F0D9028 01208025 */   move  $s0, $t1
spectrum_op_A9:
/* 10DB5C 7F0D902C 8FA9028C */  lw    $t1, 0x28c($sp)
/* 10DB60 7F0D9030 3C0D8009 */  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DB64 7F0D9034 8DADE334 */  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
/* 10DB68 7F0D9038 02138026 */  xor   $s0, $s0, $s3
/* 10DB6C 7F0D903C 320E00FF */  andi  $t6, $s0, 0xff
/* 10DB70 7F0D9040 2DD80001 */  sltiu $t8, $t6, 1
/* 10DB74 7F0D9044 252C0004 */  addiu $t4, $t1, 4
/* 10DB78 7F0D9048 AFAC028C */  sw    $t4, 0x28c($sp)
/* 10DB7C 7F0D904C AFB80048 */  sw    $t8, 0x48($sp)
/* 10DB80 7F0D9050 01CD5821 */  addu  $t3, $t6, $t5
/* 10DB84 7F0D9054 91690000 */  lbu   $t1, ($t3)
/* 10DB88 7F0D9058 0018C980 */  sll   $t9, $t8, 6
/* 10DB8C 7F0D905C 31CF00A8 */  andi  $t7, $t6, 0xa8
/* 10DB90 7F0D9060 01F94025 */  or    $t0, $t7, $t9
/* 10DB94 7F0D9064 01288825 */  or    $s1, $t1, $t0
/* 10DB98 7F0D9068 322C00FF */  andi  $t4, $s1, 0xff
/* 10DB9C 7F0D906C 01808825 */  move  $s1, $t4
/* 10DBA0 7F0D9070 100025E2 */  b     .L7F0E27FC
/* 10DBA4 7F0D9074 01C08025 */   move  $s0, $t6
spectrum_op_AA:
/* 10DBA8 7F0D9078 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10DBAC 7F0D907C 3C088009 */  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DBB0 7F0D9080 8D08E334 */  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
/* 10DBB4 7F0D9084 02148026 */  xor   $s0, $s0, $s4
/* 10DBB8 7F0D9088 320A00FF */  andi  $t2, $s0, 0xff
/* 10DBBC 7F0D908C 2D4F0001 */  sltiu $t7, $t2, 1
/* 10DBC0 7F0D9090 25D80004 */  addiu $t8, $t6, 4
/* 10DBC4 7F0D9094 AFB8028C */  sw    $t8, 0x28c($sp)
/* 10DBC8 7F0D9098 AFAF0048 */  sw    $t7, 0x48($sp)
/* 10DBCC 7F0D909C 01486021 */  addu  $t4, $t2, $t0
/* 10DBD0 7F0D90A0 918E0000 */  lbu   $t6, ($t4)
/* 10DBD4 7F0D90A4 000F5980 */  sll   $t3, $t7, 6
/* 10DBD8 7F0D90A8 315900A8 */  andi  $t9, $t2, 0xa8
/* 10DBDC 7F0D90AC 032B4825 */  or    $t1, $t9, $t3
/* 10DBE0 7F0D90B0 01C98825 */  or    $s1, $t6, $t1
/* 10DBE4 7F0D90B4 323800FF */  andi  $t8, $s1, 0xff
/* 10DBE8 7F0D90B8 03008825 */  move  $s1, $t8
/* 10DBEC 7F0D90BC 100025CF */  b     .L7F0E27FC
/* 10DBF0 7F0D90C0 01408025 */   move  $s0, $t2
spectrum_op_AB:
/* 10DBF4 7F0D90C4 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10DBF8 7F0D90C8 3C098009 */  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DBFC 7F0D90CC 8D29E334 */  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
/* 10DC00 7F0D90D0 02158026 */  xor   $s0, $s0, $s5
/* 10DC04 7F0D90D4 320D00FF */  andi  $t5, $s0, 0xff
/* 10DC08 7F0D90D8 2DB90001 */  sltiu $t9, $t5, 1
/* 10DC0C 7F0D90DC 254F0004 */  addiu $t7, $t2, 4
/* 10DC10 7F0D90E0 AFAF028C */  sw    $t7, 0x28c($sp)
/* 10DC14 7F0D90E4 AFB90048 */  sw    $t9, 0x48($sp)
/* 10DC18 7F0D90E8 01A9C021 */  addu  $t8, $t5, $t1
/* 10DC1C 7F0D90EC 930A0000 */  lbu   $t2, ($t8)
/* 10DC20 7F0D90F0 00196180 */  sll   $t4, $t9, 6
/* 10DC24 7F0D90F4 31AB00A8 */  andi  $t3, $t5, 0xa8
/* 10DC28 7F0D90F8 016C7025 */  or    $t6, $t3, $t4
/* 10DC2C 7F0D90FC 014E8825 */  or    $s1, $t2, $t6
/* 10DC30 7F0D9100 322F00FF */  andi  $t7, $s1, 0xff
/* 10DC34 7F0D9104 01E08825 */  move  $s1, $t7
/* 10DC38 7F0D9108 100025BC */  b     .L7F0E27FC
/* 10DC3C 7F0D910C 01A08025 */   move  $s0, $t5
spectrum_op_AC:
/* 10DC40 7F0D9110 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10DC44 7F0D9114 93A80287 */  lbu   $t0, 0x287($sp)
/* 10DC48 7F0D9118 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10DC4C 7F0D911C 25B90004 */  addiu $t9, $t5, 4
/* 10DC50 7F0D9120 15000003 */  bnez  $t0, .L7F0D9130
/* 10DC54 7F0D9124 AFB9028C */   sw    $t9, 0x28c($sp)
/* 10DC58 7F0D9128 1000000C */  b     .L7F0D915C
/* 10DC5C 7F0D912C AFB60048 */   sw    $s6, 0x48($sp)
.L7F0D9130:
/* 10DC60 7F0D9130 24010001 */  li    $at, 1
/* 10DC64 7F0D9134 15610005 */  bne   $t3, $at, .L7F0D914C
/* 10DC68 7F0D9138 97B80294 */   lhu   $t8, 0x294($sp)
/* 10DC6C 7F0D913C 97AC0296 */  lhu   $t4, 0x296($sp)
/* 10DC70 7F0D9140 000C4A03 */  sra   $t1, $t4, 8
/* 10DC74 7F0D9144 10000003 */  b     .L7F0D9154
/* 10DC78 7F0D9148 AFA90044 */   sw    $t1, 0x44($sp)
.L7F0D914C:
/* 10DC7C 7F0D914C 00185203 */  sra   $t2, $t8, 8
/* 10DC80 7F0D9150 AFAA0044 */  sw    $t2, 0x44($sp)
.L7F0D9154:
/* 10DC84 7F0D9154 8FAE0044 */  lw    $t6, 0x44($sp)
/* 10DC88 7F0D9158 AFAE0048 */  sw    $t6, 0x48($sp)
.L7F0D915C:
/* 10DC8C 7F0D915C 8FAF0048 */  lw    $t7, 0x48($sp)
/* 10DC90 7F0D9160 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DC94 7F0D9164 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 10DC98 7F0D9168 020F8026 */  xor   $s0, $s0, $t7
/* 10DC9C 7F0D916C 320D00FF */  andi  $t5, $s0, 0xff
/* 10DCA0 7F0D9170 2DB90001 */  sltiu $t9, $t5, 1
/* 10DCA4 7F0D9174 AFB90048 */  sw    $t9, 0x48($sp)
/* 10DCA8 7F0D9178 01B85021 */  addu  $t2, $t5, $t8
/* 10DCAC 7F0D917C 914E0000 */  lbu   $t6, ($t2)
/* 10DCB0 7F0D9180 00196180 */  sll   $t4, $t9, 6
/* 10DCB4 7F0D9184 31A800A8 */  andi  $t0, $t5, 0xa8
/* 10DCB8 7F0D9188 010C4825 */  or    $t1, $t0, $t4
/* 10DCBC 7F0D918C 01C98825 */  or    $s1, $t6, $t1
/* 10DCC0 7F0D9190 322F00FF */  andi  $t7, $s1, 0xff
/* 10DCC4 7F0D9194 01E08825 */  move  $s1, $t7
/* 10DCC8 7F0D9198 10002598 */  b     .L7F0E27FC
/* 10DCCC 7F0D919C 01A08025 */   move  $s0, $t5
spectrum_op_AD:
/* 10DCD0 7F0D91A0 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10DCD4 7F0D91A4 93AB0287 */  lbu   $t3, 0x287($sp)
/* 10DCD8 7F0D91A8 93A80287 */  lbu   $t0, 0x287($sp)
/* 10DCDC 7F0D91AC 25B90004 */  addiu $t9, $t5, 4
/* 10DCE0 7F0D91B0 15600003 */  bnez  $t3, .L7F0D91C0
/* 10DCE4 7F0D91B4 AFB9028C */   sw    $t9, 0x28c($sp)
/* 10DCE8 7F0D91B8 1000000C */  b     .L7F0D91EC
/* 10DCEC 7F0D91BC AFB70048 */   sw    $s7, 0x48($sp)
.L7F0D91C0:
/* 10DCF0 7F0D91C0 24010001 */  li    $at, 1
/* 10DCF4 7F0D91C4 15010005 */  bne   $t0, $at, .L7F0D91DC
/* 10DCF8 7F0D91C8 97AA0294 */   lhu   $t2, 0x294($sp)
/* 10DCFC 7F0D91CC 97AC0296 */  lhu   $t4, 0x296($sp)
/* 10DD00 7F0D91D0 319800FF */  andi  $t8, $t4, 0xff
/* 10DD04 7F0D91D4 10000003 */  b     .L7F0D91E4
/* 10DD08 7F0D91D8 AFB80044 */   sw    $t8, 0x44($sp)
.L7F0D91DC:
/* 10DD0C 7F0D91DC 314E00FF */  andi  $t6, $t2, 0xff
/* 10DD10 7F0D91E0 AFAE0044 */  sw    $t6, 0x44($sp)
.L7F0D91E4:
/* 10DD14 7F0D91E4 8FA90044 */  lw    $t1, 0x44($sp)
/* 10DD18 7F0D91E8 AFA90048 */  sw    $t1, 0x48($sp)
.L7F0D91EC:
/* 10DD1C 7F0D91EC 8FAF0048 */  lw    $t7, 0x48($sp)
/* 10DD20 7F0D91F0 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DD24 7F0D91F4 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 10DD28 7F0D91F8 020F8026 */  xor   $s0, $s0, $t7
/* 10DD2C 7F0D91FC 320D00FF */  andi  $t5, $s0, 0xff
/* 10DD30 7F0D9200 2DB90001 */  sltiu $t9, $t5, 1
/* 10DD34 7F0D9204 AFB90048 */  sw    $t9, 0x48($sp)
/* 10DD38 7F0D9208 01AA7021 */  addu  $t6, $t5, $t2
/* 10DD3C 7F0D920C 91C90000 */  lbu   $t1, ($t6)
/* 10DD40 7F0D9210 00196180 */  sll   $t4, $t9, 6
/* 10DD44 7F0D9214 31AB00A8 */  andi  $t3, $t5, 0xa8
/* 10DD48 7F0D9218 016CC025 */  or    $t8, $t3, $t4
/* 10DD4C 7F0D921C 01388825 */  or    $s1, $t1, $t8
/* 10DD50 7F0D9220 322F00FF */  andi  $t7, $s1, 0xff
/* 10DD54 7F0D9224 01E08825 */  move  $s1, $t7
/* 10DD58 7F0D9228 10002574 */  b     .L7F0E27FC
/* 10DD5C 7F0D922C 01A08025 */   move  $s0, $t5
spectrum_op_AE:
/* 10DD60 7F0D9230 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10DD64 7F0D9234 93A80287 */  lbu   $t0, 0x287($sp)
/* 10DD68 7F0D9238 00165A00 */  sll   $t3, $s6, 8
/* 10DD6C 7F0D923C 25B90007 */  addiu $t9, $t5, 7
/* 10DD70 7F0D9240 15000004 */  bnez  $t0, .L7F0D9254
/* 10DD74 7F0D9244 AFB9028C */   sw    $t9, 0x28c($sp)
/* 10DD78 7F0D9248 01776025 */  or    $t4, $t3, $s7
/* 10DD7C 7F0D924C 10000016 */  b     .L7F0D92A8
/* 10DD80 7F0D9250 A7AC0166 */   sh    $t4, 0x166($sp)
.L7F0D9254:
/* 10DD84 7F0D9254 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10DD88 7F0D9258 93A90287 */  lbu   $t1, 0x287($sp)
/* 10DD8C 7F0D925C 24010001 */  li    $at, 1
/* 10DD90 7F0D9260 254E0008 */  addiu $t6, $t2, 8
/* 10DD94 7F0D9264 15210004 */  bne   $t1, $at, .L7F0D9278
/* 10DD98 7F0D9268 AFAE028C */   sw    $t6, 0x28c($sp)
/* 10DD9C 7F0D926C 97B80296 */  lhu   $t8, 0x296($sp)
/* 10DDA0 7F0D9270 10000003 */  b     .L7F0D9280
/* 10DDA4 7F0D9274 AFB80048 */   sw    $t8, 0x48($sp)
.L7F0D9278:
/* 10DDA8 7F0D9278 97AF0294 */  lhu   $t7, 0x294($sp)
/* 10DDAC 7F0D927C AFAF0048 */  sw    $t7, 0x48($sp)
.L7F0D9280:
/* 10DDB0 7F0D9280 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10DDB4 7F0D9284 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10DDB8 7F0D9288 97AD0298 */  lhu   $t5, 0x298($sp)
/* 10DDBC 7F0D928C 8FAC0048 */  lw    $t4, 0x48($sp)
/* 10DDC0 7F0D9290 01B94021 */  addu  $t0, $t5, $t9
/* 10DDC4 7F0D9294 810B0000 */  lb    $t3, ($t0)
/* 10DDC8 7F0D9298 25AE0001 */  addiu $t6, $t5, 1
/* 10DDCC 7F0D929C A7AE0298 */  sh    $t6, 0x298($sp)
/* 10DDD0 7F0D92A0 016C5021 */  addu  $t2, $t3, $t4
/* 10DDD4 7F0D92A4 A7AA0166 */  sh    $t2, 0x166($sp)
.L7F0D92A8:
/* 10DDD8 7F0D92A8 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10DDDC 7F0D92AC 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10DDE0 7F0D92B0 97B80166 */  lhu   $t8, 0x166($sp)
/* 10DDE4 7F0D92B4 01387821 */  addu  $t7, $t1, $t8
/* 10DDE8 7F0D92B8 91F90000 */  lbu   $t9, ($t7)
/* 10DDEC 7F0D92BC 3C098009 */  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DDF0 7F0D92C0 8D29E334 */  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
/* 10DDF4 7F0D92C4 02198026 */  xor   $s0, $s0, $t9
/* 10DDF8 7F0D92C8 320800FF */  andi  $t0, $s0, 0xff
/* 10DDFC 7F0D92CC 2D0B0001 */  sltiu $t3, $t0, 1
/* 10DE00 7F0D92D0 AFAB0048 */  sw    $t3, 0x48($sp)
/* 10DE04 7F0D92D4 0109C021 */  addu  $t8, $t0, $t1
/* 10DE08 7F0D92D8 930F0000 */  lbu   $t7, ($t8)
/* 10DE0C 7F0D92DC 000B6980 */  sll   $t5, $t3, 6
/* 10DE10 7F0D92E0 310C00A8 */  andi  $t4, $t0, 0xa8
/* 10DE14 7F0D92E4 018D7025 */  or    $t6, $t4, $t5
/* 10DE18 7F0D92E8 01EE8825 */  or    $s1, $t7, $t6
/* 10DE1C 7F0D92EC 323900FF */  andi  $t9, $s1, 0xff
/* 10DE20 7F0D92F0 03208825 */  move  $s1, $t9
/* 10DE24 7F0D92F4 10002541 */  b     .L7F0E27FC
/* 10DE28 7F0D92F8 01008025 */   move  $s0, $t0
spectrum_op_AF:
/* 10DE2C 7F0D92FC 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10DE30 7F0D9300 3C0E8009 */  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DE34 7F0D9304 8DCEE334 */  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
/* 10DE38 7F0D9308 02108026 */  xor   $s0, $s0, $s0
/* 10DE3C 7F0D930C 320A00FF */  andi  $t2, $s0, 0xff
/* 10DE40 7F0D9310 2D4C0001 */  sltiu $t4, $t2, 1
/* 10DE44 7F0D9314 250B0004 */  addiu $t3, $t0, 4
/* 10DE48 7F0D9318 AFAB028C */  sw    $t3, 0x28c($sp)
/* 10DE4C 7F0D931C AFAC0048 */  sw    $t4, 0x48($sp)
/* 10DE50 7F0D9320 014EC821 */  addu  $t9, $t2, $t6
/* 10DE54 7F0D9324 93280000 */  lbu   $t0, ($t9)
/* 10DE58 7F0D9328 000CC180 */  sll   $t8, $t4, 6
/* 10DE5C 7F0D932C 314D00A8 */  andi  $t5, $t2, 0xa8
/* 10DE60 7F0D9330 01B87825 */  or    $t7, $t5, $t8
/* 10DE64 7F0D9334 010F8825 */  or    $s1, $t0, $t7
/* 10DE68 7F0D9338 322B00FF */  andi  $t3, $s1, 0xff
/* 10DE6C 7F0D933C 01608825 */  move  $s1, $t3
/* 10DE70 7F0D9340 1000252E */  b     .L7F0E27FC
/* 10DE74 7F0D9344 01408025 */   move  $s0, $t2
spectrum_op_B0:
/* 10DE78 7F0D9348 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10DE7C 7F0D934C 3C0F8009 */  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DE80 7F0D9350 8DEFE334 */  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
/* 10DE84 7F0D9354 02128025 */  or    $s0, $s0, $s2
/* 10DE88 7F0D9358 320900FF */  andi  $t1, $s0, 0xff
/* 10DE8C 7F0D935C 2D2D0001 */  sltiu $t5, $t1, 1
/* 10DE90 7F0D9360 254C0004 */  addiu $t4, $t2, 4
/* 10DE94 7F0D9364 AFAC028C */  sw    $t4, 0x28c($sp)
/* 10DE98 7F0D9368 AFAD0048 */  sw    $t5, 0x48($sp)
/* 10DE9C 7F0D936C 012F5821 */  addu  $t3, $t1, $t7
/* 10DEA0 7F0D9370 916A0000 */  lbu   $t2, ($t3)
/* 10DEA4 7F0D9374 000DC980 */  sll   $t9, $t5, 6
/* 10DEA8 7F0D9378 313800A8 */  andi  $t8, $t1, 0xa8
/* 10DEAC 7F0D937C 03194025 */  or    $t0, $t8, $t9
/* 10DEB0 7F0D9380 01488825 */  or    $s1, $t2, $t0
/* 10DEB4 7F0D9384 322C00FF */  andi  $t4, $s1, 0xff
/* 10DEB8 7F0D9388 01808825 */  move  $s1, $t4
/* 10DEBC 7F0D938C 1000251B */  b     .L7F0E27FC
/* 10DEC0 7F0D9390 01208025 */   move  $s0, $t1
spectrum_op_B1:
/* 10DEC4 7F0D9394 8FA9028C */  lw    $t1, 0x28c($sp)
/* 10DEC8 7F0D9398 3C088009 */  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DECC 7F0D939C 8D08E334 */  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
/* 10DED0 7F0D93A0 02138025 */  or    $s0, $s0, $s3
/* 10DED4 7F0D93A4 320E00FF */  andi  $t6, $s0, 0xff
/* 10DED8 7F0D93A8 2DD80001 */  sltiu $t8, $t6, 1
/* 10DEDC 7F0D93AC 252D0004 */  addiu $t5, $t1, 4
/* 10DEE0 7F0D93B0 AFAD028C */  sw    $t5, 0x28c($sp)
/* 10DEE4 7F0D93B4 AFB80048 */  sw    $t8, 0x48($sp)
/* 10DEE8 7F0D93B8 01C86021 */  addu  $t4, $t6, $t0
/* 10DEEC 7F0D93BC 91890000 */  lbu   $t1, ($t4)
/* 10DEF0 7F0D93C0 00185980 */  sll   $t3, $t8, 6
/* 10DEF4 7F0D93C4 31D900A8 */  andi  $t9, $t6, 0xa8
/* 10DEF8 7F0D93C8 032B5025 */  or    $t2, $t9, $t3
/* 10DEFC 7F0D93CC 012A8825 */  or    $s1, $t1, $t2
/* 10DF00 7F0D93D0 322D00FF */  andi  $t5, $s1, 0xff
/* 10DF04 7F0D93D4 01A08825 */  move  $s1, $t5
/* 10DF08 7F0D93D8 10002508 */  b     .L7F0E27FC
/* 10DF0C 7F0D93DC 01C08025 */   move  $s0, $t6
spectrum_op_B2:
/* 10DF10 7F0D93E0 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10DF14 7F0D93E4 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DF18 7F0D93E8 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 10DF1C 7F0D93EC 02148025 */  or    $s0, $s0, $s4
/* 10DF20 7F0D93F0 320F00FF */  andi  $t7, $s0, 0xff
/* 10DF24 7F0D93F4 2DF90001 */  sltiu $t9, $t7, 1
/* 10DF28 7F0D93F8 25D80004 */  addiu $t8, $t6, 4
/* 10DF2C 7F0D93FC AFB8028C */  sw    $t8, 0x28c($sp)
/* 10DF30 7F0D9400 AFB90048 */  sw    $t9, 0x48($sp)
/* 10DF34 7F0D9404 01EA6821 */  addu  $t5, $t7, $t2
/* 10DF38 7F0D9408 91AE0000 */  lbu   $t6, ($t5)
/* 10DF3C 7F0D940C 00196180 */  sll   $t4, $t9, 6
/* 10DF40 7F0D9410 31EB00A8 */  andi  $t3, $t7, 0xa8
/* 10DF44 7F0D9414 016C4825 */  or    $t1, $t3, $t4
/* 10DF48 7F0D9418 01C98825 */  or    $s1, $t6, $t1
/* 10DF4C 7F0D941C 323800FF */  andi  $t8, $s1, 0xff
/* 10DF50 7F0D9420 03008825 */  move  $s1, $t8
/* 10DF54 7F0D9424 100024F5 */  b     .L7F0E27FC
/* 10DF58 7F0D9428 01E08025 */   move  $s0, $t7
spectrum_op_B3:
/* 10DF5C 7F0D942C 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10DF60 7F0D9430 3C098009 */  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DF64 7F0D9434 8D29E334 */  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
/* 10DF68 7F0D9438 02158025 */  or    $s0, $s0, $s5
/* 10DF6C 7F0D943C 320800FF */  andi  $t0, $s0, 0xff
/* 10DF70 7F0D9440 2D0B0001 */  sltiu $t3, $t0, 1
/* 10DF74 7F0D9444 25F90004 */  addiu $t9, $t7, 4
/* 10DF78 7F0D9448 AFB9028C */  sw    $t9, 0x28c($sp)
/* 10DF7C 7F0D944C AFAB0048 */  sw    $t3, 0x48($sp)
/* 10DF80 7F0D9450 0109C021 */  addu  $t8, $t0, $t1
/* 10DF84 7F0D9454 930F0000 */  lbu   $t7, ($t8)
/* 10DF88 7F0D9458 000B6980 */  sll   $t5, $t3, 6
/* 10DF8C 7F0D945C 310C00A8 */  andi  $t4, $t0, 0xa8
/* 10DF90 7F0D9460 018D7025 */  or    $t6, $t4, $t5
/* 10DF94 7F0D9464 01EE8825 */  or    $s1, $t7, $t6
/* 10DF98 7F0D9468 323900FF */  andi  $t9, $s1, 0xff
/* 10DF9C 7F0D946C 03208825 */  move  $s1, $t9
/* 10DFA0 7F0D9470 100024E2 */  b     .L7F0E27FC
/* 10DFA4 7F0D9474 01008025 */   move  $s0, $t0
spectrum_op_B4:
/* 10DFA8 7F0D9478 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10DFAC 7F0D947C 93AA0287 */  lbu   $t2, 0x287($sp)
/* 10DFB0 7F0D9480 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10DFB4 7F0D9484 250B0004 */  addiu $t3, $t0, 4
/* 10DFB8 7F0D9488 15400003 */  bnez  $t2, .L7F0D9498
/* 10DFBC 7F0D948C AFAB028C */   sw    $t3, 0x28c($sp)
/* 10DFC0 7F0D9490 1000000C */  b     .L7F0D94C4
/* 10DFC4 7F0D9494 AFB60048 */   sw    $s6, 0x48($sp)
.L7F0D9498:
/* 10DFC8 7F0D9498 24010001 */  li    $at, 1
/* 10DFCC 7F0D949C 15810005 */  bne   $t4, $at, .L7F0D94B4
/* 10DFD0 7F0D94A0 97B80294 */   lhu   $t8, 0x294($sp)
/* 10DFD4 7F0D94A4 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10DFD8 7F0D94A8 000D4A03 */  sra   $t1, $t5, 8
/* 10DFDC 7F0D94AC 10000003 */  b     .L7F0D94BC
/* 10DFE0 7F0D94B0 AFA90044 */   sw    $t1, 0x44($sp)
.L7F0D94B4:
/* 10DFE4 7F0D94B4 00187A03 */  sra   $t7, $t8, 8
/* 10DFE8 7F0D94B8 AFAF0044 */  sw    $t7, 0x44($sp)
.L7F0D94BC:
/* 10DFEC 7F0D94BC 8FAE0044 */  lw    $t6, 0x44($sp)
/* 10DFF0 7F0D94C0 AFAE0048 */  sw    $t6, 0x48($sp)
.L7F0D94C4:
/* 10DFF4 7F0D94C4 8FB90048 */  lw    $t9, 0x48($sp)
/* 10DFF8 7F0D94C8 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 10DFFC 7F0D94CC 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 10E000 7F0D94D0 02198025 */  or    $s0, $s0, $t9
/* 10E004 7F0D94D4 320800FF */  andi  $t0, $s0, 0xff
/* 10E008 7F0D94D8 2D0B0001 */  sltiu $t3, $t0, 1
/* 10E00C 7F0D94DC AFAB0048 */  sw    $t3, 0x48($sp)
/* 10E010 7F0D94E0 01187821 */  addu  $t7, $t0, $t8
/* 10E014 7F0D94E4 91EE0000 */  lbu   $t6, ($t7)
/* 10E018 7F0D94E8 000B6980 */  sll   $t5, $t3, 6
/* 10E01C 7F0D94EC 310A00A8 */  andi  $t2, $t0, 0xa8
/* 10E020 7F0D94F0 014D4825 */  or    $t1, $t2, $t5
/* 10E024 7F0D94F4 01C98825 */  or    $s1, $t6, $t1
/* 10E028 7F0D94F8 323900FF */  andi  $t9, $s1, 0xff
/* 10E02C 7F0D94FC 03208825 */  move  $s1, $t9
/* 10E030 7F0D9500 100024BE */  b     .L7F0E27FC
/* 10E034 7F0D9504 01008025 */   move  $s0, $t0
spectrum_op_B5:
/* 10E038 7F0D9508 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10E03C 7F0D950C 93AC0287 */  lbu   $t4, 0x287($sp)
/* 10E040 7F0D9510 93AA0287 */  lbu   $t2, 0x287($sp)
/* 10E044 7F0D9514 250B0004 */  addiu $t3, $t0, 4
/* 10E048 7F0D9518 15800003 */  bnez  $t4, .L7F0D9528
/* 10E04C 7F0D951C AFAB028C */   sw    $t3, 0x28c($sp)
/* 10E050 7F0D9520 1000000C */  b     .L7F0D9554
/* 10E054 7F0D9524 AFB70048 */   sw    $s7, 0x48($sp)
.L7F0D9528:
/* 10E058 7F0D9528 24010001 */  li    $at, 1
/* 10E05C 7F0D952C 15410005 */  bne   $t2, $at, .L7F0D9544
/* 10E060 7F0D9530 97AF0294 */   lhu   $t7, 0x294($sp)
/* 10E064 7F0D9534 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10E068 7F0D9538 31B800FF */  andi  $t8, $t5, 0xff
/* 10E06C 7F0D953C 10000003 */  b     .L7F0D954C
/* 10E070 7F0D9540 AFB80044 */   sw    $t8, 0x44($sp)
.L7F0D9544:
/* 10E074 7F0D9544 31EE00FF */  andi  $t6, $t7, 0xff
/* 10E078 7F0D9548 AFAE0044 */  sw    $t6, 0x44($sp)
.L7F0D954C:
/* 10E07C 7F0D954C 8FA90044 */  lw    $t1, 0x44($sp)
/* 10E080 7F0D9550 AFA90048 */  sw    $t1, 0x48($sp)
.L7F0D9554:
/* 10E084 7F0D9554 8FB90048 */  lw    $t9, 0x48($sp)
/* 10E088 7F0D9558 3C0F8009 */  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
/* 10E08C 7F0D955C 8DEFE334 */  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
/* 10E090 7F0D9560 02198025 */  or    $s0, $s0, $t9
/* 10E094 7F0D9564 320800FF */  andi  $t0, $s0, 0xff
/* 10E098 7F0D9568 2D0B0001 */  sltiu $t3, $t0, 1
/* 10E09C 7F0D956C AFAB0048 */  sw    $t3, 0x48($sp)
/* 10E0A0 7F0D9570 010F7021 */  addu  $t6, $t0, $t7
/* 10E0A4 7F0D9574 91C90000 */  lbu   $t1, ($t6)
/* 10E0A8 7F0D9578 000B6980 */  sll   $t5, $t3, 6
/* 10E0AC 7F0D957C 310C00A8 */  andi  $t4, $t0, 0xa8
/* 10E0B0 7F0D9580 018DC025 */  or    $t8, $t4, $t5
/* 10E0B4 7F0D9584 01388825 */  or    $s1, $t1, $t8
/* 10E0B8 7F0D9588 323900FF */  andi  $t9, $s1, 0xff
/* 10E0BC 7F0D958C 03208825 */  move  $s1, $t9
/* 10E0C0 7F0D9590 1000249A */  b     .L7F0E27FC
/* 10E0C4 7F0D9594 01008025 */   move  $s0, $t0
spectrum_op_B6:
/* 10E0C8 7F0D9598 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10E0CC 7F0D959C 93AA0287 */  lbu   $t2, 0x287($sp)
/* 10E0D0 7F0D95A0 00166200 */  sll   $t4, $s6, 8
/* 10E0D4 7F0D95A4 250B0007 */  addiu $t3, $t0, 7
/* 10E0D8 7F0D95A8 15400004 */  bnez  $t2, .L7F0D95BC
/* 10E0DC 7F0D95AC AFAB028C */   sw    $t3, 0x28c($sp)
/* 10E0E0 7F0D95B0 01976825 */  or    $t5, $t4, $s7
/* 10E0E4 7F0D95B4 10000016 */  b     .L7F0D9610
/* 10E0E8 7F0D95B8 A7AD0164 */   sh    $t5, 0x164($sp)
.L7F0D95BC:
/* 10E0EC 7F0D95BC 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10E0F0 7F0D95C0 93A90287 */  lbu   $t1, 0x287($sp)
/* 10E0F4 7F0D95C4 24010001 */  li    $at, 1
/* 10E0F8 7F0D95C8 25EE0008 */  addiu $t6, $t7, 8
/* 10E0FC 7F0D95CC 15210004 */  bne   $t1, $at, .L7F0D95E0
/* 10E100 7F0D95D0 AFAE028C */   sw    $t6, 0x28c($sp)
/* 10E104 7F0D95D4 97B80296 */  lhu   $t8, 0x296($sp)
/* 10E108 7F0D95D8 10000003 */  b     .L7F0D95E8
/* 10E10C 7F0D95DC AFB80048 */   sw    $t8, 0x48($sp)
.L7F0D95E0:
/* 10E110 7F0D95E0 97B90294 */  lhu   $t9, 0x294($sp)
/* 10E114 7F0D95E4 AFB90048 */  sw    $t9, 0x48($sp)
.L7F0D95E8:
/* 10E118 7F0D95E8 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 10E11C 7F0D95EC 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10E120 7F0D95F0 97A80298 */  lhu   $t0, 0x298($sp)
/* 10E124 7F0D95F4 8FAD0048 */  lw    $t5, 0x48($sp)
/* 10E128 7F0D95F8 010B5021 */  addu  $t2, $t0, $t3
/* 10E12C 7F0D95FC 814C0000 */  lb    $t4, ($t2)
/* 10E130 7F0D9600 250E0001 */  addiu $t6, $t0, 1
/* 10E134 7F0D9604 A7AE0298 */  sh    $t6, 0x298($sp)
/* 10E138 7F0D9608 018D7821 */  addu  $t7, $t4, $t5
/* 10E13C 7F0D960C A7AF0164 */  sh    $t7, 0x164($sp)
.L7F0D9610:
/* 10E140 7F0D9610 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10E144 7F0D9614 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10E148 7F0D9618 97B80164 */  lhu   $t8, 0x164($sp)
/* 10E14C 7F0D961C 0138C821 */  addu  $t9, $t1, $t8
/* 10E150 7F0D9620 932B0000 */  lbu   $t3, ($t9)
/* 10E154 7F0D9624 3C098009 */  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
/* 10E158 7F0D9628 8D29E334 */  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
/* 10E15C 7F0D962C 020B8025 */  or    $s0, $s0, $t3
/* 10E160 7F0D9630 320A00FF */  andi  $t2, $s0, 0xff
/* 10E164 7F0D9634 2D4C0001 */  sltiu $t4, $t2, 1
/* 10E168 7F0D9638 AFAC0048 */  sw    $t4, 0x48($sp)
/* 10E16C 7F0D963C 0149C021 */  addu  $t8, $t2, $t1
/* 10E170 7F0D9640 93190000 */  lbu   $t9, ($t8)
/* 10E174 7F0D9644 000C4180 */  sll   $t0, $t4, 6
/* 10E178 7F0D9648 314D00A8 */  andi  $t5, $t2, 0xa8
/* 10E17C 7F0D964C 01A87025 */  or    $t6, $t5, $t0
/* 10E180 7F0D9650 032E8825 */  or    $s1, $t9, $t6
/* 10E184 7F0D9654 322B00FF */  andi  $t3, $s1, 0xff
/* 10E188 7F0D9658 01608825 */  move  $s1, $t3
/* 10E18C 7F0D965C 10002467 */  b     .L7F0E27FC
/* 10E190 7F0D9660 01408025 */   move  $s0, $t2
spectrum_op_B7:
/* 10E194 7F0D9664 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10E198 7F0D9668 3C0E8009 */  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
/* 10E19C 7F0D966C 8DCEE334 */  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
/* 10E1A0 7F0D9670 02108025 */  or    $s0, $s0, $s0
/* 10E1A4 7F0D9674 320F00FF */  andi  $t7, $s0, 0xff
/* 10E1A8 7F0D9678 2DED0001 */  sltiu $t5, $t7, 1
/* 10E1AC 7F0D967C 254C0004 */  addiu $t4, $t2, 4
/* 10E1B0 7F0D9680 AFAC028C */  sw    $t4, 0x28c($sp)
/* 10E1B4 7F0D9684 AFAD0048 */  sw    $t5, 0x48($sp)
/* 10E1B8 7F0D9688 01EE5821 */  addu  $t3, $t7, $t6
/* 10E1BC 7F0D968C 916A0000 */  lbu   $t2, ($t3)
/* 10E1C0 7F0D9690 000DC180 */  sll   $t8, $t5, 6
/* 10E1C4 7F0D9694 31E800A8 */  andi  $t0, $t7, 0xa8
/* 10E1C8 7F0D9698 0118C825 */  or    $t9, $t0, $t8
/* 10E1CC 7F0D969C 01598825 */  or    $s1, $t2, $t9
/* 10E1D0 7F0D96A0 322C00FF */  andi  $t4, $s1, 0xff
/* 10E1D4 7F0D96A4 01808825 */  move  $s1, $t4
/* 10E1D8 7F0D96A8 10002454 */  b     .L7F0E27FC
/* 10E1DC 7F0D96AC 01E08025 */   move  $s0, $t7
spectrum_op_B8:
/* 10E1E0 7F0D96B0 324900FF */  andi  $t1, $s2, 0xff
/* 10E1E4 7F0D96B4 02094023 */  subu  $t0, $s0, $t1
/* 10E1E8 7F0D96B8 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10E1EC 7F0D96BC 311801FF */  andi  $t8, $t0, 0x1ff
/* 10E1F0 7F0D96C0 330EFFFF */  andi  $t6, $t8, 0xffff
/* 10E1F4 7F0D96C4 2DCB0001 */  sltiu $t3, $t6, 1
/* 10E1F8 7F0D96C8 312E000F */  andi  $t6, $t1, 0xf
/* 10E1FC 7F0D96CC 3208000F */  andi  $t0, $s0, 0xf
/* 10E200 7F0D96D0 25ED0004 */  addiu $t5, $t7, 4
/* 10E204 7F0D96D4 010E502A */  slt   $t2, $t0, $t6
/* 10E208 7F0D96D8 AFAD028C */  sw    $t5, 0x28c($sp)
/* 10E20C 7F0D96DC 00187A03 */  sra   $t7, $t8, 8
/* 10E210 7F0D96E0 331900A8 */  andi  $t9, $t8, 0xa8
/* 10E214 7F0D96E4 032F6825 */  or    $t5, $t9, $t7
/* 10E218 7F0D96E8 000A6100 */  sll   $t4, $t2, 4
/* 10E21C 7F0D96EC 02097826 */  xor   $t7, $s0, $t1
/* 10E220 7F0D96F0 03007025 */  move  $t6, $t8
/* 10E224 7F0D96F4 01D05026 */  xor   $t2, $t6, $s0
/* 10E228 7F0D96F8 31E80080 */  andi  $t0, $t7, 0x80
/* 10E22C 7F0D96FC 01ACC825 */  or    $t9, $t5, $t4
/* 10E230 7F0D9700 010A6824 */  and   $t5, $t0, $t2
/* 10E234 7F0D9704 000D6143 */  sra   $t4, $t5, 5
/* 10E238 7F0D9708 032C4825 */  or    $t1, $t9, $t4
/* 10E23C 7F0D970C A7B80162 */  sh    $t8, 0x162($sp)
/* 10E240 7F0D9710 000BC180 */  sll   $t8, $t3, 6
/* 10E244 7F0D9714 352F0002 */  ori   $t7, $t1, 2
/* 10E248 7F0D9718 01F88825 */  or    $s1, $t7, $t8
/* 10E24C 7F0D971C 322E00FF */  andi  $t6, $s1, 0xff
/* 10E250 7F0D9720 01C08825 */  move  $s1, $t6
/* 10E254 7F0D9724 AFAB0048 */  sw    $t3, 0x48($sp)
/* 10E258 7F0D9728 10002434 */  b     .L7F0E27FC
/* 10E25C 7F0D972C A3B20161 */   sb    $s2, 0x161($sp)
spectrum_op_B9:
/* 10E260 7F0D9730 326D00FF */  andi  $t5, $s3, 0xff
/* 10E264 7F0D9734 020DC823 */  subu  $t9, $s0, $t5
/* 10E268 7F0D9738 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10E26C 7F0D973C 332C01FF */  andi  $t4, $t9, 0x1ff
/* 10E270 7F0D9740 3189FFFF */  andi  $t1, $t4, 0xffff
/* 10E274 7F0D9744 2D2B0001 */  sltiu $t3, $t1, 1
/* 10E278 7F0D9748 31A9000F */  andi  $t1, $t5, 0xf
/* 10E27C 7F0D974C 3219000F */  andi  $t9, $s0, 0xf
/* 10E280 7F0D9750 250A0004 */  addiu $t2, $t0, 4
/* 10E284 7F0D9754 0329782A */  slt   $t7, $t9, $t1
/* 10E288 7F0D9758 AFAA028C */  sw    $t2, 0x28c($sp)
/* 10E28C 7F0D975C 000C4203 */  sra   $t0, $t4, 8
/* 10E290 7F0D9760 319800A8 */  andi  $t8, $t4, 0xa8
/* 10E294 7F0D9764 03085025 */  or    $t2, $t8, $t0
/* 10E298 7F0D9768 000F7100 */  sll   $t6, $t7, 4
/* 10E29C 7F0D976C 020D4026 */  xor   $t0, $s0, $t5
/* 10E2A0 7F0D9770 01804825 */  move  $t1, $t4
/* 10E2A4 7F0D9774 01307826 */  xor   $t7, $t1, $s0
/* 10E2A8 7F0D9778 31190080 */  andi  $t9, $t0, 0x80
/* 10E2AC 7F0D977C 014EC025 */  or    $t8, $t2, $t6
/* 10E2B0 7F0D9780 032F5024 */  and   $t2, $t9, $t7
/* 10E2B4 7F0D9784 000A7143 */  sra   $t6, $t2, 5
/* 10E2B8 7F0D9788 030E6825 */  or    $t5, $t8, $t6
/* 10E2BC 7F0D978C A7AC015E */  sh    $t4, 0x15e($sp)
/* 10E2C0 7F0D9790 000B6180 */  sll   $t4, $t3, 6
/* 10E2C4 7F0D9794 35A80002 */  ori   $t0, $t5, 2
/* 10E2C8 7F0D9798 010C8825 */  or    $s1, $t0, $t4
/* 10E2CC 7F0D979C 322900FF */  andi  $t1, $s1, 0xff
/* 10E2D0 7F0D97A0 01208825 */  move  $s1, $t1
/* 10E2D4 7F0D97A4 AFAB0048 */  sw    $t3, 0x48($sp)
/* 10E2D8 7F0D97A8 10002414 */  b     .L7F0E27FC
/* 10E2DC 7F0D97AC A3B3015D */   sb    $s3, 0x15d($sp)
spectrum_op_BA:
/* 10E2E0 7F0D97B0 328A00FF */  andi  $t2, $s4, 0xff
/* 10E2E4 7F0D97B4 020AC023 */  subu  $t8, $s0, $t2
/* 10E2E8 7F0D97B8 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10E2EC 7F0D97BC 330E01FF */  andi  $t6, $t8, 0x1ff
/* 10E2F0 7F0D97C0 31CDFFFF */  andi  $t5, $t6, 0xffff
/* 10E2F4 7F0D97C4 2DAB0001 */  sltiu $t3, $t5, 1
/* 10E2F8 7F0D97C8 314D000F */  andi  $t5, $t2, 0xf
/* 10E2FC 7F0D97CC 3218000F */  andi  $t8, $s0, 0xf
/* 10E300 7F0D97D0 272F0004 */  addiu $t7, $t9, 4
/* 10E304 7F0D97D4 030D402A */  slt   $t0, $t8, $t5
/* 10E308 7F0D97D8 AFAF028C */  sw    $t7, 0x28c($sp)
/* 10E30C 7F0D97DC 000ECA03 */  sra   $t9, $t6, 8
/* 10E310 7F0D97E0 31CC00A8 */  andi  $t4, $t6, 0xa8
/* 10E314 7F0D97E4 01997825 */  or    $t7, $t4, $t9
/* 10E318 7F0D97E8 00084900 */  sll   $t1, $t0, 4
/* 10E31C 7F0D97EC 020AC826 */  xor   $t9, $s0, $t2
/* 10E320 7F0D97F0 01C06825 */  move  $t5, $t6
/* 10E324 7F0D97F4 01B04026 */  xor   $t0, $t5, $s0
/* 10E328 7F0D97F8 33380080 */  andi  $t8, $t9, 0x80
/* 10E32C 7F0D97FC 01E96025 */  or    $t4, $t7, $t1
/* 10E330 7F0D9800 03087824 */  and   $t7, $t8, $t0
/* 10E334 7F0D9804 000F4943 */  sra   $t1, $t7, 5
/* 10E338 7F0D9808 01895025 */  or    $t2, $t4, $t1
/* 10E33C 7F0D980C A7AE015A */  sh    $t6, 0x15a($sp)
/* 10E340 7F0D9810 000B7180 */  sll   $t6, $t3, 6
/* 10E344 7F0D9814 35590002 */  ori   $t9, $t2, 2
/* 10E348 7F0D9818 032E8825 */  or    $s1, $t9, $t6
/* 10E34C 7F0D981C 322D00FF */  andi  $t5, $s1, 0xff
/* 10E350 7F0D9820 01A08825 */  move  $s1, $t5
/* 10E354 7F0D9824 AFAB0048 */  sw    $t3, 0x48($sp)
/* 10E358 7F0D9828 100023F4 */  b     .L7F0E27FC
/* 10E35C 7F0D982C A3B40159 */   sb    $s4, 0x159($sp)
spectrum_op_BB:
/* 10E360 7F0D9830 32AF00FF */  andi  $t7, $s5, 0xff
/* 10E364 7F0D9834 020F6023 */  subu  $t4, $s0, $t7
/* 10E368 7F0D9838 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10E36C 7F0D983C 318901FF */  andi  $t1, $t4, 0x1ff
/* 10E370 7F0D9840 312AFFFF */  andi  $t2, $t1, 0xffff
/* 10E374 7F0D9844 2D4B0001 */  sltiu $t3, $t2, 1
/* 10E378 7F0D9848 31EA000F */  andi  $t2, $t7, 0xf
/* 10E37C 7F0D984C 320C000F */  andi  $t4, $s0, 0xf
/* 10E380 7F0D9850 27080004 */  addiu $t0, $t8, 4
/* 10E384 7F0D9854 018AC82A */  slt   $t9, $t4, $t2
/* 10E388 7F0D9858 AFA8028C */  sw    $t0, 0x28c($sp)
/* 10E38C 7F0D985C 0009C203 */  sra   $t8, $t1, 8
/* 10E390 7F0D9860 312E00A8 */  andi  $t6, $t1, 0xa8
/* 10E394 7F0D9864 01D84025 */  or    $t0, $t6, $t8
/* 10E398 7F0D9868 00196900 */  sll   $t5, $t9, 4
/* 10E39C 7F0D986C 020FC026 */  xor   $t8, $s0, $t7
/* 10E3A0 7F0D9870 01205025 */  move  $t2, $t1
/* 10E3A4 7F0D9874 0150C826 */  xor   $t9, $t2, $s0
/* 10E3A8 7F0D9878 330C0080 */  andi  $t4, $t8, 0x80
/* 10E3AC 7F0D987C 010D7025 */  or    $t6, $t0, $t5
/* 10E3B0 7F0D9880 01994024 */  and   $t0, $t4, $t9
/* 10E3B4 7F0D9884 00086943 */  sra   $t5, $t0, 5
/* 10E3B8 7F0D9888 01CD7825 */  or    $t7, $t6, $t5
/* 10E3BC 7F0D988C A7A90156 */  sh    $t1, 0x156($sp)
/* 10E3C0 7F0D9890 000B4980 */  sll   $t1, $t3, 6
/* 10E3C4 7F0D9894 35F80002 */  ori   $t8, $t7, 2
/* 10E3C8 7F0D9898 03098825 */  or    $s1, $t8, $t1
/* 10E3CC 7F0D989C 322A00FF */  andi  $t2, $s1, 0xff
/* 10E3D0 7F0D98A0 01408825 */  move  $s1, $t2
/* 10E3D4 7F0D98A4 AFAB0048 */  sw    $t3, 0x48($sp)
/* 10E3D8 7F0D98A8 100023D4 */  b     .L7F0E27FC
/* 10E3DC 7F0D98AC A3B50155 */   sb    $s5, 0x155($sp)
spectrum_op_BC:
/* 10E3E0 7F0D98B0 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10E3E4 7F0D98B4 93A80287 */  lbu   $t0, 0x287($sp)
/* 10E3E8 7F0D98B8 93AE0287 */  lbu   $t6, 0x287($sp)
/* 10E3EC 7F0D98BC 25990004 */  addiu $t9, $t4, 4
/* 10E3F0 7F0D98C0 15000003 */  bnez  $t0, .L7F0D98D0
/* 10E3F4 7F0D98C4 AFB9028C */   sw    $t9, 0x28c($sp)
/* 10E3F8 7F0D98C8 1000000C */  b     .L7F0D98FC
/* 10E3FC 7F0D98CC A3B60151 */   sb    $s6, 0x151($sp)
.L7F0D98D0:
/* 10E400 7F0D98D0 24010001 */  li    $at, 1
/* 10E404 7F0D98D4 15C10005 */  bne   $t6, $at, .L7F0D98EC
/* 10E408 7F0D98D8 97AB0294 */   lhu   $t3, 0x294($sp)
/* 10E40C 7F0D98DC 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10E410 7F0D98E0 000D7A03 */  sra   $t7, $t5, 8
/* 10E414 7F0D98E4 10000003 */  b     .L7F0D98F4
/* 10E418 7F0D98E8 AFAF0048 */   sw    $t7, 0x48($sp)
.L7F0D98EC:
/* 10E41C 7F0D98EC 000BC203 */  sra   $t8, $t3, 8
/* 10E420 7F0D98F0 AFB80048 */  sw    $t8, 0x48($sp)
.L7F0D98F4:
/* 10E424 7F0D98F4 8FA90048 */  lw    $t1, 0x48($sp)
/* 10E428 7F0D98F8 A3A90151 */  sb    $t1, 0x151($sp)
.L7F0D98FC:
/* 10E42C 7F0D98FC 93AA0151 */  lbu   $t2, 0x151($sp)
/* 10E430 7F0D9900 020A6023 */  subu  $t4, $s0, $t2
/* 10E434 7F0D9904 319901FF */  andi  $t9, $t4, 0x1ff
/* 10E438 7F0D9908 3328FFFF */  andi  $t0, $t9, 0xffff
/* 10E43C 7F0D990C 2D0E0001 */  sltiu $t6, $t0, 1
/* 10E440 7F0D9910 320C000F */  andi  $t4, $s0, 0xf
/* 10E444 7F0D9914 3148000F */  andi  $t0, $t2, 0xf
/* 10E448 7F0D9918 0188682A */  slt   $t5, $t4, $t0
/* 10E44C 7F0D991C 332F00A8 */  andi  $t7, $t9, 0xa8
/* 10E450 7F0D9920 0019C203 */  sra   $t8, $t9, 8
/* 10E454 7F0D9924 01F84825 */  or    $t1, $t7, $t8
/* 10E458 7F0D9928 000D5900 */  sll   $t3, $t5, 4
/* 10E45C 7F0D992C 03204025 */  move  $t0, $t9
/* 10E460 7F0D9930 020AC026 */  xor   $t8, $s0, $t2
/* 10E464 7F0D9934 330C0080 */  andi  $t4, $t8, 0x80
/* 10E468 7F0D9938 01106826 */  xor   $t5, $t0, $s0
/* 10E46C 7F0D993C 012B7825 */  or    $t7, $t1, $t3
/* 10E470 7F0D9940 018D4824 */  and   $t1, $t4, $t5
/* 10E474 7F0D9944 00095943 */  sra   $t3, $t1, 5
/* 10E478 7F0D9948 01EB5025 */  or    $t2, $t7, $t3
/* 10E47C 7F0D994C A7B90152 */  sh    $t9, 0x152($sp)
/* 10E480 7F0D9950 000EC980 */  sll   $t9, $t6, 6
/* 10E484 7F0D9954 35580002 */  ori   $t8, $t2, 2
/* 10E488 7F0D9958 03198825 */  or    $s1, $t8, $t9
/* 10E48C 7F0D995C 322800FF */  andi  $t0, $s1, 0xff
/* 10E490 7F0D9960 01008825 */  move  $s1, $t0
/* 10E494 7F0D9964 100023A5 */  b     .L7F0E27FC
/* 10E498 7F0D9968 AFAE0048 */   sw    $t6, 0x48($sp)
spectrum_op_BD:
/* 10E49C 7F0D996C 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10E4A0 7F0D9970 93A90287 */  lbu   $t1, 0x287($sp)
/* 10E4A4 7F0D9974 93AF0287 */  lbu   $t7, 0x287($sp)
/* 10E4A8 7F0D9978 258D0004 */  addiu $t5, $t4, 4
/* 10E4AC 7F0D997C 15200003 */  bnez  $t1, .L7F0D998C
/* 10E4B0 7F0D9980 AFAD028C */   sw    $t5, 0x28c($sp)
/* 10E4B4 7F0D9984 1000000C */  b     .L7F0D99B8
/* 10E4B8 7F0D9988 A3B7014D */   sb    $s7, 0x14d($sp)
.L7F0D998C:
/* 10E4BC 7F0D998C 24010001 */  li    $at, 1
/* 10E4C0 7F0D9990 15E10005 */  bne   $t7, $at, .L7F0D99A8
/* 10E4C4 7F0D9994 97AE0294 */   lhu   $t6, 0x294($sp)
/* 10E4C8 7F0D9998 97AB0296 */  lhu   $t3, 0x296($sp)
/* 10E4CC 7F0D999C 316A00FF */  andi  $t2, $t3, 0xff
/* 10E4D0 7F0D99A0 10000003 */  b     .L7F0D99B0
/* 10E4D4 7F0D99A4 AFAA0048 */   sw    $t2, 0x48($sp)
.L7F0D99A8:
/* 10E4D8 7F0D99A8 31D800FF */  andi  $t8, $t6, 0xff
/* 10E4DC 7F0D99AC AFB80048 */  sw    $t8, 0x48($sp)
.L7F0D99B0:
/* 10E4E0 7F0D99B0 8FB90048 */  lw    $t9, 0x48($sp)
/* 10E4E4 7F0D99B4 A3B9014D */  sb    $t9, 0x14d($sp)
.L7F0D99B8:
/* 10E4E8 7F0D99B8 93A8014D */  lbu   $t0, 0x14d($sp)
/* 10E4EC 7F0D99BC 02086023 */  subu  $t4, $s0, $t0
/* 10E4F0 7F0D99C0 318D01FF */  andi  $t5, $t4, 0x1ff
/* 10E4F4 7F0D99C4 31A9FFFF */  andi  $t1, $t5, 0xffff
/* 10E4F8 7F0D99C8 2D2F0001 */  sltiu $t7, $t1, 1
/* 10E4FC 7F0D99CC 320C000F */  andi  $t4, $s0, 0xf
/* 10E500 7F0D99D0 3109000F */  andi  $t1, $t0, 0xf
/* 10E504 7F0D99D4 0189582A */  slt   $t3, $t4, $t1
/* 10E508 7F0D99D8 31AA00A8 */  andi  $t2, $t5, 0xa8
/* 10E50C 7F0D99DC 000DC203 */  sra   $t8, $t5, 8
/* 10E510 7F0D99E0 0158C825 */  or    $t9, $t2, $t8
/* 10E514 7F0D99E4 000B7100 */  sll   $t6, $t3, 4
/* 10E518 7F0D99E8 01A04825 */  move  $t1, $t5
/* 10E51C 7F0D99EC 0208C026 */  xor   $t8, $s0, $t0
/* 10E520 7F0D99F0 330C0080 */  andi  $t4, $t8, 0x80
/* 10E524 7F0D99F4 01305826 */  xor   $t3, $t1, $s0
/* 10E528 7F0D99F8 032E5025 */  or    $t2, $t9, $t6
/* 10E52C 7F0D99FC 018BC824 */  and   $t9, $t4, $t3
/* 10E530 7F0D9A00 00197143 */  sra   $t6, $t9, 5
/* 10E534 7F0D9A04 014E4025 */  or    $t0, $t2, $t6
/* 10E538 7F0D9A08 A7AD014E */  sh    $t5, 0x14e($sp)
/* 10E53C 7F0D9A0C 000F6980 */  sll   $t5, $t7, 6
/* 10E540 7F0D9A10 35180002 */  ori   $t8, $t0, 2
/* 10E544 7F0D9A14 030D8825 */  or    $s1, $t8, $t5
/* 10E548 7F0D9A18 322900FF */  andi  $t1, $s1, 0xff
/* 10E54C 7F0D9A1C 01208825 */  move  $s1, $t1
/* 10E550 7F0D9A20 10002376 */  b     .L7F0E27FC
/* 10E554 7F0D9A24 AFAF0048 */   sw    $t7, 0x48($sp)
spectrum_op_BE:
/* 10E558 7F0D9A28 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10E55C 7F0D9A2C 93B90287 */  lbu   $t9, 0x287($sp)
/* 10E560 7F0D9A30 00165200 */  sll   $t2, $s6, 8
/* 10E564 7F0D9A34 258B0007 */  addiu $t3, $t4, 7
/* 10E568 7F0D9A38 17200004 */  bnez  $t9, .L7F0D9A4C
/* 10E56C 7F0D9A3C AFAB028C */   sw    $t3, 0x28c($sp)
/* 10E570 7F0D9A40 01577025 */  or    $t6, $t2, $s7
/* 10E574 7F0D9A44 10000016 */  b     .L7F0D9AA0
/* 10E578 7F0D9A48 A7AE014A */   sh    $t6, 0x14a($sp)
.L7F0D9A4C:
/* 10E57C 7F0D9A4C 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10E580 7F0D9A50 93B80287 */  lbu   $t8, 0x287($sp)
/* 10E584 7F0D9A54 24010001 */  li    $at, 1
/* 10E588 7F0D9A58 250F0008 */  addiu $t7, $t0, 8
/* 10E58C 7F0D9A5C 17010004 */  bne   $t8, $at, .L7F0D9A70
/* 10E590 7F0D9A60 AFAF028C */   sw    $t7, 0x28c($sp)
/* 10E594 7F0D9A64 97AD0296 */  lhu   $t5, 0x296($sp)
/* 10E598 7F0D9A68 10000003 */  b     .L7F0D9A78
/* 10E59C 7F0D9A6C AFAD0048 */   sw    $t5, 0x48($sp)
.L7F0D9A70:
/* 10E5A0 7F0D9A70 97A90294 */  lhu   $t1, 0x294($sp)
/* 10E5A4 7F0D9A74 AFA90048 */  sw    $t1, 0x48($sp)
.L7F0D9A78:
/* 10E5A8 7F0D9A78 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 10E5AC 7F0D9A7C 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10E5B0 7F0D9A80 97AC0298 */  lhu   $t4, 0x298($sp)
/* 10E5B4 7F0D9A84 8FAE0048 */  lw    $t6, 0x48($sp)
/* 10E5B8 7F0D9A88 018BC821 */  addu  $t9, $t4, $t3
/* 10E5BC 7F0D9A8C 832A0000 */  lb    $t2, ($t9)
/* 10E5C0 7F0D9A90 258F0001 */  addiu $t7, $t4, 1
/* 10E5C4 7F0D9A94 A7AF0298 */  sh    $t7, 0x298($sp)
/* 10E5C8 7F0D9A98 014E4021 */  addu  $t0, $t2, $t6
/* 10E5CC 7F0D9A9C A7A8014A */  sh    $t0, 0x14a($sp)
.L7F0D9AA0:
/* 10E5D0 7F0D9AA0 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 10E5D4 7F0D9AA4 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10E5D8 7F0D9AA8 97B8014A */  lhu   $t8, 0x14a($sp)
/* 10E5DC 7F0D9AAC 030D4821 */  addu  $t1, $t8, $t5
/* 10E5E0 7F0D9AB0 912B0000 */  lbu   $t3, ($t1)
/* 10E5E4 7F0D9AB4 020BC823 */  subu  $t9, $s0, $t3
/* 10E5E8 7F0D9AB8 332A01FF */  andi  $t2, $t9, 0x1ff
/* 10E5EC 7F0D9ABC 314EFFFF */  andi  $t6, $t2, 0xffff
/* 10E5F0 7F0D9AC0 2DC80001 */  sltiu $t0, $t6, 1
/* 10E5F4 7F0D9AC4 320E000F */  andi  $t6, $s0, 0xf
/* 10E5F8 7F0D9AC8 3179000F */  andi  $t9, $t3, 0xf
/* 10E5FC 7F0D9ACC 01D9602A */  slt   $t4, $t6, $t9
/* 10E600 7F0D9AD0 314F00A8 */  andi  $t7, $t2, 0xa8
/* 10E604 7F0D9AD4 000A6A03 */  sra   $t5, $t2, 8
/* 10E608 7F0D9AD8 01ED4825 */  or    $t1, $t7, $t5
/* 10E60C 7F0D9ADC 000CC100 */  sll   $t8, $t4, 4
/* 10E610 7F0D9AE0 0140C825 */  move  $t9, $t2
/* 10E614 7F0D9AE4 020B6826 */  xor   $t5, $s0, $t3
/* 10E618 7F0D9AE8 31AE0080 */  andi  $t6, $t5, 0x80
/* 10E61C 7F0D9AEC 03306026 */  xor   $t4, $t9, $s0
/* 10E620 7F0D9AF0 01387825 */  or    $t7, $t1, $t8
/* 10E624 7F0D9AF4 01CC4824 */  and   $t1, $t6, $t4
/* 10E628 7F0D9AF8 0009C143 */  sra   $t8, $t1, 5
/* 10E62C 7F0D9AFC A3AB0147 */  sb    $t3, 0x147($sp)
/* 10E630 7F0D9B00 01F85825 */  or    $t3, $t7, $t8
/* 10E634 7F0D9B04 A7AA0148 */  sh    $t2, 0x148($sp)
/* 10E638 7F0D9B08 00085180 */  sll   $t2, $t0, 6
/* 10E63C 7F0D9B0C 356D0002 */  ori   $t5, $t3, 2
/* 10E640 7F0D9B10 01AA8825 */  or    $s1, $t5, $t2
/* 10E644 7F0D9B14 323900FF */  andi  $t9, $s1, 0xff
/* 10E648 7F0D9B18 03208825 */  move  $s1, $t9
/* 10E64C 7F0D9B1C 10002337 */  b     .L7F0E27FC
/* 10E650 7F0D9B20 AFA80048 */   sw    $t0, 0x48($sp)
spectrum_op_BF:
/* 10E654 7F0D9B24 320900FF */  andi  $t1, $s0, 0xff
/* 10E658 7F0D9B28 02097823 */  subu  $t7, $s0, $t1
/* 10E65C 7F0D9B2C 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10E660 7F0D9B30 31F801FF */  andi  $t8, $t7, 0x1ff
/* 10E664 7F0D9B34 330BFFFF */  andi  $t3, $t8, 0xffff
/* 10E668 7F0D9B38 2D680001 */  sltiu $t0, $t3, 1
/* 10E66C 7F0D9B3C 312B000F */  andi  $t3, $t1, 0xf
/* 10E670 7F0D9B40 320F000F */  andi  $t7, $s0, 0xf
/* 10E674 7F0D9B44 25CC0004 */  addiu $t4, $t6, 4
/* 10E678 7F0D9B48 01EB682A */  slt   $t5, $t7, $t3
/* 10E67C 7F0D9B4C AFAC028C */  sw    $t4, 0x28c($sp)
/* 10E680 7F0D9B50 00187203 */  sra   $t6, $t8, 8
/* 10E684 7F0D9B54 330A00A8 */  andi  $t2, $t8, 0xa8
/* 10E688 7F0D9B58 014E6025 */  or    $t4, $t2, $t6
/* 10E68C 7F0D9B5C 000DC900 */  sll   $t9, $t5, 4
/* 10E690 7F0D9B60 02097026 */  xor   $t6, $s0, $t1
/* 10E694 7F0D9B64 03005825 */  move  $t3, $t8
/* 10E698 7F0D9B68 01706826 */  xor   $t5, $t3, $s0
/* 10E69C 7F0D9B6C 31CF0080 */  andi  $t7, $t6, 0x80
/* 10E6A0 7F0D9B70 01995025 */  or    $t2, $t4, $t9
/* 10E6A4 7F0D9B74 01ED6024 */  and   $t4, $t7, $t5
/* 10E6A8 7F0D9B78 000CC943 */  sra   $t9, $t4, 5
/* 10E6AC 7F0D9B7C 01594825 */  or    $t1, $t2, $t9
/* 10E6B0 7F0D9B80 A7B80144 */  sh    $t8, 0x144($sp)
/* 10E6B4 7F0D9B84 0008C180 */  sll   $t8, $t0, 6
/* 10E6B8 7F0D9B88 352E0002 */  ori   $t6, $t1, 2
/* 10E6BC 7F0D9B8C 01D88825 */  or    $s1, $t6, $t8
/* 10E6C0 7F0D9B90 322B00FF */  andi  $t3, $s1, 0xff
/* 10E6C4 7F0D9B94 01608825 */  move  $s1, $t3
/* 10E6C8 7F0D9B98 AFA80048 */  sw    $t0, 0x48($sp)
/* 10E6CC 7F0D9B9C 10002317 */  b     .L7F0E27FC
/* 10E6D0 7F0D9BA0 A3B00143 */   sb    $s0, 0x143($sp)
spectrum_op_C0:
/* 10E6D4 7F0D9BA4 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10E6D8 7F0D9BA8 322C0040 */  andi  $t4, $s1, 0x40
/* 10E6DC 7F0D9BAC 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10E6E0 7F0D9BB0 25ED0005 */  addiu $t5, $t7, 5
/* 10E6E4 7F0D9BB4 15802311 */  bnez  $t4, .L7F0E27FC
/* 10E6E8 7F0D9BB8 AFAD028C */   sw    $t5, 0x28c($sp)
/* 10E6EC 7F0D9BBC 97A90292 */  lhu   $t1, 0x292($sp)
/* 10E6F0 7F0D9BC0 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10E6F4 7F0D9BC4 25B90006 */  addiu $t9, $t5, 6
/* 10E6F8 7F0D9BC8 AFB9028C */  sw    $t9, 0x28c($sp)
/* 10E6FC 7F0D9BCC 01095821 */  addu  $t3, $t0, $t1
/* 10E700 7F0D9BD0 916F0001 */  lbu   $t7, 1($t3)
/* 10E704 7F0D9BD4 01287021 */  addu  $t6, $t1, $t0
/* 10E708 7F0D9BD8 91D80000 */  lbu   $t8, ($t6)
/* 10E70C 7F0D9BDC 000F6A00 */  sll   $t5, $t7, 8
/* 10E710 7F0D9BE0 252A0002 */  addiu $t2, $t1, 2
/* 10E714 7F0D9BE4 030D6025 */  or    $t4, $t8, $t5
/* 10E718 7F0D9BE8 A7AC0298 */  sh    $t4, 0x298($sp)
/* 10E71C 7F0D9BEC 10002303 */  b     .L7F0E27FC
/* 10E720 7F0D9BF0 A7AA0292 */   sh    $t2, 0x292($sp)
spectrum_op_C1:
/* 10E724 7F0D9BF4 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10E728 7F0D9BF8 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 10E72C 7F0D9BFC 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10E730 7F0D9C00 97A80292 */  lhu   $t0, 0x292($sp)
/* 10E734 7F0D9C04 272E000A */  addiu $t6, $t9, 0xa
/* 10E738 7F0D9C08 AFAE028C */  sw    $t6, 0x28c($sp)
/* 10E73C 7F0D9C0C 010B7821 */  addu  $t7, $t0, $t3
/* 10E740 7F0D9C10 91F30000 */  lbu   $s3, ($t7)
/* 10E744 7F0D9C14 91F20001 */  lbu   $s2, 1($t7)
/* 10E748 7F0D9C18 25180002 */  addiu $t8, $t0, 2
/* 10E74C 7F0D9C1C 100022F7 */  b     .L7F0E27FC
/* 10E750 7F0D9C20 A7B80292 */   sh    $t8, 0x292($sp)
spectrum_op_C2:
/* 10E754 7F0D9C24 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10E758 7F0D9C28 32290040 */  andi  $t1, $s1, 0x40
/* 10E75C 7F0D9C2C 97AA0298 */  lhu   $t2, 0x298($sp)
/* 10E760 7F0D9C30 25AC000A */  addiu $t4, $t5, 0xa
/* 10E764 7F0D9C34 1520000B */  bnez  $t1, .L7F0D9C64
/* 10E768 7F0D9C38 AFAC028C */   sw    $t4, 0x28c($sp)
/* 10E76C 7F0D9C3C 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10E770 7F0D9C40 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10E774 7F0D9C44 032A7821 */  addu  $t7, $t9, $t2
/* 10E778 7F0D9C48 91E80001 */  lbu   $t0, 1($t7)
/* 10E77C 7F0D9C4C 01597021 */  addu  $t6, $t2, $t9
/* 10E780 7F0D9C50 91CB0000 */  lbu   $t3, ($t6)
/* 10E784 7F0D9C54 0008C200 */  sll   $t8, $t0, 8
/* 10E788 7F0D9C58 01786825 */  or    $t5, $t3, $t8
/* 10E78C 7F0D9C5C 100022E7 */  b     .L7F0E27FC
/* 10E790 7F0D9C60 A7AD0298 */   sh    $t5, 0x298($sp)
.L7F0D9C64:
/* 10E794 7F0D9C64 97AC0298 */  lhu   $t4, 0x298($sp)
/* 10E798 7F0D9C68 25890002 */  addiu $t1, $t4, 2
/* 10E79C 7F0D9C6C 100022E3 */  b     .L7F0E27FC
/* 10E7A0 7F0D9C70 A7A90298 */   sh    $t1, 0x298($sp)
spectrum_op_C3:
/* 10E7A4 7F0D9C74 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10E7A8 7F0D9C78 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 10E7AC 7F0D9C7C 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10E7B0 7F0D9C80 97AA0298 */  lhu   $t2, 0x298($sp)
/* 10E7B4 7F0D9C84 25D9000A */  addiu $t9, $t6, 0xa
/* 10E7B8 7F0D9C88 AFB9028C */  sw    $t9, 0x28c($sp)
/* 10E7BC 7F0D9C8C 01EAC021 */  addu  $t8, $t7, $t2
/* 10E7C0 7F0D9C90 930D0001 */  lbu   $t5, 1($t8)
/* 10E7C4 7F0D9C94 014F4021 */  addu  $t0, $t2, $t7
/* 10E7C8 7F0D9C98 910B0000 */  lbu   $t3, ($t0)
/* 10E7CC 7F0D9C9C 000D6200 */  sll   $t4, $t5, 8
/* 10E7D0 7F0D9CA0 016C4825 */  or    $t1, $t3, $t4
/* 10E7D4 7F0D9CA4 100022D5 */  b     .L7F0E27FC
/* 10E7D8 7F0D9CA8 A7A90298 */   sh    $t1, 0x298($sp)
spectrum_op_C4:
/* 10E7DC 7F0D9CAC 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10E7E0 7F0D9CB0 32280040 */  andi  $t0, $s1, 0x40
/* 10E7E4 7F0D9CB4 25D9000A */  addiu $t9, $t6, 0xa
/* 10E7E8 7F0D9CB8 15000072 */  bnez  $t0, .L7F0D9E84
/* 10E7EC 7F0D9CBC AFB9028C */   sw    $t9, 0x28c($sp)
/* 10E7F0 7F0D9CC0 97B80292 */  lhu   $t8, 0x292($sp)
/* 10E7F4 7F0D9CC4 272A0007 */  addiu $t2, $t9, 7
/* 10E7F8 7F0D9CC8 AFAA028C */  sw    $t2, 0x28c($sp)
/* 10E7FC 7F0D9CCC 270DFFFE */  addiu $t5, $t8, -2
/* 10E800 7F0D9CD0 31ABFFFF */  andi  $t3, $t5, 0xffff
/* 10E804 7F0D9CD4 29615B00 */  slti  $at, $t3, 0x5b00
/* 10E808 7F0D9CD8 14200008 */  bnez  $at, .L7F0D9CFC
/* 10E80C 7F0D9CDC A7AD0292 */   sh    $t5, 0x292($sp)
/* 10E810 7F0D9CE0 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10E814 7F0D9CE4 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10E818 7F0D9CE8 97AC0298 */  lhu   $t4, 0x298($sp)
/* 10E81C 7F0D9CEC 01CBC821 */  addu  $t9, $t6, $t3
/* 10E820 7F0D9CF0 25890002 */  addiu $t1, $t4, 2
/* 10E824 7F0D9CF4 10000024 */  b     .L7F0D9D88
/* 10E828 7F0D9CF8 A3290000 */   sb    $t1, ($t9)
.L7F0D9CFC:
/* 10E82C 7F0D9CFC 97A80292 */  lhu   $t0, 0x292($sp)
/* 10E830 7F0D9D00 97B90292 */  lhu   $t9, 0x292($sp)
/* 10E834 7F0D9D04 97AF0298 */  lhu   $t7, 0x298($sp)
/* 10E838 7F0D9D08 29015800 */  slti  $at, $t0, 0x5800
/* 10E83C 7F0D9D0C 1420000C */  bnez  $at, .L7F0D9D40
/* 10E840 7F0D9D10 3C188009 */   lui   $t8, %hi(ptr_spectrum_roms) 
/* 10E844 7F0D9D14 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10E848 7F0D9D18 25EA0002 */  addiu $t2, $t7, 2
/* 10E84C 7F0D9D1C 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 10E850 7F0D9D20 03086821 */  addu  $t5, $t8, $t0
/* 10E854 7F0D9D24 A1AA0000 */  sb    $t2, ($t5)
/* 10E858 7F0D9D28 97AB0292 */  lhu   $t3, 0x292($sp)
/* 10E85C 7F0D9D2C 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 10E860 7F0D9D30 240C0001 */  li    $t4, 1
/* 10E864 7F0D9D34 01CB4821 */  addu  $t1, $t6, $t3
/* 10E868 7F0D9D38 10000013 */  b     .L7F0D9D88
/* 10E86C 7F0D9D3C A12CA800 */   sb    $t4, -0x5800($t1)
.L7F0D9D40:
/* 10E870 7F0D9D40 2B214000 */  slti  $at, $t9, 0x4000
/* 10E874 7F0D9D44 14200010 */  bnez  $at, .L7F0D9D88
/* 10E878 7F0D9D48 97AF0298 */   lhu   $t7, 0x298($sp)
/* 10E87C 7F0D9D4C 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10E880 7F0D9D50 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10E884 7F0D9D54 25F80002 */  addiu $t8, $t7, 2
/* 10E888 7F0D9D58 240D0001 */  li    $t5, 1
/* 10E88C 7F0D9D5C 01195021 */  addu  $t2, $t0, $t9
/* 10E890 7F0D9D60 A1580000 */  sb    $t8, ($t2)
/* 10E894 7F0D9D64 97AE0292 */  lhu   $t6, 0x292($sp)
/* 10E898 7F0D9D68 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 10E89C 7F0D9D6C 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 10E8A0 7F0D9D70 31CB1800 */  andi  $t3, $t6, 0x1800
/* 10E8A4 7F0D9D74 000B60C3 */  sra   $t4, $t3, 3
/* 10E8A8 7F0D9D78 31C900FF */  andi  $t1, $t6, 0xff
/* 10E8AC 7F0D9D7C 01897825 */  or    $t7, $t4, $t1
/* 10E8B0 7F0D9D80 010FC821 */  addu  $t9, $t0, $t7
/* 10E8B4 7F0D9D84 A32D0000 */  sb    $t5, ($t9)
.L7F0D9D88:
/* 10E8B8 7F0D9D88 97B80292 */  lhu   $t8, 0x292($sp)
/* 10E8BC 7F0D9D8C 97AF0292 */  lhu   $t7, 0x292($sp)
/* 10E8C0 7F0D9D90 97AB0298 */  lhu   $t3, 0x298($sp)
/* 10E8C4 7F0D9D94 270A0001 */  addiu $t2, $t8, 1
/* 10E8C8 7F0D9D98 29415B00 */  slti  $at, $t2, 0x5b00
/* 10E8CC 7F0D9D9C 14200008 */  bnez  $at, .L7F0D9DC0
/* 10E8D0 7F0D9DA0 25ED0001 */   addiu $t5, $t7, 1
/* 10E8D4 7F0D9DA4 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10E8D8 7F0D9DA8 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10E8DC 7F0D9DAC 256E0002 */  addiu $t6, $t3, 2
/* 10E8E0 7F0D9DB0 000E6203 */  sra   $t4, $t6, 8
/* 10E8E4 7F0D9DB4 01384021 */  addu  $t0, $t1, $t8
/* 10E8E8 7F0D9DB8 10000027 */  b     .L7F0D9E58
/* 10E8EC 7F0D9DBC A10C0001 */   sb    $t4, 1($t0)
.L7F0D9DC0:
/* 10E8F0 7F0D9DC0 29A15800 */  slti  $at, $t5, 0x5800
/* 10E8F4 7F0D9DC4 1420000F */  bnez  $at, .L7F0D9E04
/* 10E8F8 7F0D9DC8 97B90292 */   lhu   $t9, 0x292($sp)
/* 10E8FC 7F0D9DCC 97B90298 */  lhu   $t9, 0x298($sp)
/* 10E900 7F0D9DD0 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10E904 7F0D9DD4 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10E908 7F0D9DD8 272A0002 */  addiu $t2, $t9, 2
/* 10E90C 7F0D9DDC 000A5A03 */  sra   $t3, $t2, 8
/* 10E910 7F0D9DE0 01CF4821 */  addu  $t1, $t6, $t7
/* 10E914 7F0D9DE4 A12B0001 */  sb    $t3, 1($t1)
/* 10E918 7F0D9DE8 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 10E91C 7F0D9DEC 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 10E920 7F0D9DF0 97A80292 */  lhu   $t0, 0x292($sp)
/* 10E924 7F0D9DF4 24180001 */  li    $t8, 1
/* 10E928 7F0D9DF8 01886821 */  addu  $t5, $t4, $t0
/* 10E92C 7F0D9DFC 10000016 */  b     .L7F0D9E58
/* 10E930 7F0D9E00 A1B8A801 */   sb    $t8, -0x57ff($t5)
.L7F0D9E04:
/* 10E934 7F0D9E04 272A0001 */  addiu $t2, $t9, 1
/* 10E938 7F0D9E08 29414000 */  slti  $at, $t2, 0x4000
/* 10E93C 7F0D9E0C 14200012 */  bnez  $at, .L7F0D9E58
/* 10E940 7F0D9E10 97AE0298 */   lhu   $t6, 0x298($sp)
/* 10E944 7F0D9E14 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10E948 7F0D9E18 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10E94C 7F0D9E1C 25CF0002 */  addiu $t7, $t6, 2
/* 10E950 7F0D9E20 000F5A03 */  sra   $t3, $t7, 8
/* 10E954 7F0D9E24 01396021 */  addu  $t4, $t1, $t9
/* 10E958 7F0D9E28 A18B0001 */  sb    $t3, 1($t4)
/* 10E95C 7F0D9E2C 97B80292 */  lhu   $t8, 0x292($sp)
/* 10E960 7F0D9E30 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 10E964 7F0D9E34 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 10E968 7F0D9E38 270D0001 */  addiu $t5, $t8, 1
/* 10E96C 7F0D9E3C 31AA1800 */  andi  $t2, $t5, 0x1800
/* 10E970 7F0D9E40 000A70C3 */  sra   $t6, $t2, 3
/* 10E974 7F0D9E44 31AF00FF */  andi  $t7, $t5, 0xff
/* 10E978 7F0D9E48 01CF4825 */  or    $t1, $t6, $t7
/* 10E97C 7F0D9E4C 24080001 */  li    $t0, 1
/* 10E980 7F0D9E50 03295821 */  addu  $t3, $t9, $t1
/* 10E984 7F0D9E54 A1680000 */  sb    $t0, ($t3)
.L7F0D9E58:
/* 10E988 7F0D9E58 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 10E98C 7F0D9E5C 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10E990 7F0D9E60 97AC0298 */  lhu   $t4, 0x298($sp)
/* 10E994 7F0D9E64 030C7021 */  addu  $t6, $t8, $t4
/* 10E998 7F0D9E68 91CF0001 */  lbu   $t7, 1($t6)
/* 10E99C 7F0D9E6C 01985021 */  addu  $t2, $t4, $t8
/* 10E9A0 7F0D9E70 914D0000 */  lbu   $t5, ($t2)
/* 10E9A4 7F0D9E74 000FCA00 */  sll   $t9, $t7, 8
/* 10E9A8 7F0D9E78 01B94825 */  or    $t1, $t5, $t9
/* 10E9AC 7F0D9E7C 1000225F */  b     .L7F0E27FC
/* 10E9B0 7F0D9E80 A7A90298 */   sh    $t1, 0x298($sp)
.L7F0D9E84:
/* 10E9B4 7F0D9E84 97A80298 */  lhu   $t0, 0x298($sp)
/* 10E9B8 7F0D9E88 250B0002 */  addiu $t3, $t0, 2
/* 10E9BC 7F0D9E8C 1000225B */  b     .L7F0E27FC
/* 10E9C0 7F0D9E90 A7AB0298 */   sh    $t3, 0x298($sp)
spectrum_op_C5:
/* 10E9C4 7F0D9E94 97AC0292 */  lhu   $t4, 0x292($sp)
/* 10E9C8 7F0D9E98 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10E9CC 7F0D9E9C 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 10E9D0 7F0D9EA0 258EFFFE */  addiu $t6, $t4, -2
/* 10E9D4 7F0D9EA4 31CFFFFF */  andi  $t7, $t6, 0xffff
/* 10E9D8 7F0D9EA8 29E15B00 */  slti  $at, $t7, 0x5b00
/* 10E9DC 7F0D9EAC 2558000B */  addiu $t8, $t2, 0xb
/* 10E9E0 7F0D9EB0 AFB8028C */  sw    $t8, 0x28c($sp)
/* 10E9E4 7F0D9EB4 14200005 */  bnez  $at, .L7F0D9ECC
/* 10E9E8 7F0D9EB8 A7AE0292 */   sh    $t6, 0x292($sp)
/* 10E9EC 7F0D9EBC 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10E9F0 7F0D9EC0 01AFC821 */  addu  $t9, $t5, $t7
/* 10E9F4 7F0D9EC4 10000021 */  b     .L7F0D9F4C
/* 10E9F8 7F0D9EC8 A3330000 */   sb    $s3, ($t9)
.L7F0D9ECC:
/* 10E9FC 7F0D9ECC 97A90292 */  lhu   $t1, 0x292($sp)
/* 10EA00 7F0D9ED0 97AD0292 */  lhu   $t5, 0x292($sp)
/* 10EA04 7F0D9ED4 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10EA08 7F0D9ED8 29215800 */  slti  $at, $t1, 0x5800
/* 10EA0C 7F0D9EDC 5420000C */  bnezl $at, .L7F0D9F10
/* 10EA10 7F0D9EE0 29A14000 */   slti  $at, $t5, 0x4000
/* 10EA14 7F0D9EE4 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10EA18 7F0D9EE8 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 10EA1C 7F0D9EEC 240A0001 */  li    $t2, 1
/* 10EA20 7F0D9EF0 01095821 */  addu  $t3, $t0, $t1
/* 10EA24 7F0D9EF4 A1730000 */  sb    $s3, ($t3)
/* 10EA28 7F0D9EF8 97AC0292 */  lhu   $t4, 0x292($sp)
/* 10EA2C 7F0D9EFC 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 10EA30 7F0D9F00 030C7021 */  addu  $t6, $t8, $t4
/* 10EA34 7F0D9F04 10000011 */  b     .L7F0D9F4C
/* 10EA38 7F0D9F08 A1CAA800 */   sb    $t2, -0x5800($t6)
/* 10EA3C 7F0D9F0C 29A14000 */  slti  $at, $t5, 0x4000
.L7F0D9F10:
/* 10EA40 7F0D9F10 1420000E */  bnez  $at, .L7F0D9F4C
/* 10EA44 7F0D9F14 3C0F8009 */   lui   $t7, %hi(ptr_spectrum_roms) 
/* 10EA48 7F0D9F18 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10EA4C 7F0D9F1C 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 10EA50 7F0D9F20 24080001 */  li    $t0, 1
/* 10EA54 7F0D9F24 01EDC821 */  addu  $t9, $t7, $t5
/* 10EA58 7F0D9F28 A3330000 */  sb    $s3, ($t9)
/* 10EA5C 7F0D9F2C 97A90292 */  lhu   $t1, 0x292($sp)
/* 10EA60 7F0D9F30 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 10EA64 7F0D9F34 312B1800 */  andi  $t3, $t1, 0x1800
/* 10EA68 7F0D9F38 000BC0C3 */  sra   $t8, $t3, 3
/* 10EA6C 7F0D9F3C 312C00FF */  andi  $t4, $t1, 0xff
/* 10EA70 7F0D9F40 030C5025 */  or    $t2, $t8, $t4
/* 10EA74 7F0D9F44 01CA7821 */  addu  $t7, $t6, $t2
/* 10EA78 7F0D9F48 A1E80000 */  sb    $t0, ($t7)
.L7F0D9F4C:
/* 10EA7C 7F0D9F4C 97AD0292 */  lhu   $t5, 0x292($sp)
/* 10EA80 7F0D9F50 97B80292 */  lhu   $t8, 0x292($sp)
/* 10EA84 7F0D9F54 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 10EA88 7F0D9F58 25B90001 */  addiu $t9, $t5, 1
/* 10EA8C 7F0D9F5C 2B215B00 */  slti  $at, $t9, 0x5b00
/* 10EA90 7F0D9F60 14200005 */  bnez  $at, .L7F0D9F78
/* 10EA94 7F0D9F64 270C0001 */   addiu $t4, $t8, 1
/* 10EA98 7F0D9F68 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10EA9C 7F0D9F6C 016D4821 */  addu  $t1, $t3, $t5
/* 10EAA0 7F0D9F70 10002222 */  b     .L7F0E27FC
/* 10EAA4 7F0D9F74 A1320001 */   sb    $s2, 1($t1)
.L7F0D9F78:
/* 10EAA8 7F0D9F78 29815800 */  slti  $at, $t4, 0x5800
/* 10EAAC 7F0D9F7C 1420000C */  bnez  $at, .L7F0D9FB0
/* 10EAB0 7F0D9F80 97AD0292 */   lhu   $t5, 0x292($sp)
/* 10EAB4 7F0D9F84 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10EAB8 7F0D9F88 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10EABC 7F0D9F8C 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 10EAC0 7F0D9F90 24080001 */  li    $t0, 1
/* 10EAC4 7F0D9F94 01D85021 */  addu  $t2, $t6, $t8
/* 10EAC8 7F0D9F98 A1520001 */  sb    $s2, 1($t2)
/* 10EACC 7F0D9F9C 97B90292 */  lhu   $t9, 0x292($sp)
/* 10EAD0 7F0D9FA0 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 10EAD4 7F0D9FA4 01F95821 */  addu  $t3, $t7, $t9
/* 10EAD8 7F0D9FA8 10002214 */  b     .L7F0E27FC
/* 10EADC 7F0D9FAC A168A801 */   sb    $t0, -0x57ff($t3)
.L7F0D9FB0:
/* 10EAE0 7F0D9FB0 25A90001 */  addiu $t1, $t5, 1
/* 10EAE4 7F0D9FB4 29214000 */  slti  $at, $t1, 0x4000
/* 10EAE8 7F0D9FB8 14202210 */  bnez  $at, .L7F0E27FC
/* 10EAEC 7F0D9FBC 3C0C8009 */   lui   $t4, %hi(ptr_spectrum_roms) 
/* 10EAF0 7F0D9FC0 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 10EAF4 7F0D9FC4 24180001 */  li    $t8, 1
/* 10EAF8 7F0D9FC8 018D7021 */  addu  $t6, $t4, $t5
/* 10EAFC 7F0D9FCC A1D20001 */  sb    $s2, 1($t6)
/* 10EB00 7F0D9FD0 97AA0292 */  lhu   $t2, 0x292($sp)
/* 10EB04 7F0D9FD4 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 10EB08 7F0D9FD8 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 10EB0C 7F0D9FDC 254F0001 */  addiu $t7, $t2, 1
/* 10EB10 7F0D9FE0 31F91800 */  andi  $t9, $t7, 0x1800
/* 10EB14 7F0D9FE4 001940C3 */  sra   $t0, $t9, 3
/* 10EB18 7F0D9FE8 31EB00FF */  andi  $t3, $t7, 0xff
/* 10EB1C 7F0D9FEC 010B4825 */  or    $t1, $t0, $t3
/* 10EB20 7F0D9FF0 01896821 */  addu  $t5, $t4, $t1
/* 10EB24 7F0D9FF4 10002201 */  b     .L7F0E27FC
/* 10EB28 7F0D9FF8 A1B80000 */   sb    $t8, ($t5)
spectrum_op_C6:
/* 10EB2C 7F0D9FFC 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10EB30 7F0DA000 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 10EB34 7F0DA004 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 10EB38 7F0DA008 97B90298 */  lhu   $t9, 0x298($sp)
/* 10EB3C 7F0DA00C 25CA0007 */  addiu $t2, $t6, 7
/* 10EB40 7F0DA010 AFAA028C */  sw    $t2, 0x28c($sp)
/* 10EB44 7F0DA014 032F4021 */  addu  $t0, $t9, $t7
/* 10EB48 7F0DA018 910B0000 */  lbu   $t3, ($t0)
/* 10EB4C 7F0DA01C 3219000F */  andi  $t9, $s0, 0xf
/* 10EB50 7F0DA020 2401000F */  li    $at, 15
/* 10EB54 7F0DA024 020B4821 */  addu  $t1, $s0, $t3
/* 10EB58 7F0DA028 316A000F */  andi  $t2, $t3, 0xf
/* 10EB5C 7F0DA02C 032A7821 */  addu  $t7, $t9, $t2
/* 10EB60 7F0DA030 313800A8 */  andi  $t8, $t1, 0xa8
/* 10EB64 7F0DA034 00096A03 */  sra   $t5, $t1, 8
/* 10EB68 7F0DA038 030D7025 */  or    $t6, $t8, $t5
/* 10EB6C 7F0DA03C 02006827 */  not   $t5, $s0
/* 10EB70 7F0DA040 002F402A */  slt   $t0, $at, $t7
/* 10EB74 7F0DA044 01307826 */  xor   $t7, $t1, $s0
/* 10EB78 7F0DA048 A7A90140 */  sh    $t1, 0x140($sp)
/* 10EB7C 7F0DA04C 01ABC826 */  xor   $t9, $t5, $t3
/* 10EB80 7F0DA050 93B00141 */  lbu   $s0, 0x141($sp)
/* 10EB84 7F0DA054 332A0080 */  andi  $t2, $t9, 0x80
/* 10EB88 7F0DA058 00086100 */  sll   $t4, $t0, 4
/* 10EB8C 7F0DA05C 014F4024 */  and   $t0, $t2, $t7
/* 10EB90 7F0DA060 01CCC025 */  or    $t8, $t6, $t4
/* 10EB94 7F0DA064 97AA0298 */  lhu   $t2, 0x298($sp)
/* 10EB98 7F0DA068 00087143 */  sra   $t6, $t0, 5
/* 10EB9C 7F0DA06C 2E0D0001 */  sltiu $t5, $s0, 1
/* 10EBA0 7F0DA070 000DC980 */  sll   $t9, $t5, 6
/* 10EBA4 7F0DA074 030E6025 */  or    $t4, $t8, $t6
/* 10EBA8 7F0DA078 01998825 */  or    $s1, $t4, $t9
/* 10EBAC 7F0DA07C 322900FF */  andi  $t1, $s1, 0xff
/* 10EBB0 7F0DA080 254F0001 */  addiu $t7, $t2, 1
/* 10EBB4 7F0DA084 01208825 */  move  $s1, $t1
/* 10EBB8 7F0DA088 AFAD0048 */  sw    $t5, 0x48($sp)
/* 10EBBC 7F0DA08C A7AF0298 */  sh    $t7, 0x298($sp)
/* 10EBC0 7F0DA090 100021DA */  b     .L7F0E27FC
/* 10EBC4 7F0DA094 A3AB013F */   sb    $t3, 0x13f($sp)
spectrum_op_C7:
/* 10EBC8 7F0DA098 97AE0292 */  lhu   $t6, 0x292($sp)
/* 10EBCC 7F0DA09C 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10EBD0 7F0DA0A0 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10EBD4 7F0DA0A4 25CCFFFE */  addiu $t4, $t6, -2
/* 10EBD8 7F0DA0A8 318DFFFF */  andi  $t5, $t4, 0xffff
/* 10EBDC 7F0DA0AC 29A15B00 */  slti  $at, $t5, 0x5b00
/* 10EBE0 7F0DA0B0 2518000B */  addiu $t8, $t0, 0xb
/* 10EBE4 7F0DA0B4 AFB8028C */  sw    $t8, 0x28c($sp)
/* 10EBE8 7F0DA0B8 14200006 */  bnez  $at, .L7F0DA0D4
/* 10EBEC 7F0DA0BC A7AC0292 */   sh    $t4, 0x292($sp)
/* 10EBF0 7F0DA0C0 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10EBF4 7F0DA0C4 97AB0298 */  lhu   $t3, 0x298($sp)
/* 10EBF8 7F0DA0C8 032D4821 */  addu  $t1, $t9, $t5
/* 10EBFC 7F0DA0CC 10000023 */  b     .L7F0DA15C
/* 10EC00 7F0DA0D0 A12B0000 */   sb    $t3, ($t1)
.L7F0DA0D4:
/* 10EC04 7F0DA0D4 97AA0292 */  lhu   $t2, 0x292($sp)
/* 10EC08 7F0DA0D8 97AB0292 */  lhu   $t3, 0x292($sp)
/* 10EC0C 7F0DA0DC 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10EC10 7F0DA0E0 29415800 */  slti  $at, $t2, 0x5800
/* 10EC14 7F0DA0E4 5420000D */  bnezl $at, .L7F0DA11C
/* 10EC18 7F0DA0E8 29614000 */   slti  $at, $t3, 0x4000
/* 10EC1C 7F0DA0EC 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10EC20 7F0DA0F0 97AF0298 */  lhu   $t7, 0x298($sp)
/* 10EC24 7F0DA0F4 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 10EC28 7F0DA0F8 010AC021 */  addu  $t8, $t0, $t2
/* 10EC2C 7F0DA0FC A30F0000 */  sb    $t7, ($t8)
/* 10EC30 7F0DA100 97B90292 */  lhu   $t9, 0x292($sp)
/* 10EC34 7F0DA104 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 10EC38 7F0DA108 240E0001 */  li    $t6, 1
/* 10EC3C 7F0DA10C 01996821 */  addu  $t5, $t4, $t9
/* 10EC40 7F0DA110 10000012 */  b     .L7F0DA15C
/* 10EC44 7F0DA114 A1AEA800 */   sb    $t6, -0x5800($t5)
/* 10EC48 7F0DA118 29614000 */  slti  $at, $t3, 0x4000
.L7F0DA11C:
/* 10EC4C 7F0DA11C 1420000F */  bnez  $at, .L7F0DA15C
/* 10EC50 7F0DA120 3C088009 */   lui   $t0, %hi(ptr_spectrum_roms) 
/* 10EC54 7F0DA124 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10EC58 7F0DA128 97A90298 */  lhu   $t1, 0x298($sp)
/* 10EC5C 7F0DA12C 240F0001 */  li    $t7, 1
/* 10EC60 7F0DA130 010B5021 */  addu  $t2, $t0, $t3
/* 10EC64 7F0DA134 A1490000 */  sb    $t1, ($t2)
/* 10EC68 7F0DA138 97B80292 */  lhu   $t8, 0x292($sp)
/* 10EC6C 7F0DA13C 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 10EC70 7F0DA140 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 10EC74 7F0DA144 330C1800 */  andi  $t4, $t8, 0x1800
/* 10EC78 7F0DA148 000CC8C3 */  sra   $t9, $t4, 3
/* 10EC7C 7F0DA14C 330E00FF */  andi  $t6, $t8, 0xff
/* 10EC80 7F0DA150 032E6825 */  or    $t5, $t9, $t6
/* 10EC84 7F0DA154 010D5821 */  addu  $t3, $t0, $t5
/* 10EC88 7F0DA158 A16F0000 */  sb    $t7, ($t3)
.L7F0DA15C:
/* 10EC8C 7F0DA15C 97A90292 */  lhu   $t1, 0x292($sp)
/* 10EC90 7F0DA160 97A80292 */  lhu   $t0, 0x292($sp)
/* 10EC94 7F0DA164 97AC0298 */  lhu   $t4, 0x298($sp)
/* 10EC98 7F0DA168 252A0001 */  addiu $t2, $t1, 1
/* 10EC9C 7F0DA16C 29415B00 */  slti  $at, $t2, 0x5b00
/* 10ECA0 7F0DA170 14200007 */  bnez  $at, .L7F0DA190
/* 10ECA4 7F0DA174 250D0001 */   addiu $t5, $t0, 1
/* 10ECA8 7F0DA178 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10ECAC 7F0DA17C 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10ECB0 7F0DA180 000CC203 */  sra   $t8, $t4, 8
/* 10ECB4 7F0DA184 03297021 */  addu  $t6, $t9, $t1
/* 10ECB8 7F0DA188 10000025 */  b     .L7F0DA220
/* 10ECBC 7F0DA18C A1D80001 */   sb    $t8, 1($t6)
.L7F0DA190:
/* 10ECC0 7F0DA190 29A15800 */  slti  $at, $t5, 0x5800
/* 10ECC4 7F0DA194 1420000E */  bnez  $at, .L7F0DA1D0
/* 10ECC8 7F0DA198 97AD0292 */   lhu   $t5, 0x292($sp)
/* 10ECCC 7F0DA19C 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 10ECD0 7F0DA1A0 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 10ECD4 7F0DA1A4 97AF0298 */  lhu   $t7, 0x298($sp)
/* 10ECD8 7F0DA1A8 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 10ECDC 7F0DA1AC 01486021 */  addu  $t4, $t2, $t0
/* 10ECE0 7F0DA1B0 000F5A03 */  sra   $t3, $t7, 8
/* 10ECE4 7F0DA1B4 A18B0001 */  sb    $t3, 1($t4)
/* 10ECE8 7F0DA1B8 97B80292 */  lhu   $t8, 0x292($sp)
/* 10ECEC 7F0DA1BC 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 10ECF0 7F0DA1C0 24190001 */  li    $t9, 1
/* 10ECF4 7F0DA1C4 01387021 */  addu  $t6, $t1, $t8
/* 10ECF8 7F0DA1C8 10000015 */  b     .L7F0DA220
/* 10ECFC 7F0DA1CC A1D9A801 */   sb    $t9, -0x57ff($t6)
.L7F0DA1D0:
/* 10ED00 7F0DA1D0 25AF0001 */  addiu $t7, $t5, 1
/* 10ED04 7F0DA1D4 29E14000 */  slti  $at, $t7, 0x4000
/* 10ED08 7F0DA1D8 14200011 */  bnez  $at, .L7F0DA220
/* 10ED0C 7F0DA1DC 97AA0298 */   lhu   $t2, 0x298($sp)
/* 10ED10 7F0DA1E0 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 10ED14 7F0DA1E4 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10ED18 7F0DA1E8 000A4203 */  sra   $t0, $t2, 8
/* 10ED1C 7F0DA1EC 24090001 */  li    $t1, 1
/* 10ED20 7F0DA1F0 016D6021 */  addu  $t4, $t3, $t5
/* 10ED24 7F0DA1F4 A1880001 */  sb    $t0, 1($t4)
/* 10ED28 7F0DA1F8 97B80292 */  lhu   $t8, 0x292($sp)
/* 10ED2C 7F0DA1FC 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 10ED30 7F0DA200 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 10ED34 7F0DA204 27190001 */  addiu $t9, $t8, 1
/* 10ED38 7F0DA208 332E1800 */  andi  $t6, $t9, 0x1800
/* 10ED3C 7F0DA20C 000E78C3 */  sra   $t7, $t6, 3
/* 10ED40 7F0DA210 332A00FF */  andi  $t2, $t9, 0xff
/* 10ED44 7F0DA214 01EA5825 */  or    $t3, $t7, $t2
/* 10ED48 7F0DA218 01AB4021 */  addu  $t0, $t5, $t3
/* 10ED4C 7F0DA21C A1090000 */  sb    $t1, ($t0)
.L7F0DA220:
/* 10ED50 7F0DA220 10002176 */  b     .L7F0E27FC
/* 10ED54 7F0DA224 A7A00298 */   sh    $zero, 0x298($sp)
spectrum_op_C8:
/* 10ED58 7F0DA228 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10ED5C 7F0DA22C 322E0040 */  andi  $t6, $s1, 0x40
/* 10ED60 7F0DA230 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 10ED64 7F0DA234 25980005 */  addiu $t8, $t4, 5
/* 10ED68 7F0DA238 11C02170 */  beqz  $t6, .L7F0E27FC
/* 10ED6C 7F0DA23C AFB8028C */   sw    $t8, 0x28c($sp)
/* 10ED70 7F0DA240 97AA0292 */  lhu   $t2, 0x292($sp)
/* 10ED74 7F0DA244 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10ED78 7F0DA248 270F0006 */  addiu $t7, $t8, 6
/* 10ED7C 7F0DA24C AFAF028C */  sw    $t7, 0x28c($sp)
/* 10ED80 7F0DA250 01AA4021 */  addu  $t0, $t5, $t2
/* 10ED84 7F0DA254 910C0001 */  lbu   $t4, 1($t0)
/* 10ED88 7F0DA258 014D5821 */  addu  $t3, $t2, $t5
/* 10ED8C 7F0DA25C 91690000 */  lbu   $t1, ($t3)
/* 10ED90 7F0DA260 000CC200 */  sll   $t8, $t4, 8
/* 10ED94 7F0DA264 25590002 */  addiu $t9, $t2, 2
/* 10ED98 7F0DA268 01387025 */  or    $t6, $t1, $t8
/* 10ED9C 7F0DA26C A7AE0298 */  sh    $t6, 0x298($sp)
/* 10EDA0 7F0DA270 10002162 */  b     .L7F0E27FC
/* 10EDA4 7F0DA274 A7B90292 */   sh    $t9, 0x292($sp)
spectrum_op_C9:
/* 10EDA8 7F0DA278 8FAF028C */  lw    $t7, 0x28c($sp)
/* 10EDAC 7F0DA27C 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10EDB0 7F0DA280 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10EDB4 7F0DA284 97AC0292 */  lhu   $t4, 0x292($sp)
/* 10EDB8 7F0DA288 25EB0004 */  addiu $t3, $t7, 4
/* 10EDBC 7F0DA28C AFAB028C */  sw    $t3, 0x28c($sp)
/* 10EDC0 7F0DA290 25680006 */  addiu $t0, $t3, 6
/* 10EDC4 7F0DA294 AFA8028C */  sw    $t0, 0x28c($sp)
/* 10EDC8 7F0DA298 012C5021 */  addu  $t2, $t1, $t4
/* 10EDCC 7F0DA29C 91590001 */  lbu   $t9, 1($t2)
/* 10EDD0 7F0DA2A0 0189C021 */  addu  $t8, $t4, $t1
/* 10EDD4 7F0DA2A4 930E0000 */  lbu   $t6, ($t8)
/* 10EDD8 7F0DA2A8 00197A00 */  sll   $t7, $t9, 8
/* 10EDDC 7F0DA2AC 258D0002 */  addiu $t5, $t4, 2
/* 10EDE0 7F0DA2B0 01CF5825 */  or    $t3, $t6, $t7
/* 10EDE4 7F0DA2B4 A7AB0298 */  sh    $t3, 0x298($sp)
/* 10EDE8 7F0DA2B8 10002150 */  b     .L7F0E27FC
/* 10EDEC 7F0DA2BC A7AD0292 */   sh    $t5, 0x292($sp)
spectrum_op_CA:
/* 10EDF0 7F0DA2C0 8FA8028C */  lw    $t0, 0x28c($sp)
/* 10EDF4 7F0DA2C4 32290040 */  andi  $t1, $s1, 0x40
/* 10EDF8 7F0DA2C8 97AA0298 */  lhu   $t2, 0x298($sp)
/* 10EDFC 7F0DA2CC 2518000A */  addiu $t8, $t0, 0xa
/* 10EE00 7F0DA2D0 1120000B */  beqz  $t1, .L7F0DA300
/* 10EE04 7F0DA2D4 AFB8028C */   sw    $t8, 0x28c($sp)
/* 10EE08 7F0DA2D8 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10EE0C 7F0DA2DC 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10EE10 7F0DA2E0 032A5821 */  addu  $t3, $t9, $t2
/* 10EE14 7F0DA2E4 916C0001 */  lbu   $t4, 1($t3)
/* 10EE18 7F0DA2E8 01597021 */  addu  $t6, $t2, $t9
/* 10EE1C 7F0DA2EC 91CF0000 */  lbu   $t7, ($t6)
/* 10EE20 7F0DA2F0 000C6A00 */  sll   $t5, $t4, 8
/* 10EE24 7F0DA2F4 01ED4025 */  or    $t0, $t7, $t5
/* 10EE28 7F0DA2F8 10002140 */  b     .L7F0E27FC
/* 10EE2C 7F0DA2FC A7A80298 */   sh    $t0, 0x298($sp)
.L7F0DA300:
/* 10EE30 7F0DA300 97B80298 */  lhu   $t8, 0x298($sp)
/* 10EE34 7F0DA304 27090002 */  addiu $t1, $t8, 2
/* 10EE38 7F0DA308 1000213C */  b     .L7F0E27FC
/* 10EE3C 7F0DA30C A7A90298 */   sh    $t1, 0x298($sp)
spectrum_op_CB:
/* 10EE40 7F0DA310 8FAE028C */  lw    $t6, 0x28c($sp)
/* 10EE44 7F0DA314 93AA0287 */  lbu   $t2, 0x287($sp)
/* 10EE48 7F0DA318 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms)
/* 10EE4C 7F0DA31C 25D90004 */  addiu $t9, $t6, 4
/* 10EE50 7F0DA320 1140001F */  beqz  $t2, .L7F0DA3A0
/* 10EE54 7F0DA324 AFB9028C */   sw    $t9, 0x28c($sp)
/* 10EE58 7F0DA328 24010001 */  li    $at, 1
/* 10EE5C 7F0DA32C 15410004 */  bne   $t2, $at, .L7F0DA340
/* 10EE60 7F0DA330 3C0D8009 */   lui   $t5, %hi(ptr_spectrum_roms) 
/* 10EE64 7F0DA334 97AB0296 */  lhu   $t3, 0x296($sp)
/* 10EE68 7F0DA338 10000003 */  b     .L7F0DA348
/* 10EE6C 7F0DA33C AFAB0048 */   sw    $t3, 0x48($sp)
.L7F0DA340:
/* 10EE70 7F0DA340 97AC0294 */  lhu   $t4, 0x294($sp)
/* 10EE74 7F0DA344 AFAC0048 */  sw    $t4, 0x48($sp)
.L7F0DA348:
/* 10EE78 7F0DA348 97AF0298 */  lhu   $t7, 0x298($sp)
/* 10EE7C 7F0DA34C 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10EE80 7F0DA350 8FA90048 */  lw    $t1, 0x48($sp)
/* 10EE84 7F0DA354 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10EE88 7F0DA358 01ED4021 */  addu  $t0, $t7, $t5
/* 10EE8C 7F0DA35C 81180000 */  lb    $t8, ($t0)
/* 10EE90 7F0DA360 25F90001 */  addiu $t9, $t7, 1
/* 10EE94 7F0DA364 332CFFFF */  andi  $t4, $t9, 0xffff
/* 10EE98 7F0DA368 254B0008 */  addiu $t3, $t2, 8
/* 10EE9C 7F0DA36C 03097021 */  addu  $t6, $t8, $t1
/* 10EEA0 7F0DA370 A7AE013C */  sh    $t6, 0x13c($sp)
/* 10EEA4 7F0DA374 A7B90298 */  sh    $t9, 0x298($sp)
/* 10EEA8 7F0DA378 AFAB028C */  sw    $t3, 0x28c($sp)
/* 10EEAC 7F0DA37C 018D4021 */  addu  $t0, $t4, $t5
/* 10EEB0 7F0DA380 91180000 */  lbu   $t8, ($t0)
/* 10EEB4 7F0DA384 330E00F8 */  andi  $t6, $t8, 0xf8
/* 10EEB8 7F0DA388 35CF0006 */  ori   $t7, $t6, 6
/* 10EEBC 7F0DA38C A3B8013B */  sb    $t8, 0x13b($sp)
/* 10EEC0 7F0DA390 33090007 */  andi  $t1, $t8, 7
/* 10EEC4 7F0DA394 A3A9013A */  sb    $t1, 0x13a($sp)
/* 10EEC8 7F0DA398 1000000F */  b     .L7F0DA3D8
/* 10EECC 7F0DA39C A3AF013B */   sb    $t7, 0x13b($sp)
.L7F0DA3A0:
/* 10EED0 7F0DA3A0 97AA0298 */  lhu   $t2, 0x298($sp)
/* 10EED4 7F0DA3A4 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10EED8 7F0DA3A8 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10EEDC 7F0DA3AC 8FA90288 */  lw    $t1, 0x288($sp)
/* 10EEE0 7F0DA3B0 014BC821 */  addu  $t9, $t2, $t3
/* 10EEE4 7F0DA3B4 932C0000 */  lbu   $t4, ($t9)
/* 10EEE8 7F0DA3B8 00167200 */  sll   $t6, $s6, 8
/* 10EEEC 7F0DA3BC 01D77825 */  or    $t7, $t6, $s7
/* 10EEF0 7F0DA3C0 25A80004 */  addiu $t0, $t5, 4
/* 10EEF4 7F0DA3C4 25380001 */  addiu $t8, $t1, 1
/* 10EEF8 7F0DA3C8 AFA8028C */  sw    $t0, 0x28c($sp)
/* 10EEFC 7F0DA3CC AFB80288 */  sw    $t8, 0x288($sp)
/* 10EF00 7F0DA3D0 A7AF013C */  sh    $t7, 0x13c($sp)
/* 10EF04 7F0DA3D4 A3AC013B */  sb    $t4, 0x13b($sp)
.L7F0DA3D8:
/* 10EF08 7F0DA3D8 97AA0298 */  lhu   $t2, 0x298($sp)
/* 10EF0C 7F0DA3DC 93B9013B */  lbu   $t9, 0x13b($sp)
/* 10EF10 7F0DA3E0 93AF013B */  lbu   $t7, 0x13b($sp)
/* 10EF14 7F0DA3E4 254B0001 */  addiu $t3, $t2, 1
/* 10EF18 7F0DA3E8 2B210040 */  slti  $at, $t9, 0x40
spectrum_op_CB_40_FF:
/* 10EF1C 7F0DA3EC 102006A4 */  beqz  $at, .L7F0DBE80
/* 10EF20 7F0DA3F0 A7AB0298 */   sh    $t3, 0x298($sp)
/* 10EF24 7F0DA3F4 2F210040 */  sltiu $at, $t9, 0x40
def_7F0DBF10:
/* 10EF28 7F0DA3F8 10200867 */  beqz  $at, .L7F0DC598
/* 10EF2C 7F0DA3FC 0019C880 */   sll   $t9, $t9, 2
/* 10EF30 7F0DA400 3C018006 */  lui   $at, %hi(jpt_8005C52C)
/* 10EF34 7F0DA404 00390821 */  addu  $at, $at, $t9
/* 10EF38 7F0DA408 8C39C52C */  lw    $t9, %lo(jpt_8005C52C)($at)
/* 10EF3C 7F0DA40C 03200008 */  jr    $t9
/* 10EF40 7F0DA410 00000000 */   nop   
spectrum_op_CB_00:
/* 10EF44 7F0DA414 00126040 */  sll   $t4, $s2, 1
/* 10EF48 7F0DA418 001269C3 */  sra   $t5, $s2, 7
/* 10EF4C 7F0DA41C 018D9025 */  or    $s2, $t4, $t5
/* 10EF50 7F0DA420 324800FF */  andi  $t0, $s2, 0xff
/* 10EF54 7F0DA424 3C0C8009 */  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
/* 10EF58 7F0DA428 8D8CE334 */  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
/* 10EF5C 7F0DA42C 2D090001 */  sltiu $t1, $t0, 1
/* 10EF60 7F0DA430 AFA90048 */  sw    $t1, 0x48($sp)
/* 10EF64 7F0DA434 01009025 */  move  $s2, $t0
/* 10EF68 7F0DA438 31180001 */  andi  $t8, $t0, 1
/* 10EF6C 7F0DA43C 310E00A8 */  andi  $t6, $t0, 0xa8
/* 10EF70 7F0DA440 010C6821 */  addu  $t5, $t0, $t4
/* 10EF74 7F0DA444 91A80000 */  lbu   $t0, ($t5)
/* 10EF78 7F0DA448 030E7825 */  or    $t7, $t8, $t6
/* 10EF7C 7F0DA44C 00095980 */  sll   $t3, $t1, 6
/* 10EF80 7F0DA450 01EBC825 */  or    $t9, $t7, $t3
/* 10EF84 7F0DA454 01198825 */  or    $s1, $t0, $t9
/* 10EF88 7F0DA458 322900FF */  andi  $t1, $s1, 0xff
/* 10EF8C 7F0DA45C 1000084E */  b     .L7F0DC598
/* 10EF90 7F0DA460 01208825 */   move  $s1, $t1
spectrum_op_CB_01:
/* 10EF94 7F0DA464 0013C040 */  sll   $t8, $s3, 1
/* 10EF98 7F0DA468 001371C3 */  sra   $t6, $s3, 7
/* 10EF9C 7F0DA46C 030E9825 */  or    $s3, $t8, $t6
/* 10EFA0 7F0DA470 326A00FF */  andi  $t2, $s3, 0xff
/* 10EFA4 7F0DA474 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 10EFA8 7F0DA478 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 10EFAC 7F0DA47C 2D4F0001 */  sltiu $t7, $t2, 1
/* 10EFB0 7F0DA480 AFAF0048 */  sw    $t7, 0x48($sp)
/* 10EFB4 7F0DA484 01409825 */  move  $s3, $t2
/* 10EFB8 7F0DA488 314B0001 */  andi  $t3, $t2, 1
/* 10EFBC 7F0DA48C 314C00A8 */  andi  $t4, $t2, 0xa8
/* 10EFC0 7F0DA490 01587021 */  addu  $t6, $t2, $t8
/* 10EFC4 7F0DA494 91CA0000 */  lbu   $t2, ($t6)
/* 10EFC8 7F0DA498 016C6825 */  or    $t5, $t3, $t4
/* 10EFCC 7F0DA49C 000FC980 */  sll   $t9, $t7, 6
/* 10EFD0 7F0DA4A0 01B94825 */  or    $t1, $t5, $t9
/* 10EFD4 7F0DA4A4 01498825 */  or    $s1, $t2, $t1
/* 10EFD8 7F0DA4A8 322F00FF */  andi  $t7, $s1, 0xff
/* 10EFDC 7F0DA4AC 1000083A */  b     .L7F0DC598
/* 10EFE0 7F0DA4B0 01E08825 */   move  $s1, $t7
spectrum_op_CB_02:
/* 10EFE4 7F0DA4B4 00145840 */  sll   $t3, $s4, 1
/* 10EFE8 7F0DA4B8 001461C3 */  sra   $t4, $s4, 7
/* 10EFEC 7F0DA4BC 016CA025 */  or    $s4, $t3, $t4
/* 10EFF0 7F0DA4C0 328800FF */  andi  $t0, $s4, 0xff
/* 10EFF4 7F0DA4C4 3C0B8009 */  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
/* 10EFF8 7F0DA4C8 8D6BE334 */  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
/* 10EFFC 7F0DA4CC 2D0D0001 */  sltiu $t5, $t0, 1
/* 10F000 7F0DA4D0 AFAD0048 */  sw    $t5, 0x48($sp)
/* 10F004 7F0DA4D4 0100A025 */  move  $s4, $t0
/* 10F008 7F0DA4D8 31190001 */  andi  $t9, $t0, 1
/* 10F00C 7F0DA4DC 311800A8 */  andi  $t8, $t0, 0xa8
/* 10F010 7F0DA4E0 010B6021 */  addu  $t4, $t0, $t3
/* 10F014 7F0DA4E4 91880000 */  lbu   $t0, ($t4)
/* 10F018 7F0DA4E8 03387025 */  or    $t6, $t9, $t8
/* 10F01C 7F0DA4EC 000D4980 */  sll   $t1, $t5, 6
/* 10F020 7F0DA4F0 01C97825 */  or    $t7, $t6, $t1
/* 10F024 7F0DA4F4 010F8825 */  or    $s1, $t0, $t7
/* 10F028 7F0DA4F8 322D00FF */  andi  $t5, $s1, 0xff
/* 10F02C 7F0DA4FC 10000826 */  b     .L7F0DC598
/* 10F030 7F0DA500 01A08825 */   move  $s1, $t5
spectrum_op_CB_03:
/* 10F034 7F0DA504 0015C840 */  sll   $t9, $s5, 1
/* 10F038 7F0DA508 0015C1C3 */  sra   $t8, $s5, 7
/* 10F03C 7F0DA50C 0338A825 */  or    $s5, $t9, $t8
/* 10F040 7F0DA510 32AA00FF */  andi  $t2, $s5, 0xff
/* 10F044 7F0DA514 3C198009 */  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F048 7F0DA518 8F39E334 */  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
/* 10F04C 7F0DA51C 2D4E0001 */  sltiu $t6, $t2, 1
/* 10F050 7F0DA520 AFAE0048 */  sw    $t6, 0x48($sp)
/* 10F054 7F0DA524 0140A825 */  move  $s5, $t2
/* 10F058 7F0DA528 31490001 */  andi  $t1, $t2, 1
/* 10F05C 7F0DA52C 314B00A8 */  andi  $t3, $t2, 0xa8
/* 10F060 7F0DA530 0159C021 */  addu  $t8, $t2, $t9
/* 10F064 7F0DA534 930A0000 */  lbu   $t2, ($t8)
/* 10F068 7F0DA538 012B6025 */  or    $t4, $t1, $t3
/* 10F06C 7F0DA53C 000E7980 */  sll   $t7, $t6, 6
/* 10F070 7F0DA540 018F6825 */  or    $t5, $t4, $t7
/* 10F074 7F0DA544 014D8825 */  or    $s1, $t2, $t5
/* 10F078 7F0DA548 322E00FF */  andi  $t6, $s1, 0xff
/* 10F07C 7F0DA54C 10000812 */  b     .L7F0DC598
/* 10F080 7F0DA550 01C08825 */   move  $s1, $t6
spectrum_op_CB_04:
/* 10F084 7F0DA554 00164840 */  sll   $t1, $s6, 1
/* 10F088 7F0DA558 001659C3 */  sra   $t3, $s6, 7
/* 10F08C 7F0DA55C 012BB025 */  or    $s6, $t1, $t3
/* 10F090 7F0DA560 32C800FF */  andi  $t0, $s6, 0xff
/* 10F094 7F0DA564 3C098009 */  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F098 7F0DA568 8D29E334 */  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
/* 10F09C 7F0DA56C 2D0C0001 */  sltiu $t4, $t0, 1
/* 10F0A0 7F0DA570 AFAC0048 */  sw    $t4, 0x48($sp)
/* 10F0A4 7F0DA574 0100B025 */  move  $s6, $t0
/* 10F0A8 7F0DA578 310F0001 */  andi  $t7, $t0, 1
/* 10F0AC 7F0DA57C 311900A8 */  andi  $t9, $t0, 0xa8
/* 10F0B0 7F0DA580 01095821 */  addu  $t3, $t0, $t1
/* 10F0B4 7F0DA584 91680000 */  lbu   $t0, ($t3)
/* 10F0B8 7F0DA588 01F9C025 */  or    $t8, $t7, $t9
/* 10F0BC 7F0DA58C 000C6980 */  sll   $t5, $t4, 6
/* 10F0C0 7F0DA590 030D7025 */  or    $t6, $t8, $t5
/* 10F0C4 7F0DA594 010E8825 */  or    $s1, $t0, $t6
/* 10F0C8 7F0DA598 322C00FF */  andi  $t4, $s1, 0xff
/* 10F0CC 7F0DA59C 100007FE */  b     .L7F0DC598
/* 10F0D0 7F0DA5A0 01808825 */   move  $s1, $t4
spectrum_op_CB_05:
/* 10F0D4 7F0DA5A4 00177840 */  sll   $t7, $s7, 1
/* 10F0D8 7F0DA5A8 0017C9C3 */  sra   $t9, $s7, 7
/* 10F0DC 7F0DA5AC 01F9B825 */  or    $s7, $t7, $t9
/* 10F0E0 7F0DA5B0 32EA00FF */  andi  $t2, $s7, 0xff
/* 10F0E4 7F0DA5B4 3C0F8009 */  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F0E8 7F0DA5B8 8DEFE334 */  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
/* 10F0EC 7F0DA5BC 2D580001 */  sltiu $t8, $t2, 1
/* 10F0F0 7F0DA5C0 AFB80048 */  sw    $t8, 0x48($sp)
/* 10F0F4 7F0DA5C4 0140B825 */  move  $s7, $t2
/* 10F0F8 7F0DA5C8 314D0001 */  andi  $t5, $t2, 1
/* 10F0FC 7F0DA5CC 314900A8 */  andi  $t1, $t2, 0xa8
/* 10F100 7F0DA5D0 014FC821 */  addu  $t9, $t2, $t7
/* 10F104 7F0DA5D4 932A0000 */  lbu   $t2, ($t9)
/* 10F108 7F0DA5D8 01A95825 */  or    $t3, $t5, $t1
/* 10F10C 7F0DA5DC 00187180 */  sll   $t6, $t8, 6
/* 10F110 7F0DA5E0 016E6025 */  or    $t4, $t3, $t6
/* 10F114 7F0DA5E4 014C8825 */  or    $s1, $t2, $t4
/* 10F118 7F0DA5E8 323800FF */  andi  $t8, $s1, 0xff
/* 10F11C 7F0DA5EC 100007EA */  b     .L7F0DC598
/* 10F120 7F0DA5F0 03008825 */   move  $s1, $t8
spectrum_op_CB_06:
/* 10F124 7F0DA5F4 8FAD028C */  lw    $t5, 0x28c($sp)
/* 10F128 7F0DA5F8 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 10F12C 7F0DA5FC 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10F130 7F0DA600 97A8013C */  lhu   $t0, 0x13c($sp)
/* 10F134 7F0DA604 25A90007 */  addiu $t1, $t5, 7
/* 10F138 7F0DA608 AFA9028C */  sw    $t1, 0x28c($sp)
/* 10F13C 7F0DA60C 010B7021 */  addu  $t6, $t0, $t3
/* 10F140 7F0DA610 91CF0000 */  lbu   $t7, ($t6)
/* 10F144 7F0DA614 000FC840 */  sll   $t9, $t7, 1
/* 10F148 7F0DA618 000F51C3 */  sra   $t2, $t7, 7
/* 10F14C 7F0DA61C 032A6025 */  or    $t4, $t9, $t2
/* 10F150 7F0DA620 319800FF */  andi  $t8, $t4, 0xff
/* 10F154 7F0DA624 2F0D0001 */  sltiu $t5, $t8, 1
/* 10F158 7F0DA628 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F15C 7F0DA62C 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 10F160 7F0DA630 318900FF */  andi  $t1, $t4, 0xff
/* 10F164 7F0DA634 A3AF0139 */  sb    $t7, 0x139($sp)
/* 10F168 7F0DA638 31280001 */  andi  $t0, $t1, 1
/* 10F16C 7F0DA63C 318E00A8 */  andi  $t6, $t4, 0xa8
/* 10F170 7F0DA640 010E7825 */  or    $t7, $t0, $t6
/* 10F174 7F0DA644 A3AC0139 */  sb    $t4, 0x139($sp)
/* 10F178 7F0DA648 AFAD0048 */  sw    $t5, 0x48($sp)
/* 10F17C 7F0DA64C 01385821 */  addu  $t3, $t1, $t8
/* 10F180 7F0DA650 91680000 */  lbu   $t0, ($t3)
/* 10F184 7F0DA654 000DC980 */  sll   $t9, $t5, 6
/* 10F188 7F0DA658 97AD013C */  lhu   $t5, 0x13c($sp)
/* 10F18C 7F0DA65C 01F95025 */  or    $t2, $t7, $t9
/* 10F190 7F0DA660 010A8825 */  or    $s1, $t0, $t2
/* 10F194 7F0DA664 322E00FF */  andi  $t6, $s1, 0xff
/* 10F198 7F0DA668 29A15B00 */  slti  $at, $t5, 0x5b00
/* 10F19C 7F0DA66C 14200007 */  bnez  $at, .L7F0DA68C
/* 10F1A0 7F0DA670 01C08825 */   move  $s1, $t6
/* 10F1A4 7F0DA674 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10F1A8 7F0DA678 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10F1AC 7F0DA67C 01807825 */  move  $t7, $t4
/* 10F1B0 7F0DA680 032D6021 */  addu  $t4, $t9, $t5
/* 10F1B4 7F0DA684 100007C4 */  b     .L7F0DC598
/* 10F1B8 7F0DA688 A18F0000 */   sb    $t7, ($t4)
.L7F0DA68C:
/* 10F1BC 7F0DA68C 97A9013C */  lhu   $t1, 0x13c($sp)
/* 10F1C0 7F0DA690 97AF013C */  lhu   $t7, 0x13c($sp)
/* 10F1C4 7F0DA694 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 10F1C8 7F0DA698 29215800 */  slti  $at, $t1, 0x5800
/* 10F1CC 7F0DA69C 5420000D */  bnezl $at, .L7F0DA6D4
/* 10F1D0 7F0DA6A0 29E14000 */   slti  $at, $t7, 0x4000
/* 10F1D4 7F0DA6A4 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10F1D8 7F0DA6A8 93B80139 */  lbu   $t8, 0x139($sp)
/* 10F1DC 7F0DA6AC 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 10F1E0 7F0DA6B0 01694021 */  addu  $t0, $t3, $t1
/* 10F1E4 7F0DA6B4 A1180000 */  sb    $t8, ($t0)
/* 10F1E8 7F0DA6B8 97B9013C */  lhu   $t9, 0x13c($sp)
/* 10F1EC 7F0DA6BC 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 10F1F0 7F0DA6C0 240A0001 */  li    $t2, 1
/* 10F1F4 7F0DA6C4 01D96821 */  addu  $t5, $t6, $t9
/* 10F1F8 7F0DA6C8 100007B3 */  b     .L7F0DC598
/* 10F1FC 7F0DA6CC A1AAA800 */   sb    $t2, -0x5800($t5)
/* 10F200 7F0DA6D0 29E14000 */  slti  $at, $t7, 0x4000
.L7F0DA6D4:
/* 10F204 7F0DA6D4 142007B0 */  bnez  $at, .L7F0DC598
/* 10F208 7F0DA6D8 3C0B8009 */   lui   $t3, %hi(ptr_spectrum_roms) 
/* 10F20C 7F0DA6DC 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10F210 7F0DA6E0 93AC0139 */  lbu   $t4, 0x139($sp)
/* 10F214 7F0DA6E4 24180001 */  li    $t8, 1
/* 10F218 7F0DA6E8 016F4821 */  addu  $t1, $t3, $t7
/* 10F21C 7F0DA6EC A12C0000 */  sb    $t4, ($t1)
/* 10F220 7F0DA6F0 97A8013C */  lhu   $t0, 0x13c($sp)
/* 10F224 7F0DA6F4 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 10F228 7F0DA6F8 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 10F22C 7F0DA6FC 310E1800 */  andi  $t6, $t0, 0x1800
/* 10F230 7F0DA700 000EC8C3 */  sra   $t9, $t6, 3
/* 10F234 7F0DA704 310A00FF */  andi  $t2, $t0, 0xff
/* 10F238 7F0DA708 032A6825 */  or    $t5, $t9, $t2
/* 10F23C 7F0DA70C 016D7821 */  addu  $t7, $t3, $t5
/* 10F240 7F0DA710 100007A1 */  b     .L7F0DC598
/* 10F244 7F0DA714 A1F80000 */   sb    $t8, ($t7)
spectrum_op_CB_07:
/* 10F248 7F0DA718 00106040 */  sll   $t4, $s0, 1
/* 10F24C 7F0DA71C 001049C3 */  sra   $t1, $s0, 7
/* 10F250 7F0DA720 01898025 */  or    $s0, $t4, $t1
/* 10F254 7F0DA724 320E00FF */  andi  $t6, $s0, 0xff
/* 10F258 7F0DA728 3C0C8009 */  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F25C 7F0DA72C 8D8CE334 */  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
/* 10F260 7F0DA730 2DC80001 */  sltiu $t0, $t6, 1
/* 10F264 7F0DA734 AFA80048 */  sw    $t0, 0x48($sp)
/* 10F268 7F0DA738 01C08025 */  move  $s0, $t6
/* 10F26C 7F0DA73C 31D90001 */  andi  $t9, $t6, 1
/* 10F270 7F0DA740 31CA00A8 */  andi  $t2, $t6, 0xa8
/* 10F274 7F0DA744 01CC4821 */  addu  $t1, $t6, $t4
/* 10F278 7F0DA748 912E0000 */  lbu   $t6, ($t1)
/* 10F27C 7F0DA74C 032A5825 */  or    $t3, $t9, $t2
/* 10F280 7F0DA750 0008C180 */  sll   $t8, $t0, 6
/* 10F284 7F0DA754 01787825 */  or    $t7, $t3, $t8
/* 10F288 7F0DA758 01CF8825 */  or    $s1, $t6, $t7
/* 10F28C 7F0DA75C 322800FF */  andi  $t0, $s1, 0xff
/* 10F290 7F0DA760 1000078D */  b     .L7F0DC598
/* 10F294 7F0DA764 01008825 */   move  $s1, $t0
spectrum_op_CB_08:
/* 10F298 7F0DA768 324D0001 */  andi  $t5, $s2, 1
/* 10F29C 7F0DA76C 000D59C0 */  sll   $t3, $t5, 7
/* 10F2A0 7F0DA770 00125043 */  sra   $t2, $s2, 1
/* 10F2A4 7F0DA774 014B9025 */  or    $s2, $t2, $t3
/* 10F2A8 7F0DA778 325800FF */  andi  $t8, $s2, 0xff
/* 10F2AC 7F0DA77C 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F2B0 7F0DA780 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 10F2B4 7F0DA784 2F0C0001 */  sltiu $t4, $t8, 1
/* 10F2B8 7F0DA788 AFAC0048 */  sw    $t4, 0x48($sp)
/* 10F2BC 7F0DA78C 03009025 */  move  $s2, $t8
/* 10F2C0 7F0DA790 330900A8 */  andi  $t1, $t8, 0xa8
/* 10F2C4 7F0DA794 A3AD0138 */  sb    $t5, 0x138($sp)
/* 10F2C8 7F0DA798 030A5821 */  addu  $t3, $t8, $t2
/* 10F2CC 7F0DA79C 91780000 */  lbu   $t8, ($t3)
/* 10F2D0 7F0DA7A0 01A97025 */  or    $t6, $t5, $t1
/* 10F2D4 7F0DA7A4 000C4180 */  sll   $t0, $t4, 6
/* 10F2D8 7F0DA7A8 01C8C825 */  or    $t9, $t6, $t0
/* 10F2DC 7F0DA7AC 03198825 */  or    $s1, $t8, $t9
/* 10F2E0 7F0DA7B0 322C00FF */  andi  $t4, $s1, 0xff
/* 10F2E4 7F0DA7B4 10000778 */  b     .L7F0DC598
/* 10F2E8 7F0DA7B8 01808825 */   move  $s1, $t4
spectrum_op_CB_09:
/* 10F2EC 7F0DA7BC 326F0001 */  andi  $t7, $s3, 1
/* 10F2F0 7F0DA7C0 000F71C0 */  sll   $t6, $t7, 7
/* 10F2F4 7F0DA7C4 00134843 */  sra   $t1, $s3, 1
/* 10F2F8 7F0DA7C8 012E9825 */  or    $s3, $t1, $t6
/* 10F2FC 7F0DA7CC 326800FF */  andi  $t0, $s3, 0xff
/* 10F300 7F0DA7D0 3C098009 */  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F304 7F0DA7D4 8D29E334 */  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
/* 10F308 7F0DA7D8 2D0A0001 */  sltiu $t2, $t0, 1
/* 10F30C 7F0DA7DC AFAA0048 */  sw    $t2, 0x48($sp)
/* 10F310 7F0DA7E0 01009825 */  move  $s3, $t0
/* 10F314 7F0DA7E4 310B00A8 */  andi  $t3, $t0, 0xa8
/* 10F318 7F0DA7E8 A3AF0137 */  sb    $t7, 0x137($sp)
/* 10F31C 7F0DA7EC 01097021 */  addu  $t6, $t0, $t1
/* 10F320 7F0DA7F0 91C80000 */  lbu   $t0, ($t6)
/* 10F324 7F0DA7F4 01EBC025 */  or    $t8, $t7, $t3
/* 10F328 7F0DA7F8 000A6180 */  sll   $t4, $t2, 6
/* 10F32C 7F0DA7FC 030C6825 */  or    $t5, $t8, $t4
/* 10F330 7F0DA800 010D8825 */  or    $s1, $t0, $t5
/* 10F334 7F0DA804 322A00FF */  andi  $t2, $s1, 0xff
/* 10F338 7F0DA808 10000763 */  b     .L7F0DC598
/* 10F33C 7F0DA80C 01408825 */   move  $s1, $t2
spectrum_op_CB_0A:
/* 10F340 7F0DA810 32990001 */  andi  $t9, $s4, 1
/* 10F344 7F0DA814 0019C1C0 */  sll   $t8, $t9, 7
/* 10F348 7F0DA818 00145843 */  sra   $t3, $s4, 1
/* 10F34C 7F0DA81C 0178A025 */  or    $s4, $t3, $t8
/* 10F350 7F0DA820 328C00FF */  andi  $t4, $s4, 0xff
/* 10F354 7F0DA824 3C0B8009 */  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F358 7F0DA828 8D6BE334 */  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
/* 10F35C 7F0DA82C 2D890001 */  sltiu $t1, $t4, 1
/* 10F360 7F0DA830 AFA90048 */  sw    $t1, 0x48($sp)
/* 10F364 7F0DA834 0180A025 */  move  $s4, $t4
/* 10F368 7F0DA838 318E00A8 */  andi  $t6, $t4, 0xa8
/* 10F36C 7F0DA83C A3B90136 */  sb    $t9, 0x136($sp)
/* 10F370 7F0DA840 018BC021 */  addu  $t8, $t4, $t3
/* 10F374 7F0DA844 930C0000 */  lbu   $t4, ($t8)
/* 10F378 7F0DA848 032E4025 */  or    $t0, $t9, $t6
/* 10F37C 7F0DA84C 00095180 */  sll   $t2, $t1, 6
/* 10F380 7F0DA850 010A7825 */  or    $t7, $t0, $t2
/* 10F384 7F0DA854 018F8825 */  or    $s1, $t4, $t7
/* 10F388 7F0DA858 322900FF */  andi  $t1, $s1, 0xff
/* 10F38C 7F0DA85C 1000074E */  b     .L7F0DC598
/* 10F390 7F0DA860 01208825 */   move  $s1, $t1
spectrum_op_CB_0B:
/* 10F394 7F0DA864 32AD0001 */  andi  $t5, $s5, 1
/* 10F398 7F0DA868 000D41C0 */  sll   $t0, $t5, 7
/* 10F39C 7F0DA86C 00157043 */  sra   $t6, $s5, 1
/* 10F3A0 7F0DA870 01C8A825 */  or    $s5, $t6, $t0
/* 10F3A4 7F0DA874 32AA00FF */  andi  $t2, $s5, 0xff
/* 10F3A8 7F0DA878 3C0E8009 */  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F3AC 7F0DA87C 8DCEE334 */  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
/* 10F3B0 7F0DA880 2D4B0001 */  sltiu $t3, $t2, 1
/* 10F3B4 7F0DA884 AFAB0048 */  sw    $t3, 0x48($sp)
/* 10F3B8 7F0DA888 0140A825 */  move  $s5, $t2
/* 10F3BC 7F0DA88C 315800A8 */  andi  $t8, $t2, 0xa8
/* 10F3C0 7F0DA890 A3AD0135 */  sb    $t5, 0x135($sp)
/* 10F3C4 7F0DA894 014E4021 */  addu  $t0, $t2, $t6
/* 10F3C8 7F0DA898 910A0000 */  lbu   $t2, ($t0)
/* 10F3CC 7F0DA89C 01B86025 */  or    $t4, $t5, $t8
/* 10F3D0 7F0DA8A0 000B4980 */  sll   $t1, $t3, 6
/* 10F3D4 7F0DA8A4 0189C825 */  or    $t9, $t4, $t1
/* 10F3D8 7F0DA8A8 01598825 */  or    $s1, $t2, $t9
/* 10F3DC 7F0DA8AC 322B00FF */  andi  $t3, $s1, 0xff
/* 10F3E0 7F0DA8B0 10000739 */  b     .L7F0DC598
/* 10F3E4 7F0DA8B4 01608825 */   move  $s1, $t3
spectrum_op_CB_0C:
/* 10F3E8 7F0DA8B8 32CF0001 */  andi  $t7, $s6, 1
/* 10F3EC 7F0DA8BC 000F61C0 */  sll   $t4, $t7, 7
/* 10F3F0 7F0DA8C0 0016C043 */  sra   $t8, $s6, 1
/* 10F3F4 7F0DA8C4 030CB025 */  or    $s6, $t8, $t4
/* 10F3F8 7F0DA8C8 32C900FF */  andi  $t1, $s6, 0xff
/* 10F3FC 7F0DA8CC 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F400 7F0DA8D0 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 10F404 7F0DA8D4 2D2E0001 */  sltiu $t6, $t1, 1
/* 10F408 7F0DA8D8 AFAE0048 */  sw    $t6, 0x48($sp)
/* 10F40C 7F0DA8DC 0120B025 */  move  $s6, $t1
/* 10F410 7F0DA8E0 312800A8 */  andi  $t0, $t1, 0xa8
/* 10F414 7F0DA8E4 A3AF0134 */  sb    $t7, 0x134($sp)
/* 10F418 7F0DA8E8 01386021 */  addu  $t4, $t1, $t8
/* 10F41C 7F0DA8EC 91890000 */  lbu   $t1, ($t4)
/* 10F420 7F0DA8F0 01E85025 */  or    $t2, $t7, $t0
/* 10F424 7F0DA8F4 000E5980 */  sll   $t3, $t6, 6
/* 10F428 7F0DA8F8 014B6825 */  or    $t5, $t2, $t3
/* 10F42C 7F0DA8FC 012D8825 */  or    $s1, $t1, $t5
/* 10F430 7F0DA900 322E00FF */  andi  $t6, $s1, 0xff
/* 10F434 7F0DA904 10000724 */  b     .L7F0DC598
/* 10F438 7F0DA908 01C08825 */   move  $s1, $t6
spectrum_op_CB_0D:
/* 10F43C 7F0DA90C 32F90001 */  andi  $t9, $s7, 1
/* 10F440 7F0DA910 001951C0 */  sll   $t2, $t9, 7
/* 10F444 7F0DA914 00174043 */  sra   $t0, $s7, 1
/* 10F448 7F0DA918 010AB825 */  or    $s7, $t0, $t2
/* 10F44C 7F0DA91C 32EB00FF */  andi  $t3, $s7, 0xff
/* 10F450 7F0DA920 3C088009 */  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F454 7F0DA924 8D08E334 */  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
/* 10F458 7F0DA928 2D780001 */  sltiu $t8, $t3, 1
/* 10F45C 7F0DA92C AFB80048 */  sw    $t8, 0x48($sp)
/* 10F460 7F0DA930 0160B825 */  move  $s7, $t3
/* 10F464 7F0DA934 316C00A8 */  andi  $t4, $t3, 0xa8
/* 10F468 7F0DA938 A3B90133 */  sb    $t9, 0x133($sp)
/* 10F46C 7F0DA93C 01685021 */  addu  $t2, $t3, $t0
/* 10F470 7F0DA940 914B0000 */  lbu   $t3, ($t2)
/* 10F474 7F0DA944 032C4825 */  or    $t1, $t9, $t4
/* 10F478 7F0DA948 00187180 */  sll   $t6, $t8, 6
/* 10F47C 7F0DA94C 012E7825 */  or    $t7, $t1, $t6
/* 10F480 7F0DA950 016F8825 */  or    $s1, $t3, $t7
/* 10F484 7F0DA954 323800FF */  andi  $t8, $s1, 0xff
/* 10F488 7F0DA958 1000070F */  b     .L7F0DC598
/* 10F48C 7F0DA95C 03008825 */   move  $s1, $t8
spectrum_op_CB_0E:
/* 10F490 7F0DA960 8FB9028C */  lw    $t9, 0x28c($sp)
/* 10F494 7F0DA964 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10F498 7F0DA968 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10F49C 7F0DA96C 97AD013C */  lhu   $t5, 0x13c($sp)
/* 10F4A0 7F0DA970 272C0007 */  addiu $t4, $t9, 7
/* 10F4A4 7F0DA974 AFAC028C */  sw    $t4, 0x28c($sp)
/* 10F4A8 7F0DA978 01A97021 */  addu  $t6, $t5, $t1
/* 10F4AC 7F0DA97C 91C80000 */  lbu   $t0, ($t6)
/* 10F4B0 7F0DA980 310A00FF */  andi  $t2, $t0, 0xff
/* 10F4B4 7F0DA984 314E0001 */  andi  $t6, $t2, 1
/* 10F4B8 7F0DA988 31D800FF */  andi  $t8, $t6, 0xff
/* 10F4BC 7F0DA98C 0018C9C0 */  sll   $t9, $t8, 7
/* 10F4C0 7F0DA990 000A7843 */  sra   $t7, $t2, 1
/* 10F4C4 7F0DA994 01F96025 */  or    $t4, $t7, $t9
/* 10F4C8 7F0DA998 3C198009 */  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F4CC 7F0DA99C 8F39E334 */  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
/* 10F4D0 7F0DA9A0 318D00FF */  andi  $t5, $t4, 0xff
/* 10F4D4 7F0DA9A4 A3A80139 */  sb    $t0, 0x139($sp)
/* 10F4D8 7F0DA9A8 2DA90001 */  sltiu $t1, $t5, 1
/* 10F4DC 7F0DA9AC 318A00A8 */  andi  $t2, $t4, 0xa8
/* 10F4E0 7F0DA9B0 01CA5825 */  or    $t3, $t6, $t2
/* 10F4E4 7F0DA9B4 AFA90048 */  sw    $t1, 0x48($sp)
/* 10F4E8 7F0DA9B8 A3AC0139 */  sb    $t4, 0x139($sp)
/* 10F4EC 7F0DA9BC A3AE0132 */  sb    $t6, 0x132($sp)
/* 10F4F0 7F0DA9C0 01B94021 */  addu  $t0, $t5, $t9
/* 10F4F4 7F0DA9C4 910E0000 */  lbu   $t6, ($t0)
/* 10F4F8 7F0DA9C8 0009C180 */  sll   $t8, $t1, 6
/* 10F4FC 7F0DA9CC 97A9013C */  lhu   $t1, 0x13c($sp)
/* 10F500 7F0DA9D0 01787825 */  or    $t7, $t3, $t8
/* 10F504 7F0DA9D4 01CF8825 */  or    $s1, $t6, $t7
/* 10F508 7F0DA9D8 322A00FF */  andi  $t2, $s1, 0xff
/* 10F50C 7F0DA9DC 29215B00 */  slti  $at, $t1, 0x5b00
/* 10F510 7F0DA9E0 14200007 */  bnez  $at, .L7F0DAA00
/* 10F514 7F0DA9E4 01408825 */   move  $s1, $t2
/* 10F518 7F0DA9E8 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 10F51C 7F0DA9EC 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10F520 7F0DA9F0 01805825 */  move  $t3, $t4
/* 10F524 7F0DA9F4 03096021 */  addu  $t4, $t8, $t1
/* 10F528 7F0DA9F8 100006E7 */  b     .L7F0DC598
/* 10F52C 7F0DA9FC A18B0000 */   sb    $t3, ($t4)
.L7F0DAA00:
/* 10F530 7F0DAA00 97AD013C */  lhu   $t5, 0x13c($sp)
/* 10F534 7F0DAA04 97AB013C */  lhu   $t3, 0x13c($sp)
/* 10F538 7F0DAA08 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10F53C 7F0DAA0C 29A15800 */  slti  $at, $t5, 0x5800
/* 10F540 7F0DAA10 5420000D */  bnezl $at, .L7F0DAA48
/* 10F544 7F0DAA14 29614000 */   slti  $at, $t3, 0x4000
/* 10F548 7F0DAA18 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10F54C 7F0DAA1C 93B90139 */  lbu   $t9, 0x139($sp)
/* 10F550 7F0DAA20 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 10F554 7F0DAA24 010D7021 */  addu  $t6, $t0, $t5
/* 10F558 7F0DAA28 A1D90000 */  sb    $t9, ($t6)
/* 10F55C 7F0DAA2C 97B8013C */  lhu   $t8, 0x13c($sp)
/* 10F560 7F0DAA30 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 10F564 7F0DAA34 240F0001 */  li    $t7, 1
/* 10F568 7F0DAA38 01584821 */  addu  $t1, $t2, $t8
/* 10F56C 7F0DAA3C 100006D6 */  b     .L7F0DC598
/* 10F570 7F0DAA40 A12FA800 */   sb    $t7, -0x5800($t1)
/* 10F574 7F0DAA44 29614000 */  slti  $at, $t3, 0x4000
.L7F0DAA48:
/* 10F578 7F0DAA48 142006D3 */  bnez  $at, .L7F0DC598
/* 10F57C 7F0DAA4C 3C088009 */   lui   $t0, %hi(ptr_spectrum_roms) 
/* 10F580 7F0DAA50 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10F584 7F0DAA54 93AC0139 */  lbu   $t4, 0x139($sp)
/* 10F588 7F0DAA58 24190001 */  li    $t9, 1
/* 10F58C 7F0DAA5C 010B6821 */  addu  $t5, $t0, $t3
/* 10F590 7F0DAA60 A1AC0000 */  sb    $t4, ($t5)
/* 10F594 7F0DAA64 97AE013C */  lhu   $t6, 0x13c($sp)
/* 10F598 7F0DAA68 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 10F59C 7F0DAA6C 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 10F5A0 7F0DAA70 31CA1800 */  andi  $t2, $t6, 0x1800
/* 10F5A4 7F0DAA74 000AC0C3 */  sra   $t8, $t2, 3
/* 10F5A8 7F0DAA78 31CF00FF */  andi  $t7, $t6, 0xff
/* 10F5AC 7F0DAA7C 030F4825 */  or    $t1, $t8, $t7
/* 10F5B0 7F0DAA80 01095821 */  addu  $t3, $t0, $t1
/* 10F5B4 7F0DAA84 100006C4 */  b     .L7F0DC598
/* 10F5B8 7F0DAA88 A1790000 */   sb    $t9, ($t3)
spectrum_op_CB_0F:
/* 10F5BC 7F0DAA8C 320A0001 */  andi  $t2, $s0, 1
/* 10F5C0 7F0DAA90 000A71C0 */  sll   $t6, $t2, 7
/* 10F5C4 7F0DAA94 00106843 */  sra   $t5, $s0, 1
/* 10F5C8 7F0DAA98 01AE8025 */  or    $s0, $t5, $t6
/* 10F5CC 7F0DAA9C 321800FF */  andi  $t8, $s0, 0xff
/* 10F5D0 7F0DAAA0 3C0D8009 */  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F5D4 7F0DAAA4 8DADE334 */  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
/* 10F5D8 7F0DAAA8 2F0F0001 */  sltiu $t7, $t8, 1
/* 10F5DC 7F0DAAAC AFAF0048 */  sw    $t7, 0x48($sp)
/* 10F5E0 7F0DAAB0 03008025 */  move  $s0, $t8
/* 10F5E4 7F0DAAB4 330800A8 */  andi  $t0, $t8, 0xa8
/* 10F5E8 7F0DAAB8 A3AA0131 */  sb    $t2, 0x131($sp)
/* 10F5EC 7F0DAABC 030D7021 */  addu  $t6, $t8, $t5
/* 10F5F0 7F0DAAC0 91D80000 */  lbu   $t8, ($t6)
/* 10F5F4 7F0DAAC4 01484825 */  or    $t1, $t2, $t0
/* 10F5F8 7F0DAAC8 000F5980 */  sll   $t3, $t7, 6
/* 10F5FC 7F0DAACC 012B6025 */  or    $t4, $t1, $t3
/* 10F600 7F0DAAD0 030C8825 */  or    $s1, $t8, $t4
/* 10F604 7F0DAAD4 322F00FF */  andi  $t7, $s1, 0xff
/* 10F608 7F0DAAD8 100006AF */  b     .L7F0DC598
/* 10F60C 7F0DAADC 01E08825 */   move  $s1, $t7
spectrum_op_CB_10:
/* 10F610 7F0DAAE0 001269C3 */  sra   $t5, $s2, 7
/* 10F614 7F0DAAE4 00124040 */  sll   $t0, $s2, 1
/* 10F618 7F0DAAE8 32390001 */  andi  $t9, $s1, 1
/* 10F61C 7F0DAAEC 01199025 */  or    $s2, $t0, $t9
/* 10F620 7F0DAAF0 324900FF */  andi  $t1, $s2, 0xff
/* 10F624 7F0DAAF4 3C088009 */  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F628 7F0DAAF8 8D08E334 */  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
/* 10F62C 7F0DAAFC 2D2B0001 */  sltiu $t3, $t1, 1
/* 10F630 7F0DAB00 AFAB0048 */  sw    $t3, 0x48($sp)
/* 10F634 7F0DAB04 01209025 */  move  $s2, $t1
/* 10F638 7F0DAB08 312E00A8 */  andi  $t6, $t1, 0xa8
/* 10F63C 7F0DAB0C A3AD0130 */  sb    $t5, 0x130($sp)
/* 10F640 7F0DAB10 0128C821 */  addu  $t9, $t1, $t0
/* 10F644 7F0DAB14 93290000 */  lbu   $t1, ($t9)
/* 10F648 7F0DAB18 01AEC025 */  or    $t8, $t5, $t6
/* 10F64C 7F0DAB1C 000B7980 */  sll   $t7, $t3, 6
/* 10F650 7F0DAB20 030F5025 */  or    $t2, $t8, $t7
/* 10F654 7F0DAB24 012A8825 */  or    $s1, $t1, $t2
/* 10F658 7F0DAB28 322B00FF */  andi  $t3, $s1, 0xff
/* 10F65C 7F0DAB2C 1000069A */  b     .L7F0DC598
/* 10F660 7F0DAB30 01608825 */   move  $s1, $t3
spectrum_op_CB_11:
/* 10F664 7F0DAB34 001341C3 */  sra   $t0, $s3, 7
/* 10F668 7F0DAB38 00137040 */  sll   $t6, $s3, 1
/* 10F66C 7F0DAB3C 322C0001 */  andi  $t4, $s1, 1
/* 10F670 7F0DAB40 01CC9825 */  or    $s3, $t6, $t4
/* 10F674 7F0DAB44 327800FF */  andi  $t8, $s3, 0xff
/* 10F678 7F0DAB48 3C0E8009 */  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F67C 7F0DAB4C 8DCEE334 */  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
/* 10F680 7F0DAB50 2F0F0001 */  sltiu $t7, $t8, 1
/* 10F684 7F0DAB54 AFAF0048 */  sw    $t7, 0x48($sp)
/* 10F688 7F0DAB58 03009825 */  move  $s3, $t8
/* 10F68C 7F0DAB5C 331900A8 */  andi  $t9, $t8, 0xa8
/* 10F690 7F0DAB60 A3A8012F */  sb    $t0, 0x12f($sp)
/* 10F694 7F0DAB64 030E6021 */  addu  $t4, $t8, $t6
/* 10F698 7F0DAB68 91980000 */  lbu   $t8, ($t4)
/* 10F69C 7F0DAB6C 01194825 */  or    $t1, $t0, $t9
/* 10F6A0 7F0DAB70 000F5980 */  sll   $t3, $t7, 6
/* 10F6A4 7F0DAB74 012B6825 */  or    $t5, $t1, $t3
/* 10F6A8 7F0DAB78 030D8825 */  or    $s1, $t8, $t5
/* 10F6AC 7F0DAB7C 322F00FF */  andi  $t7, $s1, 0xff
/* 10F6B0 7F0DAB80 10000685 */  b     .L7F0DC598
/* 10F6B4 7F0DAB84 01E08825 */   move  $s1, $t7
spectrum_op_CB_12:
/* 10F6B8 7F0DAB88 001471C3 */  sra   $t6, $s4, 7
/* 10F6BC 7F0DAB8C 0014C840 */  sll   $t9, $s4, 1
/* 10F6C0 7F0DAB90 322A0001 */  andi  $t2, $s1, 1
/* 10F6C4 7F0DAB94 032AA025 */  or    $s4, $t9, $t2
/* 10F6C8 7F0DAB98 328900FF */  andi  $t1, $s4, 0xff
/* 10F6CC 7F0DAB9C 3C198009 */  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F6D0 7F0DABA0 8F39E334 */  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
/* 10F6D4 7F0DABA4 2D2B0001 */  sltiu $t3, $t1, 1
/* 10F6D8 7F0DABA8 AFAB0048 */  sw    $t3, 0x48($sp)
/* 10F6DC 7F0DABAC 0120A025 */  move  $s4, $t1
/* 10F6E0 7F0DABB0 312C00A8 */  andi  $t4, $t1, 0xa8
/* 10F6E4 7F0DABB4 A3AE012E */  sb    $t6, 0x12e($sp)
/* 10F6E8 7F0DABB8 01395021 */  addu  $t2, $t1, $t9
/* 10F6EC 7F0DABBC 91490000 */  lbu   $t1, ($t2)
/* 10F6F0 7F0DABC0 01CCC025 */  or    $t8, $t6, $t4
/* 10F6F4 7F0DABC4 000B7980 */  sll   $t7, $t3, 6
/* 10F6F8 7F0DABC8 030F4025 */  or    $t0, $t8, $t7
/* 10F6FC 7F0DABCC 01288825 */  or    $s1, $t1, $t0
/* 10F700 7F0DABD0 322B00FF */  andi  $t3, $s1, 0xff
/* 10F704 7F0DABD4 10000670 */  b     .L7F0DC598
/* 10F708 7F0DABD8 01608825 */   move  $s1, $t3
spectrum_op_CB_13:
/* 10F70C 7F0DABDC 0015C9C3 */  sra   $t9, $s5, 7
/* 10F710 7F0DABE0 00156040 */  sll   $t4, $s5, 1
/* 10F714 7F0DABE4 322D0001 */  andi  $t5, $s1, 1
/* 10F718 7F0DABE8 018DA825 */  or    $s5, $t4, $t5
/* 10F71C 7F0DABEC 32B800FF */  andi  $t8, $s5, 0xff
/* 10F720 7F0DABF0 3C0C8009 */  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F724 7F0DABF4 8D8CE334 */  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
/* 10F728 7F0DABF8 2F0F0001 */  sltiu $t7, $t8, 1
/* 10F72C 7F0DABFC AFAF0048 */  sw    $t7, 0x48($sp)
/* 10F730 7F0DAC00 0300A825 */  move  $s5, $t8
/* 10F734 7F0DAC04 330A00A8 */  andi  $t2, $t8, 0xa8
/* 10F738 7F0DAC08 A3B9012D */  sb    $t9, 0x12d($sp)
/* 10F73C 7F0DAC0C 030C6821 */  addu  $t5, $t8, $t4
/* 10F740 7F0DAC10 91B80000 */  lbu   $t8, ($t5)
/* 10F744 7F0DAC14 032A4825 */  or    $t1, $t9, $t2
/* 10F748 7F0DAC18 000F5980 */  sll   $t3, $t7, 6
/* 10F74C 7F0DAC1C 012B7025 */  or    $t6, $t1, $t3
/* 10F750 7F0DAC20 030E8825 */  or    $s1, $t8, $t6
/* 10F754 7F0DAC24 322F00FF */  andi  $t7, $s1, 0xff
/* 10F758 7F0DAC28 1000065B */  b     .L7F0DC598
/* 10F75C 7F0DAC2C 01E08825 */   move  $s1, $t7
spectrum_op_CB_14:
/* 10F760 7F0DAC30 001661C3 */  sra   $t4, $s6, 7
/* 10F764 7F0DAC34 00165040 */  sll   $t2, $s6, 1
/* 10F768 7F0DAC38 32280001 */  andi  $t0, $s1, 1
/* 10F76C 7F0DAC3C 0148B025 */  or    $s6, $t2, $t0
/* 10F770 7F0DAC40 32C900FF */  andi  $t1, $s6, 0xff
/* 10F774 7F0DAC44 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F778 7F0DAC48 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 10F77C 7F0DAC4C 2D2B0001 */  sltiu $t3, $t1, 1
/* 10F780 7F0DAC50 AFAB0048 */  sw    $t3, 0x48($sp)
/* 10F784 7F0DAC54 0120B025 */  move  $s6, $t1
/* 10F788 7F0DAC58 312D00A8 */  andi  $t5, $t1, 0xa8
/* 10F78C 7F0DAC5C A3AC012C */  sb    $t4, 0x12c($sp)
/* 10F790 7F0DAC60 012A4021 */  addu  $t0, $t1, $t2
/* 10F794 7F0DAC64 91090000 */  lbu   $t1, ($t0)
/* 10F798 7F0DAC68 018DC025 */  or    $t8, $t4, $t5
/* 10F79C 7F0DAC6C 000B7980 */  sll   $t7, $t3, 6
/* 10F7A0 7F0DAC70 030FC825 */  or    $t9, $t8, $t7
/* 10F7A4 7F0DAC74 01398825 */  or    $s1, $t1, $t9
/* 10F7A8 7F0DAC78 322B00FF */  andi  $t3, $s1, 0xff
/* 10F7AC 7F0DAC7C 10000646 */  b     .L7F0DC598
/* 10F7B0 7F0DAC80 01608825 */   move  $s1, $t3
spectrum_op_CB_15:
/* 10F7B4 7F0DAC84 001751C3 */  sra   $t2, $s7, 7
/* 10F7B8 7F0DAC88 00176840 */  sll   $t5, $s7, 1
/* 10F7BC 7F0DAC8C 322E0001 */  andi  $t6, $s1, 1
/* 10F7C0 7F0DAC90 01AEB825 */  or    $s7, $t5, $t6
/* 10F7C4 7F0DAC94 32F800FF */  andi  $t8, $s7, 0xff
/* 10F7C8 7F0DAC98 3C0D8009 */  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F7CC 7F0DAC9C 8DADE334 */  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
/* 10F7D0 7F0DACA0 2F0F0001 */  sltiu $t7, $t8, 1
/* 10F7D4 7F0DACA4 AFAF0048 */  sw    $t7, 0x48($sp)
/* 10F7D8 7F0DACA8 0300B825 */  move  $s7, $t8
/* 10F7DC 7F0DACAC 330800A8 */  andi  $t0, $t8, 0xa8
/* 10F7E0 7F0DACB0 A3AA012B */  sb    $t2, 0x12b($sp)
/* 10F7E4 7F0DACB4 030D7021 */  addu  $t6, $t8, $t5
/* 10F7E8 7F0DACB8 91D80000 */  lbu   $t8, ($t6)
/* 10F7EC 7F0DACBC 01484825 */  or    $t1, $t2, $t0
/* 10F7F0 7F0DACC0 000F5980 */  sll   $t3, $t7, 6
/* 10F7F4 7F0DACC4 012B6025 */  or    $t4, $t1, $t3
/* 10F7F8 7F0DACC8 030C8825 */  or    $s1, $t8, $t4
/* 10F7FC 7F0DACCC 322F00FF */  andi  $t7, $s1, 0xff
/* 10F800 7F0DACD0 10000631 */  b     .L7F0DC598
/* 10F804 7F0DACD4 01E08825 */   move  $s1, $t7
spectrum_op_CB_16:
/* 10F808 7F0DACD8 8FAA028C */  lw    $t2, 0x28c($sp)
/* 10F80C 7F0DACDC 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 10F810 7F0DACE0 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 10F814 7F0DACE4 97B9013C */  lhu   $t9, 0x13c($sp)
/* 10F818 7F0DACE8 25480007 */  addiu $t0, $t2, 7
/* 10F81C 7F0DACEC AFA8028C */  sw    $t0, 0x28c($sp)
/* 10F820 7F0DACF0 03295821 */  addu  $t3, $t9, $t1
/* 10F824 7F0DACF4 916D0000 */  lbu   $t5, ($t3)
/* 10F828 7F0DACF8 322F0001 */  andi  $t7, $s1, 1
/* 10F82C 7F0DACFC 31AE00FF */  andi  $t6, $t5, 0xff
/* 10F830 7F0DAD00 000E6040 */  sll   $t4, $t6, 1
/* 10F834 7F0DAD04 018F5025 */  or    $t2, $t4, $t7
/* 10F838 7F0DAD08 3C0F8009 */  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F83C 7F0DAD0C 8DEFE334 */  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
/* 10F840 7F0DAD10 000E49C3 */  sra   $t1, $t6, 7
/* 10F844 7F0DAD14 314800FF */  andi  $t0, $t2, 0xff
/* 10F848 7F0DAD18 A3AD0139 */  sb    $t5, 0x139($sp)
/* 10F84C 7F0DAD1C 314D00A8 */  andi  $t5, $t2, 0xa8
/* 10F850 7F0DAD20 2D190001 */  sltiu $t9, $t0, 1
/* 10F854 7F0DAD24 AFB90048 */  sw    $t9, 0x48($sp)
/* 10F858 7F0DAD28 012DC025 */  or    $t8, $t1, $t5
/* 10F85C 7F0DAD2C A3AA0139 */  sb    $t2, 0x139($sp)
/* 10F860 7F0DAD30 A3A9012A */  sb    $t1, 0x12a($sp)
/* 10F864 7F0DAD34 010F5821 */  addu  $t3, $t0, $t7
/* 10F868 7F0DAD38 91690000 */  lbu   $t1, ($t3)
/* 10F86C 7F0DAD3C 00197180 */  sll   $t6, $t9, 6
/* 10F870 7F0DAD40 97B9013C */  lhu   $t9, 0x13c($sp)
/* 10F874 7F0DAD44 030E6025 */  or    $t4, $t8, $t6
/* 10F878 7F0DAD48 012C8825 */  or    $s1, $t1, $t4
/* 10F87C 7F0DAD4C 322D00FF */  andi  $t5, $s1, 0xff
/* 10F880 7F0DAD50 2B215B00 */  slti  $at, $t9, 0x5b00
/* 10F884 7F0DAD54 14200007 */  bnez  $at, .L7F0DAD74
/* 10F888 7F0DAD58 01A08825 */   move  $s1, $t5
/* 10F88C 7F0DAD5C 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10F890 7F0DAD60 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10F894 7F0DAD64 0140C025 */  move  $t8, $t2
/* 10F898 7F0DAD68 01D95021 */  addu  $t2, $t6, $t9
/* 10F89C 7F0DAD6C 1000060A */  b     .L7F0DC598
/* 10F8A0 7F0DAD70 A1580000 */   sb    $t8, ($t2)
.L7F0DAD74:
/* 10F8A4 7F0DAD74 97A8013C */  lhu   $t0, 0x13c($sp)
/* 10F8A8 7F0DAD78 97B8013C */  lhu   $t8, 0x13c($sp)
/* 10F8AC 7F0DAD7C 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 10F8B0 7F0DAD80 29015800 */  slti  $at, $t0, 0x5800
/* 10F8B4 7F0DAD84 5420000D */  bnezl $at, .L7F0DADBC
/* 10F8B8 7F0DAD88 2B014000 */   slti  $at, $t8, 0x4000
/* 10F8BC 7F0DAD8C 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10F8C0 7F0DAD90 93AF0139 */  lbu   $t7, 0x139($sp)
/* 10F8C4 7F0DAD94 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 10F8C8 7F0DAD98 01684821 */  addu  $t1, $t3, $t0
/* 10F8CC 7F0DAD9C A12F0000 */  sb    $t7, ($t1)
/* 10F8D0 7F0DADA0 97AE013C */  lhu   $t6, 0x13c($sp)
/* 10F8D4 7F0DADA4 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 10F8D8 7F0DADA8 240C0001 */  li    $t4, 1
/* 10F8DC 7F0DADAC 01AEC821 */  addu  $t9, $t5, $t6
/* 10F8E0 7F0DADB0 100005F9 */  b     .L7F0DC598
/* 10F8E4 7F0DADB4 A32CA800 */   sb    $t4, -0x5800($t9)
/* 10F8E8 7F0DADB8 2B014000 */  slti  $at, $t8, 0x4000
.L7F0DADBC:
/* 10F8EC 7F0DADBC 142005F6 */  bnez  $at, .L7F0DC598
/* 10F8F0 7F0DADC0 3C0B8009 */   lui   $t3, %hi(ptr_spectrum_roms) 
/* 10F8F4 7F0DADC4 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 10F8F8 7F0DADC8 93AA0139 */  lbu   $t2, 0x139($sp)
/* 10F8FC 7F0DADCC 240F0001 */  li    $t7, 1
/* 10F900 7F0DADD0 01784021 */  addu  $t0, $t3, $t8
/* 10F904 7F0DADD4 A10A0000 */  sb    $t2, ($t0)
/* 10F908 7F0DADD8 97A9013C */  lhu   $t1, 0x13c($sp)
/* 10F90C 7F0DADDC 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 10F910 7F0DADE0 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 10F914 7F0DADE4 312D1800 */  andi  $t5, $t1, 0x1800
/* 10F918 7F0DADE8 000D70C3 */  sra   $t6, $t5, 3
/* 10F91C 7F0DADEC 312C00FF */  andi  $t4, $t1, 0xff
/* 10F920 7F0DADF0 01CCC825 */  or    $t9, $t6, $t4
/* 10F924 7F0DADF4 0179C021 */  addu  $t8, $t3, $t9
/* 10F928 7F0DADF8 100005E7 */  b     .L7F0DC598
/* 10F92C 7F0DADFC A30F0000 */   sb    $t7, ($t8)
spectrum_op_CB_17:
/* 10F930 7F0DAE00 001061C3 */  sra   $t4, $s0, 7
/* 10F934 7F0DAE04 00104040 */  sll   $t0, $s0, 1
/* 10F938 7F0DAE08 322D0001 */  andi  $t5, $s1, 1
/* 10F93C 7F0DAE0C 010D8025 */  or    $s0, $t0, $t5
/* 10F940 7F0DAE10 320900FF */  andi  $t1, $s0, 0xff
/* 10F944 7F0DAE14 3C088009 */  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F948 7F0DAE18 8D08E334 */  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
/* 10F94C 7F0DAE1C 2D2E0001 */  sltiu $t6, $t1, 1
/* 10F950 7F0DAE20 AFAE0048 */  sw    $t6, 0x48($sp)
/* 10F954 7F0DAE24 01208025 */  move  $s0, $t1
/* 10F958 7F0DAE28 312B00A8 */  andi  $t3, $t1, 0xa8
/* 10F95C 7F0DAE2C A3AC0129 */  sb    $t4, 0x129($sp)
/* 10F960 7F0DAE30 01286821 */  addu  $t5, $t1, $t0
/* 10F964 7F0DAE34 91A90000 */  lbu   $t1, ($t5)
/* 10F968 7F0DAE38 018BC825 */  or    $t9, $t4, $t3
/* 10F96C 7F0DAE3C 000EC180 */  sll   $t8, $t6, 6
/* 10F970 7F0DAE40 03385025 */  or    $t2, $t9, $t8
/* 10F974 7F0DAE44 012A8825 */  or    $s1, $t1, $t2
/* 10F978 7F0DAE48 322E00FF */  andi  $t6, $s1, 0xff
/* 10F97C 7F0DAE4C 100005D2 */  b     .L7F0DC598
/* 10F980 7F0DAE50 01C08825 */   move  $s1, $t6
spectrum_op_CB_18:
/* 10F984 7F0DAE54 32480001 */  andi  $t0, $s2, 1
/* 10F988 7F0DAE58 00125843 */  sra   $t3, $s2, 1
/* 10F98C 7F0DAE5C 001179C0 */  sll   $t7, $s1, 7
/* 10F990 7F0DAE60 016F9025 */  or    $s2, $t3, $t7
/* 10F994 7F0DAE64 325900FF */  andi  $t9, $s2, 0xff
/* 10F998 7F0DAE68 3C0B8009 */  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F99C 7F0DAE6C 8D6BE334 */  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
/* 10F9A0 7F0DAE70 2F380001 */  sltiu $t8, $t9, 1
/* 10F9A4 7F0DAE74 AFB80048 */  sw    $t8, 0x48($sp)
/* 10F9A8 7F0DAE78 03209025 */  move  $s2, $t9
/* 10F9AC 7F0DAE7C 332D00A8 */  andi  $t5, $t9, 0xa8
/* 10F9B0 7F0DAE80 A3A80128 */  sb    $t0, 0x128($sp)
/* 10F9B4 7F0DAE84 032B7821 */  addu  $t7, $t9, $t3
/* 10F9B8 7F0DAE88 91F90000 */  lbu   $t9, ($t7)
/* 10F9BC 7F0DAE8C 010D4825 */  or    $t1, $t0, $t5
/* 10F9C0 7F0DAE90 00187180 */  sll   $t6, $t8, 6
/* 10F9C4 7F0DAE94 012E6025 */  or    $t4, $t1, $t6
/* 10F9C8 7F0DAE98 032C8825 */  or    $s1, $t9, $t4
/* 10F9CC 7F0DAE9C 323800FF */  andi  $t8, $s1, 0xff
/* 10F9D0 7F0DAEA0 100005BD */  b     .L7F0DC598
/* 10F9D4 7F0DAEA4 03008825 */   move  $s1, $t8
spectrum_op_CB_19:
/* 10F9D8 7F0DAEA8 326B0001 */  andi  $t3, $s3, 1
/* 10F9DC 7F0DAEAC 00136843 */  sra   $t5, $s3, 1
/* 10F9E0 7F0DAEB0 001151C0 */  sll   $t2, $s1, 7
/* 10F9E4 7F0DAEB4 01AA9825 */  or    $s3, $t5, $t2
/* 10F9E8 7F0DAEB8 326900FF */  andi  $t1, $s3, 0xff
/* 10F9EC 7F0DAEBC 3C0D8009 */  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
/* 10F9F0 7F0DAEC0 8DADE334 */  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
/* 10F9F4 7F0DAEC4 2D2E0001 */  sltiu $t6, $t1, 1
/* 10F9F8 7F0DAEC8 AFAE0048 */  sw    $t6, 0x48($sp)
/* 10F9FC 7F0DAECC 01209825 */  move  $s3, $t1
/* 10FA00 7F0DAED0 312F00A8 */  andi  $t7, $t1, 0xa8
/* 10FA04 7F0DAED4 A3AB0127 */  sb    $t3, 0x127($sp)
/* 10FA08 7F0DAED8 012D5021 */  addu  $t2, $t1, $t5
/* 10FA0C 7F0DAEDC 91490000 */  lbu   $t1, ($t2)
/* 10FA10 7F0DAEE0 016FC825 */  or    $t9, $t3, $t7
/* 10FA14 7F0DAEE4 000EC180 */  sll   $t8, $t6, 6
/* 10FA18 7F0DAEE8 03384025 */  or    $t0, $t9, $t8
/* 10FA1C 7F0DAEEC 01288825 */  or    $s1, $t1, $t0
/* 10FA20 7F0DAEF0 322E00FF */  andi  $t6, $s1, 0xff
/* 10FA24 7F0DAEF4 100005A8 */  b     .L7F0DC598
/* 10FA28 7F0DAEF8 01C08825 */   move  $s1, $t6
spectrum_op_CB_1A:
/* 10FA2C 7F0DAEFC 328D0001 */  andi  $t5, $s4, 1
/* 10FA30 7F0DAF00 00147843 */  sra   $t7, $s4, 1
/* 10FA34 7F0DAF04 001161C0 */  sll   $t4, $s1, 7
/* 10FA38 7F0DAF08 01ECA025 */  or    $s4, $t7, $t4
/* 10FA3C 7F0DAF0C 329900FF */  andi  $t9, $s4, 0xff
/* 10FA40 7F0DAF10 3C0F8009 */  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FA44 7F0DAF14 8DEFE334 */  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
/* 10FA48 7F0DAF18 2F380001 */  sltiu $t8, $t9, 1
/* 10FA4C 7F0DAF1C AFB80048 */  sw    $t8, 0x48($sp)
/* 10FA50 7F0DAF20 0320A025 */  move  $s4, $t9
/* 10FA54 7F0DAF24 332A00A8 */  andi  $t2, $t9, 0xa8
/* 10FA58 7F0DAF28 A3AD0126 */  sb    $t5, 0x126($sp)
/* 10FA5C 7F0DAF2C 032F6021 */  addu  $t4, $t9, $t7
/* 10FA60 7F0DAF30 91990000 */  lbu   $t9, ($t4)
/* 10FA64 7F0DAF34 01AA4825 */  or    $t1, $t5, $t2
/* 10FA68 7F0DAF38 00187180 */  sll   $t6, $t8, 6
/* 10FA6C 7F0DAF3C 012E5825 */  or    $t3, $t1, $t6
/* 10FA70 7F0DAF40 032B8825 */  or    $s1, $t9, $t3
/* 10FA74 7F0DAF44 323800FF */  andi  $t8, $s1, 0xff
/* 10FA78 7F0DAF48 10000593 */  b     .L7F0DC598
/* 10FA7C 7F0DAF4C 03008825 */   move  $s1, $t8
spectrum_op_CB_1B:
/* 10FA80 7F0DAF50 32AF0001 */  andi  $t7, $s5, 1
/* 10FA84 7F0DAF54 00155043 */  sra   $t2, $s5, 1
/* 10FA88 7F0DAF58 001141C0 */  sll   $t0, $s1, 7
/* 10FA8C 7F0DAF5C 0148A825 */  or    $s5, $t2, $t0
/* 10FA90 7F0DAF60 32A900FF */  andi  $t1, $s5, 0xff
/* 10FA94 7F0DAF64 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FA98 7F0DAF68 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 10FA9C 7F0DAF6C 2D2E0001 */  sltiu $t6, $t1, 1
/* 10FAA0 7F0DAF70 AFAE0048 */  sw    $t6, 0x48($sp)
/* 10FAA4 7F0DAF74 0120A825 */  move  $s5, $t1
/* 10FAA8 7F0DAF78 312C00A8 */  andi  $t4, $t1, 0xa8
/* 10FAAC 7F0DAF7C A3AF0125 */  sb    $t7, 0x125($sp)
/* 10FAB0 7F0DAF80 012A4021 */  addu  $t0, $t1, $t2
/* 10FAB4 7F0DAF84 91090000 */  lbu   $t1, ($t0)
/* 10FAB8 7F0DAF88 01ECC825 */  or    $t9, $t7, $t4
/* 10FABC 7F0DAF8C 000EC180 */  sll   $t8, $t6, 6
/* 10FAC0 7F0DAF90 03386825 */  or    $t5, $t9, $t8
/* 10FAC4 7F0DAF94 012D8825 */  or    $s1, $t1, $t5
/* 10FAC8 7F0DAF98 322E00FF */  andi  $t6, $s1, 0xff
/* 10FACC 7F0DAF9C 1000057E */  b     .L7F0DC598
/* 10FAD0 7F0DAFA0 01C08825 */   move  $s1, $t6
spectrum_op_CB_1C:
/* 10FAD4 7F0DAFA4 32CA0001 */  andi  $t2, $s6, 1
/* 10FAD8 7F0DAFA8 00166043 */  sra   $t4, $s6, 1
/* 10FADC 7F0DAFAC 001159C0 */  sll   $t3, $s1, 7
/* 10FAE0 7F0DAFB0 018BB025 */  or    $s6, $t4, $t3
/* 10FAE4 7F0DAFB4 32D900FF */  andi  $t9, $s6, 0xff
/* 10FAE8 7F0DAFB8 3C0C8009 */  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FAEC 7F0DAFBC 8D8CE334 */  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
/* 10FAF0 7F0DAFC0 2F380001 */  sltiu $t8, $t9, 1
/* 10FAF4 7F0DAFC4 AFB80048 */  sw    $t8, 0x48($sp)
/* 10FAF8 7F0DAFC8 0320B025 */  move  $s6, $t9
/* 10FAFC 7F0DAFCC 332800A8 */  andi  $t0, $t9, 0xa8
/* 10FB00 7F0DAFD0 A3AA0124 */  sb    $t2, 0x124($sp)
/* 10FB04 7F0DAFD4 032C5821 */  addu  $t3, $t9, $t4
/* 10FB08 7F0DAFD8 91790000 */  lbu   $t9, ($t3)
/* 10FB0C 7F0DAFDC 01484825 */  or    $t1, $t2, $t0
/* 10FB10 7F0DAFE0 00187180 */  sll   $t6, $t8, 6
/* 10FB14 7F0DAFE4 012E7825 */  or    $t7, $t1, $t6
/* 10FB18 7F0DAFE8 032F8825 */  or    $s1, $t9, $t7
/* 10FB1C 7F0DAFEC 323800FF */  andi  $t8, $s1, 0xff
/* 10FB20 7F0DAFF0 10000569 */  b     .L7F0DC598
/* 10FB24 7F0DAFF4 03008825 */   move  $s1, $t8
spectrum_op_CB_1D:
/* 10FB28 7F0DAFF8 32EC0001 */  andi  $t4, $s7, 1
/* 10FB2C 7F0DAFFC 00174043 */  sra   $t0, $s7, 1
/* 10FB30 7F0DB000 001169C0 */  sll   $t5, $s1, 7
/* 10FB34 7F0DB004 010DB825 */  or    $s7, $t0, $t5
/* 10FB38 7F0DB008 32E900FF */  andi  $t1, $s7, 0xff
/* 10FB3C 7F0DB00C 3C088009 */  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FB40 7F0DB010 8D08E334 */  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
/* 10FB44 7F0DB014 2D2E0001 */  sltiu $t6, $t1, 1
/* 10FB48 7F0DB018 AFAE0048 */  sw    $t6, 0x48($sp)
/* 10FB4C 7F0DB01C 0120B825 */  move  $s7, $t1
/* 10FB50 7F0DB020 312B00A8 */  andi  $t3, $t1, 0xa8
/* 10FB54 7F0DB024 A3AC0123 */  sb    $t4, 0x123($sp)
/* 10FB58 7F0DB028 01286821 */  addu  $t5, $t1, $t0
/* 10FB5C 7F0DB02C 91A90000 */  lbu   $t1, ($t5)
/* 10FB60 7F0DB030 018BC825 */  or    $t9, $t4, $t3
/* 10FB64 7F0DB034 000EC180 */  sll   $t8, $t6, 6
/* 10FB68 7F0DB038 03385025 */  or    $t2, $t9, $t8
/* 10FB6C 7F0DB03C 012A8825 */  or    $s1, $t1, $t2
/* 10FB70 7F0DB040 322E00FF */  andi  $t6, $s1, 0xff
/* 10FB74 7F0DB044 10000554 */  b     .L7F0DC598
/* 10FB78 7F0DB048 01C08825 */   move  $s1, $t6
spectrum_op_CB_1E:
/* 10FB7C 7F0DB04C 8FAC028C */  lw    $t4, 0x28c($sp)
/* 10FB80 7F0DB050 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 10FB84 7F0DB054 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 10FB88 7F0DB058 97AF013C */  lhu   $t7, 0x13c($sp)
/* 10FB8C 7F0DB05C 258B0007 */  addiu $t3, $t4, 7
/* 10FB90 7F0DB060 AFAB028C */  sw    $t3, 0x28c($sp)
/* 10FB94 7F0DB064 01F9C021 */  addu  $t8, $t7, $t9
/* 10FB98 7F0DB068 93080000 */  lbu   $t0, ($t8)
/* 10FB9C 7F0DB06C 001171C0 */  sll   $t6, $s1, 7
/* 10FBA0 7F0DB070 310D00FF */  andi  $t5, $t0, 0xff
/* 10FBA4 7F0DB074 000D5043 */  sra   $t2, $t5, 1
/* 10FBA8 7F0DB078 014E6025 */  or    $t4, $t2, $t6
/* 10FBAC 7F0DB07C 3C0E8009 */  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FBB0 7F0DB080 8DCEE334 */  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
/* 10FBB4 7F0DB084 31B90001 */  andi  $t9, $t5, 1
/* 10FBB8 7F0DB088 318B00FF */  andi  $t3, $t4, 0xff
/* 10FBBC 7F0DB08C A3A80139 */  sb    $t0, 0x139($sp)
/* 10FBC0 7F0DB090 318800A8 */  andi  $t0, $t4, 0xa8
/* 10FBC4 7F0DB094 2D6F0001 */  sltiu $t7, $t3, 1
/* 10FBC8 7F0DB098 AFAF0048 */  sw    $t7, 0x48($sp)
/* 10FBCC 7F0DB09C 03284825 */  or    $t1, $t9, $t0
/* 10FBD0 7F0DB0A0 A3AC0139 */  sb    $t4, 0x139($sp)
/* 10FBD4 7F0DB0A4 A3B90122 */  sb    $t9, 0x122($sp)
/* 10FBD8 7F0DB0A8 016EC021 */  addu  $t8, $t3, $t6
/* 10FBDC 7F0DB0AC 93190000 */  lbu   $t9, ($t8)
/* 10FBE0 7F0DB0B0 000F6980 */  sll   $t5, $t7, 6
/* 10FBE4 7F0DB0B4 97AF013C */  lhu   $t7, 0x13c($sp)
/* 10FBE8 7F0DB0B8 012D5025 */  or    $t2, $t1, $t5
/* 10FBEC 7F0DB0BC 032A8825 */  or    $s1, $t9, $t2
/* 10FBF0 7F0DB0C0 322800FF */  andi  $t0, $s1, 0xff
/* 10FBF4 7F0DB0C4 29E15B00 */  slti  $at, $t7, 0x5b00
/* 10FBF8 7F0DB0C8 14200007 */  bnez  $at, .L7F0DB0E8
/* 10FBFC 7F0DB0CC 01008825 */   move  $s1, $t0
/* 10FC00 7F0DB0D0 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 10FC04 7F0DB0D4 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 10FC08 7F0DB0D8 01804825 */  move  $t1, $t4
/* 10FC0C 7F0DB0DC 01AF6021 */  addu  $t4, $t5, $t7
/* 10FC10 7F0DB0E0 1000052D */  b     .L7F0DC598
/* 10FC14 7F0DB0E4 A1890000 */   sb    $t1, ($t4)
.L7F0DB0E8:
/* 10FC18 7F0DB0E8 97AB013C */  lhu   $t3, 0x13c($sp)
/* 10FC1C 7F0DB0EC 97A9013C */  lhu   $t1, 0x13c($sp)
/* 10FC20 7F0DB0F0 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 10FC24 7F0DB0F4 29615800 */  slti  $at, $t3, 0x5800
/* 10FC28 7F0DB0F8 5420000D */  bnezl $at, .L7F0DB130
/* 10FC2C 7F0DB0FC 29214000 */   slti  $at, $t1, 0x4000
/* 10FC30 7F0DB100 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10FC34 7F0DB104 93AE0139 */  lbu   $t6, 0x139($sp)
/* 10FC38 7F0DB108 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 10FC3C 7F0DB10C 030BC821 */  addu  $t9, $t8, $t3
/* 10FC40 7F0DB110 A32E0000 */  sb    $t6, ($t9)
/* 10FC44 7F0DB114 97AD013C */  lhu   $t5, 0x13c($sp)
/* 10FC48 7F0DB118 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 10FC4C 7F0DB11C 240A0001 */  li    $t2, 1
/* 10FC50 7F0DB120 010D7821 */  addu  $t7, $t0, $t5
/* 10FC54 7F0DB124 1000051C */  b     .L7F0DC598
/* 10FC58 7F0DB128 A1EAA800 */   sb    $t2, -0x5800($t7)
/* 10FC5C 7F0DB12C 29214000 */  slti  $at, $t1, 0x4000
.L7F0DB130:
/* 10FC60 7F0DB130 14200519 */  bnez  $at, .L7F0DC598
/* 10FC64 7F0DB134 3C188009 */   lui   $t8, %hi(ptr_spectrum_roms) 
/* 10FC68 7F0DB138 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 10FC6C 7F0DB13C 93AC0139 */  lbu   $t4, 0x139($sp)
/* 10FC70 7F0DB140 240E0001 */  li    $t6, 1
/* 10FC74 7F0DB144 03095821 */  addu  $t3, $t8, $t1
/* 10FC78 7F0DB148 A16C0000 */  sb    $t4, ($t3)
/* 10FC7C 7F0DB14C 97B9013C */  lhu   $t9, 0x13c($sp)
/* 10FC80 7F0DB150 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 10FC84 7F0DB154 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 10FC88 7F0DB158 33281800 */  andi  $t0, $t9, 0x1800
/* 10FC8C 7F0DB15C 000868C3 */  sra   $t5, $t0, 3
/* 10FC90 7F0DB160 332A00FF */  andi  $t2, $t9, 0xff
/* 10FC94 7F0DB164 01AA7825 */  or    $t7, $t5, $t2
/* 10FC98 7F0DB168 030F4821 */  addu  $t1, $t8, $t7
/* 10FC9C 7F0DB16C 1000050A */  b     .L7F0DC598
/* 10FCA0 7F0DB170 A12E0000 */   sb    $t6, ($t1)
spectrum_op_CB_1F:
/* 10FCA4 7F0DB174 320A0001 */  andi  $t2, $s0, 1
/* 10FCA8 7F0DB178 00105843 */  sra   $t3, $s0, 1
/* 10FCAC 7F0DB17C 001141C0 */  sll   $t0, $s1, 7
/* 10FCB0 7F0DB180 01688025 */  or    $s0, $t3, $t0
/* 10FCB4 7F0DB184 321900FF */  andi  $t9, $s0, 0xff
/* 10FCB8 7F0DB188 3C0B8009 */  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FCBC 7F0DB18C 8D6BE334 */  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
/* 10FCC0 7F0DB190 2F2D0001 */  sltiu $t5, $t9, 1
/* 10FCC4 7F0DB194 AFAD0048 */  sw    $t5, 0x48($sp)
/* 10FCC8 7F0DB198 03208025 */  move  $s0, $t9
/* 10FCCC 7F0DB19C 333800A8 */  andi  $t8, $t9, 0xa8
/* 10FCD0 7F0DB1A0 A3AA0121 */  sb    $t2, 0x121($sp)
/* 10FCD4 7F0DB1A4 032B4021 */  addu  $t0, $t9, $t3
/* 10FCD8 7F0DB1A8 91190000 */  lbu   $t9, ($t0)
/* 10FCDC 7F0DB1AC 01587825 */  or    $t7, $t2, $t8
/* 10FCE0 7F0DB1B0 000D4980 */  sll   $t1, $t5, 6
/* 10FCE4 7F0DB1B4 01E96025 */  or    $t4, $t7, $t1
/* 10FCE8 7F0DB1B8 032C8825 */  or    $s1, $t9, $t4
/* 10FCEC 7F0DB1BC 322D00FF */  andi  $t5, $s1, 0xff
/* 10FCF0 7F0DB1C0 100004F5 */  b     .L7F0DC598
/* 10FCF4 7F0DB1C4 01A08825 */   move  $s1, $t5
spectrum_op_CB_20:
/* 10FCF8 7F0DB1C8 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FCFC 7F0DB1CC 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 10FD00 7F0DB1D0 001249C3 */  sra   $t1, $s2, 7
/* 10FD04 7F0DB1D4 0012C040 */  sll   $t8, $s2, 1
/* 10FD08 7F0DB1D8 331200FF */  andi  $s2, $t8, 0xff
/* 10FD0C 7F0DB1DC 2E4F0001 */  sltiu $t7, $s2, 1
/* 10FD10 7F0DB1E0 AFAF0048 */  sw    $t7, 0x48($sp)
/* 10FD14 7F0DB1E4 A3A90120 */  sb    $t1, 0x120($sp)
/* 10FD18 7F0DB1E8 024AC021 */  addu  $t8, $s2, $t2
/* 10FD1C 7F0DB1EC 930E0000 */  lbu   $t6, ($t8)
/* 10FD20 7F0DB1F0 324B00A8 */  andi  $t3, $s2, 0xa8
/* 10FD24 7F0DB1F4 012B4025 */  or    $t0, $t1, $t3
/* 10FD28 7F0DB1F8 000F6180 */  sll   $t4, $t7, 6
/* 10FD2C 7F0DB1FC 010C6825 */  or    $t5, $t0, $t4
/* 10FD30 7F0DB200 01CD8825 */  or    $s1, $t6, $t5
/* 10FD34 7F0DB204 322F00FF */  andi  $t7, $s1, 0xff
/* 10FD38 7F0DB208 100004E3 */  b     .L7F0DC598
/* 10FD3C 7F0DB20C 01E08825 */   move  $s1, $t7
spectrum_op_CB_21:
/* 10FD40 7F0DB210 3C098009 */  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FD44 7F0DB214 8D29E334 */  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
/* 10FD48 7F0DB218 001361C3 */  sra   $t4, $s3, 7
/* 10FD4C 7F0DB21C 00135840 */  sll   $t3, $s3, 1
/* 10FD50 7F0DB220 317300FF */  andi  $s3, $t3, 0xff
/* 10FD54 7F0DB224 2E680001 */  sltiu $t0, $s3, 1
/* 10FD58 7F0DB228 AFA80048 */  sw    $t0, 0x48($sp)
/* 10FD5C 7F0DB22C A3AC011F */  sb    $t4, 0x11f($sp)
/* 10FD60 7F0DB230 02695821 */  addu  $t3, $s3, $t1
/* 10FD64 7F0DB234 91790000 */  lbu   $t9, ($t3)
/* 10FD68 7F0DB238 326A00A8 */  andi  $t2, $s3, 0xa8
/* 10FD6C 7F0DB23C 018AC025 */  or    $t8, $t4, $t2
/* 10FD70 7F0DB240 00086980 */  sll   $t5, $t0, 6
/* 10FD74 7F0DB244 030D7825 */  or    $t7, $t8, $t5
/* 10FD78 7F0DB248 032F8825 */  or    $s1, $t9, $t7
/* 10FD7C 7F0DB24C 322800FF */  andi  $t0, $s1, 0xff
/* 10FD80 7F0DB250 100004D1 */  b     .L7F0DC598
/* 10FD84 7F0DB254 01008825 */   move  $s1, $t0
spectrum_op_CB_22:
/* 10FD88 7F0DB258 3C0C8009 */  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FD8C 7F0DB25C 8D8CE334 */  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
/* 10FD90 7F0DB260 001469C3 */  sra   $t5, $s4, 7
/* 10FD94 7F0DB264 00145040 */  sll   $t2, $s4, 1
/* 10FD98 7F0DB268 315400FF */  andi  $s4, $t2, 0xff
/* 10FD9C 7F0DB26C 2E980001 */  sltiu $t8, $s4, 1
/* 10FDA0 7F0DB270 AFB80048 */  sw    $t8, 0x48($sp)
/* 10FDA4 7F0DB274 A3AD011E */  sb    $t5, 0x11e($sp)
/* 10FDA8 7F0DB278 028C5021 */  addu  $t2, $s4, $t4
/* 10FDAC 7F0DB27C 914E0000 */  lbu   $t6, ($t2)
/* 10FDB0 7F0DB280 328900A8 */  andi  $t1, $s4, 0xa8
/* 10FDB4 7F0DB284 01A95825 */  or    $t3, $t5, $t1
/* 10FDB8 7F0DB288 00187980 */  sll   $t7, $t8, 6
/* 10FDBC 7F0DB28C 016F4025 */  or    $t0, $t3, $t7
/* 10FDC0 7F0DB290 01C88825 */  or    $s1, $t6, $t0
/* 10FDC4 7F0DB294 323800FF */  andi  $t8, $s1, 0xff
/* 10FDC8 7F0DB298 100004BF */  b     .L7F0DC598
/* 10FDCC 7F0DB29C 03008825 */   move  $s1, $t8
spectrum_op_CB_23:
/* 10FDD0 7F0DB2A0 3C0D8009 */  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FDD4 7F0DB2A4 8DADE334 */  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
/* 10FDD8 7F0DB2A8 001579C3 */  sra   $t7, $s5, 7
/* 10FDDC 7F0DB2AC 00154840 */  sll   $t1, $s5, 1
/* 10FDE0 7F0DB2B0 313500FF */  andi  $s5, $t1, 0xff
/* 10FDE4 7F0DB2B4 2EAB0001 */  sltiu $t3, $s5, 1
/* 10FDE8 7F0DB2B8 AFAB0048 */  sw    $t3, 0x48($sp)
/* 10FDEC 7F0DB2BC A3AF011D */  sb    $t7, 0x11d($sp)
/* 10FDF0 7F0DB2C0 02AD4821 */  addu  $t1, $s5, $t5
/* 10FDF4 7F0DB2C4 91390000 */  lbu   $t9, ($t1)
/* 10FDF8 7F0DB2C8 32AC00A8 */  andi  $t4, $s5, 0xa8
/* 10FDFC 7F0DB2CC 01EC5025 */  or    $t2, $t7, $t4
/* 10FE00 7F0DB2D0 000B4180 */  sll   $t0, $t3, 6
/* 10FE04 7F0DB2D4 0148C025 */  or    $t8, $t2, $t0
/* 10FE08 7F0DB2D8 03388825 */  or    $s1, $t9, $t8
/* 10FE0C 7F0DB2DC 322B00FF */  andi  $t3, $s1, 0xff
/* 10FE10 7F0DB2E0 100004AD */  b     .L7F0DC598
/* 10FE14 7F0DB2E4 01608825 */   move  $s1, $t3
spectrum_op_CB_24:
/* 10FE18 7F0DB2E8 3C0F8009 */  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FE1C 7F0DB2EC 8DEFE334 */  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
/* 10FE20 7F0DB2F0 001641C3 */  sra   $t0, $s6, 7
/* 10FE24 7F0DB2F4 00166040 */  sll   $t4, $s6, 1
/* 10FE28 7F0DB2F8 319600FF */  andi  $s6, $t4, 0xff
/* 10FE2C 7F0DB2FC 2ECA0001 */  sltiu $t2, $s6, 1
/* 10FE30 7F0DB300 AFAA0048 */  sw    $t2, 0x48($sp)
/* 10FE34 7F0DB304 A3A8011C */  sb    $t0, 0x11c($sp)
/* 10FE38 7F0DB308 02CF6021 */  addu  $t4, $s6, $t7
/* 10FE3C 7F0DB30C 918E0000 */  lbu   $t6, ($t4)
/* 10FE40 7F0DB310 32CD00A8 */  andi  $t5, $s6, 0xa8
/* 10FE44 7F0DB314 010D4825 */  or    $t1, $t0, $t5
/* 10FE48 7F0DB318 000AC180 */  sll   $t8, $t2, 6
/* 10FE4C 7F0DB31C 01385825 */  or    $t3, $t1, $t8
/* 10FE50 7F0DB320 01CB8825 */  or    $s1, $t6, $t3
/* 10FE54 7F0DB324 322A00FF */  andi  $t2, $s1, 0xff
/* 10FE58 7F0DB328 1000049B */  b     .L7F0DC598
/* 10FE5C 7F0DB32C 01408825 */   move  $s1, $t2
spectrum_op_CB_25:
/* 10FE60 7F0DB330 3C088009 */  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FE64 7F0DB334 8D08E334 */  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
/* 10FE68 7F0DB338 0017C1C3 */  sra   $t8, $s7, 7
/* 10FE6C 7F0DB33C 00176840 */  sll   $t5, $s7, 1
/* 10FE70 7F0DB340 31B700FF */  andi  $s7, $t5, 0xff
/* 10FE74 7F0DB344 2EE90001 */  sltiu $t1, $s7, 1
/* 10FE78 7F0DB348 AFA90048 */  sw    $t1, 0x48($sp)
/* 10FE7C 7F0DB34C A3B8011B */  sb    $t8, 0x11b($sp)
/* 10FE80 7F0DB350 02E86821 */  addu  $t5, $s7, $t0
/* 10FE84 7F0DB354 91B90000 */  lbu   $t9, ($t5)
/* 10FE88 7F0DB358 32EF00A8 */  andi  $t7, $s7, 0xa8
/* 10FE8C 7F0DB35C 030F6025 */  or    $t4, $t8, $t7
/* 10FE90 7F0DB360 00095980 */  sll   $t3, $t1, 6
/* 10FE94 7F0DB364 018B5025 */  or    $t2, $t4, $t3
/* 10FE98 7F0DB368 032A8825 */  or    $s1, $t9, $t2
/* 10FE9C 7F0DB36C 322900FF */  andi  $t1, $s1, 0xff
/* 10FEA0 7F0DB370 10000489 */  b     .L7F0DC598
/* 10FEA4 7F0DB374 01208825 */   move  $s1, $t1
spectrum_op_CB_26:
/* 10FEA8 7F0DB378 8FB8028C */  lw    $t8, 0x28c($sp)
/* 10FEAC 7F0DB37C 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 10FEB0 7F0DB380 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 10FEB4 7F0DB384 97AE013C */  lhu   $t6, 0x13c($sp)
/* 10FEB8 7F0DB388 270F0007 */  addiu $t7, $t8, 7
/* 10FEBC 7F0DB38C AFAF028C */  sw    $t7, 0x28c($sp)
/* 10FEC0 7F0DB390 01CC5821 */  addu  $t3, $t6, $t4
/* 10FEC4 7F0DB394 91680000 */  lbu   $t0, ($t3)
/* 10FEC8 7F0DB398 310D00FF */  andi  $t5, $t0, 0xff
/* 10FECC 7F0DB39C 000D79C3 */  sra   $t7, $t5, 7
/* 10FED0 7F0DB3A0 000D5040 */  sll   $t2, $t5, 1
/* 10FED4 7F0DB3A4 3C0D8009 */  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FED8 7F0DB3A8 8DADE334 */  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
/* 10FEDC 7F0DB3AC 314900FF */  andi  $t1, $t2, 0xff
/* 10FEE0 7F0DB3B0 A3A80139 */  sb    $t0, 0x139($sp)
/* 10FEE4 7F0DB3B4 2D380001 */  sltiu $t8, $t1, 1
/* 10FEE8 7F0DB3B8 314C00A8 */  andi  $t4, $t2, 0xa8
/* 10FEEC 7F0DB3BC 01EC5825 */  or    $t3, $t7, $t4
/* 10FEF0 7F0DB3C0 AFB80048 */  sw    $t8, 0x48($sp)
/* 10FEF4 7F0DB3C4 A3AA0139 */  sb    $t2, 0x139($sp)
/* 10FEF8 7F0DB3C8 A3AF011A */  sb    $t7, 0x11a($sp)
/* 10FEFC 7F0DB3CC 012D7021 */  addu  $t6, $t1, $t5
/* 10FF00 7F0DB3D0 91CF0000 */  lbu   $t7, ($t6)
/* 10FF04 7F0DB3D4 00184180 */  sll   $t0, $t8, 6
/* 10FF08 7F0DB3D8 97B8013C */  lhu   $t8, 0x13c($sp)
/* 10FF0C 7F0DB3DC 0168C825 */  or    $t9, $t3, $t0
/* 10FF10 7F0DB3E0 01F98825 */  or    $s1, $t7, $t9
/* 10FF14 7F0DB3E4 322C00FF */  andi  $t4, $s1, 0xff
/* 10FF18 7F0DB3E8 2B015B00 */  slti  $at, $t8, 0x5b00
/* 10FF1C 7F0DB3EC 14200007 */  bnez  $at, .L7F0DB40C
/* 10FF20 7F0DB3F0 01808825 */   move  $s1, $t4
/* 10FF24 7F0DB3F4 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 10FF28 7F0DB3F8 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 10FF2C 7F0DB3FC 01405825 */  move  $t3, $t2
/* 10FF30 7F0DB400 01185021 */  addu  $t2, $t0, $t8
/* 10FF34 7F0DB404 10000464 */  b     .L7F0DC598
/* 10FF38 7F0DB408 A14B0000 */   sb    $t3, ($t2)
.L7F0DB40C:
/* 10FF3C 7F0DB40C 97A9013C */  lhu   $t1, 0x13c($sp)
/* 10FF40 7F0DB410 97AB013C */  lhu   $t3, 0x13c($sp)
/* 10FF44 7F0DB414 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 10FF48 7F0DB418 29215800 */  slti  $at, $t1, 0x5800
/* 10FF4C 7F0DB41C 5420000D */  bnezl $at, .L7F0DB454
/* 10FF50 7F0DB420 29614000 */   slti  $at, $t3, 0x4000
/* 10FF54 7F0DB424 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10FF58 7F0DB428 93AD0139 */  lbu   $t5, 0x139($sp)
/* 10FF5C 7F0DB42C 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 10FF60 7F0DB430 01C97821 */  addu  $t7, $t6, $t1
/* 10FF64 7F0DB434 A1ED0000 */  sb    $t5, ($t7)
/* 10FF68 7F0DB438 97A8013C */  lhu   $t0, 0x13c($sp)
/* 10FF6C 7F0DB43C 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 10FF70 7F0DB440 24190001 */  li    $t9, 1
/* 10FF74 7F0DB444 0188C021 */  addu  $t8, $t4, $t0
/* 10FF78 7F0DB448 10000453 */  b     .L7F0DC598
/* 10FF7C 7F0DB44C A319A800 */   sb    $t9, -0x5800($t8)
/* 10FF80 7F0DB450 29614000 */  slti  $at, $t3, 0x4000
.L7F0DB454:
/* 10FF84 7F0DB454 14200450 */  bnez  $at, .L7F0DC598
/* 10FF88 7F0DB458 3C0E8009 */   lui   $t6, %hi(ptr_spectrum_roms) 
/* 10FF8C 7F0DB45C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 10FF90 7F0DB460 93AA0139 */  lbu   $t2, 0x139($sp)
/* 10FF94 7F0DB464 240D0001 */  li    $t5, 1
/* 10FF98 7F0DB468 01CB4821 */  addu  $t1, $t6, $t3
/* 10FF9C 7F0DB46C A12A0000 */  sb    $t2, ($t1)
/* 10FFA0 7F0DB470 97AF013C */  lhu   $t7, 0x13c($sp)
/* 10FFA4 7F0DB474 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 10FFA8 7F0DB478 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 10FFAC 7F0DB47C 31EC1800 */  andi  $t4, $t7, 0x1800
/* 10FFB0 7F0DB480 000C40C3 */  sra   $t0, $t4, 3
/* 10FFB4 7F0DB484 31F900FF */  andi  $t9, $t7, 0xff
/* 10FFB8 7F0DB488 0119C025 */  or    $t8, $t0, $t9
/* 10FFBC 7F0DB48C 01D85821 */  addu  $t3, $t6, $t8
/* 10FFC0 7F0DB490 10000441 */  b     .L7F0DC598
/* 10FFC4 7F0DB494 A16D0000 */   sb    $t5, ($t3)
spectrum_op_CB_27:
/* 10FFC8 7F0DB498 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 10FFCC 7F0DB49C 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 10FFD0 7F0DB4A0 001041C3 */  sra   $t0, $s0, 7
/* 10FFD4 7F0DB4A4 00104840 */  sll   $t1, $s0, 1
/* 10FFD8 7F0DB4A8 313000FF */  andi  $s0, $t1, 0xff
/* 10FFDC 7F0DB4AC 2E0F0001 */  sltiu $t7, $s0, 1
/* 10FFE0 7F0DB4B0 AFAF0048 */  sw    $t7, 0x48($sp)
/* 10FFE4 7F0DB4B4 A3A80119 */  sb    $t0, 0x119($sp)
/* 10FFE8 7F0DB4B8 020A4821 */  addu  $t1, $s0, $t2
/* 10FFEC 7F0DB4BC 912C0000 */  lbu   $t4, ($t1)
/* 10FFF0 7F0DB4C0 321900A8 */  andi  $t9, $s0, 0xa8
/* 10FFF4 7F0DB4C4 01197025 */  or    $t6, $t0, $t9
/* 10FFF8 7F0DB4C8 000F6980 */  sll   $t5, $t7, 6
/* 10FFFC 7F0DB4CC 01CD5825 */  or    $t3, $t6, $t5
/* 110000 7F0DB4D0 018B8825 */  or    $s1, $t4, $t3
/* 110004 7F0DB4D4 322F00FF */  andi  $t7, $s1, 0xff
/* 110008 7F0DB4D8 1000042F */  b     .L7F0DC598
/* 11000C 7F0DB4DC 01E08825 */   move  $s1, $t7
spectrum_op_CB_28:
/* 110010 7F0DB4E0 0012CE00 */  sll   $t9, $s2, 0x18
/* 110014 7F0DB4E4 0019C603 */  sra   $t8, $t9, 0x18
/* 110018 7F0DB4E8 00187043 */  sra   $t6, $t8, 1
/* 11001C 7F0DB4EC 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 110020 7F0DB4F0 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 110024 7F0DB4F4 32490001 */  andi  $t1, $s2, 1
/* 110028 7F0DB4F8 31D200FF */  andi  $s2, $t6, 0xff
/* 11002C 7F0DB4FC 2E4A0001 */  sltiu $t2, $s2, 1
/* 110030 7F0DB500 AFAA0048 */  sw    $t2, 0x48($sp)
/* 110034 7F0DB504 A3A90118 */  sb    $t1, 0x118($sp)
/* 110038 7F0DB508 02587021 */  addu  $t6, $s2, $t8
/* 11003C 7F0DB50C 91CD0000 */  lbu   $t5, ($t6)
/* 110040 7F0DB510 324C00A8 */  andi  $t4, $s2, 0xa8
/* 110044 7F0DB514 012C5825 */  or    $t3, $t1, $t4
/* 110048 7F0DB518 000A4180 */  sll   $t0, $t2, 6
/* 11004C 7F0DB51C 0168C825 */  or    $t9, $t3, $t0
/* 110050 7F0DB520 01B98825 */  or    $s1, $t5, $t9
/* 110054 7F0DB524 322A00FF */  andi  $t2, $s1, 0xff
/* 110058 7F0DB528 1000041B */  b     .L7F0DC598
/* 11005C 7F0DB52C 01408825 */   move  $s1, $t2
spectrum_op_CB_29:
/* 110060 7F0DB530 00136600 */  sll   $t4, $s3, 0x18
/* 110064 7F0DB534 000C7E03 */  sra   $t7, $t4, 0x18
/* 110068 7F0DB538 000F5843 */  sra   $t3, $t7, 1
/* 11006C 7F0DB53C 3C0F8009 */  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
/* 110070 7F0DB540 8DEFE334 */  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
/* 110074 7F0DB544 326E0001 */  andi  $t6, $s3, 1
/* 110078 7F0DB548 317300FF */  andi  $s3, $t3, 0xff
/* 11007C 7F0DB54C 2E780001 */  sltiu $t8, $s3, 1
/* 110080 7F0DB550 AFB80048 */  sw    $t8, 0x48($sp)
/* 110084 7F0DB554 A3AE0117 */  sb    $t6, 0x117($sp)
/* 110088 7F0DB558 026F5821 */  addu  $t3, $s3, $t7
/* 11008C 7F0DB55C 91680000 */  lbu   $t0, ($t3)
/* 110090 7F0DB560 326D00A8 */  andi  $t5, $s3, 0xa8
/* 110094 7F0DB564 01CDC825 */  or    $t9, $t6, $t5
/* 110098 7F0DB568 00184980 */  sll   $t1, $t8, 6
/* 11009C 7F0DB56C 03296025 */  or    $t4, $t9, $t1
/* 1100A0 7F0DB570 010C8825 */  or    $s1, $t0, $t4
/* 1100A4 7F0DB574 323800FF */  andi  $t8, $s1, 0xff
/* 1100A8 7F0DB578 10000407 */  b     .L7F0DC598
/* 1100AC 7F0DB57C 03008825 */   move  $s1, $t8
spectrum_op_CB_2A:
/* 1100B0 7F0DB580 00146E00 */  sll   $t5, $s4, 0x18
/* 1100B4 7F0DB584 000D5603 */  sra   $t2, $t5, 0x18
/* 1100B8 7F0DB588 000AC843 */  sra   $t9, $t2, 1
/* 1100BC 7F0DB58C 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 1100C0 7F0DB590 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 1100C4 7F0DB594 328B0001 */  andi  $t3, $s4, 1
/* 1100C8 7F0DB598 333400FF */  andi  $s4, $t9, 0xff
/* 1100CC 7F0DB59C 2E8F0001 */  sltiu $t7, $s4, 1
/* 1100D0 7F0DB5A0 AFAF0048 */  sw    $t7, 0x48($sp)
/* 1100D4 7F0DB5A4 A3AB0116 */  sb    $t3, 0x116($sp)
/* 1100D8 7F0DB5A8 028AC821 */  addu  $t9, $s4, $t2
/* 1100DC 7F0DB5AC 93290000 */  lbu   $t1, ($t9)
/* 1100E0 7F0DB5B0 328800A8 */  andi  $t0, $s4, 0xa8
/* 1100E4 7F0DB5B4 01686025 */  or    $t4, $t3, $t0
/* 1100E8 7F0DB5B8 000F7180 */  sll   $t6, $t7, 6
/* 1100EC 7F0DB5BC 018E6825 */  or    $t5, $t4, $t6
/* 1100F0 7F0DB5C0 012D8825 */  or    $s1, $t1, $t5
/* 1100F4 7F0DB5C4 322F00FF */  andi  $t7, $s1, 0xff
/* 1100F8 7F0DB5C8 100003F3 */  b     .L7F0DC598
/* 1100FC 7F0DB5CC 01E08825 */   move  $s1, $t7
spectrum_op_CB_2B:
/* 110100 7F0DB5D0 00154600 */  sll   $t0, $s5, 0x18
/* 110104 7F0DB5D4 0008C603 */  sra   $t8, $t0, 0x18
/* 110108 7F0DB5D8 00186043 */  sra   $t4, $t8, 1
/* 11010C 7F0DB5DC 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 110110 7F0DB5E0 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 110114 7F0DB5E4 32B90001 */  andi  $t9, $s5, 1
/* 110118 7F0DB5E8 319500FF */  andi  $s5, $t4, 0xff
/* 11011C 7F0DB5EC 2EAA0001 */  sltiu $t2, $s5, 1
/* 110120 7F0DB5F0 AFAA0048 */  sw    $t2, 0x48($sp)
/* 110124 7F0DB5F4 A3B90115 */  sb    $t9, 0x115($sp)
/* 110128 7F0DB5F8 02B86021 */  addu  $t4, $s5, $t8
/* 11012C 7F0DB5FC 918E0000 */  lbu   $t6, ($t4)
/* 110130 7F0DB600 32A900A8 */  andi  $t1, $s5, 0xa8
/* 110134 7F0DB604 03296825 */  or    $t5, $t9, $t1
/* 110138 7F0DB608 000A5980 */  sll   $t3, $t2, 6
/* 11013C 7F0DB60C 01AB4025 */  or    $t0, $t5, $t3
/* 110140 7F0DB610 01C88825 */  or    $s1, $t6, $t0
/* 110144 7F0DB614 322A00FF */  andi  $t2, $s1, 0xff
/* 110148 7F0DB618 100003DF */  b     .L7F0DC598
/* 11014C 7F0DB61C 01408825 */   move  $s1, $t2
spectrum_op_CB_2C:
/* 110150 7F0DB620 00164E00 */  sll   $t1, $s6, 0x18
/* 110154 7F0DB624 00097E03 */  sra   $t7, $t1, 0x18
/* 110158 7F0DB628 000F6843 */  sra   $t5, $t7, 1
/* 11015C 7F0DB62C 3C0F8009 */  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
/* 110160 7F0DB630 8DEFE334 */  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
/* 110164 7F0DB634 32CC0001 */  andi  $t4, $s6, 1
/* 110168 7F0DB638 31B600FF */  andi  $s6, $t5, 0xff
/* 11016C 7F0DB63C 2ED80001 */  sltiu $t8, $s6, 1
/* 110170 7F0DB640 AFB80048 */  sw    $t8, 0x48($sp)
/* 110174 7F0DB644 A3AC0114 */  sb    $t4, 0x114($sp)
/* 110178 7F0DB648 02CF6821 */  addu  $t5, $s6, $t7
/* 11017C 7F0DB64C 91AB0000 */  lbu   $t3, ($t5)
/* 110180 7F0DB650 32CE00A8 */  andi  $t6, $s6, 0xa8
/* 110184 7F0DB654 018E4025 */  or    $t0, $t4, $t6
/* 110188 7F0DB658 0018C980 */  sll   $t9, $t8, 6
/* 11018C 7F0DB65C 01194825 */  or    $t1, $t0, $t9
/* 110190 7F0DB660 01698825 */  or    $s1, $t3, $t1
/* 110194 7F0DB664 323800FF */  andi  $t8, $s1, 0xff
/* 110198 7F0DB668 100003CB */  b     .L7F0DC598
/* 11019C 7F0DB66C 03008825 */   move  $s1, $t8
spectrum_op_CB_2D:
/* 1101A0 7F0DB670 00177600 */  sll   $t6, $s7, 0x18
/* 1101A4 7F0DB674 000E5603 */  sra   $t2, $t6, 0x18
/* 1101A8 7F0DB678 000A4043 */  sra   $t0, $t2, 1
/* 1101AC 7F0DB67C 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 1101B0 7F0DB680 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 1101B4 7F0DB684 32ED0001 */  andi  $t5, $s7, 1
/* 1101B8 7F0DB688 311700FF */  andi  $s7, $t0, 0xff
/* 1101BC 7F0DB68C 2EEF0001 */  sltiu $t7, $s7, 1
/* 1101C0 7F0DB690 AFAF0048 */  sw    $t7, 0x48($sp)
/* 1101C4 7F0DB694 A3AD0113 */  sb    $t5, 0x113($sp)
/* 1101C8 7F0DB698 02EA4021 */  addu  $t0, $s7, $t2
/* 1101CC 7F0DB69C 91190000 */  lbu   $t9, ($t0)
/* 1101D0 7F0DB6A0 32EB00A8 */  andi  $t3, $s7, 0xa8
/* 1101D4 7F0DB6A4 01AB4825 */  or    $t1, $t5, $t3
/* 1101D8 7F0DB6A8 000F6180 */  sll   $t4, $t7, 6
/* 1101DC 7F0DB6AC 012C7025 */  or    $t6, $t1, $t4
/* 1101E0 7F0DB6B0 032E8825 */  or    $s1, $t9, $t6
/* 1101E4 7F0DB6B4 322F00FF */  andi  $t7, $s1, 0xff
/* 1101E8 7F0DB6B8 100003B7 */  b     .L7F0DC598
/* 1101EC 7F0DB6BC 01E08825 */   move  $s1, $t7
spectrum_op_CB_2E:
/* 1101F0 7F0DB6C0 8FAD028C */  lw    $t5, 0x28c($sp)
/* 1101F4 7F0DB6C4 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 1101F8 7F0DB6C8 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 1101FC 7F0DB6CC 97B8013C */  lhu   $t8, 0x13c($sp)
/* 110200 7F0DB6D0 25AB0007 */  addiu $t3, $t5, 7
/* 110204 7F0DB6D4 AFAB028C */  sw    $t3, 0x28c($sp)
/* 110208 7F0DB6D8 03096021 */  addu  $t4, $t8, $t1
/* 11020C 7F0DB6DC 91880000 */  lbu   $t0, ($t4)
/* 110210 7F0DB6E0 A3A80139 */  sb    $t0, 0x139($sp)
/* 110214 7F0DB6E4 83AE0139 */  lb    $t6, 0x139($sp)
/* 110218 7F0DB6E8 31180001 */  andi  $t8, $t0, 1
/* 11021C 7F0DB6EC A3B80112 */  sb    $t8, 0x112($sp)
/* 110220 7F0DB6F0 000E7843 */  sra   $t7, $t6, 1
/* 110224 7F0DB6F4 3C0E8009 */  lui   $t6, %hi(ptr_pc_keyboard_table_alloc) 
/* 110228 7F0DB6F8 8DCEE334 */  lw    $t6, %lo(ptr_pc_keyboard_table_alloc)($t6)
/* 11022C 7F0DB6FC 31ED00FF */  andi  $t5, $t7, 0xff
/* 110230 7F0DB700 2DAB0001 */  sltiu $t3, $t5, 1
/* 110234 7F0DB704 31EC00A8 */  andi  $t4, $t7, 0xa8
/* 110238 7F0DB708 030C5025 */  or    $t2, $t8, $t4
/* 11023C 7F0DB70C AFAB0048 */  sw    $t3, 0x48($sp)
/* 110240 7F0DB710 A3AF0139 */  sb    $t7, 0x139($sp)
/* 110244 7F0DB714 01AE4821 */  addu  $t1, $t5, $t6
/* 110248 7F0DB718 91380000 */  lbu   $t8, ($t1)
/* 11024C 7F0DB71C 000B4180 */  sll   $t0, $t3, 6
/* 110250 7F0DB720 97AB013C */  lhu   $t3, 0x13c($sp)
/* 110254 7F0DB724 0148C825 */  or    $t9, $t2, $t0
/* 110258 7F0DB728 03198825 */  or    $s1, $t8, $t9
/* 11025C 7F0DB72C 322C00FF */  andi  $t4, $s1, 0xff
/* 110260 7F0DB730 29615B00 */  slti  $at, $t3, 0x5b00
/* 110264 7F0DB734 14200007 */  bnez  $at, .L7F0DB754
/* 110268 7F0DB738 01808825 */   move  $s1, $t4
/* 11026C 7F0DB73C 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 110270 7F0DB740 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 110274 7F0DB744 01E05025 */  move  $t2, $t7
/* 110278 7F0DB748 010B7821 */  addu  $t7, $t0, $t3
/* 11027C 7F0DB74C 10000392 */  b     .L7F0DC598
/* 110280 7F0DB750 A1EA0000 */   sb    $t2, ($t7)
.L7F0DB754:
/* 110284 7F0DB754 97AD013C */  lhu   $t5, 0x13c($sp)
/* 110288 7F0DB758 97AA013C */  lhu   $t2, 0x13c($sp)
/* 11028C 7F0DB75C 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 110290 7F0DB760 29A15800 */  slti  $at, $t5, 0x5800
/* 110294 7F0DB764 5420000D */  bnezl $at, .L7F0DB79C
/* 110298 7F0DB768 29414000 */   slti  $at, $t2, 0x4000
/* 11029C 7F0DB76C 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 1102A0 7F0DB770 93AE0139 */  lbu   $t6, 0x139($sp)
/* 1102A4 7F0DB774 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 1102A8 7F0DB778 012DC021 */  addu  $t8, $t1, $t5
/* 1102AC 7F0DB77C A30E0000 */  sb    $t6, ($t8)
/* 1102B0 7F0DB780 97A8013C */  lhu   $t0, 0x13c($sp)
/* 1102B4 7F0DB784 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 1102B8 7F0DB788 24190001 */  li    $t9, 1
/* 1102BC 7F0DB78C 01885821 */  addu  $t3, $t4, $t0
/* 1102C0 7F0DB790 10000381 */  b     .L7F0DC598
/* 1102C4 7F0DB794 A179A800 */   sb    $t9, -0x5800($t3)
/* 1102C8 7F0DB798 29414000 */  slti  $at, $t2, 0x4000
.L7F0DB79C:
/* 1102CC 7F0DB79C 1420037E */  bnez  $at, .L7F0DC598
/* 1102D0 7F0DB7A0 3C098009 */   lui   $t1, %hi(ptr_spectrum_roms) 
/* 1102D4 7F0DB7A4 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 1102D8 7F0DB7A8 93AF0139 */  lbu   $t7, 0x139($sp)
/* 1102DC 7F0DB7AC 240E0001 */  li    $t6, 1
/* 1102E0 7F0DB7B0 012A6821 */  addu  $t5, $t1, $t2
/* 1102E4 7F0DB7B4 A1AF0000 */  sb    $t7, ($t5)
/* 1102E8 7F0DB7B8 97B8013C */  lhu   $t8, 0x13c($sp)
/* 1102EC 7F0DB7BC 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 1102F0 7F0DB7C0 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 1102F4 7F0DB7C4 330C1800 */  andi  $t4, $t8, 0x1800
/* 1102F8 7F0DB7C8 000C40C3 */  sra   $t0, $t4, 3
/* 1102FC 7F0DB7CC 331900FF */  andi  $t9, $t8, 0xff
/* 110300 7F0DB7D0 01195825 */  or    $t3, $t0, $t9
/* 110304 7F0DB7D4 012B5021 */  addu  $t2, $t1, $t3
/* 110308 7F0DB7D8 1000036F */  b     .L7F0DC598
/* 11030C 7F0DB7DC A14E0000 */   sb    $t6, ($t2)
spectrum_op_CB_2F:
/* 110310 7F0DB7E0 00106E00 */  sll   $t5, $s0, 0x18
/* 110314 7F0DB7E4 000D6603 */  sra   $t4, $t5, 0x18
/* 110318 7F0DB7E8 000CC043 */  sra   $t8, $t4, 1
/* 11031C 7F0DB7EC 3C0C8009 */  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
/* 110320 7F0DB7F0 8D8CE334 */  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
/* 110324 7F0DB7F4 32090001 */  andi  $t1, $s0, 1
/* 110328 7F0DB7F8 331000FF */  andi  $s0, $t8, 0xff
/* 11032C 7F0DB7FC 2E190001 */  sltiu $t9, $s0, 1
/* 110330 7F0DB800 AFB90048 */  sw    $t9, 0x48($sp)
/* 110334 7F0DB804 A3A90111 */  sb    $t1, 0x111($sp)
/* 110338 7F0DB808 020CC021 */  addu  $t8, $s0, $t4
/* 11033C 7F0DB80C 93080000 */  lbu   $t0, ($t8)
/* 110340 7F0DB810 320B00A8 */  andi  $t3, $s0, 0xa8
/* 110344 7F0DB814 012B7025 */  or    $t6, $t1, $t3
/* 110348 7F0DB818 00197980 */  sll   $t7, $t9, 6
/* 11034C 7F0DB81C 01CF6825 */  or    $t5, $t6, $t7
/* 110350 7F0DB820 010D8825 */  or    $s1, $t0, $t5
/* 110354 7F0DB824 323900FF */  andi  $t9, $s1, 0xff
/* 110358 7F0DB828 1000035B */  b     .L7F0DC598
/* 11035C 7F0DB82C 03208825 */   move  $s1, $t9
spectrum_op_CB_30:
/* 110360 7F0DB830 00125840 */  sll   $t3, $s2, 1
/* 110364 7F0DB834 356A0001 */  ori   $t2, $t3, 1
/* 110368 7F0DB838 3C0B8009 */  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
/* 11036C 7F0DB83C 8D6BE334 */  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
/* 110370 7F0DB840 001261C3 */  sra   $t4, $s2, 7
/* 110374 7F0DB844 315200FF */  andi  $s2, $t2, 0xff
/* 110378 7F0DB848 2E4F0001 */  sltiu $t7, $s2, 1
/* 11037C 7F0DB84C AFAF0048 */  sw    $t7, 0x48($sp)
/* 110380 7F0DB850 A3AC0110 */  sb    $t4, 0x110($sp)
/* 110384 7F0DB854 024B5021 */  addu  $t2, $s2, $t3
/* 110388 7F0DB858 914E0000 */  lbu   $t6, ($t2)
/* 11038C 7F0DB85C 325800A8 */  andi  $t8, $s2, 0xa8
/* 110390 7F0DB860 01984025 */  or    $t0, $t4, $t8
/* 110394 7F0DB864 000FC980 */  sll   $t9, $t7, 6
/* 110398 7F0DB868 01194825 */  or    $t1, $t0, $t9
/* 11039C 7F0DB86C 01C98825 */  or    $s1, $t6, $t1
/* 1103A0 7F0DB870 322F00FF */  andi  $t7, $s1, 0xff
/* 1103A4 7F0DB874 10000348 */  b     .L7F0DC598
/* 1103A8 7F0DB878 01E08825 */   move  $s1, $t7
spectrum_op_CB_31:
/* 1103AC 7F0DB87C 0013C040 */  sll   $t8, $s3, 1
/* 1103B0 7F0DB880 370D0001 */  ori   $t5, $t8, 1
/* 1103B4 7F0DB884 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 1103B8 7F0DB888 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 1103BC 7F0DB88C 001359C3 */  sra   $t3, $s3, 7
/* 1103C0 7F0DB890 31B300FF */  andi  $s3, $t5, 0xff
/* 1103C4 7F0DB894 2E790001 */  sltiu $t9, $s3, 1
/* 1103C8 7F0DB898 AFB90048 */  sw    $t9, 0x48($sp)
/* 1103CC 7F0DB89C A3AB010F */  sb    $t3, 0x10f($sp)
/* 1103D0 7F0DB8A0 02786821 */  addu  $t5, $s3, $t8
/* 1103D4 7F0DB8A4 91A80000 */  lbu   $t0, ($t5)
/* 1103D8 7F0DB8A8 326A00A8 */  andi  $t2, $s3, 0xa8
/* 1103DC 7F0DB8AC 016A7025 */  or    $t6, $t3, $t2
/* 1103E0 7F0DB8B0 00197980 */  sll   $t7, $t9, 6
/* 1103E4 7F0DB8B4 01CF6025 */  or    $t4, $t6, $t7
/* 1103E8 7F0DB8B8 010C8825 */  or    $s1, $t0, $t4
/* 1103EC 7F0DB8BC 323900FF */  andi  $t9, $s1, 0xff
/* 1103F0 7F0DB8C0 10000335 */  b     .L7F0DC598
/* 1103F4 7F0DB8C4 03208825 */   move  $s1, $t9
spectrum_op_CB_32:
/* 1103F8 7F0DB8C8 00145040 */  sll   $t2, $s4, 1
/* 1103FC 7F0DB8CC 35490001 */  ori   $t1, $t2, 1
/* 110400 7F0DB8D0 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 110404 7F0DB8D4 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 110408 7F0DB8D8 0014C1C3 */  sra   $t8, $s4, 7
/* 11040C 7F0DB8DC 313400FF */  andi  $s4, $t1, 0xff
/* 110410 7F0DB8E0 2E8F0001 */  sltiu $t7, $s4, 1
/* 110414 7F0DB8E4 AFAF0048 */  sw    $t7, 0x48($sp)
/* 110418 7F0DB8E8 A3B8010E */  sb    $t8, 0x10e($sp)
/* 11041C 7F0DB8EC 028A4821 */  addu  $t1, $s4, $t2
/* 110420 7F0DB8F0 912E0000 */  lbu   $t6, ($t1)
/* 110424 7F0DB8F4 328D00A8 */  andi  $t5, $s4, 0xa8
/* 110428 7F0DB8F8 030D4025 */  or    $t0, $t8, $t5
/* 11042C 7F0DB8FC 000FC980 */  sll   $t9, $t7, 6
/* 110430 7F0DB900 01195825 */  or    $t3, $t0, $t9
/* 110434 7F0DB904 01CB8825 */  or    $s1, $t6, $t3
/* 110438 7F0DB908 322F00FF */  andi  $t7, $s1, 0xff
/* 11043C 7F0DB90C 10000322 */  b     .L7F0DC598
/* 110440 7F0DB910 01E08825 */   move  $s1, $t7
spectrum_op_CB_33:
/* 110444 7F0DB914 00156840 */  sll   $t5, $s5, 1
/* 110448 7F0DB918 35AC0001 */  ori   $t4, $t5, 1
/* 11044C 7F0DB91C 3C0D8009 */  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
/* 110450 7F0DB920 8DADE334 */  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
/* 110454 7F0DB924 001551C3 */  sra   $t2, $s5, 7
/* 110458 7F0DB928 319500FF */  andi  $s5, $t4, 0xff
/* 11045C 7F0DB92C 2EB90001 */  sltiu $t9, $s5, 1
/* 110460 7F0DB930 AFB90048 */  sw    $t9, 0x48($sp)
/* 110464 7F0DB934 A3AA010D */  sb    $t2, 0x10d($sp)
/* 110468 7F0DB938 02AD6021 */  addu  $t4, $s5, $t5
/* 11046C 7F0DB93C 91880000 */  lbu   $t0, ($t4)
/* 110470 7F0DB940 32A900A8 */  andi  $t1, $s5, 0xa8
/* 110474 7F0DB944 01497025 */  or    $t6, $t2, $t1
/* 110478 7F0DB948 00197980 */  sll   $t7, $t9, 6
/* 11047C 7F0DB94C 01CFC025 */  or    $t8, $t6, $t7
/* 110480 7F0DB950 01188825 */  or    $s1, $t0, $t8
/* 110484 7F0DB954 323900FF */  andi  $t9, $s1, 0xff
/* 110488 7F0DB958 1000030F */  b     .L7F0DC598
/* 11048C 7F0DB95C 03208825 */   move  $s1, $t9
spectrum_op_CB_34:
/* 110490 7F0DB960 00164840 */  sll   $t1, $s6, 1
/* 110494 7F0DB964 352B0001 */  ori   $t3, $t1, 1
/* 110498 7F0DB968 3C098009 */  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
/* 11049C 7F0DB96C 8D29E334 */  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
/* 1104A0 7F0DB970 001669C3 */  sra   $t5, $s6, 7
/* 1104A4 7F0DB974 317600FF */  andi  $s6, $t3, 0xff
/* 1104A8 7F0DB978 2ECF0001 */  sltiu $t7, $s6, 1
/* 1104AC 7F0DB97C AFAF0048 */  sw    $t7, 0x48($sp)
/* 1104B0 7F0DB980 A3AD010C */  sb    $t5, 0x10c($sp)
/* 1104B4 7F0DB984 02C95821 */  addu  $t3, $s6, $t1
/* 1104B8 7F0DB988 916E0000 */  lbu   $t6, ($t3)
/* 1104BC 7F0DB98C 32CC00A8 */  andi  $t4, $s6, 0xa8
/* 1104C0 7F0DB990 01AC4025 */  or    $t0, $t5, $t4
/* 1104C4 7F0DB994 000FC980 */  sll   $t9, $t7, 6
/* 1104C8 7F0DB998 01195025 */  or    $t2, $t0, $t9
/* 1104CC 7F0DB99C 01CA8825 */  or    $s1, $t6, $t2
/* 1104D0 7F0DB9A0 322F00FF */  andi  $t7, $s1, 0xff
/* 1104D4 7F0DB9A4 100002FC */  b     .L7F0DC598
/* 1104D8 7F0DB9A8 01E08825 */   move  $s1, $t7
spectrum_op_CB_35:
/* 1104DC 7F0DB9AC 00176040 */  sll   $t4, $s7, 1
/* 1104E0 7F0DB9B0 35980001 */  ori   $t8, $t4, 1
/* 1104E4 7F0DB9B4 3C0C8009 */  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
/* 1104E8 7F0DB9B8 8D8CE334 */  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
/* 1104EC 7F0DB9BC 001749C3 */  sra   $t1, $s7, 7
/* 1104F0 7F0DB9C0 331700FF */  andi  $s7, $t8, 0xff
/* 1104F4 7F0DB9C4 2EF90001 */  sltiu $t9, $s7, 1
/* 1104F8 7F0DB9C8 AFB90048 */  sw    $t9, 0x48($sp)
/* 1104FC 7F0DB9CC A3A9010B */  sb    $t1, 0x10b($sp)
/* 110500 7F0DB9D0 02ECC021 */  addu  $t8, $s7, $t4
/* 110504 7F0DB9D4 93080000 */  lbu   $t0, ($t8)
/* 110508 7F0DB9D8 32EB00A8 */  andi  $t3, $s7, 0xa8
/* 11050C 7F0DB9DC 012B7025 */  or    $t6, $t1, $t3
/* 110510 7F0DB9E0 00197980 */  sll   $t7, $t9, 6
/* 110514 7F0DB9E4 01CF6825 */  or    $t5, $t6, $t7
/* 110518 7F0DB9E8 010D8825 */  or    $s1, $t0, $t5
/* 11051C 7F0DB9EC 323900FF */  andi  $t9, $s1, 0xff
/* 110520 7F0DB9F0 100002E9 */  b     .L7F0DC598
/* 110524 7F0DB9F4 03208825 */   move  $s1, $t9
spectrum_op_CB_36:
/* 110528 7F0DB9F8 8FA9028C */  lw    $t1, 0x28c($sp)
/* 11052C 7F0DB9FC 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 110530 7F0DBA00 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 110534 7F0DBA04 97AA013C */  lhu   $t2, 0x13c($sp)
/* 110538 7F0DBA08 252B0007 */  addiu $t3, $t1, 7
/* 11053C 7F0DBA0C AFAB028C */  sw    $t3, 0x28c($sp)
/* 110540 7F0DBA10 014E7821 */  addu  $t7, $t2, $t6
/* 110544 7F0DBA14 91EC0000 */  lbu   $t4, ($t7)
/* 110548 7F0DBA18 319800FF */  andi  $t8, $t4, 0xff
/* 11054C 7F0DBA1C 00186840 */  sll   $t5, $t8, 1
/* 110550 7F0DBA20 35B90001 */  ori   $t9, $t5, 1
/* 110554 7F0DBA24 3C0D8009 */  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
/* 110558 7F0DBA28 8DADE334 */  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
/* 11055C 7F0DBA2C 332900FF */  andi  $t1, $t9, 0xff
/* 110560 7F0DBA30 001851C3 */  sra   $t2, $t8, 7
/* 110564 7F0DBA34 A3AC0139 */  sb    $t4, 0x139($sp)
/* 110568 7F0DBA38 2D2B0001 */  sltiu $t3, $t1, 1
/* 11056C 7F0DBA3C 332F00A8 */  andi  $t7, $t9, 0xa8
/* 110570 7F0DBA40 014F6025 */  or    $t4, $t2, $t7
/* 110574 7F0DBA44 AFAB0048 */  sw    $t3, 0x48($sp)
/* 110578 7F0DBA48 A3B90139 */  sb    $t9, 0x139($sp)
/* 11057C 7F0DBA4C A3AA010A */  sb    $t2, 0x10a($sp)
/* 110580 7F0DBA50 012D7021 */  addu  $t6, $t1, $t5
/* 110584 7F0DBA54 91CA0000 */  lbu   $t2, ($t6)
/* 110588 7F0DBA58 000B4180 */  sll   $t0, $t3, 6
/* 11058C 7F0DBA5C 97AB013C */  lhu   $t3, 0x13c($sp)
/* 110590 7F0DBA60 0188C025 */  or    $t8, $t4, $t0
/* 110594 7F0DBA64 01588825 */  or    $s1, $t2, $t8
/* 110598 7F0DBA68 322F00FF */  andi  $t7, $s1, 0xff
/* 11059C 7F0DBA6C 29615B00 */  slti  $at, $t3, 0x5b00
/* 1105A0 7F0DBA70 14200007 */  bnez  $at, .L7F0DBA90
/* 1105A4 7F0DBA74 01E08825 */   move  $s1, $t7
/* 1105A8 7F0DBA78 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 1105AC 7F0DBA7C 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 1105B0 7F0DBA80 03206025 */  move  $t4, $t9
/* 1105B4 7F0DBA84 010BC821 */  addu  $t9, $t0, $t3
/* 1105B8 7F0DBA88 100002C3 */  b     .L7F0DC598
/* 1105BC 7F0DBA8C A32C0000 */   sb    $t4, ($t9)
.L7F0DBA90:
/* 1105C0 7F0DBA90 97A9013C */  lhu   $t1, 0x13c($sp)
/* 1105C4 7F0DBA94 97AC013C */  lhu   $t4, 0x13c($sp)
/* 1105C8 7F0DBA98 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 1105CC 7F0DBA9C 29215800 */  slti  $at, $t1, 0x5800
/* 1105D0 7F0DBAA0 5420000D */  bnezl $at, .L7F0DBAD8
/* 1105D4 7F0DBAA4 29814000 */   slti  $at, $t4, 0x4000
/* 1105D8 7F0DBAA8 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 1105DC 7F0DBAAC 93AD0139 */  lbu   $t5, 0x139($sp)
/* 1105E0 7F0DBAB0 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 1105E4 7F0DBAB4 01C95021 */  addu  $t2, $t6, $t1
/* 1105E8 7F0DBAB8 A14D0000 */  sb    $t5, ($t2)
/* 1105EC 7F0DBABC 97A8013C */  lhu   $t0, 0x13c($sp)
/* 1105F0 7F0DBAC0 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 1105F4 7F0DBAC4 24180001 */  li    $t8, 1
/* 1105F8 7F0DBAC8 01E85821 */  addu  $t3, $t7, $t0
/* 1105FC 7F0DBACC 100002B2 */  b     .L7F0DC598
/* 110600 7F0DBAD0 A178A800 */   sb    $t8, -0x5800($t3)
/* 110604 7F0DBAD4 29814000 */  slti  $at, $t4, 0x4000
.L7F0DBAD8:
/* 110608 7F0DBAD8 142002AF */  bnez  $at, .L7F0DC598
/* 11060C 7F0DBADC 3C0E8009 */   lui   $t6, %hi(ptr_spectrum_roms) 
/* 110610 7F0DBAE0 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 110614 7F0DBAE4 93B90139 */  lbu   $t9, 0x139($sp)
/* 110618 7F0DBAE8 240D0001 */  li    $t5, 1
/* 11061C 7F0DBAEC 01CC4821 */  addu  $t1, $t6, $t4
/* 110620 7F0DBAF0 A1390000 */  sb    $t9, ($t1)
/* 110624 7F0DBAF4 97AA013C */  lhu   $t2, 0x13c($sp)
/* 110628 7F0DBAF8 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 11062C 7F0DBAFC 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 110630 7F0DBB00 314F1800 */  andi  $t7, $t2, 0x1800
/* 110634 7F0DBB04 000F40C3 */  sra   $t0, $t7, 3
/* 110638 7F0DBB08 315800FF */  andi  $t8, $t2, 0xff
/* 11063C 7F0DBB0C 01185825 */  or    $t3, $t0, $t8
/* 110640 7F0DBB10 01CB6021 */  addu  $t4, $t6, $t3
/* 110644 7F0DBB14 100002A0 */  b     .L7F0DC598
/* 110648 7F0DBB18 A18D0000 */   sb    $t5, ($t4)
spectrum_op_CB_37:
/* 11064C 7F0DBB1C 00104840 */  sll   $t1, $s0, 1
/* 110650 7F0DBB20 352F0001 */  ori   $t7, $t1, 1
/* 110654 7F0DBB24 3C098009 */  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
/* 110658 7F0DBB28 8D29E334 */  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
/* 11065C 7F0DBB2C 0010C1C3 */  sra   $t8, $s0, 7
/* 110660 7F0DBB30 31F000FF */  andi  $s0, $t7, 0xff
/* 110664 7F0DBB34 2E080001 */  sltiu $t0, $s0, 1
/* 110668 7F0DBB38 AFA80048 */  sw    $t0, 0x48($sp)
/* 11066C 7F0DBB3C A3B80109 */  sb    $t8, 0x109($sp)
/* 110670 7F0DBB40 02097821 */  addu  $t7, $s0, $t1
/* 110674 7F0DBB44 91EA0000 */  lbu   $t2, ($t7)
/* 110678 7F0DBB48 320E00A8 */  andi  $t6, $s0, 0xa8
/* 11067C 7F0DBB4C 030E5825 */  or    $t3, $t8, $t6
/* 110680 7F0DBB50 00086180 */  sll   $t4, $t0, 6
/* 110684 7F0DBB54 016CC825 */  or    $t9, $t3, $t4
/* 110688 7F0DBB58 01598825 */  or    $s1, $t2, $t9
/* 11068C 7F0DBB5C 322800FF */  andi  $t0, $s1, 0xff
/* 110690 7F0DBB60 1000028D */  b     .L7F0DC598
/* 110694 7F0DBB64 01008825 */   move  $s1, $t0
spectrum_op_CB_38:
/* 110698 7F0DBB68 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 11069C 7F0DBB6C 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 1106A0 7F0DBB70 324C0001 */  andi  $t4, $s2, 1
/* 1106A4 7F0DBB74 00127042 */  srl   $t6, $s2, 1
/* 1106A8 7F0DBB78 31D200FF */  andi  $s2, $t6, 0xff
/* 1106AC 7F0DBB7C 2E4B0001 */  sltiu $t3, $s2, 1
/* 1106B0 7F0DBB80 AFAB0048 */  sw    $t3, 0x48($sp)
/* 1106B4 7F0DBB84 A3AC0108 */  sb    $t4, 0x108($sp)
/* 1106B8 7F0DBB88 02587021 */  addu  $t6, $s2, $t8
/* 1106BC 7F0DBB8C 91CD0000 */  lbu   $t5, ($t6)
/* 1106C0 7F0DBB90 324900A8 */  andi  $t1, $s2, 0xa8
/* 1106C4 7F0DBB94 01897825 */  or    $t7, $t4, $t1
/* 1106C8 7F0DBB98 000BC980 */  sll   $t9, $t3, 6
/* 1106CC 7F0DBB9C 01F94025 */  or    $t0, $t7, $t9
/* 1106D0 7F0DBBA0 01A88825 */  or    $s1, $t5, $t0
/* 1106D4 7F0DBBA4 322B00FF */  andi  $t3, $s1, 0xff
/* 1106D8 7F0DBBA8 1000027B */  b     .L7F0DC598
/* 1106DC 7F0DBBAC 01608825 */   move  $s1, $t3
spectrum_op_CB_39:
/* 1106E0 7F0DBBB0 3C0C8009 */  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
/* 1106E4 7F0DBBB4 8D8CE334 */  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
/* 1106E8 7F0DBBB8 32790001 */  andi  $t9, $s3, 1
/* 1106EC 7F0DBBBC 00134842 */  srl   $t1, $s3, 1
/* 1106F0 7F0DBBC0 313300FF */  andi  $s3, $t1, 0xff
/* 1106F4 7F0DBBC4 2E6F0001 */  sltiu $t7, $s3, 1
/* 1106F8 7F0DBBC8 AFAF0048 */  sw    $t7, 0x48($sp)
/* 1106FC 7F0DBBCC A3B90107 */  sb    $t9, 0x107($sp)
/* 110700 7F0DBBD0 026C4821 */  addu  $t1, $s3, $t4
/* 110704 7F0DBBD4 912A0000 */  lbu   $t2, ($t1)
/* 110708 7F0DBBD8 327800A8 */  andi  $t8, $s3, 0xa8
/* 11070C 7F0DBBDC 03387025 */  or    $t6, $t9, $t8
/* 110710 7F0DBBE0 000F4180 */  sll   $t0, $t7, 6
/* 110714 7F0DBBE4 01C85825 */  or    $t3, $t6, $t0
/* 110718 7F0DBBE8 014B8825 */  or    $s1, $t2, $t3
/* 11071C 7F0DBBEC 322F00FF */  andi  $t7, $s1, 0xff
/* 110720 7F0DBBF0 10000269 */  b     .L7F0DC598
/* 110724 7F0DBBF4 01E08825 */   move  $s1, $t7
spectrum_op_CB_3A:
/* 110728 7F0DBBF8 3C198009 */  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
/* 11072C 7F0DBBFC 8F39E334 */  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
/* 110730 7F0DBC00 32880001 */  andi  $t0, $s4, 1
/* 110734 7F0DBC04 0014C042 */  srl   $t8, $s4, 1
/* 110738 7F0DBC08 331400FF */  andi  $s4, $t8, 0xff
/* 11073C 7F0DBC0C 2E8E0001 */  sltiu $t6, $s4, 1
/* 110740 7F0DBC10 AFAE0048 */  sw    $t6, 0x48($sp)
/* 110744 7F0DBC14 A3A80106 */  sb    $t0, 0x106($sp)
/* 110748 7F0DBC18 0299C021 */  addu  $t8, $s4, $t9
/* 11074C 7F0DBC1C 930D0000 */  lbu   $t5, ($t8)
/* 110750 7F0DBC20 328C00A8 */  andi  $t4, $s4, 0xa8
/* 110754 7F0DBC24 010C4825 */  or    $t1, $t0, $t4
/* 110758 7F0DBC28 000E5980 */  sll   $t3, $t6, 6
/* 11075C 7F0DBC2C 012B7825 */  or    $t7, $t1, $t3
/* 110760 7F0DBC30 01AF8825 */  or    $s1, $t5, $t7
/* 110764 7F0DBC34 322E00FF */  andi  $t6, $s1, 0xff
/* 110768 7F0DBC38 10000257 */  b     .L7F0DC598
/* 11076C 7F0DBC3C 01C08825 */   move  $s1, $t6
spectrum_op_CB_3B:
/* 110770 7F0DBC40 3C088009 */  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
/* 110774 7F0DBC44 8D08E334 */  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
/* 110778 7F0DBC48 32AB0001 */  andi  $t3, $s5, 1
/* 11077C 7F0DBC4C 00156042 */  srl   $t4, $s5, 1
/* 110780 7F0DBC50 319500FF */  andi  $s5, $t4, 0xff
/* 110784 7F0DBC54 2EA90001 */  sltiu $t1, $s5, 1
/* 110788 7F0DBC58 AFA90048 */  sw    $t1, 0x48($sp)
/* 11078C 7F0DBC5C A3AB0105 */  sb    $t3, 0x105($sp)
/* 110790 7F0DBC60 02A86021 */  addu  $t4, $s5, $t0
/* 110794 7F0DBC64 918A0000 */  lbu   $t2, ($t4)
/* 110798 7F0DBC68 32B900A8 */  andi  $t9, $s5, 0xa8
/* 11079C 7F0DBC6C 0179C025 */  or    $t8, $t3, $t9
/* 1107A0 7F0DBC70 00097980 */  sll   $t7, $t1, 6
/* 1107A4 7F0DBC74 030F7025 */  or    $t6, $t8, $t7
/* 1107A8 7F0DBC78 014E8825 */  or    $s1, $t2, $t6
/* 1107AC 7F0DBC7C 322900FF */  andi  $t1, $s1, 0xff
/* 1107B0 7F0DBC80 10000245 */  b     .L7F0DC598
/* 1107B4 7F0DBC84 01208825 */   move  $s1, $t1
spectrum_op_CB_3C:
/* 1107B8 7F0DBC88 3C0B8009 */  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
/* 1107BC 7F0DBC8C 8D6BE334 */  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
/* 1107C0 7F0DBC90 32CF0001 */  andi  $t7, $s6, 1
/* 1107C4 7F0DBC94 0016C842 */  srl   $t9, $s6, 1
/* 1107C8 7F0DBC98 333600FF */  andi  $s6, $t9, 0xff
/* 1107CC 7F0DBC9C 2ED80001 */  sltiu $t8, $s6, 1
/* 1107D0 7F0DBCA0 AFB80048 */  sw    $t8, 0x48($sp)
/* 1107D4 7F0DBCA4 A3AF0104 */  sb    $t7, 0x104($sp)
/* 1107D8 7F0DBCA8 02CBC821 */  addu  $t9, $s6, $t3
/* 1107DC 7F0DBCAC 932D0000 */  lbu   $t5, ($t9)
/* 1107E0 7F0DBCB0 32C800A8 */  andi  $t0, $s6, 0xa8
/* 1107E4 7F0DBCB4 01E86025 */  or    $t4, $t7, $t0
/* 1107E8 7F0DBCB8 00187180 */  sll   $t6, $t8, 6
/* 1107EC 7F0DBCBC 018E4825 */  or    $t1, $t4, $t6
/* 1107F0 7F0DBCC0 01A98825 */  or    $s1, $t5, $t1
/* 1107F4 7F0DBCC4 323800FF */  andi  $t8, $s1, 0xff
/* 1107F8 7F0DBCC8 10000233 */  b     .L7F0DC598
/* 1107FC 7F0DBCCC 03008825 */   move  $s1, $t8
spectrum_op_CB_3D:
/* 110800 7F0DBCD0 3C0F8009 */  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
/* 110804 7F0DBCD4 8DEFE334 */  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
/* 110808 7F0DBCD8 32EE0001 */  andi  $t6, $s7, 1
/* 11080C 7F0DBCDC 00174042 */  srl   $t0, $s7, 1
/* 110810 7F0DBCE0 311700FF */  andi  $s7, $t0, 0xff
/* 110814 7F0DBCE4 2EEC0001 */  sltiu $t4, $s7, 1
/* 110818 7F0DBCE8 AFAC0048 */  sw    $t4, 0x48($sp)
/* 11081C 7F0DBCEC A3AE0103 */  sb    $t6, 0x103($sp)
/* 110820 7F0DBCF0 02EF4021 */  addu  $t0, $s7, $t7
/* 110824 7F0DBCF4 910A0000 */  lbu   $t2, ($t0)
/* 110828 7F0DBCF8 32EB00A8 */  andi  $t3, $s7, 0xa8
/* 11082C 7F0DBCFC 01CBC825 */  or    $t9, $t6, $t3
/* 110830 7F0DBD00 000C4980 */  sll   $t1, $t4, 6
/* 110834 7F0DBD04 0329C025 */  or    $t8, $t9, $t1
/* 110838 7F0DBD08 01588825 */  or    $s1, $t2, $t8
/* 11083C 7F0DBD0C 322C00FF */  andi  $t4, $s1, 0xff
/* 110840 7F0DBD10 10000221 */  b     .L7F0DC598
/* 110844 7F0DBD14 01808825 */   move  $s1, $t4
spectrum_op_CB_3E:
/* 110848 7F0DBD18 8FAE028C */  lw    $t6, 0x28c($sp)
/* 11084C 7F0DBD1C 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 110850 7F0DBD20 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 110854 7F0DBD24 97AD013C */  lhu   $t5, 0x13c($sp)
/* 110858 7F0DBD28 25CB0007 */  addiu $t3, $t6, 7
/* 11085C 7F0DBD2C AFAB028C */  sw    $t3, 0x28c($sp)
/* 110860 7F0DBD30 01B94821 */  addu  $t1, $t5, $t9
/* 110864 7F0DBD34 912F0000 */  lbu   $t7, ($t1)
/* 110868 7F0DBD38 31E800FF */  andi  $t0, $t7, 0xff
/* 11086C 7F0DBD3C 310B0001 */  andi  $t3, $t0, 1
/* 110870 7F0DBD40 0008C042 */  srl   $t8, $t0, 1
/* 110874 7F0DBD44 3C088009 */  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
/* 110878 7F0DBD48 8D08E334 */  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
/* 11087C 7F0DBD4C 330C00FF */  andi  $t4, $t8, 0xff
/* 110880 7F0DBD50 A3AF0139 */  sb    $t7, 0x139($sp)
/* 110884 7F0DBD54 2D8E0001 */  sltiu $t6, $t4, 1
/* 110888 7F0DBD58 331900A8 */  andi  $t9, $t8, 0xa8
/* 11088C 7F0DBD5C 01794825 */  or    $t1, $t3, $t9
/* 110890 7F0DBD60 AFAE0048 */  sw    $t6, 0x48($sp)
/* 110894 7F0DBD64 A3B80139 */  sb    $t8, 0x139($sp)
/* 110898 7F0DBD68 A3AB0102 */  sb    $t3, 0x102($sp)
/* 11089C 7F0DBD6C 01886821 */  addu  $t5, $t4, $t0
/* 1108A0 7F0DBD70 91AB0000 */  lbu   $t3, ($t5)
/* 1108A4 7F0DBD74 000E7980 */  sll   $t7, $t6, 6
/* 1108A8 7F0DBD78 97AE013C */  lhu   $t6, 0x13c($sp)
/* 1108AC 7F0DBD7C 012F5025 */  or    $t2, $t1, $t7
/* 1108B0 7F0DBD80 016A8825 */  or    $s1, $t3, $t2
/* 1108B4 7F0DBD84 323900FF */  andi  $t9, $s1, 0xff
/* 1108B8 7F0DBD88 29C15B00 */  slti  $at, $t6, 0x5b00
/* 1108BC 7F0DBD8C 14200007 */  bnez  $at, .L7F0DBDAC
/* 1108C0 7F0DBD90 03208825 */   move  $s1, $t9
/* 1108C4 7F0DBD94 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 1108C8 7F0DBD98 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 1108CC 7F0DBD9C 03004825 */  move  $t1, $t8
/* 1108D0 7F0DBDA0 01EEC021 */  addu  $t8, $t7, $t6
/* 1108D4 7F0DBDA4 100001FC */  b     .L7F0DC598
/* 1108D8 7F0DBDA8 A3090000 */   sb    $t1, ($t8)
.L7F0DBDAC:
/* 1108DC 7F0DBDAC 97AC013C */  lhu   $t4, 0x13c($sp)
/* 1108E0 7F0DBDB0 97A9013C */  lhu   $t1, 0x13c($sp)
/* 1108E4 7F0DBDB4 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 1108E8 7F0DBDB8 29815800 */  slti  $at, $t4, 0x5800
/* 1108EC 7F0DBDBC 5420000D */  bnezl $at, .L7F0DBDF4
/* 1108F0 7F0DBDC0 29214000 */   slti  $at, $t1, 0x4000
/* 1108F4 7F0DBDC4 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 1108F8 7F0DBDC8 93A80139 */  lbu   $t0, 0x139($sp)
/* 1108FC 7F0DBDCC 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 110900 7F0DBDD0 01AC5821 */  addu  $t3, $t5, $t4
/* 110904 7F0DBDD4 A1680000 */  sb    $t0, ($t3)
/* 110908 7F0DBDD8 97AF013C */  lhu   $t7, 0x13c($sp)
/* 11090C 7F0DBDDC 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 110910 7F0DBDE0 240A0001 */  li    $t2, 1
/* 110914 7F0DBDE4 032F7021 */  addu  $t6, $t9, $t7
/* 110918 7F0DBDE8 100001EB */  b     .L7F0DC598
/* 11091C 7F0DBDEC A1CAA800 */   sb    $t2, -0x5800($t6)
/* 110920 7F0DBDF0 29214000 */  slti  $at, $t1, 0x4000
.L7F0DBDF4:
/* 110924 7F0DBDF4 142001E8 */  bnez  $at, .L7F0DC598
/* 110928 7F0DBDF8 3C0D8009 */   lui   $t5, %hi(ptr_spectrum_roms) 
/* 11092C 7F0DBDFC 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 110930 7F0DBE00 93B80139 */  lbu   $t8, 0x139($sp)
/* 110934 7F0DBE04 24080001 */  li    $t0, 1
/* 110938 7F0DBE08 01A96021 */  addu  $t4, $t5, $t1
/* 11093C 7F0DBE0C A1980000 */  sb    $t8, ($t4)
/* 110940 7F0DBE10 97AB013C */  lhu   $t3, 0x13c($sp)
/* 110944 7F0DBE14 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 110948 7F0DBE18 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 11094C 7F0DBE1C 31791800 */  andi  $t9, $t3, 0x1800
/* 110950 7F0DBE20 001978C3 */  sra   $t7, $t9, 3
/* 110954 7F0DBE24 316A00FF */  andi  $t2, $t3, 0xff
/* 110958 7F0DBE28 01EA7025 */  or    $t6, $t7, $t2
/* 11095C 7F0DBE2C 01AE4821 */  addu  $t1, $t5, $t6
/* 110960 7F0DBE30 100001D9 */  b     .L7F0DC598
/* 110964 7F0DBE34 A1280000 */   sb    $t0, ($t1)
spectrum_op_CB_3F:
/* 110968 7F0DBE38 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 11096C 7F0DBE3C 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 110970 7F0DBE40 320F0001 */  andi  $t7, $s0, 1
/* 110974 7F0DBE44 00106042 */  srl   $t4, $s0, 1
/* 110978 7F0DBE48 319000FF */  andi  $s0, $t4, 0xff
/* 11097C 7F0DBE4C 2E0B0001 */  sltiu $t3, $s0, 1
/* 110980 7F0DBE50 AFAB0048 */  sw    $t3, 0x48($sp)
/* 110984 7F0DBE54 A3AF0101 */  sb    $t7, 0x101($sp)
/* 110988 7F0DBE58 02186021 */  addu  $t4, $s0, $t8
/* 11098C 7F0DBE5C 91990000 */  lbu   $t9, ($t4)
/* 110990 7F0DBE60 320A00A8 */  andi  $t2, $s0, 0xa8
/* 110994 7F0DBE64 01EA6825 */  or    $t5, $t7, $t2
/* 110998 7F0DBE68 000B4180 */  sll   $t0, $t3, 6
/* 11099C 7F0DBE6C 01A84825 */  or    $t1, $t5, $t0
/* 1109A0 7F0DBE70 03298825 */  or    $s1, $t9, $t1
/* 1109A4 7F0DBE74 322B00FF */  andi  $t3, $s1, 0xff
/* 1109A8 7F0DBE78 100001C7 */  b     .L7F0DC598
/* 1109AC 7F0DBE7C 01608825 */   move  $s1, $t3
.L7F0DBE80:
/* 1109B0 7F0DBE80 000F50C3 */  sra   $t2, $t7, 3
/* 1109B4 7F0DBE84 31ED00C7 */  andi  $t5, $t7, 0xc7
/* 1109B8 7F0DBE88 314E0007 */  andi  $t6, $t2, 7
/* 1109BC 7F0DBE8C 29A10088 */  slti  $at, $t5, 0x88
/* 1109C0 7F0DBE90 A3AE0100 */  sb    $t6, 0x100($sp)
/* 1109C4 7F0DBE94 1420000A */  bnez  $at, .L7F0DBEC0
/* 1109C8 7F0DBE98 AFAD0048 */   sw    $t5, 0x48($sp)
/* 1109CC 7F0DBE9C 25A8FF40 */  addiu $t0, $t5, -0xc0
/* 1109D0 7F0DBEA0 2D010008 */  sltiu $at, $t0, 8
/* 1109D4 7F0DBEA4 102001BC */  beqz  $at, .L7F0DC598
/* 1109D8 7F0DBEA8 00084080 */   sll   $t0, $t0, 2
/* 1109DC 7F0DBEAC 3C018006 */  lui   $at, %hi(jpt_8005C62C)
/* 1109E0 7F0DBEB0 00280821 */  addu  $at, $at, $t0
/* 1109E4 7F0DBEB4 8C28C62C */  lw    $t0, %lo(jpt_8005C62C)($at)
/* 1109E8 7F0DBEB8 01000008 */  jr    $t0
/* 1109EC 7F0DBEBC 00000000 */   nop   
.L7F0DBEC0:
/* 1109F0 7F0DBEC0 8FB80048 */  lw    $t8, 0x48($sp)
/* 1109F4 7F0DBEC4 8FB90048 */  lw    $t9, 0x48($sp)
/* 1109F8 7F0DBEC8 2B010048 */  slti  $at, $t8, 0x48
/* 1109FC 7F0DBECC 1420000A */  bnez  $at, .L7F0DBEF8
/* 110A00 7F0DBED0 2729FFC0 */   addiu $t1, $t9, -0x40
/* 110A04 7F0DBED4 270CFF80 */  addiu $t4, $t8, -0x80
/* 110A08 7F0DBED8 2D810008 */  sltiu $at, $t4, 8
/* 110A0C 7F0DBEDC 102001AE */  beqz  $at, .L7F0DC598
/* 110A10 7F0DBEE0 000C6080 */   sll   $t4, $t4, 2
/* 110A14 7F0DBEE4 3C018006 */  lui   $at, %hi(jpt_8005C64C)
/* 110A18 7F0DBEE8 002C0821 */  addu  $at, $at, $t4
/* 110A1C 7F0DBEEC 8C2CC64C */  lw    $t4, %lo(jpt_8005C64C)($at)
/* 110A20 7F0DBEF0 01800008 */  jr    $t4
/* 110A24 7F0DBEF4 00000000 */   nop   
.L7F0DBEF8:
/* 110A28 7F0DBEF8 2D210008 */  sltiu $at, $t1, 8
/* 110A2C 7F0DBEFC 102001A6 */  beqz  $at, .L7F0DC598
/* 110A30 7F0DBF00 00094880 */   sll   $t1, $t1, 2
/* 110A34 7F0DBF04 3C018006 */  lui   $at, %hi(jpt_8005C66C)
/* 110A38 7F0DBF08 00290821 */  addu  $at, $at, $t1
/* 110A3C 7F0DBF0C 8C29C66C */  lw    $t1, %lo(jpt_8005C66C)($at)
/* 110A40 7F0DBF10 01200008 */  jr    $t1
/* 110A44 7F0DBF14 00000000 */   nop   
spectrum_op_BIT_x_B:
/* 110A48 7F0DBF18 93AB0100 */  lbu   $t3, 0x100($sp)
/* 110A4C 7F0DBF1C 240A0001 */  li    $t2, 1
/* 110A50 7F0DBF20 24080054 */  li    $t0, 84
/* 110A54 7F0DBF24 016A7004 */  sllv  $t6, $t2, $t3
/* 110A58 7F0DBF28 024E7824 */  and   $t7, $s2, $t6
/* 110A5C 7F0DBF2C 11E00003 */  beqz  $t7, .L7F0DBF3C
/* 110A60 7F0DBF30 240D0010 */   li    $t5, 16
/* 110A64 7F0DBF34 10000002 */  b     .L7F0DBF40
/* 110A68 7F0DBF38 AFAD0044 */   sw    $t5, 0x44($sp)
.L7F0DBF3C:
/* 110A6C 7F0DBF3C AFA80044 */  sw    $t0, 0x44($sp)
.L7F0DBF40:
/* 110A70 7F0DBF40 8FB80044 */  lw    $t8, 0x44($sp)
/* 110A74 7F0DBF44 322C0001 */  andi  $t4, $s1, 1
/* 110A78 7F0DBF48 32490028 */  andi  $t1, $s2, 0x28
/* 110A7C 7F0DBF4C 030CC825 */  or    $t9, $t8, $t4
/* 110A80 7F0DBF50 03298825 */  or    $s1, $t9, $t1
/* 110A84 7F0DBF54 322A00FF */  andi  $t2, $s1, 0xff
/* 110A88 7F0DBF58 1000018F */  b     .L7F0DC598
/* 110A8C 7F0DBF5C 01408825 */   move  $s1, $t2
spectrum_op_BIT_x_C:
/* 110A90 7F0DBF60 93AB0100 */  lbu   $t3, 0x100($sp)
/* 110A94 7F0DBF64 240E0001 */  li    $t6, 1
/* 110A98 7F0DBF68 24180054 */  li    $t8, 84
/* 110A9C 7F0DBF6C 016E7804 */  sllv  $t7, $t6, $t3
/* 110AA0 7F0DBF70 026F6824 */  and   $t5, $s3, $t7
/* 110AA4 7F0DBF74 11A00003 */  beqz  $t5, .L7F0DBF84
/* 110AA8 7F0DBF78 24080010 */   li    $t0, 16
/* 110AAC 7F0DBF7C 10000002 */  b     .L7F0DBF88
/* 110AB0 7F0DBF80 AFA80048 */   sw    $t0, 0x48($sp)
.L7F0DBF84:
/* 110AB4 7F0DBF84 AFB80048 */  sw    $t8, 0x48($sp)
.L7F0DBF88:
/* 110AB8 7F0DBF88 8FAC0048 */  lw    $t4, 0x48($sp)
/* 110ABC 7F0DBF8C 32390001 */  andi  $t9, $s1, 1
/* 110AC0 7F0DBF90 326A0028 */  andi  $t2, $s3, 0x28
/* 110AC4 7F0DBF94 01994825 */  or    $t1, $t4, $t9
/* 110AC8 7F0DBF98 012A8825 */  or    $s1, $t1, $t2
/* 110ACC 7F0DBF9C 322E00FF */  andi  $t6, $s1, 0xff
/* 110AD0 7F0DBFA0 1000017D */  b     .L7F0DC598
/* 110AD4 7F0DBFA4 01C08825 */   move  $s1, $t6
spectrum_op_BIT_x_D:
/* 110AD8 7F0DBFA8 93AB0100 */  lbu   $t3, 0x100($sp)
/* 110ADC 7F0DBFAC 240F0001 */  li    $t7, 1
/* 110AE0 7F0DBFB0 240C0054 */  li    $t4, 84
/* 110AE4 7F0DBFB4 016F6804 */  sllv  $t5, $t7, $t3
/* 110AE8 7F0DBFB8 028D4024 */  and   $t0, $s4, $t5
/* 110AEC 7F0DBFBC 11000003 */  beqz  $t0, .L7F0DBFCC
/* 110AF0 7F0DBFC0 24180010 */   li    $t8, 16
/* 110AF4 7F0DBFC4 10000002 */  b     .L7F0DBFD0
/* 110AF8 7F0DBFC8 AFB80048 */   sw    $t8, 0x48($sp)
.L7F0DBFCC:
/* 110AFC 7F0DBFCC AFAC0048 */  sw    $t4, 0x48($sp)
.L7F0DBFD0:
/* 110B00 7F0DBFD0 8FB90048 */  lw    $t9, 0x48($sp)
/* 110B04 7F0DBFD4 32290001 */  andi  $t1, $s1, 1
/* 110B08 7F0DBFD8 328E0028 */  andi  $t6, $s4, 0x28
/* 110B0C 7F0DBFDC 03295025 */  or    $t2, $t9, $t1
/* 110B10 7F0DBFE0 014E8825 */  or    $s1, $t2, $t6
/* 110B14 7F0DBFE4 322F00FF */  andi  $t7, $s1, 0xff
/* 110B18 7F0DBFE8 1000016B */  b     .L7F0DC598
/* 110B1C 7F0DBFEC 01E08825 */   move  $s1, $t7
spectrum_op_BIT_x_E:
/* 110B20 7F0DBFF0 93AB0100 */  lbu   $t3, 0x100($sp)
/* 110B24 7F0DBFF4 240D0001 */  li    $t5, 1
/* 110B28 7F0DBFF8 24190054 */  li    $t9, 84
/* 110B2C 7F0DBFFC 016D4004 */  sllv  $t0, $t5, $t3
/* 110B30 7F0DC000 02A8C024 */  and   $t8, $s5, $t0
/* 110B34 7F0DC004 13000003 */  beqz  $t8, .L7F0DC014
/* 110B38 7F0DC008 240C0010 */   li    $t4, 16
/* 110B3C 7F0DC00C 10000002 */  b     .L7F0DC018
/* 110B40 7F0DC010 AFAC0048 */   sw    $t4, 0x48($sp)
.L7F0DC014:
/* 110B44 7F0DC014 AFB90048 */  sw    $t9, 0x48($sp)
.L7F0DC018:
/* 110B48 7F0DC018 8FA90048 */  lw    $t1, 0x48($sp)
/* 110B4C 7F0DC01C 322A0001 */  andi  $t2, $s1, 1
/* 110B50 7F0DC020 32AF0028 */  andi  $t7, $s5, 0x28
/* 110B54 7F0DC024 012A7025 */  or    $t6, $t1, $t2
/* 110B58 7F0DC028 01CF8825 */  or    $s1, $t6, $t7
/* 110B5C 7F0DC02C 322D00FF */  andi  $t5, $s1, 0xff
/* 110B60 7F0DC030 10000159 */  b     .L7F0DC598
/* 110B64 7F0DC034 01A08825 */   move  $s1, $t5
spectrum_op_BIT_x_H:
/* 110B68 7F0DC038 93AB0100 */  lbu   $t3, 0x100($sp)
/* 110B6C 7F0DC03C 24080001 */  li    $t0, 1
/* 110B70 7F0DC040 24090054 */  li    $t1, 84
/* 110B74 7F0DC044 0168C004 */  sllv  $t8, $t0, $t3
/* 110B78 7F0DC048 02D86024 */  and   $t4, $s6, $t8
/* 110B7C 7F0DC04C 11800003 */  beqz  $t4, .L7F0DC05C
/* 110B80 7F0DC050 24190010 */   li    $t9, 16
/* 110B84 7F0DC054 10000002 */  b     .L7F0DC060
/* 110B88 7F0DC058 AFB90048 */   sw    $t9, 0x48($sp)
.L7F0DC05C:
/* 110B8C 7F0DC05C AFA90048 */  sw    $t1, 0x48($sp)
.L7F0DC060:
/* 110B90 7F0DC060 8FAA0048 */  lw    $t2, 0x48($sp)
/* 110B94 7F0DC064 322E0001 */  andi  $t6, $s1, 1
/* 110B98 7F0DC068 32CD0028 */  andi  $t5, $s6, 0x28
/* 110B9C 7F0DC06C 014E7825 */  or    $t7, $t2, $t6
/* 110BA0 7F0DC070 01ED8825 */  or    $s1, $t7, $t5
/* 110BA4 7F0DC074 322800FF */  andi  $t0, $s1, 0xff
/* 110BA8 7F0DC078 10000147 */  b     .L7F0DC598
/* 110BAC 7F0DC07C 01008825 */   move  $s1, $t0
spectrum_op_BIT_x_L:
/* 110BB0 7F0DC080 93AB0100 */  lbu   $t3, 0x100($sp)
/* 110BB4 7F0DC084 24180001 */  li    $t8, 1
/* 110BB8 7F0DC088 240A0054 */  li    $t2, 84
/* 110BBC 7F0DC08C 01786004 */  sllv  $t4, $t8, $t3
/* 110BC0 7F0DC090 02ECC824 */  and   $t9, $s7, $t4
/* 110BC4 7F0DC094 13200003 */  beqz  $t9, .L7F0DC0A4
/* 110BC8 7F0DC098 24090010 */   li    $t1, 16
/* 110BCC 7F0DC09C 10000002 */  b     .L7F0DC0A8
/* 110BD0 7F0DC0A0 AFA90048 */   sw    $t1, 0x48($sp)
.L7F0DC0A4:
/* 110BD4 7F0DC0A4 AFAA0048 */  sw    $t2, 0x48($sp)
.L7F0DC0A8:
/* 110BD8 7F0DC0A8 8FAE0048 */  lw    $t6, 0x48($sp)
/* 110BDC 7F0DC0AC 322F0001 */  andi  $t7, $s1, 1
/* 110BE0 7F0DC0B0 32E80028 */  andi  $t0, $s7, 0x28
/* 110BE4 7F0DC0B4 01CF6825 */  or    $t5, $t6, $t7
/* 110BE8 7F0DC0B8 01A88825 */  or    $s1, $t5, $t0
/* 110BEC 7F0DC0BC 323800FF */  andi  $t8, $s1, 0xff
/* 110BF0 7F0DC0C0 10000135 */  b     .L7F0DC598
/* 110BF4 7F0DC0C4 03008825 */   move  $s1, $t8
spectrum_op_BIT_x_HL:
/* 110BF8 7F0DC0C8 8FAB028C */  lw    $t3, 0x28c($sp)
/* 110BFC 7F0DC0CC 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 110C00 7F0DC0D0 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 110C04 7F0DC0D4 97B9013C */  lhu   $t9, 0x13c($sp)
/* 110C08 7F0DC0D8 256C0004 */  addiu $t4, $t3, 4
/* 110C0C 7F0DC0DC 93AF0100 */  lbu   $t7, 0x100($sp)
/* 110C10 7F0DC0E0 AFAC028C */  sw    $t4, 0x28c($sp)
/* 110C14 7F0DC0E4 03295021 */  addu  $t2, $t9, $t1
/* 110C18 7F0DC0E8 914E0000 */  lbu   $t6, ($t2)
/* 110C1C 7F0DC0EC 240D0001 */  li    $t5, 1
/* 110C20 7F0DC0F0 01ED4004 */  sllv  $t0, $t5, $t7
/* 110C24 7F0DC0F4 01C8C024 */  and   $t8, $t6, $t0
/* 110C28 7F0DC0F8 13000004 */  beqz  $t8, .L7F0DC10C
/* 110C2C 7F0DC0FC A3AE0139 */   sb    $t6, 0x139($sp)
/* 110C30 7F0DC100 240B0010 */  li    $t3, 16
/* 110C34 7F0DC104 10000003 */  b     .L7F0DC114
/* 110C38 7F0DC108 AFAB0048 */   sw    $t3, 0x48($sp)
.L7F0DC10C:
/* 110C3C 7F0DC10C 240C0054 */  li    $t4, 84
/* 110C40 7F0DC110 AFAC0048 */  sw    $t4, 0x48($sp)
.L7F0DC114:
/* 110C44 7F0DC114 8FB90048 */  lw    $t9, 0x48($sp)
/* 110C48 7F0DC118 93AD0139 */  lbu   $t5, 0x139($sp)
/* 110C4C 7F0DC11C 97A8013C */  lhu   $t0, 0x13c($sp)
/* 110C50 7F0DC120 32290001 */  andi  $t1, $s1, 1
/* 110C54 7F0DC124 03295025 */  or    $t2, $t9, $t1
/* 110C58 7F0DC128 31AF0028 */  andi  $t7, $t5, 0x28
/* 110C5C 7F0DC12C 014F8825 */  or    $s1, $t2, $t7
/* 110C60 7F0DC130 322E00FF */  andi  $t6, $s1, 0xff
/* 110C64 7F0DC134 29015B00 */  slti  $at, $t0, 0x5b00
/* 110C68 7F0DC138 14200007 */  bnez  $at, .L7F0DC158
/* 110C6C 7F0DC13C 01C08825 */   move  $s1, $t6
/* 110C70 7F0DC140 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 110C74 7F0DC144 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 110C78 7F0DC148 93B80139 */  lbu   $t8, 0x139($sp)
/* 110C7C 7F0DC14C 01686021 */  addu  $t4, $t3, $t0
/* 110C80 7F0DC150 10000111 */  b     .L7F0DC598
/* 110C84 7F0DC154 A1980000 */   sb    $t8, ($t4)
.L7F0DC158:
/* 110C88 7F0DC158 97B9013C */  lhu   $t9, 0x13c($sp)
/* 110C8C 7F0DC15C 97B8013C */  lhu   $t8, 0x13c($sp)
/* 110C90 7F0DC160 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 110C94 7F0DC164 2B215800 */  slti  $at, $t9, 0x5800
/* 110C98 7F0DC168 5420000D */  bnezl $at, .L7F0DC1A0
/* 110C9C 7F0DC16C 2B014000 */   slti  $at, $t8, 0x4000
/* 110CA0 7F0DC170 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 110CA4 7F0DC174 93A90139 */  lbu   $t1, 0x139($sp)
/* 110CA8 7F0DC178 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 110CAC 7F0DC17C 01B95021 */  addu  $t2, $t5, $t9
/* 110CB0 7F0DC180 A1490000 */  sb    $t1, ($t2)
/* 110CB4 7F0DC184 97AB013C */  lhu   $t3, 0x13c($sp)
/* 110CB8 7F0DC188 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 110CBC 7F0DC18C 240F0001 */  li    $t7, 1
/* 110CC0 7F0DC190 01CB4021 */  addu  $t0, $t6, $t3
/* 110CC4 7F0DC194 10000100 */  b     .L7F0DC598
/* 110CC8 7F0DC198 A10FA800 */   sb    $t7, -0x5800($t0)
/* 110CCC 7F0DC19C 2B014000 */  slti  $at, $t8, 0x4000
.L7F0DC1A0:
/* 110CD0 7F0DC1A0 142000FD */  bnez  $at, .L7F0DC598
/* 110CD4 7F0DC1A4 3C0D8009 */   lui   $t5, %hi(ptr_spectrum_roms) 
/* 110CD8 7F0DC1A8 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 110CDC 7F0DC1AC 93AC0139 */  lbu   $t4, 0x139($sp)
/* 110CE0 7F0DC1B0 24090001 */  li    $t1, 1
/* 110CE4 7F0DC1B4 01B8C821 */  addu  $t9, $t5, $t8
/* 110CE8 7F0DC1B8 A32C0000 */  sb    $t4, ($t9)
/* 110CEC 7F0DC1BC 97AA013C */  lhu   $t2, 0x13c($sp)
/* 110CF0 7F0DC1C0 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 110CF4 7F0DC1C4 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 110CF8 7F0DC1C8 314E1800 */  andi  $t6, $t2, 0x1800
/* 110CFC 7F0DC1CC 000E58C3 */  sra   $t3, $t6, 3
/* 110D00 7F0DC1D0 314F00FF */  andi  $t7, $t2, 0xff
/* 110D04 7F0DC1D4 016F4025 */  or    $t0, $t3, $t7
/* 110D08 7F0DC1D8 01A8C021 */  addu  $t8, $t5, $t0
/* 110D0C 7F0DC1DC 100000EE */  b     .L7F0DC598
/* 110D10 7F0DC1E0 A3090000 */   sb    $t1, ($t8)
spectrum_op_BIT_x_A:
/* 110D14 7F0DC1E4 93AC0100 */  lbu   $t4, 0x100($sp)
/* 110D18 7F0DC1E8 24190001 */  li    $t9, 1
/* 110D1C 7F0DC1EC 240F0054 */  li    $t7, 84
/* 110D20 7F0DC1F0 01997004 */  sllv  $t6, $t9, $t4
/* 110D24 7F0DC1F4 020E5024 */  and   $t2, $s0, $t6
/* 110D28 7F0DC1F8 11400003 */  beqz  $t2, .L7F0DC208
/* 110D2C 7F0DC1FC 240B0010 */   li    $t3, 16
/* 110D30 7F0DC200 10000002 */  b     .L7F0DC20C
/* 110D34 7F0DC204 AFAB0048 */   sw    $t3, 0x48($sp)
.L7F0DC208:
/* 110D38 7F0DC208 AFAF0048 */  sw    $t7, 0x48($sp)
.L7F0DC20C:
/* 110D3C 7F0DC20C 8FAD0048 */  lw    $t5, 0x48($sp)
/* 110D40 7F0DC210 32280001 */  andi  $t0, $s1, 1
/* 110D44 7F0DC214 32180028 */  andi  $t8, $s0, 0x28
/* 110D48 7F0DC218 01A84825 */  or    $t1, $t5, $t0
/* 110D4C 7F0DC21C 01388825 */  or    $s1, $t1, $t8
/* 110D50 7F0DC220 323900FF */  andi  $t9, $s1, 0xff
/* 110D54 7F0DC224 100000DC */  b     .L7F0DC598
/* 110D58 7F0DC228 03208825 */   move  $s1, $t9
spectrum_op_RES_x_B:
/* 110D5C 7F0DC22C 93AC0100 */  lbu   $t4, 0x100($sp)
/* 110D60 7F0DC230 240E0001 */  li    $t6, 1
/* 110D64 7F0DC234 018E5004 */  sllv  $t2, $t6, $t4
/* 110D68 7F0DC238 01405827 */  not   $t3, $t2
/* 110D6C 7F0DC23C 024B9024 */  and   $s2, $s2, $t3
/* 110D70 7F0DC240 324F00FF */  andi  $t7, $s2, 0xff
/* 110D74 7F0DC244 100000D4 */  b     .L7F0DC598
/* 110D78 7F0DC248 01E09025 */   move  $s2, $t7
spectrum_op_RES_x_C:
/* 110D7C 7F0DC24C 93AD0100 */  lbu   $t5, 0x100($sp)
/* 110D80 7F0DC250 24080001 */  li    $t0, 1
/* 110D84 7F0DC254 01A84804 */  sllv  $t1, $t0, $t5
/* 110D88 7F0DC258 0120C027 */  not   $t8, $t1
/* 110D8C 7F0DC25C 02789824 */  and   $s3, $s3, $t8
/* 110D90 7F0DC260 327900FF */  andi  $t9, $s3, 0xff
/* 110D94 7F0DC264 100000CC */  b     .L7F0DC598
/* 110D98 7F0DC268 03209825 */   move  $s3, $t9
spectrum_op_RES_x_D:
/* 110D9C 7F0DC26C 93AE0100 */  lbu   $t6, 0x100($sp)
/* 110DA0 7F0DC270 240C0001 */  li    $t4, 1
/* 110DA4 7F0DC274 01CC5004 */  sllv  $t2, $t4, $t6
/* 110DA8 7F0DC278 01405827 */  not   $t3, $t2
/* 110DAC 7F0DC27C 028BA024 */  and   $s4, $s4, $t3
/* 110DB0 7F0DC280 328F00FF */  andi  $t7, $s4, 0xff
/* 110DB4 7F0DC284 100000C4 */  b     .L7F0DC598
/* 110DB8 7F0DC288 01E0A025 */   move  $s4, $t7
spectrum_op_RES_x_E:
/* 110DBC 7F0DC28C 93A80100 */  lbu   $t0, 0x100($sp)
/* 110DC0 7F0DC290 240D0001 */  li    $t5, 1
/* 110DC4 7F0DC294 010D4804 */  sllv  $t1, $t5, $t0
/* 110DC8 7F0DC298 0120C027 */  not   $t8, $t1
/* 110DCC 7F0DC29C 02B8A824 */  and   $s5, $s5, $t8
/* 110DD0 7F0DC2A0 32B900FF */  andi  $t9, $s5, 0xff
/* 110DD4 7F0DC2A4 100000BC */  b     .L7F0DC598
/* 110DD8 7F0DC2A8 0320A825 */   move  $s5, $t9
spectrum_op_RES_x_H:
/* 110DDC 7F0DC2AC 93AC0100 */  lbu   $t4, 0x100($sp)
/* 110DE0 7F0DC2B0 240E0001 */  li    $t6, 1
/* 110DE4 7F0DC2B4 018E5004 */  sllv  $t2, $t6, $t4
/* 110DE8 7F0DC2B8 01405827 */  not   $t3, $t2
/* 110DEC 7F0DC2BC 02CBB024 */  and   $s6, $s6, $t3
/* 110DF0 7F0DC2C0 32CF00FF */  andi  $t7, $s6, 0xff
/* 110DF4 7F0DC2C4 100000B4 */  b     .L7F0DC598
/* 110DF8 7F0DC2C8 01E0B025 */   move  $s6, $t7
spectrum_op_RES_x_L:
/* 110DFC 7F0DC2CC 93AD0100 */  lbu   $t5, 0x100($sp)
/* 110E00 7F0DC2D0 24080001 */  li    $t0, 1
/* 110E04 7F0DC2D4 01A84804 */  sllv  $t1, $t0, $t5
/* 110E08 7F0DC2D8 0120C027 */  not   $t8, $t1
/* 110E0C 7F0DC2DC 02F8B824 */  and   $s7, $s7, $t8
/* 110E10 7F0DC2E0 32F900FF */  andi  $t9, $s7, 0xff
/* 110E14 7F0DC2E4 100000AC */  b     .L7F0DC598
/* 110E18 7F0DC2E8 0320B825 */   move  $s7, $t9
spectrum_op_RES_x_HL:
/* 110E1C 7F0DC2EC 8FAE028C */  lw    $t6, 0x28c($sp)
/* 110E20 7F0DC2F0 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 110E24 7F0DC2F4 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 110E28 7F0DC2F8 97AA013C */  lhu   $t2, 0x13c($sp)
/* 110E2C 7F0DC2FC 25CC0004 */  addiu $t4, $t6, 4
/* 110E30 7F0DC300 93AD0100 */  lbu   $t5, 0x100($sp)
/* 110E34 7F0DC304 AFAC028C */  sw    $t4, 0x28c($sp)
/* 110E38 7F0DC308 014B7821 */  addu  $t7, $t2, $t3
/* 110E3C 7F0DC30C 91E80000 */  lbu   $t0, ($t7)
/* 110E40 7F0DC310 97AC013C */  lhu   $t4, 0x13c($sp)
/* 110E44 7F0DC314 24090001 */  li    $t1, 1
/* 110E48 7F0DC318 01A9C004 */  sllv  $t8, $t1, $t5
/* 110E4C 7F0DC31C 0300C827 */  not   $t9, $t8
/* 110E50 7F0DC320 01197024 */  and   $t6, $t0, $t9
/* 110E54 7F0DC324 A3A80139 */  sb    $t0, 0x139($sp)
/* 110E58 7F0DC328 29815B00 */  slti  $at, $t4, 0x5b00
/* 110E5C 7F0DC32C 14200006 */  bnez  $at, .L7F0DC348
/* 110E60 7F0DC330 A3AE0139 */   sb    $t6, 0x139($sp)
/* 110E64 7F0DC334 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 110E68 7F0DC338 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 110E6C 7F0DC33C 016C7821 */  addu  $t7, $t3, $t4
/* 110E70 7F0DC340 10000095 */  b     .L7F0DC598
/* 110E74 7F0DC344 A1EE0000 */   sb    $t6, ($t7)
.L7F0DC348:
/* 110E78 7F0DC348 97A9013C */  lhu   $t1, 0x13c($sp)
/* 110E7C 7F0DC34C 97AA013C */  lhu   $t2, 0x13c($sp)
/* 110E80 7F0DC350 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 110E84 7F0DC354 29215800 */  slti  $at, $t1, 0x5800
/* 110E88 7F0DC358 5420000D */  bnezl $at, .L7F0DC390
/* 110E8C 7F0DC35C 29414000 */   slti  $at, $t2, 0x4000
/* 110E90 7F0DC360 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 110E94 7F0DC364 93AD0139 */  lbu   $t5, 0x139($sp)
/* 110E98 7F0DC368 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 110E9C 7F0DC36C 03094021 */  addu  $t0, $t8, $t1
/* 110EA0 7F0DC370 A10D0000 */  sb    $t5, ($t0)
/* 110EA4 7F0DC374 97AB013C */  lhu   $t3, 0x13c($sp)
/* 110EA8 7F0DC378 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 110EAC 7F0DC37C 24190001 */  li    $t9, 1
/* 110EB0 7F0DC380 01CB6021 */  addu  $t4, $t6, $t3
/* 110EB4 7F0DC384 10000084 */  b     .L7F0DC598
/* 110EB8 7F0DC388 A199A800 */   sb    $t9, -0x5800($t4)
/* 110EBC 7F0DC38C 29414000 */  slti  $at, $t2, 0x4000
.L7F0DC390:
/* 110EC0 7F0DC390 14200081 */  bnez  $at, .L7F0DC598
/* 110EC4 7F0DC394 3C188009 */   lui   $t8, %hi(ptr_spectrum_roms) 
/* 110EC8 7F0DC398 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 110ECC 7F0DC39C 93AF0139 */  lbu   $t7, 0x139($sp)
/* 110ED0 7F0DC3A0 240D0001 */  li    $t5, 1
/* 110ED4 7F0DC3A4 030A4821 */  addu  $t1, $t8, $t2
/* 110ED8 7F0DC3A8 A12F0000 */  sb    $t7, ($t1)
/* 110EDC 7F0DC3AC 97A8013C */  lhu   $t0, 0x13c($sp)
/* 110EE0 7F0DC3B0 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 110EE4 7F0DC3B4 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 110EE8 7F0DC3B8 310E1800 */  andi  $t6, $t0, 0x1800
/* 110EEC 7F0DC3BC 000E58C3 */  sra   $t3, $t6, 3
/* 110EF0 7F0DC3C0 311900FF */  andi  $t9, $t0, 0xff
/* 110EF4 7F0DC3C4 01796025 */  or    $t4, $t3, $t9
/* 110EF8 7F0DC3C8 030C5021 */  addu  $t2, $t8, $t4
/* 110EFC 7F0DC3CC 10000072 */  b     .L7F0DC598
/* 110F00 7F0DC3D0 A14D0000 */   sb    $t5, ($t2)
spectrum_op_RES_x_A:
/* 110F04 7F0DC3D4 93AF0100 */  lbu   $t7, 0x100($sp)
/* 110F08 7F0DC3D8 24090001 */  li    $t1, 1
/* 110F0C 7F0DC3DC 01E97004 */  sllv  $t6, $t1, $t7
/* 110F10 7F0DC3E0 01C04027 */  not   $t0, $t6
/* 110F14 7F0DC3E4 02088024 */  and   $s0, $s0, $t0
/* 110F18 7F0DC3E8 320B00FF */  andi  $t3, $s0, 0xff
/* 110F1C 7F0DC3EC 1000006A */  b     .L7F0DC598
/* 110F20 7F0DC3F0 01608025 */   move  $s0, $t3
spectrum_op_SET_x_B:
/* 110F24 7F0DC3F4 93B90100 */  lbu   $t9, 0x100($sp)
/* 110F28 7F0DC3F8 24180001 */  li    $t8, 1
/* 110F2C 7F0DC3FC 03386004 */  sllv  $t4, $t8, $t9
/* 110F30 7F0DC400 024C9025 */  or    $s2, $s2, $t4
/* 110F34 7F0DC404 324D00FF */  andi  $t5, $s2, 0xff
/* 110F38 7F0DC408 10000063 */  b     .L7F0DC598
/* 110F3C 7F0DC40C 01A09025 */   move  $s2, $t5
spectrum_op_SET_x_C:
/* 110F40 7F0DC410 93AA0100 */  lbu   $t2, 0x100($sp)
/* 110F44 7F0DC414 24090001 */  li    $t1, 1
/* 110F48 7F0DC418 01497804 */  sllv  $t7, $t1, $t2
/* 110F4C 7F0DC41C 026F9825 */  or    $s3, $s3, $t7
/* 110F50 7F0DC420 326E00FF */  andi  $t6, $s3, 0xff
/* 110F54 7F0DC424 1000005C */  b     .L7F0DC598
/* 110F58 7F0DC428 01C09825 */   move  $s3, $t6
spectrum_op_SET_x_D:
/* 110F5C 7F0DC42C 93A80100 */  lbu   $t0, 0x100($sp)
/* 110F60 7F0DC430 240B0001 */  li    $t3, 1
/* 110F64 7F0DC434 010BC004 */  sllv  $t8, $t3, $t0
/* 110F68 7F0DC438 0298A025 */  or    $s4, $s4, $t8
/* 110F6C 7F0DC43C 329900FF */  andi  $t9, $s4, 0xff
/* 110F70 7F0DC440 10000055 */  b     .L7F0DC598
/* 110F74 7F0DC444 0320A025 */   move  $s4, $t9
spectrum_op_SET_x_E:
/* 110F78 7F0DC448 93AC0100 */  lbu   $t4, 0x100($sp)
/* 110F7C 7F0DC44C 240D0001 */  li    $t5, 1
/* 110F80 7F0DC450 018D4804 */  sllv  $t1, $t5, $t4
/* 110F84 7F0DC454 02A9A825 */  or    $s5, $s5, $t1
/* 110F88 7F0DC458 32AA00FF */  andi  $t2, $s5, 0xff
/* 110F8C 7F0DC45C 1000004E */  b     .L7F0DC598
/* 110F90 7F0DC460 0140A825 */   move  $s5, $t2
spectrum_op_SET_x_H:
/* 110F94 7F0DC464 93AF0100 */  lbu   $t7, 0x100($sp)
/* 110F98 7F0DC468 240E0001 */  li    $t6, 1
/* 110F9C 7F0DC46C 01EE5804 */  sllv  $t3, $t6, $t7
/* 110FA0 7F0DC470 02CBB025 */  or    $s6, $s6, $t3
/* 110FA4 7F0DC474 32C800FF */  andi  $t0, $s6, 0xff
/* 110FA8 7F0DC478 10000047 */  b     .L7F0DC598
/* 110FAC 7F0DC47C 0100B025 */   move  $s6, $t0
spectrum_op_SET_x_L:
/* 110FB0 7F0DC480 93B80100 */  lbu   $t8, 0x100($sp)
/* 110FB4 7F0DC484 24190001 */  li    $t9, 1
/* 110FB8 7F0DC488 03196804 */  sllv  $t5, $t9, $t8
/* 110FBC 7F0DC48C 02EDB825 */  or    $s7, $s7, $t5
/* 110FC0 7F0DC490 32EC00FF */  andi  $t4, $s7, 0xff
/* 110FC4 7F0DC494 10000040 */  b     .L7F0DC598
/* 110FC8 7F0DC498 0180B825 */   move  $s7, $t4
spectrum_op_SET_x_HL:
/* 110FCC 7F0DC49C 8FA9028C */  lw    $t1, 0x28c($sp)
/* 110FD0 7F0DC4A0 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 110FD4 7F0DC4A4 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 110FD8 7F0DC4A8 97AE013C */  lhu   $t6, 0x13c($sp)
/* 110FDC 7F0DC4AC 252A0004 */  addiu $t2, $t1, 4
/* 110FE0 7F0DC4B0 AFAA028C */  sw    $t2, 0x28c($sp)
/* 110FE4 7F0DC4B4 01CF5821 */  addu  $t3, $t6, $t7
/* 110FE8 7F0DC4B8 91680000 */  lbu   $t0, ($t3)
/* 110FEC 7F0DC4BC 93B90100 */  lbu   $t9, 0x100($sp)
/* 110FF0 7F0DC4C0 97A9013C */  lhu   $t1, 0x13c($sp)
/* 110FF4 7F0DC4C4 24180001 */  li    $t8, 1
/* 110FF8 7F0DC4C8 03386804 */  sllv  $t5, $t8, $t9
/* 110FFC 7F0DC4CC 010D6025 */  or    $t4, $t0, $t5
/* 111000 7F0DC4D0 A3A80139 */  sb    $t0, 0x139($sp)
/* 111004 7F0DC4D4 29215B00 */  slti  $at, $t1, 0x5b00
/* 111008 7F0DC4D8 14200006 */  bnez  $at, .L7F0DC4F4
/* 11100C 7F0DC4DC A3AC0139 */   sb    $t4, 0x139($sp)
/* 111010 7F0DC4E0 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 111014 7F0DC4E4 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 111018 7F0DC4E8 01C97821 */  addu  $t7, $t6, $t1
/* 11101C 7F0DC4EC 1000002A */  b     .L7F0DC598
/* 111020 7F0DC4F0 A1EC0000 */   sb    $t4, ($t7)
.L7F0DC4F4:
/* 111024 7F0DC4F4 97AB013C */  lhu   $t3, 0x13c($sp)
/* 111028 7F0DC4F8 97AA013C */  lhu   $t2, 0x13c($sp)
/* 11102C 7F0DC4FC 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 111030 7F0DC500 29615800 */  slti  $at, $t3, 0x5800
/* 111034 7F0DC504 5420000D */  bnezl $at, .L7F0DC53C
/* 111038 7F0DC508 29414000 */   slti  $at, $t2, 0x4000
/* 11103C 7F0DC50C 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 111040 7F0DC510 93B80139 */  lbu   $t8, 0x139($sp)
/* 111044 7F0DC514 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 111048 7F0DC518 032B4021 */  addu  $t0, $t9, $t3
/* 11104C 7F0DC51C A1180000 */  sb    $t8, ($t0)
/* 111050 7F0DC520 97AE013C */  lhu   $t6, 0x13c($sp)
/* 111054 7F0DC524 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 111058 7F0DC528 240D0001 */  li    $t5, 1
/* 11105C 7F0DC52C 018E4821 */  addu  $t1, $t4, $t6
/* 111060 7F0DC530 10000019 */  b     .L7F0DC598
/* 111064 7F0DC534 A12DA800 */   sb    $t5, -0x5800($t1)
/* 111068 7F0DC538 29414000 */  slti  $at, $t2, 0x4000
.L7F0DC53C:
/* 11106C 7F0DC53C 14200016 */  bnez  $at, .L7F0DC598
/* 111070 7F0DC540 3C198009 */   lui   $t9, %hi(ptr_spectrum_roms) 
/* 111074 7F0DC544 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 111078 7F0DC548 93AF0139 */  lbu   $t7, 0x139($sp)
/* 11107C 7F0DC54C 24180001 */  li    $t8, 1
/* 111080 7F0DC550 032A5821 */  addu  $t3, $t9, $t2
/* 111084 7F0DC554 A16F0000 */  sb    $t7, ($t3)
/* 111088 7F0DC558 97A8013C */  lhu   $t0, 0x13c($sp)
/* 11108C 7F0DC55C 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 111090 7F0DC560 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 111094 7F0DC564 310C1800 */  andi  $t4, $t0, 0x1800
/* 111098 7F0DC568 000C70C3 */  sra   $t6, $t4, 3
/* 11109C 7F0DC56C 310D00FF */  andi  $t5, $t0, 0xff
/* 1110A0 7F0DC570 01CD4825 */  or    $t1, $t6, $t5
/* 1110A4 7F0DC574 03295021 */  addu  $t2, $t9, $t1
/* 1110A8 7F0DC578 10000007 */  b     .L7F0DC598
/* 1110AC 7F0DC57C A1580000 */   sb    $t8, ($t2)
spectrum_op_SET_x_A:
/* 1110B0 7F0DC580 93AF0100 */  lbu   $t7, 0x100($sp)
/* 1110B4 7F0DC584 240B0001 */  li    $t3, 1
/* 1110B8 7F0DC588 01EB6004 */  sllv  $t4, $t3, $t7
/* 1110BC 7F0DC58C 020C8025 */  or    $s0, $s0, $t4
/* 1110C0 7F0DC590 320800FF */  andi  $t0, $s0, 0xff
/* 1110C4 7F0DC594 01008025 */  move  $s0, $t0
.L7F0DC598:
/* 1110C8 7F0DC598 93AE0287 */  lbu   $t6, 0x287($sp)
/* 1110CC 7F0DC59C 93AD013A */  lbu   $t5, 0x13a($sp)
/* 1110D0 7F0DC5A0 11C01896 */  beqz  $t6, .L7F0E27FC
/* 1110D4 7F0DC5A4 2DA10008 */   sltiu $at, $t5, 8
/* 1110D8 7F0DC5A8 10201894 */  beqz  $at, .L7F0E27FC
/* 1110DC 7F0DC5AC 000D6880 */   sll   $t5, $t5, 2
/* 1110E0 7F0DC5B0 3C018006 */  lui   $at, %hi(jpt_8005C68C)
/* 1110E4 7F0DC5B4 002D0821 */  addu  $at, $at, $t5
/* 1110E8 7F0DC5B8 8C2DC68C */  lw    $t5, %lo(jpt_8005C68C)($at)
.L7F0DC5BC:
/* 1110EC 7F0DC5BC 01A00008 */  jr    $t5
/* 1110F0 7F0DC5C0 00000000 */   nop   
.L7F0DC5C4:
/* 1110F4 7F0DC5C4 1000188D */  b     .L7F0E27FC
/* 1110F8 7F0DC5C8 93B20139 */   lbu   $s2, 0x139($sp)
.L7F0DC5CC:
/* 1110FC 7F0DC5CC 1000188B */  b     .L7F0E27FC
/* 111100 7F0DC5D0 93B30139 */   lbu   $s3, 0x139($sp)
.L7F0DC5D4:
/* 111104 7F0DC5D4 10001889 */  b     .L7F0E27FC
/* 111108 7F0DC5D8 93B40139 */   lbu   $s4, 0x139($sp)
.L7F0DC5DC:
/* 11110C 7F0DC5DC 10001887 */  b     .L7F0E27FC
/* 111110 7F0DC5E0 93B50139 */   lbu   $s5, 0x139($sp)
.L7F0DC5E4:
/* 111114 7F0DC5E4 10001885 */  b     .L7F0E27FC
/* 111118 7F0DC5E8 93B60139 */   lbu   $s6, 0x139($sp)
.L7F0DC5EC:
/* 11111C 7F0DC5EC 10001883 */  b     .L7F0E27FC
/* 111120 7F0DC5F0 93B70139 */   lbu   $s7, 0x139($sp)
.L7F0DC5F4:
/* 111124 7F0DC5F4 10001881 */  b     .L7F0E27FC
/* 111128 7F0DC5F8 93B00139 */   lbu   $s0, 0x139($sp)
spectrum_op_CC:
/* 11112C 7F0DC5FC 8FB9028C */  lw    $t9, 0x28c($sp)
/* 111130 7F0DC600 32380040 */  andi  $t8, $s1, 0x40
/* 111134 7F0DC604 2729000A */  addiu $t1, $t9, 0xa
/* 111138 7F0DC608 13000072 */  beqz  $t8, .L7F0DC7D4
/* 11113C 7F0DC60C AFA9028C */   sw    $t1, 0x28c($sp)
/* 111140 7F0DC610 97AF0292 */  lhu   $t7, 0x292($sp)
/* 111144 7F0DC614 252B0007 */  addiu $t3, $t1, 7
/* 111148 7F0DC618 AFAB028C */  sw    $t3, 0x28c($sp)
/* 11114C 7F0DC61C 25ECFFFE */  addiu $t4, $t7, -2
/* 111150 7F0DC620 3188FFFF */  andi  $t0, $t4, 0xffff
/* 111154 7F0DC624 29015B00 */  slti  $at, $t0, 0x5b00
/* 111158 7F0DC628 14200008 */  bnez  $at, .L7F0DC64C
/* 11115C 7F0DC62C A7AC0292 */   sh    $t4, 0x292($sp)
/* 111160 7F0DC630 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 111164 7F0DC634 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 111168 7F0DC638 97AE0298 */  lhu   $t6, 0x298($sp)
/* 11116C 7F0DC63C 03284821 */  addu  $t1, $t9, $t0
/* 111170 7F0DC640 25CD0002 */  addiu $t5, $t6, 2
/* 111174 7F0DC644 10000024 */  b     .L7F0DC6D8
/* 111178 7F0DC648 A12D0000 */   sb    $t5, ($t1)
.L7F0DC64C:
/* 11117C 7F0DC64C 97B80292 */  lhu   $t8, 0x292($sp)
/* 111180 7F0DC650 97A90292 */  lhu   $t1, 0x292($sp)
/* 111184 7F0DC654 97AA0298 */  lhu   $t2, 0x298($sp)
/* 111188 7F0DC658 2B015800 */  slti  $at, $t8, 0x5800
/* 11118C 7F0DC65C 1420000C */  bnez  $at, .L7F0DC690
/* 111190 7F0DC660 3C0F8009 */   lui   $t7, %hi(ptr_spectrum_roms) 
/* 111194 7F0DC664 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 111198 7F0DC668 254B0002 */  addiu $t3, $t2, 2
/* 11119C 7F0DC66C 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 1111A0 7F0DC670 01F86021 */  addu  $t4, $t7, $t8
/* 1111A4 7F0DC674 A18B0000 */  sb    $t3, ($t4)
/* 1111A8 7F0DC678 97A80292 */  lhu   $t0, 0x292($sp)
/* 1111AC 7F0DC67C 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 1111B0 7F0DC680 240E0001 */  li    $t6, 1
/* 1111B4 7F0DC684 03286821 */  addu  $t5, $t9, $t0
/* 1111B8 7F0DC688 10000013 */  b     .L7F0DC6D8
/* 1111BC 7F0DC68C A1AEA800 */   sb    $t6, -0x5800($t5)
.L7F0DC690:
/* 1111C0 7F0DC690 29214000 */  slti  $at, $t1, 0x4000
/* 1111C4 7F0DC694 14200010 */  bnez  $at, .L7F0DC6D8
/* 1111C8 7F0DC698 97AA0298 */   lhu   $t2, 0x298($sp)
/* 1111CC 7F0DC69C 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 1111D0 7F0DC6A0 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 1111D4 7F0DC6A4 254F0002 */  addiu $t7, $t2, 2
/* 1111D8 7F0DC6A8 240C0001 */  li    $t4, 1
/* 1111DC 7F0DC6AC 03095821 */  addu  $t3, $t8, $t1
/* 1111E0 7F0DC6B0 A16F0000 */  sb    $t7, ($t3)
/* 1111E4 7F0DC6B4 97B90292 */  lhu   $t9, 0x292($sp)
/* 1111E8 7F0DC6B8 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 1111EC 7F0DC6BC 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 1111F0 7F0DC6C0 33281800 */  andi  $t0, $t9, 0x1800
/* 1111F4 7F0DC6C4 000870C3 */  sra   $t6, $t0, 3
/* 1111F8 7F0DC6C8 332D00FF */  andi  $t5, $t9, 0xff
/* 1111FC 7F0DC6CC 01CD5025 */  or    $t2, $t6, $t5
/* 111200 7F0DC6D0 030A4821 */  addu  $t1, $t8, $t2
/* 111204 7F0DC6D4 A12C0000 */  sb    $t4, ($t1)
.L7F0DC6D8:
/* 111208 7F0DC6D8 97AF0292 */  lhu   $t7, 0x292($sp)
/* 11120C 7F0DC6DC 97AA0292 */  lhu   $t2, 0x292($sp)
/* 111210 7F0DC6E0 97A80298 */  lhu   $t0, 0x298($sp)
/* 111214 7F0DC6E4 25EB0001 */  addiu $t3, $t7, 1
/* 111218 7F0DC6E8 29615B00 */  slti  $at, $t3, 0x5b00
/* 11121C 7F0DC6EC 14200008 */  bnez  $at, .L7F0DC710
/* 111220 7F0DC6F0 254C0001 */   addiu $t4, $t2, 1
/* 111224 7F0DC6F4 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 111228 7F0DC6F8 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 11122C 7F0DC6FC 25190002 */  addiu $t9, $t0, 2
/* 111230 7F0DC700 00197203 */  sra   $t6, $t9, 8
/* 111234 7F0DC704 01AFC021 */  addu  $t8, $t5, $t7
/* 111238 7F0DC708 10000027 */  b     .L7F0DC7A8
/* 11123C 7F0DC70C A30E0001 */   sb    $t6, 1($t8)
.L7F0DC710:
/* 111240 7F0DC710 29815800 */  slti  $at, $t4, 0x5800
/* 111244 7F0DC714 1420000F */  bnez  $at, .L7F0DC754
/* 111248 7F0DC718 97A90292 */   lhu   $t1, 0x292($sp)
/* 11124C 7F0DC71C 97A90298 */  lhu   $t1, 0x298($sp)
/* 111250 7F0DC720 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 111254 7F0DC724 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 111258 7F0DC728 252B0002 */  addiu $t3, $t1, 2
/* 11125C 7F0DC72C 000B4203 */  sra   $t0, $t3, 8
/* 111260 7F0DC730 032A6821 */  addu  $t5, $t9, $t2
/* 111264 7F0DC734 A1A80001 */  sb    $t0, 1($t5)
/* 111268 7F0DC738 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 11126C 7F0DC73C 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 111270 7F0DC740 97B80292 */  lhu   $t8, 0x292($sp)
/* 111274 7F0DC744 240F0001 */  li    $t7, 1
/* 111278 7F0DC748 01D86021 */  addu  $t4, $t6, $t8
/* 11127C 7F0DC74C 10000016 */  b     .L7F0DC7A8
/* 111280 7F0DC750 A18FA801 */   sb    $t7, -0x57ff($t4)
.L7F0DC754:
/* 111284 7F0DC754 252B0001 */  addiu $t3, $t1, 1
/* 111288 7F0DC758 29614000 */  slti  $at, $t3, 0x4000
/* 11128C 7F0DC75C 14200012 */  bnez  $at, .L7F0DC7A8
/* 111290 7F0DC760 97B90298 */   lhu   $t9, 0x298($sp)
/* 111294 7F0DC764 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 111298 7F0DC768 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 11129C 7F0DC76C 272A0002 */  addiu $t2, $t9, 2
/* 1112A0 7F0DC770 000A4203 */  sra   $t0, $t2, 8
/* 1112A4 7F0DC774 01A97021 */  addu  $t6, $t5, $t1
/* 1112A8 7F0DC778 A1C80001 */  sb    $t0, 1($t6)
/* 1112AC 7F0DC77C 97AF0292 */  lhu   $t7, 0x292($sp)
/* 1112B0 7F0DC780 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 1112B4 7F0DC784 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 1112B8 7F0DC788 25EC0001 */  addiu $t4, $t7, 1
/* 1112BC 7F0DC78C 318B1800 */  andi  $t3, $t4, 0x1800
/* 1112C0 7F0DC790 000BC8C3 */  sra   $t9, $t3, 3
/* 1112C4 7F0DC794 318A00FF */  andi  $t2, $t4, 0xff
/* 1112C8 7F0DC798 032A6825 */  or    $t5, $t9, $t2
/* 1112CC 7F0DC79C 24180001 */  li    $t8, 1
/* 1112D0 7F0DC7A0 012D4021 */  addu  $t0, $t1, $t5
/* 1112D4 7F0DC7A4 A1180000 */  sb    $t8, ($t0)
.L7F0DC7A8:
/* 1112D8 7F0DC7A8 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 1112DC 7F0DC7AC 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 1112E0 7F0DC7B0 97AE0298 */  lhu   $t6, 0x298($sp)
/* 1112E4 7F0DC7B4 01EEC821 */  addu  $t9, $t7, $t6
/* 1112E8 7F0DC7B8 932A0001 */  lbu   $t2, 1($t9)
/* 1112EC 7F0DC7BC 01CF5821 */  addu  $t3, $t6, $t7
/* 1112F0 7F0DC7C0 916C0000 */  lbu   $t4, ($t3)
/* 1112F4 7F0DC7C4 000A4A00 */  sll   $t1, $t2, 8
/* 1112F8 7F0DC7C8 01896825 */  or    $t5, $t4, $t1
/* 1112FC 7F0DC7CC 1000180B */  b     .L7F0E27FC
/* 111300 7F0DC7D0 A7AD0298 */   sh    $t5, 0x298($sp)
.L7F0DC7D4:
/* 111304 7F0DC7D4 97B80298 */  lhu   $t8, 0x298($sp)
/* 111308 7F0DC7D8 27080002 */  addiu $t0, $t8, 2
/* 11130C 7F0DC7DC 10001807 */  b     .L7F0E27FC
/* 111310 7F0DC7E0 A7A80298 */   sh    $t0, 0x298($sp)
spectrum_op_CD:
/* 111314 7F0DC7E4 8FAB028C */  lw    $t3, 0x28c($sp)
/* 111318 7F0DC7E8 97AA0292 */  lhu   $t2, 0x292($sp)
/* 11131C 7F0DC7EC 97AD0298 */  lhu   $t5, 0x298($sp)
/* 111320 7F0DC7F0 256F000A */  addiu $t7, $t3, 0xa
/* 111324 7F0DC7F4 254CFFFE */  addiu $t4, $t2, -2
/* 111328 7F0DC7F8 3189FFFF */  andi  $t1, $t4, 0xffff
/* 11132C 7F0DC7FC AFAF028C */  sw    $t7, 0x28c($sp)
/* 111330 7F0DC800 29215B00 */  slti  $at, $t1, 0x5b00
/* 111334 7F0DC804 25F90007 */  addiu $t9, $t7, 7
/* 111338 7F0DC808 AFB9028C */  sw    $t9, 0x28c($sp)
/* 11133C 7F0DC80C 14200007 */  bnez  $at, .L7F0DC82C
/* 111340 7F0DC810 A7AC0292 */   sh    $t4, 0x292($sp)
/* 111344 7F0DC814 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 111348 7F0DC818 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 11134C 7F0DC81C 25B80002 */  addiu $t8, $t5, 2
/* 111350 7F0DC820 01095821 */  addu  $t3, $t0, $t1
/* 111354 7F0DC824 10000024 */  b     .L7F0DC8B8
/* 111358 7F0DC828 A1780000 */   sb    $t8, ($t3)
.L7F0DC82C:
/* 11135C 7F0DC82C 97AF0292 */  lhu   $t7, 0x292($sp)
/* 111360 7F0DC830 97AB0292 */  lhu   $t3, 0x292($sp)
/* 111364 7F0DC834 97AE0298 */  lhu   $t6, 0x298($sp)
/* 111368 7F0DC838 29E15800 */  slti  $at, $t7, 0x5800
/* 11136C 7F0DC83C 1420000C */  bnez  $at, .L7F0DC870
/* 111370 7F0DC840 3C0A8009 */   lui   $t2, %hi(ptr_spectrum_roms) 
/* 111374 7F0DC844 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 111378 7F0DC848 25D90002 */  addiu $t9, $t6, 2
/* 11137C 7F0DC84C 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 111380 7F0DC850 014F6021 */  addu  $t4, $t2, $t7
/* 111384 7F0DC854 A1990000 */  sb    $t9, ($t4)
/* 111388 7F0DC858 97A90292 */  lhu   $t1, 0x292($sp)
/* 11138C 7F0DC85C 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 111390 7F0DC860 240D0001 */  li    $t5, 1
/* 111394 7F0DC864 0109C021 */  addu  $t8, $t0, $t1
/* 111398 7F0DC868 10000013 */  b     .L7F0DC8B8
/* 11139C 7F0DC86C A30DA800 */   sb    $t5, -0x5800($t8)
.L7F0DC870:
/* 1113A0 7F0DC870 29614000 */  slti  $at, $t3, 0x4000
/* 1113A4 7F0DC874 14200010 */  bnez  $at, .L7F0DC8B8
/* 1113A8 7F0DC878 97AE0298 */   lhu   $t6, 0x298($sp)
/* 1113AC 7F0DC87C 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 1113B0 7F0DC880 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 1113B4 7F0DC884 25CA0002 */  addiu $t2, $t6, 2
/* 1113B8 7F0DC888 240C0001 */  li    $t4, 1
/* 1113BC 7F0DC88C 01EBC821 */  addu  $t9, $t7, $t3
/* 1113C0 7F0DC890 A32A0000 */  sb    $t2, ($t9)
/* 1113C4 7F0DC894 97A80292 */  lhu   $t0, 0x292($sp)
/* 1113C8 7F0DC898 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 1113CC 7F0DC89C 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 1113D0 7F0DC8A0 31091800 */  andi  $t1, $t0, 0x1800
/* 1113D4 7F0DC8A4 000968C3 */  sra   $t5, $t1, 3
/* 1113D8 7F0DC8A8 311800FF */  andi  $t8, $t0, 0xff
/* 1113DC 7F0DC8AC 01B87025 */  or    $t6, $t5, $t8
/* 1113E0 7F0DC8B0 01EE5821 */  addu  $t3, $t7, $t6
/* 1113E4 7F0DC8B4 A16C0000 */  sb    $t4, ($t3)
.L7F0DC8B8:
/* 1113E8 7F0DC8B8 97AA0292 */  lhu   $t2, 0x292($sp)
/* 1113EC 7F0DC8BC 97AE0292 */  lhu   $t6, 0x292($sp)
/* 1113F0 7F0DC8C0 97A90298 */  lhu   $t1, 0x298($sp)
/* 1113F4 7F0DC8C4 25590001 */  addiu $t9, $t2, 1
/* 1113F8 7F0DC8C8 2B215B00 */  slti  $at, $t9, 0x5b00
/* 1113FC 7F0DC8CC 14200008 */  bnez  $at, .L7F0DC8F0
/* 111400 7F0DC8D0 25CC0001 */   addiu $t4, $t6, 1
/* 111404 7F0DC8D4 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 111408 7F0DC8D8 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 11140C 7F0DC8DC 25280002 */  addiu $t0, $t1, 2
/* 111410 7F0DC8E0 00086A03 */  sra   $t5, $t0, 8
/* 111414 7F0DC8E4 030A7821 */  addu  $t7, $t8, $t2
/* 111418 7F0DC8E8 10000027 */  b     .L7F0DC988
/* 11141C 7F0DC8EC A1ED0001 */   sb    $t5, 1($t7)
.L7F0DC8F0:
/* 111420 7F0DC8F0 29815800 */  slti  $at, $t4, 0x5800
/* 111424 7F0DC8F4 1420000F */  bnez  $at, .L7F0DC934
/* 111428 7F0DC8F8 97AB0292 */   lhu   $t3, 0x292($sp)
/* 11142C 7F0DC8FC 97AB0298 */  lhu   $t3, 0x298($sp)
/* 111430 7F0DC900 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 111434 7F0DC904 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 111438 7F0DC908 25790002 */  addiu $t9, $t3, 2
/* 11143C 7F0DC90C 00194A03 */  sra   $t1, $t9, 8
/* 111440 7F0DC910 010EC021 */  addu  $t8, $t0, $t6
/* 111444 7F0DC914 A3090001 */  sb    $t1, 1($t8)
/* 111448 7F0DC918 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 11144C 7F0DC91C 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 111450 7F0DC920 97AF0292 */  lhu   $t7, 0x292($sp)
/* 111454 7F0DC924 240A0001 */  li    $t2, 1
/* 111458 7F0DC928 01AF6021 */  addu  $t4, $t5, $t7
/* 11145C 7F0DC92C 10000016 */  b     .L7F0DC988
/* 111460 7F0DC930 A18AA801 */   sb    $t2, -0x57ff($t4)
.L7F0DC934:
/* 111464 7F0DC934 25790001 */  addiu $t9, $t3, 1
/* 111468 7F0DC938 2B214000 */  slti  $at, $t9, 0x4000
/* 11146C 7F0DC93C 14200012 */  bnez  $at, .L7F0DC988
/* 111470 7F0DC940 97A80298 */   lhu   $t0, 0x298($sp)
/* 111474 7F0DC944 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 111478 7F0DC948 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 11147C 7F0DC94C 250E0002 */  addiu $t6, $t0, 2
/* 111480 7F0DC950 000E4A03 */  sra   $t1, $t6, 8
/* 111484 7F0DC954 030B6821 */  addu  $t5, $t8, $t3
/* 111488 7F0DC958 A1A90001 */  sb    $t1, 1($t5)
/* 11148C 7F0DC95C 97AA0292 */  lhu   $t2, 0x292($sp)
/* 111490 7F0DC960 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 111494 7F0DC964 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 111498 7F0DC968 254C0001 */  addiu $t4, $t2, 1
/* 11149C 7F0DC96C 31991800 */  andi  $t9, $t4, 0x1800
/* 1114A0 7F0DC970 001940C3 */  sra   $t0, $t9, 3
/* 1114A4 7F0DC974 318E00FF */  andi  $t6, $t4, 0xff
/* 1114A8 7F0DC978 010EC025 */  or    $t8, $t0, $t6
/* 1114AC 7F0DC97C 240F0001 */  li    $t7, 1
/* 1114B0 7F0DC980 01784821 */  addu  $t1, $t3, $t8
/* 1114B4 7F0DC984 A12F0000 */  sb    $t7, ($t1)
.L7F0DC988:
/* 1114B8 7F0DC988 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 1114BC 7F0DC98C 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 1114C0 7F0DC990 97AD0298 */  lhu   $t5, 0x298($sp)
/* 1114C4 7F0DC994 014D4021 */  addu  $t0, $t2, $t5
/* 1114C8 7F0DC998 910E0001 */  lbu   $t6, 1($t0)
/* 1114CC 7F0DC99C 01AAC821 */  addu  $t9, $t5, $t2
/* 1114D0 7F0DC9A0 932C0000 */  lbu   $t4, ($t9)
/* 1114D4 7F0DC9A4 000E5A00 */  sll   $t3, $t6, 8
/* 1114D8 7F0DC9A8 018BC025 */  or    $t8, $t4, $t3
/* 1114DC 7F0DC9AC 10001793 */  b     .L7F0E27FC
/* 1114E0 7F0DC9B0 A7B80298 */   sh    $t8, 0x298($sp)
spectrum_op_CE:
/* 1114E4 7F0DC9B4 8FAF028C */  lw    $t7, 0x28c($sp)
/* 1114E8 7F0DC9B8 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 1114EC 7F0DC9BC 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 1114F0 7F0DC9C0 97B90298 */  lhu   $t9, 0x298($sp)
/* 1114F4 7F0DC9C4 25E90007 */  addiu $t1, $t7, 7
/* 1114F8 7F0DC9C8 AFA9028C */  sw    $t1, 0x28c($sp)
/* 1114FC 7F0DC9CC 032A6821 */  addu  $t5, $t9, $t2
/* 111500 7F0DC9D0 91A80000 */  lbu   $t0, ($t5)
/* 111504 7F0DC9D4 322C0001 */  andi  $t4, $s1, 1
/* 111508 7F0DC9D8 32380001 */  andi  $t8, $s1, 1
/* 11150C 7F0DC9DC 02087021 */  addu  $t6, $s0, $t0
/* 111510 7F0DC9E0 01CC5821 */  addu  $t3, $t6, $t4
/* 111514 7F0DC9E4 320E000F */  andi  $t6, $s0, 0xf
/* 111518 7F0DC9E8 310D000F */  andi  $t5, $t0, 0xf
/* 11151C 7F0DC9EC 01CD6021 */  addu  $t4, $t6, $t5
/* 111520 7F0DC9F0 316F00A8 */  andi  $t7, $t3, 0xa8
/* 111524 7F0DC9F4 000BCA03 */  sra   $t9, $t3, 8
/* 111528 7F0DC9F8 01F95025 */  or    $t2, $t7, $t9
/* 11152C 7F0DC9FC 01984821 */  addu  $t1, $t4, $t8
/* 111530 7F0DCA00 2401000F */  li    $at, 15
/* 111534 7F0DCA04 0029782A */  slt   $t7, $at, $t1
/* 111538 7F0DCA08 000FC900 */  sll   $t9, $t7, 4
/* 11153C 7F0DCA0C 01604825 */  move  $t1, $t3
/* 111540 7F0DCA10 02006827 */  not   $t5, $s0
/* 111544 7F0DCA14 01307826 */  xor   $t7, $t1, $s0
/* 111548 7F0DCA18 A7AB00FE */  sh    $t3, 0xfe($sp)
/* 11154C 7F0DCA1C 01A86026 */  xor   $t4, $t5, $t0
/* 111550 7F0DCA20 93B000FF */  lbu   $s0, 0xff($sp)
/* 111554 7F0DCA24 31980080 */  andi  $t8, $t4, 0x80
/* 111558 7F0DCA28 01597025 */  or    $t6, $t2, $t9
/* 11155C 7F0DCA2C 030F5024 */  and   $t2, $t8, $t7
/* 111560 7F0DCA30 A3A800FD */  sb    $t0, 0xfd($sp)
/* 111564 7F0DCA34 97B80298 */  lhu   $t8, 0x298($sp)
/* 111568 7F0DCA38 000AC943 */  sra   $t9, $t2, 5
/* 11156C 7F0DCA3C 2E080001 */  sltiu $t0, $s0, 1
/* 111570 7F0DCA40 00085980 */  sll   $t3, $t0, 6
/* 111574 7F0DCA44 01D96825 */  or    $t5, $t6, $t9
/* 111578 7F0DCA48 01AB8825 */  or    $s1, $t5, $t3
/* 11157C 7F0DCA4C 322900FF */  andi  $t1, $s1, 0xff
/* 111580 7F0DCA50 270F0001 */  addiu $t7, $t8, 1
/* 111584 7F0DCA54 01208825 */  move  $s1, $t1
/* 111588 7F0DCA58 AFA80048 */  sw    $t0, 0x48($sp)
/* 11158C 7F0DCA5C 10001767 */  b     .L7F0E27FC
/* 111590 7F0DCA60 A7AF0298 */   sh    $t7, 0x298($sp)
spectrum_op_CF:
/* 111594 7F0DCA64 97B90292 */  lhu   $t9, 0x292($sp)
/* 111598 7F0DCA68 8FAA028C */  lw    $t2, 0x28c($sp)
/* 11159C 7F0DCA6C 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 1115A0 7F0DCA70 272DFFFE */  addiu $t5, $t9, -2
/* 1115A4 7F0DCA74 31A8FFFF */  andi  $t0, $t5, 0xffff
/* 1115A8 7F0DCA78 29015B00 */  slti  $at, $t0, 0x5b00
/* 1115AC 7F0DCA7C 254E000B */  addiu $t6, $t2, 0xb
/* 1115B0 7F0DCA80 AFAE028C */  sw    $t6, 0x28c($sp)
/* 1115B4 7F0DCA84 14200006 */  bnez  $at, .L7F0DCAA0
/* 1115B8 7F0DCA88 A7AD0292 */   sh    $t5, 0x292($sp)
/* 1115BC 7F0DCA8C 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 1115C0 7F0DCA90 97AC0298 */  lhu   $t4, 0x298($sp)
/* 1115C4 7F0DCA94 01684821 */  addu  $t1, $t3, $t0
/* 1115C8 7F0DCA98 10000023 */  b     .L7F0DCB28
/* 1115CC 7F0DCA9C A12C0000 */   sb    $t4, ($t1)
.L7F0DCAA0:
/* 1115D0 7F0DCAA0 97B80292 */  lhu   $t8, 0x292($sp)
/* 1115D4 7F0DCAA4 97AC0292 */  lhu   $t4, 0x292($sp)
/* 1115D8 7F0DCAA8 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 1115DC 7F0DCAAC 2B015800 */  slti  $at, $t8, 0x5800
/* 1115E0 7F0DCAB0 5420000D */  bnezl $at, .L7F0DCAE8
/* 1115E4 7F0DCAB4 29814000 */   slti  $at, $t4, 0x4000
/* 1115E8 7F0DCAB8 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 1115EC 7F0DCABC 97AF0298 */  lhu   $t7, 0x298($sp)
/* 1115F0 7F0DCAC0 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 1115F4 7F0DCAC4 01587021 */  addu  $t6, $t2, $t8
/* 1115F8 7F0DCAC8 A1CF0000 */  sb    $t7, ($t6)
/* 1115FC 7F0DCACC 97AB0292 */  lhu   $t3, 0x292($sp)
/* 111600 7F0DCAD0 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 111604 7F0DCAD4 24190001 */  li    $t9, 1
/* 111608 7F0DCAD8 01AB4021 */  addu  $t0, $t5, $t3
/* 11160C 7F0DCADC 10000012 */  b     .L7F0DCB28
/* 111610 7F0DCAE0 A119A800 */   sb    $t9, -0x5800($t0)
/* 111614 7F0DCAE4 29814000 */  slti  $at, $t4, 0x4000
.L7F0DCAE8:
/* 111618 7F0DCAE8 1420000F */  bnez  $at, .L7F0DCB28
/* 11161C 7F0DCAEC 3C0A8009 */   lui   $t2, %hi(ptr_spectrum_roms) 
/* 111620 7F0DCAF0 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 111624 7F0DCAF4 97A90298 */  lhu   $t1, 0x298($sp)
/* 111628 7F0DCAF8 240F0001 */  li    $t7, 1
/* 11162C 7F0DCAFC 014CC021 */  addu  $t8, $t2, $t4
/* 111630 7F0DCB00 A3090000 */  sb    $t1, ($t8)
/* 111634 7F0DCB04 97AE0292 */  lhu   $t6, 0x292($sp)
/* 111638 7F0DCB08 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 11163C 7F0DCB0C 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 111640 7F0DCB10 31CD1800 */  andi  $t5, $t6, 0x1800
/* 111644 7F0DCB14 000D58C3 */  sra   $t3, $t5, 3
/* 111648 7F0DCB18 31D900FF */  andi  $t9, $t6, 0xff
/* 11164C 7F0DCB1C 01794025 */  or    $t0, $t3, $t9
/* 111650 7F0DCB20 01486021 */  addu  $t4, $t2, $t0
/* 111654 7F0DCB24 A18F0000 */  sb    $t7, ($t4)
.L7F0DCB28:
/* 111658 7F0DCB28 97A90292 */  lhu   $t1, 0x292($sp)
/* 11165C 7F0DCB2C 97AA0292 */  lhu   $t2, 0x292($sp)
/* 111660 7F0DCB30 97AD0298 */  lhu   $t5, 0x298($sp)
/* 111664 7F0DCB34 25380001 */  addiu $t8, $t1, 1
/* 111668 7F0DCB38 2B015B00 */  slti  $at, $t8, 0x5b00
/* 11166C 7F0DCB3C 14200007 */  bnez  $at, .L7F0DCB5C
/* 111670 7F0DCB40 25480001 */   addiu $t0, $t2, 1
/* 111674 7F0DCB44 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 111678 7F0DCB48 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 11167C 7F0DCB4C 000D7203 */  sra   $t6, $t5, 8
/* 111680 7F0DCB50 0169C821 */  addu  $t9, $t3, $t1
/* 111684 7F0DCB54 10000025 */  b     .L7F0DCBEC
/* 111688 7F0DCB58 A32E0001 */   sb    $t6, 1($t9)
.L7F0DCB5C:
/* 11168C 7F0DCB5C 29015800 */  slti  $at, $t0, 0x5800
/* 111690 7F0DCB60 1420000E */  bnez  $at, .L7F0DCB9C
/* 111694 7F0DCB64 97A80292 */   lhu   $t0, 0x292($sp)
/* 111698 7F0DCB68 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 11169C 7F0DCB6C 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 1116A0 7F0DCB70 97AF0298 */  lhu   $t7, 0x298($sp)
/* 1116A4 7F0DCB74 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 1116A8 7F0DCB78 030A6821 */  addu  $t5, $t8, $t2
/* 1116AC 7F0DCB7C 000F6203 */  sra   $t4, $t7, 8
/* 1116B0 7F0DCB80 A1AC0001 */  sb    $t4, 1($t5)
/* 1116B4 7F0DCB84 97AE0292 */  lhu   $t6, 0x292($sp)
/* 1116B8 7F0DCB88 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 1116BC 7F0DCB8C 240B0001 */  li    $t3, 1
/* 1116C0 7F0DCB90 012EC821 */  addu  $t9, $t1, $t6
/* 1116C4 7F0DCB94 10000015 */  b     .L7F0DCBEC
/* 1116C8 7F0DCB98 A32BA801 */   sb    $t3, -0x57ff($t9)
.L7F0DCB9C:
/* 1116CC 7F0DCB9C 250F0001 */  addiu $t7, $t0, 1
/* 1116D0 7F0DCBA0 29E14000 */  slti  $at, $t7, 0x4000
/* 1116D4 7F0DCBA4 14200011 */  bnez  $at, .L7F0DCBEC
/* 1116D8 7F0DCBA8 97B80298 */   lhu   $t8, 0x298($sp)
/* 1116DC 7F0DCBAC 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 1116E0 7F0DCBB0 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 1116E4 7F0DCBB4 00185203 */  sra   $t2, $t8, 8
/* 1116E8 7F0DCBB8 24090001 */  li    $t1, 1
/* 1116EC 7F0DCBBC 01886821 */  addu  $t5, $t4, $t0
/* 1116F0 7F0DCBC0 A1AA0001 */  sb    $t2, 1($t5)
/* 1116F4 7F0DCBC4 97AE0292 */  lhu   $t6, 0x292($sp)
/* 1116F8 7F0DCBC8 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 1116FC 7F0DCBCC 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 111700 7F0DCBD0 25CB0001 */  addiu $t3, $t6, 1
/* 111704 7F0DCBD4 31791800 */  andi  $t9, $t3, 0x1800
/* 111708 7F0DCBD8 001978C3 */  sra   $t7, $t9, 3
/* 11170C 7F0DCBDC 317800FF */  andi  $t8, $t3, 0xff
/* 111710 7F0DCBE0 01F86025 */  or    $t4, $t7, $t8
/* 111714 7F0DCBE4 010C5021 */  addu  $t2, $t0, $t4
/* 111718 7F0DCBE8 A1490000 */  sb    $t1, ($t2)
.L7F0DCBEC:
/* 11171C 7F0DCBEC 240D0008 */  li    $t5, 8
/* 111720 7F0DCBF0 10001702 */  b     .L7F0E27FC
/* 111724 7F0DCBF4 A7AD0298 */   sh    $t5, 0x298($sp)
spectrum_op_D0:
/* 111728 7F0DCBF8 8FAE028C */  lw    $t6, 0x28c($sp)
/* 11172C 7F0DCBFC 322B0001 */  andi  $t3, $s1, 1
/* 111730 7F0DCC00 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 111734 7F0DCC04 25D90005 */  addiu $t9, $t6, 5
/* 111738 7F0DCC08 156016FC */  bnez  $t3, .L7F0E27FC
/* 11173C 7F0DCC0C AFB9028C */   sw    $t9, 0x28c($sp)
/* 111740 7F0DCC10 97A80292 */  lhu   $t0, 0x292($sp)
/* 111744 7F0DCC14 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 111748 7F0DCC18 27380006 */  addiu $t8, $t9, 6
/* 11174C 7F0DCC1C AFB8028C */  sw    $t8, 0x28c($sp)
/* 111750 7F0DCC20 01886821 */  addu  $t5, $t4, $t0
/* 111754 7F0DCC24 91AE0001 */  lbu   $t6, 1($t5)
/* 111758 7F0DCC28 010C4821 */  addu  $t1, $t0, $t4
/* 11175C 7F0DCC2C 912A0000 */  lbu   $t2, ($t1)
/* 111760 7F0DCC30 000ECA00 */  sll   $t9, $t6, 8
/* 111764 7F0DCC34 250F0002 */  addiu $t7, $t0, 2
/* 111768 7F0DCC38 01595825 */  or    $t3, $t2, $t9
/* 11176C 7F0DCC3C A7AB0298 */  sh    $t3, 0x298($sp)
/* 111770 7F0DCC40 100016EE */  b     .L7F0E27FC
/* 111774 7F0DCC44 A7AF0292 */   sh    $t7, 0x292($sp)
spectrum_op_D1:
/* 111778 7F0DCC48 8FB8028C */  lw    $t8, 0x28c($sp)
/* 11177C 7F0DCC4C 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 111780 7F0DCC50 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 111784 7F0DCC54 97AC0292 */  lhu   $t4, 0x292($sp)
/* 111788 7F0DCC58 2709000A */  addiu $t1, $t8, 0xa
/* 11178C 7F0DCC5C AFA9028C */  sw    $t1, 0x28c($sp)
/* 111790 7F0DCC60 018D7021 */  addu  $t6, $t4, $t5
/* 111794 7F0DCC64 91D50000 */  lbu   $s5, ($t6)
/* 111798 7F0DCC68 91D40001 */  lbu   $s4, 1($t6)
/* 11179C 7F0DCC6C 258A0002 */  addiu $t2, $t4, 2
/* 1117A0 7F0DCC70 100016E2 */  b     .L7F0E27FC
/* 1117A4 7F0DCC74 A7AA0292 */   sh    $t2, 0x292($sp)
spectrum_op_D2:
/* 1117A8 7F0DCC78 8FB9028C */  lw    $t9, 0x28c($sp)
/* 1117AC 7F0DCC7C 32280001 */  andi  $t0, $s1, 1
/* 1117B0 7F0DCC80 97AF0298 */  lhu   $t7, 0x298($sp)
/* 1117B4 7F0DCC84 272B000A */  addiu $t3, $t9, 0xa
/* 1117B8 7F0DCC88 1500000B */  bnez  $t0, .L7F0DCCB8
/* 1117BC 7F0DCC8C AFAB028C */   sw    $t3, 0x28c($sp)
/* 1117C0 7F0DCC90 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 1117C4 7F0DCC94 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 1117C8 7F0DCC98 030F7021 */  addu  $t6, $t8, $t7
/* 1117CC 7F0DCC9C 91CC0001 */  lbu   $t4, 1($t6)
/* 1117D0 7F0DCCA0 01F84821 */  addu  $t1, $t7, $t8
/* 1117D4 7F0DCCA4 912D0000 */  lbu   $t5, ($t1)
/* 1117D8 7F0DCCA8 000C5200 */  sll   $t2, $t4, 8
/* 1117DC 7F0DCCAC 01AAC825 */  or    $t9, $t5, $t2
/* 1117E0 7F0DCCB0 100016D2 */  b     .L7F0E27FC
/* 1117E4 7F0DCCB4 A7B90298 */   sh    $t9, 0x298($sp)
.L7F0DCCB8:
/* 1117E8 7F0DCCB8 97AB0298 */  lhu   $t3, 0x298($sp)
/* 1117EC 7F0DCCBC 25680002 */  addiu $t0, $t3, 2
/* 1117F0 7F0DCCC0 100016CE */  b     .L7F0E27FC
/* 1117F4 7F0DCCC4 A7A80298 */   sh    $t0, 0x298($sp)
spectrum_op_D3:
/* 1117F8 7F0DCCC8 8FA9028C */  lw    $t1, 0x28c($sp)
/* 1117FC 7F0DCCCC 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 111800 7F0DCCD0 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 111804 7F0DCCD4 97AF0298 */  lhu   $t7, 0x298($sp)
/* 111808 7F0DCCD8 2524000B */  addiu $a0, $t1, 0xb
/* 11180C 7F0DCCDC AFA4028C */  sw    $a0, 0x28c($sp)
/* 111810 7F0DCCE0 01EE6021 */  addu  $t4, $t7, $t6
/* 111814 7F0DCCE4 91860000 */  lbu   $a2, ($t4)
/* 111818 7F0DCCE8 02002825 */  move  $a1, $s0
/* 11181C 7F0DCCEC 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 111820 7F0DCCF0 02003825 */   move  $a3, $s0
/* 111824 7F0DCCF4 8FAD028C */  lw    $t5, 0x28c($sp)
/* 111828 7F0DCCF8 97AB0298 */  lhu   $t3, 0x298($sp)
/* 11182C 7F0DCCFC AFA20048 */  sw    $v0, 0x48($sp)
/* 111830 7F0DCD00 01A2C821 */  addu  $t9, $t5, $v0
/* 111834 7F0DCD04 25680001 */  addiu $t0, $t3, 1
/* 111838 7F0DCD08 AFB9028C */  sw    $t9, 0x28c($sp)
/* 11183C 7F0DCD0C 100016BB */  b     .L7F0E27FC
/* 111840 7F0DCD10 A7A80298 */   sh    $t0, 0x298($sp)
spectrum_op_D4:
/* 111844 7F0DCD14 8FA9028C */  lw    $t1, 0x28c($sp)
/* 111848 7F0DCD18 322F0001 */  andi  $t7, $s1, 1
/* 11184C 7F0DCD1C 2538000A */  addiu $t8, $t1, 0xa
/* 111850 7F0DCD20 15E00072 */  bnez  $t7, .L7F0DCEEC
/* 111854 7F0DCD24 AFB8028C */   sw    $t8, 0x28c($sp)
/* 111858 7F0DCD28 97AD0292 */  lhu   $t5, 0x292($sp)
/* 11185C 7F0DCD2C 270C0007 */  addiu $t4, $t8, 7
/* 111860 7F0DCD30 AFAC028C */  sw    $t4, 0x28c($sp)
/* 111864 7F0DCD34 25AAFFFE */  addiu $t2, $t5, -2
/* 111868 7F0DCD38 3159FFFF */  andi  $t9, $t2, 0xffff
/* 11186C 7F0DCD3C 2B215B00 */  slti  $at, $t9, 0x5b00
/* 111870 7F0DCD40 14200008 */  bnez  $at, .L7F0DCD64
/* 111874 7F0DCD44 A7AA0292 */   sh    $t2, 0x292($sp)
/* 111878 7F0DCD48 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 11187C 7F0DCD4C 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 111880 7F0DCD50 97AB0298 */  lhu   $t3, 0x298($sp)
/* 111884 7F0DCD54 0139C021 */  addu  $t8, $t1, $t9
/* 111888 7F0DCD58 25680002 */  addiu $t0, $t3, 2
/* 11188C 7F0DCD5C 10000024 */  b     .L7F0DCDF0
/* 111890 7F0DCD60 A3080000 */   sb    $t0, ($t8)
.L7F0DCD64:
/* 111894 7F0DCD64 97AF0292 */  lhu   $t7, 0x292($sp)
/* 111898 7F0DCD68 97B80292 */  lhu   $t8, 0x292($sp)
/* 11189C 7F0DCD6C 97AE0298 */  lhu   $t6, 0x298($sp)
/* 1118A0 7F0DCD70 29E15800 */  slti  $at, $t7, 0x5800
/* 1118A4 7F0DCD74 1420000C */  bnez  $at, .L7F0DCDA8
/* 1118A8 7F0DCD78 3C0D8009 */   lui   $t5, %hi(ptr_spectrum_roms) 
/* 1118AC 7F0DCD7C 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 1118B0 7F0DCD80 25CC0002 */  addiu $t4, $t6, 2
/* 1118B4 7F0DCD84 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 1118B8 7F0DCD88 01AF5021 */  addu  $t2, $t5, $t7
/* 1118BC 7F0DCD8C A14C0000 */  sb    $t4, ($t2)
/* 1118C0 7F0DCD90 97B90292 */  lhu   $t9, 0x292($sp)
/* 1118C4 7F0DCD94 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 1118C8 7F0DCD98 240B0001 */  li    $t3, 1
/* 1118CC 7F0DCD9C 01394021 */  addu  $t0, $t1, $t9
/* 1118D0 7F0DCDA0 10000013 */  b     .L7F0DCDF0
/* 1118D4 7F0DCDA4 A10BA800 */   sb    $t3, -0x5800($t0)
.L7F0DCDA8:
/* 1118D8 7F0DCDA8 2B014000 */  slti  $at, $t8, 0x4000
/* 1118DC 7F0DCDAC 14200010 */  bnez  $at, .L7F0DCDF0
/* 1118E0 7F0DCDB0 97AE0298 */   lhu   $t6, 0x298($sp)
/* 1118E4 7F0DCDB4 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 1118E8 7F0DCDB8 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 1118EC 7F0DCDBC 25CD0002 */  addiu $t5, $t6, 2
/* 1118F0 7F0DCDC0 240A0001 */  li    $t2, 1
/* 1118F4 7F0DCDC4 01F86021 */  addu  $t4, $t7, $t8
/* 1118F8 7F0DCDC8 A18D0000 */  sb    $t5, ($t4)
/* 1118FC 7F0DCDCC 97A90292 */  lhu   $t1, 0x292($sp)
/* 111900 7F0DCDD0 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 111904 7F0DCDD4 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 111908 7F0DCDD8 31391800 */  andi  $t9, $t1, 0x1800
/* 11190C 7F0DCDDC 001958C3 */  sra   $t3, $t9, 3
/* 111910 7F0DCDE0 312800FF */  andi  $t0, $t1, 0xff
/* 111914 7F0DCDE4 01687025 */  or    $t6, $t3, $t0
/* 111918 7F0DCDE8 01EEC021 */  addu  $t8, $t7, $t6
/* 11191C 7F0DCDEC A30A0000 */  sb    $t2, ($t8)
.L7F0DCDF0:
/* 111920 7F0DCDF0 97AD0292 */  lhu   $t5, 0x292($sp)
/* 111924 7F0DCDF4 97AE0292 */  lhu   $t6, 0x292($sp)
/* 111928 7F0DCDF8 97B90298 */  lhu   $t9, 0x298($sp)
/* 11192C 7F0DCDFC 25AC0001 */  addiu $t4, $t5, 1
/* 111930 7F0DCE00 29815B00 */  slti  $at, $t4, 0x5b00
/* 111934 7F0DCE04 14200008 */  bnez  $at, .L7F0DCE28
/* 111938 7F0DCE08 25CA0001 */   addiu $t2, $t6, 1
/* 11193C 7F0DCE0C 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 111940 7F0DCE10 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 111944 7F0DCE14 27290002 */  addiu $t1, $t9, 2
/* 111948 7F0DCE18 00095A03 */  sra   $t3, $t1, 8
/* 11194C 7F0DCE1C 010D7821 */  addu  $t7, $t0, $t5
/* 111950 7F0DCE20 10000027 */  b     .L7F0DCEC0
/* 111954 7F0DCE24 A1EB0001 */   sb    $t3, 1($t7)
.L7F0DCE28:
/* 111958 7F0DCE28 29415800 */  slti  $at, $t2, 0x5800
/* 11195C 7F0DCE2C 1420000F */  bnez  $at, .L7F0DCE6C
/* 111960 7F0DCE30 97B80292 */   lhu   $t8, 0x292($sp)
/* 111964 7F0DCE34 97B80298 */  lhu   $t8, 0x298($sp)
/* 111968 7F0DCE38 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 11196C 7F0DCE3C 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 111970 7F0DCE40 270C0002 */  addiu $t4, $t8, 2
/* 111974 7F0DCE44 000CCA03 */  sra   $t9, $t4, 8
/* 111978 7F0DCE48 012E4021 */  addu  $t0, $t1, $t6
/* 11197C 7F0DCE4C A1190001 */  sb    $t9, 1($t0)
/* 111980 7F0DCE50 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 111984 7F0DCE54 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 111988 7F0DCE58 97AF0292 */  lhu   $t7, 0x292($sp)
/* 11198C 7F0DCE5C 240D0001 */  li    $t5, 1
/* 111990 7F0DCE60 016F5021 */  addu  $t2, $t3, $t7
/* 111994 7F0DCE64 10000016 */  b     .L7F0DCEC0
/* 111998 7F0DCE68 A14DA801 */   sb    $t5, -0x57ff($t2)
.L7F0DCE6C:
/* 11199C 7F0DCE6C 270C0001 */  addiu $t4, $t8, 1
/* 1119A0 7F0DCE70 29814000 */  slti  $at, $t4, 0x4000
/* 1119A4 7F0DCE74 14200012 */  bnez  $at, .L7F0DCEC0
/* 1119A8 7F0DCE78 97A90298 */   lhu   $t1, 0x298($sp)
/* 1119AC 7F0DCE7C 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 1119B0 7F0DCE80 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 1119B4 7F0DCE84 252E0002 */  addiu $t6, $t1, 2
/* 1119B8 7F0DCE88 000ECA03 */  sra   $t9, $t6, 8
/* 1119BC 7F0DCE8C 01185821 */  addu  $t3, $t0, $t8
/* 1119C0 7F0DCE90 A1790001 */  sb    $t9, 1($t3)
/* 1119C4 7F0DCE94 97AD0292 */  lhu   $t5, 0x292($sp)
/* 1119C8 7F0DCE98 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 1119CC 7F0DCE9C 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 1119D0 7F0DCEA0 25AA0001 */  addiu $t2, $t5, 1
/* 1119D4 7F0DCEA4 314C1800 */  andi  $t4, $t2, 0x1800
/* 1119D8 7F0DCEA8 000C48C3 */  sra   $t1, $t4, 3
/* 1119DC 7F0DCEAC 314E00FF */  andi  $t6, $t2, 0xff
/* 1119E0 7F0DCEB0 012E4025 */  or    $t0, $t1, $t6
/* 1119E4 7F0DCEB4 240F0001 */  li    $t7, 1
/* 1119E8 7F0DCEB8 0308C821 */  addu  $t9, $t8, $t0
/* 1119EC 7F0DCEBC A32F0000 */  sb    $t7, ($t9)
.L7F0DCEC0:
/* 1119F0 7F0DCEC0 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 1119F4 7F0DCEC4 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 1119F8 7F0DCEC8 97AB0298 */  lhu   $t3, 0x298($sp)
/* 1119FC 7F0DCECC 01AB4821 */  addu  $t1, $t5, $t3
/* 111A00 7F0DCED0 912E0001 */  lbu   $t6, 1($t1)
/* 111A04 7F0DCED4 016D6021 */  addu  $t4, $t3, $t5
/* 111A08 7F0DCED8 918A0000 */  lbu   $t2, ($t4)
/* 111A0C 7F0DCEDC 000EC200 */  sll   $t8, $t6, 8
/* 111A10 7F0DCEE0 01584025 */  or    $t0, $t2, $t8
/* 111A14 7F0DCEE4 10001645 */  b     .L7F0E27FC
/* 111A18 7F0DCEE8 A7A80298 */   sh    $t0, 0x298($sp)
.L7F0DCEEC:
/* 111A1C 7F0DCEEC 97AF0298 */  lhu   $t7, 0x298($sp)
/* 111A20 7F0DCEF0 25F90002 */  addiu $t9, $t7, 2
/* 111A24 7F0DCEF4 10001641 */  b     .L7F0E27FC
/* 111A28 7F0DCEF8 A7B90298 */   sh    $t9, 0x298($sp)
spectrum_op_D5:
/* 111A2C 7F0DCEFC 97AB0292 */  lhu   $t3, 0x292($sp)
/* 111A30 7F0DCF00 8FAC028C */  lw    $t4, 0x28c($sp)
/* 111A34 7F0DCF04 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 111A38 7F0DCF08 2569FFFE */  addiu $t1, $t3, -2
/* 111A3C 7F0DCF0C 312EFFFF */  andi  $t6, $t1, 0xffff
/* 111A40 7F0DCF10 29C15B00 */  slti  $at, $t6, 0x5b00
/* 111A44 7F0DCF14 258D000B */  addiu $t5, $t4, 0xb
/* 111A48 7F0DCF18 AFAD028C */  sw    $t5, 0x28c($sp)
/* 111A4C 7F0DCF1C 14200005 */  bnez  $at, .L7F0DCF34
/* 111A50 7F0DCF20 A7A90292 */   sh    $t1, 0x292($sp)
/* 111A54 7F0DCF24 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 111A58 7F0DCF28 014EC021 */  addu  $t8, $t2, $t6
/* 111A5C 7F0DCF2C 10000021 */  b     .L7F0DCFB4
/* 111A60 7F0DCF30 A3150000 */   sb    $s5, ($t8)
.L7F0DCF34:
/* 111A64 7F0DCF34 97A80292 */  lhu   $t0, 0x292($sp)
/* 111A68 7F0DCF38 97AA0292 */  lhu   $t2, 0x292($sp)
/* 111A6C 7F0DCF3C 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 111A70 7F0DCF40 29015800 */  slti  $at, $t0, 0x5800
/* 111A74 7F0DCF44 5420000C */  bnezl $at, .L7F0DCF78
/* 111A78 7F0DCF48 29414000 */   slti  $at, $t2, 0x4000
/* 111A7C 7F0DCF4C 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 111A80 7F0DCF50 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 111A84 7F0DCF54 240C0001 */  li    $t4, 1
/* 111A88 7F0DCF58 01E8C821 */  addu  $t9, $t7, $t0
/* 111A8C 7F0DCF5C A3350000 */  sb    $s5, ($t9)
/* 111A90 7F0DCF60 97AB0292 */  lhu   $t3, 0x292($sp)
/* 111A94 7F0DCF64 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 111A98 7F0DCF68 01AB4821 */  addu  $t1, $t5, $t3
/* 111A9C 7F0DCF6C 10000011 */  b     .L7F0DCFB4
/* 111AA0 7F0DCF70 A12CA800 */   sb    $t4, -0x5800($t1)
/* 111AA4 7F0DCF74 29414000 */  slti  $at, $t2, 0x4000
.L7F0DCF78:
/* 111AA8 7F0DCF78 1420000E */  bnez  $at, .L7F0DCFB4
/* 111AAC 7F0DCF7C 3C0E8009 */   lui   $t6, %hi(ptr_spectrum_roms) 
/* 111AB0 7F0DCF80 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 111AB4 7F0DCF84 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 111AB8 7F0DCF88 240F0001 */  li    $t7, 1
/* 111ABC 7F0DCF8C 01CAC021 */  addu  $t8, $t6, $t2
/* 111AC0 7F0DCF90 A3150000 */  sb    $s5, ($t8)
/* 111AC4 7F0DCF94 97A80292 */  lhu   $t0, 0x292($sp)
/* 111AC8 7F0DCF98 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 111ACC 7F0DCF9C 31191800 */  andi  $t9, $t0, 0x1800
/* 111AD0 7F0DCFA0 001968C3 */  sra   $t5, $t9, 3
/* 111AD4 7F0DCFA4 310B00FF */  andi  $t3, $t0, 0xff
/* 111AD8 7F0DCFA8 01AB6025 */  or    $t4, $t5, $t3
/* 111ADC 7F0DCFAC 012C7021 */  addu  $t6, $t1, $t4
/* 111AE0 7F0DCFB0 A1CF0000 */  sb    $t7, ($t6)
.L7F0DCFB4:
/* 111AE4 7F0DCFB4 97AA0292 */  lhu   $t2, 0x292($sp)
/* 111AE8 7F0DCFB8 97AD0292 */  lhu   $t5, 0x292($sp)
/* 111AEC 7F0DCFBC 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 111AF0 7F0DCFC0 25580001 */  addiu $t8, $t2, 1
/* 111AF4 7F0DCFC4 2B015B00 */  slti  $at, $t8, 0x5b00
/* 111AF8 7F0DCFC8 14200005 */  bnez  $at, .L7F0DCFE0
/* 111AFC 7F0DCFCC 25AB0001 */   addiu $t3, $t5, 1
/* 111B00 7F0DCFD0 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 111B04 7F0DCFD4 032A4021 */  addu  $t0, $t9, $t2
/* 111B08 7F0DCFD8 10001608 */  b     .L7F0E27FC
/* 111B0C 7F0DCFDC A1140001 */   sb    $s4, 1($t0)
.L7F0DCFE0:
/* 111B10 7F0DCFE0 29615800 */  slti  $at, $t3, 0x5800
/* 111B14 7F0DCFE4 1420000C */  bnez  $at, .L7F0DD018
/* 111B18 7F0DCFE8 97AA0292 */   lhu   $t2, 0x292($sp)
/* 111B1C 7F0DCFEC 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 111B20 7F0DCFF0 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 111B24 7F0DCFF4 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 111B28 7F0DCFF8 240F0001 */  li    $t7, 1
/* 111B2C 7F0DCFFC 012D6021 */  addu  $t4, $t1, $t5
/* 111B30 7F0DD000 A1940001 */  sb    $s4, 1($t4)
/* 111B34 7F0DD004 97B80292 */  lhu   $t8, 0x292($sp)
/* 111B38 7F0DD008 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 111B3C 7F0DD00C 01D8C821 */  addu  $t9, $t6, $t8
/* 111B40 7F0DD010 100015FA */  b     .L7F0E27FC
/* 111B44 7F0DD014 A32FA801 */   sb    $t7, -0x57ff($t9)
.L7F0DD018:
/* 111B48 7F0DD018 25480001 */  addiu $t0, $t2, 1
/* 111B4C 7F0DD01C 29014000 */  slti  $at, $t0, 0x4000
/* 111B50 7F0DD020 142015F6 */  bnez  $at, .L7F0E27FC
/* 111B54 7F0DD024 3C0B8009 */   lui   $t3, %hi(ptr_spectrum_roms) 
/* 111B58 7F0DD028 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 111B5C 7F0DD02C 240D0001 */  li    $t5, 1
/* 111B60 7F0DD030 016A4821 */  addu  $t1, $t3, $t2
/* 111B64 7F0DD034 A1340001 */  sb    $s4, 1($t1)
/* 111B68 7F0DD038 97AC0292 */  lhu   $t4, 0x292($sp)
/* 111B6C 7F0DD03C 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 111B70 7F0DD040 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 111B74 7F0DD044 258E0001 */  addiu $t6, $t4, 1
/* 111B78 7F0DD048 31D81800 */  andi  $t8, $t6, 0x1800
/* 111B7C 7F0DD04C 001878C3 */  sra   $t7, $t8, 3
/* 111B80 7F0DD050 31D900FF */  andi  $t9, $t6, 0xff
/* 111B84 7F0DD054 01F94025 */  or    $t0, $t7, $t9
/* 111B88 7F0DD058 01685021 */  addu  $t2, $t3, $t0
/* 111B8C 7F0DD05C 100015E7 */  b     .L7F0E27FC
/* 111B90 7F0DD060 A14D0000 */   sb    $t5, ($t2)
spectrum_op_D6:
/* 111B94 7F0DD064 8FA9028C */  lw    $t1, 0x28c($sp)
/* 111B98 7F0DD068 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 111B9C 7F0DD06C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 111BA0 7F0DD070 97B80298 */  lhu   $t8, 0x298($sp)
/* 111BA4 7F0DD074 252C0007 */  addiu $t4, $t1, 7
/* 111BA8 7F0DD078 AFAC028C */  sw    $t4, 0x28c($sp)
/* 111BAC 7F0DD07C 030E7821 */  addu  $t7, $t8, $t6
/* 111BB0 7F0DD080 91F90000 */  lbu   $t9, ($t7)
/* 111BB4 7F0DD084 320F000F */  andi  $t7, $s0, 0xf
/* 111BB8 7F0DD088 02195823 */  subu  $t3, $s0, $t9
/* 111BBC 7F0DD08C 316801FF */  andi  $t0, $t3, 0x1ff
/* 111BC0 7F0DD090 310A00A8 */  andi  $t2, $t0, 0xa8
/* 111BC4 7F0DD094 00086203 */  sra   $t4, $t0, 8
/* 111BC8 7F0DD098 332E000F */  andi  $t6, $t9, 0xf
/* 111BCC 7F0DD09C 01EE582A */  slt   $t3, $t7, $t6
/* 111BD0 7F0DD0A0 014CC025 */  or    $t8, $t2, $t4
/* 111BD4 7F0DD0A4 02195026 */  xor   $t2, $s0, $t9
/* 111BD8 7F0DD0A8 000B6900 */  sll   $t5, $t3, 4
/* 111BDC 7F0DD0AC 01107026 */  xor   $t6, $t0, $s0
/* 111BE0 7F0DD0B0 A7A800FA */  sh    $t0, 0xfa($sp)
/* 111BE4 7F0DD0B4 93B000FB */  lbu   $s0, 0xfb($sp)
/* 111BE8 7F0DD0B8 314C0080 */  andi  $t4, $t2, 0x80
/* 111BEC 7F0DD0BC 018E5824 */  and   $t3, $t4, $t6
/* 111BF0 7F0DD0C0 030D4825 */  or    $t1, $t8, $t5
/* 111BF4 7F0DD0C4 000BC143 */  sra   $t8, $t3, 5
/* 111BF8 7F0DD0C8 97AE0298 */  lhu   $t6, 0x298($sp)
/* 111BFC 7F0DD0CC 01388825 */  or    $s1, $t1, $t8
/* 111C00 7F0DD0D0 A3B900F9 */  sb    $t9, 0xf9($sp)
/* 111C04 7F0DD0D4 2E0A0001 */  sltiu $t2, $s0, 1
/* 111C08 7F0DD0D8 000A7980 */  sll   $t7, $t2, 6
/* 111C0C 7F0DD0DC 36390002 */  ori   $t9, $s1, 2
/* 111C10 7F0DD0E0 032F8825 */  or    $s1, $t9, $t7
/* 111C14 7F0DD0E4 322C00FF */  andi  $t4, $s1, 0xff
/* 111C18 7F0DD0E8 25CB0001 */  addiu $t3, $t6, 1
/* 111C1C 7F0DD0EC 01808825 */  move  $s1, $t4
/* 111C20 7F0DD0F0 AFAA0048 */  sw    $t2, 0x48($sp)
/* 111C24 7F0DD0F4 100015C1 */  b     .L7F0E27FC
/* 111C28 7F0DD0F8 A7AB0298 */   sh    $t3, 0x298($sp)
spectrum_op_D7:
/* 111C2C 7F0DD0FC 97AD0292 */  lhu   $t5, 0x292($sp)
/* 111C30 7F0DD100 8FA9028C */  lw    $t1, 0x28c($sp)
/* 111C34 7F0DD104 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 111C38 7F0DD108 25B9FFFE */  addiu $t9, $t5, -2
/* 111C3C 7F0DD10C 332AFFFF */  andi  $t2, $t9, 0xffff
/* 111C40 7F0DD110 29415B00 */  slti  $at, $t2, 0x5b00
/* 111C44 7F0DD114 2538000B */  addiu $t8, $t1, 0xb
/* 111C48 7F0DD118 AFB8028C */  sw    $t8, 0x28c($sp)
/* 111C4C 7F0DD11C 14200006 */  bnez  $at, .L7F0DD138
/* 111C50 7F0DD120 A7B90292 */   sh    $t9, 0x292($sp)
/* 111C54 7F0DD124 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 111C58 7F0DD128 97A80298 */  lhu   $t0, 0x298($sp)
/* 111C5C 7F0DD12C 01EA6021 */  addu  $t4, $t7, $t2
/* 111C60 7F0DD130 10000023 */  b     .L7F0DD1C0
/* 111C64 7F0DD134 A1880000 */   sb    $t0, ($t4)
.L7F0DD138:
/* 111C68 7F0DD138 97AE0292 */  lhu   $t6, 0x292($sp)
/* 111C6C 7F0DD13C 97A80292 */  lhu   $t0, 0x292($sp)
/* 111C70 7F0DD140 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 111C74 7F0DD144 29C15800 */  slti  $at, $t6, 0x5800
/* 111C78 7F0DD148 5420000D */  bnezl $at, .L7F0DD180
/* 111C7C 7F0DD14C 29014000 */   slti  $at, $t0, 0x4000
/* 111C80 7F0DD150 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 111C84 7F0DD154 97AB0298 */  lhu   $t3, 0x298($sp)
/* 111C88 7F0DD158 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 111C8C 7F0DD15C 012EC021 */  addu  $t8, $t1, $t6
/* 111C90 7F0DD160 A30B0000 */  sb    $t3, ($t8)
/* 111C94 7F0DD164 97AF0292 */  lhu   $t7, 0x292($sp)
/* 111C98 7F0DD168 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 111C9C 7F0DD16C 240D0001 */  li    $t5, 1
/* 111CA0 7F0DD170 032F5021 */  addu  $t2, $t9, $t7
/* 111CA4 7F0DD174 10000012 */  b     .L7F0DD1C0
/* 111CA8 7F0DD178 A14DA800 */   sb    $t5, -0x5800($t2)
/* 111CAC 7F0DD17C 29014000 */  slti  $at, $t0, 0x4000
.L7F0DD180:
/* 111CB0 7F0DD180 1420000F */  bnez  $at, .L7F0DD1C0
/* 111CB4 7F0DD184 3C098009 */   lui   $t1, %hi(ptr_spectrum_roms) 
/* 111CB8 7F0DD188 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 111CBC 7F0DD18C 97AC0298 */  lhu   $t4, 0x298($sp)
/* 111CC0 7F0DD190 240B0001 */  li    $t3, 1
/* 111CC4 7F0DD194 01287021 */  addu  $t6, $t1, $t0
/* 111CC8 7F0DD198 A1CC0000 */  sb    $t4, ($t6)
/* 111CCC 7F0DD19C 97B80292 */  lhu   $t8, 0x292($sp)
/* 111CD0 7F0DD1A0 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 111CD4 7F0DD1A4 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 111CD8 7F0DD1A8 33191800 */  andi  $t9, $t8, 0x1800
/* 111CDC 7F0DD1AC 001978C3 */  sra   $t7, $t9, 3
/* 111CE0 7F0DD1B0 330D00FF */  andi  $t5, $t8, 0xff
/* 111CE4 7F0DD1B4 01ED5025 */  or    $t2, $t7, $t5
/* 111CE8 7F0DD1B8 012A4021 */  addu  $t0, $t1, $t2
/* 111CEC 7F0DD1BC A10B0000 */  sb    $t3, ($t0)
.L7F0DD1C0:
/* 111CF0 7F0DD1C0 97AC0292 */  lhu   $t4, 0x292($sp)
/* 111CF4 7F0DD1C4 97A90292 */  lhu   $t1, 0x292($sp)
/* 111CF8 7F0DD1C8 97B90298 */  lhu   $t9, 0x298($sp)
/* 111CFC 7F0DD1CC 258E0001 */  addiu $t6, $t4, 1
/* 111D00 7F0DD1D0 29C15B00 */  slti  $at, $t6, 0x5b00
/* 111D04 7F0DD1D4 14200007 */  bnez  $at, .L7F0DD1F4
/* 111D08 7F0DD1D8 252A0001 */   addiu $t2, $t1, 1
/* 111D0C 7F0DD1DC 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 111D10 7F0DD1E0 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 111D14 7F0DD1E4 0019C203 */  sra   $t8, $t9, 8
/* 111D18 7F0DD1E8 01EC6821 */  addu  $t5, $t7, $t4
/* 111D1C 7F0DD1EC 10000025 */  b     .L7F0DD284
/* 111D20 7F0DD1F0 A1B80001 */   sb    $t8, 1($t5)
.L7F0DD1F4:
/* 111D24 7F0DD1F4 29415800 */  slti  $at, $t2, 0x5800
/* 111D28 7F0DD1F8 1420000E */  bnez  $at, .L7F0DD234
/* 111D2C 7F0DD1FC 97AA0292 */   lhu   $t2, 0x292($sp)
/* 111D30 7F0DD200 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 111D34 7F0DD204 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 111D38 7F0DD208 97AB0298 */  lhu   $t3, 0x298($sp)
/* 111D3C 7F0DD20C 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 111D40 7F0DD210 01C9C821 */  addu  $t9, $t6, $t1
/* 111D44 7F0DD214 000B4203 */  sra   $t0, $t3, 8
/* 111D48 7F0DD218 A3280001 */  sb    $t0, 1($t9)
/* 111D4C 7F0DD21C 97B80292 */  lhu   $t8, 0x292($sp)
/* 111D50 7F0DD220 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 111D54 7F0DD224 240F0001 */  li    $t7, 1
/* 111D58 7F0DD228 01986821 */  addu  $t5, $t4, $t8
/* 111D5C 7F0DD22C 10000015 */  b     .L7F0DD284
/* 111D60 7F0DD230 A1AFA801 */   sb    $t7, -0x57ff($t5)
.L7F0DD234:
/* 111D64 7F0DD234 254B0001 */  addiu $t3, $t2, 1
/* 111D68 7F0DD238 29614000 */  slti  $at, $t3, 0x4000
/* 111D6C 7F0DD23C 14200011 */  bnez  $at, .L7F0DD284
/* 111D70 7F0DD240 97AE0298 */   lhu   $t6, 0x298($sp)
/* 111D74 7F0DD244 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 111D78 7F0DD248 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 111D7C 7F0DD24C 000E4A03 */  sra   $t1, $t6, 8
/* 111D80 7F0DD250 240C0001 */  li    $t4, 1
/* 111D84 7F0DD254 010AC821 */  addu  $t9, $t0, $t2
/* 111D88 7F0DD258 A3290001 */  sb    $t1, 1($t9)
/* 111D8C 7F0DD25C 97B80292 */  lhu   $t8, 0x292($sp)
/* 111D90 7F0DD260 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 111D94 7F0DD264 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 111D98 7F0DD268 270F0001 */  addiu $t7, $t8, 1
/* 111D9C 7F0DD26C 31ED1800 */  andi  $t5, $t7, 0x1800
/* 111DA0 7F0DD270 000D58C3 */  sra   $t3, $t5, 3
/* 111DA4 7F0DD274 31EE00FF */  andi  $t6, $t7, 0xff
/* 111DA8 7F0DD278 016E4025 */  or    $t0, $t3, $t6
/* 111DAC 7F0DD27C 01484821 */  addu  $t1, $t2, $t0
/* 111DB0 7F0DD280 A12C0000 */  sb    $t4, ($t1)
.L7F0DD284:
/* 111DB4 7F0DD284 24190010 */  li    $t9, 16
/* 111DB8 7F0DD288 1000155C */  b     .L7F0E27FC
/* 111DBC 7F0DD28C A7B90298 */   sh    $t9, 0x298($sp)
spectrum_op_D8:
/* 111DC0 7F0DD290 8FB8028C */  lw    $t8, 0x28c($sp)
/* 111DC4 7F0DD294 322F0001 */  andi  $t7, $s1, 1
/* 111DC8 7F0DD298 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 111DCC 7F0DD29C 270D0005 */  addiu $t5, $t8, 5
/* 111DD0 7F0DD2A0 11E01556 */  beqz  $t7, .L7F0E27FC
/* 111DD4 7F0DD2A4 AFAD028C */   sw    $t5, 0x28c($sp)
/* 111DD8 7F0DD2A8 97AA0292 */  lhu   $t2, 0x292($sp)
/* 111DDC 7F0DD2AC 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 111DE0 7F0DD2B0 25AE0006 */  addiu $t6, $t5, 6
/* 111DE4 7F0DD2B4 AFAE028C */  sw    $t6, 0x28c($sp)
/* 111DE8 7F0DD2B8 010AC821 */  addu  $t9, $t0, $t2
/* 111DEC 7F0DD2BC 93380001 */  lbu   $t8, 1($t9)
/* 111DF0 7F0DD2C0 01486021 */  addu  $t4, $t2, $t0
/* 111DF4 7F0DD2C4 91890000 */  lbu   $t1, ($t4)
/* 111DF8 7F0DD2C8 00186A00 */  sll   $t5, $t8, 8
/* 111DFC 7F0DD2CC 254B0002 */  addiu $t3, $t2, 2
/* 111E00 7F0DD2D0 012D7825 */  or    $t7, $t1, $t5
/* 111E04 7F0DD2D4 A7AF0298 */  sh    $t7, 0x298($sp)
/* 111E08 7F0DD2D8 10001548 */  b     .L7F0E27FC
/* 111E0C 7F0DD2DC A7AB0292 */   sh    $t3, 0x292($sp)
spectrum_op_D9:
/* 111E10 7F0DD2E0 8FAE028C */  lw    $t6, 0x28c($sp)
/* 111E14 7F0DD2E4 A3B200F8 */  sb    $s2, 0xf8($sp)
/* 111E18 7F0DD2E8 A3B300F7 */  sb    $s3, 0xf7($sp)
/* 111E1C 7F0DD2EC A3B400F6 */  sb    $s4, 0xf6($sp)
/* 111E20 7F0DD2F0 A3B500F5 */  sb    $s5, 0xf5($sp)
/* 111E24 7F0DD2F4 A3B600F4 */  sb    $s6, 0xf4($sp)
/* 111E28 7F0DD2F8 A3B700F3 */  sb    $s7, 0xf3($sp)
/* 111E2C 7F0DD2FC 93A800F8 */  lbu   $t0, 0xf8($sp)
/* 111E30 7F0DD300 93B900F7 */  lbu   $t9, 0xf7($sp)
/* 111E34 7F0DD304 93B800F6 */  lbu   $t8, 0xf6($sp)
/* 111E38 7F0DD308 93A900F5 */  lbu   $t1, 0xf5($sp)
/* 111E3C 7F0DD30C 93AD00F4 */  lbu   $t5, 0xf4($sp)
/* 111E40 7F0DD310 93AF00F3 */  lbu   $t7, 0xf3($sp)
/* 111E44 7F0DD314 93B202A4 */  lbu   $s2, 0x2a4($sp)
/* 111E48 7F0DD318 93B302A3 */  lbu   $s3, 0x2a3($sp)
/* 111E4C 7F0DD31C 93B402A2 */  lbu   $s4, 0x2a2($sp)
/* 111E50 7F0DD320 93B502A1 */  lbu   $s5, 0x2a1($sp)
/* 111E54 7F0DD324 93B602A0 */  lbu   $s6, 0x2a0($sp)
/* 111E58 7F0DD328 93B7029F */  lbu   $s7, 0x29f($sp)
/* 111E5C 7F0DD32C 25CC0004 */  addiu $t4, $t6, 4
/* 111E60 7F0DD330 AFAC028C */  sw    $t4, 0x28c($sp)
/* 111E64 7F0DD334 A3A802A4 */  sb    $t0, 0x2a4($sp)
/* 111E68 7F0DD338 A3B902A3 */  sb    $t9, 0x2a3($sp)
/* 111E6C 7F0DD33C A3B802A2 */  sb    $t8, 0x2a2($sp)
/* 111E70 7F0DD340 A3A902A1 */  sb    $t1, 0x2a1($sp)
/* 111E74 7F0DD344 A3AD02A0 */  sb    $t5, 0x2a0($sp)
/* 111E78 7F0DD348 1000152C */  b     .L7F0E27FC
/* 111E7C 7F0DD34C A3AF029F */   sb    $t7, 0x29f($sp)
spectrum_op_DA:
/* 111E80 7F0DD350 8FAA028C */  lw    $t2, 0x28c($sp)
/* 111E84 7F0DD354 322E0001 */  andi  $t6, $s1, 1
/* 111E88 7F0DD358 97AC0298 */  lhu   $t4, 0x298($sp)
/* 111E8C 7F0DD35C 254B000A */  addiu $t3, $t2, 0xa
/* 111E90 7F0DD360 11C0000B */  beqz  $t6, .L7F0DD390
/* 111E94 7F0DD364 AFAB028C */   sw    $t3, 0x28c($sp)
/* 111E98 7F0DD368 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 111E9C 7F0DD36C 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 111EA0 7F0DD370 010C4821 */  addu  $t1, $t0, $t4
/* 111EA4 7F0DD374 912D0001 */  lbu   $t5, 1($t1)
/* 111EA8 7F0DD378 0188C821 */  addu  $t9, $t4, $t0
/* 111EAC 7F0DD37C 93380000 */  lbu   $t8, ($t9)
/* 111EB0 7F0DD380 000D7A00 */  sll   $t7, $t5, 8
/* 111EB4 7F0DD384 030F5025 */  or    $t2, $t8, $t7
/* 111EB8 7F0DD388 1000151C */  b     .L7F0E27FC
/* 111EBC 7F0DD38C A7AA0298 */   sh    $t2, 0x298($sp)
.L7F0DD390:
/* 111EC0 7F0DD390 97AB0298 */  lhu   $t3, 0x298($sp)
/* 111EC4 7F0DD394 256E0002 */  addiu $t6, $t3, 2
/* 111EC8 7F0DD398 10001518 */  b     .L7F0E27FC
/* 111ECC 7F0DD39C A7AE0298 */   sh    $t6, 0x298($sp)
spectrum_op_DB:
/* 111ED0 7F0DD3A0 8FB9028C */  lw    $t9, 0x28c($sp)
/* 111ED4 7F0DD3A4 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 111ED8 7F0DD3A8 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 111EDC 7F0DD3AC 97AC0298 */  lhu   $t4, 0x298($sp)
/* 111EE0 7F0DD3B0 2724000B */  addiu $a0, $t9, 0xb
/* 111EE4 7F0DD3B4 AFA4028C */  sw    $a0, 0x28c($sp)
/* 111EE8 7F0DD3B8 01896821 */  addu  $t5, $t4, $t1
/* 111EEC 7F0DD3BC 91A60000 */  lbu   $a2, ($t5)
/* 111EF0 7F0DD3C0 0FC34DB6 */  jal   spectrum_input_handling
/* 111EF4 7F0DD3C4 02002825 */   move  $a1, $s0
/* 111EF8 7F0DD3C8 8FB8028C */  lw    $t8, 0x28c($sp)
/* 111EFC 7F0DD3CC 97AE0298 */  lhu   $t6, 0x298($sp)
/* 111F00 7F0DD3D0 304FFFFF */  andi  $t7, $v0, 0xffff
/* 111F04 7F0DD3D4 000F5203 */  sra   $t2, $t7, 8
/* 111F08 7F0DD3D8 A7A200F0 */  sh    $v0, 0xf0($sp)
/* 111F0C 7F0DD3DC 030A5821 */  addu  $t3, $t8, $t2
/* 111F10 7F0DD3E0 25D90001 */  addiu $t9, $t6, 1
/* 111F14 7F0DD3E4 93B000F1 */  lbu   $s0, 0xf1($sp)
/* 111F18 7F0DD3E8 AFAB028C */  sw    $t3, 0x28c($sp)
/* 111F1C 7F0DD3EC 10001503 */  b     .L7F0E27FC
/* 111F20 7F0DD3F0 A7B90298 */   sh    $t9, 0x298($sp)
spectrum_op_DC:
/* 111F24 7F0DD3F4 8FA8028C */  lw    $t0, 0x28c($sp)
/* 111F28 7F0DD3F8 32290001 */  andi  $t1, $s1, 1
/* 111F2C 7F0DD3FC 250C000A */  addiu $t4, $t0, 0xa
/* 111F30 7F0DD400 11200072 */  beqz  $t1, .L7F0DD5CC
/* 111F34 7F0DD404 AFAC028C */   sw    $t4, 0x28c($sp)
/* 111F38 7F0DD408 97B80292 */  lhu   $t8, 0x292($sp)
/* 111F3C 7F0DD40C 258F0007 */  addiu $t7, $t4, 7
/* 111F40 7F0DD410 AFAF028C */  sw    $t7, 0x28c($sp)
/* 111F44 7F0DD414 270AFFFE */  addiu $t2, $t8, -2
/* 111F48 7F0DD418 314BFFFF */  andi  $t3, $t2, 0xffff
/* 111F4C 7F0DD41C 29615B00 */  slti  $at, $t3, 0x5b00
/* 111F50 7F0DD420 14200008 */  bnez  $at, .L7F0DD444
/* 111F54 7F0DD424 A7AA0292 */   sh    $t2, 0x292($sp)
/* 111F58 7F0DD428 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 111F5C 7F0DD42C 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 111F60 7F0DD430 97AE0298 */  lhu   $t6, 0x298($sp)
/* 111F64 7F0DD434 010B6021 */  addu  $t4, $t0, $t3
/* 111F68 7F0DD438 25D90002 */  addiu $t9, $t6, 2
/* 111F6C 7F0DD43C 10000024 */  b     .L7F0DD4D0
/* 111F70 7F0DD440 A1990000 */   sb    $t9, ($t4)
.L7F0DD444:
/* 111F74 7F0DD444 97A90292 */  lhu   $t1, 0x292($sp)
/* 111F78 7F0DD448 97AC0292 */  lhu   $t4, 0x292($sp)
/* 111F7C 7F0DD44C 97AD0298 */  lhu   $t5, 0x298($sp)
/* 111F80 7F0DD450 29215800 */  slti  $at, $t1, 0x5800
/* 111F84 7F0DD454 1420000C */  bnez  $at, .L7F0DD488
/* 111F88 7F0DD458 3C188009 */   lui   $t8, %hi(ptr_spectrum_roms) 
/* 111F8C 7F0DD45C 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 111F90 7F0DD460 25AF0002 */  addiu $t7, $t5, 2
/* 111F94 7F0DD464 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 111F98 7F0DD468 03095021 */  addu  $t2, $t8, $t1
/* 111F9C 7F0DD46C A14F0000 */  sb    $t7, ($t2)
/* 111FA0 7F0DD470 97AB0292 */  lhu   $t3, 0x292($sp)
/* 111FA4 7F0DD474 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 111FA8 7F0DD478 240E0001 */  li    $t6, 1
/* 111FAC 7F0DD47C 010BC821 */  addu  $t9, $t0, $t3
/* 111FB0 7F0DD480 10000013 */  b     .L7F0DD4D0
/* 111FB4 7F0DD484 A32EA800 */   sb    $t6, -0x5800($t9)
.L7F0DD488:
/* 111FB8 7F0DD488 29814000 */  slti  $at, $t4, 0x4000
/* 111FBC 7F0DD48C 14200010 */  bnez  $at, .L7F0DD4D0
/* 111FC0 7F0DD490 97AD0298 */   lhu   $t5, 0x298($sp)
/* 111FC4 7F0DD494 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 111FC8 7F0DD498 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 111FCC 7F0DD49C 25B80002 */  addiu $t8, $t5, 2
/* 111FD0 7F0DD4A0 240A0001 */  li    $t2, 1
/* 111FD4 7F0DD4A4 012C7821 */  addu  $t7, $t1, $t4
/* 111FD8 7F0DD4A8 A1F80000 */  sb    $t8, ($t7)
/* 111FDC 7F0DD4AC 97A80292 */  lhu   $t0, 0x292($sp)
/* 111FE0 7F0DD4B0 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 111FE4 7F0DD4B4 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 111FE8 7F0DD4B8 310B1800 */  andi  $t3, $t0, 0x1800
/* 111FEC 7F0DD4BC 000B70C3 */  sra   $t6, $t3, 3
/* 111FF0 7F0DD4C0 311900FF */  andi  $t9, $t0, 0xff
/* 111FF4 7F0DD4C4 01D96825 */  or    $t5, $t6, $t9
/* 111FF8 7F0DD4C8 012D6021 */  addu  $t4, $t1, $t5
/* 111FFC 7F0DD4CC A18A0000 */  sb    $t2, ($t4)
.L7F0DD4D0:
/* 112000 7F0DD4D0 97B80292 */  lhu   $t8, 0x292($sp)
/* 112004 7F0DD4D4 97AD0292 */  lhu   $t5, 0x292($sp)
/* 112008 7F0DD4D8 97AB0298 */  lhu   $t3, 0x298($sp)
/* 11200C 7F0DD4DC 270F0001 */  addiu $t7, $t8, 1
/* 112010 7F0DD4E0 29E15B00 */  slti  $at, $t7, 0x5b00
/* 112014 7F0DD4E4 14200008 */  bnez  $at, .L7F0DD508
/* 112018 7F0DD4E8 25AA0001 */   addiu $t2, $t5, 1
/* 11201C 7F0DD4EC 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 112020 7F0DD4F0 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 112024 7F0DD4F4 25680002 */  addiu $t0, $t3, 2
/* 112028 7F0DD4F8 00087203 */  sra   $t6, $t0, 8
/* 11202C 7F0DD4FC 03384821 */  addu  $t1, $t9, $t8
/* 112030 7F0DD500 10000027 */  b     .L7F0DD5A0
/* 112034 7F0DD504 A12E0001 */   sb    $t6, 1($t1)
.L7F0DD508:
/* 112038 7F0DD508 29415800 */  slti  $at, $t2, 0x5800
/* 11203C 7F0DD50C 1420000F */  bnez  $at, .L7F0DD54C
/* 112040 7F0DD510 97AC0292 */   lhu   $t4, 0x292($sp)
/* 112044 7F0DD514 97AC0298 */  lhu   $t4, 0x298($sp)
/* 112048 7F0DD518 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 11204C 7F0DD51C 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 112050 7F0DD520 258F0002 */  addiu $t7, $t4, 2
/* 112054 7F0DD524 000F5A03 */  sra   $t3, $t7, 8
/* 112058 7F0DD528 010DC821 */  addu  $t9, $t0, $t5
/* 11205C 7F0DD52C A32B0001 */  sb    $t3, 1($t9)
/* 112060 7F0DD530 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 112064 7F0DD534 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 112068 7F0DD538 97A90292 */  lhu   $t1, 0x292($sp)
/* 11206C 7F0DD53C 24180001 */  li    $t8, 1
/* 112070 7F0DD540 01C95021 */  addu  $t2, $t6, $t1
/* 112074 7F0DD544 10000016 */  b     .L7F0DD5A0
/* 112078 7F0DD548 A158A801 */   sb    $t8, -0x57ff($t2)
.L7F0DD54C:
/* 11207C 7F0DD54C 258F0001 */  addiu $t7, $t4, 1
/* 112080 7F0DD550 29E14000 */  slti  $at, $t7, 0x4000
/* 112084 7F0DD554 14200012 */  bnez  $at, .L7F0DD5A0
/* 112088 7F0DD558 97A80298 */   lhu   $t0, 0x298($sp)
/* 11208C 7F0DD55C 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 112090 7F0DD560 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 112094 7F0DD564 250D0002 */  addiu $t5, $t0, 2
/* 112098 7F0DD568 000D5A03 */  sra   $t3, $t5, 8
/* 11209C 7F0DD56C 032C7021 */  addu  $t6, $t9, $t4
/* 1120A0 7F0DD570 A1CB0001 */  sb    $t3, 1($t6)
/* 1120A4 7F0DD574 97B80292 */  lhu   $t8, 0x292($sp)
/* 1120A8 7F0DD578 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 1120AC 7F0DD57C 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 1120B0 7F0DD580 270A0001 */  addiu $t2, $t8, 1
/* 1120B4 7F0DD584 314F1800 */  andi  $t7, $t2, 0x1800
/* 1120B8 7F0DD588 000F40C3 */  sra   $t0, $t7, 3
/* 1120BC 7F0DD58C 314D00FF */  andi  $t5, $t2, 0xff
/* 1120C0 7F0DD590 010DC825 */  or    $t9, $t0, $t5
/* 1120C4 7F0DD594 24090001 */  li    $t1, 1
/* 1120C8 7F0DD598 01995821 */  addu  $t3, $t4, $t9
/* 1120CC 7F0DD59C A1690000 */  sb    $t1, ($t3)
.L7F0DD5A0:
/* 1120D0 7F0DD5A0 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 1120D4 7F0DD5A4 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 1120D8 7F0DD5A8 97AE0298 */  lhu   $t6, 0x298($sp)
/* 1120DC 7F0DD5AC 030E4021 */  addu  $t0, $t8, $t6
/* 1120E0 7F0DD5B0 910D0001 */  lbu   $t5, 1($t0)
/* 1120E4 7F0DD5B4 01D87821 */  addu  $t7, $t6, $t8
/* 1120E8 7F0DD5B8 91EA0000 */  lbu   $t2, ($t7)
/* 1120EC 7F0DD5BC 000D6200 */  sll   $t4, $t5, 8
/* 1120F0 7F0DD5C0 014CC825 */  or    $t9, $t2, $t4
/* 1120F4 7F0DD5C4 1000148D */  b     .L7F0E27FC
/* 1120F8 7F0DD5C8 A7B90298 */   sh    $t9, 0x298($sp)
.L7F0DD5CC:
/* 1120FC 7F0DD5CC 97A90298 */  lhu   $t1, 0x298($sp)
/* 112100 7F0DD5D0 252B0002 */  addiu $t3, $t1, 2
/* 112104 7F0DD5D4 10001489 */  b     .L7F0E27FC
/* 112108 7F0DD5D8 A7AB0298 */   sh    $t3, 0x298($sp)
spectrum_op_DD:
/* 11210C 7F0DD5DC 8FAF028C */  lw    $t7, 0x28c($sp)
/* 112110 7F0DD5E0 240E0001 */  li    $t6, 1
/* 112114 7F0DD5E4 A3AE0286 */  sb    $t6, 0x286($sp)
/* 112118 7F0DD5E8 25F80004 */  addiu $t8, $t7, 4
/* 11211C 7F0DD5EC AFB8028C */  sw    $t8, 0x28c($sp)
/* 112120 7F0DD5F0 10001482 */  b     .L7F0E27FC
/* 112124 7F0DD5F4 A3A00285 */   sb    $zero, 0x285($sp)
spectrum_op_DE:
/* 112128 7F0DD5F8 8FA8028C */  lw    $t0, 0x28c($sp)
/* 11212C 7F0DD5FC 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 112130 7F0DD600 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 112134 7F0DD604 97AA0298 */  lhu   $t2, 0x298($sp)
/* 112138 7F0DD608 250D0007 */  addiu $t5, $t0, 7
/* 11213C 7F0DD60C AFAD028C */  sw    $t5, 0x28c($sp)
/* 112140 7F0DD610 014CC821 */  addu  $t9, $t2, $t4
/* 112144 7F0DD614 93290000 */  lbu   $t1, ($t9)
/* 112148 7F0DD618 322F0001 */  andi  $t7, $s1, 1
/* 11214C 7F0DD61C 3208000F */  andi  $t0, $s0, 0xf
/* 112150 7F0DD620 02095823 */  subu  $t3, $s0, $t1
/* 112154 7F0DD624 016FC023 */  subu  $t8, $t3, $t7
/* 112158 7F0DD628 330E01FF */  andi  $t6, $t8, 0x1ff
/* 11215C 7F0DD62C 312B000F */  andi  $t3, $t1, 0xf
/* 112160 7F0DD630 016FC021 */  addu  $t8, $t3, $t7
/* 112164 7F0DD634 0118502A */  slt   $t2, $t0, $t8
/* 112168 7F0DD638 31CD00A8 */  andi  $t5, $t6, 0xa8
/* 11216C 7F0DD63C 000E6203 */  sra   $t4, $t6, 8
/* 112170 7F0DD640 01ACC825 */  or    $t9, $t5, $t4
/* 112174 7F0DD644 02095826 */  xor   $t3, $s0, $t1
/* 112178 7F0DD648 000A6900 */  sll   $t5, $t2, 4
/* 11217C 7F0DD64C 01D0C026 */  xor   $t8, $t6, $s0
/* 112180 7F0DD650 A7AE00EE */  sh    $t6, 0xee($sp)
/* 112184 7F0DD654 93B000EF */  lbu   $s0, 0xef($sp)
/* 112188 7F0DD658 316F0080 */  andi  $t7, $t3, 0x80
/* 11218C 7F0DD65C 01F85024 */  and   $t2, $t7, $t8
/* 112190 7F0DD660 032D6025 */  or    $t4, $t9, $t5
/* 112194 7F0DD664 000AC943 */  sra   $t9, $t2, 5
/* 112198 7F0DD668 97B80298 */  lhu   $t8, 0x298($sp)
/* 11219C 7F0DD66C 01998825 */  or    $s1, $t4, $t9
/* 1121A0 7F0DD670 A3A900ED */  sb    $t1, 0xed($sp)
/* 1121A4 7F0DD674 2E0B0001 */  sltiu $t3, $s0, 1
/* 1121A8 7F0DD678 000B4180 */  sll   $t0, $t3, 6
/* 1121AC 7F0DD67C 36290002 */  ori   $t1, $s1, 2
/* 1121B0 7F0DD680 01288825 */  or    $s1, $t1, $t0
/* 1121B4 7F0DD684 322F00FF */  andi  $t7, $s1, 0xff
/* 1121B8 7F0DD688 270A0001 */  addiu $t2, $t8, 1
/* 1121BC 7F0DD68C 01E08825 */  move  $s1, $t7
/* 1121C0 7F0DD690 AFAB0048 */  sw    $t3, 0x48($sp)
/* 1121C4 7F0DD694 10001459 */  b     .L7F0E27FC
/* 1121C8 7F0DD698 A7AA0298 */   sh    $t2, 0x298($sp)
spectrum_op_DF:
/* 1121CC 7F0DD69C 97AD0292 */  lhu   $t5, 0x292($sp)
/* 1121D0 7F0DD6A0 8FAC028C */  lw    $t4, 0x28c($sp)
/* 1121D4 7F0DD6A4 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 1121D8 7F0DD6A8 25A9FFFE */  addiu $t1, $t5, -2
/* 1121DC 7F0DD6AC 312BFFFF */  andi  $t3, $t1, 0xffff
/* 1121E0 7F0DD6B0 29615B00 */  slti  $at, $t3, 0x5b00
/* 1121E4 7F0DD6B4 2599000B */  addiu $t9, $t4, 0xb
/* 1121E8 7F0DD6B8 AFB9028C */  sw    $t9, 0x28c($sp)
/* 1121EC 7F0DD6BC 14200006 */  bnez  $at, .L7F0DD6D8
/* 1121F0 7F0DD6C0 A7A90292 */   sh    $t1, 0x292($sp)
/* 1121F4 7F0DD6C4 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 1121F8 7F0DD6C8 97AE0298 */  lhu   $t6, 0x298($sp)
/* 1121FC 7F0DD6CC 010B7821 */  addu  $t7, $t0, $t3
/* 112200 7F0DD6D0 10000023 */  b     .L7F0DD760
/* 112204 7F0DD6D4 A1EE0000 */   sb    $t6, ($t7)
.L7F0DD6D8:
/* 112208 7F0DD6D8 97B80292 */  lhu   $t8, 0x292($sp)
/* 11220C 7F0DD6DC 97AE0292 */  lhu   $t6, 0x292($sp)
/* 112210 7F0DD6E0 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 112214 7F0DD6E4 2B015800 */  slti  $at, $t8, 0x5800
/* 112218 7F0DD6E8 5420000D */  bnezl $at, .L7F0DD720
/* 11221C 7F0DD6EC 29C14000 */   slti  $at, $t6, 0x4000
/* 112220 7F0DD6F0 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 112224 7F0DD6F4 97AA0298 */  lhu   $t2, 0x298($sp)
/* 112228 7F0DD6F8 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 11222C 7F0DD6FC 0198C821 */  addu  $t9, $t4, $t8
/* 112230 7F0DD700 A32A0000 */  sb    $t2, ($t9)
/* 112234 7F0DD704 97A80292 */  lhu   $t0, 0x292($sp)
/* 112238 7F0DD708 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 11223C 7F0DD70C 240D0001 */  li    $t5, 1
/* 112240 7F0DD710 01285821 */  addu  $t3, $t1, $t0
/* 112244 7F0DD714 10000012 */  b     .L7F0DD760
/* 112248 7F0DD718 A16DA800 */   sb    $t5, -0x5800($t3)
/* 11224C 7F0DD71C 29C14000 */  slti  $at, $t6, 0x4000
.L7F0DD720:
/* 112250 7F0DD720 1420000F */  bnez  $at, .L7F0DD760
/* 112254 7F0DD724 3C0C8009 */   lui   $t4, %hi(ptr_spectrum_roms) 
/* 112258 7F0DD728 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 11225C 7F0DD72C 97AF0298 */  lhu   $t7, 0x298($sp)
/* 112260 7F0DD730 240A0001 */  li    $t2, 1
/* 112264 7F0DD734 018EC021 */  addu  $t8, $t4, $t6
/* 112268 7F0DD738 A30F0000 */  sb    $t7, ($t8)
/* 11226C 7F0DD73C 97B90292 */  lhu   $t9, 0x292($sp)
/* 112270 7F0DD740 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 112274 7F0DD744 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 112278 7F0DD748 33291800 */  andi  $t1, $t9, 0x1800
/* 11227C 7F0DD74C 000940C3 */  sra   $t0, $t1, 3
/* 112280 7F0DD750 332D00FF */  andi  $t5, $t9, 0xff
/* 112284 7F0DD754 010D5825 */  or    $t3, $t0, $t5
/* 112288 7F0DD758 018B7021 */  addu  $t6, $t4, $t3
/* 11228C 7F0DD75C A1CA0000 */  sb    $t2, ($t6)
.L7F0DD760:
/* 112290 7F0DD760 97AF0292 */  lhu   $t7, 0x292($sp)
/* 112294 7F0DD764 97AC0292 */  lhu   $t4, 0x292($sp)
/* 112298 7F0DD768 97A90298 */  lhu   $t1, 0x298($sp)
/* 11229C 7F0DD76C 25F80001 */  addiu $t8, $t7, 1
/* 1122A0 7F0DD770 2B015B00 */  slti  $at, $t8, 0x5b00
/* 1122A4 7F0DD774 14200007 */  bnez  $at, .L7F0DD794
/* 1122A8 7F0DD778 258B0001 */   addiu $t3, $t4, 1
/* 1122AC 7F0DD77C 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 1122B0 7F0DD780 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 1122B4 7F0DD784 0009CA03 */  sra   $t9, $t1, 8
/* 1122B8 7F0DD788 010F6821 */  addu  $t5, $t0, $t7
/* 1122BC 7F0DD78C 10000025 */  b     .L7F0DD824
/* 1122C0 7F0DD790 A1B90001 */   sb    $t9, 1($t5)
.L7F0DD794:
/* 1122C4 7F0DD794 29615800 */  slti  $at, $t3, 0x5800
/* 1122C8 7F0DD798 1420000E */  bnez  $at, .L7F0DD7D4
/* 1122CC 7F0DD79C 97AB0292 */   lhu   $t3, 0x292($sp)
/* 1122D0 7F0DD7A0 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 1122D4 7F0DD7A4 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 1122D8 7F0DD7A8 97AA0298 */  lhu   $t2, 0x298($sp)
/* 1122DC 7F0DD7AC 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 1122E0 7F0DD7B0 030C4821 */  addu  $t1, $t8, $t4
/* 1122E4 7F0DD7B4 000A7203 */  sra   $t6, $t2, 8
/* 1122E8 7F0DD7B8 A12E0001 */  sb    $t6, 1($t1)
/* 1122EC 7F0DD7BC 97B90292 */  lhu   $t9, 0x292($sp)
/* 1122F0 7F0DD7C0 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 1122F4 7F0DD7C4 24080001 */  li    $t0, 1
/* 1122F8 7F0DD7C8 01F96821 */  addu  $t5, $t7, $t9
/* 1122FC 7F0DD7CC 10000015 */  b     .L7F0DD824
/* 112300 7F0DD7D0 A1A8A801 */   sb    $t0, -0x57ff($t5)
.L7F0DD7D4:
/* 112304 7F0DD7D4 256A0001 */  addiu $t2, $t3, 1
/* 112308 7F0DD7D8 29414000 */  slti  $at, $t2, 0x4000
/* 11230C 7F0DD7DC 14200011 */  bnez  $at, .L7F0DD824
/* 112310 7F0DD7E0 97B80298 */   lhu   $t8, 0x298($sp)
/* 112314 7F0DD7E4 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 112318 7F0DD7E8 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 11231C 7F0DD7EC 00186203 */  sra   $t4, $t8, 8
/* 112320 7F0DD7F0 240F0001 */  li    $t7, 1
/* 112324 7F0DD7F4 01CB4821 */  addu  $t1, $t6, $t3
/* 112328 7F0DD7F8 A12C0001 */  sb    $t4, 1($t1)
/* 11232C 7F0DD7FC 97B90292 */  lhu   $t9, 0x292($sp)
/* 112330 7F0DD800 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 112334 7F0DD804 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 112338 7F0DD808 27280001 */  addiu $t0, $t9, 1
/* 11233C 7F0DD80C 310D1800 */  andi  $t5, $t0, 0x1800
/* 112340 7F0DD810 000D50C3 */  sra   $t2, $t5, 3
/* 112344 7F0DD814 311800FF */  andi  $t8, $t0, 0xff
/* 112348 7F0DD818 01587025 */  or    $t6, $t2, $t8
/* 11234C 7F0DD81C 016E6021 */  addu  $t4, $t3, $t6
/* 112350 7F0DD820 A18F0000 */  sb    $t7, ($t4)
.L7F0DD824:
/* 112354 7F0DD824 24090018 */  li    $t1, 24
/* 112358 7F0DD828 100013F4 */  b     .L7F0E27FC
/* 11235C 7F0DD82C A7A90298 */   sh    $t1, 0x298($sp)
spectrum_op_E0:
/* 112360 7F0DD830 8FB9028C */  lw    $t9, 0x28c($sp)
/* 112364 7F0DD834 32280004 */  andi  $t0, $s1, 4
/* 112368 7F0DD838 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 11236C 7F0DD83C 272D0005 */  addiu $t5, $t9, 5
/* 112370 7F0DD840 150013EE */  bnez  $t0, .L7F0E27FC
/* 112374 7F0DD844 AFAD028C */   sw    $t5, 0x28c($sp)
/* 112378 7F0DD848 97AB0292 */  lhu   $t3, 0x292($sp)
/* 11237C 7F0DD84C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 112380 7F0DD850 25B80006 */  addiu $t8, $t5, 6
/* 112384 7F0DD854 AFB8028C */  sw    $t8, 0x28c($sp)
/* 112388 7F0DD858 01CB4821 */  addu  $t1, $t6, $t3
/* 11238C 7F0DD85C 91390001 */  lbu   $t9, 1($t1)
/* 112390 7F0DD860 016E7821 */  addu  $t7, $t3, $t6
/* 112394 7F0DD864 91EC0000 */  lbu   $t4, ($t7)
/* 112398 7F0DD868 00196A00 */  sll   $t5, $t9, 8
/* 11239C 7F0DD86C 256A0002 */  addiu $t2, $t3, 2
/* 1123A0 7F0DD870 018D4025 */  or    $t0, $t4, $t5
/* 1123A4 7F0DD874 A7A80298 */  sh    $t0, 0x298($sp)
/* 1123A8 7F0DD878 100013E0 */  b     .L7F0E27FC
/* 1123AC 7F0DD87C A7AA0292 */   sh    $t2, 0x292($sp)
spectrum_op_E1:
/* 1123B0 7F0DD880 8FB8028C */  lw    $t8, 0x28c($sp)
/* 1123B4 7F0DD884 93AE0287 */  lbu   $t6, 0x287($sp)
/* 1123B8 7F0DD888 93A80287 */  lbu   $t0, 0x287($sp)
/* 1123BC 7F0DD88C 270F000A */  addiu $t7, $t8, 0xa
/* 1123C0 7F0DD890 15C0000A */  bnez  $t6, .L7F0DD8BC
/* 1123C4 7F0DD894 AFAF028C */   sw    $t7, 0x28c($sp)
/* 1123C8 7F0DD898 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 1123CC 7F0DD89C 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 1123D0 7F0DD8A0 97A90292 */  lhu   $t1, 0x292($sp)
/* 1123D4 7F0DD8A4 01396021 */  addu  $t4, $t1, $t9
/* 1123D8 7F0DD8A8 91970000 */  lbu   $s7, ($t4)
/* 1123DC 7F0DD8AC 91960001 */  lbu   $s6, 1($t4)
/* 1123E0 7F0DD8B0 252D0002 */  addiu $t5, $t1, 2
/* 1123E4 7F0DD8B4 100013D1 */  b     .L7F0E27FC
/* 1123E8 7F0DD8B8 A7AD0292 */   sh    $t5, 0x292($sp)
.L7F0DD8BC:
/* 1123EC 7F0DD8BC 24010001 */  li    $at, 1
/* 1123F0 7F0DD8C0 1501000E */  bne   $t0, $at, .L7F0DD8FC
/* 1123F4 7F0DD8C4 3C188009 */   lui   $t8, %hi(ptr_spectrum_roms)
/* 1123F8 7F0DD8C8 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 1123FC 7F0DD8CC 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 112400 7F0DD8D0 97AB0292 */  lhu   $t3, 0x292($sp)
/* 112404 7F0DD8D4 014B7021 */  addu  $t6, $t2, $t3
/* 112408 7F0DD8D8 91D90001 */  lbu   $t9, 1($t6)
/* 11240C 7F0DD8DC 016AC021 */  addu  $t8, $t3, $t2
/* 112410 7F0DD8E0 930F0000 */  lbu   $t7, ($t8)
/* 112414 7F0DD8E4 00196200 */  sll   $t4, $t9, 8
/* 112418 7F0DD8E8 256D0002 */  addiu $t5, $t3, 2
/* 11241C 7F0DD8EC 01EC4825 */  or    $t1, $t7, $t4
/* 112420 7F0DD8F0 A7A90296 */  sh    $t1, 0x296($sp)
/* 112424 7F0DD8F4 100013C1 */  b     .L7F0E27FC
/* 112428 7F0DD8F8 A7AD0292 */   sh    $t5, 0x292($sp)
.L7F0DD8FC:
/* 11242C 7F0DD8FC 97A80292 */  lhu   $t0, 0x292($sp)
/* 112430 7F0DD900 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 112434 7F0DD904 250B0002 */  addiu $t3, $t0, 2
/* 112438 7F0DD908 0308C821 */  addu  $t9, $t8, $t0
/* 11243C 7F0DD90C 932F0001 */  lbu   $t7, 1($t9)
/* 112440 7F0DD910 01185021 */  addu  $t2, $t0, $t8
/* 112444 7F0DD914 914E0000 */  lbu   $t6, ($t2)
/* 112448 7F0DD918 000F6200 */  sll   $t4, $t7, 8
/* 11244C 7F0DD91C A7AB0292 */  sh    $t3, 0x292($sp)
/* 112450 7F0DD920 01CC4825 */  or    $t1, $t6, $t4
/* 112454 7F0DD924 100013B5 */  b     .L7F0E27FC
/* 112458 7F0DD928 A7A90294 */   sh    $t1, 0x294($sp)
spectrum_op_E2:
/* 11245C 7F0DD92C 8FAD028C */  lw    $t5, 0x28c($sp)
/* 112460 7F0DD930 32380004 */  andi  $t8, $s1, 4
/* 112464 7F0DD934 97B90298 */  lhu   $t9, 0x298($sp)
/* 112468 7F0DD938 25AA000A */  addiu $t2, $t5, 0xa
/* 11246C 7F0DD93C 1700000B */  bnez  $t8, .L7F0DD96C
/* 112470 7F0DD940 AFAA028C */   sw    $t2, 0x28c($sp)
/* 112474 7F0DD944 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 112478 7F0DD948 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 11247C 7F0DD94C 01F94821 */  addu  $t1, $t7, $t9
/* 112480 7F0DD950 91280001 */  lbu   $t0, 1($t1)
/* 112484 7F0DD954 032F7021 */  addu  $t6, $t9, $t7
/* 112488 7F0DD958 91CC0000 */  lbu   $t4, ($t6)
/* 11248C 7F0DD95C 00085A00 */  sll   $t3, $t0, 8
/* 112490 7F0DD960 018B6825 */  or    $t5, $t4, $t3
/* 112494 7F0DD964 100013A5 */  b     .L7F0E27FC
/* 112498 7F0DD968 A7AD0298 */   sh    $t5, 0x298($sp)
.L7F0DD96C:
/* 11249C 7F0DD96C 97AA0298 */  lhu   $t2, 0x298($sp)
/* 1124A0 7F0DD970 25580002 */  addiu $t8, $t2, 2
/* 1124A4 7F0DD974 100013A1 */  b     .L7F0E27FC
/* 1124A8 7F0DD978 A7B80298 */   sh    $t8, 0x298($sp)
spectrum_op_E3:
/* 1124AC 7F0DD97C 8FAE028C */  lw    $t6, 0x28c($sp)
/* 1124B0 7F0DD980 93B90287 */  lbu   $t9, 0x287($sp)
/* 1124B4 7F0DD984 93AC0287 */  lbu   $t4, 0x287($sp)
/* 1124B8 7F0DD988 25CF0013 */  addiu $t7, $t6, 0x13
/* 1124BC 7F0DD98C 17200063 */  bnez  $t9, .L7F0DDB1C
/* 1124C0 7F0DD990 AFAF028C */   sw    $t7, 0x28c($sp)
/* 1124C4 7F0DD994 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 1124C8 7F0DD998 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 1124CC 7F0DD99C 97A90292 */  lhu   $t1, 0x292($sp)
/* 1124D0 7F0DD9A0 97AF0292 */  lhu   $t7, 0x292($sp)
/* 1124D4 7F0DD9A4 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 1124D8 7F0DD9A8 01096821 */  addu  $t5, $t0, $t1
/* 1124DC 7F0DD9AC 91AA0001 */  lbu   $t2, 1($t5)
/* 1124E0 7F0DD9B0 01286021 */  addu  $t4, $t1, $t0
/* 1124E4 7F0DD9B4 918B0000 */  lbu   $t3, ($t4)
/* 1124E8 7F0DD9B8 000AC200 */  sll   $t8, $t2, 8
/* 1124EC 7F0DD9BC 29E15B00 */  slti  $at, $t7, 0x5b00
/* 1124F0 7F0DD9C0 01787025 */  or    $t6, $t3, $t8
/* 1124F4 7F0DD9C4 14200005 */  bnez  $at, .L7F0DD9DC
/* 1124F8 7F0DD9C8 A7AE00EA */   sh    $t6, 0xea($sp)
/* 1124FC 7F0DD9CC 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 112500 7F0DD9D0 032F6021 */  addu  $t4, $t9, $t7
/* 112504 7F0DD9D4 10000021 */  b     .L7F0DDA5C
/* 112508 7F0DD9D8 A1970000 */   sb    $s7, ($t4)
.L7F0DD9DC:
/* 11250C 7F0DD9DC 97A80292 */  lhu   $t0, 0x292($sp)
/* 112510 7F0DD9E0 97B90292 */  lhu   $t9, 0x292($sp)
/* 112514 7F0DD9E4 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 112518 7F0DD9E8 29015800 */  slti  $at, $t0, 0x5800
/* 11251C 7F0DD9EC 5420000C */  bnezl $at, .L7F0DDA20
/* 112520 7F0DD9F0 2B214000 */   slti  $at, $t9, 0x4000
/* 112524 7F0DD9F4 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 112528 7F0DD9F8 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 11252C 7F0DD9FC 240A0001 */  li    $t2, 1
/* 112530 7F0DDA00 01286821 */  addu  $t5, $t1, $t0
/* 112534 7F0DDA04 A1B70000 */  sb    $s7, ($t5)
/* 112538 7F0DDA08 97B80292 */  lhu   $t8, 0x292($sp)
/* 11253C 7F0DDA0C 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 112540 7F0DDA10 01787021 */  addu  $t6, $t3, $t8
/* 112544 7F0DDA14 10000011 */  b     .L7F0DDA5C
/* 112548 7F0DDA18 A1CAA800 */   sb    $t2, -0x5800($t6)
/* 11254C 7F0DDA1C 2B214000 */  slti  $at, $t9, 0x4000
.L7F0DDA20:
/* 112550 7F0DDA20 1420000E */  bnez  $at, .L7F0DDA5C
/* 112554 7F0DDA24 3C0F8009 */   lui   $t7, %hi(ptr_spectrum_roms) 
/* 112558 7F0DDA28 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 11255C 7F0DDA2C 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 112560 7F0DDA30 24090001 */  li    $t1, 1
/* 112564 7F0DDA34 01F96021 */  addu  $t4, $t7, $t9
/* 112568 7F0DDA38 A1970000 */  sb    $s7, ($t4)
/* 11256C 7F0DDA3C 97A80292 */  lhu   $t0, 0x292($sp)
/* 112570 7F0DDA40 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 112574 7F0DDA44 310D1800 */  andi  $t5, $t0, 0x1800
/* 112578 7F0DDA48 000D58C3 */  sra   $t3, $t5, 3
/* 11257C 7F0DDA4C 311800FF */  andi  $t8, $t0, 0xff
/* 112580 7F0DDA50 01785025 */  or    $t2, $t3, $t8
/* 112584 7F0DDA54 01CA7821 */  addu  $t7, $t6, $t2
/* 112588 7F0DDA58 A1E90000 */  sb    $t1, ($t7)
.L7F0DDA5C:
/* 11258C 7F0DDA5C 97B90292 */  lhu   $t9, 0x292($sp)
/* 112590 7F0DDA60 97AB0292 */  lhu   $t3, 0x292($sp)
/* 112594 7F0DDA64 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 112598 7F0DDA68 272C0001 */  addiu $t4, $t9, 1
/* 11259C 7F0DDA6C 29815B00 */  slti  $at, $t4, 0x5b00
/* 1125A0 7F0DDA70 14200005 */  bnez  $at, .L7F0DDA88
/* 1125A4 7F0DDA74 25780001 */   addiu $t8, $t3, 1
/* 1125A8 7F0DDA78 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 1125AC 7F0DDA7C 01B94021 */  addu  $t0, $t5, $t9
/* 1125B0 7F0DDA80 10000021 */  b     .L7F0DDB08
/* 1125B4 7F0DDA84 A1160001 */   sb    $s6, 1($t0)
.L7F0DDA88:
/* 1125B8 7F0DDA88 2B015800 */  slti  $at, $t8, 0x5800
/* 1125BC 7F0DDA8C 1420000C */  bnez  $at, .L7F0DDAC0
/* 1125C0 7F0DDA90 97B90292 */   lhu   $t9, 0x292($sp)
/* 1125C4 7F0DDA94 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 1125C8 7F0DDA98 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 1125CC 7F0DDA9C 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 1125D0 7F0DDAA0 24090001 */  li    $t1, 1
/* 1125D4 7F0DDAA4 01CB5021 */  addu  $t2, $t6, $t3
/* 1125D8 7F0DDAA8 A1560001 */  sb    $s6, 1($t2)
/* 1125DC 7F0DDAAC 97AC0292 */  lhu   $t4, 0x292($sp)
/* 1125E0 7F0DDAB0 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 1125E4 7F0DDAB4 01EC6821 */  addu  $t5, $t7, $t4
/* 1125E8 7F0DDAB8 10000013 */  b     .L7F0DDB08
/* 1125EC 7F0DDABC A1A9A801 */   sb    $t1, -0x57ff($t5)
.L7F0DDAC0:
/* 1125F0 7F0DDAC0 27280001 */  addiu $t0, $t9, 1
/* 1125F4 7F0DDAC4 29014000 */  slti  $at, $t0, 0x4000
/* 1125F8 7F0DDAC8 1420000F */  bnez  $at, .L7F0DDB08
/* 1125FC 7F0DDACC 3C188009 */   lui   $t8, %hi(ptr_spectrum_roms) 
/* 112600 7F0DDAD0 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 112604 7F0DDAD4 240B0001 */  li    $t3, 1
/* 112608 7F0DDAD8 03197021 */  addu  $t6, $t8, $t9
/* 11260C 7F0DDADC A1D60001 */  sb    $s6, 1($t6)
/* 112610 7F0DDAE0 97AA0292 */  lhu   $t2, 0x292($sp)
/* 112614 7F0DDAE4 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 112618 7F0DDAE8 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 11261C 7F0DDAEC 254F0001 */  addiu $t7, $t2, 1
/* 112620 7F0DDAF0 31EC1800 */  andi  $t4, $t7, 0x1800
/* 112624 7F0DDAF4 000C48C3 */  sra   $t1, $t4, 3
/* 112628 7F0DDAF8 31ED00FF */  andi  $t5, $t7, 0xff
/* 11262C 7F0DDAFC 012D4025 */  or    $t0, $t1, $t5
/* 112630 7F0DDB00 0308C821 */  addu  $t9, $t8, $t0
/* 112634 7F0DDB04 A32B0000 */  sb    $t3, ($t9)
.L7F0DDB08:
/* 112638 7F0DDB08 97B600EA */  lhu   $s6, 0xea($sp)
/* 11263C 7F0DDB0C 93B700EB */  lbu   $s7, 0xeb($sp)
/* 112640 7F0DDB10 00167203 */  sra   $t6, $s6, 8
/* 112644 7F0DDB14 10001339 */  b     .L7F0E27FC
/* 112648 7F0DDB18 31D600FF */   andi  $s6, $t6, 0xff
.L7F0DDB1C:
/* 11264C 7F0DDB1C 24010001 */  li    $at, 1
/* 112650 7F0DDB20 1581006A */  bne   $t4, $at, .L7F0DDCCC
/* 112654 7F0DDB24 97B80292 */   lhu   $t8, 0x292($sp)
/* 112658 7F0DDB28 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 11265C 7F0DDB2C 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 112660 7F0DDB30 97AF0292 */  lhu   $t7, 0x292($sp)
/* 112664 7F0DDB34 97AA0292 */  lhu   $t2, 0x292($sp)
/* 112668 7F0DDB38 012F4021 */  addu  $t0, $t1, $t7
/* 11266C 7F0DDB3C 910B0001 */  lbu   $t3, 1($t0)
/* 112670 7F0DDB40 01E96821 */  addu  $t5, $t7, $t1
/* 112674 7F0DDB44 91B80000 */  lbu   $t8, ($t5)
/* 112678 7F0DDB48 000BCA00 */  sll   $t9, $t3, 8
/* 11267C 7F0DDB4C 29415B00 */  slti  $at, $t2, 0x5b00
/* 112680 7F0DDB50 03197025 */  or    $t6, $t8, $t9
/* 112684 7F0DDB54 14200007 */  bnez  $at, .L7F0DDB74
/* 112688 7F0DDB58 A7AE00E8 */   sh    $t6, 0xe8($sp)
/* 11268C 7F0DDB5C 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 112690 7F0DDB60 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 112694 7F0DDB64 97AC0296 */  lhu   $t4, 0x296($sp)
/* 112698 7F0DDB68 01AA4821 */  addu  $t1, $t5, $t2
/* 11269C 7F0DDB6C 10000023 */  b     .L7F0DDBFC
/* 1126A0 7F0DDB70 A12C0000 */   sb    $t4, ($t1)
.L7F0DDB74:
/* 1126A4 7F0DDB74 97AF0292 */  lhu   $t7, 0x292($sp)
/* 1126A8 7F0DDB78 97AC0292 */  lhu   $t4, 0x292($sp)
/* 1126AC 7F0DDB7C 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 1126B0 7F0DDB80 29E15800 */  slti  $at, $t7, 0x5800
/* 1126B4 7F0DDB84 5420000D */  bnezl $at, .L7F0DDBBC
/* 1126B8 7F0DDB88 29814000 */   slti  $at, $t4, 0x4000
/* 1126BC 7F0DDB8C 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 1126C0 7F0DDB90 97A80296 */  lhu   $t0, 0x296($sp)
/* 1126C4 7F0DDB94 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 1126C8 7F0DDB98 016FC021 */  addu  $t8, $t3, $t7
/* 1126CC 7F0DDB9C A3080000 */  sb    $t0, ($t8)
/* 1126D0 7F0DDBA0 97AD0292 */  lhu   $t5, 0x292($sp)
/* 1126D4 7F0DDBA4 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 1126D8 7F0DDBA8 24190001 */  li    $t9, 1
/* 1126DC 7F0DDBAC 01CD5021 */  addu  $t2, $t6, $t5
/* 1126E0 7F0DDBB0 10000012 */  b     .L7F0DDBFC
/* 1126E4 7F0DDBB4 A159A800 */   sb    $t9, -0x5800($t2)
/* 1126E8 7F0DDBB8 29814000 */  slti  $at, $t4, 0x4000
.L7F0DDBBC:
/* 1126EC 7F0DDBBC 1420000F */  bnez  $at, .L7F0DDBFC
/* 1126F0 7F0DDBC0 3C0B8009 */   lui   $t3, %hi(ptr_spectrum_roms) 
/* 1126F4 7F0DDBC4 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 1126F8 7F0DDBC8 97A90296 */  lhu   $t1, 0x296($sp)
/* 1126FC 7F0DDBCC 24080001 */  li    $t0, 1
/* 112700 7F0DDBD0 016C7821 */  addu  $t7, $t3, $t4
/* 112704 7F0DDBD4 A1E90000 */  sb    $t1, ($t7)
/* 112708 7F0DDBD8 97B80292 */  lhu   $t8, 0x292($sp)
/* 11270C 7F0DDBDC 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 112710 7F0DDBE0 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 112714 7F0DDBE4 330E1800 */  andi  $t6, $t8, 0x1800
/* 112718 7F0DDBE8 000E68C3 */  sra   $t5, $t6, 3
/* 11271C 7F0DDBEC 331900FF */  andi  $t9, $t8, 0xff
/* 112720 7F0DDBF0 01B95025 */  or    $t2, $t5, $t9
/* 112724 7F0DDBF4 016A6021 */  addu  $t4, $t3, $t2
/* 112728 7F0DDBF8 A1880000 */  sb    $t0, ($t4)
.L7F0DDBFC:
/* 11272C 7F0DDBFC 97A90292 */  lhu   $t1, 0x292($sp)
/* 112730 7F0DDC00 97AB0292 */  lhu   $t3, 0x292($sp)
/* 112734 7F0DDC04 97AE0296 */  lhu   $t6, 0x296($sp)
/* 112738 7F0DDC08 252F0001 */  addiu $t7, $t1, 1
/* 11273C 7F0DDC0C 29E15B00 */  slti  $at, $t7, 0x5b00
/* 112740 7F0DDC10 14200007 */  bnez  $at, .L7F0DDC30
/* 112744 7F0DDC14 256A0001 */   addiu $t2, $t3, 1
/* 112748 7F0DDC18 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 11274C 7F0DDC1C 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 112750 7F0DDC20 000EC203 */  sra   $t8, $t6, 8
/* 112754 7F0DDC24 01A9C821 */  addu  $t9, $t5, $t1
/* 112758 7F0DDC28 10000025 */  b     .L7F0DDCC0
/* 11275C 7F0DDC2C A3380001 */   sb    $t8, 1($t9)
.L7F0DDC30:
/* 112760 7F0DDC30 29415800 */  slti  $at, $t2, 0x5800
/* 112764 7F0DDC34 1420000E */  bnez  $at, .L7F0DDC70
/* 112768 7F0DDC38 97AA0292 */   lhu   $t2, 0x292($sp)
/* 11276C 7F0DDC3C 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 112770 7F0DDC40 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 112774 7F0DDC44 97A80296 */  lhu   $t0, 0x296($sp)
/* 112778 7F0DDC48 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 11277C 7F0DDC4C 01EB7021 */  addu  $t6, $t7, $t3
/* 112780 7F0DDC50 00086203 */  sra   $t4, $t0, 8
/* 112784 7F0DDC54 A1CC0001 */  sb    $t4, 1($t6)
/* 112788 7F0DDC58 97B80292 */  lhu   $t8, 0x292($sp)
/* 11278C 7F0DDC5C 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 112790 7F0DDC60 240D0001 */  li    $t5, 1
/* 112794 7F0DDC64 0138C821 */  addu  $t9, $t1, $t8
/* 112798 7F0DDC68 10000015 */  b     .L7F0DDCC0
/* 11279C 7F0DDC6C A32DA801 */   sb    $t5, -0x57ff($t9)
.L7F0DDC70:
/* 1127A0 7F0DDC70 25480001 */  addiu $t0, $t2, 1
/* 1127A4 7F0DDC74 29014000 */  slti  $at, $t0, 0x4000
/* 1127A8 7F0DDC78 14200011 */  bnez  $at, .L7F0DDCC0
/* 1127AC 7F0DDC7C 97AF0296 */   lhu   $t7, 0x296($sp)
/* 1127B0 7F0DDC80 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 1127B4 7F0DDC84 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 1127B8 7F0DDC88 000F5A03 */  sra   $t3, $t7, 8
/* 1127BC 7F0DDC8C 24090001 */  li    $t1, 1
/* 1127C0 7F0DDC90 018A7021 */  addu  $t6, $t4, $t2
/* 1127C4 7F0DDC94 A1CB0001 */  sb    $t3, 1($t6)
/* 1127C8 7F0DDC98 97B80292 */  lhu   $t8, 0x292($sp)
/* 1127CC 7F0DDC9C 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 1127D0 7F0DDCA0 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 1127D4 7F0DDCA4 270D0001 */  addiu $t5, $t8, 1
/* 1127D8 7F0DDCA8 31B91800 */  andi  $t9, $t5, 0x1800
/* 1127DC 7F0DDCAC 001940C3 */  sra   $t0, $t9, 3
/* 1127E0 7F0DDCB0 31AF00FF */  andi  $t7, $t5, 0xff
/* 1127E4 7F0DDCB4 010F6025 */  or    $t4, $t0, $t7
/* 1127E8 7F0DDCB8 014C5821 */  addu  $t3, $t2, $t4
/* 1127EC 7F0DDCBC A1690000 */  sb    $t1, ($t3)
.L7F0DDCC0:
/* 1127F0 7F0DDCC0 97AE00E8 */  lhu   $t6, 0xe8($sp)
/* 1127F4 7F0DDCC4 100012CD */  b     .L7F0E27FC
/* 1127F8 7F0DDCC8 A7AE0296 */   sh    $t6, 0x296($sp)
.L7F0DDCCC:
/* 1127FC 7F0DDCCC 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 112800 7F0DDCD0 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 112804 7F0DDCD4 97AB0292 */  lhu   $t3, 0x292($sp)
/* 112808 7F0DDCD8 03387821 */  addu  $t7, $t9, $t8
/* 11280C 7F0DDCDC 91EA0001 */  lbu   $t2, 1($t7)
/* 112810 7F0DDCE0 03196821 */  addu  $t5, $t8, $t9
/* 112814 7F0DDCE4 91A80000 */  lbu   $t0, ($t5)
/* 112818 7F0DDCE8 000A6200 */  sll   $t4, $t2, 8
/* 11281C 7F0DDCEC 29615B00 */  slti  $at, $t3, 0x5b00
/* 112820 7F0DDCF0 010C4825 */  or    $t1, $t0, $t4
/* 112824 7F0DDCF4 14200007 */  bnez  $at, .L7F0DDD14
/* 112828 7F0DDCF8 A7A900E6 */   sh    $t1, 0xe6($sp)
/* 11282C 7F0DDCFC 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 112830 7F0DDD00 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 112834 7F0DDD04 97AE0294 */  lhu   $t6, 0x294($sp)
/* 112838 7F0DDD08 01ABC821 */  addu  $t9, $t5, $t3
/* 11283C 7F0DDD0C 10000023 */  b     .L7F0DDD9C
/* 112840 7F0DDD10 A32E0000 */   sb    $t6, ($t9)
.L7F0DDD14:
/* 112844 7F0DDD14 97B80292 */  lhu   $t8, 0x292($sp)
/* 112848 7F0DDD18 97AE0292 */  lhu   $t6, 0x292($sp)
/* 11284C 7F0DDD1C 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 112850 7F0DDD20 2B015800 */  slti  $at, $t8, 0x5800
/* 112854 7F0DDD24 5420000D */  bnezl $at, .L7F0DDD5C
/* 112858 7F0DDD28 29C14000 */   slti  $at, $t6, 0x4000
/* 11285C 7F0DDD2C 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 112860 7F0DDD30 97AF0294 */  lhu   $t7, 0x294($sp)
/* 112864 7F0DDD34 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 112868 7F0DDD38 01584021 */  addu  $t0, $t2, $t8
/* 11286C 7F0DDD3C A10F0000 */  sb    $t7, ($t0)
/* 112870 7F0DDD40 97AD0292 */  lhu   $t5, 0x292($sp)
/* 112874 7F0DDD44 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 112878 7F0DDD48 240C0001 */  li    $t4, 1
/* 11287C 7F0DDD4C 012D5821 */  addu  $t3, $t1, $t5
/* 112880 7F0DDD50 10000012 */  b     .L7F0DDD9C
/* 112884 7F0DDD54 A16CA800 */   sb    $t4, -0x5800($t3)
/* 112888 7F0DDD58 29C14000 */  slti  $at, $t6, 0x4000
.L7F0DDD5C:
/* 11288C 7F0DDD5C 1420000F */  bnez  $at, .L7F0DDD9C
/* 112890 7F0DDD60 3C0A8009 */   lui   $t2, %hi(ptr_spectrum_roms) 
/* 112894 7F0DDD64 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 112898 7F0DDD68 97B90294 */  lhu   $t9, 0x294($sp)
/* 11289C 7F0DDD6C 240F0001 */  li    $t7, 1
/* 1128A0 7F0DDD70 014EC021 */  addu  $t8, $t2, $t6
/* 1128A4 7F0DDD74 A3190000 */  sb    $t9, ($t8)
/* 1128A8 7F0DDD78 97A80292 */  lhu   $t0, 0x292($sp)
/* 1128AC 7F0DDD7C 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 1128B0 7F0DDD80 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 1128B4 7F0DDD84 31091800 */  andi  $t1, $t0, 0x1800
/* 1128B8 7F0DDD88 000968C3 */  sra   $t5, $t1, 3
/* 1128BC 7F0DDD8C 310C00FF */  andi  $t4, $t0, 0xff
/* 1128C0 7F0DDD90 01AC5825 */  or    $t3, $t5, $t4
/* 1128C4 7F0DDD94 014B7021 */  addu  $t6, $t2, $t3
/* 1128C8 7F0DDD98 A1CF0000 */  sb    $t7, ($t6)
.L7F0DDD9C:
/* 1128CC 7F0DDD9C 97B90292 */  lhu   $t9, 0x292($sp)
/* 1128D0 7F0DDDA0 97AA0292 */  lhu   $t2, 0x292($sp)
/* 1128D4 7F0DDDA4 97A90294 */  lhu   $t1, 0x294($sp)
/* 1128D8 7F0DDDA8 27380001 */  addiu $t8, $t9, 1
/* 1128DC 7F0DDDAC 2B015B00 */  slti  $at, $t8, 0x5b00
/* 1128E0 7F0DDDB0 14200007 */  bnez  $at, .L7F0DDDD0
/* 1128E4 7F0DDDB4 254B0001 */   addiu $t3, $t2, 1
/* 1128E8 7F0DDDB8 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 1128EC 7F0DDDBC 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 1128F0 7F0DDDC0 00094203 */  sra   $t0, $t1, 8
/* 1128F4 7F0DDDC4 01B96021 */  addu  $t4, $t5, $t9
/* 1128F8 7F0DDDC8 10000025 */  b     .L7F0DDE60
/* 1128FC 7F0DDDCC A1880001 */   sb    $t0, 1($t4)
.L7F0DDDD0:
/* 112900 7F0DDDD0 29615800 */  slti  $at, $t3, 0x5800
/* 112904 7F0DDDD4 1420000E */  bnez  $at, .L7F0DDE10
/* 112908 7F0DDDD8 97AB0292 */   lhu   $t3, 0x292($sp)
/* 11290C 7F0DDDDC 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 112910 7F0DDDE0 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 112914 7F0DDDE4 97AF0294 */  lhu   $t7, 0x294($sp)
/* 112918 7F0DDDE8 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 11291C 7F0DDDEC 030A4821 */  addu  $t1, $t8, $t2
/* 112920 7F0DDDF0 000F7203 */  sra   $t6, $t7, 8
/* 112924 7F0DDDF4 A12E0001 */  sb    $t6, 1($t1)
/* 112928 7F0DDDF8 97A80292 */  lhu   $t0, 0x292($sp)
/* 11292C 7F0DDDFC 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 112930 7F0DDE00 240D0001 */  li    $t5, 1
/* 112934 7F0DDE04 03286021 */  addu  $t4, $t9, $t0
/* 112938 7F0DDE08 10000015 */  b     .L7F0DDE60
/* 11293C 7F0DDE0C A18DA801 */   sb    $t5, -0x57ff($t4)
.L7F0DDE10:
/* 112940 7F0DDE10 256F0001 */  addiu $t7, $t3, 1
/* 112944 7F0DDE14 29E14000 */  slti  $at, $t7, 0x4000
/* 112948 7F0DDE18 14200011 */  bnez  $at, .L7F0DDE60
/* 11294C 7F0DDE1C 97B80294 */   lhu   $t8, 0x294($sp)
/* 112950 7F0DDE20 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 112954 7F0DDE24 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 112958 7F0DDE28 00185203 */  sra   $t2, $t8, 8
/* 11295C 7F0DDE2C 24190001 */  li    $t9, 1
/* 112960 7F0DDE30 01CB4821 */  addu  $t1, $t6, $t3
/* 112964 7F0DDE34 A12A0001 */  sb    $t2, 1($t1)
/* 112968 7F0DDE38 97A80292 */  lhu   $t0, 0x292($sp)
/* 11296C 7F0DDE3C 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 112970 7F0DDE40 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 112974 7F0DDE44 250D0001 */  addiu $t5, $t0, 1
/* 112978 7F0DDE48 31AC1800 */  andi  $t4, $t5, 0x1800
/* 11297C 7F0DDE4C 000C78C3 */  sra   $t7, $t4, 3
/* 112980 7F0DDE50 31B800FF */  andi  $t8, $t5, 0xff
/* 112984 7F0DDE54 01F87025 */  or    $t6, $t7, $t8
/* 112988 7F0DDE58 016E5021 */  addu  $t2, $t3, $t6
/* 11298C 7F0DDE5C A1590000 */  sb    $t9, ($t2)
.L7F0DDE60:
/* 112990 7F0DDE60 97A900E6 */  lhu   $t1, 0xe6($sp)
/* 112994 7F0DDE64 10001265 */  b     .L7F0E27FC
/* 112998 7F0DDE68 A7A90294 */   sh    $t1, 0x294($sp)
spectrum_op_E4:
/* 11299C 7F0DDE6C 8FA8028C */  lw    $t0, 0x28c($sp)
/* 1129A0 7F0DDE70 322D0004 */  andi  $t5, $s1, 4
/* 1129A4 7F0DDE74 250C000A */  addiu $t4, $t0, 0xa
/* 1129A8 7F0DDE78 15A00072 */  bnez  $t5, .L7F0DE044
/* 1129AC 7F0DDE7C AFAC028C */   sw    $t4, 0x28c($sp)
/* 1129B0 7F0DDE80 97AB0292 */  lhu   $t3, 0x292($sp)
/* 1129B4 7F0DDE84 25980007 */  addiu $t8, $t4, 7
/* 1129B8 7F0DDE88 AFB8028C */  sw    $t8, 0x28c($sp)
/* 1129BC 7F0DDE8C 256EFFFE */  addiu $t6, $t3, -2
/* 1129C0 7F0DDE90 31D9FFFF */  andi  $t9, $t6, 0xffff
/* 1129C4 7F0DDE94 2B215B00 */  slti  $at, $t9, 0x5b00
/* 1129C8 7F0DDE98 14200008 */  bnez  $at, .L7F0DDEBC
/* 1129CC 7F0DDE9C A7AE0292 */   sh    $t6, 0x292($sp)
/* 1129D0 7F0DDEA0 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 1129D4 7F0DDEA4 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 1129D8 7F0DDEA8 97AA0298 */  lhu   $t2, 0x298($sp)
/* 1129DC 7F0DDEAC 01196021 */  addu  $t4, $t0, $t9
/* 1129E0 7F0DDEB0 25490002 */  addiu $t1, $t2, 2
/* 1129E4 7F0DDEB4 10000024 */  b     .L7F0DDF48
/* 1129E8 7F0DDEB8 A1890000 */   sb    $t1, ($t4)
.L7F0DDEBC:
/* 1129EC 7F0DDEBC 97AD0292 */  lhu   $t5, 0x292($sp)
/* 1129F0 7F0DDEC0 97AC0292 */  lhu   $t4, 0x292($sp)
/* 1129F4 7F0DDEC4 97AF0298 */  lhu   $t7, 0x298($sp)
/* 1129F8 7F0DDEC8 29A15800 */  slti  $at, $t5, 0x5800
/* 1129FC 7F0DDECC 1420000C */  bnez  $at, .L7F0DDF00
/* 112A00 7F0DDED0 3C0B8009 */   lui   $t3, %hi(ptr_spectrum_roms) 
/* 112A04 7F0DDED4 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 112A08 7F0DDED8 25F80002 */  addiu $t8, $t7, 2
/* 112A0C 7F0DDEDC 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 112A10 7F0DDEE0 016D7021 */  addu  $t6, $t3, $t5
/* 112A14 7F0DDEE4 A1D80000 */  sb    $t8, ($t6)
/* 112A18 7F0DDEE8 97B90292 */  lhu   $t9, 0x292($sp)
/* 112A1C 7F0DDEEC 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 112A20 7F0DDEF0 240A0001 */  li    $t2, 1
/* 112A24 7F0DDEF4 01194821 */  addu  $t1, $t0, $t9
/* 112A28 7F0DDEF8 10000013 */  b     .L7F0DDF48
/* 112A2C 7F0DDEFC A12AA800 */   sb    $t2, -0x5800($t1)
.L7F0DDF00:
/* 112A30 7F0DDF00 29814000 */  slti  $at, $t4, 0x4000
/* 112A34 7F0DDF04 14200010 */  bnez  $at, .L7F0DDF48
/* 112A38 7F0DDF08 97AF0298 */   lhu   $t7, 0x298($sp)
/* 112A3C 7F0DDF0C 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 112A40 7F0DDF10 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 112A44 7F0DDF14 25EB0002 */  addiu $t3, $t7, 2
/* 112A48 7F0DDF18 240E0001 */  li    $t6, 1
/* 112A4C 7F0DDF1C 01ACC021 */  addu  $t8, $t5, $t4
/* 112A50 7F0DDF20 A30B0000 */  sb    $t3, ($t8)
/* 112A54 7F0DDF24 97A80292 */  lhu   $t0, 0x292($sp)
/* 112A58 7F0DDF28 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 112A5C 7F0DDF2C 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 112A60 7F0DDF30 31191800 */  andi  $t9, $t0, 0x1800
/* 112A64 7F0DDF34 001950C3 */  sra   $t2, $t9, 3
/* 112A68 7F0DDF38 310900FF */  andi  $t1, $t0, 0xff
/* 112A6C 7F0DDF3C 01497825 */  or    $t7, $t2, $t1
/* 112A70 7F0DDF40 01AF6021 */  addu  $t4, $t5, $t7
/* 112A74 7F0DDF44 A18E0000 */  sb    $t6, ($t4)
.L7F0DDF48:
/* 112A78 7F0DDF48 97AB0292 */  lhu   $t3, 0x292($sp)
/* 112A7C 7F0DDF4C 97AF0292 */  lhu   $t7, 0x292($sp)
/* 112A80 7F0DDF50 97B90298 */  lhu   $t9, 0x298($sp)
/* 112A84 7F0DDF54 25780001 */  addiu $t8, $t3, 1
/* 112A88 7F0DDF58 2B015B00 */  slti  $at, $t8, 0x5b00
/* 112A8C 7F0DDF5C 14200008 */  bnez  $at, .L7F0DDF80
/* 112A90 7F0DDF60 25EE0001 */   addiu $t6, $t7, 1
/* 112A94 7F0DDF64 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 112A98 7F0DDF68 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 112A9C 7F0DDF6C 27280002 */  addiu $t0, $t9, 2
/* 112AA0 7F0DDF70 00085203 */  sra   $t2, $t0, 8
/* 112AA4 7F0DDF74 012B6821 */  addu  $t5, $t1, $t3
/* 112AA8 7F0DDF78 10000027 */  b     .L7F0DE018
/* 112AAC 7F0DDF7C A1AA0001 */   sb    $t2, 1($t5)
.L7F0DDF80:
/* 112AB0 7F0DDF80 29C15800 */  slti  $at, $t6, 0x5800
/* 112AB4 7F0DDF84 1420000F */  bnez  $at, .L7F0DDFC4
/* 112AB8 7F0DDF88 97AC0292 */   lhu   $t4, 0x292($sp)
/* 112ABC 7F0DDF8C 97AC0298 */  lhu   $t4, 0x298($sp)
/* 112AC0 7F0DDF90 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 112AC4 7F0DDF94 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 112AC8 7F0DDF98 25980002 */  addiu $t8, $t4, 2
/* 112ACC 7F0DDF9C 0018CA03 */  sra   $t9, $t8, 8
/* 112AD0 7F0DDFA0 010F4821 */  addu  $t1, $t0, $t7
/* 112AD4 7F0DDFA4 A1390001 */  sb    $t9, 1($t1)
/* 112AD8 7F0DDFA8 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 112ADC 7F0DDFAC 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 112AE0 7F0DDFB0 97AD0292 */  lhu   $t5, 0x292($sp)
/* 112AE4 7F0DDFB4 240B0001 */  li    $t3, 1
/* 112AE8 7F0DDFB8 014D7021 */  addu  $t6, $t2, $t5
/* 112AEC 7F0DDFBC 10000016 */  b     .L7F0DE018
/* 112AF0 7F0DDFC0 A1CBA801 */   sb    $t3, -0x57ff($t6)
.L7F0DDFC4:
/* 112AF4 7F0DDFC4 25980001 */  addiu $t8, $t4, 1
/* 112AF8 7F0DDFC8 2B014000 */  slti  $at, $t8, 0x4000
/* 112AFC 7F0DDFCC 14200012 */  bnez  $at, .L7F0DE018
/* 112B00 7F0DDFD0 97A80298 */   lhu   $t0, 0x298($sp)
/* 112B04 7F0DDFD4 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 112B08 7F0DDFD8 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 112B0C 7F0DDFDC 250F0002 */  addiu $t7, $t0, 2
/* 112B10 7F0DDFE0 000FCA03 */  sra   $t9, $t7, 8
/* 112B14 7F0DDFE4 012C5021 */  addu  $t2, $t1, $t4
/* 112B18 7F0DDFE8 A1590001 */  sb    $t9, 1($t2)
/* 112B1C 7F0DDFEC 97AB0292 */  lhu   $t3, 0x292($sp)
/* 112B20 7F0DDFF0 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 112B24 7F0DDFF4 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 112B28 7F0DDFF8 256E0001 */  addiu $t6, $t3, 1
/* 112B2C 7F0DDFFC 31D81800 */  andi  $t8, $t6, 0x1800
/* 112B30 7F0DE000 001840C3 */  sra   $t0, $t8, 3
/* 112B34 7F0DE004 31CF00FF */  andi  $t7, $t6, 0xff
/* 112B38 7F0DE008 010F4825 */  or    $t1, $t0, $t7
/* 112B3C 7F0DE00C 240D0001 */  li    $t5, 1
/* 112B40 7F0DE010 0189C821 */  addu  $t9, $t4, $t1
/* 112B44 7F0DE014 A32D0000 */  sb    $t5, ($t9)
.L7F0DE018:
/* 112B48 7F0DE018 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 112B4C 7F0DE01C 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 112B50 7F0DE020 97AA0298 */  lhu   $t2, 0x298($sp)
/* 112B54 7F0DE024 016A4021 */  addu  $t0, $t3, $t2
/* 112B58 7F0DE028 910F0001 */  lbu   $t7, 1($t0)
/* 112B5C 7F0DE02C 014BC021 */  addu  $t8, $t2, $t3
/* 112B60 7F0DE030 930E0000 */  lbu   $t6, ($t8)
/* 112B64 7F0DE034 000F6200 */  sll   $t4, $t7, 8
/* 112B68 7F0DE038 01CC4825 */  or    $t1, $t6, $t4
/* 112B6C 7F0DE03C 100011EF */  b     .L7F0E27FC
/* 112B70 7F0DE040 A7A90298 */   sh    $t1, 0x298($sp)
.L7F0DE044:
/* 112B74 7F0DE044 97AD0298 */  lhu   $t5, 0x298($sp)
/* 112B78 7F0DE048 25B90002 */  addiu $t9, $t5, 2
/* 112B7C 7F0DE04C 100011EB */  b     .L7F0E27FC
/* 112B80 7F0DE050 A7B90298 */   sh    $t9, 0x298($sp)
spectrum_op_E5:
/* 112B84 7F0DE054 8FB8028C */  lw    $t8, 0x28c($sp)
/* 112B88 7F0DE058 93AA0287 */  lbu   $t2, 0x287($sp)
/* 112B8C 7F0DE05C 93AF0287 */  lbu   $t7, 0x287($sp)
/* 112B90 7F0DE060 270B000B */  addiu $t3, $t8, 0xb
/* 112B94 7F0DE064 15400058 */  bnez  $t2, .L7F0DE1C8
/* 112B98 7F0DE068 AFAB028C */   sw    $t3, 0x28c($sp)
/* 112B9C 7F0DE06C 97A80292 */  lhu   $t0, 0x292($sp)
/* 112BA0 7F0DE070 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 112BA4 7F0DE074 250FFFFE */  addiu $t7, $t0, -2
/* 112BA8 7F0DE078 31EEFFFF */  andi  $t6, $t7, 0xffff
/* 112BAC 7F0DE07C 29C15B00 */  slti  $at, $t6, 0x5b00
/* 112BB0 7F0DE080 14200005 */  bnez  $at, .L7F0DE098
/* 112BB4 7F0DE084 A7AF0292 */   sh    $t7, 0x292($sp)
/* 112BB8 7F0DE088 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 112BBC 7F0DE08C 018E4821 */  addu  $t1, $t4, $t6
/* 112BC0 7F0DE090 10000021 */  b     .L7F0DE118
/* 112BC4 7F0DE094 A1370000 */   sb    $s7, ($t1)
.L7F0DE098:
/* 112BC8 7F0DE098 97AD0292 */  lhu   $t5, 0x292($sp)
/* 112BCC 7F0DE09C 97AC0292 */  lhu   $t4, 0x292($sp)
/* 112BD0 7F0DE0A0 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 112BD4 7F0DE0A4 29A15800 */  slti  $at, $t5, 0x5800
/* 112BD8 7F0DE0A8 5420000C */  bnezl $at, .L7F0DE0DC
/* 112BDC 7F0DE0AC 29814000 */   slti  $at, $t4, 0x4000
/* 112BE0 7F0DE0B0 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 112BE4 7F0DE0B4 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 112BE8 7F0DE0B8 240B0001 */  li    $t3, 1
/* 112BEC 7F0DE0BC 032DC021 */  addu  $t8, $t9, $t5
/* 112BF0 7F0DE0C0 A3170000 */  sb    $s7, ($t8)
/* 112BF4 7F0DE0C4 97A80292 */  lhu   $t0, 0x292($sp)
/* 112BF8 7F0DE0C8 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 112BFC 7F0DE0CC 01487821 */  addu  $t7, $t2, $t0
/* 112C00 7F0DE0D0 10000011 */  b     .L7F0DE118
/* 112C04 7F0DE0D4 A1EBA800 */   sb    $t3, -0x5800($t7)
/* 112C08 7F0DE0D8 29814000 */  slti  $at, $t4, 0x4000
.L7F0DE0DC:
/* 112C0C 7F0DE0DC 1420000E */  bnez  $at, .L7F0DE118
/* 112C10 7F0DE0E0 3C0E8009 */   lui   $t6, %hi(ptr_spectrum_roms) 
/* 112C14 7F0DE0E4 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 112C18 7F0DE0E8 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 112C1C 7F0DE0EC 24190001 */  li    $t9, 1
/* 112C20 7F0DE0F0 01CC4821 */  addu  $t1, $t6, $t4
/* 112C24 7F0DE0F4 A1370000 */  sb    $s7, ($t1)
/* 112C28 7F0DE0F8 97AD0292 */  lhu   $t5, 0x292($sp)
/* 112C2C 7F0DE0FC 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 112C30 7F0DE100 31B81800 */  andi  $t8, $t5, 0x1800
/* 112C34 7F0DE104 001850C3 */  sra   $t2, $t8, 3
/* 112C38 7F0DE108 31A800FF */  andi  $t0, $t5, 0xff
/* 112C3C 7F0DE10C 01485825 */  or    $t3, $t2, $t0
/* 112C40 7F0DE110 01EB7021 */  addu  $t6, $t7, $t3
/* 112C44 7F0DE114 A1D90000 */  sb    $t9, ($t6)
.L7F0DE118:
/* 112C48 7F0DE118 97AC0292 */  lhu   $t4, 0x292($sp)
/* 112C4C 7F0DE11C 97AA0292 */  lhu   $t2, 0x292($sp)
/* 112C50 7F0DE120 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 112C54 7F0DE124 25890001 */  addiu $t1, $t4, 1
/* 112C58 7F0DE128 29215B00 */  slti  $at, $t1, 0x5b00
/* 112C5C 7F0DE12C 14200005 */  bnez  $at, .L7F0DE144
/* 112C60 7F0DE130 25480001 */   addiu $t0, $t2, 1
/* 112C64 7F0DE134 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 112C68 7F0DE138 030C6821 */  addu  $t5, $t8, $t4
/* 112C6C 7F0DE13C 100011AF */  b     .L7F0E27FC
/* 112C70 7F0DE140 A1B60001 */   sb    $s6, 1($t5)
.L7F0DE144:
/* 112C74 7F0DE144 29015800 */  slti  $at, $t0, 0x5800
/* 112C78 7F0DE148 1420000C */  bnez  $at, .L7F0DE17C
/* 112C7C 7F0DE14C 97AC0292 */   lhu   $t4, 0x292($sp)
/* 112C80 7F0DE150 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 112C84 7F0DE154 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 112C88 7F0DE158 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 112C8C 7F0DE15C 24190001 */  li    $t9, 1
/* 112C90 7F0DE160 01EA5821 */  addu  $t3, $t7, $t2
/* 112C94 7F0DE164 A1760001 */  sb    $s6, 1($t3)
/* 112C98 7F0DE168 97A90292 */  lhu   $t1, 0x292($sp)
/* 112C9C 7F0DE16C 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 112CA0 7F0DE170 01C9C021 */  addu  $t8, $t6, $t1
/* 112CA4 7F0DE174 100011A1 */  b     .L7F0E27FC
/* 112CA8 7F0DE178 A319A801 */   sb    $t9, -0x57ff($t8)
.L7F0DE17C:
/* 112CAC 7F0DE17C 258D0001 */  addiu $t5, $t4, 1
/* 112CB0 7F0DE180 29A14000 */  slti  $at, $t5, 0x4000
/* 112CB4 7F0DE184 1420119D */  bnez  $at, .L7F0E27FC
/* 112CB8 7F0DE188 3C088009 */   lui   $t0, %hi(ptr_spectrum_roms) 
/* 112CBC 7F0DE18C 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 112CC0 7F0DE190 240A0001 */  li    $t2, 1
/* 112CC4 7F0DE194 010C7821 */  addu  $t7, $t0, $t4
/* 112CC8 7F0DE198 A1F60001 */  sb    $s6, 1($t7)
/* 112CCC 7F0DE19C 97AB0292 */  lhu   $t3, 0x292($sp)
/* 112CD0 7F0DE1A0 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 112CD4 7F0DE1A4 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 112CD8 7F0DE1A8 256E0001 */  addiu $t6, $t3, 1
/* 112CDC 7F0DE1AC 31C91800 */  andi  $t1, $t6, 0x1800
/* 112CE0 7F0DE1B0 0009C8C3 */  sra   $t9, $t1, 3
/* 112CE4 7F0DE1B4 31D800FF */  andi  $t8, $t6, 0xff
/* 112CE8 7F0DE1B8 03386825 */  or    $t5, $t9, $t8
/* 112CEC 7F0DE1BC 010D6021 */  addu  $t4, $t0, $t5
/* 112CF0 7F0DE1C0 1000118E */  b     .L7F0E27FC
/* 112CF4 7F0DE1C4 A18A0000 */   sb    $t2, ($t4)
.L7F0DE1C8:
/* 112CF8 7F0DE1C8 24010001 */  li    $at, 1
/* 112CFC 7F0DE1CC 15E10061 */  bne   $t7, $at, .L7F0DE354
/* 112D00 7F0DE1D0 97A90292 */   lhu   $t1, 0x292($sp)
/* 112D04 7F0DE1D4 97AB0292 */  lhu   $t3, 0x292($sp)
/* 112D08 7F0DE1D8 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 112D0C 7F0DE1DC 2569FFFE */  addiu $t1, $t3, -2
/* 112D10 7F0DE1E0 312EFFFF */  andi  $t6, $t1, 0xffff
/* 112D14 7F0DE1E4 29C15B00 */  slti  $at, $t6, 0x5b00
/* 112D18 7F0DE1E8 14200006 */  bnez  $at, .L7F0DE204
/* 112D1C 7F0DE1EC A7A90292 */   sh    $t1, 0x292($sp)
/* 112D20 7F0DE1F0 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 112D24 7F0DE1F4 97B90296 */  lhu   $t9, 0x296($sp)
/* 112D28 7F0DE1F8 030E4021 */  addu  $t0, $t8, $t6
/* 112D2C 7F0DE1FC 10000023 */  b     .L7F0DE28C
/* 112D30 7F0DE200 A1190000 */   sb    $t9, ($t0)
.L7F0DE204:
/* 112D34 7F0DE204 97AD0292 */  lhu   $t5, 0x292($sp)
/* 112D38 7F0DE208 97B90292 */  lhu   $t9, 0x292($sp)
/* 112D3C 7F0DE20C 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 112D40 7F0DE210 29A15800 */  slti  $at, $t5, 0x5800
/* 112D44 7F0DE214 5420000D */  bnezl $at, .L7F0DE24C
/* 112D48 7F0DE218 2B214000 */   slti  $at, $t9, 0x4000
/* 112D4C 7F0DE21C 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 112D50 7F0DE220 97AA0296 */  lhu   $t2, 0x296($sp)
/* 112D54 7F0DE224 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 112D58 7F0DE228 018D7821 */  addu  $t7, $t4, $t5
/* 112D5C 7F0DE22C A1EA0000 */  sb    $t2, ($t7)
/* 112D60 7F0DE230 97B80292 */  lhu   $t8, 0x292($sp)
/* 112D64 7F0DE234 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 112D68 7F0DE238 240B0001 */  li    $t3, 1
/* 112D6C 7F0DE23C 01387021 */  addu  $t6, $t1, $t8
/* 112D70 7F0DE240 10000012 */  b     .L7F0DE28C
/* 112D74 7F0DE244 A1CBA800 */   sb    $t3, -0x5800($t6)
/* 112D78 7F0DE248 2B214000 */  slti  $at, $t9, 0x4000
.L7F0DE24C:
/* 112D7C 7F0DE24C 1420000F */  bnez  $at, .L7F0DE28C
/* 112D80 7F0DE250 3C0C8009 */   lui   $t4, %hi(ptr_spectrum_roms) 
/* 112D84 7F0DE254 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 112D88 7F0DE258 97A80296 */  lhu   $t0, 0x296($sp)
/* 112D8C 7F0DE25C 240A0001 */  li    $t2, 1
/* 112D90 7F0DE260 01996821 */  addu  $t5, $t4, $t9
/* 112D94 7F0DE264 A1A80000 */  sb    $t0, ($t5)
/* 112D98 7F0DE268 97AF0292 */  lhu   $t7, 0x292($sp)
/* 112D9C 7F0DE26C 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 112DA0 7F0DE270 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 112DA4 7F0DE274 31E91800 */  andi  $t1, $t7, 0x1800
/* 112DA8 7F0DE278 0009C0C3 */  sra   $t8, $t1, 3
/* 112DAC 7F0DE27C 31EB00FF */  andi  $t3, $t7, 0xff
/* 112DB0 7F0DE280 030B7025 */  or    $t6, $t8, $t3
/* 112DB4 7F0DE284 018EC821 */  addu  $t9, $t4, $t6
/* 112DB8 7F0DE288 A32A0000 */  sb    $t2, ($t9)
.L7F0DE28C:
/* 112DBC 7F0DE28C 97A80292 */  lhu   $t0, 0x292($sp)
/* 112DC0 7F0DE290 97AC0292 */  lhu   $t4, 0x292($sp)
/* 112DC4 7F0DE294 97A90296 */  lhu   $t1, 0x296($sp)
/* 112DC8 7F0DE298 250D0001 */  addiu $t5, $t0, 1
/* 112DCC 7F0DE29C 29A15B00 */  slti  $at, $t5, 0x5b00
/* 112DD0 7F0DE2A0 14200007 */  bnez  $at, .L7F0DE2C0
/* 112DD4 7F0DE2A4 258E0001 */   addiu $t6, $t4, 1
/* 112DD8 7F0DE2A8 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 112DDC 7F0DE2AC 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 112DE0 7F0DE2B0 00097A03 */  sra   $t7, $t1, 8
/* 112DE4 7F0DE2B4 03085821 */  addu  $t3, $t8, $t0
/* 112DE8 7F0DE2B8 10001150 */  b     .L7F0E27FC
/* 112DEC 7F0DE2BC A16F0001 */   sb    $t7, 1($t3)
.L7F0DE2C0:
/* 112DF0 7F0DE2C0 29C15800 */  slti  $at, $t6, 0x5800
/* 112DF4 7F0DE2C4 1420000E */  bnez  $at, .L7F0DE300
/* 112DF8 7F0DE2C8 97AE0292 */   lhu   $t6, 0x292($sp)
/* 112DFC 7F0DE2CC 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 112E00 7F0DE2D0 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 112E04 7F0DE2D4 97AA0296 */  lhu   $t2, 0x296($sp)
/* 112E08 7F0DE2D8 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 112E0C 7F0DE2DC 01AC4821 */  addu  $t1, $t5, $t4
/* 112E10 7F0DE2E0 000ACA03 */  sra   $t9, $t2, 8
/* 112E14 7F0DE2E4 A1390001 */  sb    $t9, 1($t1)
/* 112E18 7F0DE2E8 97AF0292 */  lhu   $t7, 0x292($sp)
/* 112E1C 7F0DE2EC 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 112E20 7F0DE2F0 24180001 */  li    $t8, 1
/* 112E24 7F0DE2F4 010F5821 */  addu  $t3, $t0, $t7
/* 112E28 7F0DE2F8 10001140 */  b     .L7F0E27FC
/* 112E2C 7F0DE2FC A178A801 */   sb    $t8, -0x57ff($t3)
.L7F0DE300:
/* 112E30 7F0DE300 25CA0001 */  addiu $t2, $t6, 1
/* 112E34 7F0DE304 29414000 */  slti  $at, $t2, 0x4000
/* 112E38 7F0DE308 1420113C */  bnez  $at, .L7F0E27FC
/* 112E3C 7F0DE30C 97AD0296 */   lhu   $t5, 0x296($sp)
/* 112E40 7F0DE310 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 112E44 7F0DE314 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 112E48 7F0DE318 000D6203 */  sra   $t4, $t5, 8
/* 112E4C 7F0DE31C 24080001 */  li    $t0, 1
/* 112E50 7F0DE320 032E4821 */  addu  $t1, $t9, $t6
/* 112E54 7F0DE324 A12C0001 */  sb    $t4, 1($t1)
/* 112E58 7F0DE328 97AF0292 */  lhu   $t7, 0x292($sp)
/* 112E5C 7F0DE32C 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 112E60 7F0DE330 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 112E64 7F0DE334 25F80001 */  addiu $t8, $t7, 1
/* 112E68 7F0DE338 330B1800 */  andi  $t3, $t8, 0x1800
/* 112E6C 7F0DE33C 000B50C3 */  sra   $t2, $t3, 3
/* 112E70 7F0DE340 330D00FF */  andi  $t5, $t8, 0xff
/* 112E74 7F0DE344 014DC825 */  or    $t9, $t2, $t5
/* 112E78 7F0DE348 01D96021 */  addu  $t4, $t6, $t9
/* 112E7C 7F0DE34C 1000112B */  b     .L7F0E27FC
/* 112E80 7F0DE350 A1880000 */   sb    $t0, ($t4)
.L7F0DE354:
/* 112E84 7F0DE354 252FFFFE */  addiu $t7, $t1, -2
/* 112E88 7F0DE358 31EBFFFF */  andi  $t3, $t7, 0xffff
/* 112E8C 7F0DE35C 29615B00 */  slti  $at, $t3, 0x5b00
/* 112E90 7F0DE360 14200007 */  bnez  $at, .L7F0DE380
/* 112E94 7F0DE364 A7AF0292 */   sh    $t7, 0x292($sp)
/* 112E98 7F0DE368 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 112E9C 7F0DE36C 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 112EA0 7F0DE370 97B80294 */  lhu   $t8, 0x294($sp)
/* 112EA4 7F0DE374 014B6821 */  addu  $t5, $t2, $t3
/* 112EA8 7F0DE378 10000023 */  b     .L7F0DE408
/* 112EAC 7F0DE37C A1B80000 */   sb    $t8, ($t5)
.L7F0DE380:
/* 112EB0 7F0DE380 97AE0292 */  lhu   $t6, 0x292($sp)
/* 112EB4 7F0DE384 97B80292 */  lhu   $t8, 0x292($sp)
/* 112EB8 7F0DE388 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 112EBC 7F0DE38C 29C15800 */  slti  $at, $t6, 0x5800
/* 112EC0 7F0DE390 5420000D */  bnezl $at, .L7F0DE3C8
/* 112EC4 7F0DE394 2B014000 */   slti  $at, $t8, 0x4000
/* 112EC8 7F0DE398 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 112ECC 7F0DE39C 97B90294 */  lhu   $t9, 0x294($sp)
/* 112ED0 7F0DE3A0 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 112ED4 7F0DE3A4 010E6021 */  addu  $t4, $t0, $t6
/* 112ED8 7F0DE3A8 A1990000 */  sb    $t9, ($t4)
/* 112EDC 7F0DE3AC 97AA0292 */  lhu   $t2, 0x292($sp)
/* 112EE0 7F0DE3B0 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 112EE4 7F0DE3B4 24090001 */  li    $t1, 1
/* 112EE8 7F0DE3B8 01EA5821 */  addu  $t3, $t7, $t2
/* 112EEC 7F0DE3BC 10000012 */  b     .L7F0DE408
/* 112EF0 7F0DE3C0 A169A800 */   sb    $t1, -0x5800($t3)
/* 112EF4 7F0DE3C4 2B014000 */  slti  $at, $t8, 0x4000
.L7F0DE3C8:
/* 112EF8 7F0DE3C8 1420000F */  bnez  $at, .L7F0DE408
/* 112EFC 7F0DE3CC 3C088009 */   lui   $t0, %hi(ptr_spectrum_roms) 
/* 112F00 7F0DE3D0 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 112F04 7F0DE3D4 97AD0294 */  lhu   $t5, 0x294($sp)
/* 112F08 7F0DE3D8 24190001 */  li    $t9, 1
/* 112F0C 7F0DE3DC 01187021 */  addu  $t6, $t0, $t8
/* 112F10 7F0DE3E0 A1CD0000 */  sb    $t5, ($t6)
/* 112F14 7F0DE3E4 97AC0292 */  lhu   $t4, 0x292($sp)
/* 112F18 7F0DE3E8 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 112F1C 7F0DE3EC 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 112F20 7F0DE3F0 318F1800 */  andi  $t7, $t4, 0x1800
/* 112F24 7F0DE3F4 000F50C3 */  sra   $t2, $t7, 3
/* 112F28 7F0DE3F8 318900FF */  andi  $t1, $t4, 0xff
/* 112F2C 7F0DE3FC 01495825 */  or    $t3, $t2, $t1
/* 112F30 7F0DE400 010BC021 */  addu  $t8, $t0, $t3
/* 112F34 7F0DE404 A3190000 */  sb    $t9, ($t8)
.L7F0DE408:
/* 112F38 7F0DE408 97AD0292 */  lhu   $t5, 0x292($sp)
/* 112F3C 7F0DE40C 97A80292 */  lhu   $t0, 0x292($sp)
/* 112F40 7F0DE410 97AF0294 */  lhu   $t7, 0x294($sp)
/* 112F44 7F0DE414 25AE0001 */  addiu $t6, $t5, 1
/* 112F48 7F0DE418 29C15B00 */  slti  $at, $t6, 0x5b00
/* 112F4C 7F0DE41C 14200007 */  bnez  $at, .L7F0DE43C
/* 112F50 7F0DE420 250B0001 */   addiu $t3, $t0, 1
/* 112F54 7F0DE424 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 112F58 7F0DE428 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 112F5C 7F0DE42C 000F6203 */  sra   $t4, $t7, 8
/* 112F60 7F0DE430 014D4821 */  addu  $t1, $t2, $t5
/* 112F64 7F0DE434 100010F1 */  b     .L7F0E27FC
/* 112F68 7F0DE438 A12C0001 */   sb    $t4, 1($t1)
.L7F0DE43C:
/* 112F6C 7F0DE43C 29615800 */  slti  $at, $t3, 0x5800
/* 112F70 7F0DE440 1420000E */  bnez  $at, .L7F0DE47C
/* 112F74 7F0DE444 97AB0292 */   lhu   $t3, 0x292($sp)
/* 112F78 7F0DE448 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 112F7C 7F0DE44C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 112F80 7F0DE450 97B90294 */  lhu   $t9, 0x294($sp)
/* 112F84 7F0DE454 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 112F88 7F0DE458 01C87821 */  addu  $t7, $t6, $t0
/* 112F8C 7F0DE45C 0019C203 */  sra   $t8, $t9, 8
/* 112F90 7F0DE460 A1F80001 */  sb    $t8, 1($t7)
/* 112F94 7F0DE464 97AC0292 */  lhu   $t4, 0x292($sp)
/* 112F98 7F0DE468 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 112F9C 7F0DE46C 240A0001 */  li    $t2, 1
/* 112FA0 7F0DE470 01AC4821 */  addu  $t1, $t5, $t4
/* 112FA4 7F0DE474 100010E1 */  b     .L7F0E27FC
/* 112FA8 7F0DE478 A12AA801 */   sb    $t2, -0x57ff($t1)
.L7F0DE47C:
/* 112FAC 7F0DE47C 25790001 */  addiu $t9, $t3, 1
/* 112FB0 7F0DE480 2B214000 */  slti  $at, $t9, 0x4000
/* 112FB4 7F0DE484 142010DD */  bnez  $at, .L7F0E27FC
/* 112FB8 7F0DE488 97AE0294 */   lhu   $t6, 0x294($sp)
/* 112FBC 7F0DE48C 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 112FC0 7F0DE490 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 112FC4 7F0DE494 000E4203 */  sra   $t0, $t6, 8
/* 112FC8 7F0DE498 240D0001 */  li    $t5, 1
/* 112FCC 7F0DE49C 030B7821 */  addu  $t7, $t8, $t3
/* 112FD0 7F0DE4A0 A1E80001 */  sb    $t0, 1($t7)
/* 112FD4 7F0DE4A4 97AC0292 */  lhu   $t4, 0x292($sp)
/* 112FD8 7F0DE4A8 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 112FDC 7F0DE4AC 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 112FE0 7F0DE4B0 258A0001 */  addiu $t2, $t4, 1
/* 112FE4 7F0DE4B4 31491800 */  andi  $t1, $t2, 0x1800
/* 112FE8 7F0DE4B8 0009C8C3 */  sra   $t9, $t1, 3
/* 112FEC 7F0DE4BC 314E00FF */  andi  $t6, $t2, 0xff
/* 112FF0 7F0DE4C0 032EC025 */  or    $t8, $t9, $t6
/* 112FF4 7F0DE4C4 01784021 */  addu  $t0, $t3, $t8
/* 112FF8 7F0DE4C8 100010CC */  b     .L7F0E27FC
/* 112FFC 7F0DE4CC A10D0000 */   sb    $t5, ($t0)
spectrum_op_E6:
/* 113000 7F0DE4D0 8FAF028C */  lw    $t7, 0x28c($sp)
/* 113004 7F0DE4D4 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 113008 7F0DE4D8 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 11300C 7F0DE4DC 97AA0298 */  lhu   $t2, 0x298($sp)
/* 113010 7F0DE4E0 25EC0007 */  addiu $t4, $t7, 7
/* 113014 7F0DE4E4 AFAC028C */  sw    $t4, 0x28c($sp)
/* 113018 7F0DE4E8 012AC821 */  addu  $t9, $t1, $t2
/* 11301C 7F0DE4EC 932E0000 */  lbu   $t6, ($t9)
/* 113020 7F0DE4F0 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 113024 7F0DE4F4 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 113028 7F0DE4F8 020E8024 */  and   $s0, $s0, $t6
/* 11302C 7F0DE4FC 320B00FF */  andi  $t3, $s0, 0xff
/* 113030 7F0DE500 2D780001 */  sltiu $t8, $t3, 1
/* 113034 7F0DE504 AFB80048 */  sw    $t8, 0x48($sp)
/* 113038 7F0DE508 00187980 */  sll   $t7, $t8, 6
/* 11303C 7F0DE50C 016AC821 */  addu  $t9, $t3, $t2
/* 113040 7F0DE510 932E0000 */  lbu   $t6, ($t9)
/* 113044 7F0DE514 316D00A8 */  andi  $t5, $t3, 0xa8
/* 113048 7F0DE518 97B80298 */  lhu   $t8, 0x298($sp)
/* 11304C 7F0DE51C 01AF6025 */  or    $t4, $t5, $t7
/* 113050 7F0DE520 35890010 */  ori   $t1, $t4, 0x10
/* 113054 7F0DE524 01608025 */  move  $s0, $t3
/* 113058 7F0DE528 01C98825 */  or    $s1, $t6, $t1
/* 11305C 7F0DE52C 322B00FF */  andi  $t3, $s1, 0xff
/* 113060 7F0DE530 27080001 */  addiu $t0, $t8, 1
/* 113064 7F0DE534 01608825 */  move  $s1, $t3
/* 113068 7F0DE538 100010B0 */  b     .L7F0E27FC
/* 11306C 7F0DE53C A7A80298 */   sh    $t0, 0x298($sp)
spectrum_op_E7:
/* 113070 7F0DE540 97AC0292 */  lhu   $t4, 0x292($sp)
/* 113074 7F0DE544 8FAD028C */  lw    $t5, 0x28c($sp)
/* 113078 7F0DE548 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 11307C 7F0DE54C 258AFFFE */  addiu $t2, $t4, -2
/* 113080 7F0DE550 3159FFFF */  andi  $t9, $t2, 0xffff
/* 113084 7F0DE554 2B215B00 */  slti  $at, $t9, 0x5b00
/* 113088 7F0DE558 25AF000B */  addiu $t7, $t5, 0xb
/* 11308C 7F0DE55C AFAF028C */  sw    $t7, 0x28c($sp)
/* 113090 7F0DE560 14200006 */  bnez  $at, .L7F0DE57C
/* 113094 7F0DE564 A7AA0292 */   sh    $t2, 0x292($sp)
/* 113098 7F0DE568 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 11309C 7F0DE56C 97AE0298 */  lhu   $t6, 0x298($sp)
/* 1130A0 7F0DE570 01395821 */  addu  $t3, $t1, $t9
/* 1130A4 7F0DE574 10000023 */  b     .L7F0DE604
/* 1130A8 7F0DE578 A16E0000 */   sb    $t6, ($t3)
.L7F0DE57C:
/* 1130AC 7F0DE57C 97B80292 */  lhu   $t8, 0x292($sp)
/* 1130B0 7F0DE580 97AE0292 */  lhu   $t6, 0x292($sp)
/* 1130B4 7F0DE584 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 1130B8 7F0DE588 2B015800 */  slti  $at, $t8, 0x5800
/* 1130BC 7F0DE58C 5420000D */  bnezl $at, .L7F0DE5C4
/* 1130C0 7F0DE590 29C14000 */   slti  $at, $t6, 0x4000
/* 1130C4 7F0DE594 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 1130C8 7F0DE598 97A80298 */  lhu   $t0, 0x298($sp)
/* 1130CC 7F0DE59C 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 1130D0 7F0DE5A0 01B87821 */  addu  $t7, $t5, $t8
/* 1130D4 7F0DE5A4 A1E80000 */  sb    $t0, ($t7)
/* 1130D8 7F0DE5A8 97A90292 */  lhu   $t1, 0x292($sp)
/* 1130DC 7F0DE5AC 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 1130E0 7F0DE5B0 240C0001 */  li    $t4, 1
/* 1130E4 7F0DE5B4 0149C821 */  addu  $t9, $t2, $t1
/* 1130E8 7F0DE5B8 10000012 */  b     .L7F0DE604
/* 1130EC 7F0DE5BC A32CA800 */   sb    $t4, -0x5800($t9)
/* 1130F0 7F0DE5C0 29C14000 */  slti  $at, $t6, 0x4000
.L7F0DE5C4:
/* 1130F4 7F0DE5C4 1420000F */  bnez  $at, .L7F0DE604
/* 1130F8 7F0DE5C8 3C0D8009 */   lui   $t5, %hi(ptr_spectrum_roms) 
/* 1130FC 7F0DE5CC 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 113100 7F0DE5D0 97AB0298 */  lhu   $t3, 0x298($sp)
/* 113104 7F0DE5D4 24080001 */  li    $t0, 1
/* 113108 7F0DE5D8 01AEC021 */  addu  $t8, $t5, $t6
/* 11310C 7F0DE5DC A30B0000 */  sb    $t3, ($t8)
/* 113110 7F0DE5E0 97AF0292 */  lhu   $t7, 0x292($sp)
/* 113114 7F0DE5E4 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 113118 7F0DE5E8 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 11311C 7F0DE5EC 31EA1800 */  andi  $t2, $t7, 0x1800
/* 113120 7F0DE5F0 000A48C3 */  sra   $t1, $t2, 3
/* 113124 7F0DE5F4 31EC00FF */  andi  $t4, $t7, 0xff
/* 113128 7F0DE5F8 012CC825 */  or    $t9, $t1, $t4
/* 11312C 7F0DE5FC 01B97021 */  addu  $t6, $t5, $t9
/* 113130 7F0DE600 A1C80000 */  sb    $t0, ($t6)
.L7F0DE604:
/* 113134 7F0DE604 97AB0292 */  lhu   $t3, 0x292($sp)
/* 113138 7F0DE608 97AD0292 */  lhu   $t5, 0x292($sp)
/* 11313C 7F0DE60C 97AA0298 */  lhu   $t2, 0x298($sp)
/* 113140 7F0DE610 25780001 */  addiu $t8, $t3, 1
/* 113144 7F0DE614 2B015B00 */  slti  $at, $t8, 0x5b00
/* 113148 7F0DE618 14200007 */  bnez  $at, .L7F0DE638
/* 11314C 7F0DE61C 25B90001 */   addiu $t9, $t5, 1
/* 113150 7F0DE620 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 113154 7F0DE624 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 113158 7F0DE628 000A7A03 */  sra   $t7, $t2, 8
/* 11315C 7F0DE62C 012B6021 */  addu  $t4, $t1, $t3
/* 113160 7F0DE630 10000025 */  b     .L7F0DE6C8
/* 113164 7F0DE634 A18F0001 */   sb    $t7, 1($t4)
.L7F0DE638:
/* 113168 7F0DE638 2B215800 */  slti  $at, $t9, 0x5800
/* 11316C 7F0DE63C 1420000E */  bnez  $at, .L7F0DE678
/* 113170 7F0DE640 97B90292 */   lhu   $t9, 0x292($sp)
/* 113174 7F0DE644 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 113178 7F0DE648 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 11317C 7F0DE64C 97A80298 */  lhu   $t0, 0x298($sp)
/* 113180 7F0DE650 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 113184 7F0DE654 030D5021 */  addu  $t2, $t8, $t5
/* 113188 7F0DE658 00087203 */  sra   $t6, $t0, 8
/* 11318C 7F0DE65C A14E0001 */  sb    $t6, 1($t2)
/* 113190 7F0DE660 97AF0292 */  lhu   $t7, 0x292($sp)
/* 113194 7F0DE664 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 113198 7F0DE668 24090001 */  li    $t1, 1
/* 11319C 7F0DE66C 016F6021 */  addu  $t4, $t3, $t7
/* 1131A0 7F0DE670 10000015 */  b     .L7F0DE6C8
/* 1131A4 7F0DE674 A189A801 */   sb    $t1, -0x57ff($t4)
.L7F0DE678:
/* 1131A8 7F0DE678 27280001 */  addiu $t0, $t9, 1
/* 1131AC 7F0DE67C 29014000 */  slti  $at, $t0, 0x4000
/* 1131B0 7F0DE680 14200011 */  bnez  $at, .L7F0DE6C8
/* 1131B4 7F0DE684 97B80298 */   lhu   $t8, 0x298($sp)
/* 1131B8 7F0DE688 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 1131BC 7F0DE68C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 1131C0 7F0DE690 00186A03 */  sra   $t5, $t8, 8
/* 1131C4 7F0DE694 240B0001 */  li    $t3, 1
/* 1131C8 7F0DE698 01D95021 */  addu  $t2, $t6, $t9
/* 1131CC 7F0DE69C A14D0001 */  sb    $t5, 1($t2)
/* 1131D0 7F0DE6A0 97AF0292 */  lhu   $t7, 0x292($sp)
/* 1131D4 7F0DE6A4 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 1131D8 7F0DE6A8 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 1131DC 7F0DE6AC 25E90001 */  addiu $t1, $t7, 1
/* 1131E0 7F0DE6B0 312C1800 */  andi  $t4, $t1, 0x1800
/* 1131E4 7F0DE6B4 000C40C3 */  sra   $t0, $t4, 3
/* 1131E8 7F0DE6B8 313800FF */  andi  $t8, $t1, 0xff
/* 1131EC 7F0DE6BC 01187025 */  or    $t6, $t0, $t8
/* 1131F0 7F0DE6C0 032E6821 */  addu  $t5, $t9, $t6
/* 1131F4 7F0DE6C4 A1AB0000 */  sb    $t3, ($t5)
.L7F0DE6C8:
/* 1131F8 7F0DE6C8 240A0020 */  li    $t2, 32
/* 1131FC 7F0DE6CC 1000104B */  b     .L7F0E27FC
/* 113200 7F0DE6D0 A7AA0298 */   sh    $t2, 0x298($sp)
spectrum_op_E8:
/* 113204 7F0DE6D4 8FAF028C */  lw    $t7, 0x28c($sp)
/* 113208 7F0DE6D8 32290004 */  andi  $t1, $s1, 4
/* 11320C 7F0DE6DC 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 113210 7F0DE6E0 25EC0005 */  addiu $t4, $t7, 5
/* 113214 7F0DE6E4 11201045 */  beqz  $t1, .L7F0E27FC
/* 113218 7F0DE6E8 AFAC028C */   sw    $t4, 0x28c($sp)
/* 11321C 7F0DE6EC 97B90292 */  lhu   $t9, 0x292($sp)
/* 113220 7F0DE6F0 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 113224 7F0DE6F4 25980006 */  addiu $t8, $t4, 6
/* 113228 7F0DE6F8 AFB8028C */  sw    $t8, 0x28c($sp)
/* 11322C 7F0DE6FC 01D95021 */  addu  $t2, $t6, $t9
/* 113230 7F0DE700 914F0001 */  lbu   $t7, 1($t2)
/* 113234 7F0DE704 032E5821 */  addu  $t3, $t9, $t6
/* 113238 7F0DE708 916D0000 */  lbu   $t5, ($t3)
/* 11323C 7F0DE70C 000F6200 */  sll   $t4, $t7, 8
/* 113240 7F0DE710 27280002 */  addiu $t0, $t9, 2
/* 113244 7F0DE714 01AC4825 */  or    $t1, $t5, $t4
/* 113248 7F0DE718 A7A90298 */  sh    $t1, 0x298($sp)
/* 11324C 7F0DE71C 10001037 */  b     .L7F0E27FC
/* 113250 7F0DE720 A7A80292 */   sh    $t0, 0x292($sp)
spectrum_op_E9:
/* 113254 7F0DE724 8FB8028C */  lw    $t8, 0x28c($sp)
/* 113258 7F0DE728 93AE0287 */  lbu   $t6, 0x287($sp)
/* 11325C 7F0DE72C 93AD0287 */  lbu   $t5, 0x287($sp)
/* 113260 7F0DE730 270B0004 */  addiu $t3, $t8, 4
/* 113264 7F0DE734 15C00005 */  bnez  $t6, .L7F0DE74C
/* 113268 7F0DE738 AFAB028C */   sw    $t3, 0x28c($sp)
/* 11326C 7F0DE73C 00165200 */  sll   $t2, $s6, 8
/* 113270 7F0DE740 01577825 */  or    $t7, $t2, $s7
/* 113274 7F0DE744 1000102D */  b     .L7F0E27FC
/* 113278 7F0DE748 A7AF0298 */   sh    $t7, 0x298($sp)
.L7F0DE74C:
/* 11327C 7F0DE74C 24010001 */  li    $at, 1
/* 113280 7F0DE750 15A10004 */  bne   $t5, $at, .L7F0DE764
/* 113284 7F0DE754 97A90294 */   lhu   $t1, 0x294($sp)
/* 113288 7F0DE758 97AC0296 */  lhu   $t4, 0x296($sp)
/* 11328C 7F0DE75C 10000002 */  b     .L7F0DE768
/* 113290 7F0DE760 AFAC0048 */   sw    $t4, 0x48($sp)
.L7F0DE764:
/* 113294 7F0DE764 AFA90048 */  sw    $t1, 0x48($sp)
.L7F0DE768:
/* 113298 7F0DE768 8FB90048 */  lw    $t9, 0x48($sp)
/* 11329C 7F0DE76C 10001023 */  b     .L7F0E27FC
/* 1132A0 7F0DE770 A7B90298 */   sh    $t9, 0x298($sp)
spectrum_op_EA:
/* 1132A4 7F0DE774 8FA8028C */  lw    $t0, 0x28c($sp)
/* 1132A8 7F0DE778 322B0004 */  andi  $t3, $s1, 4
/* 1132AC 7F0DE77C 97AE0298 */  lhu   $t6, 0x298($sp)
/* 1132B0 7F0DE780 2518000A */  addiu $t8, $t0, 0xa
/* 1132B4 7F0DE784 1160000B */  beqz  $t3, .L7F0DE7B4
/* 1132B8 7F0DE788 AFB8028C */   sw    $t8, 0x28c($sp)
/* 1132BC 7F0DE78C 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 1132C0 7F0DE790 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 1132C4 7F0DE794 014E6021 */  addu  $t4, $t2, $t6
/* 1132C8 7F0DE798 91890001 */  lbu   $t1, 1($t4)
/* 1132CC 7F0DE79C 01CA7821 */  addu  $t7, $t6, $t2
/* 1132D0 7F0DE7A0 91ED0000 */  lbu   $t5, ($t7)
/* 1132D4 7F0DE7A4 0009CA00 */  sll   $t9, $t1, 8
/* 1132D8 7F0DE7A8 01B94025 */  or    $t0, $t5, $t9
/* 1132DC 7F0DE7AC 10001013 */  b     .L7F0E27FC
/* 1132E0 7F0DE7B0 A7A80298 */   sh    $t0, 0x298($sp)
.L7F0DE7B4:
/* 1132E4 7F0DE7B4 97B80298 */  lhu   $t8, 0x298($sp)
/* 1132E8 7F0DE7B8 270B0002 */  addiu $t3, $t8, 2
/* 1132EC 7F0DE7BC 1000100F */  b     .L7F0E27FC
/* 1132F0 7F0DE7C0 A7AB0298 */   sh    $t3, 0x298($sp)
spectrum_op_EB:
/* 1132F4 7F0DE7C4 8FAF028C */  lw    $t7, 0x28c($sp)
/* 1132F8 7F0DE7C8 A3B600E5 */  sb    $s6, 0xe5($sp)
/* 1132FC 7F0DE7CC A3B500E4 */  sb    $s5, 0xe4($sp)
/* 113300 7F0DE7D0 329600FF */  andi  $s6, $s4, 0xff
/* 113304 7F0DE7D4 32F500FF */  andi  $s5, $s7, 0xff
/* 113308 7F0DE7D8 25EA0004 */  addiu $t2, $t7, 4
/* 11330C 7F0DE7DC AFAA028C */  sw    $t2, 0x28c($sp)
/* 113310 7F0DE7E0 93B400E5 */  lbu   $s4, 0xe5($sp)
/* 113314 7F0DE7E4 10001005 */  b     .L7F0E27FC
/* 113318 7F0DE7E8 93B700E4 */   lbu   $s7, 0xe4($sp)
spectrum_op_EC:
/* 11331C 7F0DE7EC 8FAE028C */  lw    $t6, 0x28c($sp)
/* 113320 7F0DE7F0 32290004 */  andi  $t1, $s1, 4
/* 113324 7F0DE7F4 25CC000A */  addiu $t4, $t6, 0xa
/* 113328 7F0DE7F8 11200072 */  beqz  $t1, .L7F0DE9C4
/* 11332C 7F0DE7FC AFAC028C */   sw    $t4, 0x28c($sp)
/* 113330 7F0DE800 97A80292 */  lhu   $t0, 0x292($sp)
/* 113334 7F0DE804 25990007 */  addiu $t9, $t4, 7
/* 113338 7F0DE808 AFB9028C */  sw    $t9, 0x28c($sp)
/* 11333C 7F0DE80C 2518FFFE */  addiu $t8, $t0, -2
/* 113340 7F0DE810 330BFFFF */  andi  $t3, $t8, 0xffff
/* 113344 7F0DE814 29615B00 */  slti  $at, $t3, 0x5b00
/* 113348 7F0DE818 14200008 */  bnez  $at, .L7F0DE83C
/* 11334C 7F0DE81C A7B80292 */   sh    $t8, 0x292($sp)
/* 113350 7F0DE820 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 113354 7F0DE824 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 113358 7F0DE828 97AF0298 */  lhu   $t7, 0x298($sp)
/* 11335C 7F0DE82C 01CB6021 */  addu  $t4, $t6, $t3
/* 113360 7F0DE830 25EA0002 */  addiu $t2, $t7, 2
/* 113364 7F0DE834 10000024 */  b     .L7F0DE8C8
/* 113368 7F0DE838 A18A0000 */   sb    $t2, ($t4)
.L7F0DE83C:
/* 11336C 7F0DE83C 97A90292 */  lhu   $t1, 0x292($sp)
/* 113370 7F0DE840 97AC0292 */  lhu   $t4, 0x292($sp)
/* 113374 7F0DE844 97AD0298 */  lhu   $t5, 0x298($sp)
/* 113378 7F0DE848 29215800 */  slti  $at, $t1, 0x5800
/* 11337C 7F0DE84C 1420000C */  bnez  $at, .L7F0DE880
/* 113380 7F0DE850 3C088009 */   lui   $t0, %hi(ptr_spectrum_roms) 
/* 113384 7F0DE854 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 113388 7F0DE858 25B90002 */  addiu $t9, $t5, 2
/* 11338C 7F0DE85C 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 113390 7F0DE860 0109C021 */  addu  $t8, $t0, $t1
/* 113394 7F0DE864 A3190000 */  sb    $t9, ($t8)
/* 113398 7F0DE868 97AB0292 */  lhu   $t3, 0x292($sp)
/* 11339C 7F0DE86C 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 1133A0 7F0DE870 240F0001 */  li    $t7, 1
/* 1133A4 7F0DE874 01CB5021 */  addu  $t2, $t6, $t3
/* 1133A8 7F0DE878 10000013 */  b     .L7F0DE8C8
/* 1133AC 7F0DE87C A14FA800 */   sb    $t7, -0x5800($t2)
.L7F0DE880:
/* 1133B0 7F0DE880 29814000 */  slti  $at, $t4, 0x4000
/* 1133B4 7F0DE884 14200010 */  bnez  $at, .L7F0DE8C8
/* 1133B8 7F0DE888 97AD0298 */   lhu   $t5, 0x298($sp)
/* 1133BC 7F0DE88C 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 1133C0 7F0DE890 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 1133C4 7F0DE894 25A80002 */  addiu $t0, $t5, 2
/* 1133C8 7F0DE898 24180001 */  li    $t8, 1
/* 1133CC 7F0DE89C 012CC821 */  addu  $t9, $t1, $t4
/* 1133D0 7F0DE8A0 A3280000 */  sb    $t0, ($t9)
/* 1133D4 7F0DE8A4 97AE0292 */  lhu   $t6, 0x292($sp)
/* 1133D8 7F0DE8A8 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 1133DC 7F0DE8AC 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 1133E0 7F0DE8B0 31CB1800 */  andi  $t3, $t6, 0x1800
/* 1133E4 7F0DE8B4 000B78C3 */  sra   $t7, $t3, 3
/* 1133E8 7F0DE8B8 31CA00FF */  andi  $t2, $t6, 0xff
/* 1133EC 7F0DE8BC 01EA6825 */  or    $t5, $t7, $t2
/* 1133F0 7F0DE8C0 012D6021 */  addu  $t4, $t1, $t5
/* 1133F4 7F0DE8C4 A1980000 */  sb    $t8, ($t4)
.L7F0DE8C8:
/* 1133F8 7F0DE8C8 97A80292 */  lhu   $t0, 0x292($sp)
/* 1133FC 7F0DE8CC 97AD0292 */  lhu   $t5, 0x292($sp)
/* 113400 7F0DE8D0 97AB0298 */  lhu   $t3, 0x298($sp)
/* 113404 7F0DE8D4 25190001 */  addiu $t9, $t0, 1
/* 113408 7F0DE8D8 2B215B00 */  slti  $at, $t9, 0x5b00
/* 11340C 7F0DE8DC 14200008 */  bnez  $at, .L7F0DE900
/* 113410 7F0DE8E0 25B80001 */   addiu $t8, $t5, 1
/* 113414 7F0DE8E4 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 113418 7F0DE8E8 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 11341C 7F0DE8EC 256E0002 */  addiu $t6, $t3, 2
/* 113420 7F0DE8F0 000E7A03 */  sra   $t7, $t6, 8
/* 113424 7F0DE8F4 01484821 */  addu  $t1, $t2, $t0
/* 113428 7F0DE8F8 10000027 */  b     .L7F0DE998
/* 11342C 7F0DE8FC A12F0001 */   sb    $t7, 1($t1)
.L7F0DE900:
/* 113430 7F0DE900 2B015800 */  slti  $at, $t8, 0x5800
/* 113434 7F0DE904 1420000F */  bnez  $at, .L7F0DE944
/* 113438 7F0DE908 97AC0292 */   lhu   $t4, 0x292($sp)
/* 11343C 7F0DE90C 97AC0298 */  lhu   $t4, 0x298($sp)
/* 113440 7F0DE910 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 113444 7F0DE914 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 113448 7F0DE918 25990002 */  addiu $t9, $t4, 2
/* 11344C 7F0DE91C 00195A03 */  sra   $t3, $t9, 8
/* 113450 7F0DE920 01CD5021 */  addu  $t2, $t6, $t5
/* 113454 7F0DE924 A14B0001 */  sb    $t3, 1($t2)
/* 113458 7F0DE928 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 11345C 7F0DE92C 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 113460 7F0DE930 97A90292 */  lhu   $t1, 0x292($sp)
/* 113464 7F0DE934 24080001 */  li    $t0, 1
/* 113468 7F0DE938 01E9C021 */  addu  $t8, $t7, $t1
/* 11346C 7F0DE93C 10000016 */  b     .L7F0DE998
/* 113470 7F0DE940 A308A801 */   sb    $t0, -0x57ff($t8)
.L7F0DE944:
/* 113474 7F0DE944 25990001 */  addiu $t9, $t4, 1
/* 113478 7F0DE948 2B214000 */  slti  $at, $t9, 0x4000
/* 11347C 7F0DE94C 14200012 */  bnez  $at, .L7F0DE998
/* 113480 7F0DE950 97AE0298 */   lhu   $t6, 0x298($sp)
/* 113484 7F0DE954 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 113488 7F0DE958 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 11348C 7F0DE95C 25CD0002 */  addiu $t5, $t6, 2
/* 113490 7F0DE960 000D5A03 */  sra   $t3, $t5, 8
/* 113494 7F0DE964 014C7821 */  addu  $t7, $t2, $t4
/* 113498 7F0DE968 A1EB0001 */  sb    $t3, 1($t7)
/* 11349C 7F0DE96C 97A80292 */  lhu   $t0, 0x292($sp)
/* 1134A0 7F0DE970 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 1134A4 7F0DE974 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 1134A8 7F0DE978 25180001 */  addiu $t8, $t0, 1
/* 1134AC 7F0DE97C 33191800 */  andi  $t9, $t8, 0x1800
/* 1134B0 7F0DE980 001970C3 */  sra   $t6, $t9, 3
/* 1134B4 7F0DE984 330D00FF */  andi  $t5, $t8, 0xff
/* 1134B8 7F0DE988 01CD5025 */  or    $t2, $t6, $t5
/* 1134BC 7F0DE98C 24090001 */  li    $t1, 1
/* 1134C0 7F0DE990 018A5821 */  addu  $t3, $t4, $t2
/* 1134C4 7F0DE994 A1690000 */  sb    $t1, ($t3)
.L7F0DE998:
/* 1134C8 7F0DE998 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 1134CC 7F0DE99C 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 1134D0 7F0DE9A0 97AF0298 */  lhu   $t7, 0x298($sp)
/* 1134D4 7F0DE9A4 010F7021 */  addu  $t6, $t0, $t7
/* 1134D8 7F0DE9A8 91CD0001 */  lbu   $t5, 1($t6)
/* 1134DC 7F0DE9AC 01E8C821 */  addu  $t9, $t7, $t0
/* 1134E0 7F0DE9B0 93380000 */  lbu   $t8, ($t9)
/* 1134E4 7F0DE9B4 000D6200 */  sll   $t4, $t5, 8
/* 1134E8 7F0DE9B8 030C5025 */  or    $t2, $t8, $t4
/* 1134EC 7F0DE9BC 10000F8F */  b     .L7F0E27FC
/* 1134F0 7F0DE9C0 A7AA0298 */   sh    $t2, 0x298($sp)
.L7F0DE9C4:
/* 1134F4 7F0DE9C4 97A90298 */  lhu   $t1, 0x298($sp)
/* 1134F8 7F0DE9C8 252B0002 */  addiu $t3, $t1, 2
/* 1134FC 7F0DE9CC 10000F8B */  b     .L7F0E27FC
/* 113500 7F0DE9D0 A7AB0298 */   sh    $t3, 0x298($sp)
spectrum_op_ED:
/* 113504 7F0DE9D4 8FB9028C */  lw    $t9, 0x28c($sp)
/* 113508 7F0DE9D8 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 11350C 7F0DE9DC 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 113510 7F0DE9E0 97AF0298 */  lhu   $t7, 0x298($sp)
/* 113514 7F0DE9E4 27280004 */  addiu $t0, $t9, 4
/* 113518 7F0DE9E8 AFA8028C */  sw    $t0, 0x28c($sp)
/* 11351C 7F0DE9EC 01EE6821 */  addu  $t5, $t7, $t6
/* 113520 7F0DE9F0 91B80000 */  lbu   $t8, ($t5)
/* 113524 7F0DE9F4 8FAA0288 */  lw    $t2, 0x288($sp)
/* 113528 7F0DE9F8 25EC0001 */  addiu $t4, $t7, 1
/* 11352C 7F0DE9FC 330B00FF */  andi  $t3, $t8, 0xff
/* 113530 7F0DEA00 2961007F */  slti  $at, $t3, 0x7f
/* 113534 7F0DEA04 25490001 */  addiu $t1, $t2, 1
/* 113538 7F0DEA08 A7AC0298 */  sh    $t4, 0x298($sp)
/* 11353C 7F0DEA0C AFA90288 */  sw    $t1, 0x288($sp)
/* 113540 7F0DEA10 AFAB0048 */  sw    $t3, 0x48($sp)
/* 113544 7F0DEA14 1420000A */  bnez  $at, .L7F0DEA40
/* 113548 7F0DEA18 A3B800E3 */   sb    $t8, 0xe3($sp)
/* 11354C 7F0DEA1C 2579FF60 */  addiu $t9, $t3, -0xa0
/* 113550 7F0DEA20 2F21001C */  sltiu $at, $t9, 0x1c
/* 113554 7F0DEA24 10200C11 */  beqz  $at, .L7F0E1A6C
/* 113558 7F0DEA28 0019C880 */   sll   $t9, $t9, 2
/* 11355C 7F0DEA2C 3C018006 */  lui   $at, %hi(jpt_8005C6AC)
/* 113560 7F0DEA30 00390821 */  addu  $at, $at, $t9
/* 113564 7F0DEA34 8C39C6AC */  lw    $t9, %lo(jpt_8005C6AC)($at)
/* 113568 7F0DEA38 03200008 */  jr    $t9
/* 11356C 7F0DEA3C 00000000 */   nop   
.L7F0DEA40:
/* 113570 7F0DEA40 8FA80048 */  lw    $t0, 0x48($sp)
/* 113574 7F0DEA44 250EFFC0 */  addiu $t6, $t0, -0x40
/* 113578 7F0DEA48 2DC1003F */  sltiu $at, $t6, 0x3f
/* 11357C 7F0DEA4C 10200C07 */  beqz  $at, .L7F0E1A6C
/* 113580 7F0DEA50 000E7080 */   sll   $t6, $t6, 2
/* 113584 7F0DEA54 3C018006 */  lui   $at, %hi(jpt_8005C71C)
/* 113588 7F0DEA58 002E0821 */  addu  $at, $at, $t6
/* 11358C 7F0DEA5C 8C2EC71C */  lw    $t6, %lo(jpt_8005C71C)($at)
/* 113590 7F0DEA60 01C00008 */  jr    $t6
/* 113594 7F0DEA64 00000000 */   nop   
spectrum_op_ED_40:
/* 113598 7F0DEA68 8FAD028C */  lw    $t5, 0x28c($sp)
/* 11359C 7F0DEA6C 02402825 */  move  $a1, $s2
/* 1135A0 7F0DEA70 02603025 */  move  $a2, $s3
/* 1135A4 7F0DEA74 25A40008 */  addiu $a0, $t5, 8
/* 1135A8 7F0DEA78 0FC34DB6 */  jal   spectrum_input_handling
/* 1135AC 7F0DEA7C AFA4028C */   sw    $a0, 0x28c($sp)
/* 1135B0 7F0DEA80 8FAF028C */  lw    $t7, 0x28c($sp)
/* 1135B4 7F0DEA84 304CFFFF */  andi  $t4, $v0, 0xffff
/* 1135B8 7F0DEA88 000C5203 */  sra   $t2, $t4, 8
/* 1135BC 7F0DEA8C A7A200E0 */  sh    $v0, 0xe0($sp)
/* 1135C0 7F0DEA90 01EA4821 */  addu  $t1, $t7, $t2
/* 1135C4 7F0DEA94 93B200E1 */  lbu   $s2, 0xe1($sp)
/* 1135C8 7F0DEA98 3C0F8009 */  lui   $t7, %hi(ptr_pc_keyboard_table_alloc) 
/* 1135CC 7F0DEA9C 8DEFE334 */  lw    $t7, %lo(ptr_pc_keyboard_table_alloc)($t7)
/* 1135D0 7F0DEAA0 2E4B0001 */  sltiu $t3, $s2, 1
/* 1135D4 7F0DEAA4 AFAB0048 */  sw    $t3, 0x48($sp)
/* 1135D8 7F0DEAA8 AFA9028C */  sw    $t1, 0x28c($sp)
/* 1135DC 7F0DEAAC 024F5021 */  addu  $t2, $s2, $t7
/* 1135E0 7F0DEAB0 91490000 */  lbu   $t1, ($t2)
/* 1135E4 7F0DEAB4 32390001 */  andi  $t9, $s1, 1
/* 1135E8 7F0DEAB8 324800A8 */  andi  $t0, $s2, 0xa8
/* 1135EC 7F0DEABC 03287025 */  or    $t6, $t9, $t0
/* 1135F0 7F0DEAC0 000BC180 */  sll   $t8, $t3, 6
/* 1135F4 7F0DEAC4 01D86025 */  or    $t4, $t6, $t8
/* 1135F8 7F0DEAC8 012C8825 */  or    $s1, $t1, $t4
/* 1135FC 7F0DEACC 322B00FF */  andi  $t3, $s1, 0xff
/* 113600 7F0DEAD0 10000F4A */  b     .L7F0E27FC
/* 113604 7F0DEAD4 01608825 */   move  $s1, $t3
spectrum_op_ED_41:
/* 113608 7F0DEAD8 8FB9028C */  lw    $t9, 0x28c($sp)
/* 11360C 7F0DEADC 02402825 */  move  $a1, $s2
/* 113610 7F0DEAE0 02603025 */  move  $a2, $s3
/* 113614 7F0DEAE4 27240008 */  addiu $a0, $t9, 8
/* 113618 7F0DEAE8 AFA4028C */  sw    $a0, 0x28c($sp)
/* 11361C 7F0DEAEC 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 113620 7F0DEAF0 02403825 */   move  $a3, $s2
/* 113624 7F0DEAF4 8FAD028C */  lw    $t5, 0x28c($sp)
/* 113628 7F0DEAF8 AFA20048 */  sw    $v0, 0x48($sp)
/* 11362C 7F0DEAFC 01A2C021 */  addu  $t8, $t5, $v0
/* 113630 7F0DEB00 10000F3E */  b     .L7F0E27FC
/* 113634 7F0DEB04 AFB8028C */   sw    $t8, 0x28c($sp)
spectrum_op_ED_42:
/* 113638 7F0DEB08 00124A00 */  sll   $t1, $s2, 8
/* 11363C 7F0DEB0C 8FAF028C */  lw    $t7, 0x28c($sp)
/* 113640 7F0DEB10 01336025 */  or    $t4, $t1, $s3
/* 113644 7F0DEB14 00165A00 */  sll   $t3, $s6, 8
/* 113648 7F0DEB18 0177C825 */  or    $t9, $t3, $s7
/* 11364C 7F0DEB1C 3188FFFF */  andi  $t0, $t4, 0xffff
/* 113650 7F0DEB20 03286823 */  subu  $t5, $t9, $t0
/* 113654 7F0DEB24 322E0001 */  andi  $t6, $s1, 1
/* 113658 7F0DEB28 3C010001 */  lui   $at, (0x0001FFFF >> 16) # lui $at, 1
/* 11365C 7F0DEB2C 3421FFFF */  ori   $at, (0x0001FFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 113660 7F0DEB30 01AEC023 */  subu  $t8, $t5, $t6
/* 113664 7F0DEB34 25EA000B */  addiu $t2, $t7, 0xb
/* 113668 7F0DEB38 03017824 */  and   $t7, $t8, $at
/* 11366C 7F0DEB3C 000F5A02 */  srl   $t3, $t7, 8
/* 113670 7F0DEB40 317900A8 */  andi  $t9, $t3, 0xa8
/* 113674 7F0DEB44 000F4402 */  srl   $t0, $t7, 0x10
/* 113678 7F0DEB48 AFAA028C */  sw    $t2, 0x28c($sp)
/* 11367C 7F0DEB4C 03286825 */  or    $t5, $t9, $t0
/* 113680 7F0DEB50 31EAFFFF */  andi  $t2, $t7, 0xffff
/* 113684 7F0DEB54 2D490001 */  sltiu $t1, $t2, 1
/* 113688 7F0DEB58 35AE0002 */  ori   $t6, $t5, 2
/* 11368C 7F0DEB5C 00164200 */  sll   $t0, $s6, 8
/* 113690 7F0DEB60 01176825 */  or    $t5, $t0, $s7
/* 113694 7F0DEB64 318A0FFF */  andi  $t2, $t4, 0xfff
/* 113698 7F0DEB68 322B0001 */  andi  $t3, $s1, 1
/* 11369C 7F0DEB6C 014BC821 */  addu  $t9, $t2, $t3
/* 1136A0 7F0DEB70 31B80FFF */  andi  $t8, $t5, 0xfff
/* 1136A4 7F0DEB74 0319502A */  slt   $t2, $t8, $t9
/* 1136A8 7F0DEB78 000A5900 */  sll   $t3, $t2, 4
/* 1136AC 7F0DEB7C 01CB4025 */  or    $t0, $t6, $t3
/* 1136B0 7F0DEB80 00166A00 */  sll   $t5, $s6, 8
/* 1136B4 7F0DEB84 01B7C025 */  or    $t8, $t5, $s7
/* 1136B8 7F0DEB88 00165200 */  sll   $t2, $s6, 8
/* 1136BC 7F0DEB8C 01577025 */  or    $t6, $t2, $s7
/* 1136C0 7F0DEB90 01805825 */  move  $t3, $t4
/* 1136C4 7F0DEB94 01CB6826 */  xor   $t5, $t6, $t3
/* 1136C8 7F0DEB98 030FC826 */  xor   $t9, $t8, $t7
/* 1136CC 7F0DEB9C 01B9C024 */  and   $t8, $t5, $t9
/* 1136D0 7F0DEBA0 330A8000 */  andi  $t2, $t8, 0x8000
/* 1136D4 7F0DEBA4 A7AC00DE */  sh    $t4, 0xde($sp)
/* 1136D8 7F0DEBA8 000A6342 */  srl   $t4, $t2, 0xd
/* 1136DC 7F0DEBAC 010C7025 */  or    $t6, $t0, $t4
/* 1136E0 7F0DEBB0 00095980 */  sll   $t3, $t1, 6
/* 1136E4 7F0DEBB4 01CB8825 */  or    $s1, $t6, $t3
/* 1136E8 7F0DEBB8 000FB202 */  srl   $s6, $t7, 8
/* 1136EC 7F0DEBBC 32D800FF */  andi  $t8, $s6, 0xff
/* 1136F0 7F0DEBC0 362D0002 */  ori   $t5, $s1, 2
/* 1136F4 7F0DEBC4 AFAF00D8 */  sw    $t7, 0xd8($sp)
/* 1136F8 7F0DEBC8 93B700DB */  lbu   $s7, 0xdb($sp)
/* 1136FC 7F0DEBCC 31B100FF */  andi  $s1, $t5, 0xff
/* 113700 7F0DEBD0 0300B025 */  move  $s6, $t8
/* 113704 7F0DEBD4 10000F09 */  b     .L7F0E27FC
/* 113708 7F0DEBD8 AFA90048 */   sw    $t1, 0x48($sp)
spectrum_op_ED_43:
/* 11370C 7F0DEBDC 8FAA028C */  lw    $t2, 0x28c($sp)
/* 113710 7F0DEBE0 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 113714 7F0DEBE4 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 113718 7F0DEBE8 97AC0298 */  lhu   $t4, 0x298($sp)
/* 11371C 7F0DEBEC 25480010 */  addiu $t0, $t2, 0x10
/* 113720 7F0DEBF0 AFA8028C */  sw    $t0, 0x28c($sp)
/* 113724 7F0DEBF4 012C6821 */  addu  $t5, $t1, $t4
/* 113728 7F0DEBF8 91B90001 */  lbu   $t9, 1($t5)
/* 11372C 7F0DEBFC 01897021 */  addu  $t6, $t4, $t1
/* 113730 7F0DEC00 91CB0000 */  lbu   $t3, ($t6)
/* 113734 7F0DEC04 00197A00 */  sll   $t7, $t9, 8
/* 113738 7F0DEC08 258A0002 */  addiu $t2, $t4, 2
/* 11373C 7F0DEC0C 016FC025 */  or    $t8, $t3, $t7
/* 113740 7F0DEC10 3308FFFF */  andi  $t0, $t8, 0xffff
/* 113744 7F0DEC14 29015B00 */  slti  $at, $t0, 0x5b00
/* 113748 7F0DEC18 A7B800D6 */  sh    $t8, 0xd6($sp)
/* 11374C 7F0DEC1C 14200006 */  bnez  $at, .L7F0DEC38
/* 113750 7F0DEC20 A7AA0298 */   sh    $t2, 0x298($sp)
/* 113754 7F0DEC24 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 113758 7F0DEC28 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 11375C 7F0DEC2C 01C84821 */  addu  $t1, $t6, $t0
/* 113760 7F0DEC30 10000021 */  b     .L7F0DECB8
/* 113764 7F0DEC34 A1330000 */   sb    $s3, ($t1)
.L7F0DEC38:
/* 113768 7F0DEC38 97AD00D6 */  lhu   $t5, 0xd6($sp)
/* 11376C 7F0DEC3C 97AE00D6 */  lhu   $t6, 0xd6($sp)
/* 113770 7F0DEC40 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 113774 7F0DEC44 29A15800 */  slti  $at, $t5, 0x5800
/* 113778 7F0DEC48 5420000C */  bnezl $at, .L7F0DEC7C
/* 11377C 7F0DEC4C 29C14000 */   slti  $at, $t6, 0x4000
/* 113780 7F0DEC50 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 113784 7F0DEC54 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 113788 7F0DEC58 240F0001 */  li    $t7, 1
/* 11378C 7F0DEC5C 032D5821 */  addu  $t3, $t9, $t5
/* 113790 7F0DEC60 A1730000 */  sb    $s3, ($t3)
/* 113794 7F0DEC64 97AC00D6 */  lhu   $t4, 0xd6($sp)
/* 113798 7F0DEC68 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 11379C 7F0DEC6C 030C5021 */  addu  $t2, $t8, $t4
/* 1137A0 7F0DEC70 10000011 */  b     .L7F0DECB8
/* 1137A4 7F0DEC74 A14FA800 */   sb    $t7, -0x5800($t2)
/* 1137A8 7F0DEC78 29C14000 */  slti  $at, $t6, 0x4000
.L7F0DEC7C:
/* 1137AC 7F0DEC7C 1420000E */  bnez  $at, .L7F0DECB8
/* 1137B0 7F0DEC80 3C088009 */   lui   $t0, %hi(ptr_spectrum_roms) 
/* 1137B4 7F0DEC84 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 1137B8 7F0DEC88 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 1137BC 7F0DEC8C 24190001 */  li    $t9, 1
/* 1137C0 7F0DEC90 010E4821 */  addu  $t1, $t0, $t6
/* 1137C4 7F0DEC94 A1330000 */  sb    $s3, ($t1)
/* 1137C8 7F0DEC98 97AD00D6 */  lhu   $t5, 0xd6($sp)
/* 1137CC 7F0DEC9C 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 1137D0 7F0DECA0 31AB1800 */  andi  $t3, $t5, 0x1800
/* 1137D4 7F0DECA4 000BC0C3 */  sra   $t8, $t3, 3
/* 1137D8 7F0DECA8 31AC00FF */  andi  $t4, $t5, 0xff
/* 1137DC 7F0DECAC 030C7825 */  or    $t7, $t8, $t4
/* 1137E0 7F0DECB0 014F4021 */  addu  $t0, $t2, $t7
/* 1137E4 7F0DECB4 A1190000 */  sb    $t9, ($t0)
.L7F0DECB8:
/* 1137E8 7F0DECB8 97AE00D6 */  lhu   $t6, 0xd6($sp)
/* 1137EC 7F0DECBC 97B800D6 */  lhu   $t8, 0xd6($sp)
/* 1137F0 7F0DECC0 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 1137F4 7F0DECC4 25C90001 */  addiu $t1, $t6, 1
/* 1137F8 7F0DECC8 29215B00 */  slti  $at, $t1, 0x5b00
/* 1137FC 7F0DECCC 14200005 */  bnez  $at, .L7F0DECE4
/* 113800 7F0DECD0 270C0001 */   addiu $t4, $t8, 1
/* 113804 7F0DECD4 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 113808 7F0DECD8 016E6821 */  addu  $t5, $t3, $t6
/* 11380C 7F0DECDC 10000EC7 */  b     .L7F0E27FC
/* 113810 7F0DECE0 A1B20001 */   sb    $s2, 1($t5)
.L7F0DECE4:
/* 113814 7F0DECE4 29815800 */  slti  $at, $t4, 0x5800
/* 113818 7F0DECE8 1420000C */  bnez  $at, .L7F0DED1C
/* 11381C 7F0DECEC 97AE00D6 */   lhu   $t6, 0xd6($sp)
/* 113820 7F0DECF0 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 113824 7F0DECF4 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 113828 7F0DECF8 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 11382C 7F0DECFC 24190001 */  li    $t9, 1
/* 113830 7F0DED00 01587821 */  addu  $t7, $t2, $t8
/* 113834 7F0DED04 A1F20001 */  sb    $s2, 1($t7)
/* 113838 7F0DED08 97A900D6 */  lhu   $t1, 0xd6($sp)
/* 11383C 7F0DED0C 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 113840 7F0DED10 01095821 */  addu  $t3, $t0, $t1
/* 113844 7F0DED14 10000EB9 */  b     .L7F0E27FC
/* 113848 7F0DED18 A179A801 */   sb    $t9, -0x57ff($t3)
.L7F0DED1C:
/* 11384C 7F0DED1C 25CD0001 */  addiu $t5, $t6, 1
/* 113850 7F0DED20 29A14000 */  slti  $at, $t5, 0x4000
/* 113854 7F0DED24 14200EB5 */  bnez  $at, .L7F0E27FC
/* 113858 7F0DED28 3C0C8009 */   lui   $t4, %hi(ptr_spectrum_roms) 
/* 11385C 7F0DED2C 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 113860 7F0DED30 24180001 */  li    $t8, 1
/* 113864 7F0DED34 018E5021 */  addu  $t2, $t4, $t6
/* 113868 7F0DED38 A1520001 */  sb    $s2, 1($t2)
/* 11386C 7F0DED3C 97AF00D6 */  lhu   $t7, 0xd6($sp)
/* 113870 7F0DED40 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 113874 7F0DED44 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 113878 7F0DED48 25E80001 */  addiu $t0, $t7, 1
/* 11387C 7F0DED4C 31091800 */  andi  $t1, $t0, 0x1800
/* 113880 7F0DED50 0009C8C3 */  sra   $t9, $t1, 3
/* 113884 7F0DED54 310B00FF */  andi  $t3, $t0, 0xff
/* 113888 7F0DED58 032B6825 */  or    $t5, $t9, $t3
/* 11388C 7F0DED5C 018D7021 */  addu  $t6, $t4, $t5
/* 113890 7F0DED60 10000EA6 */  b     .L7F0E27FC
/* 113894 7F0DED64 A1D80000 */   sb    $t8, ($t6)
spectrum_op_ED_44:
/* 113898 7F0DED68 00108023 */  negu  $s0, $s0
/* 11389C 7F0DED6C 320900FF */  andi  $t1, $s0, 0xff
/* 1138A0 7F0DED70 8FAA028C */  lw    $t2, 0x28c($sp)
/* 1138A4 7F0DED74 2D280001 */  sltiu $t0, $t1, 1
/* 1138A8 7F0DED78 3138000F */  andi  $t8, $t1, 0xf
/* 1138AC 7F0DED7C 01208025 */  move  $s0, $t1
/* 1138B0 7F0DED80 313900A8 */  andi  $t9, $t1, 0xa8
/* 1138B4 7F0DED84 254F0004 */  addiu $t7, $t2, 4
/* 1138B8 7F0DED88 39290080 */  xori  $t1, $t1, 0x80
/* 1138BC 7F0DED8C 0018702A */  slt   $t6, $zero, $t8
/* 1138C0 7F0DED90 00086180 */  sll   $t4, $t0, 6
/* 1138C4 7F0DED94 AFAF028C */  sw    $t7, 0x28c($sp)
/* 1138C8 7F0DED98 032C6825 */  or    $t5, $t9, $t4
/* 1138CC 7F0DED9C 000E5100 */  sll   $t2, $t6, 4
/* 1138D0 7F0DEDA0 2D290001 */  sltiu $t1, $t1, 1
/* 1138D4 7F0DEDA4 AFA80048 */  sw    $t0, 0x48($sp)
/* 1138D8 7F0DEDA8 00094080 */  sll   $t0, $t1, 2
/* 1138DC 7F0DEDAC 01AA7825 */  or    $t7, $t5, $t2
/* 1138E0 7F0DEDB0 01E85825 */  or    $t3, $t7, $t0
/* 1138E4 7F0DEDB4 35790002 */  ori   $t9, $t3, 2
/* 1138E8 7F0DEDB8 0010602A */  slt   $t4, $zero, $s0
/* 1138EC 7F0DEDBC 032C8825 */  or    $s1, $t9, $t4
/* 1138F0 7F0DEDC0 323800FF */  andi  $t8, $s1, 0xff
/* 1138F4 7F0DEDC4 10000E8D */  b     .L7F0E27FC
/* 1138F8 7F0DEDC8 03008825 */   move  $s1, $t8
spectrum_op_ED_45:
/* 1138FC 7F0DEDCC 8FAE028C */  lw    $t6, 0x28c($sp)
/* 113900 7F0DEDD0 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 113904 7F0DEDD4 93AA029C */  lbu   $t2, 0x29c($sp)
/* 113908 7F0DEDD8 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 11390C 7F0DEDDC 97A80292 */  lhu   $t0, 0x292($sp)
/* 113910 7F0DEDE0 25CD0004 */  addiu $t5, $t6, 4
/* 113914 7F0DEDE4 AFAD028C */  sw    $t5, 0x28c($sp)
/* 113918 7F0DEDE8 25AF0006 */  addiu $t7, $t5, 6
/* 11391C 7F0DEDEC AFAF028C */  sw    $t7, 0x28c($sp)
/* 113920 7F0DEDF0 A3AA029D */  sb    $t2, 0x29d($sp)
/* 113924 7F0DEDF4 0168C021 */  addu  $t8, $t3, $t0
/* 113928 7F0DEDF8 930E0001 */  lbu   $t6, 1($t8)
/* 11392C 7F0DEDFC 010BC821 */  addu  $t9, $t0, $t3
/* 113930 7F0DEE00 932C0000 */  lbu   $t4, ($t9)
/* 113934 7F0DEE04 000E6A00 */  sll   $t5, $t6, 8
/* 113938 7F0DEE08 25090002 */  addiu $t1, $t0, 2
/* 11393C 7F0DEE0C 018D5025 */  or    $t2, $t4, $t5
/* 113940 7F0DEE10 A7AA0298 */  sh    $t2, 0x298($sp)
/* 113944 7F0DEE14 10000E79 */  b     .L7F0E27FC
/* 113948 7F0DEE18 A7A90292 */   sh    $t1, 0x292($sp)
spectrum_op_ED_46:
/* 11394C 7F0DEE1C 8FAF028C */  lw    $t7, 0x28c($sp)
/* 113950 7F0DEE20 A3A0029B */  sb    $zero, 0x29b($sp)
/* 113954 7F0DEE24 25F90004 */  addiu $t9, $t7, 4
/* 113958 7F0DEE28 10000E74 */  b     .L7F0E27FC
/* 11395C 7F0DEE2C AFB9028C */   sw    $t9, 0x28c($sp)
spectrum_op_ED_47:
/* 113960 7F0DEE30 8FAB028C */  lw    $t3, 0x28c($sp)
/* 113964 7F0DEE34 A3B0029E */  sb    $s0, 0x29e($sp)
/* 113968 7F0DEE38 25780005 */  addiu $t8, $t3, 5
/* 11396C 7F0DEE3C 10000E6F */  b     .L7F0E27FC
/* 113970 7F0DEE40 AFB8028C */   sw    $t8, 0x28c($sp)
spectrum_op_ED_48:
/* 113974 7F0DEE44 8FAE028C */  lw    $t6, 0x28c($sp)
/* 113978 7F0DEE48 02402825 */  move  $a1, $s2
/* 11397C 7F0DEE4C 02603025 */  move  $a2, $s3
/* 113980 7F0DEE50 25C40008 */  addiu $a0, $t6, 8
/* 113984 7F0DEE54 0FC34DB6 */  jal   spectrum_input_handling
/* 113988 7F0DEE58 AFA4028C */   sw    $a0, 0x28c($sp)
/* 11398C 7F0DEE5C 8FAD028C */  lw    $t5, 0x28c($sp)
/* 113990 7F0DEE60 304AFFFF */  andi  $t2, $v0, 0xffff
/* 113994 7F0DEE64 000A4203 */  sra   $t0, $t2, 8
/* 113998 7F0DEE68 A7A200D4 */  sh    $v0, 0xd4($sp)
/* 11399C 7F0DEE6C 01A84821 */  addu  $t1, $t5, $t0
/* 1139A0 7F0DEE70 93B300D5 */  lbu   $s3, 0xd5($sp)
/* 1139A4 7F0DEE74 3C0D8009 */  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
/* 1139A8 7F0DEE78 8DADE334 */  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
/* 1139AC 7F0DEE7C 2E6F0001 */  sltiu $t7, $s3, 1
/* 1139B0 7F0DEE80 AFAF0048 */  sw    $t7, 0x48($sp)
/* 1139B4 7F0DEE84 AFA9028C */  sw    $t1, 0x28c($sp)
/* 1139B8 7F0DEE88 026D4021 */  addu  $t0, $s3, $t5
/* 1139BC 7F0DEE8C 91090000 */  lbu   $t1, ($t0)
/* 1139C0 7F0DEE90 32390001 */  andi  $t9, $s1, 1
/* 1139C4 7F0DEE94 326B00A8 */  andi  $t3, $s3, 0xa8
/* 1139C8 7F0DEE98 032BC025 */  or    $t8, $t9, $t3
/* 1139CC 7F0DEE9C 000F6180 */  sll   $t4, $t7, 6
/* 1139D0 7F0DEEA0 030C5025 */  or    $t2, $t8, $t4
/* 1139D4 7F0DEEA4 012A8825 */  or    $s1, $t1, $t2
/* 1139D8 7F0DEEA8 322F00FF */  andi  $t7, $s1, 0xff
/* 1139DC 7F0DEEAC 10000E53 */  b     .L7F0E27FC
/* 1139E0 7F0DEEB0 01E08825 */   move  $s1, $t7
spectrum_op_ED_49:
/* 1139E4 7F0DEEB4 8FB9028C */  lw    $t9, 0x28c($sp)
/* 1139E8 7F0DEEB8 02402825 */  move  $a1, $s2
/* 1139EC 7F0DEEBC 02603025 */  move  $a2, $s3
/* 1139F0 7F0DEEC0 27240008 */  addiu $a0, $t9, 8
/* 1139F4 7F0DEEC4 AFA4028C */  sw    $a0, 0x28c($sp)
/* 1139F8 7F0DEEC8 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 1139FC 7F0DEECC 02603825 */   move  $a3, $s3
/* 113A00 7F0DEED0 8FAE028C */  lw    $t6, 0x28c($sp)
/* 113A04 7F0DEED4 AFA20048 */  sw    $v0, 0x48($sp)
/* 113A08 7F0DEED8 01C26021 */  addu  $t4, $t6, $v0
/* 113A0C 7F0DEEDC 10000E47 */  b     .L7F0E27FC
/* 113A10 7F0DEEE0 AFAC028C */   sw    $t4, 0x28c($sp)
spectrum_op_ED_4A:
/* 113A14 7F0DEEE4 00124A00 */  sll   $t1, $s2, 8
/* 113A18 7F0DEEE8 01335025 */  or    $t2, $t1, $s3
/* 113A1C 7F0DEEEC 00167A00 */  sll   $t7, $s6, 8
/* 113A20 7F0DEEF0 01F7C825 */  or    $t9, $t7, $s7
/* 113A24 7F0DEEF4 314BFFFF */  andi  $t3, $t2, 0xffff
/* 113A28 7F0DEEF8 8FAD028C */  lw    $t5, 0x28c($sp)
/* 113A2C 7F0DEEFC 032B7021 */  addu  $t6, $t9, $t3
/* 113A30 7F0DEF00 32380001 */  andi  $t8, $s1, 1
/* 113A34 7F0DEF04 01D86021 */  addu  $t4, $t6, $t8
/* 113A38 7F0DEF08 25A8000B */  addiu $t0, $t5, 0xb
/* 113A3C 7F0DEF0C 000C4A02 */  srl   $t1, $t4, 8
/* 113A40 7F0DEF10 AFA8028C */  sw    $t0, 0x28c($sp)
/* 113A44 7F0DEF14 312F00A8 */  andi  $t7, $t1, 0xa8
/* 113A48 7F0DEF18 318DFFFF */  andi  $t5, $t4, 0xffff
/* 113A4C 7F0DEF1C 000CCC02 */  srl   $t9, $t4, 0x10
/* 113A50 7F0DEF20 00167200 */  sll   $t6, $s6, 8
/* 113A54 7F0DEF24 01D7C025 */  or    $t8, $t6, $s7
/* 113A58 7F0DEF28 01F95825 */  or    $t3, $t7, $t9
/* 113A5C 7F0DEF2C 2DA80001 */  sltiu $t0, $t5, 1
/* 113A60 7F0DEF30 330D0FFF */  andi  $t5, $t8, 0xfff
/* 113A64 7F0DEF34 314F0FFF */  andi  $t7, $t2, 0xfff
/* 113A68 7F0DEF38 01AFC821 */  addu  $t9, $t5, $t7
/* 113A6C 7F0DEF3C 322E0001 */  andi  $t6, $s1, 1
/* 113A70 7F0DEF40 032EC021 */  addu  $t8, $t9, $t6
/* 113A74 7F0DEF44 24010FFF */  li    $at, 4095
/* 113A78 7F0DEF48 0038482A */  slt   $t1, $at, $t8
/* 113A7C 7F0DEF4C 00096900 */  sll   $t5, $t1, 4
/* 113A80 7F0DEF50 016D7825 */  or    $t7, $t3, $t5
/* 113A84 7F0DEF54 0016CA00 */  sll   $t9, $s6, 8
/* 113A88 7F0DEF58 03377025 */  or    $t6, $t9, $s7
/* 113A8C 7F0DEF5C 00164A00 */  sll   $t1, $s6, 8
/* 113A90 7F0DEF60 01375827 */  nor   $t3, $t1, $s7
/* 113A94 7F0DEF64 01406825 */  move  $t5, $t2
/* 113A98 7F0DEF68 016DC826 */  xor   $t9, $t3, $t5
/* 113A9C 7F0DEF6C 01CCC026 */  xor   $t8, $t6, $t4
/* 113AA0 7F0DEF70 03387024 */  and   $t6, $t9, $t8
/* 113AA4 7F0DEF74 31C98000 */  andi  $t1, $t6, 0x8000
/* 113AA8 7F0DEF78 A7AA00D2 */  sh    $t2, 0xd2($sp)
/* 113AAC 7F0DEF7C 00095342 */  srl   $t2, $t1, 0xd
/* 113AB0 7F0DEF80 01EA5825 */  or    $t3, $t7, $t2
/* 113AB4 7F0DEF84 00086980 */  sll   $t5, $t0, 6
/* 113AB8 7F0DEF88 016D8825 */  or    $s1, $t3, $t5
/* 113ABC 7F0DEF8C 000CB202 */  srl   $s6, $t4, 8
/* 113AC0 7F0DEF90 32CE00FF */  andi  $t6, $s6, 0xff
/* 113AC4 7F0DEF94 36390002 */  ori   $t9, $s1, 2
/* 113AC8 7F0DEF98 AFAC00CC */  sw    $t4, 0xcc($sp)
/* 113ACC 7F0DEF9C 93B700CF */  lbu   $s7, 0xcf($sp)
/* 113AD0 7F0DEFA0 333100FF */  andi  $s1, $t9, 0xff
/* 113AD4 7F0DEFA4 01C0B025 */  move  $s6, $t6
/* 113AD8 7F0DEFA8 10000E14 */  b     .L7F0E27FC
/* 113ADC 7F0DEFAC AFA80048 */   sw    $t0, 0x48($sp)
spectrum_op_ED_4B:
/* 113AE0 7F0DEFB0 8FA9028C */  lw    $t1, 0x28c($sp)
/* 113AE4 7F0DEFB4 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 113AE8 7F0DEFB8 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 113AEC 7F0DEFBC 97AA0298 */  lhu   $t2, 0x298($sp)
/* 113AF0 7F0DEFC0 252F0010 */  addiu $t7, $t1, 0x10
/* 113AF4 7F0DEFC4 AFAF028C */  sw    $t7, 0x28c($sp)
/* 113AF8 7F0DEFC8 010AC821 */  addu  $t9, $t0, $t2
/* 113AFC 7F0DEFCC 93380001 */  lbu   $t8, 1($t9)
/* 113B00 7F0DEFD0 01485821 */  addu  $t3, $t2, $t0
/* 113B04 7F0DEFD4 916D0000 */  lbu   $t5, ($t3)
/* 113B08 7F0DEFD8 00186200 */  sll   $t4, $t8, 8
/* 113B0C 7F0DEFDC 25490002 */  addiu $t1, $t2, 2
/* 113B10 7F0DEFE0 01AC7025 */  or    $t6, $t5, $t4
/* 113B14 7F0DEFE4 31CFFFFF */  andi  $t7, $t6, 0xffff
/* 113B18 7F0DEFE8 A7AE00CA */  sh    $t6, 0xca($sp)
/* 113B1C 7F0DEFEC A7A90298 */  sh    $t1, 0x298($sp)
/* 113B20 7F0DEFF0 01E85821 */  addu  $t3, $t7, $t0
/* 113B24 7F0DEFF4 91730000 */  lbu   $s3, ($t3)
/* 113B28 7F0DEFF8 10000E00 */  b     .L7F0E27FC
/* 113B2C 7F0DEFFC 91720001 */   lbu   $s2, 1($t3)
spectrum_op_ED_4C:
/* 113B30 7F0DF000 00108023 */  negu  $s0, $s0
/* 113B34 7F0DF004 320D00FF */  andi  $t5, $s0, 0xff
/* 113B38 7F0DF008 8FB9028C */  lw    $t9, 0x28c($sp)
/* 113B3C 7F0DF00C 2DAC0001 */  sltiu $t4, $t5, 1
/* 113B40 7F0DF010 31A8000F */  andi  $t0, $t5, 0xf
/* 113B44 7F0DF014 01A08025 */  move  $s0, $t5
/* 113B48 7F0DF018 31AE00A8 */  andi  $t6, $t5, 0xa8
/* 113B4C 7F0DF01C 27380004 */  addiu $t8, $t9, 4
/* 113B50 7F0DF020 39AD0080 */  xori  $t5, $t5, 0x80
/* 113B54 7F0DF024 0008582A */  slt   $t3, $zero, $t0
/* 113B58 7F0DF028 000C4980 */  sll   $t1, $t4, 6
/* 113B5C 7F0DF02C AFB8028C */  sw    $t8, 0x28c($sp)
/* 113B60 7F0DF030 01C97825 */  or    $t7, $t6, $t1
/* 113B64 7F0DF034 000BC900 */  sll   $t9, $t3, 4
/* 113B68 7F0DF038 2DAD0001 */  sltiu $t5, $t5, 1
/* 113B6C 7F0DF03C AFAC0048 */  sw    $t4, 0x48($sp)
/* 113B70 7F0DF040 000D6080 */  sll   $t4, $t5, 2
/* 113B74 7F0DF044 01F9C025 */  or    $t8, $t7, $t9
/* 113B78 7F0DF048 030C5025 */  or    $t2, $t8, $t4
/* 113B7C 7F0DF04C 354E0002 */  ori   $t6, $t2, 2
/* 113B80 7F0DF050 0010482A */  slt   $t1, $zero, $s0
/* 113B84 7F0DF054 01C98825 */  or    $s1, $t6, $t1
/* 113B88 7F0DF058 322800FF */  andi  $t0, $s1, 0xff
/* 113B8C 7F0DF05C 10000DE7 */  b     .L7F0E27FC
/* 113B90 7F0DF060 01008825 */   move  $s1, $t0
spectrum_op_ED_4D:
/* 113B94 7F0DF064 8FAB028C */  lw    $t3, 0x28c($sp)
/* 113B98 7F0DF068 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 113B9C 7F0DF06C 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 113BA0 7F0DF070 97B80292 */  lhu   $t8, 0x292($sp)
/* 113BA4 7F0DF074 256F0004 */  addiu $t7, $t3, 4
/* 113BA8 7F0DF078 AFAF028C */  sw    $t7, 0x28c($sp)
/* 113BAC 7F0DF07C 25ED0006 */  addiu $t5, $t7, 6
/* 113BB0 7F0DF080 AFAD028C */  sw    $t5, 0x28c($sp)
/* 113BB4 7F0DF084 01984821 */  addu  $t1, $t4, $t8
/* 113BB8 7F0DF088 91280001 */  lbu   $t0, 1($t1)
/* 113BBC 7F0DF08C 030C5021 */  addu  $t2, $t8, $t4
/* 113BC0 7F0DF090 914E0000 */  lbu   $t6, ($t2)
/* 113BC4 7F0DF094 00085A00 */  sll   $t3, $t0, 8
/* 113BC8 7F0DF098 27190002 */  addiu $t9, $t8, 2
/* 113BCC 7F0DF09C 01CB7825 */  or    $t7, $t6, $t3
/* 113BD0 7F0DF0A0 A7AF0298 */  sh    $t7, 0x298($sp)
/* 113BD4 7F0DF0A4 10000DD5 */  b     .L7F0E27FC
/* 113BD8 7F0DF0A8 A7B90292 */   sh    $t9, 0x292($sp)
spectrum_op_ED_4E:
/* 113BDC 7F0DF0AC 8FAD028C */  lw    $t5, 0x28c($sp)
/* 113BE0 7F0DF0B0 240C0001 */  li    $t4, 1
/* 113BE4 7F0DF0B4 A3AC029B */  sb    $t4, 0x29b($sp)
/* 113BE8 7F0DF0B8 25AA0004 */  addiu $t2, $t5, 4
/* 113BEC 7F0DF0BC 10000DCF */  b     .L7F0E27FC
/* 113BF0 7F0DF0C0 AFAA028C */   sw    $t2, 0x28c($sp)
spectrum_op_ED_4F:
/* 113BF4 7F0DF0C4 8FA9028C */  lw    $t1, 0x28c($sp)
/* 113BF8 7F0DF0C8 320E00FF */  andi  $t6, $s0, 0xff
/* 113BFC 7F0DF0CC A3B002A7 */  sb    $s0, 0x2a7($sp)
/* 113C00 7F0DF0D0 25280005 */  addiu $t0, $t1, 5
/* 113C04 7F0DF0D4 AFA8028C */  sw    $t0, 0x28c($sp)
/* 113C08 7F0DF0D8 10000DC8 */  b     .L7F0E27FC
/* 113C0C 7F0DF0DC AFAE0288 */   sw    $t6, 0x288($sp)
spectrum_op_ED_50:
/* 113C10 7F0DF0E0 8FAB028C */  lw    $t3, 0x28c($sp)
/* 113C14 7F0DF0E4 02402825 */  move  $a1, $s2
/* 113C18 7F0DF0E8 02603025 */  move  $a2, $s3
/* 113C1C 7F0DF0EC 25640008 */  addiu $a0, $t3, 8
/* 113C20 7F0DF0F0 0FC34DB6 */  jal   spectrum_input_handling
/* 113C24 7F0DF0F4 AFA4028C */   sw    $a0, 0x28c($sp)
/* 113C28 7F0DF0F8 8FB8028C */  lw    $t8, 0x28c($sp)
/* 113C2C 7F0DF0FC 3059FFFF */  andi  $t9, $v0, 0xffff
/* 113C30 7F0DF100 00196A03 */  sra   $t5, $t9, 8
/* 113C34 7F0DF104 A7A200C8 */  sh    $v0, 0xc8($sp)
/* 113C38 7F0DF108 030D5021 */  addu  $t2, $t8, $t5
/* 113C3C 7F0DF10C 93B400C9 */  lbu   $s4, 0xc9($sp)
/* 113C40 7F0DF110 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 113C44 7F0DF114 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 113C48 7F0DF118 2E8C0001 */  sltiu $t4, $s4, 1
/* 113C4C 7F0DF11C AFAC0048 */  sw    $t4, 0x48($sp)
/* 113C50 7F0DF120 AFAA028C */  sw    $t2, 0x28c($sp)
/* 113C54 7F0DF124 02986821 */  addu  $t5, $s4, $t8
/* 113C58 7F0DF128 91AA0000 */  lbu   $t2, ($t5)
/* 113C5C 7F0DF12C 32290001 */  andi  $t1, $s1, 1
/* 113C60 7F0DF130 328800A8 */  andi  $t0, $s4, 0xa8
/* 113C64 7F0DF134 01287025 */  or    $t6, $t1, $t0
/* 113C68 7F0DF138 000C7980 */  sll   $t7, $t4, 6
/* 113C6C 7F0DF13C 01CFC825 */  or    $t9, $t6, $t7
/* 113C70 7F0DF140 01598825 */  or    $s1, $t2, $t9
/* 113C74 7F0DF144 322C00FF */  andi  $t4, $s1, 0xff
/* 113C78 7F0DF148 10000DAC */  b     .L7F0E27FC
/* 113C7C 7F0DF14C 01808825 */   move  $s1, $t4
spectrum_op_ED_51:
/* 113C80 7F0DF150 8FA9028C */  lw    $t1, 0x28c($sp)
/* 113C84 7F0DF154 02402825 */  move  $a1, $s2
/* 113C88 7F0DF158 02603025 */  move  $a2, $s3
/* 113C8C 7F0DF15C 25240008 */  addiu $a0, $t1, 8
/* 113C90 7F0DF160 AFA4028C */  sw    $a0, 0x28c($sp)
/* 113C94 7F0DF164 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 113C98 7F0DF168 02803825 */   move  $a3, $s4
/* 113C9C 7F0DF16C 8FAB028C */  lw    $t3, 0x28c($sp)
/* 113CA0 7F0DF170 AFA20048 */  sw    $v0, 0x48($sp)
/* 113CA4 7F0DF174 01627821 */  addu  $t7, $t3, $v0
/* 113CA8 7F0DF178 10000DA0 */  b     .L7F0E27FC
/* 113CAC 7F0DF17C AFAF028C */   sw    $t7, 0x28c($sp)
spectrum_op_ED_52:
/* 113CB0 7F0DF180 00145200 */  sll   $t2, $s4, 8
/* 113CB4 7F0DF184 8FB8028C */  lw    $t8, 0x28c($sp)
/* 113CB8 7F0DF188 0155C825 */  or    $t9, $t2, $s5
/* 113CBC 7F0DF18C 00166200 */  sll   $t4, $s6, 8
/* 113CC0 7F0DF190 01974825 */  or    $t1, $t4, $s7
/* 113CC4 7F0DF194 3328FFFF */  andi  $t0, $t9, 0xffff
/* 113CC8 7F0DF198 01285823 */  subu  $t3, $t1, $t0
/* 113CCC 7F0DF19C 322E0001 */  andi  $t6, $s1, 1
/* 113CD0 7F0DF1A0 3C010001 */  lui   $at, (0x0001FFFF >> 16) # lui $at, 1
/* 113CD4 7F0DF1A4 3421FFFF */  ori   $at, (0x0001FFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 113CD8 7F0DF1A8 016E7823 */  subu  $t7, $t3, $t6
/* 113CDC 7F0DF1AC 270D000B */  addiu $t5, $t8, 0xb
/* 113CE0 7F0DF1B0 01E1C024 */  and   $t8, $t7, $at
/* 113CE4 7F0DF1B4 00186202 */  srl   $t4, $t8, 8
/* 113CE8 7F0DF1B8 318900A8 */  andi  $t1, $t4, 0xa8
/* 113CEC 7F0DF1BC 00184402 */  srl   $t0, $t8, 0x10
/* 113CF0 7F0DF1C0 AFAD028C */  sw    $t5, 0x28c($sp)
/* 113CF4 7F0DF1C4 01285825 */  or    $t3, $t1, $t0
/* 113CF8 7F0DF1C8 330DFFFF */  andi  $t5, $t8, 0xffff
/* 113CFC 7F0DF1CC 2DAA0001 */  sltiu $t2, $t5, 1
/* 113D00 7F0DF1D0 356E0002 */  ori   $t6, $t3, 2
/* 113D04 7F0DF1D4 00164200 */  sll   $t0, $s6, 8
/* 113D08 7F0DF1D8 01175825 */  or    $t3, $t0, $s7
/* 113D0C 7F0DF1DC 332D0FFF */  andi  $t5, $t9, 0xfff
/* 113D10 7F0DF1E0 322C0001 */  andi  $t4, $s1, 1
/* 113D14 7F0DF1E4 01AC4821 */  addu  $t1, $t5, $t4
/* 113D18 7F0DF1E8 316F0FFF */  andi  $t7, $t3, 0xfff
/* 113D1C 7F0DF1EC 01E9682A */  slt   $t5, $t7, $t1
/* 113D20 7F0DF1F0 000D6100 */  sll   $t4, $t5, 4
/* 113D24 7F0DF1F4 01CC4025 */  or    $t0, $t6, $t4
/* 113D28 7F0DF1F8 00165A00 */  sll   $t3, $s6, 8
/* 113D2C 7F0DF1FC 01777825 */  or    $t7, $t3, $s7
/* 113D30 7F0DF200 00166A00 */  sll   $t5, $s6, 8
/* 113D34 7F0DF204 01B77025 */  or    $t6, $t5, $s7
/* 113D38 7F0DF208 03206025 */  move  $t4, $t9
/* 113D3C 7F0DF20C 01CC5826 */  xor   $t3, $t6, $t4
/* 113D40 7F0DF210 01F84826 */  xor   $t1, $t7, $t8
/* 113D44 7F0DF214 01697824 */  and   $t7, $t3, $t1
/* 113D48 7F0DF218 31ED8000 */  andi  $t5, $t7, 0x8000
/* 113D4C 7F0DF21C A7B900C6 */  sh    $t9, 0xc6($sp)
/* 113D50 7F0DF220 000DCB42 */  srl   $t9, $t5, 0xd
/* 113D54 7F0DF224 01197025 */  or    $t6, $t0, $t9
/* 113D58 7F0DF228 000A6180 */  sll   $t4, $t2, 6
/* 113D5C 7F0DF22C 01CC8825 */  or    $s1, $t6, $t4
/* 113D60 7F0DF230 0018B202 */  srl   $s6, $t8, 8
/* 113D64 7F0DF234 32CF00FF */  andi  $t7, $s6, 0xff
/* 113D68 7F0DF238 362B0002 */  ori   $t3, $s1, 2
/* 113D6C 7F0DF23C AFB800C0 */  sw    $t8, 0xc0($sp)
/* 113D70 7F0DF240 93B700C3 */  lbu   $s7, 0xc3($sp)
/* 113D74 7F0DF244 317100FF */  andi  $s1, $t3, 0xff
/* 113D78 7F0DF248 01E0B025 */  move  $s6, $t7
/* 113D7C 7F0DF24C 10000D6B */  b     .L7F0E27FC
/* 113D80 7F0DF250 AFAA0048 */   sw    $t2, 0x48($sp)
spectrum_op_ED_53:
/* 113D84 7F0DF254 8FAD028C */  lw    $t5, 0x28c($sp)
/* 113D88 7F0DF258 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 113D8C 7F0DF25C 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 113D90 7F0DF260 97B90298 */  lhu   $t9, 0x298($sp)
/* 113D94 7F0DF264 25A80010 */  addiu $t0, $t5, 0x10
/* 113D98 7F0DF268 AFA8028C */  sw    $t0, 0x28c($sp)
/* 113D9C 7F0DF26C 01595821 */  addu  $t3, $t2, $t9
/* 113DA0 7F0DF270 91690001 */  lbu   $t1, 1($t3)
/* 113DA4 7F0DF274 032A7021 */  addu  $t6, $t9, $t2
/* 113DA8 7F0DF278 91CC0000 */  lbu   $t4, ($t6)
/* 113DAC 7F0DF27C 0009C200 */  sll   $t8, $t1, 8
/* 113DB0 7F0DF280 272D0002 */  addiu $t5, $t9, 2
/* 113DB4 7F0DF284 01987825 */  or    $t7, $t4, $t8
/* 113DB8 7F0DF288 31E8FFFF */  andi  $t0, $t7, 0xffff
/* 113DBC 7F0DF28C 29015B00 */  slti  $at, $t0, 0x5b00
/* 113DC0 7F0DF290 A7AF00BE */  sh    $t7, 0xbe($sp)
/* 113DC4 7F0DF294 14200006 */  bnez  $at, .L7F0DF2B0
/* 113DC8 7F0DF298 A7AD0298 */   sh    $t5, 0x298($sp)
/* 113DCC 7F0DF29C 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 113DD0 7F0DF2A0 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 113DD4 7F0DF2A4 01C85021 */  addu  $t2, $t6, $t0
/* 113DD8 7F0DF2A8 10000021 */  b     .L7F0DF330
/* 113DDC 7F0DF2AC A1550000 */   sb    $s5, ($t2)
.L7F0DF2B0:
/* 113DE0 7F0DF2B0 97AB00BE */  lhu   $t3, 0xbe($sp)
/* 113DE4 7F0DF2B4 97AE00BE */  lhu   $t6, 0xbe($sp)
/* 113DE8 7F0DF2B8 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 113DEC 7F0DF2BC 29615800 */  slti  $at, $t3, 0x5800
/* 113DF0 7F0DF2C0 5420000C */  bnezl $at, .L7F0DF2F4
/* 113DF4 7F0DF2C4 29C14000 */   slti  $at, $t6, 0x4000
/* 113DF8 7F0DF2C8 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 113DFC 7F0DF2CC 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 113E00 7F0DF2D0 24180001 */  li    $t8, 1
/* 113E04 7F0DF2D4 012B6021 */  addu  $t4, $t1, $t3
/* 113E08 7F0DF2D8 A1950000 */  sb    $s5, ($t4)
/* 113E0C 7F0DF2DC 97B900BE */  lhu   $t9, 0xbe($sp)
/* 113E10 7F0DF2E0 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 113E14 7F0DF2E4 01F96821 */  addu  $t5, $t7, $t9
/* 113E18 7F0DF2E8 10000011 */  b     .L7F0DF330
/* 113E1C 7F0DF2EC A1B8A800 */   sb    $t8, -0x5800($t5)
/* 113E20 7F0DF2F0 29C14000 */  slti  $at, $t6, 0x4000
.L7F0DF2F4:
/* 113E24 7F0DF2F4 1420000E */  bnez  $at, .L7F0DF330
/* 113E28 7F0DF2F8 3C088009 */   lui   $t0, %hi(ptr_spectrum_roms) 
/* 113E2C 7F0DF2FC 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 113E30 7F0DF300 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 113E34 7F0DF304 24090001 */  li    $t1, 1
/* 113E38 7F0DF308 010E5021 */  addu  $t2, $t0, $t6
/* 113E3C 7F0DF30C A1550000 */  sb    $s5, ($t2)
/* 113E40 7F0DF310 97AB00BE */  lhu   $t3, 0xbe($sp)
/* 113E44 7F0DF314 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 113E48 7F0DF318 316C1800 */  andi  $t4, $t3, 0x1800
/* 113E4C 7F0DF31C 000C78C3 */  sra   $t7, $t4, 3
/* 113E50 7F0DF320 317900FF */  andi  $t9, $t3, 0xff
/* 113E54 7F0DF324 01F9C025 */  or    $t8, $t7, $t9
/* 113E58 7F0DF328 01B84021 */  addu  $t0, $t5, $t8
/* 113E5C 7F0DF32C A1090000 */  sb    $t1, ($t0)
.L7F0DF330:
/* 113E60 7F0DF330 97AE00BE */  lhu   $t6, 0xbe($sp)
/* 113E64 7F0DF334 97AF00BE */  lhu   $t7, 0xbe($sp)
/* 113E68 7F0DF338 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 113E6C 7F0DF33C 25CA0001 */  addiu $t2, $t6, 1
/* 113E70 7F0DF340 29415B00 */  slti  $at, $t2, 0x5b00
/* 113E74 7F0DF344 14200005 */  bnez  $at, .L7F0DF35C
/* 113E78 7F0DF348 25F90001 */   addiu $t9, $t7, 1
/* 113E7C 7F0DF34C 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 113E80 7F0DF350 018E5821 */  addu  $t3, $t4, $t6
/* 113E84 7F0DF354 10000D29 */  b     .L7F0E27FC
/* 113E88 7F0DF358 A1740001 */   sb    $s4, 1($t3)
.L7F0DF35C:
/* 113E8C 7F0DF35C 2B215800 */  slti  $at, $t9, 0x5800
/* 113E90 7F0DF360 1420000C */  bnez  $at, .L7F0DF394
/* 113E94 7F0DF364 97AE00BE */   lhu   $t6, 0xbe($sp)
/* 113E98 7F0DF368 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 113E9C 7F0DF36C 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 113EA0 7F0DF370 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 113EA4 7F0DF374 24090001 */  li    $t1, 1
/* 113EA8 7F0DF378 01AFC021 */  addu  $t8, $t5, $t7
/* 113EAC 7F0DF37C A3140001 */  sb    $s4, 1($t8)
/* 113EB0 7F0DF380 97AA00BE */  lhu   $t2, 0xbe($sp)
/* 113EB4 7F0DF384 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 113EB8 7F0DF388 010A6021 */  addu  $t4, $t0, $t2
/* 113EBC 7F0DF38C 10000D1B */  b     .L7F0E27FC
/* 113EC0 7F0DF390 A189A801 */   sb    $t1, -0x57ff($t4)
.L7F0DF394:
/* 113EC4 7F0DF394 25CB0001 */  addiu $t3, $t6, 1
/* 113EC8 7F0DF398 29614000 */  slti  $at, $t3, 0x4000
/* 113ECC 7F0DF39C 14200D17 */  bnez  $at, .L7F0E27FC
/* 113ED0 7F0DF3A0 3C198009 */   lui   $t9, %hi(ptr_spectrum_roms) 
/* 113ED4 7F0DF3A4 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 113ED8 7F0DF3A8 240F0001 */  li    $t7, 1
/* 113EDC 7F0DF3AC 032E6821 */  addu  $t5, $t9, $t6
/* 113EE0 7F0DF3B0 A1B40001 */  sb    $s4, 1($t5)
/* 113EE4 7F0DF3B4 97B800BE */  lhu   $t8, 0xbe($sp)
/* 113EE8 7F0DF3B8 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 113EEC 7F0DF3BC 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 113EF0 7F0DF3C0 27080001 */  addiu $t0, $t8, 1
/* 113EF4 7F0DF3C4 310A1800 */  andi  $t2, $t0, 0x1800
/* 113EF8 7F0DF3C8 000A48C3 */  sra   $t1, $t2, 3
/* 113EFC 7F0DF3CC 310C00FF */  andi  $t4, $t0, 0xff
/* 113F00 7F0DF3D0 012C5825 */  or    $t3, $t1, $t4
/* 113F04 7F0DF3D4 032B7021 */  addu  $t6, $t9, $t3
/* 113F08 7F0DF3D8 10000D08 */  b     .L7F0E27FC
/* 113F0C 7F0DF3DC A1CF0000 */   sb    $t7, ($t6)
spectrum_op_ED_54:
/* 113F10 7F0DF3E0 00108023 */  negu  $s0, $s0
/* 113F14 7F0DF3E4 320A00FF */  andi  $t2, $s0, 0xff
/* 113F18 7F0DF3E8 8FAD028C */  lw    $t5, 0x28c($sp)
/* 113F1C 7F0DF3EC 2D480001 */  sltiu $t0, $t2, 1
/* 113F20 7F0DF3F0 314F000F */  andi  $t7, $t2, 0xf
/* 113F24 7F0DF3F4 01408025 */  move  $s0, $t2
/* 113F28 7F0DF3F8 314900A8 */  andi  $t1, $t2, 0xa8
/* 113F2C 7F0DF3FC 25B80004 */  addiu $t8, $t5, 4
/* 113F30 7F0DF400 394A0080 */  xori  $t2, $t2, 0x80
/* 113F34 7F0DF404 000F702A */  slt   $t6, $zero, $t7
/* 113F38 7F0DF408 0008C980 */  sll   $t9, $t0, 6
/* 113F3C 7F0DF40C AFB8028C */  sw    $t8, 0x28c($sp)
/* 113F40 7F0DF410 01395825 */  or    $t3, $t1, $t9
/* 113F44 7F0DF414 000E6900 */  sll   $t5, $t6, 4
/* 113F48 7F0DF418 2D4A0001 */  sltiu $t2, $t2, 1
/* 113F4C 7F0DF41C AFA80048 */  sw    $t0, 0x48($sp)
/* 113F50 7F0DF420 000A4080 */  sll   $t0, $t2, 2
/* 113F54 7F0DF424 016DC025 */  or    $t8, $t3, $t5
/* 113F58 7F0DF428 03086025 */  or    $t4, $t8, $t0
/* 113F5C 7F0DF42C 35890002 */  ori   $t1, $t4, 2
/* 113F60 7F0DF430 0010C82A */  slt   $t9, $zero, $s0
/* 113F64 7F0DF434 01398825 */  or    $s1, $t1, $t9
/* 113F68 7F0DF438 322F00FF */  andi  $t7, $s1, 0xff
/* 113F6C 7F0DF43C 10000CEF */  b     .L7F0E27FC
/* 113F70 7F0DF440 01E08825 */   move  $s1, $t7
spectrum_op_ED_55:
/* 113F74 7F0DF444 8FAE028C */  lw    $t6, 0x28c($sp)
/* 113F78 7F0DF448 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 113F7C 7F0DF44C 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 113F80 7F0DF450 97B80292 */  lhu   $t8, 0x292($sp)
/* 113F84 7F0DF454 25CB0004 */  addiu $t3, $t6, 4
/* 113F88 7F0DF458 AFAB028C */  sw    $t3, 0x28c($sp)
/* 113F8C 7F0DF45C 256A0006 */  addiu $t2, $t3, 6
/* 113F90 7F0DF460 AFAA028C */  sw    $t2, 0x28c($sp)
/* 113F94 7F0DF464 0118C821 */  addu  $t9, $t0, $t8
/* 113F98 7F0DF468 932F0001 */  lbu   $t7, 1($t9)
/* 113F9C 7F0DF46C 03086021 */  addu  $t4, $t8, $t0
/* 113FA0 7F0DF470 91890000 */  lbu   $t1, ($t4)
/* 113FA4 7F0DF474 000F7200 */  sll   $t6, $t7, 8
/* 113FA8 7F0DF478 270D0002 */  addiu $t5, $t8, 2
/* 113FAC 7F0DF47C 012E5825 */  or    $t3, $t1, $t6
/* 113FB0 7F0DF480 A7AB0298 */  sh    $t3, 0x298($sp)
/* 113FB4 7F0DF484 10000CDD */  b     .L7F0E27FC
/* 113FB8 7F0DF488 A7AD0292 */   sh    $t5, 0x292($sp)
spectrum_op_ED_56:
/* 113FBC 7F0DF48C 8FAA028C */  lw    $t2, 0x28c($sp)
/* 113FC0 7F0DF490 24080002 */  li    $t0, 2
/* 113FC4 7F0DF494 A3A8029B */  sb    $t0, 0x29b($sp)
/* 113FC8 7F0DF498 254C0004 */  addiu $t4, $t2, 4
/* 113FCC 7F0DF49C 10000CD7 */  b     .L7F0E27FC
/* 113FD0 7F0DF4A0 AFAC028C */   sw    $t4, 0x28c($sp)
spectrum_op_ED_57:
/* 113FD4 7F0DF4A4 93B0029E */  lbu   $s0, 0x29e($sp)
/* 113FD8 7F0DF4A8 8FB9028C */  lw    $t9, 0x28c($sp)
/* 113FDC 7F0DF4AC 93A8029C */  lbu   $t0, 0x29c($sp)
/* 113FE0 7F0DF4B0 322E0001 */  andi  $t6, $s1, 1
/* 113FE4 7F0DF4B4 2E090001 */  sltiu $t1, $s0, 1
/* 113FE8 7F0DF4B8 320B00A8 */  andi  $t3, $s0, 0xa8
/* 113FEC 7F0DF4BC 01CBC025 */  or    $t8, $t6, $t3
/* 113FF0 7F0DF4C0 00095180 */  sll   $t2, $t1, 6
/* 113FF4 7F0DF4C4 272F0005 */  addiu $t7, $t9, 5
/* 113FF8 7F0DF4C8 030A6025 */  or    $t4, $t8, $t2
/* 113FFC 7F0DF4CC 0008C880 */  sll   $t9, $t0, 2
/* 114000 7F0DF4D0 AFAF028C */  sw    $t7, 0x28c($sp)
/* 114004 7F0DF4D4 01998825 */  or    $s1, $t4, $t9
/* 114008 7F0DF4D8 322F00FF */  andi  $t7, $s1, 0xff
/* 11400C 7F0DF4DC 01E08825 */  move  $s1, $t7
/* 114010 7F0DF4E0 10000CC6 */  b     .L7F0E27FC
/* 114014 7F0DF4E4 AFA90048 */   sw    $t1, 0x48($sp)
spectrum_op_ED_58:
/* 114018 7F0DF4E8 8FA9028C */  lw    $t1, 0x28c($sp)
/* 11401C 7F0DF4EC 02402825 */  move  $a1, $s2
/* 114020 7F0DF4F0 02603025 */  move  $a2, $s3
/* 114024 7F0DF4F4 25240008 */  addiu $a0, $t1, 8
/* 114028 7F0DF4F8 0FC34DB6 */  jal   spectrum_input_handling
/* 11402C 7F0DF4FC AFA4028C */   sw    $a0, 0x28c($sp)
/* 114030 7F0DF500 8FAB028C */  lw    $t3, 0x28c($sp)
/* 114034 7F0DF504 304DFFFF */  andi  $t5, $v0, 0xffff
/* 114038 7F0DF508 000DC203 */  sra   $t8, $t5, 8
/* 11403C 7F0DF50C A7A200BC */  sh    $v0, 0xbc($sp)
/* 114040 7F0DF510 01785021 */  addu  $t2, $t3, $t8
/* 114044 7F0DF514 93B500BD */  lbu   $s5, 0xbd($sp)
/* 114048 7F0DF518 3C0B8009 */  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
/* 11404C 7F0DF51C 8D6BE334 */  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
/* 114050 7F0DF520 2EA80001 */  sltiu $t0, $s5, 1
/* 114054 7F0DF524 AFA80048 */  sw    $t0, 0x48($sp)
/* 114058 7F0DF528 AFAA028C */  sw    $t2, 0x28c($sp)
/* 11405C 7F0DF52C 02ABC021 */  addu  $t8, $s5, $t3
/* 114060 7F0DF530 930A0000 */  lbu   $t2, ($t8)
/* 114064 7F0DF534 322C0001 */  andi  $t4, $s1, 1
/* 114068 7F0DF538 32B900A8 */  andi  $t9, $s5, 0xa8
/* 11406C 7F0DF53C 01997825 */  or    $t7, $t4, $t9
/* 114070 7F0DF540 00087180 */  sll   $t6, $t0, 6
/* 114074 7F0DF544 01EE6825 */  or    $t5, $t7, $t6
/* 114078 7F0DF548 014D8825 */  or    $s1, $t2, $t5
/* 11407C 7F0DF54C 322800FF */  andi  $t0, $s1, 0xff
/* 114080 7F0DF550 10000CAA */  b     .L7F0E27FC
/* 114084 7F0DF554 01008825 */   move  $s1, $t0
spectrum_op_ED_59:
/* 114088 7F0DF558 8FAC028C */  lw    $t4, 0x28c($sp)
/* 11408C 7F0DF55C 02402825 */  move  $a1, $s2
/* 114090 7F0DF560 02603025 */  move  $a2, $s3
/* 114094 7F0DF564 25840008 */  addiu $a0, $t4, 8
/* 114098 7F0DF568 AFA4028C */  sw    $a0, 0x28c($sp)
/* 11409C 7F0DF56C 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 1140A0 7F0DF570 02A03825 */   move  $a3, $s5
/* 1140A4 7F0DF574 8FA9028C */  lw    $t1, 0x28c($sp)
/* 1140A8 7F0DF578 AFA20048 */  sw    $v0, 0x48($sp)
/* 1140AC 7F0DF57C 01227021 */  addu  $t6, $t1, $v0
/* 1140B0 7F0DF580 10000C9E */  b     .L7F0E27FC
/* 1140B4 7F0DF584 AFAE028C */   sw    $t6, 0x28c($sp)
spectrum_op_ED_5A:
/* 1140B8 7F0DF588 00145200 */  sll   $t2, $s4, 8
/* 1140BC 7F0DF58C 01556825 */  or    $t5, $t2, $s5
/* 1140C0 7F0DF590 00164200 */  sll   $t0, $s6, 8
/* 1140C4 7F0DF594 01176025 */  or    $t4, $t0, $s7
/* 1140C8 7F0DF598 31B9FFFF */  andi  $t9, $t5, 0xffff
/* 1140CC 7F0DF59C 8FAB028C */  lw    $t3, 0x28c($sp)
/* 1140D0 7F0DF5A0 01994821 */  addu  $t1, $t4, $t9
/* 1140D4 7F0DF5A4 322F0001 */  andi  $t7, $s1, 1
/* 1140D8 7F0DF5A8 012F7021 */  addu  $t6, $t1, $t7
/* 1140DC 7F0DF5AC 2578000B */  addiu $t8, $t3, 0xb
/* 1140E0 7F0DF5B0 000E5202 */  srl   $t2, $t6, 8
/* 1140E4 7F0DF5B4 AFB8028C */  sw    $t8, 0x28c($sp)
/* 1140E8 7F0DF5B8 314800A8 */  andi  $t0, $t2, 0xa8
/* 1140EC 7F0DF5BC 31CBFFFF */  andi  $t3, $t6, 0xffff
/* 1140F0 7F0DF5C0 000E6402 */  srl   $t4, $t6, 0x10
/* 1140F4 7F0DF5C4 00164A00 */  sll   $t1, $s6, 8
/* 1140F8 7F0DF5C8 01377825 */  or    $t7, $t1, $s7
/* 1140FC 7F0DF5CC 010CC825 */  or    $t9, $t0, $t4
/* 114100 7F0DF5D0 2D780001 */  sltiu $t8, $t3, 1
/* 114104 7F0DF5D4 31EB0FFF */  andi  $t3, $t7, 0xfff
/* 114108 7F0DF5D8 31A80FFF */  andi  $t0, $t5, 0xfff
/* 11410C 7F0DF5DC 01686021 */  addu  $t4, $t3, $t0
/* 114110 7F0DF5E0 32290001 */  andi  $t1, $s1, 1
/* 114114 7F0DF5E4 01897821 */  addu  $t7, $t4, $t1
/* 114118 7F0DF5E8 24010FFF */  li    $at, 4095
/* 11411C 7F0DF5EC 002F502A */  slt   $t2, $at, $t7
/* 114120 7F0DF5F0 000A5900 */  sll   $t3, $t2, 4
/* 114124 7F0DF5F4 032B4025 */  or    $t0, $t9, $t3
/* 114128 7F0DF5F8 00166200 */  sll   $t4, $s6, 8
/* 11412C 7F0DF5FC 01974825 */  or    $t1, $t4, $s7
/* 114130 7F0DF600 00165200 */  sll   $t2, $s6, 8
/* 114134 7F0DF604 0157C827 */  nor   $t9, $t2, $s7
/* 114138 7F0DF608 01A05825 */  move  $t3, $t5
/* 11413C 7F0DF60C 032B6026 */  xor   $t4, $t9, $t3
/* 114140 7F0DF610 012E7826 */  xor   $t7, $t1, $t6
/* 114144 7F0DF614 018F4824 */  and   $t1, $t4, $t7
/* 114148 7F0DF618 312A8000 */  andi  $t2, $t1, 0x8000
/* 11414C 7F0DF61C A7AD00BA */  sh    $t5, 0xba($sp)
/* 114150 7F0DF620 000A6B42 */  srl   $t5, $t2, 0xd
/* 114154 7F0DF624 010DC825 */  or    $t9, $t0, $t5
/* 114158 7F0DF628 00185980 */  sll   $t3, $t8, 6
/* 11415C 7F0DF62C 032B8825 */  or    $s1, $t9, $t3
/* 114160 7F0DF630 000EB202 */  srl   $s6, $t6, 8
/* 114164 7F0DF634 32C900FF */  andi  $t1, $s6, 0xff
/* 114168 7F0DF638 362C0002 */  ori   $t4, $s1, 2
/* 11416C 7F0DF63C AFAE00B4 */  sw    $t6, 0xb4($sp)
/* 114170 7F0DF640 93B700B7 */  lbu   $s7, 0xb7($sp)
/* 114174 7F0DF644 319100FF */  andi  $s1, $t4, 0xff
/* 114178 7F0DF648 0120B025 */  move  $s6, $t1
/* 11417C 7F0DF64C 10000C6B */  b     .L7F0E27FC
/* 114180 7F0DF650 AFB80048 */   sw    $t8, 0x48($sp)
spectrum_op_ED_5B:
/* 114184 7F0DF654 8FAA028C */  lw    $t2, 0x28c($sp)
/* 114188 7F0DF658 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 11418C 7F0DF65C 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 114190 7F0DF660 97AD0298 */  lhu   $t5, 0x298($sp)
/* 114194 7F0DF664 25480010 */  addiu $t0, $t2, 0x10
/* 114198 7F0DF668 AFA8028C */  sw    $t0, 0x28c($sp)
/* 11419C 7F0DF66C 030D6021 */  addu  $t4, $t8, $t5
/* 1141A0 7F0DF670 918F0001 */  lbu   $t7, 1($t4)
/* 1141A4 7F0DF674 01B8C821 */  addu  $t9, $t5, $t8
/* 1141A8 7F0DF678 932B0000 */  lbu   $t3, ($t9)
/* 1141AC 7F0DF67C 000F7200 */  sll   $t6, $t7, 8
/* 1141B0 7F0DF680 25AA0002 */  addiu $t2, $t5, 2
/* 1141B4 7F0DF684 016E4825 */  or    $t1, $t3, $t6
/* 1141B8 7F0DF688 3128FFFF */  andi  $t0, $t1, 0xffff
/* 1141BC 7F0DF68C A7A900B2 */  sh    $t1, 0xb2($sp)
/* 1141C0 7F0DF690 A7AA0298 */  sh    $t2, 0x298($sp)
/* 1141C4 7F0DF694 0118C821 */  addu  $t9, $t0, $t8
/* 1141C8 7F0DF698 93350000 */  lbu   $s5, ($t9)
/* 1141CC 7F0DF69C 10000C57 */  b     .L7F0E27FC
/* 1141D0 7F0DF6A0 93340001 */   lbu   $s4, 1($t9)
spectrum_op_ED_5C:
/* 1141D4 7F0DF6A4 00108023 */  negu  $s0, $s0
/* 1141D8 7F0DF6A8 320B00FF */  andi  $t3, $s0, 0xff
/* 1141DC 7F0DF6AC 8FAC028C */  lw    $t4, 0x28c($sp)
/* 1141E0 7F0DF6B0 2D6E0001 */  sltiu $t6, $t3, 1
/* 1141E4 7F0DF6B4 3178000F */  andi  $t8, $t3, 0xf
/* 1141E8 7F0DF6B8 01608025 */  move  $s0, $t3
/* 1141EC 7F0DF6BC 316900A8 */  andi  $t1, $t3, 0xa8
/* 1141F0 7F0DF6C0 258F0004 */  addiu $t7, $t4, 4
/* 1141F4 7F0DF6C4 396B0080 */  xori  $t3, $t3, 0x80
/* 1141F8 7F0DF6C8 0018C82A */  slt   $t9, $zero, $t8
/* 1141FC 7F0DF6CC 000E5180 */  sll   $t2, $t6, 6
/* 114200 7F0DF6D0 AFAF028C */  sw    $t7, 0x28c($sp)
/* 114204 7F0DF6D4 012A4025 */  or    $t0, $t1, $t2
/* 114208 7F0DF6D8 00196100 */  sll   $t4, $t9, 4
/* 11420C 7F0DF6DC 2D6B0001 */  sltiu $t3, $t3, 1
/* 114210 7F0DF6E0 AFAE0048 */  sw    $t6, 0x48($sp)
/* 114214 7F0DF6E4 000B7080 */  sll   $t6, $t3, 2
/* 114218 7F0DF6E8 010C7825 */  or    $t7, $t0, $t4
/* 11421C 7F0DF6EC 01EE6825 */  or    $t5, $t7, $t6
/* 114220 7F0DF6F0 35A90002 */  ori   $t1, $t5, 2
/* 114224 7F0DF6F4 0010502A */  slt   $t2, $zero, $s0
/* 114228 7F0DF6F8 012A8825 */  or    $s1, $t1, $t2
/* 11422C 7F0DF6FC 323800FF */  andi  $t8, $s1, 0xff
/* 114230 7F0DF700 10000C3E */  b     .L7F0E27FC
/* 114234 7F0DF704 03008825 */   move  $s1, $t8
spectrum_op_ED_5D:
/* 114238 7F0DF708 8FB9028C */  lw    $t9, 0x28c($sp)
/* 11423C 7F0DF70C 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 114240 7F0DF710 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 114244 7F0DF714 97AF0292 */  lhu   $t7, 0x292($sp)
/* 114248 7F0DF718 27280004 */  addiu $t0, $t9, 4
/* 11424C 7F0DF71C AFA8028C */  sw    $t0, 0x28c($sp)
/* 114250 7F0DF720 250B0006 */  addiu $t3, $t0, 6
/* 114254 7F0DF724 AFAB028C */  sw    $t3, 0x28c($sp)
/* 114258 7F0DF728 01CF5021 */  addu  $t2, $t6, $t7
/* 11425C 7F0DF72C 91580001 */  lbu   $t8, 1($t2)
/* 114260 7F0DF730 01EE6821 */  addu  $t5, $t7, $t6
/* 114264 7F0DF734 91A90000 */  lbu   $t1, ($t5)
/* 114268 7F0DF738 0018CA00 */  sll   $t9, $t8, 8
/* 11426C 7F0DF73C 25EC0002 */  addiu $t4, $t7, 2
/* 114270 7F0DF740 01394025 */  or    $t0, $t1, $t9
/* 114274 7F0DF744 A7A80298 */  sh    $t0, 0x298($sp)
/* 114278 7F0DF748 10000C2C */  b     .L7F0E27FC
/* 11427C 7F0DF74C A7AC0292 */   sh    $t4, 0x292($sp)
spectrum_op_ED_5E:
/* 114280 7F0DF750 8FAB028C */  lw    $t3, 0x28c($sp)
/* 114284 7F0DF754 240E0003 */  li    $t6, 3
/* 114288 7F0DF758 A3AE029B */  sb    $t6, 0x29b($sp)
/* 11428C 7F0DF75C 256D0004 */  addiu $t5, $t3, 4
/* 114290 7F0DF760 10000C26 */  b     .L7F0E27FC
/* 114294 7F0DF764 AFAD028C */   sw    $t5, 0x28c($sp)
spectrum_op_ED_5F:
/* 114298 7F0DF768 93A902A7 */  lbu   $t1, 0x2a7($sp)
/* 11429C 7F0DF76C 8FA80288 */  lw    $t0, 0x288($sp)
/* 1142A0 7F0DF770 8FAA028C */  lw    $t2, 0x28c($sp)
/* 1142A4 7F0DF774 31390080 */  andi  $t9, $t1, 0x80
/* 1142A8 7F0DF778 310F007F */  andi  $t7, $t0, 0x7f
/* 1142AC 7F0DF77C 032F8025 */  or    $s0, $t9, $t7
/* 1142B0 7F0DF780 320B00FF */  andi  $t3, $s0, 0xff
/* 1142B4 7F0DF784 25580005 */  addiu $t8, $t2, 5
/* 1142B8 7F0DF788 93AF029C */  lbu   $t7, 0x29c($sp)
/* 1142BC 7F0DF78C AFB8028C */  sw    $t8, 0x28c($sp)
/* 1142C0 7F0DF790 316A00A8 */  andi  $t2, $t3, 0xa8
/* 1142C4 7F0DF794 2D6D0001 */  sltiu $t5, $t3, 1
/* 1142C8 7F0DF798 322E0001 */  andi  $t6, $s1, 1
/* 1142CC 7F0DF79C 01CAC025 */  or    $t8, $t6, $t2
/* 1142D0 7F0DF7A0 000D4180 */  sll   $t0, $t5, 6
/* 1142D4 7F0DF7A4 A3B002A7 */  sb    $s0, 0x2a7($sp)
/* 1142D8 7F0DF7A8 0308C825 */  or    $t9, $t8, $t0
/* 1142DC 7F0DF7AC 000F6080 */  sll   $t4, $t7, 2
/* 1142E0 7F0DF7B0 01608025 */  move  $s0, $t3
/* 1142E4 7F0DF7B4 032C8825 */  or    $s1, $t9, $t4
/* 1142E8 7F0DF7B8 322B00FF */  andi  $t3, $s1, 0xff
/* 1142EC 7F0DF7BC 01608825 */  move  $s1, $t3
/* 1142F0 7F0DF7C0 10000C0E */  b     .L7F0E27FC
/* 1142F4 7F0DF7C4 AFAD0048 */   sw    $t5, 0x48($sp)
spectrum_op_ED_60:
/* 1142F8 7F0DF7C8 8FAD028C */  lw    $t5, 0x28c($sp)
/* 1142FC 7F0DF7CC 02402825 */  move  $a1, $s2
/* 114300 7F0DF7D0 02603025 */  move  $a2, $s3
/* 114304 7F0DF7D4 25A40008 */  addiu $a0, $t5, 8
/* 114308 7F0DF7D8 0FC34DB6 */  jal   spectrum_input_handling
/* 11430C 7F0DF7DC AFA4028C */   sw    $a0, 0x28c($sp)
/* 114310 7F0DF7E0 8FAA028C */  lw    $t2, 0x28c($sp)
/* 114314 7F0DF7E4 3049FFFF */  andi  $t1, $v0, 0xffff
/* 114318 7F0DF7E8 0009C203 */  sra   $t8, $t1, 8
/* 11431C 7F0DF7EC A7A200B0 */  sh    $v0, 0xb0($sp)
/* 114320 7F0DF7F0 01584021 */  addu  $t0, $t2, $t8
/* 114324 7F0DF7F4 93B600B1 */  lbu   $s6, 0xb1($sp)
/* 114328 7F0DF7F8 3C0A8009 */  lui   $t2, %hi(ptr_pc_keyboard_table_alloc) 
/* 11432C 7F0DF7FC 8D4AE334 */  lw    $t2, %lo(ptr_pc_keyboard_table_alloc)($t2)
/* 114330 7F0DF800 2ECF0001 */  sltiu $t7, $s6, 1
/* 114334 7F0DF804 AFAF0048 */  sw    $t7, 0x48($sp)
/* 114338 7F0DF808 AFA8028C */  sw    $t0, 0x28c($sp)
/* 11433C 7F0DF80C 02CAC021 */  addu  $t8, $s6, $t2
/* 114340 7F0DF810 93080000 */  lbu   $t0, ($t8)
/* 114344 7F0DF814 32390001 */  andi  $t9, $s1, 1
/* 114348 7F0DF818 32CC00A8 */  andi  $t4, $s6, 0xa8
/* 11434C 7F0DF81C 032C5825 */  or    $t3, $t9, $t4
/* 114350 7F0DF820 000F7180 */  sll   $t6, $t7, 6
/* 114354 7F0DF824 016E4825 */  or    $t1, $t3, $t6
/* 114358 7F0DF828 01098825 */  or    $s1, $t0, $t1
/* 11435C 7F0DF82C 322F00FF */  andi  $t7, $s1, 0xff
/* 114360 7F0DF830 10000BF2 */  b     .L7F0E27FC
/* 114364 7F0DF834 01E08825 */   move  $s1, $t7
spectrum_op_ED_61:
/* 114368 7F0DF838 8FB9028C */  lw    $t9, 0x28c($sp)
/* 11436C 7F0DF83C 02402825 */  move  $a1, $s2
/* 114370 7F0DF840 02603025 */  move  $a2, $s3
/* 114374 7F0DF844 27240008 */  addiu $a0, $t9, 8
/* 114378 7F0DF848 AFA4028C */  sw    $a0, 0x28c($sp)
/* 11437C 7F0DF84C 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 114380 7F0DF850 02C03825 */   move  $a3, $s6
/* 114384 7F0DF854 8FAD028C */  lw    $t5, 0x28c($sp)
/* 114388 7F0DF858 AFA20048 */  sw    $v0, 0x48($sp)
/* 11438C 7F0DF85C 01A27021 */  addu  $t6, $t5, $v0
/* 114390 7F0DF860 10000BE6 */  b     .L7F0E27FC
/* 114394 7F0DF864 AFAE028C */   sw    $t6, 0x28c($sp)
spectrum_op_ED_62:
/* 114398 7F0DF868 00164200 */  sll   $t0, $s6, 8
/* 11439C 7F0DF86C 8FAA028C */  lw    $t2, 0x28c($sp)
/* 1143A0 7F0DF870 01174825 */  or    $t1, $t0, $s7
/* 1143A4 7F0DF874 00167A00 */  sll   $t7, $s6, 8
/* 1143A8 7F0DF878 01F7C825 */  or    $t9, $t7, $s7
/* 1143AC 7F0DF87C 312CFFFF */  andi  $t4, $t1, 0xffff
/* 1143B0 7F0DF880 032C6823 */  subu  $t5, $t9, $t4
/* 1143B4 7F0DF884 322B0001 */  andi  $t3, $s1, 1
/* 1143B8 7F0DF888 3C010001 */  lui   $at, (0x0001FFFF >> 16) # lui $at, 1
/* 1143BC 7F0DF88C 3421FFFF */  ori   $at, (0x0001FFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 1143C0 7F0DF890 01AB7023 */  subu  $t6, $t5, $t3
/* 1143C4 7F0DF894 2558000B */  addiu $t8, $t2, 0xb
/* 1143C8 7F0DF898 01C15024 */  and   $t2, $t6, $at
/* 1143CC 7F0DF89C 000A7A02 */  srl   $t7, $t2, 8
/* 1143D0 7F0DF8A0 31F900A8 */  andi  $t9, $t7, 0xa8
/* 1143D4 7F0DF8A4 000A6402 */  srl   $t4, $t2, 0x10
/* 1143D8 7F0DF8A8 AFB8028C */  sw    $t8, 0x28c($sp)
/* 1143DC 7F0DF8AC 032C6825 */  or    $t5, $t9, $t4
/* 1143E0 7F0DF8B0 3158FFFF */  andi  $t8, $t2, 0xffff
/* 1143E4 7F0DF8B4 2F080001 */  sltiu $t0, $t8, 1
/* 1143E8 7F0DF8B8 35AB0002 */  ori   $t3, $t5, 2
/* 1143EC 7F0DF8BC 00166200 */  sll   $t4, $s6, 8
/* 1143F0 7F0DF8C0 01976825 */  or    $t5, $t4, $s7
/* 1143F4 7F0DF8C4 31380FFF */  andi  $t8, $t1, 0xfff
/* 1143F8 7F0DF8C8 322F0001 */  andi  $t7, $s1, 1
/* 1143FC 7F0DF8CC 030FC821 */  addu  $t9, $t8, $t7
/* 114400 7F0DF8D0 31AE0FFF */  andi  $t6, $t5, 0xfff
/* 114404 7F0DF8D4 01D9C02A */  slt   $t8, $t6, $t9
/* 114408 7F0DF8D8 00187900 */  sll   $t7, $t8, 4
/* 11440C 7F0DF8DC 016F6025 */  or    $t4, $t3, $t7
/* 114410 7F0DF8E0 00166A00 */  sll   $t5, $s6, 8
/* 114414 7F0DF8E4 01B77025 */  or    $t6, $t5, $s7
/* 114418 7F0DF8E8 0016C200 */  sll   $t8, $s6, 8
/* 11441C 7F0DF8EC 03175825 */  or    $t3, $t8, $s7
/* 114420 7F0DF8F0 01207825 */  move  $t7, $t1
/* 114424 7F0DF8F4 016F6826 */  xor   $t5, $t3, $t7
/* 114428 7F0DF8F8 01CAC826 */  xor   $t9, $t6, $t2
/* 11442C 7F0DF8FC 01B97024 */  and   $t6, $t5, $t9
/* 114430 7F0DF900 31D88000 */  andi  $t8, $t6, 0x8000
/* 114434 7F0DF904 A7A900AE */  sh    $t1, 0xae($sp)
/* 114438 7F0DF908 00184B42 */  srl   $t1, $t8, 0xd
/* 11443C 7F0DF90C 01895825 */  or    $t3, $t4, $t1
/* 114440 7F0DF910 00087980 */  sll   $t7, $t0, 6
/* 114444 7F0DF914 016F8825 */  or    $s1, $t3, $t7
/* 114448 7F0DF918 000AB202 */  srl   $s6, $t2, 8
/* 11444C 7F0DF91C 32CE00FF */  andi  $t6, $s6, 0xff
/* 114450 7F0DF920 362D0002 */  ori   $t5, $s1, 2
/* 114454 7F0DF924 AFAA00A8 */  sw    $t2, 0xa8($sp)
/* 114458 7F0DF928 93B700AB */  lbu   $s7, 0xab($sp)
/* 11445C 7F0DF92C 31B100FF */  andi  $s1, $t5, 0xff
/* 114460 7F0DF930 01C0B025 */  move  $s6, $t6
/* 114464 7F0DF934 10000BB1 */  b     .L7F0E27FC
/* 114468 7F0DF938 AFA80048 */   sw    $t0, 0x48($sp)
spectrum_op_ED_63:
/* 11446C 7F0DF93C 8FB8028C */  lw    $t8, 0x28c($sp)
/* 114470 7F0DF940 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 114474 7F0DF944 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 114478 7F0DF948 97A90298 */  lhu   $t1, 0x298($sp)
/* 11447C 7F0DF94C 270C0010 */  addiu $t4, $t8, 0x10
/* 114480 7F0DF950 AFAC028C */  sw    $t4, 0x28c($sp)
/* 114484 7F0DF954 01096821 */  addu  $t5, $t0, $t1
/* 114488 7F0DF958 91B90001 */  lbu   $t9, 1($t5)
/* 11448C 7F0DF95C 01285821 */  addu  $t3, $t1, $t0
/* 114490 7F0DF960 916F0000 */  lbu   $t7, ($t3)
/* 114494 7F0DF964 00195200 */  sll   $t2, $t9, 8
/* 114498 7F0DF968 25380002 */  addiu $t8, $t1, 2
/* 11449C 7F0DF96C 01EA7025 */  or    $t6, $t7, $t2
/* 1144A0 7F0DF970 31CCFFFF */  andi  $t4, $t6, 0xffff
/* 1144A4 7F0DF974 29815B00 */  slti  $at, $t4, 0x5b00
/* 1144A8 7F0DF978 A7AE00A6 */  sh    $t6, 0xa6($sp)
/* 1144AC 7F0DF97C 14200006 */  bnez  $at, .L7F0DF998
/* 1144B0 7F0DF980 A7B80298 */   sh    $t8, 0x298($sp)
/* 1144B4 7F0DF984 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 1144B8 7F0DF988 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 1144BC 7F0DF98C 016C4021 */  addu  $t0, $t3, $t4
/* 1144C0 7F0DF990 10000021 */  b     .L7F0DFA18
/* 1144C4 7F0DF994 A1170000 */   sb    $s7, ($t0)
.L7F0DF998:
/* 1144C8 7F0DF998 97AD00A6 */  lhu   $t5, 0xa6($sp)
/* 1144CC 7F0DF99C 97AB00A6 */  lhu   $t3, 0xa6($sp)
/* 1144D0 7F0DF9A0 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 1144D4 7F0DF9A4 29A15800 */  slti  $at, $t5, 0x5800
/* 1144D8 7F0DF9A8 5420000C */  bnezl $at, .L7F0DF9DC
/* 1144DC 7F0DF9AC 29614000 */   slti  $at, $t3, 0x4000
/* 1144E0 7F0DF9B0 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 1144E4 7F0DF9B4 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 1144E8 7F0DF9B8 240A0001 */  li    $t2, 1
/* 1144EC 7F0DF9BC 032D7821 */  addu  $t7, $t9, $t5
/* 1144F0 7F0DF9C0 A1F70000 */  sb    $s7, ($t7)
/* 1144F4 7F0DF9C4 97A900A6 */  lhu   $t1, 0xa6($sp)
/* 1144F8 7F0DF9C8 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 1144FC 7F0DF9CC 01C9C021 */  addu  $t8, $t6, $t1
/* 114500 7F0DF9D0 10000011 */  b     .L7F0DFA18
/* 114504 7F0DF9D4 A30AA800 */   sb    $t2, -0x5800($t8)
/* 114508 7F0DF9D8 29614000 */  slti  $at, $t3, 0x4000
.L7F0DF9DC:
/* 11450C 7F0DF9DC 1420000E */  bnez  $at, .L7F0DFA18
/* 114510 7F0DF9E0 3C0C8009 */   lui   $t4, %hi(ptr_spectrum_roms) 
/* 114514 7F0DF9E4 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 114518 7F0DF9E8 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 11451C 7F0DF9EC 24190001 */  li    $t9, 1
/* 114520 7F0DF9F0 018B4021 */  addu  $t0, $t4, $t3
/* 114524 7F0DF9F4 A1170000 */  sb    $s7, ($t0)
/* 114528 7F0DF9F8 97AD00A6 */  lhu   $t5, 0xa6($sp)
/* 11452C 7F0DF9FC 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 114530 7F0DFA00 31AF1800 */  andi  $t7, $t5, 0x1800
/* 114534 7F0DFA04 000F70C3 */  sra   $t6, $t7, 3
/* 114538 7F0DFA08 31A900FF */  andi  $t1, $t5, 0xff
/* 11453C 7F0DFA0C 01C95025 */  or    $t2, $t6, $t1
/* 114540 7F0DFA10 030A6021 */  addu  $t4, $t8, $t2
/* 114544 7F0DFA14 A1990000 */  sb    $t9, ($t4)
.L7F0DFA18:
/* 114548 7F0DFA18 97AB00A6 */  lhu   $t3, 0xa6($sp)
/* 11454C 7F0DFA1C 97AE00A6 */  lhu   $t6, 0xa6($sp)
/* 114550 7F0DFA20 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 114554 7F0DFA24 25680001 */  addiu $t0, $t3, 1
/* 114558 7F0DFA28 29015B00 */  slti  $at, $t0, 0x5b00
/* 11455C 7F0DFA2C 14200005 */  bnez  $at, .L7F0DFA44
/* 114560 7F0DFA30 25C90001 */   addiu $t1, $t6, 1
/* 114564 7F0DFA34 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 114568 7F0DFA38 01EB6821 */  addu  $t5, $t7, $t3
/* 11456C 7F0DFA3C 10000B6F */  b     .L7F0E27FC
/* 114570 7F0DFA40 A1B60001 */   sb    $s6, 1($t5)
.L7F0DFA44:
/* 114574 7F0DFA44 29215800 */  slti  $at, $t1, 0x5800
/* 114578 7F0DFA48 1420000C */  bnez  $at, .L7F0DFA7C
/* 11457C 7F0DFA4C 97AB00A6 */   lhu   $t3, 0xa6($sp)
/* 114580 7F0DFA50 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 114584 7F0DFA54 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 114588 7F0DFA58 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 11458C 7F0DFA5C 24190001 */  li    $t9, 1
/* 114590 7F0DFA60 030E5021 */  addu  $t2, $t8, $t6
/* 114594 7F0DFA64 A1560001 */  sb    $s6, 1($t2)
/* 114598 7F0DFA68 97A800A6 */  lhu   $t0, 0xa6($sp)
/* 11459C 7F0DFA6C 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 1145A0 7F0DFA70 01887821 */  addu  $t7, $t4, $t0
/* 1145A4 7F0DFA74 10000B61 */  b     .L7F0E27FC
/* 1145A8 7F0DFA78 A1F9A801 */   sb    $t9, -0x57ff($t7)
.L7F0DFA7C:
/* 1145AC 7F0DFA7C 256D0001 */  addiu $t5, $t3, 1
/* 1145B0 7F0DFA80 29A14000 */  slti  $at, $t5, 0x4000
/* 1145B4 7F0DFA84 14200B5D */  bnez  $at, .L7F0E27FC
/* 1145B8 7F0DFA88 3C098009 */   lui   $t1, %hi(ptr_spectrum_roms) 
/* 1145BC 7F0DFA8C 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 1145C0 7F0DFA90 240E0001 */  li    $t6, 1
/* 1145C4 7F0DFA94 012BC021 */  addu  $t8, $t1, $t3
/* 1145C8 7F0DFA98 A3160001 */  sb    $s6, 1($t8)
/* 1145CC 7F0DFA9C 97AA00A6 */  lhu   $t2, 0xa6($sp)
/* 1145D0 7F0DFAA0 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 1145D4 7F0DFAA4 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 1145D8 7F0DFAA8 254C0001 */  addiu $t4, $t2, 1
/* 1145DC 7F0DFAAC 31881800 */  andi  $t0, $t4, 0x1800
/* 1145E0 7F0DFAB0 0008C8C3 */  sra   $t9, $t0, 3
/* 1145E4 7F0DFAB4 318F00FF */  andi  $t7, $t4, 0xff
/* 1145E8 7F0DFAB8 032F6825 */  or    $t5, $t9, $t7
/* 1145EC 7F0DFABC 012D5821 */  addu  $t3, $t1, $t5
/* 1145F0 7F0DFAC0 10000B4E */  b     .L7F0E27FC
/* 1145F4 7F0DFAC4 A16E0000 */   sb    $t6, ($t3)
spectrum_op_ED_64:
/* 1145F8 7F0DFAC8 00108023 */  negu  $s0, $s0
/* 1145FC 7F0DFACC 320800FF */  andi  $t0, $s0, 0xff
/* 114600 7F0DFAD0 8FB8028C */  lw    $t8, 0x28c($sp)
/* 114604 7F0DFAD4 2D0C0001 */  sltiu $t4, $t0, 1
/* 114608 7F0DFAD8 310E000F */  andi  $t6, $t0, 0xf
/* 11460C 7F0DFADC 01008025 */  move  $s0, $t0
/* 114610 7F0DFAE0 311900A8 */  andi  $t9, $t0, 0xa8
/* 114614 7F0DFAE4 270A0004 */  addiu $t2, $t8, 4
/* 114618 7F0DFAE8 39080080 */  xori  $t0, $t0, 0x80
/* 11461C 7F0DFAEC 000E582A */  slt   $t3, $zero, $t6
/* 114620 7F0DFAF0 000C4980 */  sll   $t1, $t4, 6
/* 114624 7F0DFAF4 AFAA028C */  sw    $t2, 0x28c($sp)
/* 114628 7F0DFAF8 03296825 */  or    $t5, $t9, $t1
/* 11462C 7F0DFAFC 000BC100 */  sll   $t8, $t3, 4
/* 114630 7F0DFB00 2D080001 */  sltiu $t0, $t0, 1
/* 114634 7F0DFB04 AFAC0048 */  sw    $t4, 0x48($sp)
/* 114638 7F0DFB08 00086080 */  sll   $t4, $t0, 2
/* 11463C 7F0DFB0C 01B85025 */  or    $t2, $t5, $t8
/* 114640 7F0DFB10 014C7825 */  or    $t7, $t2, $t4
/* 114644 7F0DFB14 35F90002 */  ori   $t9, $t7, 2
/* 114648 7F0DFB18 0010482A */  slt   $t1, $zero, $s0
/* 11464C 7F0DFB1C 03298825 */  or    $s1, $t9, $t1
/* 114650 7F0DFB20 322E00FF */  andi  $t6, $s1, 0xff
/* 114654 7F0DFB24 10000B35 */  b     .L7F0E27FC
/* 114658 7F0DFB28 01C08825 */   move  $s1, $t6
spectrum_op_ED_65:
/* 11465C 7F0DFB2C 8FAB028C */  lw    $t3, 0x28c($sp)
/* 114660 7F0DFB30 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 114664 7F0DFB34 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 114668 7F0DFB38 97AA0292 */  lhu   $t2, 0x292($sp)
/* 11466C 7F0DFB3C 256D0004 */  addiu $t5, $t3, 4
/* 114670 7F0DFB40 AFAD028C */  sw    $t5, 0x28c($sp)
/* 114674 7F0DFB44 25A80006 */  addiu $t0, $t5, 6
/* 114678 7F0DFB48 AFA8028C */  sw    $t0, 0x28c($sp)
/* 11467C 7F0DFB4C 018A4821 */  addu  $t1, $t4, $t2
/* 114680 7F0DFB50 912E0001 */  lbu   $t6, 1($t1)
/* 114684 7F0DFB54 014C7821 */  addu  $t7, $t2, $t4
/* 114688 7F0DFB58 91F90000 */  lbu   $t9, ($t7)
/* 11468C 7F0DFB5C 000E5A00 */  sll   $t3, $t6, 8
/* 114690 7F0DFB60 25580002 */  addiu $t8, $t2, 2
/* 114694 7F0DFB64 032B6825 */  or    $t5, $t9, $t3
/* 114698 7F0DFB68 A7AD0298 */  sh    $t5, 0x298($sp)
/* 11469C 7F0DFB6C 10000B23 */  b     .L7F0E27FC
/* 1146A0 7F0DFB70 A7B80292 */   sh    $t8, 0x292($sp)
spectrum_op_ED_66:
/* 1146A4 7F0DFB74 8FA8028C */  lw    $t0, 0x28c($sp)
/* 1146A8 7F0DFB78 A3A0029B */  sb    $zero, 0x29b($sp)
/* 1146AC 7F0DFB7C 250F0004 */  addiu $t7, $t0, 4
/* 1146B0 7F0DFB80 10000B1E */  b     .L7F0E27FC
/* 1146B4 7F0DFB84 AFAF028C */   sw    $t7, 0x28c($sp)
spectrum_op_ED_67:
/* 1146B8 7F0DFB88 8FAC028C */  lw    $t4, 0x28c($sp)
/* 1146BC 7F0DFB8C 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 1146C0 7F0DFB90 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 1146C4 7F0DFB94 00167200 */  sll   $t6, $s6, 8
/* 1146C8 7F0DFB98 01D7C825 */  or    $t9, $t6, $s7
/* 1146CC 7F0DFB9C 2589000E */  addiu $t1, $t4, 0xe
/* 1146D0 7F0DFBA0 AFA9028C */  sw    $t1, 0x28c($sp)
/* 1146D4 7F0DFBA4 032B6821 */  addu  $t5, $t9, $t3
/* 1146D8 7F0DFBA8 91AA0000 */  lbu   $t2, ($t5)
/* 1146DC 7F0DFBAC 00104100 */  sll   $t0, $s0, 4
/* 1146E0 7F0DFBB0 320900F0 */  andi  $t1, $s0, 0xf0
/* 1146E4 7F0DFBB4 0016CA00 */  sll   $t9, $s6, 8
/* 1146E8 7F0DFBB8 314C000F */  andi  $t4, $t2, 0xf
/* 1146EC 7F0DFBBC 012C8025 */  or    $s0, $t1, $t4
/* 1146F0 7F0DFBC0 03375825 */  or    $t3, $t9, $s7
/* 1146F4 7F0DFBC4 000AC103 */  sra   $t8, $t2, 4
/* 1146F8 7F0DFBC8 01187825 */  or    $t7, $t0, $t8
/* 1146FC 7F0DFBCC 320E00FF */  andi  $t6, $s0, 0xff
/* 114700 7F0DFBD0 29615B00 */  slti  $at, $t3, 0x5b00
/* 114704 7F0DFBD4 A3AF00A4 */  sb    $t7, 0xa4($sp)
/* 114708 7F0DFBD8 01C08025 */  move  $s0, $t6
/* 11470C 7F0DFBDC 14200009 */  bnez  $at, .L7F0DFC04
/* 114710 7F0DFBE0 A3AA00A5 */   sb    $t2, 0xa5($sp)
/* 114714 7F0DFBE4 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 114718 7F0DFBE8 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 11471C 7F0DFBEC 01E06825 */  move  $t5, $t7
/* 114720 7F0DFBF0 0016C200 */  sll   $t8, $s6, 8
/* 114724 7F0DFBF4 03177825 */  or    $t7, $t8, $s7
/* 114728 7F0DFBF8 010F5021 */  addu  $t2, $t0, $t7
/* 11472C 7F0DFBFC 1000002B */  b     .L7F0DFCAC
/* 114730 7F0DFC00 A14D0000 */   sb    $t5, ($t2)
.L7F0DFC04:
/* 114734 7F0DFC04 00164A00 */  sll   $t1, $s6, 8
/* 114738 7F0DFC08 01376025 */  or    $t4, $t1, $s7
/* 11473C 7F0DFC0C 29815800 */  slti  $at, $t4, 0x5800
/* 114740 7F0DFC10 14200010 */  bnez  $at, .L7F0DFC54
/* 114744 7F0DFC14 00165A00 */   sll   $t3, $s6, 8
/* 114748 7F0DFC18 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 11474C 7F0DFC1C 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 114750 7F0DFC20 93AE00A4 */  lbu   $t6, 0xa4($sp)
/* 114754 7F0DFC24 00165A00 */  sll   $t3, $s6, 8
/* 114758 7F0DFC28 0177C025 */  or    $t8, $t3, $s7
/* 11475C 7F0DFC2C 03384021 */  addu  $t0, $t9, $t8
/* 114760 7F0DFC30 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 114764 7F0DFC34 A10E0000 */  sb    $t6, ($t0)
/* 114768 7F0DFC38 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 11476C 7F0DFC3C 00165200 */  sll   $t2, $s6, 8
/* 114770 7F0DFC40 01574825 */  or    $t1, $t2, $s7
/* 114774 7F0DFC44 240F0001 */  li    $t7, 1
/* 114778 7F0DFC48 01A96021 */  addu  $t4, $t5, $t1
/* 11477C 7F0DFC4C 10000017 */  b     .L7F0DFCAC
/* 114780 7F0DFC50 A18FA800 */   sb    $t7, -0x5800($t4)
.L7F0DFC54:
/* 114784 7F0DFC54 0177C825 */  or    $t9, $t3, $s7
/* 114788 7F0DFC58 2B214000 */  slti  $at, $t9, 0x4000
/* 11478C 7F0DFC5C 14200013 */  bnez  $at, .L7F0DFCAC
/* 114790 7F0DFC60 93B800A4 */   lbu   $t8, 0xa4($sp)
/* 114794 7F0DFC64 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 114798 7F0DFC68 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 11479C 7F0DFC6C 00164200 */  sll   $t0, $s6, 8
/* 1147A0 7F0DFC70 01175025 */  or    $t2, $t0, $s7
/* 1147A4 7F0DFC74 01CA6821 */  addu  $t5, $t6, $t2
/* 1147A8 7F0DFC78 A1B80000 */  sb    $t8, ($t5)
/* 1147AC 7F0DFC7C 00167A00 */  sll   $t7, $s6, 8
/* 1147B0 7F0DFC80 01F76025 */  or    $t4, $t7, $s7
/* 1147B4 7F0DFC84 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 1147B8 7F0DFC88 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 1147BC 7F0DFC8C 318B1800 */  andi  $t3, $t4, 0x1800
/* 1147C0 7F0DFC90 01177025 */  or    $t6, $t0, $s7
/* 1147C4 7F0DFC94 31CA00FF */  andi  $t2, $t6, 0xff
/* 1147C8 7F0DFC98 000BC8C3 */  sra   $t9, $t3, 3
/* 1147CC 7F0DFC9C 032AC025 */  or    $t8, $t9, $t2
/* 1147D0 7F0DFCA0 24090001 */  li    $t1, 1
/* 1147D4 7F0DFCA4 01B87821 */  addu  $t7, $t5, $t8
/* 1147D8 7F0DFCA8 A1E90000 */  sb    $t1, ($t7)
.L7F0DFCAC:
/* 1147DC 7F0DFCAC 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 1147E0 7F0DFCB0 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 1147E4 7F0DFCB4 2E0C0001 */  sltiu $t4, $s0, 1
/* 1147E8 7F0DFCB8 AFAC0048 */  sw    $t4, 0x48($sp)
/* 1147EC 7F0DFCBC 02184821 */  addu  $t1, $s0, $t8
/* 1147F0 7F0DFCC0 912F0000 */  lbu   $t7, ($t1)
/* 1147F4 7F0DFCC4 322B0001 */  andi  $t3, $s1, 1
/* 1147F8 7F0DFCC8 320800A8 */  andi  $t0, $s0, 0xa8
/* 1147FC 7F0DFCCC 01687025 */  or    $t6, $t3, $t0
/* 114800 7F0DFCD0 000C5180 */  sll   $t2, $t4, 6
/* 114804 7F0DFCD4 01CA6825 */  or    $t5, $t6, $t2
/* 114808 7F0DFCD8 01ED8825 */  or    $s1, $t7, $t5
/* 11480C 7F0DFCDC 322C00FF */  andi  $t4, $s1, 0xff
/* 114810 7F0DFCE0 10000AC6 */  b     .L7F0E27FC
/* 114814 7F0DFCE4 01808825 */   move  $s1, $t4
spectrum_op_ED_68:
/* 114818 7F0DFCE8 8FAB028C */  lw    $t3, 0x28c($sp)
/* 11481C 7F0DFCEC 02402825 */  move  $a1, $s2
/* 114820 7F0DFCF0 02603025 */  move  $a2, $s3
/* 114824 7F0DFCF4 25640008 */  addiu $a0, $t3, 8
/* 114828 7F0DFCF8 0FC34DB6 */  jal   spectrum_input_handling
/* 11482C 7F0DFCFC AFA4028C */   sw    $a0, 0x28c($sp)
/* 114830 7F0DFD00 8FB9028C */  lw    $t9, 0x28c($sp)
/* 114834 7F0DFD04 304EFFFF */  andi  $t6, $v0, 0xffff
/* 114838 7F0DFD08 000E5203 */  sra   $t2, $t6, 8
/* 11483C 7F0DFD0C A7A200A2 */  sh    $v0, 0xa2($sp)
/* 114840 7F0DFD10 032AC021 */  addu  $t8, $t9, $t2
/* 114844 7F0DFD14 93B700A3 */  lbu   $s7, 0xa3($sp)
/* 114848 7F0DFD18 3C198009 */  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
/* 11484C 7F0DFD1C 8F39E334 */  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
/* 114850 7F0DFD20 2EE90001 */  sltiu $t1, $s7, 1
/* 114854 7F0DFD24 AFA90048 */  sw    $t1, 0x48($sp)
/* 114858 7F0DFD28 AFB8028C */  sw    $t8, 0x28c($sp)
/* 11485C 7F0DFD2C 02F95021 */  addu  $t2, $s7, $t9
/* 114860 7F0DFD30 91580000 */  lbu   $t8, ($t2)
/* 114864 7F0DFD34 322F0001 */  andi  $t7, $s1, 1
/* 114868 7F0DFD38 32ED00A8 */  andi  $t5, $s7, 0xa8
/* 11486C 7F0DFD3C 01ED6025 */  or    $t4, $t7, $t5
/* 114870 7F0DFD40 00094180 */  sll   $t0, $t1, 6
/* 114874 7F0DFD44 01887025 */  or    $t6, $t4, $t0
/* 114878 7F0DFD48 030E8825 */  or    $s1, $t8, $t6
/* 11487C 7F0DFD4C 322900FF */  andi  $t1, $s1, 0xff
/* 114880 7F0DFD50 10000AAA */  b     .L7F0E27FC
/* 114884 7F0DFD54 01208825 */   move  $s1, $t1
spectrum_op_ED_69:
/* 114888 7F0DFD58 8FAF028C */  lw    $t7, 0x28c($sp)
/* 11488C 7F0DFD5C 02402825 */  move  $a1, $s2
/* 114890 7F0DFD60 02603025 */  move  $a2, $s3
/* 114894 7F0DFD64 25E40008 */  addiu $a0, $t7, 8
/* 114898 7F0DFD68 AFA4028C */  sw    $a0, 0x28c($sp)
/* 11489C 7F0DFD6C 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 1148A0 7F0DFD70 02E03825 */   move  $a3, $s7
/* 1148A4 7F0DFD74 8FAB028C */  lw    $t3, 0x28c($sp)
/* 1148A8 7F0DFD78 AFA20048 */  sw    $v0, 0x48($sp)
/* 1148AC 7F0DFD7C 01624021 */  addu  $t0, $t3, $v0
/* 1148B0 7F0DFD80 10000A9E */  b     .L7F0E27FC
/* 1148B4 7F0DFD84 AFA8028C */   sw    $t0, 0x28c($sp)
spectrum_op_ED_6A:
/* 1148B8 7F0DFD88 0016C200 */  sll   $t8, $s6, 8
/* 1148BC 7F0DFD8C 03177025 */  or    $t6, $t8, $s7
/* 1148C0 7F0DFD90 00164A00 */  sll   $t1, $s6, 8
/* 1148C4 7F0DFD94 01377825 */  or    $t7, $t1, $s7
/* 1148C8 7F0DFD98 31CDFFFF */  andi  $t5, $t6, 0xffff
/* 1148CC 7F0DFD9C 8FB9028C */  lw    $t9, 0x28c($sp)
/* 1148D0 7F0DFDA0 01ED5821 */  addu  $t3, $t7, $t5
/* 1148D4 7F0DFDA4 322C0001 */  andi  $t4, $s1, 1
/* 1148D8 7F0DFDA8 016C4021 */  addu  $t0, $t3, $t4
/* 1148DC 7F0DFDAC 272A000B */  addiu $t2, $t9, 0xb
/* 1148E0 7F0DFDB0 0008C202 */  srl   $t8, $t0, 8
/* 1148E4 7F0DFDB4 AFAA028C */  sw    $t2, 0x28c($sp)
/* 1148E8 7F0DFDB8 330900A8 */  andi  $t1, $t8, 0xa8
/* 1148EC 7F0DFDBC 3119FFFF */  andi  $t9, $t0, 0xffff
/* 1148F0 7F0DFDC0 00087C02 */  srl   $t7, $t0, 0x10
/* 1148F4 7F0DFDC4 00165A00 */  sll   $t3, $s6, 8
/* 1148F8 7F0DFDC8 01776025 */  or    $t4, $t3, $s7
/* 1148FC 7F0DFDCC 012F6825 */  or    $t5, $t1, $t7
/* 114900 7F0DFDD0 2F2A0001 */  sltiu $t2, $t9, 1
/* 114904 7F0DFDD4 31990FFF */  andi  $t9, $t4, 0xfff
/* 114908 7F0DFDD8 31C90FFF */  andi  $t1, $t6, 0xfff
/* 11490C 7F0DFDDC 03297821 */  addu  $t7, $t9, $t1
/* 114910 7F0DFDE0 322B0001 */  andi  $t3, $s1, 1
/* 114914 7F0DFDE4 01EB6021 */  addu  $t4, $t7, $t3
/* 114918 7F0DFDE8 24010FFF */  li    $at, 4095
/* 11491C 7F0DFDEC 002CC02A */  slt   $t8, $at, $t4
/* 114920 7F0DFDF0 0018C900 */  sll   $t9, $t8, 4
/* 114924 7F0DFDF4 01B94825 */  or    $t1, $t5, $t9
/* 114928 7F0DFDF8 00167A00 */  sll   $t7, $s6, 8
/* 11492C 7F0DFDFC 01F75825 */  or    $t3, $t7, $s7
/* 114930 7F0DFE00 0016C200 */  sll   $t8, $s6, 8
/* 114934 7F0DFE04 03176827 */  nor   $t5, $t8, $s7
/* 114938 7F0DFE08 01C0C825 */  move  $t9, $t6
/* 11493C 7F0DFE0C 01B97826 */  xor   $t7, $t5, $t9
/* 114940 7F0DFE10 01686026 */  xor   $t4, $t3, $t0
/* 114944 7F0DFE14 01EC5824 */  and   $t3, $t7, $t4
/* 114948 7F0DFE18 31788000 */  andi  $t8, $t3, 0x8000
/* 11494C 7F0DFE1C A7AE00A0 */  sh    $t6, 0xa0($sp)
/* 114950 7F0DFE20 00187342 */  srl   $t6, $t8, 0xd
/* 114954 7F0DFE24 012E6825 */  or    $t5, $t1, $t6
/* 114958 7F0DFE28 000AC980 */  sll   $t9, $t2, 6
/* 11495C 7F0DFE2C 01B98825 */  or    $s1, $t5, $t9
/* 114960 7F0DFE30 0008B202 */  srl   $s6, $t0, 8
/* 114964 7F0DFE34 32CB00FF */  andi  $t3, $s6, 0xff
/* 114968 7F0DFE38 362F0002 */  ori   $t7, $s1, 2
/* 11496C 7F0DFE3C AFA8009C */  sw    $t0, 0x9c($sp)
/* 114970 7F0DFE40 93B7009F */  lbu   $s7, 0x9f($sp)
/* 114974 7F0DFE44 31F100FF */  andi  $s1, $t7, 0xff
/* 114978 7F0DFE48 0160B025 */  move  $s6, $t3
/* 11497C 7F0DFE4C 10000A6B */  b     .L7F0E27FC
/* 114980 7F0DFE50 AFAA0048 */   sw    $t2, 0x48($sp)
spectrum_op_ED_6B:
/* 114984 7F0DFE54 8FB8028C */  lw    $t8, 0x28c($sp)
/* 114988 7F0DFE58 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 11498C 7F0DFE5C 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 114990 7F0DFE60 97AE0298 */  lhu   $t6, 0x298($sp)
/* 114994 7F0DFE64 27090010 */  addiu $t1, $t8, 0x10
/* 114998 7F0DFE68 AFA9028C */  sw    $t1, 0x28c($sp)
/* 11499C 7F0DFE6C 014E7821 */  addu  $t7, $t2, $t6
/* 1149A0 7F0DFE70 91EC0001 */  lbu   $t4, 1($t7)
/* 1149A4 7F0DFE74 01CA6821 */  addu  $t5, $t6, $t2
/* 1149A8 7F0DFE78 91B90000 */  lbu   $t9, ($t5)
/* 1149AC 7F0DFE7C 000C4200 */  sll   $t0, $t4, 8
/* 1149B0 7F0DFE80 25D80002 */  addiu $t8, $t6, 2
/* 1149B4 7F0DFE84 03285825 */  or    $t3, $t9, $t0
/* 1149B8 7F0DFE88 3169FFFF */  andi  $t1, $t3, 0xffff
/* 1149BC 7F0DFE8C A7AB009A */  sh    $t3, 0x9a($sp)
/* 1149C0 7F0DFE90 A7B80298 */  sh    $t8, 0x298($sp)
/* 1149C4 7F0DFE94 012A6821 */  addu  $t5, $t1, $t2
/* 1149C8 7F0DFE98 91B70000 */  lbu   $s7, ($t5)
/* 1149CC 7F0DFE9C 10000A57 */  b     .L7F0E27FC
/* 1149D0 7F0DFEA0 91B60001 */   lbu   $s6, 1($t5)
spectrum_op_ED_6C:
/* 1149D4 7F0DFEA4 00108023 */  negu  $s0, $s0
/* 1149D8 7F0DFEA8 321900FF */  andi  $t9, $s0, 0xff
/* 1149DC 7F0DFEAC 8FAF028C */  lw    $t7, 0x28c($sp)
/* 1149E0 7F0DFEB0 2F280001 */  sltiu $t0, $t9, 1
/* 1149E4 7F0DFEB4 332A000F */  andi  $t2, $t9, 0xf
/* 1149E8 7F0DFEB8 03208025 */  move  $s0, $t9
/* 1149EC 7F0DFEBC 332B00A8 */  andi  $t3, $t9, 0xa8
/* 1149F0 7F0DFEC0 25EC0004 */  addiu $t4, $t7, 4
/* 1149F4 7F0DFEC4 3B390080 */  xori  $t9, $t9, 0x80
/* 1149F8 7F0DFEC8 000A682A */  slt   $t5, $zero, $t2
/* 1149FC 7F0DFECC 0008C180 */  sll   $t8, $t0, 6
/* 114A00 7F0DFED0 AFAC028C */  sw    $t4, 0x28c($sp)
/* 114A04 7F0DFED4 01784825 */  or    $t1, $t3, $t8
/* 114A08 7F0DFED8 000D7900 */  sll   $t7, $t5, 4
/* 114A0C 7F0DFEDC 2F390001 */  sltiu $t9, $t9, 1
/* 114A10 7F0DFEE0 AFA80048 */  sw    $t0, 0x48($sp)
/* 114A14 7F0DFEE4 00194080 */  sll   $t0, $t9, 2
/* 114A18 7F0DFEE8 012F6025 */  or    $t4, $t1, $t7
/* 114A1C 7F0DFEEC 01887025 */  or    $t6, $t4, $t0
/* 114A20 7F0DFEF0 35CB0002 */  ori   $t3, $t6, 2
/* 114A24 7F0DFEF4 0010C02A */  slt   $t8, $zero, $s0
/* 114A28 7F0DFEF8 01788825 */  or    $s1, $t3, $t8
/* 114A2C 7F0DFEFC 322A00FF */  andi  $t2, $s1, 0xff
/* 114A30 7F0DFF00 10000A3E */  b     .L7F0E27FC
/* 114A34 7F0DFF04 01408825 */   move  $s1, $t2
spectrum_op_ED_6D:
/* 114A38 7F0DFF08 8FAD028C */  lw    $t5, 0x28c($sp)
/* 114A3C 7F0DFF0C 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 114A40 7F0DFF10 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 114A44 7F0DFF14 97AC0292 */  lhu   $t4, 0x292($sp)
/* 114A48 7F0DFF18 25A90004 */  addiu $t1, $t5, 4
/* 114A4C 7F0DFF1C AFA9028C */  sw    $t1, 0x28c($sp)
/* 114A50 7F0DFF20 25390006 */  addiu $t9, $t1, 6
/* 114A54 7F0DFF24 AFB9028C */  sw    $t9, 0x28c($sp)
/* 114A58 7F0DFF28 010CC021 */  addu  $t8, $t0, $t4
/* 114A5C 7F0DFF2C 930A0001 */  lbu   $t2, 1($t8)
/* 114A60 7F0DFF30 01887021 */  addu  $t6, $t4, $t0
/* 114A64 7F0DFF34 91CB0000 */  lbu   $t3, ($t6)
/* 114A68 7F0DFF38 000A6A00 */  sll   $t5, $t2, 8
/* 114A6C 7F0DFF3C 258F0002 */  addiu $t7, $t4, 2
/* 114A70 7F0DFF40 016D4825 */  or    $t1, $t3, $t5
/* 114A74 7F0DFF44 A7A90298 */  sh    $t1, 0x298($sp)
/* 114A78 7F0DFF48 10000A2C */  b     .L7F0E27FC
/* 114A7C 7F0DFF4C A7AF0292 */   sh    $t7, 0x292($sp)
spectrum_op_ED_6E:
/* 114A80 7F0DFF50 8FB9028C */  lw    $t9, 0x28c($sp)
/* 114A84 7F0DFF54 24080001 */  li    $t0, 1
/* 114A88 7F0DFF58 A3A8029B */  sb    $t0, 0x29b($sp)
/* 114A8C 7F0DFF5C 272E0004 */  addiu $t6, $t9, 4
/* 114A90 7F0DFF60 10000A26 */  b     .L7F0E27FC
/* 114A94 7F0DFF64 AFAE028C */   sw    $t6, 0x28c($sp)
spectrum_op_ED_6F:
/* 114A98 7F0DFF68 8FB8028C */  lw    $t8, 0x28c($sp)
/* 114A9C 7F0DFF6C 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 114AA0 7F0DFF70 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 114AA4 7F0DFF74 00165A00 */  sll   $t3, $s6, 8
/* 114AA8 7F0DFF78 01776825 */  or    $t5, $t3, $s7
/* 114AAC 7F0DFF7C 270A0005 */  addiu $t2, $t8, 5
/* 114AB0 7F0DFF80 AFAA028C */  sw    $t2, 0x28c($sp)
/* 114AB4 7F0DFF84 01A96021 */  addu  $t4, $t5, $t1
/* 114AB8 7F0DFF88 918F0000 */  lbu   $t7, ($t4)
/* 114ABC 7F0DFF8C 320E000F */  andi  $t6, $s0, 0xf
/* 114AC0 7F0DFF90 320A00F0 */  andi  $t2, $s0, 0xf0
/* 114AC4 7F0DFF94 00166A00 */  sll   $t5, $s6, 8
/* 114AC8 7F0DFF98 000FC103 */  sra   $t8, $t7, 4
/* 114ACC 7F0DFF9C 01588025 */  or    $s0, $t2, $t8
/* 114AD0 7F0DFFA0 01B74825 */  or    $t1, $t5, $s7
/* 114AD4 7F0DFFA4 000FC900 */  sll   $t9, $t7, 4
/* 114AD8 7F0DFFA8 01D94025 */  or    $t0, $t6, $t9
/* 114ADC 7F0DFFAC 320B00FF */  andi  $t3, $s0, 0xff
/* 114AE0 7F0DFFB0 29215B00 */  slti  $at, $t1, 0x5b00
/* 114AE4 7F0DFFB4 A3A80098 */  sb    $t0, 0x98($sp)
/* 114AE8 7F0DFFB8 01608025 */  move  $s0, $t3
/* 114AEC 7F0DFFBC 14200009 */  bnez  $at, .L7F0DFFE4
/* 114AF0 7F0DFFC0 A3AF0099 */   sb    $t7, 0x99($sp)
/* 114AF4 7F0DFFC4 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 114AF8 7F0DFFC8 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 114AFC 7F0DFFCC 01006025 */  move  $t4, $t0
/* 114B00 7F0DFFD0 0016CA00 */  sll   $t9, $s6, 8
/* 114B04 7F0DFFD4 03374025 */  or    $t0, $t9, $s7
/* 114B08 7F0DFFD8 01C87821 */  addu  $t7, $t6, $t0
/* 114B0C 7F0DFFDC 1000002B */  b     .L7F0E008C
/* 114B10 7F0DFFE0 A1EC0000 */   sb    $t4, ($t7)
.L7F0DFFE4:
/* 114B14 7F0DFFE4 00165200 */  sll   $t2, $s6, 8
/* 114B18 7F0DFFE8 0157C025 */  or    $t8, $t2, $s7
/* 114B1C 7F0DFFEC 2B015800 */  slti  $at, $t8, 0x5800
/* 114B20 7F0DFFF0 14200010 */  bnez  $at, .L7F0E0034
/* 114B24 7F0DFFF4 00164A00 */   sll   $t1, $s6, 8
/* 114B28 7F0DFFF8 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 114B2C 7F0DFFFC 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 114B30 7F0E0000 93AB0098 */  lbu   $t3, 0x98($sp)
/* 114B34 7F0E0004 00164A00 */  sll   $t1, $s6, 8
/* 114B38 7F0E0008 0137C825 */  or    $t9, $t1, $s7
/* 114B3C 7F0E000C 01B97021 */  addu  $t6, $t5, $t9
/* 114B40 7F0E0010 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 114B44 7F0E0014 A1CB0000 */  sb    $t3, ($t6)
/* 114B48 7F0E0018 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 114B4C 7F0E001C 00167A00 */  sll   $t7, $s6, 8
/* 114B50 7F0E0020 01F75025 */  or    $t2, $t7, $s7
/* 114B54 7F0E0024 24080001 */  li    $t0, 1
/* 114B58 7F0E0028 018AC021 */  addu  $t8, $t4, $t2
/* 114B5C 7F0E002C 10000017 */  b     .L7F0E008C
/* 114B60 7F0E0030 A308A800 */   sb    $t0, -0x5800($t8)
.L7F0E0034:
/* 114B64 7F0E0034 01376825 */  or    $t5, $t1, $s7
/* 114B68 7F0E0038 29A14000 */  slti  $at, $t5, 0x4000
/* 114B6C 7F0E003C 14200013 */  bnez  $at, .L7F0E008C
/* 114B70 7F0E0040 93B90098 */   lbu   $t9, 0x98($sp)
/* 114B74 7F0E0044 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 114B78 7F0E0048 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 114B7C 7F0E004C 00167200 */  sll   $t6, $s6, 8
/* 114B80 7F0E0050 01D77825 */  or    $t7, $t6, $s7
/* 114B84 7F0E0054 016F6021 */  addu  $t4, $t3, $t7
/* 114B88 7F0E0058 A1990000 */  sb    $t9, ($t4)
/* 114B8C 7F0E005C 00164200 */  sll   $t0, $s6, 8
/* 114B90 7F0E0060 0117C025 */  or    $t8, $t0, $s7
/* 114B94 7F0E0064 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 114B98 7F0E0068 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 114B9C 7F0E006C 33091800 */  andi  $t1, $t8, 0x1800
/* 114BA0 7F0E0070 01D75825 */  or    $t3, $t6, $s7
/* 114BA4 7F0E0074 316F00FF */  andi  $t7, $t3, 0xff
/* 114BA8 7F0E0078 000968C3 */  sra   $t5, $t1, 3
/* 114BAC 7F0E007C 01AFC825 */  or    $t9, $t5, $t7
/* 114BB0 7F0E0080 240A0001 */  li    $t2, 1
/* 114BB4 7F0E0084 01994021 */  addu  $t0, $t4, $t9
/* 114BB8 7F0E0088 A10A0000 */  sb    $t2, ($t0)
.L7F0E008C:
/* 114BBC 7F0E008C 3C198009 */  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
/* 114BC0 7F0E0090 8F39E334 */  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
/* 114BC4 7F0E0094 2E180001 */  sltiu $t8, $s0, 1
/* 114BC8 7F0E0098 AFB80048 */  sw    $t8, 0x48($sp)
/* 114BCC 7F0E009C 02195021 */  addu  $t2, $s0, $t9
/* 114BD0 7F0E00A0 91480000 */  lbu   $t0, ($t2)
/* 114BD4 7F0E00A4 32290001 */  andi  $t1, $s1, 1
/* 114BD8 7F0E00A8 320E00A8 */  andi  $t6, $s0, 0xa8
/* 114BDC 7F0E00AC 012E5825 */  or    $t3, $t1, $t6
/* 114BE0 7F0E00B0 00187980 */  sll   $t7, $t8, 6
/* 114BE4 7F0E00B4 016F6025 */  or    $t4, $t3, $t7
/* 114BE8 7F0E00B8 010C8825 */  or    $s1, $t0, $t4
/* 114BEC 7F0E00BC 323800FF */  andi  $t8, $s1, 0xff
/* 114BF0 7F0E00C0 100009CE */  b     .L7F0E27FC
/* 114BF4 7F0E00C4 03008825 */   move  $s1, $t8
spectrum_op_ED_70:
/* 114BF8 7F0E00C8 8FA9028C */  lw    $t1, 0x28c($sp)
/* 114BFC 7F0E00CC 02402825 */  move  $a1, $s2
/* 114C00 7F0E00D0 02603025 */  move  $a2, $s3
/* 114C04 7F0E00D4 25240008 */  addiu $a0, $t1, 8
/* 114C08 7F0E00D8 0FC34DB6 */  jal   spectrum_input_handling
/* 114C0C 7F0E00DC AFA4028C */   sw    $a0, 0x28c($sp)
/* 114C10 7F0E00E0 8FAB028C */  lw    $t3, 0x28c($sp)
/* 114C14 7F0E00E4 3058FFFF */  andi  $t8, $v0, 0xffff
/* 114C18 7F0E00E8 00187A03 */  sra   $t7, $t8, 8
/* 114C1C 7F0E00EC 016FC821 */  addu  $t9, $t3, $t7
/* 114C20 7F0E00F0 AFB9028C */  sw    $t9, 0x28c($sp)
/* 114C24 7F0E00F4 3C198009 */  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
/* 114C28 7F0E00F8 8F39E334 */  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
/* 114C2C 7F0E00FC 330A00FF */  andi  $t2, $t8, 0xff
/* 114C30 7F0E0100 330900A8 */  andi  $t1, $t8, 0xa8
/* 114C34 7F0E0104 2D480001 */  sltiu $t0, $t2, 1
/* 114C38 7F0E0108 A3B80097 */  sb    $t8, 0x97($sp)
/* 114C3C 7F0E010C 322C0001 */  andi  $t4, $s1, 1
/* 114C40 7F0E0110 01897025 */  or    $t6, $t4, $t1
/* 114C44 7F0E0114 AFA80048 */  sw    $t0, 0x48($sp)
/* 114C48 7F0E0118 A7A20094 */  sh    $v0, 0x94($sp)
/* 114C4C 7F0E011C 0159C021 */  addu  $t8, $t2, $t9
/* 114C50 7F0E0120 930C0000 */  lbu   $t4, ($t8)
/* 114C54 7F0E0124 00085980 */  sll   $t3, $t0, 6
/* 114C58 7F0E0128 01CB7825 */  or    $t7, $t6, $t3
/* 114C5C 7F0E012C 018F8825 */  or    $s1, $t4, $t7
/* 114C60 7F0E0130 322900FF */  andi  $t1, $s1, 0xff
/* 114C64 7F0E0134 100009B1 */  b     .L7F0E27FC
/* 114C68 7F0E0138 01208825 */   move  $s1, $t1
spectrum_op_ED_71:
/* 114C6C 7F0E013C 8FA8028C */  lw    $t0, 0x28c($sp)
/* 114C70 7F0E0140 02402825 */  move  $a1, $s2
/* 114C74 7F0E0144 02603025 */  move  $a2, $s3
/* 114C78 7F0E0148 25040008 */  addiu $a0, $t0, 8
/* 114C7C 7F0E014C AFA4028C */  sw    $a0, 0x28c($sp)
/* 114C80 7F0E0150 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 114C84 7F0E0154 00003825 */   move  $a3, $zero
/* 114C88 7F0E0158 8FAB028C */  lw    $t3, 0x28c($sp)
/* 114C8C 7F0E015C AFA20048 */  sw    $v0, 0x48($sp)
/* 114C90 7F0E0160 01625021 */  addu  $t2, $t3, $v0
/* 114C94 7F0E0164 100009A5 */  b     .L7F0E27FC
/* 114C98 7F0E0168 AFAA028C */   sw    $t2, 0x28c($sp)
spectrum_op_ED_72:
/* 114C9C 7F0E016C 97AC0292 */  lhu   $t4, 0x292($sp)
/* 114CA0 7F0E0170 8FB9028C */  lw    $t9, 0x28c($sp)
/* 114CA4 7F0E0174 00167A00 */  sll   $t7, $s6, 8
/* 114CA8 7F0E0178 01F74825 */  or    $t1, $t7, $s7
/* 114CAC 7F0E017C 322E0001 */  andi  $t6, $s1, 1
/* 114CB0 7F0E0180 3C010001 */  lui   $at, (0x0001FFFF >> 16) # lui $at, 1
/* 114CB4 7F0E0184 012C4023 */  subu  $t0, $t1, $t4
/* 114CB8 7F0E0188 010E5823 */  subu  $t3, $t0, $t6
/* 114CBC 7F0E018C 3421FFFF */  ori   $at, (0x0001FFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 114CC0 7F0E0190 2738000B */  addiu $t8, $t9, 0xb
/* 114CC4 7F0E0194 AFB8028C */  sw    $t8, 0x28c($sp)
/* 114CC8 7F0E0198 01616824 */  and   $t5, $t3, $at
/* 114CCC 7F0E019C 000DC202 */  srl   $t8, $t5, 8
/* 114CD0 7F0E01A0 330F00A8 */  andi  $t7, $t8, 0xa8
/* 114CD4 7F0E01A4 000D4C02 */  srl   $t1, $t5, 0x10
/* 114CD8 7F0E01A8 01E94025 */  or    $t0, $t7, $t1
/* 114CDC 7F0E01AC 31AAFFFF */  andi  $t2, $t5, 0xffff
/* 114CE0 7F0E01B0 2D590001 */  sltiu $t9, $t2, 1
/* 114CE4 7F0E01B4 322A0001 */  andi  $t2, $s1, 1
/* 114CE8 7F0E01B8 350E0002 */  ori   $t6, $t0, 2
/* 114CEC 7F0E01BC 00164A00 */  sll   $t1, $s6, 8
/* 114CF0 7F0E01C0 318B0FFF */  andi  $t3, $t4, 0xfff
/* 114CF4 7F0E01C4 016A7821 */  addu  $t7, $t3, $t2
/* 114CF8 7F0E01C8 01374025 */  or    $t0, $t1, $s7
/* 114CFC 7F0E01CC 310B0FFF */  andi  $t3, $t0, 0xfff
/* 114D00 7F0E01D0 016F502A */  slt   $t2, $t3, $t7
/* 114D04 7F0E01D4 000A4900 */  sll   $t1, $t2, 4
/* 114D08 7F0E01D8 01C94025 */  or    $t0, $t6, $t1
/* 114D0C 7F0E01DC 00165A00 */  sll   $t3, $s6, 8
/* 114D10 7F0E01E0 01777825 */  or    $t7, $t3, $s7
/* 114D14 7F0E01E4 00167200 */  sll   $t6, $s6, 8
/* 114D18 7F0E01E8 01D74825 */  or    $t1, $t6, $s7
/* 114D1C 7F0E01EC 012D5826 */  xor   $t3, $t1, $t5
/* 114D20 7F0E01F0 01EC5026 */  xor   $t2, $t7, $t4
/* 114D24 7F0E01F4 014B7824 */  and   $t7, $t2, $t3
/* 114D28 7F0E01F8 A7AC0092 */  sh    $t4, 0x92($sp)
/* 114D2C 7F0E01FC 31EC8000 */  andi  $t4, $t7, 0x8000
/* 114D30 7F0E0200 000C7342 */  srl   $t6, $t4, 0xd
/* 114D34 7F0E0204 AFAD008C */  sw    $t5, 0x8c($sp)
/* 114D38 7F0E0208 00196980 */  sll   $t5, $t9, 6
/* 114D3C 7F0E020C 010E4825 */  or    $t1, $t0, $t6
/* 114D40 7F0E0210 012D8825 */  or    $s1, $t1, $t5
/* 114D44 7F0E0214 362A0002 */  ori   $t2, $s1, 2
/* 114D48 7F0E0218 315100FF */  andi  $s1, $t2, 0xff
/* 114D4C 7F0E021C 93B7008F */  lbu   $s7, 0x8f($sp)
/* 114D50 7F0E0220 331600FF */  andi  $s6, $t8, 0xff
/* 114D54 7F0E0224 10000975 */  b     .L7F0E27FC
/* 114D58 7F0E0228 AFB90048 */   sw    $t9, 0x48($sp)
spectrum_op_ED_73:
/* 114D5C 7F0E022C 8FAF028C */  lw    $t7, 0x28c($sp)
/* 114D60 7F0E0230 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 114D64 7F0E0234 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 114D68 7F0E0238 97A80298 */  lhu   $t0, 0x298($sp)
/* 114D6C 7F0E023C 25EC0010 */  addiu $t4, $t7, 0x10
/* 114D70 7F0E0240 AFAC028C */  sw    $t4, 0x28c($sp)
/* 114D74 7F0E0244 01C86821 */  addu  $t5, $t6, $t0
/* 114D78 7F0E0248 91AA0001 */  lbu   $t2, 1($t5)
/* 114D7C 7F0E024C 010EC821 */  addu  $t9, $t0, $t6
/* 114D80 7F0E0250 93290000 */  lbu   $t1, ($t9)
/* 114D84 7F0E0254 000A5A00 */  sll   $t3, $t2, 8
/* 114D88 7F0E0258 250F0002 */  addiu $t7, $t0, 2
/* 114D8C 7F0E025C 012BC025 */  or    $t8, $t1, $t3
/* 114D90 7F0E0260 330CFFFF */  andi  $t4, $t8, 0xffff
/* 114D94 7F0E0264 29815B00 */  slti  $at, $t4, 0x5b00
/* 114D98 7F0E0268 A7B8008A */  sh    $t8, 0x8a($sp)
/* 114D9C 7F0E026C 14200007 */  bnez  $at, .L7F0E028C
/* 114DA0 7F0E0270 A7AF0298 */   sh    $t7, 0x298($sp)
/* 114DA4 7F0E0274 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 114DA8 7F0E0278 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 114DAC 7F0E027C 97B90292 */  lhu   $t9, 0x292($sp)
/* 114DB0 7F0E0280 01CC6821 */  addu  $t5, $t6, $t4
/* 114DB4 7F0E0284 10000023 */  b     .L7F0E0314
/* 114DB8 7F0E0288 A1B90000 */   sb    $t9, ($t5)
.L7F0E028C:
/* 114DBC 7F0E028C 97AA008A */  lhu   $t2, 0x8a($sp)
/* 114DC0 7F0E0290 97B9008A */  lhu   $t9, 0x8a($sp)
/* 114DC4 7F0E0294 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 114DC8 7F0E0298 29415800 */  slti  $at, $t2, 0x5800
/* 114DCC 7F0E029C 5420000D */  bnezl $at, .L7F0E02D4
/* 114DD0 7F0E02A0 2B214000 */   slti  $at, $t9, 0x4000
/* 114DD4 7F0E02A4 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 114DD8 7F0E02A8 97A90292 */  lhu   $t1, 0x292($sp)
/* 114DDC 7F0E02AC 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 114DE0 7F0E02B0 016AC021 */  addu  $t8, $t3, $t2
/* 114DE4 7F0E02B4 A3090000 */  sb    $t1, ($t8)
/* 114DE8 7F0E02B8 97AE008A */  lhu   $t6, 0x8a($sp)
/* 114DEC 7F0E02BC 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 114DF0 7F0E02C0 24080001 */  li    $t0, 1
/* 114DF4 7F0E02C4 01EE6021 */  addu  $t4, $t7, $t6
/* 114DF8 7F0E02C8 10000012 */  b     .L7F0E0314
/* 114DFC 7F0E02CC A188A800 */   sb    $t0, -0x5800($t4)
/* 114E00 7F0E02D0 2B214000 */  slti  $at, $t9, 0x4000
.L7F0E02D4:
/* 114E04 7F0E02D4 1420000F */  bnez  $at, .L7F0E0314
/* 114E08 7F0E02D8 3C0B8009 */   lui   $t3, %hi(ptr_spectrum_roms) 
/* 114E0C 7F0E02DC 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 114E10 7F0E02E0 97AD0292 */  lhu   $t5, 0x292($sp)
/* 114E14 7F0E02E4 24090001 */  li    $t1, 1
/* 114E18 7F0E02E8 01795021 */  addu  $t2, $t3, $t9
/* 114E1C 7F0E02EC A14D0000 */  sb    $t5, ($t2)
/* 114E20 7F0E02F0 97B8008A */  lhu   $t8, 0x8a($sp)
/* 114E24 7F0E02F4 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 114E28 7F0E02F8 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 114E2C 7F0E02FC 330F1800 */  andi  $t7, $t8, 0x1800
/* 114E30 7F0E0300 000F70C3 */  sra   $t6, $t7, 3
/* 114E34 7F0E0304 330800FF */  andi  $t0, $t8, 0xff
/* 114E38 7F0E0308 01C86025 */  or    $t4, $t6, $t0
/* 114E3C 7F0E030C 016CC821 */  addu  $t9, $t3, $t4
/* 114E40 7F0E0310 A3290000 */  sb    $t1, ($t9)
.L7F0E0314:
/* 114E44 7F0E0314 97AD008A */  lhu   $t5, 0x8a($sp)
/* 114E48 7F0E0318 97AB008A */  lhu   $t3, 0x8a($sp)
/* 114E4C 7F0E031C 97AF0292 */  lhu   $t7, 0x292($sp)
/* 114E50 7F0E0320 25AA0001 */  addiu $t2, $t5, 1
/* 114E54 7F0E0324 29415B00 */  slti  $at, $t2, 0x5b00
/* 114E58 7F0E0328 14200007 */  bnez  $at, .L7F0E0348
/* 114E5C 7F0E032C 256C0001 */   addiu $t4, $t3, 1
/* 114E60 7F0E0330 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 114E64 7F0E0334 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 114E68 7F0E0338 000FC203 */  sra   $t8, $t7, 8
/* 114E6C 7F0E033C 01CD4021 */  addu  $t0, $t6, $t5
/* 114E70 7F0E0340 1000092E */  b     .L7F0E27FC
/* 114E74 7F0E0344 A1180001 */   sb    $t8, 1($t0)
.L7F0E0348:
/* 114E78 7F0E0348 29815800 */  slti  $at, $t4, 0x5800
/* 114E7C 7F0E034C 1420000E */  bnez  $at, .L7F0E0388
/* 114E80 7F0E0350 97AC008A */   lhu   $t4, 0x8a($sp)
/* 114E84 7F0E0354 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 114E88 7F0E0358 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 114E8C 7F0E035C 97A90292 */  lhu   $t1, 0x292($sp)
/* 114E90 7F0E0360 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 114E94 7F0E0364 014B7821 */  addu  $t7, $t2, $t3
/* 114E98 7F0E0368 0009CA03 */  sra   $t9, $t1, 8
/* 114E9C 7F0E036C A1F90001 */  sb    $t9, 1($t7)
/* 114EA0 7F0E0370 97B8008A */  lhu   $t8, 0x8a($sp)
/* 114EA4 7F0E0374 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 114EA8 7F0E0378 240E0001 */  li    $t6, 1
/* 114EAC 7F0E037C 01B84021 */  addu  $t0, $t5, $t8
/* 114EB0 7F0E0380 1000091E */  b     .L7F0E27FC
/* 114EB4 7F0E0384 A10EA801 */   sb    $t6, -0x57ff($t0)
.L7F0E0388:
/* 114EB8 7F0E0388 25890001 */  addiu $t1, $t4, 1
/* 114EBC 7F0E038C 29214000 */  slti  $at, $t1, 0x4000
/* 114EC0 7F0E0390 1420091A */  bnez  $at, .L7F0E27FC
/* 114EC4 7F0E0394 97AA0292 */   lhu   $t2, 0x292($sp)
/* 114EC8 7F0E0398 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 114ECC 7F0E039C 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 114ED0 7F0E03A0 000A5A03 */  sra   $t3, $t2, 8
/* 114ED4 7F0E03A4 240D0001 */  li    $t5, 1
/* 114ED8 7F0E03A8 032C7821 */  addu  $t7, $t9, $t4
/* 114EDC 7F0E03AC A1EB0001 */  sb    $t3, 1($t7)
/* 114EE0 7F0E03B0 97B8008A */  lhu   $t8, 0x8a($sp)
/* 114EE4 7F0E03B4 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 114EE8 7F0E03B8 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 114EEC 7F0E03BC 270E0001 */  addiu $t6, $t8, 1
/* 114EF0 7F0E03C0 31C81800 */  andi  $t0, $t6, 0x1800
/* 114EF4 7F0E03C4 000848C3 */  sra   $t1, $t0, 3
/* 114EF8 7F0E03C8 31CA00FF */  andi  $t2, $t6, 0xff
/* 114EFC 7F0E03CC 012AC825 */  or    $t9, $t1, $t2
/* 114F00 7F0E03D0 01995821 */  addu  $t3, $t4, $t9
/* 114F04 7F0E03D4 10000909 */  b     .L7F0E27FC
/* 114F08 7F0E03D8 A16D0000 */   sb    $t5, ($t3)
spectrum_op_ED_74:
/* 114F0C 7F0E03DC 00108023 */  negu  $s0, $s0
/* 114F10 7F0E03E0 320800FF */  andi  $t0, $s0, 0xff
/* 114F14 7F0E03E4 8FAF028C */  lw    $t7, 0x28c($sp)
/* 114F18 7F0E03E8 2D0E0001 */  sltiu $t6, $t0, 1
/* 114F1C 7F0E03EC 310D000F */  andi  $t5, $t0, 0xf
/* 114F20 7F0E03F0 01008025 */  move  $s0, $t0
/* 114F24 7F0E03F4 310900A8 */  andi  $t1, $t0, 0xa8
/* 114F28 7F0E03F8 25F80004 */  addiu $t8, $t7, 4
/* 114F2C 7F0E03FC 39080080 */  xori  $t0, $t0, 0x80
/* 114F30 7F0E0400 000D582A */  slt   $t3, $zero, $t5
/* 114F34 7F0E0404 000E6180 */  sll   $t4, $t6, 6
/* 114F38 7F0E0408 AFB8028C */  sw    $t8, 0x28c($sp)
/* 114F3C 7F0E040C 012CC825 */  or    $t9, $t1, $t4
/* 114F40 7F0E0410 000B7900 */  sll   $t7, $t3, 4
/* 114F44 7F0E0414 2D080001 */  sltiu $t0, $t0, 1
/* 114F48 7F0E0418 AFAE0048 */  sw    $t6, 0x48($sp)
/* 114F4C 7F0E041C 00087080 */  sll   $t6, $t0, 2
/* 114F50 7F0E0420 032FC025 */  or    $t8, $t9, $t7
/* 114F54 7F0E0424 030E5025 */  or    $t2, $t8, $t6
/* 114F58 7F0E0428 35490002 */  ori   $t1, $t2, 2
/* 114F5C 7F0E042C 0010602A */  slt   $t4, $zero, $s0
/* 114F60 7F0E0430 012C8825 */  or    $s1, $t1, $t4
/* 114F64 7F0E0434 322D00FF */  andi  $t5, $s1, 0xff
/* 114F68 7F0E0438 100008F0 */  b     .L7F0E27FC
/* 114F6C 7F0E043C 01A08825 */   move  $s1, $t5
spectrum_op_ED_75:
/* 114F70 7F0E0440 8FAB028C */  lw    $t3, 0x28c($sp)
/* 114F74 7F0E0444 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 114F78 7F0E0448 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 114F7C 7F0E044C 97B80292 */  lhu   $t8, 0x292($sp)
/* 114F80 7F0E0450 25790004 */  addiu $t9, $t3, 4
/* 114F84 7F0E0454 AFB9028C */  sw    $t9, 0x28c($sp)
/* 114F88 7F0E0458 27280006 */  addiu $t0, $t9, 6
/* 114F8C 7F0E045C AFA8028C */  sw    $t0, 0x28c($sp)
/* 114F90 7F0E0460 01D86021 */  addu  $t4, $t6, $t8
/* 114F94 7F0E0464 918D0001 */  lbu   $t5, 1($t4)
/* 114F98 7F0E0468 030E5021 */  addu  $t2, $t8, $t6
/* 114F9C 7F0E046C 91490000 */  lbu   $t1, ($t2)
/* 114FA0 7F0E0470 000D5A00 */  sll   $t3, $t5, 8
/* 114FA4 7F0E0474 270F0002 */  addiu $t7, $t8, 2
/* 114FA8 7F0E0478 012BC825 */  or    $t9, $t1, $t3
/* 114FAC 7F0E047C A7B90298 */  sh    $t9, 0x298($sp)
/* 114FB0 7F0E0480 100008DE */  b     .L7F0E27FC
/* 114FB4 7F0E0484 A7AF0292 */   sh    $t7, 0x292($sp)
spectrum_op_ED_76:
/* 114FB8 7F0E0488 8FA8028C */  lw    $t0, 0x28c($sp)
/* 114FBC 7F0E048C 240E0002 */  li    $t6, 2
/* 114FC0 7F0E0490 A3AE029B */  sb    $t6, 0x29b($sp)
/* 114FC4 7F0E0494 250A0004 */  addiu $t2, $t0, 4
/* 114FC8 7F0E0498 100008D8 */  b     .L7F0E27FC
/* 114FCC 7F0E049C AFAA028C */   sw    $t2, 0x28c($sp)
spectrum_op_ED_78:
/* 114FD0 7F0E04A0 8FAC028C */  lw    $t4, 0x28c($sp)
/* 114FD4 7F0E04A4 02402825 */  move  $a1, $s2
/* 114FD8 7F0E04A8 02603025 */  move  $a2, $s3
/* 114FDC 7F0E04AC 25840008 */  addiu $a0, $t4, 8
/* 114FE0 7F0E04B0 0FC34DB6 */  jal   spectrum_input_handling
/* 114FE4 7F0E04B4 AFA4028C */   sw    $a0, 0x28c($sp)
/* 114FE8 7F0E04B8 8FA9028C */  lw    $t1, 0x28c($sp)
/* 114FEC 7F0E04BC 304BFFFF */  andi  $t3, $v0, 0xffff
/* 114FF0 7F0E04C0 000BCA03 */  sra   $t9, $t3, 8
/* 114FF4 7F0E04C4 A7A20088 */  sh    $v0, 0x88($sp)
/* 114FF8 7F0E04C8 0139C021 */  addu  $t8, $t1, $t9
/* 114FFC 7F0E04CC 93B00089 */  lbu   $s0, 0x89($sp)
/* 115000 7F0E04D0 3C098009 */  lui   $t1, %hi(ptr_pc_keyboard_table_alloc) 
/* 115004 7F0E04D4 8D29E334 */  lw    $t1, %lo(ptr_pc_keyboard_table_alloc)($t1)
/* 115008 7F0E04D8 2E0F0001 */  sltiu $t7, $s0, 1
/* 11500C 7F0E04DC AFAF0048 */  sw    $t7, 0x48($sp)
/* 115010 7F0E04E0 AFB8028C */  sw    $t8, 0x28c($sp)
/* 115014 7F0E04E4 0209C821 */  addu  $t9, $s0, $t1
/* 115018 7F0E04E8 93380000 */  lbu   $t8, ($t9)
/* 11501C 7F0E04EC 32280001 */  andi  $t0, $s1, 1
/* 115020 7F0E04F0 320A00A8 */  andi  $t2, $s0, 0xa8
/* 115024 7F0E04F4 010A7025 */  or    $t6, $t0, $t2
/* 115028 7F0E04F8 000F6980 */  sll   $t5, $t7, 6
/* 11502C 7F0E04FC 01CD5825 */  or    $t3, $t6, $t5
/* 115030 7F0E0500 030B8825 */  or    $s1, $t8, $t3
/* 115034 7F0E0504 322F00FF */  andi  $t7, $s1, 0xff
/* 115038 7F0E0508 100008BC */  b     .L7F0E27FC
/* 11503C 7F0E050C 01E08825 */   move  $s1, $t7
spectrum_op_ED_79:
/* 115040 7F0E0510 8FA8028C */  lw    $t0, 0x28c($sp)
/* 115044 7F0E0514 02402825 */  move  $a1, $s2
/* 115048 7F0E0518 02603025 */  move  $a2, $s3
/* 11504C 7F0E051C 25040008 */  addiu $a0, $t0, 8
/* 115050 7F0E0520 AFA4028C */  sw    $a0, 0x28c($sp)
/* 115054 7F0E0524 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 115058 7F0E0528 02003825 */   move  $a3, $s0
/* 11505C 7F0E052C 8FAC028C */  lw    $t4, 0x28c($sp)
/* 115060 7F0E0530 AFA20048 */  sw    $v0, 0x48($sp)
/* 115064 7F0E0534 01826821 */  addu  $t5, $t4, $v0
/* 115068 7F0E0538 100008B0 */  b     .L7F0E27FC
/* 11506C 7F0E053C AFAD028C */   sw    $t5, 0x28c($sp)
spectrum_op_ED_7A:
/* 115070 7F0E0540 97B80292 */  lhu   $t8, 0x292($sp)
/* 115074 7F0E0544 00165A00 */  sll   $t3, $s6, 8
/* 115078 7F0E0548 8FA9028C */  lw    $t1, 0x28c($sp)
/* 11507C 7F0E054C 01777825 */  or    $t7, $t3, $s7
/* 115080 7F0E0550 322A0001 */  andi  $t2, $s1, 1
/* 115084 7F0E0554 01F84021 */  addu  $t0, $t7, $t8
/* 115088 7F0E0558 010A6021 */  addu  $t4, $t0, $t2
/* 11508C 7F0E055C 2539000B */  addiu $t9, $t1, 0xb
/* 115090 7F0E0560 AFB9028C */  sw    $t9, 0x28c($sp)
/* 115094 7F0E0564 000C4A02 */  srl   $t1, $t4, 8
/* 115098 7F0E0568 313900A8 */  andi  $t9, $t1, 0xa8
/* 11509C 7F0E056C 318EFFFF */  andi  $t6, $t4, 0xffff
/* 1150A0 7F0E0570 000C5C02 */  srl   $t3, $t4, 0x10
/* 1150A4 7F0E0574 00164200 */  sll   $t0, $s6, 8
/* 1150A8 7F0E0578 01175025 */  or    $t2, $t0, $s7
/* 1150AC 7F0E057C 032B7825 */  or    $t7, $t9, $t3
/* 1150B0 7F0E0580 2DCD0001 */  sltiu $t5, $t6, 1
/* 1150B4 7F0E0584 314E0FFF */  andi  $t6, $t2, 0xfff
/* 1150B8 7F0E0588 33190FFF */  andi  $t9, $t8, 0xfff
/* 1150BC 7F0E058C 01D95821 */  addu  $t3, $t6, $t9
/* 1150C0 7F0E0590 32280001 */  andi  $t0, $s1, 1
/* 1150C4 7F0E0594 01685021 */  addu  $t2, $t3, $t0
/* 1150C8 7F0E0598 24010FFF */  li    $at, 4095
/* 1150CC 7F0E059C 002A702A */  slt   $t6, $at, $t2
/* 1150D0 7F0E05A0 000EC900 */  sll   $t9, $t6, 4
/* 1150D4 7F0E05A4 01F95825 */  or    $t3, $t7, $t9
/* 1150D8 7F0E05A8 00164200 */  sll   $t0, $s6, 8
/* 1150DC 7F0E05AC 01175027 */  nor   $t2, $t0, $s7
/* 1150E0 7F0E05B0 00167A00 */  sll   $t7, $s6, 8
/* 1150E4 7F0E05B4 01F7C825 */  or    $t9, $t7, $s7
/* 1150E8 7F0E05B8 032C4026 */  xor   $t0, $t9, $t4
/* 1150EC 7F0E05BC 01587026 */  xor   $t6, $t2, $t8
/* 1150F0 7F0E05C0 01C85024 */  and   $t2, $t6, $t0
/* 1150F4 7F0E05C4 A7B80086 */  sh    $t8, 0x86($sp)
/* 1150F8 7F0E05C8 31588000 */  andi  $t8, $t2, 0x8000
/* 1150FC 7F0E05CC 00187B42 */  srl   $t7, $t8, 0xd
/* 115100 7F0E05D0 AFAC0080 */  sw    $t4, 0x80($sp)
/* 115104 7F0E05D4 000D6180 */  sll   $t4, $t5, 6
/* 115108 7F0E05D8 016FC825 */  or    $t9, $t3, $t7
/* 11510C 7F0E05DC 032C8825 */  or    $s1, $t9, $t4
/* 115110 7F0E05E0 362E0002 */  ori   $t6, $s1, 2
/* 115114 7F0E05E4 31D100FF */  andi  $s1, $t6, 0xff
/* 115118 7F0E05E8 93B70083 */  lbu   $s7, 0x83($sp)
/* 11511C 7F0E05EC 313600FF */  andi  $s6, $t1, 0xff
/* 115120 7F0E05F0 10000882 */  b     .L7F0E27FC
/* 115124 7F0E05F4 AFAD0048 */   sw    $t5, 0x48($sp)
spectrum_op_ED_7B:
/* 115128 7F0E05F8 8FAA028C */  lw    $t2, 0x28c($sp)
/* 11512C 7F0E05FC 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 115130 7F0E0600 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 115134 7F0E0604 97AB0298 */  lhu   $t3, 0x298($sp)
/* 115138 7F0E0608 25580010 */  addiu $t8, $t2, 0x10
/* 11513C 7F0E060C AFB8028C */  sw    $t8, 0x28c($sp)
/* 115140 7F0E0610 01EB6021 */  addu  $t4, $t7, $t3
/* 115144 7F0E0614 918E0001 */  lbu   $t6, 1($t4)
/* 115148 7F0E0618 016F6821 */  addu  $t5, $t3, $t7
/* 11514C 7F0E061C 91B90000 */  lbu   $t9, ($t5)
/* 115150 7F0E0620 000E4200 */  sll   $t0, $t6, 8
/* 115154 7F0E0624 256A0002 */  addiu $t2, $t3, 2
/* 115158 7F0E0628 03284825 */  or    $t1, $t9, $t0
/* 11515C 7F0E062C 3138FFFF */  andi  $t8, $t1, 0xffff
/* 115160 7F0E0630 A7A9007E */  sh    $t1, 0x7e($sp)
/* 115164 7F0E0634 A7AA0298 */  sh    $t2, 0x298($sp)
/* 115168 7F0E0638 01F87021 */  addu  $t6, $t7, $t8
/* 11516C 7F0E063C 91D90001 */  lbu   $t9, 1($t6)
/* 115170 7F0E0640 030F6821 */  addu  $t5, $t8, $t7
/* 115174 7F0E0644 91AC0000 */  lbu   $t4, ($t5)
/* 115178 7F0E0648 00194200 */  sll   $t0, $t9, 8
/* 11517C 7F0E064C 01884825 */  or    $t1, $t4, $t0
/* 115180 7F0E0650 1000086A */  b     .L7F0E27FC
/* 115184 7F0E0654 A7A90292 */   sh    $t1, 0x292($sp)
spectrum_op_ED_7C:
/* 115188 7F0E0658 00108023 */  negu  $s0, $s0
/* 11518C 7F0E065C 320D00FF */  andi  $t5, $s0, 0xff
/* 115190 7F0E0660 8FAB028C */  lw    $t3, 0x28c($sp)
/* 115194 7F0E0664 2DAF0001 */  sltiu $t7, $t5, 1
/* 115198 7F0E0668 31A8000F */  andi  $t0, $t5, 0xf
/* 11519C 7F0E066C 01A08025 */  move  $s0, $t5
/* 1151A0 7F0E0670 31B800A8 */  andi  $t8, $t5, 0xa8
/* 1151A4 7F0E0674 256A0004 */  addiu $t2, $t3, 4
/* 1151A8 7F0E0678 39AD0080 */  xori  $t5, $t5, 0x80
/* 1151AC 7F0E067C 0008482A */  slt   $t1, $zero, $t0
/* 1151B0 7F0E0680 000FC980 */  sll   $t9, $t7, 6
/* 1151B4 7F0E0684 AFAA028C */  sw    $t2, 0x28c($sp)
/* 1151B8 7F0E0688 03196025 */  or    $t4, $t8, $t9
/* 1151BC 7F0E068C 00095900 */  sll   $t3, $t1, 4
/* 1151C0 7F0E0690 2DAD0001 */  sltiu $t5, $t5, 1
/* 1151C4 7F0E0694 AFAF0048 */  sw    $t7, 0x48($sp)
/* 1151C8 7F0E0698 000D7880 */  sll   $t7, $t5, 2
/* 1151CC 7F0E069C 018B5025 */  or    $t2, $t4, $t3
/* 1151D0 7F0E06A0 014F7025 */  or    $t6, $t2, $t7
/* 1151D4 7F0E06A4 35D80002 */  ori   $t8, $t6, 2
/* 1151D8 7F0E06A8 0010C82A */  slt   $t9, $zero, $s0
/* 1151DC 7F0E06AC 03198825 */  or    $s1, $t8, $t9
/* 1151E0 7F0E06B0 322800FF */  andi  $t0, $s1, 0xff
/* 1151E4 7F0E06B4 10000851 */  b     .L7F0E27FC
/* 1151E8 7F0E06B8 01008825 */   move  $s1, $t0
spectrum_op_ED_7D:
/* 1151EC 7F0E06BC 8FA9028C */  lw    $t1, 0x28c($sp)
/* 1151F0 7F0E06C0 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 1151F4 7F0E06C4 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 1151F8 7F0E06C8 97AA0292 */  lhu   $t2, 0x292($sp)
/* 1151FC 7F0E06CC 252C0004 */  addiu $t4, $t1, 4
/* 115200 7F0E06D0 AFAC028C */  sw    $t4, 0x28c($sp)
/* 115204 7F0E06D4 258D0006 */  addiu $t5, $t4, 6
/* 115208 7F0E06D8 AFAD028C */  sw    $t5, 0x28c($sp)
/* 11520C 7F0E06DC 01EAC821 */  addu  $t9, $t7, $t2
/* 115210 7F0E06E0 93280001 */  lbu   $t0, 1($t9)
/* 115214 7F0E06E4 014F7021 */  addu  $t6, $t2, $t7
/* 115218 7F0E06E8 91D80000 */  lbu   $t8, ($t6)
/* 11521C 7F0E06EC 00084A00 */  sll   $t1, $t0, 8
/* 115220 7F0E06F0 254B0002 */  addiu $t3, $t2, 2
/* 115224 7F0E06F4 03096025 */  or    $t4, $t8, $t1
/* 115228 7F0E06F8 A7AC0298 */  sh    $t4, 0x298($sp)
/* 11522C 7F0E06FC 1000083F */  b     .L7F0E27FC
/* 115230 7F0E0700 A7AB0292 */   sh    $t3, 0x292($sp)
spectrum_op_ED_7E:
/* 115234 7F0E0704 8FAD028C */  lw    $t5, 0x28c($sp)
/* 115238 7F0E0708 240F0003 */  li    $t7, 3
/* 11523C 7F0E070C A3AF029B */  sb    $t7, 0x29b($sp)
/* 115240 7F0E0710 25AE0004 */  addiu $t6, $t5, 4
/* 115244 7F0E0714 10000839 */  b     .L7F0E27FC
/* 115248 7F0E0718 AFAE028C */   sw    $t6, 0x28c($sp)
spectrum_op_ED_A0:
/* 11524C 7F0E071C 8FB9028C */  lw    $t9, 0x28c($sp)
/* 115250 7F0E0720 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 115254 7F0E0724 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 115258 7F0E0728 0016C200 */  sll   $t8, $s6, 8
/* 11525C 7F0E072C 03174825 */  or    $t1, $t8, $s7
/* 115260 7F0E0730 2728000C */  addiu $t0, $t9, 0xc
/* 115264 7F0E0734 AFA8028C */  sw    $t0, 0x28c($sp)
/* 115268 7F0E0738 00146A00 */  sll   $t5, $s4, 8
/* 11526C 7F0E073C 012C5021 */  addu  $t2, $t1, $t4
/* 115270 7F0E0740 914B0000 */  lbu   $t3, ($t2)
/* 115274 7F0E0744 01B57025 */  or    $t6, $t5, $s5
/* 115278 7F0E0748 29C15B00 */  slti  $at, $t6, 0x5b00
/* 11527C 7F0E074C 14200008 */  bnez  $at, .L7F0E0770
/* 115280 7F0E0750 A3AB007D */   sb    $t3, 0x7d($sp)
/* 115284 7F0E0754 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 115288 7F0E0758 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 11528C 7F0E075C 00144200 */  sll   $t0, $s4, 8
/* 115290 7F0E0760 0115C025 */  or    $t8, $t0, $s5
/* 115294 7F0E0764 03384821 */  addu  $t1, $t9, $t8
/* 115298 7F0E0768 1000002B */  b     .L7F0E0818
/* 11529C 7F0E076C A12B0000 */   sb    $t3, ($t1)
.L7F0E0770:
/* 1152A0 7F0E0770 00146200 */  sll   $t4, $s4, 8
/* 1152A4 7F0E0774 01955025 */  or    $t2, $t4, $s5
/* 1152A8 7F0E0778 29415800 */  slti  $at, $t2, 0x5800
/* 1152AC 7F0E077C 14200010 */  bnez  $at, .L7F0E07C0
/* 1152B0 7F0E0780 00147200 */   sll   $t6, $s4, 8
/* 1152B4 7F0E0784 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 1152B8 7F0E0788 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 1152BC 7F0E078C 93AB007D */  lbu   $t3, 0x7d($sp)
/* 1152C0 7F0E0790 00147200 */  sll   $t6, $s4, 8
/* 1152C4 7F0E0794 01D54025 */  or    $t0, $t6, $s5
/* 1152C8 7F0E0798 01A8C821 */  addu  $t9, $t5, $t0
/* 1152CC 7F0E079C 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 1152D0 7F0E07A0 A32B0000 */  sb    $t3, ($t9)
/* 1152D4 7F0E07A4 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 1152D8 7F0E07A8 00144A00 */  sll   $t1, $s4, 8
/* 1152DC 7F0E07AC 01356025 */  or    $t4, $t1, $s5
/* 1152E0 7F0E07B0 24180001 */  li    $t8, 1
/* 1152E4 7F0E07B4 01EC5021 */  addu  $t2, $t7, $t4
/* 1152E8 7F0E07B8 10000017 */  b     .L7F0E0818
/* 1152EC 7F0E07BC A158A800 */   sb    $t8, -0x5800($t2)
.L7F0E07C0:
/* 1152F0 7F0E07C0 01D56825 */  or    $t5, $t6, $s5
/* 1152F4 7F0E07C4 29A14000 */  slti  $at, $t5, 0x4000
/* 1152F8 7F0E07C8 14200013 */  bnez  $at, .L7F0E0818
/* 1152FC 7F0E07CC 93A8007D */   lbu   $t0, 0x7d($sp)
/* 115300 7F0E07D0 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 115304 7F0E07D4 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 115308 7F0E07D8 0014CA00 */  sll   $t9, $s4, 8
/* 11530C 7F0E07DC 03354825 */  or    $t1, $t9, $s5
/* 115310 7F0E07E0 01697821 */  addu  $t7, $t3, $t1
/* 115314 7F0E07E4 A1E80000 */  sb    $t0, ($t7)
/* 115318 7F0E07E8 0014C200 */  sll   $t8, $s4, 8
/* 11531C 7F0E07EC 03155025 */  or    $t2, $t8, $s5
/* 115320 7F0E07F0 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 115324 7F0E07F4 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 115328 7F0E07F8 314E1800 */  andi  $t6, $t2, 0x1800
/* 11532C 7F0E07FC 03355825 */  or    $t3, $t9, $s5
/* 115330 7F0E0800 316900FF */  andi  $t1, $t3, 0xff
/* 115334 7F0E0804 000E68C3 */  sra   $t5, $t6, 3
/* 115338 7F0E0808 01A94025 */  or    $t0, $t5, $t1
/* 11533C 7F0E080C 240C0001 */  li    $t4, 1
/* 115340 7F0E0810 01E8C021 */  addu  $t8, $t7, $t0
/* 115344 7F0E0814 A30C0000 */  sb    $t4, ($t8)
.L7F0E0818:
/* 115348 7F0E0818 26F70001 */  addiu $s7, $s7, 1
/* 11534C 7F0E081C 32EA00FF */  andi  $t2, $s7, 0xff
/* 115350 7F0E0820 15400004 */  bnez  $t2, .L7F0E0834
/* 115354 7F0E0824 0140B825 */   move  $s7, $t2
/* 115358 7F0E0828 26D60001 */  addiu $s6, $s6, 1
/* 11535C 7F0E082C 32CE00FF */  andi  $t6, $s6, 0xff
/* 115360 7F0E0830 01C0B025 */  move  $s6, $t6
.L7F0E0834:
/* 115364 7F0E0834 26B50001 */  addiu $s5, $s5, 1
/* 115368 7F0E0838 32B900FF */  andi  $t9, $s5, 0xff
/* 11536C 7F0E083C 17200004 */  bnez  $t9, .L7F0E0850
/* 115370 7F0E0840 0320A825 */   move  $s5, $t9
/* 115374 7F0E0844 26940001 */  addiu $s4, $s4, 1
/* 115378 7F0E0848 328B00FF */  andi  $t3, $s4, 0xff
/* 11537C 7F0E084C 0160A025 */  move  $s4, $t3
.L7F0E0850:
/* 115380 7F0E0850 2E6D0001 */  sltiu $t5, $s3, 1
/* 115384 7F0E0854 2673FFFF */  addiu $s3, $s3, -1
/* 115388 7F0E0858 326900FF */  andi  $t1, $s3, 0xff
/* 11538C 7F0E085C 01209825 */  move  $s3, $t1
/* 115390 7F0E0860 11A00004 */  beqz  $t5, .L7F0E0874
/* 115394 7F0E0864 AFAD0048 */   sw    $t5, 0x48($sp)
/* 115398 7F0E0868 2652FFFF */  addiu $s2, $s2, -1
/* 11539C 7F0E086C 324800FF */  andi  $t0, $s2, 0xff
/* 1153A0 7F0E0870 01009025 */  move  $s2, $t0
.L7F0E0874:
/* 1153A4 7F0E0874 93B8007D */  lbu   $t8, 0x7d($sp)
/* 1153A8 7F0E0878 0253C825 */  or    $t9, $s2, $s3
/* 1153AC 7F0E087C 0019582A */  slt   $t3, $zero, $t9
/* 1153B0 7F0E0880 322C00C1 */  andi  $t4, $s1, 0xc1
/* 1153B4 7F0E0884 330A0028 */  andi  $t2, $t8, 0x28
/* 1153B8 7F0E0888 018A7025 */  or    $t6, $t4, $t2
/* 1153BC 7F0E088C 000B6880 */  sll   $t5, $t3, 2
/* 1153C0 7F0E0890 01CD8825 */  or    $s1, $t6, $t5
/* 1153C4 7F0E0894 322900FF */  andi  $t1, $s1, 0xff
/* 1153C8 7F0E0898 100007D8 */  b     .L7F0E27FC
/* 1153CC 7F0E089C 01208825 */   move  $s1, $t1
spectrum_op_ED_A1:
/* 1153D0 7F0E08A0 8FAF028C */  lw    $t7, 0x28c($sp)
/* 1153D4 7F0E08A4 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 1153D8 7F0E08A8 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 1153DC 7F0E08AC 00166200 */  sll   $t4, $s6, 8
/* 1153E0 7F0E08B0 32380001 */  andi  $t8, $s1, 1
/* 1153E4 7F0E08B4 01975025 */  or    $t2, $t4, $s7
/* 1153E8 7F0E08B8 25E8000C */  addiu $t0, $t7, 0xc
/* 1153EC 7F0E08BC AFA8028C */  sw    $t0, 0x28c($sp)
/* 1153F0 7F0E08C0 A3B8007C */  sb    $t8, 0x7c($sp)
/* 1153F4 7F0E08C4 01595821 */  addu  $t3, $t2, $t9
/* 1153F8 7F0E08C8 916E0000 */  lbu   $t6, ($t3)
/* 1153FC 7F0E08CC 26F70001 */  addiu $s7, $s7, 1
/* 115400 7F0E08D0 020E6823 */  subu  $t5, $s0, $t6
/* 115404 7F0E08D4 31A901FF */  andi  $t1, $t5, 0x1ff
/* 115408 7F0E08D8 312FFFFF */  andi  $t7, $t1, 0xffff
/* 11540C 7F0E08DC 2DE80001 */  sltiu $t0, $t7, 1
/* 115410 7F0E08E0 320F000F */  andi  $t7, $s0, 0xf
/* 115414 7F0E08E4 31CD000F */  andi  $t5, $t6, 0xf
/* 115418 7F0E08E8 01EDC02A */  slt   $t8, $t7, $t5
/* 11541C 7F0E08EC 312C00A8 */  andi  $t4, $t1, 0xa8
/* 115420 7F0E08F0 0009CA03 */  sra   $t9, $t1, 8
/* 115424 7F0E08F4 01995825 */  or    $t3, $t4, $t9
/* 115428 7F0E08F8 00185100 */  sll   $t2, $t8, 4
/* 11542C 7F0E08FC 01206825 */  move  $t5, $t1
/* 115430 7F0E0900 020EC826 */  xor   $t9, $s0, $t6
/* 115434 7F0E0904 332F0080 */  andi  $t7, $t9, 0x80
/* 115438 7F0E0908 01B0C026 */  xor   $t8, $t5, $s0
/* 11543C 7F0E090C 016A6025 */  or    $t4, $t3, $t2
/* 115440 7F0E0910 01F85824 */  and   $t3, $t7, $t8
/* 115444 7F0E0914 000B5143 */  sra   $t2, $t3, 5
/* 115448 7F0E0918 A3AE0079 */  sb    $t6, 0x79($sp)
/* 11544C 7F0E091C 018A7025 */  or    $t6, $t4, $t2
/* 115450 7F0E0920 A7A9007A */  sh    $t1, 0x7a($sp)
/* 115454 7F0E0924 00084980 */  sll   $t1, $t0, 6
/* 115458 7F0E0928 35D90002 */  ori   $t9, $t6, 2
/* 11545C 7F0E092C 03298825 */  or    $s1, $t9, $t1
/* 115460 7F0E0930 322D00FF */  andi  $t5, $s1, 0xff
/* 115464 7F0E0934 32EF00FF */  andi  $t7, $s7, 0xff
/* 115468 7F0E0938 01A08825 */  move  $s1, $t5
/* 11546C 7F0E093C AFA80048 */  sw    $t0, 0x48($sp)
/* 115470 7F0E0940 15E00004 */  bnez  $t7, .L7F0E0954
/* 115474 7F0E0944 01E0B825 */   move  $s7, $t7
/* 115478 7F0E0948 26D60001 */  addiu $s6, $s6, 1
/* 11547C 7F0E094C 32D800FF */  andi  $t8, $s6, 0xff
/* 115480 7F0E0950 0300B025 */  move  $s6, $t8
.L7F0E0954:
/* 115484 7F0E0954 2E6B0001 */  sltiu $t3, $s3, 1
/* 115488 7F0E0958 2673FFFF */  addiu $s3, $s3, -1
/* 11548C 7F0E095C 326C00FF */  andi  $t4, $s3, 0xff
/* 115490 7F0E0960 01809825 */  move  $s3, $t4
/* 115494 7F0E0964 11600004 */  beqz  $t3, .L7F0E0978
/* 115498 7F0E0968 AFAB0048 */   sw    $t3, 0x48($sp)
/* 11549C 7F0E096C 2652FFFF */  addiu $s2, $s2, -1
/* 1154A0 7F0E0970 324E00FF */  andi  $t6, $s2, 0xff
/* 1154A4 7F0E0974 01C09025 */  move  $s2, $t6
.L7F0E0978:
/* 1154A8 7F0E0978 93B9007C */  lbu   $t9, 0x7c($sp)
/* 1154AC 7F0E097C 02536825 */  or    $t5, $s2, $s3
/* 1154B0 7F0E0980 000D782A */  slt   $t7, $zero, $t5
/* 1154B4 7F0E0984 322800FA */  andi  $t0, $s1, 0xfa
/* 1154B8 7F0E0988 000FC080 */  sll   $t8, $t7, 2
/* 1154BC 7F0E098C 01194825 */  or    $t1, $t0, $t9
/* 1154C0 7F0E0990 01388825 */  or    $s1, $t1, $t8
/* 1154C4 7F0E0994 322B00FF */  andi  $t3, $s1, 0xff
/* 1154C8 7F0E0998 10000798 */  b     .L7F0E27FC
/* 1154CC 7F0E099C 01608825 */   move  $s1, $t3
spectrum_op_ED_A2:
/* 1154D0 7F0E09A0 8FAC028C */  lw    $t4, 0x28c($sp)
/* 1154D4 7F0E09A4 02402825 */  move  $a1, $s2
/* 1154D8 7F0E09A8 02603025 */  move  $a2, $s3
/* 1154DC 7F0E09AC 2584000C */  addiu $a0, $t4, 0xc
/* 1154E0 7F0E09B0 0FC34DB6 */  jal   spectrum_input_handling
/* 1154E4 7F0E09B4 AFA4028C */   sw    $a0, 0x28c($sp)
/* 1154E8 7F0E09B8 00167200 */  sll   $t6, $s6, 8
/* 1154EC 7F0E09BC 01D74025 */  or    $t0, $t6, $s7
/* 1154F0 7F0E09C0 29015B00 */  slti  $at, $t0, 0x5b00
/* 1154F4 7F0E09C4 14200008 */  bnez  $at, .L7F0E09E8
/* 1154F8 7F0E09C8 A7A20076 */   sh    $v0, 0x76($sp)
/* 1154FC 7F0E09CC 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 115500 7F0E09D0 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 115504 7F0E09D4 00167A00 */  sll   $t7, $s6, 8
/* 115508 7F0E09D8 01F74825 */  or    $t1, $t7, $s7
/* 11550C 7F0E09DC 01A9C021 */  addu  $t8, $t5, $t1
/* 115510 7F0E09E0 1000002B */  b     .L7F0E0A90
/* 115514 7F0E09E4 A3020000 */   sb    $v0, ($t8)
.L7F0E09E8:
/* 115518 7F0E09E8 00165A00 */  sll   $t3, $s6, 8
/* 11551C 7F0E09EC 01776025 */  or    $t4, $t3, $s7
/* 115520 7F0E09F0 29815800 */  slti  $at, $t4, 0x5800
/* 115524 7F0E09F4 14200010 */  bnez  $at, .L7F0E0A38
/* 115528 7F0E09F8 00164200 */   sll   $t0, $s6, 8
/* 11552C 7F0E09FC 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 115530 7F0E0A00 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 115534 7F0E0A04 97AA0076 */  lhu   $t2, 0x76($sp)
/* 115538 7F0E0A08 00164200 */  sll   $t0, $s6, 8
/* 11553C 7F0E0A0C 01177825 */  or    $t7, $t0, $s7
/* 115540 7F0E0A10 01CF6821 */  addu  $t5, $t6, $t7
/* 115544 7F0E0A14 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 115548 7F0E0A18 A1AA0000 */  sb    $t2, ($t5)
/* 11554C 7F0E0A1C 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 115550 7F0E0A20 0016C200 */  sll   $t8, $s6, 8
/* 115554 7F0E0A24 03175825 */  or    $t3, $t8, $s7
/* 115558 7F0E0A28 24090001 */  li    $t1, 1
/* 11555C 7F0E0A2C 032B6021 */  addu  $t4, $t9, $t3
/* 115560 7F0E0A30 10000017 */  b     .L7F0E0A90
/* 115564 7F0E0A34 A189A800 */   sb    $t1, -0x5800($t4)
.L7F0E0A38:
/* 115568 7F0E0A38 01177025 */  or    $t6, $t0, $s7
/* 11556C 7F0E0A3C 29C14000 */  slti  $at, $t6, 0x4000
/* 115570 7F0E0A40 14200013 */  bnez  $at, .L7F0E0A90
/* 115574 7F0E0A44 97AF0076 */   lhu   $t7, 0x76($sp)
/* 115578 7F0E0A48 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 11557C 7F0E0A4C 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 115580 7F0E0A50 00166A00 */  sll   $t5, $s6, 8
/* 115584 7F0E0A54 01B7C025 */  or    $t8, $t5, $s7
/* 115588 7F0E0A58 0158C821 */  addu  $t9, $t2, $t8
/* 11558C 7F0E0A5C A32F0000 */  sb    $t7, ($t9)
/* 115590 7F0E0A60 00164A00 */  sll   $t1, $s6, 8
/* 115594 7F0E0A64 01376025 */  or    $t4, $t1, $s7
/* 115598 7F0E0A68 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 11559C 7F0E0A6C 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 1155A0 7F0E0A70 31881800 */  andi  $t0, $t4, 0x1800
/* 1155A4 7F0E0A74 01B75025 */  or    $t2, $t5, $s7
/* 1155A8 7F0E0A78 315800FF */  andi  $t8, $t2, 0xff
/* 1155AC 7F0E0A7C 000870C3 */  sra   $t6, $t0, 3
/* 1155B0 7F0E0A80 01D87825 */  or    $t7, $t6, $t8
/* 1155B4 7F0E0A84 240B0001 */  li    $t3, 1
/* 1155B8 7F0E0A88 032F4821 */  addu  $t1, $t9, $t7
/* 1155BC 7F0E0A8C A12B0000 */  sb    $t3, ($t1)
.L7F0E0A90:
/* 1155C0 7F0E0A90 97A80076 */  lhu   $t0, 0x76($sp)
/* 1155C4 7F0E0A94 8FAC028C */  lw    $t4, 0x28c($sp)
/* 1155C8 7F0E0A98 26F70001 */  addiu $s7, $s7, 1
/* 1155CC 7F0E0A9C 00086A03 */  sra   $t5, $t0, 8
/* 1155D0 7F0E0AA0 32EE00FF */  andi  $t6, $s7, 0xff
/* 1155D4 7F0E0AA4 018D5021 */  addu  $t2, $t4, $t5
/* 1155D8 7F0E0AA8 AFAA028C */  sw    $t2, 0x28c($sp)
/* 1155DC 7F0E0AAC 15C00004 */  bnez  $t6, .L7F0E0AC0
/* 1155E0 7F0E0AB0 01C0B825 */   move  $s7, $t6
/* 1155E4 7F0E0AB4 26D60001 */  addiu $s6, $s6, 1
/* 1155E8 7F0E0AB8 32D800FF */  andi  $t8, $s6, 0xff
/* 1155EC 7F0E0ABC 0300B025 */  move  $s6, $t8
.L7F0E0AC0:
/* 1155F0 7F0E0AC0 3C0D8009 */  lui   $t5, %hi(ptr_pc_keyboard_table_alloc) 
/* 1155F4 7F0E0AC4 8DADE334 */  lw    $t5, %lo(ptr_pc_keyboard_table_alloc)($t5)
/* 1155F8 7F0E0AC8 2652FFFF */  addiu $s2, $s2, -1
/* 1155FC 7F0E0ACC 325900FF */  andi  $t9, $s2, 0xff
/* 115600 7F0E0AD0 032D5021 */  addu  $t2, $t9, $t5
/* 115604 7F0E0AD4 914E0000 */  lbu   $t6, ($t2)
/* 115608 7F0E0AD8 0019582A */  slt   $t3, $zero, $t9
/* 11560C 7F0E0ADC 000B4980 */  sll   $t1, $t3, 6
/* 115610 7F0E0AE0 332F00A8 */  andi  $t7, $t9, 0xa8
/* 115614 7F0E0AE4 03209025 */  move  $s2, $t9
/* 115618 7F0E0AE8 01E94025 */  or    $t0, $t7, $t1
/* 11561C 7F0E0AEC 01D3C026 */  xor   $t8, $t6, $s3
/* 115620 7F0E0AF0 33190004 */  andi  $t9, $t8, 4
/* 115624 7F0E0AF4 350C0002 */  ori   $t4, $t0, 2
/* 115628 7F0E0AF8 032C8825 */  or    $s1, $t9, $t4
/* 11562C 7F0E0AFC 322B00FF */  andi  $t3, $s1, 0xff
/* 115630 7F0E0B00 1000073E */  b     .L7F0E27FC
/* 115634 7F0E0B04 01608825 */   move  $s1, $t3
spectrum_op_ED_A3:
/* 115638 7F0E0B08 8FAF028C */  lw    $t7, 0x28c($sp)
/* 11563C 7F0E0B0C 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 115640 7F0E0B10 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 115644 7F0E0B14 00164200 */  sll   $t0, $s6, 8
/* 115648 7F0E0B18 01176825 */  or    $t5, $t0, $s7
/* 11564C 7F0E0B1C 25E4000C */  addiu $a0, $t7, 0xc
/* 115650 7F0E0B20 AFA4028C */  sw    $a0, 0x28c($sp)
/* 115654 7F0E0B24 01AA7021 */  addu  $t6, $t5, $t2
/* 115658 7F0E0B28 91C70000 */  lbu   $a3, ($t6)
/* 11565C 7F0E0B2C 02402825 */  move  $a1, $s2
/* 115660 7F0E0B30 02603025 */  move  $a2, $s3
/* 115664 7F0E0B34 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 115668 7F0E0B38 A3A70075 */   sb    $a3, 0x75($sp)
/* 11566C 7F0E0B3C 8FB9028C */  lw    $t9, 0x28c($sp)
/* 115670 7F0E0B40 26F70001 */  addiu $s7, $s7, 1
/* 115674 7F0E0B44 32EF00FF */  andi  $t7, $s7, 0xff
/* 115678 7F0E0B48 03225821 */  addu  $t3, $t9, $v0
/* 11567C 7F0E0B4C AFAB028C */  sw    $t3, 0x28c($sp)
/* 115680 7F0E0B50 AFA20048 */  sw    $v0, 0x48($sp)
/* 115684 7F0E0B54 15E00004 */  bnez  $t7, .L7F0E0B68
/* 115688 7F0E0B58 01E0B825 */   move  $s7, $t7
/* 11568C 7F0E0B5C 26D60001 */  addiu $s6, $s6, 1
/* 115690 7F0E0B60 32C800FF */  andi  $t0, $s6, 0xff
/* 115694 7F0E0B64 0100B025 */  move  $s6, $t0
.L7F0E0B68:
/* 115698 7F0E0B68 2652FFFF */  addiu $s2, $s2, -1
/* 11569C 7F0E0B6C 324D00FF */  andi  $t5, $s2, 0xff
/* 1156A0 7F0E0B70 322A0001 */  andi  $t2, $s1, 1
/* 1156A4 7F0E0B74 354E0012 */  ori   $t6, $t2, 0x12
/* 1156A8 7F0E0B78 31A900A8 */  andi  $t1, $t5, 0xa8
/* 1156AC 7F0E0B7C 2DB90001 */  sltiu $t9, $t5, 1
/* 1156B0 7F0E0B80 00196180 */  sll   $t4, $t9, 6
/* 1156B4 7F0E0B84 01C9C025 */  or    $t8, $t6, $t1
/* 1156B8 7F0E0B88 030C8825 */  or    $s1, $t8, $t4
/* 1156BC 7F0E0B8C 322B00FF */  andi  $t3, $s1, 0xff
/* 1156C0 7F0E0B90 01A09025 */  move  $s2, $t5
/* 1156C4 7F0E0B94 10000719 */  b     .L7F0E27FC
/* 1156C8 7F0E0B98 01608825 */   move  $s1, $t3
spectrum_op_ED_A8:
/* 1156CC 7F0E0B9C 8FAF028C */  lw    $t7, 0x28c($sp)
/* 1156D0 7F0E0BA0 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 1156D4 7F0E0BA4 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 1156D8 7F0E0BA8 00166A00 */  sll   $t5, $s6, 8
/* 1156DC 7F0E0BAC 01B75025 */  or    $t2, $t5, $s7
/* 1156E0 7F0E0BB0 25E8000C */  addiu $t0, $t7, 0xc
/* 1156E4 7F0E0BB4 AFA8028C */  sw    $t0, 0x28c($sp)
/* 1156E8 7F0E0BB8 0014C200 */  sll   $t8, $s4, 8
/* 1156EC 7F0E0BBC 014E4821 */  addu  $t1, $t2, $t6
/* 1156F0 7F0E0BC0 91390000 */  lbu   $t9, ($t1)
/* 1156F4 7F0E0BC4 03156025 */  or    $t4, $t8, $s5
/* 1156F8 7F0E0BC8 29815B00 */  slti  $at, $t4, 0x5b00
/* 1156FC 7F0E0BCC 14200008 */  bnez  $at, .L7F0E0BF0
/* 115700 7F0E0BD0 A3B90074 */   sb    $t9, 0x74($sp)
/* 115704 7F0E0BD4 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 115708 7F0E0BD8 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 11570C 7F0E0BDC 00144200 */  sll   $t0, $s4, 8
/* 115710 7F0E0BE0 01156825 */  or    $t5, $t0, $s5
/* 115714 7F0E0BE4 01ED5021 */  addu  $t2, $t7, $t5
/* 115718 7F0E0BE8 1000002B */  b     .L7F0E0C98
/* 11571C 7F0E0BEC A1590000 */   sb    $t9, ($t2)
.L7F0E0BF0:
/* 115720 7F0E0BF0 00147200 */  sll   $t6, $s4, 8
/* 115724 7F0E0BF4 01D54825 */  or    $t1, $t6, $s5
/* 115728 7F0E0BF8 29215800 */  slti  $at, $t1, 0x5800
/* 11572C 7F0E0BFC 14200010 */  bnez  $at, .L7F0E0C40
/* 115730 7F0E0C00 00146200 */   sll   $t4, $s4, 8
/* 115734 7F0E0C04 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 115738 7F0E0C08 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 11573C 7F0E0C0C 93B90074 */  lbu   $t9, 0x74($sp)
/* 115740 7F0E0C10 00146200 */  sll   $t4, $s4, 8
/* 115744 7F0E0C14 01954025 */  or    $t0, $t4, $s5
/* 115748 7F0E0C18 03087821 */  addu  $t7, $t8, $t0
/* 11574C 7F0E0C1C 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 115750 7F0E0C20 A1F90000 */  sb    $t9, ($t7)
/* 115754 7F0E0C24 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 115758 7F0E0C28 00145200 */  sll   $t2, $s4, 8
/* 11575C 7F0E0C2C 01557025 */  or    $t6, $t2, $s5
/* 115760 7F0E0C30 240D0001 */  li    $t5, 1
/* 115764 7F0E0C34 016E4821 */  addu  $t1, $t3, $t6
/* 115768 7F0E0C38 10000017 */  b     .L7F0E0C98
/* 11576C 7F0E0C3C A12DA800 */   sb    $t5, -0x5800($t1)
.L7F0E0C40:
/* 115770 7F0E0C40 0195C025 */  or    $t8, $t4, $s5
/* 115774 7F0E0C44 2B014000 */  slti  $at, $t8, 0x4000
/* 115778 7F0E0C48 14200013 */  bnez  $at, .L7F0E0C98
/* 11577C 7F0E0C4C 93A80074 */   lbu   $t0, 0x74($sp)
/* 115780 7F0E0C50 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 115784 7F0E0C54 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 115788 7F0E0C58 00147A00 */  sll   $t7, $s4, 8
/* 11578C 7F0E0C5C 01F55025 */  or    $t2, $t7, $s5
/* 115790 7F0E0C60 032A5821 */  addu  $t3, $t9, $t2
/* 115794 7F0E0C64 A1680000 */  sb    $t0, ($t3)
/* 115798 7F0E0C68 00146A00 */  sll   $t5, $s4, 8
/* 11579C 7F0E0C6C 01B54825 */  or    $t1, $t5, $s5
/* 1157A0 7F0E0C70 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 1157A4 7F0E0C74 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 1157A8 7F0E0C78 312C1800 */  andi  $t4, $t1, 0x1800
/* 1157AC 7F0E0C7C 01F5C825 */  or    $t9, $t7, $s5
/* 1157B0 7F0E0C80 332A00FF */  andi  $t2, $t9, 0xff
/* 1157B4 7F0E0C84 000CC0C3 */  sra   $t8, $t4, 3
/* 1157B8 7F0E0C88 030A4025 */  or    $t0, $t8, $t2
/* 1157BC 7F0E0C8C 240E0001 */  li    $t6, 1
/* 1157C0 7F0E0C90 01686821 */  addu  $t5, $t3, $t0
/* 1157C4 7F0E0C94 A1AE0000 */  sb    $t6, ($t5)
.L7F0E0C98:
/* 1157C8 7F0E0C98 2EE90001 */  sltiu $t1, $s7, 1
/* 1157CC 7F0E0C9C 26F7FFFF */  addiu $s7, $s7, -1
/* 1157D0 7F0E0CA0 32EC00FF */  andi  $t4, $s7, 0xff
/* 1157D4 7F0E0CA4 0180B825 */  move  $s7, $t4
/* 1157D8 7F0E0CA8 11200004 */  beqz  $t1, .L7F0E0CBC
/* 1157DC 7F0E0CAC AFA90048 */   sw    $t1, 0x48($sp)
/* 1157E0 7F0E0CB0 26D6FFFF */  addiu $s6, $s6, -1
/* 1157E4 7F0E0CB4 32D900FF */  andi  $t9, $s6, 0xff
/* 1157E8 7F0E0CB8 0320B025 */  move  $s6, $t9
.L7F0E0CBC:
/* 1157EC 7F0E0CBC 2EB80001 */  sltiu $t8, $s5, 1
/* 1157F0 7F0E0CC0 26B5FFFF */  addiu $s5, $s5, -1
/* 1157F4 7F0E0CC4 32AA00FF */  andi  $t2, $s5, 0xff
/* 1157F8 7F0E0CC8 0140A825 */  move  $s5, $t2
/* 1157FC 7F0E0CCC 13000004 */  beqz  $t8, .L7F0E0CE0
/* 115800 7F0E0CD0 AFB80048 */   sw    $t8, 0x48($sp)
/* 115804 7F0E0CD4 2694FFFF */  addiu $s4, $s4, -1
/* 115808 7F0E0CD8 328800FF */  andi  $t0, $s4, 0xff
/* 11580C 7F0E0CDC 0100A025 */  move  $s4, $t0
.L7F0E0CE0:
/* 115810 7F0E0CE0 2E6E0001 */  sltiu $t6, $s3, 1
/* 115814 7F0E0CE4 2673FFFF */  addiu $s3, $s3, -1
/* 115818 7F0E0CE8 326D00FF */  andi  $t5, $s3, 0xff
/* 11581C 7F0E0CEC 01A09825 */  move  $s3, $t5
/* 115820 7F0E0CF0 11C00004 */  beqz  $t6, .L7F0E0D04
/* 115824 7F0E0CF4 AFAE0048 */   sw    $t6, 0x48($sp)
/* 115828 7F0E0CF8 2652FFFF */  addiu $s2, $s2, -1
/* 11582C 7F0E0CFC 324C00FF */  andi  $t4, $s2, 0xff
/* 115830 7F0E0D00 01809025 */  move  $s2, $t4
.L7F0E0D04:
/* 115834 7F0E0D04 93B90074 */  lbu   $t9, 0x74($sp)
/* 115838 7F0E0D08 02535825 */  or    $t3, $s2, $s3
/* 11583C 7F0E0D0C 000B402A */  slt   $t0, $zero, $t3
/* 115840 7F0E0D10 322F00C1 */  andi  $t7, $s1, 0xc1
/* 115844 7F0E0D14 33380028 */  andi  $t8, $t9, 0x28
/* 115848 7F0E0D18 01F85025 */  or    $t2, $t7, $t8
/* 11584C 7F0E0D1C 00087080 */  sll   $t6, $t0, 2
/* 115850 7F0E0D20 014E8825 */  or    $s1, $t2, $t6
/* 115854 7F0E0D24 322D00FF */  andi  $t5, $s1, 0xff
/* 115858 7F0E0D28 100006B4 */  b     .L7F0E27FC
/* 11585C 7F0E0D2C 01A08825 */   move  $s1, $t5
spectrum_op_ED_A9:
/* 115860 7F0E0D30 8FA9028C */  lw    $t1, 0x28c($sp)
/* 115864 7F0E0D34 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 115868 7F0E0D38 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 11586C 7F0E0D3C 00167A00 */  sll   $t7, $s6, 8
/* 115870 7F0E0D40 32390001 */  andi  $t9, $s1, 1
/* 115874 7F0E0D44 01F7C025 */  or    $t8, $t7, $s7
/* 115878 7F0E0D48 252C000C */  addiu $t4, $t1, 0xc
/* 11587C 7F0E0D4C AFAC028C */  sw    $t4, 0x28c($sp)
/* 115880 7F0E0D50 A3B90073 */  sb    $t9, 0x73($sp)
/* 115884 7F0E0D54 030B4021 */  addu  $t0, $t8, $t3
/* 115888 7F0E0D58 910A0000 */  lbu   $t2, ($t0)
/* 11588C 7F0E0D5C 020A7023 */  subu  $t6, $s0, $t2
/* 115890 7F0E0D60 31CD01FF */  andi  $t5, $t6, 0x1ff
/* 115894 7F0E0D64 31A9FFFF */  andi  $t1, $t5, 0xffff
/* 115898 7F0E0D68 2D2C0001 */  sltiu $t4, $t1, 1
/* 11589C 7F0E0D6C 3209000F */  andi  $t1, $s0, 0xf
/* 1158A0 7F0E0D70 314E000F */  andi  $t6, $t2, 0xf
/* 1158A4 7F0E0D74 012EC82A */  slt   $t9, $t1, $t6
/* 1158A8 7F0E0D78 31AF00A8 */  andi  $t7, $t5, 0xa8
/* 1158AC 7F0E0D7C 000D5A03 */  sra   $t3, $t5, 8
/* 1158B0 7F0E0D80 01EB4025 */  or    $t0, $t7, $t3
/* 1158B4 7F0E0D84 0019C100 */  sll   $t8, $t9, 4
/* 1158B8 7F0E0D88 01A07025 */  move  $t6, $t5
/* 1158BC 7F0E0D8C 020A5826 */  xor   $t3, $s0, $t2
/* 1158C0 7F0E0D90 31690080 */  andi  $t1, $t3, 0x80
/* 1158C4 7F0E0D94 01D0C826 */  xor   $t9, $t6, $s0
/* 1158C8 7F0E0D98 01187825 */  or    $t7, $t0, $t8
/* 1158CC 7F0E0D9C 01394024 */  and   $t0, $t1, $t9
/* 1158D0 7F0E0DA0 0008C143 */  sra   $t8, $t0, 5
/* 1158D4 7F0E0DA4 A3AA006F */  sb    $t2, 0x6f($sp)
/* 1158D8 7F0E0DA8 01F85025 */  or    $t2, $t7, $t8
/* 1158DC 7F0E0DAC A7AD0070 */  sh    $t5, 0x70($sp)
/* 1158E0 7F0E0DB0 000C6980 */  sll   $t5, $t4, 6
/* 1158E4 7F0E0DB4 354B0002 */  ori   $t3, $t2, 2
/* 1158E8 7F0E0DB8 2EE90001 */  sltiu $t1, $s7, 1
/* 1158EC 7F0E0DBC 016D8825 */  or    $s1, $t3, $t5
/* 1158F0 7F0E0DC0 26F7FFFF */  addiu $s7, $s7, -1
/* 1158F4 7F0E0DC4 322E00FF */  andi  $t6, $s1, 0xff
/* 1158F8 7F0E0DC8 AFAC0048 */  sw    $t4, 0x48($sp)
/* 1158FC 7F0E0DCC 32F900FF */  andi  $t9, $s7, 0xff
/* 115900 7F0E0DD0 01C08825 */  move  $s1, $t6
/* 115904 7F0E0DD4 0320B825 */  move  $s7, $t9
/* 115908 7F0E0DD8 11200004 */  beqz  $t1, .L7F0E0DEC
/* 11590C 7F0E0DDC AFA90048 */   sw    $t1, 0x48($sp)
/* 115910 7F0E0DE0 26D6FFFF */  addiu $s6, $s6, -1
/* 115914 7F0E0DE4 32CF00FF */  andi  $t7, $s6, 0xff
/* 115918 7F0E0DE8 01E0B025 */  move  $s6, $t7
.L7F0E0DEC:
/* 11591C 7F0E0DEC 2E780001 */  sltiu $t8, $s3, 1
/* 115920 7F0E0DF0 2673FFFF */  addiu $s3, $s3, -1
/* 115924 7F0E0DF4 326A00FF */  andi  $t2, $s3, 0xff
/* 115928 7F0E0DF8 01409825 */  move  $s3, $t2
/* 11592C 7F0E0DFC 13000004 */  beqz  $t8, .L7F0E0E10
/* 115930 7F0E0E00 AFB80048 */   sw    $t8, 0x48($sp)
/* 115934 7F0E0E04 2652FFFF */  addiu $s2, $s2, -1
/* 115938 7F0E0E08 324B00FF */  andi  $t3, $s2, 0xff
/* 11593C 7F0E0E0C 01609025 */  move  $s2, $t3
.L7F0E0E10:
/* 115940 7F0E0E10 93AE0073 */  lbu   $t6, 0x73($sp)
/* 115944 7F0E0E14 0253C825 */  or    $t9, $s2, $s3
/* 115948 7F0E0E18 0019402A */  slt   $t0, $zero, $t9
/* 11594C 7F0E0E1C 322D00FA */  andi  $t5, $s1, 0xfa
/* 115950 7F0E0E20 00087880 */  sll   $t7, $t0, 2
/* 115954 7F0E0E24 01AE4825 */  or    $t1, $t5, $t6
/* 115958 7F0E0E28 012F8825 */  or    $s1, $t1, $t7
/* 11595C 7F0E0E2C 323800FF */  andi  $t8, $s1, 0xff
/* 115960 7F0E0E30 10000672 */  b     .L7F0E27FC
/* 115964 7F0E0E34 03008825 */   move  $s1, $t8
spectrum_op_ED_AA:
/* 115968 7F0E0E38 8FAA028C */  lw    $t2, 0x28c($sp)
/* 11596C 7F0E0E3C 02402825 */  move  $a1, $s2
/* 115970 7F0E0E40 02603025 */  move  $a2, $s3
/* 115974 7F0E0E44 2544000C */  addiu $a0, $t2, 0xc
/* 115978 7F0E0E48 0FC34DB6 */  jal   spectrum_input_handling
/* 11597C 7F0E0E4C AFA4028C */   sw    $a0, 0x28c($sp)
/* 115980 7F0E0E50 00165A00 */  sll   $t3, $s6, 8
/* 115984 7F0E0E54 01776825 */  or    $t5, $t3, $s7
/* 115988 7F0E0E58 29A15B00 */  slti  $at, $t5, 0x5b00
/* 11598C 7F0E0E5C 14200008 */  bnez  $at, .L7F0E0E80
/* 115990 7F0E0E60 A7A2006C */   sh    $v0, 0x6c($sp)
/* 115994 7F0E0E64 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 115998 7F0E0E68 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 11599C 7F0E0E6C 00164200 */  sll   $t0, $s6, 8
/* 1159A0 7F0E0E70 01174825 */  or    $t1, $t0, $s7
/* 1159A4 7F0E0E74 03297821 */  addu  $t7, $t9, $t1
/* 1159A8 7F0E0E78 1000002B */  b     .L7F0E0F28
/* 1159AC 7F0E0E7C A1E20000 */   sb    $v0, ($t7)
.L7F0E0E80:
/* 1159B0 7F0E0E80 0016C200 */  sll   $t8, $s6, 8
/* 1159B4 7F0E0E84 03175025 */  or    $t2, $t8, $s7
/* 1159B8 7F0E0E88 29415800 */  slti  $at, $t2, 0x5800
/* 1159BC 7F0E0E8C 14200010 */  bnez  $at, .L7F0E0ED0
/* 1159C0 7F0E0E90 00166A00 */   sll   $t5, $s6, 8
/* 1159C4 7F0E0E94 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 1159C8 7F0E0E98 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 1159CC 7F0E0E9C 97AC006C */  lhu   $t4, 0x6c($sp)
/* 1159D0 7F0E0EA0 00166A00 */  sll   $t5, $s6, 8
/* 1159D4 7F0E0EA4 01B74025 */  or    $t0, $t5, $s7
/* 1159D8 7F0E0EA8 0168C821 */  addu  $t9, $t3, $t0
/* 1159DC 7F0E0EAC 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 1159E0 7F0E0EB0 A32C0000 */  sb    $t4, ($t9)
/* 1159E4 7F0E0EB4 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 1159E8 7F0E0EB8 00167A00 */  sll   $t7, $s6, 8
/* 1159EC 7F0E0EBC 01F7C025 */  or    $t8, $t7, $s7
/* 1159F0 7F0E0EC0 24090001 */  li    $t1, 1
/* 1159F4 7F0E0EC4 01D85021 */  addu  $t2, $t6, $t8
/* 1159F8 7F0E0EC8 10000017 */  b     .L7F0E0F28
/* 1159FC 7F0E0ECC A149A800 */   sb    $t1, -0x5800($t2)
.L7F0E0ED0:
/* 115A00 7F0E0ED0 01B75825 */  or    $t3, $t5, $s7
/* 115A04 7F0E0ED4 29614000 */  slti  $at, $t3, 0x4000
/* 115A08 7F0E0ED8 14200013 */  bnez  $at, .L7F0E0F28
/* 115A0C 7F0E0EDC 97A8006C */   lhu   $t0, 0x6c($sp)
/* 115A10 7F0E0EE0 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 115A14 7F0E0EE4 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 115A18 7F0E0EE8 0016CA00 */  sll   $t9, $s6, 8
/* 115A1C 7F0E0EEC 03377825 */  or    $t7, $t9, $s7
/* 115A20 7F0E0EF0 018F7021 */  addu  $t6, $t4, $t7
/* 115A24 7F0E0EF4 A1C80000 */  sb    $t0, ($t6)
/* 115A28 7F0E0EF8 00164A00 */  sll   $t1, $s6, 8
/* 115A2C 7F0E0EFC 01375025 */  or    $t2, $t1, $s7
/* 115A30 7F0E0F00 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 115A34 7F0E0F04 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 115A38 7F0E0F08 314D1800 */  andi  $t5, $t2, 0x1800
/* 115A3C 7F0E0F0C 03376025 */  or    $t4, $t9, $s7
/* 115A40 7F0E0F10 318F00FF */  andi  $t7, $t4, 0xff
/* 115A44 7F0E0F14 000D58C3 */  sra   $t3, $t5, 3
/* 115A48 7F0E0F18 016F4025 */  or    $t0, $t3, $t7
/* 115A4C 7F0E0F1C 24180001 */  li    $t8, 1
/* 115A50 7F0E0F20 01C84821 */  addu  $t1, $t6, $t0
/* 115A54 7F0E0F24 A1380000 */  sb    $t8, ($t1)
.L7F0E0F28:
/* 115A58 7F0E0F28 97AD006C */  lhu   $t5, 0x6c($sp)
/* 115A5C 7F0E0F2C 8FAA028C */  lw    $t2, 0x28c($sp)
/* 115A60 7F0E0F30 2EEB0001 */  sltiu $t3, $s7, 1
/* 115A64 7F0E0F34 26F7FFFF */  addiu $s7, $s7, -1
/* 115A68 7F0E0F38 000DCA03 */  sra   $t9, $t5, 8
/* 115A6C 7F0E0F3C 32EF00FF */  andi  $t7, $s7, 0xff
/* 115A70 7F0E0F40 01596021 */  addu  $t4, $t2, $t9
/* 115A74 7F0E0F44 AFAC028C */  sw    $t4, 0x28c($sp)
/* 115A78 7F0E0F48 01E0B825 */  move  $s7, $t7
/* 115A7C 7F0E0F4C 11600004 */  beqz  $t3, .L7F0E0F60
/* 115A80 7F0E0F50 AFAB0048 */   sw    $t3, 0x48($sp)
/* 115A84 7F0E0F54 26D6FFFF */  addiu $s6, $s6, -1
/* 115A88 7F0E0F58 32C800FF */  andi  $t0, $s6, 0xff
/* 115A8C 7F0E0F5C 0100B025 */  move  $s6, $t0
.L7F0E0F60:
/* 115A90 7F0E0F60 3C0B8009 */  lui   $t3, %hi(ptr_pc_keyboard_table_alloc) 
/* 115A94 7F0E0F64 8D6BE334 */  lw    $t3, %lo(ptr_pc_keyboard_table_alloc)($t3)
/* 115A98 7F0E0F68 2652FFFF */  addiu $s2, $s2, -1
/* 115A9C 7F0E0F6C 325800FF */  andi  $t8, $s2, 0xff
/* 115AA0 7F0E0F70 030B7821 */  addu  $t7, $t8, $t3
/* 115AA4 7F0E0F74 91EE0000 */  lbu   $t6, ($t7)
/* 115AA8 7F0E0F78 330900A8 */  andi  $t1, $t8, 0xa8
/* 115AAC 7F0E0F7C 0018682A */  slt   $t5, $zero, $t8
/* 115AB0 7F0E0F80 03009025 */  move  $s2, $t8
/* 115AB4 7F0E0F84 000D5180 */  sll   $t2, $t5, 6
/* 115AB8 7F0E0F88 01D34026 */  xor   $t0, $t6, $s3
/* 115ABC 7F0E0F8C 39180004 */  xori  $t8, $t0, 4
/* 115AC0 7F0E0F90 012AC825 */  or    $t9, $t1, $t2
/* 115AC4 7F0E0F94 372C0002 */  ori   $t4, $t9, 2
/* 115AC8 7F0E0F98 330D0004 */  andi  $t5, $t8, 4
/* 115ACC 7F0E0F9C 01AC8825 */  or    $s1, $t5, $t4
/* 115AD0 7F0E0FA0 322900FF */  andi  $t1, $s1, 0xff
/* 115AD4 7F0E0FA4 10000615 */  b     .L7F0E27FC
/* 115AD8 7F0E0FA8 01208825 */   move  $s1, $t1
spectrum_op_ED_AB:
/* 115ADC 7F0E0FAC 8FAA028C */  lw    $t2, 0x28c($sp)
/* 115AE0 7F0E0FB0 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 115AE4 7F0E0FB4 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 115AE8 7F0E0FB8 00165A00 */  sll   $t3, $s6, 8
/* 115AEC 7F0E0FBC 01777825 */  or    $t7, $t3, $s7
/* 115AF0 7F0E0FC0 2544000C */  addiu $a0, $t2, 0xc
/* 115AF4 7F0E0FC4 AFA4028C */  sw    $a0, 0x28c($sp)
/* 115AF8 7F0E0FC8 01EE4021 */  addu  $t0, $t7, $t6
/* 115AFC 7F0E0FCC 91070000 */  lbu   $a3, ($t0)
/* 115B00 7F0E0FD0 02402825 */  move  $a1, $s2
/* 115B04 7F0E0FD4 02603025 */  move  $a2, $s3
/* 115B08 7F0E0FD8 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 115B0C 7F0E0FDC A3A7006B */   sb    $a3, 0x6b($sp)
/* 115B10 7F0E0FE0 8FAD028C */  lw    $t5, 0x28c($sp)
/* 115B14 7F0E0FE4 2EEA0001 */  sltiu $t2, $s7, 1
/* 115B18 7F0E0FE8 26F7FFFF */  addiu $s7, $s7, -1
/* 115B1C 7F0E0FEC AFA20048 */  sw    $v0, 0x48($sp)
/* 115B20 7F0E0FF0 32EB00FF */  andi  $t3, $s7, 0xff
/* 115B24 7F0E0FF4 01A24821 */  addu  $t1, $t5, $v0
/* 115B28 7F0E0FF8 AFA9028C */  sw    $t1, 0x28c($sp)
/* 115B2C 7F0E0FFC 0160B825 */  move  $s7, $t3
/* 115B30 7F0E1000 11400004 */  beqz  $t2, .L7F0E1014
/* 115B34 7F0E1004 AFAA0048 */   sw    $t2, 0x48($sp)
/* 115B38 7F0E1008 26D6FFFF */  addiu $s6, $s6, -1
/* 115B3C 7F0E100C 32CE00FF */  andi  $t6, $s6, 0xff
/* 115B40 7F0E1010 01C0B025 */  move  $s6, $t6
.L7F0E1014:
/* 115B44 7F0E1014 2652FFFF */  addiu $s2, $s2, -1
/* 115B48 7F0E1018 324800FF */  andi  $t0, $s2, 0xff
/* 115B4C 7F0E101C 32390001 */  andi  $t9, $s1, 1
/* 115B50 7F0E1020 37380012 */  ori   $t8, $t9, 0x12
/* 115B54 7F0E1024 310D00A8 */  andi  $t5, $t0, 0xa8
/* 115B58 7F0E1028 2D090001 */  sltiu $t1, $t0, 1
/* 115B5C 7F0E102C 00095180 */  sll   $t2, $t1, 6
/* 115B60 7F0E1030 030D6025 */  or    $t4, $t8, $t5
/* 115B64 7F0E1034 018A8825 */  or    $s1, $t4, $t2
/* 115B68 7F0E1038 322B00FF */  andi  $t3, $s1, 0xff
/* 115B6C 7F0E103C 01009025 */  move  $s2, $t0
/* 115B70 7F0E1040 100005EE */  b     .L7F0E27FC
/* 115B74 7F0E1044 01608825 */   move  $s1, $t3
spectrum_op_ED_B0:
/* 115B78 7F0E1048 8FAF028C */  lw    $t7, 0x28c($sp)
/* 115B7C 7F0E104C 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 115B80 7F0E1050 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 115B84 7F0E1054 00164200 */  sll   $t0, $s6, 8
/* 115B88 7F0E1058 0117C825 */  or    $t9, $t0, $s7
/* 115B8C 7F0E105C 25EE000C */  addiu $t6, $t7, 0xc
/* 115B90 7F0E1060 AFAE028C */  sw    $t6, 0x28c($sp)
/* 115B94 7F0E1064 00146200 */  sll   $t4, $s4, 8
/* 115B98 7F0E1068 03386821 */  addu  $t5, $t9, $t8
/* 115B9C 7F0E106C 91A90000 */  lbu   $t1, ($t5)
/* 115BA0 7F0E1070 01955025 */  or    $t2, $t4, $s5
/* 115BA4 7F0E1074 29415B00 */  slti  $at, $t2, 0x5b00
/* 115BA8 7F0E1078 14200008 */  bnez  $at, .L7F0E109C
/* 115BAC 7F0E107C A3A9006A */   sb    $t1, 0x6a($sp)
/* 115BB0 7F0E1080 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 115BB4 7F0E1084 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 115BB8 7F0E1088 00147200 */  sll   $t6, $s4, 8
/* 115BBC 7F0E108C 01D54025 */  or    $t0, $t6, $s5
/* 115BC0 7F0E1090 01E8C821 */  addu  $t9, $t7, $t0
/* 115BC4 7F0E1094 1000002B */  b     .L7F0E1144
/* 115BC8 7F0E1098 A3290000 */   sb    $t1, ($t9)
.L7F0E109C:
/* 115BCC 7F0E109C 0014C200 */  sll   $t8, $s4, 8
/* 115BD0 7F0E10A0 03156825 */  or    $t5, $t8, $s5
/* 115BD4 7F0E10A4 29A15800 */  slti  $at, $t5, 0x5800
/* 115BD8 7F0E10A8 14200010 */  bnez  $at, .L7F0E10EC
/* 115BDC 7F0E10AC 00145200 */   sll   $t2, $s4, 8
/* 115BE0 7F0E10B0 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 115BE4 7F0E10B4 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 115BE8 7F0E10B8 93A9006A */  lbu   $t1, 0x6a($sp)
/* 115BEC 7F0E10BC 00145200 */  sll   $t2, $s4, 8
/* 115BF0 7F0E10C0 01557025 */  or    $t6, $t2, $s5
/* 115BF4 7F0E10C4 018E7821 */  addu  $t7, $t4, $t6
/* 115BF8 7F0E10C8 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 115BFC 7F0E10CC A1E90000 */  sb    $t1, ($t7)
/* 115C00 7F0E10D0 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 115C04 7F0E10D4 0014CA00 */  sll   $t9, $s4, 8
/* 115C08 7F0E10D8 0335C025 */  or    $t8, $t9, $s5
/* 115C0C 7F0E10DC 24080001 */  li    $t0, 1
/* 115C10 7F0E10E0 01786821 */  addu  $t5, $t3, $t8
/* 115C14 7F0E10E4 10000017 */  b     .L7F0E1144
/* 115C18 7F0E10E8 A1A8A800 */   sb    $t0, -0x5800($t5)
.L7F0E10EC:
/* 115C1C 7F0E10EC 01556025 */  or    $t4, $t2, $s5
/* 115C20 7F0E10F0 29814000 */  slti  $at, $t4, 0x4000
/* 115C24 7F0E10F4 14200013 */  bnez  $at, .L7F0E1144
/* 115C28 7F0E10F8 93AE006A */   lbu   $t6, 0x6a($sp)
/* 115C2C 7F0E10FC 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 115C30 7F0E1100 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 115C34 7F0E1104 00147A00 */  sll   $t7, $s4, 8
/* 115C38 7F0E1108 01F5C825 */  or    $t9, $t7, $s5
/* 115C3C 7F0E110C 01395821 */  addu  $t3, $t1, $t9
/* 115C40 7F0E1110 A16E0000 */  sb    $t6, ($t3)
/* 115C44 7F0E1114 00144200 */  sll   $t0, $s4, 8
/* 115C48 7F0E1118 01156825 */  or    $t5, $t0, $s5
/* 115C4C 7F0E111C 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 115C50 7F0E1120 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 115C54 7F0E1124 31AA1800 */  andi  $t2, $t5, 0x1800
/* 115C58 7F0E1128 01F54825 */  or    $t1, $t7, $s5
/* 115C5C 7F0E112C 313900FF */  andi  $t9, $t1, 0xff
/* 115C60 7F0E1130 000A60C3 */  sra   $t4, $t2, 3
/* 115C64 7F0E1134 01997025 */  or    $t6, $t4, $t9
/* 115C68 7F0E1138 24180001 */  li    $t8, 1
/* 115C6C 7F0E113C 016E4021 */  addu  $t0, $t3, $t6
/* 115C70 7F0E1140 A1180000 */  sb    $t8, ($t0)
.L7F0E1144:
/* 115C74 7F0E1144 26F70001 */  addiu $s7, $s7, 1
/* 115C78 7F0E1148 32ED00FF */  andi  $t5, $s7, 0xff
/* 115C7C 7F0E114C 15A00004 */  bnez  $t5, .L7F0E1160
/* 115C80 7F0E1150 01A0B825 */   move  $s7, $t5
/* 115C84 7F0E1154 26D60001 */  addiu $s6, $s6, 1
/* 115C88 7F0E1158 32CA00FF */  andi  $t2, $s6, 0xff
/* 115C8C 7F0E115C 0140B025 */  move  $s6, $t2
.L7F0E1160:
/* 115C90 7F0E1160 26B50001 */  addiu $s5, $s5, 1
/* 115C94 7F0E1164 32AF00FF */  andi  $t7, $s5, 0xff
/* 115C98 7F0E1168 15E00004 */  bnez  $t7, .L7F0E117C
/* 115C9C 7F0E116C 01E0A825 */   move  $s5, $t7
/* 115CA0 7F0E1170 26940001 */  addiu $s4, $s4, 1
/* 115CA4 7F0E1174 328900FF */  andi  $t1, $s4, 0xff
/* 115CA8 7F0E1178 0120A025 */  move  $s4, $t1
.L7F0E117C:
/* 115CAC 7F0E117C 2E6C0001 */  sltiu $t4, $s3, 1
/* 115CB0 7F0E1180 2673FFFF */  addiu $s3, $s3, -1
/* 115CB4 7F0E1184 327900FF */  andi  $t9, $s3, 0xff
/* 115CB8 7F0E1188 03209825 */  move  $s3, $t9
/* 115CBC 7F0E118C 11800004 */  beqz  $t4, .L7F0E11A0
/* 115CC0 7F0E1190 AFAC0048 */   sw    $t4, 0x48($sp)
/* 115CC4 7F0E1194 2652FFFF */  addiu $s2, $s2, -1
/* 115CC8 7F0E1198 324E00FF */  andi  $t6, $s2, 0xff
/* 115CCC 7F0E119C 01C09025 */  move  $s2, $t6
.L7F0E11A0:
/* 115CD0 7F0E11A0 93A8006A */  lbu   $t0, 0x6a($sp)
/* 115CD4 7F0E11A4 02537825 */  or    $t7, $s2, $s3
/* 115CD8 7F0E11A8 000F482A */  slt   $t1, $zero, $t7
/* 115CDC 7F0E11AC 323800C1 */  andi  $t8, $s1, 0xc1
/* 115CE0 7F0E11B0 310D0028 */  andi  $t5, $t0, 0x28
/* 115CE4 7F0E11B4 030D5025 */  or    $t2, $t8, $t5
/* 115CE8 7F0E11B8 00096080 */  sll   $t4, $t1, 2
/* 115CEC 7F0E11BC 014C8825 */  or    $s1, $t2, $t4
/* 115CF0 7F0E11C0 323900FF */  andi  $t9, $s1, 0xff
/* 115CF4 7F0E11C4 02535825 */  or    $t3, $s2, $s3
/* 115CF8 7F0E11C8 1160058C */  beqz  $t3, .L7F0E27FC
/* 115CFC 7F0E11CC 03208825 */   move  $s1, $t9
/* 115D00 7F0E11D0 97AE0298 */  lhu   $t6, 0x298($sp)
/* 115D04 7F0E11D4 8FB8028C */  lw    $t8, 0x28c($sp)
/* 115D08 7F0E11D8 25C8FFFE */  addiu $t0, $t6, -2
/* 115D0C 7F0E11DC 270D0005 */  addiu $t5, $t8, 5
/* 115D10 7F0E11E0 AFAD028C */  sw    $t5, 0x28c($sp)
/* 115D14 7F0E11E4 10000585 */  b     .L7F0E27FC
/* 115D18 7F0E11E8 A7A80298 */   sh    $t0, 0x298($sp)
spectrum_op_ED_B1:
/* 115D1C 7F0E11EC 8FAF028C */  lw    $t7, 0x28c($sp)
/* 115D20 7F0E11F0 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 115D24 7F0E11F4 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 115D28 7F0E11F8 00166200 */  sll   $t4, $s6, 8
/* 115D2C 7F0E11FC 322A0001 */  andi  $t2, $s1, 1
/* 115D30 7F0E1200 0197C825 */  or    $t9, $t4, $s7
/* 115D34 7F0E1204 25E9000C */  addiu $t1, $t7, 0xc
/* 115D38 7F0E1208 AFA9028C */  sw    $t1, 0x28c($sp)
/* 115D3C 7F0E120C A3AA0069 */  sb    $t2, 0x69($sp)
/* 115D40 7F0E1210 032B7021 */  addu  $t6, $t9, $t3
/* 115D44 7F0E1214 91C80000 */  lbu   $t0, ($t6)
/* 115D48 7F0E1218 26F70001 */  addiu $s7, $s7, 1
/* 115D4C 7F0E121C 24010004 */  li    $at, 4
/* 115D50 7F0E1220 0208C023 */  subu  $t8, $s0, $t0
/* 115D54 7F0E1224 330D01FF */  andi  $t5, $t8, 0x1ff
/* 115D58 7F0E1228 31AFFFFF */  andi  $t7, $t5, 0xffff
/* 115D5C 7F0E122C 2DE90001 */  sltiu $t1, $t7, 1
/* 115D60 7F0E1230 320F000F */  andi  $t7, $s0, 0xf
/* 115D64 7F0E1234 3118000F */  andi  $t8, $t0, 0xf
/* 115D68 7F0E1238 01F8502A */  slt   $t2, $t7, $t8
/* 115D6C 7F0E123C 31AC00A8 */  andi  $t4, $t5, 0xa8
/* 115D70 7F0E1240 000D5A03 */  sra   $t3, $t5, 8
/* 115D74 7F0E1244 018B7025 */  or    $t6, $t4, $t3
/* 115D78 7F0E1248 000AC900 */  sll   $t9, $t2, 4
/* 115D7C 7F0E124C 01A0C025 */  move  $t8, $t5
/* 115D80 7F0E1250 02085826 */  xor   $t3, $s0, $t0
/* 115D84 7F0E1254 316F0080 */  andi  $t7, $t3, 0x80
/* 115D88 7F0E1258 03105026 */  xor   $t2, $t8, $s0
/* 115D8C 7F0E125C 01D96025 */  or    $t4, $t6, $t9
/* 115D90 7F0E1260 01EA7024 */  and   $t6, $t7, $t2
/* 115D94 7F0E1264 000EC943 */  sra   $t9, $t6, 5
/* 115D98 7F0E1268 A3A80065 */  sb    $t0, 0x65($sp)
/* 115D9C 7F0E126C 01994025 */  or    $t0, $t4, $t9
/* 115DA0 7F0E1270 A7AD0066 */  sh    $t5, 0x66($sp)
/* 115DA4 7F0E1274 00096980 */  sll   $t5, $t1, 6
/* 115DA8 7F0E1278 350B0002 */  ori   $t3, $t0, 2
/* 115DAC 7F0E127C 016D8825 */  or    $s1, $t3, $t5
/* 115DB0 7F0E1280 323800FF */  andi  $t8, $s1, 0xff
/* 115DB4 7F0E1284 32EF00FF */  andi  $t7, $s7, 0xff
/* 115DB8 7F0E1288 03008825 */  move  $s1, $t8
/* 115DBC 7F0E128C AFA90048 */  sw    $t1, 0x48($sp)
/* 115DC0 7F0E1290 15E00004 */  bnez  $t7, .L7F0E12A4
/* 115DC4 7F0E1294 01E0B825 */   move  $s7, $t7
/* 115DC8 7F0E1298 26D60001 */  addiu $s6, $s6, 1
/* 115DCC 7F0E129C 32CA00FF */  andi  $t2, $s6, 0xff
/* 115DD0 7F0E12A0 0140B025 */  move  $s6, $t2
.L7F0E12A4:
/* 115DD4 7F0E12A4 2E6E0001 */  sltiu $t6, $s3, 1
/* 115DD8 7F0E12A8 2673FFFF */  addiu $s3, $s3, -1
/* 115DDC 7F0E12AC 326C00FF */  andi  $t4, $s3, 0xff
/* 115DE0 7F0E12B0 01809825 */  move  $s3, $t4
/* 115DE4 7F0E12B4 11C00004 */  beqz  $t6, .L7F0E12C8
/* 115DE8 7F0E12B8 AFAE0048 */   sw    $t6, 0x48($sp)
/* 115DEC 7F0E12BC 2652FFFF */  addiu $s2, $s2, -1
/* 115DF0 7F0E12C0 324800FF */  andi  $t0, $s2, 0xff
/* 115DF4 7F0E12C4 01009025 */  move  $s2, $t0
.L7F0E12C8:
/* 115DF8 7F0E12C8 93AB0069 */  lbu   $t3, 0x69($sp)
/* 115DFC 7F0E12CC 0253C025 */  or    $t8, $s2, $s3
/* 115E00 7F0E12D0 0018782A */  slt   $t7, $zero, $t8
/* 115E04 7F0E12D4 322900FA */  andi  $t1, $s1, 0xfa
/* 115E08 7F0E12D8 000F5080 */  sll   $t2, $t7, 2
/* 115E0C 7F0E12DC 012B6825 */  or    $t5, $t1, $t3
/* 115E10 7F0E12E0 01AA8825 */  or    $s1, $t5, $t2
/* 115E14 7F0E12E4 322E00FF */  andi  $t6, $s1, 0xff
/* 115E18 7F0E12E8 31CC0044 */  andi  $t4, $t6, 0x44
/* 115E1C 7F0E12EC 15810543 */  bne   $t4, $at, .L7F0E27FC
/* 115E20 7F0E12F0 01C08825 */   move  $s1, $t6
/* 115E24 7F0E12F4 97B90298 */  lhu   $t9, 0x298($sp)
/* 115E28 7F0E12F8 8FA9028C */  lw    $t1, 0x28c($sp)
/* 115E2C 7F0E12FC 2728FFFE */  addiu $t0, $t9, -2
/* 115E30 7F0E1300 252B0005 */  addiu $t3, $t1, 5
/* 115E34 7F0E1304 AFAB028C */  sw    $t3, 0x28c($sp)
/* 115E38 7F0E1308 1000053C */  b     .L7F0E27FC
/* 115E3C 7F0E130C A7A80298 */   sh    $t0, 0x298($sp)
spectrum_op_ED_B2:
/* 115E40 7F0E1310 8FB8028C */  lw    $t8, 0x28c($sp)
/* 115E44 7F0E1314 02402825 */  move  $a1, $s2
/* 115E48 7F0E1318 02603025 */  move  $a2, $s3
/* 115E4C 7F0E131C 2704000C */  addiu $a0, $t8, 0xc
/* 115E50 7F0E1320 0FC34DB6 */  jal   spectrum_input_handling
/* 115E54 7F0E1324 AFA4028C */   sw    $a0, 0x28c($sp)
/* 115E58 7F0E1328 00166A00 */  sll   $t5, $s6, 8
/* 115E5C 7F0E132C 01B75025 */  or    $t2, $t5, $s7
/* 115E60 7F0E1330 29415B00 */  slti  $at, $t2, 0x5b00
/* 115E64 7F0E1334 14200008 */  bnez  $at, .L7F0E1358
/* 115E68 7F0E1338 A7A20062 */   sh    $v0, 0x62($sp)
/* 115E6C 7F0E133C 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 115E70 7F0E1340 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 115E74 7F0E1344 0016CA00 */  sll   $t9, $s6, 8
/* 115E78 7F0E1348 03374025 */  or    $t0, $t9, $s7
/* 115E7C 7F0E134C 01884821 */  addu  $t1, $t4, $t0
/* 115E80 7F0E1350 1000002B */  b     .L7F0E1400
/* 115E84 7F0E1354 A1220000 */   sb    $v0, ($t1)
.L7F0E1358:
/* 115E88 7F0E1358 00165A00 */  sll   $t3, $s6, 8
/* 115E8C 7F0E135C 0177C025 */  or    $t8, $t3, $s7
/* 115E90 7F0E1360 2B015800 */  slti  $at, $t8, 0x5800
/* 115E94 7F0E1364 14200010 */  bnez  $at, .L7F0E13A8
/* 115E98 7F0E1368 00165200 */   sll   $t2, $s6, 8
/* 115E9C 7F0E136C 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 115EA0 7F0E1370 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 115EA4 7F0E1374 97AF0062 */  lhu   $t7, 0x62($sp)
/* 115EA8 7F0E1378 00165200 */  sll   $t2, $s6, 8
/* 115EAC 7F0E137C 0157C825 */  or    $t9, $t2, $s7
/* 115EB0 7F0E1380 01B96021 */  addu  $t4, $t5, $t9
/* 115EB4 7F0E1384 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 115EB8 7F0E1388 A18F0000 */  sb    $t7, ($t4)
/* 115EBC 7F0E138C 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 115EC0 7F0E1390 00164A00 */  sll   $t1, $s6, 8
/* 115EC4 7F0E1394 01375825 */  or    $t3, $t1, $s7
/* 115EC8 7F0E1398 24080001 */  li    $t0, 1
/* 115ECC 7F0E139C 01CBC021 */  addu  $t8, $t6, $t3
/* 115ED0 7F0E13A0 10000017 */  b     .L7F0E1400
/* 115ED4 7F0E13A4 A308A800 */   sb    $t0, -0x5800($t8)
.L7F0E13A8:
/* 115ED8 7F0E13A8 01576825 */  or    $t5, $t2, $s7
/* 115EDC 7F0E13AC 29A14000 */  slti  $at, $t5, 0x4000
/* 115EE0 7F0E13B0 14200013 */  bnez  $at, .L7F0E1400
/* 115EE4 7F0E13B4 97B90062 */   lhu   $t9, 0x62($sp)
/* 115EE8 7F0E13B8 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 115EEC 7F0E13BC 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 115EF0 7F0E13C0 00166200 */  sll   $t4, $s6, 8
/* 115EF4 7F0E13C4 01974825 */  or    $t1, $t4, $s7
/* 115EF8 7F0E13C8 01E97021 */  addu  $t6, $t7, $t1
/* 115EFC 7F0E13CC A1D90000 */  sb    $t9, ($t6)
/* 115F00 7F0E13D0 00164200 */  sll   $t0, $s6, 8
/* 115F04 7F0E13D4 0117C025 */  or    $t8, $t0, $s7
/* 115F08 7F0E13D8 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 115F0C 7F0E13DC 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 115F10 7F0E13E0 330A1800 */  andi  $t2, $t8, 0x1800
/* 115F14 7F0E13E4 01977825 */  or    $t7, $t4, $s7
/* 115F18 7F0E13E8 31E900FF */  andi  $t1, $t7, 0xff
/* 115F1C 7F0E13EC 000A68C3 */  sra   $t5, $t2, 3
/* 115F20 7F0E13F0 01A9C825 */  or    $t9, $t5, $t1
/* 115F24 7F0E13F4 240B0001 */  li    $t3, 1
/* 115F28 7F0E13F8 01D94021 */  addu  $t0, $t6, $t9
/* 115F2C 7F0E13FC A10B0000 */  sb    $t3, ($t0)
.L7F0E1400:
/* 115F30 7F0E1400 97AA0062 */  lhu   $t2, 0x62($sp)
/* 115F34 7F0E1404 8FB8028C */  lw    $t8, 0x28c($sp)
/* 115F38 7F0E1408 26F70001 */  addiu $s7, $s7, 1
/* 115F3C 7F0E140C 000A6203 */  sra   $t4, $t2, 8
/* 115F40 7F0E1410 32ED00FF */  andi  $t5, $s7, 0xff
/* 115F44 7F0E1414 030C7821 */  addu  $t7, $t8, $t4
/* 115F48 7F0E1418 AFAF028C */  sw    $t7, 0x28c($sp)
/* 115F4C 7F0E141C 15A00004 */  bnez  $t5, .L7F0E1430
/* 115F50 7F0E1420 01A0B825 */   move  $s7, $t5
/* 115F54 7F0E1424 26D60001 */  addiu $s6, $s6, 1
/* 115F58 7F0E1428 32C900FF */  andi  $t1, $s6, 0xff
/* 115F5C 7F0E142C 0120B025 */  move  $s6, $t1
.L7F0E1430:
/* 115F60 7F0E1430 3C0C8009 */  lui   $t4, %hi(ptr_pc_keyboard_table_alloc) 
/* 115F64 7F0E1434 8D8CE334 */  lw    $t4, %lo(ptr_pc_keyboard_table_alloc)($t4)
/* 115F68 7F0E1438 2652FFFF */  addiu $s2, $s2, -1
/* 115F6C 7F0E143C 324E00FF */  andi  $t6, $s2, 0xff
/* 115F70 7F0E1440 01CC7821 */  addu  $t7, $t6, $t4
/* 115F74 7F0E1444 91ED0000 */  lbu   $t5, ($t7)
/* 115F78 7F0E1448 000E582A */  slt   $t3, $zero, $t6
/* 115F7C 7F0E144C 000B4180 */  sll   $t0, $t3, 6
/* 115F80 7F0E1450 31D900A8 */  andi  $t9, $t6, 0xa8
/* 115F84 7F0E1454 01C09025 */  move  $s2, $t6
/* 115F88 7F0E1458 03285025 */  or    $t2, $t9, $t0
/* 115F8C 7F0E145C 01B34826 */  xor   $t1, $t5, $s3
/* 115F90 7F0E1460 312E0004 */  andi  $t6, $t1, 4
/* 115F94 7F0E1464 35580002 */  ori   $t8, $t2, 2
/* 115F98 7F0E1468 01D88825 */  or    $s1, $t6, $t8
/* 115F9C 7F0E146C 322B00FF */  andi  $t3, $s1, 0xff
/* 115FA0 7F0E1470 124004E2 */  beqz  $s2, .L7F0E27FC
/* 115FA4 7F0E1474 01608825 */   move  $s1, $t3
/* 115FA8 7F0E1478 97B90298 */  lhu   $t9, 0x298($sp)
/* 115FAC 7F0E147C 8FAA028C */  lw    $t2, 0x28c($sp)
/* 115FB0 7F0E1480 2728FFFE */  addiu $t0, $t9, -2
/* 115FB4 7F0E1484 254C0005 */  addiu $t4, $t2, 5
/* 115FB8 7F0E1488 AFAC028C */  sw    $t4, 0x28c($sp)
/* 115FBC 7F0E148C 100004DB */  b     .L7F0E27FC
/* 115FC0 7F0E1490 A7A80298 */   sh    $t0, 0x298($sp)
spectrum_op_ED_B3:
/* 115FC4 7F0E1494 8FAF028C */  lw    $t7, 0x28c($sp)
/* 115FC8 7F0E1498 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 115FCC 7F0E149C 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 115FD0 7F0E14A0 00164A00 */  sll   $t1, $s6, 8
/* 115FD4 7F0E14A4 01377025 */  or    $t6, $t1, $s7
/* 115FD8 7F0E14A8 25E4000C */  addiu $a0, $t7, 0xc
/* 115FDC 7F0E14AC AFA4028C */  sw    $a0, 0x28c($sp)
/* 115FE0 7F0E14B0 01D85821 */  addu  $t3, $t6, $t8
/* 115FE4 7F0E14B4 91670000 */  lbu   $a3, ($t3)
/* 115FE8 7F0E14B8 02402825 */  move  $a1, $s2
/* 115FEC 7F0E14BC 02603025 */  move  $a2, $s3
/* 115FF0 7F0E14C0 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 115FF4 7F0E14C4 A3A70061 */   sb    $a3, 0x61($sp)
/* 115FF8 7F0E14C8 8FA8028C */  lw    $t0, 0x28c($sp)
/* 115FFC 7F0E14CC 26F70001 */  addiu $s7, $s7, 1
/* 116000 7F0E14D0 32EF00FF */  andi  $t7, $s7, 0xff
/* 116004 7F0E14D4 01026021 */  addu  $t4, $t0, $v0
/* 116008 7F0E14D8 AFAC028C */  sw    $t4, 0x28c($sp)
/* 11600C 7F0E14DC AFA20048 */  sw    $v0, 0x48($sp)
/* 116010 7F0E14E0 15E00004 */  bnez  $t7, .L7F0E14F4
/* 116014 7F0E14E4 01E0B825 */   move  $s7, $t7
/* 116018 7F0E14E8 26D60001 */  addiu $s6, $s6, 1
/* 11601C 7F0E14EC 32C900FF */  andi  $t1, $s6, 0xff
/* 116020 7F0E14F0 0120B025 */  move  $s6, $t1
.L7F0E14F4:
/* 116024 7F0E14F4 2652FFFF */  addiu $s2, $s2, -1
/* 116028 7F0E14F8 324E00FF */  andi  $t6, $s2, 0xff
/* 11602C 7F0E14FC 32380001 */  andi  $t8, $s1, 1
/* 116030 7F0E1500 370B0012 */  ori   $t3, $t8, 0x12
/* 116034 7F0E1504 31CD00A8 */  andi  $t5, $t6, 0xa8
/* 116038 7F0E1508 2DC80001 */  sltiu $t0, $t6, 1
/* 11603C 7F0E150C 00085180 */  sll   $t2, $t0, 6
/* 116040 7F0E1510 016DC825 */  or    $t9, $t3, $t5
/* 116044 7F0E1514 032A8825 */  or    $s1, $t9, $t2
/* 116048 7F0E1518 322C00FF */  andi  $t4, $s1, 0xff
/* 11604C 7F0E151C 01C09025 */  move  $s2, $t6
/* 116050 7F0E1520 11C004B6 */  beqz  $t6, .L7F0E27FC
/* 116054 7F0E1524 01808825 */   move  $s1, $t4
/* 116058 7F0E1528 97AF0298 */  lhu   $t7, 0x298($sp)
/* 11605C 7F0E152C 8FAE028C */  lw    $t6, 0x28c($sp)
/* 116060 7F0E1530 25E9FFFE */  addiu $t1, $t7, -2
/* 116064 7F0E1534 25D80005 */  addiu $t8, $t6, 5
/* 116068 7F0E1538 AFB8028C */  sw    $t8, 0x28c($sp)
/* 11606C 7F0E153C 100004AF */  b     .L7F0E27FC
/* 116070 7F0E1540 A7A90298 */   sh    $t1, 0x298($sp)
spectrum_op_ED_B8:
/* 116074 7F0E1544 8FAB028C */  lw    $t3, 0x28c($sp)
/* 116078 7F0E1548 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 11607C 7F0E154C 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 116080 7F0E1550 00164200 */  sll   $t0, $s6, 8
/* 116084 7F0E1554 0117C825 */  or    $t9, $t0, $s7
/* 116088 7F0E1558 256D000C */  addiu $t5, $t3, 0xc
/* 11608C 7F0E155C AFAD028C */  sw    $t5, 0x28c($sp)
/* 116090 7F0E1560 00144A00 */  sll   $t1, $s4, 8
/* 116094 7F0E1564 032A6021 */  addu  $t4, $t9, $t2
/* 116098 7F0E1568 918F0000 */  lbu   $t7, ($t4)
/* 11609C 7F0E156C 01357025 */  or    $t6, $t1, $s5
/* 1160A0 7F0E1570 29C15B00 */  slti  $at, $t6, 0x5b00
/* 1160A4 7F0E1574 14200008 */  bnez  $at, .L7F0E1598
/* 1160A8 7F0E1578 A3AF0060 */   sb    $t7, 0x60($sp)
/* 1160AC 7F0E157C 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 1160B0 7F0E1580 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 1160B4 7F0E1584 00146A00 */  sll   $t5, $s4, 8
/* 1160B8 7F0E1588 01B54025 */  or    $t0, $t5, $s5
/* 1160BC 7F0E158C 0168C821 */  addu  $t9, $t3, $t0
/* 1160C0 7F0E1590 1000002B */  b     .L7F0E1640
/* 1160C4 7F0E1594 A32F0000 */   sb    $t7, ($t9)
.L7F0E1598:
/* 1160C8 7F0E1598 00145200 */  sll   $t2, $s4, 8
/* 1160CC 7F0E159C 01556025 */  or    $t4, $t2, $s5
/* 1160D0 7F0E15A0 29815800 */  slti  $at, $t4, 0x5800
/* 1160D4 7F0E15A4 14200010 */  bnez  $at, .L7F0E15E8
/* 1160D8 7F0E15A8 00147200 */   sll   $t6, $s4, 8
/* 1160DC 7F0E15AC 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 1160E0 7F0E15B0 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 1160E4 7F0E15B4 93AF0060 */  lbu   $t7, 0x60($sp)
/* 1160E8 7F0E15B8 00147200 */  sll   $t6, $s4, 8
/* 1160EC 7F0E15BC 01D56825 */  or    $t5, $t6, $s5
/* 1160F0 7F0E15C0 012D5821 */  addu  $t3, $t1, $t5
/* 1160F4 7F0E15C4 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 1160F8 7F0E15C8 A16F0000 */  sb    $t7, ($t3)
/* 1160FC 7F0E15CC 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 116100 7F0E15D0 0014CA00 */  sll   $t9, $s4, 8
/* 116104 7F0E15D4 03355025 */  or    $t2, $t9, $s5
/* 116108 7F0E15D8 24080001 */  li    $t0, 1
/* 11610C 7F0E15DC 030A6021 */  addu  $t4, $t8, $t2
/* 116110 7F0E15E0 10000017 */  b     .L7F0E1640
/* 116114 7F0E15E4 A188A800 */   sb    $t0, -0x5800($t4)
.L7F0E15E8:
/* 116118 7F0E15E8 01D54825 */  or    $t1, $t6, $s5
/* 11611C 7F0E15EC 29214000 */  slti  $at, $t1, 0x4000
/* 116120 7F0E15F0 14200013 */  bnez  $at, .L7F0E1640
/* 116124 7F0E15F4 93AD0060 */   lbu   $t5, 0x60($sp)
/* 116128 7F0E15F8 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 11612C 7F0E15FC 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 116130 7F0E1600 00145A00 */  sll   $t3, $s4, 8
/* 116134 7F0E1604 0175C825 */  or    $t9, $t3, $s5
/* 116138 7F0E1608 01F9C021 */  addu  $t8, $t7, $t9
/* 11613C 7F0E160C A30D0000 */  sb    $t5, ($t8)
/* 116140 7F0E1610 00144200 */  sll   $t0, $s4, 8
/* 116144 7F0E1614 01156025 */  or    $t4, $t0, $s5
/* 116148 7F0E1618 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 11614C 7F0E161C 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 116150 7F0E1620 318E1800 */  andi  $t6, $t4, 0x1800
/* 116154 7F0E1624 01757825 */  or    $t7, $t3, $s5
/* 116158 7F0E1628 31F900FF */  andi  $t9, $t7, 0xff
/* 11615C 7F0E162C 000E48C3 */  sra   $t1, $t6, 3
/* 116160 7F0E1630 01396825 */  or    $t5, $t1, $t9
/* 116164 7F0E1634 240A0001 */  li    $t2, 1
/* 116168 7F0E1638 030D4021 */  addu  $t0, $t8, $t5
/* 11616C 7F0E163C A10A0000 */  sb    $t2, ($t0)
.L7F0E1640:
/* 116170 7F0E1640 2EEC0001 */  sltiu $t4, $s7, 1
/* 116174 7F0E1644 26F7FFFF */  addiu $s7, $s7, -1
/* 116178 7F0E1648 32EE00FF */  andi  $t6, $s7, 0xff
/* 11617C 7F0E164C 01C0B825 */  move  $s7, $t6
/* 116180 7F0E1650 11800004 */  beqz  $t4, .L7F0E1664
/* 116184 7F0E1654 AFAC0048 */   sw    $t4, 0x48($sp)
/* 116188 7F0E1658 26D6FFFF */  addiu $s6, $s6, -1
/* 11618C 7F0E165C 32CF00FF */  andi  $t7, $s6, 0xff
/* 116190 7F0E1660 01E0B025 */  move  $s6, $t7
.L7F0E1664:
/* 116194 7F0E1664 2EA90001 */  sltiu $t1, $s5, 1
/* 116198 7F0E1668 26B5FFFF */  addiu $s5, $s5, -1
/* 11619C 7F0E166C 32B900FF */  andi  $t9, $s5, 0xff
/* 1161A0 7F0E1670 0320A825 */  move  $s5, $t9
/* 1161A4 7F0E1674 11200004 */  beqz  $t1, .L7F0E1688
/* 1161A8 7F0E1678 AFA90048 */   sw    $t1, 0x48($sp)
/* 1161AC 7F0E167C 2694FFFF */  addiu $s4, $s4, -1
/* 1161B0 7F0E1680 328D00FF */  andi  $t5, $s4, 0xff
/* 1161B4 7F0E1684 01A0A025 */  move  $s4, $t5
.L7F0E1688:
/* 1161B8 7F0E1688 2E6A0001 */  sltiu $t2, $s3, 1
/* 1161BC 7F0E168C 2673FFFF */  addiu $s3, $s3, -1
/* 1161C0 7F0E1690 326800FF */  andi  $t0, $s3, 0xff
/* 1161C4 7F0E1694 01009825 */  move  $s3, $t0
/* 1161C8 7F0E1698 11400004 */  beqz  $t2, .L7F0E16AC
/* 1161CC 7F0E169C AFAA0048 */   sw    $t2, 0x48($sp)
/* 1161D0 7F0E16A0 2652FFFF */  addiu $s2, $s2, -1
/* 1161D4 7F0E16A4 324E00FF */  andi  $t6, $s2, 0xff
/* 1161D8 7F0E16A8 01C09025 */  move  $s2, $t6
.L7F0E16AC:
/* 1161DC 7F0E16AC 93AF0060 */  lbu   $t7, 0x60($sp)
/* 1161E0 7F0E16B0 0253C025 */  or    $t8, $s2, $s3
/* 1161E4 7F0E16B4 0018682A */  slt   $t5, $zero, $t8
/* 1161E8 7F0E16B8 322B00C1 */  andi  $t3, $s1, 0xc1
/* 1161EC 7F0E16BC 31E90028 */  andi  $t1, $t7, 0x28
/* 1161F0 7F0E16C0 0169C825 */  or    $t9, $t3, $t1
/* 1161F4 7F0E16C4 000D5080 */  sll   $t2, $t5, 2
/* 1161F8 7F0E16C8 032A8825 */  or    $s1, $t9, $t2
/* 1161FC 7F0E16CC 322800FF */  andi  $t0, $s1, 0xff
/* 116200 7F0E16D0 02536025 */  or    $t4, $s2, $s3
/* 116204 7F0E16D4 11800449 */  beqz  $t4, .L7F0E27FC
/* 116208 7F0E16D8 01008825 */   move  $s1, $t0
/* 11620C 7F0E16DC 97AE0298 */  lhu   $t6, 0x298($sp)
/* 116210 7F0E16E0 8FAB028C */  lw    $t3, 0x28c($sp)
/* 116214 7F0E16E4 25CFFFFE */  addiu $t7, $t6, -2
/* 116218 7F0E16E8 25690005 */  addiu $t1, $t3, 5
/* 11621C 7F0E16EC AFA9028C */  sw    $t1, 0x28c($sp)
/* 116220 7F0E16F0 10000442 */  b     .L7F0E27FC
/* 116224 7F0E16F4 A7AF0298 */   sh    $t7, 0x298($sp)
spectrum_op_ED_B9:
/* 116228 7F0E16F8 8FB8028C */  lw    $t8, 0x28c($sp)
/* 11622C 7F0E16FC 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 116230 7F0E1700 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 116234 7F0E1704 00165200 */  sll   $t2, $s6, 8
/* 116238 7F0E1708 32390001 */  andi  $t9, $s1, 1
/* 11623C 7F0E170C 01574025 */  or    $t0, $t2, $s7
/* 116240 7F0E1710 270D000C */  addiu $t5, $t8, 0xc
/* 116244 7F0E1714 AFAD028C */  sw    $t5, 0x28c($sp)
/* 116248 7F0E1718 A3B9005F */  sb    $t9, 0x5f($sp)
/* 11624C 7F0E171C 010C7021 */  addu  $t6, $t0, $t4
/* 116250 7F0E1720 91CF0000 */  lbu   $t7, ($t6)
/* 116254 7F0E1724 24010004 */  li    $at, 4
/* 116258 7F0E1728 020F5823 */  subu  $t3, $s0, $t7
/* 11625C 7F0E172C 316901FF */  andi  $t1, $t3, 0x1ff
/* 116260 7F0E1730 3138FFFF */  andi  $t8, $t1, 0xffff
/* 116264 7F0E1734 2F0D0001 */  sltiu $t5, $t8, 1
/* 116268 7F0E1738 3218000F */  andi  $t8, $s0, 0xf
/* 11626C 7F0E173C 31EB000F */  andi  $t3, $t7, 0xf
/* 116270 7F0E1740 030BC82A */  slt   $t9, $t8, $t3
/* 116274 7F0E1744 312A00A8 */  andi  $t2, $t1, 0xa8
/* 116278 7F0E1748 00096203 */  sra   $t4, $t1, 8
/* 11627C 7F0E174C 014C7025 */  or    $t6, $t2, $t4
/* 116280 7F0E1750 00194100 */  sll   $t0, $t9, 4
/* 116284 7F0E1754 01205825 */  move  $t3, $t1
/* 116288 7F0E1758 020F6026 */  xor   $t4, $s0, $t7
/* 11628C 7F0E175C 31980080 */  andi  $t8, $t4, 0x80
/* 116290 7F0E1760 0170C826 */  xor   $t9, $t3, $s0
/* 116294 7F0E1764 01C85025 */  or    $t2, $t6, $t0
/* 116298 7F0E1768 03197024 */  and   $t6, $t8, $t9
/* 11629C 7F0E176C 000E4143 */  sra   $t0, $t6, 5
/* 1162A0 7F0E1770 A3AF005B */  sb    $t7, 0x5b($sp)
/* 1162A4 7F0E1774 01487825 */  or    $t7, $t2, $t0
/* 1162A8 7F0E1778 A7A9005C */  sh    $t1, 0x5c($sp)
/* 1162AC 7F0E177C 000D4980 */  sll   $t1, $t5, 6
/* 1162B0 7F0E1780 35EC0002 */  ori   $t4, $t7, 2
/* 1162B4 7F0E1784 2EF80001 */  sltiu $t8, $s7, 1
/* 1162B8 7F0E1788 01898825 */  or    $s1, $t4, $t1
/* 1162BC 7F0E178C 26F7FFFF */  addiu $s7, $s7, -1
/* 1162C0 7F0E1790 322B00FF */  andi  $t3, $s1, 0xff
/* 1162C4 7F0E1794 AFAD0048 */  sw    $t5, 0x48($sp)
/* 1162C8 7F0E1798 32F900FF */  andi  $t9, $s7, 0xff
/* 1162CC 7F0E179C 01608825 */  move  $s1, $t3
/* 1162D0 7F0E17A0 0320B825 */  move  $s7, $t9
/* 1162D4 7F0E17A4 13000004 */  beqz  $t8, .L7F0E17B8
/* 1162D8 7F0E17A8 AFB80048 */   sw    $t8, 0x48($sp)
/* 1162DC 7F0E17AC 26D6FFFF */  addiu $s6, $s6, -1
/* 1162E0 7F0E17B0 32CA00FF */  andi  $t2, $s6, 0xff
/* 1162E4 7F0E17B4 0140B025 */  move  $s6, $t2
.L7F0E17B8:
/* 1162E8 7F0E17B8 2E680001 */  sltiu $t0, $s3, 1
/* 1162EC 7F0E17BC 2673FFFF */  addiu $s3, $s3, -1
/* 1162F0 7F0E17C0 326F00FF */  andi  $t7, $s3, 0xff
/* 1162F4 7F0E17C4 01E09825 */  move  $s3, $t7
/* 1162F8 7F0E17C8 11000004 */  beqz  $t0, .L7F0E17DC
/* 1162FC 7F0E17CC AFA80048 */   sw    $t0, 0x48($sp)
/* 116300 7F0E17D0 2652FFFF */  addiu $s2, $s2, -1
/* 116304 7F0E17D4 324C00FF */  andi  $t4, $s2, 0xff
/* 116308 7F0E17D8 01809025 */  move  $s2, $t4
.L7F0E17DC:
/* 11630C 7F0E17DC 93AB005F */  lbu   $t3, 0x5f($sp)
/* 116310 7F0E17E0 0253C825 */  or    $t9, $s2, $s3
/* 116314 7F0E17E4 0019702A */  slt   $t6, $zero, $t9
/* 116318 7F0E17E8 322900FA */  andi  $t1, $s1, 0xfa
/* 11631C 7F0E17EC 000E5080 */  sll   $t2, $t6, 2
/* 116320 7F0E17F0 012BC025 */  or    $t8, $t1, $t3
/* 116324 7F0E17F4 030A8825 */  or    $s1, $t8, $t2
/* 116328 7F0E17F8 322800FF */  andi  $t0, $s1, 0xff
/* 11632C 7F0E17FC 310F0044 */  andi  $t7, $t0, 0x44
/* 116330 7F0E1800 15E103FE */  bne   $t7, $at, .L7F0E27FC
/* 116334 7F0E1804 01008825 */   move  $s1, $t0
/* 116338 7F0E1808 97AD0298 */  lhu   $t5, 0x298($sp)
/* 11633C 7F0E180C 8FA9028C */  lw    $t1, 0x28c($sp)
/* 116340 7F0E1810 25ACFFFE */  addiu $t4, $t5, -2
/* 116344 7F0E1814 252B0005 */  addiu $t3, $t1, 5
/* 116348 7F0E1818 AFAB028C */  sw    $t3, 0x28c($sp)
/* 11634C 7F0E181C 100003F7 */  b     .L7F0E27FC
/* 116350 7F0E1820 A7AC0298 */   sh    $t4, 0x298($sp)
spectrum_op_ED_BA:
/* 116354 7F0E1824 8FB9028C */  lw    $t9, 0x28c($sp)
/* 116358 7F0E1828 02402825 */  move  $a1, $s2
/* 11635C 7F0E182C 02603025 */  move  $a2, $s3
/* 116360 7F0E1830 2724000C */  addiu $a0, $t9, 0xc
/* 116364 7F0E1834 0FC34DB6 */  jal   spectrum_input_handling
/* 116368 7F0E1838 AFA4028C */   sw    $a0, 0x28c($sp)
/* 11636C 7F0E183C 0016C200 */  sll   $t8, $s6, 8
/* 116370 7F0E1840 03175025 */  or    $t2, $t8, $s7
/* 116374 7F0E1844 29415B00 */  slti  $at, $t2, 0x5b00
/* 116378 7F0E1848 14200008 */  bnez  $at, .L7F0E186C
/* 11637C 7F0E184C A7A20058 */   sh    $v0, 0x58($sp)
/* 116380 7F0E1850 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 116384 7F0E1854 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 116388 7F0E1858 00166A00 */  sll   $t5, $s6, 8
/* 11638C 7F0E185C 01B76025 */  or    $t4, $t5, $s7
/* 116390 7F0E1860 01EC4821 */  addu  $t1, $t7, $t4
/* 116394 7F0E1864 1000002B */  b     .L7F0E1914
/* 116398 7F0E1868 A1220000 */   sb    $v0, ($t1)
.L7F0E186C:
/* 11639C 7F0E186C 00165A00 */  sll   $t3, $s6, 8
/* 1163A0 7F0E1870 0177C825 */  or    $t9, $t3, $s7
/* 1163A4 7F0E1874 2B215800 */  slti  $at, $t9, 0x5800
/* 1163A8 7F0E1878 14200010 */  bnez  $at, .L7F0E18BC
/* 1163AC 7F0E187C 00165200 */   sll   $t2, $s6, 8
/* 1163B0 7F0E1880 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 1163B4 7F0E1884 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 1163B8 7F0E1888 97AE0058 */  lhu   $t6, 0x58($sp)
/* 1163BC 7F0E188C 00165200 */  sll   $t2, $s6, 8
/* 1163C0 7F0E1890 01576825 */  or    $t5, $t2, $s7
/* 1163C4 7F0E1894 030D7821 */  addu  $t7, $t8, $t5
/* 1163C8 7F0E1898 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 1163CC 7F0E189C A1EE0000 */  sb    $t6, ($t7)
/* 1163D0 7F0E18A0 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 1163D4 7F0E18A4 00164A00 */  sll   $t1, $s6, 8
/* 1163D8 7F0E18A8 01375825 */  or    $t3, $t1, $s7
/* 1163DC 7F0E18AC 240C0001 */  li    $t4, 1
/* 1163E0 7F0E18B0 010BC821 */  addu  $t9, $t0, $t3
/* 1163E4 7F0E18B4 10000017 */  b     .L7F0E1914
/* 1163E8 7F0E18B8 A32CA800 */   sb    $t4, -0x5800($t9)
.L7F0E18BC:
/* 1163EC 7F0E18BC 0157C025 */  or    $t8, $t2, $s7
/* 1163F0 7F0E18C0 2B014000 */  slti  $at, $t8, 0x4000
/* 1163F4 7F0E18C4 14200013 */  bnez  $at, .L7F0E1914
/* 1163F8 7F0E18C8 97AD0058 */   lhu   $t5, 0x58($sp)
/* 1163FC 7F0E18CC 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 116400 7F0E18D0 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 116404 7F0E18D4 00167A00 */  sll   $t7, $s6, 8
/* 116408 7F0E18D8 01F74825 */  or    $t1, $t7, $s7
/* 11640C 7F0E18DC 01C94021 */  addu  $t0, $t6, $t1
/* 116410 7F0E18E0 A10D0000 */  sb    $t5, ($t0)
/* 116414 7F0E18E4 00166200 */  sll   $t4, $s6, 8
/* 116418 7F0E18E8 0197C825 */  or    $t9, $t4, $s7
/* 11641C 7F0E18EC 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 116420 7F0E18F0 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 116424 7F0E18F4 332A1800 */  andi  $t2, $t9, 0x1800
/* 116428 7F0E18F8 01F77025 */  or    $t6, $t7, $s7
/* 11642C 7F0E18FC 31C900FF */  andi  $t1, $t6, 0xff
/* 116430 7F0E1900 000AC0C3 */  sra   $t8, $t2, 3
/* 116434 7F0E1904 03096825 */  or    $t5, $t8, $t1
/* 116438 7F0E1908 240B0001 */  li    $t3, 1
/* 11643C 7F0E190C 010D6021 */  addu  $t4, $t0, $t5
/* 116440 7F0E1910 A18B0000 */  sb    $t3, ($t4)
.L7F0E1914:
/* 116444 7F0E1914 97AA0058 */  lhu   $t2, 0x58($sp)
/* 116448 7F0E1918 8FB9028C */  lw    $t9, 0x28c($sp)
/* 11644C 7F0E191C 2EF80001 */  sltiu $t8, $s7, 1
/* 116450 7F0E1920 26F7FFFF */  addiu $s7, $s7, -1
/* 116454 7F0E1924 000A7A03 */  sra   $t7, $t2, 8
/* 116458 7F0E1928 32E900FF */  andi  $t1, $s7, 0xff
/* 11645C 7F0E192C 032F7021 */  addu  $t6, $t9, $t7
/* 116460 7F0E1930 AFAE028C */  sw    $t6, 0x28c($sp)
/* 116464 7F0E1934 0120B825 */  move  $s7, $t1
/* 116468 7F0E1938 13000004 */  beqz  $t8, .L7F0E194C
/* 11646C 7F0E193C AFB80048 */   sw    $t8, 0x48($sp)
/* 116470 7F0E1940 26D6FFFF */  addiu $s6, $s6, -1
/* 116474 7F0E1944 32CD00FF */  andi  $t5, $s6, 0xff
/* 116478 7F0E1948 01A0B025 */  move  $s6, $t5
.L7F0E194C:
/* 11647C 7F0E194C 3C188009 */  lui   $t8, %hi(ptr_pc_keyboard_table_alloc) 
/* 116480 7F0E1950 8F18E334 */  lw    $t8, %lo(ptr_pc_keyboard_table_alloc)($t8)
/* 116484 7F0E1954 2652FFFF */  addiu $s2, $s2, -1
/* 116488 7F0E1958 324B00FF */  andi  $t3, $s2, 0xff
/* 11648C 7F0E195C 01784821 */  addu  $t1, $t3, $t8
/* 116490 7F0E1960 91280000 */  lbu   $t0, ($t1)
/* 116494 7F0E1964 316C00A8 */  andi  $t4, $t3, 0xa8
/* 116498 7F0E1968 000B502A */  slt   $t2, $zero, $t3
/* 11649C 7F0E196C 01609025 */  move  $s2, $t3
/* 1164A0 7F0E1970 000AC980 */  sll   $t9, $t2, 6
/* 1164A4 7F0E1974 01136826 */  xor   $t5, $t0, $s3
/* 1164A8 7F0E1978 39AB0004 */  xori  $t3, $t5, 4
/* 1164AC 7F0E197C 01997825 */  or    $t7, $t4, $t9
/* 1164B0 7F0E1980 35EE0002 */  ori   $t6, $t7, 2
/* 1164B4 7F0E1984 316A0004 */  andi  $t2, $t3, 4
/* 1164B8 7F0E1988 014E8825 */  or    $s1, $t2, $t6
/* 1164BC 7F0E198C 322C00FF */  andi  $t4, $s1, 0xff
/* 1164C0 7F0E1990 1240039A */  beqz  $s2, .L7F0E27FC
/* 1164C4 7F0E1994 01808825 */   move  $s1, $t4
/* 1164C8 7F0E1998 97B90298 */  lhu   $t9, 0x298($sp)
/* 1164CC 7F0E199C 8FB8028C */  lw    $t8, 0x28c($sp)
/* 1164D0 7F0E19A0 272FFFFE */  addiu $t7, $t9, -2
/* 1164D4 7F0E19A4 27090005 */  addiu $t1, $t8, 5
/* 1164D8 7F0E19A8 AFA9028C */  sw    $t1, 0x28c($sp)
/* 1164DC 7F0E19AC 10000393 */  b     .L7F0E27FC
/* 1164E0 7F0E19B0 A7AF0298 */   sh    $t7, 0x298($sp)
spectrum_op_ED_BB:
/* 1164E4 7F0E19B4 8FA8028C */  lw    $t0, 0x28c($sp)
/* 1164E8 7F0E19B8 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 1164EC 7F0E19BC 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 1164F0 7F0E19C0 00165A00 */  sll   $t3, $s6, 8
/* 1164F4 7F0E19C4 01775025 */  or    $t2, $t3, $s7
/* 1164F8 7F0E19C8 2504000C */  addiu $a0, $t0, 0xc
/* 1164FC 7F0E19CC AFA4028C */  sw    $a0, 0x28c($sp)
/* 116500 7F0E19D0 014E6021 */  addu  $t4, $t2, $t6
/* 116504 7F0E19D4 91870000 */  lbu   $a3, ($t4)
/* 116508 7F0E19D8 02402825 */  move  $a1, $s2
/* 11650C 7F0E19DC 02603025 */  move  $a2, $s3
/* 116510 7F0E19E0 0FC34DF7 */  jal   sub_GAME_7F0D37DC
/* 116514 7F0E19E4 A3A70057 */   sb    $a3, 0x57($sp)
/* 116518 7F0E19E8 8FAF028C */  lw    $t7, 0x28c($sp)
/* 11651C 7F0E19EC 2EE80001 */  sltiu $t0, $s7, 1
/* 116520 7F0E19F0 26F7FFFF */  addiu $s7, $s7, -1
/* 116524 7F0E19F4 AFA20048 */  sw    $v0, 0x48($sp)
/* 116528 7F0E19F8 32EB00FF */  andi  $t3, $s7, 0xff
/* 11652C 7F0E19FC 01E24821 */  addu  $t1, $t7, $v0
/* 116530 7F0E1A00 AFA9028C */  sw    $t1, 0x28c($sp)
/* 116534 7F0E1A04 0160B825 */  move  $s7, $t3
/* 116538 7F0E1A08 11000004 */  beqz  $t0, .L7F0E1A1C
/* 11653C 7F0E1A0C AFA80048 */   sw    $t0, 0x48($sp)
/* 116540 7F0E1A10 26D6FFFF */  addiu $s6, $s6, -1
/* 116544 7F0E1A14 32CE00FF */  andi  $t6, $s6, 0xff
/* 116548 7F0E1A18 01C0B025 */  move  $s6, $t6
.L7F0E1A1C:
/* 11654C 7F0E1A1C 2652FFFF */  addiu $s2, $s2, -1
/* 116550 7F0E1A20 324C00FF */  andi  $t4, $s2, 0xff
/* 116554 7F0E1A24 322D0001 */  andi  $t5, $s1, 1
/* 116558 7F0E1A28 35B90012 */  ori   $t9, $t5, 0x12
/* 11655C 7F0E1A2C 318F00A8 */  andi  $t7, $t4, 0xa8
/* 116560 7F0E1A30 2D890001 */  sltiu $t1, $t4, 1
/* 116564 7F0E1A34 00094180 */  sll   $t0, $t1, 6
/* 116568 7F0E1A38 032FC025 */  or    $t8, $t9, $t7
/* 11656C 7F0E1A3C 03088825 */  or    $s1, $t8, $t0
/* 116570 7F0E1A40 322B00FF */  andi  $t3, $s1, 0xff
/* 116574 7F0E1A44 01809025 */  move  $s2, $t4
/* 116578 7F0E1A48 1180036C */  beqz  $t4, .L7F0E27FC
/* 11657C 7F0E1A4C 01608825 */   move  $s1, $t3
/* 116580 7F0E1A50 97AA0298 */  lhu   $t2, 0x298($sp)
/* 116584 7F0E1A54 8FAC028C */  lw    $t4, 0x28c($sp)
/* 116588 7F0E1A58 254EFFFE */  addiu $t6, $t2, -2
/* 11658C 7F0E1A5C 258D0005 */  addiu $t5, $t4, 5
/* 116590 7F0E1A60 AFAD028C */  sw    $t5, 0x28c($sp)
/* 116594 7F0E1A64 10000365 */  b     .L7F0E27FC
/* 116598 7F0E1A68 A7AE0298 */   sh    $t6, 0x298($sp)
.L7F0E1A6C:
/* 11659C 7F0E1A6C 8FB9028C */  lw    $t9, 0x28c($sp)
/* 1165A0 7F0E1A70 272F0004 */  addiu $t7, $t9, 4
/* 1165A4 7F0E1A74 10000361 */  b     .L7F0E27FC
/* 1165A8 7F0E1A78 AFAF028C */   sw    $t7, 0x28c($sp)
spectrum_op_EE:
/* 1165AC 7F0E1A7C 8FA9028C */  lw    $t1, 0x28c($sp)
/* 1165B0 7F0E1A80 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 1165B4 7F0E1A84 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 1165B8 7F0E1A88 97AB0298 */  lhu   $t3, 0x298($sp)
/* 1165BC 7F0E1A8C 25380007 */  addiu $t8, $t1, 7
/* 1165C0 7F0E1A90 AFB8028C */  sw    $t8, 0x28c($sp)
/* 1165C4 7F0E1A94 010B5021 */  addu  $t2, $t0, $t3
/* 1165C8 7F0E1A98 914E0000 */  lbu   $t6, ($t2)
/* 1165CC 7F0E1A9C 3C088009 */  lui   $t0, %hi(ptr_pc_keyboard_table_alloc) 
/* 1165D0 7F0E1AA0 8D08E334 */  lw    $t0, %lo(ptr_pc_keyboard_table_alloc)($t0)
/* 1165D4 7F0E1AA4 020E8026 */  xor   $s0, $s0, $t6
/* 1165D8 7F0E1AA8 320C00FF */  andi  $t4, $s0, 0xff
/* 1165DC 7F0E1AAC 2D8D0001 */  sltiu $t5, $t4, 1
/* 1165E0 7F0E1AB0 AFAD0048 */  sw    $t5, 0x48($sp)
/* 1165E4 7F0E1AB4 01885821 */  addu  $t3, $t4, $t0
/* 1165E8 7F0E1AB8 916A0000 */  lbu   $t2, ($t3)
/* 1165EC 7F0E1ABC 01808025 */  move  $s0, $t4
/* 1165F0 7F0E1AC0 319900A8 */  andi  $t9, $t4, 0xa8
/* 1165F4 7F0E1AC4 97AC0298 */  lhu   $t4, 0x298($sp)
/* 1165F8 7F0E1AC8 000D4980 */  sll   $t1, $t5, 6
/* 1165FC 7F0E1ACC 0329C025 */  or    $t8, $t9, $t1
/* 116600 7F0E1AD0 01588825 */  or    $s1, $t2, $t8
/* 116604 7F0E1AD4 322E00FF */  andi  $t6, $s1, 0xff
/* 116608 7F0E1AD8 258D0001 */  addiu $t5, $t4, 1
/* 11660C 7F0E1ADC 01C08825 */  move  $s1, $t6
/* 116610 7F0E1AE0 10000346 */  b     .L7F0E27FC
/* 116614 7F0E1AE4 A7AD0298 */   sh    $t5, 0x298($sp)
spectrum_op_EF:
/* 116618 7F0E1AE8 97A90292 */  lhu   $t1, 0x292($sp)
/* 11661C 7F0E1AEC 8FAF028C */  lw    $t7, 0x28c($sp)
/* 116620 7F0E1AF0 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 116624 7F0E1AF4 2528FFFE */  addiu $t0, $t1, -2
/* 116628 7F0E1AF8 310BFFFF */  andi  $t3, $t0, 0xffff
/* 11662C 7F0E1AFC 29615B00 */  slti  $at, $t3, 0x5b00
/* 116630 7F0E1B00 25F9000B */  addiu $t9, $t7, 0xb
/* 116634 7F0E1B04 AFB9028C */  sw    $t9, 0x28c($sp)
/* 116638 7F0E1B08 14200006 */  bnez  $at, .L7F0E1B24
/* 11663C 7F0E1B0C A7A80292 */   sh    $t0, 0x292($sp)
/* 116640 7F0E1B10 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 116644 7F0E1B14 97AA0298 */  lhu   $t2, 0x298($sp)
/* 116648 7F0E1B18 030B7021 */  addu  $t6, $t8, $t3
/* 11664C 7F0E1B1C 10000023 */  b     .L7F0E1BAC
/* 116650 7F0E1B20 A1CA0000 */   sb    $t2, ($t6)
.L7F0E1B24:
/* 116654 7F0E1B24 97AC0292 */  lhu   $t4, 0x292($sp)
/* 116658 7F0E1B28 97AA0292 */  lhu   $t2, 0x292($sp)
/* 11665C 7F0E1B2C 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 116660 7F0E1B30 29815800 */  slti  $at, $t4, 0x5800
/* 116664 7F0E1B34 5420000D */  bnezl $at, .L7F0E1B6C
/* 116668 7F0E1B38 29414000 */   slti  $at, $t2, 0x4000
/* 11666C 7F0E1B3C 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 116670 7F0E1B40 97AD0298 */  lhu   $t5, 0x298($sp)
/* 116674 7F0E1B44 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 116678 7F0E1B48 01ECC821 */  addu  $t9, $t7, $t4
/* 11667C 7F0E1B4C A32D0000 */  sb    $t5, ($t9)
/* 116680 7F0E1B50 97B80292 */  lhu   $t8, 0x292($sp)
/* 116684 7F0E1B54 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 116688 7F0E1B58 24090001 */  li    $t1, 1
/* 11668C 7F0E1B5C 01185821 */  addu  $t3, $t0, $t8
/* 116690 7F0E1B60 10000012 */  b     .L7F0E1BAC
/* 116694 7F0E1B64 A169A800 */   sb    $t1, -0x5800($t3)
/* 116698 7F0E1B68 29414000 */  slti  $at, $t2, 0x4000
.L7F0E1B6C:
/* 11669C 7F0E1B6C 1420000F */  bnez  $at, .L7F0E1BAC
/* 1166A0 7F0E1B70 3C0F8009 */   lui   $t7, %hi(ptr_spectrum_roms) 
/* 1166A4 7F0E1B74 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 1166A8 7F0E1B78 97AE0298 */  lhu   $t6, 0x298($sp)
/* 1166AC 7F0E1B7C 240D0001 */  li    $t5, 1
/* 1166B0 7F0E1B80 01EA6021 */  addu  $t4, $t7, $t2
/* 1166B4 7F0E1B84 A18E0000 */  sb    $t6, ($t4)
/* 1166B8 7F0E1B88 97B90292 */  lhu   $t9, 0x292($sp)
/* 1166BC 7F0E1B8C 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 1166C0 7F0E1B90 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 1166C4 7F0E1B94 33281800 */  andi  $t0, $t9, 0x1800
/* 1166C8 7F0E1B98 0008C0C3 */  sra   $t8, $t0, 3
/* 1166CC 7F0E1B9C 332900FF */  andi  $t1, $t9, 0xff
/* 1166D0 7F0E1BA0 03095825 */  or    $t3, $t8, $t1
/* 1166D4 7F0E1BA4 01EB5021 */  addu  $t2, $t7, $t3
/* 1166D8 7F0E1BA8 A14D0000 */  sb    $t5, ($t2)
.L7F0E1BAC:
/* 1166DC 7F0E1BAC 97AE0292 */  lhu   $t6, 0x292($sp)
/* 1166E0 7F0E1BB0 97AF0292 */  lhu   $t7, 0x292($sp)
/* 1166E4 7F0E1BB4 97A80298 */  lhu   $t0, 0x298($sp)
/* 1166E8 7F0E1BB8 25CC0001 */  addiu $t4, $t6, 1
/* 1166EC 7F0E1BBC 29815B00 */  slti  $at, $t4, 0x5b00
/* 1166F0 7F0E1BC0 14200007 */  bnez  $at, .L7F0E1BE0
/* 1166F4 7F0E1BC4 25EB0001 */   addiu $t3, $t7, 1
/* 1166F8 7F0E1BC8 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 1166FC 7F0E1BCC 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 116700 7F0E1BD0 0008CA03 */  sra   $t9, $t0, 8
/* 116704 7F0E1BD4 030E4821 */  addu  $t1, $t8, $t6
/* 116708 7F0E1BD8 10000025 */  b     .L7F0E1C70
/* 11670C 7F0E1BDC A1390001 */   sb    $t9, 1($t1)
.L7F0E1BE0:
/* 116710 7F0E1BE0 29615800 */  slti  $at, $t3, 0x5800
/* 116714 7F0E1BE4 1420000E */  bnez  $at, .L7F0E1C20
/* 116718 7F0E1BE8 97AB0292 */   lhu   $t3, 0x292($sp)
/* 11671C 7F0E1BEC 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 116720 7F0E1BF0 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 116724 7F0E1BF4 97AD0298 */  lhu   $t5, 0x298($sp)
/* 116728 7F0E1BF8 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 11672C 7F0E1BFC 018F4021 */  addu  $t0, $t4, $t7
/* 116730 7F0E1C00 000D5203 */  sra   $t2, $t5, 8
/* 116734 7F0E1C04 A10A0001 */  sb    $t2, 1($t0)
/* 116738 7F0E1C08 97B90292 */  lhu   $t9, 0x292($sp)
/* 11673C 7F0E1C0C 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 116740 7F0E1C10 24180001 */  li    $t8, 1
/* 116744 7F0E1C14 01D94821 */  addu  $t1, $t6, $t9
/* 116748 7F0E1C18 10000015 */  b     .L7F0E1C70
/* 11674C 7F0E1C1C A138A801 */   sb    $t8, -0x57ff($t1)
.L7F0E1C20:
/* 116750 7F0E1C20 256D0001 */  addiu $t5, $t3, 1
/* 116754 7F0E1C24 29A14000 */  slti  $at, $t5, 0x4000
/* 116758 7F0E1C28 14200011 */  bnez  $at, .L7F0E1C70
/* 11675C 7F0E1C2C 97AC0298 */   lhu   $t4, 0x298($sp)
/* 116760 7F0E1C30 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 116764 7F0E1C34 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 116768 7F0E1C38 000C7A03 */  sra   $t7, $t4, 8
/* 11676C 7F0E1C3C 240E0001 */  li    $t6, 1
/* 116770 7F0E1C40 014B4021 */  addu  $t0, $t2, $t3
/* 116774 7F0E1C44 A10F0001 */  sb    $t7, 1($t0)
/* 116778 7F0E1C48 97B90292 */  lhu   $t9, 0x292($sp)
/* 11677C 7F0E1C4C 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 116780 7F0E1C50 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 116784 7F0E1C54 27380001 */  addiu $t8, $t9, 1
/* 116788 7F0E1C58 33091800 */  andi  $t1, $t8, 0x1800
/* 11678C 7F0E1C5C 000968C3 */  sra   $t5, $t1, 3
/* 116790 7F0E1C60 330C00FF */  andi  $t4, $t8, 0xff
/* 116794 7F0E1C64 01AC5025 */  or    $t2, $t5, $t4
/* 116798 7F0E1C68 016A7821 */  addu  $t7, $t3, $t2
/* 11679C 7F0E1C6C A1EE0000 */  sb    $t6, ($t7)
.L7F0E1C70:
/* 1167A0 7F0E1C70 24080028 */  li    $t0, 40
/* 1167A4 7F0E1C74 100002E1 */  b     .L7F0E27FC
/* 1167A8 7F0E1C78 A7A80298 */   sh    $t0, 0x298($sp)
spectrum_op_F0:
/* 1167AC 7F0E1C7C 8FB9028C */  lw    $t9, 0x28c($sp)
/* 1167B0 7F0E1C80 32380080 */  andi  $t8, $s1, 0x80
/* 1167B4 7F0E1C84 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 1167B8 7F0E1C88 27290005 */  addiu $t1, $t9, 5
/* 1167BC 7F0E1C8C 170002DB */  bnez  $t8, .L7F0E27FC
/* 1167C0 7F0E1C90 AFA9028C */   sw    $t1, 0x28c($sp)
/* 1167C4 7F0E1C94 97AB0292 */  lhu   $t3, 0x292($sp)
/* 1167C8 7F0E1C98 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 1167CC 7F0E1C9C 252C0006 */  addiu $t4, $t1, 6
/* 1167D0 7F0E1CA0 AFAC028C */  sw    $t4, 0x28c($sp)
/* 1167D4 7F0E1CA4 014B4021 */  addu  $t0, $t2, $t3
/* 1167D8 7F0E1CA8 91190001 */  lbu   $t9, 1($t0)
/* 1167DC 7F0E1CAC 016A7021 */  addu  $t6, $t3, $t2
/* 1167E0 7F0E1CB0 91CF0000 */  lbu   $t7, ($t6)
/* 1167E4 7F0E1CB4 00194A00 */  sll   $t1, $t9, 8
/* 1167E8 7F0E1CB8 256D0002 */  addiu $t5, $t3, 2
/* 1167EC 7F0E1CBC 01E9C025 */  or    $t8, $t7, $t1
/* 1167F0 7F0E1CC0 A7B80298 */  sh    $t8, 0x298($sp)
/* 1167F4 7F0E1CC4 100002CD */  b     .L7F0E27FC
/* 1167F8 7F0E1CC8 A7AD0292 */   sh    $t5, 0x292($sp)
spectrum_op_F1:
/* 1167FC 7F0E1CCC 8FAC028C */  lw    $t4, 0x28c($sp)
/* 116800 7F0E1CD0 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 116804 7F0E1CD4 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 116808 7F0E1CD8 97AA0292 */  lhu   $t2, 0x292($sp)
/* 11680C 7F0E1CDC 258E000A */  addiu $t6, $t4, 0xa
/* 116810 7F0E1CE0 AFAE028C */  sw    $t6, 0x28c($sp)
/* 116814 7F0E1CE4 0148C821 */  addu  $t9, $t2, $t0
/* 116818 7F0E1CE8 93310000 */  lbu   $s1, ($t9)
/* 11681C 7F0E1CEC 93300001 */  lbu   $s0, 1($t9)
/* 116820 7F0E1CF0 254F0002 */  addiu $t7, $t2, 2
/* 116824 7F0E1CF4 100002C1 */  b     .L7F0E27FC
/* 116828 7F0E1CF8 A7AF0292 */   sh    $t7, 0x292($sp)
spectrum_op_F2:
/* 11682C 7F0E1CFC 8FA9028C */  lw    $t1, 0x28c($sp)
/* 116830 7F0E1D00 322B0080 */  andi  $t3, $s1, 0x80
/* 116834 7F0E1D04 97AD0298 */  lhu   $t5, 0x298($sp)
/* 116838 7F0E1D08 2538000A */  addiu $t8, $t1, 0xa
/* 11683C 7F0E1D0C 1560000B */  bnez  $t3, .L7F0E1D3C
/* 116840 7F0E1D10 AFB8028C */   sw    $t8, 0x28c($sp)
/* 116844 7F0E1D14 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 116848 7F0E1D18 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 11684C 7F0E1D1C 018DC821 */  addu  $t9, $t4, $t5
/* 116850 7F0E1D20 932A0001 */  lbu   $t2, 1($t9)
/* 116854 7F0E1D24 01AC7021 */  addu  $t6, $t5, $t4
/* 116858 7F0E1D28 91C80000 */  lbu   $t0, ($t6)
/* 11685C 7F0E1D2C 000A7A00 */  sll   $t7, $t2, 8
/* 116860 7F0E1D30 010F4825 */  or    $t1, $t0, $t7
/* 116864 7F0E1D34 100002B1 */  b     .L7F0E27FC
/* 116868 7F0E1D38 A7A90298 */   sh    $t1, 0x298($sp)
.L7F0E1D3C:
/* 11686C 7F0E1D3C 97B80298 */  lhu   $t8, 0x298($sp)
/* 116870 7F0E1D40 270B0002 */  addiu $t3, $t8, 2
/* 116874 7F0E1D44 100002AD */  b     .L7F0E27FC
/* 116878 7F0E1D48 A7AB0298 */   sh    $t3, 0x298($sp)
spectrum_op_F3:
/* 11687C 7F0E1D4C 8FAE028C */  lw    $t6, 0x28c($sp)
/* 116880 7F0E1D50 A3A0029C */  sb    $zero, 0x29c($sp)
/* 116884 7F0E1D54 A3A0029D */  sb    $zero, 0x29d($sp)
/* 116888 7F0E1D58 25CC0004 */  addiu $t4, $t6, 4
/* 11688C 7F0E1D5C AFAC028C */  sw    $t4, 0x28c($sp)
/* 116890 7F0E1D60 100002A6 */  b     .L7F0E27FC
/* 116894 7F0E1D64 A3A00285 */   sb    $zero, 0x285($sp)
spectrum_op_F4:
/* 116898 7F0E1D68 8FAD028C */  lw    $t5, 0x28c($sp)
/* 11689C 7F0E1D6C 322A0080 */  andi  $t2, $s1, 0x80
/* 1168A0 7F0E1D70 25B9000A */  addiu $t9, $t5, 0xa
/* 1168A4 7F0E1D74 15400072 */  bnez  $t2, .L7F0E1F40
/* 1168A8 7F0E1D78 AFB9028C */   sw    $t9, 0x28c($sp)
/* 1168AC 7F0E1D7C 97A90292 */  lhu   $t1, 0x292($sp)
/* 1168B0 7F0E1D80 272F0007 */  addiu $t7, $t9, 7
/* 1168B4 7F0E1D84 AFAF028C */  sw    $t7, 0x28c($sp)
/* 1168B8 7F0E1D88 2538FFFE */  addiu $t8, $t1, -2
/* 1168BC 7F0E1D8C 330BFFFF */  andi  $t3, $t8, 0xffff
/* 1168C0 7F0E1D90 29615B00 */  slti  $at, $t3, 0x5b00
/* 1168C4 7F0E1D94 14200008 */  bnez  $at, .L7F0E1DB8
/* 1168C8 7F0E1D98 A7B80292 */   sh    $t8, 0x292($sp)
/* 1168CC 7F0E1D9C 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 1168D0 7F0E1DA0 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 1168D4 7F0E1DA4 97AE0298 */  lhu   $t6, 0x298($sp)
/* 1168D8 7F0E1DA8 01ABC821 */  addu  $t9, $t5, $t3
/* 1168DC 7F0E1DAC 25CC0002 */  addiu $t4, $t6, 2
/* 1168E0 7F0E1DB0 10000024 */  b     .L7F0E1E44
/* 1168E4 7F0E1DB4 A32C0000 */   sb    $t4, ($t9)
.L7F0E1DB8:
/* 1168E8 7F0E1DB8 97AA0292 */  lhu   $t2, 0x292($sp)
/* 1168EC 7F0E1DBC 97B90292 */  lhu   $t9, 0x292($sp)
/* 1168F0 7F0E1DC0 97A80298 */  lhu   $t0, 0x298($sp)
/* 1168F4 7F0E1DC4 29415800 */  slti  $at, $t2, 0x5800
/* 1168F8 7F0E1DC8 1420000C */  bnez  $at, .L7F0E1DFC
/* 1168FC 7F0E1DCC 3C098009 */   lui   $t1, %hi(ptr_spectrum_roms) 
/* 116900 7F0E1DD0 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 116904 7F0E1DD4 250F0002 */  addiu $t7, $t0, 2
/* 116908 7F0E1DD8 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 11690C 7F0E1DDC 012AC021 */  addu  $t8, $t1, $t2
/* 116910 7F0E1DE0 A30F0000 */  sb    $t7, ($t8)
/* 116914 7F0E1DE4 97AB0292 */  lhu   $t3, 0x292($sp)
/* 116918 7F0E1DE8 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 11691C 7F0E1DEC 240E0001 */  li    $t6, 1
/* 116920 7F0E1DF0 01AB6021 */  addu  $t4, $t5, $t3
/* 116924 7F0E1DF4 10000013 */  b     .L7F0E1E44
/* 116928 7F0E1DF8 A18EA800 */   sb    $t6, -0x5800($t4)
.L7F0E1DFC:
/* 11692C 7F0E1DFC 2B214000 */  slti  $at, $t9, 0x4000
/* 116930 7F0E1E00 14200010 */  bnez  $at, .L7F0E1E44
/* 116934 7F0E1E04 97A80298 */   lhu   $t0, 0x298($sp)
/* 116938 7F0E1E08 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 11693C 7F0E1E0C 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 116940 7F0E1E10 25090002 */  addiu $t1, $t0, 2
/* 116944 7F0E1E14 24180001 */  li    $t8, 1
/* 116948 7F0E1E18 01597821 */  addu  $t7, $t2, $t9
/* 11694C 7F0E1E1C A1E90000 */  sb    $t1, ($t7)
/* 116950 7F0E1E20 97AD0292 */  lhu   $t5, 0x292($sp)
/* 116954 7F0E1E24 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 116958 7F0E1E28 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 11695C 7F0E1E2C 31AB1800 */  andi  $t3, $t5, 0x1800
/* 116960 7F0E1E30 000B70C3 */  sra   $t6, $t3, 3
/* 116964 7F0E1E34 31AC00FF */  andi  $t4, $t5, 0xff
/* 116968 7F0E1E38 01CC4025 */  or    $t0, $t6, $t4
/* 11696C 7F0E1E3C 0148C821 */  addu  $t9, $t2, $t0
/* 116970 7F0E1E40 A3380000 */  sb    $t8, ($t9)
.L7F0E1E44:
/* 116974 7F0E1E44 97A90292 */  lhu   $t1, 0x292($sp)
/* 116978 7F0E1E48 97A80292 */  lhu   $t0, 0x292($sp)
/* 11697C 7F0E1E4C 97AB0298 */  lhu   $t3, 0x298($sp)
/* 116980 7F0E1E50 252F0001 */  addiu $t7, $t1, 1
/* 116984 7F0E1E54 29E15B00 */  slti  $at, $t7, 0x5b00
/* 116988 7F0E1E58 14200008 */  bnez  $at, .L7F0E1E7C
/* 11698C 7F0E1E5C 25180001 */   addiu $t8, $t0, 1
/* 116990 7F0E1E60 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 116994 7F0E1E64 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 116998 7F0E1E68 256D0002 */  addiu $t5, $t3, 2
/* 11699C 7F0E1E6C 000D7203 */  sra   $t6, $t5, 8
/* 1169A0 7F0E1E70 01895021 */  addu  $t2, $t4, $t1
/* 1169A4 7F0E1E74 10000027 */  b     .L7F0E1F14
/* 1169A8 7F0E1E78 A14E0001 */   sb    $t6, 1($t2)
.L7F0E1E7C:
/* 1169AC 7F0E1E7C 2B015800 */  slti  $at, $t8, 0x5800
/* 1169B0 7F0E1E80 1420000F */  bnez  $at, .L7F0E1EC0
/* 1169B4 7F0E1E84 97B90292 */   lhu   $t9, 0x292($sp)
/* 1169B8 7F0E1E88 97B90298 */  lhu   $t9, 0x298($sp)
/* 1169BC 7F0E1E8C 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 1169C0 7F0E1E90 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 1169C4 7F0E1E94 272F0002 */  addiu $t7, $t9, 2
/* 1169C8 7F0E1E98 000F5A03 */  sra   $t3, $t7, 8
/* 1169CC 7F0E1E9C 01A86021 */  addu  $t4, $t5, $t0
/* 1169D0 7F0E1EA0 A18B0001 */  sb    $t3, 1($t4)
/* 1169D4 7F0E1EA4 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 1169D8 7F0E1EA8 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 1169DC 7F0E1EAC 97AA0292 */  lhu   $t2, 0x292($sp)
/* 1169E0 7F0E1EB0 24090001 */  li    $t1, 1
/* 1169E4 7F0E1EB4 01CAC021 */  addu  $t8, $t6, $t2
/* 1169E8 7F0E1EB8 10000016 */  b     .L7F0E1F14
/* 1169EC 7F0E1EBC A309A801 */   sb    $t1, -0x57ff($t8)
.L7F0E1EC0:
/* 1169F0 7F0E1EC0 272F0001 */  addiu $t7, $t9, 1
/* 1169F4 7F0E1EC4 29E14000 */  slti  $at, $t7, 0x4000
/* 1169F8 7F0E1EC8 14200012 */  bnez  $at, .L7F0E1F14
/* 1169FC 7F0E1ECC 97AD0298 */   lhu   $t5, 0x298($sp)
/* 116A00 7F0E1ED0 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 116A04 7F0E1ED4 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 116A08 7F0E1ED8 25A80002 */  addiu $t0, $t5, 2
/* 116A0C 7F0E1EDC 00085A03 */  sra   $t3, $t0, 8
/* 116A10 7F0E1EE0 01997021 */  addu  $t6, $t4, $t9
/* 116A14 7F0E1EE4 A1CB0001 */  sb    $t3, 1($t6)
/* 116A18 7F0E1EE8 97A90292 */  lhu   $t1, 0x292($sp)
/* 116A1C 7F0E1EEC 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 116A20 7F0E1EF0 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 116A24 7F0E1EF4 25380001 */  addiu $t8, $t1, 1
/* 116A28 7F0E1EF8 330F1800 */  andi  $t7, $t8, 0x1800
/* 116A2C 7F0E1EFC 000F68C3 */  sra   $t5, $t7, 3
/* 116A30 7F0E1F00 330800FF */  andi  $t0, $t8, 0xff
/* 116A34 7F0E1F04 01A86025 */  or    $t4, $t5, $t0
/* 116A38 7F0E1F08 240A0001 */  li    $t2, 1
/* 116A3C 7F0E1F0C 032C5821 */  addu  $t3, $t9, $t4
/* 116A40 7F0E1F10 A16A0000 */  sb    $t2, ($t3)
.L7F0E1F14:
/* 116A44 7F0E1F14 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 116A48 7F0E1F18 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 116A4C 7F0E1F1C 97AE0298 */  lhu   $t6, 0x298($sp)
/* 116A50 7F0E1F20 012E6821 */  addu  $t5, $t1, $t6
/* 116A54 7F0E1F24 91A80001 */  lbu   $t0, 1($t5)
/* 116A58 7F0E1F28 01C97821 */  addu  $t7, $t6, $t1
/* 116A5C 7F0E1F2C 91F80000 */  lbu   $t8, ($t7)
/* 116A60 7F0E1F30 0008CA00 */  sll   $t9, $t0, 8
/* 116A64 7F0E1F34 03196025 */  or    $t4, $t8, $t9
/* 116A68 7F0E1F38 10000230 */  b     .L7F0E27FC
/* 116A6C 7F0E1F3C A7AC0298 */   sh    $t4, 0x298($sp)
.L7F0E1F40:
/* 116A70 7F0E1F40 97AA0298 */  lhu   $t2, 0x298($sp)
/* 116A74 7F0E1F44 254B0002 */  addiu $t3, $t2, 2
/* 116A78 7F0E1F48 1000022C */  b     .L7F0E27FC
/* 116A7C 7F0E1F4C A7AB0298 */   sh    $t3, 0x298($sp)
spectrum_op_F5:
/* 116A80 7F0E1F50 97AE0292 */  lhu   $t6, 0x292($sp)
/* 116A84 7F0E1F54 8FAF028C */  lw    $t7, 0x28c($sp)
/* 116A88 7F0E1F58 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 116A8C 7F0E1F5C 25CDFFFE */  addiu $t5, $t6, -2
/* 116A90 7F0E1F60 31A8FFFF */  andi  $t0, $t5, 0xffff
/* 116A94 7F0E1F64 29015B00 */  slti  $at, $t0, 0x5b00
/* 116A98 7F0E1F68 25E9000B */  addiu $t1, $t7, 0xb
/* 116A9C 7F0E1F6C AFA9028C */  sw    $t1, 0x28c($sp)
/* 116AA0 7F0E1F70 14200005 */  bnez  $at, .L7F0E1F88
/* 116AA4 7F0E1F74 A7AD0292 */   sh    $t5, 0x292($sp)
/* 116AA8 7F0E1F78 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 116AAC 7F0E1F7C 0308C821 */  addu  $t9, $t8, $t0
/* 116AB0 7F0E1F80 10000021 */  b     .L7F0E2008
/* 116AB4 7F0E1F84 A3310000 */   sb    $s1, ($t9)
.L7F0E1F88:
/* 116AB8 7F0E1F88 97AC0292 */  lhu   $t4, 0x292($sp)
/* 116ABC 7F0E1F8C 97B80292 */  lhu   $t8, 0x292($sp)
/* 116AC0 7F0E1F90 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 116AC4 7F0E1F94 29815800 */  slti  $at, $t4, 0x5800
/* 116AC8 7F0E1F98 5420000C */  bnezl $at, .L7F0E1FCC
/* 116ACC 7F0E1F9C 2B014000 */   slti  $at, $t8, 0x4000
/* 116AD0 7F0E1FA0 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 116AD4 7F0E1FA4 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 116AD8 7F0E1FA8 240F0001 */  li    $t7, 1
/* 116ADC 7F0E1FAC 014C5821 */  addu  $t3, $t2, $t4
/* 116AE0 7F0E1FB0 A1710000 */  sb    $s1, ($t3)
/* 116AE4 7F0E1FB4 97AE0292 */  lhu   $t6, 0x292($sp)
/* 116AE8 7F0E1FB8 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 116AEC 7F0E1FBC 012E6821 */  addu  $t5, $t1, $t6
/* 116AF0 7F0E1FC0 10000011 */  b     .L7F0E2008
/* 116AF4 7F0E1FC4 A1AFA800 */   sb    $t7, -0x5800($t5)
/* 116AF8 7F0E1FC8 2B014000 */  slti  $at, $t8, 0x4000
.L7F0E1FCC:
/* 116AFC 7F0E1FCC 1420000E */  bnez  $at, .L7F0E2008
/* 116B00 7F0E1FD0 3C088009 */   lui   $t0, %hi(ptr_spectrum_roms) 
/* 116B04 7F0E1FD4 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 116B08 7F0E1FD8 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 116B0C 7F0E1FDC 240A0001 */  li    $t2, 1
/* 116B10 7F0E1FE0 0118C821 */  addu  $t9, $t0, $t8
/* 116B14 7F0E1FE4 A3310000 */  sb    $s1, ($t9)
/* 116B18 7F0E1FE8 97AC0292 */  lhu   $t4, 0x292($sp)
/* 116B1C 7F0E1FEC 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 116B20 7F0E1FF0 318B1800 */  andi  $t3, $t4, 0x1800
/* 116B24 7F0E1FF4 000B48C3 */  sra   $t1, $t3, 3
/* 116B28 7F0E1FF8 318E00FF */  andi  $t6, $t4, 0xff
/* 116B2C 7F0E1FFC 012E7825 */  or    $t7, $t1, $t6
/* 116B30 7F0E2000 01AF4021 */  addu  $t0, $t5, $t7
/* 116B34 7F0E2004 A10A0000 */  sb    $t2, ($t0)
.L7F0E2008:
/* 116B38 7F0E2008 97B80292 */  lhu   $t8, 0x292($sp)
/* 116B3C 7F0E200C 97A90292 */  lhu   $t1, 0x292($sp)
/* 116B40 7F0E2010 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 116B44 7F0E2014 27190001 */  addiu $t9, $t8, 1
/* 116B48 7F0E2018 2B215B00 */  slti  $at, $t9, 0x5b00
/* 116B4C 7F0E201C 14200005 */  bnez  $at, .L7F0E2034
/* 116B50 7F0E2020 252E0001 */   addiu $t6, $t1, 1
/* 116B54 7F0E2024 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 116B58 7F0E2028 01786021 */  addu  $t4, $t3, $t8
/* 116B5C 7F0E202C 100001F3 */  b     .L7F0E27FC
/* 116B60 7F0E2030 A1900001 */   sb    $s0, 1($t4)
.L7F0E2034:
/* 116B64 7F0E2034 29C15800 */  slti  $at, $t6, 0x5800
/* 116B68 7F0E2038 1420000C */  bnez  $at, .L7F0E206C
/* 116B6C 7F0E203C 97B80292 */   lhu   $t8, 0x292($sp)
/* 116B70 7F0E2040 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 116B74 7F0E2044 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 116B78 7F0E2048 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 116B7C 7F0E204C 240A0001 */  li    $t2, 1
/* 116B80 7F0E2050 01A97821 */  addu  $t7, $t5, $t1
/* 116B84 7F0E2054 A1F00001 */  sb    $s0, 1($t7)
/* 116B88 7F0E2058 97B90292 */  lhu   $t9, 0x292($sp)
/* 116B8C 7F0E205C 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 116B90 7F0E2060 01195821 */  addu  $t3, $t0, $t9
/* 116B94 7F0E2064 100001E5 */  b     .L7F0E27FC
/* 116B98 7F0E2068 A16AA801 */   sb    $t2, -0x57ff($t3)
.L7F0E206C:
/* 116B9C 7F0E206C 270C0001 */  addiu $t4, $t8, 1
/* 116BA0 7F0E2070 29814000 */  slti  $at, $t4, 0x4000
/* 116BA4 7F0E2074 142001E1 */  bnez  $at, .L7F0E27FC
/* 116BA8 7F0E2078 3C0E8009 */   lui   $t6, %hi(ptr_spectrum_roms) 
/* 116BAC 7F0E207C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 116BB0 7F0E2080 24090001 */  li    $t1, 1
/* 116BB4 7F0E2084 01D86821 */  addu  $t5, $t6, $t8
/* 116BB8 7F0E2088 A1B00001 */  sb    $s0, 1($t5)
/* 116BBC 7F0E208C 97AF0292 */  lhu   $t7, 0x292($sp)
/* 116BC0 7F0E2090 3C0E8009 */  lui   $t6, %hi(ptr_300alloc) 
/* 116BC4 7F0E2094 8DCEE32C */  lw    $t6, %lo(ptr_300alloc)($t6)
/* 116BC8 7F0E2098 25E80001 */  addiu $t0, $t7, 1
/* 116BCC 7F0E209C 31191800 */  andi  $t9, $t0, 0x1800
/* 116BD0 7F0E20A0 001950C3 */  sra   $t2, $t9, 3
/* 116BD4 7F0E20A4 310B00FF */  andi  $t3, $t0, 0xff
/* 116BD8 7F0E20A8 014B6025 */  or    $t4, $t2, $t3
/* 116BDC 7F0E20AC 01CCC021 */  addu  $t8, $t6, $t4
/* 116BE0 7F0E20B0 100001D2 */  b     .L7F0E27FC
/* 116BE4 7F0E20B4 A3090000 */   sb    $t1, ($t8)
spectrum_op_F6:
/* 116BE8 7F0E20B8 8FAD028C */  lw    $t5, 0x28c($sp)
/* 116BEC 7F0E20BC 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 116BF0 7F0E20C0 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 116BF4 7F0E20C4 97A80298 */  lhu   $t0, 0x298($sp)
/* 116BF8 7F0E20C8 25AF0007 */  addiu $t7, $t5, 7
/* 116BFC 7F0E20CC AFAF028C */  sw    $t7, 0x28c($sp)
/* 116C00 7F0E20D0 03285021 */  addu  $t2, $t9, $t0
/* 116C04 7F0E20D4 914B0000 */  lbu   $t3, ($t2)
/* 116C08 7F0E20D8 3C198009 */  lui   $t9, %hi(ptr_pc_keyboard_table_alloc) 
/* 116C0C 7F0E20DC 8F39E334 */  lw    $t9, %lo(ptr_pc_keyboard_table_alloc)($t9)
/* 116C10 7F0E20E0 020B8025 */  or    $s0, $s0, $t3
/* 116C14 7F0E20E4 320E00FF */  andi  $t6, $s0, 0xff
/* 116C18 7F0E20E8 2DCC0001 */  sltiu $t4, $t6, 1
/* 116C1C 7F0E20EC AFAC0048 */  sw    $t4, 0x48($sp)
/* 116C20 7F0E20F0 01D94021 */  addu  $t0, $t6, $t9
/* 116C24 7F0E20F4 910A0000 */  lbu   $t2, ($t0)
/* 116C28 7F0E20F8 01C08025 */  move  $s0, $t6
/* 116C2C 7F0E20FC 31C900A8 */  andi  $t1, $t6, 0xa8
/* 116C30 7F0E2100 97AE0298 */  lhu   $t6, 0x298($sp)
/* 116C34 7F0E2104 000C6980 */  sll   $t5, $t4, 6
/* 116C38 7F0E2108 012D7825 */  or    $t7, $t1, $t5
/* 116C3C 7F0E210C 014F8825 */  or    $s1, $t2, $t7
/* 116C40 7F0E2110 322B00FF */  andi  $t3, $s1, 0xff
/* 116C44 7F0E2114 25CC0001 */  addiu $t4, $t6, 1
/* 116C48 7F0E2118 01608825 */  move  $s1, $t3
/* 116C4C 7F0E211C 100001B7 */  b     .L7F0E27FC
/* 116C50 7F0E2120 A7AC0298 */   sh    $t4, 0x298($sp)
spectrum_op_F7:
/* 116C54 7F0E2124 97AD0292 */  lhu   $t5, 0x292($sp)
/* 116C58 7F0E2128 8FB8028C */  lw    $t8, 0x28c($sp)
/* 116C5C 7F0E212C 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 116C60 7F0E2130 25B9FFFE */  addiu $t9, $t5, -2
/* 116C64 7F0E2134 3328FFFF */  andi  $t0, $t9, 0xffff
/* 116C68 7F0E2138 29015B00 */  slti  $at, $t0, 0x5b00
/* 116C6C 7F0E213C 2709000B */  addiu $t1, $t8, 0xb
/* 116C70 7F0E2140 AFA9028C */  sw    $t1, 0x28c($sp)
/* 116C74 7F0E2144 14200006 */  bnez  $at, .L7F0E2160
/* 116C78 7F0E2148 A7B90292 */   sh    $t9, 0x292($sp)
/* 116C7C 7F0E214C 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 116C80 7F0E2150 97AA0298 */  lhu   $t2, 0x298($sp)
/* 116C84 7F0E2154 01E85821 */  addu  $t3, $t7, $t0
/* 116C88 7F0E2158 10000023 */  b     .L7F0E21E8
/* 116C8C 7F0E215C A16A0000 */   sb    $t2, ($t3)
.L7F0E2160:
/* 116C90 7F0E2160 97AE0292 */  lhu   $t6, 0x292($sp)
/* 116C94 7F0E2164 97AA0292 */  lhu   $t2, 0x292($sp)
/* 116C98 7F0E2168 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 116C9C 7F0E216C 29C15800 */  slti  $at, $t6, 0x5800
/* 116CA0 7F0E2170 5420000D */  bnezl $at, .L7F0E21A8
/* 116CA4 7F0E2174 29414000 */   slti  $at, $t2, 0x4000
/* 116CA8 7F0E2178 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 116CAC 7F0E217C 97AC0298 */  lhu   $t4, 0x298($sp)
/* 116CB0 7F0E2180 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 116CB4 7F0E2184 030E4821 */  addu  $t1, $t8, $t6
/* 116CB8 7F0E2188 A12C0000 */  sb    $t4, ($t1)
/* 116CBC 7F0E218C 97AF0292 */  lhu   $t7, 0x292($sp)
/* 116CC0 7F0E2190 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 116CC4 7F0E2194 240D0001 */  li    $t5, 1
/* 116CC8 7F0E2198 032F4021 */  addu  $t0, $t9, $t7
/* 116CCC 7F0E219C 10000012 */  b     .L7F0E21E8
/* 116CD0 7F0E21A0 A10DA800 */   sb    $t5, -0x5800($t0)
/* 116CD4 7F0E21A4 29414000 */  slti  $at, $t2, 0x4000
.L7F0E21A8:
/* 116CD8 7F0E21A8 1420000F */  bnez  $at, .L7F0E21E8
/* 116CDC 7F0E21AC 3C188009 */   lui   $t8, %hi(ptr_spectrum_roms) 
/* 116CE0 7F0E21B0 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 116CE4 7F0E21B4 97AB0298 */  lhu   $t3, 0x298($sp)
/* 116CE8 7F0E21B8 240C0001 */  li    $t4, 1
/* 116CEC 7F0E21BC 030A7021 */  addu  $t6, $t8, $t2
/* 116CF0 7F0E21C0 A1CB0000 */  sb    $t3, ($t6)
/* 116CF4 7F0E21C4 97A90292 */  lhu   $t1, 0x292($sp)
/* 116CF8 7F0E21C8 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 116CFC 7F0E21CC 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 116D00 7F0E21D0 31391800 */  andi  $t9, $t1, 0x1800
/* 116D04 7F0E21D4 001978C3 */  sra   $t7, $t9, 3
/* 116D08 7F0E21D8 312D00FF */  andi  $t5, $t1, 0xff
/* 116D0C 7F0E21DC 01ED4025 */  or    $t0, $t7, $t5
/* 116D10 7F0E21E0 03085021 */  addu  $t2, $t8, $t0
/* 116D14 7F0E21E4 A14C0000 */  sb    $t4, ($t2)
.L7F0E21E8:
/* 116D18 7F0E21E8 97AB0292 */  lhu   $t3, 0x292($sp)
/* 116D1C 7F0E21EC 97B80292 */  lhu   $t8, 0x292($sp)
/* 116D20 7F0E21F0 97B90298 */  lhu   $t9, 0x298($sp)
/* 116D24 7F0E21F4 256E0001 */  addiu $t6, $t3, 1
/* 116D28 7F0E21F8 29C15B00 */  slti  $at, $t6, 0x5b00
/* 116D2C 7F0E21FC 14200007 */  bnez  $at, .L7F0E221C
/* 116D30 7F0E2200 27080001 */   addiu $t0, $t8, 1
/* 116D34 7F0E2204 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 116D38 7F0E2208 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 116D3C 7F0E220C 00194A03 */  sra   $t1, $t9, 8
/* 116D40 7F0E2210 01EB6821 */  addu  $t5, $t7, $t3
/* 116D44 7F0E2214 10000025 */  b     .L7F0E22AC
/* 116D48 7F0E2218 A1A90001 */   sb    $t1, 1($t5)
.L7F0E221C:
/* 116D4C 7F0E221C 29015800 */  slti  $at, $t0, 0x5800
/* 116D50 7F0E2220 1420000E */  bnez  $at, .L7F0E225C
/* 116D54 7F0E2224 97A80292 */   lhu   $t0, 0x292($sp)
/* 116D58 7F0E2228 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 116D5C 7F0E222C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 116D60 7F0E2230 97AC0298 */  lhu   $t4, 0x298($sp)
/* 116D64 7F0E2234 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 116D68 7F0E2238 01D8C821 */  addu  $t9, $t6, $t8
/* 116D6C 7F0E223C 000C5203 */  sra   $t2, $t4, 8
/* 116D70 7F0E2240 A32A0001 */  sb    $t2, 1($t9)
/* 116D74 7F0E2244 97A90292 */  lhu   $t1, 0x292($sp)
/* 116D78 7F0E2248 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 116D7C 7F0E224C 240F0001 */  li    $t7, 1
/* 116D80 7F0E2250 01696821 */  addu  $t5, $t3, $t1
/* 116D84 7F0E2254 10000015 */  b     .L7F0E22AC
/* 116D88 7F0E2258 A1AFA801 */   sb    $t7, -0x57ff($t5)
.L7F0E225C:
/* 116D8C 7F0E225C 250C0001 */  addiu $t4, $t0, 1
/* 116D90 7F0E2260 29814000 */  slti  $at, $t4, 0x4000
/* 116D94 7F0E2264 14200011 */  bnez  $at, .L7F0E22AC
/* 116D98 7F0E2268 97AE0298 */   lhu   $t6, 0x298($sp)
/* 116D9C 7F0E226C 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 116DA0 7F0E2270 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 116DA4 7F0E2274 000EC203 */  sra   $t8, $t6, 8
/* 116DA8 7F0E2278 240B0001 */  li    $t3, 1
/* 116DAC 7F0E227C 0148C821 */  addu  $t9, $t2, $t0
/* 116DB0 7F0E2280 A3380001 */  sb    $t8, 1($t9)
/* 116DB4 7F0E2284 97A90292 */  lhu   $t1, 0x292($sp)
/* 116DB8 7F0E2288 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 116DBC 7F0E228C 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 116DC0 7F0E2290 252F0001 */  addiu $t7, $t1, 1
/* 116DC4 7F0E2294 31ED1800 */  andi  $t5, $t7, 0x1800
/* 116DC8 7F0E2298 000D60C3 */  sra   $t4, $t5, 3
/* 116DCC 7F0E229C 31EE00FF */  andi  $t6, $t7, 0xff
/* 116DD0 7F0E22A0 018E5025 */  or    $t2, $t4, $t6
/* 116DD4 7F0E22A4 010AC021 */  addu  $t8, $t0, $t2
/* 116DD8 7F0E22A8 A30B0000 */  sb    $t3, ($t8)
.L7F0E22AC:
/* 116DDC 7F0E22AC 24190030 */  li    $t9, 48
/* 116DE0 7F0E22B0 10000152 */  b     .L7F0E27FC
/* 116DE4 7F0E22B4 A7B90298 */   sh    $t9, 0x298($sp)
spectrum_op_F8:
/* 116DE8 7F0E22B8 8FA9028C */  lw    $t1, 0x28c($sp)
/* 116DEC 7F0E22BC 322F0080 */  andi  $t7, $s1, 0x80
/* 116DF0 7F0E22C0 3C0A8009 */  lui   $t2, %hi(ptr_spectrum_roms) 
/* 116DF4 7F0E22C4 252D0005 */  addiu $t5, $t1, 5
/* 116DF8 7F0E22C8 11E0014C */  beqz  $t7, .L7F0E27FC
/* 116DFC 7F0E22CC AFAD028C */   sw    $t5, 0x28c($sp)
/* 116E00 7F0E22D0 97A80292 */  lhu   $t0, 0x292($sp)
/* 116E04 7F0E22D4 8D4AE328 */  lw    $t2, %lo(ptr_spectrum_roms)($t2)
/* 116E08 7F0E22D8 25AE0006 */  addiu $t6, $t5, 6
/* 116E0C 7F0E22DC AFAE028C */  sw    $t6, 0x28c($sp)
/* 116E10 7F0E22E0 0148C821 */  addu  $t9, $t2, $t0
/* 116E14 7F0E22E4 93290001 */  lbu   $t1, 1($t9)
/* 116E18 7F0E22E8 010A5821 */  addu  $t3, $t0, $t2
/* 116E1C 7F0E22EC 91780000 */  lbu   $t8, ($t3)
/* 116E20 7F0E22F0 00096A00 */  sll   $t5, $t1, 8
/* 116E24 7F0E22F4 250C0002 */  addiu $t4, $t0, 2
/* 116E28 7F0E22F8 030D7825 */  or    $t7, $t8, $t5
/* 116E2C 7F0E22FC A7AF0298 */  sh    $t7, 0x298($sp)
/* 116E30 7F0E2300 1000013E */  b     .L7F0E27FC
/* 116E34 7F0E2304 A7AC0292 */   sh    $t4, 0x292($sp)
spectrum_op_F9:
/* 116E38 7F0E2308 8FAE028C */  lw    $t6, 0x28c($sp)
/* 116E3C 7F0E230C 93AA0287 */  lbu   $t2, 0x287($sp)
/* 116E40 7F0E2310 93B80287 */  lbu   $t8, 0x287($sp)
/* 116E44 7F0E2314 25CB0006 */  addiu $t3, $t6, 6
/* 116E48 7F0E2318 15400005 */  bnez  $t2, .L7F0E2330
/* 116E4C 7F0E231C AFAB028C */   sw    $t3, 0x28c($sp)
/* 116E50 7F0E2320 0016CA00 */  sll   $t9, $s6, 8
/* 116E54 7F0E2324 03374825 */  or    $t1, $t9, $s7
/* 116E58 7F0E2328 10000134 */  b     .L7F0E27FC
/* 116E5C 7F0E232C A7A90292 */   sh    $t1, 0x292($sp)
.L7F0E2330:
/* 116E60 7F0E2330 24010001 */  li    $at, 1
/* 116E64 7F0E2334 17010004 */  bne   $t8, $at, .L7F0E2348
/* 116E68 7F0E2338 97AF0294 */   lhu   $t7, 0x294($sp)
/* 116E6C 7F0E233C 97AD0296 */  lhu   $t5, 0x296($sp)
/* 116E70 7F0E2340 10000002 */  b     .L7F0E234C
/* 116E74 7F0E2344 AFAD0048 */   sw    $t5, 0x48($sp)
.L7F0E2348:
/* 116E78 7F0E2348 AFAF0048 */  sw    $t7, 0x48($sp)
.L7F0E234C:
/* 116E7C 7F0E234C 8FA80048 */  lw    $t0, 0x48($sp)
/* 116E80 7F0E2350 1000012A */  b     .L7F0E27FC
/* 116E84 7F0E2354 A7A80292 */   sh    $t0, 0x292($sp)
spectrum_op_FA:
/* 116E88 7F0E2358 8FAC028C */  lw    $t4, 0x28c($sp)
/* 116E8C 7F0E235C 322B0080 */  andi  $t3, $s1, 0x80
/* 116E90 7F0E2360 97AA0298 */  lhu   $t2, 0x298($sp)
/* 116E94 7F0E2364 258E000A */  addiu $t6, $t4, 0xa
/* 116E98 7F0E2368 1160000B */  beqz  $t3, .L7F0E2398
/* 116E9C 7F0E236C AFAE028C */   sw    $t6, 0x28c($sp)
/* 116EA0 7F0E2370 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 116EA4 7F0E2374 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 116EA8 7F0E2378 032A6821 */  addu  $t5, $t9, $t2
/* 116EAC 7F0E237C 91AF0001 */  lbu   $t7, 1($t5)
/* 116EB0 7F0E2380 01594821 */  addu  $t1, $t2, $t9
/* 116EB4 7F0E2384 91380000 */  lbu   $t8, ($t1)
/* 116EB8 7F0E2388 000F4200 */  sll   $t0, $t7, 8
/* 116EBC 7F0E238C 03086025 */  or    $t4, $t8, $t0
/* 116EC0 7F0E2390 1000011A */  b     .L7F0E27FC
/* 116EC4 7F0E2394 A7AC0298 */   sh    $t4, 0x298($sp)
.L7F0E2398:
/* 116EC8 7F0E2398 97AE0298 */  lhu   $t6, 0x298($sp)
/* 116ECC 7F0E239C 25CB0002 */  addiu $t3, $t6, 2
/* 116ED0 7F0E23A0 10000116 */  b     .L7F0E27FC
/* 116ED4 7F0E23A4 A7AB0298 */   sh    $t3, 0x298($sp)
spectrum_op_FB:
/* 116ED8 7F0E23A8 8FA9028C */  lw    $t1, 0x28c($sp)
/* 116EDC 7F0E23AC 240A0001 */  li    $t2, 1
/* 116EE0 7F0E23B0 240D0001 */  li    $t5, 1
/* 116EE4 7F0E23B4 25390004 */  addiu $t9, $t1, 4
/* 116EE8 7F0E23B8 AFB9028C */  sw    $t9, 0x28c($sp)
/* 116EEC 7F0E23BC A3AD029D */  sb    $t5, 0x29d($sp)
/* 116EF0 7F0E23C0 A3AA029C */  sb    $t2, 0x29c($sp)
/* 116EF4 7F0E23C4 1000010D */  b     .L7F0E27FC
/* 116EF8 7F0E23C8 A3A00285 */   sb    $zero, 0x285($sp)
spectrum_op_FC:
/* 116EFC 7F0E23CC 8FAF028C */  lw    $t7, 0x28c($sp)
/* 116F00 7F0E23D0 32280080 */  andi  $t0, $s1, 0x80
/* 116F04 7F0E23D4 25F8000A */  addiu $t8, $t7, 0xa
/* 116F08 7F0E23D8 11000072 */  beqz  $t0, .L7F0E25A4
/* 116F0C 7F0E23DC AFB8028C */   sw    $t8, 0x28c($sp)
/* 116F10 7F0E23E0 97AB0292 */  lhu   $t3, 0x292($sp)
/* 116F14 7F0E23E4 270E0007 */  addiu $t6, $t8, 7
/* 116F18 7F0E23E8 AFAE028C */  sw    $t6, 0x28c($sp)
/* 116F1C 7F0E23EC 2569FFFE */  addiu $t1, $t3, -2
/* 116F20 7F0E23F0 3139FFFF */  andi  $t9, $t1, 0xffff
/* 116F24 7F0E23F4 2B215B00 */  slti  $at, $t9, 0x5b00
/* 116F28 7F0E23F8 14200008 */  bnez  $at, .L7F0E241C
/* 116F2C 7F0E23FC A7A90292 */   sh    $t1, 0x292($sp)
/* 116F30 7F0E2400 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 116F34 7F0E2404 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 116F38 7F0E2408 97AA0298 */  lhu   $t2, 0x298($sp)
/* 116F3C 7F0E240C 01F9C021 */  addu  $t8, $t7, $t9
/* 116F40 7F0E2410 254D0002 */  addiu $t5, $t2, 2
/* 116F44 7F0E2414 10000024 */  b     .L7F0E24A8
/* 116F48 7F0E2418 A30D0000 */   sb    $t5, ($t8)
.L7F0E241C:
/* 116F4C 7F0E241C 97A80292 */  lhu   $t0, 0x292($sp)
/* 116F50 7F0E2420 97B80292 */  lhu   $t8, 0x292($sp)
/* 116F54 7F0E2424 97AC0298 */  lhu   $t4, 0x298($sp)
/* 116F58 7F0E2428 29015800 */  slti  $at, $t0, 0x5800
/* 116F5C 7F0E242C 1420000C */  bnez  $at, .L7F0E2460
/* 116F60 7F0E2430 3C0B8009 */   lui   $t3, %hi(ptr_spectrum_roms) 
/* 116F64 7F0E2434 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 116F68 7F0E2438 258E0002 */  addiu $t6, $t4, 2
/* 116F6C 7F0E243C 3C0F8009 */  lui   $t7, %hi(ptr_300alloc) 
/* 116F70 7F0E2440 01684821 */  addu  $t1, $t3, $t0
/* 116F74 7F0E2444 A12E0000 */  sb    $t6, ($t1)
/* 116F78 7F0E2448 97B90292 */  lhu   $t9, 0x292($sp)
/* 116F7C 7F0E244C 8DEFE32C */  lw    $t7, %lo(ptr_300alloc)($t7)
/* 116F80 7F0E2450 240A0001 */  li    $t2, 1
/* 116F84 7F0E2454 01F96821 */  addu  $t5, $t7, $t9
/* 116F88 7F0E2458 10000013 */  b     .L7F0E24A8
/* 116F8C 7F0E245C A1AAA800 */   sb    $t2, -0x5800($t5)
.L7F0E2460:
/* 116F90 7F0E2460 2B014000 */  slti  $at, $t8, 0x4000
/* 116F94 7F0E2464 14200010 */  bnez  $at, .L7F0E24A8
/* 116F98 7F0E2468 97AC0298 */   lhu   $t4, 0x298($sp)
/* 116F9C 7F0E246C 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 116FA0 7F0E2470 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 116FA4 7F0E2474 258B0002 */  addiu $t3, $t4, 2
/* 116FA8 7F0E2478 24090001 */  li    $t1, 1
/* 116FAC 7F0E247C 01187021 */  addu  $t6, $t0, $t8
/* 116FB0 7F0E2480 A1CB0000 */  sb    $t3, ($t6)
/* 116FB4 7F0E2484 97AF0292 */  lhu   $t7, 0x292($sp)
/* 116FB8 7F0E2488 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 116FBC 7F0E248C 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 116FC0 7F0E2490 31F91800 */  andi  $t9, $t7, 0x1800
/* 116FC4 7F0E2494 001950C3 */  sra   $t2, $t9, 3
/* 116FC8 7F0E2498 31ED00FF */  andi  $t5, $t7, 0xff
/* 116FCC 7F0E249C 014D6025 */  or    $t4, $t2, $t5
/* 116FD0 7F0E24A0 010CC021 */  addu  $t8, $t0, $t4
/* 116FD4 7F0E24A4 A3090000 */  sb    $t1, ($t8)
.L7F0E24A8:
/* 116FD8 7F0E24A8 97AB0292 */  lhu   $t3, 0x292($sp)
/* 116FDC 7F0E24AC 97AC0292 */  lhu   $t4, 0x292($sp)
/* 116FE0 7F0E24B0 97B90298 */  lhu   $t9, 0x298($sp)
/* 116FE4 7F0E24B4 256E0001 */  addiu $t6, $t3, 1
/* 116FE8 7F0E24B8 29C15B00 */  slti  $at, $t6, 0x5b00
/* 116FEC 7F0E24BC 14200008 */  bnez  $at, .L7F0E24E0
/* 116FF0 7F0E24C0 25890001 */   addiu $t1, $t4, 1
/* 116FF4 7F0E24C4 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 116FF8 7F0E24C8 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 116FFC 7F0E24CC 272F0002 */  addiu $t7, $t9, 2
/* 117000 7F0E24D0 000F5203 */  sra   $t2, $t7, 8
/* 117004 7F0E24D4 01AB4021 */  addu  $t0, $t5, $t3
/* 117008 7F0E24D8 10000027 */  b     .L7F0E2578
/* 11700C 7F0E24DC A10A0001 */   sb    $t2, 1($t0)
.L7F0E24E0:
/* 117010 7F0E24E0 29215800 */  slti  $at, $t1, 0x5800
/* 117014 7F0E24E4 1420000F */  bnez  $at, .L7F0E2524
/* 117018 7F0E24E8 97B80292 */   lhu   $t8, 0x292($sp)
/* 11701C 7F0E24EC 97B80298 */  lhu   $t8, 0x298($sp)
/* 117020 7F0E24F0 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 117024 7F0E24F4 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 117028 7F0E24F8 270E0002 */  addiu $t6, $t8, 2
/* 11702C 7F0E24FC 000ECA03 */  sra   $t9, $t6, 8
/* 117030 7F0E2500 01EC6821 */  addu  $t5, $t7, $t4
/* 117034 7F0E2504 A1B90001 */  sb    $t9, 1($t5)
/* 117038 7F0E2508 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 11703C 7F0E250C 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 117040 7F0E2510 97A80292 */  lhu   $t0, 0x292($sp)
/* 117044 7F0E2514 240B0001 */  li    $t3, 1
/* 117048 7F0E2518 01484821 */  addu  $t1, $t2, $t0
/* 11704C 7F0E251C 10000016 */  b     .L7F0E2578
/* 117050 7F0E2520 A12BA801 */   sb    $t3, -0x57ff($t1)
.L7F0E2524:
/* 117054 7F0E2524 270E0001 */  addiu $t6, $t8, 1
/* 117058 7F0E2528 29C14000 */  slti  $at, $t6, 0x4000
/* 11705C 7F0E252C 14200012 */  bnez  $at, .L7F0E2578
/* 117060 7F0E2530 97AF0298 */   lhu   $t7, 0x298($sp)
/* 117064 7F0E2534 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 117068 7F0E2538 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 11706C 7F0E253C 25EC0002 */  addiu $t4, $t7, 2
/* 117070 7F0E2540 000CCA03 */  sra   $t9, $t4, 8
/* 117074 7F0E2544 01B85021 */  addu  $t2, $t5, $t8
/* 117078 7F0E2548 A1590001 */  sb    $t9, 1($t2)
/* 11707C 7F0E254C 97AB0292 */  lhu   $t3, 0x292($sp)
/* 117080 7F0E2550 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 117084 7F0E2554 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 117088 7F0E2558 25690001 */  addiu $t1, $t3, 1
/* 11708C 7F0E255C 312E1800 */  andi  $t6, $t1, 0x1800
/* 117090 7F0E2560 000E78C3 */  sra   $t7, $t6, 3
/* 117094 7F0E2564 312C00FF */  andi  $t4, $t1, 0xff
/* 117098 7F0E2568 01EC6825 */  or    $t5, $t7, $t4
/* 11709C 7F0E256C 24080001 */  li    $t0, 1
/* 1170A0 7F0E2570 030DC821 */  addu  $t9, $t8, $t5
/* 1170A4 7F0E2574 A3280000 */  sb    $t0, ($t9)
.L7F0E2578:
/* 1170A8 7F0E2578 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 1170AC 7F0E257C 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 1170B0 7F0E2580 97AA0298 */  lhu   $t2, 0x298($sp)
/* 1170B4 7F0E2584 016A7821 */  addu  $t7, $t3, $t2
/* 1170B8 7F0E2588 91EC0001 */  lbu   $t4, 1($t7)
/* 1170BC 7F0E258C 014B7021 */  addu  $t6, $t2, $t3
/* 1170C0 7F0E2590 91C90000 */  lbu   $t1, ($t6)
/* 1170C4 7F0E2594 000CC200 */  sll   $t8, $t4, 8
/* 1170C8 7F0E2598 01386825 */  or    $t5, $t1, $t8
/* 1170CC 7F0E259C 10000097 */  b     .L7F0E27FC
/* 1170D0 7F0E25A0 A7AD0298 */   sh    $t5, 0x298($sp)
.L7F0E25A4:
/* 1170D4 7F0E25A4 97A80298 */  lhu   $t0, 0x298($sp)
/* 1170D8 7F0E25A8 25190002 */  addiu $t9, $t0, 2
/* 1170DC 7F0E25AC 10000093 */  b     .L7F0E27FC
/* 1170E0 7F0E25B0 A7B90298 */   sh    $t9, 0x298($sp)
spectrum_op_FD:
/* 1170E4 7F0E25B4 8FAE028C */  lw    $t6, 0x28c($sp)
/* 1170E8 7F0E25B8 240A0002 */  li    $t2, 2
/* 1170EC 7F0E25BC A3AA0286 */  sb    $t2, 0x286($sp)
/* 1170F0 7F0E25C0 25CB0004 */  addiu $t3, $t6, 4
/* 1170F4 7F0E25C4 AFAB028C */  sw    $t3, 0x28c($sp)
/* 1170F8 7F0E25C8 1000008C */  b     .L7F0E27FC
/* 1170FC 7F0E25CC A3A00285 */   sb    $zero, 0x285($sp)
spectrum_op_FE:
/* 117100 7F0E25D0 8FAF028C */  lw    $t7, 0x28c($sp)
/* 117104 7F0E25D4 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 117108 7F0E25D8 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 11710C 7F0E25DC 97A90298 */  lhu   $t1, 0x298($sp)
/* 117110 7F0E25E0 25EC0007 */  addiu $t4, $t7, 7
/* 117114 7F0E25E4 AFAC028C */  sw    $t4, 0x28c($sp)
/* 117118 7F0E25E8 01386821 */  addu  $t5, $t1, $t8
/* 11711C 7F0E25EC 91A80000 */  lbu   $t0, ($t5)
/* 117120 7F0E25F0 0208C823 */  subu  $t9, $s0, $t0
/* 117124 7F0E25F4 332E01FF */  andi  $t6, $t9, 0x1ff
/* 117128 7F0E25F8 31CBFFFF */  andi  $t3, $t6, 0xffff
/* 11712C 7F0E25FC 2D6A0001 */  sltiu $t2, $t3, 1
/* 117130 7F0E2600 320B000F */  andi  $t3, $s0, 0xf
/* 117134 7F0E2604 3119000F */  andi  $t9, $t0, 0xf
/* 117138 7F0E2608 0179782A */  slt   $t7, $t3, $t9
/* 11713C 7F0E260C 31CC00A8 */  andi  $t4, $t6, 0xa8
/* 117140 7F0E2610 000EC203 */  sra   $t8, $t6, 8
/* 117144 7F0E2614 01986825 */  or    $t5, $t4, $t8
/* 117148 7F0E2618 000F4900 */  sll   $t1, $t7, 4
/* 11714C 7F0E261C 01C0C825 */  move  $t9, $t6
/* 117150 7F0E2620 0208C026 */  xor   $t8, $s0, $t0
/* 117154 7F0E2624 330B0080 */  andi  $t3, $t8, 0x80
/* 117158 7F0E2628 03307826 */  xor   $t7, $t9, $s0
/* 11715C 7F0E262C 01A96025 */  or    $t4, $t5, $t1
/* 117160 7F0E2630 016F6824 */  and   $t5, $t3, $t7
/* 117164 7F0E2634 000D4943 */  sra   $t1, $t5, 5
/* 117168 7F0E2638 A3A80053 */  sb    $t0, 0x53($sp)
/* 11716C 7F0E263C 97AB0298 */  lhu   $t3, 0x298($sp)
/* 117170 7F0E2640 01894025 */  or    $t0, $t4, $t1
/* 117174 7F0E2644 A7AE0054 */  sh    $t6, 0x54($sp)
/* 117178 7F0E2648 000A7180 */  sll   $t6, $t2, 6
/* 11717C 7F0E264C 35180002 */  ori   $t8, $t0, 2
/* 117180 7F0E2650 030E8825 */  or    $s1, $t8, $t6
/* 117184 7F0E2654 323900FF */  andi  $t9, $s1, 0xff
/* 117188 7F0E2658 256F0001 */  addiu $t7, $t3, 1
/* 11718C 7F0E265C 03208825 */  move  $s1, $t9
/* 117190 7F0E2660 AFAA0048 */  sw    $t2, 0x48($sp)
/* 117194 7F0E2664 10000065 */  b     .L7F0E27FC
/* 117198 7F0E2668 A7AF0298 */   sh    $t7, 0x298($sp)
spectrum_op_FF:
/* 11719C 7F0E266C 97A90292 */  lhu   $t1, 0x292($sp)
/* 1171A0 7F0E2670 8FAD028C */  lw    $t5, 0x28c($sp)
/* 1171A4 7F0E2674 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 1171A8 7F0E2678 2528FFFE */  addiu $t0, $t1, -2
/* 1171AC 7F0E267C 310AFFFF */  andi  $t2, $t0, 0xffff
/* 1171B0 7F0E2680 29415B00 */  slti  $at, $t2, 0x5b00
/* 1171B4 7F0E2684 25AC000B */  addiu $t4, $t5, 0xb
/* 1171B8 7F0E2688 AFAC028C */  sw    $t4, 0x28c($sp)
/* 1171BC 7F0E268C 14200006 */  bnez  $at, .L7F0E26A8
/* 1171C0 7F0E2690 A7A80292 */   sh    $t0, 0x292($sp)
/* 1171C4 7F0E2694 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 1171C8 7F0E2698 97B80298 */  lhu   $t8, 0x298($sp)
/* 1171CC 7F0E269C 01CAC821 */  addu  $t9, $t6, $t2
/* 1171D0 7F0E26A0 10000023 */  b     .L7F0E2730
/* 1171D4 7F0E26A4 A3380000 */   sb    $t8, ($t9)
.L7F0E26A8:
/* 1171D8 7F0E26A8 97AB0292 */  lhu   $t3, 0x292($sp)
/* 1171DC 7F0E26AC 97B80292 */  lhu   $t8, 0x292($sp)
/* 1171E0 7F0E26B0 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 1171E4 7F0E26B4 29615800 */  slti  $at, $t3, 0x5800
/* 1171E8 7F0E26B8 5420000D */  bnezl $at, .L7F0E26F0
/* 1171EC 7F0E26BC 2B014000 */   slti  $at, $t8, 0x4000
/* 1171F0 7F0E26C0 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 1171F4 7F0E26C4 97AF0298 */  lhu   $t7, 0x298($sp)
/* 1171F8 7F0E26C8 3C088009 */  lui   $t0, %hi(ptr_300alloc) 
/* 1171FC 7F0E26CC 01AB6021 */  addu  $t4, $t5, $t3
/* 117200 7F0E26D0 A18F0000 */  sb    $t7, ($t4)
/* 117204 7F0E26D4 97AE0292 */  lhu   $t6, 0x292($sp)
/* 117208 7F0E26D8 8D08E32C */  lw    $t0, %lo(ptr_300alloc)($t0)
/* 11720C 7F0E26DC 24090001 */  li    $t1, 1
/* 117210 7F0E26E0 010E5021 */  addu  $t2, $t0, $t6
/* 117214 7F0E26E4 10000012 */  b     .L7F0E2730
/* 117218 7F0E26E8 A149A800 */   sb    $t1, -0x5800($t2)
/* 11721C 7F0E26EC 2B014000 */  slti  $at, $t8, 0x4000
.L7F0E26F0:
/* 117220 7F0E26F0 1420000F */  bnez  $at, .L7F0E2730
/* 117224 7F0E26F4 3C0D8009 */   lui   $t5, %hi(ptr_spectrum_roms) 
/* 117228 7F0E26F8 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 11722C 7F0E26FC 97B90298 */  lhu   $t9, 0x298($sp)
/* 117230 7F0E2700 240F0001 */  li    $t7, 1
/* 117234 7F0E2704 01B85821 */  addu  $t3, $t5, $t8
/* 117238 7F0E2708 A1790000 */  sb    $t9, ($t3)
/* 11723C 7F0E270C 97AC0292 */  lhu   $t4, 0x292($sp)
/* 117240 7F0E2710 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 117244 7F0E2714 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 117248 7F0E2718 31881800 */  andi  $t0, $t4, 0x1800
/* 11724C 7F0E271C 000870C3 */  sra   $t6, $t0, 3
/* 117250 7F0E2720 318900FF */  andi  $t1, $t4, 0xff
/* 117254 7F0E2724 01C95025 */  or    $t2, $t6, $t1
/* 117258 7F0E2728 01AAC021 */  addu  $t8, $t5, $t2
/* 11725C 7F0E272C A30F0000 */  sb    $t7, ($t8)
.L7F0E2730:
/* 117260 7F0E2730 97B90292 */  lhu   $t9, 0x292($sp)
/* 117264 7F0E2734 97AD0292 */  lhu   $t5, 0x292($sp)
/* 117268 7F0E2738 97A80298 */  lhu   $t0, 0x298($sp)
/* 11726C 7F0E273C 272B0001 */  addiu $t3, $t9, 1
/* 117270 7F0E2740 29615B00 */  slti  $at, $t3, 0x5b00
/* 117274 7F0E2744 14200007 */  bnez  $at, .L7F0E2764
/* 117278 7F0E2748 25AA0001 */   addiu $t2, $t5, 1
/* 11727C 7F0E274C 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 117280 7F0E2750 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 117284 7F0E2754 00086203 */  sra   $t4, $t0, 8
/* 117288 7F0E2758 01D94821 */  addu  $t1, $t6, $t9
/* 11728C 7F0E275C 10000025 */  b     .L7F0E27F4
/* 117290 7F0E2760 A12C0001 */   sb    $t4, 1($t1)
.L7F0E2764:
/* 117294 7F0E2764 29415800 */  slti  $at, $t2, 0x5800
/* 117298 7F0E2768 1420000E */  bnez  $at, .L7F0E27A4
/* 11729C 7F0E276C 97AA0292 */   lhu   $t2, 0x292($sp)
/* 1172A0 7F0E2770 3C0B8009 */  lui   $t3, %hi(ptr_spectrum_roms) 
/* 1172A4 7F0E2774 8D6BE328 */  lw    $t3, %lo(ptr_spectrum_roms)($t3)
/* 1172A8 7F0E2778 97AF0298 */  lhu   $t7, 0x298($sp)
/* 1172AC 7F0E277C 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 1172B0 7F0E2780 016D4021 */  addu  $t0, $t3, $t5
/* 1172B4 7F0E2784 000FC203 */  sra   $t8, $t7, 8
/* 1172B8 7F0E2788 A1180001 */  sb    $t8, 1($t0)
/* 1172BC 7F0E278C 97AC0292 */  lhu   $t4, 0x292($sp)
/* 1172C0 7F0E2790 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 1172C4 7F0E2794 240E0001 */  li    $t6, 1
/* 1172C8 7F0E2798 032C4821 */  addu  $t1, $t9, $t4
/* 1172CC 7F0E279C 10000015 */  b     .L7F0E27F4
/* 1172D0 7F0E27A0 A12EA801 */   sb    $t6, -0x57ff($t1)
.L7F0E27A4:
/* 1172D4 7F0E27A4 254F0001 */  addiu $t7, $t2, 1
/* 1172D8 7F0E27A8 29E14000 */  slti  $at, $t7, 0x4000
/* 1172DC 7F0E27AC 14200011 */  bnez  $at, .L7F0E27F4
/* 1172E0 7F0E27B0 97AB0298 */   lhu   $t3, 0x298($sp)
/* 1172E4 7F0E27B4 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 1172E8 7F0E27B8 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 1172EC 7F0E27BC 000B6A03 */  sra   $t5, $t3, 8
/* 1172F0 7F0E27C0 24190001 */  li    $t9, 1
/* 1172F4 7F0E27C4 030A4021 */  addu  $t0, $t8, $t2
/* 1172F8 7F0E27C8 A10D0001 */  sb    $t5, 1($t0)
/* 1172FC 7F0E27CC 97AC0292 */  lhu   $t4, 0x292($sp)
/* 117300 7F0E27D0 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 117304 7F0E27D4 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 117308 7F0E27D8 258E0001 */  addiu $t6, $t4, 1
/* 11730C 7F0E27DC 31C91800 */  andi  $t1, $t6, 0x1800
/* 117310 7F0E27E0 000978C3 */  sra   $t7, $t1, 3
/* 117314 7F0E27E4 31CB00FF */  andi  $t3, $t6, 0xff
/* 117318 7F0E27E8 01EBC025 */  or    $t8, $t7, $t3
/* 11731C 7F0E27EC 01586821 */  addu  $t5, $t2, $t8
/* 117320 7F0E27F0 A1B90000 */  sb    $t9, ($t5)
.L7F0E27F4:
/* 117324 7F0E27F4 24080038 */  li    $t0, 56
/* 117328 7F0E27F8 A7A80298 */  sh    $t0, 0x298($sp)
.L7F0E27FC:
/* 11732C 7F0E27FC 8FAC028C */  lw    $t4, 0x28c($sp)
/* 117330 7F0E2800 8FA90280 */  lw    $t1, 0x280($sp)
/* 117334 7F0E2804 0189082B */  sltu  $at, $t4, $t1
/* 117338 7F0E2808 1420C473 */  bnez  $at, .L7F0D39D8
/* 11733C 7F0E280C 00000000 */   nop   
/* 117340 7F0E2810 93AE0285 */  lbu   $t6, 0x285($sp)
/* 117344 7F0E2814 11C0C470 */  beqz  $t6, .L7F0D39D8
/* 117348 7F0E2818 00000000 */   nop   
.L7F0E281C:
/* 11734C 7F0E281C 8FAF028C */  lw    $t7, 0x28c($sp)
/* 117350 7F0E2820 8FAB0280 */  lw    $t3, 0x280($sp)
/* 117354 7F0E2824 93AA0285 */  lbu   $t2, 0x285($sp)
/* 117358 7F0E2828 01EB082B */  sltu  $at, $t7, $t3
/* 11735C 7F0E282C 142000F6 */  bnez  $at, .L7F0E2C08
/* 117360 7F0E2830 00000000 */   nop   
/* 117364 7F0E2834 114000F4 */  beqz  $t2, .L7F0E2C08
/* 117368 7F0E2838 00000000 */   nop   
/* 11736C 7F0E283C 93B9029D */  lbu   $t9, 0x29d($sp)
/* 117370 7F0E2840 01EBC023 */  subu  $t8, $t7, $t3
/* 117374 7F0E2844 AFB8028C */  sw    $t8, 0x28c($sp)
/* 117378 7F0E2848 132000EF */  beqz  $t9, .L7F0E2C08
/* 11737C 7F0E284C 97AD0298 */   lhu   $t5, 0x298($sp)
/* 117380 7F0E2850 3C088009 */  lui   $t0, %hi(ptr_spectrum_roms) 
/* 117384 7F0E2854 8D08E328 */  lw    $t0, %lo(ptr_spectrum_roms)($t0)
/* 117388 7F0E2858 24010076 */  li    $at, 118
/* 11738C 7F0E285C 25AE0001 */  addiu $t6, $t5, 1
/* 117390 7F0E2860 01A86021 */  addu  $t4, $t5, $t0
/* 117394 7F0E2864 91890000 */  lbu   $t1, ($t4)
/* 117398 7F0E2868 55210003 */  bnel  $t1, $at, .L7F0E2878
/* 11739C 7F0E286C 8FAA028C */   lw    $t2, 0x28c($sp)
/* 1173A0 7F0E2870 A7AE0298 */  sh    $t6, 0x298($sp)
/* 1173A4 7F0E2874 8FAA028C */  lw    $t2, 0x28c($sp)
.L7F0E2878:
/* 1173A8 7F0E2878 93AB029B */  lbu   $t3, 0x29b($sp)
/* 1173AC 7F0E287C A3A0029C */  sb    $zero, 0x29c($sp)
/* 1173B0 7F0E2880 254F0005 */  addiu $t7, $t2, 5
/* 1173B4 7F0E2884 A3A0029D */  sb    $zero, 0x29d($sp)
/* 1173B8 7F0E2888 AFAF028C */  sw    $t7, 0x28c($sp)
/* 1173BC 7F0E288C 1160000A */  beqz  $t3, .L7F0E28B8
/* 1173C0 7F0E2890 AFAB0048 */   sw    $t3, 0x48($sp)
/* 1173C4 7F0E2894 24010001 */  li    $at, 1
/* 1173C8 7F0E2898 11610007 */  beq   $t3, $at, .L7F0E28B8
/* 1173CC 7F0E289C 24010002 */   li    $at, 2
/* 1173D0 7F0E28A0 11610005 */  beq   $t3, $at, .L7F0E28B8
/* 1173D4 7F0E28A4 24010003 */   li    $at, 3
/* 1173D8 7F0E28A8 11610068 */  beq   $t3, $at, .L7F0E2A4C
/* 1173DC 7F0E28AC 8FB9028C */   lw    $t9, 0x28c($sp)
/* 1173E0 7F0E28B0 100000D5 */  b     .L7F0E2C08
/* 1173E4 7F0E28B4 00000000 */   nop   
.L7F0E28B8:
/* 1173E8 7F0E28B8 97A80292 */  lhu   $t0, 0x292($sp)
/* 1173EC 7F0E28BC 8FB8028C */  lw    $t8, 0x28c($sp)
/* 1173F0 7F0E28C0 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 1173F4 7F0E28C4 250CFFFE */  addiu $t4, $t0, -2
/* 1173F8 7F0E28C8 3189FFFF */  andi  $t1, $t4, 0xffff
/* 1173FC 7F0E28CC 29215B00 */  slti  $at, $t1, 0x5b00
/* 117400 7F0E28D0 27190008 */  addiu $t9, $t8, 8
/* 117404 7F0E28D4 AFB9028C */  sw    $t9, 0x28c($sp)
/* 117408 7F0E28D8 14200006 */  bnez  $at, .L7F0E28F4
/* 11740C 7F0E28DC A7AC0292 */   sh    $t4, 0x292($sp)
/* 117410 7F0E28E0 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 117414 7F0E28E4 97AD0298 */  lhu   $t5, 0x298($sp)
/* 117418 7F0E28E8 01C95021 */  addu  $t2, $t6, $t1
/* 11741C 7F0E28EC 10000023 */  b     .L7F0E297C
/* 117420 7F0E28F0 A14D0000 */   sb    $t5, ($t2)
.L7F0E28F4:
/* 117424 7F0E28F4 97AF0292 */  lhu   $t7, 0x292($sp)
/* 117428 7F0E28F8 97AD0292 */  lhu   $t5, 0x292($sp)
/* 11742C 7F0E28FC 3C188009 */  lui   $t8, %hi(ptr_spectrum_roms) 
/* 117430 7F0E2900 29E15800 */  slti  $at, $t7, 0x5800
/* 117434 7F0E2904 5420000D */  bnezl $at, .L7F0E293C
/* 117438 7F0E2908 29A14000 */   slti  $at, $t5, 0x4000
/* 11743C 7F0E290C 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 117440 7F0E2910 97AB0298 */  lhu   $t3, 0x298($sp)
/* 117444 7F0E2914 3C0C8009 */  lui   $t4, %hi(ptr_300alloc) 
/* 117448 7F0E2918 030FC821 */  addu  $t9, $t8, $t7
/* 11744C 7F0E291C A32B0000 */  sb    $t3, ($t9)
/* 117450 7F0E2920 97AE0292 */  lhu   $t6, 0x292($sp)
/* 117454 7F0E2924 8D8CE32C */  lw    $t4, %lo(ptr_300alloc)($t4)
/* 117458 7F0E2928 24080001 */  li    $t0, 1
/* 11745C 7F0E292C 018E4821 */  addu  $t1, $t4, $t6
/* 117460 7F0E2930 10000012 */  b     .L7F0E297C
/* 117464 7F0E2934 A128A800 */   sb    $t0, -0x5800($t1)
/* 117468 7F0E2938 29A14000 */  slti  $at, $t5, 0x4000
.L7F0E293C:
/* 11746C 7F0E293C 1420000F */  bnez  $at, .L7F0E297C
/* 117470 7F0E2940 3C188009 */   lui   $t8, %hi(ptr_spectrum_roms) 
/* 117474 7F0E2944 8F18E328 */  lw    $t8, %lo(ptr_spectrum_roms)($t8)
/* 117478 7F0E2948 97AA0298 */  lhu   $t2, 0x298($sp)
/* 11747C 7F0E294C 240B0001 */  li    $t3, 1
/* 117480 7F0E2950 030D7821 */  addu  $t7, $t8, $t5
/* 117484 7F0E2954 A1EA0000 */  sb    $t2, ($t7)
/* 117488 7F0E2958 97B90292 */  lhu   $t9, 0x292($sp)
/* 11748C 7F0E295C 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 117490 7F0E2960 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 117494 7F0E2964 332C1800 */  andi  $t4, $t9, 0x1800
/* 117498 7F0E2968 000C70C3 */  sra   $t6, $t4, 3
/* 11749C 7F0E296C 332800FF */  andi  $t0, $t9, 0xff
/* 1174A0 7F0E2970 01C84825 */  or    $t1, $t6, $t0
/* 1174A4 7F0E2974 03096821 */  addu  $t5, $t8, $t1
/* 1174A8 7F0E2978 A1AB0000 */  sb    $t3, ($t5)
.L7F0E297C:
/* 1174AC 7F0E297C 97AA0292 */  lhu   $t2, 0x292($sp)
/* 1174B0 7F0E2980 97B80292 */  lhu   $t8, 0x292($sp)
/* 1174B4 7F0E2984 97AC0298 */  lhu   $t4, 0x298($sp)
/* 1174B8 7F0E2988 254F0001 */  addiu $t7, $t2, 1
/* 1174BC 7F0E298C 29E15B00 */  slti  $at, $t7, 0x5b00
/* 1174C0 7F0E2990 14200007 */  bnez  $at, .L7F0E29B0
/* 1174C4 7F0E2994 27090001 */   addiu $t1, $t8, 1
/* 1174C8 7F0E2998 3C0E8009 */  lui   $t6, %hi(ptr_spectrum_roms) 
/* 1174CC 7F0E299C 8DCEE328 */  lw    $t6, %lo(ptr_spectrum_roms)($t6)
/* 1174D0 7F0E29A0 000CCA03 */  sra   $t9, $t4, 8
/* 1174D4 7F0E29A4 01CA4021 */  addu  $t0, $t6, $t2
/* 1174D8 7F0E29A8 10000025 */  b     .L7F0E2A40
/* 1174DC 7F0E29AC A1190001 */   sb    $t9, 1($t0)
.L7F0E29B0:
/* 1174E0 7F0E29B0 29215800 */  slti  $at, $t1, 0x5800
/* 1174E4 7F0E29B4 1420000E */  bnez  $at, .L7F0E29F0
/* 1174E8 7F0E29B8 97A90292 */   lhu   $t1, 0x292($sp)
/* 1174EC 7F0E29BC 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 1174F0 7F0E29C0 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 1174F4 7F0E29C4 97AB0298 */  lhu   $t3, 0x298($sp)
/* 1174F8 7F0E29C8 3C0A8009 */  lui   $t2, %hi(ptr_300alloc) 
/* 1174FC 7F0E29CC 01F86021 */  addu  $t4, $t7, $t8
/* 117500 7F0E29D0 000B6A03 */  sra   $t5, $t3, 8
/* 117504 7F0E29D4 A18D0001 */  sb    $t5, 1($t4)
/* 117508 7F0E29D8 97B90292 */  lhu   $t9, 0x292($sp)
/* 11750C 7F0E29DC 8D4AE32C */  lw    $t2, %lo(ptr_300alloc)($t2)
/* 117510 7F0E29E0 240E0001 */  li    $t6, 1
/* 117514 7F0E29E4 01594021 */  addu  $t0, $t2, $t9
/* 117518 7F0E29E8 10000015 */  b     .L7F0E2A40
/* 11751C 7F0E29EC A10EA801 */   sb    $t6, -0x57ff($t0)
.L7F0E29F0:
/* 117520 7F0E29F0 252B0001 */  addiu $t3, $t1, 1
/* 117524 7F0E29F4 29614000 */  slti  $at, $t3, 0x4000
/* 117528 7F0E29F8 14200011 */  bnez  $at, .L7F0E2A40
/* 11752C 7F0E29FC 97AF0298 */   lhu   $t7, 0x298($sp)
/* 117530 7F0E2A00 3C0D8009 */  lui   $t5, %hi(ptr_spectrum_roms) 
/* 117534 7F0E2A04 8DADE328 */  lw    $t5, %lo(ptr_spectrum_roms)($t5)
/* 117538 7F0E2A08 000FC203 */  sra   $t8, $t7, 8
/* 11753C 7F0E2A0C 240A0001 */  li    $t2, 1
/* 117540 7F0E2A10 01A96021 */  addu  $t4, $t5, $t1
/* 117544 7F0E2A14 A1980001 */  sb    $t8, 1($t4)
/* 117548 7F0E2A18 97B90292 */  lhu   $t9, 0x292($sp)
/* 11754C 7F0E2A1C 3C098009 */  lui   $t1, %hi(ptr_300alloc) 
/* 117550 7F0E2A20 8D29E32C */  lw    $t1, %lo(ptr_300alloc)($t1)
/* 117554 7F0E2A24 272E0001 */  addiu $t6, $t9, 1
/* 117558 7F0E2A28 31C81800 */  andi  $t0, $t6, 0x1800
/* 11755C 7F0E2A2C 000858C3 */  sra   $t3, $t0, 3
/* 117560 7F0E2A30 31CF00FF */  andi  $t7, $t6, 0xff
/* 117564 7F0E2A34 016F6825 */  or    $t5, $t3, $t7
/* 117568 7F0E2A38 012DC021 */  addu  $t8, $t1, $t5
/* 11756C 7F0E2A3C A30A0000 */  sb    $t2, ($t8)
.L7F0E2A40:
/* 117570 7F0E2A40 240C0038 */  li    $t4, 56
/* 117574 7F0E2A44 10000070 */  b     .L7F0E2C08
/* 117578 7F0E2A48 A7AC0298 */   sh    $t4, 0x298($sp)
.L7F0E2A4C:
/* 11757C 7F0E2A4C 93AE029E */  lbu   $t6, 0x29e($sp)
/* 117580 7F0E2A50 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 117584 7F0E2A54 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 117588 7F0E2A58 000E5A00 */  sll   $t3, $t6, 8
/* 11758C 7F0E2A5C 2728000E */  addiu $t0, $t9, 0xe
/* 117590 7F0E2A60 356F00FF */  ori   $t7, $t3, 0xff
/* 117594 7F0E2A64 97AE0292 */  lhu   $t6, 0x292($sp)
/* 117598 7F0E2A68 AFA8028C */  sw    $t0, 0x28c($sp)
/* 11759C 7F0E2A6C 012FC021 */  addu  $t8, $t1, $t7
/* 1175A0 7F0E2A70 930C0001 */  lbu   $t4, 1($t8)
/* 1175A4 7F0E2A74 01E96821 */  addu  $t5, $t7, $t1
/* 1175A8 7F0E2A78 91AA0000 */  lbu   $t2, ($t5)
/* 1175AC 7F0E2A7C 25CBFFFE */  addiu $t3, $t6, -2
/* 1175B0 7F0E2A80 316DFFFF */  andi  $t5, $t3, 0xffff
/* 1175B4 7F0E2A84 000CCA00 */  sll   $t9, $t4, 8
/* 1175B8 7F0E2A88 29A15B00 */  slti  $at, $t5, 0x5b00
/* 1175BC 7F0E2A8C 01594025 */  or    $t0, $t2, $t9
/* 1175C0 7F0E2A90 AFA8004C */  sw    $t0, 0x4c($sp)
/* 1175C4 7F0E2A94 14200007 */  bnez  $at, .L7F0E2AB4
/* 1175C8 7F0E2A98 A7AB0292 */   sh    $t3, 0x292($sp)
/* 1175CC 7F0E2A9C 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 1175D0 7F0E2AA0 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 1175D4 7F0E2AA4 97A90298 */  lhu   $t1, 0x298($sp)
/* 1175D8 7F0E2AA8 01EDC021 */  addu  $t8, $t7, $t5
/* 1175DC 7F0E2AAC 10000023 */  b     .L7F0E2B3C
/* 1175E0 7F0E2AB0 A3090000 */   sb    $t1, ($t8)
.L7F0E2AB4:
/* 1175E4 7F0E2AB4 97AC0292 */  lhu   $t4, 0x292($sp)
/* 1175E8 7F0E2AB8 97A90292 */  lhu   $t1, 0x292($sp)
/* 1175EC 7F0E2ABC 3C198009 */  lui   $t9, %hi(ptr_spectrum_roms) 
/* 1175F0 7F0E2AC0 29815800 */  slti  $at, $t4, 0x5800
/* 1175F4 7F0E2AC4 5420000D */  bnezl $at, .L7F0E2AFC
/* 1175F8 7F0E2AC8 29214000 */   slti  $at, $t1, 0x4000
/* 1175FC 7F0E2ACC 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 117600 7F0E2AD0 97AA0298 */  lhu   $t2, 0x298($sp)
/* 117604 7F0E2AD4 3C0B8009 */  lui   $t3, %hi(ptr_300alloc) 
/* 117608 7F0E2AD8 032C4021 */  addu  $t0, $t9, $t4
/* 11760C 7F0E2ADC A10A0000 */  sb    $t2, ($t0)
/* 117610 7F0E2AE0 97AF0292 */  lhu   $t7, 0x292($sp)
/* 117614 7F0E2AE4 8D6BE32C */  lw    $t3, %lo(ptr_300alloc)($t3)
/* 117618 7F0E2AE8 240E0001 */  li    $t6, 1
/* 11761C 7F0E2AEC 016F6821 */  addu  $t5, $t3, $t7
/* 117620 7F0E2AF0 10000012 */  b     .L7F0E2B3C
/* 117624 7F0E2AF4 A1AEA800 */   sb    $t6, -0x5800($t5)
/* 117628 7F0E2AF8 29214000 */  slti  $at, $t1, 0x4000
.L7F0E2AFC:
/* 11762C 7F0E2AFC 1420000F */  bnez  $at, .L7F0E2B3C
/* 117630 7F0E2B00 3C198009 */   lui   $t9, %hi(ptr_spectrum_roms) 
/* 117634 7F0E2B04 8F39E328 */  lw    $t9, %lo(ptr_spectrum_roms)($t9)
/* 117638 7F0E2B08 97B80298 */  lhu   $t8, 0x298($sp)
/* 11763C 7F0E2B0C 240A0001 */  li    $t2, 1
/* 117640 7F0E2B10 03296021 */  addu  $t4, $t9, $t1
/* 117644 7F0E2B14 A1980000 */  sb    $t8, ($t4)
/* 117648 7F0E2B18 97A80292 */  lhu   $t0, 0x292($sp)
/* 11764C 7F0E2B1C 3C198009 */  lui   $t9, %hi(ptr_300alloc) 
/* 117650 7F0E2B20 8F39E32C */  lw    $t9, %lo(ptr_300alloc)($t9)
/* 117654 7F0E2B24 310B1800 */  andi  $t3, $t0, 0x1800
/* 117658 7F0E2B28 000B78C3 */  sra   $t7, $t3, 3
/* 11765C 7F0E2B2C 310E00FF */  andi  $t6, $t0, 0xff
/* 117660 7F0E2B30 01EE6825 */  or    $t5, $t7, $t6
/* 117664 7F0E2B34 032D4821 */  addu  $t1, $t9, $t5
/* 117668 7F0E2B38 A12A0000 */  sb    $t2, ($t1)
.L7F0E2B3C:
/* 11766C 7F0E2B3C 97B80292 */  lhu   $t8, 0x292($sp)
/* 117670 7F0E2B40 97B90292 */  lhu   $t9, 0x292($sp)
/* 117674 7F0E2B44 97AB0298 */  lhu   $t3, 0x298($sp)
/* 117678 7F0E2B48 270C0001 */  addiu $t4, $t8, 1
/* 11767C 7F0E2B4C 29815B00 */  slti  $at, $t4, 0x5b00
/* 117680 7F0E2B50 14200007 */  bnez  $at, .L7F0E2B70
/* 117684 7F0E2B54 272D0001 */   addiu $t5, $t9, 1
/* 117688 7F0E2B58 3C0F8009 */  lui   $t7, %hi(ptr_spectrum_roms) 
/* 11768C 7F0E2B5C 8DEFE328 */  lw    $t7, %lo(ptr_spectrum_roms)($t7)
/* 117690 7F0E2B60 000B4203 */  sra   $t0, $t3, 8
/* 117694 7F0E2B64 01F87021 */  addu  $t6, $t7, $t8
/* 117698 7F0E2B68 10000025 */  b     .L7F0E2C00
/* 11769C 7F0E2B6C A1C80001 */   sb    $t0, 1($t6)
.L7F0E2B70:
/* 1176A0 7F0E2B70 29A15800 */  slti  $at, $t5, 0x5800
/* 1176A4 7F0E2B74 1420000E */  bnez  $at, .L7F0E2BB0
/* 1176A8 7F0E2B78 97AD0292 */   lhu   $t5, 0x292($sp)
/* 1176AC 7F0E2B7C 3C0C8009 */  lui   $t4, %hi(ptr_spectrum_roms) 
/* 1176B0 7F0E2B80 8D8CE328 */  lw    $t4, %lo(ptr_spectrum_roms)($t4)
/* 1176B4 7F0E2B84 97AA0298 */  lhu   $t2, 0x298($sp)
/* 1176B8 7F0E2B88 3C188009 */  lui   $t8, %hi(ptr_300alloc) 
/* 1176BC 7F0E2B8C 01995821 */  addu  $t3, $t4, $t9
/* 1176C0 7F0E2B90 000A4A03 */  sra   $t1, $t2, 8
/* 1176C4 7F0E2B94 A1690001 */  sb    $t1, 1($t3)
/* 1176C8 7F0E2B98 97A80292 */  lhu   $t0, 0x292($sp)
/* 1176CC 7F0E2B9C 8F18E32C */  lw    $t8, %lo(ptr_300alloc)($t8)
/* 1176D0 7F0E2BA0 240F0001 */  li    $t7, 1
/* 1176D4 7F0E2BA4 03087021 */  addu  $t6, $t8, $t0
/* 1176D8 7F0E2BA8 10000015 */  b     .L7F0E2C00
/* 1176DC 7F0E2BAC A1CFA801 */   sb    $t7, -0x57ff($t6)
.L7F0E2BB0:
/* 1176E0 7F0E2BB0 25AA0001 */  addiu $t2, $t5, 1
/* 1176E4 7F0E2BB4 29414000 */  slti  $at, $t2, 0x4000
/* 1176E8 7F0E2BB8 14200011 */  bnez  $at, .L7F0E2C00
/* 1176EC 7F0E2BBC 97AC0298 */   lhu   $t4, 0x298($sp)
/* 1176F0 7F0E2BC0 3C098009 */  lui   $t1, %hi(ptr_spectrum_roms) 
/* 1176F4 7F0E2BC4 8D29E328 */  lw    $t1, %lo(ptr_spectrum_roms)($t1)
/* 1176F8 7F0E2BC8 000CCA03 */  sra   $t9, $t4, 8
/* 1176FC 7F0E2BCC 24180001 */  li    $t8, 1
/* 117700 7F0E2BD0 012D5821 */  addu  $t3, $t1, $t5
/* 117704 7F0E2BD4 A1790001 */  sb    $t9, 1($t3)
/* 117708 7F0E2BD8 97A80292 */  lhu   $t0, 0x292($sp)
/* 11770C 7F0E2BDC 3C0D8009 */  lui   $t5, %hi(ptr_300alloc) 
/* 117710 7F0E2BE0 8DADE32C */  lw    $t5, %lo(ptr_300alloc)($t5)
/* 117714 7F0E2BE4 250F0001 */  addiu $t7, $t0, 1
/* 117718 7F0E2BE8 31EE1800 */  andi  $t6, $t7, 0x1800
/* 11771C 7F0E2BEC 000E50C3 */  sra   $t2, $t6, 3
/* 117720 7F0E2BF0 31EC00FF */  andi  $t4, $t7, 0xff
/* 117724 7F0E2BF4 014C4825 */  or    $t1, $t2, $t4
/* 117728 7F0E2BF8 01A9C821 */  addu  $t9, $t5, $t1
/* 11772C 7F0E2BFC A3380000 */  sb    $t8, ($t9)
.L7F0E2C00:
/* 117730 7F0E2C00 8FAB004C */  lw    $t3, 0x4c($sp)
/* 117734 7F0E2C04 A7AB0298 */  sh    $t3, 0x298($sp)
.L7F0E2C08:
/* 117738 7F0E2C08 3C018009 */  lui   $at, %hi(spectrum_header16_15)
/* 11773C 7F0E2C0C A030E338 */  sb    $s0, %lo(spectrum_header16_15)($at)
/* 117740 7F0E2C10 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E339)
/* 117744 7F0E2C14 A031E339 */  sb    $s1, %lo(byte_CODE_bss_8008E339)($at)
/* 117748 7F0E2C18 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E33A)
/* 11774C 7F0E2C1C A032E33A */  sb    $s2, %lo(byte_CODE_bss_8008E33A)($at)
/* 117750 7F0E2C20 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E33B)
/* 117754 7F0E2C24 A033E33B */  sb    $s3, %lo(byte_CODE_bss_8008E33B)($at)
/* 117758 7F0E2C28 3C018009 */  lui   $at, %hi(off_CODE_bss_8008E33C)
/* 11775C 7F0E2C2C A034E33C */  sb    $s4, %lo(off_CODE_bss_8008E33C)($at)
/* 117760 7F0E2C30 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E33D)
/* 117764 7F0E2C34 A035E33D */  sb    $s5, %lo(byte_CODE_bss_8008E33D)($at)
/* 117768 7F0E2C38 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E33E)
/* 11776C 7F0E2C3C A036E33E */  sb    $s6, %lo(byte_CODE_bss_8008E33E)($at)
/* 117770 7F0E2C40 93A802A6 */  lbu   $t0, 0x2a6($sp)
/* 117774 7F0E2C44 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E33F)
/* 117778 7F0E2C48 A037E33F */  sb    $s7, %lo(byte_CODE_bss_8008E33F)($at)
/* 11777C 7F0E2C4C 93AE02A5 */  lbu   $t6, 0x2a5($sp)
/* 117780 7F0E2C50 3C018009 */  lui   $at, %hi(off_CODE_bss_8008E340)
/* 117784 7F0E2C54 A028E340 */  sb    $t0, %lo(off_CODE_bss_8008E340)($at)
/* 117788 7F0E2C58 93AF02A4 */  lbu   $t7, 0x2a4($sp)
/* 11778C 7F0E2C5C 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E341)
/* 117790 7F0E2C60 A02EE341 */  sb    $t6, %lo(byte_CODE_bss_8008E341)($at)
/* 117794 7F0E2C64 93AA02A3 */  lbu   $t2, 0x2a3($sp)
/* 117798 7F0E2C68 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E342)
/* 11779C 7F0E2C6C A02FE342 */  sb    $t7, %lo(byte_CODE_bss_8008E342)($at)
/* 1177A0 7F0E2C70 93AC02A2 */  lbu   $t4, 0x2a2($sp)
/* 1177A4 7F0E2C74 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E343)
/* 1177A8 7F0E2C78 A02AE343 */  sb    $t2, %lo(byte_CODE_bss_8008E343)($at)
/* 1177AC 7F0E2C7C 93AD02A1 */  lbu   $t5, 0x2a1($sp)
/* 1177B0 7F0E2C80 3C018009 */  lui   $at, %hi(off_CODE_bss_8008E344)
/* 1177B4 7F0E2C84 A02CE344 */  sb    $t4, %lo(off_CODE_bss_8008E344)($at)
/* 1177B8 7F0E2C88 93A902A0 */  lbu   $t1, 0x2a0($sp)
/* 1177BC 7F0E2C8C 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E345)
/* 1177C0 7F0E2C90 A02DE345 */  sb    $t5, %lo(byte_CODE_bss_8008E345)($at)
/* 1177C4 7F0E2C94 93B8029F */  lbu   $t8, 0x29f($sp)
/* 1177C8 7F0E2C98 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E346)
/* 1177CC 7F0E2C9C A029E346 */  sb    $t1, %lo(byte_CODE_bss_8008E346)($at)
/* 1177D0 7F0E2CA0 93B9029D */  lbu   $t9, 0x29d($sp)
/* 1177D4 7F0E2CA4 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E347)
/* 1177D8 7F0E2CA8 A038E347 */  sb    $t8, %lo(byte_CODE_bss_8008E347)($at)
/* 1177DC 7F0E2CAC 93AB029C */  lbu   $t3, 0x29c($sp)
/* 1177E0 7F0E2CB0 3C018009 */  lui   $at, %hi(spec_IFF2_lower)
/* 1177E4 7F0E2CB4 A039E34A */  sb    $t9, %lo(spec_IFF2_lower)($at)
/* 1177E8 7F0E2CB8 93A8029E */  lbu   $t0, 0x29e($sp)
/* 1177EC 7F0E2CBC 3C018009 */  lui   $at, %hi(spec_IFF2_upper)
/* 1177F0 7F0E2CC0 A02BE34B */  sb    $t3, %lo(spec_IFF2_upper)($at)
/* 1177F4 7F0E2CC4 93AE02A7 */  lbu   $t6, 0x2a7($sp)
/* 1177F8 7F0E2CC8 3C018009 */  lui   $at, %hi(spec_I)
/* 1177FC 7F0E2CCC A028E348 */  sb    $t0, %lo(spec_I)($at)
/* 117800 7F0E2CD0 93AA029B */  lbu   $t2, 0x29b($sp)
/* 117804 7F0E2CD4 3C018009 */  lui   $at, %hi(byte_CODE_bss_8008E349)
/* 117808 7F0E2CD8 A02EE349 */  sb    $t6, %lo(byte_CODE_bss_8008E349)($at)
/* 11780C 7F0E2CDC 97AC0296 */  lhu   $t4, 0x296($sp)
/* 117810 7F0E2CE0 3C018009 */  lui   $at, %hi(spec_IM)
/* 117814 7F0E2CE4 A02AE34C */  sb    $t2, %lo(spec_IM)($at)
/* 117818 7F0E2CE8 97AD0294 */  lhu   $t5, 0x294($sp)
/* 11781C 7F0E2CEC 3C018009 */  lui   $at, %hi(spec_IX)
/* 117820 7F0E2CF0 A42CE34E */  sh    $t4, %lo(spec_IX)($at)
/* 117824 7F0E2CF4 97A90292 */  lhu   $t1, 0x292($sp)
/* 117828 7F0E2CF8 3C018009 */  lui   $at, %hi(spec_IY)
/* 11782C 7F0E2CFC 8FAF0288 */  lw    $t7, 0x288($sp)
/* 117830 7F0E2D00 A42DE350 */  sh    $t5, %lo(spec_IY)($at)
/* 117834 7F0E2D04 8FBF0034 */  lw    $ra, 0x34($sp)
/* 117838 7F0E2D08 3C018009 */  lui   $at, %hi(spec_SP)
/* 11783C 7F0E2D0C 97B80298 */  lhu   $t8, 0x298($sp)
/* 117840 7F0E2D10 A429E352 */  sh    $t1, %lo(spec_SP)($at)
/* 117844 7F0E2D14 3C018009 */  lui   $at, %hi(spec_PC)
/* 117848 7F0E2D18 8FB70030 */  lw    $s7, 0x30($sp)
/* 11784C 7F0E2D1C 8FB6002C */  lw    $s6, 0x2c($sp)
/* 117850 7F0E2D20 8FB50028 */  lw    $s5, 0x28($sp)
/* 117854 7F0E2D24 8FB40024 */  lw    $s4, 0x24($sp)
/* 117858 7F0E2D28 8FB30020 */  lw    $s3, 0x20($sp)
/* 11785C 7F0E2D2C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 117860 7F0E2D30 8FB10018 */  lw    $s1, 0x18($sp)
/* 117864 7F0E2D34 8FB00014 */  lw    $s0, 0x14($sp)
/* 117868 7F0E2D38 A3AF02A7 */  sb    $t7, 0x2a7($sp)
/* 11786C 7F0E2D3C 27BD02B0 */  addiu $sp, $sp, 0x2b0
/* 117870 7F0E2D40 03E00008 */  jr    $ra
/* 117874 7F0E2D44 A438E354 */   sh    $t8, %lo(spec_PC)($at)
)
#endif

