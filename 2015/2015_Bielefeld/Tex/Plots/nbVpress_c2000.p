set terminal tikz standalone
set output "nbVpress_c2000.tex"

set size ratio 0.65

#set style line 1 lt 1 lc rgb "#2C3E50"
set style line 1 lt 1 lc rgb "#2980B9"
set style line 2 lt 1 lc rgb "#E74C3C"
set style line 3 lt 1 lc rgb "#FFC200"
set style line 4 lt 1 lc rgb "#588F27"
set style line 5 lt 3 lc rgb "#2980B9"
set style line 6 lt 3 lc rgb "#E74C3C"
set style line 7 lt 3 lc rgb "#FFC200"
set style line 8 lt 3 lc rgb "#588F27"

set style line 10 lt 1 lc rgb "#2C3E50"

set ylabel "$P/m_B^4$" textcolor ls 10
set xlabel "$n_B/m_B^3$" textcolor ls 10

unset key

set border ls 10

set yrange [0:2.5e-5]
set ytics ("0" 0, "0.5e-5" 5e-6, "1.0e-5" 1e-5, "1.5e-5" 15e-6, "2.0e-5" 2.0e-5, "2.5e-5" 2.5e-5)

set label "$T = 10$ MeV" at 0.001,2e-5 textcolor ls 10
set label "$m_{\\pi} = 20$ GeV" at 0.001,1.85e-5 textcolor ls 10

plot "Data/nbVpress_T10_c2000_k8.dat" using 2:4:3:5 w xyerrorbars ls 1 lw 2
