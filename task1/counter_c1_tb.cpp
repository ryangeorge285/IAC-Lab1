#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

int main(int argc, char **argv, char **env)
{
    int i, clk;

    Verilated::commandArgs(argc, argv);

    Vcounter *top = new Vcounter;

    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("counter.vcd");

    top->clk = 1;
    top->rst = 1;
    top->en = 0;
    int count = 0;
    int delaycycle3 = 0;

    for (i = 0; i < 300; i++)
    {
        for (clk = 0; clk < 2; clk++)
        {
            tfp->dump(2 * i + clk);
            top->clk = !top->clk;
            top->eval();
        }

        bool rst = (i < 2) | (i == 18);
        bool en;
        if (i > 4)
        {
            if (count == 9)
            {
                if (delaycycle3 == 2)
                {
                    en = 1;
                    delaycycle3 = 0;
                }
                else
                {
                    en = 0;
                    delaycycle3 += 1;
                }
            }
            else
                en = 1;
        }
        else
            en = 0;

        top->rst = rst;
        count = rst == false ? count + en : 0;

        top->en = en;

        if (Verilated::gotFinish())
            exit(0);
    }

    tfp->close();
    exit(0);
}