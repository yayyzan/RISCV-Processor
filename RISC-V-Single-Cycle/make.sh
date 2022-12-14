instrmem="RTL/instrmem.sv"
filename=$1
base=`echo $filename | sed "s/\.s$//"`
basename=`basename -s .s $filename`
replacement='$readmemh("\.\/programs\/'$basename'\.hex", rom_array);'


rm -rf "$base.hex"
riscv64-unknown-elf-as -R -march=rv32im -mabi=ilp32 -o "$base.out" "$base.s"
riscv64-unknown-elf-ld -melf32lriscv -e 0xBFC00000 -Ttext 0xBFC00000 -o "$base.out.reloc" "$base.out"
rm "$base.out"
riscv64-unknown-elf-objcopy -O binary -j .text "$base.out.reloc" "$base.bin"
rm "$base.out.reloc"
./format_hex.sh "$base"
rm "$base.bin"

sed -i "s/\$readmemh(.*/$replacement/" ./RTL/instrmem.sv

./init.sh