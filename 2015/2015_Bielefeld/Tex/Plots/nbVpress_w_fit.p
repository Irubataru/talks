set terminal tikz standalone
set output "nbVpress_w_fit.tex"

set size ratio 0.65

#set style line 1 lt 1 lc rgb "#2C3E50"
set style line 1 lt 1 lc rgb "#2980B9" pt 6
set style line 2 lt 1 lc rgb "#E74C3C"
set style line 3 lt 1 lc rgb "#FFC200"
set style line 4 lt 1 lc rgb "#588F27"
set style line 5 lt 3 lc rgb "#2980B9"
set style line 6 lt 3 lc rgb "#E74C3C"
set style line 7 lt 3 lc rgb "#FFC200"
set style line 8 lt 3 lc rgb "#588F27"

set style line 10 lt 1 lc rgb "#2C3E50"

set xlabel "$n_B/m_B^3$" textcolor ls 10
set ylabel "$P/m_B^4$" textcolor ls 10

set key left Left at graph 0.04,0.9 spacing 2 textcolor ls 10

f(x) = a * x**(1.667)

fit f(x) 'Data/nbVpress_T10_c2000_k8.dat' using 2:3:4:5 every ::::27 via a

fittitle = sprintf("$%.5f (n_B/m_B^3)^{5/3}$", a)

set border ls 10

set yrange [0:1.75e-5]
set ytics ("0" 0, "0.5e-5" 5e-6, "1.0e-5" 1e-5, "1.5e-5" 15e-6, "2.0e-5" 2.0e-5, "2.5e-5" 2.5e-5)

set label "$T = 10$ MeV" at graph 0.7,0.2 textcolor ls 10
set label "$m_{\\pi} = 20$ GeV" at graph 0.7,0.13 textcolor ls 10

plot "Data/nbVpress_T10_c2000_k8.dat" using 2:4:3:5 every ::::27 title "Continuum extrapolated" w xyerrorbars ls 1 lw 2,\
  f(x) title fittitle ls 2 lw 2
