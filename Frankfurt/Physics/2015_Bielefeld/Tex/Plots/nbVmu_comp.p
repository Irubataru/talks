set terminal tikz standalone
set output "nbVmu_comp.tex"

set size ratio 0.65

#set style line 1 lt 1 lc rgb "#2C3E50"
set style line 1 dt 1 lc rgb "#2980B9"
set style line 2 dt 1 lc rgb "#E74C3C"
set style line 3 dt 1 lc rgb "#FFC200"
set style line 4 dt 1 lc rgb "#588F27"
set style line 5 dt 3 lc rgb "#2980B9"
set style line 6 dt 3 lc rgb "#E74C3C"
set style line 7 dt 3 lc rgb "#FFC200"
set style line 8 dt 3 lc rgb "#588F27"

set style line 10 lt 1 lc rgb "#2C3E50"

set xlabel "$\\mu/m_B$" textcolor ls 10
set ylabel "$n_B/m_B^3$" textcolor ls 10

set key at 0.998,0.007 textcolor ls 10

set border ls 10

set xrange [0.996:1.0012]

set label "$T = 10$ MeV" at 0.9975,0.0055 right textcolor ls 10
set label "$m_{\\pi} = 20$ GeV" at 0.9975,0.0048 right textcolor ls 10

#plot "Data/nbVpress_T10_c2000_k8.dat" using 2:4:3:5 w xyerrorbars ls 1 lw 2
plot 'Data/m_analytic.dat' u ($1):(($2+$6)/2):($3+$7+sqrt(($6-$2)**2)) title "analytic" w errorbars ls 1 pt 6 lw 2,\
'Data/m_numeric.dat' u ($1):(($2+$6)/2):($3+$7+sqrt(($6-$2)**2)) title "simulated" w errorbars ls 2 lw 2 
#plot 'analytic.txt' u ($1):(($2+$6)/2):($3+$7+sqrt(($6-$2)**2)) w errorbars t '$analytical$','langevin.txt' u ($1):(($2+$6)/2):($3+$7+sqrt(($6-$2)**2)) w errorbars t '$simulated$'
