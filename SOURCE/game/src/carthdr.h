#ifndef BATMAN_CARTHDR_H
#define BATMAN_CARTHDR_H
#include "ngpc_types.h"
extern void cart_entry(void);
#pragma section const f_header
const char Licensed[28]=" LICENSED BY SNK CORPORATION";
const FuncPtr EntryPoint=cart_entry;
const short CartID=0x0000;
const short CartSystem=0x1000;
const char CartTitle[12]="BATMAN MOVIE";
const long CartReserved[4]={0,0,0,0};
#pragma section const
#endif
