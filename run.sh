make;
riscv64-unknown-elf-objdump -D build/riscv-hs-tests.elf > build/riscv-hs-tests.dump;

if [ $1 == "spike" ]; then
    spike -l --log=spike-trace.log --isa=rv64gch --misaligned build/riscv-hs-tests.elf &> spike-term.log
    less -R spike-term.log
elif [ $1 == "sail" ]; then
    ../../sail-riscv/c_emulator/riscv_sim_RV64 --enable-misaligned -t sail-term.log build/riscv-hs-tests.elf > sail-trace.log
    less -R sail-term.log
else
    printf "[ERROR] Please specify emulator [spike | sail]";
fi