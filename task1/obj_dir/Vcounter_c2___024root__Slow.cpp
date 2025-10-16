// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter_c2.h for the primary calling header

#include "Vcounter_c2__pch.h"
#include "Vcounter_c2__Syms.h"
#include "Vcounter_c2___024root.h"

void Vcounter_c2___024root___ctor_var_reset(Vcounter_c2___024root* vlSelf);

Vcounter_c2___024root::Vcounter_c2___024root(Vcounter_c2__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vcounter_c2___024root___ctor_var_reset(this);
}

void Vcounter_c2___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vcounter_c2___024root::~Vcounter_c2___024root() {
}
