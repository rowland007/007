#include "ultra64.h"
#include "game/bond.h"

// bss
s32 z_buffer_width;
s32 z_buffer_height;

// data
s32 z_buffer = 0;

void zbufDeallocate(void) {
    z_buffer = 0;
}

#define ALIGN64(val) (((val) + 0x3F) & ~0x3F)
u32 mempAllocBytesInBank(u32 bytes,u8 bank);
s32 getPlayerCount(void);
void zbufAllocate(void) {
    if (resolution != 0) {
        z_buffer_width = 440;
        z_buffer_height = 330;
    } else {
        z_buffer_width = 320;
        if (getPlayerCount() == 1) {
            z_buffer_height = 240;
        } else {
            z_buffer_height = 120;
        }
    }
    z_buffer = mempAllocBytesInBank((z_buffer_width * z_buffer_height * 2) + 64, 4);
    z_buffer = ALIGN64(z_buffer);
}

void zbufSetBuffer(s32 buffer, s32 width, s32 height) {
    z_buffer = buffer;
    z_buffer_width = width;
    z_buffer_height = height;
}

Gfx *zbufInit(Gfx *gdl) {
    s32 phi_a3;
    s32 test;
    if (z_buffer == 0) {
        zbufAllocate();
    }
    if (!(get_cur_playernum() < 2) || ((getPlayerCount() == 2) && (get_cur_playernum() == 1))) {
        phi_a3 = 320 * 240;
    } else {
        phi_a3 = 0;
    }
    test = (z_buffer - phi_a3);
    test = test & ~0x3F;
    gDPPipeSync(gdl++);
    gDPSetDepthImage(gdl++, test);
    return gdl;
}

s16 get_video2_settings_txtClipW(void);
s16 get_video2_settings_txtClipH(void);
Gfx *zbufClearCurrentPlayer(Gfx *gdl) {
    s32 start_x;
    s32 end_x;
    gDPPipeSync(gdl++);
    gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, z_buffer_width, (z_buffer + 0x80000000));
    gDPSetCycleType(gdl++, G_CYC_FILL);
    gDPSetFillColor(gdl++, (GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0)));
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, get_video2_settings_txtClipW(), get_video2_settings_txtClipH());
    if (getPlayerCount() < 3) {
        start_x = 0;
        end_x = get_video2_settings_txtClipW() - 1;
    } else if ((get_cur_playernum() == 0) || (get_cur_playernum() == 2)) {
        start_x = 0;
        end_x = (get_video2_settings_txtClipW() / 2) - 1;
    } else {
        start_x = get_video2_settings_txtClipW() / 2;
        end_x = get_video2_settings_txtClipW() - 1;
    }
    gDPFillRectangle(gdl++, start_x, 0, end_x, (z_buffer_height - 1));
    gDPPipeSync(gdl++);
    return gdl;
}
