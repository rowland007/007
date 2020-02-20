#include "ultra64.h"
#include "game/unk_0C0A70.h"
#include "music.h"
#include "bondgame.h"


// bss
s32 stop_play_flag;
s32 is_gameover_flag;
s32 dword_CODE_bss_8008C708;
s32 dword_CODE_bss_8008C70C;
s32 time_trigger_alt_gameover_msg;
s32 dword_CODE_bss_8008C714;
s32 is_paused;
s32 who_paused;

// data
u16 loaded_text_index[] = {
    TEXT(LMPMENU,0),TEXT(LMPMENU,1),TEXT(LMPMENU,2),TEXT(LMPMENU,3),TEXT(LMPMENU,4),TEXT(LMPMENU,5),
    TEXT(LMPMENU,6),TEXT(LMPMENU,7),TEXT(LMPMENU,8),TEXT(LMPMENU,9),TEXT(LMPMENU,0xA),TEXT(LMPMENU,0xB),
    TEXT(LMPMENU,0xC),TEXT(LMPMENU,0xD),TEXT(LMPMENU,0xE),TEXT(LMPMENU,0xF),TEXT(LMPMENU,0x10)
};

//rodata
/*8005BC20*/
const char ascii_MP_watch_menu_percentd[] = "%d";
const char ascii_MP_watch_menu_BLANK[] = "";
const char ascii_MP_watch_menu_left_chevron[] = "<";
const char ascii_MP_watch_menu_right_chevron[] = ">";
const char ascii_pnum_KILLS[] = "%s%d %s";
const char ascii_pnum_LOSSES[] = "%s%d %s";

// rodata


#ifdef NONMATCHING
u32 check_can_advance_right_on_mpmenu(void) {
  switch(pPlayer->mpmenumode) {
  case 0:
    return 1;
  case 1:
    return 1;
  case 2:
    return 1;
  case 3:
    if (is_gameover_flag == 0) {
      return 1;
    }
    return 0;
  case 4:
    return 1;
  case 5:
    return 0;
  case 6:
    return 0;
  case 7:
    return 0;
  default:
    return 0;
  }
}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BC40*/
glabel jpt_MP_menu_page_adv_right
.word page_adv_right_yes
.word page_adv_right_yes
.word page_adv_right_yes
.word page_adv_right_gameover
.word page_adv_right_yes
.word page_adv_right_no
.word page_adv_right_no
.word page_adv_right_no
.text
glabel check_can_advance_right_on_mpmenu
/* 0F6950 7F0C1E20 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0F6954 7F0C1E24 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0F6958 7F0C1E28 00001025 */  move  $v0, $zero
/* 0F695C 7F0C1E2C 8DCF29C8 */  lw    $t7, 0x29c8($t6)
/* 0F6960 7F0C1E30 2DE10008 */  sltiu $at, $t7, 8
/* 0F6964 7F0C1E34 10200013 */  beqz  $at, .L7F0C1E84
/* 0F6968 7F0C1E38 000F7880 */   sll   $t7, $t7, 2
/* 0F696C 7F0C1E3C 3C018006 */  lui   $at, %hi(jpt_MP_menu_page_adv_right)
/* 0F6970 7F0C1E40 002F0821 */  addu  $at, $at, $t7
/* 0F6974 7F0C1E44 8C2FBC40 */  lw    $t7, %lo(jpt_MP_menu_page_adv_right)($at)
/* 0F6978 7F0C1E48 01E00008 */  jr    $t7
/* 0F697C 7F0C1E4C 00000000 */   nop   
page_adv_right_yes:
/* 0F6980 7F0C1E50 03E00008 */  jr    $ra
/* 0F6984 7F0C1E54 24020001 */   li    $v0, 1

page_adv_right_no:
/* 0F6988 7F0C1E58 03E00008 */  jr    $ra
/* 0F698C 7F0C1E5C 00001025 */   move  $v0, $zero

page_adv_right_gameover:
/* 0F6990 7F0C1E60 3C188009 */  lui   $t8, %hi(is_gameover_flag) 
/* 0F6994 7F0C1E64 8F18C704 */  lw    $t8, %lo(is_gameover_flag)($t8)
/* 0F6998 7F0C1E68 24030001 */  li    $v1, 1
/* 0F699C 7F0C1E6C 13000003 */  beqz  $t8, .L7F0C1E7C
/* 0F69A0 7F0C1E70 00000000 */   nop   
/* 0F69A4 7F0C1E74 03E00008 */  jr    $ra
/* 0F69A8 7F0C1E78 00001025 */   move  $v0, $zero

.L7F0C1E7C:
/* 0F69AC 7F0C1E7C 03E00008 */  jr    $ra
/* 0F69B0 7F0C1E80 00601025 */   move  $v0, $v1

.L7F0C1E84:
/* 0F69B4 7F0C1E84 03E00008 */  jr    $ra
/* 0F69B8 7F0C1E88 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
u32 check_can_advance_left_on_mpmenu(void) {
  switch(pPlayer->mpmenumode) {
  case 0:
    return 0;
  case 1:
    if (is_gameover_flag == 0) {
      return 0;
    }
    return 1;
  case 2:
    return 1;
  case 3:
    return 1;
  case 4:
    return 1;
  case 5:
    return 1;
  case 6:
    return 0;
  case 7:
    return 0;
  default:
    return 0;
  }
}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BC60*/
glabel jpt_MP_menu_page_adv_left
.word page_adv_left_no
.word page_adv_left_gameover
.word page_adv_left_yes
.word page_adv_left_yes
.word page_adv_left_yes
.word page_adv_left_yes
.word page_adv_left_no
.word page_adv_left_no

.text
glabel check_can_advance_left_on_mpmenu
/* 0F69BC 7F0C1E8C 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0F69C0 7F0C1E90 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0F69C4 7F0C1E94 00001025 */  move  $v0, $zero
/* 0F69C8 7F0C1E98 8DCF29C8 */  lw    $t7, 0x29c8($t6)
/* 0F69CC 7F0C1E9C 2DE10008 */  sltiu $at, $t7, 8
/* 0F69D0 7F0C1EA0 10200013 */  beqz  $at, .L7F0C1EF0
/* 0F69D4 7F0C1EA4 000F7880 */   sll   $t7, $t7, 2
/* 0F69D8 7F0C1EA8 3C018006 */  lui   $at, %hi(jpt_MP_menu_page_adv_left)
/* 0F69DC 7F0C1EAC 002F0821 */  addu  $at, $at, $t7
/* 0F69E0 7F0C1EB0 8C2FBC60 */  lw    $t7, %lo(jpt_MP_menu_page_adv_left)($at)
/* 0F69E4 7F0C1EB4 01E00008 */  jr    $t7
/* 0F69E8 7F0C1EB8 00000000 */   nop   
page_adv_left_yes:
/* 0F69EC 7F0C1EBC 03E00008 */  jr    $ra
/* 0F69F0 7F0C1EC0 24020001 */   li    $v0, 1

page_adv_left_no:
/* 0F69F4 7F0C1EC4 03E00008 */  jr    $ra
/* 0F69F8 7F0C1EC8 00001025 */   move  $v0, $zero

page_adv_left_gameover:
/* 0F69FC 7F0C1ECC 3C188009 */  lui   $t8, %hi(is_gameover_flag) 
/* 0F6A00 7F0C1ED0 8F18C704 */  lw    $t8, %lo(is_gameover_flag)($t8)
/* 0F6A04 7F0C1ED4 00001825 */  move  $v1, $zero
/* 0F6A08 7F0C1ED8 13000003 */  beqz  $t8, .L7F0C1EE8
/* 0F6A0C 7F0C1EDC 00000000 */   nop   
/* 0F6A10 7F0C1EE0 03E00008 */  jr    $ra
/* 0F6A14 7F0C1EE4 24020001 */   li    $v0, 1

.L7F0C1EE8:
/* 0F6A18 7F0C1EE8 03E00008 */  jr    $ra
/* 0F6A1C 7F0C1EEC 00601025 */   move  $v0, $v1

def_7F0C1EB4:
.L7F0C1EF0:
/* 0F6A20 7F0C1EF0 03E00008 */  jr    $ra
/* 0F6A24 7F0C1EF4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void check_if_player_is_pressing_anything_right(s32 arg0) {
    s32 sp18;
    s32 sp1C;
    s32 temp_t6;
    ? temp_ret;

    // Node 0
    temp_t6 = ((s32) (arg0 << 0x18) >> 0x18);
    sp18 = temp_t6;
    sp1C = get_controller_3dstick_L_R(temp_t6, -2, 1);
    temp_ret = get_controller_buttons_pressed(sp18, 0x101);
    if ((temp_ret == 0) && (sp1C > 0))
    {
        // Node 2
        if (pPlayer->unk29D0 != 0)
        {
            // Node 3
        }
    }
    else
    {
        // Node 3
    }
    // Node 4
    return temp_ret;
}
#else
GLOBAL_ASM(
.text
glabel check_if_player_is_pressing_anything_right
/* 0F6A28 7F0C1EF8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F6A2C 7F0C1EFC 00042600 */  sll   $a0, $a0, 0x18
/* 0F6A30 7F0C1F00 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F6A34 7F0C1F04 00047603 */  sra   $t6, $a0, 0x18
/* 0F6A38 7F0C1F08 01C02025 */  move  $a0, $t6
/* 0F6A3C 7F0C1F0C AFAE0018 */  sw    $t6, 0x18($sp)
/* 0F6A40 7F0C1F10 2405FFFE */  li    $a1, -2
/* 0F6A44 7F0C1F14 0C00312D */  jal   get_controller_3dstick_L_R
/* 0F6A48 7F0C1F18 24060001 */   li    $a2, 1
/* 0F6A4C 7F0C1F1C 8FA40018 */  lw    $a0, 0x18($sp)
/* 0F6A50 7F0C1F20 AFA2001C */  sw    $v0, 0x1c($sp)
/* 0F6A54 7F0C1F24 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F6A58 7F0C1F28 24050101 */   li    $a1, 257
/* 0F6A5C 7F0C1F2C 1440000A */  bnez  $v0, .L7F0C1F58
/* 0F6A60 7F0C1F30 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F6A64 7F0C1F34 8FAF001C */  lw    $t7, 0x1c($sp)
/* 0F6A68 7F0C1F38 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0F6A6C 7F0C1F3C 00001025 */  move  $v0, $zero
/* 0F6A70 7F0C1F40 19E00007 */  blez  $t7, .L7F0C1F60
/* 0F6A74 7F0C1F44 00000000 */   nop   
/* 0F6A78 7F0C1F48 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0F6A7C 7F0C1F4C 8F1929D0 */  lw    $t9, 0x29d0($t8)
/* 0F6A80 7F0C1F50 13200003 */  beqz  $t9, .L7F0C1F60
/* 0F6A84 7F0C1F54 00000000 */   nop   
.L7F0C1F58:
/* 0F6A88 7F0C1F58 10000001 */  b     .L7F0C1F60
/* 0F6A8C 7F0C1F5C 24020001 */   li    $v0, 1
.L7F0C1F60:
/* 0F6A90 7F0C1F60 03E00008 */  jr    $ra
/* 0F6A94 7F0C1F64 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void check_if_player_is_pressing_anything_left(s32 arg0) {
    s32 sp18;
    s32 sp1C;
    s32 temp_t6;

    // Node 0
    temp_t6 = ((s32) (arg0 << 0x18) >> 0x18);
    sp18 = temp_t6;
    sp1C = get_controller_3dstick_L_R(temp_t6, -2, 1);
    if ((get_controller_buttons_pressed(sp18, 0x202) == 0) && (sp1C < -1))
    {
        // Node 2
        if (pPlayer->unk29D0 != 0)
        {
            // Node 3
            return;
            // (possible return value: 1)
        }
    }
    else
    {
        // Node 3
        return;
        // (possible return value: 1)
    }
    // (possible return value: 1)
}

#else
GLOBAL_ASM(
.text
glabel check_if_player_is_pressing_anything_left
/* 0F6A98 7F0C1F68 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F6A9C 7F0C1F6C 00042600 */  sll   $a0, $a0, 0x18
/* 0F6AA0 7F0C1F70 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F6AA4 7F0C1F74 00047603 */  sra   $t6, $a0, 0x18
/* 0F6AA8 7F0C1F78 01C02025 */  move  $a0, $t6
/* 0F6AAC 7F0C1F7C AFAE0018 */  sw    $t6, 0x18($sp)
/* 0F6AB0 7F0C1F80 2405FFFE */  li    $a1, -2
/* 0F6AB4 7F0C1F84 0C00312D */  jal   get_controller_3dstick_L_R
/* 0F6AB8 7F0C1F88 24060001 */   li    $a2, 1
/* 0F6ABC 7F0C1F8C 8FA40018 */  lw    $a0, 0x18($sp)
/* 0F6AC0 7F0C1F90 AFA2001C */  sw    $v0, 0x1c($sp)
/* 0F6AC4 7F0C1F94 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F6AC8 7F0C1F98 24050202 */   li    $a1, 514
/* 0F6ACC 7F0C1F9C 1440000B */  bnez  $v0, .L7F0C1FCC
/* 0F6AD0 7F0C1FA0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F6AD4 7F0C1FA4 8FAF001C */  lw    $t7, 0x1c($sp)
/* 0F6AD8 7F0C1FA8 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0F6ADC 7F0C1FAC 00001025 */  move  $v0, $zero
/* 0F6AE0 7F0C1FB0 29E1FFFF */  slti  $at, $t7, -1
/* 0F6AE4 7F0C1FB4 10200007 */  beqz  $at, .L7F0C1FD4
/* 0F6AE8 7F0C1FB8 00000000 */   nop   
/* 0F6AEC 7F0C1FBC 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0F6AF0 7F0C1FC0 8F1929D0 */  lw    $t9, 0x29d0($t8)
/* 0F6AF4 7F0C1FC4 13200003 */  beqz  $t9, .L7F0C1FD4
/* 0F6AF8 7F0C1FC8 00000000 */   nop   
.L7F0C1FCC:
/* 0F6AFC 7F0C1FCC 10000001 */  b     .L7F0C1FD4
/* 0F6B00 7F0C1FD0 24020001 */   li    $v0, 1
.L7F0C1FD4:
/* 0F6B04 7F0C1FD4 03E00008 */  jr    $ra
/* 0F6B08 7F0C1FD8 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





void play_watch_sfx_beep(void)
{
    play_sfx_a1(ptr_sfx_buf, 0x9f, 0);
}

void unpause_game(void)
{
    stop_play_flag = 0;
    is_gameover_flag = 0;
    is_paused = 0;
}






#ifdef NONMATCHING
void sub_GAME_7F0C2024(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C2024
/* 0F6B54 7F0C2024 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F6B58 7F0C2028 00A6082A */  slt   $at, $a1, $a2
/* 0F6B5C 7F0C202C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F6B60 7F0C2030 1420000C */  bnez  $at, .L7F0C2064
/* 0F6B64 7F0C2034 AFA40020 */   sw    $a0, 0x20($sp)
/* 0F6B68 7F0C2038 54C5000E */  bnel  $a2, $a1, .L7F0C2074
/* 0F6B6C 7F0C203C 00002025 */   move  $a0, $zero
/* 0F6B70 7F0C2040 AFA50024 */  sw    $a1, 0x24($sp)
/* 0F6B74 7F0C2044 AFA60028 */  sw    $a2, 0x28($sp)
/* 0F6B78 7F0C2048 0C002914 */  jal   get_random_value
/* 0F6B7C 7F0C204C AFA7002C */   sw    $a3, 0x2c($sp)
/* 0F6B80 7F0C2050 304E0001 */  andi  $t6, $v0, 1
/* 0F6B84 7F0C2054 8FA50024 */  lw    $a1, 0x24($sp)
/* 0F6B88 7F0C2058 8FA60028 */  lw    $a2, 0x28($sp)
/* 0F6B8C 7F0C205C 11C00004 */  beqz  $t6, .L7F0C2070
/* 0F6B90 7F0C2060 8FA7002C */   lw    $a3, 0x2c($sp)
.L7F0C2064:
/* 0F6B94 7F0C2064 24040001 */  li    $a0, 1
/* 0F6B98 7F0C2068 10000003 */  b     .L7F0C2078
/* 0F6B9C 7F0C206C 00C01825 */   move  $v1, $a2
.L7F0C2070:
/* 0F6BA0 7F0C2070 00002025 */  move  $a0, $zero
.L7F0C2074:
/* 0F6BA4 7F0C2074 00A01825 */  move  $v1, $a1
.L7F0C2078:
/* 0F6BA8 7F0C2078 8FAF0020 */  lw    $t7, 0x20($sp)
/* 0F6BAC 7F0C207C 29E10003 */  slti  $at, $t7, 3
/* 0F6BB0 7F0C2080 1420001F */  bnez  $at, .L7F0C2100
/* 0F6BB4 7F0C2084 0067082A */   slt   $at, $v1, $a3
/* 0F6BB8 7F0C2088 5420000D */  bnezl $at, .L7F0C20C0
/* 0F6BBC 7F0C208C 24040002 */   li    $a0, 2
/* 0F6BC0 7F0C2090 54E3000D */  bnel  $a3, $v1, .L7F0C20C8
/* 0F6BC4 7F0C2094 8FB90020 */   lw    $t9, 0x20($sp)
/* 0F6BC8 7F0C2098 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0F6BCC 7F0C209C AFA40018 */  sw    $a0, 0x18($sp)
/* 0F6BD0 7F0C20A0 0C002914 */  jal   get_random_value
/* 0F6BD4 7F0C20A4 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0F6BD8 7F0C20A8 30580001 */  andi  $t8, $v0, 1
/* 0F6BDC 7F0C20AC 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F6BE0 7F0C20B0 8FA40018 */  lw    $a0, 0x18($sp)
/* 0F6BE4 7F0C20B4 13000003 */  beqz  $t8, .L7F0C20C4
/* 0F6BE8 7F0C20B8 8FA7002C */   lw    $a3, 0x2c($sp)
/* 0F6BEC 7F0C20BC 24040002 */  li    $a0, 2
.L7F0C20C0:
/* 0F6BF0 7F0C20C0 00E01825 */  move  $v1, $a3
.L7F0C20C4:
/* 0F6BF4 7F0C20C4 8FB90020 */  lw    $t9, 0x20($sp)
.L7F0C20C8:
/* 0F6BF8 7F0C20C8 8FA20030 */  lw    $v0, 0x30($sp)
/* 0F6BFC 7F0C20CC 2B210004 */  slti  $at, $t9, 4
/* 0F6C00 7F0C20D0 1420000B */  bnez  $at, .L7F0C2100
/* 0F6C04 7F0C20D4 0062082A */   slt   $at, $v1, $v0
/* 0F6C08 7F0C20D8 54200009 */  bnezl $at, .L7F0C2100
/* 0F6C0C 7F0C20DC 24040003 */   li    $a0, 3
/* 0F6C10 7F0C20E0 54430008 */  bnel  $v0, $v1, .L7F0C2104
/* 0F6C14 7F0C20E4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F6C18 7F0C20E8 0C002914 */  jal   get_random_value
/* 0F6C1C 7F0C20EC AFA40018 */   sw    $a0, 0x18($sp)
/* 0F6C20 7F0C20F0 30480001 */  andi  $t0, $v0, 1
/* 0F6C24 7F0C20F4 11000002 */  beqz  $t0, .L7F0C2100
/* 0F6C28 7F0C20F8 8FA40018 */   lw    $a0, 0x18($sp)
/* 0F6C2C 7F0C20FC 24040003 */  li    $a0, 3
.L7F0C2100:
/* 0F6C30 7F0C2100 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0C2104:
/* 0F6C34 7F0C2104 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F6C38 7F0C2108 00801025 */  move  $v0, $a0
/* 0F6C3C 7F0C210C 03E00008 */  jr    $ra
/* 0F6C40 7F0C2110 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C2114(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C2114
/* 0F6C44 7F0C2114 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F6C48 7F0C2118 00C5082A */  slt   $at, $a2, $a1
/* 0F6C4C 7F0C211C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F6C50 7F0C2120 1420000C */  bnez  $at, .L7F0C2154
/* 0F6C54 7F0C2124 AFA40020 */   sw    $a0, 0x20($sp)
/* 0F6C58 7F0C2128 54C5000E */  bnel  $a2, $a1, .L7F0C2164
/* 0F6C5C 7F0C212C 00002025 */   move  $a0, $zero
/* 0F6C60 7F0C2130 AFA50024 */  sw    $a1, 0x24($sp)
/* 0F6C64 7F0C2134 AFA60028 */  sw    $a2, 0x28($sp)
/* 0F6C68 7F0C2138 0C002914 */  jal   get_random_value
/* 0F6C6C 7F0C213C AFA7002C */   sw    $a3, 0x2c($sp)
/* 0F6C70 7F0C2140 304E0001 */  andi  $t6, $v0, 1
/* 0F6C74 7F0C2144 8FA50024 */  lw    $a1, 0x24($sp)
/* 0F6C78 7F0C2148 8FA60028 */  lw    $a2, 0x28($sp)
/* 0F6C7C 7F0C214C 11C00004 */  beqz  $t6, .L7F0C2160
/* 0F6C80 7F0C2150 8FA7002C */   lw    $a3, 0x2c($sp)
.L7F0C2154:
/* 0F6C84 7F0C2154 24040001 */  li    $a0, 1
/* 0F6C88 7F0C2158 10000003 */  b     .L7F0C2168
/* 0F6C8C 7F0C215C 00C01825 */   move  $v1, $a2
.L7F0C2160:
/* 0F6C90 7F0C2160 00002025 */  move  $a0, $zero
.L7F0C2164:
/* 0F6C94 7F0C2164 00A01825 */  move  $v1, $a1
.L7F0C2168:
/* 0F6C98 7F0C2168 8FAF0020 */  lw    $t7, 0x20($sp)
/* 0F6C9C 7F0C216C 29E10003 */  slti  $at, $t7, 3
/* 0F6CA0 7F0C2170 1420001F */  bnez  $at, .L7F0C21F0
/* 0F6CA4 7F0C2174 00E3082A */   slt   $at, $a3, $v1
/* 0F6CA8 7F0C2178 5420000D */  bnezl $at, .L7F0C21B0
/* 0F6CAC 7F0C217C 24040002 */   li    $a0, 2
/* 0F6CB0 7F0C2180 54E3000D */  bnel  $a3, $v1, .L7F0C21B8
/* 0F6CB4 7F0C2184 8FB90020 */   lw    $t9, 0x20($sp)
/* 0F6CB8 7F0C2188 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0F6CBC 7F0C218C AFA40018 */  sw    $a0, 0x18($sp)
/* 0F6CC0 7F0C2190 0C002914 */  jal   get_random_value
/* 0F6CC4 7F0C2194 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0F6CC8 7F0C2198 30580001 */  andi  $t8, $v0, 1
/* 0F6CCC 7F0C219C 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F6CD0 7F0C21A0 8FA40018 */  lw    $a0, 0x18($sp)
/* 0F6CD4 7F0C21A4 13000003 */  beqz  $t8, .L7F0C21B4
/* 0F6CD8 7F0C21A8 8FA7002C */   lw    $a3, 0x2c($sp)
/* 0F6CDC 7F0C21AC 24040002 */  li    $a0, 2
.L7F0C21B0:
/* 0F6CE0 7F0C21B0 00E01825 */  move  $v1, $a3
.L7F0C21B4:
/* 0F6CE4 7F0C21B4 8FB90020 */  lw    $t9, 0x20($sp)
.L7F0C21B8:
/* 0F6CE8 7F0C21B8 8FA20030 */  lw    $v0, 0x30($sp)
/* 0F6CEC 7F0C21BC 2B210004 */  slti  $at, $t9, 4
/* 0F6CF0 7F0C21C0 1420000B */  bnez  $at, .L7F0C21F0
/* 0F6CF4 7F0C21C4 0043082A */   slt   $at, $v0, $v1
/* 0F6CF8 7F0C21C8 54200009 */  bnezl $at, .L7F0C21F0
/* 0F6CFC 7F0C21CC 24040003 */   li    $a0, 3
/* 0F6D00 7F0C21D0 54430008 */  bnel  $v0, $v1, .L7F0C21F4
/* 0F6D04 7F0C21D4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F6D08 7F0C21D8 0C002914 */  jal   get_random_value
/* 0F6D0C 7F0C21DC AFA40018 */   sw    $a0, 0x18($sp)
/* 0F6D10 7F0C21E0 30480001 */  andi  $t0, $v0, 1
/* 0F6D14 7F0C21E4 11000002 */  beqz  $t0, .L7F0C21F0
/* 0F6D18 7F0C21E8 8FA40018 */   lw    $a0, 0x18($sp)
/* 0F6D1C 7F0C21EC 24040003 */  li    $a0, 3
.L7F0C21F0:
/* 0F6D20 7F0C21F0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0C21F4:
/* 0F6D24 7F0C21F4 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F6D28 7F0C21F8 00801025 */  move  $v0, $a0
/* 0F6D2C 7F0C21FC 03E00008 */  jr    $ra
/* 0F6D30 7F0C2200 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C2204(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C2204
/* 0F6D34 7F0C2204 44856000 */  mtc1  $a1, $f12
/* 0F6D38 7F0C2208 44867000 */  mtc1  $a2, $f14
/* 0F6D3C 7F0C220C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F6D40 7F0C2210 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F6D44 7F0C2214 460E603C */  c.lt.s $f12, $f14
/* 0F6D48 7F0C2218 AFA40020 */  sw    $a0, 0x20($sp)
/* 0F6D4C 7F0C221C AFA7002C */  sw    $a3, 0x2c($sp)
/* 0F6D50 7F0C2220 4503000D */  bc1tl .L7F0C2258
/* 0F6D54 7F0C2224 4600710D */   trunc.w.s $f4, $f14
/* 0F6D58 7F0C2228 460C7032 */  c.eq.s $f14, $f12
/* 0F6D5C 7F0C222C 00000000 */  nop   
/* 0F6D60 7F0C2230 4502000E */  bc1fl .L7F0C226C
/* 0F6D64 7F0C2234 4600618D */   trunc.w.s $f6, $f12
/* 0F6D68 7F0C2238 E7AC0024 */  swc1  $f12, 0x24($sp)
/* 0F6D6C 7F0C223C 0C002914 */  jal   get_random_value
/* 0F6D70 7F0C2240 E7AE0028 */   swc1  $f14, 0x28($sp)
/* 0F6D74 7F0C2244 304E0001 */  andi  $t6, $v0, 1
/* 0F6D78 7F0C2248 C7AC0024 */  lwc1  $f12, 0x24($sp)
/* 0F6D7C 7F0C224C 11C00006 */  beqz  $t6, .L7F0C2268
/* 0F6D80 7F0C2250 C7AE0028 */   lwc1  $f14, 0x28($sp)
/* 0F6D84 7F0C2254 4600710D */  trunc.w.s $f4, $f14
.L7F0C2258:
/* 0F6D88 7F0C2258 24040001 */  li    $a0, 1
/* 0F6D8C 7F0C225C 44032000 */  mfc1  $v1, $f4
/* 0F6D90 7F0C2260 10000006 */  b     .L7F0C227C
/* 0F6D94 7F0C2264 8FB90020 */   lw    $t9, 0x20($sp)
.L7F0C2268:
/* 0F6D98 7F0C2268 4600618D */  trunc.w.s $f6, $f12
.L7F0C226C:
/* 0F6D9C 7F0C226C 00002025 */  move  $a0, $zero
/* 0F6DA0 7F0C2270 44033000 */  mfc1  $v1, $f6
/* 0F6DA4 7F0C2274 00000000 */  nop   
/* 0F6DA8 7F0C2278 8FB90020 */  lw    $t9, 0x20($sp)
.L7F0C227C:
/* 0F6DAC 7F0C227C 2B210003 */  slti  $at, $t9, 3
/* 0F6DB0 7F0C2280 5420002E */  bnezl $at, .L7F0C233C
/* 0F6DB4 7F0C2284 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F6DB8 7F0C2288 44834000 */  mtc1  $v1, $f8
/* 0F6DBC 7F0C228C C7AA002C */  lwc1  $f10, 0x2c($sp)
/* 0F6DC0 7F0C2290 46804020 */  cvt.s.w $f0, $f8
/* 0F6DC4 7F0C2294 460A003C */  c.lt.s $f0, $f10
/* 0F6DC8 7F0C2298 00000000 */  nop   
/* 0F6DCC 7F0C229C 4503000D */  bc1tl .L7F0C22D4
/* 0F6DD0 7F0C22A0 C7B0002C */   lwc1  $f16, 0x2c($sp)
/* 0F6DD4 7F0C22A4 46005032 */  c.eq.s $f10, $f0
/* 0F6DD8 7F0C22A8 00000000 */  nop   
/* 0F6DDC 7F0C22AC 4502000E */  bc1fl .L7F0C22E8
/* 0F6DE0 7F0C22B0 8FAA0020 */   lw    $t2, 0x20($sp)
/* 0F6DE4 7F0C22B4 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0F6DE8 7F0C22B8 0C002914 */  jal   get_random_value
/* 0F6DEC 7F0C22BC AFA40018 */   sw    $a0, 0x18($sp)
/* 0F6DF0 7F0C22C0 30480001 */  andi  $t0, $v0, 1
/* 0F6DF4 7F0C22C4 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F6DF8 7F0C22C8 11000006 */  beqz  $t0, .L7F0C22E4
/* 0F6DFC 7F0C22CC 8FA40018 */   lw    $a0, 0x18($sp)
/* 0F6E00 7F0C22D0 C7B0002C */  lwc1  $f16, 0x2c($sp)
.L7F0C22D4:
/* 0F6E04 7F0C22D4 24040002 */  li    $a0, 2
/* 0F6E08 7F0C22D8 4600848D */  trunc.w.s $f18, $f16
/* 0F6E0C 7F0C22DC 44039000 */  mfc1  $v1, $f18
/* 0F6E10 7F0C22E0 00000000 */  nop   
.L7F0C22E4:
/* 0F6E14 7F0C22E4 8FAA0020 */  lw    $t2, 0x20($sp)
.L7F0C22E8:
/* 0F6E18 7F0C22E8 29410004 */  slti  $at, $t2, 4
/* 0F6E1C 7F0C22EC 54200013 */  bnezl $at, .L7F0C233C
/* 0F6E20 7F0C22F0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F6E24 7F0C22F4 44832000 */  mtc1  $v1, $f4
/* 0F6E28 7F0C22F8 C7A20030 */  lwc1  $f2, 0x30($sp)
/* 0F6E2C 7F0C22FC 46802020 */  cvt.s.w $f0, $f4
/* 0F6E30 7F0C2300 4602003C */  c.lt.s $f0, $f2
/* 0F6E34 7F0C2304 00000000 */  nop   
/* 0F6E38 7F0C2308 4503000B */  bc1tl .L7F0C2338
/* 0F6E3C 7F0C230C 24040003 */   li    $a0, 3
/* 0F6E40 7F0C2310 46001032 */  c.eq.s $f2, $f0
/* 0F6E44 7F0C2314 00000000 */  nop   
/* 0F6E48 7F0C2318 45020008 */  bc1fl .L7F0C233C
/* 0F6E4C 7F0C231C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F6E50 7F0C2320 0C002914 */  jal   get_random_value
/* 0F6E54 7F0C2324 AFA40018 */   sw    $a0, 0x18($sp)
/* 0F6E58 7F0C2328 304B0001 */  andi  $t3, $v0, 1
/* 0F6E5C 7F0C232C 11600002 */  beqz  $t3, .L7F0C2338
/* 0F6E60 7F0C2330 8FA40018 */   lw    $a0, 0x18($sp)
/* 0F6E64 7F0C2334 24040003 */  li    $a0, 3
.L7F0C2338:
/* 0F6E68 7F0C2338 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0C233C:
/* 0F6E6C 7F0C233C 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F6E70 7F0C2340 00801025 */  move  $v0, $a0
/* 0F6E74 7F0C2344 03E00008 */  jr    $ra
/* 0F6E78 7F0C2348 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C234C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C234C
/* 0F6E7C 7F0C234C 44856000 */  mtc1  $a1, $f12
/* 0F6E80 7F0C2350 44867000 */  mtc1  $a2, $f14
/* 0F6E84 7F0C2354 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F6E88 7F0C2358 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F6E8C 7F0C235C 460C703C */  c.lt.s $f14, $f12
/* 0F6E90 7F0C2360 AFA40020 */  sw    $a0, 0x20($sp)
/* 0F6E94 7F0C2364 AFA7002C */  sw    $a3, 0x2c($sp)
/* 0F6E98 7F0C2368 4503000D */  bc1tl .L7F0C23A0
/* 0F6E9C 7F0C236C 4600710D */   trunc.w.s $f4, $f14
/* 0F6EA0 7F0C2370 460C7032 */  c.eq.s $f14, $f12
/* 0F6EA4 7F0C2374 00000000 */  nop   
/* 0F6EA8 7F0C2378 4502000E */  bc1fl .L7F0C23B4
/* 0F6EAC 7F0C237C 4600618D */   trunc.w.s $f6, $f12
/* 0F6EB0 7F0C2380 E7AC0024 */  swc1  $f12, 0x24($sp)
/* 0F6EB4 7F0C2384 0C002914 */  jal   get_random_value
/* 0F6EB8 7F0C2388 E7AE0028 */   swc1  $f14, 0x28($sp)
/* 0F6EBC 7F0C238C 304E0001 */  andi  $t6, $v0, 1
/* 0F6EC0 7F0C2390 C7AC0024 */  lwc1  $f12, 0x24($sp)
/* 0F6EC4 7F0C2394 11C00006 */  beqz  $t6, .L7F0C23B0
/* 0F6EC8 7F0C2398 C7AE0028 */   lwc1  $f14, 0x28($sp)
/* 0F6ECC 7F0C239C 4600710D */  trunc.w.s $f4, $f14
.L7F0C23A0:
/* 0F6ED0 7F0C23A0 24040001 */  li    $a0, 1
/* 0F6ED4 7F0C23A4 44032000 */  mfc1  $v1, $f4
/* 0F6ED8 7F0C23A8 10000006 */  b     .L7F0C23C4
/* 0F6EDC 7F0C23AC 8FB90020 */   lw    $t9, 0x20($sp)
.L7F0C23B0:
/* 0F6EE0 7F0C23B0 4600618D */  trunc.w.s $f6, $f12
.L7F0C23B4:
/* 0F6EE4 7F0C23B4 00002025 */  move  $a0, $zero
/* 0F6EE8 7F0C23B8 44033000 */  mfc1  $v1, $f6
/* 0F6EEC 7F0C23BC 00000000 */  nop   
/* 0F6EF0 7F0C23C0 8FB90020 */  lw    $t9, 0x20($sp)
.L7F0C23C4:
/* 0F6EF4 7F0C23C4 2B210003 */  slti  $at, $t9, 3
/* 0F6EF8 7F0C23C8 5420002E */  bnezl $at, .L7F0C2484
/* 0F6EFC 7F0C23CC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F6F00 7F0C23D0 44834000 */  mtc1  $v1, $f8
/* 0F6F04 7F0C23D4 C7AA002C */  lwc1  $f10, 0x2c($sp)
/* 0F6F08 7F0C23D8 46804020 */  cvt.s.w $f0, $f8
/* 0F6F0C 7F0C23DC 4600503C */  c.lt.s $f10, $f0
/* 0F6F10 7F0C23E0 00000000 */  nop   
/* 0F6F14 7F0C23E4 4503000D */  bc1tl .L7F0C241C
/* 0F6F18 7F0C23E8 C7B0002C */   lwc1  $f16, 0x2c($sp)
/* 0F6F1C 7F0C23EC 46005032 */  c.eq.s $f10, $f0
/* 0F6F20 7F0C23F0 00000000 */  nop   
/* 0F6F24 7F0C23F4 4502000E */  bc1fl .L7F0C2430
/* 0F6F28 7F0C23F8 8FAA0020 */   lw    $t2, 0x20($sp)
/* 0F6F2C 7F0C23FC AFA3001C */  sw    $v1, 0x1c($sp)
/* 0F6F30 7F0C2400 0C002914 */  jal   get_random_value
/* 0F6F34 7F0C2404 AFA40018 */   sw    $a0, 0x18($sp)
/* 0F6F38 7F0C2408 30480001 */  andi  $t0, $v0, 1
/* 0F6F3C 7F0C240C 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F6F40 7F0C2410 11000006 */  beqz  $t0, .L7F0C242C
/* 0F6F44 7F0C2414 8FA40018 */   lw    $a0, 0x18($sp)
/* 0F6F48 7F0C2418 C7B0002C */  lwc1  $f16, 0x2c($sp)
.L7F0C241C:
/* 0F6F4C 7F0C241C 24040002 */  li    $a0, 2
/* 0F6F50 7F0C2420 4600848D */  trunc.w.s $f18, $f16
/* 0F6F54 7F0C2424 44039000 */  mfc1  $v1, $f18
/* 0F6F58 7F0C2428 00000000 */  nop   
.L7F0C242C:
/* 0F6F5C 7F0C242C 8FAA0020 */  lw    $t2, 0x20($sp)
.L7F0C2430:
/* 0F6F60 7F0C2430 29410004 */  slti  $at, $t2, 4
/* 0F6F64 7F0C2434 54200013 */  bnezl $at, .L7F0C2484
/* 0F6F68 7F0C2438 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F6F6C 7F0C243C 44832000 */  mtc1  $v1, $f4
/* 0F6F70 7F0C2440 C7A20030 */  lwc1  $f2, 0x30($sp)
/* 0F6F74 7F0C2444 46802020 */  cvt.s.w $f0, $f4
/* 0F6F78 7F0C2448 4600103C */  c.lt.s $f2, $f0
/* 0F6F7C 7F0C244C 00000000 */  nop   
/* 0F6F80 7F0C2450 4503000B */  bc1tl .L7F0C2480
/* 0F6F84 7F0C2454 24040003 */   li    $a0, 3
/* 0F6F88 7F0C2458 46001032 */  c.eq.s $f2, $f0
/* 0F6F8C 7F0C245C 00000000 */  nop   
/* 0F6F90 7F0C2460 45020008 */  bc1fl .L7F0C2484
/* 0F6F94 7F0C2464 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F6F98 7F0C2468 0C002914 */  jal   get_random_value
/* 0F6F9C 7F0C246C AFA40018 */   sw    $a0, 0x18($sp)
/* 0F6FA0 7F0C2470 304B0001 */  andi  $t3, $v0, 1
/* 0F6FA4 7F0C2474 11600002 */  beqz  $t3, .L7F0C2480
/* 0F6FA8 7F0C2478 8FA40018 */   lw    $a0, 0x18($sp)
/* 0F6FAC 7F0C247C 24040003 */  li    $a0, 3
.L7F0C2480:
/* 0F6FB0 7F0C2480 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0C2484:
/* 0F6FB4 7F0C2484 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F6FB8 7F0C2488 00801025 */  move  $v0, $a0
/* 0F6FBC 7F0C248C 03E00008 */  jr    $ra
/* 0F6FC0 7F0C2490 00000000 */   nop   
)
#endif





void pauseAndLockControls(void) {
    set_controls_locked_flag(1);
    is_paused = 1;
}






#ifdef NONMATCHING
void sub_GAME_7F0C24BC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C24BC
/* 0F6FEC 7F0C24BC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F6FF0 7F0C24C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F6FF4 7F0C24C4 0FC26919 */  jal   get_num_players
/* 0F6FF8 7F0C24C8 00000000 */   nop   
/* 0F6FFC 7F0C24CC 24010001 */  li    $at, 1
/* 0F7000 7F0C24D0 14410003 */  bne   $v0, $at, .L7F0C24E0
/* 0F7004 7F0C24D4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F7008 7F0C24D8 1000000F */  b     .L7F0C2518
/* 0F700C 7F0C24DC 24020001 */   li    $v0, 1
.L7F0C24E0:
/* 0F7010 7F0C24E0 3C0E8009 */  lui   $t6, %hi(stop_play_flag) 
/* 0F7014 7F0C24E4 8DCEC700 */  lw    $t6, %lo(stop_play_flag)($t6)
/* 0F7018 7F0C24E8 3C0F8008 */  lui   $t7, %hi(pPlayer) 
/* 0F701C 7F0C24EC 11C00003 */  beqz  $t6, .L7F0C24FC
/* 0F7020 7F0C24F0 00000000 */   nop   
/* 0F7024 7F0C24F4 10000008 */  b     .L7F0C2518
/* 0F7028 7F0C24F8 00001025 */   move  $v0, $zero
.L7F0C24FC:
/* 0F702C 7F0C24FC 8DEFA0B0 */  lw    $t7, %lo(pPlayer)($t7)
/* 0F7030 7F0C2500 24020001 */  li    $v0, 1
/* 0F7034 7F0C2504 8DF829C4 */  lw    $t8, 0x29c4($t7)
/* 0F7038 7F0C2508 13000003 */  beqz  $t8, .L7F0C2518
/* 0F703C 7F0C250C 00000000 */   nop   
/* 0F7040 7F0C2510 10000001 */  b     .L7F0C2518
/* 0F7044 7F0C2514 00001025 */   move  $v0, $zero
.L7F0C2518:
/* 0F7048 7F0C2518 03E00008 */  jr    $ra
/* 0F704C 7F0C251C 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





void set_stopplay_flag(void) {
    stop_play_flag = 1;
}






#ifdef NONMATCHING
void sub_GAME_7F0C2530(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_8005BC80
.word 0x4852f000 /*216000.0*/
glabel D_8005BC84
.word 0x47c35000 /*100000.0*/
.text
glabel sub_GAME_7F0C2530
/* 0F7060 7F0C2530 27BDFE98 */  addiu $sp, $sp, -0x168
/* 0F7064 7F0C2534 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0F7068 7F0C2538 AFB10024 */  sw    $s1, 0x24($sp)
/* 0F706C 7F0C253C 00808825 */  move  $s1, $a0
/* 0F7070 7F0C2540 AFBE0040 */  sw    $fp, 0x40($sp)
/* 0F7074 7F0C2544 AFB7003C */  sw    $s7, 0x3c($sp)
/* 0F7078 7F0C2548 AFB60038 */  sw    $s6, 0x38($sp)
/* 0F707C 7F0C254C AFB50034 */  sw    $s5, 0x34($sp)
/* 0F7080 7F0C2550 AFB40030 */  sw    $s4, 0x30($sp)
/* 0F7084 7F0C2554 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0F7088 7F0C2558 AFB20028 */  sw    $s2, 0x28($sp)
/* 0F708C 7F0C255C 0FC26919 */  jal   get_num_players
/* 0F7090 7F0C2560 AFB00020 */   sw    $s0, 0x20($sp)
/* 0F7094 7F0C2564 0FC22FEE */  jal   sub_GAME_7F08BFB8
/* 0F7098 7F0C2568 0040F025 */   move  $fp, $v0
/* 0F709C 7F0C256C 0C002449 */  jal   sfx_c_70009124
/* 0F70A0 7F0C2570 00408025 */   move  $s0, $v0
/* 0F70A4 7F0C2574 0FC3030F */  jal   set_missionstate
/* 0F70A8 7F0C2578 00002025 */   move  $a0, $zero
/* 0F70AC 7F0C257C 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F70B0 7F0C2580 00000000 */   nop   
/* 0F70B4 7F0C2584 0C001C0F */  jal   musicTrack1Vol
/* 0F70B8 7F0C2588 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F70BC 7F0C258C 3C018002 */  lui   $at, %hi(music1_playing)
/* 0F70C0 7F0C2590 AC20434C */  sw    $zero, %lo(music1_playing)($at)
/* 0F70C4 7F0C2594 0C001B9F */  jal   musicTrack1Play
/* 0F70C8 7F0C2598 2404002C */   li    $a0, 44
/* 0F70CC 7F0C259C 0FC30925 */  jal   pauseAndLockControls
/* 0F70D0 7F0C25A0 00000000 */   nop   
/* 0F70D4 7F0C25A4 12200005 */  beqz  $s1, .L7F0C25BC
/* 0F70D8 7F0C25A8 24180001 */   li    $t8, 1
/* 0F70DC 7F0C25AC 240E012C */  li    $t6, 300
/* 0F70E0 7F0C25B0 3C018009 */  lui   $at, %hi(is_gameover_flag)
/* 0F70E4 7F0C25B4 10000004 */  b     .L7F0C25C8
/* 0F70E8 7F0C25B8 AC2EC704 */   sw    $t6, %lo(is_gameover_flag)($at)
.L7F0C25BC:
/* 0F70EC 7F0C25BC 240F0001 */  li    $t7, 1
/* 0F70F0 7F0C25C0 3C018009 */  lui   $at, %hi(is_gameover_flag)
/* 0F70F4 7F0C25C4 AC2FC704 */  sw    $t7, %lo(is_gameover_flag)($at)
.L7F0C25C8:
/* 0F70F8 7F0C25C8 3C018009 */  lui   $at, %hi(time_trigger_alt_gameover_msg)
/* 0F70FC 7F0C25CC AC38C710 */  sw    $t8, %lo(time_trigger_alt_gameover_msg)($at)
/* 0F7100 7F0C25D0 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C714)
/* 0F7104 7F0C25D4 24190014 */  li    $t9, 20
/* 0F7108 7F0C25D8 AC39C714 */  sw    $t9, %lo(dword_CODE_bss_8008C714)($at)
/* 0F710C 7F0C25DC 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C708)
/* 0F7110 7F0C25E0 AC20C708 */  sw    $zero, %lo(dword_CODE_bss_8008C708)($at)
/* 0F7114 7F0C25E4 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C70C)
/* 0F7118 7F0C25E8 0FC26C54 */  jal   get_cur_playernum
/* 0F711C 7F0C25EC AC20C70C */   sw    $zero, %lo(dword_CODE_bss_8008C70C)($at)
/* 0F7120 7F0C25F0 AFA20150 */  sw    $v0, 0x150($sp)
/* 0F7124 7F0C25F4 1BC00078 */  blez  $fp, .L7F0C27D8
/* 0F7128 7F0C25F8 0000B025 */   move  $s6, $zero
/* 0F712C 7F0C25FC 26080001 */  addiu $t0, $s0, 1
/* 0F7130 7F0C2600 44882000 */  mtc1  $t0, $f4
/* 0F7134 7F0C2604 3C018006 */  lui   $at, %hi(D_8005BC80)
/* 0F7138 7F0C2608 C428BC80 */  lwc1  $f8, %lo(D_8005BC80)($at)
/* 0F713C 7F0C260C 468021A0 */  cvt.s.w $f6, $f4
/* 0F7140 7F0C2610 3C148008 */  lui   $s4, %hi(player1_player_data)
/* 0F7144 7F0C2614 3C158008 */  lui   $s5, %hi(pPlayer)
/* 0F7148 7F0C2618 26B5A0B0 */  addiu $s5, %lo(pPlayer) # addiu $s5, $s5, -0x5f50
/* 0F714C 7F0C261C 26949EF0 */  addiu $s4, %lo(player1_player_data) # addiu $s4, $s4, -0x6110
/* 0F7150 7F0C2620 27B2006C */  addiu $s2, $sp, 0x6c
/* 0F7154 7F0C2624 46083283 */  div.s $f10, $f6, $f8
/* 0F7158 7F0C2628 24170003 */  li    $s7, 3
/* 0F715C 7F0C262C E7AA0048 */  swc1  $f10, 0x48($sp)
.L7F0C2630:
/* 0F7160 7F0C2630 02C02025 */  move  $a0, $s6
/* 0F7164 7F0C2634 0FC26C43 */  jal   set_cur_player
/* 0F7168 7F0C2638 00008825 */   move  $s1, $zero
/* 0F716C 7F0C263C 8EAA0000 */  lw    $t2, ($s5)
/* 0F7170 7F0C2640 24090001 */  li    $t1, 1
/* 0F7174 7F0C2644 27A40154 */  addiu $a0, $sp, 0x154
/* 0F7178 7F0C2648 AD4929C4 */  sw    $t1, 0x29c4($t2)
/* 0F717C 7F0C264C 8EAB0000 */  lw    $t3, ($s5)
/* 0F7180 7F0C2650 27A50158 */  addiu $a1, $sp, 0x158
/* 0F7184 7F0C2654 AD7729C8 */  sw    $s7, 0x29c8($t3)
/* 0F7188 7F0C2658 8EAC0000 */  lw    $t4, ($s5)
/* 0F718C 7F0C265C AD802A10 */  sw    $zero, 0x2a10($t4)
/* 0F7190 7F0C2660 8EAD0000 */  lw    $t5, ($s5)
/* 0F7194 7F0C2664 0FC236C2 */  jal   sub_GAME_7F08DB08
/* 0F7198 7F0C2668 ADA02A14 */   sw    $zero, 0x2a14($t5)
/* 0F719C 7F0C266C 8FA40154 */  lw    $a0, 0x154($sp)
/* 0F71A0 7F0C2670 0FC075A0 */  jal   store_favorite_weapon_current_player
/* 0F71A4 7F0C2674 8FA50158 */   lw    $a1, 0x158($sp)
/* 0F71A8 7F0C2678 0FC1A9D0 */  jal   get_curplayer_shot_register
/* 0F71AC 7F0C267C 00002025 */   move  $a0, $zero
/* 0F71B0 7F0C2680 AE420000 */  sw    $v0, ($s2)
/* 0F71B4 7F0C2684 0FC1A9D0 */  jal   get_curplayer_shot_register
/* 0F71B8 7F0C2688 24040001 */   li    $a0, 1
/* 0F71BC 7F0C268C AE420004 */  sw    $v0, 4($s2)
/* 0F71C0 7F0C2690 AE400008 */  sw    $zero, 8($s2)
/* 0F71C4 7F0C2694 AE40000C */  sw    $zero, 0xc($s2)
/* 0F71C8 7F0C2698 0FC040A4 */  jal   get_selected_num_players
/* 0F71CC 7F0C269C AE400010 */   sw    $zero, 0x10($s2)
/* 0F71D0 7F0C26A0 18400023 */  blez  $v0, .L7F0C2730
/* 0F71D4 7F0C26A4 001170C0 */   sll   $t6, $s1, 3
/* 0F71D8 7F0C26A8 001640C0 */  sll   $t0, $s6, 3
/* 0F71DC 7F0C26AC 01164023 */  subu  $t0, $t0, $s6
/* 0F71E0 7F0C26B0 01D17023 */  subu  $t6, $t6, $s1
/* 0F71E4 7F0C26B4 3C198008 */  lui   $t9, %hi(player1_player_data) 
/* 0F71E8 7F0C26B8 27399EF0 */  addiu $t9, %lo(player1_player_data) # addiu $t9, $t9, -0x6110
/* 0F71EC 7F0C26BC 000E7100 */  sll   $t6, $t6, 4
/* 0F71F0 7F0C26C0 00084100 */  sll   $t0, $t0, 4
/* 0F71F4 7F0C26C4 00167880 */  sll   $t7, $s6, 2
/* 0F71F8 7F0C26C8 00114880 */  sll   $t1, $s1, 2
/* 0F71FC 7F0C26CC 01095021 */  addu  $t2, $t0, $t1
/* 0F7200 7F0C26D0 01CFC021 */  addu  $t8, $t6, $t7
/* 0F7204 7F0C26D4 03199821 */  addu  $s3, $t8, $t9
/* 0F7208 7F0C26D8 01598021 */  addu  $s0, $t2, $t9
/* 0F720C 7F0C26DC 8E4B000C */  lw    $t3, 0xc($s2)
.L7F0C26E0:
/* 0F7210 7F0C26E0 8E6C0024 */  lw    $t4, 0x24($s3)
/* 0F7214 7F0C26E4 26730070 */  addiu $s3, $s3, 0x70
/* 0F7218 7F0C26E8 016C6821 */  addu  $t5, $t3, $t4
/* 0F721C 7F0C26EC 16D10006 */  bne   $s6, $s1, .L7F0C2708
/* 0F7220 7F0C26F0 AE4D000C */   sw    $t5, 0xc($s2)
/* 0F7224 7F0C26F4 8E4E0010 */  lw    $t6, 0x10($s2)
/* 0F7228 7F0C26F8 8E0F0024 */  lw    $t7, 0x24($s0)
/* 0F722C 7F0C26FC 01CFC021 */  addu  $t8, $t6, $t7
/* 0F7230 7F0C2700 10000005 */  b     .L7F0C2718
/* 0F7234 7F0C2704 AE580010 */   sw    $t8, 0x10($s2)
.L7F0C2708:
/* 0F7238 7F0C2708 8E480008 */  lw    $t0, 8($s2)
/* 0F723C 7F0C270C 8E090024 */  lw    $t1, 0x24($s0)
/* 0F7240 7F0C2710 01095021 */  addu  $t2, $t0, $t1
/* 0F7244 7F0C2714 AE4A0008 */  sw    $t2, 8($s2)
.L7F0C2718:
/* 0F7248 7F0C2718 26310001 */  addiu $s1, $s1, 1
/* 0F724C 7F0C271C 0FC040A4 */  jal   get_selected_num_players
/* 0F7250 7F0C2720 26100004 */   addiu $s0, $s0, 4
/* 0F7254 7F0C2724 0222082A */  slt   $at, $s1, $v0
/* 0F7258 7F0C2728 5420FFED */  bnezl $at, .L7F0C26E0
/* 0F725C 7F0C272C 8E4B000C */   lw    $t3, 0xc($s2)
.L7F0C2730:
/* 0F7260 7F0C2730 8E590008 */  lw    $t9, 8($s2)
/* 0F7264 7F0C2734 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F7268 7F0C2738 44811000 */  mtc1  $at, $f2
/* 0F726C 7F0C273C 44998000 */  mtc1  $t9, $f16
/* 0F7270 7F0C2740 3C0142C8 */  li    $at, 0x42C80000 # 100.000000
/* 0F7274 7F0C2744 44812000 */  mtc1  $at, $f4
/* 0F7278 7F0C2748 468084A0 */  cvt.s.w $f18, $f16
/* 0F727C 7F0C274C 8E4B0000 */  lw    $t3, ($s2)
/* 0F7280 7F0C2750 8E4C000C */  lw    $t4, 0xc($s2)
/* 0F7284 7F0C2754 8E8D003C */  lw    $t5, 0x3c($s4)
/* 0F7288 7F0C2758 448B3000 */  mtc1  $t3, $f6
/* 0F728C 7F0C275C 8E8E0034 */  lw    $t6, 0x34($s4)
/* 0F7290 7F0C2760 46049002 */  mul.s $f0, $f18, $f4
/* 0F7294 7F0C2764 448C9000 */  mtc1  $t4, $f18
/* 0F7298 7F0C2768 3C018006 */  lui   $at, %hi(D_8005BC84)
/* 0F729C 7F0C276C AE4D001C */  sw    $t5, 0x1c($s2)
/* 0F72A0 7F0C2770 AE4E0020 */  sw    $t6, 0x20($s2)
/* 0F72A4 7F0C2774 8E8F004C */  lw    $t7, 0x4c($s4)
/* 0F72A8 7F0C2778 46803220 */  cvt.s.w $f8, $f6
/* 0F72AC 7F0C277C 8E980050 */  lw    $t8, 0x50($s4)
/* 0F72B0 7F0C2780 26D60001 */  addiu $s6, $s6, 1
/* 0F72B4 7F0C2784 26520038 */  addiu $s2, $s2, 0x38
/* 0F72B8 7F0C2788 26940070 */  addiu $s4, $s4, 0x70
/* 0F72BC 7F0C278C 46809120 */  cvt.s.w $f4, $f18
/* 0F72C0 7F0C2790 46024280 */  add.s $f10, $f8, $f2
/* 0F72C4 7F0C2794 46022180 */  add.s $f6, $f4, $f2
/* 0F72C8 7F0C2798 460A0403 */  div.s $f16, $f0, $f10
/* 0F72CC 7F0C279C C68AFFC8 */  lwc1  $f10, -0x38($s4)
/* 0F72D0 7F0C27A0 46060203 */  div.s $f8, $f0, $f6
/* 0F72D4 7F0C27A4 E650FFDC */  swc1  $f16, -0x24($s2)
/* 0F72D8 7F0C27A8 E648FFE0 */  swc1  $f8, -0x20($s2)
/* 0F72DC 7F0C27AC C430BC84 */  lwc1  $f16, %lo(D_8005BC84)($at)
/* 0F72E0 7F0C27B0 C7A40048 */  lwc1  $f4, 0x48($sp)
/* 0F72E4 7F0C27B4 C688FFD0 */  lwc1  $f8, -0x30($s4)
/* 0F72E8 7F0C27B8 46105483 */  div.s $f18, $f10, $f16
/* 0F72EC 7F0C27BC AE40FFF4 */  sw    $zero, -0xc($s2)
/* 0F72F0 7F0C27C0 AE4FFFF8 */  sw    $t7, -8($s2)
/* 0F72F4 7F0C27C4 AE58FFFC */  sw    $t8, -4($s2)
/* 0F72F8 7F0C27C8 E648FFF0 */  swc1  $f8, -0x10($s2)
/* 0F72FC 7F0C27CC 46049183 */  div.s $f6, $f18, $f4
/* 0F7300 7F0C27D0 16DEFF97 */  bne   $s6, $fp, .L7F0C2630
/* 0F7304 7F0C27D4 E646FFEC */   swc1  $f6, -0x14($s2)
.L7F0C27D8:
/* 0F7308 7F0C27D8 24170003 */  li    $s7, 3
/* 0F730C 7F0C27DC 0FC26C43 */  jal   set_cur_player
/* 0F7310 7F0C27E0 8FA40150 */   lw    $a0, 0x150($sp)
/* 0F7314 7F0C27E4 8FA80124 */  lw    $t0, 0x124($sp)
/* 0F7318 7F0C27E8 03C02025 */  move  $a0, $fp
/* 0F731C 7F0C27EC 8FA5007C */  lw    $a1, 0x7c($sp)
/* 0F7320 7F0C27F0 8FA600B4 */  lw    $a2, 0xb4($sp)
/* 0F7324 7F0C27F4 8FA700EC */  lw    $a3, 0xec($sp)
/* 0F7328 7F0C27F8 0FC30809 */  jal   sub_GAME_7F0C2024
/* 0F732C 7F0C27FC AFA80010 */   sw    $t0, 0x10($sp)
/* 0F7330 7F0C2800 24130038 */  li    $s3, 56
/* 0F7334 7F0C2804 00530019 */  multu $v0, $s3
/* 0F7338 7F0C2808 27B1006C */  addiu $s1, $sp, 0x6c
/* 0F733C 7F0C280C 03C02025 */  move  $a0, $fp
/* 0F7340 7F0C2810 00004812 */  mflo  $t1
/* 0F7344 7F0C2814 02298021 */  addu  $s0, $s1, $t1
/* 0F7348 7F0C2818 8E0A0010 */  lw    $t2, 0x10($s0)
/* 0F734C 7F0C281C 59400005 */  blezl $t2, .L7F0C2834
/* 0F7350 7F0C2820 8FAC0114 */   lw    $t4, 0x114($sp)
/* 0F7354 7F0C2824 8E19002C */  lw    $t9, 0x2c($s0)
/* 0F7358 7F0C2828 372B0001 */  ori   $t3, $t9, 1
/* 0F735C 7F0C282C AE0B002C */  sw    $t3, 0x2c($s0)
/* 0F7360 7F0C2830 8FAC0114 */  lw    $t4, 0x114($sp)
.L7F0C2834:
/* 0F7364 7F0C2834 8FA5006C */  lw    $a1, 0x6c($sp)
/* 0F7368 7F0C2838 8FA600A4 */  lw    $a2, 0xa4($sp)
/* 0F736C 7F0C283C 8FA700DC */  lw    $a3, 0xdc($sp)
/* 0F7370 7F0C2840 0FC30845 */  jal   sub_GAME_7F0C2114
/* 0F7374 7F0C2844 AFAC0010 */   sw    $t4, 0x10($sp)
/* 0F7378 7F0C2848 00530019 */  multu $v0, $s3
/* 0F737C 7F0C284C 03C02025 */  move  $a0, $fp
/* 0F7380 7F0C2850 00006812 */  mflo  $t5
/* 0F7384 7F0C2854 022D8021 */  addu  $s0, $s1, $t5
/* 0F7388 7F0C2858 8E0E0000 */  lw    $t6, ($s0)
/* 0F738C 7F0C285C 29C10064 */  slti  $at, $t6, 0x64
/* 0F7390 7F0C2860 50200005 */  beql  $at, $zero, .L7F0C2878
/* 0F7394 7F0C2864 C7AA013C */   lwc1  $f10, 0x13c($sp)
/* 0F7398 7F0C2868 8E0F002C */  lw    $t7, 0x2c($s0)
/* 0F739C 7F0C286C 35F80002 */  ori   $t8, $t7, 2
/* 0F73A0 7F0C2870 AE18002C */  sw    $t8, 0x2c($s0)
/* 0F73A4 7F0C2874 C7AA013C */  lwc1  $f10, 0x13c($sp)
.L7F0C2878:
/* 0F73A8 7F0C2878 8FA50094 */  lw    $a1, 0x94($sp)
/* 0F73AC 7F0C287C 8FA600CC */  lw    $a2, 0xcc($sp)
/* 0F73B0 7F0C2880 8FA70104 */  lw    $a3, 0x104($sp)
/* 0F73B4 7F0C2884 0FC308D3 */  jal   sub_GAME_7F0C234C
/* 0F73B8 7F0C2888 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0F73BC 7F0C288C 00530019 */  multu $v0, $s3
/* 0F73C0 7F0C2890 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0F73C4 7F0C2894 44818000 */  mtc1  $at, $f16
/* 0F73C8 7F0C2898 03C02025 */  move  $a0, $fp
/* 0F73CC 7F0C289C 00004012 */  mflo  $t0
/* 0F73D0 7F0C28A0 02288021 */  addu  $s0, $s1, $t0
/* 0F73D4 7F0C28A4 C6120028 */  lwc1  $f18, 0x28($s0)
/* 0F73D8 7F0C28A8 4610903E */  c.le.s $f18, $f16
/* 0F73DC 7F0C28AC 00000000 */  nop   
/* 0F73E0 7F0C28B0 45020005 */  bc1fl .L7F0C28C8
/* 0F73E4 7F0C28B4 C7A4013C */   lwc1  $f4, 0x13c($sp)
/* 0F73E8 7F0C28B8 8E09002C */  lw    $t1, 0x2c($s0)
/* 0F73EC 7F0C28BC 352A0004 */  ori   $t2, $t1, 4
/* 0F73F0 7F0C28C0 AE0A002C */  sw    $t2, 0x2c($s0)
/* 0F73F4 7F0C28C4 C7A4013C */  lwc1  $f4, 0x13c($sp)
.L7F0C28C8:
/* 0F73F8 7F0C28C8 8FA50094 */  lw    $a1, 0x94($sp)
/* 0F73FC 7F0C28CC 8FA600CC */  lw    $a2, 0xcc($sp)
/* 0F7400 7F0C28D0 8FA70104 */  lw    $a3, 0x104($sp)
/* 0F7404 7F0C28D4 0FC30881 */  jal   sub_GAME_7F0C2204
/* 0F7408 7F0C28D8 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0F740C 7F0C28DC 00530019 */  multu $v0, $s3
/* 0F7410 7F0C28E0 3C0140C0 */  li    $at, 0x40C00000 # 6.000000
/* 0F7414 7F0C28E4 44813000 */  mtc1  $at, $f6
/* 0F7418 7F0C28E8 03C02025 */  move  $a0, $fp
/* 0F741C 7F0C28EC 0000C812 */  mflo  $t9
/* 0F7420 7F0C28F0 02398021 */  addu  $s0, $s1, $t9
/* 0F7424 7F0C28F4 C6080028 */  lwc1  $f8, 0x28($s0)
/* 0F7428 7F0C28F8 4608303C */  c.lt.s $f6, $f8
/* 0F742C 7F0C28FC 00000000 */  nop   
/* 0F7430 7F0C2900 45020005 */  bc1fl .L7F0C2918
/* 0F7434 7F0C2904 8FAD0118 */   lw    $t5, 0x118($sp)
/* 0F7438 7F0C2908 8E0B002C */  lw    $t3, 0x2c($s0)
/* 0F743C 7F0C290C 356C0008 */  ori   $t4, $t3, 8
/* 0F7440 7F0C2910 AE0C002C */  sw    $t4, 0x2c($s0)
/* 0F7444 7F0C2914 8FAD0118 */  lw    $t5, 0x118($sp)
.L7F0C2918:
/* 0F7448 7F0C2918 8FA50070 */  lw    $a1, 0x70($sp)
/* 0F744C 7F0C291C 8FA600A8 */  lw    $a2, 0xa8($sp)
/* 0F7450 7F0C2920 8FA700E0 */  lw    $a3, 0xe0($sp)
/* 0F7454 7F0C2924 0FC30809 */  jal   sub_GAME_7F0C2024
/* 0F7458 7F0C2928 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0F745C 7F0C292C 00530019 */  multu $v0, $s3
/* 0F7460 7F0C2930 03C02025 */  move  $a0, $fp
/* 0F7464 7F0C2934 00007012 */  mflo  $t6
/* 0F7468 7F0C2938 022E8021 */  addu  $s0, $s1, $t6
/* 0F746C 7F0C293C 8E0F0004 */  lw    $t7, 4($s0)
/* 0F7470 7F0C2940 59E00005 */  blezl $t7, .L7F0C2958
/* 0F7474 7F0C2944 C7AA0128 */   lwc1  $f10, 0x128($sp)
/* 0F7478 7F0C2948 8E18002C */  lw    $t8, 0x2c($s0)
/* 0F747C 7F0C294C 37080010 */  ori   $t0, $t8, 0x10
/* 0F7480 7F0C2950 AE08002C */  sw    $t0, 0x2c($s0)
/* 0F7484 7F0C2954 C7AA0128 */  lwc1  $f10, 0x128($sp)
.L7F0C2958:
/* 0F7488 7F0C2958 8FA50080 */  lw    $a1, 0x80($sp)
/* 0F748C 7F0C295C 8FA600B8 */  lw    $a2, 0xb8($sp)
/* 0F7490 7F0C2960 8FA700F0 */  lw    $a3, 0xf0($sp)
/* 0F7494 7F0C2964 0FC30881 */  jal   sub_GAME_7F0C2204
/* 0F7498 7F0C2968 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0F749C 7F0C296C 00530019 */  multu $v0, $s3
/* 0F74A0 7F0C2970 44808000 */  mtc1  $zero, $f16
/* 0F74A4 7F0C2974 03C02025 */  move  $a0, $fp
/* 0F74A8 7F0C2978 00004812 */  mflo  $t1
/* 0F74AC 7F0C297C 02298021 */  addu  $s0, $s1, $t1
/* 0F74B0 7F0C2980 C6120014 */  lwc1  $f18, 0x14($s0)
/* 0F74B4 7F0C2984 4612803C */  c.lt.s $f16, $f18
/* 0F74B8 7F0C2988 00000000 */  nop   
/* 0F74BC 7F0C298C 45020005 */  bc1fl .L7F0C29A4
/* 0F74C0 7F0C2990 C7A4012C */   lwc1  $f4, 0x12c($sp)
/* 0F74C4 7F0C2994 8E0A002C */  lw    $t2, 0x2c($s0)
/* 0F74C8 7F0C2998 35590020 */  ori   $t9, $t2, 0x20
/* 0F74CC 7F0C299C AE19002C */  sw    $t9, 0x2c($s0)
/* 0F74D0 7F0C29A0 C7A4012C */  lwc1  $f4, 0x12c($sp)
.L7F0C29A4:
/* 0F74D4 7F0C29A4 8FA50084 */  lw    $a1, 0x84($sp)
/* 0F74D8 7F0C29A8 8FA600BC */  lw    $a2, 0xbc($sp)
/* 0F74DC 7F0C29AC 8FA700F4 */  lw    $a3, 0xf4($sp)
/* 0F74E0 7F0C29B0 0FC30881 */  jal   sub_GAME_7F0C2204
/* 0F74E4 7F0C29B4 E7A40010 */   swc1  $f4, 0x10($sp)
/* 0F74E8 7F0C29B8 00530019 */  multu $v0, $s3
/* 0F74EC 7F0C29BC 44803000 */  mtc1  $zero, $f6
/* 0F74F0 7F0C29C0 03C02025 */  move  $a0, $fp
/* 0F74F4 7F0C29C4 00005812 */  mflo  $t3
/* 0F74F8 7F0C29C8 022B8021 */  addu  $s0, $s1, $t3
/* 0F74FC 7F0C29CC C6080018 */  lwc1  $f8, 0x18($s0)
/* 0F7500 7F0C29D0 4608303C */  c.lt.s $f6, $f8
/* 0F7504 7F0C29D4 00000000 */  nop   
/* 0F7508 7F0C29D8 45020005 */  bc1fl .L7F0C29F0
/* 0F750C 7F0C29DC C7AA012C */   lwc1  $f10, 0x12c($sp)
/* 0F7510 7F0C29E0 8E0C002C */  lw    $t4, 0x2c($s0)
/* 0F7514 7F0C29E4 358D0040 */  ori   $t5, $t4, 0x40
/* 0F7518 7F0C29E8 AE0D002C */  sw    $t5, 0x2c($s0)
/* 0F751C 7F0C29EC C7AA012C */  lwc1  $f10, 0x12c($sp)
.L7F0C29F0:
/* 0F7520 7F0C29F0 8FA50084 */  lw    $a1, 0x84($sp)
/* 0F7524 7F0C29F4 8FA600BC */  lw    $a2, 0xbc($sp)
/* 0F7528 7F0C29F8 8FA700F4 */  lw    $a3, 0xf4($sp)
/* 0F752C 7F0C29FC 0FC308D3 */  jal   sub_GAME_7F0C234C
/* 0F7530 7F0C2A00 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 0F7534 7F0C2A04 00530019 */  multu $v0, $s3
/* 0F7538 7F0C2A08 03C02025 */  move  $a0, $fp
/* 0F753C 7F0C2A0C 00007012 */  mflo  $t6
/* 0F7540 7F0C2A10 022E8021 */  addu  $s0, $s1, $t6
/* 0F7544 7F0C2A14 8E0F002C */  lw    $t7, 0x2c($s0)
/* 0F7548 7F0C2A18 35F80080 */  ori   $t8, $t7, 0x80
/* 0F754C 7F0C2A1C AE18002C */  sw    $t8, 0x2c($s0)
/* 0F7550 7F0C2A20 8FA80134 */  lw    $t0, 0x134($sp)
/* 0F7554 7F0C2A24 8FA700FC */  lw    $a3, 0xfc($sp)
/* 0F7558 7F0C2A28 8FA600C4 */  lw    $a2, 0xc4($sp)
/* 0F755C 7F0C2A2C 8FA5008C */  lw    $a1, 0x8c($sp)
/* 0F7560 7F0C2A30 0FC30845 */  jal   sub_GAME_7F0C2114
/* 0F7564 7F0C2A34 AFA80010 */   sw    $t0, 0x10($sp)
/* 0F7568 7F0C2A38 00530019 */  multu $v0, $s3
/* 0F756C 7F0C2A3C 03C02025 */  move  $a0, $fp
/* 0F7570 7F0C2A40 00004812 */  mflo  $t1
/* 0F7574 7F0C2A44 02298021 */  addu  $s0, $s1, $t1
/* 0F7578 7F0C2A48 8E0A002C */  lw    $t2, 0x2c($s0)
/* 0F757C 7F0C2A4C 35590100 */  ori   $t9, $t2, 0x100
/* 0F7580 7F0C2A50 AE19002C */  sw    $t9, 0x2c($s0)
/* 0F7584 7F0C2A54 C7B00138 */  lwc1  $f16, 0x138($sp)
/* 0F7588 7F0C2A58 8FA70100 */  lw    $a3, 0x100($sp)
/* 0F758C 7F0C2A5C 8FA600C8 */  lw    $a2, 0xc8($sp)
/* 0F7590 7F0C2A60 8FA50090 */  lw    $a1, 0x90($sp)
/* 0F7594 7F0C2A64 0FC30881 */  jal   sub_GAME_7F0C2204
/* 0F7598 7F0C2A68 E7B00010 */   swc1  $f16, 0x10($sp)
/* 0F759C 7F0C2A6C 00530019 */  multu $v0, $s3
/* 0F75A0 7F0C2A70 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0F75A4 7F0C2A74 44819000 */  mtc1  $at, $f18
/* 0F75A8 7F0C2A78 03C02025 */  move  $a0, $fp
/* 0F75AC 7F0C2A7C 00005812 */  mflo  $t3
/* 0F75B0 7F0C2A80 022B8021 */  addu  $s0, $s1, $t3
/* 0F75B4 7F0C2A84 C6040024 */  lwc1  $f4, 0x24($s0)
/* 0F75B8 7F0C2A88 4604903C */  c.lt.s $f18, $f4
/* 0F75BC 7F0C2A8C 00000000 */  nop   
/* 0F75C0 7F0C2A90 45020005 */  bc1fl .L7F0C2AA8
/* 0F75C4 7F0C2A94 8FAE0130 */   lw    $t6, 0x130($sp)
/* 0F75C8 7F0C2A98 8E0C002C */  lw    $t4, 0x2c($s0)
/* 0F75CC 7F0C2A9C 358D0200 */  ori   $t5, $t4, 0x200
/* 0F75D0 7F0C2AA0 AE0D002C */  sw    $t5, 0x2c($s0)
/* 0F75D4 7F0C2AA4 8FAE0130 */  lw    $t6, 0x130($sp)
.L7F0C2AA8:
/* 0F75D8 7F0C2AA8 8FA50088 */  lw    $a1, 0x88($sp)
/* 0F75DC 7F0C2AAC 8FA600C0 */  lw    $a2, 0xc0($sp)
/* 0F75E0 7F0C2AB0 8FA700F8 */  lw    $a3, 0xf8($sp)
/* 0F75E4 7F0C2AB4 0FC30845 */  jal   sub_GAME_7F0C2114
/* 0F75E8 7F0C2AB8 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0F75EC 7F0C2ABC 00530019 */  multu $v0, $s3
/* 0F75F0 7F0C2AC0 03C02025 */  move  $a0, $fp
/* 0F75F4 7F0C2AC4 00007812 */  mflo  $t7
/* 0F75F8 7F0C2AC8 022F8021 */  addu  $s0, $s1, $t7
/* 0F75FC 7F0C2ACC 8E18002C */  lw    $t8, 0x2c($s0)
/* 0F7600 7F0C2AD0 37080400 */  ori   $t0, $t8, 0x400
/* 0F7604 7F0C2AD4 AE08002C */  sw    $t0, 0x2c($s0)
/* 0F7608 7F0C2AD8 8FA90130 */  lw    $t1, 0x130($sp)
/* 0F760C 7F0C2ADC 8FA700F8 */  lw    $a3, 0xf8($sp)
/* 0F7610 7F0C2AE0 8FA600C0 */  lw    $a2, 0xc0($sp)
/* 0F7614 7F0C2AE4 8FA50088 */  lw    $a1, 0x88($sp)
/* 0F7618 7F0C2AE8 0FC30809 */  jal   sub_GAME_7F0C2024
/* 0F761C 7F0C2AEC AFA90010 */   sw    $t1, 0x10($sp)
/* 0F7620 7F0C2AF0 00530019 */  multu $v0, $s3
/* 0F7624 7F0C2AF4 03C02025 */  move  $a0, $fp
/* 0F7628 7F0C2AF8 00005012 */  mflo  $t2
/* 0F762C 7F0C2AFC 022A8021 */  addu  $s0, $s1, $t2
/* 0F7630 7F0C2B00 8E19001C */  lw    $t9, 0x1c($s0)
/* 0F7634 7F0C2B04 5B200007 */  blezl $t9, .L7F0C2B24
/* 0F7638 7F0C2B08 8FAD0144 */   lw    $t5, 0x144($sp)
/* 0F763C 7F0C2B0C 8E03002C */  lw    $v1, 0x2c($s0)
/* 0F7640 7F0C2B10 306B0400 */  andi  $t3, $v1, 0x400
/* 0F7644 7F0C2B14 15600002 */  bnez  $t3, .L7F0C2B20
/* 0F7648 7F0C2B18 346C0800 */   ori   $t4, $v1, 0x800
/* 0F764C 7F0C2B1C AE0C002C */  sw    $t4, 0x2c($s0)
.L7F0C2B20:
/* 0F7650 7F0C2B20 8FAD0144 */  lw    $t5, 0x144($sp)
.L7F0C2B24:
/* 0F7654 7F0C2B24 8FA5009C */  lw    $a1, 0x9c($sp)
/* 0F7658 7F0C2B28 8FA600D4 */  lw    $a2, 0xd4($sp)
/* 0F765C 7F0C2B2C 8FA7010C */  lw    $a3, 0x10c($sp)
/* 0F7660 7F0C2B30 0FC30809 */  jal   sub_GAME_7F0C2024
/* 0F7664 7F0C2B34 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0F7668 7F0C2B38 00530019 */  multu $v0, $s3
/* 0F766C 7F0C2B3C 03C02025 */  move  $a0, $fp
/* 0F7670 7F0C2B40 00007012 */  mflo  $t6
/* 0F7674 7F0C2B44 022E8021 */  addu  $s0, $s1, $t6
/* 0F7678 7F0C2B48 8E0F0030 */  lw    $t7, 0x30($s0)
/* 0F767C 7F0C2B4C 59E00005 */  blezl $t7, .L7F0C2B64
/* 0F7680 7F0C2B50 8FA90148 */   lw    $t1, 0x148($sp)
/* 0F7684 7F0C2B54 8E18002C */  lw    $t8, 0x2c($s0)
/* 0F7688 7F0C2B58 37082000 */  ori   $t0, $t8, 0x2000
/* 0F768C 7F0C2B5C AE08002C */  sw    $t0, 0x2c($s0)
/* 0F7690 7F0C2B60 8FA90148 */  lw    $t1, 0x148($sp)
.L7F0C2B64:
/* 0F7694 7F0C2B64 8FA500A0 */  lw    $a1, 0xa0($sp)
/* 0F7698 7F0C2B68 8FA600D8 */  lw    $a2, 0xd8($sp)
/* 0F769C 7F0C2B6C 8FA70110 */  lw    $a3, 0x110($sp)
/* 0F76A0 7F0C2B70 0FC30845 */  jal   sub_GAME_7F0C2114
/* 0F76A4 7F0C2B74 AFA90010 */   sw    $t1, 0x10($sp)
/* 0F76A8 7F0C2B78 00530019 */  multu $v0, $s3
/* 0F76AC 7F0C2B7C 33C20001 */  andi  $v0, $fp, 1
/* 0F76B0 7F0C2B80 00005012 */  mflo  $t2
/* 0F76B4 7F0C2B84 022A8021 */  addu  $s0, $s1, $t2
/* 0F76B8 7F0C2B88 8E190034 */  lw    $t9, 0x34($s0)
/* 0F76BC 7F0C2B8C 1B200004 */  blez  $t9, .L7F0C2BA0
/* 0F76C0 7F0C2B90 00000000 */   nop   
/* 0F76C4 7F0C2B94 8E0B002C */  lw    $t3, 0x2c($s0)
/* 0F76C8 7F0C2B98 356C1000 */  ori   $t4, $t3, 0x1000
/* 0F76CC 7F0C2B9C AE0C002C */  sw    $t4, 0x2c($s0)
.L7F0C2BA0:
/* 0F76D0 7F0C2BA0 1BC0005A */  blez  $fp, .L7F0C2D0C
/* 0F76D4 7F0C2BA4 0000B025 */   move  $s6, $zero
/* 0F76D8 7F0C2BA8 10400016 */  beqz  $v0, .L7F0C2C04
/* 0F76DC 7F0C2BAC 3C198008 */   lui   $t9, %hi(player1_player_data) 
/* 0F76E0 7F0C2BB0 3C028008 */  lui   $v0, %hi(player1_player_data + 0x58)
/* 0F76E4 7F0C2BB4 8C429F48 */  lw    $v0, %lo(player1_player_data + 0x58)($v0)
/* 0F76E8 7F0C2BB8 24030004 */  li    $v1, 4
/* 0F76EC 7F0C2BBC 24160001 */  li    $s6, 1
/* 0F76F0 7F0C2BC0 14620005 */  bne   $v1, $v0, .L7F0C2BD8
/* 0F76F4 7F0C2BC4 8FAD0098 */   lw    $t5, 0x98($sp)
/* 0F76F8 7F0C2BC8 3C040001 */  lui   $a0, 1
/* 0F76FC 7F0C2BCC 01A47025 */  or    $t6, $t5, $a0
/* 0F7700 7F0C2BD0 1000000B */  b     .L7F0C2C00
/* 0F7704 7F0C2BD4 AFAE0098 */   sw    $t6, 0x98($sp)
.L7F0C2BD8:
/* 0F7708 7F0C2BD8 16E20005 */  bne   $s7, $v0, .L7F0C2BF0
/* 0F770C 7F0C2BDC 24050002 */   li    $a1, 2
/* 0F7710 7F0C2BE0 8FAF0098 */  lw    $t7, 0x98($sp)
/* 0F7714 7F0C2BE4 35F88000 */  ori   $t8, $t7, 0x8000
/* 0F7718 7F0C2BE8 10000005 */  b     .L7F0C2C00
/* 0F771C 7F0C2BEC AFB80098 */   sw    $t8, 0x98($sp)
.L7F0C2BF0:
/* 0F7720 7F0C2BF0 14A20003 */  bne   $a1, $v0, .L7F0C2C00
/* 0F7724 7F0C2BF4 8FA80098 */   lw    $t0, 0x98($sp)
/* 0F7728 7F0C2BF8 35094000 */  ori   $t1, $t0, 0x4000
/* 0F772C 7F0C2BFC AFA90098 */  sw    $t1, 0x98($sp)
.L7F0C2C00:
/* 0F7730 7F0C2C00 12DE0041 */  beq   $s6, $fp, .L7F0C2D08
.L7F0C2C04:
/* 0F7734 7F0C2C04 001650C0 */   sll   $t2, $s6, 3
/* 0F7738 7F0C2C08 01565023 */  subu  $t2, $t2, $s6
/* 0F773C 7F0C2C0C 000A5100 */  sll   $t2, $t2, 4
/* 0F7740 7F0C2C10 27399EF0 */  addiu $t9, %lo(player1_player_data) # addiu $t9, $t9, -0x6110
/* 0F7744 7F0C2C14 0159A021 */  addu  $s4, $t2, $t9
/* 0F7748 7F0C2C18 24030004 */  li    $v1, 4
/* 0F774C 7F0C2C1C 3C040001 */  lui   $a0, 1
/* 0F7750 7F0C2C20 24050002 */  li    $a1, 2
.L7F0C2C24:
/* 0F7754 7F0C2C24 8E820058 */  lw    $v0, 0x58($s4)
/* 0F7758 7F0C2C28 14620008 */  bne   $v1, $v0, .L7F0C2C4C
/* 0F775C 7F0C2C2C 00000000 */   nop   
/* 0F7760 7F0C2C30 02D30019 */  multu $s6, $s3
/* 0F7764 7F0C2C34 00005812 */  mflo  $t3
/* 0F7768 7F0C2C38 022B9021 */  addu  $s2, $s1, $t3
/* 0F776C 7F0C2C3C 8E4C002C */  lw    $t4, 0x2c($s2)
/* 0F7770 7F0C2C40 01846825 */  or    $t5, $t4, $a0
/* 0F7774 7F0C2C44 10000012 */  b     .L7F0C2C90
/* 0F7778 7F0C2C48 AE4D002C */   sw    $t5, 0x2c($s2)
.L7F0C2C4C:
/* 0F777C 7F0C2C4C 16E20008 */  bne   $s7, $v0, .L7F0C2C70
/* 0F7780 7F0C2C50 00000000 */   nop   
/* 0F7784 7F0C2C54 02D30019 */  multu $s6, $s3
/* 0F7788 7F0C2C58 00007012 */  mflo  $t6
/* 0F778C 7F0C2C5C 022E9021 */  addu  $s2, $s1, $t6
/* 0F7790 7F0C2C60 8E4F002C */  lw    $t7, 0x2c($s2)
/* 0F7794 7F0C2C64 35F88000 */  ori   $t8, $t7, 0x8000
/* 0F7798 7F0C2C68 10000009 */  b     .L7F0C2C90
/* 0F779C 7F0C2C6C AE58002C */   sw    $t8, 0x2c($s2)
.L7F0C2C70:
/* 0F77A0 7F0C2C70 54A20008 */  bnel  $a1, $v0, .L7F0C2C94
/* 0F77A4 7F0C2C74 8E8200C8 */   lw    $v0, 0xc8($s4)
/* 0F77A8 7F0C2C78 02D30019 */  multu $s6, $s3
/* 0F77AC 7F0C2C7C 00004012 */  mflo  $t0
/* 0F77B0 7F0C2C80 02289021 */  addu  $s2, $s1, $t0
/* 0F77B4 7F0C2C84 8E49002C */  lw    $t1, 0x2c($s2)
/* 0F77B8 7F0C2C88 352A4000 */  ori   $t2, $t1, 0x4000
/* 0F77BC 7F0C2C8C AE4A002C */  sw    $t2, 0x2c($s2)
.L7F0C2C90:
/* 0F77C0 7F0C2C90 8E8200C8 */  lw    $v0, 0xc8($s4)
.L7F0C2C94:
/* 0F77C4 7F0C2C94 14620008 */  bne   $v1, $v0, .L7F0C2CB8
/* 0F77C8 7F0C2C98 00000000 */   nop   
/* 0F77CC 7F0C2C9C 02D30019 */  multu $s6, $s3
/* 0F77D0 7F0C2CA0 0000C812 */  mflo  $t9
/* 0F77D4 7F0C2CA4 02399021 */  addu  $s2, $s1, $t9
/* 0F77D8 7F0C2CA8 8E4B0064 */  lw    $t3, 0x64($s2)
/* 0F77DC 7F0C2CAC 01646025 */  or    $t4, $t3, $a0
/* 0F77E0 7F0C2CB0 10000012 */  b     .L7F0C2CFC
/* 0F77E4 7F0C2CB4 AE4C0064 */   sw    $t4, 0x64($s2)
.L7F0C2CB8:
/* 0F77E8 7F0C2CB8 16E20008 */  bne   $s7, $v0, .L7F0C2CDC
/* 0F77EC 7F0C2CBC 00000000 */   nop   
/* 0F77F0 7F0C2CC0 02D30019 */  multu $s6, $s3
/* 0F77F4 7F0C2CC4 00006812 */  mflo  $t5
/* 0F77F8 7F0C2CC8 022D9021 */  addu  $s2, $s1, $t5
/* 0F77FC 7F0C2CCC 8E4E0064 */  lw    $t6, 0x64($s2)
/* 0F7800 7F0C2CD0 35CF8000 */  ori   $t7, $t6, 0x8000
/* 0F7804 7F0C2CD4 10000009 */  b     .L7F0C2CFC
/* 0F7808 7F0C2CD8 AE4F0064 */   sw    $t7, 0x64($s2)
.L7F0C2CDC:
/* 0F780C 7F0C2CDC 54A20008 */  bnel  $a1, $v0, .L7F0C2D00
/* 0F7810 7F0C2CE0 26D60002 */   addiu $s6, $s6, 2
/* 0F7814 7F0C2CE4 02D30019 */  multu $s6, $s3
/* 0F7818 7F0C2CE8 0000C012 */  mflo  $t8
/* 0F781C 7F0C2CEC 02389021 */  addu  $s2, $s1, $t8
/* 0F7820 7F0C2CF0 8E480064 */  lw    $t0, 0x64($s2)
/* 0F7824 7F0C2CF4 35094000 */  ori   $t1, $t0, 0x4000
/* 0F7828 7F0C2CF8 AE490064 */  sw    $t1, 0x64($s2)
.L7F0C2CFC:
/* 0F782C 7F0C2CFC 26D60002 */  addiu $s6, $s6, 2
.L7F0C2D00:
/* 0F7830 7F0C2D00 16DEFFC8 */  bne   $s6, $fp, .L7F0C2C24
/* 0F7834 7F0C2D04 269400E0 */   addiu $s4, $s4, 0xe0
.L7F0C2D08:
/* 0F7838 7F0C2D08 0000B025 */  move  $s6, $zero
.L7F0C2D0C:
/* 0F783C 7F0C2D0C 1BC00050 */  blez  $fp, .L7F0C2E50
/* 0F7840 7F0C2D10 3C148005 */   lui   $s4, %hi(loaded_text_index)
/* 0F7844 7F0C2D14 26948640 */  addiu $s4, %lo(loaded_text_index) # addiu $s4, $s4, -0x79c0
/* 0F7848 7F0C2D18 27B2006C */  addiu $s2, $sp, 0x6c
/* 0F784C 7F0C2D1C 24150011 */  li    $s5, 17
.L7F0C2D20:
/* 0F7850 7F0C2D20 00009825 */  move  $s3, $zero
/* 0F7854 7F0C2D24 24050010 */  li    $a1, 16
/* 0F7858 7F0C2D28 8E50002C */  lw    $s0, 0x2c($s2)
.L7F0C2D2C:
/* 0F785C 7F0C2D2C 240A0001 */  li    $t2, 1
/* 0F7860 7F0C2D30 00AA1004 */  sllv  $v0, $t2, $a1
/* 0F7864 7F0C2D34 0202C824 */  and   $t9, $s0, $v0
/* 0F7868 7F0C2D38 1320000F */  beqz  $t9, .L7F0C2D78
/* 0F786C 7F0C2D3C 00405827 */   not   $t3, $v0
/* 0F7870 7F0C2D40 00056840 */  sll   $t5, $a1, 1
/* 0F7874 7F0C2D44 3C188008 */  lui   $t8, %hi(ptr_BONDdata_p1) 
/* 0F7878 7F0C2D48 020B6024 */  and   $t4, $s0, $t3
/* 0F787C 7F0C2D4C 27189EE0 */  addiu $t8, %lo(ptr_BONDdata_p1) # addiu $t8, $t8, -0x6120
/* 0F7880 7F0C2D50 028D7021 */  addu  $t6, $s4, $t5
/* 0F7884 7F0C2D54 00167880 */  sll   $t7, $s6, 2
/* 0F7888 7F0C2D58 AE4C002C */  sw    $t4, 0x2c($s2)
/* 0F788C 7F0C2D5C 01F88821 */  addu  $s1, $t7, $t8
/* 0F7890 7F0C2D60 95C40000 */  lhu   $a0, ($t6)
/* 0F7894 7F0C2D64 0FC30776 */  jal   get_textptr_for_textID
/* 0F7898 7F0C2D68 24130001 */   li    $s3, 1
/* 0F789C 7F0C2D6C 8E280000 */  lw    $t0, ($s1)
/* 0F78A0 7F0C2D70 AD022A10 */  sw    $v0, 0x2a10($t0)
/* 0F78A4 7F0C2D74 8E50002C */  lw    $s0, 0x2c($s2)
.L7F0C2D78:
/* 0F78A8 7F0C2D78 16000002 */  bnez  $s0, .L7F0C2D84
/* 0F78AC 7F0C2D7C 00000000 */   nop   
/* 0F78B0 7F0C2D80 24130001 */  li    $s3, 1
.L7F0C2D84:
/* 0F78B4 7F0C2D84 0C002914 */  jal   get_random_value
/* 0F78B8 7F0C2D88 00000000 */   nop   
/* 0F78BC 7F0C2D8C 0055001B */  divu  $zero, $v0, $s5
/* 0F78C0 7F0C2D90 00002810 */  mfhi  $a1
/* 0F78C4 7F0C2D94 16A00002 */  bnez  $s5, .L7F0C2DA0
/* 0F78C8 7F0C2D98 00000000 */   nop   
/* 0F78CC 7F0C2D9C 0007000D */  break 7
.L7F0C2DA0:
/* 0F78D0 7F0C2DA0 5260FFE2 */  beql  $s3, $zero, .L7F0C2D2C
/* 0F78D4 7F0C2DA4 8E50002C */   lw    $s0, 0x2c($s2)
/* 0F78D8 7F0C2DA8 2A610002 */  slti  $at, $s3, 2
/* 0F78DC 7F0C2DAC 50200026 */  beql  $at, $zero, .L7F0C2E48
/* 0F78E0 7F0C2DB0 26D60001 */   addiu $s6, $s6, 1
.L7F0C2DB4:
/* 0F78E4 7F0C2DB4 0C002914 */  jal   get_random_value
/* 0F78E8 7F0C2DB8 00000000 */   nop   
/* 0F78EC 7F0C2DBC 0055001B */  divu  $zero, $v0, $s5
/* 0F78F0 7F0C2DC0 8E50002C */  lw    $s0, 0x2c($s2)
/* 0F78F4 7F0C2DC4 00001810 */  mfhi  $v1
/* 0F78F8 7F0C2DC8 24090001 */  li    $t1, 1
/* 0F78FC 7F0C2DCC 00695004 */  sllv  $t2, $t1, $v1
/* 0F7900 7F0C2DD0 16A00002 */  bnez  $s5, .L7F0C2DDC
/* 0F7904 7F0C2DD4 00000000 */   nop   
/* 0F7908 7F0C2DD8 0007000D */  break 7
.L7F0C2DDC:
/* 0F790C 7F0C2DDC 020AC824 */  and   $t9, $s0, $t2
/* 0F7910 7F0C2DE0 13200012 */  beqz  $t9, .L7F0C2E2C
/* 0F7914 7F0C2DE4 00602825 */   move  $a1, $v1
/* 0F7918 7F0C2DE8 240B0001 */  li    $t3, 1
/* 0F791C 7F0C2DEC 006B6004 */  sllv  $t4, $t3, $v1
/* 0F7920 7F0C2DF0 01806827 */  not   $t5, $t4
/* 0F7924 7F0C2DF4 00037840 */  sll   $t7, $v1, 1
/* 0F7928 7F0C2DF8 3C098008 */  lui   $t1, %hi(ptr_BONDdata_p1) 
/* 0F792C 7F0C2DFC 020D7024 */  and   $t6, $s0, $t5
/* 0F7930 7F0C2E00 25299EE0 */  addiu $t1, %lo(ptr_BONDdata_p1) # addiu $t1, $t1, -0x6120
/* 0F7934 7F0C2E04 028FC021 */  addu  $t8, $s4, $t7
/* 0F7938 7F0C2E08 00164080 */  sll   $t0, $s6, 2
/* 0F793C 7F0C2E0C AE4E002C */  sw    $t6, 0x2c($s2)
/* 0F7940 7F0C2E10 01098821 */  addu  $s1, $t0, $t1
/* 0F7944 7F0C2E14 97040000 */  lhu   $a0, ($t8)
/* 0F7948 7F0C2E18 0FC30776 */  jal   get_textptr_for_textID
/* 0F794C 7F0C2E1C 24130002 */   li    $s3, 2
/* 0F7950 7F0C2E20 8E2A0000 */  lw    $t2, ($s1)
/* 0F7954 7F0C2E24 AD422A14 */  sw    $v0, 0x2a14($t2)
/* 0F7958 7F0C2E28 8E50002C */  lw    $s0, 0x2c($s2)
.L7F0C2E2C:
/* 0F795C 7F0C2E2C 56000003 */  bnezl $s0, .L7F0C2E3C
/* 0F7960 7F0C2E30 2A610002 */   slti  $at, $s3, 2
/* 0F7964 7F0C2E34 24130002 */  li    $s3, 2
/* 0F7968 7F0C2E38 2A610002 */  slti  $at, $s3, 2
.L7F0C2E3C:
/* 0F796C 7F0C2E3C 1420FFDD */  bnez  $at, .L7F0C2DB4
/* 0F7970 7F0C2E40 00000000 */   nop   
/* 0F7974 7F0C2E44 26D60001 */  addiu $s6, $s6, 1
.L7F0C2E48:
/* 0F7978 7F0C2E48 16DEFFB5 */  bne   $s6, $fp, .L7F0C2D20
/* 0F797C 7F0C2E4C 26520038 */   addiu $s2, $s2, 0x38
.L7F0C2E50:
/* 0F7980 7F0C2E50 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0F7984 7F0C2E54 8FB00020 */  lw    $s0, 0x20($sp)
/* 0F7988 7F0C2E58 8FB10024 */  lw    $s1, 0x24($sp)
/* 0F798C 7F0C2E5C 8FB20028 */  lw    $s2, 0x28($sp)
/* 0F7990 7F0C2E60 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0F7994 7F0C2E64 8FB40030 */  lw    $s4, 0x30($sp)
/* 0F7998 7F0C2E68 8FB50034 */  lw    $s5, 0x34($sp)
/* 0F799C 7F0C2E6C 8FB60038 */  lw    $s6, 0x38($sp)
/* 0F79A0 7F0C2E70 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0F79A4 7F0C2E74 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0F79A8 7F0C2E78 03E00008 */  jr    $ra
/* 0F79AC 7F0C2E7C 27BD0168 */   addiu $sp, $sp, 0x168
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C2E80(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C2E80
/* 0F79B0 7F0C2E80 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F79B4 7F0C2E84 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F79B8 7F0C2E88 0FC26C54 */  jal   get_cur_playernum
/* 0F79BC 7F0C2E8C 00000000 */   nop   
/* 0F79C0 7F0C2E90 0FC26919 */  jal   get_num_players
/* 0F79C4 7F0C2E94 AFA20034 */   sw    $v0, 0x34($sp)
/* 0F79C8 7F0C2E98 83A40037 */  lb    $a0, 0x37($sp)
/* 0F79CC 7F0C2E9C 2405FFFE */  li    $a1, -2
/* 0F79D0 7F0C2EA0 24060001 */  li    $a2, 1
/* 0F79D4 7F0C2EA4 AFA20030 */  sw    $v0, 0x30($sp)
/* 0F79D8 7F0C2EA8 0C00312D */  jal   get_controller_3dstick_L_R
/* 0F79DC 7F0C2EAC AFA40018 */   sw    $a0, 0x18($sp)
/* 0F79E0 7F0C2EB0 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0F79E4 7F0C2EB4 0FC26D36 */  jal   sub_GAME_7F09B4D8
/* 0F79E8 7F0C2EB8 8FA40034 */   lw    $a0, 0x34($sp)
/* 0F79EC 7F0C2EBC 1440000E */  bnez  $v0, .L7F0C2EF8
/* 0F79F0 7F0C2EC0 8FA80030 */   lw    $t0, 0x30($sp)
/* 0F79F4 7F0C2EC4 3C058009 */  lui   $a1, %hi(is_gameover_flag)
/* 0F79F8 7F0C2EC8 24A5C704 */  addiu $a1, %lo(is_gameover_flag) # addiu $a1, $a1, -0x38fc
/* 0F79FC 7F0C2ECC 8CA20000 */  lw    $v0, ($a1)
/* 0F7A00 7F0C2ED0 3C0E8005 */  lui   $t6, %hi(D_80048498) 
/* 0F7A04 7F0C2ED4 28410002 */  slti  $at, $v0, 2
/* 0F7A08 7F0C2ED8 14200007 */  bnez  $at, .L7F0C2EF8
/* 0F7A0C 7F0C2EDC 00000000 */   nop   
/* 0F7A10 7F0C2EE0 8DCE8498 */  lw    $t6, %lo(D_80048498)($t6)
/* 0F7A14 7F0C2EE4 24190001 */  li    $t9, 1
/* 0F7A18 7F0C2EE8 004E7823 */  subu  $t7, $v0, $t6
/* 0F7A1C 7F0C2EEC 1DE00002 */  bgtz  $t7, .L7F0C2EF8
/* 0F7A20 7F0C2EF0 ACAF0000 */   sw    $t7, ($a1)
/* 0F7A24 7F0C2EF4 ACB90000 */  sw    $t9, ($a1)
.L7F0C2EF8:
/* 0F7A28 7F0C2EF8 3C058009 */  lui   $a1, %hi(is_gameover_flag)
/* 0F7A2C 7F0C2EFC 24010001 */  li    $at, 1
/* 0F7A30 7F0C2F00 110101A3 */  beq   $t0, $at, .L7F0C3590
/* 0F7A34 7F0C2F04 24A5C704 */   addiu $a1, %lo(is_gameover_flag) # addiu $a1, $a1, -0x38fc
/* 0F7A38 7F0C2F08 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7A3C 7F0C2F0C 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7A40 7F0C2F10 8CE30000 */  lw    $v1, ($a3)
/* 0F7A44 7F0C2F14 8CA20000 */  lw    $v0, ($a1)
/* 0F7A48 7F0C2F18 8C6900D8 */  lw    $t1, 0xd8($v1)
/* 0F7A4C 7F0C2F1C 28410002 */  slti  $at, $v0, 2
/* 0F7A50 7F0C2F20 11200007 */  beqz  $t1, .L7F0C2F40
/* 0F7A54 7F0C2F24 00000000 */   nop   
/* 0F7A58 7F0C2F28 14400005 */  bnez  $v0, .L7F0C2F40
/* 0F7A5C 7F0C2F2C 00000000 */   nop   
/* 0F7A60 7F0C2F30 AC6029C4 */  sw    $zero, 0x29c4($v1)
/* 0F7A64 7F0C2F34 8CEA0000 */  lw    $t2, ($a3)
/* 0F7A68 7F0C2F38 10000195 */  b     .L7F0C3590
/* 0F7A6C 7F0C2F3C AD402A00 */   sw    $zero, 0x2a00($t2)
.L7F0C2F40:
/* 0F7A70 7F0C2F40 10200193 */  beqz  $at, .L7F0C3590
/* 0F7A74 7F0C2F44 8FA40034 */   lw    $a0, 0x34($sp)
/* 0F7A78 7F0C2F48 0FC26D36 */  jal   sub_GAME_7F09B4D8
/* 0F7A7C 7F0C2F4C AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7A80 7F0C2F50 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7A84 7F0C2F54 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7A88 7F0C2F58 14400021 */  bnez  $v0, .L7F0C2FE0
/* 0F7A8C 7F0C2F5C 8FA80030 */   lw    $t0, 0x30($sp)
/* 0F7A90 7F0C2F60 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C70C)
/* 0F7A94 7F0C2F64 2484C70C */  addiu $a0, %lo(dword_CODE_bss_8008C70C) # addiu $a0, $a0, -0x38f4
/* 0F7A98 7F0C2F68 3C058009 */  lui   $a1, %hi(dword_CODE_bss_8008C714)
/* 0F7A9C 7F0C2F6C 3C028005 */  lui   $v0, %hi(D_80048498)
/* 0F7AA0 7F0C2F70 8C428498 */  lw    $v0, %lo(D_80048498)($v0)
/* 0F7AA4 7F0C2F74 8C8B0000 */  lw    $t3, ($a0)
/* 0F7AA8 7F0C2F78 24A5C714 */  addiu $a1, %lo(dword_CODE_bss_8008C714) # addiu $a1, $a1, -0x38ec
/* 0F7AAC 7F0C2F7C 8CAD0000 */  lw    $t5, ($a1)
/* 0F7AB0 7F0C2F80 01626021 */  addu  $t4, $t3, $v0
/* 0F7AB4 7F0C2F84 29810014 */  slti  $at, $t4, 0x14
/* 0F7AB8 7F0C2F88 01A27021 */  addu  $t6, $t5, $v0
/* 0F7ABC 7F0C2F8C AC8C0000 */  sw    $t4, ($a0)
/* 0F7AC0 7F0C2F90 14200008 */  bnez  $at, .L7F0C2FB4
/* 0F7AC4 7F0C2F94 ACAE0000 */   sw    $t6, ($a1)
/* 0F7AC8 7F0C2F98 3C068009 */  lui   $a2, %hi(dword_CODE_bss_8008C708)
/* 0F7ACC 7F0C2F9C 24C6C708 */  addiu $a2, %lo(dword_CODE_bss_8008C708) # addiu $a2, $a2, -0x38f8
/* 0F7AD0 7F0C2FA0 8CC20000 */  lw    $v0, ($a2)
/* 0F7AD4 7F0C2FA4 258FFFEC */  addiu $t7, $t4, -0x14
/* 0F7AD8 7F0C2FA8 AC8F0000 */  sw    $t7, ($a0)
/* 0F7ADC 7F0C2FAC 2C580001 */  sltiu $t8, $v0, 1
/* 0F7AE0 7F0C2FB0 ACD80000 */  sw    $t8, ($a2)
.L7F0C2FB4:
/* 0F7AE4 7F0C2FB4 8CA30000 */  lw    $v1, ($a1)
/* 0F7AE8 7F0C2FB8 3C048009 */  lui   $a0, %hi(time_trigger_alt_gameover_msg)
/* 0F7AEC 7F0C2FBC 2484C710 */  addiu $a0, %lo(time_trigger_alt_gameover_msg) # addiu $a0, $a0, -0x38f0
/* 0F7AF0 7F0C2FC0 28610078 */  slti  $at, $v1, 0x78
/* 0F7AF4 7F0C2FC4 14200006 */  bnez  $at, .L7F0C2FE0
/* 0F7AF8 7F0C2FC8 00000000 */   nop   
/* 0F7AFC 7F0C2FCC 8C820000 */  lw    $v0, ($a0)
/* 0F7B00 7F0C2FD0 2479FF88 */  addiu $t9, $v1, -0x78
/* 0F7B04 7F0C2FD4 ACB90000 */  sw    $t9, ($a1)
/* 0F7B08 7F0C2FD8 2C490001 */  sltiu $t1, $v0, 1
/* 0F7B0C 7F0C2FDC AC890000 */  sw    $t1, ($a0)
.L7F0C2FE0:
/* 0F7B10 7F0C2FE0 3C028008 */  lui   $v0, %hi(pPlayersPerm)
/* 0F7B14 7F0C2FE4 8C42A0B4 */  lw    $v0, %lo(pPlayersPerm)($v0)
/* 0F7B18 7F0C2FE8 8CEA0000 */  lw    $t2, ($a3)
/* 0F7B1C 7F0C2FEC 8C4B0054 */  lw    $t3, 0x54($v0)
/* 0F7B20 7F0C2FF0 8D4329F8 */  lw    $v1, 0x29f8($t2)
/* 0F7B24 7F0C2FF4 0163082A */  slt   $at, $t3, $v1
/* 0F7B28 7F0C2FF8 10200002 */  beqz  $at, .L7F0C3004
/* 0F7B2C 7F0C2FFC 00000000 */   nop   
/* 0F7B30 7F0C3000 AC430054 */  sw    $v1, 0x54($v0)
.L7F0C3004:
/* 0F7B34 7F0C3004 0FC22FEE */  jal   sub_GAME_7F08BFB8
/* 0F7B38 7F0C3008 AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7B3C 7F0C300C 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7B40 7F0C3010 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7B44 7F0C3014 8CE30000 */  lw    $v1, ($a3)
/* 0F7B48 7F0C3018 3C0C8008 */  lui   $t4, %hi(pPlayersPerm) 
/* 0F7B4C 7F0C301C 8D8CA0B4 */  lw    $t4, %lo(pPlayersPerm)($t4)
/* 0F7B50 7F0C3020 8C6E29F4 */  lw    $t6, 0x29f4($v1)
/* 0F7B54 7F0C3024 8FA80030 */  lw    $t0, 0x30($sp)
/* 0F7B58 7F0C3028 8D8D004C */  lw    $t5, 0x4c($t4)
/* 0F7B5C 7F0C302C 004E7823 */  subu  $t7, $v0, $t6
/* 0F7B60 7F0C3030 01AF082A */  slt   $at, $t5, $t7
/* 0F7B64 7F0C3034 5020000E */  beql  $at, $zero, .L7F0C3070
/* 0F7B68 7F0C3038 8C6B29C4 */   lw    $t3, 0x29c4($v1)
/* 0F7B6C 7F0C303C 0FC22FEE */  jal   sub_GAME_7F08BFB8
/* 0F7B70 7F0C3040 AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7B74 7F0C3044 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7B78 7F0C3048 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7B7C 7F0C304C 8CF80000 */  lw    $t8, ($a3)
/* 0F7B80 7F0C3050 3C0A8008 */  lui   $t2, %hi(pPlayersPerm) 
/* 0F7B84 7F0C3054 8D4AA0B4 */  lw    $t2, %lo(pPlayersPerm)($t2)
/* 0F7B88 7F0C3058 8F1929F4 */  lw    $t9, 0x29f4($t8)
/* 0F7B8C 7F0C305C 8FA80030 */  lw    $t0, 0x30($sp)
/* 0F7B90 7F0C3060 00594823 */  subu  $t1, $v0, $t9
/* 0F7B94 7F0C3064 AD49004C */  sw    $t1, 0x4c($t2)
/* 0F7B98 7F0C3068 8CE30000 */  lw    $v1, ($a3)
/* 0F7B9C 7F0C306C 8C6B29C4 */  lw    $t3, 0x29c4($v1)
.L7F0C3070:
/* 0F7BA0 7F0C3070 83A4001B */  lb    $a0, 0x1b($sp)
/* 0F7BA4 7F0C3074 1160012F */  beqz  $t3, .L7F0C3534
/* 0F7BA8 7F0C3078 00000000 */   nop   
/* 0F7BAC 7F0C307C 8FA40034 */  lw    $a0, 0x34($sp)
/* 0F7BB0 7F0C3080 0FC307BE */  jal   check_if_player_is_pressing_anything_right
/* 0F7BB4 7F0C3084 AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7BB8 7F0C3088 1040000E */  beqz  $v0, .L7F0C30C4
/* 0F7BBC 7F0C308C 8FA80030 */   lw    $t0, 0x30($sp)
/* 0F7BC0 7F0C3090 0FC30788 */  jal   check_can_advance_right_on_mpmenu
/* 0F7BC4 7F0C3094 AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7BC8 7F0C3098 1040000A */  beqz  $v0, .L7F0C30C4
/* 0F7BCC 7F0C309C 8FA80030 */   lw    $t0, 0x30($sp)
/* 0F7BD0 7F0C30A0 0FC307F7 */  jal   play_watch_sfx_beep
/* 0F7BD4 7F0C30A4 00000000 */   nop   
/* 0F7BD8 7F0C30A8 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7BDC 7F0C30AC 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7BE0 7F0C30B0 8CE30000 */  lw    $v1, ($a3)
/* 0F7BE4 7F0C30B4 8C6C29C8 */  lw    $t4, 0x29c8($v1)
/* 0F7BE8 7F0C30B8 258E0001 */  addiu $t6, $t4, 1
/* 0F7BEC 7F0C30BC 10000112 */  b     .L7F0C3508
/* 0F7BF0 7F0C30C0 AC6E29C8 */   sw    $t6, 0x29c8($v1)
.L7F0C30C4:
/* 0F7BF4 7F0C30C4 8FA40034 */  lw    $a0, 0x34($sp)
/* 0F7BF8 7F0C30C8 0FC307DA */  jal   check_if_player_is_pressing_anything_left
/* 0F7BFC 7F0C30CC AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7C00 7F0C30D0 1040000E */  beqz  $v0, .L7F0C310C
/* 0F7C04 7F0C30D4 8FA80030 */   lw    $t0, 0x30($sp)
/* 0F7C08 7F0C30D8 0FC307A3 */  jal   check_can_advance_left_on_mpmenu
/* 0F7C0C 7F0C30DC AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7C10 7F0C30E0 1040000A */  beqz  $v0, .L7F0C310C
/* 0F7C14 7F0C30E4 8FA80030 */   lw    $t0, 0x30($sp)
/* 0F7C18 7F0C30E8 0FC307F7 */  jal   play_watch_sfx_beep
/* 0F7C1C 7F0C30EC 00000000 */   nop   
/* 0F7C20 7F0C30F0 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7C24 7F0C30F4 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7C28 7F0C30F8 8CE30000 */  lw    $v1, ($a3)
/* 0F7C2C 7F0C30FC 8C6D29C8 */  lw    $t5, 0x29c8($v1)
/* 0F7C30 7F0C3100 25AFFFFF */  addiu $t7, $t5, -1
/* 0F7C34 7F0C3104 10000100 */  b     .L7F0C3508
/* 0F7C38 7F0C3108 AC6F29C8 */   sw    $t7, 0x29c8($v1)
.L7F0C310C:
/* 0F7C3C 7F0C310C 8FA40034 */  lw    $a0, 0x34($sp)
/* 0F7C40 7F0C3110 0FC307BE */  jal   check_if_player_is_pressing_anything_right
/* 0F7C44 7F0C3114 AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7C48 7F0C3118 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7C4C 7F0C311C 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7C50 7F0C3120 1040000E */  beqz  $v0, .L7F0C315C
/* 0F7C54 7F0C3124 8FA80030 */   lw    $t0, 0x30($sp)
/* 0F7C58 7F0C3128 8CF80000 */  lw    $t8, ($a3)
/* 0F7C5C 7F0C312C 24010006 */  li    $at, 6
/* 0F7C60 7F0C3130 8F1929C8 */  lw    $t9, 0x29c8($t8)
/* 0F7C64 7F0C3134 5721000A */  bnel  $t9, $at, .L7F0C3160
/* 0F7C68 7F0C3138 8FA40034 */   lw    $a0, 0x34($sp)
/* 0F7C6C 7F0C313C 0FC307F7 */  jal   play_watch_sfx_beep
/* 0F7C70 7F0C3140 00000000 */   nop   
/* 0F7C74 7F0C3144 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7C78 7F0C3148 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7C7C 7F0C314C 8CEA0000 */  lw    $t2, ($a3)
/* 0F7C80 7F0C3150 24090001 */  li    $t1, 1
/* 0F7C84 7F0C3154 100000EC */  b     .L7F0C3508
/* 0F7C88 7F0C3158 AD4929CC */   sw    $t1, 0x29cc($t2)
.L7F0C315C:
/* 0F7C8C 7F0C315C 8FA40034 */  lw    $a0, 0x34($sp)
.L7F0C3160:
/* 0F7C90 7F0C3160 0FC307DA */  jal   check_if_player_is_pressing_anything_left
/* 0F7C94 7F0C3164 AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7C98 7F0C3168 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7C9C 7F0C316C 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7CA0 7F0C3170 1040000D */  beqz  $v0, .L7F0C31A8
/* 0F7CA4 7F0C3174 8FA80030 */   lw    $t0, 0x30($sp)
/* 0F7CA8 7F0C3178 8CEB0000 */  lw    $t3, ($a3)
/* 0F7CAC 7F0C317C 24010006 */  li    $at, 6
/* 0F7CB0 7F0C3180 8D6C29C8 */  lw    $t4, 0x29c8($t3)
/* 0F7CB4 7F0C3184 55810009 */  bnel  $t4, $at, .L7F0C31AC
/* 0F7CB8 7F0C3188 83A4001B */   lb    $a0, 0x1b($sp)
/* 0F7CBC 7F0C318C 0FC307F7 */  jal   play_watch_sfx_beep
/* 0F7CC0 7F0C3190 00000000 */   nop   
/* 0F7CC4 7F0C3194 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7CC8 7F0C3198 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7CCC 7F0C319C 8CEE0000 */  lw    $t6, ($a3)
/* 0F7CD0 7F0C31A0 100000D9 */  b     .L7F0C3508
/* 0F7CD4 7F0C31A4 ADC029CC */   sw    $zero, 0x29cc($t6)
.L7F0C31A8:
/* 0F7CD8 7F0C31A8 83A4001B */  lb    $a0, 0x1b($sp)
.L7F0C31AC:
/* 0F7CDC 7F0C31AC 34058000 */  li    $a1, 32768
/* 0F7CE0 7F0C31B0 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F7CE4 7F0C31B4 AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7CE8 7F0C31B8 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7CEC 7F0C31BC 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7CF0 7F0C31C0 10400022 */  beqz  $v0, .L7F0C324C
/* 0F7CF4 7F0C31C4 8FA80030 */   lw    $t0, 0x30($sp)
/* 0F7CF8 7F0C31C8 8CED0000 */  lw    $t5, ($a3)
/* 0F7CFC 7F0C31CC 24010004 */  li    $at, 4
/* 0F7D00 7F0C31D0 8DAF29C8 */  lw    $t7, 0x29c8($t5)
/* 0F7D04 7F0C31D4 55E1001E */  bnel  $t7, $at, .L7F0C3250
/* 0F7D08 7F0C31D8 8CEA0000 */   lw    $t2, ($a3)
/* 0F7D0C 7F0C31DC 0FC307F7 */  jal   play_watch_sfx_beep
/* 0F7D10 7F0C31E0 00000000 */   nop   
/* 0F7D14 7F0C31E4 3C038009 */  lui   $v1, %hi(is_paused)
/* 0F7D18 7F0C31E8 2463C718 */  addiu $v1, %lo(is_paused) # addiu $v1, $v1, -0x38e8
/* 0F7D1C 7F0C31EC 8C780000 */  lw    $t8, ($v1)
/* 0F7D20 7F0C31F0 24190001 */  li    $t9, 1
/* 0F7D24 7F0C31F4 17000009 */  bnez  $t8, .L7F0C321C
/* 0F7D28 7F0C31F8 00000000 */   nop   
/* 0F7D2C 7F0C31FC 0FC26C54 */  jal   get_cur_playernum
/* 0F7D30 7F0C3200 AC790000 */   sw    $t9, ($v1)
/* 0F7D34 7F0C3204 3C018009 */  lui   $at, %hi(who_paused)
/* 0F7D38 7F0C3208 AC22C71C */  sw    $v0, %lo(who_paused)($at)
/* 0F7D3C 7F0C320C 0FC2FEFE */  jal   set_controls_locked_flag
/* 0F7D40 7F0C3210 24040001 */   li    $a0, 1
/* 0F7D44 7F0C3214 100000BD */  b     .L7F0C350C
/* 0F7D48 7F0C3218 8FA2002C */   lw    $v0, 0x2c($sp)
.L7F0C321C:
/* 0F7D4C 7F0C321C 0FC26C54 */  jal   get_cur_playernum
/* 0F7D50 7F0C3220 00000000 */   nop   
/* 0F7D54 7F0C3224 3C098009 */  lui   $t1, %hi(who_paused) 
/* 0F7D58 7F0C3228 8D29C71C */  lw    $t1, %lo(who_paused)($t1)
/* 0F7D5C 7F0C322C 3C038009 */  lui   $v1, %hi(is_paused)
/* 0F7D60 7F0C3230 2463C718 */  addiu $v1, %lo(is_paused) # addiu $v1, $v1, -0x38e8
/* 0F7D64 7F0C3234 144900B4 */  bne   $v0, $t1, .L7F0C3508
/* 0F7D68 7F0C3238 00002025 */   move  $a0, $zero
/* 0F7D6C 7F0C323C 0FC2FEFE */  jal   set_controls_locked_flag
/* 0F7D70 7F0C3240 AC600000 */   sw    $zero, ($v1)
/* 0F7D74 7F0C3244 100000B1 */  b     .L7F0C350C
/* 0F7D78 7F0C3248 8FA2002C */   lw    $v0, 0x2c($sp)
.L7F0C324C:
/* 0F7D7C 7F0C324C 8CEA0000 */  lw    $t2, ($a3)
.L7F0C3250:
/* 0F7D80 7F0C3250 24060007 */  li    $a2, 7
/* 0F7D84 7F0C3254 83A4001B */  lb    $a0, 0x1b($sp)
/* 0F7D88 7F0C3258 8D4B29C8 */  lw    $t3, 0x29c8($t2)
/* 0F7D8C 7F0C325C 34059000 */  li    $a1, 36864
/* 0F7D90 7F0C3260 14CB0011 */  bne   $a2, $t3, .L7F0C32A8
/* 0F7D94 7F0C3264 00000000 */   nop   
/* 0F7D98 7F0C3268 83A4001B */  lb    $a0, 0x1b($sp)
/* 0F7D9C 7F0C326C 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F7DA0 7F0C3270 24054000 */   li    $a1, 16384
/* 0F7DA4 7F0C3274 504000A5 */  beql  $v0, $zero, .L7F0C350C
/* 0F7DA8 7F0C3278 8FA2002C */   lw    $v0, 0x2c($sp)
/* 0F7DAC 7F0C327C 0FC307F7 */  jal   play_watch_sfx_beep
/* 0F7DB0 7F0C3280 00000000 */   nop   
/* 0F7DB4 7F0C3284 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7DB8 7F0C3288 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7DBC 7F0C328C 8CEE0000 */  lw    $t6, ($a3)
/* 0F7DC0 7F0C3290 240C0001 */  li    $t4, 1
/* 0F7DC4 7F0C3294 240D0003 */  li    $t5, 3
/* 0F7DC8 7F0C3298 ADCC29C4 */  sw    $t4, 0x29c4($t6)
/* 0F7DCC 7F0C329C 8CEF0000 */  lw    $t7, ($a3)
/* 0F7DD0 7F0C32A0 10000099 */  b     .L7F0C3508
/* 0F7DD4 7F0C32A4 ADED29C8 */   sw    $t5, 0x29c8($t7)
.L7F0C32A8:
/* 0F7DD8 7F0C32A8 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F7DDC 7F0C32AC AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7DE0 7F0C32B0 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7DE4 7F0C32B4 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7DE8 7F0C32B8 1040000E */  beqz  $v0, .L7F0C32F4
/* 0F7DEC 7F0C32BC 8FA80030 */   lw    $t0, 0x30($sp)
/* 0F7DF0 7F0C32C0 8CE30000 */  lw    $v1, ($a3)
/* 0F7DF4 7F0C32C4 24010005 */  li    $at, 5
/* 0F7DF8 7F0C32C8 8C6229C8 */  lw    $v0, 0x29c8($v1)
/* 0F7DFC 7F0C32CC 10410002 */  beq   $v0, $at, .L7F0C32D8
/* 0F7E00 7F0C32D0 24010006 */   li    $at, 6
/* 0F7E04 7F0C32D4 1441000D */  bne   $v0, $at, .L7F0C330C
.L7F0C32D8:
/* 0F7E08 7F0C32D8 24010006 */   li    $at, 6
/* 0F7E0C 7F0C32DC 54410006 */  bnel  $v0, $at, .L7F0C32F8
/* 0F7E10 7F0C32E0 83A4001B */   lb    $a0, 0x1b($sp)
/* 0F7E14 7F0C32E4 8C7829CC */  lw    $t8, 0x29cc($v1)
/* 0F7E18 7F0C32E8 24010001 */  li    $at, 1
/* 0F7E1C 7F0C32EC 17010007 */  bne   $t8, $at, .L7F0C330C
/* 0F7E20 7F0C32F0 00000000 */   nop   
.L7F0C32F4:
/* 0F7E24 7F0C32F4 83A4001B */  lb    $a0, 0x1b($sp)
.L7F0C32F8:
/* 0F7E28 7F0C32F8 24054000 */  li    $a1, 16384
/* 0F7E2C 7F0C32FC 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F7E30 7F0C3300 AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7E34 7F0C3304 10400052 */  beqz  $v0, .L7F0C3450
/* 0F7E38 7F0C3308 8FA80030 */   lw    $t0, 0x30($sp)
.L7F0C330C:
/* 0F7E3C 7F0C330C 0FC307F7 */  jal   play_watch_sfx_beep
/* 0F7E40 7F0C3310 AFA80030 */   sw    $t0, 0x30($sp)
/* 0F7E44 7F0C3314 3C198009 */  lui   $t9, %hi(is_gameover_flag) 
/* 0F7E48 7F0C3318 8F39C704 */  lw    $t9, %lo(is_gameover_flag)($t9)
/* 0F7E4C 7F0C331C 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7E50 7F0C3320 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7E54 7F0C3324 24060007 */  li    $a2, 7
/* 0F7E58 7F0C3328 13200039 */  beqz  $t9, .L7F0C3410
/* 0F7E5C 7F0C332C 8FA80030 */   lw    $t0, 0x30($sp)
/* 0F7E60 7F0C3330 8CE90000 */  lw    $t1, ($a3)
/* 0F7E64 7F0C3334 00001825 */  move  $v1, $zero
/* 0F7E68 7F0C3338 00002025 */  move  $a0, $zero
/* 0F7E6C 7F0C333C 1900002E */  blez  $t0, .L7F0C33F8
/* 0F7E70 7F0C3340 AD2629C8 */   sw    $a2, 0x29c8($t1)
/* 0F7E74 7F0C3344 31070003 */  andi  $a3, $t0, 3
/* 0F7E78 7F0C3348 10E0000E */  beqz  $a3, .L7F0C3384
/* 0F7E7C 7F0C334C 00E02825 */   move  $a1, $a3
/* 0F7E80 7F0C3350 3C0B8008 */  lui   $t3, %hi(ptr_BONDdata_p1) 
/* 0F7E84 7F0C3354 256B9EE0 */  addiu $t3, %lo(ptr_BONDdata_p1) # addiu $t3, $t3, -0x6120
/* 0F7E88 7F0C3358 00005080 */  sll   $t2, $zero, 2
/* 0F7E8C 7F0C335C 014B1021 */  addu  $v0, $t2, $t3
.L7F0C3360:
/* 0F7E90 7F0C3360 8C4C0000 */  lw    $t4, ($v0)
/* 0F7E94 7F0C3364 24840001 */  addiu $a0, $a0, 1
/* 0F7E98 7F0C3368 8D8E29C8 */  lw    $t6, 0x29c8($t4)
/* 0F7E9C 7F0C336C 14CE0002 */  bne   $a2, $t6, .L7F0C3378
/* 0F7EA0 7F0C3370 00000000 */   nop   
/* 0F7EA4 7F0C3374 24630001 */  addiu $v1, $v1, 1
.L7F0C3378:
/* 0F7EA8 7F0C3378 14A4FFF9 */  bne   $a1, $a0, .L7F0C3360
/* 0F7EAC 7F0C337C 24420004 */   addiu $v0, $v0, 4
/* 0F7EB0 7F0C3380 1088001D */  beq   $a0, $t0, .L7F0C33F8
.L7F0C3384:
/* 0F7EB4 7F0C3384 3C0F8008 */   lui   $t7, %hi(ptr_BONDdata_p1) 
/* 0F7EB8 7F0C3388 25EF9EE0 */  addiu $t7, %lo(ptr_BONDdata_p1) # addiu $t7, $t7, -0x6120
/* 0F7EBC 7F0C338C 00046880 */  sll   $t5, $a0, 2
/* 0F7EC0 7F0C3390 0008C080 */  sll   $t8, $t0, 2
/* 0F7EC4 7F0C3394 030F2821 */  addu  $a1, $t8, $t7
/* 0F7EC8 7F0C3398 01AF1021 */  addu  $v0, $t5, $t7
/* 0F7ECC 7F0C339C 8C590000 */  lw    $t9, ($v0)
.L7F0C33A0:
/* 0F7ED0 7F0C33A0 8F2929C8 */  lw    $t1, 0x29c8($t9)
/* 0F7ED4 7F0C33A4 54C90003 */  bnel  $a2, $t1, .L7F0C33B4
/* 0F7ED8 7F0C33A8 8C4A0004 */   lw    $t2, 4($v0)
/* 0F7EDC 7F0C33AC 24630001 */  addiu $v1, $v1, 1
/* 0F7EE0 7F0C33B0 8C4A0004 */  lw    $t2, 4($v0)
.L7F0C33B4:
/* 0F7EE4 7F0C33B4 8D4B29C8 */  lw    $t3, 0x29c8($t2)
/* 0F7EE8 7F0C33B8 54CB0003 */  bnel  $a2, $t3, .L7F0C33C8
/* 0F7EEC 7F0C33BC 8C4C0008 */   lw    $t4, 8($v0)
/* 0F7EF0 7F0C33C0 24630001 */  addiu $v1, $v1, 1
/* 0F7EF4 7F0C33C4 8C4C0008 */  lw    $t4, 8($v0)
.L7F0C33C8:
/* 0F7EF8 7F0C33C8 8D8E29C8 */  lw    $t6, 0x29c8($t4)
/* 0F7EFC 7F0C33CC 54CE0003 */  bnel  $a2, $t6, .L7F0C33DC
/* 0F7F00 7F0C33D0 8C4D000C */   lw    $t5, 0xc($v0)
/* 0F7F04 7F0C33D4 24630001 */  addiu $v1, $v1, 1
/* 0F7F08 7F0C33D8 8C4D000C */  lw    $t5, 0xc($v0)
.L7F0C33DC:
/* 0F7F0C 7F0C33DC 24420010 */  addiu $v0, $v0, 0x10
/* 0F7F10 7F0C33E0 8DB829C8 */  lw    $t8, 0x29c8($t5)
/* 0F7F14 7F0C33E4 14D80002 */  bne   $a2, $t8, .L7F0C33F0
/* 0F7F18 7F0C33E8 00000000 */   nop   
/* 0F7F1C 7F0C33EC 24630001 */  addiu $v1, $v1, 1
.L7F0C33F0:
/* 0F7F20 7F0C33F0 5445FFEB */  bnel  $v0, $a1, .L7F0C33A0
/* 0F7F24 7F0C33F4 8C590000 */   lw    $t9, ($v0)
.L7F0C33F8:
/* 0F7F28 7F0C33F8 54680044 */  bnel  $v1, $t0, .L7F0C350C
/* 0F7F2C 7F0C33FC 8FA2002C */   lw    $v0, 0x2c($sp)
/* 0F7F30 7F0C3400 0C001A54 */  jal   set_loaded_stage
/* 0F7F34 7F0C3404 2404005A */   li    $a0, 90
/* 0F7F38 7F0C3408 10000040 */  b     .L7F0C350C
/* 0F7F3C 7F0C340C 8FA2002C */   lw    $v0, 0x2c($sp)
.L7F0C3410:
/* 0F7F40 7F0C3410 8CEF0000 */  lw    $t7, ($a3)
/* 0F7F44 7F0C3414 2419003C */  li    $t9, 60
/* 0F7F48 7F0C3418 ADE029C4 */  sw    $zero, 0x29c4($t7)
/* 0F7F4C 7F0C341C 8CE90000 */  lw    $t1, ($a3)
/* 0F7F50 7F0C3420 0FC26C54 */  jal   get_cur_playernum
/* 0F7F54 7F0C3424 AD392A00 */   sw    $t9, 0x2a00($t1)
/* 0F7F58 7F0C3428 3C0A8009 */  lui   $t2, %hi(who_paused) 
/* 0F7F5C 7F0C342C 8D4AC71C */  lw    $t2, %lo(who_paused)($t2)
/* 0F7F60 7F0C3430 3C038009 */  lui   $v1, %hi(is_paused)
/* 0F7F64 7F0C3434 2463C718 */  addiu $v1, %lo(is_paused) # addiu $v1, $v1, -0x38e8
/* 0F7F68 7F0C3438 144A0033 */  bne   $v0, $t2, .L7F0C3508
/* 0F7F6C 7F0C343C 00002025 */   move  $a0, $zero
/* 0F7F70 7F0C3440 0FC2FEFE */  jal   set_controls_locked_flag
/* 0F7F74 7F0C3444 AC600000 */   sw    $zero, ($v1)
/* 0F7F78 7F0C3448 10000030 */  b     .L7F0C350C
/* 0F7F7C 7F0C344C 8FA2002C */   lw    $v0, 0x2c($sp)
.L7F0C3450:
/* 0F7F80 7F0C3450 83A4001B */  lb    $a0, 0x1b($sp)
/* 0F7F84 7F0C3454 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F7F88 7F0C3458 34059000 */   li    $a1, 36864
/* 0F7F8C 7F0C345C 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7F90 7F0C3460 10400010 */  beqz  $v0, .L7F0C34A4
/* 0F7F94 7F0C3464 24E7A0B0 */   addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7F98 7F0C3468 8CEB0000 */  lw    $t3, ($a3)
/* 0F7F9C 7F0C346C 24010005 */  li    $at, 5
/* 0F7FA0 7F0C3470 8D6C29C8 */  lw    $t4, 0x29c8($t3)
/* 0F7FA4 7F0C3474 5581000C */  bnel  $t4, $at, .L7F0C34A8
/* 0F7FA8 7F0C3478 83A4001B */   lb    $a0, 0x1b($sp)
/* 0F7FAC 7F0C347C 0FC307F7 */  jal   play_watch_sfx_beep
/* 0F7FB0 7F0C3480 00000000 */   nop   
/* 0F7FB4 7F0C3484 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7FB8 7F0C3488 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7FBC 7F0C348C 8CED0000 */  lw    $t5, ($a3)
/* 0F7FC0 7F0C3490 240E0006 */  li    $t6, 6
/* 0F7FC4 7F0C3494 ADAE29C8 */  sw    $t6, 0x29c8($t5)
/* 0F7FC8 7F0C3498 8CF80000 */  lw    $t8, ($a3)
/* 0F7FCC 7F0C349C 1000001A */  b     .L7F0C3508
/* 0F7FD0 7F0C34A0 AF0029CC */   sw    $zero, 0x29cc($t8)
.L7F0C34A4:
/* 0F7FD4 7F0C34A4 83A4001B */  lb    $a0, 0x1b($sp)
.L7F0C34A8:
/* 0F7FD8 7F0C34A8 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F7FDC 7F0C34AC 34059000 */   li    $a1, 36864
/* 0F7FE0 7F0C34B0 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F7FE4 7F0C34B4 10400014 */  beqz  $v0, .L7F0C3508
/* 0F7FE8 7F0C34B8 24E7A0B0 */   addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F7FEC 7F0C34BC 8CE30000 */  lw    $v1, ($a3)
/* 0F7FF0 7F0C34C0 24010006 */  li    $at, 6
/* 0F7FF4 7F0C34C4 8C6F29C8 */  lw    $t7, 0x29c8($v1)
/* 0F7FF8 7F0C34C8 55E10010 */  bnel  $t7, $at, .L7F0C350C
/* 0F7FFC 7F0C34CC 8FA2002C */   lw    $v0, 0x2c($sp)
/* 0F8000 7F0C34D0 8C7929CC */  lw    $t9, 0x29cc($v1)
/* 0F8004 7F0C34D4 24010001 */  li    $at, 1
/* 0F8008 7F0C34D8 5721000C */  bnel  $t9, $at, .L7F0C350C
/* 0F800C 7F0C34DC 8FA2002C */   lw    $v0, 0x2c($sp)
/* 0F8010 7F0C34E0 0FC307F7 */  jal   play_watch_sfx_beep
/* 0F8014 7F0C34E4 00000000 */   nop   
/* 0F8018 7F0C34E8 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F801C 7F0C34EC 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F8020 7F0C34F0 8CE90000 */  lw    $t1, ($a3)
/* 0F8024 7F0C34F4 00002025 */  move  $a0, $zero
/* 0F8028 7F0C34F8 AD2029C4 */  sw    $zero, 0x29c4($t1)
/* 0F802C 7F0C34FC 8CEA0000 */  lw    $t2, ($a3)
/* 0F8030 7F0C3500 0FC3094C */  jal   sub_GAME_7F0C2530
/* 0F8034 7F0C3504 AD402A00 */   sw    $zero, 0x2a00($t2)
.L7F0C3508:
/* 0F8038 7F0C3508 8FA2002C */  lw    $v0, 0x2c($sp)
.L7F0C350C:
/* 0F803C 7F0C350C 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0F8040 7F0C3510 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0F8044 7F0C3514 10400002 */  beqz  $v0, .L7F0C3520
/* 0F8048 7F0C3518 2401FFFF */   li    $at, -1
/* 0F804C 7F0C351C 14410003 */  bne   $v0, $at, .L7F0C352C
.L7F0C3520:
/* 0F8050 7F0C3520 240B0001 */   li    $t3, 1
/* 0F8054 7F0C3524 1000001A */  b     .L7F0C3590
/* 0F8058 7F0C3528 AC6B29D0 */   sw    $t3, 0x29d0($v1)
.L7F0C352C:
/* 0F805C 7F0C352C 10000018 */  b     .L7F0C3590
/* 0F8060 7F0C3530 AC6029D0 */   sw    $zero, 0x29d0($v1)
.L7F0C3534:
/* 0F8064 7F0C3534 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F8068 7F0C3538 24051000 */   li    $a1, 4096
/* 0F806C 7F0C353C 50400015 */  beql  $v0, $zero, .L7F0C3594
/* 0F8070 7F0C3540 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F8074 7F0C3544 0FC307F7 */  jal   play_watch_sfx_beep
/* 0F8078 7F0C3548 00000000 */   nop   
/* 0F807C 7F0C354C 3C078008 */  lui   $a3, %hi(pPlayer)
/* 0F8080 7F0C3550 24E7A0B0 */  addiu $a3, %lo(pPlayer) # addiu $a3, $a3, -0x5f50
/* 0F8084 7F0C3554 8CEE0000 */  lw    $t6, ($a3)
/* 0F8088 7F0C3558 240C0001 */  li    $t4, 1
/* 0F808C 7F0C355C 240D0003 */  li    $t5, 3
/* 0F8090 7F0C3560 ADCC29C4 */  sw    $t4, 0x29c4($t6)
/* 0F8094 7F0C3564 8CF80000 */  lw    $t8, ($a3)
/* 0F8098 7F0C3568 240F0001 */  li    $t7, 1
/* 0F809C 7F0C356C AF0D29C8 */  sw    $t5, 0x29c8($t8)
/* 0F80A0 7F0C3570 8CF90000 */  lw    $t9, ($a3)
/* 0F80A4 7F0C3574 AF2F29D0 */  sw    $t7, 0x29d0($t9)
/* 0F80A8 7F0C3578 8CE30000 */  lw    $v1, ($a3)
/* 0F80AC 7F0C357C C46400DC */  lwc1  $f4, 0xdc($v1)
/* 0F80B0 7F0C3580 E46400EC */  swc1  $f4, 0xec($v1)
/* 0F80B4 7F0C3584 8CE30000 */  lw    $v1, ($a3)
/* 0F80B8 7F0C3588 C46600E0 */  lwc1  $f6, 0xe0($v1)
/* 0F80BC 7F0C358C E46600F0 */  swc1  $f6, 0xf0($v1)
.L7F0C3590:
/* 0F80C0 7F0C3590 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0C3594:
/* 0F80C4 7F0C3594 27BD0038 */  addiu $sp, $sp, 0x38
/* 0F80C8 7F0C3598 03E00008 */  jr    $ra
/* 0F80CC 7F0C359C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void display_text_for_playerdata_on_MP_menu(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BC88*/
glabel jpt_MP_overlays_scoring_scenario_0
.word green_text_normal
.word green_text_highlighted
.word red_text_normal
.word red_text_highlighted
.word blue_text_normal
.word blue_text_highlighted

.text
glabel display_text_for_playerdata_on_MP_menu
/* 0F80D0 7F0C35A0 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0F80D4 7F0C35A4 AFB00034 */  sw    $s0, 0x34($sp)
/* 0F80D8 7F0C35A8 00A08025 */  move  $s0, $a1
/* 0F80DC 7F0C35AC AFB10038 */  sw    $s1, 0x38($sp)
/* 0F80E0 7F0C35B0 00808825 */  move  $s1, $a0
/* 0F80E4 7F0C35B4 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0F80E8 7F0C35B8 AFA60068 */  sw    $a2, 0x68($sp)
/* 0F80EC 7F0C35BC 3C058006 */  lui   $a1, %hi(ascii_MP_watch_menu_percentd)
/* 0F80F0 7F0C35C0 24A5BC20 */  addiu $a1, %lo(ascii_MP_watch_menu_percentd) # addiu $a1, $a1, -0x43e0
/* 0F80F4 7F0C35C4 00E03025 */  move  $a2, $a3
/* 0F80F8 7F0C35C8 0C002B25 */  jal   sprintf
/* 0F80FC 7F0C35CC 27A40048 */   addiu $a0, $sp, 0x48
/* 0F8100 7F0C35D0 3C0E8004 */  lui   $t6, %hi(ptrFirstFontTableSmall) 
/* 0F8104 7F0C35D4 8DCE0EAC */  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
/* 0F8108 7F0C35D8 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0F810C 7F0C35DC 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0F8110 7F0C35E0 27A40050 */  addiu $a0, $sp, 0x50
/* 0F8114 7F0C35E4 27A50054 */  addiu $a1, $sp, 0x54
/* 0F8118 7F0C35E8 27A60048 */  addiu $a2, $sp, 0x48
/* 0F811C 7F0C35EC AFA00014 */  sw    $zero, 0x14($sp)
/* 0F8120 7F0C35F0 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0F8124 7F0C35F4 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0F8128 7F0C35F8 8FAF0054 */  lw    $t7, 0x54($sp)
/* 0F812C 7F0C35FC 8FA90070 */  lw    $t1, 0x70($sp)
/* 0F8130 7F0C3600 8FA80068 */  lw    $t0, 0x68($sp)
/* 0F8134 7F0C3604 000FC043 */  sra   $t8, $t7, 1
/* 0F8138 7F0C3608 0218C823 */  subu  $t9, $s0, $t8
/* 0F813C 7F0C360C 2D210006 */  sltiu $at, $t1, 6
/* 0F8140 7F0C3610 AFB9005C */  sw    $t9, 0x5c($sp)
/* 0F8144 7F0C3614 102000AA */  beqz  $at, .L7F0C38C0
/* 0F8148 7F0C3618 AFA80058 */   sw    $t0, 0x58($sp)
/* 0F814C 7F0C361C 00094880 */  sll   $t1, $t1, 2
/* 0F8150 7F0C3620 3C018006 */  lui   $at, %hi(jpt_MP_overlays_scoring_scenario_0)
/* 0F8154 7F0C3624 00290821 */  addu  $at, $at, $t1
/* 0F8158 7F0C3628 8C29BC88 */  lw    $t1, %lo(jpt_MP_overlays_scoring_scenario_0)($at)
/* 0F815C 7F0C362C 01200008 */  jr    $t1
/* 0F8160 7F0C3630 00000000 */   nop   
green_text_normal:
/* 0F8164 7F0C3634 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F8168 7F0C3638 00000000 */   nop   
/* 0F816C 7F0C363C 00028400 */  sll   $s0, $v0, 0x10
/* 0F8170 7F0C3640 00105403 */  sra   $t2, $s0, 0x10
/* 0F8174 7F0C3644 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F8178 7F0C3648 01408025 */   move  $s0, $t2
/* 0F817C 7F0C364C 3C0B8004 */  lui   $t3, %hi(ptrSecondFontTableSmall) 
/* 0F8180 7F0C3650 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) 
/* 0F8184 7F0C3654 8D8C0EAC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0F8188 7F0C3658 8D6B0EB0 */  lw    $t3, %lo(ptrSecondFontTableSmall)($t3)
/* 0F818C 7F0C365C 3C0D00FF */  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
/* 0F8190 7F0C3660 35AD00B0 */  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0F8194 7F0C3664 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0F8198 7F0C3668 02202025 */  move  $a0, $s1
/* 0F819C 7F0C366C 27A5005C */  addiu $a1, $sp, 0x5c
/* 0F81A0 7F0C3670 27A60058 */  addiu $a2, $sp, 0x58
/* 0F81A4 7F0C3674 27A70048 */  addiu $a3, $sp, 0x48
/* 0F81A8 7F0C3678 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F81AC 7F0C367C AFA20020 */  sw    $v0, 0x20($sp)
/* 0F81B0 7F0C3680 AFA00024 */  sw    $zero, 0x24($sp)
/* 0F81B4 7F0C3684 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F81B8 7F0C3688 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0F81BC 7F0C368C 0FC2B6AF */  jal   en_text_write_stuff
/* 0F81C0 7F0C3690 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0F81C4 7F0C3694 1000008A */  b     .L7F0C38C0
/* 0F81C8 7F0C3698 00408825 */   move  $s1, $v0
green_text_highlighted:
/* 0F81CC 7F0C369C 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F81D0 7F0C36A0 00000000 */   nop   
/* 0F81D4 7F0C36A4 00028400 */  sll   $s0, $v0, 0x10
/* 0F81D8 7F0C36A8 00107403 */  sra   $t6, $s0, 0x10
/* 0F81DC 7F0C36AC 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F81E0 7F0C36B0 01C08025 */   move  $s0, $t6
/* 0F81E4 7F0C36B4 3C0F8004 */  lui   $t7, %hi(ptrSecondFontTableSmall) 
/* 0F81E8 7F0C36B8 3C188004 */  lui   $t8, %hi(ptrFirstFontTableSmall) 
/* 0F81EC 7F0C36BC 8F180EAC */  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
/* 0F81F0 7F0C36C0 8DEF0EB0 */  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
/* 0F81F4 7F0C36C4 3C19A0FF */  lui   $t9, (0xA0FFA0F0 >> 16) # lui $t9, 0xa0ff
/* 0F81F8 7F0C36C8 3C080070 */  lui   $t0, (0x007000A0 >> 16) # lui $t0, 0x70
/* 0F81FC 7F0C36CC 350800A0 */  ori   $t0, (0x007000A0 & 0xFFFF) # ori $t0, $t0, 0xa0
/* 0F8200 7F0C36D0 3739A0F0 */  ori   $t9, (0xA0FFA0F0 & 0xFFFF) # ori $t9, $t9, 0xa0f0
/* 0F8204 7F0C36D4 AFB90018 */  sw    $t9, 0x18($sp)
/* 0F8208 7F0C36D8 AFA8001C */  sw    $t0, 0x1c($sp)
/* 0F820C 7F0C36DC 02202025 */  move  $a0, $s1
/* 0F8210 7F0C36E0 27A5005C */  addiu $a1, $sp, 0x5c
/* 0F8214 7F0C36E4 27A60058 */  addiu $a2, $sp, 0x58
/* 0F8218 7F0C36E8 27A70048 */  addiu $a3, $sp, 0x48
/* 0F821C 7F0C36EC AFB00020 */  sw    $s0, 0x20($sp)
/* 0F8220 7F0C36F0 AFA20024 */  sw    $v0, 0x24($sp)
/* 0F8224 7F0C36F4 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F8228 7F0C36F8 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0F822C 7F0C36FC AFB80014 */  sw    $t8, 0x14($sp)
/* 0F8230 7F0C3700 0FC2B9BB */  jal   jp_text_write_stuff
/* 0F8234 7F0C3704 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0F8238 7F0C3708 1000006D */  b     .L7F0C38C0
/* 0F823C 7F0C370C 00408825 */   move  $s1, $v0
red_text_normal:
/* 0F8240 7F0C3710 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F8244 7F0C3714 00000000 */   nop   
/* 0F8248 7F0C3718 00028400 */  sll   $s0, $v0, 0x10
/* 0F824C 7F0C371C 00104C03 */  sra   $t1, $s0, 0x10
/* 0F8250 7F0C3720 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F8254 7F0C3724 01208025 */   move  $s0, $t1
/* 0F8258 7F0C3728 3C0A8004 */  lui   $t2, %hi(ptrSecondFontTableSmall) 
/* 0F825C 7F0C372C 3C0B8004 */  lui   $t3, %hi(ptrFirstFontTableSmall) 
/* 0F8260 7F0C3730 8D6B0EAC */  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
/* 0F8264 7F0C3734 8D4A0EB0 */  lw    $t2, %lo(ptrSecondFontTableSmall)($t2)
/* 0F8268 7F0C3738 3C0CFF40 */  lui   $t4, (0xFF4040B0 >> 16) # lui $t4, 0xff40
/* 0F826C 7F0C373C 358C40B0 */  ori   $t4, (0xFF4040B0 & 0xFFFF) # ori $t4, $t4, 0x40b0
/* 0F8270 7F0C3740 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0F8274 7F0C3744 02202025 */  move  $a0, $s1
/* 0F8278 7F0C3748 27A5005C */  addiu $a1, $sp, 0x5c
/* 0F827C 7F0C374C 27A60058 */  addiu $a2, $sp, 0x58
/* 0F8280 7F0C3750 27A70048 */  addiu $a3, $sp, 0x48
/* 0F8284 7F0C3754 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F8288 7F0C3758 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F828C 7F0C375C AFA00024 */  sw    $zero, 0x24($sp)
/* 0F8290 7F0C3760 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F8294 7F0C3764 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0F8298 7F0C3768 0FC2B6AF */  jal   en_text_write_stuff
/* 0F829C 7F0C376C AFAA0010 */   sw    $t2, 0x10($sp)
/* 0F82A0 7F0C3770 10000053 */  b     .L7F0C38C0
/* 0F82A4 7F0C3774 00408825 */   move  $s1, $v0
red_text_highlighted:
/* 0F82A8 7F0C3778 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F82AC 7F0C377C 00000000 */   nop   
/* 0F82B0 7F0C3780 00028400 */  sll   $s0, $v0, 0x10
/* 0F82B4 7F0C3784 00106C03 */  sra   $t5, $s0, 0x10
/* 0F82B8 7F0C3788 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F82BC 7F0C378C 01A08025 */   move  $s0, $t5
/* 0F82C0 7F0C3790 3C0E8004 */  lui   $t6, %hi(ptrSecondFontTableSmall) 
/* 0F82C4 7F0C3794 3C0F8004 */  lui   $t7, %hi(ptrFirstFontTableSmall) 
/* 0F82C8 7F0C3798 8DEF0EAC */  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
/* 0F82CC 7F0C379C 8DCE0EB0 */  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
/* 0F82D0 7F0C37A0 3C18FFA0 */  lui   $t8, (0xFFA0A0F0 >> 16) # lui $t8, 0xffa0
/* 0F82D4 7F0C37A4 3C197000 */  lui   $t9, (0x700000A0 >> 16) # lui $t9, 0x7000
/* 0F82D8 7F0C37A8 373900A0 */  ori   $t9, (0x700000A0 & 0xFFFF) # ori $t9, $t9, 0xa0
/* 0F82DC 7F0C37AC 3718A0F0 */  ori   $t8, (0xFFA0A0F0 & 0xFFFF) # ori $t8, $t8, 0xa0f0
/* 0F82E0 7F0C37B0 AFB80018 */  sw    $t8, 0x18($sp)
/* 0F82E4 7F0C37B4 AFB9001C */  sw    $t9, 0x1c($sp)
/* 0F82E8 7F0C37B8 02202025 */  move  $a0, $s1
/* 0F82EC 7F0C37BC 27A5005C */  addiu $a1, $sp, 0x5c
/* 0F82F0 7F0C37C0 27A60058 */  addiu $a2, $sp, 0x58
/* 0F82F4 7F0C37C4 27A70048 */  addiu $a3, $sp, 0x48
/* 0F82F8 7F0C37C8 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F82FC 7F0C37CC AFA20024 */  sw    $v0, 0x24($sp)
/* 0F8300 7F0C37D0 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F8304 7F0C37D4 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0F8308 7F0C37D8 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0F830C 7F0C37DC 0FC2B9BB */  jal   jp_text_write_stuff
/* 0F8310 7F0C37E0 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0F8314 7F0C37E4 10000036 */  b     .L7F0C38C0
/* 0F8318 7F0C37E8 00408825 */   move  $s1, $v0
blue_text_normal:
/* 0F831C 7F0C37EC 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F8320 7F0C37F0 00000000 */   nop   
/* 0F8324 7F0C37F4 00028400 */  sll   $s0, $v0, 0x10
/* 0F8328 7F0C37F8 00104403 */  sra   $t0, $s0, 0x10
/* 0F832C 7F0C37FC 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F8330 7F0C3800 01008025 */   move  $s0, $t0
/* 0F8334 7F0C3804 3C098004 */  lui   $t1, %hi(ptrSecondFontTableSmall) 
/* 0F8338 7F0C3808 3C0A8004 */  lui   $t2, %hi(ptrFirstFontTableSmall) 
/* 0F833C 7F0C380C 8D4A0EAC */  lw    $t2, %lo(ptrFirstFontTableSmall)($t2)
/* 0F8340 7F0C3810 8D290EB0 */  lw    $t1, %lo(ptrSecondFontTableSmall)($t1)
/* 0F8344 7F0C3814 3C0B4040 */  lui   $t3, (0x4040FFB0 >> 16) # lui $t3, 0x4040
/* 0F8348 7F0C3818 356BFFB0 */  ori   $t3, (0x4040FFB0 & 0xFFFF) # ori $t3, $t3, 0xffb0
/* 0F834C 7F0C381C AFAB0018 */  sw    $t3, 0x18($sp)
/* 0F8350 7F0C3820 02202025 */  move  $a0, $s1
/* 0F8354 7F0C3824 27A5005C */  addiu $a1, $sp, 0x5c
/* 0F8358 7F0C3828 27A60058 */  addiu $a2, $sp, 0x58
/* 0F835C 7F0C382C 27A70048 */  addiu $a3, $sp, 0x48
/* 0F8360 7F0C3830 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F8364 7F0C3834 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F8368 7F0C3838 AFA00024 */  sw    $zero, 0x24($sp)
/* 0F836C 7F0C383C AFA00028 */  sw    $zero, 0x28($sp)
/* 0F8370 7F0C3840 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0F8374 7F0C3844 0FC2B6AF */  jal   en_text_write_stuff
/* 0F8378 7F0C3848 AFA90010 */   sw    $t1, 0x10($sp)
/* 0F837C 7F0C384C 1000001C */  b     .L7F0C38C0
/* 0F8380 7F0C3850 00408825 */   move  $s1, $v0
blue_text_highlighted:
/* 0F8384 7F0C3854 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F8388 7F0C3858 00000000 */   nop   
/* 0F838C 7F0C385C 00028400 */  sll   $s0, $v0, 0x10
/* 0F8390 7F0C3860 00106403 */  sra   $t4, $s0, 0x10
/* 0F8394 7F0C3864 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F8398 7F0C3868 01808025 */   move  $s0, $t4
/* 0F839C 7F0C386C 3C0D8004 */  lui   $t5, %hi(ptrSecondFontTableSmall) 
/* 0F83A0 7F0C3870 3C0E8004 */  lui   $t6, %hi(ptrFirstFontTableSmall) 
/* 0F83A4 7F0C3874 8DCE0EAC */  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
/* 0F83A8 7F0C3878 8DAD0EB0 */  lw    $t5, %lo(ptrSecondFontTableSmall)($t5)
/* 0F83AC 7F0C387C 3C0FA0A0 */  lui   $t7, (0xA0A0FFF0 >> 16) # lui $t7, 0xa0a0
/* 0F83B0 7F0C3880 35EFFFF0 */  ori   $t7, (0xA0A0FFF0 & 0xFFFF) # ori $t7, $t7, 0xfff0
/* 0F83B4 7F0C3884 241870A0 */  li    $t8, 28832
/* 0F83B8 7F0C3888 AFB8001C */  sw    $t8, 0x1c($sp)
/* 0F83BC 7F0C388C AFAF0018 */  sw    $t7, 0x18($sp)
/* 0F83C0 7F0C3890 02202025 */  move  $a0, $s1
/* 0F83C4 7F0C3894 27A5005C */  addiu $a1, $sp, 0x5c
/* 0F83C8 7F0C3898 27A60058 */  addiu $a2, $sp, 0x58
/* 0F83CC 7F0C389C 27A70048 */  addiu $a3, $sp, 0x48
/* 0F83D0 7F0C38A0 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F83D4 7F0C38A4 AFA20024 */  sw    $v0, 0x24($sp)
/* 0F83D8 7F0C38A8 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F83DC 7F0C38AC AFA0002C */  sw    $zero, 0x2c($sp)
/* 0F83E0 7F0C38B0 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0F83E4 7F0C38B4 0FC2B9BB */  jal   jp_text_write_stuff
/* 0F83E8 7F0C38B8 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0F83EC 7F0C38BC 00408825 */  move  $s1, $v0
def_7F0C362C:
.L7F0C38C0:
/* 0F83F0 7F0C38C0 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0F83F4 7F0C38C4 02201025 */  move  $v0, $s1
/* 0F83F8 7F0C38C8 8FB10038 */  lw    $s1, 0x38($sp)
/* 0F83FC 7F0C38CC 8FB00034 */  lw    $s0, 0x34($sp)
/* 0F8400 7F0C38D0 03E00008 */  jr    $ra
/* 0F8404 7F0C38D4 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif





#ifdef NONMATCHING
void get_points_for_mp_player(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BCA0*/
glabel jpt_MP_overlays_scoring
.word num_player_kills
.word num_deaths
.word time_with_flag
.word num_player_kills
.word num_player_kills
.word team_player_kills
.word team_player_kills
.word team_player_kills

.text
glabel get_points_for_mp_player
/* 0F8408 7F0C38D8 000470C0 */  sll   $t6, $a0, 3
/* 0F840C 7F0C38DC 3C038008 */  lui   $v1, %hi(player1_player_data)
/* 0F8410 7F0C38E0 01C47023 */  subu  $t6, $t6, $a0
/* 0F8414 7F0C38E4 24639EF0 */  addiu $v1, %lo(player1_player_data) # addiu $v1, $v1, -0x6110
/* 0F8418 7F0C38E8 000E7100 */  sll   $t6, $t6, 4
/* 0F841C 7F0C38EC 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F8420 7F0C38F0 006E5821 */  addu  $t3, $v1, $t6
/* 0F8424 7F0C38F4 91670069 */  lbu   $a3, 0x69($t3)
/* 0F8428 7F0C38F8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F842C 7F0C38FC AFAB0018 */  sw    $t3, 0x18($sp)
/* 0F8430 7F0C3900 AFA40038 */  sw    $a0, 0x38($sp)
/* 0F8434 7F0C3904 0FC26919 */  jal   get_num_players
/* 0F8438 7F0C3908 AFA70034 */   sw    $a3, 0x34($sp)
/* 0F843C 7F0C390C AFA00024 */  sw    $zero, 0x24($sp)
/* 0F8440 7F0C3910 0FC051D6 */  jal   get_scenario
/* 0F8444 7F0C3914 AFA20030 */   sw    $v0, 0x30($sp)
/* 0F8448 7F0C3918 3C038008 */  lui   $v1, %hi(player1_player_data)
/* 0F844C 7F0C391C 2C410008 */  sltiu $at, $v0, 8
/* 0F8450 7F0C3920 24639EF0 */  addiu $v1, %lo(player1_player_data) # addiu $v1, $v1, -0x6110
/* 0F8454 7F0C3924 8FA40024 */  lw    $a0, 0x24($sp)
/* 0F8458 7F0C3928 8FA50038 */  lw    $a1, 0x38($sp)
/* 0F845C 7F0C392C 8FA70034 */  lw    $a3, 0x34($sp)
/* 0F8460 7F0C3930 8FAA0030 */  lw    $t2, 0x30($sp)
/* 0F8464 7F0C3934 102000D2 */  beqz  $at, .L7F0C3C80
/* 0F8468 7F0C3938 8FAB0018 */   lw    $t3, 0x18($sp)
/* 0F846C 7F0C393C 00027880 */  sll   $t7, $v0, 2
/* 0F8470 7F0C3940 3C018006 */  lui   $at, %hi(jpt_MP_overlays_scoring)
/* 0F8474 7F0C3944 002F0821 */  addu  $at, $at, $t7
/* 0F8478 7F0C3948 8C2FBCA0 */  lw    $t7, %lo(jpt_MP_overlays_scoring)($at)
/* 0F847C 7F0C394C 01E00008 */  jr    $t7
/* 0F8480 7F0C3950 00000000 */   nop   
num_player_kills:
/* 0F8484 7F0C3954 19400068 */  blez  $t2, .L7F0C3AF8
/* 0F8488 7F0C3958 00004825 */   move  $t1, $zero
/* 0F848C 7F0C395C 31480003 */  andi  $t0, $t2, 3
/* 0F8490 7F0C3960 11000017 */  beqz  $t0, .L7F0C39C0
/* 0F8494 7F0C3964 01001025 */   move  $v0, $t0
.L7F0C3968:
/* 0F8498 7F0C3968 1125000A */  beq   $t1, $a1, .L7F0C3994
/* 0F849C 7F0C396C 0009C0C0 */   sll   $t8, $t1, 3
/* 0F84A0 7F0C3970 0005C0C0 */  sll   $t8, $a1, 3
/* 0F84A4 7F0C3974 0305C023 */  subu  $t8, $t8, $a1
/* 0F84A8 7F0C3978 0018C100 */  sll   $t8, $t8, 4
/* 0F84AC 7F0C397C 0078C821 */  addu  $t9, $v1, $t8
/* 0F84B0 7F0C3980 00096880 */  sll   $t5, $t1, 2
/* 0F84B4 7F0C3984 032D7021 */  addu  $t6, $t9, $t5
/* 0F84B8 7F0C3988 8DCF0024 */  lw    $t7, 0x24($t6)
/* 0F84BC 7F0C398C 10000008 */  b     .L7F0C39B0
/* 0F84C0 7F0C3990 008F2021 */   addu  $a0, $a0, $t7
.L7F0C3994:
/* 0F84C4 7F0C3994 0309C023 */  subu  $t8, $t8, $t1
/* 0F84C8 7F0C3998 0018C100 */  sll   $t8, $t8, 4
/* 0F84CC 7F0C399C 0078C821 */  addu  $t9, $v1, $t8
/* 0F84D0 7F0C39A0 00056880 */  sll   $t5, $a1, 2
/* 0F84D4 7F0C39A4 032D7021 */  addu  $t6, $t9, $t5
/* 0F84D8 7F0C39A8 8DCF0024 */  lw    $t7, 0x24($t6)
/* 0F84DC 7F0C39AC 008F2023 */  subu  $a0, $a0, $t7
.L7F0C39B0:
/* 0F84E0 7F0C39B0 25290001 */  addiu $t1, $t1, 1
/* 0F84E4 7F0C39B4 1449FFEC */  bne   $v0, $t1, .L7F0C3968
/* 0F84E8 7F0C39B8 00000000 */   nop   
/* 0F84EC 7F0C39BC 112A004E */  beq   $t1, $t2, .L7F0C3AF8
.L7F0C39C0:
/* 0F84F0 7F0C39C0 24A2FFFF */   addiu $v0, $a1, -1
/* 0F84F4 7F0C39C4 24A6FFFE */  addiu $a2, $a1, -2
/* 0F84F8 7F0C39C8 24A7FFFD */  addiu $a3, $a1, -3
.L7F0C39CC:
/* 0F84FC 7F0C39CC 1125000A */  beq   $t1, $a1, .L7F0C39F8
/* 0F8500 7F0C39D0 0009C0C0 */   sll   $t8, $t1, 3
/* 0F8504 7F0C39D4 0005C0C0 */  sll   $t8, $a1, 3
/* 0F8508 7F0C39D8 0305C023 */  subu  $t8, $t8, $a1
/* 0F850C 7F0C39DC 0018C100 */  sll   $t8, $t8, 4
/* 0F8510 7F0C39E0 0078C821 */  addu  $t9, $v1, $t8
/* 0F8514 7F0C39E4 00096880 */  sll   $t5, $t1, 2
/* 0F8518 7F0C39E8 032D7021 */  addu  $t6, $t9, $t5
/* 0F851C 7F0C39EC 8DCF0024 */  lw    $t7, 0x24($t6)
/* 0F8520 7F0C39F0 10000008 */  b     .L7F0C3A14
/* 0F8524 7F0C39F4 008F2021 */   addu  $a0, $a0, $t7
.L7F0C39F8:
/* 0F8528 7F0C39F8 0309C023 */  subu  $t8, $t8, $t1
/* 0F852C 7F0C39FC 0018C100 */  sll   $t8, $t8, 4
/* 0F8530 7F0C3A00 0078C821 */  addu  $t9, $v1, $t8
/* 0F8534 7F0C3A04 00056880 */  sll   $t5, $a1, 2
/* 0F8538 7F0C3A08 032D7021 */  addu  $t6, $t9, $t5
/* 0F853C 7F0C3A0C 8DCF0024 */  lw    $t7, 0x24($t6)
/* 0F8540 7F0C3A10 008F2023 */  subu  $a0, $a0, $t7
.L7F0C3A14:
/* 0F8544 7F0C3A14 1122000A */  beq   $t1, $v0, .L7F0C3A40
/* 0F8548 7F0C3A18 0009C0C0 */   sll   $t8, $t1, 3
/* 0F854C 7F0C3A1C 0005C0C0 */  sll   $t8, $a1, 3
/* 0F8550 7F0C3A20 0305C023 */  subu  $t8, $t8, $a1
/* 0F8554 7F0C3A24 0018C100 */  sll   $t8, $t8, 4
/* 0F8558 7F0C3A28 0078C821 */  addu  $t9, $v1, $t8
/* 0F855C 7F0C3A2C 00096880 */  sll   $t5, $t1, 2
/* 0F8560 7F0C3A30 032D7021 */  addu  $t6, $t9, $t5
/* 0F8564 7F0C3A34 8DCF0028 */  lw    $t7, 0x28($t6)
/* 0F8568 7F0C3A38 10000008 */  b     .L7F0C3A5C
/* 0F856C 7F0C3A3C 008F2021 */   addu  $a0, $a0, $t7
.L7F0C3A40:
/* 0F8570 7F0C3A40 0309C023 */  subu  $t8, $t8, $t1
/* 0F8574 7F0C3A44 0018C100 */  sll   $t8, $t8, 4
/* 0F8578 7F0C3A48 0078C821 */  addu  $t9, $v1, $t8
/* 0F857C 7F0C3A4C 00056880 */  sll   $t5, $a1, 2
/* 0F8580 7F0C3A50 032D7021 */  addu  $t6, $t9, $t5
/* 0F8584 7F0C3A54 8DCF0094 */  lw    $t7, 0x94($t6)
/* 0F8588 7F0C3A58 008F2023 */  subu  $a0, $a0, $t7
.L7F0C3A5C:
/* 0F858C 7F0C3A5C 1126000A */  beq   $t1, $a2, .L7F0C3A88
/* 0F8590 7F0C3A60 0009C0C0 */   sll   $t8, $t1, 3
/* 0F8594 7F0C3A64 0005C0C0 */  sll   $t8, $a1, 3
/* 0F8598 7F0C3A68 0305C023 */  subu  $t8, $t8, $a1
/* 0F859C 7F0C3A6C 0018C100 */  sll   $t8, $t8, 4
/* 0F85A0 7F0C3A70 0078C821 */  addu  $t9, $v1, $t8
/* 0F85A4 7F0C3A74 00096880 */  sll   $t5, $t1, 2
/* 0F85A8 7F0C3A78 032D7021 */  addu  $t6, $t9, $t5
/* 0F85AC 7F0C3A7C 8DCF002C */  lw    $t7, 0x2c($t6)
/* 0F85B0 7F0C3A80 10000008 */  b     .L7F0C3AA4
/* 0F85B4 7F0C3A84 008F2021 */   addu  $a0, $a0, $t7
.L7F0C3A88:
/* 0F85B8 7F0C3A88 0309C023 */  subu  $t8, $t8, $t1
/* 0F85BC 7F0C3A8C 0018C100 */  sll   $t8, $t8, 4
/* 0F85C0 7F0C3A90 0078C821 */  addu  $t9, $v1, $t8
/* 0F85C4 7F0C3A94 00056880 */  sll   $t5, $a1, 2
/* 0F85C8 7F0C3A98 032D7021 */  addu  $t6, $t9, $t5
/* 0F85CC 7F0C3A9C 8DCF0104 */  lw    $t7, 0x104($t6)
/* 0F85D0 7F0C3AA0 008F2023 */  subu  $a0, $a0, $t7
.L7F0C3AA4:
/* 0F85D4 7F0C3AA4 1127000A */  beq   $t1, $a3, .L7F0C3AD0
/* 0F85D8 7F0C3AA8 0009C0C0 */   sll   $t8, $t1, 3
/* 0F85DC 7F0C3AAC 0005C0C0 */  sll   $t8, $a1, 3
/* 0F85E0 7F0C3AB0 0305C023 */  subu  $t8, $t8, $a1
/* 0F85E4 7F0C3AB4 0018C100 */  sll   $t8, $t8, 4
/* 0F85E8 7F0C3AB8 0078C821 */  addu  $t9, $v1, $t8
/* 0F85EC 7F0C3ABC 00096880 */  sll   $t5, $t1, 2
/* 0F85F0 7F0C3AC0 032D7021 */  addu  $t6, $t9, $t5
/* 0F85F4 7F0C3AC4 8DCF0030 */  lw    $t7, 0x30($t6)
/* 0F85F8 7F0C3AC8 10000008 */  b     .L7F0C3AEC
/* 0F85FC 7F0C3ACC 008F2021 */   addu  $a0, $a0, $t7
.L7F0C3AD0:
/* 0F8600 7F0C3AD0 0309C023 */  subu  $t8, $t8, $t1
/* 0F8604 7F0C3AD4 0018C100 */  sll   $t8, $t8, 4
/* 0F8608 7F0C3AD8 0078C821 */  addu  $t9, $v1, $t8
/* 0F860C 7F0C3ADC 00056880 */  sll   $t5, $a1, 2
/* 0F8610 7F0C3AE0 032D7021 */  addu  $t6, $t9, $t5
/* 0F8614 7F0C3AE4 8DCF0174 */  lw    $t7, 0x174($t6)
/* 0F8618 7F0C3AE8 008F2023 */  subu  $a0, $a0, $t7
.L7F0C3AEC:
/* 0F861C 7F0C3AEC 25290004 */  addiu $t1, $t1, 4
/* 0F8620 7F0C3AF0 152AFFB6 */  bne   $t1, $t2, .L7F0C39CC
/* 0F8624 7F0C3AF4 00000000 */   nop   
.L7F0C3AF8:
/* 0F8628 7F0C3AF8 8D780020 */  lw    $t8, 0x20($t3)
/* 0F862C 7F0C3AFC 2559FFFE */  addiu $t9, $t2, -2
/* 0F8630 7F0C3B00 03190019 */  multu $t8, $t9
/* 0F8634 7F0C3B04 00006812 */  mflo  $t5
/* 0F8638 7F0C3B08 008D2021 */  addu  $a0, $a0, $t5
/* 0F863C 7F0C3B0C 1000005D */  b     .L7F0C3C84
/* 0F8640 7F0C3B10 8FBF0014 */   lw    $ra, 0x14($sp)
num_deaths:
/* 0F8644 7F0C3B14 916E0068 */  lbu   $t6, 0x68($t3)
/* 0F8648 7F0C3B18 240F0004 */  li    $t7, 4
/* 0F864C 7F0C3B1C 10000058 */  b     .L7F0C3C80
/* 0F8650 7F0C3B20 01EE2023 */   subu  $a0, $t7, $t6
time_with_flag:
/* 0F8654 7F0C3B24 10000056 */  b     .L7F0C3C80
/* 0F8658 7F0C3B28 8D640060 */   lw    $a0, 0x60($t3)
team_player_kills:
/* 0F865C 7F0C3B2C 19400054 */  blez  $t2, .L7F0C3C80
/* 0F8660 7F0C3B30 00004825 */   move  $t1, $zero
/* 0F8664 7F0C3B34 3C0C8008 */  lui   $t4, %hi(player1_player_data) 
/* 0F8668 7F0C3B38 258C9EF0 */  addiu $t4, %lo(player1_player_data) # addiu $t4, $t4, -0x6110
.L7F0C3B3C:
/* 0F866C 7F0C3B3C 91980069 */  lbu   $t8, 0x69($t4)
/* 0F8670 7F0C3B40 54F8004D */  bnel  $a3, $t8, .L7F0C3C78
/* 0F8674 7F0C3B44 25290001 */   addiu $t1, $t1, 1
/* 0F8678 7F0C3B48 1940004A */  blez  $t2, .L7F0C3C74
/* 0F867C 7F0C3B4C 00002825 */   move  $a1, $zero
/* 0F8680 7F0C3B50 0009C8C0 */  sll   $t9, $t1, 3
/* 0F8684 7F0C3B54 0329C823 */  subu  $t9, $t9, $t1
/* 0F8688 7F0C3B58 3C0D8008 */  lui   $t5, %hi(player1_player_data) 
/* 0F868C 7F0C3B5C 25AD9EF0 */  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x6110
/* 0F8690 7F0C3B60 0019C900 */  sll   $t9, $t9, 4
/* 0F8694 7F0C3B64 31480003 */  andi  $t0, $t2, 3
/* 0F8698 7F0C3B68 11000015 */  beqz  $t0, .L7F0C3BC0
/* 0F869C 7F0C3B6C 032D5821 */   addu  $t3, $t9, $t5
/* 0F86A0 7F0C3B70 000078C0 */  sll   $t7, $zero, 3
/* 0F86A4 7F0C3B74 01E07823 */  subu  $t7, $t7, $zero
/* 0F86A8 7F0C3B78 000F7900 */  sll   $t7, $t7, 4
/* 0F86AC 7F0C3B7C 00007080 */  sll   $t6, $zero, 2
/* 0F86B0 7F0C3B80 016E1021 */  addu  $v0, $t3, $t6
/* 0F86B4 7F0C3B84 01ED1821 */  addu  $v1, $t7, $t5
/* 0F86B8 7F0C3B88 01003025 */  move  $a2, $t0
.L7F0C3B8C:
/* 0F86BC 7F0C3B8C 90780069 */  lbu   $t8, 0x69($v1)
/* 0F86C0 7F0C3B90 24A50001 */  addiu $a1, $a1, 1
/* 0F86C4 7F0C3B94 24630070 */  addiu $v1, $v1, 0x70
/* 0F86C8 7F0C3B98 50F80005 */  beql  $a3, $t8, .L7F0C3BB0
/* 0F86CC 7F0C3B9C 8C4F0024 */   lw    $t7, 0x24($v0)
/* 0F86D0 7F0C3BA0 8C590024 */  lw    $t9, 0x24($v0)
/* 0F86D4 7F0C3BA4 10000003 */  b     .L7F0C3BB4
/* 0F86D8 7F0C3BA8 00992021 */   addu  $a0, $a0, $t9
/* 0F86DC 7F0C3BAC 8C4F0024 */  lw    $t7, 0x24($v0)
.L7F0C3BB0:
/* 0F86E0 7F0C3BB0 008F2023 */  subu  $a0, $a0, $t7
.L7F0C3BB4:
/* 0F86E4 7F0C3BB4 14C5FFF5 */  bne   $a2, $a1, .L7F0C3B8C
/* 0F86E8 7F0C3BB8 24420004 */   addiu $v0, $v0, 4
/* 0F86EC 7F0C3BBC 10AA002D */  beq   $a1, $t2, .L7F0C3C74
.L7F0C3BC0:
/* 0F86F0 7F0C3BC0 000568C0 */   sll   $t5, $a1, 3
/* 0F86F4 7F0C3BC4 01A56823 */  subu  $t5, $t5, $a1
/* 0F86F8 7F0C3BC8 3C0E8008 */  lui   $t6, %hi(player1_player_data) 
/* 0F86FC 7F0C3BCC 25CE9EF0 */  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
/* 0F8700 7F0C3BD0 000D6900 */  sll   $t5, $t5, 4
/* 0F8704 7F0C3BD4 00053080 */  sll   $a2, $a1, 2
/* 0F8708 7F0C3BD8 01661021 */  addu  $v0, $t3, $a2
/* 0F870C 7F0C3BDC 01AE1821 */  addu  $v1, $t5, $t6
/* 0F8710 7F0C3BE0 000A4080 */  sll   $t0, $t2, 2
.L7F0C3BE4:
/* 0F8714 7F0C3BE4 90780069 */  lbu   $t8, 0x69($v1)
/* 0F8718 7F0C3BE8 24C60010 */  addiu $a2, $a2, 0x10
/* 0F871C 7F0C3BEC 50F80005 */  beql  $a3, $t8, .L7F0C3C04
/* 0F8720 7F0C3BF0 8C4F0024 */   lw    $t7, 0x24($v0)
/* 0F8724 7F0C3BF4 8C590024 */  lw    $t9, 0x24($v0)
/* 0F8728 7F0C3BF8 10000003 */  b     .L7F0C3C08
/* 0F872C 7F0C3BFC 00992021 */   addu  $a0, $a0, $t9
/* 0F8730 7F0C3C00 8C4F0024 */  lw    $t7, 0x24($v0)
.L7F0C3C04:
/* 0F8734 7F0C3C04 008F2023 */  subu  $a0, $a0, $t7
.L7F0C3C08:
/* 0F8738 7F0C3C08 906D00D9 */  lbu   $t5, 0xd9($v1)
/* 0F873C 7F0C3C0C 50ED0005 */  beql  $a3, $t5, .L7F0C3C24
/* 0F8740 7F0C3C10 8C580028 */   lw    $t8, 0x28($v0)
/* 0F8744 7F0C3C14 8C4E0028 */  lw    $t6, 0x28($v0)
/* 0F8748 7F0C3C18 10000003 */  b     .L7F0C3C28
/* 0F874C 7F0C3C1C 008E2021 */   addu  $a0, $a0, $t6
/* 0F8750 7F0C3C20 8C580028 */  lw    $t8, 0x28($v0)
.L7F0C3C24:
/* 0F8754 7F0C3C24 00982023 */  subu  $a0, $a0, $t8
.L7F0C3C28:
/* 0F8758 7F0C3C28 90790149 */  lbu   $t9, 0x149($v1)
/* 0F875C 7F0C3C2C 50F90005 */  beql  $a3, $t9, .L7F0C3C44
/* 0F8760 7F0C3C30 8C4D002C */   lw    $t5, 0x2c($v0)
/* 0F8764 7F0C3C34 8C4F002C */  lw    $t7, 0x2c($v0)
/* 0F8768 7F0C3C38 10000003 */  b     .L7F0C3C48
/* 0F876C 7F0C3C3C 008F2021 */   addu  $a0, $a0, $t7
/* 0F8770 7F0C3C40 8C4D002C */  lw    $t5, 0x2c($v0)
.L7F0C3C44:
/* 0F8774 7F0C3C44 008D2023 */  subu  $a0, $a0, $t5
.L7F0C3C48:
/* 0F8778 7F0C3C48 906E01B9 */  lbu   $t6, 0x1b9($v1)
/* 0F877C 7F0C3C4C 246301C0 */  addiu $v1, $v1, 0x1c0
/* 0F8780 7F0C3C50 50EE0005 */  beql  $a3, $t6, .L7F0C3C68
/* 0F8784 7F0C3C54 8C590030 */   lw    $t9, 0x30($v0)
/* 0F8788 7F0C3C58 8C580030 */  lw    $t8, 0x30($v0)
/* 0F878C 7F0C3C5C 10000003 */  b     .L7F0C3C6C
/* 0F8790 7F0C3C60 00982021 */   addu  $a0, $a0, $t8
/* 0F8794 7F0C3C64 8C590030 */  lw    $t9, 0x30($v0)
.L7F0C3C68:
/* 0F8798 7F0C3C68 00992023 */  subu  $a0, $a0, $t9
.L7F0C3C6C:
/* 0F879C 7F0C3C6C 14C8FFDD */  bne   $a2, $t0, .L7F0C3BE4
/* 0F87A0 7F0C3C70 24420010 */   addiu $v0, $v0, 0x10
.L7F0C3C74:
/* 0F87A4 7F0C3C74 25290001 */  addiu $t1, $t1, 1
.L7F0C3C78:
/* 0F87A8 7F0C3C78 152AFFB0 */  bne   $t1, $t2, .L7F0C3B3C
/* 0F87AC 7F0C3C7C 258C0070 */   addiu $t4, $t4, 0x70
def_7F0C394C:
.L7F0C3C80:
/* 0F87B0 7F0C3C80 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0C3C84:
/* 0F87B4 7F0C3C84 27BD0038 */  addiu $sp, $sp, 0x38
/* 0F87B8 7F0C3C88 00801025 */  move  $v0, $a0
/* 0F87BC 7F0C3C8C 03E00008 */  jr    $ra
/* 0F87C0 7F0C3C90 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void write_playerrank_to_buffer(void) {

}
#else
GLOBAL_ASM(
.text
glabel write_playerrank_to_buffer
/* 0F87C4 7F0C3C94 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0F87C8 7F0C3C98 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F87CC 7F0C3C9C AFB00018 */  sw    $s0, 0x18($sp)
/* 0F87D0 7F0C3CA0 AFA40080 */  sw    $a0, 0x80($sp)
/* 0F87D4 7F0C3CA4 0FC051D6 */  jal   get_scenario
/* 0F87D8 7F0C3CA8 AFA50084 */   sw    $a1, 0x84($sp)
/* 0F87DC 7F0C3CAC 0FC26919 */  jal   get_num_players
/* 0F87E0 7F0C3CB0 AFA2007C */   sw    $v0, 0x7c($sp)
/* 0F87E4 7F0C3CB4 00405825 */  move  $t3, $v0
/* 0F87E8 7F0C3CB8 18400013 */  blez  $v0, .L7F0C3D08
/* 0F87EC 7F0C3CBC 00008025 */   move  $s0, $zero
/* 0F87F0 7F0C3CC0 27A30068 */  addiu $v1, $sp, 0x68
/* 0F87F4 7F0C3CC4 27A50058 */  addiu $a1, $sp, 0x58
.L7F0C3CC8:
/* 0F87F8 7F0C3CC8 02002025 */  move  $a0, $s0
/* 0F87FC 7F0C3CCC AFA30038 */  sw    $v1, 0x38($sp)
/* 0F8800 7F0C3CD0 AFA5003C */  sw    $a1, 0x3c($sp)
/* 0F8804 7F0C3CD4 0FC30E36 */  jal   get_points_for_mp_player
/* 0F8808 7F0C3CD8 AFAB0078 */   sw    $t3, 0x78($sp)
/* 0F880C 7F0C3CDC 8FA5003C */  lw    $a1, 0x3c($sp)
/* 0F8810 7F0C3CE0 8FAB0078 */  lw    $t3, 0x78($sp)
/* 0F8814 7F0C3CE4 8FA30038 */  lw    $v1, 0x38($sp)
/* 0F8818 7F0C3CE8 ACB00000 */  sw    $s0, ($a1)
/* 0F881C 7F0C3CEC 26100001 */  addiu $s0, $s0, 1
/* 0F8820 7F0C3CF0 020B082A */  slt   $at, $s0, $t3
/* 0F8824 7F0C3CF4 24A50004 */  addiu $a1, $a1, 4
/* 0F8828 7F0C3CF8 24630004 */  addiu $v1, $v1, 4
/* 0F882C 7F0C3CFC 1420FFF2 */  bnez  $at, .L7F0C3CC8
/* 0F8830 7F0C3D00 AC62FFFC */   sw    $v0, -4($v1)
/* 0F8834 7F0C3D04 00008025 */  move  $s0, $zero
.L7F0C3D08:
/* 0F8838 7F0C3D08 1960003F */  blez  $t3, .L7F0C3E08
/* 0F883C 7F0C3D0C 00005025 */   move  $t2, $zero
/* 0F8840 7F0C3D10 256CFFFF */  addiu $t4, $t3, -1
/* 0F8844 7F0C3D14 27A80058 */  addiu $t0, $sp, 0x58
/* 0F8848 7F0C3D18 8FA50068 */  lw    $a1, 0x68($sp)
/* 0F884C 7F0C3D1C 8FA4006C */  lw    $a0, 0x6c($sp)
.L7F0C3D20:
/* 0F8850 7F0C3D20 19800034 */  blez  $t4, .L7F0C3DF4
/* 0F8854 7F0C3D24 254A0001 */   addiu $t2, $t2, 1
/* 0F8858 7F0C3D28 2562FFFF */  addiu $v0, $t3, -1
/* 0F885C 7F0C3D2C 304E0001 */  andi  $t6, $v0, 1
/* 0F8860 7F0C3D30 11C0000B */  beqz  $t6, .L7F0C3D60
/* 0F8864 7F0C3D34 00A4082A */   slt   $at, $a1, $a0
/* 0F8868 7F0C3D38 10200008 */  beqz  $at, .L7F0C3D5C
/* 0F886C 7F0C3D3C 24100001 */   li    $s0, 1
/* 0F8870 7F0C3D40 00801025 */  move  $v0, $a0
/* 0F8874 7F0C3D44 00A02025 */  move  $a0, $a1
/* 0F8878 7F0C3D48 00402825 */  move  $a1, $v0
/* 0F887C 7F0C3D4C 8FA2005C */  lw    $v0, 0x5c($sp)
/* 0F8880 7F0C3D50 8FAF0058 */  lw    $t7, 0x58($sp)
/* 0F8884 7F0C3D54 AFA20058 */  sw    $v0, 0x58($sp)
/* 0F8888 7F0C3D58 AFAF005C */  sw    $t7, 0x5c($sp)
.L7F0C3D5C:
/* 0F888C 7F0C3D5C 120C0024 */  beq   $s0, $t4, .L7F0C3DF0
.L7F0C3D60:
/* 0F8890 7F0C3D60 27B80068 */   addiu $t8, $sp, 0x68
/* 0F8894 7F0C3D64 00103880 */  sll   $a3, $s0, 2
/* 0F8898 7F0C3D68 000CC880 */  sll   $t9, $t4, 2
/* 0F889C 7F0C3D6C 03384821 */  addu  $t1, $t9, $t8
/* 0F88A0 7F0C3D70 00F81821 */  addu  $v1, $a3, $t8
/* 0F88A4 7F0C3D74 AFA4006C */  sw    $a0, 0x6c($sp)
/* 0F88A8 7F0C3D78 AFA50068 */  sw    $a1, 0x68($sp)
.L7F0C3D7C:
/* 0F88AC 7F0C3D7C 8C660000 */  lw    $a2, ($v1)
/* 0F88B0 7F0C3D80 8C640004 */  lw    $a0, 4($v1)
/* 0F88B4 7F0C3D84 01072821 */  addu  $a1, $t0, $a3
/* 0F88B8 7F0C3D88 00C4082A */  slt   $at, $a2, $a0
/* 0F88BC 7F0C3D8C 50200009 */  beql  $at, $zero, .L7F0C3DB4
/* 0F88C0 7F0C3D90 8C660008 */   lw    $a2, 8($v1)
/* 0F88C4 7F0C3D94 8CA20004 */  lw    $v0, 4($a1)
/* 0F88C8 7F0C3D98 8CAD0000 */  lw    $t5, ($a1)
/* 0F88CC 7F0C3D9C AC640000 */  sw    $a0, ($v1)
/* 0F88D0 7F0C3DA0 AC660004 */  sw    $a2, 4($v1)
/* 0F88D4 7F0C3DA4 00C02025 */  move  $a0, $a2
/* 0F88D8 7F0C3DA8 ACA20000 */  sw    $v0, ($a1)
/* 0F88DC 7F0C3DAC ACAD0004 */  sw    $t5, 4($a1)
/* 0F88E0 7F0C3DB0 8C660008 */  lw    $a2, 8($v1)
.L7F0C3DB4:
/* 0F88E4 7F0C3DB4 01072821 */  addu  $a1, $t0, $a3
/* 0F88E8 7F0C3DB8 0086082A */  slt   $at, $a0, $a2
/* 0F88EC 7F0C3DBC 50200008 */  beql  $at, $zero, .L7F0C3DE0
/* 0F88F0 7F0C3DC0 24630008 */   addiu $v1, $v1, 8
/* 0F88F4 7F0C3DC4 8CA20008 */  lw    $v0, 8($a1)
/* 0F88F8 7F0C3DC8 8CAE0004 */  lw    $t6, 4($a1)
/* 0F88FC 7F0C3DCC AC640008 */  sw    $a0, 8($v1)
/* 0F8900 7F0C3DD0 AC660004 */  sw    $a2, 4($v1)
/* 0F8904 7F0C3DD4 ACA20004 */  sw    $v0, 4($a1)
/* 0F8908 7F0C3DD8 ACAE0008 */  sw    $t6, 8($a1)
/* 0F890C 7F0C3DDC 24630008 */  addiu $v1, $v1, 8
.L7F0C3DE0:
/* 0F8910 7F0C3DE0 8FA4006C */  lw    $a0, 0x6c($sp)
/* 0F8914 7F0C3DE4 8FA50068 */  lw    $a1, 0x68($sp)
/* 0F8918 7F0C3DE8 1469FFE4 */  bne   $v1, $t1, .L7F0C3D7C
/* 0F891C 7F0C3DEC 24E70008 */   addiu $a3, $a3, 8
.L7F0C3DF0:
/* 0F8920 7F0C3DF0 00008025 */  move  $s0, $zero
.L7F0C3DF4:
/* 0F8924 7F0C3DF4 154BFFCA */  bne   $t2, $t3, .L7F0C3D20
/* 0F8928 7F0C3DF8 00000000 */   nop   
/* 0F892C 7F0C3DFC AFA50068 */  sw    $a1, 0x68($sp)
/* 0F8930 7F0C3E00 AFA4006C */  sw    $a0, 0x6c($sp)
/* 0F8934 7F0C3E04 00005025 */  move  $t2, $zero
.L7F0C3E08:
/* 0F8938 7F0C3E08 19600008 */  blez  $t3, .L7F0C3E2C
/* 0F893C 7F0C3E0C 27A50058 */   addiu $a1, $sp, 0x58
/* 0F8940 7F0C3E10 8FA20084 */  lw    $v0, 0x84($sp)
.L7F0C3E14:
/* 0F8944 7F0C3E14 8CAF0000 */  lw    $t7, ($a1)
/* 0F8948 7F0C3E18 104F0004 */  beq   $v0, $t7, .L7F0C3E2C
/* 0F894C 7F0C3E1C 00000000 */   nop   
/* 0F8950 7F0C3E20 26100001 */  addiu $s0, $s0, 1
/* 0F8954 7F0C3E24 160BFFFB */  bne   $s0, $t3, .L7F0C3E14
/* 0F8958 7F0C3E28 24A50004 */   addiu $a1, $a1, 4
.L7F0C3E2C:
/* 0F895C 7F0C3E2C 0600000B */  bltz  $s0, .L7F0C3E5C
/* 0F8960 7F0C3E30 0010C880 */   sll   $t9, $s0, 2
/* 0F8964 7F0C3E34 27A20068 */  addiu $v0, $sp, 0x68
/* 0F8968 7F0C3E38 03226821 */  addu  $t5, $t9, $v0
/* 0F896C 7F0C3E3C 8DA60000 */  lw    $a2, ($t5)
.L7F0C3E40:
/* 0F8970 7F0C3E40 8C4E0000 */  lw    $t6, ($v0)
/* 0F8974 7F0C3E44 260F0001 */  addiu $t7, $s0, 1
/* 0F8978 7F0C3E48 11C60004 */  beq   $t6, $a2, .L7F0C3E5C
/* 0F897C 7F0C3E4C 00000000 */   nop   
/* 0F8980 7F0C3E50 254A0001 */  addiu $t2, $t2, 1
/* 0F8984 7F0C3E54 15EAFFFA */  bne   $t7, $t2, .L7F0C3E40
/* 0F8988 7F0C3E58 24420004 */   addiu $v0, $v0, 4
.L7F0C3E5C:
/* 0F898C 7F0C3E5C 1140000A */  beqz  $t2, .L7F0C3E88
/* 0F8990 7F0C3E60 24010001 */   li    $at, 1
/* 0F8994 7F0C3E64 1141000F */  beq   $t2, $at, .L7F0C3EA4
/* 0F8998 7F0C3E68 24010002 */   li    $at, 2
/* 0F899C 7F0C3E6C 11410014 */  beq   $t2, $at, .L7F0C3EC0
/* 0F89A0 7F0C3E70 8FA2007C */   lw    $v0, 0x7c($sp)
/* 0F89A4 7F0C3E74 24010003 */  li    $at, 3
/* 0F89A8 7F0C3E78 11410024 */  beq   $t2, $at, .L7F0C3F0C
/* 0F89AC 7F0C3E7C 8FB9007C */   lw    $t9, 0x7c($sp)
/* 0F89B0 7F0C3E80 10000032 */  b     .L7F0C3F4C
/* 0F89B4 7F0C3E84 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0C3E88:
/* 0F89B8 7F0C3E88 0FC30776 */  jal   get_textptr_for_textID
/* 0F89BC 7F0C3E8C 3404A011 */   li    $a0, 40977
/* 0F89C0 7F0C3E90 8FA40080 */  lw    $a0, 0x80($sp)
/* 0F89C4 7F0C3E94 0C002B25 */  jal   sprintf
/* 0F89C8 7F0C3E98 00402825 */   move  $a1, $v0
/* 0F89CC 7F0C3E9C 1000002B */  b     .L7F0C3F4C
/* 0F89D0 7F0C3EA0 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0C3EA4:
/* 0F89D4 7F0C3EA4 0FC30776 */  jal   get_textptr_for_textID
/* 0F89D8 7F0C3EA8 3404A012 */   li    $a0, 40978
/* 0F89DC 7F0C3EAC 8FA40080 */  lw    $a0, 0x80($sp)
/* 0F89E0 7F0C3EB0 0C002B25 */  jal   sprintf
/* 0F89E4 7F0C3EB4 00402825 */   move  $a1, $v0
/* 0F89E8 7F0C3EB8 10000024 */  b     .L7F0C3F4C
/* 0F89EC 7F0C3EBC 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0C3EC0:
/* 0F89F0 7F0C3EC0 24010005 */  li    $at, 5
/* 0F89F4 7F0C3EC4 1041000A */  beq   $v0, $at, .L7F0C3EF0
/* 0F89F8 7F0C3EC8 24010007 */   li    $at, 7
/* 0F89FC 7F0C3ECC 10410008 */  beq   $v0, $at, .L7F0C3EF0
/* 0F8A00 7F0C3ED0 00000000 */   nop   
/* 0F8A04 7F0C3ED4 0FC30776 */  jal   get_textptr_for_textID
/* 0F8A08 7F0C3ED8 3404A013 */   li    $a0, 40979
/* 0F8A0C 7F0C3EDC 8FA40080 */  lw    $a0, 0x80($sp)
/* 0F8A10 7F0C3EE0 0C002B25 */  jal   sprintf
/* 0F8A14 7F0C3EE4 00402825 */   move  $a1, $v0
/* 0F8A18 7F0C3EE8 10000018 */  b     .L7F0C3F4C
/* 0F8A1C 7F0C3EEC 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0C3EF0:
/* 0F8A20 7F0C3EF0 0FC30776 */  jal   get_textptr_for_textID
/* 0F8A24 7F0C3EF4 3404A012 */   li    $a0, 40978
/* 0F8A28 7F0C3EF8 8FA40080 */  lw    $a0, 0x80($sp)
/* 0F8A2C 7F0C3EFC 0C002B25 */  jal   sprintf
/* 0F8A30 7F0C3F00 00402825 */   move  $a1, $v0
/* 0F8A34 7F0C3F04 10000011 */  b     .L7F0C3F4C
/* 0F8A38 7F0C3F08 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0C3F0C:
/* 0F8A3C 7F0C3F0C 24010006 */  li    $at, 6
/* 0F8A40 7F0C3F10 13210008 */  beq   $t9, $at, .L7F0C3F34
/* 0F8A44 7F0C3F14 00000000 */   nop   
/* 0F8A48 7F0C3F18 0FC30776 */  jal   get_textptr_for_textID
/* 0F8A4C 7F0C3F1C 3404A014 */   li    $a0, 40980
/* 0F8A50 7F0C3F20 8FA40080 */  lw    $a0, 0x80($sp)
/* 0F8A54 7F0C3F24 0C002B25 */  jal   sprintf
/* 0F8A58 7F0C3F28 00402825 */   move  $a1, $v0
/* 0F8A5C 7F0C3F2C 10000007 */  b     .L7F0C3F4C
/* 0F8A60 7F0C3F30 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0C3F34:
/* 0F8A64 7F0C3F34 0FC30776 */  jal   get_textptr_for_textID
/* 0F8A68 7F0C3F38 3404A012 */   li    $a0, 40978
/* 0F8A6C 7F0C3F3C 8FA40080 */  lw    $a0, 0x80($sp)
/* 0F8A70 7F0C3F40 0C002B25 */  jal   sprintf
/* 0F8A74 7F0C3F44 00402825 */   move  $a1, $v0
/* 0F8A78 7F0C3F48 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0C3F4C:
/* 0F8A7C 7F0C3F4C 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F8A80 7F0C3F50 27BD0080 */  addiu $sp, $sp, 0x80
/* 0F8A84 7F0C3F54 03E00008 */  jr    $ra
/* 0F8A88 7F0C3F58 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void true_if_displaying_rank_in_mp(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BCC0*/
glabel jpt_MP_overlays_scoring_scenario_1
.word not_yolt
.word yolt
.word not_yolt
.word not_yolt
.word not_yolt
.word not_yolt
.word not_yolt
.word not_yolt
.text
glabel true_if_displaying_rank_in_mp
/* 0F8A8C 7F0C3F5C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F8A90 7F0C3F60 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F8A94 7F0C3F64 0FC051D6 */  jal   get_scenario
/* 0F8A98 7F0C3F68 AFA40018 */   sw    $a0, 0x18($sp)
/* 0F8A9C 7F0C3F6C 2C410008 */  sltiu $at, $v0, 8
/* 0F8AA0 7F0C3F70 10200010 */  beqz  $at, .L7F0C3FB4
/* 0F8AA4 7F0C3F74 00027080 */   sll   $t6, $v0, 2
/* 0F8AA8 7F0C3F78 3C018006 */  lui   $at, %hi(jpt_MP_overlays_scoring_scenario_1)
/* 0F8AAC 7F0C3F7C 002E0821 */  addu  $at, $at, $t6
/* 0F8AB0 7F0C3F80 8C2EBCC0 */  lw    $t6, %lo(jpt_MP_overlays_scoring_scenario_1)($at)
/* 0F8AB4 7F0C3F84 01C00008 */  jr    $t6
/* 0F8AB8 7F0C3F88 00000000 */   nop   
not_yolt:
/* 0F8ABC 7F0C3F8C 1000000B */  b     .L7F0C3FBC
/* 0F8AC0 7F0C3F90 24020001 */   li    $v0, 1
yolt:
/* 0F8AC4 7F0C3F94 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0F8AC8 7F0C3F98 24030001 */  li    $v1, 1
/* 0F8ACC 7F0C3F9C 11E00003 */  beqz  $t7, .L7F0C3FAC
/* 0F8AD0 7F0C3FA0 00000000 */   nop   
/* 0F8AD4 7F0C3FA4 10000005 */  b     .L7F0C3FBC
/* 0F8AD8 7F0C3FA8 00001025 */   move  $v0, $zero
.L7F0C3FAC:
/* 0F8ADC 7F0C3FAC 10000003 */  b     .L7F0C3FBC
/* 0F8AE0 7F0C3FB0 00601025 */   move  $v0, $v1
def_7F0C3F84:
.L7F0C3FB4:
/* 0F8AE4 7F0C3FB4 1000FFFF */  b     .L7F0C3FB4
/* 0F8AE8 7F0C3FB8 00000000 */   nop   
.L7F0C3FBC:
/* 0F8AEC 7F0C3FBC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F8AF0 7F0C3FC0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F8AF4 7F0C3FC4 03E00008 */  jr    $ra
/* 0F8AF8 7F0C3FC8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void true_if_displaying_score_in_mp(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005BCE0*/
glabel jpt_MP_overlays_scoring_scenario_2
.word not_yolt_tld
.word yolt_tld
.word yolt_tld
.word not_yolt_tld
.word not_yolt_tld
.word not_yolt_tld
.word not_yolt_tld
/*.word not_yolt_tld*/
.text
glabel true_if_displaying_score_in_mp
/* 0F8AFC 7F0C3FCC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F8B00 7F0C3FD0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F8B04 7F0C3FD4 0FC051D6 */  jal   get_scenario
/* 0F8B08 7F0C3FD8 AFA40018 */   sw    $a0, 0x18($sp)
/* 0F8B0C 7F0C3FDC 2C410008 */  sltiu $at, $v0, 8
/* 0F8B10 7F0C3FE0 1020000A */  beqz  $at, .L7F0C400C
/* 0F8B14 7F0C3FE4 00027080 */   sll   $t6, $v0, 2
/* 0F8B18 7F0C3FE8 3C018006 */  lui   $at, %hi(jpt_MP_overlays_scoring_scenario_2)
/* 0F8B1C 7F0C3FEC 002E0821 */  addu  $at, $at, $t6
/* 0F8B20 7F0C3FF0 8C2EBCE0 */  lw    $t6, %lo(jpt_MP_overlays_scoring_scenario_2)($at)
/* 0F8B24 7F0C3FF4 01C00008 */  jr    $t6
/* 0F8B28 7F0C3FF8 00000000 */   nop   
not_yolt_tld:
/* 0F8B2C 7F0C3FFC 10000005 */  b     .L7F0C4014
/* 0F8B30 7F0C4000 24020001 */   li    $v0, 1
yolt_tld:
/* 0F8B34 7F0C4004 10000003 */  b     .L7F0C4014
/* 0F8B38 7F0C4008 00001025 */   move  $v0, $zero
def_7F0C3FF4:
.L7F0C400C:
/* 0F8B3C 7F0C400C 1000FFFF */  b     .L7F0C400C
/* 0F8B40 7F0C4010 00000000 */   nop   
.L7F0C4014:
/* 0F8B44 7F0C4014 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F8B48 7F0C4018 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F8B4C 7F0C401C 03E00008 */  jr    $ra
/* 0F8B50 7F0C4020 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void mp_watch_menu_display(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
/*jtbl hacks*/
.word not_yolt_tld

/*D:8005BD00*/
glabel jpt_MP_menu_window_text
.word text_play
.word text_play
.word text_play
.word text_play
.word text_pause_unpause
.word text_exit
.word text_exit
.word text_blank

.text
glabel mp_watch_menu_display
/* 0F8B54 7F0C4024 27BDFF28 */  addiu $sp, $sp, -0xd8
/* 0F8B58 7F0C4028 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0F8B5C 7F0C402C AFB10038 */  sw    $s1, 0x38($sp)
/* 0F8B60 7F0C4030 00808825 */  move  $s1, $a0
/* 0F8B64 7F0C4034 0FC26C54 */  jal   get_cur_playernum
/* 0F8B68 7F0C4038 AFB00034 */   sw    $s0, 0x34($sp)
/* 0F8B6C 7F0C403C 0FC26919 */  jal   get_num_players
/* 0F8B70 7F0C4040 AFA200D4 */   sw    $v0, 0xd4($sp)
/* 0F8B74 7F0C4044 24010001 */  li    $at, 1
/* 0F8B78 7F0C4048 00404025 */  move  $t0, $v0
/* 0F8B7C 7F0C404C 14410003 */  bne   $v0, $at, .L7F0C405C
/* 0F8B80 7F0C4050 00008025 */   move  $s0, $zero
/* 0F8B84 7F0C4054 100007F7 */  b     .L7F0C6034
/* 0F8B88 7F0C4058 02201025 */   move  $v0, $s1
.L7F0C405C:
/* 0F8B8C 7F0C405C 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0F8B90 7F0C4060 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0F8B94 7F0C4064 02202025 */  move  $a0, $s1
/* 0F8B98 7F0C4068 8C6E29C4 */  lw    $t6, 0x29c4($v1)
/* 0F8B9C 7F0C406C 51C0076D */  beql  $t6, $zero, .L7F0C5E24
/* 0F8BA0 7F0C4070 8C6E00D8 */   lw    $t6, 0xd8($v1)
/* 0F8BA4 7F0C4074 0FC2B366 */  jal   microcode_constructor
/* 0F8BA8 7F0C4078 AFA800D0 */   sw    $t0, 0xd0($sp)
/* 0F8BAC 7F0C407C 8FAF00D0 */  lw    $t7, 0xd0($sp)
/* 0F8BB0 7F0C4080 24010002 */  li    $at, 2
/* 0F8BB4 7F0C4084 00408825 */  move  $s1, $v0
/* 0F8BB8 7F0C4088 15E10004 */  bne   $t7, $at, .L7F0C409C
/* 0F8BBC 7F0C408C 3C198008 */   lui   $t9, %hi(pPlayer) 
/* 0F8BC0 7F0C4090 24180050 */  li    $t8, 80
/* 0F8BC4 7F0C4094 10000002 */  b     .L7F0C40A0
/* 0F8BC8 7F0C4098 AFB800A8 */   sw    $t8, 0xa8($sp)
.L7F0C409C:
/* 0F8BCC 7F0C409C AFA000A8 */  sw    $zero, 0xa8($sp)
.L7F0C40A0:
/* 0F8BD0 7F0C40A0 8F39A0B0 */  lw    $t9, %lo(pPlayer)($t9)
/* 0F8BD4 7F0C40A4 8F2929C8 */  lw    $t1, 0x29c8($t9)
/* 0F8BD8 7F0C40A8 2D210008 */  sltiu $at, $t1, 8
/* 0F8BDC 7F0C40AC 10200038 */  beqz  $at, .L7F0C4190
/* 0F8BE0 7F0C40B0 00094880 */   sll   $t1, $t1, 2
/* 0F8BE4 7F0C40B4 3C018006 */  lui   $at, %hi(jpt_MP_menu_window_text)
/* 0F8BE8 7F0C40B8 00290821 */  addu  $at, $at, $t1
/* 0F8BEC 7F0C40BC 8C29BD00 */  lw    $t1, %lo(jpt_MP_menu_window_text)($at)
/* 0F8BF0 7F0C40C0 01200008 */  jr    $t1
/* 0F8BF4 7F0C40C4 00000000 */   nop   
text_play:
/* 0F8BF8 7F0C40C8 3C0A8009 */  lui   $t2, %hi(is_gameover_flag) 
/* 0F8BFC 7F0C40CC 8D4AC704 */  lw    $t2, %lo(is_gameover_flag)($t2)
/* 0F8C00 7F0C40D0 3C0B8009 */  lui   $t3, %hi(time_trigger_alt_gameover_msg) 
/* 0F8C04 7F0C40D4 15400005 */  bnez  $t2, .L7F0C40EC
/* 0F8C08 7F0C40D8 00000000 */   nop   
/* 0F8C0C 7F0C40DC 0FC30776 */  jal   get_textptr_for_textID
/* 0F8C10 7F0C40E0 3404A015 */   li    $a0, 40981
/* 0F8C14 7F0C40E4 1000002A */  b     .L7F0C4190
/* 0F8C18 7F0C40E8 AFA200A4 */   sw    $v0, 0xa4($sp)
.L7F0C40EC:
/* 0F8C1C 7F0C40EC 8D6BC710 */  lw    $t3, %lo(time_trigger_alt_gameover_msg)($t3)
/* 0F8C20 7F0C40F0 11600005 */  beqz  $t3, .L7F0C4108
/* 0F8C24 7F0C40F4 00000000 */   nop   
/* 0F8C28 7F0C40F8 0FC30776 */  jal   get_textptr_for_textID
/* 0F8C2C 7F0C40FC 3404A016 */   li    $a0, 40982
/* 0F8C30 7F0C4100 10000023 */  b     .L7F0C4190
/* 0F8C34 7F0C4104 AFA200A4 */   sw    $v0, 0xa4($sp)
.L7F0C4108:
/* 0F8C38 7F0C4108 0FC30776 */  jal   get_textptr_for_textID
/* 0F8C3C 7F0C410C 3404A017 */   li    $a0, 40983
/* 0F8C40 7F0C4110 1000001F */  b     .L7F0C4190
/* 0F8C44 7F0C4114 AFA200A4 */   sw    $v0, 0xa4($sp)
text_blank:
/* 0F8C48 7F0C4118 3C0C8006 */  lui   $t4, %hi(ascii_MP_watch_menu_BLANK) 
/* 0F8C4C 7F0C411C 258CBC24 */  addiu $t4, %lo(ascii_MP_watch_menu_BLANK) # addiu $t4, $t4, -0x43dc
/* 0F8C50 7F0C4120 1000001B */  b     .L7F0C4190
/* 0F8C54 7F0C4124 AFAC00A4 */   sw    $t4, 0xa4($sp)
text_pause_unpause:
/* 0F8C58 7F0C4128 3C0D8009 */  lui   $t5, %hi(is_paused) 
/* 0F8C5C 7F0C412C 8DADC718 */  lw    $t5, %lo(is_paused)($t5)
/* 0F8C60 7F0C4130 11A0000B */  beqz  $t5, .L7F0C4160
/* 0F8C64 7F0C4134 00000000 */   nop   
/* 0F8C68 7F0C4138 0FC30776 */  jal   get_textptr_for_textID
/* 0F8C6C 7F0C413C 3404A018 */   li    $a0, 40984
/* 0F8C70 7F0C4140 0FC26C54 */  jal   get_cur_playernum
/* 0F8C74 7F0C4144 AFA200A4 */   sw    $v0, 0xa4($sp)
/* 0F8C78 7F0C4148 3C0E8009 */  lui   $t6, %hi(who_paused) 
/* 0F8C7C 7F0C414C 8DCEC71C */  lw    $t6, %lo(who_paused)($t6)
/* 0F8C80 7F0C4150 144E000F */  bne   $v0, $t6, .L7F0C4190
/* 0F8C84 7F0C4154 00000000 */   nop   
/* 0F8C88 7F0C4158 1000000D */  b     .L7F0C4190
/* 0F8C8C 7F0C415C 24100001 */   li    $s0, 1
.L7F0C4160:
/* 0F8C90 7F0C4160 0FC30776 */  jal   get_textptr_for_textID
/* 0F8C94 7F0C4164 3404A019 */   li    $a0, 40985
/* 0F8C98 7F0C4168 10000009 */  b     .L7F0C4190
/* 0F8C9C 7F0C416C AFA200A4 */   sw    $v0, 0xa4($sp)
text_exit:
/* 0F8CA0 7F0C4170 0FC30776 */  jal   get_textptr_for_textID
/* 0F8CA4 7F0C4174 3404A01A */   li    $a0, 40986
/* 0F8CA8 7F0C4178 0C001145 */  jal   get_video2_settings_ulx
/* 0F8CAC 7F0C417C AFA200A4 */   sw    $v0, 0xa4($sp)
/* 0F8CB0 7F0C4180 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0F8CB4 7F0C4184 004F2021 */  addu  $a0, $v0, $t7
/* 0F8CB8 7F0C4188 24840041 */  addiu $a0, $a0, 0x41
/* 0F8CBC 7F0C418C AFA400CC */  sw    $a0, 0xcc($sp)
def_7F0C40C0:
.L7F0C4190:
/* 0F8CC0 7F0C4190 3C188004 */  lui   $t8, %hi(ptrFirstFontTableSmall) 
/* 0F8CC4 7F0C4194 8F180EAC */  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
/* 0F8CC8 7F0C4198 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0F8CCC 7F0C419C 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0F8CD0 7F0C41A0 27A400BC */  addiu $a0, $sp, 0xbc
/* 0F8CD4 7F0C41A4 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0F8CD8 7F0C41A8 8FA600A4 */  lw    $a2, 0xa4($sp)
/* 0F8CDC 7F0C41AC AFA00014 */  sw    $zero, 0x14($sp)
/* 0F8CE0 7F0C41B0 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0F8CE4 7F0C41B4 AFB80010 */   sw    $t8, 0x10($sp)
/* 0F8CE8 7F0C41B8 0C001145 */  jal   get_video2_settings_ulx
/* 0F8CEC 7F0C41BC 00000000 */   nop   
/* 0F8CF0 7F0C41C0 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0F8CF4 7F0C41C4 8FAA00C0 */  lw    $t2, 0xc0($sp)
/* 0F8CF8 7F0C41C8 00594821 */  addu  $t1, $v0, $t9
/* 0F8CFC 7F0C41CC 000A5843 */  sra   $t3, $t2, 1
/* 0F8D00 7F0C41D0 012B2023 */  subu  $a0, $t1, $t3
/* 0F8D04 7F0C41D4 24840050 */  addiu $a0, $a0, 0x50
/* 0F8D08 7F0C41D8 0C001149 */  jal   get_video2_settings_uly
/* 0F8D0C 7F0C41DC AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F8D10 7F0C41E0 8FAC00BC */  lw    $t4, 0xbc($sp)
/* 0F8D14 7F0C41E4 000C6843 */  sra   $t5, $t4, 1
/* 0F8D18 7F0C41E8 004D7023 */  subu  $t6, $v0, $t5
/* 0F8D1C 7F0C41EC 25CF0016 */  addiu $t7, $t6, 0x16
/* 0F8D20 7F0C41F0 1200001E */  beqz  $s0, .L7F0C426C
/* 0F8D24 7F0C41F4 AFAF00C8 */   sw    $t7, 0xc8($sp)
/* 0F8D28 7F0C41F8 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F8D2C 7F0C41FC 00000000 */   nop   
/* 0F8D30 7F0C4200 00028400 */  sll   $s0, $v0, 0x10
/* 0F8D34 7F0C4204 0010C403 */  sra   $t8, $s0, 0x10
/* 0F8D38 7F0C4208 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F8D3C 7F0C420C 03008025 */   move  $s0, $t8
/* 0F8D40 7F0C4210 3C198004 */  lui   $t9, %hi(ptrSecondFontTableSmall) 
/* 0F8D44 7F0C4214 3C0A8004 */  lui   $t2, %hi(ptrFirstFontTableSmall) 
/* 0F8D48 7F0C4218 8D4A0EAC */  lw    $t2, %lo(ptrFirstFontTableSmall)($t2)
/* 0F8D4C 7F0C421C 8F390EB0 */  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
/* 0F8D50 7F0C4220 3C09A0FF */  lui   $t1, (0xA0FFA0F0 >> 16) # lui $t1, 0xa0ff
/* 0F8D54 7F0C4224 3C0B0070 */  lui   $t3, (0x007000A0 >> 16) # lui $t3, 0x70
/* 0F8D58 7F0C4228 356B00A0 */  ori   $t3, (0x007000A0 & 0xFFFF) # ori $t3, $t3, 0xa0
/* 0F8D5C 7F0C422C 3529A0F0 */  ori   $t1, (0xA0FFA0F0 & 0xFFFF) # ori $t1, $t1, 0xa0f0
/* 0F8D60 7F0C4230 AFA90018 */  sw    $t1, 0x18($sp)
/* 0F8D64 7F0C4234 AFAB001C */  sw    $t3, 0x1c($sp)
/* 0F8D68 7F0C4238 02202025 */  move  $a0, $s1
/* 0F8D6C 7F0C423C 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F8D70 7F0C4240 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F8D74 7F0C4244 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0F8D78 7F0C4248 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F8D7C 7F0C424C AFA20024 */  sw    $v0, 0x24($sp)
/* 0F8D80 7F0C4250 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F8D84 7F0C4254 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0F8D88 7F0C4258 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0F8D8C 7F0C425C 0FC2B9BB */  jal   jp_text_write_stuff
/* 0F8D90 7F0C4260 AFB90010 */   sw    $t9, 0x10($sp)
/* 0F8D94 7F0C4264 1000001A */  b     .L7F0C42D0
/* 0F8D98 7F0C4268 00408825 */   move  $s1, $v0
.L7F0C426C:
/* 0F8D9C 7F0C426C 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F8DA0 7F0C4270 00000000 */   nop   
/* 0F8DA4 7F0C4274 00028400 */  sll   $s0, $v0, 0x10
/* 0F8DA8 7F0C4278 00106403 */  sra   $t4, $s0, 0x10
/* 0F8DAC 7F0C427C 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F8DB0 7F0C4280 01808025 */   move  $s0, $t4
/* 0F8DB4 7F0C4284 3C0D8004 */  lui   $t5, %hi(ptrSecondFontTableSmall) 
/* 0F8DB8 7F0C4288 3C0E8004 */  lui   $t6, %hi(ptrFirstFontTableSmall) 
/* 0F8DBC 7F0C428C 8DCE0EAC */  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
/* 0F8DC0 7F0C4290 8DAD0EB0 */  lw    $t5, %lo(ptrSecondFontTableSmall)($t5)
/* 0F8DC4 7F0C4294 3C0F00FF */  lui   $t7, (0x00FF00B0 >> 16) # lui $t7, 0xff
/* 0F8DC8 7F0C4298 35EF00B0 */  ori   $t7, (0x00FF00B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0F8DCC 7F0C429C AFAF0018 */  sw    $t7, 0x18($sp)
/* 0F8DD0 7F0C42A0 02202025 */  move  $a0, $s1
/* 0F8DD4 7F0C42A4 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F8DD8 7F0C42A8 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F8DDC 7F0C42AC 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0F8DE0 7F0C42B0 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F8DE4 7F0C42B4 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F8DE8 7F0C42B8 AFA00024 */  sw    $zero, 0x24($sp)
/* 0F8DEC 7F0C42BC AFA00028 */  sw    $zero, 0x28($sp)
/* 0F8DF0 7F0C42C0 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0F8DF4 7F0C42C4 0FC2B6AF */  jal   en_text_write_stuff
/* 0F8DF8 7F0C42C8 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0F8DFC 7F0C42CC 00408825 */  move  $s1, $v0
.L7F0C42D0:
/* 0F8E00 7F0C42D0 0FC307A3 */  jal   check_can_advance_left_on_mpmenu
/* 0F8E04 7F0C42D4 00000000 */   nop   
/* 0F8E08 7F0C42D8 10400056 */  beqz  $v0, .L7F0C4434
/* 0F8E0C 7F0C42DC 00000000 */   nop   
/* 0F8E10 7F0C42E0 0C001145 */  jal   get_video2_settings_ulx
/* 0F8E14 7F0C42E4 00000000 */   nop   
/* 0F8E18 7F0C42E8 3C038009 */  lui   $v1, %hi(is_gameover_flag)
/* 0F8E1C 7F0C42EC 8C63C704 */  lw    $v1, %lo(is_gameover_flag)($v1)
/* 0F8E20 7F0C42F0 0002CC00 */  sll   $t9, $v0, 0x10
/* 0F8E24 7F0C42F4 2418000A */  li    $t8, 10
/* 0F8E28 7F0C42F8 50600004 */  beql  $v1, $zero, .L7F0C430C
/* 0F8E2C 7F0C42FC AFA00050 */   sw    $zero, 0x50($sp)
/* 0F8E30 7F0C4300 10000002 */  b     .L7F0C430C
/* 0F8E34 7F0C4304 AFB80050 */   sw    $t8, 0x50($sp)
/* 0F8E38 7F0C4308 AFA00050 */  sw    $zero, 0x50($sp)
.L7F0C430C:
/* 0F8E3C 7F0C430C 8FA900A8 */  lw    $t1, 0xa8($sp)
/* 0F8E40 7F0C4310 8FAC0050 */  lw    $t4, 0x50($sp)
/* 0F8E44 7F0C4314 00195403 */  sra   $t2, $t9, 0x10
/* 0F8E48 7F0C4318 01495821 */  addu  $t3, $t2, $t1
/* 0F8E4C 7F0C431C 016C2023 */  subu  $a0, $t3, $t4
/* 0F8E50 7F0C4320 24840028 */  addiu $a0, $a0, 0x28
/* 0F8E54 7F0C4324 10600003 */  beqz  $v1, .L7F0C4334
/* 0F8E58 7F0C4328 AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F8E5C 7F0C432C 2484FFF8 */  addiu $a0, $a0, -8
/* 0F8E60 7F0C4330 AFA400CC */  sw    $a0, 0xcc($sp)
.L7F0C4334:
/* 0F8E64 7F0C4334 0C001149 */  jal   get_video2_settings_uly
/* 0F8E68 7F0C4338 00000000 */   nop   
/* 0F8E6C 7F0C433C 3C0E8009 */  lui   $t6, %hi(dword_CODE_bss_8008C708) 
/* 0F8E70 7F0C4340 8DCEC708 */  lw    $t6, %lo(dword_CODE_bss_8008C708)($t6)
/* 0F8E74 7F0C4344 244D0016 */  addiu $t5, $v0, 0x16
/* 0F8E78 7F0C4348 AFAD00C8 */  sw    $t5, 0xc8($sp)
/* 0F8E7C 7F0C434C 15C0001C */  bnez  $t6, .L7F0C43C0
/* 0F8E80 7F0C4350 00000000 */   nop   
/* 0F8E84 7F0C4354 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F8E88 7F0C4358 00000000 */   nop   
/* 0F8E8C 7F0C435C 00028400 */  sll   $s0, $v0, 0x10
/* 0F8E90 7F0C4360 00107C03 */  sra   $t7, $s0, 0x10
/* 0F8E94 7F0C4364 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F8E98 7F0C4368 01E08025 */   move  $s0, $t7
/* 0F8E9C 7F0C436C 3C188004 */  lui   $t8, %hi(ptrSecondFontTableSmall) 
/* 0F8EA0 7F0C4370 3C198004 */  lui   $t9, %hi(ptrFirstFontTableSmall) 
/* 0F8EA4 7F0C4374 8F390EAC */  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
/* 0F8EA8 7F0C4378 8F180EB0 */  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
/* 0F8EAC 7F0C437C 3C0A00FF */  lui   $t2, (0x00FF00B0 >> 16) # lui $t2, 0xff
/* 0F8EB0 7F0C4380 354A00B0 */  ori   $t2, (0x00FF00B0 & 0xFFFF) # ori $t2, $t2, 0xb0
/* 0F8EB4 7F0C4384 3C078006 */  lui   $a3, %hi(ascii_MP_watch_menu_left_chevron)
/* 0F8EB8 7F0C4388 24E7BC28 */  addiu $a3, %lo(ascii_MP_watch_menu_left_chevron) # addiu $a3, $a3, -0x43d8
/* 0F8EBC 7F0C438C AFAA0018 */  sw    $t2, 0x18($sp)
/* 0F8EC0 7F0C4390 02202025 */  move  $a0, $s1
/* 0F8EC4 7F0C4394 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F8EC8 7F0C4398 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F8ECC 7F0C439C AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F8ED0 7F0C43A0 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F8ED4 7F0C43A4 AFA00024 */  sw    $zero, 0x24($sp)
/* 0F8ED8 7F0C43A8 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F8EDC 7F0C43AC AFB90014 */  sw    $t9, 0x14($sp)
/* 0F8EE0 7F0C43B0 0FC2B6AF */  jal   en_text_write_stuff
/* 0F8EE4 7F0C43B4 AFB80010 */   sw    $t8, 0x10($sp)
/* 0F8EE8 7F0C43B8 1000001E */  b     .L7F0C4434
/* 0F8EEC 7F0C43BC 00408825 */   move  $s1, $v0
.L7F0C43C0:
/* 0F8EF0 7F0C43C0 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F8EF4 7F0C43C4 00000000 */   nop   
/* 0F8EF8 7F0C43C8 00028400 */  sll   $s0, $v0, 0x10
/* 0F8EFC 7F0C43CC 00104C03 */  sra   $t1, $s0, 0x10
/* 0F8F00 7F0C43D0 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F8F04 7F0C43D4 01208025 */   move  $s0, $t1
/* 0F8F08 7F0C43D8 3C0B8004 */  lui   $t3, %hi(ptrSecondFontTableSmall) 
/* 0F8F0C 7F0C43DC 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) 
/* 0F8F10 7F0C43E0 8D8C0EAC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0F8F14 7F0C43E4 8D6B0EB0 */  lw    $t3, %lo(ptrSecondFontTableSmall)($t3)
/* 0F8F18 7F0C43E8 3C0DA0FF */  lui   $t5, (0xA0FFA0F0 >> 16) # lui $t5, 0xa0ff
/* 0F8F1C 7F0C43EC 3C0E0070 */  lui   $t6, (0x007000A0 >> 16) # lui $t6, 0x70
/* 0F8F20 7F0C43F0 35CE00A0 */  ori   $t6, (0x007000A0 & 0xFFFF) # ori $t6, $t6, 0xa0
/* 0F8F24 7F0C43F4 35ADA0F0 */  ori   $t5, (0xA0FFA0F0 & 0xFFFF) # ori $t5, $t5, 0xa0f0
/* 0F8F28 7F0C43F8 3C078006 */  lui   $a3, %hi(ascii_MP_watch_menu_left_chevron)
/* 0F8F2C 7F0C43FC 24E7BC28 */  addiu $a3, %lo(ascii_MP_watch_menu_left_chevron) # addiu $a3, $a3, -0x43d8
/* 0F8F30 7F0C4400 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0F8F34 7F0C4404 AFAE001C */  sw    $t6, 0x1c($sp)
/* 0F8F38 7F0C4408 02202025 */  move  $a0, $s1
/* 0F8F3C 7F0C440C 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F8F40 7F0C4410 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F8F44 7F0C4414 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F8F48 7F0C4418 AFA20024 */  sw    $v0, 0x24($sp)
/* 0F8F4C 7F0C441C AFA00028 */  sw    $zero, 0x28($sp)
/* 0F8F50 7F0C4420 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0F8F54 7F0C4424 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0F8F58 7F0C4428 0FC2B9BB */  jal   jp_text_write_stuff
/* 0F8F5C 7F0C442C AFAB0010 */   sw    $t3, 0x10($sp)
/* 0F8F60 7F0C4430 00408825 */  move  $s1, $v0
.L7F0C4434:
/* 0F8F64 7F0C4434 0FC30788 */  jal   check_can_advance_right_on_mpmenu
/* 0F8F68 7F0C4438 00000000 */   nop   
/* 0F8F6C 7F0C443C 10400056 */  beqz  $v0, .L7F0C4598
/* 0F8F70 7F0C4440 00000000 */   nop   
/* 0F8F74 7F0C4444 0C001145 */  jal   get_video2_settings_ulx
/* 0F8F78 7F0C4448 00000000 */   nop   
/* 0F8F7C 7F0C444C 3C038009 */  lui   $v1, %hi(is_gameover_flag)
/* 0F8F80 7F0C4450 8C63C704 */  lw    $v1, %lo(is_gameover_flag)($v1)
/* 0F8F84 7F0C4454 0002CC00 */  sll   $t9, $v0, 0x10
/* 0F8F88 7F0C4458 240F000A */  li    $t7, 10
/* 0F8F8C 7F0C445C 50600004 */  beql  $v1, $zero, .L7F0C4470
/* 0F8F90 7F0C4460 AFA00050 */   sw    $zero, 0x50($sp)
/* 0F8F94 7F0C4464 10000002 */  b     .L7F0C4470
/* 0F8F98 7F0C4468 AFAF0050 */   sw    $t7, 0x50($sp)
/* 0F8F9C 7F0C446C AFA00050 */  sw    $zero, 0x50($sp)
.L7F0C4470:
/* 0F8FA0 7F0C4470 8FB80050 */  lw    $t8, 0x50($sp)
/* 0F8FA4 7F0C4474 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0F8FA8 7F0C4478 00195403 */  sra   $t2, $t9, 0x10
/* 0F8FAC 7F0C447C 030A4821 */  addu  $t1, $t8, $t2
/* 0F8FB0 7F0C4480 012B2021 */  addu  $a0, $t1, $t3
/* 0F8FB4 7F0C4484 24840070 */  addiu $a0, $a0, 0x70
/* 0F8FB8 7F0C4488 10600003 */  beqz  $v1, .L7F0C4498
/* 0F8FBC 7F0C448C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F8FC0 7F0C4490 24840008 */  addiu $a0, $a0, 8
/* 0F8FC4 7F0C4494 AFA400CC */  sw    $a0, 0xcc($sp)
.L7F0C4498:
/* 0F8FC8 7F0C4498 0C001149 */  jal   get_video2_settings_uly
/* 0F8FCC 7F0C449C 00000000 */   nop   
/* 0F8FD0 7F0C44A0 3C0D8009 */  lui   $t5, %hi(dword_CODE_bss_8008C708) 
/* 0F8FD4 7F0C44A4 8DADC708 */  lw    $t5, %lo(dword_CODE_bss_8008C708)($t5)
/* 0F8FD8 7F0C44A8 244C0016 */  addiu $t4, $v0, 0x16
/* 0F8FDC 7F0C44AC AFAC00C8 */  sw    $t4, 0xc8($sp)
/* 0F8FE0 7F0C44B0 15A0001C */  bnez  $t5, .L7F0C4524
/* 0F8FE4 7F0C44B4 00000000 */   nop   
/* 0F8FE8 7F0C44B8 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F8FEC 7F0C44BC 00000000 */   nop   
/* 0F8FF0 7F0C44C0 00028400 */  sll   $s0, $v0, 0x10
/* 0F8FF4 7F0C44C4 00107403 */  sra   $t6, $s0, 0x10
/* 0F8FF8 7F0C44C8 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F8FFC 7F0C44CC 01C08025 */   move  $s0, $t6
/* 0F9000 7F0C44D0 3C0F8004 */  lui   $t7, %hi(ptrSecondFontTableSmall) 
/* 0F9004 7F0C44D4 3C198004 */  lui   $t9, %hi(ptrFirstFontTableSmall) 
/* 0F9008 7F0C44D8 8F390EAC */  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
/* 0F900C 7F0C44DC 8DEF0EB0 */  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
/* 0F9010 7F0C44E0 3C1800FF */  lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
/* 0F9014 7F0C44E4 371800B0 */  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0F9018 7F0C44E8 3C078006 */  lui   $a3, %hi(ascii_MP_watch_menu_right_chevron)
/* 0F901C 7F0C44EC 24E7BC2C */  addiu $a3, %lo(ascii_MP_watch_menu_right_chevron) # addiu $a3, $a3, -0x43d4
/* 0F9020 7F0C44F0 AFB80018 */  sw    $t8, 0x18($sp)
/* 0F9024 7F0C44F4 02202025 */  move  $a0, $s1
/* 0F9028 7F0C44F8 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F902C 7F0C44FC 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9030 7F0C4500 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F9034 7F0C4504 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F9038 7F0C4508 AFA00024 */  sw    $zero, 0x24($sp)
/* 0F903C 7F0C450C AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9040 7F0C4510 AFB90014 */  sw    $t9, 0x14($sp)
/* 0F9044 7F0C4514 0FC2B6AF */  jal   en_text_write_stuff
/* 0F9048 7F0C4518 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0F904C 7F0C451C 1000001E */  b     .L7F0C4598
/* 0F9050 7F0C4520 00408825 */   move  $s1, $v0
.L7F0C4524:
/* 0F9054 7F0C4524 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F9058 7F0C4528 00000000 */   nop   
/* 0F905C 7F0C452C 00028400 */  sll   $s0, $v0, 0x10
/* 0F9060 7F0C4530 00105403 */  sra   $t2, $s0, 0x10
/* 0F9064 7F0C4534 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F9068 7F0C4538 01408025 */   move  $s0, $t2
/* 0F906C 7F0C453C 3C098004 */  lui   $t1, %hi(ptrSecondFontTableSmall) 
/* 0F9070 7F0C4540 3C0B8004 */  lui   $t3, %hi(ptrFirstFontTableSmall) 
/* 0F9074 7F0C4544 8D6B0EAC */  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
/* 0F9078 7F0C4548 8D290EB0 */  lw    $t1, %lo(ptrSecondFontTableSmall)($t1)
/* 0F907C 7F0C454C 3C0CA0FF */  lui   $t4, (0xA0FFA0F0 >> 16) # lui $t4, 0xa0ff
/* 0F9080 7F0C4550 3C0D0070 */  lui   $t5, (0x007000A0 >> 16) # lui $t5, 0x70
/* 0F9084 7F0C4554 35AD00A0 */  ori   $t5, (0x007000A0 & 0xFFFF) # ori $t5, $t5, 0xa0
/* 0F9088 7F0C4558 358CA0F0 */  ori   $t4, (0xA0FFA0F0 & 0xFFFF) # ori $t4, $t4, 0xa0f0
/* 0F908C 7F0C455C 3C078006 */  lui   $a3, %hi(ascii_MP_watch_menu_right_chevron)
/* 0F9090 7F0C4560 24E7BC2C */  addiu $a3, %lo(ascii_MP_watch_menu_right_chevron) # addiu $a3, $a3, -0x43d4
/* 0F9094 7F0C4564 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0F9098 7F0C4568 AFAD001C */  sw    $t5, 0x1c($sp)
/* 0F909C 7F0C456C 02202025 */  move  $a0, $s1
/* 0F90A0 7F0C4570 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F90A4 7F0C4574 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F90A8 7F0C4578 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F90AC 7F0C457C AFA20024 */  sw    $v0, 0x24($sp)
/* 0F90B0 7F0C4580 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F90B4 7F0C4584 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0F90B8 7F0C4588 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0F90BC 7F0C458C 0FC2B9BB */  jal   jp_text_write_stuff
/* 0F90C0 7F0C4590 AFA90010 */   sw    $t1, 0x10($sp)
/* 0F90C4 7F0C4594 00408825 */  move  $s1, $v0
.L7F0C4598:
/* 0F90C8 7F0C4598 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0F90CC 7F0C459C 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0F90D0 7F0C45A0 24010003 */  li    $at, 3
/* 0F90D4 7F0C45A4 8FAE00D0 */  lw    $t6, 0xd0($sp)
/* 0F90D8 7F0C45A8 8C6229C8 */  lw    $v0, 0x29c8($v1)
/* 0F90DC 7F0C45AC 10410003 */  beq   $v0, $at, .L7F0C45BC
/* 0F90E0 7F0C45B0 24010004 */   li    $at, 4
/* 0F90E4 7F0C45B4 544101AA */  bnel  $v0, $at, .L7F0C4C60
/* 0F90E8 7F0C45B8 24010002 */   li    $at, 2
.L7F0C45BC:
/* 0F90EC 7F0C45BC 19C0000D */  blez  $t6, .L7F0C45F4
/* 0F90F0 7F0C45C0 00002025 */   move  $a0, $zero
/* 0F90F4 7F0C45C4 27A30094 */  addiu $v1, $sp, 0x94
/* 0F90F8 7F0C45C8 AFA30044 */  sw    $v1, 0x44($sp)
.L7F0C45CC:
/* 0F90FC 7F0C45CC 0FC30E36 */  jal   get_points_for_mp_player
/* 0F9100 7F0C45D0 AFA40090 */   sw    $a0, 0x90($sp)
/* 0F9104 7F0C45D4 8FA30044 */  lw    $v1, 0x44($sp)
/* 0F9108 7F0C45D8 8FA40090 */  lw    $a0, 0x90($sp)
/* 0F910C 7F0C45DC AC620000 */  sw    $v0, ($v1)
/* 0F9110 7F0C45E0 8FAF00D0 */  lw    $t7, 0xd0($sp)
/* 0F9114 7F0C45E4 24840001 */  addiu $a0, $a0, 1
/* 0F9118 7F0C45E8 24630004 */  addiu $v1, $v1, 4
/* 0F911C 7F0C45EC 548FFFF7 */  bnel  $a0, $t7, .L7F0C45CC
/* 0F9120 7F0C45F0 AFA30044 */   sw    $v1, 0x44($sp)
.L7F0C45F4:
/* 0F9124 7F0C45F4 3C048009 */  lui   $a0, %hi(is_gameover_flag)
/* 0F9128 7F0C45F8 8C84C704 */  lw    $a0, %lo(is_gameover_flag)($a0)
/* 0F912C 7F0C45FC 2C990001 */  sltiu $t9, $a0, 1
/* 0F9130 7F0C4600 13200005 */  beqz  $t9, .L7F0C4618
/* 0F9134 7F0C4604 03202025 */   move  $a0, $t9
/* 0F9138 7F0C4608 3C048009 */  lui   $a0, %hi(stop_play_flag)
/* 0F913C 7F0C460C 8C84C700 */  lw    $a0, %lo(stop_play_flag)($a0)
/* 0F9140 7F0C4610 2C980001 */  sltiu $t8, $a0, 1
/* 0F9144 7F0C4614 03002025 */  move  $a0, $t8
.L7F0C4618:
/* 0F9148 7F0C4618 0FC30FD7 */  jal   true_if_displaying_rank_in_mp
/* 0F914C 7F0C461C 00000000 */   nop   
/* 0F9150 7F0C4620 10400034 */  beqz  $v0, .L7F0C46F4
/* 0F9154 7F0C4624 27A400AC */   addiu $a0, $sp, 0xac
/* 0F9158 7F0C4628 0FC30F25 */  jal   write_playerrank_to_buffer
/* 0F915C 7F0C462C 8FA500D4 */   lw    $a1, 0xd4($sp)
/* 0F9160 7F0C4630 3C0A8004 */  lui   $t2, %hi(ptrFirstFontTableSmall) 
/* 0F9164 7F0C4634 8D4A0EAC */  lw    $t2, %lo(ptrFirstFontTableSmall)($t2)
/* 0F9168 7F0C4638 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0F916C 7F0C463C 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0F9170 7F0C4640 27A400BC */  addiu $a0, $sp, 0xbc
/* 0F9174 7F0C4644 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0F9178 7F0C4648 27A600AC */  addiu $a2, $sp, 0xac
/* 0F917C 7F0C464C AFA00014 */  sw    $zero, 0x14($sp)
/* 0F9180 7F0C4650 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0F9184 7F0C4654 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0F9188 7F0C4658 0C001145 */  jal   get_video2_settings_ulx
/* 0F918C 7F0C465C 00000000 */   nop   
/* 0F9190 7F0C4660 8FA900A8 */  lw    $t1, 0xa8($sp)
/* 0F9194 7F0C4664 8FAC00C0 */  lw    $t4, 0xc0($sp)
/* 0F9198 7F0C4668 00495821 */  addu  $t3, $v0, $t1
/* 0F919C 7F0C466C 000C6843 */  sra   $t5, $t4, 1
/* 0F91A0 7F0C4670 016D2023 */  subu  $a0, $t3, $t5
/* 0F91A4 7F0C4674 24840050 */  addiu $a0, $a0, 0x50
/* 0F91A8 7F0C4678 0C001149 */  jal   get_video2_settings_uly
/* 0F91AC 7F0C467C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F91B0 7F0C4680 8FAE00BC */  lw    $t6, 0xbc($sp)
/* 0F91B4 7F0C4684 000E7843 */  sra   $t7, $t6, 1
/* 0F91B8 7F0C4688 004FC823 */  subu  $t9, $v0, $t7
/* 0F91BC 7F0C468C 27380025 */  addiu $t8, $t9, 0x25
/* 0F91C0 7F0C4690 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F91C4 7F0C4694 AFB800C8 */   sw    $t8, 0xc8($sp)
/* 0F91C8 7F0C4698 00028400 */  sll   $s0, $v0, 0x10
/* 0F91CC 7F0C469C 00105403 */  sra   $t2, $s0, 0x10
/* 0F91D0 7F0C46A0 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F91D4 7F0C46A4 01408025 */   move  $s0, $t2
/* 0F91D8 7F0C46A8 3C098004 */  lui   $t1, %hi(ptrSecondFontTableSmall) 
/* 0F91DC 7F0C46AC 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) 
/* 0F91E0 7F0C46B0 8D8C0EAC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0F91E4 7F0C46B4 8D290EB0 */  lw    $t1, %lo(ptrSecondFontTableSmall)($t1)
/* 0F91E8 7F0C46B8 3C0B00FF */  lui   $t3, (0x00FF00B0 >> 16) # lui $t3, 0xff
/* 0F91EC 7F0C46BC 356B00B0 */  ori   $t3, (0x00FF00B0 & 0xFFFF) # ori $t3, $t3, 0xb0
/* 0F91F0 7F0C46C0 AFAB0018 */  sw    $t3, 0x18($sp)
/* 0F91F4 7F0C46C4 02202025 */  move  $a0, $s1
/* 0F91F8 7F0C46C8 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F91FC 7F0C46CC 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9200 7F0C46D0 27A700AC */  addiu $a3, $sp, 0xac
/* 0F9204 7F0C46D4 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F9208 7F0C46D8 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F920C 7F0C46DC AFA00024 */  sw    $zero, 0x24($sp)
/* 0F9210 7F0C46E0 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9214 7F0C46E4 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0F9218 7F0C46E8 0FC2B6AF */  jal   en_text_write_stuff
/* 0F921C 7F0C46EC AFA90010 */   sw    $t1, 0x10($sp)
/* 0F9220 7F0C46F0 00408825 */  move  $s1, $v0
.L7F0C46F4:
/* 0F9224 7F0C46F4 3C048009 */  lui   $a0, %hi(is_gameover_flag)
/* 0F9228 7F0C46F8 8C84C704 */  lw    $a0, %lo(is_gameover_flag)($a0)
/* 0F922C 7F0C46FC 2C8D0001 */  sltiu $t5, $a0, 1
/* 0F9230 7F0C4700 11A00005 */  beqz  $t5, .L7F0C4718
/* 0F9234 7F0C4704 01A02025 */   move  $a0, $t5
/* 0F9238 7F0C4708 3C048009 */  lui   $a0, %hi(stop_play_flag)
/* 0F923C 7F0C470C 8C84C700 */  lw    $a0, %lo(stop_play_flag)($a0)
/* 0F9240 7F0C4710 2C8E0001 */  sltiu $t6, $a0, 1
/* 0F9244 7F0C4714 01C02025 */  move  $a0, $t6
.L7F0C4718:
/* 0F9248 7F0C4718 0FC30FF3 */  jal   true_if_displaying_score_in_mp
/* 0F924C 7F0C471C 00000000 */   nop   
/* 0F9250 7F0C4720 1040014B */  beqz  $v0, .L7F0C4C50
/* 0F9254 7F0C4724 00000000 */   nop   
/* 0F9258 7F0C4728 0FC051D6 */  jal   get_scenario
/* 0F925C 7F0C472C 00000000 */   nop   
/* 0F9260 7F0C4730 AFA20080 */  sw    $v0, 0x80($sp)
/* 0F9264 7F0C4734 0FC30776 */  jal   get_textptr_for_textID
/* 0F9268 7F0C4738 3404A01B */   li    $a0, 40987
/* 0F926C 7F0C473C 3C0F8004 */  lui   $t7, %hi(ptrFirstFontTableSmall) 
/* 0F9270 7F0C4740 8DEF0EAC */  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
/* 0F9274 7F0C4744 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0F9278 7F0C4748 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0F927C 7F0C474C 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0F9280 7F0C4750 27A400BC */  addiu $a0, $sp, 0xbc
/* 0F9284 7F0C4754 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0F9288 7F0C4758 00403025 */  move  $a2, $v0
/* 0F928C 7F0C475C AFA00014 */  sw    $zero, 0x14($sp)
/* 0F9290 7F0C4760 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0F9294 7F0C4764 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0F9298 7F0C4768 0C001145 */  jal   get_video2_settings_ulx
/* 0F929C 7F0C476C 00000000 */   nop   
/* 0F92A0 7F0C4770 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0F92A4 7F0C4774 8FAA00C0 */  lw    $t2, 0xc0($sp)
/* 0F92A8 7F0C4778 0059C021 */  addu  $t8, $v0, $t9
/* 0F92AC 7F0C477C 000A4843 */  sra   $t1, $t2, 1
/* 0F92B0 7F0C4780 03092023 */  subu  $a0, $t8, $t1
/* 0F92B4 7F0C4784 24840050 */  addiu $a0, $a0, 0x50
/* 0F92B8 7F0C4788 0C001149 */  jal   get_video2_settings_uly
/* 0F92BC 7F0C478C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F92C0 7F0C4790 8FAC00BC */  lw    $t4, 0xbc($sp)
/* 0F92C4 7F0C4794 000C5843 */  sra   $t3, $t4, 1
/* 0F92C8 7F0C4798 004B6823 */  subu  $t5, $v0, $t3
/* 0F92CC 7F0C479C 25AE0035 */  addiu $t6, $t5, 0x35
/* 0F92D0 7F0C47A0 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F92D4 7F0C47A4 AFAE00C8 */   sw    $t6, 0xc8($sp)
/* 0F92D8 7F0C47A8 00028400 */  sll   $s0, $v0, 0x10
/* 0F92DC 7F0C47AC 00107C03 */  sra   $t7, $s0, 0x10
/* 0F92E0 7F0C47B0 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F92E4 7F0C47B4 01E08025 */   move  $s0, $t7
/* 0F92E8 7F0C47B8 3C198004 */  lui   $t9, %hi(ptrSecondFontTableSmall) 
/* 0F92EC 7F0C47BC 3C0A8004 */  lui   $t2, %hi(ptrFirstFontTableSmall) 
/* 0F92F0 7F0C47C0 8D4A0EAC */  lw    $t2, %lo(ptrFirstFontTableSmall)($t2)
/* 0F92F4 7F0C47C4 8F390EB0 */  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
/* 0F92F8 7F0C47C8 3C1800FF */  lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
/* 0F92FC 7F0C47CC 371800B0 */  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0F9300 7F0C47D0 AFB80018 */  sw    $t8, 0x18($sp)
/* 0F9304 7F0C47D4 02202025 */  move  $a0, $s1
/* 0F9308 7F0C47D8 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F930C 7F0C47DC 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9310 7F0C47E0 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0F9314 7F0C47E4 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F9318 7F0C47E8 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F931C 7F0C47EC AFA00024 */  sw    $zero, 0x24($sp)
/* 0F9320 7F0C47F0 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9324 7F0C47F4 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0F9328 7F0C47F8 0FC2B6AF */  jal   en_text_write_stuff
/* 0F932C 7F0C47FC AFB90010 */   sw    $t9, 0x10($sp)
/* 0F9330 7F0C4800 8FA30080 */  lw    $v1, 0x80($sp)
/* 0F9334 7F0C4804 24010005 */  li    $at, 5
/* 0F9338 7F0C4808 00408825 */  move  $s1, $v0
/* 0F933C 7F0C480C 10610009 */  beq   $v1, $at, .L7F0C4834
/* 0F9340 7F0C4810 8FA900D4 */   lw    $t1, 0xd4($sp)
/* 0F9344 7F0C4814 24010006 */  li    $at, 6
/* 0F9348 7F0C4818 10610006 */  beq   $v1, $at, .L7F0C4834
/* 0F934C 7F0C481C 24010007 */   li    $at, 7
/* 0F9350 7F0C4820 10610004 */  beq   $v1, $at, .L7F0C4834
/* 0F9354 7F0C4824 24010002 */   li    $at, 2
/* 0F9358 7F0C4828 10610002 */  beq   $v1, $at, .L7F0C4834
/* 0F935C 7F0C482C 24010003 */   li    $at, 3
/* 0F9360 7F0C4830 14610015 */  bne   $v1, $at, .L7F0C4888
.L7F0C4834:
/* 0F9364 7F0C4834 000960C0 */   sll   $t4, $t1, 3
/* 0F9368 7F0C4838 01896023 */  subu  $t4, $t4, $t1
/* 0F936C 7F0C483C 000C6100 */  sll   $t4, $t4, 4
/* 0F9370 7F0C4840 3C0B8008 */  lui   $t3, %hi(player1_player_data+105)
/* 0F9374 7F0C4844 016C5821 */  addu  $t3, $t3, $t4
/* 0F9378 7F0C4848 916B9F59 */  lbu   $t3, %lo(player1_player_data+105)($t3)
/* 0F937C 7F0C484C 24190005 */  li    $t9, 5
/* 0F9380 7F0C4850 240A0004 */  li    $t2, 4
/* 0F9384 7F0C4854 15600008 */  bnez  $t3, .L7F0C4878
/* 0F9388 7F0C4858 24180002 */   li    $t8, 2
/* 0F938C 7F0C485C 240D0003 */  li    $t5, 3
/* 0F9390 7F0C4860 240E0002 */  li    $t6, 2
/* 0F9394 7F0C4864 240F0004 */  li    $t7, 4
/* 0F9398 7F0C4868 AFAD008C */  sw    $t5, 0x8c($sp)
/* 0F939C 7F0C486C AFAE0088 */  sw    $t6, 0x88($sp)
/* 0F93A0 7F0C4870 10000009 */  b     .L7F0C4898
/* 0F93A4 7F0C4874 AFAF0084 */   sw    $t7, 0x84($sp)
.L7F0C4878:
/* 0F93A8 7F0C4878 AFB9008C */  sw    $t9, 0x8c($sp)
/* 0F93AC 7F0C487C AFAA0088 */  sw    $t2, 0x88($sp)
/* 0F93B0 7F0C4880 10000005 */  b     .L7F0C4898
/* 0F93B4 7F0C4884 AFB80084 */   sw    $t8, 0x84($sp)
.L7F0C4888:
/* 0F93B8 7F0C4888 24090001 */  li    $t1, 1
/* 0F93BC 7F0C488C AFA9008C */  sw    $t1, 0x8c($sp)
/* 0F93C0 7F0C4890 AFA00088 */  sw    $zero, 0x88($sp)
/* 0F93C4 7F0C4894 AFA00084 */  sw    $zero, 0x84($sp)
.L7F0C4898:
/* 0F93C8 7F0C4898 8FAC00D0 */  lw    $t4, 0xd0($sp)
/* 0F93CC 7F0C489C 24010002 */  li    $at, 2
/* 0F93D0 7F0C48A0 1581004E */  bne   $t4, $at, .L7F0C49DC
/* 0F93D4 7F0C48A4 00000000 */   nop   
/* 0F93D8 7F0C48A8 0C001145 */  jal   get_video2_settings_ulx
/* 0F93DC 7F0C48AC 00000000 */   nop   
/* 0F93E0 7F0C48B0 00028400 */  sll   $s0, $v0, 0x10
/* 0F93E4 7F0C48B4 00105C03 */  sra   $t3, $s0, 0x10
/* 0F93E8 7F0C48B8 0C001149 */  jal   get_video2_settings_uly
/* 0F93EC 7F0C48BC 01608025 */   move  $s0, $t3
/* 0F93F0 7F0C48C0 8FA800D4 */  lw    $t0, 0xd4($sp)
/* 0F93F4 7F0C48C4 00021C00 */  sll   $v1, $v0, 0x10
/* 0F93F8 7F0C48C8 00036C03 */  sra   $t5, $v1, 0x10
/* 0F93FC 7F0C48CC 15000004 */  bnez  $t0, .L7F0C48E0
/* 0F9400 7F0C48D0 01A01825 */   move  $v1, $t5
/* 0F9404 7F0C48D4 8FAE008C */  lw    $t6, 0x8c($sp)
/* 0F9408 7F0C48D8 1000000F */  b     .L7F0C4918
/* 0F940C 7F0C48DC AFAE0050 */   sw    $t6, 0x50($sp)
.L7F0C48E0:
/* 0F9410 7F0C48E0 0008C8C0 */  sll   $t9, $t0, 3
/* 0F9414 7F0C48E4 0328C823 */  subu  $t9, $t9, $t0
/* 0F9418 7F0C48E8 0019C900 */  sll   $t9, $t9, 4
/* 0F941C 7F0C48EC 3C0A8008 */  lui   $t2, %hi(player1_player_data + 0x69)
/* 0F9420 7F0C48F0 01595021 */  addu  $t2, $t2, $t9
/* 0F9424 7F0C48F4 3C0F8008 */  lui   $t7, %hi(player1_player_data + 0x69) 
/* 0F9428 7F0C48F8 91EF9F59 */  lbu   $t7, %lo(player1_player_data + 0x69)($t7)
/* 0F942C 7F0C48FC 914A9F59 */  lbu   $t2, %lo(player1_player_data + 0x69)($t2)
/* 0F9430 7F0C4900 8FA60084 */  lw    $a2, 0x84($sp)
/* 0F9434 7F0C4904 15EA0003 */  bne   $t7, $t2, .L7F0C4914
/* 0F9438 7F0C4908 00000000 */   nop   
/* 0F943C 7F0C490C 10000001 */  b     .L7F0C4914
/* 0F9440 7F0C4910 8FA60088 */   lw    $a2, 0x88($sp)
.L7F0C4914:
/* 0F9444 7F0C4914 AFA60050 */  sw    $a2, 0x50($sp)
.L7F0C4918:
/* 0F9448 7F0C4918 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0F944C 7F0C491C 8FA90050 */  lw    $t1, 0x50($sp)
/* 0F9450 7F0C4920 02202025 */  move  $a0, $s1
/* 0F9454 7F0C4924 02182821 */  addu  $a1, $s0, $t8
/* 0F9458 7F0C4928 24A50050 */  addiu $a1, $a1, 0x50
/* 0F945C 7F0C492C 24660046 */  addiu $a2, $v1, 0x46
/* 0F9460 7F0C4930 8FA70094 */  lw    $a3, 0x94($sp)
/* 0F9464 7F0C4934 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9468 7F0C4938 AFA90010 */   sw    $t1, 0x10($sp)
/* 0F946C 7F0C493C 0C001145 */  jal   get_video2_settings_ulx
/* 0F9470 7F0C4940 00408825 */   move  $s1, $v0
/* 0F9474 7F0C4944 00028400 */  sll   $s0, $v0, 0x10
/* 0F9478 7F0C4948 00106403 */  sra   $t4, $s0, 0x10
/* 0F947C 7F0C494C 0C001149 */  jal   get_video2_settings_uly
/* 0F9480 7F0C4950 01808025 */   move  $s0, $t4
/* 0F9484 7F0C4954 8FA400D4 */  lw    $a0, 0xd4($sp)
/* 0F9488 7F0C4958 00021C00 */  sll   $v1, $v0, 0x10
/* 0F948C 7F0C495C 00035C03 */  sra   $t3, $v1, 0x10
/* 0F9490 7F0C4960 24010001 */  li    $at, 1
/* 0F9494 7F0C4964 14810004 */  bne   $a0, $at, .L7F0C4978
/* 0F9498 7F0C4968 01601825 */   move  $v1, $t3
/* 0F949C 7F0C496C 8FAD008C */  lw    $t5, 0x8c($sp)
/* 0F94A0 7F0C4970 1000000F */  b     .L7F0C49B0
/* 0F94A4 7F0C4974 AFAD0050 */   sw    $t5, 0x50($sp)
.L7F0C4978:
/* 0F94A8 7F0C4978 0004C8C0 */  sll   $t9, $a0, 3
/* 0F94AC 7F0C497C 0324C823 */  subu  $t9, $t9, $a0
/* 0F94B0 7F0C4980 3C028008 */  lui   $v0, %hi(player1_player_data)
/* 0F94B4 7F0C4984 24429EF0 */  addiu $v0, %lo(player1_player_data) # addiu $v0, $v0, -0x6110
/* 0F94B8 7F0C4988 0019C900 */  sll   $t9, $t9, 4
/* 0F94BC 7F0C498C 00597821 */  addu  $t7, $v0, $t9
/* 0F94C0 7F0C4990 91EA0069 */  lbu   $t2, 0x69($t7)
/* 0F94C4 7F0C4994 904E00D9 */  lbu   $t6, 0xd9($v0)
/* 0F94C8 7F0C4998 8FA60084 */  lw    $a2, 0x84($sp)
/* 0F94CC 7F0C499C 15CA0003 */  bne   $t6, $t2, .L7F0C49AC
/* 0F94D0 7F0C49A0 00000000 */   nop   
/* 0F94D4 7F0C49A4 10000001 */  b     .L7F0C49AC
/* 0F94D8 7F0C49A8 8FA60088 */   lw    $a2, 0x88($sp)
.L7F0C49AC:
/* 0F94DC 7F0C49AC AFA60050 */  sw    $a2, 0x50($sp)
.L7F0C49B0:
/* 0F94E0 7F0C49B0 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0F94E4 7F0C49B4 8FA90050 */  lw    $t1, 0x50($sp)
/* 0F94E8 7F0C49B8 02202025 */  move  $a0, $s1
/* 0F94EC 7F0C49BC 02182821 */  addu  $a1, $s0, $t8
/* 0F94F0 7F0C49C0 24A50050 */  addiu $a1, $a1, 0x50
/* 0F94F4 7F0C49C4 24660056 */  addiu $a2, $v1, 0x56
/* 0F94F8 7F0C49C8 8FA70098 */  lw    $a3, 0x98($sp)
/* 0F94FC 7F0C49CC 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9500 7F0C49D0 AFA90010 */   sw    $t1, 0x10($sp)
/* 0F9504 7F0C49D4 1000009E */  b     .L7F0C4C50
/* 0F9508 7F0C49D8 00408825 */   move  $s1, $v0
.L7F0C49DC:
/* 0F950C 7F0C49DC 0C001145 */  jal   get_video2_settings_ulx
/* 0F9510 7F0C49E0 00000000 */   nop   
/* 0F9514 7F0C49E4 00028400 */  sll   $s0, $v0, 0x10
/* 0F9518 7F0C49E8 00106403 */  sra   $t4, $s0, 0x10
/* 0F951C 7F0C49EC 0C001149 */  jal   get_video2_settings_uly
/* 0F9520 7F0C49F0 01808025 */   move  $s0, $t4
/* 0F9524 7F0C49F4 8FA800D4 */  lw    $t0, 0xd4($sp)
/* 0F9528 7F0C49F8 00021C00 */  sll   $v1, $v0, 0x10
/* 0F952C 7F0C49FC 00035C03 */  sra   $t3, $v1, 0x10
/* 0F9530 7F0C4A00 15000004 */  bnez  $t0, .L7F0C4A14
/* 0F9534 7F0C4A04 01601825 */   move  $v1, $t3
/* 0F9538 7F0C4A08 8FAD008C */  lw    $t5, 0x8c($sp)
/* 0F953C 7F0C4A0C 1000000F */  b     .L7F0C4A4C
/* 0F9540 7F0C4A10 AFAD0050 */   sw    $t5, 0x50($sp)
.L7F0C4A14:
/* 0F9544 7F0C4A14 000878C0 */  sll   $t7, $t0, 3
/* 0F9548 7F0C4A18 01E87823 */  subu  $t7, $t7, $t0
/* 0F954C 7F0C4A1C 000F7900 */  sll   $t7, $t7, 4
/* 0F9550 7F0C4A20 3C0E8008 */  lui   $t6, %hi(player1_player_data + 0x69)
/* 0F9554 7F0C4A24 01CF7021 */  addu  $t6, $t6, $t7
/* 0F9558 7F0C4A28 3C198008 */  lui   $t9, %hi(player1_player_data + 0x69) 
/* 0F955C 7F0C4A2C 93399F59 */  lbu   $t9, %lo(player1_player_data + 0x69)($t9)
/* 0F9560 7F0C4A30 91CE9F59 */  lbu   $t6, %lo(player1_player_data + 0x69)($t6)
/* 0F9564 7F0C4A34 8FA60084 */  lw    $a2, 0x84($sp)
/* 0F9568 7F0C4A38 172E0003 */  bne   $t9, $t6, .L7F0C4A48
/* 0F956C 7F0C4A3C 00000000 */   nop   
/* 0F9570 7F0C4A40 10000001 */  b     .L7F0C4A48
/* 0F9574 7F0C4A44 8FA60088 */   lw    $a2, 0x88($sp)
.L7F0C4A48:
/* 0F9578 7F0C4A48 AFA60050 */  sw    $a2, 0x50($sp)
.L7F0C4A4C:
/* 0F957C 7F0C4A4C 8FAA00A8 */  lw    $t2, 0xa8($sp)
/* 0F9580 7F0C4A50 8FB80050 */  lw    $t8, 0x50($sp)
/* 0F9584 7F0C4A54 02202025 */  move  $a0, $s1
/* 0F9588 7F0C4A58 020A2821 */  addu  $a1, $s0, $t2
/* 0F958C 7F0C4A5C 24A50040 */  addiu $a1, $a1, 0x40
/* 0F9590 7F0C4A60 24660046 */  addiu $a2, $v1, 0x46
/* 0F9594 7F0C4A64 8FA70094 */  lw    $a3, 0x94($sp)
/* 0F9598 7F0C4A68 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F959C 7F0C4A6C AFB80010 */   sw    $t8, 0x10($sp)
/* 0F95A0 7F0C4A70 0C001145 */  jal   get_video2_settings_ulx
/* 0F95A4 7F0C4A74 00408825 */   move  $s1, $v0
/* 0F95A8 7F0C4A78 00028400 */  sll   $s0, $v0, 0x10
/* 0F95AC 7F0C4A7C 00104C03 */  sra   $t1, $s0, 0x10
/* 0F95B0 7F0C4A80 0C001149 */  jal   get_video2_settings_uly
/* 0F95B4 7F0C4A84 01208025 */   move  $s0, $t1
/* 0F95B8 7F0C4A88 8FA800D4 */  lw    $t0, 0xd4($sp)
/* 0F95BC 7F0C4A8C 00021C00 */  sll   $v1, $v0, 0x10
/* 0F95C0 7F0C4A90 00036403 */  sra   $t4, $v1, 0x10
/* 0F95C4 7F0C4A94 24010001 */  li    $at, 1
/* 0F95C8 7F0C4A98 15010004 */  bne   $t0, $at, .L7F0C4AAC
/* 0F95CC 7F0C4A9C 01801825 */   move  $v1, $t4
/* 0F95D0 7F0C4AA0 8FAB008C */  lw    $t3, 0x8c($sp)
/* 0F95D4 7F0C4AA4 1000000F */  b     .L7F0C4AE4
/* 0F95D8 7F0C4AA8 AFAB0050 */   sw    $t3, 0x50($sp)
.L7F0C4AAC:
/* 0F95DC 7F0C4AAC 000878C0 */  sll   $t7, $t0, 3
/* 0F95E0 7F0C4AB0 01E87823 */  subu  $t7, $t7, $t0
/* 0F95E4 7F0C4AB4 000F7900 */  sll   $t7, $t7, 4
/* 0F95E8 7F0C4AB8 3C198008 */  lui   $t9, %hi(player1_player_data + 0x69)
/* 0F95EC 7F0C4ABC 032FC821 */  addu  $t9, $t9, $t7
/* 0F95F0 7F0C4AC0 3C0D8008 */  lui   $t5, %hi(player2_player_data + 0x69) 
/* 0F95F4 7F0C4AC4 91AD9FC9 */  lbu   $t5, %lo(player2_player_data + 0x69)($t5)
/* 0F95F8 7F0C4AC8 93399F59 */  lbu   $t9, %lo(player1_player_data + 0x69)($t9)
/* 0F95FC 7F0C4ACC 8FA60084 */  lw    $a2, 0x84($sp)
/* 0F9600 7F0C4AD0 15B90003 */  bne   $t5, $t9, .L7F0C4AE0
/* 0F9604 7F0C4AD4 00000000 */   nop   
/* 0F9608 7F0C4AD8 10000001 */  b     .L7F0C4AE0
/* 0F960C 7F0C4ADC 8FA60088 */   lw    $a2, 0x88($sp)
.L7F0C4AE0:
/* 0F9610 7F0C4AE0 AFA60050 */  sw    $a2, 0x50($sp)
.L7F0C4AE4:
/* 0F9614 7F0C4AE4 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0F9618 7F0C4AE8 8FAA0050 */  lw    $t2, 0x50($sp)
/* 0F961C 7F0C4AEC 02202025 */  move  $a0, $s1
/* 0F9620 7F0C4AF0 020E2821 */  addu  $a1, $s0, $t6
/* 0F9624 7F0C4AF4 24A50060 */  addiu $a1, $a1, 0x60
/* 0F9628 7F0C4AF8 24660046 */  addiu $a2, $v1, 0x46
/* 0F962C 7F0C4AFC 8FA70098 */  lw    $a3, 0x98($sp)
/* 0F9630 7F0C4B00 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9634 7F0C4B04 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0F9638 7F0C4B08 0C001145 */  jal   get_video2_settings_ulx
/* 0F963C 7F0C4B0C 00408825 */   move  $s1, $v0
/* 0F9640 7F0C4B10 00028400 */  sll   $s0, $v0, 0x10
/* 0F9644 7F0C4B14 0010C403 */  sra   $t8, $s0, 0x10
/* 0F9648 7F0C4B18 0C001149 */  jal   get_video2_settings_uly
/* 0F964C 7F0C4B1C 03008025 */   move  $s0, $t8
/* 0F9650 7F0C4B20 8FA800D4 */  lw    $t0, 0xd4($sp)
/* 0F9654 7F0C4B24 00021C00 */  sll   $v1, $v0, 0x10
/* 0F9658 7F0C4B28 00034C03 */  sra   $t1, $v1, 0x10
/* 0F965C 7F0C4B2C 24010002 */  li    $at, 2
/* 0F9660 7F0C4B30 15010004 */  bne   $t0, $at, .L7F0C4B44
/* 0F9664 7F0C4B34 01201825 */   move  $v1, $t1
/* 0F9668 7F0C4B38 8FAC008C */  lw    $t4, 0x8c($sp)
/* 0F966C 7F0C4B3C 1000000F */  b     .L7F0C4B7C
/* 0F9670 7F0C4B40 AFAC0050 */   sw    $t4, 0x50($sp)
.L7F0C4B44:
/* 0F9674 7F0C4B44 000878C0 */  sll   $t7, $t0, 3
/* 0F9678 7F0C4B48 01E87823 */  subu  $t7, $t7, $t0
/* 0F967C 7F0C4B4C 000F7900 */  sll   $t7, $t7, 4
/* 0F9680 7F0C4B50 3C0D8008 */  lui   $t5, %hi(player1_player_data + 0x69)
/* 0F9684 7F0C4B54 01AF6821 */  addu  $t5, $t5, $t7
/* 0F9688 7F0C4B58 3C0B8008 */  lui   $t3, %hi(player3_player_data + 0x69) 
/* 0F968C 7F0C4B5C 916BA039 */  lbu   $t3, %lo(player3_player_data + 0x69)($t3)
/* 0F9690 7F0C4B60 91AD9F59 */  lbu   $t5, %lo(player1_player_data + 0x69)($t5)
/* 0F9694 7F0C4B64 8FA60084 */  lw    $a2, 0x84($sp)
/* 0F9698 7F0C4B68 156D0003 */  bne   $t3, $t5, .L7F0C4B78
/* 0F969C 7F0C4B6C 00000000 */   nop   
/* 0F96A0 7F0C4B70 10000001 */  b     .L7F0C4B78
/* 0F96A4 7F0C4B74 8FA60088 */   lw    $a2, 0x88($sp)
.L7F0C4B78:
/* 0F96A8 7F0C4B78 AFA60050 */  sw    $a2, 0x50($sp)
.L7F0C4B7C:
/* 0F96AC 7F0C4B7C 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0F96B0 7F0C4B80 8FAE0050 */  lw    $t6, 0x50($sp)
/* 0F96B4 7F0C4B84 02202025 */  move  $a0, $s1
/* 0F96B8 7F0C4B88 02192821 */  addu  $a1, $s0, $t9
/* 0F96BC 7F0C4B8C 24A50040 */  addiu $a1, $a1, 0x40
/* 0F96C0 7F0C4B90 24660056 */  addiu $a2, $v1, 0x56
/* 0F96C4 7F0C4B94 8FA7009C */  lw    $a3, 0x9c($sp)
/* 0F96C8 7F0C4B98 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F96CC 7F0C4B9C AFAE0010 */   sw    $t6, 0x10($sp)
/* 0F96D0 7F0C4BA0 8FAA00D0 */  lw    $t2, 0xd0($sp)
/* 0F96D4 7F0C4BA4 24010004 */  li    $at, 4
/* 0F96D8 7F0C4BA8 00408825 */  move  $s1, $v0
/* 0F96DC 7F0C4BAC 15410028 */  bne   $t2, $at, .L7F0C4C50
/* 0F96E0 7F0C4BB0 00000000 */   nop   
/* 0F96E4 7F0C4BB4 0C001145 */  jal   get_video2_settings_ulx
/* 0F96E8 7F0C4BB8 00000000 */   nop   
/* 0F96EC 7F0C4BBC 00028400 */  sll   $s0, $v0, 0x10
/* 0F96F0 7F0C4BC0 0010C403 */  sra   $t8, $s0, 0x10
/* 0F96F4 7F0C4BC4 0C001149 */  jal   get_video2_settings_uly
/* 0F96F8 7F0C4BC8 03008025 */   move  $s0, $t8
/* 0F96FC 7F0C4BCC 8FA400D4 */  lw    $a0, 0xd4($sp)
/* 0F9700 7F0C4BD0 00021C00 */  sll   $v1, $v0, 0x10
/* 0F9704 7F0C4BD4 00034C03 */  sra   $t1, $v1, 0x10
/* 0F9708 7F0C4BD8 24010003 */  li    $at, 3
/* 0F970C 7F0C4BDC 14810004 */  bne   $a0, $at, .L7F0C4BF0
/* 0F9710 7F0C4BE0 01201825 */   move  $v1, $t1
/* 0F9714 7F0C4BE4 8FAC008C */  lw    $t4, 0x8c($sp)
/* 0F9718 7F0C4BE8 1000000F */  b     .L7F0C4C28
/* 0F971C 7F0C4BEC AFAC0050 */   sw    $t4, 0x50($sp)
.L7F0C4BF0:
/* 0F9720 7F0C4BF0 000458C0 */  sll   $t3, $a0, 3
/* 0F9724 7F0C4BF4 01645823 */  subu  $t3, $t3, $a0
/* 0F9728 7F0C4BF8 3C028008 */  lui   $v0, %hi(player1_player_data)
/* 0F972C 7F0C4BFC 24429EF0 */  addiu $v0, %lo(player1_player_data) # addiu $v0, $v0, -0x6110
/* 0F9730 7F0C4C00 000B5900 */  sll   $t3, $t3, 4
/* 0F9734 7F0C4C04 004B6821 */  addu  $t5, $v0, $t3
/* 0F9738 7F0C4C08 91B90069 */  lbu   $t9, 0x69($t5)
/* 0F973C 7F0C4C0C 904F01B9 */  lbu   $t7, 0x1b9($v0)
/* 0F9740 7F0C4C10 8FA60084 */  lw    $a2, 0x84($sp)
/* 0F9744 7F0C4C14 15F90003 */  bne   $t7, $t9, .L7F0C4C24
/* 0F9748 7F0C4C18 00000000 */   nop   
/* 0F974C 7F0C4C1C 10000001 */  b     .L7F0C4C24
/* 0F9750 7F0C4C20 8FA60088 */   lw    $a2, 0x88($sp)
.L7F0C4C24:
/* 0F9754 7F0C4C24 AFA60050 */  sw    $a2, 0x50($sp)
.L7F0C4C28:
/* 0F9758 7F0C4C28 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0F975C 7F0C4C2C 8FAA0050 */  lw    $t2, 0x50($sp)
/* 0F9760 7F0C4C30 02202025 */  move  $a0, $s1
/* 0F9764 7F0C4C34 020E2821 */  addu  $a1, $s0, $t6
/* 0F9768 7F0C4C38 24A50060 */  addiu $a1, $a1, 0x60
/* 0F976C 7F0C4C3C 24660056 */  addiu $a2, $v1, 0x56
/* 0F9770 7F0C4C40 8FA700A0 */  lw    $a3, 0xa0($sp)
/* 0F9774 7F0C4C44 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9778 7F0C4C48 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0F977C 7F0C4C4C 00408825 */  move  $s1, $v0
.L7F0C4C50:
/* 0F9780 7F0C4C50 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0F9784 7F0C4C54 100003BB */  b     .L7F0C5B44
/* 0F9788 7F0C4C58 8C63A0B0 */   lw    $v1, %lo(pPlayer)($v1)
/* 0F978C 7F0C4C5C 24010002 */  li    $at, 2
.L7F0C4C60:
/* 0F9790 7F0C4C60 1441011C */  bne   $v0, $at, .L7F0C50D4
/* 0F9794 7F0C4C64 3C048009 */   lui   $a0, %hi(is_gameover_flag)
/* 0F9798 7F0C4C68 8C84C704 */  lw    $a0, %lo(is_gameover_flag)($a0)
/* 0F979C 7F0C4C6C 2C980001 */  sltiu $t8, $a0, 1
/* 0F97A0 7F0C4C70 13000005 */  beqz  $t8, .L7F0C4C88
/* 0F97A4 7F0C4C74 03002025 */   move  $a0, $t8
/* 0F97A8 7F0C4C78 3C048009 */  lui   $a0, %hi(stop_play_flag)
/* 0F97AC 7F0C4C7C 8C84C700 */  lw    $a0, %lo(stop_play_flag)($a0)
/* 0F97B0 7F0C4C80 2C890001 */  sltiu $t1, $a0, 1
/* 0F97B4 7F0C4C84 01202025 */  move  $a0, $t1
.L7F0C4C88:
/* 0F97B8 7F0C4C88 0FC30FD7 */  jal   true_if_displaying_rank_in_mp
/* 0F97BC 7F0C4C8C 00000000 */   nop   
/* 0F97C0 7F0C4C90 10400034 */  beqz  $v0, .L7F0C4D64
/* 0F97C4 7F0C4C94 27A400AC */   addiu $a0, $sp, 0xac
/* 0F97C8 7F0C4C98 0FC30F25 */  jal   write_playerrank_to_buffer
/* 0F97CC 7F0C4C9C 8FA500D4 */   lw    $a1, 0xd4($sp)
/* 0F97D0 7F0C4CA0 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) 
/* 0F97D4 7F0C4CA4 8D8C0EAC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0F97D8 7F0C4CA8 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0F97DC 7F0C4CAC 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0F97E0 7F0C4CB0 27A400BC */  addiu $a0, $sp, 0xbc
/* 0F97E4 7F0C4CB4 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0F97E8 7F0C4CB8 27A600AC */  addiu $a2, $sp, 0xac
/* 0F97EC 7F0C4CBC AFA00014 */  sw    $zero, 0x14($sp)
/* 0F97F0 7F0C4CC0 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0F97F4 7F0C4CC4 AFAC0010 */   sw    $t4, 0x10($sp)
/* 0F97F8 7F0C4CC8 0C001145 */  jal   get_video2_settings_ulx
/* 0F97FC 7F0C4CCC 00000000 */   nop   
/* 0F9800 7F0C4CD0 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0F9804 7F0C4CD4 8FAF00C0 */  lw    $t7, 0xc0($sp)
/* 0F9808 7F0C4CD8 004B6821 */  addu  $t5, $v0, $t3
/* 0F980C 7F0C4CDC 000FC843 */  sra   $t9, $t7, 1
/* 0F9810 7F0C4CE0 01B92023 */  subu  $a0, $t5, $t9
/* 0F9814 7F0C4CE4 24840050 */  addiu $a0, $a0, 0x50
/* 0F9818 7F0C4CE8 0C001149 */  jal   get_video2_settings_uly
/* 0F981C 7F0C4CEC AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F9820 7F0C4CF0 8FAE00BC */  lw    $t6, 0xbc($sp)
/* 0F9824 7F0C4CF4 000E5043 */  sra   $t2, $t6, 1
/* 0F9828 7F0C4CF8 004AC023 */  subu  $t8, $v0, $t2
/* 0F982C 7F0C4CFC 27090025 */  addiu $t1, $t8, 0x25
/* 0F9830 7F0C4D00 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F9834 7F0C4D04 AFA900C8 */   sw    $t1, 0xc8($sp)
/* 0F9838 7F0C4D08 00028400 */  sll   $s0, $v0, 0x10
/* 0F983C 7F0C4D0C 00106403 */  sra   $t4, $s0, 0x10
/* 0F9840 7F0C4D10 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F9844 7F0C4D14 01808025 */   move  $s0, $t4
/* 0F9848 7F0C4D18 3C0B8004 */  lui   $t3, %hi(ptrSecondFontTableSmall) 
/* 0F984C 7F0C4D1C 3C0F8004 */  lui   $t7, %hi(ptrFirstFontTableSmall) 
/* 0F9850 7F0C4D20 8DEF0EAC */  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
/* 0F9854 7F0C4D24 8D6B0EB0 */  lw    $t3, %lo(ptrSecondFontTableSmall)($t3)
/* 0F9858 7F0C4D28 3C0D00FF */  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
/* 0F985C 7F0C4D2C 35AD00B0 */  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0F9860 7F0C4D30 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0F9864 7F0C4D34 02202025 */  move  $a0, $s1
/* 0F9868 7F0C4D38 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F986C 7F0C4D3C 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9870 7F0C4D40 27A700AC */  addiu $a3, $sp, 0xac
/* 0F9874 7F0C4D44 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F9878 7F0C4D48 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F987C 7F0C4D4C AFA00024 */  sw    $zero, 0x24($sp)
/* 0F9880 7F0C4D50 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9884 7F0C4D54 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0F9888 7F0C4D58 0FC2B6AF */  jal   en_text_write_stuff
/* 0F988C 7F0C4D5C AFAB0010 */   sw    $t3, 0x10($sp)
/* 0F9890 7F0C4D60 00408825 */  move  $s1, $v0
.L7F0C4D64:
/* 0F9894 7F0C4D64 0FC30776 */  jal   get_textptr_for_textID
/* 0F9898 7F0C4D68 3404A01C */   li    $a0, 40988
/* 0F989C 7F0C4D6C 3404A01D */  li    $a0, 40989
/* 0F98A0 7F0C4D70 0FC30776 */  jal   get_textptr_for_textID
/* 0F98A4 7F0C4D74 AFA2004C */   sw    $v0, 0x4c($sp)
/* 0F98A8 7F0C4D78 8FA700D4 */  lw    $a3, 0xd4($sp)
/* 0F98AC 7F0C4D7C 3C058006 */  lui   $a1, %hi(ascii_pnum_KILLS)
/* 0F98B0 7F0C4D80 24A5BC30 */  addiu $a1, %lo(ascii_pnum_KILLS) # addiu $a1, $a1, -0x43d0
/* 0F98B4 7F0C4D84 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0F98B8 7F0C4D88 27A400AC */  addiu $a0, $sp, 0xac
/* 0F98BC 7F0C4D8C AFA20010 */  sw    $v0, 0x10($sp)
/* 0F98C0 7F0C4D90 0C002B25 */  jal   sprintf
/* 0F98C4 7F0C4D94 24E70001 */   addiu $a3, $a3, 1
/* 0F98C8 7F0C4D98 3C198004 */  lui   $t9, %hi(ptrFirstFontTableSmall) 
/* 0F98CC 7F0C4D9C 8F390EAC */  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
/* 0F98D0 7F0C4DA0 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0F98D4 7F0C4DA4 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0F98D8 7F0C4DA8 27A400BC */  addiu $a0, $sp, 0xbc
/* 0F98DC 7F0C4DAC 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0F98E0 7F0C4DB0 27A600AC */  addiu $a2, $sp, 0xac
/* 0F98E4 7F0C4DB4 AFA00014 */  sw    $zero, 0x14($sp)
/* 0F98E8 7F0C4DB8 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0F98EC 7F0C4DBC AFB90010 */   sw    $t9, 0x10($sp)
/* 0F98F0 7F0C4DC0 0C001145 */  jal   get_video2_settings_ulx
/* 0F98F4 7F0C4DC4 00000000 */   nop   
/* 0F98F8 7F0C4DC8 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0F98FC 7F0C4DCC 8FB800C0 */  lw    $t8, 0xc0($sp)
/* 0F9900 7F0C4DD0 004E5021 */  addu  $t2, $v0, $t6
/* 0F9904 7F0C4DD4 00184843 */  sra   $t1, $t8, 1
/* 0F9908 7F0C4DD8 01492023 */  subu  $a0, $t2, $t1
/* 0F990C 7F0C4DDC 24840050 */  addiu $a0, $a0, 0x50
/* 0F9910 7F0C4DE0 0C001149 */  jal   get_video2_settings_uly
/* 0F9914 7F0C4DE4 AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F9918 7F0C4DE8 8FAC00BC */  lw    $t4, 0xbc($sp)
/* 0F991C 7F0C4DEC 000C5843 */  sra   $t3, $t4, 1
/* 0F9920 7F0C4DF0 004B7823 */  subu  $t7, $v0, $t3
/* 0F9924 7F0C4DF4 25ED0035 */  addiu $t5, $t7, 0x35
/* 0F9928 7F0C4DF8 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F992C 7F0C4DFC AFAD00C8 */   sw    $t5, 0xc8($sp)
/* 0F9930 7F0C4E00 00028400 */  sll   $s0, $v0, 0x10
/* 0F9934 7F0C4E04 0010CC03 */  sra   $t9, $s0, 0x10
/* 0F9938 7F0C4E08 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F993C 7F0C4E0C 03208025 */   move  $s0, $t9
/* 0F9940 7F0C4E10 3C0E8004 */  lui   $t6, %hi(ptrSecondFontTableSmall) 
/* 0F9944 7F0C4E14 3C188004 */  lui   $t8, %hi(ptrFirstFontTableSmall) 
/* 0F9948 7F0C4E18 8F180EAC */  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
/* 0F994C 7F0C4E1C 8DCE0EB0 */  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
/* 0F9950 7F0C4E20 3C0A00FF */  lui   $t2, (0x00FF00B0 >> 16) # lui $t2, 0xff
/* 0F9954 7F0C4E24 354A00B0 */  ori   $t2, (0x00FF00B0 & 0xFFFF) # ori $t2, $t2, 0xb0
/* 0F9958 7F0C4E28 AFAA0018 */  sw    $t2, 0x18($sp)
/* 0F995C 7F0C4E2C 02202025 */  move  $a0, $s1
/* 0F9960 7F0C4E30 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F9964 7F0C4E34 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9968 7F0C4E38 27A700AC */  addiu $a3, $sp, 0xac
/* 0F996C 7F0C4E3C AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F9970 7F0C4E40 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F9974 7F0C4E44 AFA00024 */  sw    $zero, 0x24($sp)
/* 0F9978 7F0C4E48 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F997C 7F0C4E4C AFB80014 */  sw    $t8, 0x14($sp)
/* 0F9980 7F0C4E50 0FC2B6AF */  jal   en_text_write_stuff
/* 0F9984 7F0C4E54 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0F9988 7F0C4E58 8FA900D0 */  lw    $t1, 0xd0($sp)
/* 0F998C 7F0C4E5C 00408825 */  move  $s1, $v0
/* 0F9990 7F0C4E60 24010002 */  li    $at, 2
/* 0F9994 7F0C4E64 15210033 */  bne   $t1, $at, .L7F0C4F34
/* 0F9998 7F0C4E68 8FA200D4 */   lw    $v0, 0xd4($sp)
/* 0F999C 7F0C4E6C 8FA200D4 */  lw    $v0, 0xd4($sp)
/* 0F99A0 7F0C4E70 50400018 */  beql  $v0, $zero, .L7F0C4ED4
/* 0F99A4 7F0C4E74 24010001 */   li    $at, 1
/* 0F99A8 7F0C4E78 0C001145 */  jal   get_video2_settings_ulx
/* 0F99AC 7F0C4E7C 00000000 */   nop   
/* 0F99B0 7F0C4E80 00028400 */  sll   $s0, $v0, 0x10
/* 0F99B4 7F0C4E84 00106403 */  sra   $t4, $s0, 0x10
/* 0F99B8 7F0C4E88 0C001149 */  jal   get_video2_settings_uly
/* 0F99BC 7F0C4E8C 01808025 */   move  $s0, $t4
/* 0F99C0 7F0C4E90 8FAF00D4 */  lw    $t7, 0xd4($sp)
/* 0F99C4 7F0C4E94 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0F99C8 7F0C4E98 3C078008 */  lui   $a3, %hi(player1_player_data+36)
/* 0F99CC 7F0C4E9C 000F68C0 */  sll   $t5, $t7, 3
/* 0F99D0 7F0C4EA0 01AF6823 */  subu  $t5, $t5, $t7
/* 0F99D4 7F0C4EA4 000D6900 */  sll   $t5, $t5, 4
/* 0F99D8 7F0C4EA8 00ED3821 */  addu  $a3, $a3, $t5
/* 0F99DC 7F0C4EAC 020B2821 */  addu  $a1, $s0, $t3
/* 0F99E0 7F0C4EB0 24A50050 */  addiu $a1, $a1, 0x50
/* 0F99E4 7F0C4EB4 8CE79F14 */  lw    $a3, %lo(player1_player_data+36)($a3)
/* 0F99E8 7F0C4EB8 02202025 */  move  $a0, $s1
/* 0F99EC 7F0C4EBC 24460046 */  addiu $a2, $v0, 0x46
/* 0F99F0 7F0C4EC0 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F99F4 7F0C4EC4 AFA00010 */   sw    $zero, 0x10($sp)
/* 0F99F8 7F0C4EC8 00408825 */  move  $s1, $v0
/* 0F99FC 7F0C4ECC 8FA200D4 */  lw    $v0, 0xd4($sp)
/* 0F9A00 7F0C4ED0 24010001 */  li    $at, 1
.L7F0C4ED4:
/* 0F9A04 7F0C4ED4 1041007C */  beq   $v0, $at, .L7F0C50C8
/* 0F9A08 7F0C4ED8 0002C8C0 */   sll   $t9, $v0, 3
/* 0F9A0C 7F0C4EDC 0322C823 */  subu  $t9, $t9, $v0
/* 0F9A10 7F0C4EE0 3C0E8008 */  lui   $t6, %hi(player1_player_data) 
/* 0F9A14 7F0C4EE4 25CE9EF0 */  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
/* 0F9A18 7F0C4EE8 0019C900 */  sll   $t9, $t9, 4
/* 0F9A1C 7F0C4EEC 032EC021 */  addu  $t8, $t9, $t6
/* 0F9A20 7F0C4EF0 0C001145 */  jal   get_video2_settings_ulx
/* 0F9A24 7F0C4EF4 AFB80044 */   sw    $t8, 0x44($sp)
/* 0F9A28 7F0C4EF8 00028400 */  sll   $s0, $v0, 0x10
/* 0F9A2C 7F0C4EFC 00105403 */  sra   $t2, $s0, 0x10
/* 0F9A30 7F0C4F00 0C001149 */  jal   get_video2_settings_uly
/* 0F9A34 7F0C4F04 01408025 */   move  $s0, $t2
/* 0F9A38 7F0C4F08 8FA900A8 */  lw    $t1, 0xa8($sp)
/* 0F9A3C 7F0C4F0C 8FAC0044 */  lw    $t4, 0x44($sp)
/* 0F9A40 7F0C4F10 02202025 */  move  $a0, $s1
/* 0F9A44 7F0C4F14 02092821 */  addu  $a1, $s0, $t1
/* 0F9A48 7F0C4F18 8D870028 */  lw    $a3, 0x28($t4)
/* 0F9A4C 7F0C4F1C AFA00010 */  sw    $zero, 0x10($sp)
/* 0F9A50 7F0C4F20 24A50050 */  addiu $a1, $a1, 0x50
/* 0F9A54 7F0C4F24 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9A58 7F0C4F28 24460056 */   addiu $a2, $v0, 0x56
/* 0F9A5C 7F0C4F2C 10000066 */  b     .L7F0C50C8
/* 0F9A60 7F0C4F30 00408825 */   move  $s1, $v0
.L7F0C4F34:
/* 0F9A64 7F0C4F34 50400018 */  beql  $v0, $zero, .L7F0C4F98
/* 0F9A68 7F0C4F38 24010001 */   li    $at, 1
/* 0F9A6C 7F0C4F3C 0C001145 */  jal   get_video2_settings_ulx
/* 0F9A70 7F0C4F40 00000000 */   nop   
/* 0F9A74 7F0C4F44 00028400 */  sll   $s0, $v0, 0x10
/* 0F9A78 7F0C4F48 00105C03 */  sra   $t3, $s0, 0x10
/* 0F9A7C 7F0C4F4C 0C001149 */  jal   get_video2_settings_uly
/* 0F9A80 7F0C4F50 01608025 */   move  $s0, $t3
/* 0F9A84 7F0C4F54 8FAD00D4 */  lw    $t5, 0xd4($sp)
/* 0F9A88 7F0C4F58 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0F9A8C 7F0C4F5C 3C078008 */  lui   $a3, %hi(player1_player_data+36)
/* 0F9A90 7F0C4F60 000DC8C0 */  sll   $t9, $t5, 3
/* 0F9A94 7F0C4F64 032DC823 */  subu  $t9, $t9, $t5
/* 0F9A98 7F0C4F68 0019C900 */  sll   $t9, $t9, 4
/* 0F9A9C 7F0C4F6C 00F93821 */  addu  $a3, $a3, $t9
/* 0F9AA0 7F0C4F70 020F2821 */  addu  $a1, $s0, $t7
/* 0F9AA4 7F0C4F74 24A50040 */  addiu $a1, $a1, 0x40
/* 0F9AA8 7F0C4F78 8CE79F14 */  lw    $a3, %lo(player1_player_data+36)($a3)
/* 0F9AAC 7F0C4F7C 02202025 */  move  $a0, $s1
/* 0F9AB0 7F0C4F80 24460046 */  addiu $a2, $v0, 0x46
/* 0F9AB4 7F0C4F84 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9AB8 7F0C4F88 AFA00010 */   sw    $zero, 0x10($sp)
/* 0F9ABC 7F0C4F8C 00408825 */  move  $s1, $v0
/* 0F9AC0 7F0C4F90 8FA200D4 */  lw    $v0, 0xd4($sp)
/* 0F9AC4 7F0C4F94 24010001 */  li    $at, 1
.L7F0C4F98:
/* 0F9AC8 7F0C4F98 10410017 */  beq   $v0, $at, .L7F0C4FF8
/* 0F9ACC 7F0C4F9C 000270C0 */   sll   $t6, $v0, 3
/* 0F9AD0 7F0C4FA0 01C27023 */  subu  $t6, $t6, $v0
/* 0F9AD4 7F0C4FA4 3C188008 */  lui   $t8, %hi(player1_player_data) 
/* 0F9AD8 7F0C4FA8 27189EF0 */  addiu $t8, %lo(player1_player_data) # addiu $t8, $t8, -0x6110
/* 0F9ADC 7F0C4FAC 000E7100 */  sll   $t6, $t6, 4
/* 0F9AE0 7F0C4FB0 01D85021 */  addu  $t2, $t6, $t8
/* 0F9AE4 7F0C4FB4 0C001145 */  jal   get_video2_settings_ulx
/* 0F9AE8 7F0C4FB8 AFAA0044 */   sw    $t2, 0x44($sp)
/* 0F9AEC 7F0C4FBC 00028400 */  sll   $s0, $v0, 0x10
/* 0F9AF0 7F0C4FC0 00104C03 */  sra   $t1, $s0, 0x10
/* 0F9AF4 7F0C4FC4 0C001149 */  jal   get_video2_settings_uly
/* 0F9AF8 7F0C4FC8 01208025 */   move  $s0, $t1
/* 0F9AFC 7F0C4FCC 8FAC00A8 */  lw    $t4, 0xa8($sp)
/* 0F9B00 7F0C4FD0 8FAB0044 */  lw    $t3, 0x44($sp)
/* 0F9B04 7F0C4FD4 02202025 */  move  $a0, $s1
/* 0F9B08 7F0C4FD8 020C2821 */  addu  $a1, $s0, $t4
/* 0F9B0C 7F0C4FDC 8D670028 */  lw    $a3, 0x28($t3)
/* 0F9B10 7F0C4FE0 AFA00010 */  sw    $zero, 0x10($sp)
/* 0F9B14 7F0C4FE4 24A50060 */  addiu $a1, $a1, 0x60
/* 0F9B18 7F0C4FE8 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9B1C 7F0C4FEC 24460046 */   addiu $a2, $v0, 0x46
/* 0F9B20 7F0C4FF0 00408825 */  move  $s1, $v0
/* 0F9B24 7F0C4FF4 8FA200D4 */  lw    $v0, 0xd4($sp)
.L7F0C4FF8:
/* 0F9B28 7F0C4FF8 24010002 */  li    $at, 2
/* 0F9B2C 7F0C4FFC 10410017 */  beq   $v0, $at, .L7F0C505C
/* 0F9B30 7F0C5000 000278C0 */   sll   $t7, $v0, 3
/* 0F9B34 7F0C5004 01E27823 */  subu  $t7, $t7, $v0
/* 0F9B38 7F0C5008 3C0D8008 */  lui   $t5, %hi(player1_player_data) 
/* 0F9B3C 7F0C500C 25AD9EF0 */  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x6110
/* 0F9B40 7F0C5010 000F7900 */  sll   $t7, $t7, 4
/* 0F9B44 7F0C5014 01EDC821 */  addu  $t9, $t7, $t5
/* 0F9B48 7F0C5018 0C001145 */  jal   get_video2_settings_ulx
/* 0F9B4C 7F0C501C AFB90044 */   sw    $t9, 0x44($sp)
/* 0F9B50 7F0C5020 00028400 */  sll   $s0, $v0, 0x10
/* 0F9B54 7F0C5024 00107403 */  sra   $t6, $s0, 0x10
/* 0F9B58 7F0C5028 0C001149 */  jal   get_video2_settings_uly
/* 0F9B5C 7F0C502C 01C08025 */   move  $s0, $t6
/* 0F9B60 7F0C5030 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0F9B64 7F0C5034 8FAA0044 */  lw    $t2, 0x44($sp)
/* 0F9B68 7F0C5038 02202025 */  move  $a0, $s1
/* 0F9B6C 7F0C503C 02182821 */  addu  $a1, $s0, $t8
/* 0F9B70 7F0C5040 8D47002C */  lw    $a3, 0x2c($t2)
/* 0F9B74 7F0C5044 AFA00010 */  sw    $zero, 0x10($sp)
/* 0F9B78 7F0C5048 24A50040 */  addiu $a1, $a1, 0x40
/* 0F9B7C 7F0C504C 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9B80 7F0C5050 24460056 */   addiu $a2, $v0, 0x56
/* 0F9B84 7F0C5054 00408825 */  move  $s1, $v0
/* 0F9B88 7F0C5058 8FA200D4 */  lw    $v0, 0xd4($sp)
.L7F0C505C:
/* 0F9B8C 7F0C505C 8FA900D0 */  lw    $t1, 0xd0($sp)
/* 0F9B90 7F0C5060 24010004 */  li    $at, 4
/* 0F9B94 7F0C5064 15210018 */  bne   $t1, $at, .L7F0C50C8
/* 0F9B98 7F0C5068 24010003 */   li    $at, 3
/* 0F9B9C 7F0C506C 10410016 */  beq   $v0, $at, .L7F0C50C8
/* 0F9BA0 7F0C5070 000260C0 */   sll   $t4, $v0, 3
/* 0F9BA4 7F0C5074 01826023 */  subu  $t4, $t4, $v0
/* 0F9BA8 7F0C5078 3C0B8008 */  lui   $t3, %hi(player1_player_data) 
/* 0F9BAC 7F0C507C 256B9EF0 */  addiu $t3, %lo(player1_player_data) # addiu $t3, $t3, -0x6110
/* 0F9BB0 7F0C5080 000C6100 */  sll   $t4, $t4, 4
/* 0F9BB4 7F0C5084 018B7821 */  addu  $t7, $t4, $t3
/* 0F9BB8 7F0C5088 0C001145 */  jal   get_video2_settings_ulx
/* 0F9BBC 7F0C508C AFAF0044 */   sw    $t7, 0x44($sp)
/* 0F9BC0 7F0C5090 00028400 */  sll   $s0, $v0, 0x10
/* 0F9BC4 7F0C5094 00106C03 */  sra   $t5, $s0, 0x10
/* 0F9BC8 7F0C5098 0C001149 */  jal   get_video2_settings_uly
/* 0F9BCC 7F0C509C 01A08025 */   move  $s0, $t5
/* 0F9BD0 7F0C50A0 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0F9BD4 7F0C50A4 8FAE0044 */  lw    $t6, 0x44($sp)
/* 0F9BD8 7F0C50A8 02202025 */  move  $a0, $s1
/* 0F9BDC 7F0C50AC 02192821 */  addu  $a1, $s0, $t9
/* 0F9BE0 7F0C50B0 8DC70030 */  lw    $a3, 0x30($t6)
/* 0F9BE4 7F0C50B4 AFA00010 */  sw    $zero, 0x10($sp)
/* 0F9BE8 7F0C50B8 24A50060 */  addiu $a1, $a1, 0x60
/* 0F9BEC 7F0C50BC 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9BF0 7F0C50C0 24460056 */   addiu $a2, $v0, 0x56
/* 0F9BF4 7F0C50C4 00408825 */  move  $s1, $v0
.L7F0C50C8:
/* 0F9BF8 7F0C50C8 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0F9BFC 7F0C50CC 1000029D */  b     .L7F0C5B44
/* 0F9C00 7F0C50D0 8C63A0B0 */   lw    $v1, %lo(pPlayer)($v1)
.L7F0C50D4:
/* 0F9C04 7F0C50D4 24010001 */  li    $at, 1
/* 0F9C08 7F0C50D8 144101A9 */  bne   $v0, $at, .L7F0C5780
/* 0F9C0C 7F0C50DC 3C048009 */   lui   $a0, %hi(is_gameover_flag)
/* 0F9C10 7F0C50E0 8C84C704 */  lw    $a0, %lo(is_gameover_flag)($a0)
/* 0F9C14 7F0C50E4 2C980001 */  sltiu $t8, $a0, 1
/* 0F9C18 7F0C50E8 13000005 */  beqz  $t8, .L7F0C5100
/* 0F9C1C 7F0C50EC 03002025 */   move  $a0, $t8
/* 0F9C20 7F0C50F0 3C048009 */  lui   $a0, %hi(stop_play_flag)
/* 0F9C24 7F0C50F4 8C84C700 */  lw    $a0, %lo(stop_play_flag)($a0)
/* 0F9C28 7F0C50F8 2C8A0001 */  sltiu $t2, $a0, 1
/* 0F9C2C 7F0C50FC 01402025 */  move  $a0, $t2
.L7F0C5100:
/* 0F9C30 7F0C5100 0FC30FD7 */  jal   true_if_displaying_rank_in_mp
/* 0F9C34 7F0C5104 00000000 */   nop   
/* 0F9C38 7F0C5108 10400034 */  beqz  $v0, .L7F0C51DC
/* 0F9C3C 7F0C510C 27A400AC */   addiu $a0, $sp, 0xac
/* 0F9C40 7F0C5110 0FC30F25 */  jal   write_playerrank_to_buffer
/* 0F9C44 7F0C5114 8FA500D4 */   lw    $a1, 0xd4($sp)
/* 0F9C48 7F0C5118 3C098004 */  lui   $t1, %hi(ptrFirstFontTableSmall) 
/* 0F9C4C 7F0C511C 8D290EAC */  lw    $t1, %lo(ptrFirstFontTableSmall)($t1)
/* 0F9C50 7F0C5120 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0F9C54 7F0C5124 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0F9C58 7F0C5128 27A400BC */  addiu $a0, $sp, 0xbc
/* 0F9C5C 7F0C512C 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0F9C60 7F0C5130 27A600AC */  addiu $a2, $sp, 0xac
/* 0F9C64 7F0C5134 AFA00014 */  sw    $zero, 0x14($sp)
/* 0F9C68 7F0C5138 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0F9C6C 7F0C513C AFA90010 */   sw    $t1, 0x10($sp)
/* 0F9C70 7F0C5140 0C001145 */  jal   get_video2_settings_ulx
/* 0F9C74 7F0C5144 00000000 */   nop   
/* 0F9C78 7F0C5148 8FAC00A8 */  lw    $t4, 0xa8($sp)
/* 0F9C7C 7F0C514C 8FAF00C0 */  lw    $t7, 0xc0($sp)
/* 0F9C80 7F0C5150 004C5821 */  addu  $t3, $v0, $t4
/* 0F9C84 7F0C5154 000F6843 */  sra   $t5, $t7, 1
/* 0F9C88 7F0C5158 016D2023 */  subu  $a0, $t3, $t5
/* 0F9C8C 7F0C515C 24840050 */  addiu $a0, $a0, 0x50
/* 0F9C90 7F0C5160 0C001149 */  jal   get_video2_settings_uly
/* 0F9C94 7F0C5164 AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F9C98 7F0C5168 8FB900BC */  lw    $t9, 0xbc($sp)
/* 0F9C9C 7F0C516C 00197043 */  sra   $t6, $t9, 1
/* 0F9CA0 7F0C5170 004EC023 */  subu  $t8, $v0, $t6
/* 0F9CA4 7F0C5174 270A0025 */  addiu $t2, $t8, 0x25
/* 0F9CA8 7F0C5178 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F9CAC 7F0C517C AFAA00C8 */   sw    $t2, 0xc8($sp)
/* 0F9CB0 7F0C5180 00028400 */  sll   $s0, $v0, 0x10
/* 0F9CB4 7F0C5184 00104C03 */  sra   $t1, $s0, 0x10
/* 0F9CB8 7F0C5188 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F9CBC 7F0C518C 01208025 */   move  $s0, $t1
/* 0F9CC0 7F0C5190 3C0C8004 */  lui   $t4, %hi(ptrSecondFontTableSmall) 
/* 0F9CC4 7F0C5194 3C0F8004 */  lui   $t7, %hi(ptrFirstFontTableSmall) 
/* 0F9CC8 7F0C5198 8DEF0EAC */  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
/* 0F9CCC 7F0C519C 8D8C0EB0 */  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
/* 0F9CD0 7F0C51A0 3C0B00FF */  lui   $t3, (0x00FF00B0 >> 16) # lui $t3, 0xff
/* 0F9CD4 7F0C51A4 356B00B0 */  ori   $t3, (0x00FF00B0 & 0xFFFF) # ori $t3, $t3, 0xb0
/* 0F9CD8 7F0C51A8 AFAB0018 */  sw    $t3, 0x18($sp)
/* 0F9CDC 7F0C51AC 02202025 */  move  $a0, $s1
/* 0F9CE0 7F0C51B0 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F9CE4 7F0C51B4 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9CE8 7F0C51B8 27A700AC */  addiu $a3, $sp, 0xac
/* 0F9CEC 7F0C51BC AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F9CF0 7F0C51C0 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F9CF4 7F0C51C4 AFA00024 */  sw    $zero, 0x24($sp)
/* 0F9CF8 7F0C51C8 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9CFC 7F0C51CC AFAF0014 */  sw    $t7, 0x14($sp)
/* 0F9D00 7F0C51D0 0FC2B6AF */  jal   en_text_write_stuff
/* 0F9D04 7F0C51D4 AFAC0010 */   sw    $t4, 0x10($sp)
/* 0F9D08 7F0C51D8 00408825 */  move  $s1, $v0
.L7F0C51DC:
/* 0F9D0C 7F0C51DC 0FC30776 */  jal   get_textptr_for_textID
/* 0F9D10 7F0C51E0 3404A01C */   li    $a0, 40988
/* 0F9D14 7F0C51E4 3404A01E */  li    $a0, 40990
/* 0F9D18 7F0C51E8 0FC30776 */  jal   get_textptr_for_textID
/* 0F9D1C 7F0C51EC AFA2004C */   sw    $v0, 0x4c($sp)
/* 0F9D20 7F0C51F0 8FA700D4 */  lw    $a3, 0xd4($sp)
/* 0F9D24 7F0C51F4 3C058006 */  lui   $a1, %hi(ascii_pnum_LOSSES)
/* 0F9D28 7F0C51F8 24A5BC38 */  addiu $a1, %lo(ascii_pnum_LOSSES) # addiu $a1, $a1, -0x43c8
/* 0F9D2C 7F0C51FC 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0F9D30 7F0C5200 27A400AC */  addiu $a0, $sp, 0xac
/* 0F9D34 7F0C5204 AFA20010 */  sw    $v0, 0x10($sp)
/* 0F9D38 7F0C5208 0C002B25 */  jal   sprintf
/* 0F9D3C 7F0C520C 24E70001 */   addiu $a3, $a3, 1
/* 0F9D40 7F0C5210 3C0D8004 */  lui   $t5, %hi(ptrFirstFontTableSmall) 
/* 0F9D44 7F0C5214 8DAD0EAC */  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
/* 0F9D48 7F0C5218 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0F9D4C 7F0C521C 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0F9D50 7F0C5220 27A400BC */  addiu $a0, $sp, 0xbc
/* 0F9D54 7F0C5224 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0F9D58 7F0C5228 27A600AC */  addiu $a2, $sp, 0xac
/* 0F9D5C 7F0C522C AFA00014 */  sw    $zero, 0x14($sp)
/* 0F9D60 7F0C5230 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0F9D64 7F0C5234 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0F9D68 7F0C5238 0C001145 */  jal   get_video2_settings_ulx
/* 0F9D6C 7F0C523C 00000000 */   nop   
/* 0F9D70 7F0C5240 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0F9D74 7F0C5244 8FB800C0 */  lw    $t8, 0xc0($sp)
/* 0F9D78 7F0C5248 00597021 */  addu  $t6, $v0, $t9
/* 0F9D7C 7F0C524C 00185043 */  sra   $t2, $t8, 1
/* 0F9D80 7F0C5250 01CA2023 */  subu  $a0, $t6, $t2
/* 0F9D84 7F0C5254 24840050 */  addiu $a0, $a0, 0x50
/* 0F9D88 7F0C5258 0C001149 */  jal   get_video2_settings_uly
/* 0F9D8C 7F0C525C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F9D90 7F0C5260 8FA900BC */  lw    $t1, 0xbc($sp)
/* 0F9D94 7F0C5264 00096043 */  sra   $t4, $t1, 1
/* 0F9D98 7F0C5268 004C7823 */  subu  $t7, $v0, $t4
/* 0F9D9C 7F0C526C 25EB0035 */  addiu $t3, $t7, 0x35
/* 0F9DA0 7F0C5270 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F9DA4 7F0C5274 AFAB00C8 */   sw    $t3, 0xc8($sp)
/* 0F9DA8 7F0C5278 00028400 */  sll   $s0, $v0, 0x10
/* 0F9DAC 7F0C527C 00106C03 */  sra   $t5, $s0, 0x10
/* 0F9DB0 7F0C5280 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F9DB4 7F0C5284 01A08025 */   move  $s0, $t5
/* 0F9DB8 7F0C5288 3C198004 */  lui   $t9, %hi(ptrSecondFontTableSmall) 
/* 0F9DBC 7F0C528C 3C188004 */  lui   $t8, %hi(ptrFirstFontTableSmall) 
/* 0F9DC0 7F0C5290 8F180EAC */  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
/* 0F9DC4 7F0C5294 8F390EB0 */  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
/* 0F9DC8 7F0C5298 3C0EFF40 */  lui   $t6, (0xFF4040B0 >> 16) # lui $t6, 0xff40
/* 0F9DCC 7F0C529C 35CE40B0 */  ori   $t6, (0xFF4040B0 & 0xFFFF) # ori $t6, $t6, 0x40b0
/* 0F9DD0 7F0C52A0 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0F9DD4 7F0C52A4 02202025 */  move  $a0, $s1
/* 0F9DD8 7F0C52A8 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F9DDC 7F0C52AC 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9DE0 7F0C52B0 27A700AC */  addiu $a3, $sp, 0xac
/* 0F9DE4 7F0C52B4 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F9DE8 7F0C52B8 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F9DEC 7F0C52BC AFA00024 */  sw    $zero, 0x24($sp)
/* 0F9DF0 7F0C52C0 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9DF4 7F0C52C4 AFB80014 */  sw    $t8, 0x14($sp)
/* 0F9DF8 7F0C52C8 0FC2B6AF */  jal   en_text_write_stuff
/* 0F9DFC 7F0C52CC AFB90010 */   sw    $t9, 0x10($sp)
/* 0F9E00 7F0C52D0 8FAA00D0 */  lw    $t2, 0xd0($sp)
/* 0F9E04 7F0C52D4 24010002 */  li    $at, 2
/* 0F9E08 7F0C52D8 00408825 */  move  $s1, $v0
/* 0F9E0C 7F0C52DC 15410062 */  bne   $t2, $at, .L7F0C5468
/* 0F9E10 7F0C52E0 8FB800D4 */   lw    $t8, 0xd4($sp)
/* 0F9E14 7F0C52E4 8FA200D4 */  lw    $v0, 0xd4($sp)
/* 0F9E18 7F0C52E8 3C0D8008 */  lui   $t5, %hi(player1_player_data + 0x24) 
/* 0F9E1C 7F0C52EC 10400016 */  beqz  $v0, .L7F0C5348
/* 0F9E20 7F0C52F0 00000000 */   nop   
/* 0F9E24 7F0C52F4 0C001145 */  jal   get_video2_settings_ulx
/* 0F9E28 7F0C52F8 00000000 */   nop   
/* 0F9E2C 7F0C52FC 00028400 */  sll   $s0, $v0, 0x10
/* 0F9E30 7F0C5300 00104C03 */  sra   $t1, $s0, 0x10
/* 0F9E34 7F0C5304 0C001149 */  jal   get_video2_settings_uly
/* 0F9E38 7F0C5308 01208025 */   move  $s0, $t1
/* 0F9E3C 7F0C530C 8FAF00D4 */  lw    $t7, 0xd4($sp)
/* 0F9E40 7F0C5310 8FAC00A8 */  lw    $t4, 0xa8($sp)
/* 0F9E44 7F0C5314 3C078008 */  lui   $a3, %hi(player1_player_data+36)
/* 0F9E48 7F0C5318 000F5880 */  sll   $t3, $t7, 2
/* 0F9E4C 7F0C531C 00EB3821 */  addu  $a3, $a3, $t3
/* 0F9E50 7F0C5320 020C2821 */  addu  $a1, $s0, $t4
/* 0F9E54 7F0C5324 24A50050 */  addiu $a1, $a1, 0x50
/* 0F9E58 7F0C5328 8CE79F14 */  lw    $a3, %lo(player1_player_data+36)($a3)
/* 0F9E5C 7F0C532C 02202025 */  move  $a0, $s1
/* 0F9E60 7F0C5330 24460046 */  addiu $a2, $v0, 0x46
/* 0F9E64 7F0C5334 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9E68 7F0C5338 AFA00010 */   sw    $zero, 0x10($sp)
/* 0F9E6C 7F0C533C 00408825 */  move  $s1, $v0
/* 0F9E70 7F0C5340 10000019 */  b     .L7F0C53A8
/* 0F9E74 7F0C5344 8FA200D4 */   lw    $v0, 0xd4($sp)
.L7F0C5348:
/* 0F9E78 7F0C5348 8DAD9F14 */  lw    $t5, %lo(player1_player_data + 0x24)($t5)
/* 0F9E7C 7F0C534C 59A00017 */  blezl $t5, .L7F0C53AC
/* 0F9E80 7F0C5350 24010001 */   li    $at, 1
/* 0F9E84 7F0C5354 0C001145 */  jal   get_video2_settings_ulx
/* 0F9E88 7F0C5358 00000000 */   nop   
/* 0F9E8C 7F0C535C 00028400 */  sll   $s0, $v0, 0x10
/* 0F9E90 7F0C5360 0010CC03 */  sra   $t9, $s0, 0x10
/* 0F9E94 7F0C5364 0C001149 */  jal   get_video2_settings_uly
/* 0F9E98 7F0C5368 03208025 */   move  $s0, $t9
/* 0F9E9C 7F0C536C 8FAE00D4 */  lw    $t6, 0xd4($sp)
/* 0F9EA0 7F0C5370 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0F9EA4 7F0C5374 3C078008 */  lui   $a3, %hi(player1_player_data+36)
/* 0F9EA8 7F0C5378 000E5080 */  sll   $t2, $t6, 2
/* 0F9EAC 7F0C537C 00EA3821 */  addu  $a3, $a3, $t2
/* 0F9EB0 7F0C5380 24090003 */  li    $t1, 3
/* 0F9EB4 7F0C5384 02182821 */  addu  $a1, $s0, $t8
/* 0F9EB8 7F0C5388 24A50050 */  addiu $a1, $a1, 0x50
/* 0F9EBC 7F0C538C AFA90010 */  sw    $t1, 0x10($sp)
/* 0F9EC0 7F0C5390 8CE79F14 */  lw    $a3, %lo(player1_player_data+36)($a3)
/* 0F9EC4 7F0C5394 02202025 */  move  $a0, $s1
/* 0F9EC8 7F0C5398 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9ECC 7F0C539C 24460046 */   addiu $a2, $v0, 0x46
/* 0F9ED0 7F0C53A0 00408825 */  move  $s1, $v0
/* 0F9ED4 7F0C53A4 8FA200D4 */  lw    $v0, 0xd4($sp)
.L7F0C53A8:
/* 0F9ED8 7F0C53A8 24010001 */  li    $at, 1
.L7F0C53AC:
/* 0F9EDC 7F0C53AC 10410016 */  beq   $v0, $at, .L7F0C5408
/* 0F9EE0 7F0C53B0 3C0E8008 */   lui   $t6, %hi(player2_player_data + 0x28) 
/* 0F9EE4 7F0C53B4 3C0F8008 */  lui   $t7, %hi(player1_player_data) 
/* 0F9EE8 7F0C53B8 25EF9EF0 */  addiu $t7, %lo(player1_player_data) # addiu $t7, $t7, -0x6110
/* 0F9EEC 7F0C53BC 00026080 */  sll   $t4, $v0, 2
/* 0F9EF0 7F0C53C0 018F5821 */  addu  $t3, $t4, $t7
/* 0F9EF4 7F0C53C4 0C001145 */  jal   get_video2_settings_ulx
/* 0F9EF8 7F0C53C8 AFAB0044 */   sw    $t3, 0x44($sp)
/* 0F9EFC 7F0C53CC 00028400 */  sll   $s0, $v0, 0x10
/* 0F9F00 7F0C53D0 00106C03 */  sra   $t5, $s0, 0x10
/* 0F9F04 7F0C53D4 0C001149 */  jal   get_video2_settings_uly
/* 0F9F08 7F0C53D8 01A08025 */   move  $s0, $t5
/* 0F9F0C 7F0C53DC 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0F9F10 7F0C53E0 8FB80044 */  lw    $t8, 0x44($sp)
/* 0F9F14 7F0C53E4 02202025 */  move  $a0, $s1
/* 0F9F18 7F0C53E8 02192821 */  addu  $a1, $s0, $t9
/* 0F9F1C 7F0C53EC 8F070094 */  lw    $a3, 0x94($t8)
/* 0F9F20 7F0C53F0 AFA00010 */  sw    $zero, 0x10($sp)
/* 0F9F24 7F0C53F4 24A50050 */  addiu $a1, $a1, 0x50
/* 0F9F28 7F0C53F8 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9F2C 7F0C53FC 24460056 */   addiu $a2, $v0, 0x56
/* 0F9F30 7F0C5400 100000DC */  b     .L7F0C5774
/* 0F9F34 7F0C5404 00408825 */   move  $s1, $v0
.L7F0C5408:
/* 0F9F38 7F0C5408 8DCE9F88 */  lw    $t6, %lo(player2_player_data + 0x28)($t6)
/* 0F9F3C 7F0C540C 3C098008 */  lui   $t1, %hi(player1_player_data) 
/* 0F9F40 7F0C5410 25299EF0 */  addiu $t1, %lo(player1_player_data) # addiu $t1, $t1, -0x6110
/* 0F9F44 7F0C5414 19C000D7 */  blez  $t6, .L7F0C5774
/* 0F9F48 7F0C5418 00025080 */   sll   $t2, $v0, 2
/* 0F9F4C 7F0C541C 01496021 */  addu  $t4, $t2, $t1
/* 0F9F50 7F0C5420 0C001145 */  jal   get_video2_settings_ulx
/* 0F9F54 7F0C5424 AFAC0044 */   sw    $t4, 0x44($sp)
/* 0F9F58 7F0C5428 00028400 */  sll   $s0, $v0, 0x10
/* 0F9F5C 7F0C542C 00107C03 */  sra   $t7, $s0, 0x10
/* 0F9F60 7F0C5430 0C001149 */  jal   get_video2_settings_uly
/* 0F9F64 7F0C5434 01E08025 */   move  $s0, $t7
/* 0F9F68 7F0C5438 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0F9F6C 7F0C543C 8FAD0044 */  lw    $t5, 0x44($sp)
/* 0F9F70 7F0C5440 24190003 */  li    $t9, 3
/* 0F9F74 7F0C5444 020B2821 */  addu  $a1, $s0, $t3
/* 0F9F78 7F0C5448 8DA70094 */  lw    $a3, 0x94($t5)
/* 0F9F7C 7F0C544C AFB90010 */  sw    $t9, 0x10($sp)
/* 0F9F80 7F0C5450 24A50050 */  addiu $a1, $a1, 0x50
/* 0F9F84 7F0C5454 02202025 */  move  $a0, $s1
/* 0F9F88 7F0C5458 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9F8C 7F0C545C 24460056 */   addiu $a2, $v0, 0x56
/* 0F9F90 7F0C5460 100000C4 */  b     .L7F0C5774
/* 0F9F94 7F0C5464 00408825 */   move  $s1, $v0
.L7F0C5468:
/* 0F9F98 7F0C5468 13000015 */  beqz  $t8, .L7F0C54C0
/* 0F9F9C 7F0C546C 3C0F8008 */   lui   $t7, %hi(player1_player_data + 0x24) 
/* 0F9FA0 7F0C5470 0C001145 */  jal   get_video2_settings_ulx
/* 0F9FA4 7F0C5474 00000000 */   nop   
/* 0F9FA8 7F0C5478 00028400 */  sll   $s0, $v0, 0x10
/* 0F9FAC 7F0C547C 00107403 */  sra   $t6, $s0, 0x10
/* 0F9FB0 7F0C5480 0C001149 */  jal   get_video2_settings_uly
/* 0F9FB4 7F0C5484 01C08025 */   move  $s0, $t6
/* 0F9FB8 7F0C5488 8FA900D4 */  lw    $t1, 0xd4($sp)
/* 0F9FBC 7F0C548C 8FAA00A8 */  lw    $t2, 0xa8($sp)
/* 0F9FC0 7F0C5490 3C078008 */  lui   $a3, %hi(player1_player_data+36)
/* 0F9FC4 7F0C5494 00096080 */  sll   $t4, $t1, 2
/* 0F9FC8 7F0C5498 00EC3821 */  addu  $a3, $a3, $t4
/* 0F9FCC 7F0C549C 020A2821 */  addu  $a1, $s0, $t2
/* 0F9FD0 7F0C54A0 24A50040 */  addiu $a1, $a1, 0x40
/* 0F9FD4 7F0C54A4 8CE79F14 */  lw    $a3, %lo(player1_player_data+36)($a3)
/* 0F9FD8 7F0C54A8 02202025 */  move  $a0, $s1
/* 0F9FDC 7F0C54AC 24460046 */  addiu $a2, $v0, 0x46
/* 0F9FE0 7F0C54B0 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0F9FE4 7F0C54B4 AFA00010 */   sw    $zero, 0x10($sp)
/* 0F9FE8 7F0C54B8 10000018 */  b     .L7F0C551C
/* 0F9FEC 7F0C54BC 00408825 */   move  $s1, $v0
.L7F0C54C0:
/* 0F9FF0 7F0C54C0 8DEF9F14 */  lw    $t7, %lo(player1_player_data + 0x24)($t7)
/* 0F9FF4 7F0C54C4 59E00016 */  blezl $t7, .L7F0C5520
/* 0F9FF8 7F0C54C8 8FAA00D4 */   lw    $t2, 0xd4($sp)
/* 0F9FFC 7F0C54CC 0C001145 */  jal   get_video2_settings_ulx
/* 0FA000 7F0C54D0 00000000 */   nop   
/* 0FA004 7F0C54D4 00028400 */  sll   $s0, $v0, 0x10
/* 0FA008 7F0C54D8 00105C03 */  sra   $t3, $s0, 0x10
/* 0FA00C 7F0C54DC 0C001149 */  jal   get_video2_settings_uly
/* 0FA010 7F0C54E0 01608025 */   move  $s0, $t3
/* 0FA014 7F0C54E4 8FB900D4 */  lw    $t9, 0xd4($sp)
/* 0FA018 7F0C54E8 8FAD00A8 */  lw    $t5, 0xa8($sp)
/* 0FA01C 7F0C54EC 3C078008 */  lui   $a3, %hi(player1_player_data+36)
/* 0FA020 7F0C54F0 0019C080 */  sll   $t8, $t9, 2
/* 0FA024 7F0C54F4 00F83821 */  addu  $a3, $a3, $t8
/* 0FA028 7F0C54F8 240E0003 */  li    $t6, 3
/* 0FA02C 7F0C54FC 020D2821 */  addu  $a1, $s0, $t5
/* 0FA030 7F0C5500 24A50040 */  addiu $a1, $a1, 0x40
/* 0FA034 7F0C5504 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0FA038 7F0C5508 8CE79F14 */  lw    $a3, %lo(player1_player_data+36)($a3)
/* 0FA03C 7F0C550C 02202025 */  move  $a0, $s1
/* 0FA040 7F0C5510 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA044 7F0C5514 24460046 */   addiu $a2, $v0, 0x46
/* 0FA048 7F0C5518 00408825 */  move  $s1, $v0
.L7F0C551C:
/* 0FA04C 7F0C551C 8FAA00D4 */  lw    $t2, 0xd4($sp)
.L7F0C5520:
/* 0FA050 7F0C5520 24010001 */  li    $at, 1
/* 0FA054 7F0C5524 3C188008 */  lui   $t8, %hi(player2_player_data + 0x28) 
/* 0FA058 7F0C5528 11410015 */  beq   $t2, $at, .L7F0C5580
/* 0FA05C 7F0C552C 000A4880 */   sll   $t1, $t2, 2
/* 0FA060 7F0C5530 3C0C8008 */  lui   $t4, %hi(player1_player_data) 
/* 0FA064 7F0C5534 258C9EF0 */  addiu $t4, %lo(player1_player_data) # addiu $t4, $t4, -0x6110
/* 0FA068 7F0C5538 012C7821 */  addu  $t7, $t1, $t4
/* 0FA06C 7F0C553C 0C001145 */  jal   get_video2_settings_ulx
/* 0FA070 7F0C5540 AFAF0044 */   sw    $t7, 0x44($sp)
/* 0FA074 7F0C5544 00028400 */  sll   $s0, $v0, 0x10
/* 0FA078 7F0C5548 00105C03 */  sra   $t3, $s0, 0x10
/* 0FA07C 7F0C554C 0C001149 */  jal   get_video2_settings_uly
/* 0FA080 7F0C5550 01608025 */   move  $s0, $t3
/* 0FA084 7F0C5554 8FAD00A8 */  lw    $t5, 0xa8($sp)
/* 0FA088 7F0C5558 8FB90044 */  lw    $t9, 0x44($sp)
/* 0FA08C 7F0C555C 02202025 */  move  $a0, $s1
/* 0FA090 7F0C5560 020D2821 */  addu  $a1, $s0, $t5
/* 0FA094 7F0C5564 8F270094 */  lw    $a3, 0x94($t9)
/* 0FA098 7F0C5568 AFA00010 */  sw    $zero, 0x10($sp)
/* 0FA09C 7F0C556C 24A50060 */  addiu $a1, $a1, 0x60
/* 0FA0A0 7F0C5570 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA0A4 7F0C5574 24460046 */   addiu $a2, $v0, 0x46
/* 0FA0A8 7F0C5578 10000019 */  b     .L7F0C55E0
/* 0FA0AC 7F0C557C 00408825 */   move  $s1, $v0
.L7F0C5580:
/* 0FA0B0 7F0C5580 8F189F88 */  lw    $t8, %lo(player2_player_data + 0x28)($t8)
/* 0FA0B4 7F0C5584 8FAE00D4 */  lw    $t6, 0xd4($sp)
/* 0FA0B8 7F0C5588 3C098008 */  lui   $t1, %hi(player1_player_data) 
/* 0FA0BC 7F0C558C 1B000014 */  blez  $t8, .L7F0C55E0
/* 0FA0C0 7F0C5590 000E5080 */   sll   $t2, $t6, 2
/* 0FA0C4 7F0C5594 25299EF0 */  addiu $t1, %lo(player1_player_data) # addiu $t1, $t1, -0x6110
/* 0FA0C8 7F0C5598 01496021 */  addu  $t4, $t2, $t1
/* 0FA0CC 7F0C559C 0C001145 */  jal   get_video2_settings_ulx
/* 0FA0D0 7F0C55A0 AFAC0044 */   sw    $t4, 0x44($sp)
/* 0FA0D4 7F0C55A4 00028400 */  sll   $s0, $v0, 0x10
/* 0FA0D8 7F0C55A8 00107C03 */  sra   $t7, $s0, 0x10
/* 0FA0DC 7F0C55AC 0C001149 */  jal   get_video2_settings_uly
/* 0FA0E0 7F0C55B0 01E08025 */   move  $s0, $t7
/* 0FA0E4 7F0C55B4 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0FA0E8 7F0C55B8 8FAD0044 */  lw    $t5, 0x44($sp)
/* 0FA0EC 7F0C55BC 24190003 */  li    $t9, 3
/* 0FA0F0 7F0C55C0 020B2821 */  addu  $a1, $s0, $t3
/* 0FA0F4 7F0C55C4 8DA70094 */  lw    $a3, 0x94($t5)
/* 0FA0F8 7F0C55C8 AFB90010 */  sw    $t9, 0x10($sp)
/* 0FA0FC 7F0C55CC 24A50060 */  addiu $a1, $a1, 0x60
/* 0FA100 7F0C55D0 02202025 */  move  $a0, $s1
/* 0FA104 7F0C55D4 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA108 7F0C55D8 24460046 */   addiu $a2, $v0, 0x46
/* 0FA10C 7F0C55DC 00408825 */  move  $s1, $v0
.L7F0C55E0:
/* 0FA110 7F0C55E0 8FB800D4 */  lw    $t8, 0xd4($sp)
/* 0FA114 7F0C55E4 24010002 */  li    $at, 2
/* 0FA118 7F0C55E8 3C0D8008 */  lui   $t5, %hi(player3_player_data + 0x2C) 
/* 0FA11C 7F0C55EC 13010015 */  beq   $t8, $at, .L7F0C5644
/* 0FA120 7F0C55F0 00187080 */   sll   $t6, $t8, 2
/* 0FA124 7F0C55F4 3C0A8008 */  lui   $t2, %hi(player1_player_data) 
/* 0FA128 7F0C55F8 254A9EF0 */  addiu $t2, %lo(player1_player_data) # addiu $t2, $t2, -0x6110
/* 0FA12C 7F0C55FC 01CA4821 */  addu  $t1, $t6, $t2
/* 0FA130 7F0C5600 0C001145 */  jal   get_video2_settings_ulx
/* 0FA134 7F0C5604 AFA90044 */   sw    $t1, 0x44($sp)
/* 0FA138 7F0C5608 00028400 */  sll   $s0, $v0, 0x10
/* 0FA13C 7F0C560C 00106403 */  sra   $t4, $s0, 0x10
/* 0FA140 7F0C5610 0C001149 */  jal   get_video2_settings_uly
/* 0FA144 7F0C5614 01808025 */   move  $s0, $t4
/* 0FA148 7F0C5618 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0FA14C 7F0C561C 8FAB0044 */  lw    $t3, 0x44($sp)
/* 0FA150 7F0C5620 02202025 */  move  $a0, $s1
/* 0FA154 7F0C5624 020F2821 */  addu  $a1, $s0, $t7
/* 0FA158 7F0C5628 8D670104 */  lw    $a3, 0x104($t3)
/* 0FA15C 7F0C562C AFA00010 */  sw    $zero, 0x10($sp)
/* 0FA160 7F0C5630 24A50040 */  addiu $a1, $a1, 0x40
/* 0FA164 7F0C5634 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA168 7F0C5638 24460056 */   addiu $a2, $v0, 0x56
/* 0FA16C 7F0C563C 10000019 */  b     .L7F0C56A4
/* 0FA170 7F0C5640 00408825 */   move  $s1, $v0
.L7F0C5644:
/* 0FA174 7F0C5644 8DAD9FFC */  lw    $t5, %lo(player3_player_data + 0x2C)($t5)
/* 0FA178 7F0C5648 8FB900D4 */  lw    $t9, 0xd4($sp)
/* 0FA17C 7F0C564C 3C0E8008 */  lui   $t6, %hi(player1_player_data) 
/* 0FA180 7F0C5650 19A00014 */  blez  $t5, .L7F0C56A4
/* 0FA184 7F0C5654 0019C080 */   sll   $t8, $t9, 2
/* 0FA188 7F0C5658 25CE9EF0 */  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
/* 0FA18C 7F0C565C 030E5021 */  addu  $t2, $t8, $t6
/* 0FA190 7F0C5660 0C001145 */  jal   get_video2_settings_ulx
/* 0FA194 7F0C5664 AFAA0044 */   sw    $t2, 0x44($sp)
/* 0FA198 7F0C5668 00028400 */  sll   $s0, $v0, 0x10
/* 0FA19C 7F0C566C 00104C03 */  sra   $t1, $s0, 0x10
/* 0FA1A0 7F0C5670 0C001149 */  jal   get_video2_settings_uly
/* 0FA1A4 7F0C5674 01208025 */   move  $s0, $t1
/* 0FA1A8 7F0C5678 8FAC00A8 */  lw    $t4, 0xa8($sp)
/* 0FA1AC 7F0C567C 8FAF0044 */  lw    $t7, 0x44($sp)
/* 0FA1B0 7F0C5680 240B0003 */  li    $t3, 3
/* 0FA1B4 7F0C5684 020C2821 */  addu  $a1, $s0, $t4
/* 0FA1B8 7F0C5688 8DE70104 */  lw    $a3, 0x104($t7)
/* 0FA1BC 7F0C568C AFAB0010 */  sw    $t3, 0x10($sp)
/* 0FA1C0 7F0C5690 24A50040 */  addiu $a1, $a1, 0x40
/* 0FA1C4 7F0C5694 02202025 */  move  $a0, $s1
/* 0FA1C8 7F0C5698 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA1CC 7F0C569C 24460056 */   addiu $a2, $v0, 0x56
/* 0FA1D0 7F0C56A0 00408825 */  move  $s1, $v0
.L7F0C56A4:
/* 0FA1D4 7F0C56A4 8FAD00D0 */  lw    $t5, 0xd0($sp)
/* 0FA1D8 7F0C56A8 24010004 */  li    $at, 4
/* 0FA1DC 7F0C56AC 8FB900D4 */  lw    $t9, 0xd4($sp)
/* 0FA1E0 7F0C56B0 15A10030 */  bne   $t5, $at, .L7F0C5774
/* 0FA1E4 7F0C56B4 24010003 */   li    $at, 3
/* 0FA1E8 7F0C56B8 13210016 */  beq   $t9, $at, .L7F0C5714
/* 0FA1EC 7F0C56BC 3C0B8008 */   lui   $t3, %hi(player3_player_data + 0x30) 
/* 0FA1F0 7F0C56C0 3C0E8008 */  lui   $t6, %hi(player1_player_data) 
/* 0FA1F4 7F0C56C4 25CE9EF0 */  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
/* 0FA1F8 7F0C56C8 0019C080 */  sll   $t8, $t9, 2
/* 0FA1FC 7F0C56CC 030E5021 */  addu  $t2, $t8, $t6
/* 0FA200 7F0C56D0 0C001145 */  jal   get_video2_settings_ulx
/* 0FA204 7F0C56D4 AFAA0044 */   sw    $t2, 0x44($sp)
/* 0FA208 7F0C56D8 00028400 */  sll   $s0, $v0, 0x10
/* 0FA20C 7F0C56DC 00104C03 */  sra   $t1, $s0, 0x10
/* 0FA210 7F0C56E0 0C001149 */  jal   get_video2_settings_uly
/* 0FA214 7F0C56E4 01208025 */   move  $s0, $t1
/* 0FA218 7F0C56E8 8FAC00A8 */  lw    $t4, 0xa8($sp)
/* 0FA21C 7F0C56EC 8FAF0044 */  lw    $t7, 0x44($sp)
/* 0FA220 7F0C56F0 02202025 */  move  $a0, $s1
/* 0FA224 7F0C56F4 020C2821 */  addu  $a1, $s0, $t4
/* 0FA228 7F0C56F8 8DE70174 */  lw    $a3, 0x174($t7)
/* 0FA22C 7F0C56FC AFA00010 */  sw    $zero, 0x10($sp)
/* 0FA230 7F0C5700 24A50060 */  addiu $a1, $a1, 0x60
/* 0FA234 7F0C5704 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA238 7F0C5708 24460056 */   addiu $a2, $v0, 0x56
/* 0FA23C 7F0C570C 10000019 */  b     .L7F0C5774
/* 0FA240 7F0C5710 00408825 */   move  $s1, $v0
.L7F0C5714:
/* 0FA244 7F0C5714 8D6BA070 */  lw    $t3, %lo(player4_player_data+0x30)($t3)
/* 0FA248 7F0C5718 8FAD00D4 */  lw    $t5, 0xd4($sp)
/* 0FA24C 7F0C571C 3C188008 */  lui   $t8, %hi(player1_player_data) 
/* 0FA250 7F0C5720 19600014 */  blez  $t3, .L7F0C5774
/* 0FA254 7F0C5724 000DC880 */   sll   $t9, $t5, 2
/* 0FA258 7F0C5728 27189EF0 */  addiu $t8, %lo(player1_player_data) # addiu $t8, $t8, -0x6110
/* 0FA25C 7F0C572C 03387021 */  addu  $t6, $t9, $t8
/* 0FA260 7F0C5730 0C001145 */  jal   get_video2_settings_ulx
/* 0FA264 7F0C5734 AFAE0044 */   sw    $t6, 0x44($sp)
/* 0FA268 7F0C5738 00028400 */  sll   $s0, $v0, 0x10
/* 0FA26C 7F0C573C 00105403 */  sra   $t2, $s0, 0x10
/* 0FA270 7F0C5740 0C001149 */  jal   get_video2_settings_uly
/* 0FA274 7F0C5744 01408025 */   move  $s0, $t2
/* 0FA278 7F0C5748 8FA900A8 */  lw    $t1, 0xa8($sp)
/* 0FA27C 7F0C574C 8FAC0044 */  lw    $t4, 0x44($sp)
/* 0FA280 7F0C5750 240F0003 */  li    $t7, 3
/* 0FA284 7F0C5754 02092821 */  addu  $a1, $s0, $t1
/* 0FA288 7F0C5758 8D870174 */  lw    $a3, 0x174($t4)
/* 0FA28C 7F0C575C AFAF0010 */  sw    $t7, 0x10($sp)
/* 0FA290 7F0C5760 24A50060 */  addiu $a1, $a1, 0x60
/* 0FA294 7F0C5764 02202025 */  move  $a0, $s1
/* 0FA298 7F0C5768 0FC30D68 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA29C 7F0C576C 24460056 */   addiu $a2, $v0, 0x56
/* 0FA2A0 7F0C5770 00408825 */  move  $s1, $v0
.L7F0C5774:
/* 0FA2A4 7F0C5774 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0FA2A8 7F0C5778 100000F2 */  b     .L7F0C5B44
/* 0FA2AC 7F0C577C 8C63A0B0 */   lw    $v1, %lo(pPlayer)($v1)
.L7F0C5780:
/* 0FA2B0 7F0C5780 544000F1 */  bnezl $v0, .L7F0C5B48
/* 0FA2B4 7F0C5784 8C6F29C8 */   lw    $t7, 0x29c8($v1)
/* 0FA2B8 7F0C5788 8FAD00D0 */  lw    $t5, 0xd0($sp)
/* 0FA2BC 7F0C578C 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0FA2C0 7F0C5790 29A10003 */  slti  $at, $t5, 3
/* 0FA2C4 7F0C5794 1420000A */  bnez  $at, .L7F0C57C0
/* 0FA2C8 7F0C5798 AFAB0074 */   sw    $t3, 0x74($sp)
/* 0FA2CC 7F0C579C 8FB900D4 */  lw    $t9, 0xd4($sp)
/* 0FA2D0 7F0C57A0 8FAA00A8 */  lw    $t2, 0xa8($sp)
/* 0FA2D4 7F0C57A4 256EFFF9 */  addiu $t6, $t3, -7
/* 0FA2D8 7F0C57A8 33380001 */  andi  $t8, $t9, 1
/* 0FA2DC 7F0C57AC 13000003 */  beqz  $t8, .L7F0C57BC
/* 0FA2E0 7F0C57B0 25490007 */   addiu $t1, $t2, 7
/* 0FA2E4 7F0C57B4 10000002 */  b     .L7F0C57C0
/* 0FA2E8 7F0C57B8 AFAE0074 */   sw    $t6, 0x74($sp)
.L7F0C57BC:
/* 0FA2EC 7F0C57BC AFA90074 */  sw    $t1, 0x74($sp)
.L7F0C57C0:
/* 0FA2F0 7F0C57C0 0FC30776 */  jal   get_textptr_for_textID
/* 0FA2F4 7F0C57C4 3404A01F */   li    $a0, 40991
/* 0FA2F8 7F0C57C8 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) 
/* 0FA2FC 7F0C57CC 8D8C0EAC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0FA300 7F0C57D0 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0FA304 7F0C57D4 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0FA308 7F0C57D8 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FA30C 7F0C57DC 27A4007C */  addiu $a0, $sp, 0x7c
/* 0FA310 7F0C57E0 27A50078 */  addiu $a1, $sp, 0x78
/* 0FA314 7F0C57E4 00403025 */  move  $a2, $v0
/* 0FA318 7F0C57E8 AFA00014 */  sw    $zero, 0x14($sp)
/* 0FA31C 7F0C57EC 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0FA320 7F0C57F0 AFAC0010 */   sw    $t4, 0x10($sp)
/* 0FA324 7F0C57F4 0C001145 */  jal   get_video2_settings_ulx
/* 0FA328 7F0C57F8 00000000 */   nop   
/* 0FA32C 7F0C57FC 8FAF0074 */  lw    $t7, 0x74($sp)
/* 0FA330 7F0C5800 8FB90078 */  lw    $t9, 0x78($sp)
/* 0FA334 7F0C5804 004F6821 */  addu  $t5, $v0, $t7
/* 0FA338 7F0C5808 0019C043 */  sra   $t8, $t9, 1
/* 0FA33C 7F0C580C 01B82023 */  subu  $a0, $t5, $t8
/* 0FA340 7F0C5810 24840050 */  addiu $a0, $a0, 0x50
/* 0FA344 7F0C5814 0C001149 */  jal   get_video2_settings_uly
/* 0FA348 7F0C5818 AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FA34C 7F0C581C 8FAB007C */  lw    $t3, 0x7c($sp)
/* 0FA350 7F0C5820 000B7043 */  sra   $t6, $t3, 1
/* 0FA354 7F0C5824 004E5023 */  subu  $t2, $v0, $t6
/* 0FA358 7F0C5828 25490025 */  addiu $t1, $t2, 0x25
/* 0FA35C 7F0C582C 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FA360 7F0C5830 AFA900C8 */   sw    $t1, 0xc8($sp)
/* 0FA364 7F0C5834 00028400 */  sll   $s0, $v0, 0x10
/* 0FA368 7F0C5838 00106403 */  sra   $t4, $s0, 0x10
/* 0FA36C 7F0C583C 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FA370 7F0C5840 01808025 */   move  $s0, $t4
/* 0FA374 7F0C5844 3C0F8004 */  lui   $t7, %hi(ptrSecondFontTableSmall) 
/* 0FA378 7F0C5848 3C198004 */  lui   $t9, %hi(ptrFirstFontTableSmall) 
/* 0FA37C 7F0C584C 8F390EAC */  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
/* 0FA380 7F0C5850 8DEF0EB0 */  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
/* 0FA384 7F0C5854 3C0D00FF */  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
/* 0FA388 7F0C5858 35AD00B0 */  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0FA38C 7F0C585C AFAD0018 */  sw    $t5, 0x18($sp)
/* 0FA390 7F0C5860 02202025 */  move  $a0, $s1
/* 0FA394 7F0C5864 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FA398 7F0C5868 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FA39C 7F0C586C 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FA3A0 7F0C5870 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FA3A4 7F0C5874 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FA3A8 7F0C5878 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FA3AC 7F0C587C AFA00028 */  sw    $zero, 0x28($sp)
/* 0FA3B0 7F0C5880 AFB90014 */  sw    $t9, 0x14($sp)
/* 0FA3B4 7F0C5884 0FC2B6AF */  jal   en_text_write_stuff
/* 0FA3B8 7F0C5888 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0FA3BC 7F0C588C 00408825 */  move  $s1, $v0
/* 0FA3C0 7F0C5890 8FA400D4 */  lw    $a0, 0xd4($sp)
/* 0FA3C4 7F0C5894 0FC026D4 */  jal   getplayerfavoredweapon
/* 0FA3C8 7F0C5898 00002825 */   move  $a1, $zero
/* 0FA3CC 7F0C589C 3C188004 */  lui   $t8, %hi(ptrFirstFontTableSmall) 
/* 0FA3D0 7F0C58A0 8F180EAC */  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
/* 0FA3D4 7F0C58A4 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0FA3D8 7F0C58A8 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0FA3DC 7F0C58AC 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FA3E0 7F0C58B0 27A4007C */  addiu $a0, $sp, 0x7c
/* 0FA3E4 7F0C58B4 27A50078 */  addiu $a1, $sp, 0x78
/* 0FA3E8 7F0C58B8 00403025 */  move  $a2, $v0
/* 0FA3EC 7F0C58BC AFA00014 */  sw    $zero, 0x14($sp)
/* 0FA3F0 7F0C58C0 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0FA3F4 7F0C58C4 AFB80010 */   sw    $t8, 0x10($sp)
/* 0FA3F8 7F0C58C8 0C001145 */  jal   get_video2_settings_ulx
/* 0FA3FC 7F0C58CC 00000000 */   nop   
/* 0FA400 7F0C58D0 8FAB0074 */  lw    $t3, 0x74($sp)
/* 0FA404 7F0C58D4 8FAA0078 */  lw    $t2, 0x78($sp)
/* 0FA408 7F0C58D8 004B7021 */  addu  $t6, $v0, $t3
/* 0FA40C 7F0C58DC 000A4843 */  sra   $t1, $t2, 1
/* 0FA410 7F0C58E0 01C92023 */  subu  $a0, $t6, $t1
/* 0FA414 7F0C58E4 24840050 */  addiu $a0, $a0, 0x50
/* 0FA418 7F0C58E8 0C001149 */  jal   get_video2_settings_uly
/* 0FA41C 7F0C58EC AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FA420 7F0C58F0 3C0F8005 */  lui   $t7, %hi(j_text_trigger) 
/* 0FA424 7F0C58F4 8DEF84D0 */  lw    $t7, %lo(j_text_trigger)($t7)
/* 0FA428 7F0C58F8 00021C00 */  sll   $v1, $v0, 0x10
/* 0FA42C 7F0C58FC 00036403 */  sra   $t4, $v1, 0x10
/* 0FA430 7F0C5900 11E00003 */  beqz  $t7, .L7F0C5910
/* 0FA434 7F0C5904 01801825 */   move  $v1, $t4
/* 0FA438 7F0C5908 10000002 */  b     .L7F0C5914
/* 0FA43C 7F0C590C 24040004 */   li    $a0, 4
.L7F0C5910:
/* 0FA440 7F0C5910 00002025 */  move  $a0, $zero
.L7F0C5914:
/* 0FA444 7F0C5914 8FAD007C */  lw    $t5, 0x7c($sp)
/* 0FA448 7F0C5918 0083C821 */  addu  $t9, $a0, $v1
/* 0FA44C 7F0C591C 000DC043 */  sra   $t8, $t5, 1
/* 0FA450 7F0C5920 03385823 */  subu  $t3, $t9, $t8
/* 0FA454 7F0C5924 256A0035 */  addiu $t2, $t3, 0x35
/* 0FA458 7F0C5928 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FA45C 7F0C592C AFAA00C8 */   sw    $t2, 0xc8($sp)
/* 0FA460 7F0C5930 00028400 */  sll   $s0, $v0, 0x10
/* 0FA464 7F0C5934 00107403 */  sra   $t6, $s0, 0x10
/* 0FA468 7F0C5938 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FA46C 7F0C593C 01C08025 */   move  $s0, $t6
/* 0FA470 7F0C5940 3C098004 */  lui   $t1, %hi(ptrSecondFontTableSmall) 
/* 0FA474 7F0C5944 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) 
/* 0FA478 7F0C5948 8D8C0EAC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0FA47C 7F0C594C 8D290EB0 */  lw    $t1, %lo(ptrSecondFontTableSmall)($t1)
/* 0FA480 7F0C5950 3C0F00FF */  lui   $t7, (0x00FF00B0 >> 16) # lui $t7, 0xff
/* 0FA484 7F0C5954 35EF00B0 */  ori   $t7, (0x00FF00B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0FA488 7F0C5958 AFAF0018 */  sw    $t7, 0x18($sp)
/* 0FA48C 7F0C595C 02202025 */  move  $a0, $s1
/* 0FA490 7F0C5960 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FA494 7F0C5964 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FA498 7F0C5968 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FA49C 7F0C596C AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FA4A0 7F0C5970 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FA4A4 7F0C5974 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FA4A8 7F0C5978 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FA4AC 7F0C597C AFAC0014 */  sw    $t4, 0x14($sp)
/* 0FA4B0 7F0C5980 0FC2B6AF */  jal   en_text_write_stuff
/* 0FA4B4 7F0C5984 AFA90010 */   sw    $t1, 0x10($sp)
/* 0FA4B8 7F0C5988 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0FA4BC 7F0C598C 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0FA4C0 7F0C5990 00408825 */  move  $s1, $v0
/* 0FA4C4 7F0C5994 27A4007C */  addiu $a0, $sp, 0x7c
/* 0FA4C8 7F0C5998 8C682A10 */  lw    $t0, 0x2a10($v1)
/* 0FA4CC 7F0C599C 27A50078 */  addiu $a1, $sp, 0x78
/* 0FA4D0 7F0C59A0 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0FA4D4 7F0C59A4 11000031 */  beqz  $t0, .L7F0C5A6C
/* 0FA4D8 7F0C59A8 01003025 */   move  $a2, $t0
/* 0FA4DC 7F0C59AC 3C0D8004 */  lui   $t5, %hi(ptrFirstFontTableSmall) 
/* 0FA4E0 7F0C59B0 8DAD0EAC */  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
/* 0FA4E4 7F0C59B4 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FA4E8 7F0C59B8 AFA00014 */  sw    $zero, 0x14($sp)
/* 0FA4EC 7F0C59BC AFA800A4 */  sw    $t0, 0xa4($sp)
/* 0FA4F0 7F0C59C0 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0FA4F4 7F0C59C4 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0FA4F8 7F0C59C8 0C001145 */  jal   get_video2_settings_ulx
/* 0FA4FC 7F0C59CC 00000000 */   nop   
/* 0FA500 7F0C59D0 8FB90074 */  lw    $t9, 0x74($sp)
/* 0FA504 7F0C59D4 8FAB0078 */  lw    $t3, 0x78($sp)
/* 0FA508 7F0C59D8 0059C021 */  addu  $t8, $v0, $t9
/* 0FA50C 7F0C59DC 000B5043 */  sra   $t2, $t3, 1
/* 0FA510 7F0C59E0 030A2023 */  subu  $a0, $t8, $t2
/* 0FA514 7F0C59E4 24840050 */  addiu $a0, $a0, 0x50
/* 0FA518 7F0C59E8 0C001149 */  jal   get_video2_settings_uly
/* 0FA51C 7F0C59EC AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FA520 7F0C59F0 8FAE007C */  lw    $t6, 0x7c($sp)
/* 0FA524 7F0C59F4 000E4843 */  sra   $t1, $t6, 1
/* 0FA528 7F0C59F8 00496023 */  subu  $t4, $v0, $t1
/* 0FA52C 7F0C59FC 258F004B */  addiu $t7, $t4, 0x4b
/* 0FA530 7F0C5A00 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FA534 7F0C5A04 AFAF00C8 */   sw    $t7, 0xc8($sp)
/* 0FA538 7F0C5A08 00028400 */  sll   $s0, $v0, 0x10
/* 0FA53C 7F0C5A0C 00106C03 */  sra   $t5, $s0, 0x10
/* 0FA540 7F0C5A10 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FA544 7F0C5A14 01A08025 */   move  $s0, $t5
/* 0FA548 7F0C5A18 3C198004 */  lui   $t9, %hi(ptrSecondFontTableSmall) 
/* 0FA54C 7F0C5A1C 3C0B8004 */  lui   $t3, %hi(ptrFirstFontTableSmall) 
/* 0FA550 7F0C5A20 8D6B0EAC */  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
/* 0FA554 7F0C5A24 8F390EB0 */  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
/* 0FA558 7F0C5A28 3C1800FF */  lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
/* 0FA55C 7F0C5A2C 371800B0 */  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0FA560 7F0C5A30 AFB80018 */  sw    $t8, 0x18($sp)
/* 0FA564 7F0C5A34 02202025 */  move  $a0, $s1
/* 0FA568 7F0C5A38 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FA56C 7F0C5A3C 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FA570 7F0C5A40 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FA574 7F0C5A44 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FA578 7F0C5A48 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FA57C 7F0C5A4C AFA00024 */  sw    $zero, 0x24($sp)
/* 0FA580 7F0C5A50 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FA584 7F0C5A54 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0FA588 7F0C5A58 0FC2B6AF */  jal   en_text_write_stuff
/* 0FA58C 7F0C5A5C AFB90010 */   sw    $t9, 0x10($sp)
/* 0FA590 7F0C5A60 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0FA594 7F0C5A64 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0FA598 7F0C5A68 00408825 */  move  $s1, $v0
.L7F0C5A6C:
/* 0FA59C 7F0C5A6C 8C622A14 */  lw    $v0, 0x2a14($v1)
/* 0FA5A0 7F0C5A70 27A4007C */  addiu $a0, $sp, 0x7c
/* 0FA5A4 7F0C5A74 27A50078 */  addiu $a1, $sp, 0x78
/* 0FA5A8 7F0C5A78 10400032 */  beqz  $v0, .L7F0C5B44
/* 0FA5AC 7F0C5A7C 00403025 */   move  $a2, $v0
/* 0FA5B0 7F0C5A80 3C0A8004 */  lui   $t2, %hi(ptrFirstFontTableSmall) 
/* 0FA5B4 7F0C5A84 8D4A0EAC */  lw    $t2, %lo(ptrFirstFontTableSmall)($t2)
/* 0FA5B8 7F0C5A88 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0FA5BC 7F0C5A8C 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FA5C0 7F0C5A90 AFA00014 */  sw    $zero, 0x14($sp)
/* 0FA5C4 7F0C5A94 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0FA5C8 7F0C5A98 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0FA5CC 7F0C5A9C AFAA0010 */   sw    $t2, 0x10($sp)
/* 0FA5D0 7F0C5AA0 0C001145 */  jal   get_video2_settings_ulx
/* 0FA5D4 7F0C5AA4 00000000 */   nop   
/* 0FA5D8 7F0C5AA8 8FAE0074 */  lw    $t6, 0x74($sp)
/* 0FA5DC 7F0C5AAC 8FAC0078 */  lw    $t4, 0x78($sp)
/* 0FA5E0 7F0C5AB0 004E4821 */  addu  $t1, $v0, $t6
/* 0FA5E4 7F0C5AB4 000C7843 */  sra   $t7, $t4, 1
/* 0FA5E8 7F0C5AB8 012F2023 */  subu  $a0, $t1, $t7
/* 0FA5EC 7F0C5ABC 24840050 */  addiu $a0, $a0, 0x50
/* 0FA5F0 7F0C5AC0 0C001149 */  jal   get_video2_settings_uly
/* 0FA5F4 7F0C5AC4 AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FA5F8 7F0C5AC8 8FAD007C */  lw    $t5, 0x7c($sp)
/* 0FA5FC 7F0C5ACC 000DC843 */  sra   $t9, $t5, 1
/* 0FA600 7F0C5AD0 00595823 */  subu  $t3, $v0, $t9
/* 0FA604 7F0C5AD4 25780058 */  addiu $t8, $t3, 0x58
/* 0FA608 7F0C5AD8 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FA60C 7F0C5ADC AFB800C8 */   sw    $t8, 0xc8($sp)
/* 0FA610 7F0C5AE0 00028400 */  sll   $s0, $v0, 0x10
/* 0FA614 7F0C5AE4 00105403 */  sra   $t2, $s0, 0x10
/* 0FA618 7F0C5AE8 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FA61C 7F0C5AEC 01408025 */   move  $s0, $t2
/* 0FA620 7F0C5AF0 3C0E8004 */  lui   $t6, %hi(ptrSecondFontTableSmall) 
/* 0FA624 7F0C5AF4 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) 
/* 0FA628 7F0C5AF8 8D8C0EAC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0FA62C 7F0C5AFC 8DCE0EB0 */  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
/* 0FA630 7F0C5B00 3C0900FF */  lui   $t1, (0x00FF00B0 >> 16) # lui $t1, 0xff
/* 0FA634 7F0C5B04 352900B0 */  ori   $t1, (0x00FF00B0 & 0xFFFF) # ori $t1, $t1, 0xb0
/* 0FA638 7F0C5B08 AFA90018 */  sw    $t1, 0x18($sp)
/* 0FA63C 7F0C5B0C 02202025 */  move  $a0, $s1
/* 0FA640 7F0C5B10 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FA644 7F0C5B14 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FA648 7F0C5B18 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FA64C 7F0C5B1C AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FA650 7F0C5B20 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FA654 7F0C5B24 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FA658 7F0C5B28 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FA65C 7F0C5B2C AFAC0014 */  sw    $t4, 0x14($sp)
/* 0FA660 7F0C5B30 0FC2B6AF */  jal   en_text_write_stuff
/* 0FA664 7F0C5B34 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0FA668 7F0C5B38 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0FA66C 7F0C5B3C 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0FA670 7F0C5B40 00408825 */  move  $s1, $v0
.L7F0C5B44:
/* 0FA674 7F0C5B44 8C6F29C8 */  lw    $t7, 0x29c8($v1)
.L7F0C5B48:
/* 0FA678 7F0C5B48 24010006 */  li    $at, 6
/* 0FA67C 7F0C5B4C 15E100B0 */  bne   $t7, $at, .L7F0C5E10
/* 0FA680 7F0C5B50 00000000 */   nop   
/* 0FA684 7F0C5B54 0FC30776 */  jal   get_textptr_for_textID
/* 0FA688 7F0C5B58 3404A020 */   li    $a0, 40992
/* 0FA68C 7F0C5B5C 3C0D8004 */  lui   $t5, %hi(ptrFirstFontTableSmall) 
/* 0FA690 7F0C5B60 8DAD0EAC */  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
/* 0FA694 7F0C5B64 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0FA698 7F0C5B68 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0FA69C 7F0C5B6C 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FA6A0 7F0C5B70 27A400BC */  addiu $a0, $sp, 0xbc
/* 0FA6A4 7F0C5B74 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0FA6A8 7F0C5B78 00403025 */  move  $a2, $v0
/* 0FA6AC 7F0C5B7C AFA00014 */  sw    $zero, 0x14($sp)
/* 0FA6B0 7F0C5B80 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0FA6B4 7F0C5B84 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0FA6B8 7F0C5B88 0C001145 */  jal   get_video2_settings_ulx
/* 0FA6BC 7F0C5B8C 00000000 */   nop   
/* 0FA6C0 7F0C5B90 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0FA6C4 7F0C5B94 8FB800C0 */  lw    $t8, 0xc0($sp)
/* 0FA6C8 7F0C5B98 00595821 */  addu  $t3, $v0, $t9
/* 0FA6CC 7F0C5B9C 00185043 */  sra   $t2, $t8, 1
/* 0FA6D0 7F0C5BA0 016A2023 */  subu  $a0, $t3, $t2
/* 0FA6D4 7F0C5BA4 24840036 */  addiu $a0, $a0, 0x36
/* 0FA6D8 7F0C5BA8 0C001149 */  jal   get_video2_settings_uly
/* 0FA6DC 7F0C5BAC AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FA6E0 7F0C5BB0 8FAE00BC */  lw    $t6, 0xbc($sp)
/* 0FA6E4 7F0C5BB4 3C0D8008 */  lui   $t5, %hi(pPlayer) 
/* 0FA6E8 7F0C5BB8 8DADA0B0 */  lw    $t5, %lo(pPlayer)($t5)
/* 0FA6EC 7F0C5BBC 000E6043 */  sra   $t4, $t6, 1
/* 0FA6F0 7F0C5BC0 004C4823 */  subu  $t1, $v0, $t4
/* 0FA6F4 7F0C5BC4 252F0036 */  addiu $t7, $t1, 0x36
/* 0FA6F8 7F0C5BC8 AFAF00C8 */  sw    $t7, 0xc8($sp)
/* 0FA6FC 7F0C5BCC 8DB929CC */  lw    $t9, 0x29cc($t5)
/* 0FA700 7F0C5BD0 1720001E */  bnez  $t9, .L7F0C5C4C
/* 0FA704 7F0C5BD4 00000000 */   nop   
/* 0FA708 7F0C5BD8 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FA70C 7F0C5BDC 00000000 */   nop   
/* 0FA710 7F0C5BE0 00028400 */  sll   $s0, $v0, 0x10
/* 0FA714 7F0C5BE4 0010C403 */  sra   $t8, $s0, 0x10
/* 0FA718 7F0C5BE8 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FA71C 7F0C5BEC 03008025 */   move  $s0, $t8
/* 0FA720 7F0C5BF0 3C0B8004 */  lui   $t3, %hi(ptrSecondFontTableSmall) 
/* 0FA724 7F0C5BF4 3C0A8004 */  lui   $t2, %hi(ptrFirstFontTableSmall) 
/* 0FA728 7F0C5BF8 8D4A0EAC */  lw    $t2, %lo(ptrFirstFontTableSmall)($t2)
/* 0FA72C 7F0C5BFC 8D6B0EB0 */  lw    $t3, %lo(ptrSecondFontTableSmall)($t3)
/* 0FA730 7F0C5C00 3C0EA0FF */  lui   $t6, (0xA0FFA0F0 >> 16) # lui $t6, 0xa0ff
/* 0FA734 7F0C5C04 3C0C0070 */  lui   $t4, (0x007000A0 >> 16) # lui $t4, 0x70
/* 0FA738 7F0C5C08 358C00A0 */  ori   $t4, (0x007000A0 & 0xFFFF) # ori $t4, $t4, 0xa0
/* 0FA73C 7F0C5C0C 35CEA0F0 */  ori   $t6, (0xA0FFA0F0 & 0xFFFF) # ori $t6, $t6, 0xa0f0
/* 0FA740 7F0C5C10 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0FA744 7F0C5C14 AFAC001C */  sw    $t4, 0x1c($sp)
/* 0FA748 7F0C5C18 02202025 */  move  $a0, $s1
/* 0FA74C 7F0C5C1C 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FA750 7F0C5C20 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FA754 7F0C5C24 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FA758 7F0C5C28 AFB00020 */  sw    $s0, 0x20($sp)
/* 0FA75C 7F0C5C2C AFA20024 */  sw    $v0, 0x24($sp)
/* 0FA760 7F0C5C30 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FA764 7F0C5C34 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0FA768 7F0C5C38 AFAA0014 */  sw    $t2, 0x14($sp)
/* 0FA76C 7F0C5C3C 0FC2B9BB */  jal   jp_text_write_stuff
/* 0FA770 7F0C5C40 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0FA774 7F0C5C44 1000001A */  b     .L7F0C5CB0
/* 0FA778 7F0C5C48 00408825 */   move  $s1, $v0
.L7F0C5C4C:
/* 0FA77C 7F0C5C4C 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FA780 7F0C5C50 00000000 */   nop   
/* 0FA784 7F0C5C54 00028400 */  sll   $s0, $v0, 0x10
/* 0FA788 7F0C5C58 00104C03 */  sra   $t1, $s0, 0x10
/* 0FA78C 7F0C5C5C 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FA790 7F0C5C60 01208025 */   move  $s0, $t1
/* 0FA794 7F0C5C64 3C0F8004 */  lui   $t7, %hi(ptrSecondFontTableSmall) 
/* 0FA798 7F0C5C68 3C0D8004 */  lui   $t5, %hi(ptrFirstFontTableSmall) 
/* 0FA79C 7F0C5C6C 8DAD0EAC */  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
/* 0FA7A0 7F0C5C70 8DEF0EB0 */  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
/* 0FA7A4 7F0C5C74 3C1900FF */  lui   $t9, (0x00FF00B0 >> 16) # lui $t9, 0xff
/* 0FA7A8 7F0C5C78 373900B0 */  ori   $t9, (0x00FF00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0FA7AC 7F0C5C7C AFB90018 */  sw    $t9, 0x18($sp)
/* 0FA7B0 7F0C5C80 02202025 */  move  $a0, $s1
/* 0FA7B4 7F0C5C84 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FA7B8 7F0C5C88 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FA7BC 7F0C5C8C 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FA7C0 7F0C5C90 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FA7C4 7F0C5C94 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FA7C8 7F0C5C98 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FA7CC 7F0C5C9C AFA00028 */  sw    $zero, 0x28($sp)
/* 0FA7D0 7F0C5CA0 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0FA7D4 7F0C5CA4 0FC2B6AF */  jal   en_text_write_stuff
/* 0FA7D8 7F0C5CA8 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0FA7DC 7F0C5CAC 00408825 */  move  $s1, $v0
.L7F0C5CB0:
/* 0FA7E0 7F0C5CB0 0FC30776 */  jal   get_textptr_for_textID
/* 0FA7E4 7F0C5CB4 3404A021 */   li    $a0, 40993
/* 0FA7E8 7F0C5CB8 3C188004 */  lui   $t8, %hi(ptrFirstFontTableSmall) 
/* 0FA7EC 7F0C5CBC 8F180EAC */  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
/* 0FA7F0 7F0C5CC0 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0FA7F4 7F0C5CC4 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0FA7F8 7F0C5CC8 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FA7FC 7F0C5CCC 27A400BC */  addiu $a0, $sp, 0xbc
/* 0FA800 7F0C5CD0 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0FA804 7F0C5CD4 00403025 */  move  $a2, $v0
/* 0FA808 7F0C5CD8 AFA00014 */  sw    $zero, 0x14($sp)
/* 0FA80C 7F0C5CDC 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0FA810 7F0C5CE0 AFB80010 */   sw    $t8, 0x10($sp)
/* 0FA814 7F0C5CE4 0C001145 */  jal   get_video2_settings_ulx
/* 0FA818 7F0C5CE8 00000000 */   nop   
/* 0FA81C 7F0C5CEC 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0FA820 7F0C5CF0 8FAE00C0 */  lw    $t6, 0xc0($sp)
/* 0FA824 7F0C5CF4 004B5021 */  addu  $t2, $v0, $t3
/* 0FA828 7F0C5CF8 000E6043 */  sra   $t4, $t6, 1
/* 0FA82C 7F0C5CFC 014C2023 */  subu  $a0, $t2, $t4
/* 0FA830 7F0C5D00 24840068 */  addiu $a0, $a0, 0x68
/* 0FA834 7F0C5D04 0C001149 */  jal   get_video2_settings_uly
/* 0FA838 7F0C5D08 AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FA83C 7F0C5D0C 8FA900BC */  lw    $t1, 0xbc($sp)
/* 0FA840 7F0C5D10 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0FA844 7F0C5D14 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0FA848 7F0C5D18 00097843 */  sra   $t7, $t1, 1
/* 0FA84C 7F0C5D1C 004F6823 */  subu  $t5, $v0, $t7
/* 0FA850 7F0C5D20 25B90036 */  addiu $t9, $t5, 0x36
/* 0FA854 7F0C5D24 AFB900C8 */  sw    $t9, 0xc8($sp)
/* 0FA858 7F0C5D28 8F0B29CC */  lw    $t3, 0x29cc($t8)
/* 0FA85C 7F0C5D2C 24010001 */  li    $at, 1
/* 0FA860 7F0C5D30 1561001E */  bne   $t3, $at, .L7F0C5DAC
/* 0FA864 7F0C5D34 00000000 */   nop   
/* 0FA868 7F0C5D38 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FA86C 7F0C5D3C 00000000 */   nop   
/* 0FA870 7F0C5D40 00028400 */  sll   $s0, $v0, 0x10
/* 0FA874 7F0C5D44 00107403 */  sra   $t6, $s0, 0x10
/* 0FA878 7F0C5D48 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FA87C 7F0C5D4C 01C08025 */   move  $s0, $t6
/* 0FA880 7F0C5D50 3C0A8004 */  lui   $t2, %hi(ptrSecondFontTableSmall) 
/* 0FA884 7F0C5D54 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) 
/* 0FA888 7F0C5D58 8D8C0EAC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0FA88C 7F0C5D5C 8D4A0EB0 */  lw    $t2, %lo(ptrSecondFontTableSmall)($t2)
/* 0FA890 7F0C5D60 3C09A0FF */  lui   $t1, (0xA0FFA0F0 >> 16) # lui $t1, 0xa0ff
/* 0FA894 7F0C5D64 3C0F0070 */  lui   $t7, (0x007000A0 >> 16) # lui $t7, 0x70
/* 0FA898 7F0C5D68 35EF00A0 */  ori   $t7, (0x007000A0 & 0xFFFF) # ori $t7, $t7, 0xa0
/* 0FA89C 7F0C5D6C 3529A0F0 */  ori   $t1, (0xA0FFA0F0 & 0xFFFF) # ori $t1, $t1, 0xa0f0
/* 0FA8A0 7F0C5D70 AFA90018 */  sw    $t1, 0x18($sp)
/* 0FA8A4 7F0C5D74 AFAF001C */  sw    $t7, 0x1c($sp)
/* 0FA8A8 7F0C5D78 02202025 */  move  $a0, $s1
/* 0FA8AC 7F0C5D7C 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FA8B0 7F0C5D80 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FA8B4 7F0C5D84 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FA8B8 7F0C5D88 AFB00020 */  sw    $s0, 0x20($sp)
/* 0FA8BC 7F0C5D8C AFA20024 */  sw    $v0, 0x24($sp)
/* 0FA8C0 7F0C5D90 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FA8C4 7F0C5D94 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0FA8C8 7F0C5D98 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0FA8CC 7F0C5D9C 0FC2B9BB */  jal   jp_text_write_stuff
/* 0FA8D0 7F0C5DA0 AFAA0010 */   sw    $t2, 0x10($sp)
/* 0FA8D4 7F0C5DA4 1000001A */  b     .L7F0C5E10
/* 0FA8D8 7F0C5DA8 00408825 */   move  $s1, $v0
.L7F0C5DAC:
/* 0FA8DC 7F0C5DAC 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FA8E0 7F0C5DB0 00000000 */   nop   
/* 0FA8E4 7F0C5DB4 00028400 */  sll   $s0, $v0, 0x10
/* 0FA8E8 7F0C5DB8 00106C03 */  sra   $t5, $s0, 0x10
/* 0FA8EC 7F0C5DBC 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FA8F0 7F0C5DC0 01A08025 */   move  $s0, $t5
/* 0FA8F4 7F0C5DC4 3C198004 */  lui   $t9, %hi(ptrSecondFontTableSmall) 
/* 0FA8F8 7F0C5DC8 3C188004 */  lui   $t8, %hi(ptrFirstFontTableSmall) 
/* 0FA8FC 7F0C5DCC 8F180EAC */  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
/* 0FA900 7F0C5DD0 8F390EB0 */  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
/* 0FA904 7F0C5DD4 3C0B00FF */  lui   $t3, (0x00FF00B0 >> 16) # lui $t3, 0xff
/* 0FA908 7F0C5DD8 356B00B0 */  ori   $t3, (0x00FF00B0 & 0xFFFF) # ori $t3, $t3, 0xb0
/* 0FA90C 7F0C5DDC AFAB0018 */  sw    $t3, 0x18($sp)
/* 0FA910 7F0C5DE0 02202025 */  move  $a0, $s1
/* 0FA914 7F0C5DE4 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FA918 7F0C5DE8 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FA91C 7F0C5DEC 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FA920 7F0C5DF0 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FA924 7F0C5DF4 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FA928 7F0C5DF8 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FA92C 7F0C5DFC AFA00028 */  sw    $zero, 0x28($sp)
/* 0FA930 7F0C5E00 AFB80014 */  sw    $t8, 0x14($sp)
/* 0FA934 7F0C5E04 0FC2B6AF */  jal   en_text_write_stuff
/* 0FA938 7F0C5E08 AFB90010 */   sw    $t9, 0x10($sp)
/* 0FA93C 7F0C5E0C 00408825 */  move  $s1, $v0
.L7F0C5E10:
/* 0FA940 7F0C5E10 0FC2B3BC */  jal   combiner_bayer_lod_perspective
/* 0FA944 7F0C5E14 02202025 */   move  $a0, $s1
/* 0FA948 7F0C5E18 10000085 */  b     .L7F0C6030
/* 0FA94C 7F0C5E1C 00408825 */   move  $s1, $v0
/* 0FA950 7F0C5E20 8C6E00D8 */  lw    $t6, 0xd8($v1)
.L7F0C5E24:
/* 0FA954 7F0C5E24 51C00083 */  beql  $t6, $zero, .L7F0C6034
/* 0FA958 7F0C5E28 02201025 */   move  $v0, $s1
/* 0FA95C 7F0C5E2C 8C6A0428 */  lw    $t2, 0x428($v1)
/* 0FA960 7F0C5E30 51400080 */  beql  $t2, $zero, .L7F0C6034
/* 0FA964 7F0C5E34 02201025 */   move  $v0, $s1
/* 0FA968 7F0C5E38 8C6C0424 */  lw    $t4, 0x424($v1)
/* 0FA96C 7F0C5E3C 3C098009 */  lui   $t1, %hi(stop_play_flag) 
/* 0FA970 7F0C5E40 5180007C */  beql  $t4, $zero, .L7F0C6034
/* 0FA974 7F0C5E44 02201025 */   move  $v0, $s1
/* 0FA978 7F0C5E48 8D29C700 */  lw    $t1, %lo(stop_play_flag)($t1)
/* 0FA97C 7F0C5E4C 3C0F8009 */  lui   $t7, %hi(is_gameover_flag) 
/* 0FA980 7F0C5E50 55200078 */  bnezl $t1, .L7F0C6034
/* 0FA984 7F0C5E54 02201025 */   move  $v0, $s1
/* 0FA988 7F0C5E58 8DEFC704 */  lw    $t7, %lo(is_gameover_flag)($t7)
/* 0FA98C 7F0C5E5C 00002025 */  move  $a0, $zero
/* 0FA990 7F0C5E60 55E00074 */  bnezl $t7, .L7F0C6034
/* 0FA994 7F0C5E64 02201025 */   move  $v0, $s1
/* 0FA998 7F0C5E68 18400028 */  blez  $v0, .L7F0C5F0C
/* 0FA99C 7F0C5E6C 00002825 */   move  $a1, $zero
/* 0FA9A0 7F0C5E70 30470003 */  andi  $a3, $v0, 3
/* 0FA9A4 7F0C5E74 10E00011 */  beqz  $a3, .L7F0C5EBC
/* 0FA9A8 7F0C5E78 00E03025 */   move  $a2, $a3
/* 0FA9AC 7F0C5E7C 8FB900D4 */  lw    $t9, 0xd4($sp)
/* 0FA9B0 7F0C5E80 000068C0 */  sll   $t5, $zero, 3
/* 0FA9B4 7F0C5E84 01A06823 */  subu  $t5, $t5, $zero
/* 0FA9B8 7F0C5E88 000D6900 */  sll   $t5, $t5, 4
/* 0FA9BC 7F0C5E8C 3C0E8008 */  lui   $t6, %hi(player1_player_data) 
/* 0FA9C0 7F0C5E90 0019C080 */  sll   $t8, $t9, 2
/* 0FA9C4 7F0C5E94 01B85821 */  addu  $t3, $t5, $t8
/* 0FA9C8 7F0C5E98 25CE9EF0 */  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x6110
/* 0FA9CC 7F0C5E9C 016E1821 */  addu  $v1, $t3, $t6
.L7F0C5EA0:
/* 0FA9D0 7F0C5EA0 8C6A0024 */  lw    $t2, 0x24($v1)
/* 0FA9D4 7F0C5EA4 24A50001 */  addiu $a1, $a1, 1
/* 0FA9D8 7F0C5EA8 24630070 */  addiu $v1, $v1, 0x70
/* 0FA9DC 7F0C5EAC 14C5FFFC */  bne   $a2, $a1, .L7F0C5EA0
/* 0FA9E0 7F0C5EB0 008A2021 */   addu  $a0, $a0, $t2
/* 0FA9E4 7F0C5EB4 10A20015 */  beq   $a1, $v0, .L7F0C5F0C
/* 0FA9E8 7F0C5EB8 00000000 */   nop   
.L7F0C5EBC:
/* 0FA9EC 7F0C5EBC 8FA900D4 */  lw    $t1, 0xd4($sp)
/* 0FA9F0 7F0C5EC0 000560C0 */  sll   $t4, $a1, 3
/* 0FA9F4 7F0C5EC4 01856023 */  subu  $t4, $t4, $a1
/* 0FA9F8 7F0C5EC8 000C6100 */  sll   $t4, $t4, 4
/* 0FA9FC 7F0C5ECC 3C0D8008 */  lui   $t5, %hi(player1_player_data) 
/* 0FAA00 7F0C5ED0 00097880 */  sll   $t7, $t1, 2
/* 0FAA04 7F0C5ED4 018FC821 */  addu  $t9, $t4, $t7
/* 0FAA08 7F0C5ED8 25AD9EF0 */  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x6110
/* 0FAA0C 7F0C5EDC 032D1821 */  addu  $v1, $t9, $t5
.L7F0C5EE0:
/* 0FAA10 7F0C5EE0 8C780024 */  lw    $t8, 0x24($v1)
/* 0FAA14 7F0C5EE4 8C6B0094 */  lw    $t3, 0x94($v1)
/* 0FAA18 7F0C5EE8 8C6E0104 */  lw    $t6, 0x104($v1)
/* 0FAA1C 7F0C5EEC 00982021 */  addu  $a0, $a0, $t8
/* 0FAA20 7F0C5EF0 8C6A0174 */  lw    $t2, 0x174($v1)
/* 0FAA24 7F0C5EF4 008B2021 */  addu  $a0, $a0, $t3
/* 0FAA28 7F0C5EF8 24A50004 */  addiu $a1, $a1, 4
/* 0FAA2C 7F0C5EFC 008E2021 */  addu  $a0, $a0, $t6
/* 0FAA30 7F0C5F00 246301C0 */  addiu $v1, $v1, 0x1c0
/* 0FAA34 7F0C5F04 14A8FFF6 */  bne   $a1, $t0, .L7F0C5EE0
/* 0FAA38 7F0C5F08 008A2021 */   addu  $a0, $a0, $t2
.L7F0C5F0C:
/* 0FAA3C 7F0C5F0C 0FC051D6 */  jal   get_scenario
/* 0FAA40 7F0C5F10 AFA40058 */   sw    $a0, 0x58($sp)
/* 0FAA44 7F0C5F14 24010001 */  li    $at, 1
/* 0FAA48 7F0C5F18 14410004 */  bne   $v0, $at, .L7F0C5F2C
/* 0FAA4C 7F0C5F1C 8FA40058 */   lw    $a0, 0x58($sp)
/* 0FAA50 7F0C5F20 28810002 */  slti  $at, $a0, 2
/* 0FAA54 7F0C5F24 50200043 */  beql  $at, $zero, .L7F0C6034
/* 0FAA58 7F0C5F28 02201025 */   move  $v0, $s1
.L7F0C5F2C:
/* 0FAA5C 7F0C5F2C 0FC2D3ED */  jal   sub_GAME_7F0B4FB4
/* 0FAA60 7F0C5F30 02202025 */   move  $a0, $s1
/* 0FAA64 7F0C5F34 0FC2B366 */  jal   microcode_constructor
/* 0FAA68 7F0C5F38 00402025 */   move  $a0, $v0
/* 0FAA6C 7F0C5F3C 00408825 */  move  $s1, $v0
/* 0FAA70 7F0C5F40 0FC30776 */  jal   get_textptr_for_textID
/* 0FAA74 7F0C5F44 3404A022 */   li    $a0, 40994
/* 0FAA78 7F0C5F48 3C098004 */  lui   $t1, %hi(ptrFirstFontTableSmall) 
/* 0FAA7C 7F0C5F4C 8D290EAC */  lw    $t1, %lo(ptrFirstFontTableSmall)($t1)
/* 0FAA80 7F0C5F50 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall)
/* 0FAA84 7F0C5F54 AFA20060 */  sw    $v0, 0x60($sp)
/* 0FAA88 7F0C5F58 8CE70EB0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FAA8C 7F0C5F5C 27A40064 */  addiu $a0, $sp, 0x64
/* 0FAA90 7F0C5F60 27A50068 */  addiu $a1, $sp, 0x68
/* 0FAA94 7F0C5F64 00403025 */  move  $a2, $v0
/* 0FAA98 7F0C5F68 AFA00014 */  sw    $zero, 0x14($sp)
/* 0FAA9C 7F0C5F6C 0FC2BA63 */  jal   sub_GAME_7F0AE98C
/* 0FAAA0 7F0C5F70 AFA90010 */   sw    $t1, 0x10($sp)
/* 0FAAA4 7F0C5F74 0C001145 */  jal   get_video2_settings_ulx
/* 0FAAA8 7F0C5F78 00000000 */   nop   
/* 0FAAAC 7F0C5F7C 0C001127 */  jal   get_video2_settings_width
/* 0FAAB0 7F0C5F80 A7A20056 */   sh    $v0, 0x56($sp)
/* 0FAAB4 7F0C5F84 87A30056 */  lh    $v1, 0x56($sp)
/* 0FAAB8 7F0C5F88 8FAD0068 */  lw    $t5, 0x68($sp)
/* 0FAABC 7F0C5F8C 00027843 */  sra   $t7, $v0, 1
/* 0FAAC0 7F0C5F90 01E3C821 */  addu  $t9, $t7, $v1
/* 0FAAC4 7F0C5F94 000DC043 */  sra   $t8, $t5, 1
/* 0FAAC8 7F0C5F98 03385823 */  subu  $t3, $t9, $t8
/* 0FAACC 7F0C5F9C 0C001149 */  jal   get_video2_settings_uly
/* 0FAAD0 7F0C5FA0 AFAB0070 */   sw    $t3, 0x70($sp)
/* 0FAAD4 7F0C5FA4 0C00112B */  jal   get_video2_settings_height
/* 0FAAD8 7F0C5FA8 A7A20056 */   sh    $v0, 0x56($sp)
/* 0FAADC 7F0C5FAC 87A30056 */  lh    $v1, 0x56($sp)
/* 0FAAE0 7F0C5FB0 8FAC0064 */  lw    $t4, 0x64($sp)
/* 0FAAE4 7F0C5FB4 00025043 */  sra   $t2, $v0, 1
/* 0FAAE8 7F0C5FB8 01434821 */  addu  $t1, $t2, $v1
/* 0FAAEC 7F0C5FBC 000C7843 */  sra   $t7, $t4, 1
/* 0FAAF0 7F0C5FC0 012F6823 */  subu  $t5, $t1, $t7
/* 0FAAF4 7F0C5FC4 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FAAF8 7F0C5FC8 AFAD006C */   sw    $t5, 0x6c($sp)
/* 0FAAFC 7F0C5FCC 00028400 */  sll   $s0, $v0, 0x10
/* 0FAB00 7F0C5FD0 0010CC03 */  sra   $t9, $s0, 0x10
/* 0FAB04 7F0C5FD4 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FAB08 7F0C5FD8 03208025 */   move  $s0, $t9
/* 0FAB0C 7F0C5FDC 3C188004 */  lui   $t8, %hi(ptrSecondFontTableSmall) 
/* 0FAB10 7F0C5FE0 3C0B8004 */  lui   $t3, %hi(ptrFirstFontTableSmall) 
/* 0FAB14 7F0C5FE4 8D6B0EAC */  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
/* 0FAB18 7F0C5FE8 8F180EB0 */  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
/* 0FAB1C 7F0C5FEC 3C0E00FF */  lui   $t6, (0x00FF00B0 >> 16) # lui $t6, 0xff
/* 0FAB20 7F0C5FF0 35CE00B0 */  ori   $t6, (0x00FF00B0 & 0xFFFF) # ori $t6, $t6, 0xb0
/* 0FAB24 7F0C5FF4 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0FAB28 7F0C5FF8 02202025 */  move  $a0, $s1
/* 0FAB2C 7F0C5FFC 27A50070 */  addiu $a1, $sp, 0x70
/* 0FAB30 7F0C6000 27A6006C */  addiu $a2, $sp, 0x6c
/* 0FAB34 7F0C6004 8FA70060 */  lw    $a3, 0x60($sp)
/* 0FAB38 7F0C6008 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FAB3C 7F0C600C AFA20020 */  sw    $v0, 0x20($sp)
/* 0FAB40 7F0C6010 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FAB44 7F0C6014 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FAB48 7F0C6018 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0FAB4C 7F0C601C 0FC2B6AF */  jal   en_text_write_stuff
/* 0FAB50 7F0C6020 AFB80010 */   sw    $t8, 0x10($sp)
/* 0FAB54 7F0C6024 0FC2B3BC */  jal   combiner_bayer_lod_perspective
/* 0FAB58 7F0C6028 00402025 */   move  $a0, $v0
/* 0FAB5C 7F0C602C 00408825 */  move  $s1, $v0
.L7F0C6030:
/* 0FAB60 7F0C6030 02201025 */  move  $v0, $s1
.L7F0C6034:
/* 0FAB64 7F0C6034 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0FAB68 7F0C6038 8FB00034 */  lw    $s0, 0x34($sp)
/* 0FAB6C 7F0C603C 8FB10038 */  lw    $s1, 0x38($sp)
/* 0FAB70 7F0C6040 03E00008 */  jr    $ra
/* 0FAB74 7F0C6044 27BD00D8 */   addiu $sp, $sp, 0xd8
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
/*jtbl hacks*/
.word not_yolt_tld

/*D:8005BD00*/
glabel jpt_MP_menu_window_text
.word text_play
.word text_play
.word text_play
.word text_play
.word text_pause_unpause
.word text_exit
.word text_exit
.word text_blank

.text
glabel mp_watch_menu_display
/* 0F9844 7F0C4CD4 27BDFF28 */  addiu $sp, $sp, -0xd8
/* 0F9848 7F0C4CD8 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0F984C 7F0C4CDC AFB10038 */  sw    $s1, 0x38($sp)
/* 0F9850 7F0C4CE0 00808825 */  move  $s1, $a0
/* 0F9854 7F0C4CE4 0FC26F3C */  jal   get_cur_playernum
/* 0F9858 7F0C4CE8 AFB00034 */   sw    $s0, 0x34($sp)
/* 0F985C 7F0C4CEC 0FC26C01 */  jal   get_num_players
/* 0F9860 7F0C4CF0 AFA200D4 */   sw    $v0, 0xd4($sp)
/* 0F9864 7F0C4CF4 24010001 */  li    $at, 1
/* 0F9868 7F0C4CF8 00404025 */  move  $t0, $v0
/* 0F986C 7F0C4CFC 14410003 */  bne   $v0, $at, .Ljp7F0C4D0C
/* 0F9870 7F0C4D00 00008025 */   move  $s0, $zero
/* 0F9874 7F0C4D04 10000804 */  b     .Ljp7F0C6D18
/* 0F9878 7F0C4D08 02201025 */   move  $v0, $s1
.Ljp7F0C4D0C:
/* 0F987C 7F0C4D0C 3C038008 */  lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0F9880 7F0C4D10 8C63A120 */  lw    $v1, %lo(pPlayer)($v1)
/* 0F9884 7F0C4D14 02202025 */  move  $a0, $s1
/* 0F9888 7F0C4D18 8C6E29C4 */  lw    $t6, 0x29c4($v1)
/* 0F988C 7F0C4D1C 51C0076D */  beql  $t6, $zero, .Ljp7F0C6AD4
/* 0F9890 7F0C4D20 8C6C00D8 */   lw    $t4, 0xd8($v1)
/* 0F9894 7F0C4D24 0FC2B652 */  jal   microcode_constructor
/* 0F9898 7F0C4D28 AFA800D0 */   sw    $t0, 0xd0($sp)
/* 0F989C 7F0C4D2C 8FAF00D0 */  lw    $t7, 0xd0($sp)
/* 0F98A0 7F0C4D30 24010002 */  li    $at, 2
/* 0F98A4 7F0C4D34 00408825 */  move  $s1, $v0
/* 0F98A8 7F0C4D38 15E10004 */  bne   $t7, $at, .Ljp7F0C4D4C
/* 0F98AC 7F0C4D3C 3C198008 */   lui   $t9, %hi(pPlayer) # $t9, 0x8008
/* 0F98B0 7F0C4D40 24180050 */  li    $t8, 80
/* 0F98B4 7F0C4D44 10000002 */  b     .Ljp7F0C4D50
/* 0F98B8 7F0C4D48 AFB800A8 */   sw    $t8, 0xa8($sp)
.Ljp7F0C4D4C:
/* 0F98BC 7F0C4D4C AFA000A8 */  sw    $zero, 0xa8($sp)
.Ljp7F0C4D50:
/* 0F98C0 7F0C4D50 8F39A120 */  lw    $t9, %lo(pPlayer)($t9)
/* 0F98C4 7F0C4D54 8F2B29C8 */  lw    $t3, 0x29c8($t9)
/* 0F98C8 7F0C4D58 2D610008 */  sltiu $at, $t3, 8
/* 0F98CC 7F0C4D5C 10200038 */  beqz  $at, .Ljp7F0C4E40
/* 0F98D0 7F0C4D60 000B5880 */   sll   $t3, $t3, 2
/* 0F98D4 7F0C4D64 3C018006 */  lui   $at, %hi(jpt_MP_menu_window_text)
/* 0F98D8 7F0C4D68 002B0821 */  addu  $at, $at, $t3
/* 0F98DC 7F0C4D6C 8C2BBD40 */  lw    $t3, %lo(jpt_MP_menu_window_text)($at)
/* 0F98E0 7F0C4D70 01600008 */  jr    $t3
/* 0F98E4 7F0C4D74 00000000 */   nop   
text_play:
/* 0F98E8 7F0C4D78 3C0C8009 */  lui   $t4, %hi(is_gameover_flag) # $t4, 0x8009
/* 0F98EC 7F0C4D7C 8D8CC774 */  lw    $t4, %lo(is_gameover_flag)($t4)
/* 0F98F0 7F0C4D80 3C0D8009 */  lui   $t5, %hi(time_trigger_alt_gameover_msg) # $t5, 0x8009
/* 0F98F4 7F0C4D84 15800005 */  bnez  $t4, .Ljp7F0C4D9C
/* 0F98F8 7F0C4D88 00000000 */   nop   
/* 0F98FC 7F0C4D8C 0FC30AA2 */  jal   get_textptr_for_textID
/* 0F9900 7F0C4D90 3404A015 */   li    $a0, 40981
/* 0F9904 7F0C4D94 1000002A */  b     .Ljp7F0C4E40
/* 0F9908 7F0C4D98 AFA200A4 */   sw    $v0, 0xa4($sp)
.Ljp7F0C4D9C:
/* 0F990C 7F0C4D9C 8DADC780 */  lw    $t5, %lo(time_trigger_alt_gameover_msg)($t5)
/* 0F9910 7F0C4DA0 11A00005 */  beqz  $t5, .Ljp7F0C4DB8
/* 0F9914 7F0C4DA4 00000000 */   nop   
/* 0F9918 7F0C4DA8 0FC30AA2 */  jal   get_textptr_for_textID
/* 0F991C 7F0C4DAC 3404A016 */   li    $a0, 40982
/* 0F9920 7F0C4DB0 10000023 */  b     .Ljp7F0C4E40
/* 0F9924 7F0C4DB4 AFA200A4 */   sw    $v0, 0xa4($sp)
.Ljp7F0C4DB8:
/* 0F9928 7F0C4DB8 0FC30AA2 */  jal   get_textptr_for_textID
/* 0F992C 7F0C4DBC 3404A017 */   li    $a0, 40983
/* 0F9930 7F0C4DC0 1000001F */  b     .Ljp7F0C4E40
/* 0F9934 7F0C4DC4 AFA200A4 */   sw    $v0, 0xa4($sp)
text_blank:
/* 0F9938 7F0C4DC8 3C0E8006 */  lui   $t6, %hi(ascii_MP_watch_menu_BLANK) # $t6, 0x8006
/* 0F993C 7F0C4DCC 25CEBC64 */  addiu $t6, %lo(ascii_MP_watch_menu_BLANK) # addiu $t6, $t6, -0x439c
/* 0F9940 7F0C4DD0 1000001B */  b     .Ljp7F0C4E40
/* 0F9944 7F0C4DD4 AFAE00A4 */   sw    $t6, 0xa4($sp)
text_pause_unpause:
/* 0F9948 7F0C4DD8 3C0F8009 */  lui   $t7, %hi(is_paused) # $t7, 0x8009
/* 0F994C 7F0C4DDC 8DEFC788 */  lw    $t7, %lo(is_paused)($t7)
/* 0F9950 7F0C4DE0 11E0000B */  beqz  $t7, .Ljp7F0C4E10
/* 0F9954 7F0C4DE4 00000000 */   nop   
/* 0F9958 7F0C4DE8 0FC30AA2 */  jal   get_textptr_for_textID
/* 0F995C 7F0C4DEC 3404A018 */   li    $a0, 40984
/* 0F9960 7F0C4DF0 0FC26F3C */  jal   get_cur_playernum
/* 0F9964 7F0C4DF4 AFA200A4 */   sw    $v0, 0xa4($sp)
/* 0F9968 7F0C4DF8 3C188009 */  lui   $t8, %hi(who_paused) # $t8, 0x8009
/* 0F996C 7F0C4DFC 8F18C78C */  lw    $t8, %lo(who_paused)($t8)
/* 0F9970 7F0C4E00 1458000F */  bne   $v0, $t8, .Ljp7F0C4E40
/* 0F9974 7F0C4E04 00000000 */   nop   
/* 0F9978 7F0C4E08 1000000D */  b     .Ljp7F0C4E40
/* 0F997C 7F0C4E0C 24100001 */   li    $s0, 1
.Ljp7F0C4E10:
/* 0F9980 7F0C4E10 0FC30AA2 */  jal   get_textptr_for_textID
/* 0F9984 7F0C4E14 3404A019 */   li    $a0, 40985
/* 0F9988 7F0C4E18 10000009 */  b     .Ljp7F0C4E40
/* 0F998C 7F0C4E1C AFA200A4 */   sw    $v0, 0xa4($sp)
text_exit:
/* 0F9990 7F0C4E20 0FC30AA2 */  jal   get_textptr_for_textID
/* 0F9994 7F0C4E24 3404A01A */   li    $a0, 40986
/* 0F9998 7F0C4E28 0C001145 */  jal   get_video2_settings_ulx
/* 0F999C 7F0C4E2C AFA200A4 */   sw    $v0, 0xa4($sp)
/* 0F99A0 7F0C4E30 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0F99A4 7F0C4E34 00592021 */  addu  $a0, $v0, $t9
/* 0F99A8 7F0C4E38 24840041 */  addiu $a0, $a0, 0x41
/* 0F99AC 7F0C4E3C AFA400CC */  sw    $a0, 0xcc($sp)
def_7F0C40C0:
.Ljp7F0C4E40:
/* 0F99B0 7F0C4E40 3C0B8004 */  lui   $t3, %hi(ptrFirstFontTableSmall) # $t3, 0x8004
/* 0F99B4 7F0C4E44 8D6B0EDC */  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
/* 0F99B8 7F0C4E48 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0F99BC 7F0C4E4C 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0F99C0 7F0C4E50 27A400BC */  addiu $a0, $sp, 0xbc
/* 0F99C4 7F0C4E54 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0F99C8 7F0C4E58 8FA600A4 */  lw    $a2, 0xa4($sp)
/* 0F99CC 7F0C4E5C AFA00014 */  sw    $zero, 0x14($sp)
/* 0F99D0 7F0C4E60 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0F99D4 7F0C4E64 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0F99D8 7F0C4E68 0C001145 */  jal   get_video2_settings_ulx
/* 0F99DC 7F0C4E6C 00000000 */   nop   
/* 0F99E0 7F0C4E70 8FAC00A8 */  lw    $t4, 0xa8($sp)
/* 0F99E4 7F0C4E74 8FAE00C0 */  lw    $t6, 0xc0($sp)
/* 0F99E8 7F0C4E78 004C6821 */  addu  $t5, $v0, $t4
/* 0F99EC 7F0C4E7C 000E7843 */  sra   $t7, $t6, 1
/* 0F99F0 7F0C4E80 01AF2023 */  subu  $a0, $t5, $t7
/* 0F99F4 7F0C4E84 24840050 */  addiu $a0, $a0, 0x50
/* 0F99F8 7F0C4E88 0C001149 */  jal   get_video2_settings_uly
/* 0F99FC 7F0C4E8C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F9A00 7F0C4E90 8FB800BC */  lw    $t8, 0xbc($sp)
/* 0F9A04 7F0C4E94 0018C843 */  sra   $t9, $t8, 1
/* 0F9A08 7F0C4E98 00595823 */  subu  $t3, $v0, $t9
/* 0F9A0C 7F0C4E9C 256C0016 */  addiu $t4, $t3, 0x16
/* 0F9A10 7F0C4EA0 1200001E */  beqz  $s0, .Ljp7F0C4F1C
/* 0F9A14 7F0C4EA4 AFAC00C8 */   sw    $t4, 0xc8($sp)
/* 0F9A18 7F0C4EA8 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F9A1C 7F0C4EAC 00000000 */   nop   
/* 0F9A20 7F0C4EB0 00028400 */  sll   $s0, $v0, 0x10
/* 0F9A24 7F0C4EB4 00107403 */  sra   $t6, $s0, 0x10
/* 0F9A28 7F0C4EB8 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F9A2C 7F0C4EBC 01C08025 */   move  $s0, $t6
/* 0F9A30 7F0C4EC0 3C0D8004 */  lui   $t5, %hi(ptrSecondFontTableSmall) # $t5, 0x8004
/* 0F9A34 7F0C4EC4 3C0F8004 */  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
/* 0F9A38 7F0C4EC8 8DEF0EDC */  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
/* 0F9A3C 7F0C4ECC 8DAD0EE0 */  lw    $t5, %lo(ptrSecondFontTableSmall)($t5)
/* 0F9A40 7F0C4ED0 3C18A0FF */  lui   $t8, (0xA0FFA0F0 >> 16) # lui $t8, 0xa0ff
/* 0F9A44 7F0C4ED4 3C190070 */  lui   $t9, (0x007000A0 >> 16) # lui $t9, 0x70
/* 0F9A48 7F0C4ED8 373900A0 */  ori   $t9, (0x007000A0 & 0xFFFF) # ori $t9, $t9, 0xa0
/* 0F9A4C 7F0C4EDC 3718A0F0 */  ori   $t8, (0xA0FFA0F0 & 0xFFFF) # ori $t8, $t8, 0xa0f0
/* 0F9A50 7F0C4EE0 AFB80018 */  sw    $t8, 0x18($sp)
/* 0F9A54 7F0C4EE4 AFB9001C */  sw    $t9, 0x1c($sp)
/* 0F9A58 7F0C4EE8 02202025 */  move  $a0, $s1
/* 0F9A5C 7F0C4EEC 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F9A60 7F0C4EF0 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9A64 7F0C4EF4 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0F9A68 7F0C4EF8 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F9A6C 7F0C4EFC AFA20024 */  sw    $v0, 0x24($sp)
/* 0F9A70 7F0C4F00 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9A74 7F0C4F04 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0F9A78 7F0C4F08 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0F9A7C 7F0C4F0C 0FC2BCA7 */  jal   jp_text_write_stuff
/* 0F9A80 7F0C4F10 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0F9A84 7F0C4F14 1000001A */  b     .Ljp7F0C4F80
/* 0F9A88 7F0C4F18 00408825 */   move  $s1, $v0
.Ljp7F0C4F1C:
/* 0F9A8C 7F0C4F1C 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F9A90 7F0C4F20 00000000 */   nop   
/* 0F9A94 7F0C4F24 00028400 */  sll   $s0, $v0, 0x10
/* 0F9A98 7F0C4F28 00105C03 */  sra   $t3, $s0, 0x10
/* 0F9A9C 7F0C4F2C 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F9AA0 7F0C4F30 01608025 */   move  $s0, $t3
/* 0F9AA4 7F0C4F34 3C0C8004 */  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
/* 0F9AA8 7F0C4F38 3C0E8004 */  lui   $t6, %hi(ptrFirstFontTableSmall) # $t6, 0x8004
/* 0F9AAC 7F0C4F3C 8DCE0EDC */  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
/* 0F9AB0 7F0C4F40 8D8C0EE0 */  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
/* 0F9AB4 7F0C4F44 3C0D00FF */  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
/* 0F9AB8 7F0C4F48 35AD00B0 */  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0F9ABC 7F0C4F4C AFAD0018 */  sw    $t5, 0x18($sp)
/* 0F9AC0 7F0C4F50 02202025 */  move  $a0, $s1
/* 0F9AC4 7F0C4F54 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F9AC8 7F0C4F58 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9ACC 7F0C4F5C 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0F9AD0 7F0C4F60 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F9AD4 7F0C4F64 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F9AD8 7F0C4F68 AFA00024 */  sw    $zero, 0x24($sp)
/* 0F9ADC 7F0C4F6C AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9AE0 7F0C4F70 AFAE0014 */  sw    $t6, 0x14($sp)
/* 0F9AE4 7F0C4F74 0FC2B99B */  jal   en_text_write_stuff
/* 0F9AE8 7F0C4F78 AFAC0010 */   sw    $t4, 0x10($sp)
/* 0F9AEC 7F0C4F7C 00408825 */  move  $s1, $v0
.Ljp7F0C4F80:
/* 0F9AF0 7F0C4F80 0FC30ACF */  jal   check_can_advance_left_on_mpmenu
/* 0F9AF4 7F0C4F84 00000000 */   nop   
/* 0F9AF8 7F0C4F88 10400056 */  beqz  $v0, .Ljp7F0C50E4
/* 0F9AFC 7F0C4F8C 00000000 */   nop   
/* 0F9B00 7F0C4F90 0C001145 */  jal   get_video2_settings_ulx
/* 0F9B04 7F0C4F94 00000000 */   nop   
/* 0F9B08 7F0C4F98 3C038009 */  lui   $v1, %hi(is_gameover_flag) # $v1, 0x8009
/* 0F9B0C 7F0C4F9C 8C63C774 */  lw    $v1, %lo(is_gameover_flag)($v1)
/* 0F9B10 7F0C4FA0 0002C400 */  sll   $t8, $v0, 0x10
/* 0F9B14 7F0C4FA4 240F000A */  li    $t7, 10
/* 0F9B18 7F0C4FA8 50600004 */  beql  $v1, $zero, .Ljp7F0C4FBC
/* 0F9B1C 7F0C4FAC AFA00050 */   sw    $zero, 0x50($sp)
/* 0F9B20 7F0C4FB0 10000002 */  b     .Ljp7F0C4FBC
/* 0F9B24 7F0C4FB4 AFAF0050 */   sw    $t7, 0x50($sp)
/* 0F9B28 7F0C4FB8 AFA00050 */  sw    $zero, 0x50($sp)
.Ljp7F0C4FBC:
/* 0F9B2C 7F0C4FBC 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0F9B30 7F0C4FC0 8FAE0050 */  lw    $t6, 0x50($sp)
/* 0F9B34 7F0C4FC4 0018CC03 */  sra   $t9, $t8, 0x10
/* 0F9B38 7F0C4FC8 032B6021 */  addu  $t4, $t9, $t3
/* 0F9B3C 7F0C4FCC 018E2023 */  subu  $a0, $t4, $t6
/* 0F9B40 7F0C4FD0 24840028 */  addiu $a0, $a0, 0x28
/* 0F9B44 7F0C4FD4 10600003 */  beqz  $v1, .Ljp7F0C4FE4
/* 0F9B48 7F0C4FD8 AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F9B4C 7F0C4FDC 2484FFF8 */  addiu $a0, $a0, -8
/* 0F9B50 7F0C4FE0 AFA400CC */  sw    $a0, 0xcc($sp)
.Ljp7F0C4FE4:
/* 0F9B54 7F0C4FE4 0C001149 */  jal   get_video2_settings_uly
/* 0F9B58 7F0C4FE8 00000000 */   nop   
/* 0F9B5C 7F0C4FEC 3C0F8009 */  lui   $t7, %hi(dword_CODE_bss_8008C708) # $t7, 0x8009
/* 0F9B60 7F0C4FF0 8DEFC778 */  lw    $t7, %lo(dword_CODE_bss_8008C708)($t7)
/* 0F9B64 7F0C4FF4 244D0016 */  addiu $t5, $v0, 0x16
/* 0F9B68 7F0C4FF8 AFAD00C8 */  sw    $t5, 0xc8($sp)
/* 0F9B6C 7F0C4FFC 15E0001C */  bnez  $t7, .Ljp7F0C5070
/* 0F9B70 7F0C5000 00000000 */   nop   
/* 0F9B74 7F0C5004 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F9B78 7F0C5008 00000000 */   nop   
/* 0F9B7C 7F0C500C 00028400 */  sll   $s0, $v0, 0x10
/* 0F9B80 7F0C5010 0010C403 */  sra   $t8, $s0, 0x10
/* 0F9B84 7F0C5014 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F9B88 7F0C5018 03008025 */   move  $s0, $t8
/* 0F9B8C 7F0C501C 3C198004 */  lui   $t9, %hi(ptrSecondFontTableSmall) # $t9, 0x8004
/* 0F9B90 7F0C5020 3C0B8004 */  lui   $t3, %hi(ptrFirstFontTableSmall) # $t3, 0x8004
/* 0F9B94 7F0C5024 8D6B0EDC */  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
/* 0F9B98 7F0C5028 8F390EE0 */  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
/* 0F9B9C 7F0C502C 3C0C00FF */  lui   $t4, (0x00FF00B0 >> 16) # lui $t4, 0xff
/* 0F9BA0 7F0C5030 358C00B0 */  ori   $t4, (0x00FF00B0 & 0xFFFF) # ori $t4, $t4, 0xb0
/* 0F9BA4 7F0C5034 3C078006 */  lui   $a3, %hi(ascii_MP_watch_menu_left_chevron) # $a3, 0x8006
/* 0F9BA8 7F0C5038 24E7BC68 */  addiu $a3, %lo(ascii_MP_watch_menu_left_chevron) # addiu $a3, $a3, -0x4398
/* 0F9BAC 7F0C503C AFAC0018 */  sw    $t4, 0x18($sp)
/* 0F9BB0 7F0C5040 02202025 */  move  $a0, $s1
/* 0F9BB4 7F0C5044 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F9BB8 7F0C5048 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9BBC 7F0C504C AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F9BC0 7F0C5050 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F9BC4 7F0C5054 AFA00024 */  sw    $zero, 0x24($sp)
/* 0F9BC8 7F0C5058 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9BCC 7F0C505C AFAB0014 */  sw    $t3, 0x14($sp)
/* 0F9BD0 7F0C5060 0FC2B99B */  jal   en_text_write_stuff
/* 0F9BD4 7F0C5064 AFB90010 */   sw    $t9, 0x10($sp)
/* 0F9BD8 7F0C5068 1000001E */  b     .Ljp7F0C50E4
/* 0F9BDC 7F0C506C 00408825 */   move  $s1, $v0
.Ljp7F0C5070:
/* 0F9BE0 7F0C5070 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F9BE4 7F0C5074 00000000 */   nop   
/* 0F9BE8 7F0C5078 00028400 */  sll   $s0, $v0, 0x10
/* 0F9BEC 7F0C507C 00107403 */  sra   $t6, $s0, 0x10
/* 0F9BF0 7F0C5080 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F9BF4 7F0C5084 01C08025 */   move  $s0, $t6
/* 0F9BF8 7F0C5088 3C0D8004 */  lui   $t5, %hi(ptrSecondFontTableSmall) # $t5, 0x8004
/* 0F9BFC 7F0C508C 3C0F8004 */  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
/* 0F9C00 7F0C5090 8DEF0EDC */  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
/* 0F9C04 7F0C5094 8DAD0EE0 */  lw    $t5, %lo(ptrSecondFontTableSmall)($t5)
/* 0F9C08 7F0C5098 3C18A0FF */  lui   $t8, (0xA0FFA0F0 >> 16) # lui $t8, 0xa0ff
/* 0F9C0C 7F0C509C 3C190070 */  lui   $t9, (0x007000A0 >> 16) # lui $t9, 0x70
/* 0F9C10 7F0C50A0 373900A0 */  ori   $t9, (0x007000A0 & 0xFFFF) # ori $t9, $t9, 0xa0
/* 0F9C14 7F0C50A4 3718A0F0 */  ori   $t8, (0xA0FFA0F0 & 0xFFFF) # ori $t8, $t8, 0xa0f0
/* 0F9C18 7F0C50A8 3C078006 */  lui   $a3, %hi(ascii_MP_watch_menu_left_chevron) # $a3, 0x8006
/* 0F9C1C 7F0C50AC 24E7BC68 */  addiu $a3, %lo(ascii_MP_watch_menu_left_chevron) # addiu $a3, $a3, -0x4398
/* 0F9C20 7F0C50B0 AFB80018 */  sw    $t8, 0x18($sp)
/* 0F9C24 7F0C50B4 AFB9001C */  sw    $t9, 0x1c($sp)
/* 0F9C28 7F0C50B8 02202025 */  move  $a0, $s1
/* 0F9C2C 7F0C50BC 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F9C30 7F0C50C0 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9C34 7F0C50C4 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F9C38 7F0C50C8 AFA20024 */  sw    $v0, 0x24($sp)
/* 0F9C3C 7F0C50CC AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9C40 7F0C50D0 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0F9C44 7F0C50D4 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0F9C48 7F0C50D8 0FC2BCA7 */  jal   jp_text_write_stuff
/* 0F9C4C 7F0C50DC AFAD0010 */   sw    $t5, 0x10($sp)
/* 0F9C50 7F0C50E0 00408825 */  move  $s1, $v0
.Ljp7F0C50E4:
/* 0F9C54 7F0C50E4 0FC30AB4 */  jal   check_can_advance_right_on_mpmenu
/* 0F9C58 7F0C50E8 00000000 */   nop   
/* 0F9C5C 7F0C50EC 10400056 */  beqz  $v0, .Ljp7F0C5248
/* 0F9C60 7F0C50F0 00000000 */   nop   
/* 0F9C64 7F0C50F4 0C001145 */  jal   get_video2_settings_ulx
/* 0F9C68 7F0C50F8 00000000 */   nop   
/* 0F9C6C 7F0C50FC 3C038009 */  lui   $v1, %hi(is_gameover_flag) # $v1, 0x8009
/* 0F9C70 7F0C5100 8C63C774 */  lw    $v1, %lo(is_gameover_flag)($v1)
/* 0F9C74 7F0C5104 00027400 */  sll   $t6, $v0, 0x10
/* 0F9C78 7F0C5108 240B000A */  li    $t3, 10
/* 0F9C7C 7F0C510C 50600004 */  beql  $v1, $zero, .Ljp7F0C5120
/* 0F9C80 7F0C5110 AFA00050 */   sw    $zero, 0x50($sp)
/* 0F9C84 7F0C5114 10000002 */  b     .Ljp7F0C5120
/* 0F9C88 7F0C5118 AFAB0050 */   sw    $t3, 0x50($sp)
/* 0F9C8C 7F0C511C AFA00050 */  sw    $zero, 0x50($sp)
.Ljp7F0C5120:
/* 0F9C90 7F0C5120 8FAC0050 */  lw    $t4, 0x50($sp)
/* 0F9C94 7F0C5124 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0F9C98 7F0C5128 000E6C03 */  sra   $t5, $t6, 0x10
/* 0F9C9C 7F0C512C 018D7821 */  addu  $t7, $t4, $t5
/* 0F9CA0 7F0C5130 01F82021 */  addu  $a0, $t7, $t8
/* 0F9CA4 7F0C5134 24840070 */  addiu $a0, $a0, 0x70
/* 0F9CA8 7F0C5138 10600003 */  beqz  $v1, .Ljp7F0C5148
/* 0F9CAC 7F0C513C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F9CB0 7F0C5140 24840008 */  addiu $a0, $a0, 8
/* 0F9CB4 7F0C5144 AFA400CC */  sw    $a0, 0xcc($sp)
.Ljp7F0C5148:
/* 0F9CB8 7F0C5148 0C001149 */  jal   get_video2_settings_uly
/* 0F9CBC 7F0C514C 00000000 */   nop   
/* 0F9CC0 7F0C5150 3C0B8009 */  lui   $t3, %hi(dword_CODE_bss_8008C708) # $t3, 0x8009
/* 0F9CC4 7F0C5154 8D6BC778 */  lw    $t3, %lo(dword_CODE_bss_8008C708)($t3)
/* 0F9CC8 7F0C5158 24590016 */  addiu $t9, $v0, 0x16
/* 0F9CCC 7F0C515C AFB900C8 */  sw    $t9, 0xc8($sp)
/* 0F9CD0 7F0C5160 1560001C */  bnez  $t3, .Ljp7F0C51D4
/* 0F9CD4 7F0C5164 00000000 */   nop   
/* 0F9CD8 7F0C5168 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F9CDC 7F0C516C 00000000 */   nop   
/* 0F9CE0 7F0C5170 00028400 */  sll   $s0, $v0, 0x10
/* 0F9CE4 7F0C5174 00107403 */  sra   $t6, $s0, 0x10
/* 0F9CE8 7F0C5178 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F9CEC 7F0C517C 01C08025 */   move  $s0, $t6
/* 0F9CF0 7F0C5180 3C0C8004 */  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
/* 0F9CF4 7F0C5184 3C0D8004 */  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
/* 0F9CF8 7F0C5188 8DAD0EDC */  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
/* 0F9CFC 7F0C518C 8D8C0EE0 */  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
/* 0F9D00 7F0C5190 3C0F00FF */  lui   $t7, (0x00FF00B0 >> 16) # lui $t7, 0xff
/* 0F9D04 7F0C5194 35EF00B0 */  ori   $t7, (0x00FF00B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0F9D08 7F0C5198 3C078006 */  lui   $a3, %hi(ascii_MP_watch_menu_right_chevron) # $a3, 0x8006
/* 0F9D0C 7F0C519C 24E7BC6C */  addiu $a3, %lo(ascii_MP_watch_menu_right_chevron) # addiu $a3, $a3, -0x4394
/* 0F9D10 7F0C51A0 AFAF0018 */  sw    $t7, 0x18($sp)
/* 0F9D14 7F0C51A4 02202025 */  move  $a0, $s1
/* 0F9D18 7F0C51A8 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F9D1C 7F0C51AC 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9D20 7F0C51B0 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F9D24 7F0C51B4 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F9D28 7F0C51B8 AFA00024 */  sw    $zero, 0x24($sp)
/* 0F9D2C 7F0C51BC AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9D30 7F0C51C0 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0F9D34 7F0C51C4 0FC2B99B */  jal   en_text_write_stuff
/* 0F9D38 7F0C51C8 AFAC0010 */   sw    $t4, 0x10($sp)
/* 0F9D3C 7F0C51CC 1000001E */  b     .Ljp7F0C5248
/* 0F9D40 7F0C51D0 00408825 */   move  $s1, $v0
.Ljp7F0C51D4:
/* 0F9D44 7F0C51D4 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F9D48 7F0C51D8 00000000 */   nop   
/* 0F9D4C 7F0C51DC 00028400 */  sll   $s0, $v0, 0x10
/* 0F9D50 7F0C51E0 0010C403 */  sra   $t8, $s0, 0x10
/* 0F9D54 7F0C51E4 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F9D58 7F0C51E8 03008025 */   move  $s0, $t8
/* 0F9D5C 7F0C51EC 3C198004 */  lui   $t9, %hi(ptrSecondFontTableSmall) # $t9, 0x8004
/* 0F9D60 7F0C51F0 3C0B8004 */  lui   $t3, %hi(ptrFirstFontTableSmall) # $t3, 0x8004
/* 0F9D64 7F0C51F4 8D6B0EDC */  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
/* 0F9D68 7F0C51F8 8F390EE0 */  lw    $t9, %lo(ptrSecondFontTableSmall)($t9)
/* 0F9D6C 7F0C51FC 3C0EA0FF */  lui   $t6, (0xA0FFA0F0 >> 16) # lui $t6, 0xa0ff
/* 0F9D70 7F0C5200 3C0C0070 */  lui   $t4, (0x007000A0 >> 16) # lui $t4, 0x70
/* 0F9D74 7F0C5204 358C00A0 */  ori   $t4, (0x007000A0 & 0xFFFF) # ori $t4, $t4, 0xa0
/* 0F9D78 7F0C5208 35CEA0F0 */  ori   $t6, (0xA0FFA0F0 & 0xFFFF) # ori $t6, $t6, 0xa0f0
/* 0F9D7C 7F0C520C 3C078006 */  lui   $a3, %hi(ascii_MP_watch_menu_right_chevron) # $a3, 0x8006
/* 0F9D80 7F0C5210 24E7BC6C */  addiu $a3, %lo(ascii_MP_watch_menu_right_chevron) # addiu $a3, $a3, -0x4394
/* 0F9D84 7F0C5214 AFAE0018 */  sw    $t6, 0x18($sp)
/* 0F9D88 7F0C5218 AFAC001C */  sw    $t4, 0x1c($sp)
/* 0F9D8C 7F0C521C 02202025 */  move  $a0, $s1
/* 0F9D90 7F0C5220 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F9D94 7F0C5224 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9D98 7F0C5228 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F9D9C 7F0C522C AFA20024 */  sw    $v0, 0x24($sp)
/* 0F9DA0 7F0C5230 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9DA4 7F0C5234 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0F9DA8 7F0C5238 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0F9DAC 7F0C523C 0FC2BCA7 */  jal   jp_text_write_stuff
/* 0F9DB0 7F0C5240 AFB90010 */   sw    $t9, 0x10($sp)
/* 0F9DB4 7F0C5244 00408825 */  move  $s1, $v0
.Ljp7F0C5248:
/* 0F9DB8 7F0C5248 3C038008 */  lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0F9DBC 7F0C524C 8C63A120 */  lw    $v1, %lo(pPlayer)($v1)
/* 0F9DC0 7F0C5250 24010003 */  li    $at, 3
/* 0F9DC4 7F0C5254 8FAD00D0 */  lw    $t5, 0xd0($sp)
/* 0F9DC8 7F0C5258 8C6229C8 */  lw    $v0, 0x29c8($v1)
/* 0F9DCC 7F0C525C 10410003 */  beq   $v0, $at, .Ljp7F0C526C
/* 0F9DD0 7F0C5260 24010004 */   li    $at, 4
/* 0F9DD4 7F0C5264 544101AA */  bnel  $v0, $at, .Ljp7F0C5910
/* 0F9DD8 7F0C5268 24010002 */   li    $at, 2
.Ljp7F0C526C:
/* 0F9DDC 7F0C526C 19A0000D */  blez  $t5, .Ljp7F0C52A4
/* 0F9DE0 7F0C5270 00002025 */   move  $a0, $zero
/* 0F9DE4 7F0C5274 27A30094 */  addiu $v1, $sp, 0x94
/* 0F9DE8 7F0C5278 AFA30044 */  sw    $v1, 0x44($sp)
.Ljp7F0C527C:
/* 0F9DEC 7F0C527C 0FC31162 */  jal   get_points_for_mp_player
/* 0F9DF0 7F0C5280 AFA40090 */   sw    $a0, 0x90($sp)
/* 0F9DF4 7F0C5284 8FA30044 */  lw    $v1, 0x44($sp)
/* 0F9DF8 7F0C5288 8FA40090 */  lw    $a0, 0x90($sp)
/* 0F9DFC 7F0C528C AC620000 */  sw    $v0, ($v1)
/* 0F9E00 7F0C5290 8FAF00D0 */  lw    $t7, 0xd0($sp)
/* 0F9E04 7F0C5294 24840001 */  addiu $a0, $a0, 1
/* 0F9E08 7F0C5298 24630004 */  addiu $v1, $v1, 4
/* 0F9E0C 7F0C529C 548FFFF7 */  bnel  $a0, $t7, .Ljp7F0C527C
/* 0F9E10 7F0C52A0 AFA30044 */   sw    $v1, 0x44($sp)
.Ljp7F0C52A4:
/* 0F9E14 7F0C52A4 3C048009 */  lui   $a0, %hi(is_gameover_flag) # $a0, 0x8009
/* 0F9E18 7F0C52A8 8C84C774 */  lw    $a0, %lo(is_gameover_flag)($a0)
/* 0F9E1C 7F0C52AC 2C980001 */  sltiu $t8, $a0, 1
/* 0F9E20 7F0C52B0 13000005 */  beqz  $t8, .Ljp7F0C52C8
/* 0F9E24 7F0C52B4 03002025 */   move  $a0, $t8
/* 0F9E28 7F0C52B8 3C048009 */  lui   $a0, %hi(stop_play_flag) # $a0, 0x8009
/* 0F9E2C 7F0C52BC 8C84C770 */  lw    $a0, %lo(stop_play_flag)($a0)
/* 0F9E30 7F0C52C0 2C990001 */  sltiu $t9, $a0, 1
/* 0F9E34 7F0C52C4 03202025 */  move  $a0, $t9
.Ljp7F0C52C8:
/* 0F9E38 7F0C52C8 0FC31303 */  jal   true_if_displaying_rank_in_mp
/* 0F9E3C 7F0C52CC 00000000 */   nop   
/* 0F9E40 7F0C52D0 10400034 */  beqz  $v0, .Ljp7F0C53A4
/* 0F9E44 7F0C52D4 27A400AC */   addiu $a0, $sp, 0xac
/* 0F9E48 7F0C52D8 0FC31251 */  jal   write_playerrank_to_buffer
/* 0F9E4C 7F0C52DC 8FA500D4 */   lw    $a1, 0xd4($sp)
/* 0F9E50 7F0C52E0 3C0B8004 */  lui   $t3, %hi(ptrFirstFontTableSmall) # $t3, 0x8004
/* 0F9E54 7F0C52E4 8D6B0EDC */  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
/* 0F9E58 7F0C52E8 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0F9E5C 7F0C52EC 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0F9E60 7F0C52F0 27A400BC */  addiu $a0, $sp, 0xbc
/* 0F9E64 7F0C52F4 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0F9E68 7F0C52F8 27A600AC */  addiu $a2, $sp, 0xac
/* 0F9E6C 7F0C52FC AFA00014 */  sw    $zero, 0x14($sp)
/* 0F9E70 7F0C5300 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0F9E74 7F0C5304 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0F9E78 7F0C5308 0C001145 */  jal   get_video2_settings_ulx
/* 0F9E7C 7F0C530C 00000000 */   nop   
/* 0F9E80 7F0C5310 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0F9E84 7F0C5314 8FAD00C0 */  lw    $t5, 0xc0($sp)
/* 0F9E88 7F0C5318 004E6021 */  addu  $t4, $v0, $t6
/* 0F9E8C 7F0C531C 000D7843 */  sra   $t7, $t5, 1
/* 0F9E90 7F0C5320 018F2023 */  subu  $a0, $t4, $t7
/* 0F9E94 7F0C5324 24840050 */  addiu $a0, $a0, 0x50
/* 0F9E98 7F0C5328 0C001149 */  jal   get_video2_settings_uly
/* 0F9E9C 7F0C532C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F9EA0 7F0C5330 8FB800BC */  lw    $t8, 0xbc($sp)
/* 0F9EA4 7F0C5334 0018C843 */  sra   $t9, $t8, 1
/* 0F9EA8 7F0C5338 00595823 */  subu  $t3, $v0, $t9
/* 0F9EAC 7F0C533C 256E0025 */  addiu $t6, $t3, 0x25
/* 0F9EB0 7F0C5340 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F9EB4 7F0C5344 AFAE00C8 */   sw    $t6, 0xc8($sp)
/* 0F9EB8 7F0C5348 00028400 */  sll   $s0, $v0, 0x10
/* 0F9EBC 7F0C534C 00106C03 */  sra   $t5, $s0, 0x10
/* 0F9EC0 7F0C5350 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F9EC4 7F0C5354 01A08025 */   move  $s0, $t5
/* 0F9EC8 7F0C5358 3C0C8004 */  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
/* 0F9ECC 7F0C535C 3C0F8004 */  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
/* 0F9ED0 7F0C5360 8DEF0EDC */  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
/* 0F9ED4 7F0C5364 8D8C0EE0 */  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
/* 0F9ED8 7F0C5368 3C1800FF */  lui   $t8, (0x00FF00B0 >> 16) # lui $t8, 0xff
/* 0F9EDC 7F0C536C 371800B0 */  ori   $t8, (0x00FF00B0 & 0xFFFF) # ori $t8, $t8, 0xb0
/* 0F9EE0 7F0C5370 AFB80018 */  sw    $t8, 0x18($sp)
/* 0F9EE4 7F0C5374 02202025 */  move  $a0, $s1
/* 0F9EE8 7F0C5378 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F9EEC 7F0C537C 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0F9EF0 7F0C5380 27A700AC */  addiu $a3, $sp, 0xac
/* 0F9EF4 7F0C5384 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0F9EF8 7F0C5388 AFA20020 */  sw    $v0, 0x20($sp)
/* 0F9EFC 7F0C538C AFA00024 */  sw    $zero, 0x24($sp)
/* 0F9F00 7F0C5390 AFA00028 */  sw    $zero, 0x28($sp)
/* 0F9F04 7F0C5394 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0F9F08 7F0C5398 0FC2B99B */  jal   en_text_write_stuff
/* 0F9F0C 7F0C539C AFAC0010 */   sw    $t4, 0x10($sp)
/* 0F9F10 7F0C53A0 00408825 */  move  $s1, $v0
.Ljp7F0C53A4:
/* 0F9F14 7F0C53A4 3C048009 */  lui   $a0, %hi(is_gameover_flag) # $a0, 0x8009
/* 0F9F18 7F0C53A8 8C84C774 */  lw    $a0, %lo(is_gameover_flag)($a0)
/* 0F9F1C 7F0C53AC 2C990001 */  sltiu $t9, $a0, 1
/* 0F9F20 7F0C53B0 13200005 */  beqz  $t9, .Ljp7F0C53C8
/* 0F9F24 7F0C53B4 03202025 */   move  $a0, $t9
/* 0F9F28 7F0C53B8 3C048009 */  lui   $a0, %hi(stop_play_flag) # $a0, 0x8009
/* 0F9F2C 7F0C53BC 8C84C770 */  lw    $a0, %lo(stop_play_flag)($a0)
/* 0F9F30 7F0C53C0 2C8B0001 */  sltiu $t3, $a0, 1
/* 0F9F34 7F0C53C4 01602025 */  move  $a0, $t3
.Ljp7F0C53C8:
/* 0F9F38 7F0C53C8 0FC3131F */  jal   true_if_displaying_score_in_mp
/* 0F9F3C 7F0C53CC 00000000 */   nop   
/* 0F9F40 7F0C53D0 1040014B */  beqz  $v0, .Ljp7F0C5900
/* 0F9F44 7F0C53D4 00000000 */   nop   
/* 0F9F48 7F0C53D8 0FC05202 */  jal   get_scenario
/* 0F9F4C 7F0C53DC 00000000 */   nop   
/* 0F9F50 7F0C53E0 AFA20080 */  sw    $v0, 0x80($sp)
/* 0F9F54 7F0C53E4 0FC30AA2 */  jal   get_textptr_for_textID
/* 0F9F58 7F0C53E8 3404A01B */   li    $a0, 40987
/* 0F9F5C 7F0C53EC 3C0E8004 */  lui   $t6, %hi(ptrFirstFontTableSmall) # $t6, 0x8004
/* 0F9F60 7F0C53F0 8DCE0EDC */  lw    $t6, %lo(ptrFirstFontTableSmall)($t6)
/* 0F9F64 7F0C53F4 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0F9F68 7F0C53F8 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0F9F6C 7F0C53FC 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0F9F70 7F0C5400 27A400BC */  addiu $a0, $sp, 0xbc
/* 0F9F74 7F0C5404 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0F9F78 7F0C5408 00403025 */  move  $a2, $v0
/* 0F9F7C 7F0C540C AFA00014 */  sw    $zero, 0x14($sp)
/* 0F9F80 7F0C5410 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0F9F84 7F0C5414 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0F9F88 7F0C5418 0C001145 */  jal   get_video2_settings_ulx
/* 0F9F8C 7F0C541C 00000000 */   nop   
/* 0F9F90 7F0C5420 8FAD00A8 */  lw    $t5, 0xa8($sp)
/* 0F9F94 7F0C5424 8FAF00C0 */  lw    $t7, 0xc0($sp)
/* 0F9F98 7F0C5428 004D6021 */  addu  $t4, $v0, $t5
/* 0F9F9C 7F0C542C 000FC043 */  sra   $t8, $t7, 1
/* 0F9FA0 7F0C5430 01982023 */  subu  $a0, $t4, $t8
/* 0F9FA4 7F0C5434 24840050 */  addiu $a0, $a0, 0x50
/* 0F9FA8 7F0C5438 0C001149 */  jal   get_video2_settings_uly
/* 0F9FAC 7F0C543C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0F9FB0 7F0C5440 8FB900BC */  lw    $t9, 0xbc($sp)
/* 0F9FB4 7F0C5444 00195843 */  sra   $t3, $t9, 1
/* 0F9FB8 7F0C5448 004B7023 */  subu  $t6, $v0, $t3
/* 0F9FBC 7F0C544C 25CD0035 */  addiu $t5, $t6, 0x35
/* 0F9FC0 7F0C5450 0C001107 */  jal   get_video2_settings_txtClipW
/* 0F9FC4 7F0C5454 AFAD00C8 */   sw    $t5, 0xc8($sp)
/* 0F9FC8 7F0C5458 00028400 */  sll   $s0, $v0, 0x10
/* 0F9FCC 7F0C545C 00107C03 */  sra   $t7, $s0, 0x10
/* 0F9FD0 7F0C5460 0C00110B */  jal   get_video2_settings_txtClipH
/* 0F9FD4 7F0C5464 01E08025 */   move  $s0, $t7
/* 0F9FD8 7F0C5468 3C0C8004 */  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
/* 0F9FDC 7F0C546C 3C188004 */  lui   $t8, %hi(ptrFirstFontTableSmall) # $t8, 0x8004
/* 0F9FE0 7F0C5470 8F180EDC */  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
/* 0F9FE4 7F0C5474 8D8C0EE0 */  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
/* 0F9FE8 7F0C5478 3C1900FF */  lui   $t9, (0x00FF00B0 >> 16) # lui $t9, 0xff
/* 0F9FEC 7F0C547C 373900B0 */  ori   $t9, (0x00FF00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0F9FF0 7F0C5480 AFB90018 */  sw    $t9, 0x18($sp)
/* 0F9FF4 7F0C5484 02202025 */  move  $a0, $s1
/* 0F9FF8 7F0C5488 27A500CC */  addiu $a1, $sp, 0xcc
/* 0F9FFC 7F0C548C 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FA000 7F0C5490 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FA004 7F0C5494 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FA008 7F0C5498 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FA00C 7F0C549C AFA00024 */  sw    $zero, 0x24($sp)
/* 0FA010 7F0C54A0 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FA014 7F0C54A4 AFB80014 */  sw    $t8, 0x14($sp)
/* 0FA018 7F0C54A8 0FC2B99B */  jal   en_text_write_stuff
/* 0FA01C 7F0C54AC AFAC0010 */   sw    $t4, 0x10($sp)
/* 0FA020 7F0C54B0 8FA30080 */  lw    $v1, 0x80($sp)
/* 0FA024 7F0C54B4 24010005 */  li    $at, 5
/* 0FA028 7F0C54B8 00408825 */  move  $s1, $v0
/* 0FA02C 7F0C54BC 1061000A */  beq   $v1, $at, .Ljp7F0C54E8
/* 0FA030 7F0C54C0 8FAB00D4 */   lw    $t3, 0xd4($sp)
/* 0FA034 7F0C54C4 24010006 */  li    $at, 6
/* 0FA038 7F0C54C8 10610007 */  beq   $v1, $at, .Ljp7F0C54E8
/* 0FA03C 7F0C54CC 24010007 */   li    $at, 7
/* 0FA040 7F0C54D0 10610005 */  beq   $v1, $at, .Ljp7F0C54E8
/* 0FA044 7F0C54D4 24010002 */   li    $at, 2
/* 0FA048 7F0C54D8 10610003 */  beq   $v1, $at, .Ljp7F0C54E8
/* 0FA04C 7F0C54DC 24010003 */   li    $at, 3
/* 0FA050 7F0C54E0 14610016 */  bne   $v1, $at, .Ljp7F0C553C
/* 0FA054 7F0C54E4 240D0001 */   li    $t5, 1
.Ljp7F0C54E8:
/* 0FA058 7F0C54E8 000B70C0 */  sll   $t6, $t3, 3
/* 0FA05C 7F0C54EC 01CB7023 */  subu  $t6, $t6, $t3
/* 0FA060 7F0C54F0 000E7100 */  sll   $t6, $t6, 4
/* 0FA064 7F0C54F4 3C0D8008 */  lui   $t5, %hi(player1_player_data+105)
/* 0FA068 7F0C54F8 01AE6821 */  addu  $t5, $t5, $t6
/* 0FA06C 7F0C54FC 91AD9FC9 */  lbu   $t5, %lo(player1_player_data+105)($t5)
/* 0FA070 7F0C5500 24190005 */  li    $t9, 5
/* 0FA074 7F0C5504 240B0004 */  li    $t3, 4
/* 0FA078 7F0C5508 15A00008 */  bnez  $t5, .Ljp7F0C552C
/* 0FA07C 7F0C550C 240E0002 */   li    $t6, 2
/* 0FA080 7F0C5510 240F0003 */  li    $t7, 3
/* 0FA084 7F0C5514 240C0002 */  li    $t4, 2
/* 0FA088 7F0C5518 24180004 */  li    $t8, 4
/* 0FA08C 7F0C551C AFAF008C */  sw    $t7, 0x8c($sp)
/* 0FA090 7F0C5520 AFAC0088 */  sw    $t4, 0x88($sp)
/* 0FA094 7F0C5524 10000008 */  b     .Ljp7F0C5548
/* 0FA098 7F0C5528 AFB80084 */   sw    $t8, 0x84($sp)
.Ljp7F0C552C:
/* 0FA09C 7F0C552C AFB9008C */  sw    $t9, 0x8c($sp)
/* 0FA0A0 7F0C5530 AFAB0088 */  sw    $t3, 0x88($sp)
/* 0FA0A4 7F0C5534 10000004 */  b     .Ljp7F0C5548
/* 0FA0A8 7F0C5538 AFAE0084 */   sw    $t6, 0x84($sp)
.Ljp7F0C553C:
/* 0FA0AC 7F0C553C AFAD008C */  sw    $t5, 0x8c($sp)
/* 0FA0B0 7F0C5540 AFA00088 */  sw    $zero, 0x88($sp)
/* 0FA0B4 7F0C5544 AFA00084 */  sw    $zero, 0x84($sp)
.Ljp7F0C5548:
/* 0FA0B8 7F0C5548 8FAF00D0 */  lw    $t7, 0xd0($sp)
/* 0FA0BC 7F0C554C 24010002 */  li    $at, 2
/* 0FA0C0 7F0C5550 15E1004E */  bne   $t7, $at, .Ljp7F0C568C
/* 0FA0C4 7F0C5554 00000000 */   nop   
/* 0FA0C8 7F0C5558 0C001145 */  jal   get_video2_settings_ulx
/* 0FA0CC 7F0C555C 00000000 */   nop   
/* 0FA0D0 7F0C5560 00028400 */  sll   $s0, $v0, 0x10
/* 0FA0D4 7F0C5564 00106403 */  sra   $t4, $s0, 0x10
/* 0FA0D8 7F0C5568 0C001149 */  jal   get_video2_settings_uly
/* 0FA0DC 7F0C556C 01808025 */   move  $s0, $t4
/* 0FA0E0 7F0C5570 8FA300D4 */  lw    $v1, 0xd4($sp)
/* 0FA0E4 7F0C5574 00024400 */  sll   $t0, $v0, 0x10
/* 0FA0E8 7F0C5578 0008C403 */  sra   $t8, $t0, 0x10
/* 0FA0EC 7F0C557C 14600004 */  bnez  $v1, .Ljp7F0C5590
/* 0FA0F0 7F0C5580 03004025 */   move  $t0, $t8
/* 0FA0F4 7F0C5584 8FB9008C */  lw    $t9, 0x8c($sp)
/* 0FA0F8 7F0C5588 1000000F */  b     .Ljp7F0C55C8
/* 0FA0FC 7F0C558C AFB90050 */   sw    $t9, 0x50($sp)
.Ljp7F0C5590:
/* 0FA100 7F0C5590 000370C0 */  sll   $t6, $v1, 3
/* 0FA104 7F0C5594 01C37023 */  subu  $t6, $t6, $v1
/* 0FA108 7F0C5598 000E7100 */  sll   $t6, $t6, 4
/* 0FA10C 7F0C559C 3C0D8008 */  lui   $t5, %hi(player1_player_data + 0x69)
/* 0FA110 7F0C55A0 01AE6821 */  addu  $t5, $t5, $t6
/* 0FA114 7F0C55A4 3C0B8008 */  lui   $t3, %hi(player1_player_data + 0x69) # $t3, 0x8008
/* 0FA118 7F0C55A8 916B9FC9 */  lbu   $t3, %lo(player1_player_data + 0x69)($t3)
/* 0FA11C 7F0C55AC 91AD9FC9 */  lbu   $t5, %lo(player1_player_data + 0x69)($t5)
/* 0FA120 7F0C55B0 8FA60084 */  lw    $a2, 0x84($sp)
/* 0FA124 7F0C55B4 156D0003 */  bne   $t3, $t5, .Ljp7F0C55C4
/* 0FA128 7F0C55B8 00000000 */   nop   
/* 0FA12C 7F0C55BC 10000001 */  b     .Ljp7F0C55C4
/* 0FA130 7F0C55C0 8FA60088 */   lw    $a2, 0x88($sp)
.Ljp7F0C55C4:
/* 0FA134 7F0C55C4 AFA60050 */  sw    $a2, 0x50($sp)
.Ljp7F0C55C8:
/* 0FA138 7F0C55C8 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0FA13C 7F0C55CC 8FAC0050 */  lw    $t4, 0x50($sp)
/* 0FA140 7F0C55D0 02202025 */  move  $a0, $s1
/* 0FA144 7F0C55D4 020F2821 */  addu  $a1, $s0, $t7
/* 0FA148 7F0C55D8 24A50050 */  addiu $a1, $a1, 0x50
/* 0FA14C 7F0C55DC 25060046 */  addiu $a2, $t0, 0x46
/* 0FA150 7F0C55E0 8FA70094 */  lw    $a3, 0x94($sp)
/* 0FA154 7F0C55E4 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA158 7F0C55E8 AFAC0010 */   sw    $t4, 0x10($sp)
/* 0FA15C 7F0C55EC 0C001145 */  jal   get_video2_settings_ulx
/* 0FA160 7F0C55F0 00408825 */   move  $s1, $v0
/* 0FA164 7F0C55F4 00028400 */  sll   $s0, $v0, 0x10
/* 0FA168 7F0C55F8 0010C403 */  sra   $t8, $s0, 0x10
/* 0FA16C 7F0C55FC 0C001149 */  jal   get_video2_settings_uly
/* 0FA170 7F0C5600 03008025 */   move  $s0, $t8
/* 0FA174 7F0C5604 8FA300D4 */  lw    $v1, 0xd4($sp)
/* 0FA178 7F0C5608 00024400 */  sll   $t0, $v0, 0x10
/* 0FA17C 7F0C560C 0008CC03 */  sra   $t9, $t0, 0x10
/* 0FA180 7F0C5610 24010001 */  li    $at, 1
/* 0FA184 7F0C5614 14610004 */  bne   $v1, $at, .Ljp7F0C5628
/* 0FA188 7F0C5618 03204025 */   move  $t0, $t9
/* 0FA18C 7F0C561C 8FAE008C */  lw    $t6, 0x8c($sp)
/* 0FA190 7F0C5620 1000000F */  b     .Ljp7F0C5660
/* 0FA194 7F0C5624 AFAE0050 */   sw    $t6, 0x50($sp)
.Ljp7F0C5628:
/* 0FA198 7F0C5628 000368C0 */  sll   $t5, $v1, 3
/* 0FA19C 7F0C562C 01A36823 */  subu  $t5, $t5, $v1
/* 0FA1A0 7F0C5630 3C028008 */  lui   $v0, %hi(player1_player_data) # $v0, 0x8008
/* 0FA1A4 7F0C5634 24429F60 */  addiu $v0, %lo(player1_player_data) # addiu $v0, $v0, -0x60a0
/* 0FA1A8 7F0C5638 000D6900 */  sll   $t5, $t5, 4
/* 0FA1AC 7F0C563C 004D7821 */  addu  $t7, $v0, $t5
/* 0FA1B0 7F0C5640 91EC0069 */  lbu   $t4, 0x69($t7)
/* 0FA1B4 7F0C5644 904B00D9 */  lbu   $t3, 0xd9($v0)
/* 0FA1B8 7F0C5648 8FA60084 */  lw    $a2, 0x84($sp)
/* 0FA1BC 7F0C564C 156C0003 */  bne   $t3, $t4, .Ljp7F0C565C
/* 0FA1C0 7F0C5650 00000000 */   nop   
/* 0FA1C4 7F0C5654 10000001 */  b     .Ljp7F0C565C
/* 0FA1C8 7F0C5658 8FA60088 */   lw    $a2, 0x88($sp)
.Ljp7F0C565C:
/* 0FA1CC 7F0C565C AFA60050 */  sw    $a2, 0x50($sp)
.Ljp7F0C5660:
/* 0FA1D0 7F0C5660 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0FA1D4 7F0C5664 8FB90050 */  lw    $t9, 0x50($sp)
/* 0FA1D8 7F0C5668 02202025 */  move  $a0, $s1
/* 0FA1DC 7F0C566C 02182821 */  addu  $a1, $s0, $t8
/* 0FA1E0 7F0C5670 24A50050 */  addiu $a1, $a1, 0x50
/* 0FA1E4 7F0C5674 25060056 */  addiu $a2, $t0, 0x56
/* 0FA1E8 7F0C5678 8FA70098 */  lw    $a3, 0x98($sp)
/* 0FA1EC 7F0C567C 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA1F0 7F0C5680 AFB90010 */   sw    $t9, 0x10($sp)
/* 0FA1F4 7F0C5684 1000009E */  b     .Ljp7F0C5900
/* 0FA1F8 7F0C5688 00408825 */   move  $s1, $v0
.Ljp7F0C568C:
/* 0FA1FC 7F0C568C 0C001145 */  jal   get_video2_settings_ulx
/* 0FA200 7F0C5690 00000000 */   nop   
/* 0FA204 7F0C5694 00028400 */  sll   $s0, $v0, 0x10
/* 0FA208 7F0C5698 00107403 */  sra   $t6, $s0, 0x10
/* 0FA20C 7F0C569C 0C001149 */  jal   get_video2_settings_uly
/* 0FA210 7F0C56A0 01C08025 */   move  $s0, $t6
/* 0FA214 7F0C56A4 8FA300D4 */  lw    $v1, 0xd4($sp)
/* 0FA218 7F0C56A8 00024400 */  sll   $t0, $v0, 0x10
/* 0FA21C 7F0C56AC 00086C03 */  sra   $t5, $t0, 0x10
/* 0FA220 7F0C56B0 14600004 */  bnez  $v1, .Ljp7F0C56C4
/* 0FA224 7F0C56B4 01A04025 */   move  $t0, $t5
/* 0FA228 7F0C56B8 8FAF008C */  lw    $t7, 0x8c($sp)
/* 0FA22C 7F0C56BC 1000000F */  b     .Ljp7F0C56FC
/* 0FA230 7F0C56C0 AFAF0050 */   sw    $t7, 0x50($sp)
.Ljp7F0C56C4:
/* 0FA234 7F0C56C4 000360C0 */  sll   $t4, $v1, 3
/* 0FA238 7F0C56C8 01836023 */  subu  $t4, $t4, $v1
/* 0FA23C 7F0C56CC 000C6100 */  sll   $t4, $t4, 4
/* 0FA240 7F0C56D0 3C188008 */  lui   $t8, %hi(player1_player_data + 0x69)
/* 0FA244 7F0C56D4 030CC021 */  addu  $t8, $t8, $t4
/* 0FA248 7F0C56D8 3C0B8008 */  lui   $t3, %hi(player1_player_data + 0x69) # $t3, 0x8008
/* 0FA24C 7F0C56DC 916B9FC9 */  lbu   $t3, %lo(player1_player_data + 0x69)($t3)
/* 0FA250 7F0C56E0 93189FC9 */  lbu   $t8, %lo(player1_player_data + 0x69)($t8)
/* 0FA254 7F0C56E4 8FA60084 */  lw    $a2, 0x84($sp)
/* 0FA258 7F0C56E8 15780003 */  bne   $t3, $t8, .Ljp7F0C56F8
/* 0FA25C 7F0C56EC 00000000 */   nop   
/* 0FA260 7F0C56F0 10000001 */  b     .Ljp7F0C56F8
/* 0FA264 7F0C56F4 8FA60088 */   lw    $a2, 0x88($sp)
.Ljp7F0C56F8:
/* 0FA268 7F0C56F8 AFA60050 */  sw    $a2, 0x50($sp)
.Ljp7F0C56FC:
/* 0FA26C 7F0C56FC 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0FA270 7F0C5700 8FAE0050 */  lw    $t6, 0x50($sp)
/* 0FA274 7F0C5704 02202025 */  move  $a0, $s1
/* 0FA278 7F0C5708 02192821 */  addu  $a1, $s0, $t9
/* 0FA27C 7F0C570C 24A50040 */  addiu $a1, $a1, 0x40
/* 0FA280 7F0C5710 25060046 */  addiu $a2, $t0, 0x46
/* 0FA284 7F0C5714 8FA70094 */  lw    $a3, 0x94($sp)
/* 0FA288 7F0C5718 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA28C 7F0C571C AFAE0010 */   sw    $t6, 0x10($sp)
/* 0FA290 7F0C5720 0C001145 */  jal   get_video2_settings_ulx
/* 0FA294 7F0C5724 00408825 */   move  $s1, $v0
/* 0FA298 7F0C5728 00028400 */  sll   $s0, $v0, 0x10
/* 0FA29C 7F0C572C 00106C03 */  sra   $t5, $s0, 0x10
/* 0FA2A0 7F0C5730 0C001149 */  jal   get_video2_settings_uly
/* 0FA2A4 7F0C5734 01A08025 */   move  $s0, $t5
/* 0FA2A8 7F0C5738 8FA300D4 */  lw    $v1, 0xd4($sp)
/* 0FA2AC 7F0C573C 00024400 */  sll   $t0, $v0, 0x10
/* 0FA2B0 7F0C5740 00087C03 */  sra   $t7, $t0, 0x10
/* 0FA2B4 7F0C5744 24010001 */  li    $at, 1
/* 0FA2B8 7F0C5748 14610004 */  bne   $v1, $at, .Ljp7F0C575C
/* 0FA2BC 7F0C574C 01E04025 */   move  $t0, $t7
/* 0FA2C0 7F0C5750 8FAC008C */  lw    $t4, 0x8c($sp)
/* 0FA2C4 7F0C5754 1000000F */  b     .Ljp7F0C5794
/* 0FA2C8 7F0C5758 AFAC0050 */   sw    $t4, 0x50($sp)
.Ljp7F0C575C:
/* 0FA2CC 7F0C575C 0003C0C0 */  sll   $t8, $v1, 3
/* 0FA2D0 7F0C5760 0303C023 */  subu  $t8, $t8, $v1
/* 0FA2D4 7F0C5764 0018C100 */  sll   $t8, $t8, 4
/* 0FA2D8 7F0C5768 3C198008 */  lui   $t9, %hi(player1_player_data + 0x69)
/* 0FA2DC 7F0C576C 0338C821 */  addu  $t9, $t9, $t8
/* 0FA2E0 7F0C5770 3C0B8008 */  lui   $t3, %hi(player2_player_data + 0x69) # $t3, 0x8008
/* 0FA2E4 7F0C5774 916BA039 */  lbu   $t3, %lo(player2_player_data + 0x69)($t3)
/* 0FA2E8 7F0C5778 93399FC9 */  lbu   $t9, %lo(player1_player_data + 0x69)($t9)
/* 0FA2EC 7F0C577C 8FA60084 */  lw    $a2, 0x84($sp)
/* 0FA2F0 7F0C5780 15790003 */  bne   $t3, $t9, .Ljp7F0C5790
/* 0FA2F4 7F0C5784 00000000 */   nop   
/* 0FA2F8 7F0C5788 10000001 */  b     .Ljp7F0C5790
/* 0FA2FC 7F0C578C 8FA60088 */   lw    $a2, 0x88($sp)
.Ljp7F0C5790:
/* 0FA300 7F0C5790 AFA60050 */  sw    $a2, 0x50($sp)
.Ljp7F0C5794:
/* 0FA304 7F0C5794 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FA308 7F0C5798 8FAD0050 */  lw    $t5, 0x50($sp)
/* 0FA30C 7F0C579C 02202025 */  move  $a0, $s1
/* 0FA310 7F0C57A0 020E2821 */  addu  $a1, $s0, $t6
/* 0FA314 7F0C57A4 24A50060 */  addiu $a1, $a1, 0x60
/* 0FA318 7F0C57A8 25060046 */  addiu $a2, $t0, 0x46
/* 0FA31C 7F0C57AC 8FA70098 */  lw    $a3, 0x98($sp)
/* 0FA320 7F0C57B0 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA324 7F0C57B4 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0FA328 7F0C57B8 0C001145 */  jal   get_video2_settings_ulx
/* 0FA32C 7F0C57BC 00408825 */   move  $s1, $v0
/* 0FA330 7F0C57C0 00028400 */  sll   $s0, $v0, 0x10
/* 0FA334 7F0C57C4 00107C03 */  sra   $t7, $s0, 0x10
/* 0FA338 7F0C57C8 0C001149 */  jal   get_video2_settings_uly
/* 0FA33C 7F0C57CC 01E08025 */   move  $s0, $t7
/* 0FA340 7F0C57D0 8FA300D4 */  lw    $v1, 0xd4($sp)
/* 0FA344 7F0C57D4 00024400 */  sll   $t0, $v0, 0x10
/* 0FA348 7F0C57D8 00086403 */  sra   $t4, $t0, 0x10
/* 0FA34C 7F0C57DC 24010002 */  li    $at, 2
/* 0FA350 7F0C57E0 14610004 */  bne   $v1, $at, .Ljp7F0C57F4
/* 0FA354 7F0C57E4 01804025 */   move  $t0, $t4
/* 0FA358 7F0C57E8 8FB8008C */  lw    $t8, 0x8c($sp)
/* 0FA35C 7F0C57EC 1000000F */  b     .Ljp7F0C582C
/* 0FA360 7F0C57F0 AFB80050 */   sw    $t8, 0x50($sp)
.Ljp7F0C57F4:
/* 0FA364 7F0C57F4 0003C8C0 */  sll   $t9, $v1, 3
/* 0FA368 7F0C57F8 0323C823 */  subu  $t9, $t9, $v1
/* 0FA36C 7F0C57FC 0019C900 */  sll   $t9, $t9, 4
/* 0FA370 7F0C5800 3C0E8008 */  lui   $t6, %hi(player1_player_data + 0x69)
/* 0FA374 7F0C5804 01D97021 */  addu  $t6, $t6, $t9
/* 0FA378 7F0C5808 3C0B8008 */  lui   $t3, %hi(player3_player_data + 0x69) # $t3, 0x8008
/* 0FA37C 7F0C580C 916BA0A9 */  lbu   $t3, %lo(player3_player_data + 0x69)($t3)
/* 0FA380 7F0C5810 91CE9FC9 */  lbu   $t6, %lo(player1_player_data + 0x69)($t6)
/* 0FA384 7F0C5814 8FA60084 */  lw    $a2, 0x84($sp)
/* 0FA388 7F0C5818 156E0003 */  bne   $t3, $t6, .Ljp7F0C5828
/* 0FA38C 7F0C581C 00000000 */   nop   
/* 0FA390 7F0C5820 10000001 */  b     .Ljp7F0C5828
/* 0FA394 7F0C5824 8FA60088 */   lw    $a2, 0x88($sp)
.Ljp7F0C5828:
/* 0FA398 7F0C5828 AFA60050 */  sw    $a2, 0x50($sp)
.Ljp7F0C582C:
/* 0FA39C 7F0C582C 8FAD00A8 */  lw    $t5, 0xa8($sp)
/* 0FA3A0 7F0C5830 8FAF0050 */  lw    $t7, 0x50($sp)
/* 0FA3A4 7F0C5834 02202025 */  move  $a0, $s1
/* 0FA3A8 7F0C5838 020D2821 */  addu  $a1, $s0, $t5
/* 0FA3AC 7F0C583C 24A50040 */  addiu $a1, $a1, 0x40
/* 0FA3B0 7F0C5840 25060056 */  addiu $a2, $t0, 0x56
/* 0FA3B4 7F0C5844 8FA7009C */  lw    $a3, 0x9c($sp)
/* 0FA3B8 7F0C5848 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA3BC 7F0C584C AFAF0010 */   sw    $t7, 0x10($sp)
/* 0FA3C0 7F0C5850 8FAC00D0 */  lw    $t4, 0xd0($sp)
/* 0FA3C4 7F0C5854 24010004 */  li    $at, 4
/* 0FA3C8 7F0C5858 00408825 */  move  $s1, $v0
/* 0FA3CC 7F0C585C 15810028 */  bne   $t4, $at, .Ljp7F0C5900
/* 0FA3D0 7F0C5860 00000000 */   nop   
/* 0FA3D4 7F0C5864 0C001145 */  jal   get_video2_settings_ulx
/* 0FA3D8 7F0C5868 00000000 */   nop   
/* 0FA3DC 7F0C586C 00028400 */  sll   $s0, $v0, 0x10
/* 0FA3E0 7F0C5870 0010C403 */  sra   $t8, $s0, 0x10
/* 0FA3E4 7F0C5874 0C001149 */  jal   get_video2_settings_uly
/* 0FA3E8 7F0C5878 03008025 */   move  $s0, $t8
/* 0FA3EC 7F0C587C 8FA300D4 */  lw    $v1, 0xd4($sp)
/* 0FA3F0 7F0C5880 00024400 */  sll   $t0, $v0, 0x10
/* 0FA3F4 7F0C5884 0008CC03 */  sra   $t9, $t0, 0x10
/* 0FA3F8 7F0C5888 24010003 */  li    $at, 3
/* 0FA3FC 7F0C588C 14610004 */  bne   $v1, $at, .Ljp7F0C58A0
/* 0FA400 7F0C5890 03204025 */   move  $t0, $t9
/* 0FA404 7F0C5894 8FAB008C */  lw    $t3, 0x8c($sp)
/* 0FA408 7F0C5898 1000000F */  b     .Ljp7F0C58D8
/* 0FA40C 7F0C589C AFAB0050 */   sw    $t3, 0x50($sp)
.Ljp7F0C58A0:
/* 0FA410 7F0C58A0 000368C0 */  sll   $t5, $v1, 3
/* 0FA414 7F0C58A4 01A36823 */  subu  $t5, $t5, $v1
/* 0FA418 7F0C58A8 3C028008 */  lui   $v0, %hi(player1_player_data) # $v0, 0x8008
/* 0FA41C 7F0C58AC 24429F60 */  addiu $v0, %lo(player1_player_data) # addiu $v0, $v0, -0x60a0
/* 0FA420 7F0C58B0 000D6900 */  sll   $t5, $t5, 4
/* 0FA424 7F0C58B4 004D7821 */  addu  $t7, $v0, $t5
/* 0FA428 7F0C58B8 91EC0069 */  lbu   $t4, 0x69($t7)
/* 0FA42C 7F0C58BC 904E01B9 */  lbu   $t6, 0x1b9($v0)
/* 0FA430 7F0C58C0 8FA60084 */  lw    $a2, 0x84($sp)
/* 0FA434 7F0C58C4 15CC0003 */  bne   $t6, $t4, .Ljp7F0C58D4
/* 0FA438 7F0C58C8 00000000 */   nop   
/* 0FA43C 7F0C58CC 10000001 */  b     .Ljp7F0C58D4
/* 0FA440 7F0C58D0 8FA60088 */   lw    $a2, 0x88($sp)
.Ljp7F0C58D4:
/* 0FA444 7F0C58D4 AFA60050 */  sw    $a2, 0x50($sp)
.Ljp7F0C58D8:
/* 0FA448 7F0C58D8 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0FA44C 7F0C58DC 8FB90050 */  lw    $t9, 0x50($sp)
/* 0FA450 7F0C58E0 02202025 */  move  $a0, $s1
/* 0FA454 7F0C58E4 02182821 */  addu  $a1, $s0, $t8
/* 0FA458 7F0C58E8 24A50060 */  addiu $a1, $a1, 0x60
/* 0FA45C 7F0C58EC 25060056 */  addiu $a2, $t0, 0x56
/* 0FA460 7F0C58F0 8FA700A0 */  lw    $a3, 0xa0($sp)
/* 0FA464 7F0C58F4 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA468 7F0C58F8 AFB90010 */   sw    $t9, 0x10($sp)
/* 0FA46C 7F0C58FC 00408825 */  move  $s1, $v0
.Ljp7F0C5900:
/* 0FA470 7F0C5900 3C038008 */  lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0FA474 7F0C5904 100003BB */  b     .Ljp7F0C67F4
/* 0FA478 7F0C5908 8C63A120 */   lw    $v1, %lo(pPlayer)($v1)
/* 0FA47C 7F0C590C 24010002 */  li    $at, 2
.Ljp7F0C5910:
/* 0FA480 7F0C5910 1441011C */  bne   $v0, $at, .Ljp7F0C5D84
/* 0FA484 7F0C5914 3C048009 */   lui   $a0, %hi(is_gameover_flag) # $a0, 0x8009
/* 0FA488 7F0C5918 8C84C774 */  lw    $a0, %lo(is_gameover_flag)($a0)
/* 0FA48C 7F0C591C 2C8B0001 */  sltiu $t3, $a0, 1
/* 0FA490 7F0C5920 11600005 */  beqz  $t3, .Ljp7F0C5938
/* 0FA494 7F0C5924 01602025 */   move  $a0, $t3
/* 0FA498 7F0C5928 3C048009 */  lui   $a0, %hi(stop_play_flag) # $a0, 0x8009
/* 0FA49C 7F0C592C 8C84C770 */  lw    $a0, %lo(stop_play_flag)($a0)
/* 0FA4A0 7F0C5930 2C8D0001 */  sltiu $t5, $a0, 1
/* 0FA4A4 7F0C5934 01A02025 */  move  $a0, $t5
.Ljp7F0C5938:
/* 0FA4A8 7F0C5938 0FC31303 */  jal   true_if_displaying_rank_in_mp
/* 0FA4AC 7F0C593C 00000000 */   nop   
/* 0FA4B0 7F0C5940 10400034 */  beqz  $v0, .Ljp7F0C5A14
/* 0FA4B4 7F0C5944 27A400AC */   addiu $a0, $sp, 0xac
/* 0FA4B8 7F0C5948 0FC31251 */  jal   write_playerrank_to_buffer
/* 0FA4BC 7F0C594C 8FA500D4 */   lw    $a1, 0xd4($sp)
/* 0FA4C0 7F0C5950 3C0F8004 */  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
/* 0FA4C4 7F0C5954 8DEF0EDC */  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
/* 0FA4C8 7F0C5958 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0FA4CC 7F0C595C 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FA4D0 7F0C5960 27A400BC */  addiu $a0, $sp, 0xbc
/* 0FA4D4 7F0C5964 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0FA4D8 7F0C5968 27A600AC */  addiu $a2, $sp, 0xac
/* 0FA4DC 7F0C596C AFA00014 */  sw    $zero, 0x14($sp)
/* 0FA4E0 7F0C5970 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0FA4E4 7F0C5974 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0FA4E8 7F0C5978 0C001145 */  jal   get_video2_settings_ulx
/* 0FA4EC 7F0C597C 00000000 */   nop   
/* 0FA4F0 7F0C5980 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FA4F4 7F0C5984 8FB800C0 */  lw    $t8, 0xc0($sp)
/* 0FA4F8 7F0C5988 004E6021 */  addu  $t4, $v0, $t6
/* 0FA4FC 7F0C598C 0018C843 */  sra   $t9, $t8, 1
/* 0FA500 7F0C5990 01992023 */  subu  $a0, $t4, $t9
/* 0FA504 7F0C5994 24840050 */  addiu $a0, $a0, 0x50
/* 0FA508 7F0C5998 0C001149 */  jal   get_video2_settings_uly
/* 0FA50C 7F0C599C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FA510 7F0C59A0 8FAB00BC */  lw    $t3, 0xbc($sp)
/* 0FA514 7F0C59A4 000B6843 */  sra   $t5, $t3, 1
/* 0FA518 7F0C59A8 004D7823 */  subu  $t7, $v0, $t5
/* 0FA51C 7F0C59AC 25EE0025 */  addiu $t6, $t7, 0x25
/* 0FA520 7F0C59B0 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FA524 7F0C59B4 AFAE00C8 */   sw    $t6, 0xc8($sp)
/* 0FA528 7F0C59B8 00028400 */  sll   $s0, $v0, 0x10
/* 0FA52C 7F0C59BC 0010C403 */  sra   $t8, $s0, 0x10
/* 0FA530 7F0C59C0 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FA534 7F0C59C4 03008025 */   move  $s0, $t8
/* 0FA538 7F0C59C8 3C0C8004 */  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
/* 0FA53C 7F0C59CC 3C198004 */  lui   $t9, %hi(ptrFirstFontTableSmall) # $t9, 0x8004
/* 0FA540 7F0C59D0 8F390EDC */  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
/* 0FA544 7F0C59D4 8D8C0EE0 */  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
/* 0FA548 7F0C59D8 3C0B00FF */  lui   $t3, (0x00FF00B0 >> 16) # lui $t3, 0xff
/* 0FA54C 7F0C59DC 356B00B0 */  ori   $t3, (0x00FF00B0 & 0xFFFF) # ori $t3, $t3, 0xb0
/* 0FA550 7F0C59E0 AFAB0018 */  sw    $t3, 0x18($sp)
/* 0FA554 7F0C59E4 02202025 */  move  $a0, $s1
/* 0FA558 7F0C59E8 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FA55C 7F0C59EC 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FA560 7F0C59F0 27A700AC */  addiu $a3, $sp, 0xac
/* 0FA564 7F0C59F4 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FA568 7F0C59F8 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FA56C 7F0C59FC AFA00024 */  sw    $zero, 0x24($sp)
/* 0FA570 7F0C5A00 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FA574 7F0C5A04 AFB90014 */  sw    $t9, 0x14($sp)
/* 0FA578 7F0C5A08 0FC2B99B */  jal   en_text_write_stuff
/* 0FA57C 7F0C5A0C AFAC0010 */   sw    $t4, 0x10($sp)
/* 0FA580 7F0C5A10 00408825 */  move  $s1, $v0
.Ljp7F0C5A14:
/* 0FA584 7F0C5A14 0FC30AA2 */  jal   get_textptr_for_textID
/* 0FA588 7F0C5A18 3404A01C */   li    $a0, 40988
/* 0FA58C 7F0C5A1C 3404A01D */  li    $a0, 40989
/* 0FA590 7F0C5A20 0FC30AA2 */  jal   get_textptr_for_textID
/* 0FA594 7F0C5A24 AFA2004C */   sw    $v0, 0x4c($sp)
/* 0FA598 7F0C5A28 8FA700D4 */  lw    $a3, 0xd4($sp)
/* 0FA59C 7F0C5A2C 3C058006 */  lui   $a1, %hi(ascii_pnum_KILLS) # $a1, 0x8006
/* 0FA5A0 7F0C5A30 24A5BC70 */  addiu $a1, %lo(ascii_pnum_KILLS) # addiu $a1, $a1, -0x4390
/* 0FA5A4 7F0C5A34 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0FA5A8 7F0C5A38 27A400AC */  addiu $a0, $sp, 0xac
/* 0FA5AC 7F0C5A3C AFA20010 */  sw    $v0, 0x10($sp)
/* 0FA5B0 7F0C5A40 0C002B29 */  jal   sprintf
/* 0FA5B4 7F0C5A44 24E70001 */   addiu $a3, $a3, 1
/* 0FA5B8 7F0C5A48 3C0D8004 */  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
/* 0FA5BC 7F0C5A4C 8DAD0EDC */  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
/* 0FA5C0 7F0C5A50 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0FA5C4 7F0C5A54 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FA5C8 7F0C5A58 27A400BC */  addiu $a0, $sp, 0xbc
/* 0FA5CC 7F0C5A5C 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0FA5D0 7F0C5A60 27A600AC */  addiu $a2, $sp, 0xac
/* 0FA5D4 7F0C5A64 AFA00014 */  sw    $zero, 0x14($sp)
/* 0FA5D8 7F0C5A68 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0FA5DC 7F0C5A6C AFAD0010 */   sw    $t5, 0x10($sp)
/* 0FA5E0 7F0C5A70 0C001145 */  jal   get_video2_settings_ulx
/* 0FA5E4 7F0C5A74 00000000 */   nop   
/* 0FA5E8 7F0C5A78 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0FA5EC 7F0C5A7C 8FB800C0 */  lw    $t8, 0xc0($sp)
/* 0FA5F0 7F0C5A80 004F7021 */  addu  $t6, $v0, $t7
/* 0FA5F4 7F0C5A84 00186043 */  sra   $t4, $t8, 1
/* 0FA5F8 7F0C5A88 01CC2023 */  subu  $a0, $t6, $t4
/* 0FA5FC 7F0C5A8C 24840050 */  addiu $a0, $a0, 0x50
/* 0FA600 7F0C5A90 0C001149 */  jal   get_video2_settings_uly
/* 0FA604 7F0C5A94 AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FA608 7F0C5A98 8FB900BC */  lw    $t9, 0xbc($sp)
/* 0FA60C 7F0C5A9C 00195843 */  sra   $t3, $t9, 1
/* 0FA610 7F0C5AA0 004B6823 */  subu  $t5, $v0, $t3
/* 0FA614 7F0C5AA4 25AF0035 */  addiu $t7, $t5, 0x35
/* 0FA618 7F0C5AA8 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FA61C 7F0C5AAC AFAF00C8 */   sw    $t7, 0xc8($sp)
/* 0FA620 7F0C5AB0 00028400 */  sll   $s0, $v0, 0x10
/* 0FA624 7F0C5AB4 0010C403 */  sra   $t8, $s0, 0x10
/* 0FA628 7F0C5AB8 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FA62C 7F0C5ABC 03008025 */   move  $s0, $t8
/* 0FA630 7F0C5AC0 3C0E8004 */  lui   $t6, %hi(ptrSecondFontTableSmall) # $t6, 0x8004
/* 0FA634 7F0C5AC4 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) # $t4, 0x8004
/* 0FA638 7F0C5AC8 8D8C0EDC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0FA63C 7F0C5ACC 8DCE0EE0 */  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
/* 0FA640 7F0C5AD0 3C1900FF */  lui   $t9, (0x00FF00B0 >> 16) # lui $t9, 0xff
/* 0FA644 7F0C5AD4 373900B0 */  ori   $t9, (0x00FF00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0FA648 7F0C5AD8 AFB90018 */  sw    $t9, 0x18($sp)
/* 0FA64C 7F0C5ADC 02202025 */  move  $a0, $s1
/* 0FA650 7F0C5AE0 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FA654 7F0C5AE4 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FA658 7F0C5AE8 27A700AC */  addiu $a3, $sp, 0xac
/* 0FA65C 7F0C5AEC AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FA660 7F0C5AF0 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FA664 7F0C5AF4 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FA668 7F0C5AF8 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FA66C 7F0C5AFC AFAC0014 */  sw    $t4, 0x14($sp)
/* 0FA670 7F0C5B00 0FC2B99B */  jal   en_text_write_stuff
/* 0FA674 7F0C5B04 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0FA678 7F0C5B08 8FAB00D0 */  lw    $t3, 0xd0($sp)
/* 0FA67C 7F0C5B0C 00408825 */  move  $s1, $v0
/* 0FA680 7F0C5B10 24010002 */  li    $at, 2
/* 0FA684 7F0C5B14 15610033 */  bne   $t3, $at, .Ljp7F0C5BE4
/* 0FA688 7F0C5B18 8FA200D4 */   lw    $v0, 0xd4($sp)
/* 0FA68C 7F0C5B1C 8FA200D4 */  lw    $v0, 0xd4($sp)
/* 0FA690 7F0C5B20 50400018 */  beql  $v0, $zero, .Ljp7F0C5B84
/* 0FA694 7F0C5B24 24010001 */   li    $at, 1
/* 0FA698 7F0C5B28 0C001145 */  jal   get_video2_settings_ulx
/* 0FA69C 7F0C5B2C 00000000 */   nop   
/* 0FA6A0 7F0C5B30 00028400 */  sll   $s0, $v0, 0x10
/* 0FA6A4 7F0C5B34 00106C03 */  sra   $t5, $s0, 0x10
/* 0FA6A8 7F0C5B38 0C001149 */  jal   get_video2_settings_uly
/* 0FA6AC 7F0C5B3C 01A08025 */   move  $s0, $t5
/* 0FA6B0 7F0C5B40 8FB800D4 */  lw    $t8, 0xd4($sp)
/* 0FA6B4 7F0C5B44 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0FA6B8 7F0C5B48 3C078008 */  lui   $a3, %hi(player1_player_data+36)
/* 0FA6BC 7F0C5B4C 001870C0 */  sll   $t6, $t8, 3
/* 0FA6C0 7F0C5B50 01D87023 */  subu  $t6, $t6, $t8
/* 0FA6C4 7F0C5B54 000E7100 */  sll   $t6, $t6, 4
/* 0FA6C8 7F0C5B58 00EE3821 */  addu  $a3, $a3, $t6
/* 0FA6CC 7F0C5B5C 020F2821 */  addu  $a1, $s0, $t7
/* 0FA6D0 7F0C5B60 24A50050 */  addiu $a1, $a1, 0x50
/* 0FA6D4 7F0C5B64 8CE79F84 */  lw    $a3, %lo(player1_player_data+36)($a3)
/* 0FA6D8 7F0C5B68 02202025 */  move  $a0, $s1
/* 0FA6DC 7F0C5B6C 24460046 */  addiu $a2, $v0, 0x46
/* 0FA6E0 7F0C5B70 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA6E4 7F0C5B74 AFA00010 */   sw    $zero, 0x10($sp)
/* 0FA6E8 7F0C5B78 00408825 */  move  $s1, $v0
/* 0FA6EC 7F0C5B7C 8FA200D4 */  lw    $v0, 0xd4($sp)
/* 0FA6F0 7F0C5B80 24010001 */  li    $at, 1
.Ljp7F0C5B84:
/* 0FA6F4 7F0C5B84 1041007C */  beq   $v0, $at, .Ljp7F0C5D78
/* 0FA6F8 7F0C5B88 000260C0 */   sll   $t4, $v0, 3
/* 0FA6FC 7F0C5B8C 01826023 */  subu  $t4, $t4, $v0
/* 0FA700 7F0C5B90 3C198008 */  lui   $t9, %hi(player1_player_data) # $t9, 0x8008
/* 0FA704 7F0C5B94 27399F60 */  addiu $t9, %lo(player1_player_data) # addiu $t9, $t9, -0x60a0
/* 0FA708 7F0C5B98 000C6100 */  sll   $t4, $t4, 4
/* 0FA70C 7F0C5B9C 01995821 */  addu  $t3, $t4, $t9
/* 0FA710 7F0C5BA0 0C001145 */  jal   get_video2_settings_ulx
/* 0FA714 7F0C5BA4 AFAB0044 */   sw    $t3, 0x44($sp)
/* 0FA718 7F0C5BA8 00028400 */  sll   $s0, $v0, 0x10
/* 0FA71C 7F0C5BAC 00106C03 */  sra   $t5, $s0, 0x10
/* 0FA720 7F0C5BB0 0C001149 */  jal   get_video2_settings_uly
/* 0FA724 7F0C5BB4 01A08025 */   move  $s0, $t5
/* 0FA728 7F0C5BB8 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0FA72C 7F0C5BBC 8FB80044 */  lw    $t8, 0x44($sp)
/* 0FA730 7F0C5BC0 02202025 */  move  $a0, $s1
/* 0FA734 7F0C5BC4 020F2821 */  addu  $a1, $s0, $t7
/* 0FA738 7F0C5BC8 8F070028 */  lw    $a3, 0x28($t8)
/* 0FA73C 7F0C5BCC AFA00010 */  sw    $zero, 0x10($sp)
/* 0FA740 7F0C5BD0 24A50050 */  addiu $a1, $a1, 0x50
/* 0FA744 7F0C5BD4 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA748 7F0C5BD8 24460056 */   addiu $a2, $v0, 0x56
/* 0FA74C 7F0C5BDC 10000066 */  b     .Ljp7F0C5D78
/* 0FA750 7F0C5BE0 00408825 */   move  $s1, $v0
.Ljp7F0C5BE4:
/* 0FA754 7F0C5BE4 50400018 */  beql  $v0, $zero, .Ljp7F0C5C48
/* 0FA758 7F0C5BE8 24010001 */   li    $at, 1
/* 0FA75C 7F0C5BEC 0C001145 */  jal   get_video2_settings_ulx
/* 0FA760 7F0C5BF0 00000000 */   nop   
/* 0FA764 7F0C5BF4 00028400 */  sll   $s0, $v0, 0x10
/* 0FA768 7F0C5BF8 00107403 */  sra   $t6, $s0, 0x10
/* 0FA76C 7F0C5BFC 0C001149 */  jal   get_video2_settings_uly
/* 0FA770 7F0C5C00 01C08025 */   move  $s0, $t6
/* 0FA774 7F0C5C04 8FB900D4 */  lw    $t9, 0xd4($sp)
/* 0FA778 7F0C5C08 8FAC00A8 */  lw    $t4, 0xa8($sp)
/* 0FA77C 7F0C5C0C 3C078008 */  lui   $a3, %hi(player1_player_data+36)
/* 0FA780 7F0C5C10 001958C0 */  sll   $t3, $t9, 3
/* 0FA784 7F0C5C14 01795823 */  subu  $t3, $t3, $t9
/* 0FA788 7F0C5C18 000B5900 */  sll   $t3, $t3, 4
/* 0FA78C 7F0C5C1C 00EB3821 */  addu  $a3, $a3, $t3
/* 0FA790 7F0C5C20 020C2821 */  addu  $a1, $s0, $t4
/* 0FA794 7F0C5C24 24A50040 */  addiu $a1, $a1, 0x40
/* 0FA798 7F0C5C28 8CE79F84 */  lw    $a3, %lo(player1_player_data+36)($a3)
/* 0FA79C 7F0C5C2C 02202025 */  move  $a0, $s1
/* 0FA7A0 7F0C5C30 24460046 */  addiu $a2, $v0, 0x46
/* 0FA7A4 7F0C5C34 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA7A8 7F0C5C38 AFA00010 */   sw    $zero, 0x10($sp)
/* 0FA7AC 7F0C5C3C 00408825 */  move  $s1, $v0
/* 0FA7B0 7F0C5C40 8FA200D4 */  lw    $v0, 0xd4($sp)
/* 0FA7B4 7F0C5C44 24010001 */  li    $at, 1
.Ljp7F0C5C48:
/* 0FA7B8 7F0C5C48 10410017 */  beq   $v0, $at, .Ljp7F0C5CA8
/* 0FA7BC 7F0C5C4C 000268C0 */   sll   $t5, $v0, 3
/* 0FA7C0 7F0C5C50 01A26823 */  subu  $t5, $t5, $v0
/* 0FA7C4 7F0C5C54 3C0F8008 */  lui   $t7, %hi(player1_player_data) # $t7, 0x8008
/* 0FA7C8 7F0C5C58 25EF9F60 */  addiu $t7, %lo(player1_player_data) # addiu $t7, $t7, -0x60a0
/* 0FA7CC 7F0C5C5C 000D6900 */  sll   $t5, $t5, 4
/* 0FA7D0 7F0C5C60 01AFC021 */  addu  $t8, $t5, $t7
/* 0FA7D4 7F0C5C64 0C001145 */  jal   get_video2_settings_ulx
/* 0FA7D8 7F0C5C68 AFB80044 */   sw    $t8, 0x44($sp)
/* 0FA7DC 7F0C5C6C 00028400 */  sll   $s0, $v0, 0x10
/* 0FA7E0 7F0C5C70 00107403 */  sra   $t6, $s0, 0x10
/* 0FA7E4 7F0C5C74 0C001149 */  jal   get_video2_settings_uly
/* 0FA7E8 7F0C5C78 01C08025 */   move  $s0, $t6
/* 0FA7EC 7F0C5C7C 8FAC00A8 */  lw    $t4, 0xa8($sp)
/* 0FA7F0 7F0C5C80 8FB90044 */  lw    $t9, 0x44($sp)
/* 0FA7F4 7F0C5C84 02202025 */  move  $a0, $s1
/* 0FA7F8 7F0C5C88 020C2821 */  addu  $a1, $s0, $t4
/* 0FA7FC 7F0C5C8C 8F270028 */  lw    $a3, 0x28($t9)
/* 0FA800 7F0C5C90 AFA00010 */  sw    $zero, 0x10($sp)
/* 0FA804 7F0C5C94 24A50060 */  addiu $a1, $a1, 0x60
/* 0FA808 7F0C5C98 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA80C 7F0C5C9C 24460046 */   addiu $a2, $v0, 0x46
/* 0FA810 7F0C5CA0 00408825 */  move  $s1, $v0
/* 0FA814 7F0C5CA4 8FA200D4 */  lw    $v0, 0xd4($sp)
.Ljp7F0C5CA8:
/* 0FA818 7F0C5CA8 24010002 */  li    $at, 2
/* 0FA81C 7F0C5CAC 10410017 */  beq   $v0, $at, .Ljp7F0C5D0C
/* 0FA820 7F0C5CB0 000258C0 */   sll   $t3, $v0, 3
/* 0FA824 7F0C5CB4 01625823 */  subu  $t3, $t3, $v0
/* 0FA828 7F0C5CB8 3C0D8008 */  lui   $t5, %hi(player1_player_data) # $t5, 0x8008
/* 0FA82C 7F0C5CBC 25AD9F60 */  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x60a0
/* 0FA830 7F0C5CC0 000B5900 */  sll   $t3, $t3, 4
/* 0FA834 7F0C5CC4 016D7821 */  addu  $t7, $t3, $t5
/* 0FA838 7F0C5CC8 0C001145 */  jal   get_video2_settings_ulx
/* 0FA83C 7F0C5CCC AFAF0044 */   sw    $t7, 0x44($sp)
/* 0FA840 7F0C5CD0 00028400 */  sll   $s0, $v0, 0x10
/* 0FA844 7F0C5CD4 0010C403 */  sra   $t8, $s0, 0x10
/* 0FA848 7F0C5CD8 0C001149 */  jal   get_video2_settings_uly
/* 0FA84C 7F0C5CDC 03008025 */   move  $s0, $t8
/* 0FA850 7F0C5CE0 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FA854 7F0C5CE4 8FAC0044 */  lw    $t4, 0x44($sp)
/* 0FA858 7F0C5CE8 02202025 */  move  $a0, $s1
/* 0FA85C 7F0C5CEC 020E2821 */  addu  $a1, $s0, $t6
/* 0FA860 7F0C5CF0 8D87002C */  lw    $a3, 0x2c($t4)
/* 0FA864 7F0C5CF4 AFA00010 */  sw    $zero, 0x10($sp)
/* 0FA868 7F0C5CF8 24A50040 */  addiu $a1, $a1, 0x40
/* 0FA86C 7F0C5CFC 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA870 7F0C5D00 24460056 */   addiu $a2, $v0, 0x56
/* 0FA874 7F0C5D04 00408825 */  move  $s1, $v0
/* 0FA878 7F0C5D08 8FA200D4 */  lw    $v0, 0xd4($sp)
.Ljp7F0C5D0C:
/* 0FA87C 7F0C5D0C 8FB900D0 */  lw    $t9, 0xd0($sp)
/* 0FA880 7F0C5D10 24010004 */  li    $at, 4
/* 0FA884 7F0C5D14 17210018 */  bne   $t9, $at, .Ljp7F0C5D78
/* 0FA888 7F0C5D18 24010003 */   li    $at, 3
/* 0FA88C 7F0C5D1C 10410016 */  beq   $v0, $at, .Ljp7F0C5D78
/* 0FA890 7F0C5D20 000258C0 */   sll   $t3, $v0, 3
/* 0FA894 7F0C5D24 01625823 */  subu  $t3, $t3, $v0
/* 0FA898 7F0C5D28 3C0D8008 */  lui   $t5, %hi(player1_player_data) # $t5, 0x8008
/* 0FA89C 7F0C5D2C 25AD9F60 */  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x60a0
/* 0FA8A0 7F0C5D30 000B5900 */  sll   $t3, $t3, 4
/* 0FA8A4 7F0C5D34 016D7821 */  addu  $t7, $t3, $t5
/* 0FA8A8 7F0C5D38 0C001145 */  jal   get_video2_settings_ulx
/* 0FA8AC 7F0C5D3C AFAF0044 */   sw    $t7, 0x44($sp)
/* 0FA8B0 7F0C5D40 00028400 */  sll   $s0, $v0, 0x10
/* 0FA8B4 7F0C5D44 0010C403 */  sra   $t8, $s0, 0x10
/* 0FA8B8 7F0C5D48 0C001149 */  jal   get_video2_settings_uly
/* 0FA8BC 7F0C5D4C 03008025 */   move  $s0, $t8
/* 0FA8C0 7F0C5D50 8FAE00A8 */  lw    $t6, 0xa8($sp)
/* 0FA8C4 7F0C5D54 8FAC0044 */  lw    $t4, 0x44($sp)
/* 0FA8C8 7F0C5D58 02202025 */  move  $a0, $s1
/* 0FA8CC 7F0C5D5C 020E2821 */  addu  $a1, $s0, $t6
/* 0FA8D0 7F0C5D60 8D870030 */  lw    $a3, 0x30($t4)
/* 0FA8D4 7F0C5D64 AFA00010 */  sw    $zero, 0x10($sp)
/* 0FA8D8 7F0C5D68 24A50060 */  addiu $a1, $a1, 0x60
/* 0FA8DC 7F0C5D6C 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FA8E0 7F0C5D70 24460056 */   addiu $a2, $v0, 0x56
/* 0FA8E4 7F0C5D74 00408825 */  move  $s1, $v0
.Ljp7F0C5D78:
/* 0FA8E8 7F0C5D78 3C038008 */  lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0FA8EC 7F0C5D7C 1000029D */  b     .Ljp7F0C67F4
/* 0FA8F0 7F0C5D80 8C63A120 */   lw    $v1, %lo(pPlayer)($v1)
.Ljp7F0C5D84:
/* 0FA8F4 7F0C5D84 24010001 */  li    $at, 1
/* 0FA8F8 7F0C5D88 144101A9 */  bne   $v0, $at, .Ljp7F0C6430
/* 0FA8FC 7F0C5D8C 3C048009 */   lui   $a0, %hi(is_gameover_flag) # $a0, 0x8009
/* 0FA900 7F0C5D90 8C84C774 */  lw    $a0, %lo(is_gameover_flag)($a0)
/* 0FA904 7F0C5D94 2C990001 */  sltiu $t9, $a0, 1
/* 0FA908 7F0C5D98 13200005 */  beqz  $t9, .Ljp7F0C5DB0
/* 0FA90C 7F0C5D9C 03202025 */   move  $a0, $t9
/* 0FA910 7F0C5DA0 3C048009 */  lui   $a0, %hi(stop_play_flag) # $a0, 0x8009
/* 0FA914 7F0C5DA4 8C84C770 */  lw    $a0, %lo(stop_play_flag)($a0)
/* 0FA918 7F0C5DA8 2C8B0001 */  sltiu $t3, $a0, 1
/* 0FA91C 7F0C5DAC 01602025 */  move  $a0, $t3
.Ljp7F0C5DB0:
/* 0FA920 7F0C5DB0 0FC31303 */  jal   true_if_displaying_rank_in_mp
/* 0FA924 7F0C5DB4 00000000 */   nop   
/* 0FA928 7F0C5DB8 10400034 */  beqz  $v0, .Ljp7F0C5E8C
/* 0FA92C 7F0C5DBC 27A400AC */   addiu $a0, $sp, 0xac
/* 0FA930 7F0C5DC0 0FC31251 */  jal   write_playerrank_to_buffer
/* 0FA934 7F0C5DC4 8FA500D4 */   lw    $a1, 0xd4($sp)
/* 0FA938 7F0C5DC8 3C0D8004 */  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
/* 0FA93C 7F0C5DCC 8DAD0EDC */  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
/* 0FA940 7F0C5DD0 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0FA944 7F0C5DD4 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FA948 7F0C5DD8 27A400BC */  addiu $a0, $sp, 0xbc
/* 0FA94C 7F0C5DDC 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0FA950 7F0C5DE0 27A600AC */  addiu $a2, $sp, 0xac
/* 0FA954 7F0C5DE4 AFA00014 */  sw    $zero, 0x14($sp)
/* 0FA958 7F0C5DE8 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0FA95C 7F0C5DEC AFAD0010 */   sw    $t5, 0x10($sp)
/* 0FA960 7F0C5DF0 0C001145 */  jal   get_video2_settings_ulx
/* 0FA964 7F0C5DF4 00000000 */   nop   
/* 0FA968 7F0C5DF8 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0FA96C 7F0C5DFC 8FAE00C0 */  lw    $t6, 0xc0($sp)
/* 0FA970 7F0C5E00 004FC021 */  addu  $t8, $v0, $t7
/* 0FA974 7F0C5E04 000E6043 */  sra   $t4, $t6, 1
/* 0FA978 7F0C5E08 030C2023 */  subu  $a0, $t8, $t4
/* 0FA97C 7F0C5E0C 24840050 */  addiu $a0, $a0, 0x50
/* 0FA980 7F0C5E10 0C001149 */  jal   get_video2_settings_uly
/* 0FA984 7F0C5E14 AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FA988 7F0C5E18 8FB900BC */  lw    $t9, 0xbc($sp)
/* 0FA98C 7F0C5E1C 00195843 */  sra   $t3, $t9, 1
/* 0FA990 7F0C5E20 004B6823 */  subu  $t5, $v0, $t3
/* 0FA994 7F0C5E24 25AF0025 */  addiu $t7, $t5, 0x25
/* 0FA998 7F0C5E28 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FA99C 7F0C5E2C AFAF00C8 */   sw    $t7, 0xc8($sp)
/* 0FA9A0 7F0C5E30 00028400 */  sll   $s0, $v0, 0x10
/* 0FA9A4 7F0C5E34 00107403 */  sra   $t6, $s0, 0x10
/* 0FA9A8 7F0C5E38 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FA9AC 7F0C5E3C 01C08025 */   move  $s0, $t6
/* 0FA9B0 7F0C5E40 3C188004 */  lui   $t8, %hi(ptrSecondFontTableSmall) # $t8, 0x8004
/* 0FA9B4 7F0C5E44 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) # $t4, 0x8004
/* 0FA9B8 7F0C5E48 8D8C0EDC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0FA9BC 7F0C5E4C 8F180EE0 */  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
/* 0FA9C0 7F0C5E50 3C1900FF */  lui   $t9, (0x00FF00B0 >> 16) # lui $t9, 0xff
/* 0FA9C4 7F0C5E54 373900B0 */  ori   $t9, (0x00FF00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0FA9C8 7F0C5E58 AFB90018 */  sw    $t9, 0x18($sp)
/* 0FA9CC 7F0C5E5C 02202025 */  move  $a0, $s1
/* 0FA9D0 7F0C5E60 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FA9D4 7F0C5E64 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FA9D8 7F0C5E68 27A700AC */  addiu $a3, $sp, 0xac
/* 0FA9DC 7F0C5E6C AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FA9E0 7F0C5E70 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FA9E4 7F0C5E74 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FA9E8 7F0C5E78 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FA9EC 7F0C5E7C AFAC0014 */  sw    $t4, 0x14($sp)
/* 0FA9F0 7F0C5E80 0FC2B99B */  jal   en_text_write_stuff
/* 0FA9F4 7F0C5E84 AFB80010 */   sw    $t8, 0x10($sp)
/* 0FA9F8 7F0C5E88 00408825 */  move  $s1, $v0
.Ljp7F0C5E8C:
/* 0FA9FC 7F0C5E8C 0FC30AA2 */  jal   get_textptr_for_textID
/* 0FAA00 7F0C5E90 3404A01C */   li    $a0, 40988
/* 0FAA04 7F0C5E94 3404A01E */  li    $a0, 40990
/* 0FAA08 7F0C5E98 0FC30AA2 */  jal   get_textptr_for_textID
/* 0FAA0C 7F0C5E9C AFA2004C */   sw    $v0, 0x4c($sp)
/* 0FAA10 7F0C5EA0 8FA700D4 */  lw    $a3, 0xd4($sp)
/* 0FAA14 7F0C5EA4 3C058006 */  lui   $a1, %hi(ascii_pnum_LOSSES) # $a1, 0x8006
/* 0FAA18 7F0C5EA8 24A5BC78 */  addiu $a1, %lo(ascii_pnum_LOSSES) # addiu $a1, $a1, -0x4388
/* 0FAA1C 7F0C5EAC 8FA6004C */  lw    $a2, 0x4c($sp)
/* 0FAA20 7F0C5EB0 27A400AC */  addiu $a0, $sp, 0xac
/* 0FAA24 7F0C5EB4 AFA20010 */  sw    $v0, 0x10($sp)
/* 0FAA28 7F0C5EB8 0C002B29 */  jal   sprintf
/* 0FAA2C 7F0C5EBC 24E70001 */   addiu $a3, $a3, 1
/* 0FAA30 7F0C5EC0 3C0B8004 */  lui   $t3, %hi(ptrFirstFontTableSmall) # $t3, 0x8004
/* 0FAA34 7F0C5EC4 8D6B0EDC */  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
/* 0FAA38 7F0C5EC8 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0FAA3C 7F0C5ECC 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FAA40 7F0C5ED0 27A400BC */  addiu $a0, $sp, 0xbc
/* 0FAA44 7F0C5ED4 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0FAA48 7F0C5ED8 27A600AC */  addiu $a2, $sp, 0xac
/* 0FAA4C 7F0C5EDC AFA00014 */  sw    $zero, 0x14($sp)
/* 0FAA50 7F0C5EE0 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0FAA54 7F0C5EE4 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0FAA58 7F0C5EE8 0C001145 */  jal   get_video2_settings_ulx
/* 0FAA5C 7F0C5EEC 00000000 */   nop   
/* 0FAA60 7F0C5EF0 8FAD00A8 */  lw    $t5, 0xa8($sp)
/* 0FAA64 7F0C5EF4 8FAE00C0 */  lw    $t6, 0xc0($sp)
/* 0FAA68 7F0C5EF8 004D7821 */  addu  $t7, $v0, $t5
/* 0FAA6C 7F0C5EFC 000EC043 */  sra   $t8, $t6, 1
/* 0FAA70 7F0C5F00 01F82023 */  subu  $a0, $t7, $t8
/* 0FAA74 7F0C5F04 24840050 */  addiu $a0, $a0, 0x50
/* 0FAA78 7F0C5F08 0C001149 */  jal   get_video2_settings_uly
/* 0FAA7C 7F0C5F0C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FAA80 7F0C5F10 8FAC00BC */  lw    $t4, 0xbc($sp)
/* 0FAA84 7F0C5F14 000CC843 */  sra   $t9, $t4, 1
/* 0FAA88 7F0C5F18 00595823 */  subu  $t3, $v0, $t9
/* 0FAA8C 7F0C5F1C 256D0035 */  addiu $t5, $t3, 0x35
/* 0FAA90 7F0C5F20 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FAA94 7F0C5F24 AFAD00C8 */   sw    $t5, 0xc8($sp)
/* 0FAA98 7F0C5F28 00028400 */  sll   $s0, $v0, 0x10
/* 0FAA9C 7F0C5F2C 00107403 */  sra   $t6, $s0, 0x10
/* 0FAAA0 7F0C5F30 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FAAA4 7F0C5F34 01C08025 */   move  $s0, $t6
/* 0FAAA8 7F0C5F38 3C0F8004 */  lui   $t7, %hi(ptrSecondFontTableSmall) # $t7, 0x8004
/* 0FAAAC 7F0C5F3C 3C188004 */  lui   $t8, %hi(ptrFirstFontTableSmall) # $t8, 0x8004
/* 0FAAB0 7F0C5F40 8F180EDC */  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
/* 0FAAB4 7F0C5F44 8DEF0EE0 */  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
/* 0FAAB8 7F0C5F48 3C0CFF40 */  lui   $t4, (0xFF4040B0 >> 16) # lui $t4, 0xff40
/* 0FAABC 7F0C5F4C 358C40B0 */  ori   $t4, (0xFF4040B0 & 0xFFFF) # ori $t4, $t4, 0x40b0
/* 0FAAC0 7F0C5F50 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0FAAC4 7F0C5F54 02202025 */  move  $a0, $s1
/* 0FAAC8 7F0C5F58 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FAACC 7F0C5F5C 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FAAD0 7F0C5F60 27A700AC */  addiu $a3, $sp, 0xac
/* 0FAAD4 7F0C5F64 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FAAD8 7F0C5F68 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FAADC 7F0C5F6C AFA00024 */  sw    $zero, 0x24($sp)
/* 0FAAE0 7F0C5F70 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FAAE4 7F0C5F74 AFB80014 */  sw    $t8, 0x14($sp)
/* 0FAAE8 7F0C5F78 0FC2B99B */  jal   en_text_write_stuff
/* 0FAAEC 7F0C5F7C AFAF0010 */   sw    $t7, 0x10($sp)
/* 0FAAF0 7F0C5F80 8FB900D0 */  lw    $t9, 0xd0($sp)
/* 0FAAF4 7F0C5F84 24010002 */  li    $at, 2
/* 0FAAF8 7F0C5F88 00408825 */  move  $s1, $v0
/* 0FAAFC 7F0C5F8C 17210062 */  bne   $t9, $at, .Ljp7F0C6118
/* 0FAB00 7F0C5F90 8FAF00D4 */   lw    $t7, 0xd4($sp)
/* 0FAB04 7F0C5F94 8FA200D4 */  lw    $v0, 0xd4($sp)
/* 0FAB08 7F0C5F98 3C188008 */  lui   $t8, %hi(player1_player_data + 0x24) # $t8, 0x8008
/* 0FAB0C 7F0C5F9C 10400016 */  beqz  $v0, .Ljp7F0C5FF8
/* 0FAB10 7F0C5FA0 00000000 */   nop   
/* 0FAB14 7F0C5FA4 0C001145 */  jal   get_video2_settings_ulx
/* 0FAB18 7F0C5FA8 00000000 */   nop   
/* 0FAB1C 7F0C5FAC 00028400 */  sll   $s0, $v0, 0x10
/* 0FAB20 7F0C5FB0 00105C03 */  sra   $t3, $s0, 0x10
/* 0FAB24 7F0C5FB4 0C001149 */  jal   get_video2_settings_uly
/* 0FAB28 7F0C5FB8 01608025 */   move  $s0, $t3
/* 0FAB2C 7F0C5FBC 8FAE00D4 */  lw    $t6, 0xd4($sp)
/* 0FAB30 7F0C5FC0 8FAD00A8 */  lw    $t5, 0xa8($sp)
/* 0FAB34 7F0C5FC4 3C078008 */  lui   $a3, %hi(player1_player_data+36)
/* 0FAB38 7F0C5FC8 000E7880 */  sll   $t7, $t6, 2
/* 0FAB3C 7F0C5FCC 00EF3821 */  addu  $a3, $a3, $t7
/* 0FAB40 7F0C5FD0 020D2821 */  addu  $a1, $s0, $t5
/* 0FAB44 7F0C5FD4 24A50050 */  addiu $a1, $a1, 0x50
/* 0FAB48 7F0C5FD8 8CE79F84 */  lw    $a3, %lo(player1_player_data+36)($a3)
/* 0FAB4C 7F0C5FDC 02202025 */  move  $a0, $s1
/* 0FAB50 7F0C5FE0 24460046 */  addiu $a2, $v0, 0x46
/* 0FAB54 7F0C5FE4 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FAB58 7F0C5FE8 AFA00010 */   sw    $zero, 0x10($sp)
/* 0FAB5C 7F0C5FEC 00408825 */  move  $s1, $v0
/* 0FAB60 7F0C5FF0 10000019 */  b     .Ljp7F0C6058
/* 0FAB64 7F0C5FF4 8FA200D4 */   lw    $v0, 0xd4($sp)
.Ljp7F0C5FF8:
/* 0FAB68 7F0C5FF8 8F189F84 */  lw    $t8, %lo(player1_player_data + 0x24)($t8)
/* 0FAB6C 7F0C5FFC 5B000017 */  blezl $t8, .Ljp7F0C605C
/* 0FAB70 7F0C6000 24010001 */   li    $at, 1
/* 0FAB74 7F0C6004 0C001145 */  jal   get_video2_settings_ulx
/* 0FAB78 7F0C6008 00000000 */   nop   
/* 0FAB7C 7F0C600C 00028400 */  sll   $s0, $v0, 0x10
/* 0FAB80 7F0C6010 00106403 */  sra   $t4, $s0, 0x10
/* 0FAB84 7F0C6014 0C001149 */  jal   get_video2_settings_uly
/* 0FAB88 7F0C6018 01808025 */   move  $s0, $t4
/* 0FAB8C 7F0C601C 8FAB00D4 */  lw    $t3, 0xd4($sp)
/* 0FAB90 7F0C6020 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0FAB94 7F0C6024 3C078008 */  lui   $a3, %hi(player1_player_data+36)
/* 0FAB98 7F0C6028 000B6880 */  sll   $t5, $t3, 2
/* 0FAB9C 7F0C602C 00ED3821 */  addu  $a3, $a3, $t5
/* 0FABA0 7F0C6030 240E0003 */  li    $t6, 3
/* 0FABA4 7F0C6034 02192821 */  addu  $a1, $s0, $t9
/* 0FABA8 7F0C6038 24A50050 */  addiu $a1, $a1, 0x50
/* 0FABAC 7F0C603C AFAE0010 */  sw    $t6, 0x10($sp)
/* 0FABB0 7F0C6040 8CE79F84 */  lw    $a3, %lo(player1_player_data+36)($a3)
/* 0FABB4 7F0C6044 02202025 */  move  $a0, $s1
/* 0FABB8 7F0C6048 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FABBC 7F0C604C 24460046 */   addiu $a2, $v0, 0x46
/* 0FABC0 7F0C6050 00408825 */  move  $s1, $v0
/* 0FABC4 7F0C6054 8FA200D4 */  lw    $v0, 0xd4($sp)
.Ljp7F0C6058:
/* 0FABC8 7F0C6058 24010001 */  li    $at, 1
.Ljp7F0C605C:
/* 0FABCC 7F0C605C 10410016 */  beq   $v0, $at, .Ljp7F0C60B8
/* 0FABD0 7F0C6060 3C0E8008 */   lui   $t6, %hi(player2_player_data + 0x28) # $t6, 0x8008
/* 0FABD4 7F0C6064 3C188008 */  lui   $t8, %hi(player1_player_data) # $t8, 0x8008
/* 0FABD8 7F0C6068 27189F60 */  addiu $t8, %lo(player1_player_data) # addiu $t8, $t8, -0x60a0
/* 0FABDC 7F0C606C 00027880 */  sll   $t7, $v0, 2
/* 0FABE0 7F0C6070 01F86021 */  addu  $t4, $t7, $t8
/* 0FABE4 7F0C6074 0C001145 */  jal   get_video2_settings_ulx
/* 0FABE8 7F0C6078 AFAC0044 */   sw    $t4, 0x44($sp)
/* 0FABEC 7F0C607C 00028400 */  sll   $s0, $v0, 0x10
/* 0FABF0 7F0C6080 0010CC03 */  sra   $t9, $s0, 0x10
/* 0FABF4 7F0C6084 0C001149 */  jal   get_video2_settings_uly
/* 0FABF8 7F0C6088 03208025 */   move  $s0, $t9
/* 0FABFC 7F0C608C 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0FAC00 7F0C6090 8FAD0044 */  lw    $t5, 0x44($sp)
/* 0FAC04 7F0C6094 02202025 */  move  $a0, $s1
/* 0FAC08 7F0C6098 020B2821 */  addu  $a1, $s0, $t3
/* 0FAC0C 7F0C609C 8DA70094 */  lw    $a3, 0x94($t5)
/* 0FAC10 7F0C60A0 AFA00010 */  sw    $zero, 0x10($sp)
/* 0FAC14 7F0C60A4 24A50050 */  addiu $a1, $a1, 0x50
/* 0FAC18 7F0C60A8 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FAC1C 7F0C60AC 24460056 */   addiu $a2, $v0, 0x56
/* 0FAC20 7F0C60B0 100000DC */  b     .Ljp7F0C6424
/* 0FAC24 7F0C60B4 00408825 */   move  $s1, $v0
.Ljp7F0C60B8:
/* 0FAC28 7F0C60B8 8DCE9FF8 */  lw    $t6, %lo(player2_player_data + 0x28)($t6)
/* 0FAC2C 7F0C60BC 3C188008 */  lui   $t8, %hi(player1_player_data) # $t8, 0x8008
/* 0FAC30 7F0C60C0 27189F60 */  addiu $t8, %lo(player1_player_data) # addiu $t8, $t8, -0x60a0
/* 0FAC34 7F0C60C4 19C000D7 */  blez  $t6, .Ljp7F0C6424
/* 0FAC38 7F0C60C8 00027880 */   sll   $t7, $v0, 2
/* 0FAC3C 7F0C60CC 01F86021 */  addu  $t4, $t7, $t8
/* 0FAC40 7F0C60D0 0C001145 */  jal   get_video2_settings_ulx
/* 0FAC44 7F0C60D4 AFAC0044 */   sw    $t4, 0x44($sp)
/* 0FAC48 7F0C60D8 00028400 */  sll   $s0, $v0, 0x10
/* 0FAC4C 7F0C60DC 0010CC03 */  sra   $t9, $s0, 0x10
/* 0FAC50 7F0C60E0 0C001149 */  jal   get_video2_settings_uly
/* 0FAC54 7F0C60E4 03208025 */   move  $s0, $t9
/* 0FAC58 7F0C60E8 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0FAC5C 7F0C60EC 8FAD0044 */  lw    $t5, 0x44($sp)
/* 0FAC60 7F0C60F0 240E0003 */  li    $t6, 3
/* 0FAC64 7F0C60F4 020B2821 */  addu  $a1, $s0, $t3
/* 0FAC68 7F0C60F8 8DA70094 */  lw    $a3, 0x94($t5)
/* 0FAC6C 7F0C60FC AFAE0010 */  sw    $t6, 0x10($sp)
/* 0FAC70 7F0C6100 24A50050 */  addiu $a1, $a1, 0x50
/* 0FAC74 7F0C6104 02202025 */  move  $a0, $s1
/* 0FAC78 7F0C6108 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FAC7C 7F0C610C 24460056 */   addiu $a2, $v0, 0x56
/* 0FAC80 7F0C6110 100000C4 */  b     .Ljp7F0C6424
/* 0FAC84 7F0C6114 00408825 */   move  $s1, $v0
.Ljp7F0C6118:
/* 0FAC88 7F0C6118 11E00015 */  beqz  $t7, .Ljp7F0C6170
/* 0FAC8C 7F0C611C 3C0D8008 */   lui   $t5, %hi(player1_player_data + 0x24) # $t5, 0x8008
/* 0FAC90 7F0C6120 0C001145 */  jal   get_video2_settings_ulx
/* 0FAC94 7F0C6124 00000000 */   nop   
/* 0FAC98 7F0C6128 00028400 */  sll   $s0, $v0, 0x10
/* 0FAC9C 7F0C612C 0010C403 */  sra   $t8, $s0, 0x10
/* 0FACA0 7F0C6130 0C001149 */  jal   get_video2_settings_uly
/* 0FACA4 7F0C6134 03008025 */   move  $s0, $t8
/* 0FACA8 7F0C6138 8FB900D4 */  lw    $t9, 0xd4($sp)
/* 0FACAC 7F0C613C 8FAC00A8 */  lw    $t4, 0xa8($sp)
/* 0FACB0 7F0C6140 3C078008 */  lui   $a3, %hi(player1_player_data+36)
/* 0FACB4 7F0C6144 00195880 */  sll   $t3, $t9, 2
/* 0FACB8 7F0C6148 00EB3821 */  addu  $a3, $a3, $t3
/* 0FACBC 7F0C614C 020C2821 */  addu  $a1, $s0, $t4
/* 0FACC0 7F0C6150 24A50040 */  addiu $a1, $a1, 0x40
/* 0FACC4 7F0C6154 8CE79F84 */  lw    $a3, %lo(player1_player_data+36)($a3)
/* 0FACC8 7F0C6158 02202025 */  move  $a0, $s1
/* 0FACCC 7F0C615C 24460046 */  addiu $a2, $v0, 0x46
/* 0FACD0 7F0C6160 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FACD4 7F0C6164 AFA00010 */   sw    $zero, 0x10($sp)
/* 0FACD8 7F0C6168 10000018 */  b     .Ljp7F0C61CC
/* 0FACDC 7F0C616C 00408825 */   move  $s1, $v0
.Ljp7F0C6170:
/* 0FACE0 7F0C6170 8DAD9F84 */  lw    $t5, %lo(player1_player_data + 0x24)($t5)
/* 0FACE4 7F0C6174 59A00016 */  blezl $t5, .Ljp7F0C61D0
/* 0FACE8 7F0C6178 8FAB00D4 */   lw    $t3, 0xd4($sp)
/* 0FACEC 7F0C617C 0C001145 */  jal   get_video2_settings_ulx
/* 0FACF0 7F0C6180 00000000 */   nop   
/* 0FACF4 7F0C6184 00028400 */  sll   $s0, $v0, 0x10
/* 0FACF8 7F0C6188 00107403 */  sra   $t6, $s0, 0x10
/* 0FACFC 7F0C618C 0C001149 */  jal   get_video2_settings_uly
/* 0FAD00 7F0C6190 01C08025 */   move  $s0, $t6
/* 0FAD04 7F0C6194 8FB800D4 */  lw    $t8, 0xd4($sp)
/* 0FAD08 7F0C6198 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0FAD0C 7F0C619C 3C078008 */  lui   $a3, %hi(player1_player_data+36)
/* 0FAD10 7F0C61A0 00186080 */  sll   $t4, $t8, 2
/* 0FAD14 7F0C61A4 00EC3821 */  addu  $a3, $a3, $t4
/* 0FAD18 7F0C61A8 24190003 */  li    $t9, 3
/* 0FAD1C 7F0C61AC 020F2821 */  addu  $a1, $s0, $t7
/* 0FAD20 7F0C61B0 24A50040 */  addiu $a1, $a1, 0x40
/* 0FAD24 7F0C61B4 AFB90010 */  sw    $t9, 0x10($sp)
/* 0FAD28 7F0C61B8 8CE79F84 */  lw    $a3, %lo(player1_player_data+36)($a3)
/* 0FAD2C 7F0C61BC 02202025 */  move  $a0, $s1
/* 0FAD30 7F0C61C0 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FAD34 7F0C61C4 24460046 */   addiu $a2, $v0, 0x46
/* 0FAD38 7F0C61C8 00408825 */  move  $s1, $v0
.Ljp7F0C61CC:
/* 0FAD3C 7F0C61CC 8FAB00D4 */  lw    $t3, 0xd4($sp)
.Ljp7F0C61D0:
/* 0FAD40 7F0C61D0 24010001 */  li    $at, 1
/* 0FAD44 7F0C61D4 3C0E8008 */  lui   $t6, %hi(player1_player_data) # $t6, 0x8008
/* 0FAD48 7F0C61D8 11610014 */  beq   $t3, $at, .Ljp7F0C622C
/* 0FAD4C 7F0C61DC 000B6880 */   sll   $t5, $t3, 2
/* 0FAD50 7F0C61E0 25CE9F60 */  addiu $t6, %lo(player1_player_data) # addiu $t6, $t6, -0x60a0
/* 0FAD54 7F0C61E4 01AE7821 */  addu  $t7, $t5, $t6
/* 0FAD58 7F0C61E8 0C001145 */  jal   get_video2_settings_ulx
/* 0FAD5C 7F0C61EC AFAF0044 */   sw    $t7, 0x44($sp)
/* 0FAD60 7F0C61F0 00028400 */  sll   $s0, $v0, 0x10
/* 0FAD64 7F0C61F4 0010C403 */  sra   $t8, $s0, 0x10
/* 0FAD68 7F0C61F8 0C001149 */  jal   get_video2_settings_uly
/* 0FAD6C 7F0C61FC 03008025 */   move  $s0, $t8
/* 0FAD70 7F0C6200 8FAC00A8 */  lw    $t4, 0xa8($sp)
/* 0FAD74 7F0C6204 8FB90044 */  lw    $t9, 0x44($sp)
/* 0FAD78 7F0C6208 02202025 */  move  $a0, $s1
/* 0FAD7C 7F0C620C 020C2821 */  addu  $a1, $s0, $t4
/* 0FAD80 7F0C6210 8F270094 */  lw    $a3, 0x94($t9)
/* 0FAD84 7F0C6214 AFA00010 */  sw    $zero, 0x10($sp)
/* 0FAD88 7F0C6218 24A50060 */  addiu $a1, $a1, 0x60
/* 0FAD8C 7F0C621C 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FAD90 7F0C6220 24460046 */   addiu $a2, $v0, 0x46
/* 0FAD94 7F0C6224 1000001A */  b     .Ljp7F0C6290
/* 0FAD98 7F0C6228 00408825 */   move  $s1, $v0
.Ljp7F0C622C:
/* 0FAD9C 7F0C622C 3C0B8008 */  lui   $t3, %hi(player2_player_data + 0x28) # $t3, 0x8008
/* 0FADA0 7F0C6230 8D6B9FF8 */  lw    $t3, %lo(player2_player_data + 0x28)($t3)
/* 0FADA4 7F0C6234 8FAD00D4 */  lw    $t5, 0xd4($sp)
/* 0FADA8 7F0C6238 3C0F8008 */  lui   $t7, %hi(player1_player_data) # $t7, 0x8008
/* 0FADAC 7F0C623C 19600014 */  blez  $t3, .Ljp7F0C6290
/* 0FADB0 7F0C6240 000D7080 */   sll   $t6, $t5, 2
/* 0FADB4 7F0C6244 25EF9F60 */  addiu $t7, %lo(player1_player_data) # addiu $t7, $t7, -0x60a0
/* 0FADB8 7F0C6248 01CFC021 */  addu  $t8, $t6, $t7
/* 0FADBC 7F0C624C 0C001145 */  jal   get_video2_settings_ulx
/* 0FADC0 7F0C6250 AFB80044 */   sw    $t8, 0x44($sp)
/* 0FADC4 7F0C6254 00028400 */  sll   $s0, $v0, 0x10
/* 0FADC8 7F0C6258 00106403 */  sra   $t4, $s0, 0x10
/* 0FADCC 7F0C625C 0C001149 */  jal   get_video2_settings_uly
/* 0FADD0 7F0C6260 01808025 */   move  $s0, $t4
/* 0FADD4 7F0C6264 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0FADD8 7F0C6268 8FAB0044 */  lw    $t3, 0x44($sp)
/* 0FADDC 7F0C626C 240D0003 */  li    $t5, 3
/* 0FADE0 7F0C6270 02192821 */  addu  $a1, $s0, $t9
/* 0FADE4 7F0C6274 8D670094 */  lw    $a3, 0x94($t3)
/* 0FADE8 7F0C6278 AFAD0010 */  sw    $t5, 0x10($sp)
/* 0FADEC 7F0C627C 24A50060 */  addiu $a1, $a1, 0x60
/* 0FADF0 7F0C6280 02202025 */  move  $a0, $s1
/* 0FADF4 7F0C6284 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FADF8 7F0C6288 24460046 */   addiu $a2, $v0, 0x46
/* 0FADFC 7F0C628C 00408825 */  move  $s1, $v0
.Ljp7F0C6290:
/* 0FAE00 7F0C6290 8FAE00D4 */  lw    $t6, 0xd4($sp)
/* 0FAE04 7F0C6294 24010002 */  li    $at, 2
/* 0FAE08 7F0C6298 3C188008 */  lui   $t8, %hi(player1_player_data) # $t8, 0x8008
/* 0FAE0C 7F0C629C 11C10014 */  beq   $t6, $at, .Ljp7F0C62F0
/* 0FAE10 7F0C62A0 000E7880 */   sll   $t7, $t6, 2
/* 0FAE14 7F0C62A4 27189F60 */  addiu $t8, %lo(player1_player_data) # addiu $t8, $t8, -0x60a0
/* 0FAE18 7F0C62A8 01F86021 */  addu  $t4, $t7, $t8
/* 0FAE1C 7F0C62AC 0C001145 */  jal   get_video2_settings_ulx
/* 0FAE20 7F0C62B0 AFAC0044 */   sw    $t4, 0x44($sp)
/* 0FAE24 7F0C62B4 00028400 */  sll   $s0, $v0, 0x10
/* 0FAE28 7F0C62B8 0010CC03 */  sra   $t9, $s0, 0x10
/* 0FAE2C 7F0C62BC 0C001149 */  jal   get_video2_settings_uly
/* 0FAE30 7F0C62C0 03208025 */   move  $s0, $t9
/* 0FAE34 7F0C62C4 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0FAE38 7F0C62C8 8FAD0044 */  lw    $t5, 0x44($sp)
/* 0FAE3C 7F0C62CC 02202025 */  move  $a0, $s1
/* 0FAE40 7F0C62D0 020B2821 */  addu  $a1, $s0, $t3
/* 0FAE44 7F0C62D4 8DA70104 */  lw    $a3, 0x104($t5)
/* 0FAE48 7F0C62D8 AFA00010 */  sw    $zero, 0x10($sp)
/* 0FAE4C 7F0C62DC 24A50040 */  addiu $a1, $a1, 0x40
/* 0FAE50 7F0C62E0 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FAE54 7F0C62E4 24460056 */   addiu $a2, $v0, 0x56
/* 0FAE58 7F0C62E8 1000001A */  b     .Ljp7F0C6354
/* 0FAE5C 7F0C62EC 00408825 */   move  $s1, $v0
.Ljp7F0C62F0:
/* 0FAE60 7F0C62F0 3C0E8008 */  lui   $t6, %hi(player3_player_data + 0x2C) # $t6, 0x8008
/* 0FAE64 7F0C62F4 8DCEA06C */  lw    $t6, %lo(player3_player_data + 0x2C)($t6)
/* 0FAE68 7F0C62F8 8FAF00D4 */  lw    $t7, 0xd4($sp)
/* 0FAE6C 7F0C62FC 3C0C8008 */  lui   $t4, %hi(player1_player_data) # $t4, 0x8008
/* 0FAE70 7F0C6300 19C00014 */  blez  $t6, .Ljp7F0C6354
/* 0FAE74 7F0C6304 000FC080 */   sll   $t8, $t7, 2
/* 0FAE78 7F0C6308 258C9F60 */  addiu $t4, %lo(player1_player_data) # addiu $t4, $t4, -0x60a0
/* 0FAE7C 7F0C630C 030CC821 */  addu  $t9, $t8, $t4
/* 0FAE80 7F0C6310 0C001145 */  jal   get_video2_settings_ulx
/* 0FAE84 7F0C6314 AFB90044 */   sw    $t9, 0x44($sp)
/* 0FAE88 7F0C6318 00028400 */  sll   $s0, $v0, 0x10
/* 0FAE8C 7F0C631C 00105C03 */  sra   $t3, $s0, 0x10
/* 0FAE90 7F0C6320 0C001149 */  jal   get_video2_settings_uly
/* 0FAE94 7F0C6324 01608025 */   move  $s0, $t3
/* 0FAE98 7F0C6328 8FAD00A8 */  lw    $t5, 0xa8($sp)
/* 0FAE9C 7F0C632C 8FAE0044 */  lw    $t6, 0x44($sp)
/* 0FAEA0 7F0C6330 240F0003 */  li    $t7, 3
/* 0FAEA4 7F0C6334 020D2821 */  addu  $a1, $s0, $t5
/* 0FAEA8 7F0C6338 8DC70104 */  lw    $a3, 0x104($t6)
/* 0FAEAC 7F0C633C AFAF0010 */  sw    $t7, 0x10($sp)
/* 0FAEB0 7F0C6340 24A50040 */  addiu $a1, $a1, 0x40
/* 0FAEB4 7F0C6344 02202025 */  move  $a0, $s1
/* 0FAEB8 7F0C6348 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FAEBC 7F0C634C 24460056 */   addiu $a2, $v0, 0x56
/* 0FAEC0 7F0C6350 00408825 */  move  $s1, $v0
.Ljp7F0C6354:
/* 0FAEC4 7F0C6354 8FB800D0 */  lw    $t8, 0xd0($sp)
/* 0FAEC8 7F0C6358 24010004 */  li    $at, 4
/* 0FAECC 7F0C635C 8FAC00D4 */  lw    $t4, 0xd4($sp)
/* 0FAED0 7F0C6360 17010030 */  bne   $t8, $at, .Ljp7F0C6424
/* 0FAED4 7F0C6364 24010003 */   li    $at, 3
/* 0FAED8 7F0C6368 11810015 */  beq   $t4, $at, .Ljp7F0C63C0
/* 0FAEDC 7F0C636C 000CC880 */   sll   $t9, $t4, 2
/* 0FAEE0 7F0C6370 3C0B8008 */  lui   $t3, %hi(player1_player_data) # $t3, 0x8008
/* 0FAEE4 7F0C6374 256B9F60 */  addiu $t3, %lo(player1_player_data) # addiu $t3, $t3, -0x60a0
/* 0FAEE8 7F0C6378 032B6821 */  addu  $t5, $t9, $t3
/* 0FAEEC 7F0C637C 0C001145 */  jal   get_video2_settings_ulx
/* 0FAEF0 7F0C6380 AFAD0044 */   sw    $t5, 0x44($sp)
/* 0FAEF4 7F0C6384 00028400 */  sll   $s0, $v0, 0x10
/* 0FAEF8 7F0C6388 00107403 */  sra   $t6, $s0, 0x10
/* 0FAEFC 7F0C638C 0C001149 */  jal   get_video2_settings_uly
/* 0FAF00 7F0C6390 01C08025 */   move  $s0, $t6
/* 0FAF04 7F0C6394 8FAF00A8 */  lw    $t7, 0xa8($sp)
/* 0FAF08 7F0C6398 8FB80044 */  lw    $t8, 0x44($sp)
/* 0FAF0C 7F0C639C 02202025 */  move  $a0, $s1
/* 0FAF10 7F0C63A0 020F2821 */  addu  $a1, $s0, $t7
/* 0FAF14 7F0C63A4 8F070174 */  lw    $a3, 0x174($t8)
/* 0FAF18 7F0C63A8 AFA00010 */  sw    $zero, 0x10($sp)
/* 0FAF1C 7F0C63AC 24A50060 */  addiu $a1, $a1, 0x60
/* 0FAF20 7F0C63B0 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FAF24 7F0C63B4 24460056 */   addiu $a2, $v0, 0x56
/* 0FAF28 7F0C63B8 1000001A */  b     .Ljp7F0C6424
/* 0FAF2C 7F0C63BC 00408825 */   move  $s1, $v0
.Ljp7F0C63C0:
/* 0FAF30 7F0C63C0 3C0C8008 */  lui   $t4, %hi(player4_player_data+0x30) # $t4, 0x8008
/* 0FAF34 7F0C63C4 8D8CA0E0 */  lw    $t4, %lo(player4_player_data+0x30)($t4)
/* 0FAF38 7F0C63C8 8FB900D4 */  lw    $t9, 0xd4($sp)
/* 0FAF3C 7F0C63CC 3C0D8008 */  lui   $t5, %hi(player1_player_data) # $t5, 0x8008
/* 0FAF40 7F0C63D0 19800014 */  blez  $t4, .Ljp7F0C6424
/* 0FAF44 7F0C63D4 00195880 */   sll   $t3, $t9, 2
/* 0FAF48 7F0C63D8 25AD9F60 */  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x60a0
/* 0FAF4C 7F0C63DC 016D7021 */  addu  $t6, $t3, $t5
/* 0FAF50 7F0C63E0 0C001145 */  jal   get_video2_settings_ulx
/* 0FAF54 7F0C63E4 AFAE0044 */   sw    $t6, 0x44($sp)
/* 0FAF58 7F0C63E8 00028400 */  sll   $s0, $v0, 0x10
/* 0FAF5C 7F0C63EC 00107C03 */  sra   $t7, $s0, 0x10
/* 0FAF60 7F0C63F0 0C001149 */  jal   get_video2_settings_uly
/* 0FAF64 7F0C63F4 01E08025 */   move  $s0, $t7
/* 0FAF68 7F0C63F8 8FB800A8 */  lw    $t8, 0xa8($sp)
/* 0FAF6C 7F0C63FC 8FAC0044 */  lw    $t4, 0x44($sp)
/* 0FAF70 7F0C6400 24190003 */  li    $t9, 3
/* 0FAF74 7F0C6404 02182821 */  addu  $a1, $s0, $t8
/* 0FAF78 7F0C6408 8D870174 */  lw    $a3, 0x174($t4)
/* 0FAF7C 7F0C640C AFB90010 */  sw    $t9, 0x10($sp)
/* 0FAF80 7F0C6410 24A50060 */  addiu $a1, $a1, 0x60
/* 0FAF84 7F0C6414 02202025 */  move  $a0, $s1
/* 0FAF88 7F0C6418 0FC31094 */  jal   display_text_for_playerdata_on_MP_menu
/* 0FAF8C 7F0C641C 24460056 */   addiu $a2, $v0, 0x56
/* 0FAF90 7F0C6420 00408825 */  move  $s1, $v0
.Ljp7F0C6424:
/* 0FAF94 7F0C6424 3C038008 */  lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0FAF98 7F0C6428 100000F2 */  b     .Ljp7F0C67F4
/* 0FAF9C 7F0C642C 8C63A120 */   lw    $v1, %lo(pPlayer)($v1)
.Ljp7F0C6430:
/* 0FAFA0 7F0C6430 544000F1 */  bnezl $v0, .Ljp7F0C67F8
/* 0FAFA4 7F0C6434 8C6D29C8 */   lw    $t5, 0x29c8($v1)
/* 0FAFA8 7F0C6438 8FAD00D0 */  lw    $t5, 0xd0($sp)
/* 0FAFAC 7F0C643C 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0FAFB0 7F0C6440 29A10003 */  slti  $at, $t5, 3
/* 0FAFB4 7F0C6444 1420000A */  bnez  $at, .Ljp7F0C6470
/* 0FAFB8 7F0C6448 AFAB0074 */   sw    $t3, 0x74($sp)
/* 0FAFBC 7F0C644C 8FAE00D4 */  lw    $t6, 0xd4($sp)
/* 0FAFC0 7F0C6450 8FAC00A8 */  lw    $t4, 0xa8($sp)
/* 0FAFC4 7F0C6454 2578FFF9 */  addiu $t8, $t3, -7
/* 0FAFC8 7F0C6458 31CF0001 */  andi  $t7, $t6, 1
/* 0FAFCC 7F0C645C 11E00003 */  beqz  $t7, .Ljp7F0C646C
/* 0FAFD0 7F0C6460 25990007 */   addiu $t9, $t4, 7
/* 0FAFD4 7F0C6464 10000002 */  b     .Ljp7F0C6470
/* 0FAFD8 7F0C6468 AFB80074 */   sw    $t8, 0x74($sp)
.Ljp7F0C646C:
/* 0FAFDC 7F0C646C AFB90074 */  sw    $t9, 0x74($sp)
.Ljp7F0C6470:
/* 0FAFE0 7F0C6470 0FC30AA2 */  jal   get_textptr_for_textID
/* 0FAFE4 7F0C6474 3404A01F */   li    $a0, 40991
/* 0FAFE8 7F0C6478 3C0D8004 */  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
/* 0FAFEC 7F0C647C 8DAD0EDC */  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
/* 0FAFF0 7F0C6480 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0FAFF4 7F0C6484 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0FAFF8 7F0C6488 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FAFFC 7F0C648C 27A4007C */  addiu $a0, $sp, 0x7c
/* 0FB000 7F0C6490 27A50078 */  addiu $a1, $sp, 0x78
/* 0FB004 7F0C6494 00403025 */  move  $a2, $v0
/* 0FB008 7F0C6498 AFA00014 */  sw    $zero, 0x14($sp)
/* 0FB00C 7F0C649C 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0FB010 7F0C64A0 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0FB014 7F0C64A4 0C001145 */  jal   get_video2_settings_ulx
/* 0FB018 7F0C64A8 00000000 */   nop   
/* 0FB01C 7F0C64AC 8FAE0074 */  lw    $t6, 0x74($sp)
/* 0FB020 7F0C64B0 8FAB0078 */  lw    $t3, 0x78($sp)
/* 0FB024 7F0C64B4 004E7821 */  addu  $t7, $v0, $t6
/* 0FB028 7F0C64B8 000BC043 */  sra   $t8, $t3, 1
/* 0FB02C 7F0C64BC 01F82023 */  subu  $a0, $t7, $t8
/* 0FB030 7F0C64C0 24840050 */  addiu $a0, $a0, 0x50
/* 0FB034 7F0C64C4 0C001149 */  jal   get_video2_settings_uly
/* 0FB038 7F0C64C8 AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FB03C 7F0C64CC 8FAC007C */  lw    $t4, 0x7c($sp)
/* 0FB040 7F0C64D0 000CC843 */  sra   $t9, $t4, 1
/* 0FB044 7F0C64D4 00596823 */  subu  $t5, $v0, $t9
/* 0FB048 7F0C64D8 25AE0025 */  addiu $t6, $t5, 0x25
/* 0FB04C 7F0C64DC 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FB050 7F0C64E0 AFAE00C8 */   sw    $t6, 0xc8($sp)
/* 0FB054 7F0C64E4 00028400 */  sll   $s0, $v0, 0x10
/* 0FB058 7F0C64E8 00105C03 */  sra   $t3, $s0, 0x10
/* 0FB05C 7F0C64EC 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FB060 7F0C64F0 01608025 */   move  $s0, $t3
/* 0FB064 7F0C64F4 3C0F8004 */  lui   $t7, %hi(ptrSecondFontTableSmall) # $t7, 0x8004
/* 0FB068 7F0C64F8 3C188004 */  lui   $t8, %hi(ptrFirstFontTableSmall) # $t8, 0x8004
/* 0FB06C 7F0C64FC 8F180EDC */  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
/* 0FB070 7F0C6500 8DEF0EE0 */  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
/* 0FB074 7F0C6504 3C0C00FF */  lui   $t4, (0x00FF00B0 >> 16) # lui $t4, 0xff
/* 0FB078 7F0C6508 358C00B0 */  ori   $t4, (0x00FF00B0 & 0xFFFF) # ori $t4, $t4, 0xb0
/* 0FB07C 7F0C650C AFAC0018 */  sw    $t4, 0x18($sp)
/* 0FB080 7F0C6510 02202025 */  move  $a0, $s1
/* 0FB084 7F0C6514 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FB088 7F0C6518 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FB08C 7F0C651C 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FB090 7F0C6520 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FB094 7F0C6524 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FB098 7F0C6528 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FB09C 7F0C652C AFA00028 */  sw    $zero, 0x28($sp)
/* 0FB0A0 7F0C6530 AFB80014 */  sw    $t8, 0x14($sp)
/* 0FB0A4 7F0C6534 0FC2B99B */  jal   en_text_write_stuff
/* 0FB0A8 7F0C6538 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0FB0AC 7F0C653C 00408825 */  move  $s1, $v0
/* 0FB0B0 7F0C6540 8FA400D4 */  lw    $a0, 0xd4($sp)
/* 0FB0B4 7F0C6544 0FC026DC */  jal   getplayerfavoredweapon
/* 0FB0B8 7F0C6548 00002825 */   move  $a1, $zero
/* 0FB0BC 7F0C654C 3C198004 */  lui   $t9, %hi(ptrFirstFontTableSmall) # $t9, 0x8004
/* 0FB0C0 7F0C6550 8F390EDC */  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
/* 0FB0C4 7F0C6554 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0FB0C8 7F0C6558 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0FB0CC 7F0C655C 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FB0D0 7F0C6560 27A4007C */  addiu $a0, $sp, 0x7c
/* 0FB0D4 7F0C6564 27A50078 */  addiu $a1, $sp, 0x78
/* 0FB0D8 7F0C6568 00403025 */  move  $a2, $v0
/* 0FB0DC 7F0C656C AFA00014 */  sw    $zero, 0x14($sp)
/* 0FB0E0 7F0C6570 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0FB0E4 7F0C6574 AFB90010 */   sw    $t9, 0x10($sp)
/* 0FB0E8 7F0C6578 0C001145 */  jal   get_video2_settings_ulx
/* 0FB0EC 7F0C657C 00000000 */   nop   
/* 0FB0F0 7F0C6580 8FAD0074 */  lw    $t5, 0x74($sp)
/* 0FB0F4 7F0C6584 8FAB0078 */  lw    $t3, 0x78($sp)
/* 0FB0F8 7F0C6588 004D7021 */  addu  $t6, $v0, $t5
/* 0FB0FC 7F0C658C 000B7843 */  sra   $t7, $t3, 1
/* 0FB100 7F0C6590 01CF2023 */  subu  $a0, $t6, $t7
/* 0FB104 7F0C6594 24840050 */  addiu $a0, $a0, 0x50
/* 0FB108 7F0C6598 0C001149 */  jal   get_video2_settings_uly
/* 0FB10C 7F0C659C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FB110 7F0C65A0 3C0C8005 */  lui   $t4, %hi(j_text_trigger) # $t4, 0x8005
/* 0FB114 7F0C65A4 8D8C8500 */  lw    $t4, %lo(j_text_trigger)($t4)
/* 0FB118 7F0C65A8 00024400 */  sll   $t0, $v0, 0x10
/* 0FB11C 7F0C65AC 0008C403 */  sra   $t8, $t0, 0x10
/* 0FB120 7F0C65B0 11800003 */  beqz  $t4, .Ljp7F0C65C0
/* 0FB124 7F0C65B4 03004025 */   move  $t0, $t8
/* 0FB128 7F0C65B8 10000002 */  b     .Ljp7F0C65C4
/* 0FB12C 7F0C65BC 24040004 */   li    $a0, 4
.Ljp7F0C65C0:
/* 0FB130 7F0C65C0 00002025 */  move  $a0, $zero
.Ljp7F0C65C4:
/* 0FB134 7F0C65C4 8FAD007C */  lw    $t5, 0x7c($sp)
/* 0FB138 7F0C65C8 0088C821 */  addu  $t9, $a0, $t0
/* 0FB13C 7F0C65CC 000D5843 */  sra   $t3, $t5, 1
/* 0FB140 7F0C65D0 032B7023 */  subu  $t6, $t9, $t3
/* 0FB144 7F0C65D4 25CF0035 */  addiu $t7, $t6, 0x35
/* 0FB148 7F0C65D8 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FB14C 7F0C65DC AFAF00C8 */   sw    $t7, 0xc8($sp)
/* 0FB150 7F0C65E0 00028400 */  sll   $s0, $v0, 0x10
/* 0FB154 7F0C65E4 0010C403 */  sra   $t8, $s0, 0x10
/* 0FB158 7F0C65E8 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FB15C 7F0C65EC 03008025 */   move  $s0, $t8
/* 0FB160 7F0C65F0 3C0C8004 */  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
/* 0FB164 7F0C65F4 3C0D8004 */  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
/* 0FB168 7F0C65F8 8DAD0EDC */  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
/* 0FB16C 7F0C65FC 8D8C0EE0 */  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
/* 0FB170 7F0C6600 3C1900FF */  lui   $t9, (0x00FF00B0 >> 16) # lui $t9, 0xff
/* 0FB174 7F0C6604 373900B0 */  ori   $t9, (0x00FF00B0 & 0xFFFF) # ori $t9, $t9, 0xb0
/* 0FB178 7F0C6608 AFB90018 */  sw    $t9, 0x18($sp)
/* 0FB17C 7F0C660C 02202025 */  move  $a0, $s1
/* 0FB180 7F0C6610 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FB184 7F0C6614 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FB188 7F0C6618 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FB18C 7F0C661C AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FB190 7F0C6620 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FB194 7F0C6624 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FB198 7F0C6628 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FB19C 7F0C662C AFAD0014 */  sw    $t5, 0x14($sp)
/* 0FB1A0 7F0C6630 0FC2B99B */  jal   en_text_write_stuff
/* 0FB1A4 7F0C6634 AFAC0010 */   sw    $t4, 0x10($sp)
/* 0FB1A8 7F0C6638 3C038008 */  lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0FB1AC 7F0C663C 8C63A120 */  lw    $v1, %lo(pPlayer)($v1)
/* 0FB1B0 7F0C6640 00408825 */  move  $s1, $v0
/* 0FB1B4 7F0C6644 27A4007C */  addiu $a0, $sp, 0x7c
/* 0FB1B8 7F0C6648 8C682A10 */  lw    $t0, 0x2a10($v1)
/* 0FB1BC 7F0C664C 27A50078 */  addiu $a1, $sp, 0x78
/* 0FB1C0 7F0C6650 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0FB1C4 7F0C6654 11000031 */  beqz  $t0, .Ljp7F0C671C
/* 0FB1C8 7F0C6658 01003025 */   move  $a2, $t0
/* 0FB1CC 7F0C665C 3C0B8004 */  lui   $t3, %hi(ptrFirstFontTableSmall) # $t3, 0x8004
/* 0FB1D0 7F0C6660 8D6B0EDC */  lw    $t3, %lo(ptrFirstFontTableSmall)($t3)
/* 0FB1D4 7F0C6664 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FB1D8 7F0C6668 AFA00014 */  sw    $zero, 0x14($sp)
/* 0FB1DC 7F0C666C AFA800A4 */  sw    $t0, 0xa4($sp)
/* 0FB1E0 7F0C6670 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0FB1E4 7F0C6674 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0FB1E8 7F0C6678 0C001145 */  jal   get_video2_settings_ulx
/* 0FB1EC 7F0C667C 00000000 */   nop   
/* 0FB1F0 7F0C6680 8FAE0074 */  lw    $t6, 0x74($sp)
/* 0FB1F4 7F0C6684 8FB80078 */  lw    $t8, 0x78($sp)
/* 0FB1F8 7F0C6688 004E7821 */  addu  $t7, $v0, $t6
/* 0FB1FC 7F0C668C 00186043 */  sra   $t4, $t8, 1
/* 0FB200 7F0C6690 01EC2023 */  subu  $a0, $t7, $t4
/* 0FB204 7F0C6694 24840050 */  addiu $a0, $a0, 0x50
/* 0FB208 7F0C6698 0C001149 */  jal   get_video2_settings_uly
/* 0FB20C 7F0C669C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FB210 7F0C66A0 8FAD007C */  lw    $t5, 0x7c($sp)
/* 0FB214 7F0C66A4 000DC843 */  sra   $t9, $t5, 1
/* 0FB218 7F0C66A8 00595823 */  subu  $t3, $v0, $t9
/* 0FB21C 7F0C66AC 256E004B */  addiu $t6, $t3, 0x4b
/* 0FB220 7F0C66B0 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FB224 7F0C66B4 AFAE00C8 */   sw    $t6, 0xc8($sp)
/* 0FB228 7F0C66B8 00028400 */  sll   $s0, $v0, 0x10
/* 0FB22C 7F0C66BC 0010C403 */  sra   $t8, $s0, 0x10
/* 0FB230 7F0C66C0 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FB234 7F0C66C4 03008025 */   move  $s0, $t8
/* 0FB238 7F0C66C8 3C0F8004 */  lui   $t7, %hi(ptrSecondFontTableSmall) # $t7, 0x8004
/* 0FB23C 7F0C66CC 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) # $t4, 0x8004
/* 0FB240 7F0C66D0 8D8C0EDC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0FB244 7F0C66D4 8DEF0EE0 */  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
/* 0FB248 7F0C66D8 3C0D00FF */  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
/* 0FB24C 7F0C66DC 35AD00B0 */  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0FB250 7F0C66E0 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0FB254 7F0C66E4 02202025 */  move  $a0, $s1
/* 0FB258 7F0C66E8 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FB25C 7F0C66EC 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FB260 7F0C66F0 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FB264 7F0C66F4 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FB268 7F0C66F8 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FB26C 7F0C66FC AFA00024 */  sw    $zero, 0x24($sp)
/* 0FB270 7F0C6700 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FB274 7F0C6704 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0FB278 7F0C6708 0FC2B99B */  jal   en_text_write_stuff
/* 0FB27C 7F0C670C AFAF0010 */   sw    $t7, 0x10($sp)
/* 0FB280 7F0C6710 3C038008 */  lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0FB284 7F0C6714 8C63A120 */  lw    $v1, %lo(pPlayer)($v1)
/* 0FB288 7F0C6718 00408825 */  move  $s1, $v0
.Ljp7F0C671C:
/* 0FB28C 7F0C671C 8C622A14 */  lw    $v0, 0x2a14($v1)
/* 0FB290 7F0C6720 27A4007C */  addiu $a0, $sp, 0x7c
/* 0FB294 7F0C6724 27A50078 */  addiu $a1, $sp, 0x78
/* 0FB298 7F0C6728 10400032 */  beqz  $v0, .Ljp7F0C67F4
/* 0FB29C 7F0C672C 00403025 */   move  $a2, $v0
/* 0FB2A0 7F0C6730 3C198004 */  lui   $t9, %hi(ptrFirstFontTableSmall) # $t9, 0x8004
/* 0FB2A4 7F0C6734 8F390EDC */  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
/* 0FB2A8 7F0C6738 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0FB2AC 7F0C673C 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FB2B0 7F0C6740 AFA00014 */  sw    $zero, 0x14($sp)
/* 0FB2B4 7F0C6744 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0FB2B8 7F0C6748 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0FB2BC 7F0C674C AFB90010 */   sw    $t9, 0x10($sp)
/* 0FB2C0 7F0C6750 0C001145 */  jal   get_video2_settings_ulx
/* 0FB2C4 7F0C6754 00000000 */   nop   
/* 0FB2C8 7F0C6758 8FAB0074 */  lw    $t3, 0x74($sp)
/* 0FB2CC 7F0C675C 8FB80078 */  lw    $t8, 0x78($sp)
/* 0FB2D0 7F0C6760 004B7021 */  addu  $t6, $v0, $t3
/* 0FB2D4 7F0C6764 00187843 */  sra   $t7, $t8, 1
/* 0FB2D8 7F0C6768 01CF2023 */  subu  $a0, $t6, $t7
/* 0FB2DC 7F0C676C 24840050 */  addiu $a0, $a0, 0x50
/* 0FB2E0 7F0C6770 0C001149 */  jal   get_video2_settings_uly
/* 0FB2E4 7F0C6774 AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FB2E8 7F0C6778 8FAC007C */  lw    $t4, 0x7c($sp)
/* 0FB2EC 7F0C677C 000C6843 */  sra   $t5, $t4, 1
/* 0FB2F0 7F0C6780 004DC823 */  subu  $t9, $v0, $t5
/* 0FB2F4 7F0C6784 272B0058 */  addiu $t3, $t9, 0x58
/* 0FB2F8 7F0C6788 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FB2FC 7F0C678C AFAB00C8 */   sw    $t3, 0xc8($sp)
/* 0FB300 7F0C6790 00028400 */  sll   $s0, $v0, 0x10
/* 0FB304 7F0C6794 0010C403 */  sra   $t8, $s0, 0x10
/* 0FB308 7F0C6798 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FB30C 7F0C679C 03008025 */   move  $s0, $t8
/* 0FB310 7F0C67A0 3C0E8004 */  lui   $t6, %hi(ptrSecondFontTableSmall) # $t6, 0x8004
/* 0FB314 7F0C67A4 3C0F8004 */  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
/* 0FB318 7F0C67A8 8DEF0EDC */  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
/* 0FB31C 7F0C67AC 8DCE0EE0 */  lw    $t6, %lo(ptrSecondFontTableSmall)($t6)
/* 0FB320 7F0C67B0 3C0C00FF */  lui   $t4, (0x00FF00B0 >> 16) # lui $t4, 0xff
/* 0FB324 7F0C67B4 358C00B0 */  ori   $t4, (0x00FF00B0 & 0xFFFF) # ori $t4, $t4, 0xb0
/* 0FB328 7F0C67B8 AFAC0018 */  sw    $t4, 0x18($sp)
/* 0FB32C 7F0C67BC 02202025 */  move  $a0, $s1
/* 0FB330 7F0C67C0 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FB334 7F0C67C4 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FB338 7F0C67C8 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FB33C 7F0C67CC AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FB340 7F0C67D0 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FB344 7F0C67D4 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FB348 7F0C67D8 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FB34C 7F0C67DC AFAF0014 */  sw    $t7, 0x14($sp)
/* 0FB350 7F0C67E0 0FC2B99B */  jal   en_text_write_stuff
/* 0FB354 7F0C67E4 AFAE0010 */   sw    $t6, 0x10($sp)
/* 0FB358 7F0C67E8 3C038008 */  lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0FB35C 7F0C67EC 8C63A120 */  lw    $v1, %lo(pPlayer)($v1)
/* 0FB360 7F0C67F0 00408825 */  move  $s1, $v0
.Ljp7F0C67F4:
/* 0FB364 7F0C67F4 8C6D29C8 */  lw    $t5, 0x29c8($v1)
.Ljp7F0C67F8:
/* 0FB368 7F0C67F8 24010006 */  li    $at, 6
/* 0FB36C 7F0C67FC 15A100B0 */  bne   $t5, $at, .Ljp7F0C6AC0
/* 0FB370 7F0C6800 00000000 */   nop   
/* 0FB374 7F0C6804 0FC30AA2 */  jal   get_textptr_for_textID
/* 0FB378 7F0C6808 3404A020 */   li    $a0, 40992
/* 0FB37C 7F0C680C 3C198004 */  lui   $t9, %hi(ptrFirstFontTableSmall) # $t9, 0x8004
/* 0FB380 7F0C6810 8F390EDC */  lw    $t9, %lo(ptrFirstFontTableSmall)($t9)
/* 0FB384 7F0C6814 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0FB388 7F0C6818 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0FB38C 7F0C681C 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FB390 7F0C6820 27A400BC */  addiu $a0, $sp, 0xbc
/* 0FB394 7F0C6824 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0FB398 7F0C6828 00403025 */  move  $a2, $v0
/* 0FB39C 7F0C682C AFA00014 */  sw    $zero, 0x14($sp)
/* 0FB3A0 7F0C6830 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0FB3A4 7F0C6834 AFB90010 */   sw    $t9, 0x10($sp)
/* 0FB3A8 7F0C6838 0C001145 */  jal   get_video2_settings_ulx
/* 0FB3AC 7F0C683C 00000000 */   nop   
/* 0FB3B0 7F0C6840 8FAB00A8 */  lw    $t3, 0xa8($sp)
/* 0FB3B4 7F0C6844 8FAE00C0 */  lw    $t6, 0xc0($sp)
/* 0FB3B8 7F0C6848 004BC021 */  addu  $t8, $v0, $t3
/* 0FB3BC 7F0C684C 000E7843 */  sra   $t7, $t6, 1
/* 0FB3C0 7F0C6850 030F2023 */  subu  $a0, $t8, $t7
/* 0FB3C4 7F0C6854 24840036 */  addiu $a0, $a0, 0x36
/* 0FB3C8 7F0C6858 0C001149 */  jal   get_video2_settings_uly
/* 0FB3CC 7F0C685C AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FB3D0 7F0C6860 8FAC00BC */  lw    $t4, 0xbc($sp)
/* 0FB3D4 7F0C6864 3C0E8008 */  lui   $t6, %hi(pPlayer) # $t6, 0x8008
/* 0FB3D8 7F0C6868 8DCEA120 */  lw    $t6, %lo(pPlayer)($t6)
/* 0FB3DC 7F0C686C 000C6843 */  sra   $t5, $t4, 1
/* 0FB3E0 7F0C6870 004DC823 */  subu  $t9, $v0, $t5
/* 0FB3E4 7F0C6874 272B0036 */  addiu $t3, $t9, 0x36
/* 0FB3E8 7F0C6878 AFAB00C8 */  sw    $t3, 0xc8($sp)
/* 0FB3EC 7F0C687C 8DD829CC */  lw    $t8, 0x29cc($t6)
/* 0FB3F0 7F0C6880 1700001E */  bnez  $t8, .Ljp7F0C68FC
/* 0FB3F4 7F0C6884 00000000 */   nop   
/* 0FB3F8 7F0C6888 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FB3FC 7F0C688C 00000000 */   nop   
/* 0FB400 7F0C6890 00028400 */  sll   $s0, $v0, 0x10
/* 0FB404 7F0C6894 00107C03 */  sra   $t7, $s0, 0x10
/* 0FB408 7F0C6898 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FB40C 7F0C689C 01E08025 */   move  $s0, $t7
/* 0FB410 7F0C68A0 3C0C8004 */  lui   $t4, %hi(ptrSecondFontTableSmall) # $t4, 0x8004
/* 0FB414 7F0C68A4 3C0D8004 */  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
/* 0FB418 7F0C68A8 8DAD0EDC */  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
/* 0FB41C 7F0C68AC 8D8C0EE0 */  lw    $t4, %lo(ptrSecondFontTableSmall)($t4)
/* 0FB420 7F0C68B0 3C19A0FF */  lui   $t9, (0xA0FFA0F0 >> 16) # lui $t9, 0xa0ff
/* 0FB424 7F0C68B4 3C0B0070 */  lui   $t3, (0x007000A0 >> 16) # lui $t3, 0x70
/* 0FB428 7F0C68B8 356B00A0 */  ori   $t3, (0x007000A0 & 0xFFFF) # ori $t3, $t3, 0xa0
/* 0FB42C 7F0C68BC 3739A0F0 */  ori   $t9, (0xA0FFA0F0 & 0xFFFF) # ori $t9, $t9, 0xa0f0
/* 0FB430 7F0C68C0 AFB90018 */  sw    $t9, 0x18($sp)
/* 0FB434 7F0C68C4 AFAB001C */  sw    $t3, 0x1c($sp)
/* 0FB438 7F0C68C8 02202025 */  move  $a0, $s1
/* 0FB43C 7F0C68CC 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FB440 7F0C68D0 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FB444 7F0C68D4 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FB448 7F0C68D8 AFB00020 */  sw    $s0, 0x20($sp)
/* 0FB44C 7F0C68DC AFA20024 */  sw    $v0, 0x24($sp)
/* 0FB450 7F0C68E0 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FB454 7F0C68E4 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0FB458 7F0C68E8 AFAD0014 */  sw    $t5, 0x14($sp)
/* 0FB45C 7F0C68EC 0FC2BCA7 */  jal   jp_text_write_stuff
/* 0FB460 7F0C68F0 AFAC0010 */   sw    $t4, 0x10($sp)
/* 0FB464 7F0C68F4 1000001A */  b     .Ljp7F0C6960
/* 0FB468 7F0C68F8 00408825 */   move  $s1, $v0
.Ljp7F0C68FC:
/* 0FB46C 7F0C68FC 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FB470 7F0C6900 00000000 */   nop   
/* 0FB474 7F0C6904 00028400 */  sll   $s0, $v0, 0x10
/* 0FB478 7F0C6908 00107403 */  sra   $t6, $s0, 0x10
/* 0FB47C 7F0C690C 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FB480 7F0C6910 01C08025 */   move  $s0, $t6
/* 0FB484 7F0C6914 3C188004 */  lui   $t8, %hi(ptrSecondFontTableSmall) # $t8, 0x8004
/* 0FB488 7F0C6918 3C0F8004 */  lui   $t7, %hi(ptrFirstFontTableSmall) # $t7, 0x8004
/* 0FB48C 7F0C691C 8DEF0EDC */  lw    $t7, %lo(ptrFirstFontTableSmall)($t7)
/* 0FB490 7F0C6920 8F180EE0 */  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
/* 0FB494 7F0C6924 3C0C00FF */  lui   $t4, (0x00FF00B0 >> 16) # lui $t4, 0xff
/* 0FB498 7F0C6928 358C00B0 */  ori   $t4, (0x00FF00B0 & 0xFFFF) # ori $t4, $t4, 0xb0
/* 0FB49C 7F0C692C AFAC0018 */  sw    $t4, 0x18($sp)
/* 0FB4A0 7F0C6930 02202025 */  move  $a0, $s1
/* 0FB4A4 7F0C6934 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FB4A8 7F0C6938 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FB4AC 7F0C693C 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FB4B0 7F0C6940 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FB4B4 7F0C6944 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FB4B8 7F0C6948 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FB4BC 7F0C694C AFA00028 */  sw    $zero, 0x28($sp)
/* 0FB4C0 7F0C6950 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0FB4C4 7F0C6954 0FC2B99B */  jal   en_text_write_stuff
/* 0FB4C8 7F0C6958 AFB80010 */   sw    $t8, 0x10($sp)
/* 0FB4CC 7F0C695C 00408825 */  move  $s1, $v0
.Ljp7F0C6960:
/* 0FB4D0 7F0C6960 0FC30AA2 */  jal   get_textptr_for_textID
/* 0FB4D4 7F0C6964 3404A021 */   li    $a0, 40993
/* 0FB4D8 7F0C6968 3C0D8004 */  lui   $t5, %hi(ptrFirstFontTableSmall) # $t5, 0x8004
/* 0FB4DC 7F0C696C 8DAD0EDC */  lw    $t5, %lo(ptrFirstFontTableSmall)($t5)
/* 0FB4E0 7F0C6970 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0FB4E4 7F0C6974 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0FB4E8 7F0C6978 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FB4EC 7F0C697C 27A400BC */  addiu $a0, $sp, 0xbc
/* 0FB4F0 7F0C6980 27A500C0 */  addiu $a1, $sp, 0xc0
/* 0FB4F4 7F0C6984 00403025 */  move  $a2, $v0
/* 0FB4F8 7F0C6988 AFA00014 */  sw    $zero, 0x14($sp)
/* 0FB4FC 7F0C698C 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0FB500 7F0C6990 AFAD0010 */   sw    $t5, 0x10($sp)
/* 0FB504 7F0C6994 0C001145 */  jal   get_video2_settings_ulx
/* 0FB508 7F0C6998 00000000 */   nop   
/* 0FB50C 7F0C699C 8FB900A8 */  lw    $t9, 0xa8($sp)
/* 0FB510 7F0C69A0 8FAE00C0 */  lw    $t6, 0xc0($sp)
/* 0FB514 7F0C69A4 00595821 */  addu  $t3, $v0, $t9
/* 0FB518 7F0C69A8 000EC043 */  sra   $t8, $t6, 1
/* 0FB51C 7F0C69AC 01782023 */  subu  $a0, $t3, $t8
/* 0FB520 7F0C69B0 24840068 */  addiu $a0, $a0, 0x68
/* 0FB524 7F0C69B4 0C001149 */  jal   get_video2_settings_uly
/* 0FB528 7F0C69B8 AFA400CC */   sw    $a0, 0xcc($sp)
/* 0FB52C 7F0C69BC 8FAF00BC */  lw    $t7, 0xbc($sp)
/* 0FB530 7F0C69C0 3C0E8008 */  lui   $t6, %hi(pPlayer) # $t6, 0x8008
/* 0FB534 7F0C69C4 8DCEA120 */  lw    $t6, %lo(pPlayer)($t6)
/* 0FB538 7F0C69C8 000F6043 */  sra   $t4, $t7, 1
/* 0FB53C 7F0C69CC 004C6823 */  subu  $t5, $v0, $t4
/* 0FB540 7F0C69D0 25B90036 */  addiu $t9, $t5, 0x36
/* 0FB544 7F0C69D4 AFB900C8 */  sw    $t9, 0xc8($sp)
/* 0FB548 7F0C69D8 8DCB29CC */  lw    $t3, 0x29cc($t6)
/* 0FB54C 7F0C69DC 24010001 */  li    $at, 1
/* 0FB550 7F0C69E0 1561001E */  bne   $t3, $at, .Ljp7F0C6A5C
/* 0FB554 7F0C69E4 00000000 */   nop   
/* 0FB558 7F0C69E8 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FB55C 7F0C69EC 00000000 */   nop   
/* 0FB560 7F0C69F0 00028400 */  sll   $s0, $v0, 0x10
/* 0FB564 7F0C69F4 0010C403 */  sra   $t8, $s0, 0x10
/* 0FB568 7F0C69F8 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FB56C 7F0C69FC 03008025 */   move  $s0, $t8
/* 0FB570 7F0C6A00 3C0F8004 */  lui   $t7, %hi(ptrSecondFontTableSmall) # $t7, 0x8004
/* 0FB574 7F0C6A04 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) # $t4, 0x8004
/* 0FB578 7F0C6A08 8D8C0EDC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0FB57C 7F0C6A0C 8DEF0EE0 */  lw    $t7, %lo(ptrSecondFontTableSmall)($t7)
/* 0FB580 7F0C6A10 3C0DA0FF */  lui   $t5, (0xA0FFA0F0 >> 16) # lui $t5, 0xa0ff
/* 0FB584 7F0C6A14 3C190070 */  lui   $t9, (0x007000A0 >> 16) # lui $t9, 0x70
/* 0FB588 7F0C6A18 373900A0 */  ori   $t9, (0x007000A0 & 0xFFFF) # ori $t9, $t9, 0xa0
/* 0FB58C 7F0C6A1C 35ADA0F0 */  ori   $t5, (0xA0FFA0F0 & 0xFFFF) # ori $t5, $t5, 0xa0f0
/* 0FB590 7F0C6A20 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0FB594 7F0C6A24 AFB9001C */  sw    $t9, 0x1c($sp)
/* 0FB598 7F0C6A28 02202025 */  move  $a0, $s1
/* 0FB59C 7F0C6A2C 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FB5A0 7F0C6A30 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FB5A4 7F0C6A34 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FB5A8 7F0C6A38 AFB00020 */  sw    $s0, 0x20($sp)
/* 0FB5AC 7F0C6A3C AFA20024 */  sw    $v0, 0x24($sp)
/* 0FB5B0 7F0C6A40 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FB5B4 7F0C6A44 AFA0002C */  sw    $zero, 0x2c($sp)
/* 0FB5B8 7F0C6A48 AFAC0014 */  sw    $t4, 0x14($sp)
/* 0FB5BC 7F0C6A4C 0FC2BCA7 */  jal   jp_text_write_stuff
/* 0FB5C0 7F0C6A50 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0FB5C4 7F0C6A54 1000001A */  b     .Ljp7F0C6AC0
/* 0FB5C8 7F0C6A58 00408825 */   move  $s1, $v0
.Ljp7F0C6A5C:
/* 0FB5CC 7F0C6A5C 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FB5D0 7F0C6A60 00000000 */   nop   
/* 0FB5D4 7F0C6A64 00028400 */  sll   $s0, $v0, 0x10
/* 0FB5D8 7F0C6A68 00107403 */  sra   $t6, $s0, 0x10
/* 0FB5DC 7F0C6A6C 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FB5E0 7F0C6A70 01C08025 */   move  $s0, $t6
/* 0FB5E4 7F0C6A74 3C0B8004 */  lui   $t3, %hi(ptrSecondFontTableSmall) # $t3, 0x8004
/* 0FB5E8 7F0C6A78 3C188004 */  lui   $t8, %hi(ptrFirstFontTableSmall) # $t8, 0x8004
/* 0FB5EC 7F0C6A7C 8F180EDC */  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
/* 0FB5F0 7F0C6A80 8D6B0EE0 */  lw    $t3, %lo(ptrSecondFontTableSmall)($t3)
/* 0FB5F4 7F0C6A84 3C0F00FF */  lui   $t7, (0x00FF00B0 >> 16) # lui $t7, 0xff
/* 0FB5F8 7F0C6A88 35EF00B0 */  ori   $t7, (0x00FF00B0 & 0xFFFF) # ori $t7, $t7, 0xb0
/* 0FB5FC 7F0C6A8C AFAF0018 */  sw    $t7, 0x18($sp)
/* 0FB600 7F0C6A90 02202025 */  move  $a0, $s1
/* 0FB604 7F0C6A94 27A500CC */  addiu $a1, $sp, 0xcc
/* 0FB608 7F0C6A98 27A600C8 */  addiu $a2, $sp, 0xc8
/* 0FB60C 7F0C6A9C 8FA700A4 */  lw    $a3, 0xa4($sp)
/* 0FB610 7F0C6AA0 AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FB614 7F0C6AA4 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FB618 7F0C6AA8 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FB61C 7F0C6AAC AFA00028 */  sw    $zero, 0x28($sp)
/* 0FB620 7F0C6AB0 AFB80014 */  sw    $t8, 0x14($sp)
/* 0FB624 7F0C6AB4 0FC2B99B */  jal   en_text_write_stuff
/* 0FB628 7F0C6AB8 AFAB0010 */   sw    $t3, 0x10($sp)
/* 0FB62C 7F0C6ABC 00408825 */  move  $s1, $v0
.Ljp7F0C6AC0:
/* 0FB630 7F0C6AC0 0FC2B6A8 */  jal   combiner_bayer_lod_perspective
/* 0FB634 7F0C6AC4 02202025 */   move  $a0, $s1
/* 0FB638 7F0C6AC8 10000092 */  b     .Ljp7F0C6D14
/* 0FB63C 7F0C6ACC 00408825 */   move  $s1, $v0
/* 0FB640 7F0C6AD0 8C6C00D8 */  lw    $t4, 0xd8($v1)
.Ljp7F0C6AD4:
/* 0FB644 7F0C6AD4 51800090 */  beql  $t4, $zero, .Ljp7F0C6D18
/* 0FB648 7F0C6AD8 02201025 */   move  $v0, $s1
/* 0FB64C 7F0C6ADC 8C6D0428 */  lw    $t5, 0x428($v1)
/* 0FB650 7F0C6AE0 51A0008D */  beql  $t5, $zero, .Ljp7F0C6D18
/* 0FB654 7F0C6AE4 02201025 */   move  $v0, $s1
/* 0FB658 7F0C6AE8 8C790424 */  lw    $t9, 0x424($v1)
/* 0FB65C 7F0C6AEC 3C0E8009 */  lui   $t6, %hi(stop_play_flag) # $t6, 0x8009
/* 0FB660 7F0C6AF0 53200089 */  beql  $t9, $zero, .Ljp7F0C6D18
/* 0FB664 7F0C6AF4 02201025 */   move  $v0, $s1
/* 0FB668 7F0C6AF8 8DCEC770 */  lw    $t6, %lo(stop_play_flag)($t6)
/* 0FB66C 7F0C6AFC 3C0B8009 */  lui   $t3, %hi(is_gameover_flag) # $t3, 0x8009
/* 0FB670 7F0C6B00 55C00085 */  bnezl $t6, .Ljp7F0C6D18
/* 0FB674 7F0C6B04 02201025 */   move  $v0, $s1
/* 0FB678 7F0C6B08 8D6BC774 */  lw    $t3, %lo(is_gameover_flag)($t3)
/* 0FB67C 7F0C6B0C 00002025 */  move  $a0, $zero
/* 0FB680 7F0C6B10 55600081 */  bnezl $t3, .Ljp7F0C6D18
/* 0FB684 7F0C6B14 02201025 */   move  $v0, $s1
/* 0FB688 7F0C6B18 18400028 */  blez  $v0, .Ljp7F0C6BBC
/* 0FB68C 7F0C6B1C 00002825 */   move  $a1, $zero
/* 0FB690 7F0C6B20 30470003 */  andi  $a3, $v0, 3
/* 0FB694 7F0C6B24 10E00011 */  beqz  $a3, .Ljp7F0C6B6C
/* 0FB698 7F0C6B28 00E03025 */   move  $a2, $a3
/* 0FB69C 7F0C6B2C 8FAF00D4 */  lw    $t7, 0xd4($sp)
/* 0FB6A0 7F0C6B30 0000C0C0 */  sll   $t8, $zero, 3
/* 0FB6A4 7F0C6B34 0300C023 */  subu  $t8, $t8, $zero
/* 0FB6A8 7F0C6B38 0018C100 */  sll   $t8, $t8, 4
/* 0FB6AC 7F0C6B3C 3C198008 */  lui   $t9, %hi(player1_player_data) # $t9, 0x8008
/* 0FB6B0 7F0C6B40 000F6080 */  sll   $t4, $t7, 2
/* 0FB6B4 7F0C6B44 030C6821 */  addu  $t5, $t8, $t4
/* 0FB6B8 7F0C6B48 27399F60 */  addiu $t9, %lo(player1_player_data) # addiu $t9, $t9, -0x60a0
/* 0FB6BC 7F0C6B4C 01B91821 */  addu  $v1, $t5, $t9
.Ljp7F0C6B50:
/* 0FB6C0 7F0C6B50 8C6E0024 */  lw    $t6, 0x24($v1)
/* 0FB6C4 7F0C6B54 24A50001 */  addiu $a1, $a1, 1
/* 0FB6C8 7F0C6B58 24630070 */  addiu $v1, $v1, 0x70
/* 0FB6CC 7F0C6B5C 14C5FFFC */  bne   $a2, $a1, .Ljp7F0C6B50
/* 0FB6D0 7F0C6B60 008E2021 */   addu  $a0, $a0, $t6
/* 0FB6D4 7F0C6B64 10A20015 */  beq   $a1, $v0, .Ljp7F0C6BBC
/* 0FB6D8 7F0C6B68 00000000 */   nop   
.Ljp7F0C6B6C:
/* 0FB6DC 7F0C6B6C 8FAF00D4 */  lw    $t7, 0xd4($sp)
/* 0FB6E0 7F0C6B70 000558C0 */  sll   $t3, $a1, 3
/* 0FB6E4 7F0C6B74 01655823 */  subu  $t3, $t3, $a1
/* 0FB6E8 7F0C6B78 000B5900 */  sll   $t3, $t3, 4
/* 0FB6EC 7F0C6B7C 3C0D8008 */  lui   $t5, %hi(player1_player_data) # $t5, 0x8008
/* 0FB6F0 7F0C6B80 000FC080 */  sll   $t8, $t7, 2
/* 0FB6F4 7F0C6B84 01786021 */  addu  $t4, $t3, $t8
/* 0FB6F8 7F0C6B88 25AD9F60 */  addiu $t5, %lo(player1_player_data) # addiu $t5, $t5, -0x60a0
/* 0FB6FC 7F0C6B8C 018D1821 */  addu  $v1, $t4, $t5
.Ljp7F0C6B90:
/* 0FB700 7F0C6B90 8C790024 */  lw    $t9, 0x24($v1)
/* 0FB704 7F0C6B94 8C6E0094 */  lw    $t6, 0x94($v1)
/* 0FB708 7F0C6B98 8C6F0104 */  lw    $t7, 0x104($v1)
/* 0FB70C 7F0C6B9C 00992021 */  addu  $a0, $a0, $t9
/* 0FB710 7F0C6BA0 8C6B0174 */  lw    $t3, 0x174($v1)
/* 0FB714 7F0C6BA4 008E2021 */  addu  $a0, $a0, $t6
/* 0FB718 7F0C6BA8 24A50004 */  addiu $a1, $a1, 4
/* 0FB71C 7F0C6BAC 008F2021 */  addu  $a0, $a0, $t7
/* 0FB720 7F0C6BB0 246301C0 */  addiu $v1, $v1, 0x1c0
/* 0FB724 7F0C6BB4 14A8FFF6 */  bne   $a1, $t0, .Ljp7F0C6B90
/* 0FB728 7F0C6BB8 008B2021 */   addu  $a0, $a0, $t3
.Ljp7F0C6BBC:
/* 0FB72C 7F0C6BBC 0FC05202 */  jal   get_scenario
/* 0FB730 7F0C6BC0 AFA40058 */   sw    $a0, 0x58($sp)
/* 0FB734 7F0C6BC4 24010001 */  li    $at, 1
/* 0FB738 7F0C6BC8 14410004 */  bne   $v0, $at, .Ljp7F0C6BDC
/* 0FB73C 7F0C6BCC 8FA40058 */   lw    $a0, 0x58($sp)
/* 0FB740 7F0C6BD0 28810002 */  slti  $at, $a0, 2
/* 0FB744 7F0C6BD4 50200050 */  beql  $at, $zero, .Ljp7F0C6D18
/* 0FB748 7F0C6BD8 02201025 */   move  $v0, $s1
.Ljp7F0C6BDC:
/* 0FB74C 7F0C6BDC 0FC2D6D9 */  jal   sub_GAME_7F0B4FB4
/* 0FB750 7F0C6BE0 02202025 */   move  $a0, $s1
/* 0FB754 7F0C6BE4 0FC2B652 */  jal   microcode_constructor
/* 0FB758 7F0C6BE8 00402025 */   move  $a0, $v0
/* 0FB75C 7F0C6BEC 00408825 */  move  $s1, $v0
/* 0FB760 7F0C6BF0 0FC30AA2 */  jal   get_textptr_for_textID
/* 0FB764 7F0C6BF4 3404A022 */   li    $a0, 40994
/* 0FB768 7F0C6BF8 3C188004 */  lui   $t8, %hi(ptrFirstFontTableSmall) # $t8, 0x8004
/* 0FB76C 7F0C6BFC 8F180EDC */  lw    $t8, %lo(ptrFirstFontTableSmall)($t8)
/* 0FB770 7F0C6C00 3C078004 */  lui   $a3, %hi(ptrSecondFontTableSmall) # $a3, 0x8004
/* 0FB774 7F0C6C04 AFA20060 */  sw    $v0, 0x60($sp)
/* 0FB778 7F0C6C08 8CE70EE0 */  lw    $a3, %lo(ptrSecondFontTableSmall)($a3)
/* 0FB77C 7F0C6C0C 27A40064 */  addiu $a0, $sp, 0x64
/* 0FB780 7F0C6C10 27A50068 */  addiu $a1, $sp, 0x68
/* 0FB784 7F0C6C14 00403025 */  move  $a2, $v0
/* 0FB788 7F0C6C18 AFA00014 */  sw    $zero, 0x14($sp)
/* 0FB78C 7F0C6C1C 0FC2BD4F */  jal   sub_GAME_7F0AE98C
/* 0FB790 7F0C6C20 AFB80010 */   sw    $t8, 0x10($sp)
/* 0FB794 7F0C6C24 0C001145 */  jal   get_video2_settings_ulx
/* 0FB798 7F0C6C28 00000000 */   nop   
/* 0FB79C 7F0C6C2C 0C001127 */  jal   get_video2_settings_width
/* 0FB7A0 7F0C6C30 A7A20056 */   sh    $v0, 0x56($sp)
/* 0FB7A4 7F0C6C34 87A80056 */  lh    $t0, 0x56($sp)
/* 0FB7A8 7F0C6C38 8FAE0068 */  lw    $t6, 0x68($sp)
/* 0FB7AC 7F0C6C3C 00026843 */  sra   $t5, $v0, 1
/* 0FB7B0 7F0C6C40 01A8C821 */  addu  $t9, $t5, $t0
/* 0FB7B4 7F0C6C44 000E7843 */  sra   $t7, $t6, 1
/* 0FB7B8 7F0C6C48 032F5023 */  subu  $t2, $t9, $t7
/* 0FB7BC 7F0C6C4C 0C001149 */  jal   get_video2_settings_uly
/* 0FB7C0 7F0C6C50 AFAA0070 */   sw    $t2, 0x70($sp)
/* 0FB7C4 7F0C6C54 0C00112B */  jal   get_video2_settings_height
/* 0FB7C8 7F0C6C58 A7A20056 */   sh    $v0, 0x56($sp)
/* 0FB7CC 7F0C6C5C 87A80056 */  lh    $t0, 0x56($sp)
/* 0FB7D0 7F0C6C60 8FA90064 */  lw    $t1, 0x64($sp)
/* 0FB7D4 7F0C6C64 0002C043 */  sra   $t8, $v0, 1
/* 0FB7D8 7F0C6C68 8FAA0070 */  lw    $t2, 0x70($sp)
/* 0FB7DC 7F0C6C6C 8FAE0068 */  lw    $t6, 0x68($sp)
/* 0FB7E0 7F0C6C70 03086021 */  addu  $t4, $t8, $t0
/* 0FB7E4 7F0C6C74 00096843 */  sra   $t5, $t1, 1
/* 0FB7E8 7F0C6C78 018D1823 */  subu  $v1, $t4, $t5
/* 0FB7EC 7F0C6C7C 0069C821 */  addu  $t9, $v1, $t1
/* 0FB7F0 7F0C6C80 272F0001 */  addiu $t7, $t9, 1
/* 0FB7F4 7F0C6C84 014E3821 */  addu  $a3, $t2, $t6
/* 0FB7F8 7F0C6C88 24E70001 */  addiu $a3, $a3, 1
/* 0FB7FC 7F0C6C8C AFAF0010 */  sw    $t7, 0x10($sp)
/* 0FB800 7F0C6C90 2466FFFF */  addiu $a2, $v1, -1
/* 0FB804 7F0C6C94 AFA3006C */  sw    $v1, 0x6c($sp)
/* 0FB808 7F0C6C98 02202025 */  move  $a0, $s1
/* 0FB80C 7F0C6C9C AFA00014 */  sw    $zero, 0x14($sp)
/* 0FB810 7F0C6CA0 0FC2B6F1 */  jal   microcode_constructor_related_to_menus
/* 0FB814 7F0C6CA4 2545FFFF */   addiu $a1, $t2, -1
/* 0FB818 7F0C6CA8 0C001107 */  jal   get_video2_settings_txtClipW
/* 0FB81C 7F0C6CAC 00408825 */   move  $s1, $v0
/* 0FB820 7F0C6CB0 00028400 */  sll   $s0, $v0, 0x10
/* 0FB824 7F0C6CB4 00105C03 */  sra   $t3, $s0, 0x10
/* 0FB828 7F0C6CB8 0C00110B */  jal   get_video2_settings_txtClipH
/* 0FB82C 7F0C6CBC 01608025 */   move  $s0, $t3
/* 0FB830 7F0C6CC0 3C188004 */  lui   $t8, %hi(ptrSecondFontTableSmall) # $t8, 0x8004
/* 0FB834 7F0C6CC4 3C0C8004 */  lui   $t4, %hi(ptrFirstFontTableSmall) # $t4, 0x8004
/* 0FB838 7F0C6CC8 8D8C0EDC */  lw    $t4, %lo(ptrFirstFontTableSmall)($t4)
/* 0FB83C 7F0C6CCC 8F180EE0 */  lw    $t8, %lo(ptrSecondFontTableSmall)($t8)
/* 0FB840 7F0C6CD0 3C0D00FF */  lui   $t5, (0x00FF00B0 >> 16) # lui $t5, 0xff
/* 0FB844 7F0C6CD4 35AD00B0 */  ori   $t5, (0x00FF00B0 & 0xFFFF) # ori $t5, $t5, 0xb0
/* 0FB848 7F0C6CD8 AFAD0018 */  sw    $t5, 0x18($sp)
/* 0FB84C 7F0C6CDC 02202025 */  move  $a0, $s1
/* 0FB850 7F0C6CE0 27A50070 */  addiu $a1, $sp, 0x70
/* 0FB854 7F0C6CE4 27A6006C */  addiu $a2, $sp, 0x6c
/* 0FB858 7F0C6CE8 8FA70060 */  lw    $a3, 0x60($sp)
/* 0FB85C 7F0C6CEC AFB0001C */  sw    $s0, 0x1c($sp)
/* 0FB860 7F0C6CF0 AFA20020 */  sw    $v0, 0x20($sp)
/* 0FB864 7F0C6CF4 AFA00024 */  sw    $zero, 0x24($sp)
/* 0FB868 7F0C6CF8 AFA00028 */  sw    $zero, 0x28($sp)
/* 0FB86C 7F0C6CFC AFAC0014 */  sw    $t4, 0x14($sp)
/* 0FB870 7F0C6D00 0FC2B99B */  jal   en_text_write_stuff
/* 0FB874 7F0C6D04 AFB80010 */   sw    $t8, 0x10($sp)
/* 0FB878 7F0C6D08 0FC2B6A8 */  jal   combiner_bayer_lod_perspective
/* 0FB87C 7F0C6D0C 00402025 */   move  $a0, $v0
/* 0FB880 7F0C6D10 00408825 */  move  $s1, $v0
.Ljp7F0C6D14:
/* 0FB884 7F0C6D14 02201025 */  move  $v0, $s1
.Ljp7F0C6D18:
/* 0FB888 7F0C6D18 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0FB88C 7F0C6D1C 8FB00034 */  lw    $s0, 0x34($sp)
/* 0FB890 7F0C6D20 8FB10038 */  lw    $s1, 0x38($sp)
/* 0FB894 7F0C6D24 03E00008 */  jr    $ra
/* 0FB898 7F0C6D28 27BD00D8 */   addiu $sp, $sp, 0xd8
)
#endif

#endif



#ifdef NONMATCHING
s32 sub_GAME_7F0C6048(void)
{
    if (is_gameover_flag != 0)
    {
        return 0;
    }
    return (pPlayer->mpmenuon | (0 < pPlayer->healthdisplaytime));
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C6048
/* 0FAB78 7F0C6048 3C0E8009 */  lui   $t6, %hi(is_gameover_flag) 
/* 0FAB7C 7F0C604C 8DCEC704 */  lw    $t6, %lo(is_gameover_flag)($t6)
/* 0FAB80 7F0C6050 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0FAB84 7F0C6054 11C00003 */  beqz  $t6, .L7F0C6064
/* 0FAB88 7F0C6058 00000000 */   nop   
/* 0FAB8C 7F0C605C 03E00008 */  jr    $ra
/* 0FAB90 7F0C6060 00001025 */   move  $v0, $zero

.L7F0C6064:
/* 0FAB94 7F0C6064 8C42A0B0 */  lw    $v0, %lo(pPlayer)($v0)
/* 0FAB98 7F0C6068 8C582A00 */  lw    $t8, 0x2a00($v0)
/* 0FAB9C 7F0C606C 8C4F29C4 */  lw    $t7, 0x29c4($v0)
/* 0FABA0 7F0C6070 0018C82A */  slt   $t9, $zero, $t8
/* 0FABA4 7F0C6074 01F91825 */  or    $v1, $t7, $t9
/* 0FABA8 7F0C6078 03E00008 */  jr    $ra
/* 0FABAC 7F0C607C 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
s32 checkGamePaused(void) {
    return is_paused;
}
#else
GLOBAL_ASM(
.text
glabel checkGamePaused
/* 0FABB0 7F0C6080 3C028009 */  lui   $v0, %hi(is_paused)
/* 0FABB4 7F0C6084 03E00008 */  jr    $ra
/* 0FABB8 7F0C6088 8C42C718 */   lw    $v0, %lo(is_paused)($v0)
)
#endif


