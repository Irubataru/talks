set terminal tikz standalone
set output "resummed_conv_part2.tex"

set size ratio 0.65

set yrange [-.5:3]

#set style line 1 lt 1 lc rgb "#2C3E50"
set style line 1 lt 1 lc rgb "#2980B9"
set style line 2 lt 1 lc rgb "#E74C3C"
set style line 3 lt 1 lc rgb "#FFC200"
set style line 4 lt 1 lc rgb "#588F27"
set style line 5 lt 2 lc rgb "#2980B9"
set style line 6 lt 2 lc rgb "#E74C3C"
set style line 7 lt 2 lc rgb "#FFC200"
set style line 8 lt 2 lc rgb "#588F27"

set style line 10 lt 1 lc rgb "#2C3E50"

set multiplot

set xlabel "$h_2$" textcolor ls 10
set ylabel "$a^3 n_B$" textcolor ls 10

set border 3 ls 10
set xtics nomirror
set ytics nomirror

set key at 0.06,0.5 spacing 1.75 textcolor ls 10
set label "Linked Cluster" at 0.012,0.6 textcolor ls 10

plot "Data/resummed_conv.dat" using 1:3 title "$\\mathcal{O}(\\kappa^2)$" w l ls 1 lw 2.5,\
"Data/resummed_conv.dat" using 1:4 title "$\\mathcal{O}(\\kappa^4)$" w l ls 2 lw 2.5,\
"Data/resummed_conv.dat" using 1:5 title "$\\mathcal{O}(\\kappa^6)$" w l ls 3 lw 2.5,\
"Data/resummed_conv.dat" using 1:6 title "$\\mathcal{O}(\\kappa^8)$" w l ls 4 lw 2.5


set key at 0.06,2.8 spacing 1.75 textcolor ls 10
set label "Resummed" at 0.012,2.9 textcolor ls 10

plot "Data/resummed_conv.dat" using 1:7 title "$\\mathcal{O}(\\kappa^2)$" w l ls 5 lw 2.5,\
"Data/resummed_conv.dat" using 1:8 title "$\\mathcal{O}(\\kappa^4)$" w l ls 6 lw 2.5,\
"Data/resummed_conv.dat" using 1:9 title "$\\mathcal{O}(\\kappa^6)$" w l ls 7 lw 2.5,\
"Data/resummed_conv.dat" using 1:10 title "$\\mathcal{O}(\\kappa^8)$" w l ls 8 lw 2.5


unset multiplot
