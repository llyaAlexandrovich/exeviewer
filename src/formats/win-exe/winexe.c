#include "winexe.h"








void FillOutDOSHeader(IMAGE_DOS_HEADER* idh, char* buffer)
{
    idh->e_magic = MAKEWORD(buffer[0], buffer[1]);
    idh->e_cblp = MAKEWORD(buffer[2], buffer[3]);
    idh->e_cp = MAKEWORD(buffer[4], buffer[5]);
    idh->e_crlc = MAKEWORD(buffer[6], buffer[7]);
    idh->e_cparhdr = MAKEWORD(buffer[8], buffer[9]);
    idh->e_minalloc = MAKEWORD(buffer[10], buffer[11]);
    idh->e_maxalloc = MAKEWORD(buffer[12], buffer[13]);
    idh->e_ss = MAKEWORD(buffer[14], buffer[15]);
    idh->e_sp = MAKEWORD(buffer[16], buffer[17]);
    idh->e_csum = MAKEWORD(buffer[18], buffer[19]);
    idh->e_ip = MAKEWORD(buffer[20], buffer[21]);
    idh->e_cs = MAKEWORD(buffer[22], buffer[23]);
    idh->e_lfarlc = MAKEWORD(buffer[24], buffer[25]);
    idh->e_ovno = MAKEWORD(buffer[26], buffer[27]);
    idh->e_res[0] = MAKEWORD(buffer[28], buffer[29]);
    idh->e_res[1] = MAKEWORD(buffer[30], buffer[31]);
    idh->e_res[2] = MAKEWORD(buffer[32], buffer[33]);
    idh->e_res[3] = MAKEWORD(buffer[34], buffer[35]);
    idh->e_oemid = MAKEWORD(buffer[36], buffer[37]);
    idh->e_oeminfo = MAKEWORD(buffer[38], buffer[39]);
    idh->e_res2[0] = MAKEWORD(buffer[40], buffer[41]);
    idh->e_res2[1] = MAKEWORD(buffer[42], buffer[43]);
    idh->e_res2[2] = MAKEWORD(buffer[44], buffer[45]);
    idh->e_res2[3] = MAKEWORD(buffer[46], buffer[47]);
    idh->e_res2[4] = MAKEWORD(buffer[48], buffer[49]);
    idh->e_res2[5] = MAKEWORD(buffer[50], buffer[51]);
    idh->e_res2[6] = MAKEWORD(buffer[52], buffer[53]);
    idh->e_res2[7] = MAKEWORD(buffer[54], buffer[55]);
    idh->e_res2[8] = MAKEWORD(buffer[56], buffer[57]);
    idh->e_res2[9] = MAKEWORD(buffer[58], buffer[59]);
    idh->e_lfanew = MAKEWORD(buffer[60], buffer[61]);
}