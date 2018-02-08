set terminal tikz standalone
set output "nbOfPi_T20_a02.tex"

set size ratio 0.65

#set style line 1 lt 1 lc rgb "#2C3E50"
set style line 1 lt 1 lc rgb "#2980B9" pt 1
set style line 2 lt 1 lc rgb "#E74C3C" pt 4
set style line 3 lt 1 lc rgb "#FFC200" pt 6
set style line 4 lt 1 lc rgb "#588F27"
set style line 5 lt 3 lc rgb "#2980B9"
set style line 6 lt 3 lc rgb "#E74C3C"
set style line 7 lt 3 lc rgb "#FFC200"
set style line 8 lt 3 lc rgb "#588F27"

set style line 10 lt 1 lc rgb "#2C3E50"

set ylabel "$n_B/m_B^3$" textcolor ls 10
set xlabel "$m_{\\pi} [\\mathrm{GeV}]$" textcolor ls 10

set key right Left at graph 0.5,0.9 spacing 2 textcolor ls 10

set border ls 10

set yrange [0:0.007]
#set ytics ("0" 0, "0.5e-5" 5e-6, "1.0e-5" 1e-5, "1.5e-5" 15e-6, "2.0e-5" 2.0e-5, "2.5e-5" 2.5e-5)

set label "\\hskip5pt$T = 20$ MeV" left at graph 0.65,0.87 textcolor ls 10
set label "\\hskip7pt$a = 0.2$ fm" left at graph 0.65,0.8 textcolor ls 10
set label "$\\mu_B = 0.999 \\,n_B$" left at graph 0.65,0.73 textcolor ls 10

plot "Data/nbOfmpi_T20_a0.2.dat" using 1:3:(abs($3-$2)) title "$\\kappa^4$ " with errorbars ls 1 lw 2,\
"Data/nbOfmpi_T20_a0.2.dat" using 1:4:(abs($4-$3)) title "$\\kappa^6$ " with errorbars ls 2 lw 2,\
"Data/nbOfmpi_T20_a0.2.dat" using 1:5:(abs($5-$4)) title "$\\kappa^8$ " with errorbars ls 3 lw 2
