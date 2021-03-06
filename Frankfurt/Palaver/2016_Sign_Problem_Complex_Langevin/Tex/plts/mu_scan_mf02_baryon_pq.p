set terminal tikz standalone background rgb "#F9F2E7"
set output "mu_scan_mf02_baryon_pq.tex"

set xlabel "$\\mu$"
set ylabel "$\\Re \\langle \\eta^{\\dagger} \\eta \\rangle / N$"

set size ratio 0.4

set key at graph 0.98,0.3

set style line 1 lt 1 lc rgb "#8FBE00" lw 3 pt 7 ps 1.5
set style line 2 lt 1 lc rgb "#FA2A00" lw 3 pt 5 ps 1.5
set style line 3 lt 1 lc rgb "#00A8C6" lw 3 pt 3 ps 1.5
set style line 4 lt 1 lc rgb "#588F27"

set style line 10 lt 1 lc rgb "#1c140d" lw 2

#set yrange [-2:6]
set xrange [0:2]

plot "data/mu_scan/baryon_48_mf02_s.dat" using 1:($2+2*$1):3 title "$N = 48$" w yerrorbars ls 1,\
     "data/analytic/mu_scan/48/baryon_mf02.dat" using 1:($2+2*$1)  title  "analytic" w l ls 2 lw 5,\
     "data/phase_quenched/mu_scan/baryon_mf02.dat" using 1:($2+2*$1)  title  "phase quenched" w l ls 3 lw 5
