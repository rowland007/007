# Goldeneye 007 (U) disassembly and split file
# generated by n64split v0.4a - N64 ROM splitter

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
.section .text
glabel osEPiRawStartDma
/* 01F130 7001E530 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 01F134 7001E534 AFBF001C */  sw    $ra, 0x1c($sp)
/* 01F138 7001E538 AFA40028 */  sw    $a0, 0x28($sp)
/* 01F13C 7001E53C AFA5002C */  sw    $a1, 0x2c($sp)
/* 01F140 7001E540 AFA60030 */  sw    $a2, 0x30($sp)
/* 01F144 7001E544 AFA70034 */  sw    $a3, 0x34($sp)
/* 01F148 7001E548 AFB10018 */  sw    $s1, 0x18($sp)
/* 01F14C 7001E54C AFB00014 */  sw    $s0, 0x14($sp)
/* 01F150 7001E550 3C0EA460 */  lui   $t6, %hi(PI_STATUS_REG) # $t6, 0xa460
/* 01F154 7001E554 8DD00010 */  lw    $s0, %lo(PI_STATUS_REG)($t6)
/* 01F158 7001E558 320F0003 */  andi  $t7, $s0, 3
/* 01F15C 7001E55C 11E00006 */  beqz  $t7, .L7001E578
/* 01F160 7001E560 00000000 */   nop   
.L7001E564:
/* 01F164 7001E564 3C18A460 */  lui   $t8, %hi(PI_STATUS_REG) # $t8, 0xa460
/* 01F168 7001E568 8F100010 */  lw    $s0, %lo(PI_STATUS_REG)($t8)
/* 01F16C 7001E56C 32190003 */  andi  $t9, $s0, 3
/* 01F170 7001E570 1720FFFC */  bnez  $t9, .L7001E564
/* 01F174 7001E574 00000000 */   nop   
.L7001E578:
/* 01F178 7001E578 0C003A2C */  jal   osVirtualToPhysical
/* 01F17C 7001E57C 8FA40034 */   lw    $a0, 0x34($sp)
/* 01F180 7001E580 3C08A460 */  lui   $t0, 0xa460
/* 01F184 7001E584 AD020000 */  sw    $v0, ($t0)
/* 01F188 7001E588 8FA90028 */  lw    $t1, 0x28($sp)
/* 01F18C 7001E58C 8FAB0030 */  lw    $t3, 0x30($sp)
/* 01F190 7001E590 3C011FFF */  lui   $at, (0x1FFFFFFF >> 16) # lui $at, 0x1fff
/* 01F194 7001E594 8D2A000C */  lw    $t2, 0xc($t1)
/* 01F198 7001E598 3421FFFF */  ori   $at, (0x1FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 01F19C 7001E59C 3C0EA460 */  lui   $t6, %hi(PI_CART_ADDR_REG) # $t6, 0xa460
/* 01F1A0 7001E5A0 014B6025 */  or    $t4, $t2, $t3
/* 01F1A4 7001E5A4 01816824 */  and   $t5, $t4, $at
/* 01F1A8 7001E5A8 ADCD0004 */  sw    $t5, %lo(PI_CART_ADDR_REG)($t6)
/* 01F1AC 7001E5AC 8FB1002C */  lw    $s1, 0x2c($sp)
/* 01F1B0 7001E5B0 12200005 */  beqz  $s1, .L7001E5C8
/* 01F1B4 7001E5B4 24010001 */   li    $at, 1
/* 01F1B8 7001E5B8 12210008 */  beq   $s1, $at, .L7001E5DC
/* 01F1BC 7001E5BC 00000000 */   nop   
/* 01F1C0 7001E5C0 1000000B */  b     .L7001E5F0
/* 01F1C4 7001E5C4 00000000 */   nop   
.L7001E5C8:
/* 01F1C8 7001E5C8 8FAF0038 */  lw    $t7, 0x38($sp)
/* 01F1CC 7001E5CC 3C19A460 */  lui   $t9, %hi(PI_WR_LEN_REG) # $t9, 0xa460
/* 01F1D0 7001E5D0 25F8FFFF */  addiu $t8, $t7, -1
/* 01F1D4 7001E5D4 10000008 */  b     .L7001E5F8
/* 01F1D8 7001E5D8 AF38000C */   sw    $t8, %lo(PI_WR_LEN_REG)($t9)
.L7001E5DC:
/* 01F1DC 7001E5DC 8FA80038 */  lw    $t0, 0x38($sp)
/* 01F1E0 7001E5E0 3C0AA460 */  lui   $t2, %hi(PI_RD_LEN_REG) # $t2, 0xa460
/* 01F1E4 7001E5E4 2509FFFF */  addiu $t1, $t0, -1
/* 01F1E8 7001E5E8 10000003 */  b     .L7001E5F8
/* 01F1EC 7001E5EC AD490008 */   sw    $t1, %lo(PI_RD_LEN_REG)($t2)
.L7001E5F0:
/* 01F1F0 7001E5F0 10000002 */  b     .L7001E5FC
/* 01F1F4 7001E5F4 2402FFFF */   li    $v0, -1
.L7001E5F8:
/* 01F1F8 7001E5F8 00001025 */  move  $v0, $zero
.L7001E5FC:
/* 01F1FC 7001E5FC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 01F200 7001E600 8FB00014 */  lw    $s0, 0x14($sp)
/* 01F204 7001E604 8FB10018 */  lw    $s1, 0x18($sp)
/* 01F208 7001E608 03E00008 */  jr    $ra
/* 01F20C 7001E60C 27BD0028 */   addiu $sp, $sp, 0x28
