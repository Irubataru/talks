set terminal tikz standalone background rgb "#F9F2E7"
set output "compare_step_baryon_mu_scan.tex"

set xlabel "$\\mu$"
set ylabel "$\\Re \\langle \\eta^{\\dagger} \\eta \\rangle / N$"

set size ratio 0.4

set key at graph 0.98,0.2

set style line 1 lt 1 lc rgb "#8FBE00" lw 3 pt 7 ps 1.5
set style line 2 lt 1 lc rgb "#FA2A00" lw 3 pt 5 ps 1.5
set style line 3 lt 1 lc rgb "#00A8C6" lw 3 pt 3 ps 1.5
set style line 4 lt 1 lc rgb "#588F27"

set style line 10 lt 1 lc rgb "#1c140d" lw 2

#set title "$n_f = 1, \\; m = 0$"

set yrange [-2:6]
set xrange [0:2]

plot "data/mu_scan/baryon_48_mf0_n.dat" using 1:($2+2*$1):3 title "$\\Delta t = 10^{-4}$" w yerrorbars ls 1,\
     "data/mu_scan/baryon_48_mf0_s.dat" using 1:($2+2*$1):3  title "$\\Delta t = 10^{-5}$" w yerrorbars ls 2
