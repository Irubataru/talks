set terminal tikz standalone background rgb "#F9F2E7"
set output "mu_scan_mf02_cond.tex"

set xlabel "$\\mu$"
set ylabel "$\\Re \\langle \\bar{\\eta} \\eta \\rangle / N$"

set xrange [0:2]
#set yrange [1.5:4]

set size ratio 0.4

set key at graph 0.98,0.9

set style line 1 lt 1 lc rgb "#8FBE00" lw 3 pt 7 ps 1.5
set style line 2 lt 1 lc rgb "#FA2A00" lw 3 pt 5 ps 1.5
set style line 3 lt 1 lc rgb "#00A8C6" lw 3 pt 3 ps 1.5
set style line 4 lt 1 lc rgb "#588F27"

set style line 10 lt 1 lc rgb "#1c140d" lw 2

plot "data/mu_scan/cond_48_mf02_s.dat" using 1:2:3 title "$N = 48$" w yerrorbars ls 1,\
     "data/analytic/mu_scan/48/cond_mf02.dat" using 1:2 title "analytic" w l ls 2 lw 5
