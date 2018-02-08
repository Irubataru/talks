set terminal tikz standalone
set output "binding_energy.tex"

set size ratio 0.65

set xrange [0.97:1.02]
#set yrange [-.5:3]


#set style line 1 lt 1 lc rgb "#2C3E50"
set style line 1 lt 1 lc rgb "#2980B9"
set style line 2 lt 1 lc rgb "#E74C3C"
set style line 3 lt 1 lc rgb "#FFC200"
set style line 4 lt 1 lc rgb "#588F27"

set style line 10 lt 1 lc rgb "#2C3E50"

set key at 0.985,-0.01 spacing 1.75 textcolor ls 10

set xlabel "$3\\mu / m_B$" textcolor ls 10
set ylabel "$\\epsilon$" textcolor ls 10


set border 3 ls 10
set xtics nomirror
set ytics nomirror

plot "Data/binding.dat" using 1:2 title "$\\mathcal{O}(\\kappa^2)$" w l ls 1 lw 2.5,\
"Data/binding.dat" using 1:3 title "$\\mathcal{O}(\\kappa^4)$" w l ls 2 lw 2.5,\
"Data/binding.dat" using 1:4 title "$\\mathcal{O}(\\kappa^6)$" w l ls 3 lw 2.5,\
"Data/binding.dat" using 1:5 title "$\\mathcal{O}(\\kappa^8)$" w l ls 4 lw 2.5
