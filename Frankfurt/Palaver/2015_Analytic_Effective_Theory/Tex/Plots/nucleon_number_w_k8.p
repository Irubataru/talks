set terminal tikz standalone
set output "nucleon_number_w_k8.tex"

set size ratio 0.65

set key at 0.06,1.25 spacing 1.75

set style line 1 lt 1 lc rgb "#2C3E50"
set style line 2 lt 1 lc rgb "#2980B9"
set style line 3 lt 2 lc rgb "#2980B9"
set style line 4 lt 1 lc rgb "#E74C3C"
set style line 5 lt 2 lc rgb "#E74C3C"
#set style line 6 lt 1 pt 6 lc rgb "#3498DB"
#set style line 6 lt 1 pt 6 lc rgb "#468966"
set style line 6 lt 1 pt 6 lc rgb "#588F27"

set style line 10 lt 1 lc rgb "#2C3E50"

set xlabel "$h_2$" textcolor ls 10
set ylabel "$a^3 n_B$" textcolor ls 10

set border 3 ls 10
set xtics nomirror
set ytics nomirror

plot "Data/convergence.dat" using 1:2 title "static" w l ls 1 lw 2.5,\
"Data/convergence.dat" using 1:3 title "$\\mathcal{O}(\\kappa^2)$" w l ls 2 lw 2.5,\
"Data/convergence.dat" using 1:4 title "$\\mathcal{O}(\\kappa^4)$" w l ls 3 lw 2.5,\
"Data/convergence.dat" using 1:5 title "$\\mathcal{O}(\\kappa^6)$" w l ls 4 lw 2.5,\
"Data/convergence.dat" using 1:6 title "$\\mathcal{O}(\\kappa^8)$" w l ls 5 lw 2.5,\
"Data/k8.dat" using 1:2:3 title "$\\mathcal{O}(\\kappa^8)$ data" w yerrorbars ls 6 lw 2.5
