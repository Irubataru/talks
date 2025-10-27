set terminal tikz standalone background rgb "#F9F2E7"
set output "mass_scan_mu02_baryon.tex"

set xlabel "$m$"
set ylabel "$\\Re \\langle \\eta^{\\dagger} \\eta \\rangle / N$"

set size ratio 0.4

set key at graph 0.98,0.2

set style line 1 lt 1 lc rgb "#8FBE00" lw 3 pt 7 ps 1.5
set style line 2 lt 1 lc rgb "#FA2A00" lw 3 pt 5 ps 1.5
set style line 3 lt 1 lc rgb "#00A8C6" lw 3 pt 3 ps 1.5
set style line 4 lt 1 lc rgb "#588F27"

set style line 10 lt 1 lc rgb "#1c140d" lw 2

#set yrange [-2:6]
set xrange [0:2]

plot "data/mass_scan/baryon_48_mu02_s.dat" using 1:($2+2*0.2):3 title "$N = 48$" w yerrorbars ls 1,\
     "data/analytic/mass_scan/48/baryon_mu02.dat" using 1:($2+2*0.2)  title  "analytic" w l ls 2 lw 5
