set terminal tikz standalone
set output "eos_cont.tex"

set size ratio 0.65

unset key

set style line 2 lt 1 lc rgb "#2C3E50"
set style line 2 lt 1 lc rgb "#2980B9"
set style line 3 lt 2 lc rgb "#2980B9"
set style line 4 lt 1 lc rgb "#E74C3C"
set style line 5 lt 2 lc rgb "#E74C3C"

set style line 10 lt 1 lc rgb "#2C3E50"

set xlabel "$n_B / m_B^3$" textcolor ls 10
set ylabel "$P / m_B^4$" textcolor ls 10

set border ls 10
#set xtics nomirror
#set ytics nomirror

plot "./Data/nbVpress_T10_c2000_k8.dat" using 2:4:3:5 w xyerrorbars ls 2
