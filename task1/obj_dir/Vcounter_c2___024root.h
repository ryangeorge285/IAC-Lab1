// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcounter_c2.h for the primary calling header

#ifndef VERILATED_VCOUNTER_C2___024ROOT_H_
#define VERILATED_VCOUNTER_C2___024ROOT_H_  // guard

#include "verilated.h"


class Vcounter_c2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vcounter_c2___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(en,0,0);
    VL_OUT8(count,7,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vcounter_c2__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcounter_c2___024root(Vcounter_c2__Syms* symsp, const char* v__name);
    ~Vcounter_c2___024root();
    VL_UNCOPYABLE(Vcounter_c2___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
