set terminal tikz standalone
set output "eos.tex"

set size ratio 0.65

set xrange [0:6.5]
set yrange [0:60]

unset key

set style line 2 lt 1 lc rgb "#2C3E50"
set style line 2 lt 1 lc rgb "#2980B9"
set style line 3 lt 2 lc rgb "#2980B9"
set style line 4 lt 1 lc rgb "#E74C3C"
set style line 5 lt 2 lc rgb "#E74C3C"

set style line 10 lt 1 lc rgb "#2C3E50"

set xlabel "$a^3 n_B$" textcolor ls 10
set ylabel "$a^4 P$" textcolor ls 10

set border ls 10
#set xtics nomirror
#set ytics nomirror

plot "Data/eos.dat" using 3:2 title "EoS" w l ls 2 lw 5
