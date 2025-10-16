#include "Vcounter_c2.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv, char **env)
{
    int i, clk;

    Verilated::commandArgs(argc, argv);

    Vcounter_c2 *top = new Vcounter_c2;

    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("counter_c2.vcd");

    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    for (i = 0; i < 300; i++)
    {
        for (clk = 0; clk < 2; clk++)
        {
            tfp->dump(2 * i + clk);
            top->clk = !top->clk;
            top->eval();
        }
        top->rst = (i < 2) | (i == 15);
        top->en = i > 4;
        if (Verilated::gotFinish())
            exit(0);
    }

    tfp->close();
    exit(0);
}