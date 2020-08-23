#pragma once

#pragma once
#include "C:\Users\DELL\Desktop\Lab2bai3Pong\Dependencies\SDL\SDL.h"
#include "global.h"
#include <stdlib.h>
#include <time.h>


#define BOARD_CELL 16 /* kích thước 1 ô, nên là lũy thừa của 2 */
#define BOARD_WIDTH (BOARD_CELL * 58) /* chiều rộng cửa sổ */
#define BOARD_HEIGHT (BOARD_CELL * 40) /* chiều cao cửa sổ */
#define BOARD_TOP BOARD_CELL /* biên đỉnh */
#define BOARD_BOTTOM (BOARD_HEIGHT-BOARD_CELL) /* biên đáy */
#define CR_BLUE 0xFF /* màu trắng */
#define CR_GRAY 0x66 /* màu xám */
#define CR_BLACK 0x00 /* màu đen */
#define DIGIT_WIDTH 3 /* chiều rộng 1 ký số */
#define DIGIT_HEIGHT 5 /* chiều cao 1 ký số */
/* khai báo các biến toàn cục */
extern SDL_Window* g_window; /* SDL window */
extern SDL_Renderer* g_renderer; /* SDL renderer */
extern char DIGITS[10 * DIGIT_HEIGHT]; /* font các ký số */
/* phát sinh vector chuyển động ngẫu nhiên */
int velocity();
/* kiểm tra va chạm giữa hai SDL_Rect */
SDL_bool rectCollide(const SDL_Rect* a, const SDL_Rect* b);
/* vẽ một hình chữ nhật */
void rectDraw(int x, int y, int w, int h, int cr);
/* vẽ một ký số sử dụng font chữ đã được định nghĩa */
void digitDraw(int x, int y, int digit);
SDL_Window* g_window = NULL; /* SDL window */
SDL_Renderer* g_renderer = NULL; /* SDL renderer */
char DIGITS[10 * DIGIT_HEIGHT] = /* font chữ cho các ký số */
{
 0x07, 0x05, 0x05, 0x05, 0x07, /* 0 */
 0x06, 0x02, 0x02, 0x02, 0x07, /* 1 */
 0x07, 0x01, 0x07, 0x04, 0x07, /* 2 */
 0x07, 0x01, 0x03, 0x01, 0x07, /* 3 */
 0x05, 0x05, 0x07, 0x01, 0x01, /* 4 */
 0x07, 0x04, 0x07, 0x01, 0x07, /* 5 */
 0x07, 0x04, 0x07, 0x05, 0x07, /* 6 */
 0x07, 0x01, 0x01, 0x01, 0x01, /* 7 */
 0x07, 0x05, 0x07, 0x05, 0x07, /* 8 */
 0x07, 0x05, 0x07, 0x01, 0x01 /* 9 */
};
int velocity()
{
    int value = 0; /* phát sinh ngẫu nhiên một trong hai giá trị là -1 hoặc 1 */
    do { value = 1 - (rand() % 3); } while (!value);
    return value;
}
SDL_bool rectCollide(const SDL_Rect* a, const SDL_Rect* b)
{
    /* kiểm tra hình chữ nhật a, b có giao nhau hay không */
    return SDL_HasIntersection(a, b);
}
void rectDraw(int x, int y, int w, int h, int cr)
{
    /* vẽ hình chữ nhật, đây là hàm được sử dụng để vẽ mọi đối tượng trong trò chơi */
    SDL_Rect rc = { x, y, w, h };
    SDL_SetRenderDrawColor(g_renderer, cr, cr, cr, 0xFF);
    SDL_RenderFillRect(g_renderer, &rc);
}
void digitDraw(int x, int y, int digit) /* vẽ một ký số */
{
    for (int i = 0; i < DIGIT_HEIGHT; i++) { /* lặp 5 dòng */
        char value = DIGITS[digit * DIGIT_HEIGHT + i];
        for (int j = 0; j < DIGIT_WIDTH; j++) { /* lặp 3 cột */
            if (value & 0x4) /* kiểm tra bit thứ 3 */
                rectDraw(x + j * BOARD_CELL, /* vẽ 1 ô nếu bit=1 */
                    y + i * BOARD_CELL,
                    BOARD_CELL, BOARD_CELL, CR_GRAY);
            value <<= 1; /* dịch trái 1 bit */
        }
    }
}
