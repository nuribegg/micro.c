static void putc(char c)
{
    if (c == '\n') {
        col = 0;
        row++;
        return;
    }

    if (c == '\b') {
        if (col > 0) {
            col--;
            VGA[row * 80 + col] = 0x0700;
        }
        return;
    }

    VGA[row * 80 + col] = 0x0700 | c;
    col++;

    if (col >= 80) {
        col = 0;
        row++;
    }
}
