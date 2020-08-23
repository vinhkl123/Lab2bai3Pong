#pragma once

void paddleInit(paddleInit* pad, int x, int y)
{
    pad->x = x;
    pad->y = y;
    pad->score = 0; /* ?i?m s? ban ??u */
    pad->dir = PADDLE_STOP; /* h??ng di chuy?n ban ??u */
}
void paddleDraw(PADDLE* pad)
{
    rectDraw(pad->x, pad->y, PADDLE_WIDTH, PADDLE_HEIGHT, CR_WHITE);
}
void paddleUpdate(PADDLE* pad)
{
    if (pad->dir == PADDLE_UP) { /* di chuy?n lên, có ki?m tra va ch?m */
        if (pad->y - PADDLE_SPEED > PADDLE_COLLIDE_TOP)
            pad->y -= PADDLE_SPEED;
        else
            pad->y = PADDLE_COLLIDE_TOP;
    }
    else
        if (pad->dir == PADDLE_DOWN) { /* di chuy?n xu?ng, có ki?m tra va ch?m */
            if (pad->y + PADDLE_SPEED < PADDLE_COLLIDE_BOTTOM)
                pad->y += PADDLE_SPEED;
            else
                pad->y = PADDLE_COLLIDE_BOTTOM;
        }
    pad->dir = PADDLE_STOP; /* d?ng chuy?n ??ng */
}