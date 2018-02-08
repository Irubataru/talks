set terminal tikz standalone
set output "rgediag.tex"

set xrange [0:320]
set yrange [0:180]

set xlabel "$\\mu$ [MeV]"
set ylabel "$T$ [MeV]"

set ytics 0,40,180

set bars 0.2

plot "RGEData/phaseDiagHErr" using 1:2:3 title "RGE" with errorbars lt 1 pt 2 lc rgb "#F26101",\
"2FlData/phaseMs600" every ::76 title "MF" w l lc rgb "#604269" lt 1,\
"2FlData/phaseMs600" every ::::76 notitle w l lc rgb "#604269" lt 5,\
"2FlData/phaseMs600" every ::76::76 notitle w p pt 7 lc rgb "#604269",\
